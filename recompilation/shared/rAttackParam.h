#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;

// Declarations
class cAttackParam;
class rAttackParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

class cAttackParam : public MtObject
{
public:
    enum
    {
        INDEX_UID = 0,
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
    cAttackParam();
    void copy(const cAttackParam& src);
    // Address: 0x01a76660 - 0x01a76661 (1 bytes)
    virtual ~cAttackParam() {}
public:
    u16 mIndex;  // offset: 0x8
    u16 mPhysAttack2;  // offset: 0xa
    f32 mPhysAttackRate;  // offset: 0xc
    u8 mAttackType2;  // offset: 0x10
    u8 mElementType2;  // offset: 0x11
    u16 mMgcAttack2;  // offset: 0x12
    f32 mWeaponBadStatusRate;  // offset: 0x14
    f32 mMgcAttackRate;  // offset: 0x18
    f32 mElement;  // offset: 0x1c
    f32 mShrinkRate;  // offset: 0x20
    u8 mShrinkType2;  // offset: 0x24
    u8 mBlowType2;  // offset: 0x25
    u8 mClimbAttackFlag2;  // offset: 0x26
    u8 mSPReactionType2;  // offset: 0x27
    f32 mBlowRate;  // offset: 0x28
    f32 mDownRate;  // offset: 0x2c
    f32 mShakesRate;  // offset: 0x30
    f32 mClimbBonusRate;  // offset: 0x34
    f32 mClimbBonusRateShrink;  // offset: 0x38
    f32 mClimbBonusRateBlow;  // offset: 0x3c
    f32 mClimbBonusRateShake;  // offset: 0x40
    f32 mClimbBonusRateDown;  // offset: 0x44
    f32 mHpUp;  // offset: 0x48
    f32 mHpUpRate;  // offset: 0x4c
    f32 mStaminaUp;  // offset: 0x50
    f32 mStaminaUpRate;  // offset: 0x54
    u8 mWindReactionLv2;  // offset: 0x58
    u8 mRangeType2;  // offset: 0x59
    u8 mGroundShrinkLv2;  // offset: 0x5a
    u8 mHitStopFlag2;  // offset: 0x5b
    f32 mWindReactionSpeedZ;  // offset: 0x5c
    f32 mWindReactionAccelerateZ;  // offset: 0x60
    f32 mWindReactionSpeedY;  // offset: 0x64
    f32 mWindReactionGravityY;  // offset: 0x68
    u16 mWork2;  // offset: 0x6c
    u16 mAttackID;  // offset: 0x6e
    f32 mHitStopTime;  // offset: 0x70
    f32 mHitSlowRate;  // offset: 0x74
    f32 mDamageAngle;  // offset: 0x78
    u32 mDamageFlag;  // offset: 0x7c
    f32 mGroundShrinkSpeedZ;  // offset: 0x80
    f32 mGroundShrinkAccelerateZ;  // offset: 0x84
    f32 mGroundShrinkSpeedY;  // offset: 0x88
    f32 mGroundShrinkGravityY;  // offset: 0x8c
    u8 mAirShrinkLv2;  // offset: 0x90
    u8 mGroundBlowLv2;  // offset: 0x91
    u8 mAirBlowLv2;  // offset: 0x92
    u8 mCatchFlag2;  // offset: 0x93
    f32 mAirShrinkSpeedZ;  // offset: 0x94
    f32 mAirShrinkAccelerateZ;  // offset: 0x98
    f32 mAirShrinkSpeedY;  // offset: 0x9c
    f32 mAirShrinkGravityY;  // offset: 0xa0
    f32 mGroundBlowSpeedZ;  // offset: 0xa4
    f32 mGroundBlowAccelerateZ;  // offset: 0xa8
    f32 mGroundBlowSpeedY;  // offset: 0xac
    f32 mGroundBlowGravityY;  // offset: 0xb0
    f32 mAirBlowSpeedZ;  // offset: 0xb4
    f32 mAirBlowAccelerateZ;  // offset: 0xb8
    f32 mAirBlowSpeedY;  // offset: 0xbc
    f32 mAirBlowGravityY;  // offset: 0xc0
    u32 mBadOcdUID_1;  // offset: 0xc4
    u32 mBadOcdUID_2;  // offset: 0xc8
    u32 mBadOcdUID_3;  // offset: 0xcc
    u32 mBadOcdUID_4;  // offset: 0xd0
    u32 mBadOcdUID_5;  // offset: 0xd4
    u32 mGoodStatusFlag;  // offset: 0xd8
    u16 mOcdEndurance_2;  // offset: 0xdc
    u16 mOcdEndurance_1;  // offset: 0xde
    u16 mOcdEndurance_3;  // offset: 0xe0
    u16 mOcdEndurance_4;  // offset: 0xe2
    u16 mOcdEndurance_5;  // offset: 0xe4
    u16 mGuardDefence2;  // offset: 0xe6
    u8 mGuardFlag2;  // offset: 0xe8
    u8 mGuardAttackerReaction2;  // offset: 0xe9
    u16 mMultiHitResetTime2;  // offset: 0xea
    u32 mGuardAngle;  // offset: 0xec
    f32 mGuardActionRate;  // offset: 0xf0
    u16 mHitCollisionFlag2;  // offset: 0xf4
    u16 mEffectFlag2;  // offset: 0xf6
    u8 mEffectType2;  // offset: 0xf8
    u8 mEffectAngle2;  // offset: 0xf9
    u8 mSeType2;  // offset: 0xfa
    u8 mSeSize2;  // offset: 0xfb
    u8 mWepCategory2;  // offset: 0xfc
    u8 mCatchType;  // offset: 0xfd
    u16 mSeFlag2;  // offset: 0xfe
    u64 mFlag3;  // offset: 0x100
    u16 mCorePointDispTime2;  // offset: 0x108
    u16 mDamageMin2;  // offset: 0x10a
    u32 mAbilityAttackFlag;  // offset: 0x10c
    u64 mBadStatusFlag2;  // offset: 0x110
    u8 mFreeBit;  // offset: 0x118
    bool mIsPhysAttackOnly;  // offset: 0x119
    bool mMultiHit;  // offset: 0x11a
private:
    u32 mFlag2;  // offset: 0x11c
public:
    static MyDTI DTI;
    static const u16 DATA_VERSION = 110;
    static const u16 DATA_VERSION_OLD_PARAM = 108;
};

class rAttackParam : public rTbl2<cAttackParam>
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
    rAttackParam();
    virtual ~rAttackParam();
    virtual bool loadData(MtDataReader& in, cAttackParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    virtual bool loadCore(MtDataReader& r);  // vtable slot 21
public:
    u32 mUParam32[4];  // offset: 0x7c
    u64 mUParam64[2];  // offset: 0x90
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline rAttackParam::rAttackParam() {
    this->mUParam32[2] = static_cast<unsigned int>(0);
    this->mUParam32[3] = static_cast<unsigned int>(0);
    this->mUParam32[0] = static_cast<unsigned int>(0);
    this->mUParam32[1] = static_cast<unsigned int>(0);
    this->mUParam64[1] = static_cast<long unsigned int>(0);
    this->mUParam64[0] = static_cast<long unsigned int>(0);
}
