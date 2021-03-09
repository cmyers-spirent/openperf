#!/bin/env python3
#
# Create a .h file from the rte_eth_af_packet.c file containing
# private structures so can be used to access private members.
#
import os
import sys

file_begin_fmt = \
"""#ifndef _%(GUARD)s_
#define _%(GUARD)s_

#ifdef __cplusplus__
extern "C" {
#endif /* __cplusplus__ */

"""

file_end_fmt = \
"""
#ifdef __cplusplus__
}
#endif /* __cplusplus__ */

#endif /*  _%(GUARD)s_ */
"""

def write_header_file(src_file, dst_file):
    found = False
    guard = os.path.basename(dst_file).replace('.', '_').upper()
    # Copy everything between RTE_PMD_AF_PACKET_MAX_RINGS define and 1st static keyword
    with open(src_file, 'r') as sf, open(dst_file, 'w') as df:
        df.write(file_begin_fmt % {'GUARD': guard})
        for line in sf:
            if not found:
                if line.startswith('#define RTE_PMD_AF_PACKET_MAX_RINGS'):
                    found = True
                    df.write(line)
            else:
                if line.startswith('static'):
                    break
                df.write(line)
        df.write(file_end_fmt % {'GUARD': guard})

write_header_file(sys.argv[1], sys.argv[2])
