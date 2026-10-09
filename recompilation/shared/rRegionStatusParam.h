#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtVector3;
class rRegionBreakInfo;

// Declarations
class cChildRegionStatusParam;
class cChildRegionStatusParamList;
class cParentRegionStatusParam;
class rChildRegionStatusParam;
class rChildRegionStatusParamList;
class rParentRegionStatusParam;

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using u64 = __uint64_t;
using HP_DATATYPE = u64;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cChildRegionStatusParam : public MtObject
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
    cChildRegionStatusParam();
    // Address: 0x01ab02a0 - 0x01ab02a1 (1 bytes)
    virtual ~cChildRegionStatusParam() {}
public:
    u32 mNo;  // offset: 0x8
    u32 mParentNo[2];  // offset: 0xc
    f32 mAttackTolerance[4];  // offset: 0x14
    f32 mMagicTolerance[7];  // offset: 0x24
    f32 mShrinkAdj;  // offset: 0x40
    f32 mBlowAdj;  // offset: 0x44
    f32 mDownAdj;  // offset: 0x48
    f32 mShrinkDamageRatePhys[4];  // offset: 0x4c
    f32 mShrinkDamageRateMagic[7];  // offset: 0x5c
    f32 mBlowDamageRatePhys[4];  // offset: 0x78
    f32 mBlowDamageRateMagic[7];  // offset: 0x88
    f32 mDownDamageRatePhys[4];  // offset: 0xa4
    f32 mDownDamageRateMagic[7];  // offset: 0xb4
    f32 mRageShrinkAdj;  // offset: 0xd0
    f32 mOcdAdj;  // offset: 0xd4
    f32 mShakeAdjPhys[4];  // offset: 0xd8
    f32 mShakeAdjMagic[7];  // offset: 0xe8
    f32 mShakeAdjShake;  // offset: 0x104
    f32 mHitStopAdj;  // offset: 0x108
    f32 mHitSlowAdj;  // offset: 0x10c
    u32 mHitStopDefenceAttr;  // offset: 0x110
    u32 mCorePointType;  // offset: 0x114
    s32 mCorePointID;  // offset: 0x118
    s32 mCoreJointNo;  // offset: 0x11c
    MtVector3 mCoreJointOffset;  // offset: 0x120
    s32 mCoreEpvIndex;  // offset: 0x130
    s32 mCoreEpvElementNo;  // offset: 0x134
    u32 mSurface;  // offset: 0x138
    bool mIsClimbBonus;  // offset: 0x13c
    bool mIsDownWeakRegion;  // offset: 0x13d
    u32 mAttackReactionType[4];  // offset: 0x140
    bool mIsElementWeakRegion[7];  // offset: 0x150
    static MyDTI DTI;
};

class cChildRegionStatusParamList : public MtObject
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
    cChildRegionStatusParamList();
    virtual ~cChildRegionStatusParamList();
public:
    u32 mStatusNo;  // offset: 0x8
    u32 mStatusType;  // offset: 0xc
    s32 mStatusPrio;  // offset: 0x10
    rChildRegionStatusParam* mpChildRegion;  // offset: 0x18
    static MyDTI DTI;
};

class cParentRegionStatusParam : public MtObject
{
public:
    enum INTEGER_DIGIT
    {
        DIGIT_ZERO = 0,
        DIGIT_MAN = 1,
        DIGIT_OKU = 2,
        DIGIT_THOU = 3,
        DIGIT_KEI = 4,
        DIGITNUM = 5,
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
    cParentRegionStatusParam();
    virtual ~cParentRegionStatusParam();
private:
    u64 getHpMaxFromHpEdit() const;
public:
    u32 mNo;  // offset: 0x8
    u32 mRegionCategory;  // offset: 0xc
    bool mIsReGenerate;  // offset: 0x10
    u32 mRegenerateProprirty;  // offset: 0x14
    HP_DATATYPE mHpMax;  // offset: 0x18
    f32 mShPMax;  // offset: 0x20
    f32 mShPSpeed;  // offset: 0x24
    f32 mShPResetTimerMax;  // offset: 0x28
    f32 mBlPMax;  // offset: 0x2c
    f32 mBlPSpeed;  // offset: 0x30
    f32 mBlResetTimerMax;  // offset: 0x34
    f32 mDownPMax;  // offset: 0x38
    f32 mDownPSpeed;  // offset: 0x3c
    f32 mDownPResetTimerMax;  // offset: 0x40
    f32 mShakePMax;  // offset: 0x44
    f32 mShakePSpeed;  // offset: 0x48
    f32 mShakeResetTimerMax;  // offset: 0x4c
    f32 mRageShrinkMax;  // offset: 0x50
    bool mIsDamageToMain;  // offset: 0x54
    u32 mBreakReactionNo;  // offset: 0x58
    rRegionBreakInfo* mpBreakInfo;  // offset: 0x60
private:
    u32 mHPForEdit[5];  // offset: 0x68
public:
    static MyDTI DTI;
private:
    static const u32 HP_MAX_KEI = 1843;
};

class rChildRegionStatusParam : public rTbl2<cChildRegionStatusParam>
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
    virtual bool loadData(MtDataReader& in, cChildRegionStatusParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rChildRegionStatusParamList : public rTbl2<cChildRegionStatusParamList>
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
    virtual bool loadData(MtDataReader& in, cChildRegionStatusParamList* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rParentRegionStatusParam : public rTbl2<cParentRegionStatusParam>
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
    virtual bool loadData(MtDataReader& in, cParentRegionStatusParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};
