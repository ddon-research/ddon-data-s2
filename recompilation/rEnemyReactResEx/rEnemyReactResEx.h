#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/rTbl2.h"

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
    // Address: 0x01a8be20 - 0x01a8be21 (1 bytes)
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

// Inline, no code of its own: checked where it is inlined.
inline cEnemyReactRes::cEnemyReactRes() {
    this->mParam1 = static_cast<s32>(0);
    this->mPercent = 0.0f;
    this->mParam0 = static_cast<s32>(0);
    this->mCountStart = static_cast<u32>(0);
    this->mCountEnd = static_cast<u32>(0);
}
