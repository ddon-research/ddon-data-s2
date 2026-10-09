#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtStlAllocator.h"
#include "../shared/MtStlCustom.h"
#include "../shared/cSystem.h"
#include "user_service_api.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
struct SceUserServiceLoginUserIdList;
class cUserManagerListener;

// Declarations
class sUserManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using __int32_t = int;
using int32_t = __int32_t;
using SceUserServiceUserId = int32_t;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sUserManager : public cSystem
{
public:
    class MyDTI;
    struct GamepadInfo;
    class UserInfo;
public:
    using EventListenerSet = MtStlSet<cUserManagerListener*, MtStlAllocator<cUserManagerListener*> >;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct GamepadInfo
    {
        // inferred: sUserManager::isPadConnected names sUserManager::UserInfo::mPad.mIsConnected
        friend class sUserManager;
    public:
        void clear();
        u32 getUserId();
        bool isConnected();
        s32 getHandler();
        s32 getPortType();
    private:
        void initialize();
        void connectPad(s32 ID, s32 ScePadPortType);
        void checkPadConnection();
    private:
        bool mIsConnected;  // offset: 0x0
        s32 mHandler;  // offset: 0x4
        s32 mPortType;  // offset: 0x8
        s32 mUserId;  // offset: 0xc
    };
public:
    class UserInfo
    {
        // inferred: sUserManager::getUserId names sUserManager::UserInfo::mId
        friend class sUserManager;
    public:
        s32 getUserId();
        void clear();
        bool isGuest();
        bool isLogin();
        MT_CTSTR getUserName();
        s32 getPadHandler();
        bool isPadConnected();
        s32 getPadSpecHandler();
        bool isPadSpecConnected();
    private:
        UserInfo();
        UserInfo(s32 ID);
        void initialize();
        void makeUser(s32 ID);
        void checkPadConnection();
    private:
        s32 mId;  // offset: 0x0
        bool mIsLogin;  // offset: 0x4
        bool mIsGuest;  // offset: 0x5
        MT_CHAR mUserName[17];  // offset: 0x6
        SceUserServiceUserColor mColor;  // offset: 0x18
        sUserManager::GamepadInfo mPad;  // offset: 0x1c
        sUserManager::GamepadInfo mPadSpec;  // offset: 0x2c
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
    sUserManager();
    virtual ~sUserManager();
    static sUserManager* getInstance();
    virtual void move();  // vtable slot 7
    void initializeInfo();
    s32 getUserNum();
    s32 getUserId(s32 UserNo);
    s32 getInitialUserId();
    bool isPadConnected(s32 padno);
    u32 getPadNum();
    MT_CTSTR getUserName(s32);
    bool isLogin(s32);
    bool isGuest(s32);
    void addListener(cUserManagerListener* listener);
    void removeListener(cUserManagerListener* listener);
    s32 getPadHandler(s32 userId);
    s32 getPadSpecHandler(s32 userId);
    s32 getUserIdFromPad(s32 PadHandle);
    s32 getPadRemoteHandler();
    bool isPadRemoteConnected();
    bool isPadSpecConnected(s32 userId);
    void showAccountPicker(u32 padno);
    u32 getState();
    u32 getResult();
private:
    void addUser(s32 id);
    void removeUser(s32 id);
    void checkUserLogEvent();
    void checkPadConnection();
private:
    s32 mUserNum;  // offset: 0x14
    EventListenerSet mListener;  // offset: 0x18
    SceUserServiceUserId mInitialUserId;  // offset: 0x30
    SceUserServiceLoginUserIdList mUserIdList;  // offset: 0x34
    GamepadInfo mPadTVRemote;  // offset: 0x44
    UserInfo mUser[4];  // offset: 0x54
public:
    static MyDTI DTI;
    static const u32 MAX_USER_NUMBER = 16;
private:
    static sUserManager* mpInstance;
};
