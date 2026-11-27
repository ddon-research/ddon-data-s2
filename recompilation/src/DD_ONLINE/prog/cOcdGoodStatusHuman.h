#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cOcdGoodStatus.h"
#include "../../generated/shared/nDDOGame.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cShlConditionInfo;

// Declarations
class cOcdElementCover;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cOcdElementCover : public cOcdGoodStatusBase
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
    cOcdElementCover();
    virtual ~cOcdElementCover();
    virtual void init(bool initFlag);  // vtable slot 9
    virtual void final();  // vtable slot 11
    nDDOGame::ELEMENT_TYPE getElemnentType() const;
    f32 getAdjsutRate() const;
    f32 getAdjustDamageRate() const;
    virtual void callbackHitShlCondition_Catch(const cShlConditionInfo* pShlInfo);  // vtable slot 24
public:
    static MyDTI DTI;
};

inline void* cOcdElementCover::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cOcdElementCover::cOcdElementCover() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cOcdElementCover::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cOcdElementCover::DTI)->memAlloc(sz, align, ::cOcdElementCover::DTI.::MtDTI::getID());
}

inline void cOcdElementCover::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cOcdElementCover::DTI)->memFree(p_addr);
}
