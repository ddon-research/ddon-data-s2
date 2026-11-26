#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;
class MtVector3;
class uShlBase;

// Declarations
class cShlFuwaFuwaCtrl2;
class cShlFuwaFuwaInfo2;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlFuwaFuwaCtrl2 : public MtObject
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
    cShlFuwaFuwaCtrl2();
    virtual ~cShlFuwaFuwaCtrl2();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void init(uShlBase* pShl, const cShlFuwaFuwaInfo2& srcInfo);
    void updateFuwa(uShlBase* pShl, f32 deltaTime);
    bool isEnd() const;
private:
    f32 updateFuwaCore(f32& timer, f32& period, f32& scale, f32 initPeriod, f32 initScale, f32 initRandom, f32 deltaTime);
private:
    MtVector3 mPos;  // offset: 0x10
    MtVector3 mDisplace;  // offset: 0x20
    MtVector3 mPeriodTimer;  // offset: 0x30
    MtVector3 mPeriod;  // offset: 0x40
    MtVector3 mScale;  // offset: 0x50
    MtVector3 mInitPeriod;  // offset: 0x60
    MtVector3 mInitScale;  // offset: 0x70
    MtVector3 mInitRandom;  // offset: 0x80
    MtVector3 mInitShlDir;  // offset: 0x90
    f32 mSeqTimer;  // offset: 0xa0
    f32 mInitInterFrame;  // offset: 0xa4
    f32 mInterFrame;  // offset: 0xa8
    u32 mFuwaFuwaOption;  // offset: 0xac
    bool mIsEnd;  // offset: 0xb0
public:
    static MyDTI DTI;
};

class cShlFuwaFuwaInfo2 : public MtObject
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
    cShlFuwaFuwaInfo2();
    virtual ~cShlFuwaFuwaInfo2();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    void copy(const cShlFuwaFuwaInfo2& srcInfo);
public:
    f32 mPeriod;  // offset: 0x8
    f32 mScale;  // offset: 0xc
    f32 mRandom;  // offset: 0x10
    f32 mTime;  // offset: 0x14
    f32 mInterFrame;  // offset: 0x18
    u32 mFuwaFuwaOption;  // offset: 0x1c
    static MyDTI DTI;
};

inline void* cShlFuwaFuwaCtrl2::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* cShlFuwaFuwaInfo2::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
