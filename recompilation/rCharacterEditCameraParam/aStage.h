#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "cArea.h"
#include "../shared/cOmControl.h"
#include "cPlDeadFlow.h"
#include "../shared/cStageEpvCtrl.h"
#include "../shared/nDDOUtility.h"
#include "../shared/nStage.h"
#include "../shared/rStageCustomPartsEx.h"
#include "../shared/sCollision.h"
#include "../shared/sItemManager.h"

// Forward declarations
class CDataCommonU32;
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cArcLoaderBase;
class cCamExParam;
class cDayNightColorFogParam;
class cFSMTaskCtrl;
class cOmTreeControl;
class cPlDeadFlow;
class cSplitBgm;
class cStageEpvCtrl;
class cTalkMsgData;
class cUnit;
namespace nStage { struct stEventParam; }
class rOccluderEx;
class rPlantTree;
class rScheduler;
class rSoundAreaInfo;
class rSoundAttributeSe;
class rSoundRequest;
class rSoundStreamRequest;
class rStageConnect;
class rStageInfo;
class rStartPos;
class rWaypoint;
class rZone;
class uColorCorrectFilter;
class uDDOModel;
class uGUIClock;
class uGUICredit;
class uGUIMapMini;
class uGUIQuickParty;
class uLargeEnemyCamera;
class uScheduler;
class uSoundGenerator;
class uSoundOcclusion;
class uSoundTrigger;
class uStageCraftPawnCtrl;
class uStageFieldCtrl;
class uStageJointCtrl;
class uStageMyRoom;
class uStagePartsCtrl;
class uStageRevivalPawn;

// Declarations
class aStage;

// Type aliases from DWARF
using CommonU32Vec = MtTypedArray<CDataCommonU32>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using f32 = float;
using u32 = unsigned int;
namespace nCollision { using SBC_HANDLE = u32; }
using s32 = int;
using size_t = _Sizet;
using u8 = unsigned char;

