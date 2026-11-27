#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "uShlBase.h"
#include "uShlGenerator.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;

// Declarations
class cShlParamGeneTarget;
class uShlGeneTarget;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamGeneTarget : public cShlParamBase
{
public:
    class MyDTI;
    class cShootCtrlParamGeneTarget;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cShootCtrlParamGeneTarget : public MtObject
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
        cShootCtrlParamGeneTarget();
        virtual ~cShootCtrlParamGeneTarget() {}
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    public:
        f32 waitFrame;  // offset: 0x8
        s32 shlNo;  // offset: 0xc
        MtVector3 offset;  // offset: 0x10
        f32 degY;  // offset: 0x20
        f32 distScale;  // offset: 0x24
        static MyDTI DTI;
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
    cShlParamGeneTarget();
    virtual ~cShlParamGeneTarget();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 8
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
    virtual void addShlList(const cShlParamGeneTarget* pParam);  // vtable slot 12
public:
    MtArray shlList;  // offset: 0x160
    static MyDTI DTI;
};

class uShlGeneTarget : public uShlGenerator
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
    const cShlParamGeneTarget* getShlParam() const;
    uShlGeneTarget();
    virtual ~uShlGeneTarget();
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
protected:
    virtual void setShl(u32 shlNo, const MtVector3& offset, f32 degY, f32 scale);  // vtable slot 186
public:
    static MyDTI DTI;
};

inline void* cShlParamGeneTarget::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamGeneTarget::cShlParamGeneTarget() {
    this->shlList.mAutoDelete = true;
}

inline void* cShlParamGeneTarget::cShootCtrlParamGeneTarget::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamGeneTarget::cShootCtrlParamGeneTarget::cShootCtrlParamGeneTarget() {
    this->waitFrame = 0.0f;
    this->shlNo = -1;
    this->degY = 0.0f;
    this->offset.z = 0.0f;
    this->offset.pad_ = 0.0f;
    this->offset.x = 0.0f;
    this->offset.y = 0.0f;
    this->distScale = 1.0f;
}

inline void* uShlGeneTarget::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlGeneTarget::uShlGeneTarget() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cShlParamGeneTarget::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamGeneTarget::DTI)->memAlloc(sz, align, ::cShlParamGeneTarget::DTI.::MtDTI::getID());
}

inline void cShlParamGeneTarget::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cShlParamGeneTarget::DTI)->memFree(p_addr);
}

inline void* cShlParamGeneTarget::cShootCtrlParamGeneTarget::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamGeneTarget::cShootCtrlParamGeneTarget::DTI)->memAlloc(sz, align, ::cShlParamGeneTarget::cShootCtrlParamGeneTarget::DTI.::MtDTI::getID());
}

inline void cShlParamGeneTarget::cShootCtrlParamGeneTarget::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cShlParamGeneTarget::cShootCtrlParamGeneTarget::DTI)->memFree(p_addr);
}

inline void* uShlGeneTarget::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlGeneTarget::DTI)->memAlloc(sz, align, ::uShlGeneTarget::DTI.::MtDTI::getID());
}

inline void uShlGeneTarget::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlGeneTarget::DTI)->memFree(p_addr);
}

inline const cShlParamGeneTarget* uShlGeneTarget::getShlParam() const {
    return static_cast<const cShlParamGeneTarget*>(this->::uShlBase::mpShlParam2);
}
