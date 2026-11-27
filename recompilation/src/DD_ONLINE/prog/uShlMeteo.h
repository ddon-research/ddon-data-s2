#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtEaseCurve.h"
#include "../../MT/MtMath.h"
#include "uShlBase.h"
#include "uShlGenerator.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtHermiteCurve;
class MtMatrix;
class MtObject;
class MtPropertyList;
class MtVector3;
class cEfcHandle;
class cShlParamBase;

// Declarations
class cShlParamMeteo;
class cShlParamMeteoCtrl;
class uShlMeteo;
class uShlMeteoCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamMeteo : public cShlParamBase
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
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 8
    virtual void createPropertySE(MtPropertyList& s);  // vtable slot 9
    cShlParamMeteo();
    virtual ~cShlParamMeteo();
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    f32 distWallCheck;  // offset: 0x160
    f32 fallFrame;  // offset: 0x164
    f32 vanishTime;  // offset: 0x168
    MtHermiteCurve moveCurve;  // offset: 0x16c
    s32 shlNoHitExp;  // offset: 0x1ac
    s32 noticeShlNo;  // offset: 0x1b0
    s32 epvNoKira;  // offset: 0x1b4
    s32 epvNoTarget;  // offset: 0x1b8
    s32 seNoFall;  // offset: 0x1bc
    f32 distance;  // offset: 0x1c0
    static MyDTI DTI;
};

class cShlParamMeteoCtrl : public cShlParamGenerator
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
    cShlParamMeteoCtrl();
    virtual ~cShlParamMeteoCtrl() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 8
    virtual void createPropertySE(MtPropertyList& s);  // vtable slot 9
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    static MyDTI DTI;
};

class uShlMeteo : public uShlBase
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
    const cShlParamMeteo* getShlParam() const;
    uShlMeteo();
    virtual ~uShlMeteo();
    virtual void setup();  // vtable slot 6
    virtual void initSub();  // vtable slot 177
    virtual void updateSub();  // vtable slot 175
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    virtual void updateEfcHandle();  // vtable slot 58
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
protected:
    void checkScr();
    void createNoticeShl(u32 index);
    uShlBase* createHitScrShl(u32 index, u32 shotSts, bool isNow);
private:
    u32 mRoutine;  // offset: 0x2ab0
    f32 fallTimer;  // offset: 0x2ab4
    MtVector3 mGroundPos;  // offset: 0x2ac0
    cEfcHandle* mpTargetEfcHandle;  // offset: 0x2ad0
public:
    static MyDTI DTI;
};

class uShlMeteoCtrl : public uShlGenerator
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
    const cShlParamMeteoCtrl* getShlParam() const;
    uShlMeteoCtrl();
    virtual ~uShlMeteoCtrl();
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    virtual void updateEfcHandle();  // vtable slot 58
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
protected:
    virtual void setShl(u32 shlNo, const MtVector3& offset, f32 degX, f32 degY);  // vtable slot 186
private:
    MtVector3 mMeteoCenter;  // offset: 0x2ad0
    MtMatrix mShootMat;  // offset: 0x2ae0
public:
    static MyDTI DTI;
};

inline void* cShlParamMeteo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamMeteo::cShlParamMeteo() {
    this->distWallCheck = 500.0f;
    this->fallFrame = 40.0f;
    this->vanishTime = 10.0f;
    this->moveCurve.x[0] = 0.0f;
    this->moveCurve.y[0] = 0.0f;
    this->moveCurve.x[1] = 0.414747f;
    this->moveCurve.x[2] = 0.705069f;
    this->moveCurve.y[1] = 0.057377f;
    this->moveCurve.y[2] = 0.245902f;
    this->moveCurve.x[3] = 0.896313f;
    this->moveCurve.x[4] = 1.0f;
    this->moveCurve.y[3] = 0.647541f;
    this->moveCurve.y[4] = 1.0f;
    this->moveCurve.x[5] = 1.0f;
    this->moveCurve.x[6] = 1.0f;
    this->moveCurve.y[5] = 1.0f;
    this->moveCurve.y[6] = 1.0f;
    this->moveCurve.x[7] = 1.0f;
    this->moveCurve.y[7] = 1.0f;
    this->seNoFall = -1;
    this->epvNoKira = -1;
    this->epvNoTarget = -1;
    this->shlNoHitExp = -1;
    this->noticeShlNo = -1;
    this->distance = 0.0f;
}

