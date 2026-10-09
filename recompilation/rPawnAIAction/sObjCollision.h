#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cObjHitCache.h"
#include "../shared/cSystem.h"
#include "../shared/nCatch.h"
#include "../shared/nDDOUtility.h"
#include "../shared/nEnemyID.h"
#include "../shared/nHuman.h"
#include "../shared/nObjCollision.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cAdjLimitParam;
class cAttackParam;
class cBlowSaveEmLvParam;
class cCalcDamageLvAdj;
class cCollNode;
class cDamageSaveEmLvParam;
class cDamageSpecialAdj;
class cDmJobAdjParam;
class cDmJobPawnAdjParam;
class cDmLvPawnAdjParam;
class cDmVecWeightParam;
class cEmDamageDirInfo;
class cHitInfoAfter;
class cModelList;
class cObjHitCache;
class cResource;
class cShrinkBlowValue;
class rAdjLimitParam;
class rAdjustParam;
class rAttackParam;
class rBlowSaveEmLvParam;
class rCalcDamageAtdmAdj;
class rCalcDamageAtdmAdjRate;
class rCalcDamageLvAdj;
class rCaughtDamageRateRefTbl;
class rCaughtDamageRateTbl;
class rCollNode;
class rDamageSaveEmLvParam;
class rDamageSpecialAdj;
class rDmJobAdjParam;
class rDmJobPawnAdjParam;
class rDmLvPawnAdjParam;
class rDmVecWeightParam;
class rEmDamageDirInfo;
class rErosionShakeConvert;
class rObjCollision;
class rPushRate;
class rShrinkBlowValue;
class uDDOModel;

// Declarations
class sObjCollision;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using u32 = unsigned int;
namespace nObjCollision { using HIT_CACHE_HANDLE = u32; }
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u64 = __uint64_t;

class sObjCollision : public cSystem
{
public:
    enum SYS_PARAM_TYPE
    {
        VISUAL_PARAM = 0,
        GUARD_STOP_TIME = 1,
        STAMINA_GUARD_SCALE = 2,
        CORE_POINT_SHAKE_ADJ = 3,
        CORE_POINT_SWITCH_DOWN_ADJ = 4,
        ENCHANT_ENDURANCE_ATK = 5,
        ENCHANT_ENDURANCE_ADJ_HM = 6,
        ENCHANT_ENDURANCE_ADJ_EM = 7,
        ATDM_VALUE_ALPHA = 8,
        ATDM_VALUE_BETA = 9,
        ATDM_VALUE_GAMMA = 10,
        ATDM_CALC_POWER_MAX = 11,
        ATDM_CALC_POWER_MIN = 12,
        ATDM_VALUE_MAX = 13,
        ATDM_VALUE_MIN = 14,
        RAID_ATTACK_BASE_PHYS_OM = 15,
        RAID_ATTACK_WEP_PHYS_OM = 16,
        RAID_ATTACK_BASE_MAGIC_OM = 17,
        RAID_ATTACK_WEP_MAGIC_OM = 18,
        CREST_DAMAGE_ADJ = 19,
        IN_SLEEP_NORMAL_SHAKE_CNT = 20,
        IN_SLEEP_ANGER_SHAKE_CNT = 21,
        SLEEP_CHANCE_HP_DAMAGE = 22,
        SLEEP_CHANCE_STAMINA_SHAKE = 23,
        SLEEP_CHANCE_STAMINA_CORE = 24,
        EM_BLOW_RANDOM_DIS_MAX = 25,
        EM_BLOW_RANDOM_DIS_MIN = 26,
        EM_BLOW_RANDOM_TIME_MAX = 27,
        BLOW_SAVE_BASE_ADJ = 28,
    };
    enum PAWN_CONSTANT_PARAM
    {
        PAWN_CONSTANT_ATDMRATE = 0,
        PAWN_CONSTANT_ENDUEANCE = 1,
        PAWN_CONSTANT_HPDAMAGE = 2,
        PAWN_CONSTANT_SUTAMINADAMAGE = 3,
        PAWN_CONSTANT_GUARD = 4,
        PAWN_CONSTANT_SUTAMINADAMAGE_GUARD = 5,
        PAWN_CONSTANT_HP_HEAL = 6,
        PAWN_CONSTANT_HP_HEAL_WEP = 7,
    };
public:
    template <typename rParamType> class cParamInfoManager;
    template <typename T> class cParamInfo;
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    template <typename T>
    class cParamInfo : public MtObject
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
        static void usage();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        cParamInfo(T* pParam, u64 uID);
        virtual ~cParamInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void addCount();
        void subCount();
        u32 getCount() const;
        u64 getUID() const;
        T* getParamPtr() const;
    private:
        cParamInfo();
    private:
        T* mpParam;  // offset: 0x8
        u32 registNum;  // offset: 0x10
        u64 mUID;  // offset: 0x18
    public:
        static MyDTI DTI;
    };
