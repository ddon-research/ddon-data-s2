#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "cAITargetInfo.h"
#include "cEvaluation.h"
#include "cPawnActInterface.h"
#include "cThinkMgr.h"
#include "cpComponent.h"
#include "nDDOUtility.h"
#include "nPawn.h"
#include "rAIPawnActNoSwitch.h"
#include "rGUIMessage.h"
#include "rMsgSet.h"
#include "rPawnAI.h"
#include "rPriorityThink.h"
#include "rSoundStreamRequest.h"
#include "res_ptr.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cAIGrid;
class cAIPawnActNoSwitch;
class cAIPawnOrderParam;
class cAITargetInfo;
class cAITargetInfoArray;
class cContextInstHm;
class cContextInterface;
namespace cEvaluationName { class cEvaluation; }
class cGeneralPoint;
class cHitInfo;
class cHitNode;
class cPawnAIAction;
class cPawnActInterBreak;
class cPawnActInterCommon;
class cPawnActInterDisableMgr;
class cPawnActInterIn;
class cPawnActInterWaitFootwork;
class cPawnActInterface;
class cPawnEnableArea;
class cPrioThkIO;
namespace cThinkMgrName { class cThinkMgr; }
class cpActionManager;
class kTHINKDATA;
class rAIPawnActNoSwitch;
class rGUIMessage;
class rMsgSet;
class rPawnAIAction;
class rPriorityThink;
class rSoundStreamRequest;
class rkThinkData;
class uCharacter;
class uDDOModel;
class uHuman;

// Declarations
class cpPawnThink;

