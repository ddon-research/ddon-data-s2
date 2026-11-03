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
class cRegionBreakInfo;
class rRegionBreakInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cRegionBreakInfo : public MtObject
{
    friend class rRegionBreakInfo;
public:
    enum
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
    cRegionBreakInfo();
    virtual ~cRegionBreakInfo() {}
    s32 getRegionJointNo() const;
public:
    s32 mLockOnJointID;  // offset: 0x8
    s32 mLockOffJointID;  // offset: 0xc
private:
    s32 mSoundJointNo;  // offset: 0x10
public:
    static MyDTI DTI;
};

class rRegionBreakInfo : public rTbl2<cRegionBreakInfo>
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
    virtual bool loadData(MtDataReader& r, cRegionBreakInfo* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

inline void* cRegionBreakInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cRegionBreakInfo::cRegionBreakInfo() {
    this->mLockOnJointID = 0;
    this->mLockOffJointID = -1;
    this->mSoundJointNo = -1;
}

inline s32 cRegionBreakInfo::getRegionJointNo() const {
    return this->mSoundJointNo;
}

inline void* rRegionBreakInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void cRegionBreakInfo::operator delete[](void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cRegionBreakInfo::DTI)->memFree(p_addr);
}

inline void* cRegionBreakInfo::operator new[](size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cRegionBreakInfo::DTI)->memAlloc(sz, align, ::cRegionBreakInfo::DTI.::MtDTI::getID());
}
