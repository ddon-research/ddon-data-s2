#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cAreaExt.h"
#include "nCharacterData.h"
#include "sGUIExt.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cArcLoaderBase;
class cCharacterData;
class cOpeningMovie;
namespace nCharacterData { struct stCharacterName; }
class rSoundRequest;
class rSoundStreamRequest;
class uCharacterEdit;
class uCharacterSelect;
class uGUISystemMsg;

// Declarations
class aMenu;

// Type aliases from DWARF
using CHAR_NAME = nCharacterData::stCharacterName;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class aMenu : public cAreaExt
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
        MOVE_R0_GET_CHAR_LIST_REQ = 1,
        MOVE_R0_GET_CHAR_LIST_WAIT = 2,
        MOVE_R0_GET_CHAR_INFO_REQ = 3,
        MOVE_R0_GET_CHAR_ERROR = 4,
        MOVE_R0_DATA_LOAD = 5,
        MOVE_R0_CHAR_SELECT = 6,
        MOVE_R0_OP_MOVIE = 7,
        MOVE_R0_CHAR_EDIT = 8,
        MOVE_R0_CHAR_EDIT_END = 9,
        MOVE_R0_CREATE_CHAR_ERROR = 10,
        MOVE_R0_PREPARE_DECIDE_CHAR_REQ = 11,
        MOVE_R0_PREPARE_DECIDE_CHAR_WAIT = 12,
        MOVE_R0_LOGIN_WAIT_REQ = 13,
        MOVE_R0_LOGIN_WAIT_WAIT = 14,
        MOVE_R0_LOGIN_WAIT_CANCEL_WAIT = 15,
        MOVE_R0_DECIDE_GAME_SERVER = 16,
        MOVE_R0_GET_SESSION_KEY = 17,
        MOVE_R0_CONNECT_GAME_SERVER = 18,
        MOVE_R0_DISCONNECT_LOGIN_SERVER = 19,
        MOVE_R0_GET_GAME_SETTING_REQ = 20,
        MOVE_R0_GET_GAME_SETTING_WAIT = 21,
        MOVE_R0_DECIDE_CHAR_REQ = 22,
        MOVE_R0_DECIDE_CHAR_WAIT = 23,
        MOVE_R0_GET_STAGE_LIST_REQ = 24,
        MOVE_R0_GET_STAGE_LIST_WAIT = 25,
        MOVE_R0_GET_LOADING_INFO_REQ = 26,
        MOVE_R0_GET_LOADING_INFO_WAIT = 27,
        MOVE_R0_SERVER_LIST_INIT = 28,
        MOVE_R0_SERVER_LIST_MOVE = 29,
        MOVE_R0_DISCONNECT_GAME_SERVER = 30,
        MOVE_R0_CONNECT_LOGIN_SERVER = 31,
        MOVE_R0_TO_LOBBY = 32,
        MOVE_R0_WAIT_TO_LOBBY = 33,
        MOVE_R0_LOBBY_ERROR = 34,
        MOVE_R0_TO_TITLE = 35,
        MOVE_R0_WAIT_TO_TITLE = 36,
    };
    enum
    {
        MOVE_R1_MOVIE_INIT = 0,
        MOVE_R1_MOVIE_FADE_WAIT = 1,
        MOVE_R1_MOVIE_FADE_WAIT_SETUP = 2,
        MOVE_R1_MOVIE_MOVE = 3,
        MOVE_R1_MOVIE_END_INIT = 4,
        MOVE_R1_MOVIE_END_LOOP = 5,
        MOVE_R1_MOVIE_CHICE_MODE = 6,
    };
    enum
    {
        MOVIE_RESULT_CONTINUE = 0,
        MOVIE_RESULT_END = 1,
        MOVIE_RESULT_NEW_END = 2,
    };
    enum
    {
        MOVE_R1_TO_TUTORIAL_STAGE_INIT = 0,
        MOVE_R1_TO_TUTORIAL_STAGE_MOVE = 1,
    };
    enum
    {
        TO_TUTORIAL_STAGE_RESULT_CONTINUE = 0,
        TO_TUTORIAL_STAGE_RESULT_END = 1,
        TO_TUTORIAL_STAGE_RESULT_ERROR = 2,
    };
    enum
    {
        DECIDE_GAME_SERVER_R1_INIT = 0,
        DECIDE_GAME_SERVER_R1_MOVE = 1,
        DECIDE_GAME_SERVER_R1_EXIT_SUCCESS = 2,
        DECIDE_GAME_SERVER_R1_EXIT_FAILED = 99,
    };
    enum
    {
        GET_SESSION_KEY_R1_INIT = 0,
        GET_SESSION_KEY_R1_REQ = 1,
        GET_SESSION_KEY_R1_WAIT = 2,
        GET_SESSION_KEY_R1_EXIT_SUCCESS = 3,
        GET_SESSION_KEY_R1_EXIT_FAILED = 99,
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
        CONNECT_GAME_R1_INIT = 0,
        CONNECT_GAME_R1_CONNECT_REQ = 1,
        CONNECT_GAME_R1_CONNECT_WAIT = 2,
        CONNECT_GAME_R1_OPEN_KEY_WAIT = 3,
        CONNECT_GAME_R1_HAND_SHAKE_REQ = 4,
        CONNECT_GAME_R1_HAND_SHAKE_WAIT = 5,
        CONNECT_GAME_R1_LOGIN_REQ = 6,
        CONNECT_GAME_R1_LOGIN_WAIT = 7,
        CONNECT_GAME_R1_EXIT_SUCCESS = 8,
        CONNECT_GAME_R1_EXIT_FAILED = 99,
    };
    enum
    {
        DISCONNECT_LOGIN_R1_INIT = 0,
        DISCONNECT_LOGIN_R1_LOGOUT_REQ = 1,
        DISCONNECT_LOGIN_R1_LOGOUT_WAIT = 2,
        DISCONNECT_LOGIN_R1_DISCONNECT_REQ = 3,
        DISCONNECT_LOGIN_R1_DISCONNECT_WAIT = 4,
        DISCONNECT_LOGIN_R1_EXIT_SUCCESS = 5,
        DISCONNECT_LOGIN_R1_EXIT_FAILED = 99,
    };
    enum
    {
        DISCONNECT_GAME_R1_INIT = 0,
        DISCONNECT_GAME_R1_LOGOUT_REQ = 1,
        DISCONNECT_GAME_R1_DISCONNECT_WAIT = 2,
        DISCONNECT_GAME_R1_EXIT_SUCCESS = 3,
        DISCONNECT_GAME_R1_EXIT_FAILED = 99,
    };
    enum
    {
        CONNECT_LOGIN_R1_INIT = 0,
        CONNECT_LOGIN_R1_CONNECT_REQ = 1,
        CONNECT_LOGIN_R1_CONNECT_WAIT = 2,
        CONNECT_LOGIN_R1_EXIT_SUCCESS = 3,
        CONNECT_LOGIN_R1_EXIT_FAILED = 99,
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
    aMenu();
    virtual ~aMenu();
    virtual bool load();  // vtable slot 6
    virtual void init();  // vtable slot 7
    virtual void move();  // vtable slot 8
    virtual void final();  // vtable slot 9
    virtual const MtDTI& getParentType();  // vtable slot 10
    virtual MT_CTSTR getShaderSegment();  // vtable slot 12
    rSoundRequest* getMenuSe();
private:
    void loadSoundResource();
    void releaseSoundResource();
    void checkBgmTitleToMenu();
protected:
    void initMovie();
    s32 moveMovie();
    void initJumpToTutorialStage();
    s32 moveJumpToTutorialStage();
private:
    s32 moveDecideGameServer();
    s32 moveGetSessionkey();
    s32 moveConnectGameServer();
    s32 moveDisconnectLoginServer();
    s32 moveDisconnectGameServer();
    s32 moveConnectLoginServer();
    void resetFlow();
private:
    TICKET mArcTicket;  // offset: 0x30
    rSoundStreamRequest* mprTitleBGM;  // offset: 0x38
    u32 mDialogHandle;  // offset: 0x40
    s32 mCharCursor;  // offset: 0x44
    s32 mCharNum;  // offset: 0x48
    s32 mElementNum;  // offset: 0x4c
    bool mIsNewCreate;  // offset: 0x50
    bool mIsClanNotice;  // offset: 0x51
    u32 mOldLoginWaitNum;  // offset: 0x54
    f32 mLoginWaitTimer;  // offset: 0x58
    uGUISystemMsg* mpGUISystemMsgLoginWait;  // offset: 0x60
    uGUISystemMsg* mpGUISystemMsgCancelWait;  // offset: 0x68
    uCharacterSelect* mpCharacterSelect;  // offset: 0x70
    cCharacterData* mpCharData;  // offset: 0x78
    CHAR_NAME mCharacterName;  // offset: 0x80
    MT_CHAR mCharFirstNameSjis[13];  // offset: 0x96
    MT_CHAR mCharLastNameSjis[9];  // offset: 0xa3
    cOpeningMovie* mpOpening;  // offset: 0xb0
    bool mIsBgmCall;  // offset: 0xb8
    uCharacterEdit* mpCharacterEdit;  // offset: 0xc0
    sGUIExt::cDialog mGUIDialog;  // offset: 0xc8
    rSoundRequest* mpSE;  // offset: 0xd0
    bool mLoadNgFlag;  // offset: 0xd8
public:
    static MyDTI DTI;
};

inline void* aMenu::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline rSoundRequest* aMenu::getMenuSe() {
    return this->mpSE;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/rSoundStreamRequest.h"

inline void aMenu::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::aMenu::DTI)->memFree(p_addr);
}

inline void aMenu::releaseSoundResource() {
    if (this->mprTitleBGM == nullptr) {
        return;
    }
    this->mprTitleBGM->::cResource::release();
    this->mprTitleBGM = nullptr;
}
