#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "uShlFollowMove.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cShlParamBase;

// Declarations
class cShlParamShortCharge;
class uShlShortCharge;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamShortCharge : public cShlParamFollowMove
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
    cShlParamShortCharge();
    virtual ~cShlParamShortCharge();
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    f32 MgcChargeRate;  // offset: 0x18c
    f32 PysChargeRate;  // offset: 0x190
    static MyDTI DTI;
};

class uShlShortCharge : public uShlFollowMove
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
    const cShlParamShortCharge* getShlParam() const;
    uShlShortCharge();
    virtual ~uShlShortCharge();
public:
    static MyDTI DTI;
};

inline void* cShlParamShortCharge::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamShortCharge::cShlParamShortCharge() {
    this->MgcChargeRate = 1.0f;
    this->PysChargeRate = 1.0f;
}

inline void* uShlShortCharge::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlShortCharge::uShlShortCharge() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cShlParamShortCharge::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamShortCharge::DTI)->memAlloc(sz, align, ::cShlParamShortCharge::DTI.::MtDTI::getID());
}

inline void* uShlShortCharge::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlShortCharge::DTI)->memAlloc(sz, align, ::uShlShortCharge::DTI.::MtDTI::getID());
}

inline void uShlShortCharge::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlShortCharge::DTI)->memFree(p_addr);
}
