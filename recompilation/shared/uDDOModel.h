#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "cArcLoader.h"
#include "cComponentManager.h"
#include "cContextInterface.h"
#include "cDamageMsg.h"
#include "cDelegate.h"
#include "ctl_storageArray.h"
#include "nAction.h"
#include "nCatch.h"
#include "nDDOModel.h"
#include "nDDOUtility.h"
#include "nObjCollision.h"
#include "nObjCondition.h"
#include "uModel.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtQuaternion;
class MtVector3;
class cAsyncArc;
class cAttackParam;
class cBlowShrinkDmInfo;
class cCollNode;
class cComponentManager;
class cContextCharacter;
class cContextInstance;
class cContextInterface;
class cDamageMsg;
class cDamageSeInfo;
class cDraw;
class cGUIUtility;
class cGeneralPoint;
class cGeneralPointIterator;
class cGroundAttrInfo;
class cGroupParam;
class cHitGeom;
class cHitInfo;
class cHitInfoAfter;
class cHitNode;
class cOcdInfo;
class cParentRegionStatus;
class cShlNotifyInfo;
class cState;
class cUnitDieInfo;
class cpAISensor;
class cpActionManager;
class cpActionRequest;
class cpActionSelect;
class cpCatchCtrl;
class cpChargeCtrl;
class cpCheckWallCliff;
class cpComponent;
class cpCorePointCtrl;
class cpDDMrlMgr;
class cpEffectProvider;
class cpEffectStatusManager;
class cpEnemyThink;
class cpEquip;
class cpErosionEnemySmall;
class cpHpDamageCtrl;
class cpHugeble;
class cpInput;
class cpInvincibleCtrl;
class cpItemThrow;
class cpJob02;
class cpJob03;
class cpJob04;
class cpJob05;
class cpJob06;
class cpJob09;
class cpJob10;
class cpKeepAtkAdjust;
class cpLayout;
class cpLockOn;
class cpLockOnTargetManager;
class cpModelConst;
class cpMotionHistory;
class cpMotionSe;
class cpNpc;
class cpObjCollisionBase;
class cpOcdCtrl;
class cpPartsCtrl;
class cpPathFinding;
class cpPawnThink;
class cpPivotCtrl;
class cpRegionStatusCtrl;
class cpRotateCtrl;
class cpSafePos;
class cpScrCollision;
class cpSequenceCtrl;
class cpShlShotCtrl;
class cpSlave;
class cpSoftBody;
class cpStateManager;
class cpStatusChange;
class cpTalk;
class cpWallExitCtrl;
class cpWorkRate;
namespace nHuman { struct stShellRequestMsg; }
namespace nLayout { struct stLayoutID; }
namespace nLayout { struct stSplitID; }
namespace nMotion { struct MOTION_INFO; }
namespace nObjCondition { struct stHolyAbsorpReqMsg; }
class rArchive;
class rModel;
class rShlParamList;
class sAIPawnSys;
class uAimCheck;
class uCharacter;
class uControl;
class uControlNpc;
class uEnemy;
class uHuman;
class uHumanEnemy;
class uNpc;
class uOmModel;
class uPawn;
class uPlayer;
class uShlBase;

// Declarations
class uDDOModel;

// Type aliases from DWARF
using u32 = unsigned int;
using ARC_TAGID = u32;
using __uint64_t = long unsigned int;
using u64 = __uint64_t;
using BitData = u64;
using HP_DATATYPE = u64;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;

