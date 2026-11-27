#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cAreaExt.h"
#include "cStageEpvCtrl.h"
#include "../../XFramework/rScheduler.h"
#include "res_ptr.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cArcLoaderBase;
class cStageEpvCtrl;
class rGUIMessage;
class rScheduler;
class rSoundStreamRequest;
class uGUIServerSelect;
class uGUITitle;
class uScheduler;

// Declarations
class aTitle;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class aTitle : public cAreaExt
{
public:
    enum
    {
        RNO_0_LOAD_INIT = 0,
        RNO_0_LOAD_MOVE = 1,
    };
    enum
    {
        MOVE_R0_INIT = 0,
        MOVE_R0_WEATHER_START = 1,
        MOVE_R0_FIRST_OPTION = 2,
        MOVE_R0_TITLE = 3,
        MOVE_R0_FINAL_WAIT = 4,
        MOVE_R0_CONNECT_CHECK = 5,
        MOVE_R0_START = 6,
        MOVE_R0_MOVE = 7,
        MOVE_R0_GET_SERVER_ENV_LIST = 8,
        MOVE_R0_SELECT_SERVER_ENV = 9,
        MOVE_R0_DEV_ACCOUNT = 10,
        MOVE_R0_LOGIN_BACK_DOOR = 11,
        MOVE_R0_VER_CHECK = 12,
        MOVE_R0_CONNECT_LOGIN_SERVER = 13,
        MOVE_R0_GET_ERROR_MESSAGE_LIST = 14,
        MOVE_R0_GET_GAME_SETTING = 15,
        MOVE_R0_GET_CHARGE_INFO = 16,
        MOVE_R0_TO_MENU = 17,
        MOVE_R0_TO_MENU_WAIT = 18,
        MOVE_R0_TO_LAUNCHER_WAIT = 19,
    };
    enum
    {
        BACK_SCHR_NUM = 10,
    };
    enum
    {
        MOVE_R1_INIT = 0,
        MOVE_R1_MOVE = 1,
        MOVE_R1_EXIT = 2,
        MOVE_R1_FAILED = 99,
    };
    enum
    {
        VER_CHECK_R1_INIT = 0,
        VER_CHECK_R1_TU_REQ = 1,
        VER_CHECK_R1_TU_WAIT = 2,
        VER_CHECK_R1_EXE_REQ = 3,
        VER_CHECK_R1_EXE_WAIT = 4,
        VER_CHECK_R1_DATA_REQ = 5,
        VER_CHECK_R1_DATA_WAIT = 6,
        VER_CHECK_R1_ERROR = 7,
        VER_CHECK_R1_EXIT_SUCCESS = 8,
        VER_CHECK_R1_EXIT_FAILED = 9,
    };
    enum
    {
        CONNECT_LOGIN_R1_INIT = 0,
        CONNECT_LOGIN_R1_CONNECT_REQ = 1,
        CONNECT_LOGIN_R1_CONNECT_WAIT = 2,
        CONNECT_LOGIN_R1_OPEN_KEY_WAIT = 3,
        CONNECT_LOGIN_R1_HAND_SHAKE_REQ = 4,
        CONNECT_LOGIN_R1_HAND_SHAKE_WAIT = 5,
        CONNECT_LOGIN_R1_LOGIN_REQ = 6,
        CONNECT_LOGIN_R1_LOGIN_WAIT = 7,
        CONNECT_LOGIN_R1_EXIT_SUCCESS = 8,
        CONNECT_LOGIN_R1_EXIT_FAILED = 99,
    };
    enum
    {
        GET_ERROR_MESSAGE_LIST_R1_INIT = 0,
        GET_ERROR_MESSAGE_LIST_R1_REQ = 1,
        GET_ERROR_MESSAGE_LIST_R1_WAIT = 2,
        GET_ERROR_MESSAGE_LIST_R1_EXIT_SUCCESS = 3,
        GET_ERROR_MESSAGE_LIST_R1_EXIT_FAILED = 99,
    };
    enum
    {
        GET_GAME_SETTING_R1_INIT = 0,
        GET_GAME_SETTING_R1_REQ = 1,
        GET_GAME_SETTING_R1_WAIT = 2,
        GET_GAME_SETTING_R1_EXIT_SUCCESS = 3,
        GET_GAME_SETTING_R1_EXIT_FAILED = 99,
    };
    enum
    {
        GET_CHARGE_INFO_R1_INIT = 0,
        GET_CHARGE_INFO_R1_REQ = 1,
        GET_CHARGE_INFO_R1_WAIT = 2,
        GET_CHARGE_INFO_R1_EXIT_SUCCESS = 3,
        GET_CHARGE_INFO_R1_EXIT_FAILED = 99,
    };
    enum
    {
        INPUT_ID_R2_INIT = 0,
        INPUT_ID_R2_SELECT = 1,
        INPUT_ID_R2_USER_ID = 2,
    };
    enum
    {
        INPUT_USER_ID = 0,
        INPUT_OK = 1,
        INPUT_MAX = 2,
    };
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
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
    aTitle();
    virtual ~aTitle();
    virtual bool load();  // vtable slot 6
    virtual void init();  // vtable slot 7
    virtual void move();  // vtable slot 8
    virtual void final();  // vtable slot 9
    virtual const MtDTI& getParentType();  // vtable slot 10
    virtual MT_CTSTR getShaderSegment();  // vtable slot 12
    void loadSoundResource();
    void releaseSoundResource();
private:
    void reqSystemMessageUI(MT_CTSTR pMsg, bool isButton);
    s32 moveVerCheck();
    s32 moveConnectLoginServer();
    s32 moveGetErrorMessageList();
    s32 moveGetGameSetting();
    s32 moveGetChargeInfo();
    void resetFlow();
    void initInputID();
    s32 moveInputID();
    void setKeyboardSetting(MT_CTSTR titleStr, MT_CTSTR defStr, s32 size);
    void loadResTitleWeather();
    void releaseTitleWeather();
    void beginTitleWeather();
    void updateTitleWeatherMain();
    void updateTitleWeatherReturnMovie();
    void endTitleWeather();
    void rndBackSchuduler();
private:
    TICKET mArcTicket;  // offset: 0x30
    uGUITitle* mpGUITitle;  // offset: 0x38
    rGUIMessage* mpSysGMDRes;  // offset: 0x40
    u32 mDialogHandle;  // offset: 0x48
    f32 mFTimer;  // offset: 0x4c
    s32 mInputCursor;  // offset: 0x50
    MT_CHAR mUserID[64];  // offset: 0x54
    MT_CHAR mPassword[64];  // offset: 0x94
    rSoundStreamRequest* mprTitleBGM;  // offset: 0xd8
    uGUIServerSelect* mpGUIServerSelect;  // offset: 0xe0
    bool mDebugDraw;  // offset: 0xe8
    cStageEpvCtrl mStageEpvCtrl;  // offset: 0xf0
    bool mIsEffectOffOld;  // offset: 0x1a0
    uScheduler* mpBackScheduler;  // offset: 0x1a8
    res_ptr<rScheduler> mBackSchedulerRes[10];  // offset: 0x1b0
    u32 mBackSchedulerNum;  // offset: 0x200
    bool mIsFirstOption;  // offset: 0x204
public:
    static MyDTI DTI;
protected:
    static const s32 USER_ID_SIZE_MAX = 64;
    static const s32 PASSWORD_SIZE_MAX = 64;
};

inline void* aTitle::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/rSoundStreamRequest.h"

inline void aTitle::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::aTitle::DTI)->memFree(p_addr);
}

inline void aTitle::releaseSoundResource() {
    if (this->mprTitleBGM == nullptr) {
        return;
    }
    this->mprTitleBGM->::cResource::release();
    this->mprTitleBGM = nullptr;
}
