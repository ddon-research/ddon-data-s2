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
class uDDOModel;

// Declarations
class cpOmBlink;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpOmBlink : public cpComponent
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
    cpOmBlink();
    virtual ~cpOmBlink();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void updatePtr();  // vtable slot 9
    void setBlinkType(s32 type);
    void setBlinkOff();
protected:
    uDDOModel* mpModel;  // offset: 0x50
    u32 mBlinkType;  // offset: 0x58
    f32 mRangeNear;  // offset: 0x5c
    f32 mRangeFar;  // offset: 0x60
    f32 mDiffuseColorCtr;  // offset: 0x64
    f32 mDiffuseIdleTimer;  // offset: 0x68
public:
    static MyDTI DTI;
};

inline void* cpOmBlink::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void cpOmBlink::setBlinkType(s32 type) {
    this->mBlinkType = static_cast<u32>(type);
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cpOmBlink::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cpOmBlink::DTI);
}

inline void cpOmBlink::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cpOmBlink::DTI)->memFree(p_addr);
}
