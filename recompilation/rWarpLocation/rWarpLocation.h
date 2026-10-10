#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cUIObject.h"
#include "../shared/rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;

// Declarations
class cWarpLocation;
class rWarpLocation;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cWarpLocation : public cUIResource
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
    cWarpLocation();
    // Address: 0x01ab7ae0 - 0x01ab7ae1 (1 bytes)
    virtual ~cWarpLocation() {}
public:
    u32 mId;  // offset: 0x8
    u32 mSortNo;  // offset: 0xc
    u32 mAreaId;  // offset: 0x10
    u32 mSpotId;  // offset: 0x14
    s32 mStageNo;  // offset: 0x18
    u32 mPosNo;  // offset: 0x1c
    u16 mMapPosX;  // offset: 0x20
    u16 mMapPosY;  // offset: 0x22
    u8 mIconType;  // offset: 0x24
    static MyDTI DTI;
    static const u16 DATA_VERSION = 352;
};

class rWarpLocation : public rTbl2<cWarpLocation>
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
    virtual bool loadData(MtDataReader& in, cWarpLocation* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline cWarpLocation::cWarpLocation() {
    // inferred: the base constructor inlined with no DWARF copy left no code: cUIResource() (its vtable store is dead under this class's; T967's rule for a base, 024 T1016)
    this->mIconType = static_cast<u8>(0);
    this->mMapPosX = static_cast<u16>(0);
    this->mMapPosY = static_cast<u16>(0);
    this->mStageNo = static_cast<s32>(0);
    this->mPosNo = static_cast<u32>(0);
    this->mAreaId = static_cast<u32>(0);
    this->mSpotId = static_cast<u32>(0);
    this->mId = static_cast<u32>(0);
    this->mSortNo = static_cast<u32>(0);
}
