#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "cLayoutSet.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cArcLoaderBase;
class cLayoutSet;

// Declarations
class cSplitArc;
class cSplitBase;
class cSplitLot;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cSplitBase : public MtObject
{
    // inferred: cSplitLot::eraseWait names cSplitBase::mStatus
    friend class cSplitLot;
public:
    enum
    {
        STATUS_READY = 0,
        STATUS_LOADING = 1,
        STATUS_USAGE = 2,
        STATUS_COMPLETE = 3,
        STATUS_UNIT = 4,
        STATUS_ERASE = 5,
        STATUS_KILL = 6,
        STATUS_ERROR = 7,
        STATUS_NO_CLASS = 8,
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
    cSplitBase();
    // Address: 0x01a61950 - 0x01a61951 (1 bytes)
    virtual ~cSplitBase() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void setStatus(s32 status);
    s32 getStatus() const;
    void setXZ(s32 x, s32 z);
    s32 getX() const;
    s32 getZ() const;
    bool hasSameXZ(s32 x, s32 z) const;
private:
    s32 mStatus;  // offset: 0x8
    s32 mIdX;  // offset: 0xc
    s32 mIdZ;  // offset: 0x10
public:
    static MyDTI DTI;
};

class cSplitLot : public cSplitBase
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
    cSplitLot();
    virtual ~cSplitLot();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void eraseWait();
    void updatePtr();
    void eraseInsListUnit();
    void setLotResource();
    bool updateLotSbcResourceUsage();
    cLayoutSet* getLotSet();
private:
    cLayoutSet mLotSet;  // offset: 0x18
    f32 mEraseTimer;  // offset: 0xa0
public:
    static MyDTI DTI;
};

class cSplitArc : public cSplitBase
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
    cSplitArc();
    virtual ~cSplitArc();
    u8 getFno() const;
    void setFno(u8);
    bool setArcTicket(s32 stageNo, s32 x, s32 z, MT_CTSTR parts, s32 areaNo);
public:
    TICKET mArcTicket;  // offset: 0x18
    u8 mFno;  // offset: 0x20
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cSplitBase::cSplitBase() {
    this->mStatus = static_cast<s32>(0);
    this->mIdX = static_cast<s32>(-1);
    this->mIdZ = static_cast<s32>(-1);
}

// Inline, no code of its own: checked where it is inlined.
inline s32 cSplitBase::getX() const {
    return this->mIdX;
}

// Inline, no code of its own: checked where it is inlined.
inline s32 cSplitBase::getZ() const {
    return this->mIdZ;
}
