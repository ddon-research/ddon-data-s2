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
class cNpcIsUseJobParamEx;
class rNpcIsUseJobParamEx;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class cNpcIsUseJobParamEx : public MtObject
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
    static MT_CTSTR getResName();
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
    cNpcIsUseJobParamEx();
    // Address: 0x01a9f310 - 0x01a9f311 (1 bytes)
    virtual ~cNpcIsUseJobParamEx() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    bool hasSameAttributes(u16 stageNo, u16 groupNo, u8 unitNo, u32 questId) const;
private:
    u16 mStageNo;  // offset: 0x8
    u16 mGroupNo;  // offset: 0xa
    u8 mUnitNo;  // offset: 0xc
    u32 mQuestId;  // offset: 0x10
public:
    static const u32 DATA_VERSION = 1;
    static MyDTI DTI;
};

class rNpcIsUseJobParamEx : public rTbl2<cNpcIsUseJobParamEx>
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
    virtual bool loadData(MtDataReader& in, cNpcIsUseJobParamEx* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cNpcIsUseJobParamEx::cNpcIsUseJobParamEx() {
    this->mStageNo = static_cast<u16>(0);
    this->mGroupNo = static_cast<u16>(0);
    this->mUnitNo = static_cast<u8>(0);
    this->mQuestId = static_cast<u32>(0);
}
