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
class cCatchInfoParam;
class rCatchInfoParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cCatchInfoParam : public MtObject
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
    cCatchInfoParam();
    cCatchInfoParam(const cCatchInfoParam&);
    // Address: 0x01a7ae60 - 0x01a7ae61 (1 bytes)
    virtual ~cCatchInfoParam() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mCatchType;  // offset: 0x8
    u32 mCatchActionTblNo;  // offset: 0xc
    bool mIsConst;  // offset: 0x10
    bool mRevAdjust;  // offset: 0x11
    bool mConstScaleOff;  // offset: 0x12
    bool mIsCheckSlaveDist;  // offset: 0x13
    f32 mCheckSlaveDist;  // offset: 0x14
    u32 mConstJointNo;  // offset: 0x18
    f32 mLoopTimer;  // offset: 0x1c
    s32 mLeverGachaPoint;  // offset: 0x20
    static MyDTI DTI;
    static const u16 DATA_VERSION = 18;
};

class rCatchInfoParam : public rTbl2<cCatchInfoParam>
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
    virtual bool loadData(MtDataReader& in, cCatchInfoParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cCatchInfoParam::cCatchInfoParam() {
    this->mCatchType = static_cast<u32>(0);
    this->mCatchActionTblNo = static_cast<u32>(0);
    this->mIsConst = true;
    this->mRevAdjust = false;
    this->mConstScaleOff = false;
    this->mConstJointNo = static_cast<u32>(255);
    this->mLoopTimer = 150.0f;
    this->mLeverGachaPoint = static_cast<s32>(50);
    this->mIsCheckSlaveDist = false;
    this->mCheckSlaveDist = 200.0f;
}
