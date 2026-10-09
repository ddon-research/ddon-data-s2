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
class cCraftCapPassData;
class rCraftCapPass;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cCraftCapPassData : public MtObject
{
public:
    enum
    {
        TYPE_NONE = 0,
        TYPE_CAP_PASS = 1,
        TYPE_NUM = 2,
    };
    enum ResStatus
    {
        DATA_VERSION = 2,
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
    cCraftCapPassData();
    // Address: 0x01a81080 - 0x01a81081 (1 bytes)
    virtual ~cCraftCapPassData() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    u32 getRecipeId();
    u16 getStartLv();
    u16 getLvCap();
    u16 getVer();
    u8 getRound();
    u8 getType();
public:
    u32 mRecipeId;  // offset: 0x8
    u16 mStartLv;  // offset: 0xc
    u16 mLvCap;  // offset: 0xe
    u16 mVer;  // offset: 0x10
    u8 mRound;  // offset: 0x12
    u8 mType;  // offset: 0x13
    static MyDTI DTI;
};

class rCraftCapPass : public rTbl2<cCraftCapPassData>
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
    virtual bool loadData(MtDataReader& in, cCraftCapPassData* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cCraftCapPassData::cCraftCapPassData() {
    this->mRecipeId = static_cast<u32>(0);
    this->mStartLv = static_cast<u16>(1);
    this->mLvCap = static_cast<u16>(1);
    this->mVer = static_cast<u16>(0);
    this->mRound = static_cast<u8>(1);
    this->mType = static_cast<u8>(0);
}
