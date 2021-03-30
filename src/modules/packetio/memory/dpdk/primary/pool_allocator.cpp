#include <memory>
#include <numeric>

#include "core/op_core.h"
#include "packetio/drivers/dpdk/dpdk.h"
#include "packetio/drivers/dpdk/port_info.hpp"
#include "packetio/memory/dpdk/primary/mempool_fmt.h"
#include "packetio/memory/dpdk/primary/pool_allocator.hpp"

namespace openperf::packetio::dpdk::primary {

/*
 * Provide additional space between the mbuf header and payload for stack usage.
 * Adjust as necessary.
 */
constexpr auto mempool_private_size = 64;

/*
 * Per the DPDK documentation, cache size should be a divisor of pool
 * size.  However, since the optimal pool size is a Mersenne number,
 * nice multiples of 2 tend to be wasteful.  This table specifies the
 * cache size to use for various pool sizes in order to minimize wasted
 * pool elements.
 */

#if RTE_MEMPOOL_CACHE_MAX_SIZE < 512
#error "RTE_MEMPOOL_CACHE_MAX_SIZE must be at least 512"
#endif

static struct cache_size_map
{
    uint32_t nb_mbufs;
    uint32_t cache_size;
} packetio_cache_size_map[] = {
    {63, 9},       /* 63 % 9 == 0 */
    {127, 21},     /* 127 % 21 == 1 (127 is prime) */
    {255, 51},     /* 255 % 51 == 0 */
    {511, 73},     /* 511 % 73 == 0 */
    {1023, 341},   /* 1023 % 341 == 0 */
    {2047, 341},   /* 2047 % 341 == 1 */
    {4095, 455},   /* 4095 % 455 == 0 */
    {8191, 455},   /* 8191 % 455 == 1 (8191 is prime) */
    {16383, 455},  /* 16383 % 455 == 3 */
    {32767, 504},  /* 32767 % 504 == 7 */
    {65535, 508},  /* 65535 % 508 == 3 */
    {131071, 510}, /* 131071 % 510 == 1 (131071 is prime) */
};

__attribute__((const)) static uint32_t get_cache_size(uint32_t nb_mbufs)
{
    for (size_t i = 0; i < op_count_of(packetio_cache_size_map); i++) {
        if (packetio_cache_size_map[i].nb_mbufs == nb_mbufs) {
            return (packetio_cache_size_map[i].cache_size);
        }
    }

    return (RTE_MEMPOOL_CACHE_MAX_SIZE);
}

/*
 * Convert nb_mbufs to a Mersenne number, as those are the
 * most efficient size for mempools.  If our input is already a
 * power of 2, return input - 1 instead of doubling the size.
 */
__attribute__((const)) static uint32_t pool_size_adjust(uint32_t nb_mbufs)
{
    return (rte_is_power_of_2(nb_mbufs) ? nb_mbufs - 1
                                        : rte_align32pow2(nb_mbufs) - 1);
}

static void log_mempool(const struct rte_mempool* mpool)
{
    OP_LOG(OP_LOG_INFO,
           "%s: %u, %u byte mbufs on NUMA socket %d\n",
           mpool->name,
           mpool->size,
           rte_pktmbuf_data_room_size((struct rte_mempool*)mpool),
           mpool->socket_id);
}

static rte_mempool*
create_mempool(const char* name, size_t size, int socket_id, uint16_t mbuf_size)
{
    size_t nb_mbufs = op_min(131072, pool_size_adjust(op_max(1024U, size)));

    rte_mempool* mp = rte_pktmbuf_pool_create_by_ops(name,
                                                     nb_mbufs,
                                                     get_cache_size(nb_mbufs),
                                                     mempool_private_size,
                                                     mbuf_size,
                                                     socket_id,
                                                     "stack");

    if (!mp) {
        throw std::runtime_error(std::string("Could not allocate mempool = ")
                                 + name);
    }

    log_mempool(mp);

    return (mp);
}

void pool_allocator::init(const std::vector<uint16_t>& port_indexes,
                          const std::map<uint16_t, queue::count>& q_counts,
                          const uint16_t mbuf_size,
                          const uint32_t extra_tx_mbuf_count)
{
    /* Base default pool size on the number and types of ports on each NUMA node
     */
    for (auto i = 0U; i < RTE_MAX_NUMA_NODES; i++) {
        size_t nb_tx = 0, nb_rx = 0;
        std::for_each(
            begin(port_indexes), end(port_indexes), [&](const uint16_t id) {
                const auto& cursor = q_counts.find(id);
                if (cursor == q_counts.end() || port_info::socket_id(id) != i) {
                    return;
                }
                nb_tx += (cursor->second.tx * port_info::tx_desc_count(id));
                nb_rx += (cursor->second.rx * port_info::rx_desc_count(id));
            });
        if (nb_rx) {
            /* We need a Rx mempool for this NUMA node */
            std::array<char, RTE_MEMPOOL_NAMESIZE> name_buf;
            snprintf(name_buf.data(),
                     RTE_MEMPOOL_NAMESIZE,
                     rx_mempool_format.data(),
                     i);
            m_rx_pools.emplace(
                i, create_mempool(name_buf.data(), nb_rx, i, mbuf_size));
        }
        if (nb_tx) {
            /* We need a Tx mempool for this NUMA node */
            std::array<char, RTE_MEMPOOL_NAMESIZE> name_buf;
            snprintf(name_buf.data(),
                     RTE_MEMPOOL_NAMESIZE,
                     tx_mempool_format.data(),
                     i);
            nb_tx += extra_tx_mbuf_count;
            m_tx_pools.emplace(
                i, create_mempool(name_buf.data(), nb_tx, i, mbuf_size));
        }
    }
};

void pool_allocator::fini()
{
    m_rx_pools.clear();
    m_tx_pools.clear();
}

/* Grab the first Rx memory pool less than or equal to the given socket id. */
rte_mempool* pool_allocator::get_rx_mempool(unsigned socket_id) const
{
    assert(socket_id <= RTE_MAX_NUMA_NODES);
    assert(!m_rx_pools.empty());
    auto cursor = m_rx_pools.upper_bound(socket_id);
    return (cursor == std::begin(m_rx_pools) ? cursor->second.get()
                                             : std::prev(cursor)->second.get());
}

/* Grab the first Tx memory pool less than or equal to the given socket id. */
rte_mempool* pool_allocator::get_tx_mempool(unsigned socket_id) const
{
    assert(socket_id <= RTE_MAX_NUMA_NODES);
    assert(!m_tx_pools.empty());
    auto cursor = m_tx_pools.upper_bound(socket_id);
    return (cursor == std::begin(m_tx_pools) ? cursor->second.get()
                                             : std::prev(cursor)->second.get());
}

} // namespace openperf::packetio::dpdk::primary
