#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "nDDOGame.h"
#include "nObjCondition.h"

// Forward declarations
class MtAllocator;
class MtDTI;

// Declarations
class cShlConditionInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlConditionInfo : public MtObject
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
    cShlConditionInfo();
    // Address: 0x0197c750 - 0x0197c751 (1 bytes)
    virtual ~cShlConditionInfo() {}
    void copy(const cShlConditionInfo& src);
public:
    bool mIsSetActiveTime;  // offset: 0x8
    f32 mActiveTime;  // offset: 0xc
    f32 mAdjustParam0;  // offset: 0x10
    f32 mAdjustParam1;  // offset: 0x14
    nDDOGame::ELEMENT_TYPE mElementType;  // offset: 0x18
    nObjCondition::IMMUNE_BOOST_LV mBoostLv;  // offset: 0x1c
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cShlConditionInfo::cShlConditionInfo() {
    this->mActiveTime = 10.0f;
    this->mAdjustParam0 = 1.0f;
    this->mAdjustParam1 = 0.0f;
    this->mElementType = static_cast<nDDOGame::ELEMENT_TYPE>(2);
    this->mIsSetActiveTime = false;
    this->mBoostLv = static_cast<nObjCondition::IMMUNE_BOOST_LV>(9);
}
