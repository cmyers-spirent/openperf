#ifndef _OP_PACKETIO_DPDK_PRIMARY_ARG_PARSER_HPP_
#define _OP_PACKETIO_DPDK_PRIMARY_ARG_PARSER_HPP_

#include "packetio/drivers/dpdk/arg_parser.hpp"

extern const char op_packetio_dpdk_no_lro[];
extern const char op_packetio_dpdk_no_rx_irqs[];
extern const char op_packetio_dpdk_no_link_irqs[];
extern const char op_packetio_dpdk_test_mode[];
extern const char op_packetio_dpdk_test_portpairs[];
extern const char op_packetio_dpdk_stack_mbuf_count[];
extern const char op_packetio_dpdk_stack_mbuf_size[];

namespace openperf::packetio::dpdk::config {

int dpdk_test_portpairs(); /**< Number of eth ring devs */
bool dpdk_test_mode();     /**< test mode enable/disable */

uint32_t
dpdk_stack_mbuf_count(); /**< Number of additional mbufs for TCP/IP stack */

std::optional<uint16_t>
dpdk_stack_mbuf_size(); /**< TCP/IP stack mbuf size in bytes */

} // namespace openperf::packetio::dpdk::config

#endif /* _OP_PACKETIO_DPDK_PRIMARY_ARG_PARSER_HPP_ */
