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
class cEnemyBloodStain;
class rEnemyBloodStain;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cEnemyBloodStain : public MtObject
{
public:
    enum
    {
        DATA_VERSION = 1,
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
    cEnemyBloodStain();
    // Address: 0x01a8a500 - 0x01a8a501 (1 bytes)
    virtual ~cEnemyBloodStain() {}
public:
    s32 mBloodStainType;  // offset: 0x8
    f32 mHpRateLv1;  // offset: 0xc
    f32 mHpRateLv2;  // offset: 0x10
    f32 mHpRateLv3;  // offset: 0x14
    s32 mRegionNoLv1;  // offset: 0x18
    s32 mRegionNoLv2;  // offset: 0x1c
    s32 mRegionNoLv3;  // offset: 0x20
    static MyDTI DTI;
};

class rEnemyBloodStain : public rTbl2<cEnemyBloodStain>
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
    virtual bool loadData(MtDataReader& r, cEnemyBloodStain* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cEnemyBloodStain::cEnemyBloodStain() {
    this->mBloodStainType = static_cast<s32>(0);
    this->mHpRateLv1 = 0.7f;
    this->mHpRateLv2 = 0.5f;
    this->mHpRateLv3 = 0.3f;
    this->mRegionNoLv1 = static_cast<s32>(11);
    this->mRegionNoLv2 = static_cast<s32>(11);
    this->mRegionNoLv3 = static_cast<s32>(11);
}
