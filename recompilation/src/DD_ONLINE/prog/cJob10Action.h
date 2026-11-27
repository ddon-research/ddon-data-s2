#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cHumanAction.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
class cJob10ExecuteBoost;
class cJob10NormalAttackBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cJob10NormalAttackBase : public cHumanActBase
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
    virtual void init();  // vtable slot 7
    virtual void move();  // vtable slot 8
    virtual void final();  // vtable slot 9
public:
    static MyDTI DTI;
};

class cJob10ExecuteBoost : public cJob10NormalAttackBase
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
    virtual void init();  // vtable slot 7
    virtual void move();  // vtable slot 8
    virtual void final();  // vtable slot 9
    bool getIsStartDecSpirit();
public:
    bool mIsStartDecSpirit;  // offset: 0x41
    static MyDTI DTI;
};

inline void* cJob10ExecuteBoost::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cJob10NormalAttackBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void cJob10ExecuteBoost::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cJob10ExecuteBoost::DTI)->memFree(p_addr);
}

inline void* cJob10NormalAttackBase::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cJob10NormalAttackBase::DTI)->memAlloc(sz, align, ::cJob10NormalAttackBase::DTI.::MtDTI::getID());
}

inline void cJob10NormalAttackBase::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cJob10NormalAttackBase::DTI)->memFree(p_addr);
}
