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
class cCaughtInfoParam;
class rCaughtInfoParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cCaughtInfoParam : public MtObject
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
    cCaughtInfoParam();
    cCaughtInfoParam(const cCaughtInfoParam&);
    virtual ~cCaughtInfoParam() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mCatchType;  // offset: 0x8
    u32 mCaughtActionTblNo;  // offset: 0xc
    MtVector3 mConstOffsetPos;  // offset: 0x10
    MtVector3 mConstOffsetAngle;  // offset: 0x20
    static MyDTI DTI;
    static const u16 DATA_VERSION = 15;
};

class rCaughtInfoParam : public rTbl2<cCaughtInfoParam>
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
    virtual bool loadData(MtDataReader& in, cCaughtInfoParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    static MyDTI DTI;
};

inline void* cCaughtInfoParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* rCaughtInfoParam::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void cCaughtInfoParam::operator delete[](void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cCaughtInfoParam::DTI)->memFree(p_addr);
}

inline void* cCaughtInfoParam::operator new[](size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cCaughtInfoParam::DTI)->memAlloc(sz, align, ::cCaughtInfoParam::DTI.::MtDTI::getID());
}

inline void* cCaughtInfoParam::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cCaughtInfoParam::DTI)->memAlloc(sz, align, ::cCaughtInfoParam::DTI.::MtDTI::getID());
}

inline void cCaughtInfoParam::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cCaughtInfoParam::DTI)->memFree(p_addr);
}

inline cCaughtInfoParam::cCaughtInfoParam() {
    this->mCatchType = 0;
    this->mCaughtActionTblNo = 0;
    this->mConstOffsetPos.x = ::MtVector3::Zero.x;
    this->mConstOffsetPos.y = ::MtVector3::Zero.y;
    this->mConstOffsetPos.z = ::MtVector3::Zero.z;
    this->mConstOffsetPos.pad_ = 0.0f;
    this->mConstOffsetAngle.x = ::MtVector3::Zero.x;
    this->mConstOffsetAngle.y = ::MtVector3::Zero.y;
    this->mConstOffsetAngle.z = ::MtVector3::Zero.z;
    this->mConstOffsetAngle.pad_ = 0.0f;
}

inline void* rCaughtInfoParam::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::rCaughtInfoParam::DTI)->memAlloc(sz, align, ::rCaughtInfoParam::DTI.::MtDTI::getID());
}

inline void rCaughtInfoParam::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::rCaughtInfoParam::DTI)->memFree(p_addr);
}
