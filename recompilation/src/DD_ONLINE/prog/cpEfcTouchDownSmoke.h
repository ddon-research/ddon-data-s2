#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cpSequenceCtrl;

// Declarations
class cpEfcTouchDownSmoke;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cpEfcTouchDownSmoke : public cpComponent
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
    cpEfcTouchDownSmoke();
    virtual ~cpEfcTouchDownSmoke();
    virtual void updatePtr();  // vtable slot 9
    void callbackSequenceTrigger(cpSequenceCtrl* pSeqCtrl, u32 page, u32 bit, u16 work);
public:
    static MyDTI DTI;
};

inline void* cpEfcTouchDownSmoke::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cpEfcTouchDownSmoke::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cpEfcTouchDownSmoke::DTI);
}

inline void cpEfcTouchDownSmoke::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cpEfcTouchDownSmoke::DTI)->memFree(p_addr);
}
