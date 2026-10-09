#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "nHuman.h"

// Forward declarations
class BitReader;
class BitWriter;
class MtAllocator;
class MtDTI;
class MtPropertyList;

// Declarations
namespace nJobParam { class cHumanBaseInfo; }
namespace nJobParam { class cJobInfo; }

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

namespace nJobParam {
    class cHumanBaseInfo : public ::MtObject
    {
    public:
        enum
        {
            HP_INIT = 0,
            HP_LVUP_ADD = 1,
            STM_INIT = 2,
            STM_LVUP_ADD = 3,
            LOST_INIT = 4,
            LOST_LVUP_ADD = 5,
        };
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cHumanBaseInfo();
        virtual ~cHumanBaseInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        f32 getHP() const;
        void setHP(f32 NewValue);
        f32 getMaxHP() const;
        void setMaxHP(f32 NewValue);
        void setFinalMaxHP(f32 hp);
        f32 getFinalMaxHP() const;
        f32 getFinalMaxHPCheatCheck() const;
    private:
        f32 getFinalMaxHPPrivate() const;
        void setFinalMaxHPPrivate(f32 NewValue);
        u32 getFinalMaxHPCheatCheckPrivate() const;
        void setFinalMaxHPCheatCheckPrivate(u32 NewValue);
    public:
        f32 getLogInHpWhite() const;
        void setLogInHpWhite(f32 NewValue);
        f32 getStamina() const;
        void setStamina(f32 NewValue);
        f32 getMaxStamina() const;
        void setMaxStamina(f32 NewValue);
        f32 getFinalMaxStamina() const;
        void setFinalMaxStamina(f32 NewValue);
        u32 getLostPower() const;
        void setLostPower(u32 NewValue);
        u16 getLostLv() const;
        void setLostLv(u16 NewValue);
        s32 getAbilityCapacity() const;
        void setAbilityCapacity(s32 NewValue);
        u16 getAbilityCapaLv() const;
        void setAbilityCapaLv(u16 NewValue);
        u32 getLostNum() const;
        void setLostNum(u32 NewValue);
        u32 getMaxLostNum() const;
        void setMaxLostNum(u32 NewValue);
        f32 getGainHp() const;
        void setGainHp(f32 NewValue);
        f32 getGainStamina() const;
        void setGainStamina(f32 NewValue);
        u32 getGainAtk() const;
        void setGainAtk(u32 NewValue);
        u32 getGainDef() const;
        void setGainDef(u32 NewValue);
        u32 getGainMAtk() const;
        void setGainMAtk(u32 NewValue);
        u32 getGainMDef() const;
        void setGainMDef(u32 NewValue);
        bool serialize(BitWriter& w) const;
        bool deserialize(BitReader& r, u32 version);
        void copyData(const nJobParam::cHumanBaseInfo& src);
        void init();
        void initHp();
        void initStamina();
        void initLostPower();
    private:
        void setFinalMaxHPCheatCheck(f32 hp);
    public:
        f32 mHP_pri;  // offset: 0x8
        f32 mMaxHP_pri;  // offset: 0xc
        f32 mFinalMaxHP_pri;  // offset: 0x10
    private:
        u32 mFinalMaxHPCheatCheck_pri;  // offset: 0x14
        f32 mLogInHpWhite_pri;  // offset: 0x18
    public:
        f32 mStamina_pri;  // offset: 0x1c
        f32 mMaxStamina_pri;  // offset: 0x20
        f32 mFinalMaxStamina_pri;  // offset: 0x24
        u32 mLostPower_pri;  // offset: 0x28
        u16 mLostLv_pri;  // offset: 0x2c
        s32 mAbilityCapacity_pri;  // offset: 0x30
        u16 mAbilityCapaLv_pri;  // offset: 0x34
        u32 mLostNum_pri;  // offset: 0x38
        u32 mMaxLostNum_pri;  // offset: 0x3c
        f32 mGainHp_pri;  // offset: 0x40
        f32 mGainStamina_pri;  // offset: 0x44
        u32 mGainAtk_pri;  // offset: 0x48
        u32 mGainDef_pri;  // offset: 0x4c
        u32 mGainMAtk_pri;  // offset: 0x50
        u32 mGainMDef_pri;  // offset: 0x54
        static MyDTI DTI;
    };
}  // namespace nJobParam

