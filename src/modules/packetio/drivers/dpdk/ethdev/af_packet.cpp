#include <linux/if_ether.h>
#include <linux/if_packet.h>
#include <assert.h>

#include "packetio/drivers/dpdk/dpdk.h"
#include "packetio/drivers/dpdk/ethdev/af_packet.hpp"
#include "rte_pmd_af_packet_priv.h"

/*
 * Process local PMD private data for af_packet driver.
 */
struct pmd_process_private
{
    rte_intr_handle intr_handle;
    int intr_vec[RTE_PMD_AF_PACKET_MAX_RINGS];
    const struct eth_dev_ops* real_dev_ops;
    struct eth_dev_ops dev_ops;
};

pmd_process_private* af_packet_get_process_private(struct rte_eth_dev* dev)
{
    /* The actual af_packet driver doesn't currently use the process_private
     * member so could store pmd_process_private pointer there. However if
     * future versions do use it, this code would still work. Whereas if
     * intr_handle is used in future this code would not be needed anyway.
     */
    if (!dev->intr_handle) { return NULL; }
    return container_of(dev->intr_handle, pmd_process_private, intr_handle);
}

static int af_packet_rx_queue_intr_enable(struct rte_eth_dev*, uint16_t)
{
    // Driver is using the rx socket fd for "interrupt" signalling so
    // it is always enabled.
    return 0;
}

static int af_packet_rx_queue_intr_disable(struct rte_eth_dev*, uint16_t)
{
    // Driver is using the rx socket fd for "interrupt" signalling so
    // it is always enabled.
    return 0;
}

static void af_packet_intr_configure(struct rte_eth_dev* dev, bool rx_enable)
{
    int ivec = 0;
    auto priv = static_cast<pmd_internals*>(dev->data->dev_private);
    rte_intr_handle* intr_handle = dev->intr_handle;

    if (!intr_handle) { return; }

    for (uint16_t q = 0; q < dev->data->nb_rx_queues; ++q, ++ivec) {
        // DPDK subtracts RTE_INTR_VEC_RXTX_OFFSET to get tx/rx offset
        // so need to add it here.
        intr_handle->intr_vec[q] = RTE_INTR_VEC_RXTX_OFFSET + ivec;

        // Make sure eth_dev_rx_intr_ctl_q_get_fd() returns -1 when rx
        // interrupts are disabled.
        intr_handle->efds[ivec] = rx_enable ? priv->rx_queue[q].sockfd : -1;
    }
    intr_handle->nb_efd = ivec;
    intr_handle->max_intr = RTE_INTR_VEC_RXTX_OFFSET + ivec;
}

static int af_packet_dev_configure(struct rte_eth_dev* dev)
{
    auto pp = af_packet_get_process_private(dev);
    if (!pp) { return -1; }

    int result = pp->real_dev_ops->dev_configure(dev);
    if (result) { return result; }
    af_packet_intr_configure(dev, dev->data->dev_conf.intr_conf.rxq);
    return 0;
}

int hook_af_packet_ethdev(uint16_t port)
{
    auto dev = &rte_eth_devices[port];
    assert(dev->intr_handle == NULL);
    assert(dev->dev_ops->rx_queue_intr_enable);
    assert(dev->dev_ops->rx_queue_intr_disable);

    auto pp = reinterpret_cast<pmd_process_private*>(
        calloc(1, sizeof(pmd_process_private)));
    if (!pp) return -1;

    /* copy original dev_ops function pointers and override where necessary */
    pp->dev_ops = *dev->dev_ops;
    pp->dev_ops.dev_configure = af_packet_dev_configure;
    pp->dev_ops.rx_queue_intr_enable = af_packet_rx_queue_intr_enable;
    pp->dev_ops.rx_queue_intr_disable = af_packet_rx_queue_intr_disable;

    /* store original dev_ops pointer and replace with overridden dev_ops */
    pp->real_dev_ops = dev->dev_ops;
    dev->dev_ops = &pp->dev_ops;

    /* initialize intr_handle */
    pp->intr_handle.type = RTE_INTR_HANDLE_VDEV;
    pp->intr_handle.fd = -1;
    pp->intr_handle.intr_vec = pp->intr_vec;
    dev->intr_handle = &pp->intr_handle;
    af_packet_intr_configure(dev, dev->data->dev_conf.intr_conf.rxq);

    return 0;
}

void unhook_af_packet_ethdev(uint16_t port)
{
    auto dev = &rte_eth_devices[port];
    if (dev->intr_handle) {
        auto pp = af_packet_get_process_private(dev);
        dev->dev_ops = pp->real_dev_ops;
        dev->intr_handle = NULL;
        free(pp);
    }
}
