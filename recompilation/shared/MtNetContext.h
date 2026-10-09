#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtNetObject.h"
#include "MtNetRequest.h"

// Forward declarations
struct MtNetError;
class MtNetFriendList;
struct MtNetIpAddress;
struct MtNetPhysicalAddress;
class MtNetRequest;
class MtNetRequestController;
struct MtNetSessionInfo;
class MtNetUniqueId;
class MtTime;

// Declarations
class MtNetContext;

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;

class MtNetContext : public MtNetObject, public MtNetRequestController::Listener
{
public:
    enum
    {
        SIGN_IN_LEVEL_NONE = 0,
        SIGN_IN_LEVEL_USER = 1,
        SIGN_IN_LEVEL_AUTH = 2,
    };
public:
    class Listener;
public:
    class Listener
    {
    public:
        Listener();
        virtual ~Listener() {}
        virtual void onNtcDestruct();  // vtable slot 2
        virtual void onNtcSignInChange(s32 sign_in_level, MtNetError* net_err);  // vtable slot 3
        virtual void onNtcFriendListChange(MtNetFriendList* friend_list);  // vtable slot 4
        virtual void onNtcInviteAccept();  // vtable slot 5
        virtual void onNtcInviteAcceptSucceed(MtNetSessionInfo* info);  // vtable slot 6
        virtual void onNtcInviteAcceptFail(MtNetError* net_err);  // vtable slot 7
        virtual void onAnsStartSucceed(u32 req_seq, s32 sign_in_level);  // vtable slot 8
        virtual void onAnsStartFail(u32 req_seq, MtNetError* net_err);  // vtable slot 9
        virtual void onAnsFinalize(u32 req_seq);  // vtable slot 10
    };
public:
    MtNetContext(s32 user_index);
    virtual ~MtNetContext();
    void addDependency(MtNetObject* obj);
    void removeDependency(MtNetObject* obj);
    void addListener(Listener* listener);
    void removeListener(Listener* listener);
    virtual void move() = 0;  // vtable slot 11
    s32 getUserIndex() const;
    virtual void getUniqueId(MtNetUniqueId*) = 0;  // vtable slot 12
    virtual s32 getSignInLevel() const = 0;  // vtable slot 13
    virtual bool isAllowedMultiplay() const = 0;  // vtable slot 14
    virtual bool isIpObtained() const = 0;  // vtable slot 15
    virtual bool isPhysicalLink() const = 0;  // vtable slot 16
    virtual s32 getIpAddressSelfNum() const = 0;  // vtable slot 17
    virtual void getIpAddressSelf(s32, MtNetIpAddress*) const = 0;  // vtable slot 18
    virtual s32 getPhysicalAddressSelfNum() const = 0;  // vtable slot 19
    virtual void getPhysicalAddressSelf(s32, MtNetPhysicalAddress*) const = 0;  // vtable slot 20
    virtual void setAddressIndex(s32) = 0;  // vtable slot 21
    virtual s32 getAddressIndex() const = 0;  // vtable slot 22
    virtual s32 getCountry() const = 0;  // vtable slot 23
    virtual MtNetFriendList* getFriendList() = 0;  // vtable slot 24
    virtual bool getTime(MtTime*) = 0;  // vtable slot 25
    void reqStart(u32* req_seq, s32 sign_in_level);
    void reqFinalize(u32* req_seq);
    virtual void onGuideOpen(bool) = 0;  // vtable slot 26
    virtual void onGuideSignInChanged(s32) = 0;  // vtable slot 27
    virtual void onGuideConnectionChanged(void*) = 0;  // vtable slot 28
    virtual void onGuideInviteAccepted(s32) = 0;  // vtable slot 29
    virtual void onGuidePhysicalLinkChanged(bool) = 0;  // vtable slot 30
    virtual void onGuideFriendListChanged(s32, s32) = 0;  // vtable slot 31
    virtual void onGuideAppSuspend() = 0;  // vtable slot 32
    virtual void onGuideAppShutdown() = 0;  // vtable slot 33
protected:
    void beginDestruct();
    void beginMove();
    void endMove();
    void cbNtcSignInChange(s32 sign_in_level, MtNetError* net_err);
    void cbNtcFriendListChange(MtNetFriendList* friend_list);
    void cbNtcInviteAccept();
    void cbNtcInviteAcceptSucceed(MtNetSessionInfo* info);
    void cbNtcInviteAcceptFail(MtNetError* net_err);
    void cbAnsStartSucceed(MtNetRequest* req, s32 sign_in_level);
    void cbAnsStartFail(MtNetRequest* req, MtNetError* net_err);
    void cbAnsFinalize(MtNetRequest* req);
    virtual s32 moveStart(MtNetRequest*) = 0;  // vtable slot 34
    virtual s32 moveFinalize(MtNetRequest*) = 0;  // vtable slot 35
private:
    virtual bool canMoveRequest(MtNetRequest* req);  // vtable slot 36
    virtual s32 startRequest(MtNetRequest* req);  // vtable slot 37
    virtual s32 moveRequest(MtNetRequest* req);  // vtable slot 38
    virtual void endRequest(MtNetRequest* req);  // vtable slot 39
    virtual void startFailRequest(MtNetRequest* req);  // vtable slot 40
    s32 startEmpty(MtNetRequest* req);
    void endEmpty(MtNetRequest* req);
protected:
    MtNetRequestController mRequestController;  // offset: 0x30
    bool mIsDestructor;  // offset: 0xa8
private:
    MtNetObject* mpDependObject[4];  // offset: 0xb0
    Listener* mpListener;  // offset: 0xd0
    s32 mUserIndex;  // offset: 0xd8
    bool mIsNeedFinalize;  // offset: 0xdc
protected:
    static const s32 MAX_NUM_DEPEND_OBJECT = 4;
    static const s32 REQUEST_ID_START = 257;
    static const s32 REQUEST_ID_FINALIZE = 258;
};
