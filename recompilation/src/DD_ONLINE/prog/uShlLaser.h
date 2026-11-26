#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "uShlBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cEfcHandle;

// Declarations
class cShlParamLaser;
class uShlLaser;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamLaser : public cShlParamBase
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
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamLaser();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 8
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
private:
    f32 mLaserBaseLength;  // offset: 0x160
    f32 mMaxScale;  // offset: 0x164
    s32 mLandEffectNo;  // offset: 0x168
public:
    static MyDTI DTI;
};

class uShlLaser : public uShlBase
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
    const cShlParamLaser* getShlParam() const;
    uShlLaser();
    virtual ~uShlLaser() {}
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void update();  // vtable slot 174
    virtual void updateEfcHandle();  // vtable slot 58
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
private:
    bool mFlgHitLand;  // offset: 0x2ab0
    MtVector3 mHitLandPos;  // offset: 0x2ac0
    cEfcHandle* mpEfcHandleLand;  // offset: 0x2ad0
public:
    static MyDTI DTI;
};

inline void* cShlParamLaser::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamLaser::cShlParamLaser() {
    this->mLaserBaseLength = 4000.0f;
    this->mMaxScale = 2.0f;
    this->mLandEffectNo = -1;
}

inline void* uShlLaser::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
