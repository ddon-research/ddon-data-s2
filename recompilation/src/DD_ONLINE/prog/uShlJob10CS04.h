#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "uShlSpeed.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cHitInfo;
class cShlParamBase;

// Declarations
class cShlParamJob10CS04;
class uShlJob10CS04;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamJob10CS04 : public cShlParamSpeed
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
    cShlParamJob10CS04();
    virtual ~cShlParamJob10CS04();
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    s32 mDieShlIdx;  // offset: 0x1f0
    f32 mDieDistance;  // offset: 0x1f4
    static MyDTI DTI;
};

class uShlJob10CS04 : public uShlSpeed
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
    const cShlParamJob10CS04* getShlParam() const;
    uShlJob10CS04();
    virtual ~uShlJob10CS04() {}
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
    virtual void kill();  // vtable slot 16
    virtual void progKillReqOrg();  // vtable slot 189
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 83
    virtual void setDiePos(const MtVector3& pos);  // vtable slot 190
private:
    bool mFlgCreateDieShl;  // offset: 0x2b86
    MtVector3 mDiePos;  // offset: 0x2b90
public:
    static MyDTI DTI;
};

inline void* cShlParamJob10CS04::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamJob10CS04::cShlParamJob10CS04() {
    this->mDieShlIdx = -1;
    this->mDieDistance = -1.0f;
}

inline void* uShlJob10CS04::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"
#include "uShlBase.h"

inline void* cShlParamJob10CS04::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamJob10CS04::DTI)->memAlloc(sz, align, ::cShlParamJob10CS04::DTI.::MtDTI::getID());
}

inline void* uShlJob10CS04::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlJob10CS04::DTI)->memAlloc(sz, align, ::uShlJob10CS04::DTI.::MtDTI::getID());
}

inline void uShlJob10CS04::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlJob10CS04::DTI)->memFree(p_addr);
}

inline const cShlParamJob10CS04* uShlJob10CS04::getShlParam() const {
    return static_cast<const cShlParamJob10CS04*>(this->::uShlBase::mpShlParam2);
}

inline uShlJob10CS04::uShlJob10CS04() {
    this->mFlgCreateDieShl = false;
    this->mDiePos = ::MtVector3::Zero;
}
