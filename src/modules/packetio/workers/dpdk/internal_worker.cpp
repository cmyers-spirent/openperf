#include "packetio/internal_worker.hpp"
#include "packetio/drivers/dpdk/dpdk.h"
#include "packetio/workers/dpdk/worker_queues.hpp"
#include "packetio/workers/dpdk/worker_api.hpp"

namespace openperf::packetio::internal::worker {

unsigned get_id() { return (rte_lcore_id()); }

unsigned get_numa_node() { return (rte_socket_id()); }

void stack_add_socket_ref(uint16_t port)
{
    auto& queues = dpdk::worker::port_queues::instance();
    auto fib = queues.fib<dpdk::worker::fib*>();
    if (fib) fib->add_socket(port);
}

void stack_remove_socket_ref(uint16_t port)
{
    auto& queues = dpdk::worker::port_queues::instance();
    auto fib = queues.fib<dpdk::worker::fib*>();
    if (fib) fib->remove_socket(port);
}

} // namespace openperf::packetio::internal::worker
