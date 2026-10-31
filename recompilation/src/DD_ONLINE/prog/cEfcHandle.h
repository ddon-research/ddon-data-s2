#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class cOmComponent;
class cPlActWpnBow;
class cUnit;
class cpChantCommand;
class cpJob06;
class cpJob08;
class cpJob09;
class cpJob10;
class sEffectExt;
class uHuman;
class uPlayer;
class uShlAlchemy;
class uShlBakuensen;
class uStageRevivalPawn;

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
    friend class cOmComponent;
    friend class cPlActWpnBow;
    friend class cpChantCommand;
    friend class cpJob06;
    friend class cpJob08;
    friend class cpJob09;
    friend class cpJob10;
    friend class sEffectExt;
    friend class uHuman;
    friend class uPlayer;
    friend class uShlAlchemy;
    friend class uShlBakuensen;
    friend class uStageRevivalPawn;
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

inline cEfcHandle::cEfcHandle() {
    this->UnitType = 5;
    this->GroupID[7] = 0xFFFFFFFFFFFFFFFFul;
    this->GroupID[6] = 0xFFFFFFFFFFFFFFFFul;
    this->GroupID[5] = 0xFFFFFFFFFFFFFFFFul;
    this->GroupID[4] = 0xFFFFFFFFFFFFFFFFul;
    this->GroupID[3] = 0xFFFFFFFFFFFFFFFFul;
    this->GroupID[2] = 0xFFFFFFFFFFFFFFFFul;
    this->GroupID[1] = 0xFFFFFFFFFFFFFFFFul;
    this->GroupID[0] = 0xFFFFFFFFFFFFFFFFul;
    this->UniqueID = 0xFFFFFFFFFFFFFFFFul;
    this->mpNext = nullptr;
    this->mRefCount = 0;
    this->mpEventOwner = nullptr;
    this->mElement = 0;
    this->mEventNo = 0;
    this->mE2DType = 0;
    this->mIndex = 0;
    this->mpOwner = nullptr;
    this->mArrowJointNo = -1;
}

inline u32 cEfcHandle::getUnitType() const {
    return this->UnitType;
}

inline u64 cEfcHandle::getUniqueID() const {
    return this->UniqueID;
}

inline void cEfcHandle::setOwner(cUnit* pOwner) {
    this->mpOwner = pOwner;
}
