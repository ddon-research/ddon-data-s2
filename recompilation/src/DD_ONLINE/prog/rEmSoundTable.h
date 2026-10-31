#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtPropertyList;
class MtVector3;

// Declarations
class cEmSoundTable;
class rEmSoundTable;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cEmSoundTable : public MtObject
{
public:
    enum
    {
        REQUEST_TYPE_SE = 0,
        REQUEST_TYPE_STREAM = 1,
        REQUEST_TYPE_NUM = 2,
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
    cEmSoundTable();
    virtual ~cEmSoundTable() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mIdx;  // offset: 0x8
    bool mDieIsNoCall;  // offset: 0xc
    u32 mSoundResNo;  // offset: 0x10
    u32 mSoundNo;  // offset: 0x14
    bool mAttachFlag;  // offset: 0x18
    u32 mRequestType;  // offset: 0x1c
    s32 mBoneNo;  // offset: 0x20
    MtVector3 mOffsetPos;  // offset: 0x30
    static MyDTI DTI;
    static const u16 DATA_VERSION = 261;
};

class rEmSoundTable : public rTbl2<cEmSoundTable>
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
    virtual bool loadData(MtDataReader& in, cEmSoundTable* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

inline cEmSoundTable::cEmSoundTable() {
    this->mIdx = 1;
    this->mSoundResNo = 0;
    this->mSoundNo = 0;
    this->mAttachFlag = false;
    this->mRequestType = 0;
    this->mBoneNo = -1;
    this->mDieIsNoCall = false;
    this->mOffsetPos.z = 0.0f;
    this->mOffsetPos.pad_ = 0.0f;
    this->mOffsetPos.x = 0.0f;
    this->mOffsetPos.y = 0.0f;
}
