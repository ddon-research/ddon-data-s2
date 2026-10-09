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

// Declarations
class cShakeCtrl;
class rShakeCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShakeCtrl : public MtObject
{
public:
    enum
    {
        DATA_VERSION = 15,
    };
    enum
    {
        IMPACT = 1,
    };
    enum
    {
        IK_R_ARM = 1,
        IK_L_ARM = 2,
        IK_R_LEG = 4,
        IK_L_LEG = 8,
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
    cShakeCtrl();
    // Address: 0x01aa55d0 - 0x01aa55d1 (1 bytes)
    virtual ~cShakeCtrl() {}
public:
    s32 mJntNo;  // offset: 0x8
    f32 mShakeRot;  // offset: 0xc
    f32 mShakeAxis;  // offset: 0x10
    f32 mShakeTrans;  // offset: 0x14
    s32 mJntNoChild;  // offset: 0x18
    f32 mChildRate;  // offset: 0x1c
    u32 mAxis;  // offset: 0x20
    u32 mFlag;  // offset: 0x24
    u32 mIK;  // offset: 0x28
    static MyDTI DTI;
};

class rShakeCtrl : public rTbl2<cShakeCtrl>
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
    rShakeCtrl();
    virtual ~rShakeCtrl();
    virtual bool loadData(MtDataReader& r, cShakeCtrl* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    virtual bool loadCore(MtDataReader& r);  // vtable slot 21
public:
    f32 mFrame;  // offset: 0x7c
    f32 mCycle;  // offset: 0x80
    f32 mRate;  // offset: 0x84
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cShakeCtrl::cShakeCtrl() {
    this->mJntNo = static_cast<s32>(-1);
    this->mShakeRot = 20.0f;
    this->mShakeAxis = 10.0f;
    this->mShakeTrans = 20.0f;
    this->mJntNoChild = static_cast<s32>(-1);
    this->mChildRate = 1.0f;
    this->mAxis = static_cast<u32>(1);
    this->mFlag = static_cast<u32>(0);
    this->mIK = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline rShakeCtrl::rShakeCtrl() {
    this->mFrame = 10.0f;
    this->mCycle = 10.0f;
    this->mRate = 1.0f;
}
