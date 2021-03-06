#ifndef _OP_PACKET_PROTOCOL_STATISTICS_GENERIC_PROTOCOL_COUNTERS_HPP_
#define _OP_PACKET_PROTOCOL_STATISTICS_GENERIC_PROTOCOL_COUNTERS_HPP_

#include <memory>

#include "packet/statistics/protocol/packet_type_counters.hpp"
#include "packetio/packet_type.hpp"
#include "utils/enum_flags.hpp"

namespace openperf::packet::statistics {

class generic_protocol_counters
{
public:
    using packet_type_flags = packetio::packet::packet_type::flags;

    template <typename StatsTuple>
    generic_protocol_counters(StatsTuple tuple)
        : m_self(std::make_shared<stats_model<StatsTuple>>(std::move(tuple)))
    {}

    template <typename StatsType> const StatsType& get() const
    {
        return (m_self->get<StatsType>());
    }

    template <typename StatsType> StatsType& get()
    {
        return (const_cast<StatsType&>(m_self->get<StatsType>()));
    }

    template <typename StatsType> bool holds() const
    {
        return (m_self->holds<StatsType>());
    }

    void update(const packet_type_flags values[], uint16_t nb_values) const
    {
        m_self->update(values, nb_values);
    }

    void dump(std::ostream& os) const { m_self->dump(os); }

private:
    struct stats_concept
    {
        virtual ~stats_concept() = default;

        template <typename StatsType> struct tag
        {};

        template <typename StatsType> const StatsType& get() const
        {
            return (get(tag<StatsType>{}));
        }

        template <typename StatsType> bool holds() const
        {
            return (holds(tag<StatsType>{}));
        }

        virtual void update(const packet_type_flags values[],
                            uint16_t nb_values) const = 0;

        virtual void dump(std::ostream& os) const = 0;

    protected:
        virtual const protocol::ethernet&
        get(tag<protocol::ethernet>&&) const = 0;
        virtual const protocol::ip& get(tag<protocol::ip>&&) const = 0;
        virtual const protocol::transport&
        get(tag<protocol::transport>&&) const = 0;
        virtual const protocol::tunnel& get(tag<protocol::tunnel>&&) const = 0;
        virtual const protocol::inner_ethernet&
        get(tag<protocol::inner_ethernet>&&) const = 0;
        virtual const protocol::inner_ip&
        get(tag<protocol::inner_ip>&&) const = 0;
        virtual const protocol::inner_transport&
        get(tag<protocol::inner_transport>&&) const = 0;

        virtual bool holds(tag<protocol::ethernet>&&) const = 0;
        virtual bool holds(tag<protocol::ip>&&) const = 0;
        virtual bool holds(tag<protocol::transport>&&) const = 0;
        virtual bool holds(tag<protocol::tunnel>&&) const = 0;
        virtual bool holds(tag<protocol::inner_ethernet>&&) const = 0;
        virtual bool holds(tag<protocol::inner_ip>&&) const = 0;
        virtual bool holds(tag<protocol::inner_transport>&&) const = 0;
    };

    template <typename StatsTuple> struct stats_model final : stats_concept
    {
        stats_model(StatsTuple tuple)
            : m_data(std::move(tuple))
        {}

        const protocol::ethernet& get(tag<protocol::ethernet>&&) const override
        {
            return (get_counter<protocol::ethernet, StatsTuple>(m_data));
        }

        const protocol::ip& get(tag<protocol::ip>&&) const override
        {
            return (get_counter<protocol::ip, StatsTuple>(m_data));
        }

        const protocol::transport&
        get(tag<protocol::transport>&&) const override
        {
            return (get_counter<protocol::transport, StatsTuple>(m_data));
        }

        const protocol::tunnel& get(tag<protocol::tunnel>&&) const override
        {
            return (get_counter<protocol::tunnel, StatsTuple>(m_data));
        }

        const protocol::inner_ethernet&
        get(tag<protocol::inner_ethernet>&&) const override
        {
            return (get_counter<protocol::inner_ethernet, StatsTuple>(m_data));
        }

        const protocol::inner_ip& get(tag<protocol::inner_ip>&&) const override
        {
            return (get_counter<protocol::inner_ip, StatsTuple>(m_data));
        }

        const protocol::inner_transport&
        get(tag<protocol::inner_transport>&&) const override
        {
            return (get_counter<protocol::inner_transport, StatsTuple>(m_data));
        }

        bool holds(tag<protocol::ethernet>&&) const override
        {
            return (holds_stat<protocol::ethernet, StatsTuple>(m_data));
        }

        bool holds(tag<protocol::ip>&&) const override
        {
            return (holds_stat<protocol::ip, StatsTuple>(m_data));
        }

        bool holds(tag<protocol::transport>&&) const override
        {
            return (holds_stat<protocol::transport, StatsTuple>(m_data));
        }

        bool holds(tag<protocol::tunnel>&&) const override
        {
            return (holds_stat<protocol::tunnel, StatsTuple>(m_data));
        }

        bool holds(tag<protocol::inner_ethernet>&&) const override
        {
            return (holds_stat<protocol::inner_ethernet, StatsTuple>(m_data));
        }

        bool holds(tag<protocol::inner_ip>&&) const override
        {
            return (holds_stat<protocol::inner_ip, StatsTuple>(m_data));
        }

        bool holds(tag<protocol::inner_transport>&&) const override
        {
            return (holds_stat<protocol::inner_transport, StatsTuple>(m_data));
        }

        void update(const packet_type_flags values[],
                    uint16_t nb_values) const override
        {
            protocol::update(m_data, values, nb_values);
        }

        void dump(std::ostream& os) const override
        {
            protocol::dump(os, m_data);
        }

        mutable StatsTuple m_data;
    };

    std::shared_ptr<stats_concept> m_self;
};

enum class protocol_flags {
    none = 0,
    ethernet = (1 << 0),
    ip = (1 << 1),
    transport = (1 << 2),
    tunnel = (1 << 3),
    inner_ethernet = (1 << 4),
    inner_ip = (1 << 5),
    inner_transport = (1 << 6)
};

generic_protocol_counters
make_counters(openperf::utils::bit_flags<protocol_flags> flags);

enum protocol_flags to_protocol_flag(std::string_view name);
std::string_view to_name(enum protocol_flags);

openperf::utils::bit_flags<protocol_flags>
to_protocol_flags(const generic_protocol_counters&);

} // namespace openperf::packet::statistics

declare_enum_flags(openperf::packet::statistics::protocol_flags);

namespace openperf::packet::statistics {
inline constexpr auto all_protocol_counters =
    (protocol_flags::ethernet | protocol_flags::ip | protocol_flags::transport
     | protocol_flags::tunnel | protocol_flags::inner_ethernet
     | protocol_flags::inner_ip | protocol_flags::inner_transport);

}

#endif /* _OP_PACKET_PROTOCOL_STATISTICS_GENERIC_PROTOCOL_COUNTERS_HPP_ */