class aStage : public cArea
{
public:
    enum MOVE_PROFILE
    {
        MOVE_PROFILE_000_MOVE_STAGEALL = 0,
        MOVE_PROFILE_010_MOVE_SCENARIOMANAGER = 1,
        MOVE_PROFILE_020_MOVE_SETMANAGER = 2,
        MOVE_PROFILE_NUM = 3,
    };
    enum
    {
        AREA_JMP_STANDBY = 0,
        AREA_JMP_ACCEPT = 1,
        AREA_JMP_BUSY = 2,
        AREA_JMP_MENU = 3,
    };
    enum
    {
        WARP_TYPE_OUTPOST = 0,
        WARP_TYPE_GAME_MENU = 1,
        WARP_TYPE_SCR_DOOR = 2,
        WARP_TYPE_WARP_OM = 3,
    };
    enum
    {
        LOAD_R0_ST_BEFORE = 0,
        LOAD_R0_ST_PROLOGUE_OUT_INIT = 1,
        LOAD_R0_ST_PROLOGUE_OUT_WAIT = 2,
        LOAD_R0_ST_CHANGE_SERVER_INIT = 3,
        LOAD_R0_ST_CHANGE_SERVER_WAIT = 4,
        LOAD_R0_ST_CHANGE_SERVER_ERROR = 5,
        LOAD_R0_ST_GAMETIME_REQ = 6,
        LOAD_R0_ST_GAMETIME_WAIT = 7,
        LOAD_R0_ST_GET_SESSION_KEY = 8,
        LOAD_R0_ST_GET_SESSION_KEY_WAIT = 9,
        LOAD_R0_ST_GET_SESSION_KEY_RETRY = 10,
        LOAD_R0_ST_GET_SESSION_KEY_RETRY_WAIT = 11,
        LOAD_R0_ST_CAPLINK_LOGIN_WAIT = 12,
        LOAD_R0_ST_CAPLINK_LOGIN_RETRY_WAIT = 13,
        LOAD_R0_ST_CAPLINK_LOGIN_COMP_WAIT = 14,
        LOAD_R0_ST_GET_MY_PAWN_LIST_REQ = 15,
        LOAD_R0_ST_GET_MY_PAWN_LIST_WAIT = 16,
        LOAD_R0_ST_GET_RENTED_PAWN_LIST_REQ = 17,
        LOAD_R0_ST_GET_RENTED_PAWN_LIST_WAIT = 18,
        LOAD_R0_ST_GET_DLC_BOUGHTS_REQ = 19,
        LOAD_R0_ST_GET_DLC_BOUGHTS_WAIT = 20,
        LOAD_R0_ST_GET_ITEM_LIST_REQ = 21,
        LOAD_R0_ST_GET_ITEM_LIST_WAIT = 22,
        LOAD_R0_ST_GET_ORB_GAIN_REQ = 23,
        LOAD_R0_ST_GET_ORB_GAIN_WAIT = 24,
        LOAD_R0_ST_GET_JOB_LIST_REQ = 25,
        LOAD_R0_ST_GET_JOB_LIST_WAIT = 26,
        LOAD_R0_ST_GET_SET_SKILL_REQ = 27,
        LOAD_R0_ST_GET_SET_SKILL_WAIT = 28,
        LOAD_R0_ST_GET_RELEASE_WARP_POINT_REQ = 29,
        LOAD_R0_ST_GET_RELEASE_WARP_POINT_WAIT = 30,
        LOAD_R0_ST_GET_AREA_POINT_REQ = 31,
        LOAD_R0_ST_GET_AREA_POINT_WAIT = 32,
        LOAD_R0_ST_GET_COMMUNITY_LIST_REQ = 33,
        LOAD_R0_ST_GET_COMMUNITY_LIST_WAIT = 34,
        LOAD_R0_ST_GET_GROUPCHAT_LIST_REQ = 35,
        LOAD_R0_ST_GET_GROUPCHAT_LIST_WAIT = 36,
        LOAD_R0_ST_GET_MAIL_LIST_REQ = 37,
        LOAD_R0_ST_GET_MAIL_LIST_WAIT = 38,
        LOAD_R0_ST_GET_RELEASE_REWARD_REQ = 39,
        LOAD_R0_ST_GET_RELEASE_REWARD_WAIT = 40,
        LOAD_R0_ST_GET_ACHIEVE_REQ = 41,
        LOAD_R0_ST_GET_ACHIEVE_WAIT = 42,
        LOAD_R0_ST_CHECK_STAMP_BONUS_REQ = 43,
        LOAD_R0_ST_CHECK_STAMP_BONUS_WAIT = 44,
        LOAD_R0_ST_ENTRY_BOARD_INFO_REQ = 45,
        LOAD_R0_ST_ENTRY_BOARD_INFO_WAIT = 46,
        LOAD_R0_ST_PRE_INIT = 47,
        LOAD_R0_ST_GET_CLAN_BASE_INFO_REQ = 48,
        LOAD_R0_ST_GET_CLAN_BASE_INFO_WAIT = 49,
        LOAD_R0_ST_GET_CLAN_BASE_MYPAWN_LIST_REQ = 50,
        LOAD_R0_ST_GET_CLAN_BASE_MYPAWN_LIST_WAIT = 51,
        LOAD_R0_ST_INIT = 52,
        LOAD_R0_ST_MOVE = 53,
        LOAD_R0_ST_NET_WAIT = 54,
        LOAD_R0_ST_JOB_CHANGE = 55,
        LOAD_R0_ST_JOB_CHANGE_ERROR = 56,
        LOAD_R0_ST_PARTY_CREATE = 57,
        LOAD_R0_ST_PARTY_JOIN = 58,
        LOAD_R0_ST_AREA_CHANGE = 59,
        LOAD_R0_ST_STAGE_INIT = 60,
        LOAD_R0_ST_STAGE_RANDOM = 61,
        LOAD_R0_ST_STAGE_ARC = 62,
        LOAD_R0_ST_PL_LOAD_INIT = 63,
        LOAD_R0_ST_PL_LOAD_WAIT = 64,
        LOAD_R0_ST_PL_LOAD_END = 65,
        LOAD_R0_ST_GET_AREA_INFO = 66,
        LOAD_R0_ST_GET_AREA_INFO_WAIT = 67,
        LOAD_R0_ST_SET_OM_INIT = 68,
        LOAD_R0_ST_SET_OM_WAIT = 69,
        LOAD_R0_ST_MYROOM_WAIT = 70,
        LOAD_R0_ST_MYROOM_BOX_WAIT = 71,
        LOAD_R0_ST_END = 72,
        LOAD_R0_ST_WAIT_SYNC = 73,
        LOAD_R0_ST_END_LOOP = 74,
    };
    enum
    {
        MOVE_R0_INIT = 0,
        MOVE_R0_MAIN = 1,
        MOVE_R0_TO_LOBBY = 2,
        MOVE_R0_TO_LOBBY_TEMPLE = 3,
        MOVE_R0_TO_MENU = 4,
        MOVE_R0_TO_TITLE = 5,
        MOVE_R0_TO_STAGE = 6,
        MOVE_R0_TO_LAUNCHER = 7,
        MOVE_R0_TO_EXIT = 8,
        MOVE_R0_FADE = 9,
        MOVE_R0_EVENT = 10,
        MOVE_R0_EVENT_FSM = 11,
        MOVE_R0_WARP = 12,
        MOVE_R0_MENU_WARP = 13,
    };
    enum
    {
        TO_LAUNCHER_INIT = 0,
        TO_LAUNCHER_WAIT = 1,
        TO_LAUNCHER_EXIT = 2,
    };
    enum
    {
        MOVE_R1_INIT = 0,
        MOVE_R1_MAIN = 1,
        MOVE_R1_PAUSE = 2,
        MOVE_R1_TO_STAGE = 3,
        MOVE_R1_GAMEOVER = 4,
    };
    enum
    {
        GAMEOVER_INIT = 0,
        GAMEOVER_MAIN = 1,
        GAMEOVER_EXIT = 2,
        GAMEOVER_END = 3,
    };
    enum
    {
        MOVE_DIALOG_INIT = 0,
        MOVE_DIALOG_MAIN = 1,
        MOVE_DIALOG_EXIT = 2,
    };
    enum
    {
        FEATURE_MAX_NUM = 5,
    };
public:
    class MyDTI;
    struct GuardData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct GuardData
    {
    public:
        s32 mJmpStatus;  // offset: 0x0
        s32 mJmpStageNo;  // offset: 0x4
        u32 mJmpPosNo;  // offset: 0x8
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
    aStage();
    virtual ~aStage();
    virtual bool load();  // vtable slot 6
    virtual void init();  // vtable slot 7
    virtual void move();  // vtable slot 8
    virtual MT_CTSTR getShaderSegment();  // vtable slot 12
    virtual bool isRnoMain();  // vtable slot 13
    virtual bool isRno0MainRno1Main();  // vtable slot 14
protected:
    void move_init();
    void move_main();
    void move_to_lobby();
    void move_to_lobby_temple();
    void move_to_menu();
    void move_to_stage();
    void move_to_title();
    void move_to_launcher();
    void move_to_exit();
    void move_event();
    void move_event_fsm();
    void move_fade();
    void move_warp();
    void move_menu_warp();
    virtual void moveMain();  // vtable slot 15
    virtual void execGameMenuOpen();  // vtable slot 16
    virtual bool execGameMenuMsg();  // vtable slot 17
    virtual void execDbgGameMenu();  // vtable slot 18
    bool checkStageJump();
private:
    void movePause();
    void moveGameover();
    s32 moveDialog();
public:
    virtual void final();  // vtable slot 9
    virtual const MtDTI& getParentType();  // vtable slot 10
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    bool isLobby() const;
    bool isField() const;
    bool isSafeArea() const;
    bool isDungeon() const;
    bool isInitFade() const;
    void createGUIUnit();
    s32 getNextStage();
protected:
    void setRno(u8 r0, u8 r1);
    void setRno1(u8 r1, u8 r2);
    void setRno23(u8 r2, u8 r3);
    void setRno3(u8 r3);
    void killGameUnit();
private:
    void setPauseRno(s32 rno);
    void movePartyInvited();
    void moveQuickMatch();
protected:
    void updatePtr();
public:
    void initStageArchive(s32 stgNo);
    bool isLoadStageArchive();
    void setBlockArcLoad(s32 stgNo);
    void loadStageResource(s32 stgNo);
    void loadScenarioResource(s32 stgNo, u32 load_flag);
    void releaseStageResource();
    rStageInfo* getStageInfo() const;
    uScheduler* getScrSchdl() const;
    s32 getStageNo() const;
    bool requestStageJump(s32 stageNo, u32 posNo, u32 fadeType, bool isSync);
    bool requestAreaJump(const MtDTI* pdti);
    bool requestMenuJump();
    bool isExecuteMenuJump();
    bool isRequestJump();
    bool isEnableStageJump(bool isPermitLargeParty) const;
    bool isEnableStageJumpSce(s32 stageNo) const;
    bool getStartPosAng(s32 posNo, MtVector3& pos, MtVector3& ang, u32 idx);
    bool getLoadPos(MtVector3& pos);
    bool isSplitSbc(const MtVector3& pos);
    uStageJointCtrl* getStageJointCtrl() const;
    uStageFieldCtrl* getStageFieldCtrl() const;
    uStagePartsCtrl* getStagePartsCtrl() const;
    uStageRevivalPawn* getStageRevivalPawn() const;
    uStageCraftPawnCtrl* getCraftPawnCtrl() const;
    uStageMyRoom* getStageMyRoom() const;
    void updateCraftPawn();
    sCollision::SBC_HANDLE getScrSbcHandle(u32 idx);
    sCollision::SBC_HANDLE getEffSbcHandle(u32 idx);
    void requestCameraFld(u32 no, const uDDOModel* pObj);
    void requestCameraEvt(u32 no, const uDDOModel* pObj);
    const cCamExParam* getCameraParamFld(u32 no) const;
    const cCamExParam* getCameraParamEvt(u32 no) const;
    rOccluderEx* getOCC();
    rStartPos* getStartPos();
    bool isEnableJointArea(s32 areaNo);
    s32 getJointAreaNo(MtVector3& pos);
    u32 getStageMsgId() const;
    cTalkMsgData* getExmineMsgData() const;
    void setIsBase(bool f);
    bool isBase() const;
    u32 getLastBaseId() const;
    u32 getNowBaseId() const;
    void callNormalStageBGM();
    cDayNightColorFogParam getColorFogPD();
    rStageCustomPartsEx::HemiSphLight* getHemiSphLightPD();
    rStageCustomPartsEx::InfiLight* getInfiLightPD();
    rStageConnect* getStageConnect() const;
    s32 getJmpStatus() const;
    void setJmpStatus(s32 NewValue);
    s32 getJmpStageNo() const;
    void setJmpStageNo(s32 NewValue);
    u32 getJmpPosNo() const;
    void setJmpPosNo(u32 NewValue);
    bool isLoadNg();
protected:
    void dummyCallBack(void* param);
private:
    void releaseStageEffect();
    void loadResStageEffect();
public:
    uScheduler* getLightSchdl() const;
private:
    void constructWeather();
    void updatePtrWeather();
    void moveWeather();
    void loadResStageWeather();
    uScheduler* createStageWeatherScheduler(rScheduler* pRes);
    void releaseStageWeather();
public:
    uSoundTrigger* getSoundTrigger();
    void setSoundTrigger(rZone* pZone, const MtVector3& pos);
    uSoundGenerator* getSoundGenerator();
    void setSoundGenerator(rZone* pZone, const MtVector3& pos);
    uSoundOcclusion* getSoundOcclusion();
    void setSoundOcclusion(rZone* pZone, const MtVector3& pos);
    void constructSound();
    void loadResStageSound(s32 stgNo);
    void releaseResStageSound();
    bool isJointStage();
    bool isLestaniaStage() const;
    bool isFindamStage() const;
    bool isCustomStage();
    bool isRandStage();
    bool isSoloStage();
    bool isCraftStage();
    bool isMergoda();
    bool isPartyLargeStage();
    bool isRevivalPawnStage();
    bool isMyRoomStage();
    bool isTrainingRoomStage() const;
    bool isPartyOnlyStage();
    bool isUnitGroupStop();
    bool isStageSetup();
    cSplitBgm* getJointStageBgmType();
    u32 getSoundAttributeRequestSeNo(u32 reqNo, u32 attrId);
    rSoundAttributeSe* getSoundAttributeSe();
    rSoundRequest* getSoundAttributeRequest(u32 attrId, const MtVector3& pos);
    rSoundRequest* getSoundAttributeRequestToSndAttr(u32 attrSeId, const MtVector3& pos);
    rSoundAreaInfo* getStageAreaInfo();
    bool isPlayCamEv() const;
    void loadStageFixFsm();
    bool isEnableFSM(MT_CTSTR name) const;
    bool addFSMOrderFromName(MT_CTSTR filePath, u32 starter);
    bool addFSMEventFromName(MT_CTSTR filePath);
    bool addFSMCamEvFromName(u32 stageNo, s32 eventNo);
    bool addFSMCamEvFromName(MT_CTSTR filePath);
    void forcedTerminationFSMTask(MT_CTSTR name);
    bool loadWaypoint();
    rWaypoint* getWaypoint();
    bool isPlayEvent();
    bool checkEventPlay();
    void requestEventPlay(nStage::stEventParam* param);
    void executeEventPlay();
    s32 getReqEventId() const;
    void setReqEventId(s32 id);
    s32 getExecEventId() const;
    void setExecEventId(s32 id);
    void setEventBusy(bool flag);
    bool isEventBusy();
    bool isEventMove();
    bool isFsmEventMove();
    void setFsmEvent(bool sleep);
    bool isFsmEvent();
    bool isFsmEventPlay();
    void cancelFsmEvent();
    bool isFsmCancel();
    void stopMoveUnit(bool sleep);
    void stopMoveUnitLight(bool sleep, s32 event_no);
    void stopMoveUnitOm(bool sleep, s32 event_no);
    void stopMoveUnitFsm(bool sleep);
    void stopMoveUnitFsmSub(bool sleep);
    bool isPartyLoadFinish(s32 event_no);
    bool isStopUnit(u8 group, cUnit* pUnit);
    void updateMoveUnit();
    void finishEvent();
    cTalkMsgData* getFSMEventMsgData();
    rSoundStreamRequest* getFSMEventStreamSeData();
protected:
    void reqLoadEvArc(u8 fsm);
public:
    bool isLargeCamera();
    bool isDisableCreateCharacter() const;
    bool isDisableFadeIn() const;
    void setTutorialEquip();
    void resetTutorialEquip();
    void requestWarp(s32 startPosNo, u32 type);
    void warpPlPos(u32 startPosNo);
    void warpCommon();
    bool isStopSound();
    void soundWarpOutCommon();
    void soundWarpInCommon();
private:
    void loadResUnitCtrl();
    void releaseResUnitCtrl();
    void loadResZoneStatus();
    void releaseResZoneStatus();
    void moveLocation();
public:
    void setPerformanceCtrl(bool reset);
    void updatePerformanceCtrl();
private:
    void moveLeaveOnTheWay();
public:
    void setupProfile();
    void beginProfile(MOVE_PROFILE phase);
    void endProfile();
private:
    void initGetAnnounce();
    s32 moveGetAnnounce();
    void initGetGameTimeBaseInfo();
    s32 moveGetGameTimeBaseInfo();
public:
    bool isEndCreditGUI();
    void initEventLoading();
    void reqEventLoading(f32 wait);
protected:
    void moveCreateMyPawnAnnounce();
public:
    void setStageFeature(const CommonU32Vec& featureVec);
    void clearStageFeature();
    u32 getStageFeature(u32 idx);
    u32 getStageFeatureNum();
    void loadTreeResource(s32 stgNo);
    void initPlantTree(rPlantTree* pRes);
    void releasePlantTree();
protected:
    bool reviveWait();
public:
    bool isHouse(s32 stgNo);
    bool isKeepArchive();
    bool isReleaseArchive();
    void keepArcStage();
    void releaseKeepStage();
protected:
    u32 mStageType;  // offset: 0x30
    uGUICredit* mpGUICredit;  // offset: 0x38
    uGUIMapMini* mpGUIMapMini;  // offset: 0x40
    uGUIClock* mpGUIClock;  // offset: 0x48
    uGUIQuickParty* mpGUIQuickParty;  // offset: 0x50
    f32 mPawnJoinTimer;  // offset: 0x58
private:
    s32 mStatusDispRno;  // offset: 0x5c
    s32 mOptionRno;  // offset: 0x60
    s32 mOptionMenuCursor;  // offset: 0x64
    s32 mMsgLinkRno;  // offset: 0x68
    s32 mMsgLinkSelectCursor;  // offset: 0x6c
    s32 mMsgLinkSettingCursor;  // offset: 0x70
    s32 mMsgLinkEditValue;  // offset: 0x74
    s32 mMsgLinkEditMin;  // offset: 0x78
    s32 mMsgLinkEditMax;  // offset: 0x7c
public:
    cPlDeadFlow mPlDeadFlow;  // offset: 0x80
protected:
    s32 mTrueStageNo;  // offset: 0xb0
    rStageInfo* mpStageInfo;  // offset: 0xb8
    uScheduler* mpScrSchdl;  // offset: 0xc0
    uScheduler* mpFltrSchdl;  // offset: 0xc8
    sCollision::SBC_HANDLE mScrSbcHandle[3];  // offset: 0xd0
    sCollision::SBC_HANDLE mEffSbcHandle[3];  // offset: 0xdc
    TICKET mLotArcTicket;  // offset: 0xe8
    TICKET mEvArcTicket;  // offset: 0xf0
    TICKET mTelopArcTicket;  // offset: 0xf8
    rOccluderEx* mprOCC;  // offset: 0x100
    rStartPos* mprStartPos;  // offset: 0x108
    rStageConnect* mpStageConnect;  // offset: 0x110
    s32 mJointAreaNoPl;  // offset: 0x118
    u32 mStageMsgId;  // offset: 0x11c
    cTalkMsgData* mpStageMsgData;  // offset: 0x120
    MtVector3 mOldLoadPos;  // offset: 0x130
private:
    GuardData mGuardData;  // offset: 0x140
protected:
    u32 mJmpFadeType;  // offset: 0x14c
    const MtDTI* mpJmpDTI;  // offset: 0x150
    bool mbInitFade;  // offset: 0x158
    bool mbOmInitFlag;  // offset: 0x159
    bool mbOmFadeInFlag;  // offset: 0x15a
    bool mbOmFadeInFlagEnd;  // offset: 0x15b
    bool mbInitSound;  // offset: 0x15c
    bool mLoadNgFlag;  // offset: 0x15d
    bool mIsBase;  // offset: 0x15e
    bool mIsEntryBoardJoin;  // offset: 0x15f
    bool mIsExecuteMenuJump;  // offset: 0x160
    sItemManager::stRequest* mpReq;  // offset: 0x168
    u32 mLastBaseId;  // offset: 0x170
    u32 mNowBaseId;  // offset: 0x174
private:
    cStageEpvCtrl mStageEpvCtrl;  // offset: 0x180
    u32 mEfcEpvZoneGene;  // offset: 0x230
    uScheduler* mpEffSchdl;  // offset: 0x238
    uScheduler* mpLanternSchdl;  // offset: 0x240
    uScheduler* mpLightSchdl;  // offset: 0x248
protected:
    uSoundTrigger* mpSoundTrigger;  // offset: 0x250
    uSoundGenerator* mpSoundGenerator;  // offset: 0x258
    uSoundOcclusion* mpSoundOcclusion;  // offset: 0x260
    rSoundAttributeSe* mprSoundAttribute;  // offset: 0x268
private:
    TICKET mArcTicket;  // offset: 0x270
    s32 mPauseRno;  // offset: 0x278
    s32 mPauseMenuCursor;  // offset: 0x27c
    s32 mMemberListCursor;  // offset: 0x280
    s32 mSaveNext;  // offset: 0x284
protected:
    cFSMTaskCtrl* mpFSMTaskCtrl;  // offset: 0x288
    rWaypoint* mpWaypoint;  // offset: 0x290
    rSoundStreamRequest* mpEventStream;  // offset: 0x298
    bool mEventBusy;  // offset: 0x2a0
    bool mbFsmEvent;  // offset: 0x2a1
    bool mbFsmEventPlay;  // offset: 0x2a2
    bool mbFsmCancel;  // offset: 0x2a3
    s32 mReqEventId;  // offset: 0x2a4
    s32 mExecEventId;  // offset: 0x2a8
    s32 mOldEventId;  // offset: 0x2ac
    nStage::stEventParam mExecEventParam;  // offset: 0x2b0
    cTalkMsgData* mpFSMEventMsgData;  // offset: 0x2c0
    MtArray mMoveOff;  // offset: 0x2c8
    MtArray mDrawOff;  // offset: 0x2e8
public:
    uLargeEnemyCamera* mpLargeCamera;  // offset: 0x308
protected:
    s32 mJumpToStageNo;  // offset: 0x310
    s32 mJumpToPosNo;  // offset: 0x314
    bool mJumpSync;  // offset: 0x318
    uStageJointCtrl* mpStageJointCtrl;  // offset: 0x320
    uStageFieldCtrl* mpStageFieldCtrl;  // offset: 0x328
    uStagePartsCtrl* mpStagePartsCtrl;  // offset: 0x330
    uStageRevivalPawn* mpStageRevivalPawn;  // offset: 0x338
    uStageCraftPawnCtrl* mpStageCraftPawnCtrl;  // offset: 0x340
    uStageMyRoom* mpStageMyRoom;  // offset: 0x348
    s32 mWarpStartPosNo;  // offset: 0x350
    s32 mWarpType;  // offset: 0x354
    f32 mWarpWaitTimer;  // offset: 0x358
    MtVector3 mWarpStartPos;  // offset: 0x360
private:
    u32 mLocationTop;  // offset: 0x370
    nDDOUtility::cBitSet<128> mLocationFlag;  // offset: 0x374
public:
    uColorCorrectFilter* mpColorCorrectFilter;  // offset: 0x388
private:
    u32 mRnoGetAnnounce;  // offset: 0x390
    u32 mRnoGetGameTimeBaseInfo;  // offset: 0x394
protected:
    f32 mLoadingTimer;  // offset: 0x398
    u32 mStageFeature[5];  // offset: 0x39c
    MtTypedArray<cOmTreeControl> mOmTreeCtrl;  // offset: 0x3b0
public:
    static MyDTI DTI;
    static const u32 mTutorialEquip[10][15];
private:
    static const u32 LOCATION_NUM = 128;
};

// Inline, no code of its own: checked where it is inlined.
inline bool aStage::isExecuteMenuJump() {
    return this->mIsExecuteMenuJump;
}

// Inline, no code of its own: checked where it is inlined.
inline uStageJointCtrl* aStage::getStageJointCtrl() const {
    return this->mpStageJointCtrl;
}

// Inline, no code of its own: checked where it is inlined.
inline uStageFieldCtrl* aStage::getStageFieldCtrl() const {
    return this->mpStageFieldCtrl;
}

// Inline, no code of its own: checked where it is inlined.
inline uStagePartsCtrl* aStage::getStagePartsCtrl() const {
    return this->mpStagePartsCtrl;
}

// Inline, no code of its own: checked where it is inlined.
inline uStageCraftPawnCtrl* aStage::getCraftPawnCtrl() const {
    return this->mpStageCraftPawnCtrl;
}

// Inline, no code of its own: checked where it is inlined.
inline uStageMyRoom* aStage::getStageMyRoom() const {
    return this->mpStageMyRoom;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline s32 aStage::getJmpStatus() const {
    return this->mGuardData.mJmpStatus;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline s32 aStage::getJmpStageNo() const {
    return this->mGuardData.mJmpStageNo;
}

// Inline, no code of its own: checked where it is inlined.
inline rSoundAttributeSe* aStage::getSoundAttributeSe() {
    return this->mprSoundAttribute;
}

// Inline, no code of its own: checked where it is inlined.
inline bool aStage::isFsmEvent() {
    return this->mbFsmEvent;
}

// Inline, no code of its own: checked where it is inlined.
inline bool aStage::isFsmEventPlay() {
    return this->mbFsmEventPlay;
}