namespace nJobParam {
    class cJobInfo : public ::MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
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
        cJobInfo();
        nJobParam::cJobInfo operator+(const nJobParam::cJobInfo& src);
        u16 getLv() const;
        void setLv(u16 NewValue);
        u64 getExp() const;
        void setExp(u64 NewValue);
        u32 getAtk() const;
        void setAtk(u32 NewValue);
        u32 getDef() const;
        void setDef(u32 NewValue);
        u32 getMAtk() const;
        void setMAtk(u32 NewValue);
        u32 getMDef() const;
        void setMDef(u32 NewValue);
        u32 getStrength() const;
        void setStrength(u32 NewValue);
        u32 getDownPower() const;
        void setDownPower(u32 NewValue);
        u32 getShakePower() const;
        void setShakePower(u32 NewValue);
        u32 getStanPower() const;
        void setStanPower(u32 NewValue);
        u32 getConstitution() const;
        void setConstitution(u32 NewValue);
        u32 getGuts() const;
        void setGuts(u32 NewValue);
        u64 getJobPoint() const;
        void setJobPoint(u64 NewValue);
        s16 getFireResist() const;
        void setFireResist(s16 NewValue);
        s16 getIceResist() const;
        void setIceResist(s16 NewValue);
        s16 getThunderResist() const;
        void setThunderResist(s16 NewValue);
        s16 getHolyResist() const;
        void setHolyResist(s16 NewValue);
        s16 getDarkResist() const;
        void setDarkResist(s16 NewValue);
        u8 getSpreadResist() const;
        void setSpreadResist(u8 NewValue);
        u8 getFreezeResist() const;
        void setFreezeResist(u8 NewValue);
        u8 getShockResist() const;
        void setShockResist(u8 NewValue);
        u8 getAbsorbResist() const;
        void setAbsorbResist(u8 NewValue);
        u8 getDarkElmResist() const;
        void setDarkElmResist(u8 NewValue);
        u8 getPoisonResist() const;
        void setPoisonResist(u8 NewValue);
        u8 getSlowResist() const;
        void setSlowResist(u8 NewValue);
        u8 getSleepResist() const;
        void setSleepResist(u8 NewValue);
        u8 getStunResist() const;
        void setStunResist(u8 NewValue);
        u8 getWetResist() const;
        void setWetResist(u8 NewValue);
        u8 getOilResist() const;
        void setOilResist(u8 NewValue);
        u8 getSealResist() const;
        void setSealResist(u8 NewValue);
        u8 getCurseResist() const;
        void setCurseResist(u8 NewValue);
        u8 getSoftResist() const;
        void setSoftResist(u8 NewValue);
        u8 getStoneResist() const;
        void setStoneResist(u8 NewValue);
        u8 getGoldResist() const;
        void setGoldResist(u8 NewValue);
        u8 getFireReduceResist() const;
        void setFireReduceResist(u8 NewValue);
        u8 getIceReduceResist() const;
        void setIceReduceResist(u8 NewValue);
        u8 getThunderReduceResist() const;
        void setThunderReduceResist(u8 NewValue);
        u8 getHolyReduceResist() const;
        void setHolyReduceResist(u8 NewValue);
        u8 getDarkReduceResist() const;
        void setDarkReduceResist(u8 NewValue);
        u8 getAtkDownResist() const;
        void setAtkDownResist(u8 NewValue);
        u8 getDefDownResist() const;
        void setDefDownResist(u8 NewValue);
        u8 getMAtkDownResist() const;
        void setMAtkDownResist(u8 NewValue);
        u8 getMDefDownResist() const;
        void setMDefDownResist(u8 NewValue);
        u8 getErosionResist() const;
        void setErosionResist(u8 NewValue);
        u8 getItemSealResist() const;
        void setItemSealResist(u8 NewValue);
        bool serialize(BitWriter& w) const;
        bool deserialize(BitReader& r, u32 version);
        void copyData(const nJobParam::cJobInfo& src);
        void initJobStatus(nHuman::JOB_ENUM job);
        bool isSetParam() const;
    public:
        u16 mLv_pri;  // offset: 0x8
        u64 mExp_pri;  // offset: 0x10
        u32 mAtk_pri;  // offset: 0x18
        u32 mDef_pri;  // offset: 0x1c
        u32 mMAtk_pri;  // offset: 0x20
        u32 mMDef_pri;  // offset: 0x24
        u32 mStrength_pri;  // offset: 0x28
        u32 mDownPower_pri;  // offset: 0x2c
        u32 mShakePower_pri;  // offset: 0x30
        u32 mStanPower_pri;  // offset: 0x34
        u32 mConstitution_pri;  // offset: 0x38
        u32 mGuts_pri;  // offset: 0x3c
        u64 mJobPoint_pri;  // offset: 0x40
        s16 mFireResist_pri;  // offset: 0x48
        s16 mIceResist_pri;  // offset: 0x4a
        s16 mThunderResist_pri;  // offset: 0x4c
        s16 mHolyResist_pri;  // offset: 0x4e
        s16 mDarkResist_pri;  // offset: 0x50
        u8 mSpreadResist_pri;  // offset: 0x52
        u8 mFreezeResist_pri;  // offset: 0x53
        u8 mShockResist_pri;  // offset: 0x54
        u8 mAbsorbResist_pri;  // offset: 0x55
        u8 mDarkElmResist_pri;  // offset: 0x56
        u8 mPoisonResist_pri;  // offset: 0x57
        u8 mSlowResist_pri;  // offset: 0x58
        u8 mSleepResist_pri;  // offset: 0x59
        u8 mStunResist_pri;  // offset: 0x5a
        u8 mWetResist_pri;  // offset: 0x5b
        u8 mOilResist_pri;  // offset: 0x5c
        u8 mSealResist_pri;  // offset: 0x5d
        u8 mCurseResist_pri;  // offset: 0x5e
        u8 mSoftResist_pri;  // offset: 0x5f
        u8 mStoneResist_pri;  // offset: 0x60
        u8 mGoldResist_pri;  // offset: 0x61
        u8 mFireReduceResist_pri;  // offset: 0x62
        u8 mIceReduceResist_pri;  // offset: 0x63
        u8 mThunderReduceResist_pri;  // offset: 0x64
        u8 mHolyReduceResist_pri;  // offset: 0x65
        u8 mDarkReduceResist_pri;  // offset: 0x66
        u8 mAtkDownResist_pri;  // offset: 0x67
        u8 mDefDownResist_pri;  // offset: 0x68
        u8 mMAtkDownResist_pri;  // offset: 0x69
        u8 mMDefDownResist_pri;  // offset: 0x6a
        u8 mErosionResist_pri;  // offset: 0x6b
        u8 mItemSealResist_pri;  // offset: 0x6c
        static MyDTI DTI;
    };
}  // namespace nJobParam

