#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cpComponent.h"
#include "nDDOUtility.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cpJob10;
class uDDOModel;

// Declarations
class cpChargeCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cpChargeCtrl : public cpComponent
{
    // inferred: cpJob10::canShotCs08Shl names cpChargeCtrl::mCharge_Gi[0]
    friend class cpJob10;
public:
    enum
    {
        CHGTYPE_NONE = 0,
        CHGTYPE_MAGIC = 1,
        CHGTYPE_BOW = 2,
        CHGTYPE_MAX = 3,
    };
public:
    class MyDTI;
public:
    using floatArray = nDDOUtility::cArray<float, 5>;
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
    cpChargeCtrl();
    virtual ~cpChargeCtrl();
    virtual void setup();  // vtable slot 6
    void init();
    virtual void updatePtr();  // vtable slot 9
    void update(f32 deltaTime);
    void endCharge();
    void setupChargeStart(u8 maxLevel, bool flg, u8 uChgType);
    void setChargeParm(u8 level, f32 chargeMax, f32 chargeSpeed, f32 justTimeMax);
    void requestChargeStart();
    void requestChargeStop();
    void requestChargePose();
    void restartChargePose();
    bool isChargePose() const;
    bool checkUseOutlineJob();
    void requestChargeMaxSoon();
    f32 getChargeSpeed(u8 level) const;
    void setChargeSpeed(f32 chargeSpeed, u8 level);
    void addChargeSpeed(f32, u8);
    bool isChargeComplete() const;
    f32 getChargeSpeedHosei();
    void setMgcShortChargeHosei(f32 hosei);
    void setPysShortChargeHosei(f32 hosei);
    f32 getChargeRate(u8 level) const;
    f32 getCharge(u8 level) const;
    bool isCharging();
    f32 getChargeMax(u8) const;
    bool cheackJust();
    f32 getMinJustTime();
    f32 getMaxJustTime();
    u8 getNowChargeLevel() const;
    u8 getMaxChargeLevel() const;
    u8 getChargeType() const;
    bool getIsEnableGage();
    bool getIsGoingNextLevel();
    void chargeCut(f32 bairitu);
    f32 getChargeMax_Gi(u32 index) const;
    void setChargeMax_Gi(f32 NewValue, u32 index);
    f32 getChargeSpeed_Gi(u32 index) const;
    void setChargeSpeed_Gi(f32 NewValue, u32 index);
    f32 getCharge_Gi(u32 index) const;
    void setCharge_Gi(f32 NewValue, u32 index);
    void setIsJust(bool flg);
    bool getIsJust();
    void chargeReset();
private:
    bool mIsGoingNextLevel;  // offset: 0x50
    bool mIsCharging;  // offset: 0x51
    bool mIsPoseCharge;  // offset: 0x52
    f32 mChargeMax_Gi[5];  // offset: 0x54
    f32 mChargeSpeed_Gi[5];  // offset: 0x68
    f32 mCharge_Gi[5];  // offset: 0x7c
public:
    f32 mJustCheck;  // offset: 0x90
    floatArray mJustTimeMax;  // offset: 0x94
    u8 mMaxChargeLevel;  // offset: 0xa8
    u8 mNowChargeLevel;  // offset: 0xa9
    u8 mChargeType;  // offset: 0xaa
    f32 mMgcShortChargeHosei;  // offset: 0xac
    f32 mPysShortChargeHosei;  // offset: 0xb0
    uDDOModel* mpModel;  // offset: 0xb8
    bool mIsEnableGage;  // offset: 0xc0
    bool mIsJust;  // offset: 0xc1
    static MyDTI DTI;
    static const s16 JUST_RELEASE_TIME = 7;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline void cpChargeCtrl::init() {
    this->mIsGoingNextLevel = false;
    this->mIsCharging = false;
    this->mIsPoseCharge = false;
    this->mCharge_Gi[4] = 0.0f;
    this->mCharge_Gi[2] = 0.0f;
    this->mCharge_Gi[3] = 0.0f;
    this->mCharge_Gi[0] = 0.0f;
    this->mCharge_Gi[1] = 0.0f;
    this->mChargeSpeed_Gi[3] = 0.0f;
    this->mChargeSpeed_Gi[4] = 0.0f;
    this->mChargeSpeed_Gi[1] = 0.0f;
    this->mChargeSpeed_Gi[2] = 0.0f;
    this->mChargeMax_Gi[4] = 0.0f;
    this->mChargeSpeed_Gi[0] = 0.0f;
    this->mChargeMax_Gi[2] = 0.0f;
    this->mChargeMax_Gi[3] = 0.0f;
    this->mChargeMax_Gi[0] = 0.0f;
    this->mChargeMax_Gi[1] = 0.0f;
    this->mJustTimeMax.elems[4] = 0.0f;
    this->mJustTimeMax.elems[2] = 0.0f;
    this->mJustTimeMax.elems[3] = 0.0f;
    this->mJustTimeMax.elems[0] = 0.0f;
    this->mJustTimeMax.elems[1] = 0.0f;
    this->mMgcShortChargeHosei = 1.0f;
    this->mPysShortChargeHosei = 1.0f;
    this->mJustCheck = 7.0f;
    this->mMaxChargeLevel = static_cast<u8>(1);
    this->mNowChargeLevel = static_cast<u8>(0);
    this->mChargeType = static_cast<u8>(0);
}
