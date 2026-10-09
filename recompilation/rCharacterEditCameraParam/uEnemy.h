#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtString.h"
#include "../shared/cEvaluation.h"
#include "../shared/nDDOUtility.h"
#include "../shared/nEnemy.h"
#include "../shared/nEnemyID.h"
#include "../shared/nErosionEnemyBase.h"
#include "../shared/nObjCollision.h"
#include "../shared/nRegionStatus.h"
#include "../shared/uCharacter.h"
#include "uCnsBoneScale.h"
#include "../shared/uModel.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class MtVector3;
class cAttackParam;
class cBlowShrinkDmInfo;
class cBlowShrinkInfo;
class cCharParamEnemy;
class cCnsBoneScaleCtrl;
class cCollNode;
class cDamageSeInfo;
class cEmStatusAdj;
namespace cEvaluationName { class cEvaluation; }
class cHitInfo;
class cHitInfoAfter;
class cHitNode;
class cOcdInfo;
class cResource;
class cUnitDieInfo;
class cpCorePointCtrl;
class cpEmDmgTimer;
class cpEmLvUpCtrl;
class cpEmMontageCtrl;
class cpEmParamCtrl;
class cpEmWarpCtrl;
class cpEnemyBloodStain;
class cpEnemyEffect;
class cpEnemyLocalEst;
class cpEnemyLocalShel;
class cpEnemyMaterial;
class cpEnemyReact;
class cpEnemySound;
class cpEnemyThink;
class cpErosionEnemy;
class cpErosionEnemyBase;
class cpErosionEnemySmall;
class cpErosionSuperEnemy;
class cpFlightCtrl;
class cpReaction;
class cpShakeCtrl;
class cpStatusCheck;
class cpTransparencyCtrl;
class cpWallMaria;
namespace nRegionStatus { struct stCorePointSlaveMsg; }
class rCharParamEnemy;
class rEmStatusAdj;
class uDDOModel;

