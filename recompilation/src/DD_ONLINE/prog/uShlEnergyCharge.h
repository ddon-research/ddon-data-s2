#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "uShlBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cHitInfo;

// Declarations
class cShlParamEnergyCharge;
class uShlEnergyCharge;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamEnergyCharge : public cShlParamBase
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
    cShlParamEnergyCharge();
    virtual ~cShlParamEnergyCharge();
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    f32 mMaxPowerVal;  // offset: 0x160
    static MyDTI DTI;
};

class uShlEnergyCharge : public uShlBase
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
    const cShlParamEnergyCharge* getShlParam() const;
    uShlEnergyCharge();
    virtual ~uShlEnergyCharge();
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    virtual void callbackCheck(cHitInfo* pHitInfo);  // vtable slot 123
    virtual void callbackDamage(cHitInfo* pHitInfo);  // vtable slot 88
    virtual void executeAddDamage();  // vtable slot 183
public:
    static MyDTI DTI;
};

inline void* cShlParamEnergyCharge::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamEnergyCharge::cShlParamEnergyCharge() {
    this->mMaxPowerVal = 10.0f;
}

inline void* uShlEnergyCharge::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlEnergyCharge::uShlEnergyCharge() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cShlParamEnergyCharge::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamEnergyCharge::DTI)->memAlloc(sz, align, ::cShlParamEnergyCharge::DTI.::MtDTI::getID());
}

inline void* uShlEnergyCharge::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlEnergyCharge::DTI)->memAlloc(sz, align, ::uShlEnergyCharge::DTI.::MtDTI::getID());
}

inline void uShlEnergyCharge::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlEnergyCharge::DTI)->memFree(p_addr);
}

inline const cShlParamEnergyCharge* uShlEnergyCharge::getShlParam() const {
    return static_cast<const cShlParamEnergyCharge*>(this->::uShlBase::mpShlParam2);
}