// Inline, no code of its own: checked where it is inlined.
inline nJobParam::cJobInfo::cJobInfo() {
    this->mLv_pri = static_cast<u16>(0);
    this->mItemSealResist_pri = static_cast<u8>(0);
    this->mDefDownResist_pri = static_cast<u8>(0);
    this->mMAtkDownResist_pri = static_cast<u8>(0);
    this->mMDefDownResist_pri = static_cast<u8>(0);
    this->mErosionResist_pri = static_cast<u8>(0);
    this->mStoneResist_pri = static_cast<u8>(0);
    this->mGoldResist_pri = static_cast<u8>(0);
    this->mFireReduceResist_pri = static_cast<u8>(0);
    this->mIceReduceResist_pri = static_cast<u8>(0);
    this->mThunderReduceResist_pri = static_cast<u8>(0);
    this->mHolyReduceResist_pri = static_cast<u8>(0);
    this->mDarkReduceResist_pri = static_cast<u8>(0);
    this->mAtkDownResist_pri = static_cast<u8>(0);
    this->mSlowResist_pri = static_cast<u8>(0);
    this->mSleepResist_pri = static_cast<u8>(0);
    this->mStunResist_pri = static_cast<u8>(0);
    this->mWetResist_pri = static_cast<u8>(0);
    this->mOilResist_pri = static_cast<u8>(0);
    this->mSealResist_pri = static_cast<u8>(0);
    this->mCurseResist_pri = static_cast<u8>(0);
    this->mSoftResist_pri = static_cast<u8>(0);
    this->mDarkResist_pri = static_cast<s16>(0);
    this->mSpreadResist_pri = static_cast<u8>(0);
    this->mFreezeResist_pri = static_cast<u8>(0);
    this->mShockResist_pri = static_cast<u8>(0);
    this->mAbsorbResist_pri = static_cast<u8>(0);
    this->mDarkElmResist_pri = static_cast<u8>(0);
    this->mPoisonResist_pri = static_cast<u8>(0);
    this->mFireResist_pri = static_cast<s16>(0);
    this->mIceResist_pri = static_cast<s16>(0);
    this->mThunderResist_pri = static_cast<s16>(0);
    this->mHolyResist_pri = static_cast<s16>(0);
    this->mJobPoint_pri = static_cast<u64>(0);
    this->mConstitution_pri = static_cast<u32>(0);
    this->mGuts_pri = static_cast<u32>(0);
    this->mShakePower_pri = static_cast<u32>(0);
    this->mStanPower_pri = static_cast<u32>(0);
    this->mStrength_pri = static_cast<u32>(0);
    this->mDownPower_pri = static_cast<u32>(0);
    this->mMAtk_pri = static_cast<u32>(0);
    this->mMDef_pri = static_cast<u32>(0);
    this->mAtk_pri = static_cast<u32>(0);
    this->mDef_pri = static_cast<u32>(0);
    this->mExp_pri = static_cast<u64>(0);
}
