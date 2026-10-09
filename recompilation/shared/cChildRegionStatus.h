#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "nRegionStatus.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtVector3;
class cChildRegionStatusParam;

// Declarations
class cChildRegionStatus;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cChildRegionStatus : public MtObject
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
    cChildRegionStatus();
    // Address: 0x019615e0 - 0x019615e1 (1 bytes)
    virtual ~cChildRegionStatus() {}
    void update();
    void setParamFromRes(cChildRegionStatusParam* paramRes);
public:
    u32 mNo;  // offset: 0x8
    u32 mParentNo[2];  // offset: 0xc
    f32 mAttackTolerance[4];  // offset: 0x14
    f32 mMagicTolerance[7];  // offset: 0x24
    f32 mShrinkAdj;  // offset: 0x40
    f32 mBlowAdj;  // offset: 0x44
    f32 mDownAdj;  // offset: 0x48
    f32 mOcdAdj;  // offset: 0x4c
    f32 mRageShrinkAdj;  // offset: 0x50
    f32 mShrinkDamageRatePhys[4];  // offset: 0x54
    f32 mShrinkDamageRateMagic[7];  // offset: 0x64
    f32 mBlowDamageRatePhys[4];  // offset: 0x80
    f32 mBlowDamageRateMagic[7];  // offset: 0x90
    f32 mDownDamageRatePhys[4];  // offset: 0xac
    f32 mDownDamageRateMagic[7];  // offset: 0xbc
    f32 mShakeAdjPhys[4];  // offset: 0xd8
    f32 mShakeAdjMagic[7];  // offset: 0xe8
    f32 mShakeAdjShake;  // offset: 0x104
    f32 mHitStopAdj;  // offset: 0x108
    f32 mHitSlowAdj;  // offset: 0x10c
    u32 mHitStopDefenceAttr;  // offset: 0x110
    u32 mSurface;  // offset: 0x114
    bool mIsClimbBonus;  // offset: 0x118
    bool mIsDownWeakRegion;  // offset: 0x119
    nRegionStatus::CORE_POINT_TYPE mCorePointType;  // offset: 0x11c
    s32 mCorePointID;  // offset: 0x120
    s32 mCoreJointNo;  // offset: 0x124
    MtVector3 mCoreJointOffset;  // offset: 0x130
    s32 mCoreEpvIndex;  // offset: 0x140
    s32 mCoreEpvElementNo;  // offset: 0x144
    u32 mAttackReactionType[4];  // offset: 0x148
    bool mIsElementWeakRegion[7];  // offset: 0x158
    static MyDTI DTI;
};
