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
class MtPropertyList;

// Declarations
class cEmDamageDirInfo;
class rEmDamageDirInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class cEmDamageDirInfo : public MtObject
{
public:
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
    cEmDamageDirInfo();
    virtual ~cEmDamageDirInfo() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mEmCategory;  // offset: 0x8
    u32 mDmReactionType;  // offset: 0xc
    u32 mDirJudgeType;  // offset: 0x10
    bool mIsAdjustDir;  // offset: 0x14
    bool mIsWeightSpeedXZ;  // offset: 0x15
    bool mIsWeightSpeedY;  // offset: 0x16
    bool mIsWeightAccXZ;  // offset: 0x17
    bool mIsWeightAccY;  // offset: 0x18
    static MyDTI DTI;
};

class rEmDamageDirInfo : public rTbl2<cEmDamageDirInfo>
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
    virtual bool loadData(MtDataReader& in, cEmDamageDirInfo* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

inline cEmDamageDirInfo::cEmDamageDirInfo() {
    this->mEmCategory = 0;
    this->mDmReactionType = 263;
    this->mIsWeightAccY = false;
    this->mDirJudgeType = 0;
    this->mIsAdjustDir = false;
    this->mIsWeightSpeedXZ = false;
    this->mIsWeightSpeedY = false;
    this->mIsWeightAccXZ = false;
}
