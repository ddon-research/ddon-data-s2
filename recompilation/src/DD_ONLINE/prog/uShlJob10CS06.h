#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "uShlCustomSpline.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cShlParamBase;

// Declarations
class cShlParamJob10CS06;
class uShlJob10CS06;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamJob10CS06 : public cShlParamCustomSpline
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
    cShlParamJob10CS06();
    virtual ~cShlParamJob10CS06() {}
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    static MyDTI DTI;
};

class uShlJob10CS06 : public uShlCustomSpline
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
    const cShlParamJob10CS06* getShlParam() const;
    uShlJob10CS06();
    virtual ~uShlJob10CS06();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    void callChargeEfc();
    void callChargeSe();
    void callMaxChargeEfc();
public:
    static MyDTI DTI;
};

inline void* cShlParamJob10CS06::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamJob10CS06::cShlParamJob10CS06() {
}

inline void* uShlJob10CS06::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlJob10CS06::uShlJob10CS06() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"
#include "uShlBase.h"

inline void* cShlParamJob10CS06::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamJob10CS06::DTI)->memAlloc(sz, align, ::cShlParamJob10CS06::DTI.::MtDTI::getID());
}

inline void cShlParamJob10CS06::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cShlParamJob10CS06::DTI)->memFree(p_addr);
}

inline void* uShlJob10CS06::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlJob10CS06::DTI)->memAlloc(sz, align, ::uShlJob10CS06::DTI.::MtDTI::getID());
}

inline void uShlJob10CS06::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlJob10CS06::DTI)->memFree(p_addr);
}

inline const cShlParamJob10CS06* uShlJob10CS06::getShlParam() const {
    return static_cast<const cShlParamJob10CS06*>(this->::uShlBase::mpShlParam2);
}