public:
    template <typename rParamType>
    class cParamInfoManager : public MtObject
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
        static void usage();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        cParamInfoManager();
        virtual ~cParamInfoManager();
        rParamType* findParam(u64 id) const;
        void registParam(rParamType* pParam, u64 uID);
        void releaseParam(u64 id);
    private:
        s32 findParamStoredIndex(u64 id) const;
    private:
        MtTypedArray<sObjCollision::cParamInfo<rParamType> > mTableInfoArray;  // offset: 0x8
    public:
        static MyDTI DTI;
    private:
        static const s32 INVALID_INDEX = -1;
        static const u32 DEFAULT_RESERVE_SIZE = 64;
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
    sObjCollision();
    virtual ~sObjCollision();
    static sObjCollision* getInstance();
    void setup();
    virtual void move();  // vtable slot 7
    void setupBeforeUnitMove();
    virtual void reset();  // vtable slot 6
    void cheatCheck();
    u16 createUID();
    cObjHitCache* allocObjHitTempCache(nObjCollision::HIT_CACHE_HANDLE& handle);
    cObjHitCache* getObjHitTempCache(const nObjCollision::HIT_CACHE_HANDLE handle);
private:
    void clearHitCache();
public:
    void registResFromObjCol(rObjCollision* pObjCollision);
    void releaseResFromObjCol(rObjCollision* pObjCollision);
    void releaseResFromObjColPath(MT_CTSTR objColPath);
    rAttackParam* findAttackParamTable(u64 uID) const;
    const cAttackParam* findAttackParam(u64 uID, s32 index) const;
    void registAttackParamTable(rAttackParam* pTable, bool isUseResID);
    void releaseAttackParamTable(rAttackParam* pTable);
    rCollNode* findCollNodeTable(u64 uID) const;
    const cCollNode* findCollNode(u64 uID, s32 index) const;
    void registCollNodeTable(rCollNode* pTable, bool isUseResID);
    void releaseCollNodeTable(rCollNode* pTable);
    u64 makeParamUID(u32 tableUID, u32 index) const;
    u32 extractTableUID(u64 paramUID) const;
    u32 extractParamIndex(u64 paramUID) const;
private:
    u32 getPathID(const cResource* pRes) const;
    u32 makePathID(MT_CTSTR objColPath) const;
