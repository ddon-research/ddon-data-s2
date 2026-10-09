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
class MtPropertyList;
class MtVector2;
class MtVector3;

// Declarations
class cCollGeom;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cCollGeom : public MtObject
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
    cCollGeom();
    cCollGeom(const cCollGeom&);
    // Address: 0x01a7fb40 - 0x01a7fb41 (1 bytes)
    virtual ~cCollGeom() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u8 mShape;  // offset: 0x8
    u8 mOption;  // offset: 0x9
    u8 mScaleOption;  // offset: 0xa
    u8 mPriority;  // offset: 0xb
    u8 mLayer;  // offset: 0xc
    u8 mDmy0;  // offset: 0xd
    u16 mIndex;  // offset: 0xe
    s16 mJnt0;  // offset: 0x10
    s16 mJnt1;  // offset: 0x12
    u16 mRegionNo;  // offset: 0x14
    s16 mRangeCheckBaseJnt;  // offset: 0x16
    f32 mRadius;  // offset: 0x18
    MtVector2 mAngle0;  // offset: 0x20
    MtVector2 mAngle1;  // offset: 0x28
    MtVector3 mOffset0;  // offset: 0x30
    MtVector3 mOffset1;  // offset: 0x40
    MtVector3 mExtent;  // offset: 0x50
    bool mIsUseData;  // offset: 0x60
    static MyDTI DTI;
    static const u16 DATA_VERSION = 110;
};
