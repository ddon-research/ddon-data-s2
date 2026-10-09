#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "nErosionEnemyBase.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;

// Declarations
class cErosionInfoRes;
class cErosionRegionRes;
class cErosionSmallInfoRes;
class cErosionSuperInfoRes;
class rErosionInfoRes;
class rErosionRegion;
class rErosionSmallInfoRes;
class rErosionSuperInfoRes;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cErosionInfoRes : public MtObject
{
    // inferred: rErosionInfoRes::loadData names cErosionInfoRes::mRegenerateTimer[0]
    friend class rErosionInfoRes;
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
    f32 getRegenerateTimer(nErosionEnemyBase::EROSION_LEVEL level) const;
    f32 getCancelTimer(nErosionEnemyBase::EROSION_LEVEL level) const;
    cErosionInfoRes();
    // Address: 0x01a8e1f0 - 0x01a8e1f1 (1 bytes)
    virtual ~cErosionInfoRes() {}
private:
    f32 mRegenerateTimer[4];  // offset: 0x8
    f32 mCancelTimer[5];  // offset: 0x18
public:
    static MyDTI DTI;
};

class cErosionRegionRes : public MtObject
{
    // inferred: rErosionRegion::loadData names cErosionRegionRes::mRegionCategory
    friend class rErosionRegion;
public:
    enum
    {
        DATA_VERSION = 6,
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
    s32 getRegionCategory() const;
    s32 getRegeneratePriority() const;
    s32 getJointNo() const;
    s32 getBreakShlIndex() const;
    s32 getGenerateShlIndex() const;
    s32 getJointNo2() const;
    s32 getBreakShlIndex2() const;
    s32 getGenerateShlIndex2() const;
    s32 getJointNo3() const;
    s32 getBreakShlIndex3() const;
    s32 getGenerateShlIndex3() const;
    s32 getScaleJointNo() const;
    s32 getScaleJointNo2() const;
    s32 getScaleChangeType() const;
    void copyParam(const cErosionRegionRes& data);
    cErosionRegionRes();
    // Address: 0x01a8e240 - 0x01a8e241 (1 bytes)
    virtual ~cErosionRegionRes() {}
private:
    s32 mRegionCategory;  // offset: 0x8
    s32 mRegeneratePriority;  // offset: 0xc
    s32 mJointNo;  // offset: 0x10
    s32 mBreakShlIndex;  // offset: 0x14
    s32 mGenerateShlIndex;  // offset: 0x18
    s32 mJointNo2;  // offset: 0x1c
    s32 mBreakShlIndex2;  // offset: 0x20
    s32 mGenerateShlIndex2;  // offset: 0x24
    s32 mJointNo3;  // offset: 0x28
    s32 mBreakShlIndex3;  // offset: 0x2c
    s32 mGenerateShlIndex3;  // offset: 0x30
    s32 mScaleJointNo;  // offset: 0x34
    s32 mScaleJointNo2;  // offset: 0x38
    s32 mScaleChangeType;  // offset: 0x3c
public:
    static MyDTI DTI;
};

class cErosionSmallInfoRes : public MtObject
{
    // inferred: rErosionSmallInfoRes::loadData names cErosionSmallInfoRes::mCancelTimer
    friend class rErosionSmallInfoRes;
public:
    enum
    {
        DATA_VERSION = 4,
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
    f32 getCancelTimer() const;
    f32 getCancelWaitTimer() const;
    f32 getScaleActiveRate() const;
    f32 getScaleInActiveMax() const;
    f32 getScaleInActiveMin() const;
    cErosionSmallInfoRes();
    // Address: 0x01a8e290 - 0x01a8e291 (1 bytes)
    virtual ~cErosionSmallInfoRes() {}
private:
    f32 mCancelTimer;  // offset: 0x8
    f32 mCancelWaitTimer;  // offset: 0xc
    f32 mScaleActiveRate;  // offset: 0x10
    f32 mScaleInActiveMax;  // offset: 0x14
    f32 mScaleInActiveMin;  // offset: 0x18
public:
    static MyDTI DTI;
};

class cErosionSuperInfoRes : public MtObject
{
    // inferred: rErosionSuperInfoRes::loadData names cErosionSuperInfoRes::mCorepointType
    friend class rErosionSuperInfoRes;
public:
    enum
    {
        DATA_VERSION = 4,
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
    s32 getCorePointType() const;
    f32 getAdjustDamageRate() const;
    f32 getApearTime() const;
    s32 getResgonCategory() const;
    void copyParam(const cErosionSuperInfoRes& data);
    cErosionSuperInfoRes();
    // Address: 0x01a8e2e0 - 0x01a8e2e1 (1 bytes)
    virtual ~cErosionSuperInfoRes() {}
private:
    s32 mCorepointType;  // offset: 0x8
    f32 mAdjustDamageRate;  // offset: 0xc
    f32 mApearTime;  // offset: 0x10
    s32 mRegionCategory;  // offset: 0x14
public:
    static MyDTI DTI;
};

class rErosionInfoRes : public rTbl2<cErosionInfoRes>
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
    virtual bool loadData(MtDataReader& r, cErosionInfoRes* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rErosionRegion : public rTbl2<cErosionRegionRes>
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
    virtual bool loadData(MtDataReader& r, cErosionRegionRes* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rErosionSmallInfoRes : public rTbl2<cErosionSmallInfoRes>
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
    virtual bool loadData(MtDataReader& r, cErosionSmallInfoRes* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rErosionSuperInfoRes : public rTbl2<cErosionSuperInfoRes>
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
    virtual bool loadData(MtDataReader& r, cErosionSuperInfoRes* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline s32 cErosionRegionRes::getRegionCategory() const {
    return this->mRegionCategory;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline f32 cErosionSmallInfoRes::getScaleActiveRate() const {
    return this->mScaleActiveRate;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline f32 cErosionSmallInfoRes::getScaleInActiveMax() const {
    return this->mScaleInActiveMax;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline f32 cErosionSmallInfoRes::getScaleInActiveMin() const {
    return this->mScaleInActiveMin;
}

// Inline, no code of its own: checked where it is inlined.
inline cErosionSmallInfoRes::cErosionSmallInfoRes() {
    this->mCancelTimer = 360.0f;
    this->mCancelWaitTimer = 60.0f;
    this->mScaleActiveRate = 1.0f;
    this->mScaleInActiveMax = 1.0f;
    this->mScaleInActiveMin = 1.0f;
}
