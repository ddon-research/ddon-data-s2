#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtNetDevice.h"
#include "MtNetSocket.h"

// Forward declarations
struct MtNetAddress;
struct MtNetIpAddress;
class MtPropertyList;

// Declarations
namespace MtNet { namespace PS4Psn { class Socket; } }

// Type aliases from DWARF
using SceNetId = int;
using s32 = int;
using u32 = unsigned int;
using u8 = unsigned char;

namespace MtNet {
    namespace PS4Psn {
        class Socket : public ::MtNetSocket
        {
        public:
            virtual ~Socket();
            virtual void createProperty(MtPropertyList& s);  // vtable slot 4
            virtual void setIpAddressAny(MtNetIpAddress* addr);  // vtable slot 11
            virtual bool isIpAddressAny(const MtNetIpAddress* addr);  // vtable slot 12
            virtual void setIpAddressBroadcast(MtNetIpAddress* addr);  // vtable slot 13
            virtual bool isIpAddressBroadcast(const MtNetIpAddress* addr);  // vtable slot 14
            virtual bool isEable() const;  // vtable slot 15
            virtual void getInfoSelf(MtNetAddress* self) const;  // vtable slot 16
            virtual void getInfoPeer(MtNetAddress* peer) const;  // vtable slot 17
            virtual s32 getType() const;  // vtable slot 18
            virtual s32 startConnect(MtNetAddress* peer);  // vtable slot 19
            virtual s32 pollConnect();  // vtable slot 20
            virtual s32 listen(MtNetAddress* self);  // vtable slot 21
            virtual s32 accept(MtNetSocket* * accept_socket);  // vtable slot 22
            virtual s32 receive(MtNetAddress* peer, void* buf_ptr, s32 buf_size);  // vtable slot 23
            virtual s32 send(const MtNetAddress* peer, const void* data_ptr, s32 data_size);  // vtable slot 24
        private:
            Socket();
            Socket(s32 type, u32 option);
            Socket(const char* peer_name, const void* ca_data, s32 ca_size);
            void commonConstructor(s32 type, u32 option);
            void newSocket();
            void setOption();
        private:
            MtNetAddress mAddressSelf;  // offset: 0x24
            MtNetAddress mAddressPeer;  // offset: 0x2a
            SceNetId mSocket;  // offset: 0x30
            s32 mType;  // offset: 0x34
            u32 mOption;  // offset: 0x38
            u8 mTempRecvBuffer[1536];  // offset: 0x3c
            bool mIsEnable;  // offset: 0x63c
        public:
            static const s32 MAX_SIZE_PACKET = 1536;
        };
    }  // namespace PS4Psn
}  // namespace MtNet
