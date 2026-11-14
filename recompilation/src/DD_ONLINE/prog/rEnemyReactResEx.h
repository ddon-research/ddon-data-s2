#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;

// Declarations
class cEnemyReactRes;
class rEnemyReactResEx;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class cEnemyReactRes : public MtObject
{
public:
    enum
    {
        DATA_VERSION = 6,
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
    cEnemyReactRes();
    virtual ~cEnemyReactRes() {}
public:
    u32 mCountStart;  // offset: 0x8
    u32 mCountEnd;  // offset: 0xc
    f32 mPercent;  // offset: 0x10
    s32 mParam0;  // offset: 0x14
    s32 mParam1;  // offset: 0x18
    static MyDTI DTI;
};

class rEnemyReactResEx : public rTbl2<cEnemyReactRes>
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
    rEnemyReactResEx();
    virtual ~rEnemyReactResEx();
    virtual bool loadData(MtDataReader& r, cEnemyReactRes* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    virtual bool loadCore(MtDataReader& r);  // vtable slot 21
public:
    u32 mOverallConditionsType;  // offset: 0x7c
    f32 mOverallConditions0;  // offset: 0x80
    f32 mOverallConditions1;  // offset: 0x84
    u64 mOverallConditionsBit;  // offset: 0x88
    bool mOverallConditionsBitMode;  // offset: 0x90
    bool mOverallConditionsReverse;  // offset: 0x91
    u32 mWhereType[8];  // offset: 0x94
    s32 mWhereNo[8];  // offset: 0xb4
    bool mWhereNoRev;  // offset: 0xd4
    bool mPlayTypeHP;  // offset: 0xd5
    f32 mPlayTypeHPParam[2];  // offset: 0xd8
    bool mPlayTypeHPParamReverse;  // offset: 0xe0
    u32 mPlayTypeUseSeq;  // offset: 0xe4
    u32 mPlayTypeUseSeqWorkNo;  // offset: 0xe8
    u32 mPlayTypeSeqNo;  // offset: 0xec
    u32 mPlayTypeSeqWorkNo;  // offset: 0xf0
    u32 mPlayTypeGuard;  // offset: 0xf4
    u32 mPlayTypeNamed;  // offset: 0xf8
    u32 mPlayTypeAnger;  // offset: 0xfc
    u32 mPlayTypeNanteki;  // offset: 0x100
    u32 mPlayTypeYojinoboriAttack;  // offset: 0x104
    bool mCountType[12];  // offset: 0x108
    bool mResetTypeBlow;  // offset: 0x114
    u32 mResetTypeBlowCount;  // offset: 0x118
    bool mResetTypeShrink;  // offset: 0x11c
    u32 mResetTypeShrinkCount;  // offset: 0x120
    bool mResetTypeDown;  // offset: 0x124
    u32 mResetTypeDownCount;  // offset: 0x128
    u32 mResetType;  // offset: 0x12c
    f32 mFResetParam;  // offset: 0x130
    u32 mUResetParam;  // offset: 0x134
    bool mResultThinkTable;  // offset: 0x138
    s32 mResultThinkTableNo;  // offset: 0x13c
    bool mResultThinkTableActionGet;  // offset: 0x140
    bool mResultAction;  // offset: 0x141
    u32 mResultActionNo;  // offset: 0x144
    static MyDTI DTI;
    static const u32 REACT_WHERE_NUM = 8;
};

inline void* cEnemyReactRes::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cEnemyReactRes::cEnemyReactRes() {
    this->mParam1 = 0;
    this->mPercent = 0.0f;
    this->mParam0 = 0;
    this->mCountStart = 0;
    this->mCountEnd = 0;
}

inline void* rEnemyReactResEx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void cEnemyReactRes::operator delete[](void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cEnemyReactRes::DTI)->memFree(p_addr);
}

inline void* cEnemyReactRes::operator new[](size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cEnemyReactRes::DTI)->memAlloc(sz, align, ::cEnemyReactRes::DTI.::MtDTI::getID());
}

inline void* rEnemyReactResEx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rEnemyReactResEx::DTI)->memAlloc(sz, align, ::rEnemyReactResEx::DTI.::MtDTI::getID());
}

inline rEnemyReactResEx::rEnemyReactResEx() {
    this->mOverallConditionsType = 1;
    this->mOverallConditions0 = 0.0f;
    this->mOverallConditions1 = 0.0f;
    this->mOverallConditionsBit = 0;
    this->mOverallConditionsBitMode = false;
    this->mOverallConditionsReverse = false;
    for (u32 i = 0; i < REACT_WHERE_NUM; ++i) {
        this->mWhereType[i] = 1;
        this->mWhereNo[i] = -1;
    }
    this->mWhereNoRev = false;
    this->mPlayTypeGuard = 1;
    this->mPlayTypeNamed = 1;
    this->mPlayTypeAnger = 1;
    this->mPlayTypeNanteki = 1;
    this->mPlayTypeYojinoboriAttack = 1;
    this->mPlayTypeHP = false;
    this->mPlayTypeHPParam[0] = 0.0f;
    this->mPlayTypeHPParam[1] = 0.0f;
    this->mPlayTypeHPParamReverse = false;
    this->mPlayTypeUseSeq = 3;
    this->mPlayTypeUseSeqWorkNo = 1;
    this->mPlayTypeSeqNo = 10;
    this->mPlayTypeSeqWorkNo = 0;
    this->mResetTypeBlow = false;
    this->mResetTypeBlowCount = 1;
    this->mResetTypeShrink = false;
    this->mResetTypeShrinkCount = 1;
    this->mResetTypeDown = false;
    this->mResetTypeDownCount = 1;
    this->mResetType = 1;
    this->mFResetParam = 0.0f;
    this->mUResetParam = 0;
    this->mResultThinkTable = false;
    this->mResultThinkTableNo = -1;
    this->mResultThinkTableActionGet = false;
    this->mResultAction = false;
    this->mResultActionNo = 0;
    for (u32 i = 0; i < 12; ++i) {
        this->mCountType[i] = false;
    }
}
