#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "cpShlBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;

// Declarations
class cShlParamCompList;
class cShlParamCompSelector;
class cpShlList;
class cpShlSelector;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamCompList : public cShlParamComponent
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
    virtual const MtDTI& getComponentDTI() const;  // vtable slot 6
    cShlParamCompList();
    virtual ~cShlParamCompList();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamComponent* pParamBase);  // vtable slot 7
public:
    MtTypedArray<cShlParamComponent> mShlComponent;  // offset: 0x8
    static MyDTI DTI;
};

class cShlParamCompSelector : public cShlParamComponent
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
    virtual const MtDTI& getComponentDTI() const;  // vtable slot 6
    cShlParamCompSelector();
    virtual ~cShlParamCompSelector();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void copy(const cShlParamComponent* pParamBase);  // vtable slot 7
public:
    MtTypedArray<cShlParamComponent> mShlComponent;  // offset: 0x8
    static MyDTI DTI;
};

class cpShlList : public cpShlBase
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
public:
    static MyDTI DTI;
};

class cpShlSelector : public cpShlBase
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
protected:
    virtual u32 getSelectedIndex() const;  // vtable slot 18
public:
    static MyDTI DTI;
};

inline void* cShlParamCompList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamCompList::cShlParamCompList() {
}

inline void* cShlParamCompSelector::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamCompSelector::cShlParamCompSelector() {
}

inline void* cpShlList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cpShlSelector::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cShlParamCompList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamCompList::DTI)->memAlloc(sz, align, ::cShlParamCompList::DTI.::MtDTI::getID());
}

inline void cShlParamCompList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cShlParamCompList::DTI)->memFree(p_addr);
}

inline MtAllocator* cShlParamCompSelector::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cShlParamCompSelector::DTI);
}

inline void cpShlList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cpShlList::DTI)->memFree(p_addr);
}

inline void cpShlSelector::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cpShlSelector::DTI)->memFree(p_addr);
}
