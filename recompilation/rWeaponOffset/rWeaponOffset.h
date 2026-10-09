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
class MtObject;
class MtVector3;

// Declarations
class cWeaponOffset;
class rWeaponOffset;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cWeaponOffset : public MtObject
{
public:
    enum
    {
        DATA_VERSION = 3,
    };
    enum
    {
        CONST_OFFSET = 0,
        CONST_SKIN = 1,
        CONST_NUM = 2,
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
    cWeaponOffset();
    // Address: 0x01ab8a30 - 0x01ab8a31 (1 bytes)
    virtual ~cWeaponOffset() {}
public:
    u32 mConstType;  // offset: 0x8
    s32 mJntNo;  // offset: 0xc
    MtVector3 mRot;  // offset: 0x10
    MtVector3 mOfs;  // offset: 0x20
    f32 mFat;  // offset: 0x30
    s32 mJntNoHold;  // offset: 0x34
    MtVector3 mRotHold;  // offset: 0x40
    MtVector3 mOfsHold;  // offset: 0x50
    f32 mFatHold;  // offset: 0x60
    s32 mJntNoDamage;  // offset: 0x64
    MtVector3 mRotDamage;  // offset: 0x70
    MtVector3 mOfsDamage;  // offset: 0x80
    f32 mFatDamage;  // offset: 0x90
    s32 mJntNoSpecial;  // offset: 0x94
    MtVector3 mRotSpecial;  // offset: 0xa0
    MtVector3 mOfsSpecial;  // offset: 0xb0
    f32 mFatSpecial;  // offset: 0xc0
    static MyDTI DTI;
};

class rWeaponOffset : public rTbl2<cWeaponOffset>
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
    virtual bool loadData(MtDataReader& r, cWeaponOffset* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};