class uDDOModel : public uModel
{
    // inferred: cGUIUtility::isEquipLantern names uDDOModel::mContextInterface.mpContextInstance
    friend class cGUIUtility;
    // inferred: cParentRegionStatus::setHp names uDDOModel::mContextInterface.mpContextInstance
    friend class cParentRegionStatus;
    // inferred: cpCatchCtrl::forceCancel names uDDOModel::mContextInterface.mpContextInstance
    friend class cpCatchCtrl;
    // inferred: cpCorePointCtrl::checkSlaveMsg names uDDOModel::mContextInterface.mpContextInstance
    friend class cpCorePointCtrl;
    // inferred: cpEnemyThink::callbackGetAction names uDDOModel::mGuardComponent.mpActMgr
    friend class cpEnemyThink;
    // inferred: cpErosionEnemySmall::checkReciveMsg names uDDOModel::mContextInterface.mpContextInstance
    friend class cpErosionEnemySmall;
    // inferred: cpHpDamageCtrl::callbackHealedAfter_make names uDDOModel::mContextInterface.mpContextInstance
    friend class cpHpDamageCtrl;
    // inferred: cpItemThrow::offItemMode names uDDOModel::mContextInterface.mpContextInstance
    friend class cpItemThrow;
    // inferred: cpJob02::callbackDamageTest names uDDOModel::mGuardComponent.mpActMgr
    friend class cpJob02;
    // inferred: cpJob03::setIsJustShot names uDDOModel::mContextInterface.mpContextInstance
    friend class cpJob03;
    // inferred: cpJob04::killHealSpot names uDDOModel::mShlDeleteBit
    friend class cpJob04;
    // inferred: cpJob05::callbackCatch_Shl names uDDOModel::mContextInterface.mpContextInstance
    friend class cpJob05;
    // inferred: cpJob06::killCS14Shl names uDDOModel::mShlDeleteBit
    friend class cpJob06;
    // inferred: cpJob09::setContextCS03ValueMax names uDDOModel::mContextInterface.mpContextInstance
    friend class cpJob09;
    // inferred: cpJob10::callbackAttack names uDDOModel::mGuardComponent.mpActMgr
    friend class cpJob10;
    // inferred: cpPawnThink::sortFuncCharacterHp names uDDOModel::mContextInterface.mpContextInstance
    friend class cpPawnThink;
    // inferred: cpSlave::getTargetUID names uDDOModel::mContextInterface.mpContextInstance
    friend class cpSlave;
    // inferred: sAIPawnSys::setPawnOwnerTarget names uDDOModel::mGpCategoy
    friend class sAIPawnSys;
    // inferred: uCharacter::setupActPreInit names uDDOModel::mGuardComponent.mpActMgr
    friend class uCharacter;
    // inferred: uControl::connectModel names uDDOModel::mpCtrl
    friend class uControl;
    // inferred: uEnemy::setupContextEnemyStatusChange names uDDOModel::mContextInterface.mpContextInstance
    friend class uEnemy;
    // inferred: uHuman::setupBeforeContext names uDDOModel::mGuardComponent.mpHpDamageCtrl
    friend class uHuman;
    // inferred: uNpc::controlLantern names uDDOModel::mContextInterface.mpContextInstance
    friend class uNpc;
public:
    enum PROFILE_TYPE
    {
        PROFILE_MOVE = 0,
        PROFILE_SYNC = 1,
        PROFILE_MOVEAFTER = 2,
        PROFILE_NUM = 3,
    };
    enum PROFILE_MOVE_PHASE
    {
        PROFILE_MOVE_00_ALL = 0,
        PROFILE_MOVE_01_OMLINECTRL = 1,
        PROFILE_MOVE_02_CALLBACKMOVEBEGIN = 2,
        PROFILE_MOVE_03_ENABLESCALE = 3,
        PROFILE_MOVE_04_COMPMANAGER_UPDATE = 4,
        PROFILE_MOVE_05_UPDATE_INPUT = 5,
        PROFILE_MOVE_06_OBJADJUST = 6,
        PROFILE_MOVE_07_BEFORE = 7,
        PROFILE_MOVE_08_CHECKACTION = 8,
        PROFILE_MOVE_09_CHECKKEYCMDFUNC = 9,
        PROFILE_MOVE_0A_UPDATE = 10,
        PROFILE_MOVE_0B_UPDATEOBJSTATUS = 11,
        PROFILE_MOVE_0C_CALLBACKUPDATEAFTER = 12,
        PROFILE_MOVE_0D_UPDATEPOSITION = 13,
        PROFILE_MOVE_0E_CHECKWORKRATE = 14,
        PROFILE_MOVE_0F_CHECKMOTIONRATE = 15,
        PROFILE_MOVE_10_UPDATEMOTION = 16,
        PROFILE_MOVE_11_CALLBACKAFTERUPDATEMOTION = 17,
        PROFILE_MOVE_12_SCRADJUST = 18,
        PROFILE_MOVE_13_UPDATEMATRIX = 19,
        PROFILE_MOVE_14_CALLBACKAFTERUPDATEMATRIX = 20,
        PROFILE_MOVE_15_UPDATEGROUNDINFO = 21,
        PROFILE_MOVE_16_AFTER = 22,
        PROFILE_MOVE_17_OBJCOLLISIONUPDATE = 23,
        PROFILE_MOVE_18_CALLBACKMOVEEND = 24,
        PROFILE_MOVE_NUM = 25,
    };
    enum PROFILE_SYNC_PHASE
    {
        PROFILE_SYNC_00_ALL = 0,
        PROFILE_SYNC_01_SUPER_SYNC = 1,
        PROFILE_SYNC_02_COMPMANAGER_SYNC = 2,
        PROFILE_SYNC_03_CHECKCALCDAMAGE = 3,
        PROFILE_SYNC_04_TOUCHRELEASE = 4,
        PROFILE_SYNC_NUM = 5,
    };
    enum PROFILE_MOVEAFTER_PHASE
    {
        PROFILE_MOVEAFTER_00_ALL = 0,
        PROFILE_MOVEAFTER_01_COMPMANAGER_MOVEAFTER = 1,
        PROFILE_MOVEAFTER_02_SUPER_MOVEAFTER = 2,
        PROFILE_MOVEAFTER_03_UPDATEHITSTOP = 3,
        PROFILE_MOVEAFTER_04_SETCOMMONSTATEMRLCTRL = 4,
        PROFILE_MOVEAFTER_05_UPDATEDRAWFLAG = 5,
        PROFILE_MOVEAFTER_NUM = 6,
    };
public:
    class MyDTI;
    struct GuardComponent;
    class cOutLineController;
    struct stTouchReleaseInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct GuardComponent
    {
    public:
        cpWorkRate* mpWorkRate;  // offset: 0x0
        cpObjCollisionBase* mpObjCollision;  // offset: 0x8
        cpScrCollision* mpScrCollision;  // offset: 0x10
        cpActionManager* mpActMgr;  // offset: 0x18
        cpInput* mpInput;  // offset: 0x20
        cpActionSelect* mpActionSelect;  // offset: 0x28
        cpActionRequest* mpActionRequest;  // offset: 0x30
        cpSequenceCtrl* mpSequenceCtrl;  // offset: 0x38
        cpHpDamageCtrl* mpHpDamageCtrl;  // offset: 0x40
        cpCatchCtrl* mpCatchCtrl;  // offset: 0x48
        cpStateManager* mpStateAction;  // offset: 0x50
        cpStateManager* mpStateLive;  // offset: 0x58
        cpLockOn* mpLockOn;  // offset: 0x60
        cpChargeCtrl* mpChargeCtrl;  // offset: 0x68
        cpShlShotCtrl* mpShlShotCtrl;  // offset: 0x70
        cpRegionStatusCtrl* mpRegionStatusCtrl;  // offset: 0x78
        cpLayout* mpLayout;  // offset: 0x80
        cpSlave* mpSlave;  // offset: 0x88
        cpLockOnTargetManager* mpLockOnTargetMgr;  // offset: 0x90
        cpKeepAtkAdjust* mpKeepAtkAdjust;  // offset: 0x98
        cpPathFinding* mpPathFinding;  // offset: 0xa0
        cpStatusChange* mpStatusChange;  // offset: 0xa8
        cpPawnThink* mpPawnThink;  // offset: 0xb0
        cpAISensor* mpAISensor;  // offset: 0xb8
        cpInvincibleCtrl* mpInvincibleCtrl;  // offset: 0xc0
        cpOcdCtrl* mpOcdCtrl;  // offset: 0xc8
    };
public:
    class cOutLineController
    {
    public:
        cOutLineController();
        void setup(uDDOModel* pParent, u32 outlineNo, f32 Timer);
        void update();
        bool isExecute();
        u32 getOutLineNo();
    private:
        uDDOModel* mpParent;  // offset: 0x0
        u32 mOutLineNo;  // offset: 0x8
        f32 mTimer;  // offset: 0xc
    };
public:
    struct stTouchReleaseInfo
    {
    public:
        uDDOModel* mpRelease;  // offset: 0x0
        nDDOModel::TOUCH_RELEASE_TYPE mTouchReleaseType;  // offset: 0x8
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
    uDDOModel();
    virtual ~uDDOModel();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void sync();  // vtable slot 11
    virtual void moveAfter();  // vtable slot 10
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    virtual void kill();  // vtable slot 16
    virtual void setModel(rModel* pmod);  // vtable slot 29
    virtual void createComponent();  // vtable slot 43
    virtual void setupComponentPtr();  // vtable slot 44
    virtual void registDelegate();  // vtable slot 45
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    // Address: 0x01a5adc0 - 0x01a5adc1 (1 bytes)
    virtual void setupBeforeContext(bool initSet) {}  // vtable slot 46
    virtual void setupContextParam();  // vtable slot 47
    // Address: 0x01a5add0 - 0x01a5add1 (1 bytes)
    virtual void setupActPreInit() {}  // vtable slot 48
    virtual void setupContextPos(bool recvFlag);  // vtable slot 49
    // Address: 0x01a5ade0 - 0x01a5ade1 (1 bytes)
    virtual void setupContextAction(bool recvFlag) {}  // vtable slot 50
    // Address: 0x01a5adf0 - 0x01a5adf1 (1 bytes)
    virtual void setupContextCondition(bool recvFlag) {}  // vtable slot 51
    // Address: 0x01a5ae00 - 0x01a5ae01 (1 bytes)
    virtual void setupContextEnemyClimb(bool recvFlag) {}  // vtable slot 52
    virtual void setupContextTarget(bool recvFlag);  // vtable slot 53
    virtual void setupContextStateLive(bool recvFlag);  // vtable slot 54
    virtual void setupContextCatchCtrl(bool recvFlag);  // vtable slot 55
    // Address: 0x01a5ae10 - 0x01a5ae11 (1 bytes)
    virtual void setupContextEnemyStatusChange(bool recvFlag) {}  // vtable slot 56
    // Address: 0x01a5ae20 - 0x01a5ae21 (1 bytes)
    virtual void setupContextCorePoint(bool recvFlag) {}  // vtable slot 57
    void onDDOModelFlag(u32 flag);
    void offDDOModelFlag(u32 flag);
    bool isDDOModelFlag(u32 flag);
    void setDDOModelFlag(u32 flag);
    u32 getDDOModelFlag();
    void changeDrawModelFlag(u32 flag, bool isOn);
    virtual void updatePtr();  // vtable slot 17
    virtual void updateEfcHandle();  // vtable slot 58
    virtual void resetPos(const MtVector3& pos);  // vtable slot 59
    // Address: 0x01a5ae30 - 0x01a5ae31 (1 bytes)
    virtual void checkWorkRate() {}  // vtable slot 60
    // Address: 0x01a5ae40 - 0x01a5ae41 (1 bytes)
    virtual void checkMotionRate() {}  // vtable slot 61
    // Address: 0x01a5ae50 - 0x01a5ae51 (1 bytes)
    virtual void updateHitStop() {}  // vtable slot 62
    // Address: 0x01a5ae60 - 0x01a5ae61 (1 bytes)
    virtual void hitInstantDeath(bool isFall, bool isWall) {}  // vtable slot 63
    // Address: 0x01a5ae70 - 0x01a5ae71 (1 bytes)
    virtual void setHugebleDeath() {}  // vtable slot 64
    bool isDDOModel() const;
    bool isEnemy() const;
    bool isCharacter() const;
    bool isPlayer() const;
    bool isHuman() const;
    bool isShlBase() const;
    bool isPawn() const;
    bool isNpc() const;
    bool isOmModel() const;
    bool isAimCheck() const;
    bool isHumanEnemy() const;
    bool isEnemyLarge() const;
    bool isCoreSearch() const;
    uDDOModel* castDDOModel();
    uEnemy* castEnemy();
    uPlayer* castPlayer();
    uCharacter* castCharacter();
    uHuman* castHuman();
    uShlBase* castShlBase();
    uPawn* castPawn();
    uNpc* castNpc();
    uOmModel* castOmModel();
    uAimCheck* castAimCheck();
    uHumanEnemy* castHumanEnemy();
    uShlBase* asShlBase();
    void setMotionBlendRate(u32 type, f32 blendRate);
    void setMotionSpeed(u32 type, f32 speed);
    void setMotionFrame(u32 type, f32 frame);
    f32 getMotionFrame(u32 type) const;
    u32 getMotionNo(u32 type) const;
    bool isExistMotionNo(u32 motNo);
    nMotion::MOTION_INFO* getMotionInfo(u32 motNo) const;
    virtual bool setMotionEx(u32 src, u32 mot_no, f32 hokan, f32 frame, f32 speed, u32 attr);  // vtable slot 39
    void setDDOMotion(u32 motNo, bool forcible, u32 attr, f32 hokan, f32 frame, f32 speed);
    void setDDOMotion(MOT_TYPE type, u32 motNo, bool forcible, u32 attr, f32 hokan, f32 frame, f32 speed);
    void setDDOMotionBaseHistory(u32 motNo, bool forcible, u32 attr, f32 hokan, f32 frame, f32 speed);
    virtual f32 getMotionInterFrame(u32 mot_no);  // vtable slot 65
    void swapMotionList(u32, u32);
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    bool invalidGroupKill();
    cContextCharacter* getContext();
    cContextInstance* getContextInst();
    void setCtrl(uControl* pCtrl);
    uControl* getCtrl() const;
    uControlNpc* getCtrlNpc();
    cContextInterface& getContextInterface();
    void releaseContextInst();
    virtual void setMaster(bool is_master);  // vtable slot 66
    void throwMaster(s32 index);
    bool isMaster() const;
    uDDOModel* getTarget();
    void setTarget(uDDOModel* pTarget);
    const MtVector3& getTargetPos();
    void setTargetPos(const MtVector3& pos);
    virtual const MtVector3 getDefaultTargetPos();  // vtable slot 67
    cpComponent* getRootComponent() const;
    rShlParamList* getShlParamList() const;
    void setShlParamList(rShlParamList* pr);
    rShlParamList* getCommonShlParamList() const;
    void setCommonShlParamList(rShlParamList* pr);
private:
    void registShlParamList(const rShlParamList* pShlRes);
    void releaseShlParamList(const rShlParamList* pShlRes);
public:
    // Address: 0x01a5aed0 - 0x01a5aed1 (1 bytes)
    virtual void notifyDeleteShell(s32 work) {}  // vtable slot 68
protected:
    // Address: 0x01a5aee0 - 0x01a5aee1 (1 bytes)
    virtual void updateObjStatus() {}  // vtable slot 69
    virtual void checkReplaceInfo(cHitInfoAfter& HitInfo);  // vtable slot 70
public:
    bool isCtrlPlayer();
    bool isCtrlPawn();
    bool isCtrlNpc();
    bool isCtrlEnemy();
    void setMayaScale(bool enable);
    bool isMayaScale();
    void setForceScale(bool enable);
    bool isForceScale();
    static void enableScale(uModel* pModel, bool MayaScale, bool ForceScale);
    virtual void updateMatrix();  // vtable slot 71
    // Address: 0x01a5aef0 - 0x01a5aef1 (1 bytes)
    virtual void checkKeyCmdFunc() {}  // vtable slot 72
    // Address: 0x01a5af00 - 0x01a5af01 (1 bytes)
    virtual void callbackUpdateAfter() {}  // vtable slot 73
    // Address: 0x01a5af10 - 0x01a5af11 (1 bytes)
    virtual void callbackReplaceHitInfo_Atk(cHitInfo* pHitInfo) {}  // vtable slot 74
    // Address: 0x01a5af20 - 0x01a5af21 (1 bytes)
    virtual void callbackReplaceHitInfo_Def(cHitInfo* pHitInfo) {}  // vtable slot 75
    virtual void callbackCreateNode(cHitNode* pHitNode);  // vtable slot 76
    virtual void callbackKillNode(cHitNode* pHitNode);  // vtable slot 77
    virtual void callbackGuard(cHitInfo* pHitInfo);  // vtable slot 78
    virtual void callbackGuarded(cHitInfo* pHitInfo);  // vtable slot 79
    virtual void callbackGuardTest(cHitInfo* pHitInfo);  // vtable slot 80
    virtual void callbackGuardedTest(cHitInfo* pHitInfo);  // vtable slot 81
    // Address: 0x01a5af30 - 0x01a5af31 (1 bytes)
    virtual void callbackGuardedBefore(cHitInfo* pHitInfo) {}  // vtable slot 82
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 83
    virtual MtVector3 callbackReplaceHitNormal(const MtVector3& HitNormal);  // vtable slot 84
    virtual void callbackAttackTest(cHitInfo* pHitInfo);  // vtable slot 85
    virtual void callbackDamageTest(cHitInfo* pHitInfo);  // vtable slot 86
    virtual void callbackDamage_Register(const cHitInfo* pHitLocalInfo, cDamageMsg* pDmMsg);  // vtable slot 87
    virtual void callbackDamage(cHitInfo* pHitLocalInfo);  // vtable slot 88
    virtual void callbackDamageAfter(cHitInfoAfter* pHitInfo);  // vtable slot 89
    virtual void callbackHealAfter(cHitInfoAfter* pHitInfo);  // vtable slot 90
    virtual void callbackDamageAfter_make(cHitInfoAfter* pHitInfo);  // vtable slot 91
    // Address: 0x01a5af70 - 0x01a5af71 (1 bytes)
    virtual void callbackDamageAfter_makeEnd(cHitInfoAfter* pHitInfo) {}  // vtable slot 92
    virtual void callbackDamageAfter_calc(cHitInfoAfter* pHitInfo);  // vtable slot 93
    // Address: 0x01a5af80 - 0x01a5af81 (1 bytes)
    virtual void callbackDamageAfter_calcEnd(cHitInfoAfter* pHitInfo) {}  // vtable slot 94
    virtual void callbackDamageAfter_apply(cHitInfoAfter* pHitInfo);  // vtable slot 95
    virtual void callbackHealedAfter_make(cHitInfoAfter* pHitInfo);  // vtable slot 96
    virtual void callbackHealedAfter_calc(cHitInfoAfter* pHitInfo);  // vtable slot 97
    virtual bool callbackHealedAfter_apply(cHitInfoAfter* pHitInfo);  // vtable slot 98
    virtual bool callbackHealedAfter_apply_slave(cHitInfoAfter* pHitInfo);  // vtable slot 99
    virtual void callbackGuard_make(cHitInfo* pHitInfo);  // vtable slot 100
    virtual void callbackGuard_calc(cHitInfo* pHitInfo);  // vtable slot 101
    virtual void callbackGuard_apply(cHitInfo* pHitInfo);  // vtable slot 102
    // Address: 0x01a5afb0 - 0x01a5afb1 (1 bytes)
    virtual void callbackRegionBreak(cHitInfoAfter* pHitInfo) {}  // vtable slot 103
    // Address: 0x01a5afc0 - 0x01a5afc1 (1 bytes)
    virtual void callbackRegionBreakSlave(u32 regioNo) {}  // vtable slot 104
    // Address: 0x01a5afd0 - 0x01a5afd1 (1 bytes)
    virtual void callbackFlick(cHitInfoAfter* pHitInfo) {}  // vtable slot 105
    virtual void callbackShrink(cHitInfoAfter* pHitInfo);  // vtable slot 106
    virtual void callbackBlow(cHitInfoAfter* pHitInfo);  // vtable slot 107
    virtual bool callbackDown(cHitInfoAfter* pHitInfo);  // vtable slot 108
    virtual bool callbackShake(cHitInfoAfter* pHitInfo);  // vtable slot 109
    // Address: 0x01a5afe0 - 0x01a5afe1 (1 bytes)
    virtual void callbackStorm(cHitInfoAfter* pHitInfo) {}  // vtable slot 110
    // Address: 0x01a5aff0 - 0x01a5aff1 (1 bytes)
    virtual void callbackQuake(cHitInfoAfter* pHitInfo) {}  // vtable slot 111
    virtual bool isEnableStorm(cHitInfoAfter* pHitInfo);  // vtable slot 112
    virtual bool isEnableQuake(cHitInfoAfter* pHitInfo);  // vtable slot 113
    virtual void callbackHitStopSlow(cHitInfoAfter* pHitInfo);  // vtable slot 114
    virtual void callbackHitStopSlowRecv(cHitInfoAfter* pHitInfo);  // vtable slot 115
    // Address: 0x01a5b020 - 0x01a5b021 (1 bytes)
    virtual void callbackAttackBefore(cHitInfoAfter* pHitInfo) {}  // vtable slot 116
    virtual void callbackAttackEnd(cHitInfoAfter* pHitInfo);  // vtable slot 117
    virtual void callbackCatch(cHitInfo* pHitInfo);  // vtable slot 118
    // Address: 0x01a5b030 - 0x01a5b031 (1 bytes)
    virtual void callbackCatch_Shl(cShlNotifyInfo* pInfo) {}  // vtable slot 119
    virtual void callbackCaught(cHitInfo* pHitInfo);  // vtable slot 120
    virtual void callbackCatchTest(cHitInfo* pHitInfo);  // vtable slot 121
    virtual void callbackCaughtTest(cHitInfo* pHitInfo);  // vtable slot 122
    virtual void callbackCheck(cHitInfo* pHitInfo);  // vtable slot 123
    virtual void callbackChecked(cHitInfo* pHitInfo);  // vtable slot 124
    virtual void callbackCheckTest(cHitInfo* pHitInfo);  // vtable slot 125
    virtual void callbackCheckedTest(cHitInfo* pHitInfo);  // vtable slot 126
    virtual void callbackHeal(cHitInfo* pHitInfo);  // vtable slot 127
    virtual void callbackHealed(cHitInfo* pHitInfo);  // vtable slot 128
    virtual void callbackHealedAfter(cHitInfoAfter* pHitInfo);  // vtable slot 129
    virtual void callbackHealTest(cHitInfo* pHitInfo);  // vtable slot 130
    virtual void callbackHealedTest(cHitInfo* pHitInfo);  // vtable slot 131
    virtual void callbackPush(uDDOModel* pModel, const MtVector3& push);  // vtable slot 132
    // Address: 0x01a5b040 - 0x01a5b041 (1 bytes)
    virtual void callbackDie(cUnitDieInfo& dieInfo) {}  // vtable slot 133
    // Address: 0x01a5b050 - 0x01a5b051 (1 bytes)
    virtual void callbackInjured(bool setupFlag) {}  // vtable slot 134
    // Address: 0x01a5b060 - 0x01a5b061 (1 bytes)
    virtual void callbackLost(bool setupFlag) {}  // vtable slot 135
    // Address: 0x01a5b070 - 0x01a5b071 (1 bytes)
    virtual void callbackLostEnd(bool setupFlag) {}  // vtable slot 136
    // Address: 0x01a5b080 - 0x01a5b081 (1 bytes)
    virtual void callbackRescue(u32 unitParam, u32 touchType) {}  // vtable slot 137
    // Address: 0x01a5b090 - 0x01a5b091 (1 bytes)
    virtual void callbackOcdRescue(u32 ocdType) {}  // vtable slot 138
    // Address: 0x01a5b0a0 - 0x01a5b0a1 (1 bytes)
    virtual void callbackRespawn(bool setupFlag) {}  // vtable slot 139
    // Address: 0x01a5b0b0 - 0x01a5b0b1 (1 bytes)
    virtual void callbackReturnTerritory(bool setupFlag) {}  // vtable slot 140
    virtual void callbackChangePartsBit(BitData bitData);  // vtable slot 141
    virtual void callbackGuard_Local(cHitInfo* pHitInfo);  // vtable slot 142
    virtual u32 replaceCollisionAttr(u32 attr, const cCollNode* pCollNode);  // vtable slot 143
    virtual bool callbackRegistInterPolateGeom(MtVector3& oldPos, const MtVector3& currentPos, f32 radius, const cHitGeom* pGeom);  // vtable slot 144
    // Address: 0x01a5b0e0 - 0x01a5b0e1 (1 bytes)
    virtual void callbackReqOcdAction(cOcdInfo& OcdInfo, bool initFlag) {}  // vtable slot 145
    virtual void callbackReqOcdEndAction(u32 actNo, nAction::ACT_PRIO priority);  // vtable slot 146
    cpWorkRate* getWorkRatePtr() const;
    void setWorkRatePtr(cpWorkRate* NewValue);
    cpObjCollisionBase* getObjCollisionPtr() const;
    void setObjCollisionPtr(cpObjCollisionBase* NewValue);
    cpScrCollision* getScrCollisionPtr() const;
    void setScrCollisionPtr(cpScrCollision* NewValue);
    cpActionManager* getActMgrPtr() const;
    void setActMgrPtr(cpActionManager* NewValue);
    cpInput* getInputPtr() const;
    void setInputPtr(cpInput* NewValue);
    cpActionSelect* getActionSelectPtr() const;
    void setActionSelectPtr(cpActionSelect* NewValue);
    cpActionRequest* getActionRequestPtr() const;
    void setActionRequestPtr(cpActionRequest* NewValue);
    cpSequenceCtrl* getSequenceCtrlPtr() const;
    void setSequenceCtrlPtr(cpSequenceCtrl* NewValue);
    cpHpDamageCtrl* getHpDamageCtrlPtr() const;
    void setHpDamageCtrlPtr(cpHpDamageCtrl* NewValue);
    cpCatchCtrl* getCatchCtrlPtr() const;
    void setCatchCtrlPtr(cpCatchCtrl* NewValue);
    cpStateManager* getStateActionPtr() const;
    void setStateActionPtr(cpStateManager* NewValue);
    cpStateManager* getStateLivePtr() const;
    void setStateLivePtr(cpStateManager* NewValue);
    cpLockOn* getLockOnPtr() const;
    void setLockOnPtr(cpLockOn* NewValue);
    cpChargeCtrl* getChargeCtrlPtr() const;
    void setChargeCtrlPtr(cpChargeCtrl* NewValue);
    cpShlShotCtrl* getShlShotCtrlPtr() const;
    void setShlShotCtrlPtr(cpShlShotCtrl* NewValue);
    cpRegionStatusCtrl* getRegionStatusCtrlPtr() const;
    void setRegionStatusCtrlPtr(cpRegionStatusCtrl* NewValue);
    cpLayout* getLayoutPtr() const;
    void setLayoutPtr(cpLayout* NewValue);
    cpSlave* getSlavePtr() const;
    void setSlavePtr(cpSlave* NewValue);
    cpLockOnTargetManager* getLockOnTargetMgrPtr() const;
    void setLockOnTargetMgrPtr(cpLockOnTargetManager* NewValue);
    cpKeepAtkAdjust* getKeepAtkAdjustPtr() const;
    void setKeepAtkAdjustPtr(cpKeepAtkAdjust* NewValue);
    cpPathFinding* getPathFindingPtr() const;
    void setPathFindingPtr(cpPathFinding* NewValue);
    cpStatusChange* getStatusChangePtr() const;
    void setStatusChangePtr(cpStatusChange* NewValue);
    cpPawnThink* getPawnThinkPtr() const;
    void setPawnThinkPtr(cpPawnThink* NewValue);
    cpAISensor* getAISensorPtr() const;
    void setAISensorPtr(cpAISensor* NewValue);
    cpInvincibleCtrl* getInvincibleCtrlPtr() const;
    void setInvincibleCtrlPtr(cpInvincibleCtrl* NewValue);
    cpOcdCtrl* getOcdCtrlPtr() const;
    void setOcdCtrlPtr(cpOcdCtrl* NewValue);
    bool isMyPlayer() const;
    bool isMyPawn() const;
    bool isMyNpc() const;
    bool isCharacterBase() const;
    bool isDead() const;
    bool isDead(u32 index) const;
    bool isDeadDying();
    HP_DATATYPE getHpRoot() const;
    HP_DATATYPE getHpMaxRoot() const;
    HP_DATATYPE getHp(const u32 index) const;
    HP_DATATYPE getHpMax(const u32 index) const;
    void addHp(const HP_DATATYPE hp, const u32 index);
    void subHp(const HP_DATATYPE hp, const u32 index);
    bool isUsedPRegion(u32 index) const;
    f32 getHpRate(u32 index) const;
    void addDamage(HP_DATATYPE damage, bool isNoDeath, u32 index);
    void requestDie(bool isSelfDead);
    bool isSelfDead();
    void setSelfDead();
    f32 getShP(const u32 index) const;
    f32 getShPMax(const u32 index) const;
    f32 getBlP(const u32 index) const;
    f32 getBlPMax(const u32 index) const;
    u32 getLv();
    bool isObjStatus(const u64 sts) const;
    bool isObjStatusOld(const u64 sts) const;
    bool isObjStatusExt(const u64 sts) const;
    bool isObjStatusExtOld(const u64);
    u64 getObjStatus();
    void addObjStatus(const u64 sts);
    const MtVector3& getVelocity() const;
    const MtVector3& getAcceleration() const;
    void setVelocity(const MtVector3& vel);
    void setAcceleration(const MtVector3& acc);
    void callDamageFuncs(cHitInfo* pHitInfo);
    void callDamageAfterFuncs(cHitInfoAfter* pHitInfo, bool isApply);
    void callHealedAfterFuncs(cHitInfoAfter* pHitInfo, bool isApply);
    // Address: 0x01a5b0f0 - 0x01a5b0f1 (1 bytes)
    virtual void makeHealedAttackInfo(cHitInfoAfter* pHitInfo) {}  // vtable slot 147
    // Address: 0x01a5b100 - 0x01a5b101 (1 bytes)
    virtual void makeHealedDefenceInfo(cHitInfoAfter* pHitInfo) {}  // vtable slot 148
    virtual void makeDamageAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 149
    virtual void makeShlDamageAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 150
    void makeDamageAttackInfoCom(cHitInfoAfter* pHitInfo);
    virtual void makeDamageDefenceInfo(cHitInfoAfter* pHitInfo);  // vtable slot 151
    virtual void makeBlowShrinkAttackInfo(cBlowShrinkDmInfo* pInfo, uDDOModel* pAttacker, uDDOModel* pDefender, u32 atkAdjustUniqueId);  // vtable slot 152
    virtual void makeBlowShrinkAttackInfoShl(cBlowShrinkDmInfo* pInfo, uDDOModel* pAttacker, uDDOModel* pDefender, u32 atkAdjustUniqueId);  // vtable slot 153
    void makeBlowShrinkAttackInfoCom(cBlowShrinkDmInfo* pInfo, uDDOModel* pAttacker, uDDOModel* pDefender, u32 atkAdjustUniqueId);
    // Address: 0x01a5b110 - 0x01a5b111 (1 bytes)
    virtual void makeBlowShrinkDefenceInfo(cHitInfoAfter* pBlowShrinkInfo) {}  // vtable slot 154
    virtual void makeOcdAttackInfoShl(cHitInfoAfter* pHitInfo);  // vtable slot 155
    virtual void makeOcdAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 156
    void makeOcdAttackInfoCom(cHitInfoAfter* pHitInfo);
    void addOcdDamageParam(cHitInfoAfter* pHitInfo, u32 OcdUID, f32 endurance);
    // Address: 0x01a5b120 - 0x01a5b121 (1 bytes)
    virtual void makeOcdDefenceInfo(cHitInfoAfter* pHitInfo) {}  // vtable slot 157
    void callbackShlHitStop(cHitInfoAfter* pHitInfo);
    void addDamageMsg(const cDamageMsg& msg);
    void clearDamageMsg();
    virtual void makeGuardAttackInfo(cHitInfo* pHitInfo);  // vtable slot 158
    virtual void makeGuardDefenceInfo(cHitInfo* pHitInfo);  // vtable slot 159
    void calcGuard(cHitInfo* pHitInfo);
    // Address: 0x01a5b130 - 0x01a5b131 (1 bytes)
    virtual void applyGuardResult(cHitInfo* pHitInfo) {}  // vtable slot 160
    void applyDamageVisual(cHitInfoAfter* pHitInfo, nObjCollision::CALC_DAMADE_MODE* mode);
    virtual void applyHealVisual(cHitInfoAfter* pHitInfo, nObjCollision::CALC_DAMADE_MODE* mode);  // vtable slot 161
    void checkHitStopSlow(cHitInfoAfter* pHitInfo);
    // Address: 0x01a5b140 - 0x01a5b141 (1 bytes)
    virtual void playHitStopSlow(cHitInfoAfter* pHitInfo) {}  // vtable slot 162
    // Address: 0x01a5b150 - 0x01a5b151 (1 bytes)
    virtual void makeHitSeInfo_Attack(cDamageSeInfo* pSeInfo) {}  // vtable slot 163
    void attackParamReplace(cHitInfo* pHitInfo, s32 offset) const;
    virtual bool checkCalcDamageCancel(cHitInfo* pHitInfo);  // vtable slot 164
    MtTypedArray<cDamageMsg>& getDamageMsgArray();
private:
    bool setDmInfoToContext(const cDamageMsg* pDmMsg);
    bool isSendDamageMsg(const cHitInfo* pHitInfo) const;
public:
    void buildComponent();
    s32 getTargetUIJointNo() const;
    const MtVector3& getTargetUIOffset() const;
    void setTargetUIOffset(s32 jointNo, const MtVector3& offset);
protected:
    virtual void releaseTouchTarget(uDDOModel* pRelease, nDDOModel::TOUCH_RELEASE_TYPE type);  // vtable slot 165
public:
    virtual void setTouch(uDDOModel* pReqOwner, bool isTouchSave);  // vtable slot 166
    virtual void requestReleaseTouch(uDDOModel* pRelease, nDDOModel::TOUCH_RELEASE_TYPE type);  // vtable slot 167
    nDDOModel::TOUCH_TYPE getTouchType() const;
    void setTouchType(nDDOModel::TOUCH_TYPE type);
    void setTouchTarget(uDDOModel* pTag);
    uDDOModel* getTouchTarget() const;
    uDDOModel* getTouchedTarget(u32 index) const;
    u32 getTouchedTargetNum() const;
    void clearTouchType(nDDOModel::TOUCH_TYPE type);
    bool isNoTouch() const;
    void setNoTouch(bool f);
    u32 getScrFilter();
    cGroundAttrInfo* getGroundInfoEff();
    cGroundAttrInfo* getGroundInfoScr();
    cGroundAttrInfo* getGroundInfoWaterDepth();
    bool isHitLand() const;
    bool isAttackHit(u32 filter);
    bool isAttackTestHit(u32 filter);
    bool isDamageTestHit(u32 filter);
    void setPivotActive(bool active);
    void setPivotJointNo(u32 JntNo);
    void setPivotOffset(const MtVector3& offset);
    void setPivotPos(const MtVector3& pos);
    MtVector3 getPivotPos();
    void setRotateCtrlActive(bool active);
    bool isRotateCtrlBusy();
    void setFinalQuat(const MtQuaternion& FinalQuat, f32 speed);
    void setFinalQuatByFrame(const MtQuaternion& FinalQuat, f32 frame);
    void setFinalAngleY(f32 AngleY, f32 speed);
    void setFinalAngleYByFrame(f32 AngleY, f32 frame);
    void setFinalDir(const MtVector3& dir, f32 speed);
    void setFinalDirByFrame(const MtVector3& dir, f32 frame);
    void setFinalAimPos(const MtVector3& from, const MtVector3& to, f32 speed);
    void setFinalAimPosByFrame(const MtVector3& from, const MtVector3& to, f32 frame);
    void setDefaultRotateSpeed(f32 InterSpeed);
    f32 getDefaultRotateSpeed();
    void setDefaultRotateFrame(f32 InterFrame);
    f32 getDefaultRotateFrame();
    const MtQuaternion& getFinalQuat();
    f32 getFinalAngleY();
    void setLayoutId(const nLayout::stLayoutID& layoutID);
    const nLayout::stLayoutID getLayoutId() const;
    void setSetNo(s32 no);
    s32 getSetNo() const;
    void setSplitId(const nLayout::stSplitID& splitID);
    const nLayout::stSplitID getSplitId() const;
    void setGroupParam(const cGroupParam* param);
    const cGroupParam* getGroupParam() const;
    void setQuestId(u32 QuestId);
    u32 getQuestId();
    bool isShlDeleteBit(const u32 sts) const;
    void addShlDeleteBit(u32 deletebit);
    u32 getShlDeleteBit();
    void setShlDeleteBit(u32);
    bool isSetupPassed();
    virtual void callbackCreateShl(uShlBase* pShl);  // vtable slot 168
    virtual bool chkJointForEditDelete(u32 jntNo);  // vtable slot 169
    void requestOutline(u32 outlineType);
    void requestCommandCacheReset();
    void setInterpolateType(u32 interpolateType);
    void moveInterpolate();
    void updateInterpolatePos(const MtVector3& pos, bool forceSet);
    void updateInterpolateAngle(f32 angle);
    const MtVector3& getSafePos();
    bool isNowSafePos();
    void countUpSafePosWarpLoop();
    void initHugeble();
    void endHugeble();
    void setInstantDeath();
    bool isHugebleSafePos();
    void resetAtkAdjust();
    void setAtkAdjust(f32 atkRate, f32 blowRate, f32 shrinkRate);
    void setMgcAdjust(f32 atkRate);
    f32 getAtkRate(u16 uniqueId);
    f32 getMgcRate(u16 uniqueId);
    f32 getBlowRate(u16 uniqueId);
    f32 getShrinkRate(u16 uniqueId);
    u16 getAtkAdjustUniqueId();
    u16 getNowAtkAdjustUniqueId();
    void setNowAtkAdjustUniqueId(u16 uniqueId);
    bool isOwnerBeaDown() const;
    nCatch::CATCH_TYPE getCatchType();
    void clearHitEffectFlag(cHitInfoAfter& HitInfo);
    void clearHitSEFlag(cHitInfoAfter& HitInfo);
    void clearHitStop(cHitInfoAfter& HitInfo);
    void clearPhysAttack(cHitInfoAfter& HitInfo);
    void clearMgcAttack(cHitInfoAfter& HitInfo);
    void clearShrinkDamage(cHitInfoAfter& HitInfo);
    void clearBlowDamage(cHitInfoAfter& HitInfo);
    void clearDownDamage(cHitInfoAfter& HitInfo);
    void setAnyFlag(cHitInfoAfter& HitInfo, u64 flag);
    void setInvType(nObjCollision::UNIT_INV_TYPE type);
    void addInvType(nObjCollision::UNIT_INV_TYPE type);
    void removeInvType(nObjCollision::UNIT_INV_TYPE type);
    bool isInvTypeActive(nObjCollision::UNIT_INV_TYPE type) const;
    bool isDamageAttrActive(u32 attr) const;
    bool isDamageAttrOff(u32 attr) const;
    bool isDamageAttrOldActive(u32 attr) const;
    bool isDamageAttrOldOff(u32 attr) const;
    bool isDamageAttrActive_Through(nObjCollision::DAMAGE_ATTR_ENUM attrEnum, nObjCollision::UNIT_INV_THROUGH_TYPE type) const;
    bool isDamageAttrOldActive_Through(nObjCollision::DAMAGE_ATTR_ENUM attrEnum, nObjCollision::UNIT_INV_THROUGH_TYPE type) const;
    s32 getActionStateNo() const;
    cState* getActionState() const;
    cpOcdCtrl* getOcdCtrl() const;
    void catchAbnormalCondition(u32 condition, f32 activeTime, nObjCondition::OCD_REASON reason, f32 cacheTime, bool isItem, nObjCondition::IMMUNE_BOOST_LV boostLv);
    void catchAbnormalCondition(u32 condition, nObjCondition::OCD_REASON reason, f32 cacheTime, bool isForce);
    void recoverAbnormalCondition(u32 condition);
    bool isAbnormalConditionActive(u32 condition) const;
    virtual bool healHp(HP_DATATYPE healHp, bool isWhiteHeal, u32 regionNo);  // vtable slot 170
    void registAbsorpReqMsg(const nObjCondition::stHolyAbsorpReqMsg& srcMsg);
    void receiveAbsorpReqNetMsg(const nObjCondition::stHolyAbsorpReqMsg& srcMsg);
    void registSoulAbsorpReqMsg(const nObjCondition::stHolyAbsorpReqMsg& srcMsg);
    void receiveSoulAbsorpReqNetMsg(const nObjCondition::stHolyAbsorpReqMsg& srcMsg);
    void registShlRequest(const nHuman::stShellRequestMsg& msg);
    virtual u32 getHitLightToModel();  // vtable slot 36
    // Address: 0x01a5b190 - 0x01a5b191 (1 bytes)
    virtual void setLODData() {}  // vtable slot 171
    void setGpCategory(s32 category);
    u32 getGpCategory() const;
    void getGpIterator(cGeneralPointIterator* pDst) const;
    void getGeneralPointAll(MtTypedArray<cGeneralPoint>& dst);
    cGeneralPoint* getGeneralPointFast();
    void releaseAsyncArc();
    void setArcPtr(rArchive* ptr, ARC_TAGID tag);
    bool isValidProfiler() const;
    void updateProfilerBuffer();
private:
    void beginProfile(PROFILE_TYPE ProfileType, u32 ProfilePhase);
    void endProfile();
    void endProfile(PROFILE_TYPE ProfileType, u32 ProfilePhase);
    virtual bool checkCalc(const cAttackParam* pAtkParam);  // vtable slot 172
public:
    void setLightNpc(bool flag);
    bool isLightNpc() const;
    bool isInitSet() const;
public:
    bool mIsResetDDMrlCtrl;  // offset: 0x1f60
    u32 mDDOModelFlag;  // offset: 0x1f64
    union
    {
    public:
        u32 mUnitId;  // offset: 0x0
        struct
        {
        public:
            bool mIsDDOModel : 1;  // offset: 0x0
            bool mIsEnemy : 1;  // offset: 0x0
            bool mIsCharacter : 1;  // offset: 0x0
            bool mIsPlayer : 1;  // offset: 0x0
            bool mIsHuman : 1;  // offset: 0x0
            bool mIsShlBase : 1;  // offset: 0x0
            bool mIsPawn : 1;  // offset: 0x0
            bool mIsNpc : 1;  // offset: 0x0
            bool mIsOmModel : 1;  // offset: 0x1
            bool mIsAimCheck : 1;  // offset: 0x1
            bool mIsHumanEnemy : 1;  // offset: 0x1
            bool mIsEnemyLarge : 1;  // offset: 0x1
            bool mIsCoreSearch : 1;  // offset: 0x1
        };  // offset: 0x0
    };  // offset: 0x1f68
    cDelegate_6<void, unsigned int, unsigned int, float, float, float, unsigned int> callbackPreSetMotion;  // offset: 0x1f70
    cDelegate_6<void, unsigned int, unsigned int, float, float, float, unsigned int> callbackSetMotion;  // offset: 0x1f88
private:
    cContextInterface mContextInterface;  // offset: 0x1fa0
    bool mIsMaster;  // offset: 0x1fb8
    uControl* mpCtrl;  // offset: 0x1fc0
    uDDOModel* mpTarget;  // offset: 0x1fc8
    MtVector3 mTargetPos;  // offset: 0x1fd0
public:
    cComponentManager mComponentMgr;  // offset: 0x1fe0
protected:
    rShlParamList* mprShlParamList;  // offset: 0x1ff8
    rShlParamList* mprCommonShlParamList;  // offset: 0x2000
public:
    cDelegate_0<void> callbackMoveBegin;  // offset: 0x2008
    cDelegate_0<void> updateInput;  // offset: 0x2020
    cDelegate_0<void> before;  // offset: 0x2038
    cDelegate_0<void> checkAction;  // offset: 0x2050
    cDelegate_0<void> update;  // offset: 0x2068
    cDelegate_0<void> updateMotion;  // offset: 0x2080
    cDelegate_0<void> callbackAfterUpdateMotion;  // offset: 0x2098
    cDelegate_0<void> updatePosition;  // offset: 0x20b0
    cDelegate_2<unsigned int, MtVector3&, MtVector3&> scrAdjust;  // offset: 0x20c8
    cDelegate_0<void> callbackAfterUpdateMatrix;  // offset: 0x20e0
    cDelegate_0<void> after;  // offset: 0x20f8
    cDelegate_0<void> callbackMoveEnd;  // offset: 0x2110
    cpPivotCtrl* mpPivotCtrl;  // offset: 0x2128
    cpMotionHistory* mpMotionHistory;  // offset: 0x2130
    cpEquip* mpEquip;  // offset: 0x2138
    cpRotateCtrl* mpRotateCtrl;  // offset: 0x2140
    cpDDMrlMgr* mpDDMrlMgr;  // offset: 0x2148
    cpPartsCtrl* mpPartsCtrl;  // offset: 0x2150
    cpEffectProvider* mpEffectProvider;  // offset: 0x2158
    cpSafePos* mpSafePos;  // offset: 0x2160
    cpHugeble* mpHugeble;  // offset: 0x2168
    cpCheckWallCliff* mpCheckWallCliff;  // offset: 0x2170
    cpMotionSe* mpMotionSe;  // offset: 0x2178
    cpEffectStatusManager* mpEffectStatusManager;  // offset: 0x2180
    cpSoftBody* mpSoftBody;  // offset: 0x2188
    cpModelConst* mpModelConst;  // offset: 0x2190
    cpTalk* mpTalk;  // offset: 0x2198
    cpNpc* mpNpc;  // offset: 0x21a0
    cpWallExitCtrl* mpWallExitCtrl;  // offset: 0x21a8
private:
    GuardComponent mGuardComponent;  // offset: 0x21b0
protected:
    bool mMayaScale;  // offset: 0x2280
    bool mForceScale;  // offset: 0x2281
public:
    bool mIsSelfDead;  // offset: 0x2282
    MtVector3 mInitPos;  // offset: 0x2290
    MtVector3 mOldPos;  // offset: 0x22a0
    MtVector3 mVelocity;  // offset: 0x22b0
    MtVector3 mAcceleration;  // offset: 0x22c0
    MtVector3 mMoveVelocity;  // offset: 0x22d0
    MtVector3 mMoveVelStartPos;  // offset: 0x22e0
    u64 mObjStatus;  // offset: 0x22f0
    u64 mObjStatusOld;  // offset: 0x22f8
    u64 mObjStatusExt;  // offset: 0x2300
    u64 mObjStatusExtOld;  // offset: 0x2308
private:
    MtTypedArray<cDamageMsg> mDamageMsgArray;  // offset: 0x2310
protected:
    cOutLineController mOutLineCtrl;  // offset: 0x2330
private:
    u32 mShlDeleteBit;  // offset: 0x2340
    bool mIsCreatedFromNewDDOModel;  // offset: 0x2344
    bool mIsSetupPassed;  // offset: 0x2345
    s32 mTargetUIJointNo;  // offset: 0x2348
    MtVector3 mTargetUIOffset;  // offset: 0x2350
protected:
    nDDOModel::TOUCH_TYPE mTouchType;  // offset: 0x2360
    bool mIsNoTouch;  // offset: 0x2364
    uDDOModel* mpTouchTarget;  // offset: 0x2368
    MtTypedStorageArray<uDDOModel, 8> mTouchedArray;  // offset: 0x2370
    nDDOUtility::cArray<stTouchReleaseInfo, 8> mTouchRelReqArray;  // offset: 0x23c0
private:
    u32 mGpCategoy;  // offset: 0x2440
protected:
    MtTypedArray<cAsyncArc> mAsyncArc;  // offset: 0x2448
private:
    bool mIsLightNpc;  // offset: 0x2468
    bool mIsInitSet;  // offset: 0x2469
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline bool uDDOModel::isHuman() const {
    return (this->mUnitId & static_cast<u32>(16)) != static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline bool uDDOModel::isNpc() const {
    return (this->mUnitId & static_cast<u32>(128)) != static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline uControl* uDDOModel::getCtrl() const {
    return this->mpCtrl;
}

// Inline, no code of its own: checked where it is inlined.
inline cpObjCollisionBase* uDDOModel::getObjCollisionPtr() const {
    return this->mGuardComponent.mpObjCollision;
}

// Inline, no code of its own: checked where it is inlined.
inline cpScrCollision* uDDOModel::getScrCollisionPtr() const {
    return this->mGuardComponent.mpScrCollision;
}

// Inline, no code of its own: checked where it is inlined.
inline cpActionManager* uDDOModel::getActMgrPtr() const {
    return this->mGuardComponent.mpActMgr;
}

// Inline, no code of its own: checked where it is inlined.
inline cpInput* uDDOModel::getInputPtr() const {
    return this->mGuardComponent.mpInput;
}

// Inline, no code of its own: checked where it is inlined.
inline cpActionRequest* uDDOModel::getActionRequestPtr() const {
    return this->mGuardComponent.mpActionRequest;
}

// Inline, no code of its own: checked where it is inlined.
inline cpSequenceCtrl* uDDOModel::getSequenceCtrlPtr() const {
    return this->mGuardComponent.mpSequenceCtrl;
}

// Inline, no code of its own: checked where it is inlined.
inline cpHpDamageCtrl* uDDOModel::getHpDamageCtrlPtr() const {
    return this->mGuardComponent.mpHpDamageCtrl;
}

// Inline, no code of its own: checked where it is inlined.
inline cpCatchCtrl* uDDOModel::getCatchCtrlPtr() const {
    return this->mGuardComponent.mpCatchCtrl;
}

// Inline, no code of its own: checked where it is inlined.
inline cpStateManager* uDDOModel::getStateActionPtr() const {
    return this->mGuardComponent.mpStateAction;
}

// Inline, no code of its own: checked where it is inlined.
inline cpStateManager* uDDOModel::getStateLivePtr() const {
    return this->mGuardComponent.mpStateLive;
}

// Inline, no code of its own: checked where it is inlined.
inline cpLockOn* uDDOModel::getLockOnPtr() const {
    return this->mGuardComponent.mpLockOn;
}

// Inline, no code of its own: checked where it is inlined.
inline cpChargeCtrl* uDDOModel::getChargeCtrlPtr() const {
    return this->mGuardComponent.mpChargeCtrl;
}

// Inline, no code of its own: checked where it is inlined.
inline cpShlShotCtrl* uDDOModel::getShlShotCtrlPtr() const {
    return this->mGuardComponent.mpShlShotCtrl;
}

// Inline, no code of its own: checked where it is inlined.
inline cpLayout* uDDOModel::getLayoutPtr() const {
    return this->mGuardComponent.mpLayout;
}

// Inline, no code of its own: checked where it is inlined.
inline cpSlave* uDDOModel::getSlavePtr() const {
    return this->mGuardComponent.mpSlave;
}

// Inline, no code of its own: checked where it is inlined.
inline cpKeepAtkAdjust* uDDOModel::getKeepAtkAdjustPtr() const {
    return this->mGuardComponent.mpKeepAtkAdjust;
}

// Inline, no code of its own: checked where it is inlined.
inline cpStatusChange* uDDOModel::getStatusChangePtr() const {
    return this->mGuardComponent.mpStatusChange;
}

// Inline, no code of its own: checked where it is inlined.
inline cpInvincibleCtrl* uDDOModel::getInvincibleCtrlPtr() const {
    return this->mGuardComponent.mpInvincibleCtrl;
}

// Inline, no code of its own: checked where it is inlined.
inline cpOcdCtrl* uDDOModel::getOcdCtrlPtr() const {
    return this->mGuardComponent.mpOcdCtrl;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline u64 uDDOModel::getObjStatus() {
    return this->mObjStatus;
}
