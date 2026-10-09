#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtVector2;

// Declarations
class cHeadCtrl;
class rHeadCtrl;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cHeadCtrl : public MtObject
{
public:
    enum
    {
        DATA_VERSION = 1,
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
    cHeadCtrl();
    // Address: 0x01a93bd0 - 0x01a93bd1 (1 bytes)
    virtual ~cHeadCtrl() {}
public:
    s32 mJntNo;  // offset: 0x8
    f32 mAngleBlend;  // offset: 0xc
    MtVector2 mAngleLimit;  // offset: 0x10
    bool mLocal;  // offset: 0x18
    u32 mLocalAxis;  // offset: 0x1c
    f32 mPitchBlend;  // offset: 0x20
    MtVector2 mPitchLimit;  // offset: 0x28
    static MyDTI DTI;
};

class rHeadCtrl : public rTbl2<cHeadCtrl>
{
public:
    enum
    {
        MOT_SYNC_ON_SEQUENCE = 0,
        MOT_SYNC_OFF_SEQUENCE = 1,
        MOT_SYNC_MANUAL = 2,
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
    rHeadCtrl();
    virtual bool loadData(MtDataReader& r, cHeadCtrl* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    virtual bool loadCore(MtDataReader& r);  // vtable slot 21
public:
    s32 mBaseJntNo;  // offset: 0x7c
    f32 mBaseAngleSpeed;  // offset: 0x80
    MtVector2 mBaseAngleLimit;  // offset: 0x88
    f32 mPitchSpeed;  // offset: 0x90
    MtVector2 mBasePitchLimit;  // offset: 0x98
    MtVector2 mSafeRange;  // offset: 0xa0
    u32 mMotionSync;  // offset: 0xa8
    u32 mSeqPage;  // offset: 0xac
    u32 mSeqNo;  // offset: 0xb0
    static MyDTI DTI;
};
