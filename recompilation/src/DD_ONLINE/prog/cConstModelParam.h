#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtVector3;

// Declarations
class cConstModelParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cConstModelParam : public MtObject
{
public:
    enum
    {
        DATA_VERSION = 1,
    };
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
    cConstModelParam();
    virtual ~cConstModelParam() {}
    void copy(const cConstModelParam& src);
public:
    s32 mConstJointNo;  // offset: 0x8
    MtVector3 mConstOffset;  // offset: 0x10
    static MyDTI DTI;
};

inline void* cConstModelParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cConstModelParam::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cConstModelParam::DTI);
}

inline void* cConstModelParam::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cConstModelParam::DTI)->memAlloc(sz, align, ::cConstModelParam::DTI.::MtDTI::getID());
}

inline void cConstModelParam::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cConstModelParam::DTI)->memFree(p_addr);
}

inline cConstModelParam::cConstModelParam() {
    this->mConstJointNo = 0;
    this->mConstOffset = ::MtVector3::Zero;
}
