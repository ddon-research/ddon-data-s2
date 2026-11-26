#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cpShlCondition.h"
#include "nObjCondition.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtUI;

// Declarations
class cShlParamCompConditionJob10Cs08;
class cpShlConditionJob10Cs08;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamCompConditionJob10Cs08 : public cShlParamCompCustomCondition
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
    cShlParamCompConditionJob10Cs08();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
public:
    static MyDTI DTI;
};

class cpShlConditionJob10Cs08 : public cpShlCustomCondition
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
    nObjCondition::IMMUNE_BOOST_LV getBoostLv() const;
public:
    static MyDTI DTI;
};

inline void* cShlParamCompConditionJob10Cs08::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamCompConditionJob10Cs08::cShlParamCompConditionJob10Cs08() {
    this->::cShlParamCompCondition::mInfo.mIsSetActiveTime = true;
}

inline void* cpShlConditionJob10Cs08::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
