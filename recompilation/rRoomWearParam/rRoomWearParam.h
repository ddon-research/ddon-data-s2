#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtPropertyList;

// Declarations
class cRoomWearParam;
class rRoomWearParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cRoomWearParam : public MtObject
{
public:
    enum
    {
        TYPE_PL_ROOM = 0,
        TYPE_PAWN_ROOM = 1,
        TYPE_PAWN_BATH = 2,
        TYPE_PAWN_SLEEP = 3,
    };
    enum ResStatus
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
    cRoomWearParam();
    virtual ~cRoomWearParam();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    u32 getItem();
    u32 getType();
    u16 getAH(u32 sex);
    u16 getAB(u32 sex);
    u16 getWB(u32 sex);
    u16 getAA(u32 sex);
    u16 getAL(u32 sex);
    u16 getWL(u32 sex);
    u16 getAC(u32 sex);
public:
    u32 mItem;  // offset: 0x8
    u32 mType;  // offset: 0xc
    u16 mAH_M;  // offset: 0x10
    u16 mAB_M;  // offset: 0x12
    u16 mWB_M;  // offset: 0x14
    u16 mAA_M;  // offset: 0x16
    u16 mAL_M;  // offset: 0x18
    u16 mWL_M;  // offset: 0x1a
    u16 mAC_M;  // offset: 0x1c
    u16 mAH_W;  // offset: 0x1e
    u16 mAB_W;  // offset: 0x20
    u16 mWB_W;  // offset: 0x22
    u16 mAA_W;  // offset: 0x24
    u16 mAL_W;  // offset: 0x26
    u16 mWL_W;  // offset: 0x28
    u16 mAC_W;  // offset: 0x2a
    static MyDTI DTI;
};

class rRoomWearParam : public rTbl2<cRoomWearParam>
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
    virtual bool loadData(MtDataReader& in, cRoomWearParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cRoomWearParam::cRoomWearParam() {
    this->mWL_W = static_cast<u16>(0);
    this->mAC_W = static_cast<u16>(0);
    this->mAB_W = static_cast<u16>(0);
    this->mWB_W = static_cast<u16>(0);
    this->mAA_W = static_cast<u16>(0);
    this->mAL_W = static_cast<u16>(0);
    this->mAL_M = static_cast<u16>(0);
    this->mWL_M = static_cast<u16>(0);
    this->mAC_M = static_cast<u16>(0);
    this->mAH_W = static_cast<u16>(0);
    this->mAH_M = static_cast<u16>(0);
    this->mAB_M = static_cast<u16>(0);
    this->mWB_M = static_cast<u16>(0);
    this->mAA_M = static_cast<u16>(0);
    this->mItem = static_cast<u32>(0);
    this->mType = static_cast<u32>(0);
}
