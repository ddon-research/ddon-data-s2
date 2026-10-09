#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "cAISvPathFinding.h"
#include "cGeneralPointPtr.h"
#include "nDDOModel.h"
#include "nDDOUtility.h"
#include "nErosionEnemyBase.h"
#include "nObjCollision.h"
#include "uDDOModel.h"
#include "uModel.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtQuaternion;
class MtVector3;
class cAttackParam;
class cBlowShrinkDmInfo;
class cCollNode;
namespace cEvaluationName { class cEvaluation; }
class cGeneralPoint;
class cGeneralPointPtr;
class cHitInfo;
class cHitInfoAfter;
class cHitNode;
class cNamedParam;
class cOcdInfo;
class cpAIPawnEmChecker;
class cpActionManager;
class cpAltitudeFallCtrl;
class cpEfcFootSmoke;
class cpEfcSequenceGeneral;
class cpEfcTouchDownSmoke;
class cpEfcWeaponAfterimage;
class cpHeadCtrl;
class cpIKCtrl;
class cpJointEx2;
class cpJointOrder;
class cpLegCtrl;
class cpMotionRate;
class cpReturnTerritory;
class cpSequenceCtrl;
class cpShakeCtrl;
class cpTinyChain;
class cpVibration;
namespace nObjCollision { struct stDmageVecInfo; }
class rAttackParam;
class rMotionParam;
class uCoord;
class uGUIGaugeEnemy;
class uGUIGaugeNpc;

