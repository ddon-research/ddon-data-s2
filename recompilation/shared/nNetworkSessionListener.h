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
struct MtNetError;

// Declarations
namespace nNetwork { class SessionListener; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nNetwork {
    class SessionListener : public ::MtObject
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
        SessionListener();
        // Address: 0x01b86ec0 - 0x01b86ec1 (1 bytes)
        virtual ~SessionListener() {}
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
        // Address: 0x01b86f10 - 0x01b86f11 (1 bytes)
        virtual void onFinalize() {}  // vtable slot 6
        // Address: 0x01b86f20 - 0x01b86f21 (1 bytes)
        virtual void onDrop(MtNetError* err) {}  // vtable slot 7
        // Address: 0x01b86f30 - 0x01b86f31 (1 bytes)
        virtual void onJoinMember(s32 index, MtNetSession::Member* member) {}  // vtable slot 8
        // Address: 0x01b86f40 - 0x01b86f41 (1 bytes)
        virtual void onLeaveMember(s32 index, MtNetSession::Member* member) {}  // vtable slot 9
        // Address: 0x01b86f50 - 0x01b86f51 (1 bytes)
        virtual void onEntryMember(s32 index, bool entry) {}  // vtable slot 10
        // Address: 0x01a42560 - 0x01a42561 (1 bytes)
        virtual void onHostMemberChange(s32 index, MtNetSession::Member* member) {}  // vtable slot 11
        // Address: 0x01a42570 - 0x01a42571 (1 bytes)
        virtual void onSearchResult(MtNetSession::SearchResultList* list) {}  // vtable slot 12
        // Address: 0x01b86f60 - 0x01b86f61 (1 bytes)
        virtual void onCreateComplete(bool flag, MtNetError* err) {}  // vtable slot 13
        // Address: 0x01b86f70 - 0x01b86f71 (1 bytes)
        virtual void onSearchComplete(bool flag, MtNetError* err) {}  // vtable slot 14
        // Address: 0x01b86f80 - 0x01b86f81 (1 bytes)
        virtual void onJoinComplete(bool flag, MtNetError* err) {}  // vtable slot 15
        // Address: 0x01a42580 - 0x01a42581 (1 bytes)
        virtual void onLockComplete(bool flag, bool lock, MtNetError* err) {}  // vtable slot 16
        // Address: 0x01a42590 - 0x01a42591 (1 bytes)
        virtual void onMatch() {}  // vtable slot 17
        // Address: 0x01a425a0 - 0x01a425a1 (1 bytes)
        virtual void onTerminate() {}  // vtable slot 18
        // Address: 0x01b86f90 - 0x01b86f91 (1 bytes)
        virtual void onGameStart() {}  // vtable slot 19
        // Address: 0x01a425c0 - 0x01a425c1 (1 bytes)
        virtual void onGameEnd() {}  // vtable slot 20
        // Address: 0x01a425d0 - 0x01a425d1 (1 bytes)
        virtual void onInviteComplete() {}  // vtable slot 21
    public:
        static MyDTI DTI;
    };
}  // namespace nNetwork

// Inline, no code of its own: checked where it is inlined.
inline nNetwork::SessionListener::SessionListener() {
}
