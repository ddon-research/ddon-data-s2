#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "uShlHoming.h"
#include "uShlSpeed.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cHitInfo;
class cShlParamBase;

// Declarations
class cShlParamJob08Cs12Homing;
class cShlParamJob08Cs12Pad;
class cShlParamPadCtrl;
class uShlJob08Cs12Homing;
class uShlJob08Cs12Pad;
class uShlPadCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamJob08Cs12Homing : public cShlParamHoming
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
    cShlParamJob08Cs12Homing();
    virtual ~cShlParamJob08Cs12Homing();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    u32 maxHit;  // offset: 0x248
    s32 objHitShlNo[5];  // offset: 0x24c
    s32 finishShlNo;  // offset: 0x260
    static MyDTI DTI;
};

class cShlParamPadCtrl : public cShlParamSpeed
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
    cShlParamPadCtrl();
    virtual ~cShlParamPadCtrl();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    f32 padCtrlDeg;  // offset: 0x1f0
    f32 ctrlDist;  // offset: 0x1f4
    static MyDTI DTI;
};

class uShlJob08Cs12Homing : public uShlHoming
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
    const cShlParamJob08Cs12Homing* getShlParam() const;
    uShlJob08Cs12Homing();
    virtual ~uShlJob08Cs12Homing() {}
    virtual void updateSub();  // vtable slot 175
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 83
public:
    u32 mHitCnt;  // offset: 0x2bdc
    u32 mTargetHitCnt;  // offset: 0x2be0
    static MyDTI DTI;
};

class uShlPadCtrl : public uShlSpeed
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
    const cShlParamPadCtrl* getShlParam() const;
    uShlPadCtrl();
    virtual ~uShlPadCtrl();
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
    bool isCtrlEnd() const;
protected:
    bool mIsCtrlEnd;  // offset: 0x2b86
public:
    static MyDTI DTI;
};

class cShlParamJob08Cs12Pad : public cShlParamPadCtrl
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
    cShlParamJob08Cs12Pad();
    virtual ~cShlParamJob08Cs12Pad();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    s32 objHitShlNo;  // offset: 0x1f8
    static MyDTI DTI;
};

class uShlJob08Cs12Pad : public uShlPadCtrl
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
    const cShlParamJob08Cs12Pad* getShlParam() const;
    uShlJob08Cs12Pad();
    virtual ~uShlJob08Cs12Pad() {}
    virtual void updateSub();  // vtable slot 175
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 83
public:
    static MyDTI DTI;
};

inline void* cShlParamJob08Cs12Homing::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamJob08Cs12Homing::cShlParamJob08Cs12Homing() : maxHit(0u), finishShlNo(-1) {
    for (u32 i = 0; i < 5u; i++) {
        objHitShlNo[i] = -1;
    }
}

inline void* cShlParamJob08Cs12Pad::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamJob08Cs12Pad::cShlParamJob08Cs12Pad() {
    this->objHitShlNo = -1;
}

inline void* cShlParamPadCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamPadCtrl::cShlParamPadCtrl() {
    this->padCtrlDeg = 10.0f;
    this->ctrlDist = 3000.0f;
}

inline void* uShlJob08Cs12Homing::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlJob08Cs12Homing::uShlJob08Cs12Homing() {
    this->mHitCnt = 0;
    this->mTargetHitCnt = 0;
}

inline void* uShlJob08Cs12Pad::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlJob08Cs12Pad::uShlJob08Cs12Pad() {
}

inline void* uShlPadCtrl::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlPadCtrl::uShlPadCtrl() {
    this->mIsCtrlEnd = false;
    this->::uShlSpeed::mIsThroughWater = false;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"
#include "uShlBase.h"

inline void* cShlParamJob08Cs12Pad::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamJob08Cs12Pad::DTI)->memAlloc(sz, align, ::cShlParamJob08Cs12Pad::DTI.::MtDTI::getID());
}

inline void* cShlParamPadCtrl::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamPadCtrl::DTI)->memAlloc(sz, align, ::cShlParamPadCtrl::DTI.::MtDTI::getID());
}

inline void* uShlJob08Cs12Homing::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlJob08Cs12Homing::DTI)->memAlloc(sz, align, ::uShlJob08Cs12Homing::DTI.::MtDTI::getID());
}

inline void uShlJob08Cs12Homing::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlJob08Cs12Homing::DTI)->memFree(p_addr);
}

inline const cShlParamJob08Cs12Homing* uShlJob08Cs12Homing::getShlParam() const {
    return static_cast<const cShlParamJob08Cs12Homing*>(this->::uShlBase::mpShlParam2);
}

inline void* uShlJob08Cs12Pad::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlJob08Cs12Pad::DTI)->memAlloc(sz, align, ::uShlJob08Cs12Pad::DTI.::MtDTI::getID());
}

inline void uShlJob08Cs12Pad::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlJob08Cs12Pad::DTI)->memFree(p_addr);
}

inline const cShlParamJob08Cs12Pad* uShlJob08Cs12Pad::getShlParam() const {
    return static_cast<const cShlParamJob08Cs12Pad*>(this->::uShlBase::mpShlParam2);
}

inline void* uShlPadCtrl::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlPadCtrl::DTI)->memAlloc(sz, align, ::uShlPadCtrl::DTI.::MtDTI::getID());
}

inline void uShlPadCtrl::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlPadCtrl::DTI)->memFree(p_addr);
}

inline const cShlParamPadCtrl* uShlPadCtrl::getShlParam() const {
    return static_cast<const cShlParamPadCtrl*>(this->::uShlBase::mpShlParam2);
}
