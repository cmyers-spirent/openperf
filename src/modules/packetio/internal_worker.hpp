#ifndef _OP_PACKETIO_INTERNAL_WORKER_HPP_
#define _OP_PACKETIO_INTERNAL_WORKER_HPP_

#include <inttypes.h>

/**
 * @file
 *
 * This file contains functions intended to be run from within packetio
 * worker threads.  Generally, these should be called from generic_{sink,source}
 * code that runs within the worker thread context.
 *
 * Calling these functions *outside* of a worker thread context is an error.
 */

namespace openperf::packetio::internal::worker {

/**
 * Retrieve the worker thread id
 *
 * @return
 *   value between [0, id_max)
 */
unsigned get_id();

/**
 * Retrieve the worker thread's numa node
 *
 * @return
 *   value between [0, numa_node_max)
 */
unsigned get_numa_node();

/**
 * Add TCP/IP stack socket reference for port.
 */
void stack_add_socket_ref(uint16_t port);

/**
 * Remove TCP/IP stack socket reference for port.
 */
void stack_remove_socket_ref(uint16_t port);

} // namespace openperf::packetio::internal::worker

#endif /* _OP_PACKETIO_INTERNAL_WORKER_HPP_ */