// Declarations
class uEnemy;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uEnemy : public uCharacter
{
public:
    enum
    {
        SEQ_NO_ROTATE_0 = 0,
        SEQ_NO_ROTATE_1 = 1,
        SEQ_NO_LENGTH_0 = 2,
        SEQ_NO_LENGTH_1 = 3,
        SEQ_NO_SHELL_0 = 4,
        SEQ_NO_SHELL_1 = 5,
        SEQ_NO_XAXIS_R_ROT = 6,
        SEQ_NO_XAXIS_L_ROT = 7,
        SEQ_NO_SHAKE_CHANCE = 8,
        SEQ_NO_MONTAGE_0 = 11,
        SEQ_NO_MONTAGE_1 = 12,
        SEQ_NO_SUPERARM = 13,
        SEQ_NO_MUTEKI = 14,
        SEQ_NO_PARTSOFF_A = 15,
        SEQ_NO_PARTSOFF_B = 16,
        SEQ_NO_SHELL_2 = 21,
        SEQ_NO_DOWN = 24,
        SEQ_NO_DOWN_DIR = 25,
        SEQ_NO_HOVER = 26,
    };
public:
    class MyDTI;
    struct stShakeChanceInfo;
    struct stEnchantInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stShakeChanceInfo
    {
    public:
        stShakeChanceInfo();
        void clear();
    public:
        bool mIsActive;  // offset: 0x0
        f32 mTimer;  // offset: 0x4
    };
public:
    struct stEnchantInfo
    {
    public:
        u32 mEnchantColUID;  // offset: 0x0
        f32 mEnchantIntervalTime;  // offset: 0x4
        bool mEnchantArea;  // offset: 0x8
        bool mEnchantAreaOld;  // offset: 0x9
        bool mCanReEnchant;  // offset: 0xa
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
    uEnemy();
    virtual ~uEnemy();
    virtual void createComponent();  // vtable slot 43
    virtual void setupComponentPtr();  // vtable slot 44
    virtual void sync();  // vtable slot 11
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void setMaster(bool is_master);  // vtable slot 66
    virtual void callbackMoveBegin();  // vtable slot 195
    virtual void before();  // vtable slot 196
    virtual void updatePtr();  // vtable slot 17
    virtual void updateObjStatus();  // vtable slot 69
    virtual void update();  // vtable slot 197
    virtual void callbackUpdateAfter();  // vtable slot 73
    virtual void after();  // vtable slot 198
    virtual void registDelegate();  // vtable slot 45
    virtual void setTouch(uDDOModel* pReqOwner, bool isTouchSave);  // vtable slot 166
    virtual void updateMatrix();  // vtable slot 71
    virtual void calcWorldMatrix(u32 mode, bool debug_disp, MtColor col);  // vtable slot 186
    void updateHeadCtrl();
    void updateShakeCtrl();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    // Address: 0x01ad7230 - 0x01ad7231 (1 bytes)
    virtual void setupActionList() {}  // vtable slot 199
    virtual void setupBeforeContext(bool initSet);  // vtable slot 46
    virtual void setupContextParam();  // vtable slot 47
    virtual void setupContextCondition(bool recvFlag);  // vtable slot 51
    virtual void setupContextEnemyStatusChange(bool recvFlag);  // vtable slot 56
    virtual void setupContextCorePoint(bool recvFlag);  // vtable slot 57
    void setupEnemyScale();
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    nEnemy::ENEMY_ID getEnemyEnumID() const;
    virtual u32 getEnemyID() const;  // vtable slot 187
    void setEnemyEnumID(nEnemy::ENEMY_ID id);
    void setEnemyID(u32);
    bool isCategoryActive(nEnemy::ENEMY_CATEGORY category) const;
    void setEmReactNo(u32 no);
    u32 getEmReactNo() const;
    void setStartThinkTbl(u32 no);
    u32 getStartThinkTbl() const;
    void setSequencePartsOff(u32 seqFlag, u32 checkSeqNo);
    bool loadFsm(MT_CTSTR filePath);
    void setFsmTarget(uDDOModel* pTargetModel, const MtVector3& targetPos, s32 jointId);
    bool isHaveNpcCtrl();
    void setEnemyName(MT_CTSTR);
    MT_CTSTR getEnemyName() const;
    cpErosionEnemyBase* getErosionEnemyBase() const;
    cpErosionEnemy* getErosionEnemy() const;
    cpErosionEnemySmall* getErosionEnemySmall() const;
    cpErosionSuperEnemy* getErosionEnemySuper() const;
    virtual void callbackFall();  // vtable slot 176
    virtual void callbackAltitudeFall();  // vtable slot 177
    virtual void callbackAltitudeFallLand();  // vtable slot 178
    virtual void callbackChanceDown();  // vtable slot 200
    void callbackGetUpFromChanceDown();
    virtual void callbackGuard(cHitInfo* pHitInfo);  // vtable slot 78
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 83
    virtual void callbackDamage(cHitInfo* pHitInfo);  // vtable slot 88
    virtual void callbackDamageAfter(cHitInfoAfter* pHitInfo);  // vtable slot 89
    virtual void callbackDamageAfter_makeEnd(cHitInfoAfter* pHitInfo);  // vtable slot 92
    virtual void callbackDamageAfter_calc(cHitInfoAfter* pHitInfo);  // vtable slot 93
    virtual void callbackDamageAfter_apply(cHitInfoAfter* pHitInfo);  // vtable slot 95
    virtual void callbackGuard_make(cHitInfo* pHitInfo);  // vtable slot 100
    virtual void callbackGuard_apply(cHitInfo* pHitInfo);  // vtable slot 102
    virtual void callbackChecked(cHitInfo* pHitInfo);  // vtable slot 124
    virtual void callbackFlick(cHitInfoAfter* pHitInfo);  // vtable slot 105
    virtual void callbackFlickLocal(cHitInfo* pHitInfo);  // vtable slot 201
    virtual void callbackShrink(cHitInfoAfter* pHitInfo);  // vtable slot 106
    virtual void callbackBlow(cHitInfoAfter* pHitInfo);  // vtable slot 107
    virtual bool callbackDown(cHitInfoAfter* pHitInfo);  // vtable slot 108
    virtual bool callbackShake(cHitInfoAfter* pHitInfo);  // vtable slot 109
    virtual void callbackQuake(cHitInfoAfter* pHitInfo);  // vtable slot 111
    virtual void callbackStorm(cHitInfoAfter* pHitInfo);  // vtable slot 110
    virtual bool isEnableStorm(cHitInfoAfter* pHitInfo);  // vtable slot 112
    virtual bool isEnableQuake(cHitInfoAfter* pHitInfo);  // vtable slot 113
    virtual void callbackRegionBreak(cHitInfoAfter* pHitInfo);  // vtable slot 103
    virtual void callbackRegionBreakSlave(u32 regionNo);  // vtable slot 104
    virtual void callbackReqOcdAction(cOcdInfo& OcdInfo, bool initFlag);  // vtable slot 145
    virtual void callbackRegionBreakMasterSlave(u32 regionNo);  // vtable slot 202
    void callbackRegionRegenerateMasterSlave(u32 regionNo, nRegionStatus::P_REGION_CATEGORY category);
    virtual void callbackCheck(cHitInfo* pHitInfo);  // vtable slot 123
    void callbackExceptiveAirShrink(cHitInfoAfter* pHitInfo);
    void applyOcdAdjEm(cHitInfoAfter* pHitInfo);
    virtual void callbackChangeErosionCurrentLevel(nErosionEnemyBase::EROSION_LEVEL level, nErosionEnemyBase::EROSION_LEVEL oldLevel);  // vtable slot 193
    virtual void callbackChangeErosionRealLevel(nErosionEnemyBase::EROSION_LEVEL level, nErosionEnemyBase::EROSION_LEVEL oldLevel);  // vtable slot 194
    virtual void callbackCreateNode(cHitNode* pHitNode);  // vtable slot 76
    virtual void callbackMoveFreeze_On();  // vtable slot 180
    virtual void callbackMoveFreeze_Update();  // vtable slot 181
    virtual void callbackMoveFreeze_Off();  // vtable slot 182
    virtual void hitInstantDeath(bool isFall, bool isWall);  // vtable slot 63
    virtual void setHugebleDeath();  // vtable slot 64
    void moveInsuranceWarp();
protected:
    u32 getBreakActNo(u32 reactinNo);
    u32 actSelectShrinkActNo(cHitInfoAfter* pHitInfo);
    virtual u32 subActSelectShrinkActNo(cHitInfoAfter* pHitInfo);  // vtable slot 203
    u32 actSelectExceptiveAirShrinkActNo(cHitInfoAfter* pHitInfo);
    u32 actSelectBlowActNo(cHitInfoAfter* pHitInfo);
    virtual u32 subActSelectBlowActNo(cHitInfoAfter* pHitInfo);  // vtable slot 204
    u32 actSelectDmgShake(cHitInfoAfter* pHitInfo);
    virtual u32 subActSelectDmgShake(cHitInfoAfter* pHitInfo);  // vtable slot 205
    u32 actSelectDmgChanceDown(cHitInfoAfter* pHitInfo);
    virtual u32 subActSelectDmgChanceDown(cHitInfoAfter* pHitInfo);  // vtable slot 206
public:
    void callbackHpZero();
    virtual void callbackDie(cUnitDieInfo& dieInfo);  // vtable slot 133
    virtual u32 replaceCollisionAttr(u32 attr, const cCollNode* pCollNode);  // vtable slot 143
    cpEnemyThink* findcpEnemyThink() const;
    bool isHangedEnemy() const;
    bool isEnemyGroup(nEnemy::ENEMY_GROUP grp);
    bool is4LegEnemy() const;
    bool isFlyEnemy() const;
    bool isFloatEnemy() const;
    bool isBigEnemy() const;
    bool isAnimal() const;
    static bool isAnimal(nEnemy::ENEMY_ID emId);
    bool isShakedActionEnemy() const;
    bool isStatusRage() const;
    bool isRageNow() const;
    bool isSwitchShakeToDown() const;
    cBlowShrinkInfo* getShakInfoForGuage() const;
    virtual bool isUseAdvBgmEnemy() const;  // vtable slot 192
    nEnemy::ENEMY_MODE getEnemyMode() const;
    f32 getEnemyGuiDispRate() const;
    rCharParamEnemy* getCharaParamEnemy() const;
    cCharParamEnemy* getCharaParamEnemyObj() const;
protected:
    virtual void registOcdList(bool initSet);  // vtable slot 207
    virtual void registResource(bool initSet);  // vtable slot 208
    nEnemy::RESOURCE_TYPE selectVoResType(u32 tagId, nEnemy::RESOURCE_TYPE min, nEnemy::RESOURCE_TYPE max) const;
    void setResource(u32 resType, cResource* pResource, bool initSet);
    bool isResExist(u32 tagId, u32 searchId) const;
public:
    void setEmStatusAdjRes(rEmStatusAdj* pRes);
    const rEmStatusAdj* getEmStatusAdjRes() const;
    const cEmStatusAdj* getEmStatusRageAdj() const;
    const cEmStatusAdj* getEmStatusAdj(nEnemy::EM_STATUS_ADJ_INDEX index) const;
    bool isShakeSign() const;
    bool isResetSign() const;
    nEnemy::ENEMY_BODY_SIZE getBodySize();
    void setLv(u32 Lv);
    void setEnemyWaitting(bool enable, bool oversync);
    bool getEnemyWaitting();
    void setStartWait(bool enable, bool oversync);
    bool getStartWait();
    void setIsShakeChance(bool);
    bool isShakeChance() const;
    u32 getShakeChanceIndex() const;
    bool setStatusChangeCnsBoneScale(u32 no, u32 param0, f32 param1, f32 param2, f32 param3, f32 param4);
    bool setStatusChangeCnsBoneScale(u32 no, u32 jointNo, const MtVector3& initScale, const MtVector3& endScale, f32 frame);
    bool checkStatusChangeCnsBoneScaleEnd(u32 no);
    bool isTraceEnd();
    void setTraceEnd(bool enable);
    bool isTraceExist();
    void setTraceExist(bool enable);
    void setEmParamFromResToContext(const cCharParamEnemy* pEmParam);
    virtual void makeDamageAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 149
    virtual void makeDamageDefenceInfo(cHitInfoAfter* pHitInfo);  // vtable slot 151
    virtual void makeBlowShrinkAttackInfo(cBlowShrinkDmInfo* pInfo, uDDOModel* pAttacker, uDDOModel* pDefender, u32 atkAdjustUniqueId);  // vtable slot 152
    virtual void makeBlowShrinkDefenceInfo(cHitInfoAfter* pHitInfo);  // vtable slot 154
    virtual void makeOcdAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 156
    virtual void makeOcdAttackInfoShl(cHitInfoAfter* pHitInfo);  // vtable slot 155
    void makeOcdAttackInfoCom(cHitInfoAfter* pHitInfo);
    virtual void callbackAttackBefore(cHitInfoAfter* pHitInfo);  // vtable slot 116
    virtual void callbackGuardedBefore(cHitInfo* pHitInfo);  // vtable slot 82
    virtual void makeGuardAttackInfo(cHitInfo* pHitInfo);  // vtable slot 158
    virtual void makeGuardDefenceInfo(cHitInfo* pHitInfo);  // vtable slot 159
    virtual void makeHitSeInfo_Attack(cDamageSeInfo* pSeInfo);  // vtable slot 163
    void makeDamageStatusAdj(cHitInfoAfter* pHitInfo);
    void makeGuardStatusAdj(cHitInfo* pHitInfo);
    virtual u32 getThinkMode();  // vtable slot 188
    virtual void setThinkMode(u32 thinkmode);  // vtable slot 189
    virtual cEvaluationName::cEvaluation* getEvaluation();  // vtable slot 190
    nEnemy::DOWN_DIR getDownDir();
protected:
    u32 decideDamageReaction(cHitInfoAfter* pHitInfo, u32 ActNoF, u32 ActNoB, u32 ActNoL, u32 ActNoR, nObjCollision::REACTION_TYPE reactionType, u32 detailType);
    bool isQuakeReactionEm() const;
    bool isStormReactionEm() const;
public:
    u32 getGuardCnt();
    void addGuardCnt();
    void clrGuardCnt();
    void updateContinuousGuard();
protected:
    virtual bool callbackMotRateCheck(uModel::Motion* pMotion);  // vtable slot 191
public:
    cpWallMaria* getWallMaria() const;
    void receiveCorePointSlaveMsg(const nRegionStatus::stCorePointSlaveMsg& msg);
    void callSwayedSuccessSe();
private:
    virtual bool checkCalc(const cAttackParam* pAtkParam);  // vtable slot 172
public:
    virtual void setLODData();  // vtable slot 171
    void setDefNPCMotAct(u32 noHokan);
    void setTalkMotAct(s16 talkMotNo);
    void lockOnTarget_off();
    void requesutPartsAllOff();
    void resetReqPartsAllOff();
    bool isErosionEnemy() const;
    bool isErosionBigEnemy() const;
    bool isErosionSmallEnemy() const;
    bool isErosionSuperEnemy() const;
    void checkErosionCancel(cHitInfoAfter* pHitInfo, u32 ActNo, nObjCollision::REACTION_TYPE reactionType);
    bool isErosionInitZero() const;
    void setupEnchantMode();
    bool isActiveRageShrink() const;
    bool isRageShrinkInvisible() const;
    bool isActiveShakeChanceTime() const;
    bool isActiveShakeChanceTime(nObjCollision::SHAKE_CHANCE_TYPE chanceType) const;
    void activateShakeChanceTime(nObjCollision::SHAKE_CHANCE_TYPE chanceType);
private:
    void updateShakeChanceTime();
    void resetShakeChanceTime();
    bool isActiveDamageBounusFlag(nObjCollision::DAMAGE_BONOUS_TYPE_FLAG flag) const;
    void setupMotionBlendKeyFrame();
    void updateMotionBlendKeyFrame();
    void callbackCheckedSubNode(cHitInfo* pHitInfo);
public:
    bool isEnemyFreeEnchant() const;
private:
    void updateEnchantColInfo();
    void updateEnchantColInfoCore(u32 i);
    bool registerEnchantUid(u32 uid, f32 interval_time);
public:
    virtual bool checkRegionStatusOriginal1() const;  // vtable slot 209
    virtual bool checkRegionStatusOriginal2() const;  // vtable slot 210
private:
    void updateEyelidsMontage();
public:
    bool isActorDead() const;
    void setActorDead(bool);
    f32 getJob05ProvokeExtendDist() const;
private:
    bool disableRageEffect() const;
public:
    cpEnemyThink* mpEnemyThink;  // offset: 0x2660
    cpTransparencyCtrl* mpTransparencyCtrl;  // offset: 0x2668
    cpFlightCtrl* mpFlightCtrl;  // offset: 0x2670
    cpEmLvUpCtrl* mpEmLvUpCtrl;  // offset: 0x2678
    cpEmDmgTimer* mpEmDmgTimer;  // offset: 0x2680
    cpEnemyLocalEst* mpEnemyLocalEst;  // offset: 0x2688
    cpEnemySound* mpEnemySound;  // offset: 0x2690
    cpEnemyEffect* mpEnemyEffect;  // offset: 0x2698
    cpEnemyMaterial* mpEnemyMaterial;  // offset: 0x26a0
    cpEnemyLocalShel* mpEnemyLocalShel;  // offset: 0x26a8
    cpEmParamCtrl* mpEmParamCtrl;  // offset: 0x26b0
    cpShakeCtrl* mpShakeCtrl2;  // offset: 0x26b8
    cpCorePointCtrl* mpCorePointCtrl;  // offset: 0x26c0
    cpEnemyReact* mpEnemyReact;  // offset: 0x26c8
    cpStatusCheck* mpStatusCheck;  // offset: 0x26d0
    cpEmMontageCtrl* mpMontageCtrl;  // offset: 0x26d8
    cpReaction* mpReaction;  // offset: 0x26e0
    cpEmWarpCtrl* mpEmWarpCtrl;  // offset: 0x26e8
    cpErosionEnemyBase* mpErosionEnemy;  // offset: 0x26f0
    cpEnemyBloodStain* mpEnemyBloodStain;  // offset: 0x26f8
    u32 mSeqWorkParamHokan;  // offset: 0x2700
    u32 mSeqWorkParamHokan_Ang;  // offset: 0x2704
    u32 mSeqWorkParamXaxisHokan;  // offset: 0x2708
    u32 mSeqWorkParamXaxisHokan_Ang;  // offset: 0x270c
    u32 mSeqWorkParamDistHokan;  // offset: 0x2710
    u32 mSeqWorkParamDistHokan_Add;  // offset: 0x2714
protected:
    nEnemy::ENEMY_ID mEnemyResID;  // offset: 0x2718
    u32 mEnemyID;  // offset: 0x271c
    rCharParamEnemy* mpCharParamEnemy;  // offset: 0x2720
    rEmStatusAdj* mpEmStatusAdjRes;  // offset: 0x2728
    u32 mEmReactNo;  // offset: 0x2730
    bool mIsSetFsmTarget;  // offset: 0x2734
    uDDOModel* mpFsmTargetModel;  // offset: 0x2738
    MtVector3 mFsmTargetPos;  // offset: 0x2740
    s32 mFsmTargetJointId;  // offset: 0x2750
private:
    f32 mInsuranceTimer;  // offset: 0x2754
protected:
    bool mIsShakeSign;  // offset: 0x2758
    bool mIsResetSign;  // offset: 0x2759
    u32 mThinkTbl_Select;  // offset: 0x275c
    MtString mEnemyName;  // offset: 0x2760
private:
    bool mIsWaitting;  // offset: 0x2768
    bool mIsStartWait;  // offset: 0x2769
    bool mIsShakeChance;  // offset: 0x276a
    u32 mShakeChanceIndex;  // offset: 0x276c
protected:
    cCnsBoneScaleCtrl mCnsBoneScaleCtrl[5];  // offset: 0x2770
    bool mTraceEnd;  // offset: 0x2900
    bool mTraceExist;  // offset: 0x2901
    f32 mTraceExistWarpTimer;  // offset: 0x2904
private:
    u32 mThinkMode;  // offset: 0x2908
protected:
    nEnemy::DOWN_DIR mDownDir;  // offset: 0x290c
public:
    cEvaluationName::cEvaluation mcEvaluation;  // offset: 0x2910
    u32 mContinuousGuardCnt;  // offset: 0x5bc0
    f32 mContinuousGuardTimer;  // offset: 0x5bc4
protected:
    cpWallMaria* mpWallMaria;  // offset: 0x5bc8
    bool mIsReqPartsAllOff;  // offset: 0x5bd0
private:
    stShakeChanceInfo mShakeChanceInfo[2];  // offset: 0x5bd4
    u32 mKeyFrameBlendNo;  // offset: 0x5be4
    nDDOUtility::cArray<stEnchantInfo, 16> mEnchantColList;  // offset: 0x5be8
    s32 mEnchaColUidListIndex;  // offset: 0x5ca8
    s32 mEnchaColUidListBottom;  // offset: 0x5cac
    bool mIsActorDead;  // offset: 0x5cb0
public:
    static MyDTI DTI;
protected:
    static const u32 CNSBONESCALE_CTRL_MAX = 5;
public:
    static const u32 CHANCE_TIME_FRAME = 5;
};

// Inline, no code of its own: checked where it is inlined.
inline cpErosionEnemyBase* uEnemy::getErosionEnemyBase() const {
    return this->mpErosionEnemy;
}
