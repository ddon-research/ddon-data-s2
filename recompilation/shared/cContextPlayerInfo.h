#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "GpCourseEffect.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cContext.h"
#include "nAbility.h"
#include "nDDOUtility.h"
#include "nHuman.h"
#include "nHumanMsg.h"
#include "nJobParam.h"
#include "rTbl2.h"
#include "sGame.h"

// Forward declarations
class CDataCommonU32;
class CDataNormalSkillParam;
class CDataSetAcquirementParam;
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtPropertyList;
class cAbilityParam;
class cChargeEffectUID;
class cContextInstHm;
class cContextInterface;
class cOcdStatusParamRes;
class cPlActWpnBow;
namespace nJobParam { class cHumanBaseInfo; }
namespace nJobParam { class cJobInfo; }
class uHuman;
class uNpc;

// Declarations
class cContextPlayerInfo;
class rJobBaseParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class cContextPlayerInfo : public cContext
{
    // inferred: cContextInterface::setJob names cContextInstHm::mPlayerInfo.mCurrentJob_pri
    friend class cContextInterface;
    // inferred: cPlActWpnBow::finalUp_Shot names cContextPlayerInfo::mCurrentJob_pri
    friend class cPlActWpnBow;
    // inferred: uHuman::deleteHealingCircle names cContextPlayerInfo::mCurrentJob_pri
    friend class uHuman;
    // inferred: uNpc::setGripFinger names cContextPlayerInfo::mCurrentJob_pri
    friend class uNpc;
public:
    class MyDTI;
    class cAbility;
public:
    using JobInfoArray = nDDOUtility::cArray<nJobParam::cJobInfo, 10>;
    using AbilityArray = nDDOUtility::cArray<cContextPlayerInfo::cAbility, 10>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cAbility : public MtObject
    {
        // inferred: cContextPlayerInfo::resetAbility names cContextPlayerInfo::mAbilityInfoList.elems[0].mIsEnable
        friend class cContextPlayerInfo;
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
        cAbility();
        // Address: 0x01962b40 - 0x01962b41 (1 bytes)
        virtual ~cAbility() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        bool isEnable() const;
        void setEnable(bool isEnable);
        bool isUsed() const;
        void setUsed(bool isUsed);
        void clear();
        void copy(const cContextPlayerInfo::cAbility& src);
        const cAbilityParam* getAbilityParam(u32 index) const;
        u32 getAbilityParamNum() const;
    public:
        nAbility::ABILITY_ID mAbilityId;  // offset: 0x8
        s32 mLevel;  // offset: 0xc
    private:
        bool mIsEnable;  // offset: 0x10
        bool mIsUsed;  // offset: 0x11
    public:
        static MyDTI DTI;
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
    cContextPlayerInfo();
    virtual ~cContextPlayerInfo();
    virtual void reset();  // vtable slot 6
    void copyData(const cContextPlayerInfo&);
    u8 getJob() const;
    const nJobParam::cJobInfo& getJobInfo(u32 JobNo) const;
    const nJobParam::cHumanBaseInfo& getBaseInfo() const;
    const nJobParam::cJobInfo& getFinalJobInfo(u32 jobNo) const;
    void setJob(u8 job);
    u16 getLevel() const;
    u16 getLevelJob(u8 job) const;
    void setJobInfo(u32 JobNo, const nJobParam::cJobInfo& Info);
    void setBaseInfo(const nJobParam::cHumanBaseInfo& info);
    void addExp(nHuman::JOB_ENUM jobNo, u64 exp, bool ui);
    void setExp(nHuman::JOB_ENUM jobNo, u64 exp, u64 addExp, u64 extraExp, bool ui);
    u64 getExp(nHuman::JOB_ENUM jobNo) const;
    void setJobPoint(nHuman::JOB_ENUM jobNo, u64 jp);
    void initHp();
    void initStamina();
    void initLostPower();
private:
    void addMaxHP(f32 addHP, nHuman::JOB_ENUM jobNo);
    void addMaxStamina(f32 addStamina, nHuman::JOB_ENUM jobNo);
public:
    void addStamina(f32 add);
    void setStamina(f32 stamina);
    bool isStaminaEmpty() const;
    void subLostNum();
    void setHP(f32 hp, bool isWriteContext);
    f32 getHP() const;
    f32 getMaxHP() const;
    f32 getFinalMaxHP() const;
    f32 getFinalMaxHPCheatCheck() const;
    f32 getContextHP() const;
    void setContextHP(f32 hp);
    f32 getContextWhiteHP() const;
    void setContextWhiteHP(f32 hp);
    bool checkDying() const;
    f32 getStamina() const;
    f32 getMaxStamina() const;
    f32 getFinalMaxStamina() const;
    u32 getLostPower() const;
    u32 getMaxLostPower() const;
    u32 getLostNum() const;
    u32 getMaxLostNum() const;
    void recoverAll();
    void recoverHP();
    void recoverHarfStamina();
    void recoverStamina();
    void recoverLostNum();
    void recoverBadStatus();
    void recoverBadStatusInLobby();
    void recoverOcdPlayStartContents();
    void recoverBadStatusInSafeArea();
    bool setAbility(nAbility::ABILITY_ID id, s32 lv, nAbility::ABILITY_SLOT slot);
    bool setAbilityNotCalcStatus(nAbility::ABILITY_ID id, s32 lv, nAbility::ABILITY_SLOT slot);
    void setReceiveAbility(CDataSetAcquirementParam* pAbility);
    void setAbilityLevelUp(nAbility::ABILITY_ID id, s32 lv);
    bool getAbility(nAbility::ABILITY_SLOT slot, nAbility::ABILITY_ID& id, s32& lv) const;
    bool removeAbility(nAbility::ABILITY_SLOT slot);
    bool checkAbility(nAbility::ABILITY_ID id, s32& lv, s32& val, u32 index) const;
    bool isUsedAbilitySlot(nAbility::ABILITY_SLOT slot) const;
    void setEnableAbilitySlot(nAbility::ABILITY_SLOT slot, bool isEnable);
    bool isEnableAbilitySlot(nAbility::ABILITY_SLOT slot) const;
    void resetAbility();
    s32 getAbilityParamNum(nAbility::ABILITY_ID id) const;
    s32 getAbilityParamType(nAbility::ABILITY_ID id, u32 index) const;
    const cAbilityParam* checkOwnerAbility(nAbility::ABILITY_ID id, s32* level);
    void setOwner(uHuman* powner);
    uHuman* getOwner() const;
    void levelUpJobParam2(nJobParam::cJobInfo& job, u32 jobNo);
    void applyAbility(const cAbilityParam* pAbilityParam, s32 abilityLv, f32& addHP, f32& addStamina, nJobParam::cJobInfo& addJobInfo, u32 jobNo);
    bool checkValidAbility(const nAbility::ABILITY_ID AbilityId);
    void updateAbility();
    void setContextCalcParam();
    void calcStatus(u32 jobNo);
    void setOwnerContext(cContextInstHm* pInst);
    cContextInstHm* getOwnerContext() const;
    static u32 getNeedExp(u32 level);
    void setJobLevel(u16 lv, u32 jobNo);
    void setChargeEffect(const MtTypedArray<CDataCommonU32>& list);
    void copyChargeEffect(const cContextPlayerInfo* pOwnerContext);
    bool isOcdActive(u32 OcdUID) const;
private:
    const cOcdStatusParamRes* getOcdStatusParamRes(u32 OcdUID) const;
    void calcEquipStatus(nJobParam::cJobInfo& addJobInfo, u32 jobNo);
    void calcGoodStatus(nJobParam::cJobInfo& addJobInfo, u32 jobNo);
    void calcBadStatus(nJobParam::cJobInfo& addJobInfo, u32 jobNo);
    void clearRefChargeEffect();
    bool checkAbilityEquip(nAbility::ABILITY_ID id, s32& lv) const;
    const cAbilityParam* getAbilityParam(nAbility::ABILITY_ID id, u32 index) const;
    void makeFinalAbilityList(AbilityArray& dstList);
    void applyEquipAbilityList(const AbilityArray& finalAbilityList);
public:
    u8 getCurrentJob() const;
    void setCurrentJob(u8 NewValue);
private:
    nHuman::HM_SKILL_LV getCustomSkillLv(u32 index0, u32 index1) const;
    void setCustomSkillLv(nHuman::HM_SKILL_LV NewValue, u32 index0, u32 index1);
    nHuman::HM_SKILL_LV getNormalSkillLv(u32 index0, u32 index1) const;
    void setNormalSkillLv(nHuman::HM_SKILL_LV NewValue, u32 index0, u32 index1);
public:
    f32 getWeakHpMax() const;
    void setWeakHpMax(f32 NewValue);
    f32 getNoBadHpMax() const;
    void setNoBadHpMax(f32 NewValue);
    nHuman::HM_SKILL_LV getCustomSkillLv(const nHuman::CUSTOM_SKILL_ENUM id) const;
    nHuman::HM_SKILL_LV getCustomSkillLvJob(const nHuman::JOB_ENUM job, const nHuman::CUSTOM_SKILL_ENUM id) const;
    void setReceiveCustomSkill(CDataSetAcquirementParam* pSkill, nHuman::CUSTOM_SKILL_GROUP group);
    void setReceiveCustomSkill(u8 job, u8 revid, u8 revlv, u8 slot, nHuman::CUSTOM_SKILL_GROUP group);
    void removeReceiveCustomSkill(u8 slotNo, u8 job, nHuman::CUSTOM_SKILL_GROUP group);
    void setNowCustomSkillGroup(nHuman::CUSTOM_SKILL_GROUP group);
    nHuman::CUSTOM_SKILL_GROUP getNowCustomSkillGroup() const;
    void resetNowCustomSkillGroup();
    void setCustomSkillLv(const nHuman::CUSTOM_SKILL_ENUM id, nHuman::HM_SKILL_LV lv);
    void setCustomSkillLvJob(const nHuman::JOB_ENUM job, const nHuman::CUSTOM_SKILL_ENUM id, nHuman::HM_SKILL_LV lv);
    void resetCustomSkillLv(nHuman::JOB_ENUM job);
    void resetCustomSkillLv();
    nHuman::HM_SKILL_LV getNormalSkillLv(const nHuman::GROW_NORMAL_SKILL_ENUM id) const;
    nHuman::HM_SKILL_LV getNormalSkillLvJob(const nHuman::JOB_ENUM job, const nHuman::GROW_NORMAL_SKILL_ENUM id) const;
    void setReceiveNormalSkillLv(CDataNormalSkillParam* pNormal);
    void setNormalSkillLv(const nHuman::GROW_NORMAL_SKILL_ENUM id, nHuman::HM_SKILL_LV lv);
    void setNormalSkillLvJob(const nHuman::JOB_ENUM job, const nHuman::GROW_NORMAL_SKILL_ENUM id, nHuman::HM_SKILL_LV lv);
    void resetNormalSkillLv(const nHuman::JOB_ENUM job);
    void resetNormalSkillLv();
    void setCustomSkillPalletL(const nHuman::CUSTOM_SKILL_ENUM id, nHuman::CUSTOM_SKILL_PALLET index, nHuman::CUSTOM_SKILL_GROUP group);
    void setCustomSkillPalletR(const nHuman::CUSTOM_SKILL_ENUM id, nHuman::CUSTOM_SKILL_PALLET index, nHuman::CUSTOM_SKILL_GROUP group);
    void resetCustomSkillPallet();
    nHuman::CUSTOM_SKILL_ENUM getCustomSkillPalletL(nHuman::CUSTOM_SKILL_PALLET index, nHuman::CUSTOM_SKILL_GROUP group) const;
    nHuman::CUSTOM_SKILL_ENUM getCustomSkillPalletR(nHuman::CUSTOM_SKILL_PALLET index, nHuman::CUSTOM_SKILL_GROUP group) const;
    void setAbilityLevel(u32, u32);
    u32 getAbilityLevel(u32);
    void initRefChargeEffect();
    void setChargeEffectUID(u32 chargeUID, bool flag);
    u32 getRefChargeEffect(u32 index) const;
    bool isChargeEffect(nGpCourse::E_GP_COURSE_EFFECT chargeId) const;
    u32 getChargeEffectParam0(nGpCourse::E_GP_COURSE_EFFECT chargeId) const;
    u32 getChargeEffectParam1(nGpCourse::E_GP_COURSE_EFFECT chargeId) const;
    void setHumanEnemyCustomSkill(u32 preset);
    f32 getWeight() const;
    nHuman::WEIGHT_TYPE getWeightType() const;
    static nHuman::WEIGHT_TYPE getWeightType(const f32 weight);
    u32 getAttackUI() const;
    u32 getMgcAttackUI() const;
    u32 getAttackTotal() const;
    u32 getDefenseTotal() const;
    u32 getMgcAttackTotal() const;
    u32 getMgcDefenseTotal() const;
    u32 getStrengthTotal() const;
    u32 getDownPowerTotal() const;
    u32 getShakePowerTotal() const;
    u32 getStanPowerTotal() const;
    u32 getConstitutionTotal() const;
    u32 getGutsTotal() const;
    s16 getFireResistTotal() const;
    s16 getIceResistTotal() const;
    s16 getThunderResistTotal() const;
    s16 getHolyResistTotal() const;
    s16 getDarkResistTotal() const;
    s16 getSpreadResistTotal() const;
    s16 getFreezeResistTotal() const;
    s16 getShockResistTotal() const;
    s16 getAbsorbResistTotal() const;
    s16 getDarkElmResistTotal() const;
    s16 getPoisonResistTotal() const;
    s16 getSlowResistTotal() const;
    s16 getSleepResistTotal() const;
    s16 getStunResistTotal() const;
    s16 getWetResistTotal() const;
    s16 getOilResistTotal() const;
    s16 getSealResistTotal() const;
    s16 getCurseResistTotal() const;
    s16 getSoftResistTotal() const;
    s16 getStoneResistTotal() const;
    s16 getGoldResistTotal() const;
    s16 getFireReduceResistTotal() const;
    s16 getIceReduceResistTotal() const;
    s16 getThunderReduceResistTotal() const;
    s16 getHolyReduceResistTotal() const;
    s16 getDarkReduceResistTotal() const;
    s16 getAtkDownResistTotal() const;
    s16 getDefDownResistTotal() const;
    s16 getMAtkDownResistTotal() const;
    s16 getMDefDownResistTotal() const;
    s16 getErosionResistTotal() const;
    s16 getItemSealResistTotal() const;
    u32 getShieldStaggerTotal() const;
    bool isSafeJobCheck(nHuman::JOB_ENUM job) const;
    bool isSafeJobCheck(u8 checkJob) const;
private:
    uHuman* mpOwner;  // offset: 0x20
    u8 mCurrentJob_pri;  // offset: 0x28
public:
    nJobParam::cHumanBaseInfo mBaseInfo;  // offset: 0x30
    JobInfoArray mJobInfoList;  // offset: 0x88
    JobInfoArray mFinalJobInfoList;  // offset: 0x4e8
    nHuman::HM_SKILL_LV mCustomSkillLv_pri[10][20];  // offset: 0x948
private:
    nHuman::HM_SKILL_LV mNormalSkillLv_pri[10][10];  // offset: 0xc68
    nHuman::CUSTOM_SKILL_ENUM mCustomSkillPalletL[2][2];  // offset: 0xdf8
    nHuman::CUSTOM_SKILL_ENUM mCustomSkillPalletR[2][2];  // offset: 0xe08
    nHuman::CUSTOM_SKILL_GROUP mCurrentSkillPallet;  // offset: 0xe18
    AbilityArray mAbilityInfoList;  // offset: 0xe20
    u32 mAbilityLevelList[471];  // offset: 0xf10
    cChargeEffectUID mChargeEffectUID;  // offset: 0x1670
    cContextInstHm* mpOwnerContext;  // offset: 0x1688
    f32 mWeakHpMax_pri;  // offset: 0x1690
    f32 mNoBadHpMax_pri;  // offset: 0x1694
public:
    static MyDTI DTI;
    static const u32 DEFAULT_LOST_POWER = 15;
    static const u32 PAWN_LOST_POWER = 45;
    static const u32 NPC_LOST_POWER = 4294967295;
    static const u16 JOBBASE_DATA_VERSION = 263;
};

class rJobBaseParam : public rTbl2<nJobParam::cJobInfo>
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
    virtual bool loadData(MtDataReader& in, nJobParam::cJobInfo* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline f32 cContextPlayerInfo::getFinalMaxStamina() const {
    return this->mBaseInfo.mFinalMaxStamina_pri;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline u32 cContextPlayerInfo::getMaxLostNum() const {
    return this->mBaseInfo.mMaxLostNum_pri;
}

// Inline, no code of its own: checked where it is inlined.
inline uHuman* cContextPlayerInfo::getOwner() const {
    return this->mpOwner;
}

// Inline, no code of its own: checked where it is inlined.
inline nHuman::CUSTOM_SKILL_GROUP cContextPlayerInfo::getNowCustomSkillGroup() const {
    return this->mCurrentSkillPallet;
}

// Inline, no code of its own: checked where it is inlined.
inline cContextPlayerInfo::cAbility::cAbility() {
    this->mAbilityId = static_cast<nAbility::ABILITY_ID>(-1);
    this->mLevel = static_cast<s32>(1);
    this->mIsEnable = true;
    this->mIsUsed = false;
}
