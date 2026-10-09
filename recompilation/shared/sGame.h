#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "GpCourse.h"
#include "GpCourseEffect.h"
#include "L2C.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cCharacterData.h"
#include "cGameTime.h"
#include "cStageCtrl.h"
#include "cSystem.h"
#include "nAbility.h"
#include "nDDOUtility.h"
#include "nHuman.h"
#include "rArchive.h"

// Forward declarations
class CDataGPCourseEffectParam;
class CDataGPCourseInfo;
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector2;
class MtVector3;
class aStage;
class cAbilityData;
class cCharacterData;
class cContextInstHm;
class cContextInstance;
class cGUIUtility;
class cGameMoonAge;
class cGameTime;
class cGameWeather;
class cPlayPointInfo;
class cPlayerExpTable;
class cStageCtrl;
class cStageToSpot;
class cTalkMsgData;
class cWeaponResTable;
class cWepCateResTbl;
class cpJob02;
namespace nLoginSession { class CPacket_L2C_GP_COURSE_GET_INFO_RES; }
namespace nNetBase { class cNetBase; }
namespace nSessionManager { class cNetSessionManager; }
class rAbilityList;
class rAdjustParam;
class rArchive;
class rAreaInfo;
class rAreaInfoJointArea;
class rAreaInfoStage;
class rJobBaseParam;
class rJobLevelUpTbl2;
class rLandInfo;
class rPlayerExpTable;
class rStageToSpot;
class rTexture;
class rWeaponResTable;
class rWepCateResTbl;
class sNetworkExt;
class uControl;
class uDDOModel;
class uFade;
class uHuman;

// Declarations
class cChargeEffectUID;
class sGame;

// Type aliases from DWARF
using CGPCourseEffectParam = CDataGPCourseEffectParam;
using CGPCourseInfo = CDataGPCourseInfo;
using GPCourseEffectParamVec = MtTypedArray<CDataGPCourseEffectParam>;
using GPCourseInfoVec = MtTypedArray<CDataGPCourseInfo>;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using time_t = long int;
using t64 = time_t;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class cChargeEffectUID : public MtObject
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
    cChargeEffectUID();
    virtual ~cChargeEffectUID();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    u32 getUIDNum() const;
    void clearRefChargeEffect();
    void setUIDNum(u32 num);
    void resetChargeCount();
    bool isChargeEffect(s32 chargeId) const;
    u32 getChargeEffectParam0(s32 chargeId) const;
    u32 getChargeEffectParam1(s32 chargeId) const;
    void setChargeEffectUID(u32 chargeUID, bool flag);
private:
    bool isChargeEffectIndex(s32 index) const;
public:
    u8 getRefChargeEffectUID(u32 index) const;
    void setRefChargeEffectUID(const u8& NewValue, u32 index);
private:
    u8* mpRefChargeEffectUID;  // offset: 0x8
    u32 mNum;  // offset: 0x10
public:
    static MyDTI DTI;
};

