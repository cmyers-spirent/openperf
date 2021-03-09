#ifndef _OP_ETHDEV_AF_PACKET_HPP_
#define _OP_ETHDEV_AF_PACKET_HPP_

/**
 * The hook_af_packet_ethdev() function hooks an af_packet rte_eth_dev
 * so that it supports waiting on rxq "interrupts".
 *
 * It should be called before the rte_eth_dev_configure() function which
 * enables the rxq interrupts.
 */
int hook_af_packet_ethdev(uint16_t port);

/**
 * The unhook_af_packet_ethdev() removes the hooks added by the
 * hook_af_packet_ethdev() function.
 */
void unhook_af_packet_ethdev(uint16_t port);

#endif