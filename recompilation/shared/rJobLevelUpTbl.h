#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtDataWriter;
class MtObject;
class MtPropertyList;

// Declarations
class cIncreaseParam2;
class rJobLevelUpTbl2;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cIncreaseParam2 : public MtObject
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
    cIncreaseParam2();
    // Address: 0x01a95a60 - 0x01a95a61 (1 bytes)
    virtual ~cIncreaseParam2() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    bool loadData(MtDataReader& in);
    bool saveData(MtDataWriter& out);
public:
    u32 mLv;  // offset: 0x8
    u32 mAtk;  // offset: 0xc
    u32 mDef;  // offset: 0x10
    u32 mMAtk;  // offset: 0x14
    u32 mMDef;  // offset: 0x18
    static MyDTI DTI;
    static const u16 DATA_VERSION = 1;
};

class rJobLevelUpTbl2 : public rTbl2<cIncreaseParam2>
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
    virtual bool loadData(MtDataReader& in, cIncreaseParam2* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cIncreaseParam2::cIncreaseParam2() {
    this->mMDef = static_cast<u32>(0);
    this->mDef = static_cast<u32>(0);
    this->mMAtk = static_cast<u32>(0);
    this->mLv = static_cast<u32>(0);
    this->mAtk = static_cast<u32>(0);
}
