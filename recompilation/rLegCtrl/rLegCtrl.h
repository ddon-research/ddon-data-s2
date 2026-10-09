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
class cLegCtrl;
class rLegCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cLegCtrl : public MtObject
{
public:
    enum
    {
        DATA_VERSION = 12,
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
    cLegCtrl();
    // Address: 0x01a9b5a0 - 0x01a9b5a1 (1 bytes)
    virtual ~cLegCtrl() {}
public:
    u32 mValue;  // offset: 0x8
    static MyDTI DTI;
};

class rLegCtrl : public rTbl2<cLegCtrl>
{
public:
    enum LEG_TYPE
    {
        LEG_TYPE_2 = 0,
        LEG_TYPE_4_S = 1,
        LEG_TYPE_4_L = 2,
    };
    enum FLAG
    {
        FLAG_RESET_NO_GROUND = 1,
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
    rLegCtrl();
    virtual ~rLegCtrl();
    virtual bool loadData(MtDataReader& r, cLegCtrl* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    virtual bool loadCore(MtDataReader& r);  // vtable slot 21
public:
    bool mDisablePS3;  // offset: 0x7c
    f32 mDiffMax;  // offset: 0x80
    f32 mDiffMin;  // offset: 0x84
    f32 mCOGMin;  // offset: 0x88
    f32 mDiffSpeed;  // offset: 0x8c
    f32 mPitchSpeed;  // offset: 0x90
    f32 mFootDiffSpeed;  // offset: 0x94
    f32 mResetDiffSpeed;  // offset: 0x98
    f32 mResetFootDiffSpeed;  // offset: 0x9c
    f32 mHandBlend;  // offset: 0xa0
    f32 mHandHeight;  // offset: 0xa4
    f32 mHandHeel;  // offset: 0xa8
    f32 mHandToe;  // offset: 0xac
    f32 mFootBlend;  // offset: 0xb0
    f32 mFootHeight;  // offset: 0xb4
    f32 mFootToe;  // offset: 0xb8
    f32 mFootHeel;  // offset: 0xbc
    f32 mCheckHeightHand;  // offset: 0xc0
    f32 mCheckHeight;  // offset: 0xc4
    u32 mLegType;  // offset: 0xc8
    u32 mFlag;  // offset: 0xcc
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cLegCtrl::cLegCtrl() {
    this->mValue = static_cast<u32>(0);
}

// Inline, no code of its own: checked where it is inlined.
inline rLegCtrl::rLegCtrl() {
    this->mDisablePS3 = false;
    this->mDiffMax = 20.0f;
    this->mDiffMin = -20.0f;
    this->mCOGMin = -30.0f;
    this->mDiffSpeed = 2.0f;
    this->mPitchSpeed = 2.0f;
    this->mFootDiffSpeed = 100.0f;
    this->mResetDiffSpeed = 5.0f;
    this->mResetFootDiffSpeed = 5.0f;
    this->mHandBlend = 1.0f;
    this->mHandHeight = 10.0f;
    this->mHandToe = 10.0f;
    this->mHandHeel = 5.0f;
    this->mFootBlend = 1.0f;
    this->mFootHeight = 10.0f;
    this->mFootToe = 10.0f;
    this->mFootHeel = 5.0f;
    this->mCheckHeight = 100.0f;
    this->mCheckHeightHand = 100.0f;
    this->mLegType = static_cast<u32>(0);
    this->mFlag = static_cast<u32>(0);
}