// Declarations
class uCharacter;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using cRouteInfoIDFlag = nDDOUtility::cBitSet<7>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class uCharacter : public uDDOModel
{
public:
    enum
    {
        ROUTEACT_RET_OK = 0,
        ROUTEACT_RET_NG = 1,
        ROUTEACT_RET_CHK_ACT = 2,
        ROUTEACT_RET_NUM = 3,
    };
public:
    class MyDTI;
    struct stDmActColParam;
public:
    using cTargetLifeAreas = nDDOUtility::cArray<cGeneralPointPtr, 3>;
    using CalcWMatFunctionEx = void(uCharacter::*)(uModel::Joint*);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stDmActColParam
    {
        // inferred: uCharacter::callbackDamageAfter_apply names uCharacter::mDmActParam.mDamageDir.x
        friend class uCharacter;
    public:
        stDmActColParam();
        ~stDmActColParam();
        void setAttackParam(u64 uID);
        void setAttackParam(const cAttackParam* pParam);
        const cAttackParam* getAttackParam() const;
        void setAttackParamTable(rAttackParam* pParam);
        rAttackParam* getAttackParamTable() const;
        void setDamageDir(const MtVector3& dir);
        const MtVector3& getDamageDir() const;
    public:
        f32 mWeight;  // offset: 0x0
    private:
        cAttackParam* mpAttackParam;  // offset: 0x8
        rAttackParam* mpAttackParamTable;  // offset: 0x10
        MtVector3 mDamageDir;  // offset: 0x20
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
    uCharacter();
    virtual ~uCharacter();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void sync();  // vtable slot 11
    virtual void moveAfter();  // vtable slot 10
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    virtual void setParent(uCoord* pparent, s32 parent_no);  // vtable slot 24
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    void callbackMoveBegin();
    void before();
    void update();
    void checkAction();
    virtual u32 actionConvert(u32 actNo);  // vtable slot 173
    void updateMotion();
    virtual void updateMatrix();  // vtable slot 71
    virtual void callbackUpdateAfter();  // vtable slot 73
    void updatePosition();
    void after();
    void moveMotionEx();
    virtual void createComponent();  // vtable slot 43
    virtual void setupComponentPtr();  // vtable slot 44
    virtual void setupActPreInit();  // vtable slot 48
    virtual void setupContextAction(bool recvFlag);  // vtable slot 50
    virtual void setupContextCondition(bool recvFlag);  // vtable slot 51
    virtual void setupContextTarget(bool recvFlag);  // vtable slot 53
    virtual void callbackInjured(bool setupFlag);  // vtable slot 134
    virtual void callbackLost(bool setupFlag);  // vtable slot 135
    virtual void callbackRescue(u32 unitParam, u32 touchtype);  // vtable slot 137
    virtual void callbackOcdRescue(u32 ocdType);  // vtable slot 138
    virtual void callbackRespawn(bool setupFlag);  // vtable slot 139
    virtual void callbackReturnTerritory(bool setupFlag);  // vtable slot 140
    void checkReturnTerritory(bool forceReturnTeritory);
    bool isReturnTerritoryFlag();
    virtual void callbackEndAction(cpActionManager* pActMgr);  // vtable slot 174
    virtual void callbackHitLand();  // vtable slot 175
    virtual void callbackFall();  // vtable slot 176
    virtual void callbackAltitudeFall();  // vtable slot 177
    virtual void callbackAltitudeFallLand();  // vtable slot 178
    virtual void callbackSetCaught();  // vtable slot 179
    virtual void callbackMoveFreeze_On();  // vtable slot 180
    virtual void callbackMoveFreeze_Update();  // vtable slot 181
    virtual void callbackMoveFreeze_Off();  // vtable slot 182
    bool isMoveFreeze() const;
    bool isMoveFreezeOld() const;
    virtual u32 replaceCollisionAttr(u32 attr, const cCollNode* pCollNode);  // vtable slot 143
    virtual void updateHitStop();  // vtable slot 62
    virtual void hitInstantDeath(bool isFall, bool isWall);  // vtable slot 63
    void initObjCollision();
    void initScrCollision();
    void initEfcSequence(cpSequenceCtrl* pSeqCtrl);
    void setMotionKeyFrameNum(u32);
    virtual void effectCondistionFromScr();  // vtable slot 183
    u32 getOcdFromScrAttr() const;
    void clearOcdAll();
protected:
    virtual void updateObjStatus();  // vtable slot 69
    void updateMotionParamEx();
private:
    void updateOSTFree(u32 seq, nDDOModel::SEQ_OST_NO ostNo);
    nDDOModel::SEQ_OST_BIT seqOstNoToBit(nDDOModel::SEQ_OST_NO no);
public:
    cpTinyChain* getCpTinyChain() const;
    virtual void resetPos(const MtVector3& pos);  // vtable slot 59
    const MtQuaternion& getDamageQuat() const;
    f32 getActRotateSpeed(u32 actNo);
    virtual void callbackDamageAfter_make(cHitInfoAfter* pHitInfo);  // vtable slot 91
    virtual void callbackDamageAfter_makeEnd(cHitInfoAfter* pHitInfo);  // vtable slot 92
    virtual void callbackDamageAfter_calc(cHitInfoAfter* pHitInfo);  // vtable slot 93
    virtual void callbackDamageAfter_calcEnd(cHitInfoAfter* pHitInfo);  // vtable slot 94
    virtual void callbackDamageAfter_apply(cHitInfoAfter* pHitInfo);  // vtable slot 95
    virtual void callbackGuard_apply(cHitInfo* pHitInfo);  // vtable slot 102
    virtual void callbackShrink(cHitInfoAfter* pHitInfo);  // vtable slot 106
    virtual void callbackBlow(cHitInfoAfter* pHitInfo);  // vtable slot 107
    virtual void callbackStorm(cHitInfoAfter* pHitInfo);  // vtable slot 110
    virtual bool isEnableStorm(cHitInfoAfter* pHitInfo);  // vtable slot 112
    virtual bool isEnableQuake(cHitInfoAfter* pHitInfo);  // vtable slot 113
    // Address: 0x01ad25a0 - 0x01ad25a1 (1 bytes)
    virtual void callbackWinTarget(cHitInfoAfter* pHitInfo) {}  // vtable slot 184
protected:
    void callbackShrinkSub(cHitInfoAfter* pHitInfo);
public:
    virtual void makeDamageAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 149
    virtual void makeShlDamageAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 150
    virtual void makeDamageDefenceInfo(cHitInfoAfter* pHitInfo);  // vtable slot 151
private:
    void makeDamageAttackInfoCom(cHitInfoAfter* pHitInfo);
    void applyOcdDamageAdj(cHitInfoAfter* pHitInfo);
public:
    virtual void makeBlowShrinkAttackInfo(cBlowShrinkDmInfo* pInfo, uDDOModel* pAttacker, uDDOModel* pDefender, u32 atkAdjustUniqueId);  // vtable slot 152
    virtual void makeBlowShrinkAttackInfoShl(cBlowShrinkDmInfo* pInfo, uDDOModel* pAttacker, uDDOModel* pDefender, u32 atkAdjustUniqueId);  // vtable slot 153
    // Address: 0x01ad2580 - 0x01ad2581 (1 bytes)
    virtual void makeBlowShrinkDefenceInfo(cHitInfoAfter* pBlowShrinkInfo) {}  // vtable slot 154
    virtual void makeOcdDefenceInfo(cHitInfoAfter* pHitInfo);  // vtable slot 157
    virtual void makeOcdAttackInfoShl(cHitInfoAfter* pHitInfo);  // vtable slot 155
    void makeOcdAttackInfoCom(cHitInfoAfter* pHitInfo);
    virtual void callbackHitStopSlowRecv(cHitInfoAfter* pHitInfo);  // vtable slot 115
    virtual void playHitStopSlow(cHitInfoAfter* pHitInfo);  // vtable slot 162
    virtual void callbackGuard(cHitInfo* pHitInfo);  // vtable slot 78
    virtual void callbackGuarded(cHitInfo* pHitInfo);  // vtable slot 79
    virtual bool callbackShake(cHitInfoAfter* pHitInfo);  // vtable slot 109
    virtual bool callbackDown(cHitInfoAfter* pHitInfo);  // vtable slot 108
    virtual void callbackReqOcdAction(cOcdInfo& OcdInfo, bool initFlag);  // vtable slot 145
    virtual void callbackChecked(cHitInfo* pHitInfo);  // vtable slot 124
    virtual bool linkCallBackNavigationMesh(cAISvPathFinding::Node& next, cAISvPathFinding::Node& current);  // vtable slot 185
    u32 checkExistRouteAction(u32 stAttr, u32 enAttr, cRouteInfoIDFlag& dst);
    bool isExecRouteAction(cAISvPathFinding::Node& stNode, cAISvPathFinding::Node& edNode, cRouteInfoIDFlag& act);
    u32 getBtlBgmReqNo() const;
    void setBtlBgmReqNo(u32 reqNo);
    bool isAdvantageBgm() const;
    void setIsAdvantageBgm(bool flag);
    bool isAdvantage() const;
protected:
    void setAdvantage(bool flag);
public:
    void startStopSloTimer(f32 rate, f32 time, bool is_attacker, nObjCollision::UNIT_INV_THROUGH_TYPE invThroughType);
    void setIsFallSpeedLimitEnable(bool flag);
    f32 getHitStopSlowTimer();
private:
    void playGuardHitStop(cHitInfo* pHitInfo);
    f32 getGameDeltaTime() const;
    f32 getMoveVelAverage() const;
    void setMoveVelAverage(f32 NewValue);
    f32 getMoveVelAveInter() const;
    void setMoveVelAveInter(f32 NewValue);
    const MtVector3& getCheatCheckOldPos() const;
    void setCheatCheckOldPos(const MtVector3& NewValue);
    void checkWarpCheat();
public:
    void getLifeAreaPointAll(MtTypedArray<cGeneralPoint>* pDst, u32 filterObjID);
    bool getLifeAreaPointRnd(cGeneralPoint* * ppDst, u32 filterObjID);
    bool getLifeAreaPointNear(cGeneralPoint* * ppDst, u32 filterObjID, f32 maxRadius, f32 minRadius);
    bool getLifeAreaPointFar(cGeneralPoint* * ppDst, u32 filterObjID, f32 maxRadius, f32 minRadius);
    s32 getLifeAreaGroup() const;
    void setLifeAreaGroup(s32 val);
    bool getLifeAreaPointForEnemy(cGeneralPoint* * ppDst, u32 filterObjID, f32 maxRadius, f32 minRadius);
    void stackLifeArea(cGeneralPoint* pGp);
    bool isTargetedLifeArea(cGeneralPoint* pGp);
    void resetStackLifeArea();
    stDmActColParam& getDmActParam();
    bool makeDamageVec(nObjCollision::stDmageVecInfo* pInfo, nObjCollision::REACTION_TYPE reactionTyep, bool isAir, u32 type);
    bool makeDamageVec(nObjCollision::stDmageVecInfo* pInfo, nObjCollision::REACTION_TYPE reactionTyep, bool isAir, u32 type, u32 Lv);
protected:
    u32 decideDamageReaction4Dir(const MtVector3& dmVector, u32 ActNoF, u32 ActNoB, u32 ActNoL, u32 ActNoR, bool isAdjustDir);
    u32 decideDamageReaction2DirFB(const MtVector3& dmVector, u32 ActNoF, u32 ActNoB, bool isAdjustDir);
    u32 decideDamageReaction2DirLR(const MtVector3& dmVector, u32 ActNoL, u32 ActNoR, bool isAdjustDir);
    u32 decideDamageReactionOnlyFront(const MtVector3& dmVector, u32 ActNoF, bool isAdjustDir);
    u32 decideDamageReaction4Dir(cHitInfoAfter* pHitInfo, u32 ActNoF, u32 ActNoB, u32 ActNoL, u32 ActNoR, bool isAdjustDir);
    u32 decideDamageReaction2DirFB(cHitInfoAfter* pHitInfo, u32 ActNoF, u32 ActNoB, bool isAdjustDir);
    u32 decideDamageReaction2DirLR(cHitInfoAfter* pHitInfo, u32 ActNoL, u32 ActNoR, bool isAdjustDir);
    u32 decideDamageReactionOnlyFront(cHitInfoAfter* pHitInfo, u32 ActNoF, bool isAdjustDir);
    nObjCollision::DM_REACTION_DIR judgeDamageReactionDir4(const MtVector3& v1, const MtVector3& v2) const;
    nObjCollision::DM_REACTION_DIR judgeDamageReactionDir2FB(const MtVector3& v1, const MtVector3& v2) const;
    nObjCollision::DM_REACTION_DIR judgeDamageReactionDir2LR(const MtVector3& v1, const MtVector3& v2) const;
    void setMyDirByDamageVec(nObjCollision::DM_REACTION_DIR dir, const MtVector3& dmVec);
public:
    virtual void calcWorldMatrix(u32 mode, bool debug_disp, MtColor col);  // vtable slot 186
    virtual void updateWorldMatrix();  // vtable slot 26
protected:
    void calcWMat(uModel::Joint* pwk);
    void calcWMatScaleInherit(uModel::Joint* pwk);
    void calcWMatScaleGlobal(uModel::Joint* pwk);
    void calcWMatNoScale(uModel::Joint* pwk);
    void updateJointWorldMatrixEx(const u8* jointTable, const u32 jointNum, const u32 updateWorldMode);
public:
    virtual f32 getMotionInterFrame(u32 mot_no);  // vtable slot 65
    void setMotionParam(rMotionParam* pRes, u32 bank);
    rMotionParam* getMotionParam(u32 bank);
    u32 getMotionParamNum();
    void setMotionParamNum(u32);
    void swapMotionParam(u32, u32);
    virtual u32 getEnemyID() const;  // vtable slot 187
    virtual u32 getThinkMode();  // vtable slot 188
    virtual void setThinkMode(u32);  // vtable slot 189
    virtual cEvaluationName::cEvaluation* getEvaluation();  // vtable slot 190
    void callbackAttackEva(cHitInfo* pHitInfo);
    void callbackDamageAfterEva(cHitInfoAfter* pHitInfo);
    void callbackCreateNodeEva(cHitNode* pHitNode);
protected:
    virtual bool callbackMotRateCheck(uModel::Motion* pMotion);  // vtable slot 191
public:
    void setTargetType(u32 type);
    u32 getTargetType() const;
    void setBigUIFlag(bool flag);
    bool isBigUI() const;
    void setBloodEnemy(bool flag);
    bool isBloodEnemy() const;
    void setAreaBoss(bool flag);
    bool isAreaBoss() const;
    void setNamedNo(u32);
    void setNamedScaleRate(f32 rate);
    void setNamedId(u32 namedId);
    void changeNamedId(u32 namedId);
    cNamedParam* getNamedParam() const;
    u32 getNamedNo();
    bool isNamed();
protected:
    bool createEnemyNpcHeadUI();
    void createEnemyHeadUI();
public:
    void startForceDispGaugeEnemy();
    bool isRaidBoss() const;
    void addColNodeProgFlag(u32 flag);
    virtual bool isUseAdvBgmEnemy() const;  // vtable slot 192
    // Address: 0x01ad25d0 - 0x01ad25d1 (1 bytes)
    virtual void callbackChangeErosionCurrentLevel(nErosionEnemyBase::EROSION_LEVEL level, nErosionEnemyBase::EROSION_LEVEL oldLevel) {}  // vtable slot 193
    // Address: 0x01ad25e0 - 0x01ad25e1 (1 bytes)
    virtual void callbackChangeErosionRealLevel(nErosionEnemyBase::EROSION_LEVEL level, nErosionEnemyBase::EROSION_LEVEL oldLevel) {}  // vtable slot 194
protected:
    u32 mOcdFromScrAttr;  // offset: 0x246c
public:
    cpEfcFootSmoke* mpEfcFootSmoke;  // offset: 0x2470
    cpEfcWeaponAfterimage* mpEfcWeaponAfterimage;  // offset: 0x2478
    cpEfcTouchDownSmoke* mpEfcTouchDownSmoke;  // offset: 0x2480
    cpEfcSequenceGeneral* mpEfcSequenceGeneral;  // offset: 0x2488
    cpJointOrder* mpJointOrder;  // offset: 0x2490
    cpIKCtrl* mpIKCtrl;  // offset: 0x2498
    cpHeadCtrl* mpHeadCtrl;  // offset: 0x24a0
    cpLegCtrl* mpLegCtrl;  // offset: 0x24a8
    cpShakeCtrl* mpShakeCtrl;  // offset: 0x24b0
    cpVibration* mpVibration;  // offset: 0x24b8
    cpMotionRate* mpMotionRate;  // offset: 0x24c0
    cpAIPawnEmChecker* mpAIPawnEmChecker;  // offset: 0x24c8
    cpTinyChain* mpTinyChain;  // offset: 0x24d0
    cpAltitudeFallCtrl* mpAltitudeFallCtrl;  // offset: 0x24d8
    cpReturnTerritory* mpReturnTerritory;  // offset: 0x24e0
    cpJointEx2* mpJointEx2;  // offset: 0x24e8
    u32 mWpnType;  // offset: 0x24f0
    MtQuaternion mDamageQuat;  // offset: 0x2500
private:
    u32 mBattleBgmReqNo;  // offset: 0x2510
    bool mIsAdvantageBgm;  // offset: 0x2514
    bool mAdvantageFlag;  // offset: 0x2515
    bool mIsHitStopSlow;  // offset: 0x2516
    bool mIsHitStopAttacker;  // offset: 0x2517
    u32 mHitStopRno;  // offset: 0x2518
    f32 mHitStopSlowTimer;  // offset: 0x251c
    bool mIsFallSpeedLimitEnable;  // offset: 0x2520
    f32 mMoveVelAverage;  // offset: 0x2524
    f32 mMoveVelAveInter;  // offset: 0x2528
    MtVector3 mCheatCheckOldPos;  // offset: 0x2530
protected:
    f32 mForceDmgActTimer;  // offset: 0x2540
private:
    s32 mLifeAreaGroup;  // offset: 0x2544
    cTargetLifeAreas mTargetLifeAreas;  // offset: 0x2548
protected:
    stDmActColParam mDmActParam;  // offset: 0x2580
public:
    rMotionParam* mpMotionParam[16];  // offset: 0x25b0
protected:
    u32 mTargetType;  // offset: 0x2630
    bool mIsBigUI;  // offset: 0x2634
    bool mIsBloodEnemy;  // offset: 0x2635
    bool mIsAreaBoss;  // offset: 0x2636
    u32 mNamedNo;  // offset: 0x2638
    f32 mNamedScaleRate;  // offset: 0x263c
    cNamedParam* mpNamedParam;  // offset: 0x2640
    uGUIGaugeNpc* mpGUIGaugeNpc;  // offset: 0x2648
    uGUIGaugeEnemy* mpGUIGaugeEnemy;  // offset: 0x2650
private:
    bool mFlgMotionStop;  // offset: 0x2658
    bool mFlgMotionStopOld;  // offset: 0x2659
public:
    static MyDTI DTI;
};
