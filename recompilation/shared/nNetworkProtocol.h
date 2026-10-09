#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class MtString;
namespace nNetwork { class PacketReader; }
namespace nNetwork { class PacketWriter; }
namespace nNetwork { class Route; }
namespace nNetwork { class Session; }

// Declarations
namespace nNetwork { class Protocol; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nNetwork {
    class Protocol : public ::MtObject
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
        Protocol(MT_CTSTR name, bool system, bool broadcast);
        virtual ~Protocol() {}
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
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual void setup(nNetwork::Session* ps);  // vtable slot 6
        virtual void move();  // vtable slot 7
        virtual void create(s32 index);  // vtable slot 8
        virtual void remove(s32 index);  // vtable slot 9
        virtual bool put(const void*, u32, s32, u32, u32, s32) = 0;  // vtable slot 10
        virtual bool get(s32, nNetwork::PacketWriter&, u32, const nNetwork::Route*) = 0;  // vtable slot 11
        virtual void receive(s32, nNetwork::PacketReader&) = 0;  // vtable slot 12
        virtual void dbgGetSummary(s32 index, MtString& sum);  // vtable slot 13
        bool isSystem() const;
        bool isBroadcast() const;
    protected:
        u32 getRpc(const void* data_ptr, u32 param) const;
        void recTag(s32 route_index, u32 tag);
        void recRtt(s32 route_index, u32 rtt);
        void recQueueDelay(s32 route_index, u32 delay);
        void process(u32 callback, s32 index, const void* data_ptr, u32 data_size);
    protected:
        bool mSystem;  // offset: 0x8
        bool mBroadcast;  // offset: 0x9
        nNetwork::Session* mpSession;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
}  // namespace nNetwork
