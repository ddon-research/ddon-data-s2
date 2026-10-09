#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtSynchronize.h"
#include "cGeneralPointPtr.h"
#include "cLayoutSet.h"
#include "nDDOUtility.h"

// Forward declarations
class MtAllocator;
class MtCriticalSection;
class MtDTI;
class MtObject;
class cGeneralPointPtr;
class rLayout;

// Declarations
class cLayoutSetGeneralPoint;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cLayoutSetGeneralPoint : public cLayoutSet
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
    cLayoutSetGeneralPoint();
    virtual ~cLayoutSetGeneralPoint();
    virtual void move();  // vtable slot 7
    virtual void finish();  // vtable slot 8
    virtual MtObject* setLayoutUnit(rLayout* pLayout, u32 no, bool isForceSet, u32 mode);  // vtable slot 18
    virtual bool isUseUnitData() const;  // vtable slot 15
private:
    s32 geGptArrayNum() const;
    bool isCreated(u32 no) const;
private:
    nDDOUtility::cArray<cGeneralPointPtr, 32> mGpArray;  // offset: 0x88
    nDDOUtility::cArray<int, 32> mGpNoArray;  // offset: 0x288
    s32 mGpArrayNum;  // offset: 0x308
    MtCriticalSection mCS;  // offset: 0x310
public:
    static MyDTI DTI;
};