public:
    rPushRate* getPushRateMoveMove();
    rPushRate* getPushRateStopMove();
    rPushRate* getPushRateFix();
    void setPushRateMoveMove(rPushRate* pRes);
    void setPushRateStopMove(rPushRate* pRes);
    void setPushRateFix(rPushRate* pRes);
    bool isDamageApply(uDDOModel* pAttacker, uDDOModel* pDefender, cHitInfoAfter* pHitInfo) const;
    nObjCollision::CALC_DAMADE_MODE getCalcMode(uDDOModel* pAttacker, uDDOModel* pDefender, nObjCollision::CALC_DAMADE_KIND kind);
    rCalcDamageLvAdj* getDmLvAdjRes() const;
    rCalcDamageAtdmAdj* getDmAtdmAdjRes(bool isEnemy) const;
    rCalcDamageAtdmAdjRate* getDmAtdmAdjRateRes(bool isEnemy) const;
    const cCalcDamageLvAdj* getLvAdjData(uDDOModel* pAttcker, uDDOModel* pDefender) const;
    const cDmJobAdjParam* getDmJobAdjParam(nHuman::JOB_ENUM jobID);
    const cDmJobPawnAdjParam* getDmJobPawnAdjParam(nHuman::JOB_ENUM jobID);
    const cDmLvPawnAdjParam* getDmLvPawnAdjParam(u32 keyLv);
    const cDamageSaveEmLvParam* getDamageSaveEmLvParam(u32 keyLv);
    const cBlowSaveEmLvParam* getBlowSaveEmLvParam(u32 keyLv);
    const cDamageSpecialAdj* getDamageSpecialAdj(nObjCollision::DAMAGE_SPECIAL_ADJ adjType);
    const cShrinkBlowValue* getShBlValue(nObjCollision::SHRINK_BLOW_TYPE type, u32 Lv);
    const cEmDamageDirInfo* getEmDamageDirShrinkInfo(nEnemy::EM_CLASS_TYPE emType, u32 shrinkType, bool isAir);
    const cEmDamageDirInfo* getEmDamageDirBlowInfo(nEnemy::EM_CLASS_TYPE emType, u32 blowType, bool isAir);
    const cEmDamageDirInfo* getEmDamageDirStormInfo(nEnemy::EM_CLASS_TYPE emType, bool isAir);
    const cEmDamageDirInfo* getEmDamageDirInfo(nEnemy::EM_CLASS_TYPE emType, nObjCollision::SHRINK_BLOW_TYPE reaction);
    const cDmVecWeightParam* getDmVecWeightParam(f32 weight);
    f32 getSystemParam(SYS_PARAM_TYPE type) const;
    f32 getPawnConstantParam(PAWN_CONSTANT_PARAM type) const;
    nObjCollision::SHRINK_BLOW_TYPE getShrinkBlowTypeShrink(u32 shrinkType, bool isAir) const;
    nObjCollision::SHRINK_BLOW_TYPE getShrinkBlowTypeBlow(u32 blowType, bool isAir) const;
    nObjCollision::SHRINK_BLOW_TYPE getShrinkBlowTypeWind(bool isAir) const;
    u32 getBlowType(nObjCollision::SHRINK_BLOW_TYPE shblType) const;
    u32 getShrinkType(nObjCollision::SHRINK_BLOW_TYPE shblType) const;
    f32 getCaughtDamageRate(nCatch::CATCH_TYPE type) const;
    void createResource();
    void releaseResource();
    f32 getGuardAtkAdjMax(nObjCollision::GUARD_ATTACK_ADJ_TYPE type) const;
    f32 getGuardAtkAdjMin(nObjCollision::GUARD_ATTACK_ADJ_TYPE type) const;
    f32 getGuardDefAdjMax(nObjCollision::GUARD_DEFENCE_ADJ_TYPE type) const;
    f32 getGuardDefAdjMin(nObjCollision::GUARD_DEFENCE_ADJ_TYPE type) const;
    f32 getStaminaDamageAdjMax(nObjCollision::STAMINA_DAMAGE_ADJ_TYPE type) const;
    f32 getStaminaDamageAdjMin(nObjCollision::STAMINA_DAMAGE_ADJ_TYPE type) const;
    f32 getHpDamageAtkAdjMax(nObjCollision::HP_DAMAGE_ATTACK_ADJ_TYPE type) const;
    f32 getHpDamageAtkAdjMin(nObjCollision::HP_DAMAGE_ATTACK_ADJ_TYPE type) const;
    f32 getHpDamageDefAdjMax(nObjCollision::HP_DAMAGE_DEFENCE_ADJ_TYPE type) const;
    f32 getHpDamageDefAdjMin(nObjCollision::HP_DAMAGE_DEFENCE_ADJ_TYPE type) const;
    f32 getShrinkAtkAdjMax(nObjCollision::SHRINK_ATTACK_ADJ_TYPE type) const;
    f32 getShrinkAtkAdjMin(nObjCollision::SHRINK_ATTACK_ADJ_TYPE type) const;
    f32 getShrinkDefAdjMax(nObjCollision::SHRINK_DEFENCE_ADJ_TYPE type) const;
    f32 getShrinkDefAdjMin(nObjCollision::SHRINK_DEFENCE_ADJ_TYPE type) const;
    f32 getBlowAtkAdjMax(nObjCollision::BLOW_ATTACK_ADJ_TYPE type) const;
    f32 getBlowAtkAdjMin(nObjCollision::BLOW_ATTACK_ADJ_TYPE type) const;
    f32 getBlowDefAdjMax(nObjCollision::BLOW_DEFENCE_ADJ_TYPE type) const;
    f32 getBlowDefAdjMin(nObjCollision::BLOW_DEFENCE_ADJ_TYPE type) const;
    f32 getShakeAtkAdjMax(nObjCollision::SHAKE_ATTACK_ADJ_TYPE type) const;
    f32 getShakeAtkAdjMin(nObjCollision::SHAKE_ATTACK_ADJ_TYPE type) const;
    f32 getShakeDefAdjMax(nObjCollision::SHAKE_DEFENCE_ADJ_TYPE type) const;
    f32 getShakeDefAdjMin(nObjCollision::SHAKE_DEFENCE_ADJ_TYPE type) const;
    f32 getDownAtkAdjMax(nObjCollision::DOWN_ATTACK_ADJ_TYPE type) const;
    f32 getDownAtkAdjMin(nObjCollision::DOWN_ATTACK_ADJ_TYPE type) const;
    f32 getDownDefAdjMax(nObjCollision::DOWN_DEFENCE_ADJ_TYPE type) const;
    f32 getDownDefAdjMin(nObjCollision::DOWN_DEFENCE_ADJ_TYPE type) const;
    f32 getOcdAtkAdjMax(nObjCollision::OCD_ATTACK_ADJ_TYPE type) const;
    f32 getOcdAtkAdjMin(nObjCollision::OCD_ATTACK_ADJ_TYPE type) const;
    f32 getOcdDefAdjMax(nObjCollision::OCD_DEFENCE_ADJ_TYPE type) const;
    f32 getOcdDefAdjMin(nObjCollision::OCD_DEFENCE_ADJ_TYPE type) const;
    f32 getHpHealAtkAdjMax(nObjCollision::HP_HEAL_ATTACK_ADJ_TYPE type) const;
    f32 getHpHealAtkAdjMin(nObjCollision::HP_HEAL_ATTACK_ADJ_TYPE type) const;
    f32 getHpHealDefAdjMax(nObjCollision::HP_HEAL_DEFENCE_ADJ_TYPE type) const;
    f32 getHpHealDefAdjMin(nObjCollision::HP_HEAL_DEFENCE_ADJ_TYPE type) const;
    f32 getStaminaHealAtkAdjMax(nObjCollision::STAMINA_HEAL_ATTACK_ADJ_TYPE type) const;
    f32 getStaminaHealAtkAdjMin(nObjCollision::STAMINA_HEAL_ATTACK_ADJ_TYPE type) const;
    f32 getStaminaHealDefAdjMax(nObjCollision::STAMINA_HEAL_DEFENCE_ADJ_TYPE type) const;
    f32 getStaminaHealDefAdjMin(nObjCollision::STAMINA_HEAL_DEFENCE_ADJ_TYPE type) const;
    f32 getHolyAbsorpMax() const;
    f32 getHolyAbsorpMin() const;
    f32 getHpDamageMax() const;
    f32 getHpDamageMin() const;
    f32 findErosionCoreAddTime(f32 shakesRate) const;
