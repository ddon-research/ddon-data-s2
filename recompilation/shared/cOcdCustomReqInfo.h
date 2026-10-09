#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "nObjCondition.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class cOcdInfo;

// Declarations
class cOcdCustomReqInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cOcdCustomReqInfo : public MtObject
{
    // inferred: cOcdInfo::isReqestAbleCustom names cOcdInfo::mOcdCustomReq.mPriority
    friend class cOcdInfo;
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
    cOcdCustomReqInfo();
    void copy(const cOcdCustomReqInfo& src);
    void clear();
public:
    f32 mActiveTime;  // offset: 0x8
    nObjCondition::IMMUNE_BOOST_LV mImmuneBoostLv;  // offset: 0xc
private:
    bool mIsRequest;  // offset: 0x10
    s32 mPriority;  // offset: 0x14
public:
    static MyDTI DTI;
};
