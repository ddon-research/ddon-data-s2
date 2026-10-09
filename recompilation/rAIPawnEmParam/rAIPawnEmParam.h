#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cAIObject.h"
#include "../shared/nDDOUtility.h"
#include "../shared/rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;

// Declarations
class cAIPawnEmNode;
class rAIPawnEmParam;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cAIPawnActionGroupFlag = nDDOUtility::cBitSet<128>;
using cAIPawnEmParamFlag = nDDOUtility::cBitSet<6>;
using cAIPawnTargetPosFlag = nDDOUtility::cBitSet<64>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cAIPawnEmNode : public cAIResource
{
public:
    enum
    {
        SP_STATE_NONE = 0,
        SP_STATE_YUSA_CHANGE_OCD = 1,
        SP_STATE_YUSA_CHANGE_SEQ = 2,
        SP_STATE_YUSA_CHANGE_ALL = 3,
    };
    enum
    {
        DATA_VERSION = 15,
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
    cAIPawnEmNode();
    virtual ~cAIPawnEmNode();
public:
    u32 mEmStatusNo;  // offset: 0x8
    cAIPawnActionGroupFlag mWeakAttrFlag;  // offset: 0xc
    cAIPawnActionGroupFlag mDisableAttrFlag;  // offset: 0x1c
    cAIPawnTargetPosFlag mTargetPosFlag;  // offset: 0x2c
    s32 mActiveCoreRegionNo;  // offset: 0x34
    s32 mAddPrio;  // offset: 0x38
    cAIPawnEmParamFlag mAIPawnEmParamFlag;  // offset: 0x3c
    bool mFlgDefaultAttr;  // offset: 0x40
    bool mAttackNoInterval;  // offset: 0x41
    s32 mLayer;  // offset: 0x44
    s32 mActiveMaskEffectResionNo;  // offset: 0x48
    s32 mEmSpStatus;  // offset: 0x4c
    static MyDTI DTI;
};

class rAIPawnEmParam : public rTbl2<cAIPawnEmNode>
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
    rAIPawnEmParam();
    virtual ~rAIPawnEmParam();
    virtual bool loadData(MtDataReader& r, cAIPawnEmNode* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    virtual bool loadCore(MtDataReader& r);  // vtable slot 21
    virtual f32 getDistance() const;  // vtable slot 22
public:
    f32 mDistance;  // offset: 0x7c
    f32 mRangeSize;  // offset: 0x80
    u32 mRootPoint;  // offset: 0x84
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline rAIPawnEmParam::rAIPawnEmParam() {
    this->mDistance = 300.0f;
    this->mRangeSize = 50.0f;
    this->mRootPoint = static_cast<u32>(0);
}
