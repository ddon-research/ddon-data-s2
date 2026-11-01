#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "cRemoteCall.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtStream;
namespace nNetwork { class SessionDatabase; }
namespace nNetwork { class Transport; }

// Declarations
namespace nNetwork { class RpcNetSystem_Entry; }
namespace nNetwork { class RpcNetSystem_LinkState; }
namespace nNetwork { class RpcNetSystem_Match; }
namespace nNetwork { class RpcNetSystem_RouteKey; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

namespace nNetwork {
    class RpcNetSystem_Entry : public ::cRemoteCall
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        static void usage();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        RpcNetSystem_Entry(bool entry);
        virtual void serialize(MtStream& stream);  // vtable slot 6
        virtual void deserialize(MtStream& stream);  // vtable slot 7
    public:
        bool mEntry;  // offset: 0xc
        static MyDTI DTI;
    };
}  // namespace nNetwork

namespace nNetwork {
    class RpcNetSystem_LinkState : public ::cRemoteCall
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        static void usage();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        RpcNetSystem_LinkState();
        virtual ~RpcNetSystem_LinkState();
        virtual void serialize(MtStream& stream);  // vtable slot 6
        virtual void deserialize(MtStream& stream);  // vtable slot 7
        void init(const nNetwork::SessionDatabase* pdb, const nNetwork::Transport* pt);
    public:
        u32 mHop[16];  // offset: 0xc
        u32 mRtt[16];  // offset: 0x4c
        u32 mRecoveryTime[16];  // offset: 0x8c
        u32 mForwardNum;  // offset: 0xcc
        u32 mForwardKeyList[16];  // offset: 0xd0
        u32 mForwardInterval[16];  // offset: 0x110
        static MyDTI DTI;
        static const u32 MAX_NUM_FORWARD = 16;
    };
}  // namespace nNetwork

namespace nNetwork {
    class RpcNetSystem_Match : public ::cRemoteCall
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        static void usage();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        RpcNetSystem_Match();
        virtual void serialize(MtStream& stream);  // vtable slot 6
        virtual void deserialize(MtStream& stream);  // vtable slot 7
        void init(const nNetwork::SessionDatabase* pdb);
    public:
        bool mMatch;  // offset: 0xc
        u64 mList;  // offset: 0x10
        static MyDTI DTI;
    };
}  // namespace nNetwork

namespace nNetwork {
    class RpcNetSystem_RouteKey : public ::cRemoteCall
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        static void usage();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        RpcNetSystem_RouteKey();
        virtual ~RpcNetSystem_RouteKey();
        virtual void serialize(MtStream& stream);  // vtable slot 6
        virtual void deserialize(MtStream& stream);  // vtable slot 7
    public:
        u32 mRouteKey;  // offset: 0xc
        u8 mInitConfig[64];  // offset: 0x10
        static MyDTI DTI;
    };
}  // namespace nNetwork

inline nNetwork::RpcNetSystem_LinkState::RpcNetSystem_LinkState() {
    this->::cRemoteCall::mAttribute = 0;
}

inline nNetwork::RpcNetSystem_RouteKey::RpcNetSystem_RouteKey() {
    this->::cRemoteCall::mAttribute = 0;
}
