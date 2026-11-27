#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "uShlGenerator.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cShlParamBase;

// Declarations
class cShlParamGeneAlongGround;
class uShlGeneAlongGround;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamGeneAlongGround : public cShlParamGenerator
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
    cShlParamGeneAlongGround();
    virtual ~cShlParamGeneAlongGround();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
    f32 getCliffSafeOffSet() const;
private:
    f32 mGroundCheckYMax;  // offset: 0x18c
    f32 mGroundCheckYMin;  // offset: 0x190
    bool mWallCheck;  // offset: 0x194
    f32 mWallCheckHeight;  // offset: 0x198
    bool mWallCheckCreateForOnce;  // offset: 0x19c
    f32 mCliffSafeOffset;  // offset: 0x1a0
public:
    static MyDTI DTI;
};

class uShlGeneAlongGround : public uShlGenerator
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
    const cShlParamGeneAlongGround* getShlParam() const;
    uShlGeneAlongGround();
    virtual ~uShlGeneAlongGround();
    virtual void setup();  // vtable slot 6
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
protected:
    virtual void setShl(u32 shlNo, const MtVector3& offset, f32 degX, f32 degY);  // vtable slot 186
    bool enableCreateShell(MtVector3& pos, const MtVector3& cliff_safe_pos);
private:
    MtVector3 mLastGeneratPos;  // offset: 0x2ad0
public:
    static MyDTI DTI;
};

inline void* cShlParamGeneAlongGround::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamGeneAlongGround::cShlParamGeneAlongGround() {
    this->mGroundCheckYMax = 300.0f;
    this->mGroundCheckYMin = -300.0f;
    this->mWallCheck = false;
    this->mWallCheckHeight = 150.0f;
    this->mWallCheckCreateForOnce = false;
    this->mCliffSafeOffset = 50.0f;
}

inline void* uShlGeneAlongGround::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"
#include "uShlBase.h"

inline void* cShlParamGeneAlongGround::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamGeneAlongGround::DTI)->memAlloc(sz, align, ::cShlParamGeneAlongGround::DTI.::MtDTI::getID());
}

inline void cShlParamGeneAlongGround::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cShlParamGeneAlongGround::DTI)->memFree(p_addr);
}

inline void* uShlGeneAlongGround::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlGeneAlongGround::DTI)->memAlloc(sz, align, ::uShlGeneAlongGround::DTI.::MtDTI::getID());
}

inline void uShlGeneAlongGround::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlGeneAlongGround::DTI)->memFree(p_addr);
}

inline const cShlParamGeneAlongGround* uShlGeneAlongGround::getShlParam() const {
    return static_cast<const cShlParamGeneAlongGround*>(this->::uShlBase::mpShlParam2);
}

inline uShlGeneAlongGround::uShlGeneAlongGround() {
    this->mLastGeneratPos.x = ::MtVector3::Zero.x;
    this->mLastGeneratPos.y = ::MtVector3::Zero.y;
    this->mLastGeneratPos.z = ::MtVector3::Zero.z;
    this->mLastGeneratPos.pad_ = 0.0f;
}