class sGame : public cSystem
{
    // inferred: aStage::resetTutorialEquip names sGame::mpInstance
    friend class aStage;
    // inferred: cGUIUtility::IsChargeAttributeEnable names sGame::mCharData.mCharData.mOption.mIsDispCharges
    friend class cGUIUtility;
    // inferred: cpJob02::update names sGame::mCharData.mCharData.mOption.mIsCamDrama
    friend class cpJob02;
    // inferred: nNetBase::cNetBase::castMsgAddress names sGame::mpInstance
    friend class nNetBase::cNetBase;
    // inferred: nSessionManager::cNetSessionManager::createFlow names sGame::mCharData.mCharData.mMatchProfile.mInviteWait
    friend class nSessionManager::cNetSessionManager;
    // inferred: sNetworkExt::isClanLeader names sGame::mCharData.mCharData.mCardClan.mMyPost
    friend class sNetworkExt;
public:
    enum ANNOUNCE_TIME
    {
        ANNOUNCE_NONE = 0,
        ANNOUNCE_LAST_24H = 1,
        ANNOUNCE_LAST_1H = 2,
        ANNOUNCE_ALREADY_END = 2,
    };
    enum ANNOUNCE_TYPE
    {
        ANNOUNCE_TYPE_INVALID = 0,
        ANNOUNCE_TYPE_NONE = 1,
        ANNOUNCE_TYPE_ALL = 2,
        ANNOUNCE_TYPE_SHORT = 3,
    };
    enum FADE_TYPE
    {
        FADE_BLACK = 0,
        FADE_WHITE = 1,
    };
    enum LIKABILITY_LV
    {
        LIKABILITY_LV_NONE = 0,
        LIKABILITY_LV_1 = 1,
        LIKABILITY_LV_2 = 2,
        LIKABILITY_LV_3 = 3,
        LIKABILITY_LV_4 = 4,
    };
    enum
    {
        NET_INFO_MSG_NONE = 0,
        NET_INFO_MSG_JOIN_LOBBY = 1,
        NET_INFO_MSG_JOIN_PARTY = 2,
        NET_INFO_MSG_LEAVE_LOBBY = 3,
        NET_INFO_MSG_LEAVE_PARTY = 4,
        NET_INFO_MSG_PARTY_REQ = 5,
        NET_INFO_MSG_PARTY_REQ_CANCEL = 6,
        NET_INFO_MSG_PARTY_REQ_DECLINE = 7,
        NET_INFO_MSG_PARTY_REQ_BUSY = 8,
        NET_INFO_MSG_KICKED = 9,
        NET_INFO_MSG_BREAKUP = 10,
        NET_INFO_MSG_PARTY_JOIN_ORDER = 11,
        NET_INFO_MSG_QUICK_MATCH_SUCCESS = 12,
        NET_INFO_MSG_BIG_CYCLE_CHANGE = 13,
    };
    enum
    {
        CHARGE_COURSE_BLANK = 0,
    };
public:
    class MyDTI;
    struct GuardData;
    struct chargeEffectParam;
    struct chargeEffectSetting;
    class chargeCourseParam;
public:
    using JobLevelUpTbl = nDDOUtility::cArray<rJobLevelUpTbl2*, 10>;
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
        s32 mReqStageNo;  // offset: 0x0
        s32 mReqStartPosNo;  // offset: 0x4
    };
public:
    struct chargeEffectParam
    {
    public:
        chargeEffectParam();
        chargeEffectParam(u32 attr);
    public:
        u32 mAttr;  // offset: 0x0
    };
public:
    struct chargeEffectSetting
    {
    public:
        nGpCourse::E_GP_COURSE_EFFECT mID;  // offset: 0x0
        sGame::chargeEffectParam mParam;  // offset: 0x4
    };
