#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;

// Declarations
class cHumanEnemyCustomSkill;
class rHumanEnemyCustomSkill;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cHumanEnemyCustomSkill : public MtObject
{
public:
    enum
    {
        DATA_VERSION = 3,
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
    cHumanEnemyCustomSkill();
    virtual ~cHumanEnemyCustomSkill() {}
public:
    u32 mId;  // offset: 0x8
    u32 mCustomSkill0;  // offset: 0xc
    u32 mCustomSkill1;  // offset: 0x10
    u32 mCustomSkill2;  // offset: 0x14
    u32 mCustomSkill3;  // offset: 0x18
    u32 mCustomLevel0;  // offset: 0x1c
    u32 mCustomLevel1;  // offset: 0x20
    u32 mCustomLevel2;  // offset: 0x24
    u32 mCustomLevel3;  // offset: 0x28
    static MyDTI DTI;
};

class rHumanEnemyCustomSkill : public rTbl2<cHumanEnemyCustomSkill>
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
    virtual bool loadData(MtDataReader& r, cHumanEnemyCustomSkill* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

inline cHumanEnemyCustomSkill::cHumanEnemyCustomSkill() {
    this->mCustomLevel3 = 0;
    this->mCustomLevel1 = 0;
    this->mCustomLevel2 = 0;
    this->mCustomSkill3 = 0;
    this->mCustomLevel0 = 0;
    this->mCustomSkill1 = 0;
    this->mCustomSkill2 = 0;
    this->mId = 0;
    this->mCustomSkill0 = 0;
}
