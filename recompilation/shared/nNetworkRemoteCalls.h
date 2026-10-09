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

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

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