public:
    class chargeCourseParam : public MtObject
    {
    public:
        chargeCourseParam();
        chargeCourseParam(bool, u64);
    public:
        u32 mCourseId;  // offset: 0x8
        bool mIsEnable;  // offset: 0xc
        bool mEndReserve;  // offset: 0xd
        sGame::ANNOUNCE_TIME mAnnounce;  // offset: 0x10
        sGame::ANNOUNCE_TYPE mAnnounceType;  // offset: 0x14
        u64 mEndTime;  // offset: 0x18
        u32 mPrioGroup;  // offset: 0x20
        u32 mPrioSameTime;  // offset: 0x24
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
    sGame();
    virtual ~sGame();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    static sGame* getInstance();
    void updatePtr();
    void initDecideCharacter();
    void initJoinLobby();
    void reflectContextMyPlayer(cCharacterData* pData);
    s32 getPlayerMemberIndex(uHuman* pPl);
    void setDummyContext(cContextInstHm* pContext, s32 index);
    void createPlayerInstance();
    void createPlayerInstance_Lobby();
    void createPlayerInstance_Party();
    void killPlayerInstance(u32 uniqId);
    void requestNextStage(s32 stageNo, s32 posNo);
    s32 getReqStageNo() const;
    s32 getReqStartPosNo() const;
    void setStageNo(s32 stageNo);
    s32 getStageNo() const;
    s32 getStageNoOld() const;
    void setStartPosNo(s32 posNo);
    s32 getStartPosNo() const;
    s32 getNextStage();
    void setReturnStage(s32 stageNo, s32 posNo);
    s32 getReturnStageNo() const;
    s32 getReturnStartPosNo() const;
    void reqJumpStageFromLobby(s32 stageNo, s32 posNo);
    void reqJumpStageFromStage(s32 stageNo, s32 posNo);
    bool isReqJumpStageFromLobby();
    void setIsReqJumpStageFromLobby(bool flag);
    bool isStageJumpSync() const;
    void setIsStageJumpSync(bool Flag);
    void startFortDefense(u32 cycleContentsScheduleId, u32 StartPos);
    void startRaidBoss(u32 cycleContentsScheduleId, u32 StartPos);
    void reqJumpStageFortDefence(u32 cycleContentsScheduleId);
    void reqJumpStageRaidBoss(u32 cycleContentsScheduleId, bool isWaitFade);
    void startEndContents(u32 questId);
    void reqJumpStageEndContents(u32 questId);
    bool isReqChangeServer();
    void setIsReqChangeServer(bool flag);
    bool isNewGame() const;
    void setIsNewGame(bool flag);
    bool isViaPrologue() const;
    void setIsViaPrologue(bool flag);
    bool isPlayPrologue();
    bool isPlayerEditNow() const;
    void setIsPlayerEditNow(bool flag);
protected:
    uControl* createPlayerCtrl(cContextInstHm* pContext);
    uHuman* createPlayerUnit_Lobby(uControl* pCtrl);
    uHuman* createPlayerUnit_Party(uControl* pCtrl);
public:
    uHuman* createPlayerUnit(uControl* pCtrl);
    void initPlayerUnit(uHuman* pPl, const cContextInstHm* pContext, MtVector3& Pos, MtVector3& Angle);
    void onDisableActionPlayer();
    void offDisableActionPlayer();
    bool isDisableActionPlayer();
private:
    s32 getReqStageNoPrivate() const;
    void setReqStageNoPrivate(s32 NewValue);
    s32 getReqStartPosNoPrivate() const;
    void setReqStartPosNoPrivate(s32 NewValue);
public:
    f32 getBaseParam(u32 index) const;
    rJobBaseParam* getJobBaseParam() const;
    const cAbilityData* getAbilityData(nAbility::ABILITY_ID id) const;
    cPlayerExpTable* getPlayerExpTable(u32 level) const;
    u32 getPlayerLvMax() const;
    void LoadPlayerExpTable();
    void ReleasePlayerExpTable();
    rJobLevelUpTbl2* getJobLevelUpTbl2(nHuman::JOB_ENUM job) const;
    cPlayPointInfo* getPlayPointInfo() const;
    nNetBase::cNetBase* getNetBase();
    void callbackEntryLobby(u32 characterId, u32 pawnId);
    void callbackLeaveLobby(u32 characterId, u32 pawnId);
    void callbackEntryParty(s32 memberIndex);
    void callbackLeaveParty(s32 memberIndex);
    void reqNetInfo(u32 id, MT_CTSTR pName, s32 param, s32 sec);
    void reqNetInfoUTF8(u32, MT_CTSTR, s32, s32);
    bool isNoGetMemberIndex();
    bool isMySelfPartyMemberIndex(s32 memberIndex);
    bool isMySelfCharacterId(u32 characterId);
    bool isPawn(s32 memberIndex);
    s32 getSelfMemberIndex();
    s32 getMemberNum(bool isBeforeJoinMember);
    s32 getPlayerMemberNum(bool isBeforeJoinMember);
    s32 getPawnMemberNum(bool isBeforeJoinMember);
    bool isParty(s32 memberIndex);
    bool isParty();
    void setIsParty(s32 memberIndex, bool flag);
    void setContextStage();
    void sendContextStage();
    void sendReqLostReturnInfo();
    void sendContextReviveStock();
    cCharacterData* getCharData();
    cCharacterData::stTutorialGuide* getTutorialGuide();
    cCharacterData::stJobMasterInfo* getJobMasterInfo();
    cCharacterData::stAreaMasterInfo* getAreaMasterInfo();
    void onEnteredLand(u32 StageNo);
    bool isEnteredLand(u32 LandId);
    u16 getLimitJobLevel();
    void setLimitJobLevel(u16 level);
    u16 getLimitOrbUse();
    u16 getLimitCraftLevel();
    void setLimitCraftLevel(u16 level);
    u16 getLimitCraftSkillLevel();
    void setLimitCraftSkillLevel(u16 level);
    u32 getLimitJobPoint();
    void setLimitJobPoint(u32 jp);
    void dispLimitJobPointLog(u32 jp, MT_CTSTR pawn_name);
    u8 getReviveStock();
    void setReviveStock(u8 stock);
    void useReviveStock();
    void restockReviveStock();
    bool canReviveStock();
    void setCanReviveStock(bool flag);
    void sendContextFreeMarker();
    void resetChargeFlagAll();
    void clearChargeCourse();
    void initChargeCourse();
    void setChargeCourse(u32 courseId, bool flag, u64 endTime, bool isAnnounce, bool isExtend, u32 characterId);
    u32 getChargeCourseVersion() const;
    void setChargeCourseVersion(u32 version);
    chargeCourseParam* getChargeCourse(u32 courseId);
    chargeCourseParam* getChargeCourseIndex(u32 index);
    u32 getChargeCourseNum();
    u64 getChargeCourseEndTime(u32 courseId);
    u64 getChargeCourseEndTimeIndex(u32 index);
    bool isChargeCourseEnable(u32 courseId);
    bool isChargeCourseEnableIndex(u32 index);
    void setChargeCourseEndRserve();
    void setChargeCourseEnd();
    nLoginSession::CPacket_L2C_GP_COURSE_GET_INFO_RES& PacketGPCourseInfo();
    const GPCourseInfoVec& getGPCourseInfoVec() const;
    const GPCourseEffectParamVec& getGPCourseEffectParamVec() const;
    void setChargeEffectUID(u32 chargeUID, bool flag);
    void setChargeEffectFromCourse(u32 courseId, bool flag, u32 characterId);
    ANNOUNCE_TIME checkChargeAnnounceTime(u64 endTime);
    bool isChargeEffect(nGpCourse::E_GP_COURSE_EFFECT chargeId) const;
    s32 getChargeEffectIdx(nGpCourse::E_GP_COURSE_EFFECT chargeId, s32 startIdx) const;
    u32 getChargeEffectAttr(nGpCourse::E_GP_COURSE_EFFECT chargeId) const;
    bool isChargeEffectAttr(nGpCourse::E_GP_COURSE_EFFECT chargeId, u32 attr) const;
    u32 getChargeEffectParam0(nGpCourse::E_GP_COURSE_EFFECT chargeId) const;
    u32 getChargeEffectParam1(nGpCourse::E_GP_COURSE_EFFECT chargeId) const;
    const CGPCourseInfo* getChargeInfo(u32 CourseId);
    void setChargeEffectFlagContext(u32 charId, u32 chargeUID, bool flag);
    u32 getChargeEffectUIDNum() const;
    s32 getChargeEffectUIDIdx(u32 chargeUID) const;
    const CGPCourseEffectParam* getChargeEffectUID(u32 chargeUID) const;
    bool isChargeAnnounce(nGpCourse::E_GP_COURSE_ANNOUNCE_TYPE type, bool isParty);
    void setLobbyIn(bool flag);
    u32 getUseItemSlotLimitByStorage();
    void setUseItemSlotLimitByStorage(u32);
    u32 getMaterialItemSlotLimitByStorage();
    void setMaterialItemSlotLimitByStorage(u32);
    u32 getArmItemSlotLimitByStorage();
    void setArmItemSlotLimitByStorage(u32);
    u32 getJobItemSlotLimitByStorage();
    void setJobItemSlotLimitByStorage(u32);
    u32 getAllItemSlotLimitByStorage();
    void setAllItemSlotLimitByStorage(u32 num);
    u32 getUseItemSlotLimitByStorageEx();
    void setUseItemSlotLimitByStorageEx(u32);
    u32 getMaterialItemSlotLimitByStorageEx();
    void setMaterialItemSlotLimitByStorageEx(u32);
    u32 getArmItemSlotLimitByStorageEx();
    void setArmItemSlotLimitByStorageEx(u32);
    u32 getJobItemSlotLimitByStorageEx();
    void setJobItemSlotLimitByStorageEx(u32);
    u32 getAllItemSlotLimitByStorageEx();
    void setAllItemSlotLimitByStorageEx(u32 num);
    u32 getUseItemSlotLimitByMyBag();
    void setUseItemSlotLimitByMyBag(u32 num);
    u32 getMaterialItemSlotLimitByMyBag();
    void setMaterialItemSlotLimitByMyBag(u32 num);
    u32 getArmItemSlotLimitByMyBag();
    void setArmItemSlotLimitByMyBag(u32 num);
    u32 getJobItemSlotLimitByMyBag();
    void setJobItemSlotLimitByMyBag(u32 num);
    u32 getKeyItemSlotLimitByMyBag();
    void setKeyItemSlotLimitByMyBag(u32 num);
    void reqGameTime(u32 msec);
    void setGameTimePause(bool b);
    u32 getGameTime() const;
    u32 getGameHour() const;
    u32 getGameMinute() const;
    u32 getGameSecond() const;
    u32 getWeatherID() const;
    void reqWeatherID(u32 id);
    s32 getMoonAge() const;
    void reqMoonAge(s32 age);
    bool isMoonAgeNew() const;
    bool isMoonAgeFullMoon() const;
    bool isMoonAgeOther() const;
    cStageCtrl& getStageCtrl();
    void fadeOut(f32 frame, u32 type);
    void fadeIn(f32 frame, u32 type);
    bool isFadeEnd();
    bool isFadeOut();
    void eraseFade();
    bool isFadeBlack();
    bool isFadeIn();
    bool isFadeOutBusy();
    bool isFadeTypeBlack();
    s32 getFadeType() const;
    void setFadeType(s32 type);
    bool isEventTreeHIGH() const;
    void setEventTreeHIGH(bool f);
    bool isOnLantern();
    void setContextPawn(const cCharacterData::stPawnData& src, cContextInstHm& dst, u8 pawnType, u32 ownerId, u32 pawnId, bool resetFlag);
    void leavePawn(u32 pawnMemIndex);
    void clearPawnValue();
    void lostPawn(uDDOModel* pLostPawn);
    void lostPawn(cContextInstance* pLostPawn);
    void reqPawnTalkLost(uDDOModel* pLostPawn);
    void reqPawnTalkLost(cContextInstance* pLostPawn);
    void jumpCharEdit(u32 type, const MtDTI& retArea, u32 slotNo);
    void jumpCharEdit(u32 type, u32 retStage, u32 retPos, u32 slotNo);
    void returnCharEdit();
    u32 getCharEditType() const;
    u32 getCharEditPawnSlotNo() const;
    void setPawnEditAnnounce(bool f);
    bool isPawnEditAnnounce() const;
    u32 getPawnCreateItemID();
    void setPawnCreateItemID(u32 id);
    u32 getPawnCreateItemNum();
    void setPawnCreateItemNum(u32 num);
    void sendPawnOrder();
    u32 getPartnerPawnId();
    void setPartnerPawnId(u32 id);
    u32 getPartnerPawnPersonality() const;
    void setPartnerPawnPersonality(u32 personality);
    u32 getLikability();
    void setLikability(u32 likability);
    u32 getPawnPresentItemID();
    void setPawnPresentItemID(u32 id);
    u32 getPawnPresentItemNum();
    void setPawnPresentItemNum(u32 num);
    bool isBossBattle();
    bool isGameOverLobby() const;
    void setGameOverLobby(bool flg);
protected:
    void registAISituationValue();
public:
    void createHumanParam();
    void deleteHumanParam();
    rWeaponResTable* getWepResTable();
    void createWepArcParam();
    void deleteWepArcParam();
    void createWepResIndex();
    cWeaponResTable* getWepResData(u32 tagId, u32 sex);
    static cWeaponResTable* getWepResData(rWeaponResTable* pWepResTable, u32 tagId, u32 sex);
    void createWepCateIndex();
    cWepCateResTbl* getWepCateResData(u32 category);
    u32* getWepResIndexTbl();
private:
    cWeaponResTable* getWepResDataCore(rWeaponResTable* pWepResTable, u32* pWepResIndexTbl, u32 tagId, u32 sex);
public:
    void createAreaInfoResource();
    void releaseAreaInfoResrouce();
    u32 getAreaNum() const;
    u32 getArea(MtVector3* pPos);
    u32 getArea(s32 stageNo, MtVector3* pPos);
    bool isExistArea(u32 AreaId);
    u32 getAreaIdFromIdx(u32 index);
    u32 getAreaIndexFromId(u32 AreaId);
    MtVector2 getNewsMapPoint(u32 areaId);
    u32 getLandNum() const;
    u32 getLandId();
    u32 getLandId(u32 areaId);
    u32 getAreaNumInLand(u32 landId);
    u32 getEnableAreaNumInLand(u32 landId);
    u32 getLandIdFromIdx(u32 index);
    u32 getLandIdFromStage(s32 stageNo);
    void loadCommonData();
    void releaseCommonData();
    cTalkMsgData* getExmineMsgData() const;
    cStageToSpot* getStageToSpot(u32 stageNo);
    bool isOpeningMovieLook();
    void setOpeningMovieLook(bool isLook, bool isSave);
    void updateLastBase(u32 baseId);
    void setPartyWarpInfo(u32 id, u32 sec);
    u32 getPartyWarpLimit();
    u32 getPartyWarpId();
    u32 getPartyWarpSecOrigin();
    u32 getClanPoint();
    void setClanPoint(u32 cp);
    u32 getFromJobToRole(nHuman::JOB_ENUM jobId);
    const u32* getFromRoleToJob(nHuman::ROLE_ENUM roleId, u32* num);
    void setEnablePointShadow(bool flag);
    bool isEnableLobbyLanternShadow() const;
    void setEnableLobbyLanternShadow(bool flag);
private:
    void initKeepArc();
    void releaseKeepAll();
public:
    bool keepArc(rArchive* arc_ptr);
    bool releaseKeepArc(rArchive* arc_ptr);
    void releaseKeepArc();
    void keepArcGUI();
    void releaseKeepGUI();
    void keepArcTex();
    void releaseKeepTex();
    void keepArcOm();
    void releaseKeepOm();
private:
    GuardData mGuardData;  // offset: 0x14
    s32 mStageNo;  // offset: 0x1c
    s32 mStageNoOld;  // offset: 0x20
    s32 mStartPosNo;  // offset: 0x24
    bool mIsReqJumpStageFromLobby;  // offset: 0x28
    bool mIsReqChangeServer;  // offset: 0x29
    bool mIsNewGame;  // offset: 0x2a
    bool mIsViaPrologue;  // offset: 0x2b
    bool mIsPlayerEditNow;  // offset: 0x2c
    bool mIsReqSyncAreaJump;  // offset: 0x2d
    s32 mReturnStageNo;  // offset: 0x30
    s32 mReturnStartPosNo;  // offset: 0x34
    bool mDisableActionPlayer;  // offset: 0x38
    rAdjustParam* mpBaseParam;  // offset: 0x40
    rJobBaseParam* mpJobBaseParam;  // offset: 0x48
    rAbilityList* mpAblityList;  // offset: 0x50
    rPlayerExpTable* mpExpTable;  // offset: 0x58
    JobLevelUpTbl mpJobLevelUpTbl2;  // offset: 0x60
    u32* mpWepResIndexTbl;  // offset: 0xb0
    rWeaponResTable* mpWepResTable;  // offset: 0xb8
    rWepCateResTbl* mpWepCateResTbl;  // offset: 0xc0
    cPlayPointInfo* mpPlayPointInfo;  // offset: 0xc8
    nNetBase::cNetBase* mpNetRpc;  // offset: 0xd0
    bool mIsParty[8];  // offset: 0xd8
    cCharacterData mCharData;  // offset: 0xe0
    u16 mLimitJobLevel;  // offset: 0x3428
    u16 mLimitCraftLevel;  // offset: 0x342a
    u16 mLimitCraftSkillLevel;  // offset: 0x342c
    u32 mLimitJobPoint;  // offset: 0x3430
    nLoginSession::CPacket_L2C_GP_COURSE_GET_INFO_RES mPacketGPCourseInfo;  // offset: 0x3438
    u32 mChargeCourseVersion;  // offset: 0x3490
    MtTypedArray<chargeCourseParam> mChargeCourseParam;  // offset: 0x3498
    cChargeEffectUID mChargeEffectUID;  // offset: 0x34b8
    bool mIsLobbyIn;  // offset: 0x34d0
    u32 mUseItemSlotLimitByStorage;  // offset: 0x34d4
    u32 mMaterialItemSlotLimitByStorage;  // offset: 0x34d8
    u32 mArmItemSlotLimitByStorage;  // offset: 0x34dc
    u32 mJobItemSlotLimitByStorage;  // offset: 0x34e0
    u32 mAllItemSlotLimitByStorage;  // offset: 0x34e4
    u32 mUseItemSlotLimitByStorageEx;  // offset: 0x34e8
    u32 mMaterialItemSlotLimitByStorageEx;  // offset: 0x34ec
    u32 mArmItemSlotLimitByStorageEx;  // offset: 0x34f0
    u32 mJobItemSlotLimitByStorageEx;  // offset: 0x34f4
    u32 mAllItemSlotLimitByStorageEx;  // offset: 0x34f8
    u32 mUseItemSlotLimitByMyBag;  // offset: 0x34fc
    u32 mMaterialItemSlotLimitByMyBag;  // offset: 0x3500
    u32 mArmItemSlotLimitByMyBag;  // offset: 0x3504
    u32 mJobItemSlotLimitByMyBag;  // offset: 0x3508
    u32 mKeyItemSlotLimitByMyBag;  // offset: 0x350c
    cGameTime mGameTime;  // offset: 0x3510
    cGameWeather mGameWeather;  // offset: 0x351c
    cGameMoonAge mGameMoonAge;  // offset: 0x3528
    cStageCtrl mStageCtrl;  // offset: 0x3538
    uFade* mpFade;  // offset: 0x3568
    u32 mFadeType;  // offset: 0x3570
    bool mEventTreeHIGH;  // offset: 0x3574
    u32 mCharEditType;  // offset: 0x3578
    u32 mCharEditSlotNo;  // offset: 0x357c
    const MtDTI* mpCharEditReturnArea;  // offset: 0x3580
    u32 mCharEditStageNo;  // offset: 0x3588
    u32 mCharEditRetPosNo;  // offset: 0x358c
    bool mPawnEditAnnounce;  // offset: 0x3590
    u32 mPawnCreateItemID;  // offset: 0x3594
    u32 mPawnCreateItemNum;  // offset: 0x3598
    u32 mPartnerPawnId;  // offset: 0x359c
    u32 mPartnerPawnPersonality;  // offset: 0x35a0
    u32 mLikability;  // offset: 0x35a4
    u32 mPawnPresentItemID;  // offset: 0x35a8
    u32 mPawnPresentItemNum;  // offset: 0x35ac
    bool mCanReviveStock;  // offset: 0x35b0
    bool mIsBossBattle;  // offset: 0x35b1
    bool mIsGameOverLobby;  // offset: 0x35b2
    rAreaInfo* mpAreaInfo;  // offset: 0x35b8
    rAreaInfoJointArea* mpAreaInfoJointArea;  // offset: 0x35c0
    rAreaInfoStage* mpAreaInfoStage;  // offset: 0x35c8
    rLandInfo* mpLandInfo;  // offset: 0x35d0
    cTalkMsgData* mpCommonMsgData;  // offset: 0x35d8
    rStageToSpot* mpStageToSpot;  // offset: 0x35e0
    bool mIsOpeningMovieLook;  // offset: 0x35e8
    u32 mLastBaseId;  // offset: 0x35ec
    t64 mPartyWarpLimit;  // offset: 0x35f0
    u32 mPartyWarpId;  // offset: 0x35f8
    u32 mPartyWarpSecOrigin;  // offset: 0x35fc
    bool mIsEnableLobbyLanternShadow;  // offset: 0x3600
    rArchive* mKeepArc[8];  // offset: 0x3608
    rArchive* mKeepGUI[16];  // offset: 0x3648
    rTexture* mKeepTex[32];  // offset: 0x36c8
    MtTypedArray<rArchive> mKeepOm;  // offset: 0x37c8
    static sGame* mpInstance;
public:
    static MyDTI DTI;
    static const u32 CHARGE_BLANK = 0;
    static const u32 CH_EFT_ATTR_NONE = 0;
    static const u32 CH_EFT_ATTR_REVIVE_STOCK = 1;
    static const u32 CH_EFT_ATTR_ITEMBOX = 2;
    static const u32 CH_EFT_ATTR_RIM_WARP = 4;
    static const u32 CH_EFT_ATTR_OUTPOST_WARP = 8;
    static const u32 CH_EFT_ATTR_QUEST_MAIN = 16;
    static const u32 CH_EFT_ATTR_QUEST_WORLD = 32;
    static const u32 CH_EFT_ATTR_QUEST_BOARD = 64;
    static const u32 CH_EFT_ATTR_QUEST_GM = 128;
    static const u32 CH_EFT_ATTR_SHOP = 256;
    static const u32 CH_EFT_ATTR_BAZAAR = 512;
    static const u32 CH_EFT_ATTR_AREA_MASTER = 1024;
    static const u32 CH_EFT_ATTR_DROP = 2048;
    static const u32 CH_EFT_ATTR_GATHER = 4096;
    static const u32 CH_EFT_ATTR_MINING = 8192;
    static const u32 CH_EFT_ATTR_FELL = 16384;
    static const u32 CH_EFT_ATTR_TREASURE_BOX = 32768;
    static const u32 CH_EFT_ATTR_CRAFT = 65536;
    static const u32 CH_EFT_ATTR_STATUS = 131072;
    static const u32 CH_EFT_ATTR_INN = 262144;
    static const u32 CH_EFT_ATTR_RESCUE_PL = 524288;
    static const u32 CH_EFT_ATTR_RESCUE_PAWN = 1048576;
    static const u32 CH_EFT_ATTR_QUEST_WORLD_REWARD = 2097152;
    static const u32 CH_EFT_ATTR_QUEST_BOARD_REWARD = 4194304;
    static const u32 CH_EFT_ATTR_EXTREME_MISSION_REWARD = 8388608;
    static const u32 CH_EFT_ATTR_RIM_STONE = 16777216;
    static const u32 CH_EFT_ATTR_CHEST = 33554432;
    static const u32 CH_EFT_ATTR_IGNORE_GM = 67108864;
    static const u32 CH_EFT_ATTR_IGNORE_EXM = 134217728;
private:
    static chargeEffectParam mChargeEffectParam[51];
    static const chargeEffectSetting mChargeEffectDefault[];
public:
    static const u32 warp_point_id_lobby = 1;
    static const u32 warp_point_id_my_room = 53;
    static const u32 warp_point_id_clan_base = 66;
private:
    static const u32 KEEP_ARC_MAX = 8;
    static const u32 KEEP_GUI_MAX = 16;
    static const u32 KEEP_TEX_MAX = 32;
};

// Inline, no code of its own: checked where it is inlined.
inline sGame* sGame::getInstance() {
    return ::sGame::mpInstance;
}

// Inline, no code of its own: checked where it is inlined.
inline s32 sGame::getReqStageNo() const {
    return this->mGuardData.mReqStageNo;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline s32 sGame::getStageNoOld() const {
    return this->mStageNoOld;
}

// Inline, no code of its own: checked where it is inlined.
inline void sGame::offDisableActionPlayer() {
    this->mDisableActionPlayer = false;
}

// Inline, no code of its own: checked where it is inlined.
inline cPlayPointInfo* sGame::getPlayPointInfo() const {
    return this->mpPlayPointInfo;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline u32* sGame::getWepResIndexTbl() {
    return this->mpWepResIndexTbl;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 sGame::getPartyWarpId() {
    return this->mPartyWarpId;
}
