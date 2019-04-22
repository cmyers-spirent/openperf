#ifndef _ICP_SOCKET_PBUF_VEC_H_
#define _ICP_SOCKET_PBUF_VEC_H_

#include <cstdint>

struct pbuf;

namespace icp {
namespace socket {

class pbuf_vec
{
    /*
     * We store the length in the upper byte of the pbuf and payload pointers.
     * When machines use more than 48 bits for addressing we can update this. :)
     */
    static constexpr uintptr_t ptr_mask = 0xffffffffffff;
    static constexpr int ptr_shift = 56;
    pbuf* m_pbuf;
    void* m_payload;

public:
    pbuf_vec();
    pbuf_vec(pbuf* pbuf, void* payload, uint16_t len);

    pbuf* pbuf() const;

    void* payload() const;
    void  payload(void* addr);

    uint16_t len() const;
    void len(uint16_t len);

};

}
}
#endif /* _ICP_SOCKET_PBUF_VEC_H_ */