enum REQ_ACTINTER_PRIO
{
    REQ_ACTINTER_PRIO_NONE = 0,
    REQ_ACTINTER_PRIO_PRIO_THINK_NML = 1,
    REQ_ACTINTER_PRIO_DEF = 2,
    REQ_ACTINTER_PRIO_PRIO_THINK_HI = 3,
    REQ_ACTINTER_PRIO_NUM = 4,
};

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cAIPawnActionGroupFlag = nDDOUtility::cBitSet<128>;
using cAIPawnOrderGroupArray = nDDOUtility::cArray<unsigned int, 3>;
using cAIPawnOrderGroupArrayCounter = nDDOUtility::cArray<float, 3>;
using cAIPawnStateCounter = nDDOUtility::cArray<float, 17>;
using cAIPawnStateCounterFlag = nDDOUtility::cBitSet<17>;
using cPawnAIActComCheckFlag = nDDOUtility::cBitSet<10>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cpPawnThink : public cpComponent
{
public:
    enum
    {
        CTRL_USE_THINKMGR = 0,
        CTRL_IS_TARGET_PL = 1,
        CTRL_USE_FOLLOW_AREA = 2,
        CTRL_USE_PAWN_TALK = 3,
        CTRL_USE_WARP = 4,
        CTRL_USE_ENV = 5,
        CTRL_USE_OM = 6,
        CTRL_USE_ORDER = 7,
        CTRL_USE_OM_BREAK = 8,
        CTRL_USE_NO_MOVE = 9,
        CTRL_TGT_ANIMAL = 10,
        CTRL_TGT_PL_COOP = 11,
        CTRL_TGT_NPC = 12,
        CTRL_TGT_NO_FALL = 13,
        CTRL_USE_RORATE_NO = 14,
        CTRL_USE_NPC_NOTICE = 15,
        CTRL_NUM = 16,
    };
    enum
    {
        TRACE_DISABLE_NONE = 0,
        TRACE_DISABLE_EM = 1,
        TRACE_DISABLE_OM = 2,
        TRACE_DISABLE_NUM = 3,
    };
public:
    class MyDTI;
    class cReqActInterParam;
public:
    using cCtrlFlag = nDDOUtility::cBitSet<16>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cReqActInterParam
    {
    public:
        cReqActInterParam(f32 frame, u32 flag, f32 range, const cAIPawnActionGroupFlag* pGroupFlag, u32 enableAngleType, f32 limitTime, f32 breakDisableTime);
    public:
        const cAIPawnActionGroupFlag* mpGroupFlag;  // offset: 0x0
        nDDOUtility::cArray<float, 4> mFreeParamF32;  // offset: 0x8
        f32 mFrame;  // offset: 0x18
        u32 mFlag;  // offset: 0x1c
        f32 mRange;  // offset: 0x20
        u32 mEnableAngleType;  // offset: 0x24
        f32 mLimitTime;  // offset: 0x28
        f32 mActBreakDisableTime;  // offset: 0x2c
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
    cpPawnThink();
    virtual ~cpPawnThink();
protected:
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    void compMoveAfter();
    virtual void updatePtr();  // vtable slot 9
    virtual void kill();  // vtable slot 8
public:
    virtual void setActive(bool active);  // vtable slot 13
    void loadAISensor(uCharacter& owner);
    void setModePawn();
    void setModeHumanEnemy(rkThinkData* pThink);
    void setModePartyNpc(rkThinkData* pThink, u32 thinkID);
    void setModeOff();
    bool isNowEscapeThink();
    u32 getEnemyListLength();
private:
    void updatePartyListForPlayer();
    void updatePartyListForEnemy();
    void updateEnemyListTargetForPlayer();
    void updateEnemyListTargetForEnemyEnv();
    void updateEnemyListTargetForEnemyNoEnv();
    void updateAnimalList();
    void updateOmList();
    void updateNpc();
    void updateBattleStatus();
    void updateBattleStatusThinkMode();
    void updateFollowArea();
    void updateNoticeGrid();
    void updateGridDisableTrace();
    void updateDangerGrid();
    void updateHealingArrowGrid();
    void updateGachaRate();
    void updateGuardCount();
    void updateChantCancel();
    void updateStateCounter();
    void updateNoMove();
    void updateNoFollow();
    void updateTargetInfo(cPrioThkIO& io);
    void calcFollowArea(MtVector3* pDstRealPos, f32* pDstAngle, cPawnEnableArea* pDstEnableArea, cPawnEnableArea* pDstTargetArea, u32 type);
    void calcStandOffTime();
    void setupOmBreakHitNode();
    void killOmBreakHitNode();
    void clearAIGrids();
    void clearNoMoveParams();
    bool isEnableEnemyListTarget(cAITargetInfo* pTarget, void* pParam);
    f32 getNpcEnemyEvaFunc(cAITargetInfo* pTarget, cAITargetInfoArray* pArray, f32 deltaTime, void* pParam);
    f32 getNpcPartyEvaFunc(cAITargetInfo* pTarget, cAITargetInfoArray* pArray, f32 deltaTime, void* pParam);
public:
    u32 getGuardCnt() const;
    void resetGuardCnt();
    u32 getPrioThinkGurdCount() const;
    const cAITargetInfoArray& getPrioThinkPartyList() const;
    bool isPrioThinkChantCancel() const;
    bool isEnableFall() const;
    uDDOModel* getThinkMgrTarget() const;
    const cGeneralPoint* getTargetGeneralPoint(u32 index);
    cAITargetInfoArray& getPartyList();
    const cAIGrid* getDangerGrid() const;
private:
    void addResActInterTable(rPawnAIAction* pRes);
    void clearResActInterTable();
    void reqActInterID(u32 id, REQ_ACTINTER_PRIO prio, const cReqActInterParam& param);
    void reqActInterID(u32 id, u32 targetUID, REQ_ACTINTER_PRIO prio, const cReqActInterParam& param);
    void reqActInterID(u32 id, const MtVector3& ofsPos, REQ_ACTINTER_PRIO prio, const cReqActInterParam& param);
    void reqActInterID(u32 id, cGeneralPoint* pGp, REQ_ACTINTER_PRIO prio, const cReqActInterParam& param);
    void reqActInterIDEmActNo(u32 emActNo, u32 targetUID, const MtVector3& ofsPos, REQ_ACTINTER_PRIO prio, const cReqActInterParam& param);
    void moveActInterfaceResult();
    void moveActInterfaceThink();
    bool moveActInterfaceSubSameActReq();
    void updateEnableActInterface();
    void copyActInterInFromReqInterParam(cPawnActInterIn& dst, const cReqActInterParam& src);
public:
    u32 getNowActInterID() const;
    u32 getNextChantAction() const;
    void clearNextChantAction();
private:
    void setResPrioThink(rPriorityThink* pRes);
    void clearResPrioThink();
    void movePrioThink();
    void movePrioThinkArrowChange(uCharacter* pOwner);
    void movePrioThinkCureArrow(uCharacter* pOwner);
    void movePrioThinkMedalChange(uCharacter* pOwner);
    void movePrioThinkSpiritSupCoolDown(uCharacter* pOwner);
    void movePrioThinkErosionRescue(uCharacter* pOwner);
    void movePrioThinkSub(rPriorityThink* pRes, uCharacter* pOwner);
    void moveThinkMgr();
    void moveThinkMgrTargetListHmEm();
    void moveThinkMgrTargetListNpc();
    void moveThinkMgrThinkMode();
    bool isUpdateThinkMgr(uDDOModel& owner);
    bool isCharacterBadCondition(uCharacter* pChar);
    bool isThinkModePartyThinkModeBtl();
    static bool setTargetThinkMgr(const kTHINKDATA& tbl, MtObject* pMtObj, cThinkMgrName::cThinkMgr* pThinkMgr, u32 targetDataIdx);
    static bool sortFuncCharacterHp(const uCharacter* pA, const uCharacter* pB, u32);
    void addAIPawnActNoSwitchRes(rAIPawnActNoSwitch* pRes);
    void clearAIPawnActNoSwitchRes();
    bool updateNPCAttackDetectionThink();
public:
    cThinkMgrName::cThinkMgr* getThinkMgr();
    cEvaluationName::cEvaluation* getEvaluation();
    void setThinkMgrPrmActLimitTime(f32 time);
    uDDOModel* getThinkMgrNewTarget();
    u32 getThinkMgrNpcThinkID() const;
    const cAIPawnActNoSwitch* getAIPawnActNoSwitch(u32 emActNo);
    void movePawnOrder();
    void reqPawnOrder(const cAIPawnOrderGroupArray& src);
    void reqPawnOrderTarget(uDDOModel* pTarget);
private:
    bool isPawnOrderEnd(u32 orderId, f32 count);
    bool isPawnOrderFailed(u32 orderId, uDDOModel* pTarget);
    bool isPawnOrderResetAction(u32 orderId, uDDOModel* pTarget);
    bool isPawnOrderTargetOn(MtTypedArray<cPawnAIAction>& act, cAIPawnOrderParam* pOrder);
    bool isPawnOrderTargetHeal();
    bool isPawnOrderTargetCure(MtTypedArray<cPawnAIAction>& act);
    bool isPawnOrderTargetEnchant(MtTypedArray<cPawnAIAction>& act);
    bool isPawnOrderTargetPowerUp(MtTypedArray<cPawnAIAction>& act);
    bool isPawnOrderTargetPowerUpForSelf(MtTypedArray<cPawnAIAction>& act);
    bool isPawnOrderTargetPowerDn(MtTypedArray<cPawnAIAction>& act);
    bool isPawnOrderTargetPowerDnOcd(MtTypedArray<cPawnAIAction>& act, const cAIPawnActionGroupFlag& targetActGroup);
    bool isPawnOrderTargetIsAnger();
    void clearPawnOrderGroup(u32 group);
    void clearPawnOrderAll();
    uDDOModel* calcPawnOrderSmallTarget(cAITargetInfoArray* emList);
    uDDOModel* calcPawnOrderLargeTarget(cAITargetInfoArray* emList);
    uDDOModel* calcPawnOrderLandTarget(cAITargetInfoArray* emList);
    uDDOModel* calcPawnOrderFlyTarget(cAITargetInfoArray* emList);
    uDDOModel* calcPawnSpEmTarget(cAITargetInfoArray* emList);
    bool buriedCheckEnemy(const MtVector3& mypos, const MtVector3& empos);
    void updateWarp();
    void createWarpArea(cPawnEnableArea* pDstArea, MtVector3* pDstPos, f32* pDstAngle);
    bool isEnableStageFollowWarp();
public:
    void callbackChangeActionPawnThink(cpActionManager* pAct);
    void callbackCheckPawnThink(cHitInfo* pHitInfo);
    void callbackAttackTestPawnThink(cHitInfo* pHitInfo);
    void callbackGuardPawnThink(cHitInfo* pHitInfo);
    void callbackGuardPawnThink_calc(cHitInfo* pHitInfo);
    void requestPawnTalk(u32 situation);
    void updatePawnTalk();
    rGUIMessage* getMsgGmd();
    rMsgSet* getMsgMss();
    rSoundStreamRequest* getVoiceRes();
    f32 getMsgWaitTime();
    f32 getMsgWaitTimePintch();
    void reqPawnTalkSituationReqRescue();
    void reqPawnTalkSituationReqLvUp();
    void reqPawnTalkSituationItemUse(u32 type);
    bool isCanTalkClimb();
    void setCanTalkClimb(bool flg);
private:
    void updatePawnTalkSituationFindParty();
    void updatePawnTalkSituationLvUp();
    void updatePawnTalkSituationEnemy();
    void updatePawnTalkSituationWait();
    void updatePawnTalkSituationPinch();
    void updatePawnTalkSituationBattleStatus();
    void updatePawnTalkSituationQuest();
    void updatePawnTalkSituationRescue();
    void updatePawnTalkSituationInBase();
    void updatePawnTalkSituationTargetCore();
    void endPawnTalkSituationFindParty();
    bool checkUpdatePawnTalkSituationPinchH();
    bool checkUpdatePawnTalkSituationPinchM();
    bool checkUpdatePawnTalkSituationPinchL();
public:
    bool isPawnTalkSituation(u32 situation);
private:
    bool isPawnTalkSituationParty();
    bool isPawnTalkSituationLoginFriend();
    bool isPawnTalkSituationQuestSuccess();
    bool isPawnTalkSituationQuestFailed();
    bool isPawnTalkSituationRankIn();
    bool isPawnTalkSituationLvUp();
    bool isPawnTalkSituationFieldIn();
    bool isPawnTalkSituationFindEnemy();
    bool isPawnTalkSituationFindSEnemy();
    bool isPawnTalkSituationRescue();
    bool isPawnTalkSituationHelp();
    bool isPawnTalkSituationLost();
    bool isPawnTalkSituationDown();
    bool isPawnTalkSituationBattleIn();
    bool isPawnTalkSituationBattleEnd();
    bool isPawnTalkSituationPinchL();
    bool isPawnTalkSituationPinchM();
    bool isPawnTalkSituationPinchH();
    bool isPawnTalkSituationPlDead();
    bool isPawnTalkSituationCharge();
    bool isPawnTalkSituationHeal();
    bool isPawnTalkSituationEvaluation();
    bool isPawnTalkSituationSupport();
    bool isPawnTalkSituationEscape();
    bool isPawnTalkSituationAttack();
    bool isPawnTalkSituationCatapult();
    bool isPawnTalkSituationOrderConsent();
    bool isPawnTalkSituationOrderRefusal();
    bool isPawnTalkSituationWaitLobby();
    bool isPawnTalkSituationWaitStage();
    bool isPawnTalkSituationEnemyHold();
    bool isPawnTalkSituationVisitBase00();
    bool isPawnTalkSituationVisitBase01();
    bool isPawnTalkSituationTargetCore();
    bool isPawnTalkSituationRageEnemy();
    bool isPawnTalkSituationTireEnemy();
    bool isPawnTalkSituationDownEnemy();
    bool isPawnTalkRequestMsg(u32 msgSituation);
    bool isPawnTalkSituationDownCore();
public:
    void moveEnableFall();
    f32 getGacha();
    uCharacter* getMasterUnitChr();
    bool isPawnALiveStatus();
    f32 getTargetClimbYorokeTimer();
    bool getStateCounterFlag(u32 index);
    bool isPawnJob10EnableHealCoolDown();
    bool isPawnJob10EnableSupCoolDown();
    u32 getNowPrioThinkID();
private:
    uDDOModel* findNearEnemy();
    uDDOModel* getMasterUnit();
    uHuman* getMasterUnitHm();
    uCharacter* getOwnerUnitChr();
    uHuman* getOwnerUnitHm();
    const cContextInstHm* getTargetContextInstHm(uHuman* pOwner);
    const cContextInstHm* getOwnerContextInstHm();
    cContextInterface& getMasterContextInterface();
    cContextInterface& getOwnerContextInterface();
    cGeneralPoint* getHealFountain();
    uDDOModel* getCheckHitUnit();
    void moveEscapeThink();
    bool checkInBattle(uHuman& master);
    void updateEscape(uHuman& master);
    void initEscapeThinkInfo();
    void resetEscapeInfo();
    f32 getTargetNearDist(uDDOModel& target, uDDOModel& owner);
private:
    cCtrlFlag mCtrlFlag;  // offset: 0x50
    u32 mAIPawnRotateNo;  // offset: 0x54
    bool mIsPawnRotateNoEnableFrame;  // offset: 0x58
    cAITargetInfoArray mPartyList;  // offset: 0x60
    cAITargetInfoArray mEnemyList;  // offset: 0xd0
    cAITargetInfoArray mAnimalList;  // offset: 0x140
    cAITargetInfoArray mOmList;  // offset: 0x1b0
    uCharacter* mpNpc;  // offset: 0x220
    cAIGrid* mpNoticeGrid;  // offset: 0x228
    cAIGrid* mpTraceDisableGrid;  // offset: 0x230
    cAIGrid* mpDangerGrid;  // offset: 0x238
    cAIGrid* mpHealingArrowGruid;  // offset: 0x240
    nDDOUtility::cArray<MtVector3, 10> mNoAvoidPos;  // offset: 0x250
    u32 mUseNoAvoidNum;  // offset: 0x2f0
    cHitNode* mpOmBreakHitNode;  // offset: 0x2f8
    uDDOModel* mpAttackTestHitUnitReq;  // offset: 0x300
    uDDOModel* mpAttackTestHitUnit;  // offset: 0x308
    MtVector3 mThinkStartRealPos;  // offset: 0x310
    f32 mStandOffFrame;  // offset: 0x320
    u32 mThinkBattleStatus;  // offset: 0x324
    u32 mThinkBattleStatusOld;  // offset: 0x328
    u32 mSysThinkBattleStatus;  // offset: 0x32c
    u32 mSysThinkBattleStatusOld;  // offset: 0x330
    f32 mGachaRate;  // offset: 0x334
    f32 mGachaCounter;  // offset: 0x338
    u32 mGuardCnt;  // offset: 0x33c
    f32 mGuardCntResetTimer;  // offset: 0x340
    f32 mChatCancelTimer;  // offset: 0x344
    s32 mActChgCount;  // offset: 0x348
    u32 mDisableNotice;  // offset: 0x34c
    cAIPawnStateCounter mStateCounter;  // offset: 0x350
    cAIPawnStateCounterFlag mStateCounterFlag;  // offset: 0x394
    f32 mSlipSlopeTime;  // offset: 0x398
    bool mIsEnableAnimalCoop;  // offset: 0x39c
    u32 mStandOffZeroCount;  // offset: 0x3a0
    bool mNoMoveOldUseTrace;  // offset: 0x3a4
    MtVector3 mNoMoveTgtRealPosOld;  // offset: 0x3b0
    MtVector3 mNoMoveOwnerRealPosOld;  // offset: 0x3c0
    f32 mNoMoveOwnerAngleOld;  // offset: 0x3d0
    f32 mNoMoveFrame;  // offset: 0x3d4
    f32 mNoMoveOnFrame;  // offset: 0x3d8
    u32 mNoMoveCheckCnt;  // offset: 0x3dc
    u32 mNoMoveCheckOnCnt;  // offset: 0x3e0
    f32 mNoMoveDistance;  // offset: 0x3e4
    f32 mNoMoveInterval;  // offset: 0x3e8
    MtVector3 mNoFollowRealPosOld;  // offset: 0x3f0
    f32 mNoFollowCount;  // offset: 0x400
    f32 mNoFollowPosLenMinXZ;  // offset: 0x404
    f32 mNoFollowPosLenMinY;  // offset: 0x408
    f32 mNoFollowDisableLimitTime;  // offset: 0x40c
    u8 mNoFollowStep;  // offset: 0x410
    u8 _padding[3];  // offset: 0x411
    f32 mArrowChgIntervalTimer;  // offset: 0x414
    u32 mArrowChgOldArrow;  // offset: 0x418
    u32 mArrowChgOldBtlStatus;  // offset: 0x41c
    f32 mMedalChgIntervalTimer;  // offset: 0x420
    u32 mMedalChgOldMedal;  // offset: 0x424
    u32 mMedalChgOldBtlStatus;  // offset: 0x428
    f32 mActionCureArrowWaitTimer;  // offset: 0x42c
    f32 mSpiritStoneHealIntervalTimer;  // offset: 0x430
    f32 mSpiritStoneSupIntervalTimer;  // offset: 0x434
    f32 mErosionRescueCoolDownTimer;  // offset: 0x438
    f32 mReceiveErosionRescueCoolDownTimer;  // offset: 0x43c
    u32 mFollowAreaType;  // offset: 0x440
    cPawnEnableArea mFollowAreaTarget;  // offset: 0x448
    cPawnEnableArea mFollowAreaEnable;  // offset: 0x468
    MtVector3 mFollowAreaRealPos;  // offset: 0x490
    f32 mFollowAreaAngle;  // offset: 0x4a0
    u32 mReqFollowAreaType;  // offset: 0x4a4
    cPawnEnableArea mReqFollowAreaEnable;  // offset: 0x4a8
    cPawnEnableArea mReqFollowAreaTarget;  // offset: 0x4c8
    MtVector3 mReqFollowAreaRealPos;  // offset: 0x4f0
    f32 mReqFollowAreaAngle;  // offset: 0x500
    MtTypedArray<rPawnAIAction> mActInterTable;  // offset: 0x508
    MtTypedArray<cPawnAIAction> mActInterEnableArray;  // offset: 0x528
    cPawnActInterface mActInter;  // offset: 0x550
    u32 mNowActInterID;  // offset: 0xa10
    REQ_ACTINTER_PRIO mNowActInterPrio;  // offset: 0xa14
    cPawnActInterCommon mCommonActInterBegin;  // offset: 0xa18
    cPawnActInterBreak mCommonActInterBreak;  // offset: 0xa30
    cPawnActInterWaitFootwork mCommonActInterFootwork;  // offset: 0xa48
    cPawnActInterIn mReqActInterInParam;  // offset: 0xa60
    u32 mReqActInterID;  // offset: 0xc60
    REQ_ACTINTER_PRIO mReqActInterPrio;  // offset: 0xc64
    f32 mDoActEndStandOffFrame;  // offset: 0xc68
    cPawnAIActComCheckFlag mPrioThinkActCheckFlag;  // offset: 0xc6c
    f32 mDoJustGuardTimer;  // offset: 0xc70
    f32 mDoNormalGuardTimer;  // offset: 0xc74
    cPawnActInterDisableMgr* mpActInterDisableMgr;  // offset: 0xc78
    cAIPawnActionGroupFlag mTgtEnemyWeakGroupFlag;  // offset: 0xc80
    bool mIsEnableFall;  // offset: 0xc90
    bool mIsEnableFallOld;  // offset: 0xc91
    bool mReqActInterReset;  // offset: 0xc92
    u32 mChantNextActNo;  // offset: 0xc94
    f32 mTargetYorokeTimer;  // offset: 0xc98
    bool mNowEscapeThink;  // offset: 0xc9c
    bool mIsCanNotLightingAnchorElec;  // offset: 0xc9d
    bool mIsCanNotGoldBurst;  // offset: 0xc9e
    bool mIsCanNotClimb;  // offset: 0xc9f
    f32 mActInterResetYoyakuTimer;  // offset: 0xca0
    bool mNoUseMoveNoJump;  // offset: 0xca4
    cPrioThkIO mPrioThinkIO;  // offset: 0xcb0
    res_ptr<rPriorityThink> mpPrioThink;  // offset: 0xf10
    cThinkMgrName::cThinkMgr mcThink;  // offset: 0xf20
    MtTypedArray<rAIPawnActNoSwitch> mAIPawnActNoSwitchArray;  // offset: 0x2230
    uDDOModel* mpThinkMgrTarget;  // offset: 0x2250
    MtVector3 mThinkMgrTargetRealPos;  // offset: 0x2260
    u32 mThinkMgrRetActNo;  // offset: 0x2270
    u32 mThinkNpcThinkID;  // offset: 0x2274
    f32 mThinkModeHoldCounter;  // offset: 0x2278
    f32 mThinkMgrPrmActLimitTime;  // offset: 0x227c
    bool mUseNpcAvoid;  // offset: 0x2280
    cEvaluationName::cEvaluation mcEvaluation;  // offset: 0x2288
    bool mIsOrderActionEnd;  // offset: 0x5538
    bool mAIPawnOrderCancel;  // offset: 0x5539
    cAIPawnOrderGroupArray mAIPawnOrderArray;  // offset: 0x553c
    cAIPawnOrderGroupArrayCounter mAIPawnOrderArrayCounter;  // offset: 0x5548
    uDDOModel* mpAIPawnOrderTarget;  // offset: 0x5558
    cAIPawnOrderGroupArray mAIPawnOrderArrayReq;  // offset: 0x5560
    uDDOModel* mpAIPawnOrderTargetReq;  // offset: 0x5570
    f32 mMsgCounter;  // offset: 0x5578
    res_ptr<rSoundStreamRequest> mpVoiceRes;  // offset: 0x5580
    res_ptr<rGUIMessage> mpMsgGmd;  // offset: 0x5588
    res_ptr<rMsgSet> mpMsgMss;  // offset: 0x5590
    f32 mPawnTalkSituationFindPartyWaitTimer;  // offset: 0x5598
    f32 mPawnTalkSituationFindPartyTimer;  // offset: 0x559c
    f32 mPawnTalkSituationEmTimer;  // offset: 0x55a0
    f32 mPawnTalkSituationEmSTimer;  // offset: 0x55a4
    f32 mPawnTalkSituationBattleTimer;  // offset: 0x55a8
    f32 mPawnTalkSituationLvUpReqWaitTimer;  // offset: 0x55ac
    f32 mPawnTalkSituationLvUpTimer;  // offset: 0x55b0
    f32 mPawnTalkSituationWaitCounter;  // offset: 0x55b4
    f32 mPawnTalkSituationWaitFrame;  // offset: 0x55b8
    f32 mPawnTalkSituationDownResetTimer;  // offset: 0x55bc
    u32 mPawnTalkSituationPinchType;  // offset: 0x55c0
    u32 mPawnTalkSituationPinchOldBtlStatus;  // offset: 0x55c4
    f32 mPawnTalkSituationRescueReqTimer;  // offset: 0x55c8
    f32 mPawnTalkSituationRescueTimer;  // offset: 0x55cc
    f32 mPawnTalkSituationRescueItemUseTimer;  // offset: 0x55d0
    u32 mPawnTalkSituationRescueItemUseReqType;  // offset: 0x55d4
    f32 mPawnTalkSituationRescueOldHpRate;  // offset: 0x55d8
    f32 mPawnTalkSituationPlDeadIntervalTimer;  // offset: 0x55dc
    bool mPawnTalkSituationEm;  // offset: 0x55e0
    bool mPawnTalkSituationEmS;  // offset: 0x55e1
    bool mPawnTalkSituationOrderSuccess;  // offset: 0x55e2
    bool mPawnTalkSituationOrderFailed;  // offset: 0x55e3
    bool mPawnTalkSituationRescueHelpOld;  // offset: 0x55e4
    bool mPawnTalkSituationEmRage;  // offset: 0x55e5
    bool mPawnTalkSituationEmSwayd;  // offset: 0x55e6
    bool mPawnTalkSituationEmDown;  // offset: 0x55e7
    bool mPawnTalkSituationEmClimb;  // offset: 0x55e8
    f32 mWarpLenNml;  // offset: 0x55ec
    f32 mWarpLenBtl;  // offset: 0x55f0
    bool mFlgEscapeThink;  // offset: 0x55f4
    f32 mSheatheTimer;  // offset: 0x55f8
    f32 mEnemyInRangeTimer;  // offset: 0x55fc
public:
    static MyDTI DTI;
};