private:
    nObjCollision::CALC_DAMAGE_UNIT_TYPE chekcTYPE(uDDOModel* pModel);
    void setDmLvAdjRes(rCalcDamageLvAdj* pRes);
    void setDmAtdmAdjResHM(rCalcDamageAtdmAdj* pRes);
    void setDmAtdmAdjResEM(rCalcDamageAtdmAdj* pRes);
    void setDmAtdmAdjRateRes(rCalcDamageAtdmAdjRate* pRes);
    void setShrinkBlowValue(rShrinkBlowValue* pRes);
    void setSystemRes(rAdjustParam* pRes);
    void setPawnConstantParamRes(rAdjustParam* pRes);
    void setJobAdjRes(rDmJobAdjParam* pRes);
    void setEmDamageDirInfoRes(rEmDamageDirInfo* pRes);
    void setDmVecWeightParamRes(rDmVecWeightParam* pRes);
    void setAdjLimitParamRes(rAdjLimitParam* pRes);
    void setJobPawnAdjParamRes(rDmJobPawnAdjParam* pRes);
    void setLvPawnAdjParamRes(rDmLvPawnAdjParam* pRes);
    void setDamageSaveEmLvParam(rDamageSaveEmLvParam* pRes);
    void setBlowSaveEmLvParam(rBlowSaveEmLvParam* pRes);
    void setDamageSpecialAdj(rDamageSpecialAdj* pRes);
    void setCaughtDamageRateRefTbl(rCaughtDamageRateRefTbl* pRes);
    void setCaughtDamageRateTbl(rCaughtDamageRateTbl* pRes);
    void setErosionShakeConvert(rErosionShakeConvert* pRes);
public:
    void addModelList(cModelList& ModelList, uDDOModel* pModel);
    void removeModelList(cModelList& ModelList, uDDOModel* pModel);
    bool findModelList(cModelList& ModelList, uDDOModel* pModel);
    bool isEmptyModelList(cModelList& ModelList);
    void clearModelList(cModelList& ModelList);
    u32 getCntCheatHpAlter_PL() const;
    void setCntCheatHpAlter_PL(u32 NewValue);
    u32 getCntCheatHpAlter_EM() const;
    void setCntCheatHpAlter_EM(u32 NewValue);
    u32 getCntCheatHpZero_EM() const;
    void setCntCheatHpZero_EM(u32 NewValue);
    u32 getCntCheatDead_EM() const;
    void setCntCheatDead_EM(u32 NewValue);
    u32 getCntCheatHpAlter_Other() const;
    void setCntCheatHpAlter_Other(u32 NewValue);
    u32 getCntCheatInvFlag_PL() const;
    void setCntCheatInvFlag_PL(u32 NewValue);
    u32 getCntCheatInvFlag_EM() const;
    void setCntCheatInvFlag_EM(u32 NewValue);
    u32 getCntCheatInvFlagGold_PL() const;
    void setCntCheatInvFlagGold_PL(u32 NewValue);
    u32 getCntCheatInvFlag_Other() const;
    void setCntCheatInvFlag_Other(u32 NewValue);
    u32 getCntCheatDamageBig() const;
    void setCntCheatDamageBig(u32 NewValue);
