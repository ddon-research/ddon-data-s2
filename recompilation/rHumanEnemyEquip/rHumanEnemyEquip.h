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
class cHumanEnemyEquip;
class rHumanEnemyEquip;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cHumanEnemyEquip : public MtObject
{
public:
    enum
    {
        DATA_VERSION = 3,
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
    cHumanEnemyEquip();
    // Address: 0x01a94590 - 0x01a94591 (1 bytes)
    virtual ~cHumanEnemyEquip() {}
public:
    u32 mId;  // offset: 0x8
    u32 mMainWeaponId;  // offset: 0xc
    u32 mSubWeaponId;  // offset: 0x10
    u32 mWearTopId;  // offset: 0x14
    u32 mWearBottomId;  // offset: 0x18
    u32 mHeadId;  // offset: 0x1c
    u32 mArmorId;  // offset: 0x20
    u32 mHandId;  // offset: 0x24
    u32 mLegId;  // offset: 0x28
    u32 mAccessoryId;  // offset: 0x2c
    u32 mJewelry;  // offset: 0x30
    static MyDTI DTI;
};

class rHumanEnemyEquip : public rTbl2<cHumanEnemyEquip>
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
    virtual bool loadData(MtDataReader& r, cHumanEnemyEquip* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cHumanEnemyEquip::cHumanEnemyEquip() {
    this->mJewelry = static_cast<u32>(0);
    this->mLegId = static_cast<u32>(0);
    this->mAccessoryId = static_cast<u32>(0);
    this->mArmorId = static_cast<u32>(0);
    this->mHandId = static_cast<u32>(0);
    this->mWearBottomId = static_cast<u32>(0);
    this->mHeadId = static_cast<u32>(0);
    this->mSubWeaponId = static_cast<u32>(0);
    this->mWearTopId = static_cast<u32>(0);
    this->mId = static_cast<u32>(0);
    this->mMainWeaponId = static_cast<u32>(0);
}
