#include <system_error>

#include "packetio/drivers/dpdk/dpdk.h"
#include "packetio/drivers/dpdk/ethdev/hook.hpp"
#include "packetio/drivers/dpdk/ethdev/af_packet.hpp"

void hook_ethdevs()
{
    uint16_t port = 0;

    RTE_ETH_FOREACH_DEV (port) {
        rte_eth_dev_info info;
        if (rte_eth_dev_info_get(port, &info)) continue;
        if (strcmp(info.driver_name, "af_packet")) {
            if (hook_af_packet_ethdev(port)) {
                throw std::system_error(errno,
                                        std::generic_category(),
                                        "Unable to create hook ethdev");
            }
        }
    }
}

void unhook_ethdevs()
{
    uint16_t port = 0;

    RTE_ETH_FOREACH_DEV (port) {
        rte_eth_dev_info info;
        if (rte_eth_dev_info_get(port, &info)) continue;
        if (strcmp(info.driver_name, "af_packet")) {
            unhook_af_packet_ethdev(port);
        }
    }
}
