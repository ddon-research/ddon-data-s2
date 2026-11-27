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
namespace nNetwork { class RpcNetSystem_AnsDetour; }
namespace nNetwork { class RpcNetSystem_Config; }
namespace nNetwork { class RpcNetSystem_Entry; }
namespace nNetwork { class RpcNetSystem_HealthCheck; }
namespace nNetwork { class RpcNetSystem_LinkState; }
namespace nNetwork { class RpcNetSystem_Match; }
namespace nNetwork { class RpcNetSystem_RouteKey; }
namespace nNetwork { class RpcNetSystem_RouteKeyAck; }
namespace nNetwork { class RpcNetSystem_Terminate; }
namespace nNetwork { class RpcNetSystem_TryConnect; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

namespace nNetwork {
    class RpcNetSystem_AnsDetour : public ::cRemoteCall
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
        RpcNetSystem_AnsDetour();
        virtual ~RpcNetSystem_AnsDetour();
        virtual void serialize(MtStream& stream);  // vtable slot 6
        virtual void deserialize(MtStream& stream);  // vtable slot 7
    public:
        u32 mForwardNum;  // offset: 0xc
        s32 mForward[16];  // offset: 0x10
        u32 mForwardInterval;  // offset: 0x50
        u8 mUniqueIdData[64];  // offset: 0x54
        static MyDTI DTI;
    };
}  // namespace nNetwork

namespace nNetwork {
    class RpcNetSystem_Config : public ::cRemoteCall
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
        RpcNetSystem_Config();
        virtual ~RpcNetSystem_Config();
        virtual void serialize(MtStream& stream);  // vtable slot 6
        virtual void deserialize(MtStream& stream);  // vtable slot 7
    public:
        u8 mDiff;  // offset: 0xc
        u8 mConfig[64];  // offset: 0xd
        static MyDTI DTI;
    };
}  // namespace nNetwork

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
    class RpcNetSystem_HealthCheck : public ::cRemoteCall
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
        RpcNetSystem_HealthCheck();
        virtual void serialize(MtStream& stream);  // vtable slot 6
        virtual void deserialize(MtStream& stream);  // vtable slot 7
    public:
        f32 mLossRate;  // offset: 0xc
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

namespace nNetwork {
    class RpcNetSystem_RouteKeyAck : public ::cRemoteCall
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
        RpcNetSystem_RouteKeyAck();
        virtual ~RpcNetSystem_RouteKeyAck();
        virtual void serialize(MtStream& stream) {}  // vtable slot 6
        virtual void deserialize(MtStream& stream) {}  // vtable slot 7
    public:
        static MyDTI DTI;
    };
}  // namespace nNetwork

namespace nNetwork {
    class RpcNetSystem_Terminate : public ::cRemoteCall
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
        RpcNetSystem_Terminate();
        virtual void serialize(MtStream& stream);  // vtable slot 6
        virtual void deserialize(MtStream& stream);  // vtable slot 7
        void init(const nNetwork::SessionDatabase* pdb);
    public:
        bool mTerminate;  // offset: 0xc
        u64 mList;  // offset: 0x10
        static MyDTI DTI;
    };
}  // namespace nNetwork

namespace nNetwork {
    class RpcNetSystem_TryConnect : public ::cRemoteCall
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
        RpcNetSystem_TryConnect();
        virtual ~RpcNetSystem_TryConnect();
        virtual void serialize(MtStream& stream) {}  // vtable slot 6
        virtual void deserialize(MtStream& stream) {}  // vtable slot 7
    public:
        static MyDTI DTI;
    };
}  // namespace nNetwork

inline void* nNetwork::RpcNetSystem_AnsDetour::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline nNetwork::RpcNetSystem_AnsDetour::RpcNetSystem_AnsDetour() {
    this->::cRemoteCall::mAttribute = 0;
}

inline void* nNetwork::RpcNetSystem_Config::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline nNetwork::RpcNetSystem_Config::RpcNetSystem_Config() {
    this->::cRemoteCall::mAttribute = 0;
}

inline void* nNetwork::RpcNetSystem_Entry::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nNetwork::RpcNetSystem_HealthCheck::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nNetwork::RpcNetSystem_LinkState::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline nNetwork::RpcNetSystem_LinkState::RpcNetSystem_LinkState() {
    this->::cRemoteCall::mAttribute = 0;
}

inline void* nNetwork::RpcNetSystem_Match::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nNetwork::RpcNetSystem_RouteKey::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline nNetwork::RpcNetSystem_RouteKey::RpcNetSystem_RouteKey() {
    this->::cRemoteCall::mAttribute = 0;
}

inline void* nNetwork::RpcNetSystem_RouteKeyAck::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nNetwork::RpcNetSystem_Terminate::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* nNetwork::RpcNetSystem_TryConnect::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void* nNetwork::RpcNetSystem_AnsDetour::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nNetwork::RpcNetSystem_AnsDetour::DTI)->memAlloc(sz, align, ::nNetwork::RpcNetSystem_AnsDetour::DTI.::MtDTI::mID);
}

inline void nNetwork::RpcNetSystem_AnsDetour::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nNetwork::RpcNetSystem_AnsDetour::DTI)->memFree(p_addr);
}

inline void* nNetwork::RpcNetSystem_Config::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nNetwork::RpcNetSystem_Config::DTI)->memAlloc(sz, align, ::nNetwork::RpcNetSystem_Config::DTI.::MtDTI::mID);
}

inline void nNetwork::RpcNetSystem_Config::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nNetwork::RpcNetSystem_Config::DTI)->memFree(p_addr);
}

inline void nNetwork::RpcNetSystem_Entry::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nNetwork::RpcNetSystem_Entry::DTI)->memFree(p_addr);
}

inline void nNetwork::RpcNetSystem_HealthCheck::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nNetwork::RpcNetSystem_HealthCheck::DTI)->memFree(p_addr);
}

inline void* nNetwork::RpcNetSystem_LinkState::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nNetwork::RpcNetSystem_LinkState::DTI)->memAlloc(sz, align, ::nNetwork::RpcNetSystem_LinkState::DTI.::MtDTI::mID);
}

inline void nNetwork::RpcNetSystem_LinkState::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nNetwork::RpcNetSystem_LinkState::DTI)->memFree(p_addr);
}

inline void* nNetwork::RpcNetSystem_Match::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nNetwork::RpcNetSystem_Match::DTI)->memAlloc(sz, align, ::nNetwork::RpcNetSystem_Match::DTI.::MtDTI::mID);
}

inline void nNetwork::RpcNetSystem_Match::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nNetwork::RpcNetSystem_Match::DTI)->memFree(p_addr);
}

inline void* nNetwork::RpcNetSystem_RouteKey::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nNetwork::RpcNetSystem_RouteKey::DTI)->memAlloc(sz, align, ::nNetwork::RpcNetSystem_RouteKey::DTI.::MtDTI::mID);
}

inline void nNetwork::RpcNetSystem_RouteKey::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nNetwork::RpcNetSystem_RouteKey::DTI)->memFree(p_addr);
}

inline void* nNetwork::RpcNetSystem_Terminate::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nNetwork::RpcNetSystem_Terminate::DTI)->memAlloc(sz, align, ::nNetwork::RpcNetSystem_Terminate::DTI.::MtDTI::mID);
}

inline void nNetwork::RpcNetSystem_Terminate::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nNetwork::RpcNetSystem_Terminate::DTI)->memFree(p_addr);
}
