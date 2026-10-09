#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cBlowShrinkInfo.h"
#include "cChildRegionStatus.h"
#include "cDelegate.h"
#include "cParentRegionStatus.h"
#include "cpComponent.h"
#include "nDDOGame.h"
#include "nDDOUtility.h"
#include "nObjCollision.h"
#include "nOcdMsg.h"
#include "nRegionStatus.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cBlowShrinkDmInfo;
class cBlowShrinkInfo;
class cChildRegionStatus;
class cChildRegionStatusParam;
class cDamageEffInfo;
class cDamageMsg;
class cHitInfo;
class cHitInfoAfter;
class cParentRegionStatus;
class cRegionBreakInfo;
class cUnitDieInfo;
namespace nObjCondition { struct stHolyAbsorpReqInfo; }
namespace nObjCondition { struct stHolyAbsorpReqMsg; }
class rChildRegionStatusParam;
class rParentRegionStatusParam;
class uDDOModel;
class uEnemy;

// Declarations
class cDamageSeInfo;
class cpHpDamageCtrl;

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using u64 = __uint64_t;
using HP_DATATYPE = u64;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cAbsorpReqArray = nDDOUtility::cArray<nObjCondition::stHolyAbsorpReqInfo, 8>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cDamageSeInfo : public MtObject
{
public:
    enum ATTACKER_TYPE
    {
        TYPE_PLAYER_MYSELF = 0,
        TYPE_PLAYER_OTHER = 1,
        TYPE_POWN = 2,
        TYPE_HUMAN_ENEMY = 3,
        TYPE_ENEMY = 4,
        TYPE_NPC = 5,
        TYPE_SHELL = 6,
        TYPE_UNKOWN = 7,
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
    cDamageSeInfo();
    ATTACKER_TYPE getUnitType(uDDOModel* pModel, bool isAttackerShl);
    uDDOModel* getOwnerUnit(uDDOModel* pModel, u32 unitType);
    void copy(const cDamageSeInfo*);
public:
    uDDOModel* mpAttacker;  // offset: 0x8
    uDDOModel* mpDefender;  // offset: 0x10
    uDDOModel* mpAttackerOwner;  // offset: 0x18
    uDDOModel* mpDefenderOwner;  // offset: 0x20
    u32 mAttackType;  // offset: 0x28
    u32 mSurfaceType;  // offset: 0x2c
    bool mIsDownWeakRegion;  // offset: 0x30
    bool mIsThrust;  // offset: 0x31
    u32 mAttackReactionType;  // offset: 0x34
    u32 mAttackLevel;  // offset: 0x38
    bool mIsNoDamage;  // offset: 0x3c
    u32 mWeaponCategory;  // offset: 0x40
    u32 mAttackerType;  // offset: 0x44
    u32 mDefenderType;  // offset: 0x48
    u32 mAttackerBodySize;  // offset: 0x4c
    nDDOGame::ELEMENT_TYPE mElementType;  // offset: 0x50
    u32 mSeType;  // offset: 0x54
    bool mIsNonePhysSe;  // offset: 0x58
    bool mIsNoneElementSe;  // offset: 0x59
    u32 mEnemyWeaponType;  // offset: 0x5c
    u32 mWeaponType;  // offset: 0x60
    MtVector3 mHitPos;  // offset: 0x70
    s32 mJointNo;  // offset: 0x80
    static MyDTI DTI;
};

class cpHpDamageCtrl : public cpComponent
{
    // inferred: uEnemy::getShakInfoForGuage names cpHpDamageCtrl::mDownInfo
    friend class uEnemy;
public:
    enum ATDF_CALC_TYPE
    {
        ATDM_CALC_NORMAL = 0,
        ATDM_CALC_PL_SP_AT = 1,
        ATDM_CALC_PL_SP_DF = 2,
    };
    enum RESTRAINT_TYPE
    {
        RESTRAINT_SHRINK = 0,
        RESTRAINT_BLOW = 1,
        RESTRAINT_TYPE_NUM = 2,
    };
    enum RESPAWN_OPTION
    {
        RESPAWN_OPTION_ABILITY_59 = 1,
    };
public:
    class MyDTI;
    struct stReactionRestraint;
    struct stShrinkDamageBounusInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stReactionRestraint
    {
    public:
        stReactionRestraint();
        void clear();
    public:
        bool mIsReactionRestraint;  // offset: 0x0
        f32 mReactionRestraintFrame;  // offset: 0x4
        f32 mReactionRestraintFrameMax;  // offset: 0x8
    };
public:
    struct stShrinkDamageBounusInfo
    {
    public:
        stShrinkDamageBounusInfo();
        void clear();
        void setInfo(const cDamageMsg* pMsg);
        bool isSeted() const;
        const cDamageMsg* getDamageMsg() const;
    private:
        bool mIsSeted;  // offset: 0x0
        const cDamageMsg* mpDamageMsg;  // offset: 0x8
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
    cpHpDamageCtrl();
    virtual ~cpHpDamageCtrl();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    void before();
    void update();
    void compSync();
    void compMoveAfter();
    void checkCalcDamage();
    virtual void updatePtr();  // vtable slot 9
    bool isMainReagionisDead() const;
    bool isDead();
    bool isDead(u32 index) const;
    bool isDeadDying() const;
    HP_DATATYPE getHpRoot() const;
    HP_DATATYPE getHpMaxRoot() const;
    HP_DATATYPE getHp(const u32 index) const;
    HP_DATATYPE getHpMax(const u32 index) const;
    void healHp(const HP_DATATYPE hp, const u32 index, bool isForce);
    void subHp(const HP_DATATYPE hp, const u32 index);
    bool isUsedPRegion(u32 index) const;
    void addDamage(HP_DATATYPE damage, bool isNoDeath, u32 index);
    f32 getHpRate(u32 index) const;
    void requestDie();
    u32 getParentRegionNum() const;
    u32 getChildRegionNum() const;
    bool isDeadCheatCheck(u32 i) const;
    HP_DATATYPE getHpCheatCheck(u32 i) const;
    HP_DATATYPE getHpMaxCheatCheck(u32 i) const;
    cParentRegionStatus* getParentRegion(u32 index) const;
    cChildRegionStatus* getChildRegion(u32 index) const;
    cParentRegionStatus* findParentRegionFromNo(u32 no) const;
    cParentRegionStatus* findParentRegionFromChildNo(u32 childNo, nRegionStatus::PARENT_REGION_TYPE type) const;
    cChildRegionStatus* findChildRegionFromNo(u32 no) const;
    void addChildRegion(cChildRegionStatusParam* pRegionRes);
    void regionRegenerateAll();
    void regionRegenerate(nRegionStatus::P_REGION_TYPE regionNo);
    void regionRegenerateCate(nRegionStatus::P_REGION_CATEGORY category);
    void regionErosionRegenerateCateAll();
    void regionErosionRegenerateCateInit();
    void regionErosionRegeneratePriority();
    void setupRegionDie(nRegionStatus::P_REGION_CATEGORY category);
    void setupRegionDie(nRegionStatus::P_REGION_TYPE regionNo);
    cParentRegionStatus* findRegionFromCategory(nRegionStatus::P_REGION_CATEGORY category) const;
    nRegionStatus::REGION_REGENERATE_PRIORITY getRegenerateProprity(nRegionStatus::P_REGION_TYPE type) const;
    void setShP(f32 shrink, u32 regionNo);
    void setShPMax(f32 shrinkMax, u32 regionNo);
    f32 getShP(u32 regionNo) const;
    f32 getShPMax(u32 regionNo) const;
    void setBlP(f32 blow, u32 regionNo);
    void setBlPMax(f32 blowMax, u32 regionNo);
    f32 getBlP(u32 regionNo) const;
    f32 getBlPMax(u32 regionNo) const;
    cBlowShrinkInfo* getDownInfo();
    cBlowShrinkInfo* getShakeInfo();
    cBlowShrinkInfo* getRageShrinkInfo();
    void resetDownInfo();
    void resetShakeInfo();
    void resetRageShrinkInfo();
    bool isSwitchShakeToDown() const;
    bool isSwitchShakeToDown(uDDOModel* pModel) const;
    void regionSuicide(nRegionStatus::P_REGION_TYPE regionNo);
private:
    void regionRegenerateCore(cParentRegionStatus* pRegion);
    void regionSuicideCore(cParentRegionStatus* pRegion);
    void initParentRegion(rParentRegionStatusParam* pParentParamRes, bool initSet);
    void initChildRegion(rChildRegionStatusParam* pChildParamRes);
    void updateUseRegionBit();
public:
    void setResParentRegionTool(rParentRegionStatusParam* pRes);
    void setResParentRegion(rParentRegionStatusParam* pRes, bool initSet);
    void setResChildRegion(rChildRegionStatusParam* pRes);
    rParentRegionStatusParam* getResParentRegion() const;
    rChildRegionStatusParam* getResChildRegion() const;
    const cRegionBreakInfo* getRegionBreakInfo(nRegionStatus::P_REGION_TYPE regionNo) const;
private:
    bool isDying() const;
public:
    void callbackAbilityEffect(cHitInfoAfter* pHitInfo);
    void callbackHealedAfter_make(cHitInfoAfter* pHitInfo);
    void callbackHealedAfter_calc(cHitInfoAfter* pHitInfo);
    void checkReplaceInfo(cHitInfoAfter& HitInfo);
    void callbackDamageAfter_make(cHitInfoAfter* pHitInfo);
    void callbackDamageAfter_calc(cHitInfoAfter* pHitInfo);
    void callbackDamageAfter_apply(cHitInfoAfter* pHitInfo);
    void callbackGuard_make(cHitInfo* pHitInfo);
    void requestCallBackDie(cHitInfoAfter* pHitInfo);
    void playDamageSe(cHitInfoAfter* pHitInfo);
    virtual void makeDamageEffectInfo(cHitInfoAfter* pHitInfo, cDamageEffInfo* pEffInfo);  // vtable slot 15
    void playDamageEff(cHitInfoAfter* pHitInfo);
    void dispDamageGUI(cHitInfoAfter* pHitInfo);
    void checkFriendHitLocal(cHitInfo* pHitInfo);
    void callDamageSe(const cDamageSeInfo* pSeInfo) const;
    void callDamageAtkSe(const cDamageSeInfo* pSeInfo) const;
    void resetEndurance_ActShrink();
    void resetEndurance_ActBlow();
    void resetEndurance_ActShake();
    void resetEndurance_ActDown();
    void resetEndurance_RageStart();
private:
    void makeDamageAdj(cHitInfoAfter* pHitInfo);
    void calcDamage(cHitInfoAfter* pHitInfo);
    void calcPrepareCommon(cHitInfoAfter* pHitInfo);
    void calcDamagePrepare(cHitInfoAfter* pHitInfo);
    f32 calcFinalAttack(cHitInfoAfter* pHitInfo, bool isEnchant) const;
    f32 calcAtdmRate(cHitInfoAfter* pHitInfo, bool isPhys);
    void makeBlowShrinkDmParam(cBlowShrinkDmInfo* pInfo, uDDOModel* pAttacker, uDDOModel* pDefender);
    void calcBlowShrink(cHitInfoAfter* pHitInfo);
    void calcShakeDamage(cHitInfoAfter* pHitInfo);
    f32 calcShakeDamageCore(cHitInfoAfter* pHitInfo, bool isEnchant) const;
    f32 calcShrinkBounusDamage(cHitInfoAfter* pHitInfo, bool isSwitchEndurance) const;
    f32 calcShakeChanceRate(uEnemy* pEnemy) const;
    void applyDamageToHp(cHitInfoAfter* pHitInfo);
    void checkShrinkBlow(cHitInfoAfter* pHitInfo);
    void applyShrinkBlowDamage(cHitInfoAfter* pHitInfo, cParentRegionStatus* pRegionP, uDDOModel* pDefender);
    void applyShrinkBlowDamage_Shrink(cHitInfoAfter* pHitInfo, cParentRegionStatus* pRegionP, uDDOModel* pDefender, bool isCalc);
    void applyShrinkBlowDamage_Blow(cHitInfoAfter* pHitInfo, cParentRegionStatus* pRegionP, uDDOModel* pDefender, bool isCalc);
    void applyShrinkBlowDamage_RageShrink(cHitInfoAfter* pHitInfo, cParentRegionStatus* pRegionP, uDDOModel* pDefender, bool isCalc);
    void applyShrinkBlowDamage_Shake(cHitInfoAfter* pHitInfo, cParentRegionStatus* pRegionP, uDDOModel* pDefender, bool isCalc);
    void applyShrinkBlowDamage_Down(cHitInfoAfter* pHitInfo, cParentRegionStatus* pRegionP, uDDOModel* pDefender, bool isCalc);
    f32 calcDamageBottom(cHitInfoAfter* pHitInfo);
    ATDF_CALC_TYPE selectAtdmCalcType(uDDOModel* pAttcker, uDDOModel* pDefender, u32 LvAt, u32 LvDf) const;
    void executeCalcDamage();
    void executeCalcDamageCore(cHitInfoAfter& hitInfo);
    void executeBounusDamage();
    void makePawnDamageAdj(cHitInfoAfter* pHitInfo);
    void makePawnShrinkBlowAdj(cBlowShrinkDmInfo& blowShrinkInfo, const uDDOModel& attacker, const uDDOModel& defender);
    void makePawnHealAdj(cHitInfoAfter* pHitInfo);
    void makePawnGuardAdj(cHitInfo* pHitInfo);
    f32 calcHpDamageAttackAdj(cHitInfoAfter* pHitInfo);
    f32 calcHpDamageDefenceAdj(cHitInfoAfter* pHitInfo);
    f32 calcHpDamageFinalAdj(cHitInfoAfter* pHitInfo) const;
    f32 calcShrinkAttackAdj(cHitInfoAfter* pHitInfo);
    f32 calcShrinkDefenceAdj(cHitInfoAfter* pHitInfo);
    f32 calcBlowAttackAdj(cHitInfoAfter* pHitInfo);
    f32 calcBlowDefenceAdj(cHitInfoAfter* pHitInfo);
    f32 calcDownAttackAdj(cHitInfoAfter* pHitInfo);
    f32 calcDownDefenceAdj(cHitInfoAfter* pHitInfo);
    f32 calcShakeAttackAdj(cHitInfoAfter* pHitInfo);
    f32 calcShakeDefenceAdj(cHitInfoAfter* pHitInfo);
    f32 calcHpHealAttackAdj(cHitInfoAfter* pHitInfo);
    f32 calcHpHealDefenceAdj(cHitInfoAfter* pHitInfo);
    f32 calcStaminaHealAttackAdj(cHitInfoAfter* pHitInfo);
    f32 calcStaminaHealDefenceAdj(cHitInfoAfter* pHitInfo);
public:
    void setRespawn(bool isRescue, u32 option);
    void setDeadRecover(HP_DATATYPE hp);
    bool isDead() const;
    uDDOModel* getDDOModel() const;
    bool isRequestDie() const;
    void setRequestDie(bool flag);
    f32 getLastDamageTime() const;
    void registAbsorpReqMsg(const nObjCondition::stHolyAbsorpReqMsg& srcMsg);
    void receiveAbsorpReqNetMsg(const nObjCondition::stHolyAbsorpReqMsg& srcMsg);
private:
    void checkHolyAbsorpReq();
    void clearAbsorpReqArray();
public:
    void registSoulAbsorpReqMsg(const nObjCondition::stHolyAbsorpReqMsg& srcMsg);
    void receiveSoulAbsorpReqNetMsg(const nObjCondition::stHolyAbsorpReqMsg& srcMsg);
private:
    void checkSoulAbsorpReq();
    void clearSoulAbsorpReqArray();
public:
    void startReactionRestraint(RESTRAINT_TYPE type, f32 frame);
    void addDamageCheatCheck(HP_DATATYPE damage);
    void setShrinkBounusInfo(cHitInfoAfter* pHitInfo);
    void cancelShrinkBounusInfo(cHitInfoAfter* pHitInfo, nObjCollision::RESULT_BONOUS_PRIORITY priority);
    void setResultBounusPriority(nObjCollision::RESULT_BONOUS_PRIORITY propriry);
private:
    nObjCollision::RESULT_BONOUS_PRIORITY getResultBounusProproty() const;
    void cheatCheckHpDeadFlag();
    void cheatCheckCallbackDie();
    void updateDamageCheatCheck();
    void resetDamageCheatCheckWork();
    HP_DATATYPE getDamageCheatCheckSum() const;
    void setDamageCheatCheckSum(HP_DATATYPE NewValue);
private:
    MtTypedArray<cParentRegionStatus> mParentRegionStatusArray;  // offset: 0x50
    MtTypedArray<cChildRegionStatus> mChildRegionStatusArray;  // offset: 0x70
    cBlowShrinkInfo mDownInfo;  // offset: 0x90
    cBlowShrinkInfo mShakeInfo;  // offset: 0xc8
    cBlowShrinkInfo mRageShrinkInfo;  // offset: 0x100
    rParentRegionStatusParam* mpParentRegionRes;  // offset: 0x138
    rChildRegionStatusParam* mpChildRegionRes;  // offset: 0x140
    u32 mHpWorkNum;  // offset: 0x148
    uDDOModel* mpModel;  // offset: 0x150
public:
    cDelegate_1<void, cUnitDieInfo&> callbackDie;  // offset: 0x158
    cDelegate_0<void> callbackHpZero;  // offset: 0x170
private:
    bool mIsRequestDie;  // offset: 0x188
    bool mCompleteCallbackHpZero;  // offset: 0x189
    f32 mLastDamageTime;  // offset: 0x18c
    cAbsorpReqArray mAbsorpReqArray;  // offset: 0x190
    cAbsorpReqArray mSoulAbsorpReqArray;  // offset: 0x210
    stReactionRestraint mReactionRestraint[2];  // offset: 0x290
    stShrinkDamageBounusInfo mShrinkBounusInfo;  // offset: 0x2a8
    nObjCollision::RESULT_BONOUS_PRIORITY mResultBounusPriority;  // offset: 0x2b8
    HP_DATATYPE mDamageCheatCheckSum;  // offset: 0x2c0
    f32 mDamageCheatCheckTimer;  // offset: 0x2c8
    f32 mDamageCheatCheckSpan;  // offset: 0x2cc
    HP_DATATYPE mDamageCheat_Threshold;  // offset: 0x2d0
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline bool cpHpDamageCtrl::isRequestDie() const {
    return this->mIsRequestDie;
}
