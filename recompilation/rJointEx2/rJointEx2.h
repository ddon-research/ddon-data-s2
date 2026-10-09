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
class MtVector3;

// Declarations
class cJointEx2;
class rJointEx2;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cJointEx2 : public MtObject
{
public:
    enum
    {
        DATA_VERSION = 3,
    };
    enum
    {
        AXIS_NONE = 0,
        AXIS_X = 1,
        AXIS_Y = 2,
        AXIS_Z = 3,
        AXIS_XY = 4,
        AXIS_XZ = 5,
        AXIS_YZ = 6,
        AXIS_XYZ = 7,
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
    cJointEx2();
    // Address: 0x01a969f0 - 0x01a969f1 (1 bytes)
    virtual ~cJointEx2() {}
public:
    u8 mJntNo;  // offset: 0x8
    u8 mRefJntNo;  // offset: 0x9
    u8 mAxis;  // offset: 0xa
    u8 mLimitAxis;  // offset: 0xb
    f32 mRate;  // offset: 0xc
    f32 mTwistRate;  // offset: 0x10
    MtVector3 mRotAdd;  // offset: 0x20
    f32 mLimitMin;  // offset: 0x30
    f32 mLimitMax;  // offset: 0x34
    static MyDTI DTI;
};

class rJointEx2 : public rTbl2<cJointEx2>
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
    rJointEx2();
    virtual ~rJointEx2();
    virtual bool loadData(MtDataReader& r, cJointEx2* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
    virtual bool loadCore(MtDataReader& r);  // vtable slot 21
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline rJointEx2::rJointEx2() {
}
