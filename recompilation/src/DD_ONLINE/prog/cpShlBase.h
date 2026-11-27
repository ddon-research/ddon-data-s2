#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cHitInfo;

// Declarations
class cShlParamComponent;
class cpShlBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamComponent : public MtObject
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
    MT_CTSTR getClassName() const;
    virtual const MtDTI& getComponentDTI() const;  // vtable slot 6
    virtual void copy(const cShlParamComponent* pParam);  // vtable slot 7
public:
    static MyDTI DTI;
};

class cpShlBase : public cpComponent
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
    virtual void initSub();  // vtable slot 15
    virtual void updateSub();  // vtable slot 16
    void setParam(cShlParamComponent* pParam);
    const cShlParamComponent* getParam() const;
    virtual void callbackReplaceHitInfo_Atk(cHitInfo* pHitInfo) {}  // vtable slot 17
protected:
    cShlParamComponent* mpParam;  // offset: 0x50
public:
    static MyDTI DTI;
};

inline void* cShlParamComponent::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cpShlBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline const cShlParamComponent* cpShlBase::getParam() const {
    return this->mpParam;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void cShlParamComponent::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cShlParamComponent::DTI)->memFree(p_addr);
}

inline void* cpShlBase::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cpShlBase::DTI)->memAlloc(sz, align, ::cpShlBase::DTI.::MtDTI::getID());
}

inline void cpShlBase::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cpShlBase::DTI)->memFree(p_addr);
}
