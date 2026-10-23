#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cRemoteCall.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtStream;
namespace nNetwork { class SessionDatabase; }

// Declarations
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

// Inline, no code of its own: checked where it is inlined.
// inferred: the constructor from _ZNK8nNetwork21RpcNetSystem_RouteKey5MyDTI11newInstanceEv at 0x0119cb40-0x0119cb65, code DWARF attributes to no inlined copy
inline nNetwork::RpcNetSystem_RouteKey::RpcNetSystem_RouteKey() {
    this->::cRemoteCall::mAttribute = static_cast<u32>(0);
}
