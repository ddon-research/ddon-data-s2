#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cPlatformUtilCommon.h"
#include "cSystem.h"
#include "cUserManagerListener.h"

// Forward declarations
class MtPropertyList;

// Declarations
class cGuideListener;
class sGuideBase;

// Type aliases from DWARF
using DWORD = unsigned int;
using s32 = int;
using u32 = unsigned int;
using u8 = unsigned char;

class cGuideListener
{
protected:
    virtual ~cGuideListener() {}
    virtual void onSystemUIDispChanged(bool) = 0;  // vtable slot 2
    virtual void onSigninLevelChanged(s32) = 0;  // vtable slot 3
    virtual void onServiceConnectionChanged(void*) = 0;  // vtable slot 4
    virtual void onInviteAccepted(s32) = 0;  // vtable slot 5
    virtual void onPhysicalLinkChanged(bool) = 0;  // vtable slot 6
    virtual void onFriendListChanged(s32, s32) = 0;  // vtable slot 7
    virtual void onAppSuspend() = 0;  // vtable slot 8
    virtual void onAppShutdown() = 0;  // vtable slot 9
};

class sGuideBase : public cSystem, public cGuideListener, public cUserManagerListener
{
public:
    sGuideBase();
    virtual ~sGuideBase();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 7
    virtual void addUser(s32 user_index, s32 user_id);  // vtable slot 10
    virtual void removeUser(s32 user_index, s32 user_id);  // vtable slot 11
protected:
    virtual void onSystemService(const char* pparam, const u32 size, const u8* parg, nPlatformUtil::nSystemService::CALL_TYPE::TYPE call_type);  // vtable slot 12
    void updateNet(DWORD notifyID, long unsigned int param);
private:
    virtual void moveEx() {}  // vtable slot 13
    virtual void onNotifyEvent(u32 notifyID, u32 param) {}  // vtable slot 14
    void initUser();
private:
    bool mIsInit;  // offset: 0x28
    static const u32 MAX_NATIVE_USER_ID = 4;
};