private:
    u16 mUID;  // offset: 0x12
    nDDOUtility::cArray<nDDOUtility::cArray<cObjHitCache, 1024>, 6> mHitCacheTempArray;  // offset: 0x18
    nDDOUtility::cArray<unsigned short, 6> mCacheNum;  // offset: 0x84018
    cParamInfoManager<rAttackParam>* mpAttackParamManager;  // offset: 0x84028
    cParamInfoManager<rCollNode>* mpCollNodeManager;  // offset: 0x84030
    bool mIsReady;  // offset: 0x84038
protected:
    rPushRate* mpPushRateMoveMove;  // offset: 0x84040
    rPushRate* mpPushRateStopMove;  // offset: 0x84048
    rPushRate* mpPushRateFix;  // offset: 0x84050
private:
    rCalcDamageLvAdj* mpDmLvAdjRes;  // offset: 0x84058
    rCalcDamageAtdmAdj* mpDmAtdmAdjResHM;  // offset: 0x84060
    rCalcDamageAtdmAdj* mpDmAtdmAdjResEM;  // offset: 0x84068
    rCalcDamageAtdmAdjRate* mpDmAtdmAdjRateRes;  // offset: 0x84070
    rShrinkBlowValue* mpShBlValue;  // offset: 0x84078
    rDmJobAdjParam* mpJobAdjRes;  // offset: 0x84080
    rEmDamageDirInfo* mpEmDamageDirInfo;  // offset: 0x84088
    rDmVecWeightParam* mpDmVecWeightParam;  // offset: 0x84090
    rAdjLimitParam* mpAdjLimitParamRes;  // offset: 0x84098
    rDmJobPawnAdjParam* mpJobPawnAdjParamRes;  // offset: 0x840a0
    rDmLvPawnAdjParam* mpLvPawnAdjParamRes;  // offset: 0x840a8
    rDamageSaveEmLvParam* mpDamageSaveEmLvParam;  // offset: 0x840b0
    rBlowSaveEmLvParam* mpBlowSaveEmLvParam;  // offset: 0x840b8
    rDamageSpecialAdj* mpDamageSpecialAdj;  // offset: 0x840c0
    cAdjLimitParam* mpAdjLimitParamData;  // offset: 0x840c8
    rAdjustParam* mpSystemParamRes;  // offset: 0x840d0
    rAdjustParam* mpPawnConstantParamRes;  // offset: 0x840d8
    rCaughtDamageRateRefTbl* mpCaughtDamageRateRefTbl;  // offset: 0x840e0
    rCaughtDamageRateTbl* mpCaughtDamageRateTbl;  // offset: 0x840e8
    rErosionShakeConvert* mpErosionShakeConvert;  // offset: 0x840f0
    u32 mCntCheatHpAlter_PL;  // offset: 0x840f8
    u32 mCntCheatHpAlter_EM;  // offset: 0x840fc
    u32 mCntCheatHpZero_EM;  // offset: 0x84100
    u32 mCntCheatDead_EM;  // offset: 0x84104
    u32 mCntCheatHpAlter_Other;  // offset: 0x84108
    u32 mCntCheatInvFlag_PL;  // offset: 0x8410c
    u32 mCntCheatInvFlag_EM;  // offset: 0x84110
    u32 mCntCheatInvFlagGold_PL;  // offset: 0x84114
    u32 mCntCheatInvFlag_Other;  // offset: 0x84118
    u32 mCntCheatDamageBig;  // offset: 0x8411c
    f32 mSendInterval;  // offset: 0x84120
public:
    static MyDTI DTI;
    static sObjCollision* mpInstance;
    static const u64 INVALID_ID = 4294967295;
};

// Inline, no code of its own: checked where it is inlined.
inline sObjCollision* sObjCollision::getInstance() {
    return ::sObjCollision::mpInstance;
}
