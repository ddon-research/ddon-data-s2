#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class cUnit;
class cpChantCommand;
class cpJob06;
class cpJob08;
class cpJob09;
class sEffectExt;
class uHuman;
class uPlayer;
class uShlAlchemy;
class uShlBakuensen;

// Declarations
class cEfcHandle;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class cEfcHandle : public MtObject
{
    // inferred: cpChantCommand::updateEfcHandle names cEfcHandle::mpOwner
    friend class cpChantCommand;
    // inferred: cpJob06::updateEfcHandle names cEfcHandle::mpOwner
    friend class cpJob06;
    // inferred: cpJob08::updateEfcHandle names cEfcHandle::mpOwner
    friend class cpJob08;
    // inferred: cpJob09::updateEfcHandle names cEfcHandle::mpOwner
    friend class cpJob09;
    // inferred: sEffectExt::setHandleOwner names cEfcHandle::mpOwner
    friend class sEffectExt;
    // inferred: uHuman::updateEfcHandle names cEfcHandle::mpOwner
    friend class uHuman;
    // inferred: uPlayer::updateEfcHandle names cEfcHandle::mpOwner
    friend class uPlayer;
    // inferred: uShlAlchemy::updateEfcHandle names cEfcHandle::mpOwner
    friend class uShlAlchemy;
    // inferred: uShlBakuensen::updateEfcHandle names cEfcHandle::mpOwner
    friend class uShlBakuensen;
public:
    enum EFC_UNIT_TYPE
    {
        EFC_UNIT_TYPE_EFFECT = 0,
        EFC_UNIT_TYPE_EFFECT2D = 1,
        EFC_UNIT_TYPE_SIMPLE = 2,
        EFC_UNIT_TYPE_CAMERA = 3,
        EFC_UNIT_TYPE_PRJTEX = 4,
        EFC_UNIT_TYPE_INVALID = 5,
        EFC_UNIT_TYPE_MAX = 6,
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
    cEfcHandle();
    // Address: 0x01968060 - 0x01968061 (1 bytes)
    virtual ~cEfcHandle() {}
    void setUnitType(u32 type);
    u32 getUnitType() const;
    void setUniqueID(u64 id);
    u64 getUniqueID() const;
    void setGroupID(u64 id, u32 no);
    u64 getGroupID(u32 no) const;
    void setOwner(cUnit* pOwner);
    cUnit* getOwner();
    void setE2DParam(u32 e2dType, s32 index, s32 element);
    bool isExistE2D(u32 e2dType, s32 index, s32 element);
    void addRef();
    void setEventNo(u32 no);
    u32 getEventNo();
    void setEventOwner(cUnit* pOwner);
    cUnit* getEventOwner();
    void setArrowJointNo(s32);
    s32 getArrowJointNo() const;
public:
    cEfcHandle* mpNext;  // offset: 0x8
    u32 mRefCount;  // offset: 0x10
private:
    u32 UnitType;  // offset: 0x14
    u64 UniqueID;  // offset: 0x18
    u64 GroupID[8];  // offset: 0x20
    cUnit* mpOwner;  // offset: 0x60
    u32 mE2DType;  // offset: 0x68
    s32 mIndex;  // offset: 0x6c
    s32 mElement;  // offset: 0x70
    u32 mEventNo;  // offset: 0x74
    cUnit* mpEventOwner;  // offset: 0x78
    s32 mArrowJointNo;  // offset: 0x80
public:
    static MyDTI DTI;
    static const u64 InvalidID = 18446744073709551615u;
    static const u32 EFC_LIST_MAX = 8;
};

// Inline, no code of its own: checked where it is inlined.
inline cEfcHandle::cEfcHandle() {
    this->UnitType = static_cast<u32>(5);
    this->GroupID[7] = static_cast<long unsigned int>(-1);
    this->GroupID[6] = static_cast<long unsigned int>(-1);
    this->GroupID[5] = static_cast<long unsigned int>(-1);
    this->GroupID[4] = static_cast<long unsigned int>(-1);
    this->GroupID[3] = static_cast<long unsigned int>(-1);
    this->GroupID[2] = static_cast<long unsigned int>(-1);
    this->GroupID[1] = static_cast<long unsigned int>(-1);
    this->GroupID[0] = static_cast<long unsigned int>(-1);
    this->UniqueID = static_cast<u64>(-1);
    this->mpNext = static_cast<cEfcHandle*>(nullptr);
    this->mRefCount = static_cast<u32>(0);
    this->mpEventOwner = static_cast<cUnit*>(nullptr);
    this->mElement = static_cast<s32>(0);
    this->mEventNo = static_cast<u32>(0);
    this->mE2DType = static_cast<u32>(0);
    this->mIndex = static_cast<s32>(0);
    this->mpOwner = static_cast<cUnit*>(nullptr);
    this->mArrowJointNo = static_cast<s32>(-1);
}
