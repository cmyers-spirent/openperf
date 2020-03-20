#include <cassert>
#include <string>

#include "packetio/forwarding_table.hpp"

namespace openperf::packetio {

template <typename Interface> std::string get_interface_id(Interface* ifp);

template <typename Interface> std::atomic<void *>& get_interface_fib_data(Interface* ifp);

template <typename Interface, typename Sink, int MaxPorts>
typename forwarding_table<Interface, Sink, MaxPorts>::sink_vector
forwarding_table<Interface, Sink, MaxPorts>::empty_sink_vector;


template <typename Interface, typename Sink, int MaxPorts>
forwarding_table<Interface, Sink, MaxPorts>::forwarding_table()
{
    for (int i = 0; i < MaxPorts; i++) {
        m_interfaces[i].store(new interface_map());
        m_port_sinks[i].store(new sink_vector());
    }
}

template <typename Interface, typename Sink, int MaxPorts>
forwarding_table<Interface, Sink, MaxPorts>::~forwarding_table()
{
    for (int i = 0; i < MaxPorts; i++) {
        delete m_interfaces[i].exchange(nullptr);
        delete m_port_sinks[i].exchange(nullptr);
    }
}

template <typename Interface, typename Sink, int MaxPorts>
typename forwarding_table<Interface, Sink, MaxPorts>::interface_map*
forwarding_table<Interface, Sink, MaxPorts>::insert_interface(
    uint16_t port_idx, const net::mac_address& mac, Interface* ifp)
{
    assert(port_idx < MaxPorts);

    auto original = m_interfaces[port_idx].load(std::memory_order_relaxed);
    auto updated = new interface_map(std::move(original->set(mac, ifp)));
    return (
        m_interfaces[port_idx].exchange(updated, std::memory_order_release));
}

template <typename Interface, typename Sink, int MaxPorts>
typename forwarding_table<Interface, Sink, MaxPorts>::interface_map*
forwarding_table<Interface, Sink, MaxPorts>::remove_interface(
    uint16_t port_idx, const net::mac_address& mac)
{
    assert(port_idx < MaxPorts);

    auto original = m_interfaces[port_idx].load(std::memory_order_relaxed);
    auto updated = new interface_map(std::move(original->erase(mac)));
    return (
        m_interfaces[port_idx].exchange(updated, std::memory_order_release));
}

template <typename Interface, typename Sink, int MaxPorts>
typename forwarding_table<Interface, Sink, MaxPorts>::sink_vector*
forwarding_table<Interface, Sink, MaxPorts>::insert_sink(uint16_t port_idx,
                                                         Sink sink)
{
    assert(port_idx < MaxPorts);

    auto original = m_port_sinks[port_idx].load(std::memory_order_relaxed);
    auto updated = new sink_vector(std::move(original->push_back(sink)));
    return (m_port_sinks[port_idx].exchange(updated, std::memory_order_release));
}

template <typename Interface, typename Sink, int MaxPorts>
typename forwarding_table<Interface, Sink, MaxPorts>::sink_vector*
forwarding_table<Interface, Sink, MaxPorts>::remove_sink(uint16_t port_idx,
                                                         Sink sink)
{
    assert(port_idx < MaxPorts);

    auto original = m_port_sinks[port_idx].load(std::memory_order_relaxed);
    auto found = std::find(original->begin(), original->end(), sink);
    if (found == original->end()) return (nullptr); /* not found */
    auto updated = new sink_vector(
        std::move(original->erase(std::distance(original->begin(), found))));
    return (m_port_sinks[port_idx].exchange(updated, std::memory_order_release));
}

template <typename Interface, typename Sink, int MaxPorts>
typename forwarding_table<Interface, Sink, MaxPorts>::sink_vector*
forwarding_table<Interface, Sink, MaxPorts>::insert_interface_sink(uint16_t port_idx,
                                                                   Interface* ifp,
                                                                   Sink sink)
{
    assert(port_idx < MaxPorts);

    auto original = reinterpret_cast<sink_vector *>(get_interface_fib_data(ifp).load(std::memory_order_relaxed));
    sink_vector *updated;
    if (original) {
        updated = new sink_vector(std::move(original->push_back(sink)));
    } else {
        updated = new sink_vector(std::move(sink_vector().push_back(sink)));
    }

    return reinterpret_cast<sink_vector *>(get_interface_fib_data(ifp).exchange(reinterpret_cast<void *>(updated), std::memory_order_release));
}

template <typename Interface, typename Sink, int MaxPorts>
typename forwarding_table<Interface, Sink, MaxPorts>::sink_vector*
forwarding_table<Interface, Sink, MaxPorts>::remove_interface_sink(uint16_t port_idx,
                                                                   Interface* ifp,
                                                                   Sink sink)
{
    assert(port_idx < MaxPorts);

    auto original = reinterpret_cast<sink_vector *>(get_interface_fib_data(ifp).load(std::memory_order_relaxed));
    if (!original) return nullptr;

    sink_vector *updated = nullptr;
    auto found = std::find(original->begin(), original->end(), sink);
    if (original->size() > 1) {
        updated = new sink_vector(
            std::move(original->erase(std::distance(original->begin(), found))));
    }

    return reinterpret_cast<sink_vector *>(get_interface_fib_data(ifp).exchange(reinterpret_cast<void *>(updated), std::memory_order_release));
}

template <typename Interface, typename Sink, int MaxPorts>
Interface* forwarding_table<Interface, Sink, MaxPorts>::find_interface(
    uint16_t port_idx, std::string_view id) const
{
    assert(port_idx < MaxPorts);

    const auto& map = *(m_interfaces[port_idx].load(std::memory_order_consume));
    auto item =
        std::find_if(std::begin(map), std::end(map), [&](const auto& pair) {
            return (get_interface_id(pair.second) == id);
        });
    if (item != std::end(map)) return (item->second);

    return (nullptr);
}

template <typename Interface, typename Sink, int MaxPorts>
Interface* forwarding_table<Interface, Sink, MaxPorts>::find_interface(
    std::string_view id) const
{
    for (auto& map_ptr : m_interfaces) {
        const auto& map = *(map_ptr.load(std::memory_order_consume));
        auto item =
            std::find_if(std::begin(map), std::end(map), [&](const auto& pair) {
                return (get_interface_id(pair.second) == id);
            });
        if (item != std::end(map)) return (item->second);
    }

    return (nullptr);
}

template <typename Interface, typename Sink, int MaxPorts>
Interface* forwarding_table<Interface, Sink, MaxPorts>::find_interface(
    uint16_t port_idx, const net::mac_address& mac) const
{
    assert(port_idx < MaxPorts);

    auto map = m_interfaces[port_idx].load(std::memory_order_consume);
    auto item = map->find(mac);
    return (item ? *item : nullptr);
}

template <typename Interface, typename Sink, int MaxPorts>
Interface* forwarding_table<Interface, Sink, MaxPorts>::find_interface(
    uint16_t port_idx, const uint8_t octets[mac_address_length]) const
{
    assert(port_idx < MaxPorts);

    auto map = m_interfaces[port_idx].load(std::memory_order_consume);
    auto item = map->find(net::mac_address(octets));
    return (item ? *item : nullptr);
}

template <typename Interface, typename Sink, int MaxPorts>
typename forwarding_table<Interface, Sink, MaxPorts>::interface_map&
forwarding_table<Interface, Sink, MaxPorts>::get_interfaces(
    uint16_t port_idx) const
{
    assert(port_idx < MaxPorts);
    return (*m_interfaces[port_idx].load(std::memory_order_consume));
}

template <typename Interface, typename Sink, int MaxPorts>
typename forwarding_table<Interface, Sink, MaxPorts>::sink_vector&
forwarding_table<Interface, Sink, MaxPorts>::get_sinks(uint16_t port_idx) const
{
    assert(port_idx < MaxPorts);
    return (*m_port_sinks[port_idx].load(std::memory_order_consume));
}

template <typename Interface, typename Sink, int MaxPorts>
typename forwarding_table<Interface, Sink, MaxPorts>::sink_vector&
forwarding_table<Interface, Sink, MaxPorts>::get_interface_sinks(
    uint16_t port_idx, Interface *ifp) const
{
    assert(port_idx < MaxPorts);

    auto sinks = reinterpret_cast<sink_vector *>(get_interface_fib_data(ifp).load(std::memory_order_consume));
    if (sinks) return *sinks;

    return empty_sink_vector;
}

template <typename Interface, typename Sink, int MaxPorts>
void
forwarding_table<Interface, Sink, MaxPorts>::visit_interface_sinks(uint16_t port_idx, std::function<bool(Interface *ifp, const Sink &sink)> visitor)
{
    assert(port_idx < MaxPorts);

    auto interfaces = m_interfaces[port_idx].load(std::memory_order_consume);
    for (auto& [key, ifp] : *interfaces) {
        auto sinks = get_interface_sinks(port_idx, ifp);
        for (auto& sink : sinks) {
            if (!visitor(ifp, sink))
                return;
        }
    }
}

} // namespace openperf::packetio
