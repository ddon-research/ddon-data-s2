#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtNetSession.h"
#include "../MT/MtObject.h"

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
        virtual void onFinalize() {}  // vtable slot 6
        virtual void onDrop(MtNetError* err) {}  // vtable slot 7
        virtual void onJoinMember(s32 index, MtNetSession::Member* member) {}  // vtable slot 8
        virtual void onLeaveMember(s32 index, MtNetSession::Member* member) {}  // vtable slot 9
        virtual void onEntryMember(s32 index, bool entry) {}  // vtable slot 10
        virtual void onHostMemberChange(s32 index, MtNetSession::Member* member) {}  // vtable slot 11
        virtual void onSearchResult(MtNetSession::SearchResultList* list) {}  // vtable slot 12
        virtual void onCreateComplete(bool flag, MtNetError* err) {}  // vtable slot 13
        virtual void onSearchComplete(bool flag, MtNetError* err) {}  // vtable slot 14
        virtual void onJoinComplete(bool flag, MtNetError* err) {}  // vtable slot 15
        virtual void onLockComplete(bool flag, bool lock, MtNetError* err) {}  // vtable slot 16
        virtual void onMatch() {}  // vtable slot 17
        virtual void onTerminate() {}  // vtable slot 18
        virtual void onGameStart() {}  // vtable slot 19
        virtual void onGameEnd() {}  // vtable slot 20
        virtual void onInviteComplete() {}  // vtable slot 21
    public:
        static MyDTI DTI;
    };
}  // namespace nNetwork

inline nNetwork::SessionListener::SessionListener() {
}