inline void* cShlParamMeteoCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamMeteoCtrl::cShlParamMeteoCtrl() {
}

inline void* uShlMeteo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlMeteo::uShlMeteo() {
    this->mRoutine = 0;
    this->fallTimer = 0.0f;
    this->mpTargetEfcHandle = nullptr;
    this->mGroundPos.z = 0.0f;
    this->mGroundPos.pad_ = 0.0f;
    this->mGroundPos.x = 0.0f;
    this->mGroundPos.y = 0.0f;
}

inline void* uShlMeteoCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cShlParamMeteo::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamMeteo::DTI)->memAlloc(sz, align, ::cShlParamMeteo::DTI.::MtDTI::getID());
}

inline void* cShlParamMeteoCtrl::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamMeteoCtrl::DTI)->memAlloc(sz, align, ::cShlParamMeteoCtrl::DTI.::MtDTI::getID());
}

inline void cShlParamMeteoCtrl::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cShlParamMeteoCtrl::DTI)->memFree(p_addr);
}

inline void* uShlMeteo::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlMeteo::DTI)->memAlloc(sz, align, ::uShlMeteo::DTI.::MtDTI::getID());
}

inline void uShlMeteo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlMeteo::DTI)->memFree(p_addr);
}

inline const cShlParamMeteo* uShlMeteo::getShlParam() const {
    return static_cast<const cShlParamMeteo*>(this->::uShlBase::mpShlParam2);
}

inline void* uShlMeteoCtrl::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlMeteoCtrl::DTI)->memAlloc(sz, align, ::uShlMeteoCtrl::DTI.::MtDTI::getID());
}

inline void uShlMeteoCtrl::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlMeteoCtrl::DTI)->memFree(p_addr);
}

inline const cShlParamMeteoCtrl* uShlMeteoCtrl::getShlParam() const {
    return static_cast<const cShlParamMeteoCtrl*>(this->::uShlBase::mpShlParam2);
}

inline uShlMeteoCtrl::uShlMeteoCtrl() {
    this->mMeteoCenter.z = 0.0f;
    this->mMeteoCenter.pad_ = 0.0f;
    this->mMeteoCenter.x = 0.0f;
    this->mMeteoCenter.y = 0.0f;
    this->mShootMat.m[0].x = ::MtMatrix::Identity.m[0].x;
    this->mShootMat.m[0].y = ::MtMatrix::Identity.m[0].y;
    this->mShootMat.m[0].z = ::MtMatrix::Identity.m[0].z;
    this->mShootMat.m[0].w = ::MtMatrix::Identity.m[0].w;
    this->mShootMat.m[1].x = ::MtMatrix::Identity.m[1].x;
    this->mShootMat.m[1].y = ::MtMatrix::Identity.m[1].y;
    this->mShootMat.m[1].z = ::MtMatrix::Identity.m[1].z;
    this->mShootMat.m[1].w = ::MtMatrix::Identity.m[1].w;
    this->mShootMat.m[2].x = ::MtMatrix::Identity.m[2].x;
    this->mShootMat.m[2].y = ::MtMatrix::Identity.m[2].y;
    this->mShootMat.m[2].z = ::MtMatrix::Identity.m[2].z;
    this->mShootMat.m[2].w = ::MtMatrix::Identity.m[2].w;
    this->mShootMat.m[3].x = ::MtMatrix::Identity.m[3].x;
    this->mShootMat.m[3].y = ::MtMatrix::Identity.m[3].y;
    this->mShootMat.m[3].z = ::MtMatrix::Identity.m[3].z;
    this->mShootMat.m[3].w = ::MtMatrix::Identity.m[3].w;
}
