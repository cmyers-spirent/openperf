#include "packetio/drivers/dpdk/dpdk.h"
#include "packetio/stack/dpdk/net_interface.hpp"
#include "packetio/forwarding_table.tcc"
#include "packetio/generic_sink.hpp"

struct netif;

namespace openperf::packetio {

/*
 * Provide a template specialization for the forwarding table so that it
 * can retrieve the opaque string id from an interface.
 */
template <> std::string get_interface_id(netif* ifp)
{
    return (dpdk::to_interface(ifp).id());
}

/*
 * Provide a template specialization for the forwarding table so that it
 * can store fib data into the interface.
 */
template <> std::atomic<void*>& get_interface_fib_data(netif* ifp)
{
    return dpdk::to_interface(ifp).get_fib_data();
}

template class forwarding_table<netif, packets::generic_sink, RTE_MAX_ETHPORTS>;

} // namespace openperf::packetio
