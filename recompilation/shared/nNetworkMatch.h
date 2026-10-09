#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetSession.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class cRemoteCall;
namespace nNetwork { class RpcNetSystem_Entry; }
namespace nNetwork { class RpcNetSystem_Match; }
namespace nNetwork { class RpcNetSystem_Terminate; }
namespace nNetwork { class Session; }

// Declarations
namespace nNetwork { class Match; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nNetwork {
    class Match : public ::MtObject
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
        Match();
        // Address: 0x01bbbad0 - 0x01bbbad1 (1 bytes)
        virtual ~Match() {}
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
        virtual void move();  // vtable slot 6
        virtual void setup(nNetwork::Session* ps);  // vtable slot 7
        virtual void process(s32 src, cRemoteCall* prpc);  // vtable slot 8
        virtual void clear();  // vtable slot 9
        virtual void onJoinMember(s32 index, MtNetSession::Member* member);  // vtable slot 10
        virtual void onHostMemberChange(s32 index, MtNetSession::Member* member);  // vtable slot 11
        virtual bool tryEntry();  // vtable slot 12
        virtual bool tryCancel();  // vtable slot 13
        virtual bool tryMatch();  // vtable slot 14
        virtual bool tryTerminate();  // vtable slot 15
    private:
        void procEntry(nNetwork::RpcNetSystem_Entry& call, s32 member_index);
        void procMatch(nNetwork::RpcNetSystem_Match& call, s32 member_index);
        void procTerminate(nNetwork::RpcNetSystem_Terminate& call, s32 member_index);
    private:
        nNetwork::Session* mpSession;  // offset: 0x8
        bool mEntry;  // offset: 0x10
        bool mMatch;  // offset: 0x11
        bool mTerminate;  // offset: 0x12
    public:
        static MyDTI DTI;
    };
}  // namespace nNetwork
