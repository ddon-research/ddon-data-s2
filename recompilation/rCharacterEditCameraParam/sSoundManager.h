#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/cSystem.h"
#include "../shared/nAbility.h"
#include "../shared/sSoundExt.h"
#include "../shared/sWeatherManager.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class rSoundAreaInfo;
class rSoundStreamRequest;
class uCharacter;
class uControlNpc;
class uDDOModel;

// Declarations
class sSoundManager;

namespace sBattleState {
    enum SYS_BATTLE_STATE
    {
        SYS_STATE_NORMAL = 0,
        SYS_STATE_BATTLE = 1,
        SYS_STATE_WIN = 2,
        SYS_STATE_ESCAPE = 3,
    };
}  // namespace sBattleState

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sSoundManager : public cSystem
{
public:
    enum
    {
        BTL_STATE_NONE = 0,
        BTL_STATE_STG = 1,
        BTL_STATE_CONT = 2,
        BTL_STATE_CONT_STG = 3,
        BTL_STATE_WIN = 4,
        BTL_STATE_ESCAPE = 5,
        BTL_STATE_LOSE = 6,
        BTL_STATE_TARGET_WIN = 7,
        BTL_STATE_TARGET_ESCAPE = 8,
        BTL_STATE_NEXT_TARGET = 9,
        BTL_STATE_REBORN = 10,
        BTL_STATE_REBORN_TO_PL = 11,
        BTL_STATE_END = 12,
        BTL_STATE_CHANGE = 13,
        BTL_STATE_ADV = 14,
        BTL_STATE_ADV_WIN = 15,
        BTL_STATE_ADV_TARGET_WIN = 16,
        BTL_STATE_NUM = 17,
    };
    enum
    {
        BTL_BGM_NONE = 0,
        BTL_BGM_ZAKO = 1,
        BTL_BGM_STG = 2,
        BTL_BGM_ORG_ZAKO = 3,
        BTL_BGM_SBB_BOSS = 4,
        BTL_BGM_ORG_BOSS = 5,
        BTL_BGM_CMN_BOSS = 6,
        BTL_BGM_RARE = 7,
        BTL_BGM_SQRARE = 8,
        BTL_BGM_ABILITY = 9,
        BTL_BGM_ERO = 10,
        BTL_BGM_NUM = 11,
    };
    enum
    {
        STG_STATE_NONE = 0,
        STG_STATE_NORMAL = 1,
        STG_STATE_BASE = 2,
        STG_STATE_BAR = 3,
        STG_STATE_JUKEBOX = 4,
        STG_STATE_JUKEBOX_CHG = 5,
        STG_STATE_NPC = 6,
        STG_STATE_EVENT = 7,
        STG_STATE_FSM = 8,
        STG_STATE_CYCLE = 9,
        STG_STATE_BTL = 10,
        STG_STATE_BAR_CHG = 11,
        STG_STATE_AMB_CHG = 12,
        STG_STATE_AREA_CHG = 13,
        STG_STATE_NUM = 14,
    };
    enum
    {
        STG_BGM_NONE = 0,
        STG_BGM_NORMAL = 1,
        STG_BGM_BASE = 2,
        STG_BGM_JUKEBOX = 3,
        STG_BGM_BAR = 4,
        STG_BGM_NPC = 5,
        STG_BGM_EVENT = 6,
        STG_BGM_FSM = 7,
        STG_BGM_CYCLE = 8,
        STG_BGM_NUM = 9,
    };
    enum
    {
        FSM_STATE_NONE = 0,
        FSM_STATE_NO_BTL = 1,
        FSM_STATE_EVENT = 2,
        FSM_STATE_STOP = 3,
        FSM_STATE_CHG = 4,
        FSM_STATE_RES = 5,
        FSM_STATE_NUM = 6,
    };
    enum
    {
        QST_STATE_NONE = 0,
        QST_STATE_BTL = 1,
        QST_STATE_ADV = 2,
        QST_STATE_WIN = 3,
        QST_STATE_CHG = 4,
        QST_STATE_CHG_AREA = 5,
        QST_STATE_BTL_LOSE = 6,
        QST_STATE_BTL_REBORN = 7,
        QST_STATE_BTL_REBORN_TO_PL = 8,
        QST_STATE_NUM = 9,
    };
    enum
    {
        RESOURCE_TYPE_INGAME = 0,
        RESOURCE_TYPE_STAGE = 1,
        RESOURCE_TYPE_BATTLE = 2,
        RESOURCE_TYPE_LOBBY = 3,
        RESOURCE_TYPE_NUM = 4,
    };
    enum
    {
        QST_BGM_TYPE_NONE = 0,
        QST_BGM_TYPE_ADV = 1,
        QST_BGM_TYPE_NUM = 2,
    };
    enum
    {
        EVT_STATE_NONE = 0,
        EVT_STATE_EVENT = 1,
        EVT_STATE_CHG = 2,
        EVT_STATE_NUM = 3,
    };
    enum
    {
        EM_RANK_NONE = 0,
        EM_RANK_DEAD = 1,
        EM_RANK_ESCAPE = 2,
        EM_RANK_ZAKO = 3,
        EM_RANK_ORG_ZAKO = 4,
        EM_RANK_ERO = 5,
        EM_RANK_ERO_BOSS = 6,
        EM_RANK_CMN_BOSS = 7,
        EM_RANK_SBB_BOSS = 8,
        EM_RANK_ORG_BOSS = 9,
        EM_RANK_RARE = 10,
        EM_RANK_RARE_BOSS = 11,
        EM_RANK_SQRARE = 12,
        EM_RANK_SQRARE_BOSS = 13,
        EM_RANK_NUM = 14,
    };
    enum
    {
        EM_STATE_NONE = 0,
        EM_STATE_BTL = 1,
        EM_STATE_WIN = 2,
        EM_STATE_ESCAPE = 3,
        EM_STATE_CHANGE = 4,
        EM_STATE_NUM = 5,
    };
public:
    class cEmSetState;
    class MyDTI;
public:
    class cEmSetState : public MtObject
    {
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
        cEmSetState();
        virtual ~cEmSetState();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void setEm(rSoundStreamRequest* pr);
        static bool sort(const sSoundManager::cEmSetState* _a, const sSoundManager::cEmSetState* _b, u32 param);
    public:
        u32 mEmRank;  // offset: 0x8
        rSoundStreamRequest* mprEm;  // offset: 0x10
        u32 mEmReqNo;  // offset: 0x18
        u32 mEmWinReqNo;  // offset: 0x1c
        bool mbUseAdv;  // offset: 0x20
        bool mbAdv;  // offset: 0x21
        bool mbBGMTarget;  // offset: 0x22
        uCharacter* mpuChr;  // offset: 0x28
        bool mbDead;  // offset: 0x30
        bool mbWin;  // offset: 0x31
        bool mbEscape;  // offset: 0x32
        static MyDTI DTI;
    };
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    bool isStageOK();
    void init_222();
    void final();
    void initStage();
    void startStage();
    void finalStage();
    void clear_222();
    void move_222();
    void startBtl();
    void stopBtl();
    void startStg();
    void stopStg();
    void startQuest();
    void stopQuest();
    u32 getBtlStateSnd(bool dying);
    void updateBtl();
    void updateBtlBGMTemp();
    void pauseBtlStg();
    void resumeBtlStg();
    void clrBtl();
    void releaseBtl();
    void setBtlStqr(rSoundStreamRequest* pr);
    void setBtlStqrWin(rSoundStreamRequest* pr);
    void pauseBtl();
    void resumeBtl(rSoundStreamRequest* prBtl, u32 reqNo);
    void flushBtl();
    bool isWinBGM();
    u32 getEmState();
    void updateEm();
    void clrEm();
    void releaseEm();
    u32 getBattleInfoNum() const;
    const uDDOModel* getBattleInfoUnit(u32 index) const;
    bool isExistBattleStateEnemyId(u32 emID);
    u32 getBattleStateAreaBossType() const;
    sBattleState::SYS_BATTLE_STATE getBattleState() const;
    void updateBtlState();
    void clrBtlState();
    u32 getStgState();
    void updateStg();
    void updateStgBGMTemp();
    void clrStg();
    void releaseStg();
    void setStgStqr(rSoundStreamRequest* pr);
    void stopStgBGM();
    void reqAreaChg();
    void setStgAreaStqr(rSoundStreamRequest* pr);
    void pauseStg();
    void resumeStg(rSoundStreamRequest* prStg, u32 reqNo);
    void flushStg();
    void pauseCycle();
    void resumeCycle(rSoundStreamRequest* prStg, u32 reqNo);
    void flushCycle();
    u32 getFsmState();
    void updateFsm();
    void startFsmReq(u32 bgmType, u32 reqNo);
    void endFsmReq(bool isNotNormal);
    void startFsmReq(rSoundStreamRequest* pr, u32 reqNo);
    void clrFsm();
    void releaseFsm();
    void setFsmStqr(rSoundStreamRequest* pr);
    u32 getQuestState(bool dying);
    void updateQuest();
    void startQuestReq(s32 reqNo, u32 resourceType, u32 bgmType);
    void endQuestReq(bool isNotNormal);
    void clrQuest();
    void releaseQuest();
    void setQuestStqr(rSoundStreamRequest* pr);
    void pauseQuest();
    void resumeQuest(rSoundStreamRequest* prQuest, u32 reqNo);
    void flushQuest();
    u32 getEventState();
    void updateEvent();
    void startEventReq(bool on_stg, bool on_btl);
    void endEventReq(bool isNotNormal);
    void clrEvent();
    void releaseEvent();
    void startBarReq(rSoundStreamRequest* pRequest, u32 thisId, const MtVector3& pos);
    void endBarReq();
    void startBaseReq(rSoundStreamRequest* pRequest, u32 reqNo, u32 thisId);
    void endBaseReq(rSoundStreamRequest* pRequest, u32 reqNo, u32 thisId);
    void startJukeBox(u32 ability, u32 thisId, const MtVector3& pos);
    void endJukeBox();
    void setBarStqr(rSoundStreamRequest* pr);
    void setBaseStqr(rSoundStreamRequest* pr);
    void setCycleZone(bool v);
    bool isCycle();
    bool isAmbChange();
private:
    u32 getAbilityBgmReqNo();
public:
    u32 getAbilityBgmNum();
    s32 getAbilityBgmReqNo(u32 ability);
private:
    rSoundAreaInfo* getSAR();
    rSoundStreamRequest* getBattleBgmResource();
    u32 getNormalBattleBgmReqNo();
    u32 getNoramlBattleOutroBgmReqNo();
    bool isStageBgmUseBattle();
    u32 getStageBgmReqNo();
    rSoundStreamRequest* getStageBgmResource();
public:
    void requestFsmAreaBgmStart(u32 type, u32 reqNo);
    void requestFsmAreaBgmReMove(bool isContinuation);
    void requestQuestAreaBgmStart(s32 reqNo, u32 resourceType, u32 bgmType);
    void requestQuestAreaBgmReMove(bool isRequestEvent);
    void requestRebirth();
    void requestPlDeath();
    void requestRebirthToPlayer();
    void initStageNormalBgmCtrl();
    void startNormalStageBgmControlToArea();
    void setBarBgmReq(rSoundStreamRequest* pRequest, u32 reqNo, u32 thisId, const MtVector3& pos);
    void resetBarBgm(rSoundStreamRequest* pRequest, u32 reqNo, u32 thisId, sSoundExt::STREAM_SEARCH_KEY searchKey);
    void setBase(bool v);
    void setBaseBgmReq(rSoundStreamRequest* pRequest, u32 reqNo, u32 thisId);
    void resetBaseBgmReq(rSoundStreamRequest* pRequest, u32 reqNo, u32 thisId);
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
    sSoundManager();
    virtual ~sSoundManager();
    static sSoundManager* getInstance();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void init();
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
public:
    bool mb_222Mode;  // offset: 0x11
    rSoundStreamRequest* mprBattle;  // offset: 0x18
    rSoundStreamRequest* mprSystem;  // offset: 0x20
    rSoundStreamRequest* mprLobby;  // offset: 0x28
    rSoundStreamRequest* mpr20System;  // offset: 0x30
    rSoundStreamRequest* mpr20Lobby;  // offset: 0x38
    bool mIsBtl_222;  // offset: 0x40
    u32 mBtlStateSnd[4];  // offset: 0x44
    u32 mBtlStateSndDying;  // offset: 0x54
    rSoundStreamRequest* mprBtl;  // offset: 0x58
    u32 mBtlReqNo;  // offset: 0x60
    u32 mBtlWinReqNo;  // offset: 0x64
    u32 mBtlBGMType;  // offset: 0x68
    rSoundStreamRequest* mprBtlTemp;  // offset: 0x70
    u32 mBtlReqNoTemp;  // offset: 0x78
    u32 mBtlWinReqNoTemp;  // offset: 0x7c
    u32 mBtlBGMTypeTemp;  // offset: 0x80
    bool mbDeath;  // offset: 0x84
    bool mbRebirth;  // offset: 0x85
    bool mbHelp;  // offset: 0x86
    bool mbAdv;  // offset: 0x87
    bool mbWin;  // offset: 0x88
    rSoundStreamRequest* mprBtlWin;  // offset: 0x90
    u32 mBtlReqNoWin;  // offset: 0x98
    u32 mWinTimer;  // offset: 0x9c
    u32 mWinRno;  // offset: 0xa0
    u32 mBtlStgPausePos;  // offset: 0xa4
    rSoundStreamRequest* mprBtlPause;  // offset: 0xa8
    u32 mBtlReqNoPause;  // offset: 0xb0
    u32 mBtlPausePos;  // offset: 0xb4
    bool mbBtlPause;  // offset: 0xb8
    bool mbBtlPauseNoBgm;  // offset: 0xb9
    bool mIsEm_222;  // offset: 0xba
    u32 mEmState[4];  // offset: 0xbc
    bool mbEmAdv;  // offset: 0xcc
    MtTypedArray<cEmSetState> mEmSetState;  // offset: 0xd0
    u32 mBattleState;  // offset: 0xf0
    MtTypedArray<cEmSetState> mEmSetStateBtl;  // offset: 0xf8
    bool mbBtlWin;  // offset: 0x118
    bool mbBtlEscape;  // offset: 0x119
    f32 mBattleWinTimer;  // offset: 0x11c
    f32 mBattleEscapeTimer;  // offset: 0x120
    f32 mBattleWinKeepTimer;  // offset: 0x124
    f32 mBattleEscapeKeepTimer;  // offset: 0x128
    bool mIsStage_222;  // offset: 0x12c
    u32 mStgState[4];  // offset: 0x130
    rSoundStreamRequest* mprStg;  // offset: 0x140
    u32 mStgReqNo;  // offset: 0x148
    u32 mStgBGMType;  // offset: 0x14c
    rSoundStreamRequest* mprStgTemp;  // offset: 0x150
    u32 mStgReqNoTemp;  // offset: 0x158
    u32 mStgBGMTypeTemp;  // offset: 0x15c
    bool mbAreaChg;  // offset: 0x160
    rSoundStreamRequest* mprStgArea;  // offset: 0x168
    u32 mStgReqNoArea;  // offset: 0x170
    rSoundStreamRequest* mprStgPause;  // offset: 0x178
    u32 mStgReqNoPause;  // offset: 0x180
    bool mbStgPause;  // offset: 0x184
    bool mbStgPauseNoBgm;  // offset: 0x185
    u32 mStgPausePos;  // offset: 0x188
    rSoundStreamRequest* mprCyclePause;  // offset: 0x190
    u32 mCycleReqNoPause;  // offset: 0x198
    bool mbCyclePause;  // offset: 0x19c
    bool mbCyclePauseNoBgm;  // offset: 0x19d
    u32 mCyclePausePos;  // offset: 0x1a0
    bool mbFade;  // offset: 0x1a4
    bool mbReq;  // offset: 0x1a5
    u32 mReqTimer;  // offset: 0x1a8
    rSoundStreamRequest* mprStgFade;  // offset: 0x1b0
    u32 mStgReqNoFade;  // offset: 0x1b8
    bool mIsSecond;  // offset: 0x1bc
    bool mIsFsm_222;  // offset: 0x1bd
    u32 mFsmState[4];  // offset: 0x1c0
    u32 mFsmBgmType;  // offset: 0x1d0
    rSoundStreamRequest* mprFsm;  // offset: 0x1d8
    u32 mFsmReqNo;  // offset: 0x1e0
    u32 mFsmReqNoTemp;  // offset: 0x1e4
    rSoundStreamRequest* mprFsmTemp;  // offset: 0x1e8
    bool mIsQuest_222;  // offset: 0x1f0
    u32 mQuestState[4];  // offset: 0x1f4
    rSoundStreamRequest* mprQuest;  // offset: 0x208
    u32 mQuestReqNo;  // offset: 0x210
    u32 mQuestReqNoTemp;  // offset: 0x214
    u32 mQuestResourceType;  // offset: 0x218
    u32 mQuestBgmType;  // offset: 0x21c
    bool mbAdvQuest;  // offset: 0x220
    rSoundStreamRequest* mprQuestPause;  // offset: 0x228
    u32 mQuestReqNoPause;  // offset: 0x230
    u32 mQuestPausePos;  // offset: 0x234
    bool mbQuestPause;  // offset: 0x238
    bool mbQuestPauseNoBgm;  // offset: 0x239
    bool mIsEvent_222;  // offset: 0x23a
    u32 mEventState[4];  // offset: 0x23c
    bool mIsBar_222;  // offset: 0x24c
    bool mIsBase_222;  // offset: 0x24d
    bool mIsJukeBox_222;  // offset: 0x24e
    bool mIsJukeBoxChg;  // offset: 0x24f
    rSoundStreamRequest* mprBar;  // offset: 0x250
    u32 mBarReqNoIndex;  // offset: 0x258
    MtVector3 mBarPos;  // offset: 0x260
    u32 mJukeBoxAbilityNo;  // offset: 0x270
    MtVector3 mJukeBoxPos;  // offset: 0x280
    rSoundStreamRequest* mprBase;  // offset: 0x290
    u32 mBaseReqNo;  // offset: 0x298
    bool mIsNPC_222;  // offset: 0x29c
    const uControlNpc* mpMusicNpc;  // offset: 0x2a0
    bool mbCycleZone;  // offset: 0x2a8
    sWeatherManager::WEATHER_PHASE mAmbType;  // offset: 0x2ac
    u32 mFadeOutSpd;  // offset: 0x2b0
    static const f32 mBattleWinJudgeTime;
    static const f32 mBattleEscapeJudgeTime;
    static const f32 mBattleWinKeepTime;
    static const f32 mBattleEscapeKeepTime;
    static const nAbility::ABILITY_ID mBattleBgmChangeAbility[];
    static MyDTI DTI;
    static const u32 STREAM_STOP_FADE_TIME = 2000;
    static const u32 STREAM_STOP_BTL_FADE_TIME = 1000;
private:
    static sSoundManager* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sSoundManager* sSoundManager::getInstance() {
    return ::sSoundManager::mpInstance;
}

// Inline, no code of its own: checked where it is inlined.
inline sSoundManager::cEmSetState::cEmSetState() {
    this->mprEm = static_cast<rSoundStreamRequest*>(nullptr);
    this->mEmReqNo = static_cast<u32>(4294967295);
    this->mEmWinReqNo = static_cast<u32>(4294967295);
    this->mbAdv = false;
    this->mbUseAdv = false;
    this->mbBGMTarget = false;
    this->mEmRank = static_cast<u32>(0);
    this->mbEscape = false;
    this->mbDead = false;
    this->mbWin = false;
    this->mpuChr = static_cast<uCharacter*>(nullptr);
}
