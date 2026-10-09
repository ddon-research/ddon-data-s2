#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtMatrix;
class MtObject;
class MtPropertyList;

// Declarations
class cMagicChantParam;
class rMagicChantParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cMagicChantParam : public MtObject
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
    cMagicChantParam();
    cMagicChantParam(const cMagicChantParam&);
    // Address: 0x01a9baa0 - 0x01a9baa1 (1 bytes)
    virtual ~cMagicChantParam() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    f32 getChantTime() const;
    void setChantTime(f32 NewValue);
    f32 getChant2Time() const;
    void setChant2Time(f32 NewValue);
    f32 getCustomChantTime(u32 index) const;
    void setCustomChantTime(f32 NewValue, u32 index);
public:
    u32 mChantMot;  // offset: 0x8
    f32 mChantTime_Gi;  // offset: 0xc
    u32 mEndType;  // offset: 0x10
    bool mIsChant2;  // offset: 0x14
    u32 mChant2Mot;  // offset: 0x18
    f32 mChant2Time_Gi;  // offset: 0x1c
    bool mIsSetCustomChantTime;  // offset: 0x20
    f32 mCustomChantTime_Gi[10];  // offset: 0x24
    u32 mSetType;  // offset: 0x4c
    bool mIsConst;  // offset: 0x50
    s32 mJointNo;  // offset: 0x54
    MtMatrix mShotPosOffset;  // offset: 0x60
    MtMatrix mNoneLockOnPos;  // offset: 0xa0
    MtMatrix mNoneLockOnPosNext;  // offset: 0xe0
    u32 mShotOption;  // offset: 0x120
    u32 mShotMot;  // offset: 0x124
    bool mIsMotLoop;  // offset: 0x128
    f32 mShotLoopingTime;  // offset: 0x12c
    bool mIsUseShotLimitXAngle;  // offset: 0x130
    f32 mShotLimitXAngle;  // offset: 0x134
    u32 mEndMotion;  // offset: 0x138
    u32 mChantCameraNumber;  // offset: 0x13c
    u32 mShotCameraNumber;  // offset: 0x140
    u32 mEndCameraNumber;  // offset: 0x144
    f32 mShlBornFrame;  // offset: 0x148
    u32 mShlGroupNumber;  // offset: 0x14c
    u32 mShlIndexNumber;  // offset: 0x150
    u32 mShlGroupNumberNext;  // offset: 0x154
    u32 mShlIndexNumberNext;  // offset: 0x158
    bool mIsCanMove;  // offset: 0x15c
    u32 mChantAttribute;  // offset: 0x160
    bool mIsUseChantCommand;  // offset: 0x164
    s32 mChantCommandLevel;  // offset: 0x168
    s32 mMagocCommandNo;  // offset: 0x16c
    bool mIsUseAutoRock;  // offset: 0x170
    f32 mAutoRockRange;  // offset: 0x174
    f32 mAutoRockAngle;  // offset: 0x178
    s32 mChant2EffectIndex;  // offset: 0x17c
    s32 mChant2EffectNumber;  // offset: 0x180
    f32 mChant2EffectFrame;  // offset: 0x184
    f32 mChant2SeFrame;  // offset: 0x188
    bool mIsAimTargetSpot;  // offset: 0x18c
    f32 mAimTargetSpotMaxRange;  // offset: 0x190
    f32 mAimTargetSpotMinRange;  // offset: 0x194
    bool mIsNoChantSe;  // offset: 0x198
    f32 mAddHealHate;  // offset: 0x19c
    static MyDTI DTI;
    static const u16 DATA_VERSION = 17;
};

class rMagicChantParam : public rTbl2<cMagicChantParam>
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
    virtual bool loadData(MtDataReader& in, cMagicChantParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    static MyDTI DTI;
};
