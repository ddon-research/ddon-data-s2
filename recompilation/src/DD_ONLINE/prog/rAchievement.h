#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cUIObject.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;

// Declarations
class cAchievementData;
class cAchievementHeaderData;
class rAchievement;
class rAchievementHeader;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cAchievementData : public cUIResource
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
    cAchievementData();
    virtual ~cAchievementData() {}
public:
    u32 mID;  // offset: 0x8
    u32 mTargetNum;  // offset: 0xc
    u32 mMessageIndex;  // offset: 0x10
    u8 mCategory;  // offset: 0x14
    u8 mTrophy;  // offset: 0x15
    static MyDTI DTI;
    static const u16 DATA_VERSION = 2;
};

class cAchievementHeaderData : public cUIResource
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
    cAchievementHeaderData();
    virtual ~cAchievementHeaderData() {}
public:
    u32 mNum;  // offset: 0x8
    static MyDTI DTI;
    static const u16 DATA_VERSION = 3;
};

class rAchievement : public rTbl2<cAchievementData>
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
    virtual bool loadData(MtDataReader& in, cAchievementData* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rAchievementHeader : public rTbl2<cAchievementHeaderData>
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
    virtual bool loadData(MtDataReader& in, cAchievementHeaderData* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

inline void* cAchievementData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cAchievementData::cAchievementData() {
    this->mCategory = 0;
    this->mTrophy = 0;
    this->mMessageIndex = 0;
    this->mID = 0;
    this->mTargetNum = 0;
}

inline void* cAchievementHeaderData::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cAchievementHeaderData::cAchievementHeaderData() {
    this->mNum = 0;
}

inline void* rAchievement::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* rAchievementHeader::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void cAchievementData::operator delete[](void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cAchievementData::DTI)->memFree(p_addr);
}

inline void* cAchievementData::operator new[](size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cAchievementData::DTI)->memAlloc(sz, align, ::cAchievementData::DTI.::MtDTI::getID());
}

inline void cAchievementHeaderData::operator delete[](void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cAchievementHeaderData::DTI)->memFree(p_addr);
}

inline void* cAchievementHeaderData::operator new[](size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cAchievementHeaderData::DTI)->memAlloc(sz, align, ::cAchievementHeaderData::DTI.::MtDTI::getID());
}
