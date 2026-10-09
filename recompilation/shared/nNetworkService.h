#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtNetContext.h"
#include "MtNetObject.h"
#include "MtNetSession.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtNetContext;
struct MtNetError;
class MtNetFriendList;
struct MtNetSessionInfo;
class MtProperty;
class MtPropertyList;
class MtUI;

// Declarations
namespace nNetwork { class Context; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nNetwork {
    class Context : public ::MtObject, public MtNetContext::Listener
    {
    public:
        enum
        {
            STATE_NULL = 0,
            STATE_BOOTUP = 1,
            STATE_NONE = 2,
            STATE_USER = 3,
            STATE_AUTH = 4,
            STATE_SHUTDOWN = 5,
            STATE_ERROR = 6,
        };
        enum
        {
            INVITE_NOT_ACCEPT = 0,
            INVITE_IN_PROGRESS = 1,
            INVITE_SUCCESS = 2,
            INVITE_FAILURE = 3,
        };
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
        Context();
        virtual ~Context();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        void move();
        void reset();
        void bootup();
        void suspend();
        void shutdown();
        s32 getState() const;
        void getServiceError(MtNetError* err) const;
        bool isBootup() const;
        bool isBound() const;
        bool isStart() const;
        MtNetContext* getContext();
        const MtNetContext* getContext() const;
        MtNetFriendList* getFriendList();
        void setService(s32 service);
        s32 getService() const;
        void setOption(s32 option);
        s32 getOption() const;
        void setUserIndex(u32 user_index);
        u32 getUserIndex() const;
        void setReqLevel(s32 lv);
        s32 getReqLevel() const;
        bool isFriendListChange() const;
        bool isSignInChange() const;
        s32 getInviteState() const;
        void getInviteSessionInfo(MtNetSessionInfo& info) const;
        void getInviteError(MtNetError& err) const;
        void clearInvitation();
    private:
        void tryFinal();
        void init();
        void updateServiceState(s32 level, MtNetError* net_err);
        void changeServiceState(s32 state, MtNetError* net_err);
        virtual void onNtcDestruct();  // vtable slot 6
        virtual void onNtcSignInChange(s32 sign_in_level, MtNetError* net_err);  // vtable slot 7
        virtual void onNtcFriendListChange(MtNetFriendList* friend_list);  // vtable slot 8
        virtual void onNtcInviteAccept();  // vtable slot 9
        virtual void onNtcInviteAcceptSucceed(MtNetSessionInfo* info);  // vtable slot 10
        virtual void onNtcInviteAcceptFail(MtNetError* net_err);  // vtable slot 11
        virtual void onAnsStartSucceed(u32 req_seq, s32 sign_in_level);  // vtable slot 12
        virtual void onAnsStartFail(u32 req_seq, MtNetError* net_err);  // vtable slot 13
        virtual void onAnsFinalize(u32 req_seq);  // vtable slot 14
    private:
        s32 mState;  // offset: 0x10
        MtNetContext* mpContext;  // offset: 0x18
        MtNetFriendList* mpFriendList;  // offset: 0x20
        MtNetError mServiceError;  // offset: 0x28
        s32 mService;  // offset: 0x34
        s32 mOption;  // offset: 0x38
        u32 mUserIndex;  // offset: 0x3c
        s32 mReqLevel;  // offset: 0x40
        u32 mReqStart;  // offset: 0x44
        u32 mReqFinal;  // offset: 0x48
        bool mStart;  // offset: 0x4c
        bool mFinal;  // offset: 0x4d
        bool mIsFriendListChange;  // offset: 0x4e
        bool mIsSignInChange;  // offset: 0x4f
        s32 mInviteState;  // offset: 0x50
        MtNetSessionInfo mInviteSessionInfo;  // offset: 0x58
        MtNetError mInviteError;  // offset: 0x260
        MtNetError mSignInError;  // offset: 0x26c
    public:
        static MyDTI DTI;
    };
}  // namespace nNetwork
