#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtPrimitive3D.h"
#include "../shared/MtString.h"
#include "../shared/cResource.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtDTI;
class MtString;

// Declarations
class rAIPathConsecutive;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class rAIPathConsecutive : public cResource
{
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR, MtDTI*, size_t, u32, u32);
    };
public:
    static MtDTI* getMyDTIPtr();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    MtAABB getRegion();
    u32 getDivision();
    u32 getNumberOfResource();
    u32 getNumberOfDivisionX();
    u32 getNumberOfDivisionZ();
    u32 getFigure();
    u32 getArray();
    u32 getConsectiveStartX();
    u32 getConsectiveEndX();
    u32 getConsectiveStartZ();
    u32 getConsectiveEndZ();
    const MtString& getResourceString0();
    const MtString& getResourceString1();
    const MtString& getResourceString2();
    u32 getConnectInfo(u32 index);
protected:
    MtAABB mRegion;  // offset: 0x70
    u32 mDivision;  // offset: 0x90
    u32 mNumberOfX;  // offset: 0x94
    u32 mNumberOfZ;  // offset: 0x98
    u32 mFigure;  // offset: 0x9c
    u32 mArray;  // offset: 0xa0
    u32 mStartX;  // offset: 0xa4
    u32 mEndX;  // offset: 0xa8
    u32 mStartZ;  // offset: 0xac
    u32 mEndZ;  // offset: 0xb0
    u32 mNumberOfResource;  // offset: 0xb4
    MtString mFieldName0;  // offset: 0xb8
    MtString mFieldName1;  // offset: 0xc0
    MtString mFieldName2;  // offset: 0xc8
    u16* mpNumberOfConnect;  // offset: 0xd0
public:
    static MyDTI DTI;
    static const u32 DATA_VERSION = 5;
};
