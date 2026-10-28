#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/rTable.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;
class MtStream;
class MtVector3;

// Declarations
class cEmEffectTable;
class rEmEffectTable;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cEmEffectTable : public MtObject
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
    cEmEffectTable();
    // Address: 0x01a86a20 - 0x01a86a21 (1 bytes)
    virtual ~cEmEffectTable() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mIdx;  // offset: 0x8
    u32 mEffectSyncBitNo;  // offset: 0xc
    u32 mEffectResNo;  // offset: 0x10
    s32 mEffectEndType;  // offset: 0x14
    s32 mEffectIndexNo;  // offset: 0x18
    s32 mEffectElementNo;  // offset: 0x1c
    bool mDieNoCall;  // offset: 0x20
    u32 mBoneNo;  // offset: 0x24
    MtVector3 mOffsetPos;  // offset: 0x30
    static MyDTI DTI;
    static const u16 DATA_VERSION = 258;
};

class rEmEffectTable : public rTable
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
    rEmEffectTable();
    virtual const MtDTI& getDataDTI();  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u16 getDataVersion();  // vtable slot 18
    virtual bool load(MtStream& in);  // vtable slot 11
    bool loadData(MtDataReader& in);
    virtual bool save(MtStream& out);  // vtable slot 12
    bool saveData(MtDataWriter& out);
    bool loadData(MtDataReader& in, cEmEffectTable* pData);
    bool saveData(MtDataWriter& out, cEmEffectTable* pData);
    cEmEffectTable* getData(u32 Idx);
    void setData(MtObject*, u32);
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: parameters bound at each inlined copy's entry: the body its copies' regions agree on (026 P6b1); approximate: no recompile checks it; 2 of its copies unread: a parameter in memory or a frame slot at the entry (026 plan-P80, ruling D-C4), so approximate at most
inline cEmEffectTable::cEmEffectTable() {
    // inferred: the member constructor inlined with no DWARF copy left no code: MtVector3() (only stores of constants, dead under this body's; ruling D-P69b)
    this->mIdx = 1;
    this->mDieNoCall = false;
    this->mEffectSyncBitNo = 0;
    this->mEffectResNo = 0;
    this->mEffectEndType = 4;
    this->mEffectIndexNo = 0;
    this->mEffectElementNo = 0;
    this->mBoneNo = 255;
    this->mOffsetPos.z = 0.0f;
    this->mOffsetPos.pad_ = 0.0f;
    this->mOffsetPos.x = 0.0f;
    this->mOffsetPos.y = 0.0f;
}
