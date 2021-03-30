#include "core/op_core.h"
#include "config/op_config_file.hpp"

const char op_packetio_dpdk_no_rx_irqs[] =
    "modules.packetio.dpdk.no-rx-interrupts";
const char op_packetio_dpdk_no_link_irqs[] =
    "modules.packetio.dpdk.no-link-interrupts";
const char op_packetio_dpdk_no_lro[] = "modules.packetio.dpdk.no-lro";
const char op_packetio_dpdk_test_mode[] = "modules.packetio.dpdk.test-mode";
const char op_packetio_dpdk_test_portpairs[] =
    "modules.packetio.dpdk.test-portpairs";
const char op_packetio_dpdk_stack_mbuf_count[] = "modules.packetio.dpdk.stack-mbuf-count";
const char op_packetio_dpdk_stack_mbuf_size[] = "modules.packetio.dpdk.stack-mbuf-size";

MAKE_OPTION_DATA(
    dpdk_primary,
    NULL,
    MAKE_OPT("enable test mode by creating loopback port pairs",
             op_packetio_dpdk_test_mode,
             0,
             OP_OPTION_TYPE_NONE),
    MAKE_OPT("number of loopback port pairs for testing, defaults to 1",
             op_packetio_dpdk_test_portpairs,
             0,
             OP_OPTION_TYPE_LONG),
    MAKE_OPT("disable receive queue interrupts",
             op_packetio_dpdk_no_rx_irqs,
             0,
             OP_OPTION_TYPE_NONE),
    MAKE_OPT("disable link state and speed change interrupts",
             op_packetio_dpdk_no_link_irqs,
             0,
             OP_OPTION_TYPE_NONE),
    MAKE_OPT("disable large receive offload",
             op_packetio_dpdk_no_lro,
             0,
             OP_OPTION_TYPE_NONE),
    MAKE_OPT("TCP/IP stack mbuf count, defaults to 4096",
             op_packetio_dpdk_stack_mbuf_count,
             0,
             OP_OPTION_TYPE_LONG),
    MAKE_OPT("TCP/IP stack mbuf size, ",
             op_packetio_dpdk_stack_mbuf_size,
             0,
             OP_OPTION_TYPE_LONG),
              );

REGISTER_CLI_OPTIONS(dpdk_primary)
