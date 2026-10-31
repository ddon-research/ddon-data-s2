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
class cPrologueHmStatus;
class rPrologueHmStatus;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cPrologueHmStatus : public MtObject
{
public:
    enum
    {
        DATA_VERSION = 0,
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
    cPrologueHmStatus();
    virtual ~cPrologueHmStatus() {}
public:
    u8 mJob;  // offset: 0x8
    u8 mLv;  // offset: 0x9
    u16 mAtk;  // offset: 0xa
    u16 mDef;  // offset: 0xc
    u16 mMAtk;  // offset: 0xe
    u16 mMDef;  // offset: 0x10
    u8 mCustomId1;  // offset: 0x12
    u8 mCustomId2;  // offset: 0x13
    u8 mCustomId3;  // offset: 0x14
    u8 mCustomId4;  // offset: 0x15
    u8 mCustomId1Lv;  // offset: 0x16
    u8 mCustomId2Lv;  // offset: 0x17
    u8 mCustomId3Lv;  // offset: 0x18
    u8 mCustomId4Lv;  // offset: 0x19
    u8 mNormalId1;  // offset: 0x1a
    u8 mNormalId2;  // offset: 0x1b
    u8 mNormalId3;  // offset: 0x1c
    static MyDTI DTI;
};

class rPrologueHmStatus : public rTbl2<cPrologueHmStatus>
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
    virtual bool loadData(MtDataReader& in, cPrologueHmStatus* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

inline cPrologueHmStatus::cPrologueHmStatus() {
    this->mJob = 1;
    this->mLv = 1;
    this->mNormalId3 = 0;
    this->mNormalId1 = 0;
    this->mNormalId2 = 0;
    this->mCustomId1 = 0;
    this->mCustomId2 = 0;
    this->mCustomId3 = 0;
    this->mCustomId4 = 0;
    this->mCustomId1Lv = 0;
    this->mCustomId2Lv = 0;
    this->mCustomId3Lv = 0;
    this->mCustomId4Lv = 0;
    this->mAtk = 0;
    this->mDef = 0;
    this->mMAtk = 0;
    this->mMDef = 0;
}
