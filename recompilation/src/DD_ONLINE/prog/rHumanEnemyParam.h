#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "nJobParam.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;

// Declarations
class cHumanEnemyParam;
class rHumanEnemyParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cHumanEnemyParam : public nJobParam::cJobInfo
{
public:
    enum
    {
        DATA_VERSION = 10,
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
    cHumanEnemyParam();
    virtual ~cHumanEnemyParam() {}
public:
    u32 mMaxHp;  // offset: 0x70
    u32 mGuardDef;  // offset: 0x74
    u32 mWepAtk;  // offset: 0x78
    u32 mWepMAtk;  // offset: 0x7c
    u32 mGuardCounterCnt;  // offset: 0x80
    f32 mReturnTerritoryContTime;  // offset: 0x84
    u8 mBeardownEffective;  // offset: 0x88
    static MyDTI DTI;
};

class rHumanEnemyParam : public rTbl2<cHumanEnemyParam>
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
    virtual bool loadData(MtDataReader& in, cHumanEnemyParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

inline void* cHumanEnemyParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cHumanEnemyParam::cHumanEnemyParam() {
    this->mMaxHp = 0;
    this->mGuardDef = 500;
    this->mWepAtk = 50;
    this->mWepMAtk = 50;
    this->mGuardCounterCnt = 3;
    this->mReturnTerritoryContTime = 5400.0f;
    this->mBeardownEffective = 0;
}

inline void* rHumanEnemyParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void cHumanEnemyParam::operator delete[](void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cHumanEnemyParam::DTI)->memFree(p_addr);
}

inline void* cHumanEnemyParam::operator new[](size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cHumanEnemyParam::DTI)->memAlloc(sz, align, ::cHumanEnemyParam::DTI.::MtDTI::getID());
}
