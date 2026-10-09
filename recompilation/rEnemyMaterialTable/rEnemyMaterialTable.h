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
class cEnemyMaterialTable;
class rEnemyMaterialTable;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cEnemyMaterialTable : public MtObject
{
public:
    enum
    {
        EM_MAT_TYPE_NOT = 0,
        EM_MAT_TYPE_BLOODSTAIN = 1,
        EM_MAT_TYPE_WEAKPOINT = 2,
        EM_MAT_TYPE_ANIMATION = 3,
        EM_MAT_TYPE_MAX = 4,
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
    cEnemyMaterialTable();
    // Address: 0x01a8b590 - 0x01a8b591 (1 bytes)
    virtual ~cEnemyMaterialTable() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mIdx;  // offset: 0x8
    u32 mMaterialType;  // offset: 0xc
    s32 mMaterialNo;  // offset: 0x10
    u32 mMaterialWeakPointNo;  // offset: 0x14
    u32 mMaterialAnimationType;  // offset: 0x18
    bool mDieIsNoCall;  // offset: 0x1c
    static MyDTI DTI;
    static const u16 DATA_VERSION = 260;
};

class rEnemyMaterialTable : public rTbl2<cEnemyMaterialTable>
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
    virtual bool loadData(MtDataReader& in, cEnemyMaterialTable* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cEnemyMaterialTable::cEnemyMaterialTable() {
    this->mIdx = static_cast<u32>(1);
    this->mDieIsNoCall = false;
    this->mMaterialWeakPointNo = static_cast<u32>(0);
    this->mMaterialAnimationType = static_cast<u32>(0);
    this->mMaterialType = static_cast<u32>(0);
    this->mMaterialNo = static_cast<s32>(0);
}
