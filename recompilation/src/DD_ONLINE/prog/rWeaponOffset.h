#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "rTbl2.h"

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

inline void* cWeaponOffset::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* rWeaponOffset::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void cWeaponOffset::operator delete[](void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cWeaponOffset::DTI)->memFree(p_addr);
}

inline void* cWeaponOffset::operator new[](size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cWeaponOffset::DTI)->memAlloc(sz, align, ::cWeaponOffset::DTI.::MtDTI::getID());
}

inline void* cWeaponOffset::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cWeaponOffset::DTI)->memAlloc(sz, align, ::cWeaponOffset::DTI.::MtDTI::getID());
}

inline void cWeaponOffset::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cWeaponOffset::DTI)->memFree(p_addr);
}

inline cWeaponOffset::cWeaponOffset() {
    this->mConstType = 0;
    this->mJntNo = 0;
    this->mRot.x = ::MtVector3::Zero.x;
    this->mRot.y = ::MtVector3::Zero.y;
    this->mRot.z = ::MtVector3::Zero.z;
    this->mRot.pad_ = 0.0f;
    this->mOfs.x = ::MtVector3::Zero.x;
    this->mOfs.y = ::MtVector3::Zero.y;
    this->mOfs.z = ::MtVector3::Zero.z;
    this->mOfs.pad_ = 0.0f;
    this->mFat = 1.0f;
    this->mJntNoHold = 0;
    this->mRotHold.x = ::MtVector3::Zero.x;
    this->mRotHold.y = ::MtVector3::Zero.y;
    this->mRotHold.z = ::MtVector3::Zero.z;
    this->mRotHold.pad_ = 0.0f;
    this->mOfsHold.x = ::MtVector3::Zero.x;
    this->mOfsHold.y = ::MtVector3::Zero.y;
    this->mOfsHold.z = ::MtVector3::Zero.z;
    this->mOfsHold.pad_ = 0.0f;
    this->mFatHold = 1.0f;
    this->mJntNoDamage = 0;
    this->mRotDamage.x = ::MtVector3::Zero.x;
    this->mRotDamage.y = ::MtVector3::Zero.y;
    this->mRotDamage.z = ::MtVector3::Zero.z;
    this->mRotDamage.pad_ = 0.0f;
    this->mOfsDamage.x = ::MtVector3::Zero.x;
    this->mOfsDamage.y = ::MtVector3::Zero.y;
    this->mOfsDamage.z = ::MtVector3::Zero.z;
    this->mOfsDamage.pad_ = 0.0f;
    this->mFatDamage = 1.0f;
    this->mJntNoSpecial = 0;
    this->mRotSpecial.x = ::MtVector3::Zero.x;
    this->mRotSpecial.y = ::MtVector3::Zero.y;
    this->mRotSpecial.z = ::MtVector3::Zero.z;
    this->mRotSpecial.pad_ = 0.0f;
    this->mOfsSpecial.x = ::MtVector3::Zero.x;
    this->mOfsSpecial.y = ::MtVector3::Zero.y;
    this->mOfsSpecial.z = ::MtVector3::Zero.z;
    this->mOfsSpecial.pad_ = 0.0f;
    this->mFatSpecial = 1.0f;
}

inline void* rWeaponOffset::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rWeaponOffset::DTI)->memAlloc(sz, align, ::rWeaponOffset::DTI.::MtDTI::getID());
}

inline void rWeaponOffset::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rWeaponOffset::DTI)->memFree(p_addr);
}
