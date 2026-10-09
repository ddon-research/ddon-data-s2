#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "nDDOUtility.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtPropertyList;
class MtVector3;

// Declarations
class cShotReqInfo2;
class rShotReqInfo2;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cShotReqInfo2 : public MtObject
{
public:
    enum SHOT_REQ_TYPE
    {
        SHOT_REQ_TYPE_DEFAULT = 2,
        SHOT_REQ_TYPE_FURY = 4,
        SHOT_REQ_TYPE_EROSION_S = 8,
        SHOT_REQ_TYPE_EROSION_M = 16,
        SHOT_REQ_TYPE_EROSION_L = 32,
        SHOT_REQ_TYPE_EROSION_ALIVE_PARTS_1 = 64,
        SHOT_REQ_TYPE_EROSION_ALIVE_PARTS_2 = 128,
        SHOT_REQ_TYPE_EROSION_ALIVE_PARTS_3 = 256,
        SHOT_REQ_TYPE_NO_EROSION = 512,
        SHOT_REQ_TYPE_EROSION_LL = 1024,
        SHOT_REQ_TYPE_EROSION_ALIVE_PARTS_4 = 2048,
        SHOT_REQ_TYPE_CHECK_LIVE_REGION = 4096,
        SHOT_REQ_TYPE_NO_FURY = 8192,
        SHOT_REQ_TYPE_CHECK_HP_RATE = 16384,
    };
public:
    class MyDTI;
    struct stShotReq2Param;
public:
    using SHOT_REQ_INF_ARRAY = nDDOUtility::cArray<cShotReqInfo2::stShotReq2Param, 3>;
    using SHOT_REQ_INFO = cShotReqInfo2::stShotReq2Param;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stShotReq2Param
    {
    public:
        bool mIsUse;  // offset: 0x0
        bool mIsLockOnTarget;  // offset: 0x1
        bool mIsConst;  // offset: 0x2
        u32 mShotFlag;  // offset: 0x4
        u32 mShotGroup;  // offset: 0x8
        u32 mShotIndex;  // offset: 0xc
        u32 mSetTarget;  // offset: 0x10
        u32 mJointNo;  // offset: 0x14
        MtVector3 mOffsetPos;  // offset: 0x20
        MtVector3 mOffsetDir;  // offset: 0x30
        u32 mLiveRegionNo;  // offset: 0x40
        s32 mEnchantElementType;  // offset: 0x44
        bool mUseAbsolutePos;  // offset: 0x48
        f32 mHpRateLimit1;  // offset: 0x4c
        f32 mHpRateLimit2;  // offset: 0x50
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
    cShotReqInfo2();
    cShotReqInfo2(const cShotReqInfo2&);
    // Address: 0x01aa60b0 - 0x01aa60b1 (1 bytes)
    virtual ~cShotReqInfo2() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    SHOT_REQ_INF_ARRAY mData;  // offset: 0x10
    static MyDTI DTI;
    static const s16 MAX_REQ_NUM = 3;
    static const u16 DATA_VERSION = 9;
};

class rShotReqInfo2 : public rTbl2<cShotReqInfo2>
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
    virtual bool loadData(MtDataReader& in, cShotReqInfo2* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    static MyDTI DTI;
};
