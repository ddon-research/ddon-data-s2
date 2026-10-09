#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtVector3;
class cAttackParam;
class cHitGeom;
class cHitInfo;
class uDDOModel;

// Declarations
class cShlNotifyInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlNotifyInfo : public MtObject
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
    cShlNotifyInfo();
    void createParam(cHitInfo* pHitInfo);
public:
    const cAttackParam* mpAttackParam;  // offset: 0x8
    uDDOModel* mpAtkModel;  // offset: 0x10
    uDDOModel* mpDfdModel;  // offset: 0x18
    const cHitGeom* mpAtkGeom;  // offset: 0x20
    const cHitGeom* mpDfdGeom;  // offset: 0x28
    MtVector3 mHitPos;  // offset: 0x30
    static MyDTI DTI;
};
