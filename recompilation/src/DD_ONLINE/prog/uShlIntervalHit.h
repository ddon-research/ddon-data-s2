#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "nDDOUtility.h"
#include "uShlBase.h"
#include "uShlStick.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cHitNode;
class cShlParamBase;
class uShlBase;
class uShlStick;

// Declarations
template <typename shlclass, typename ParentClass> class cShlParamIntervalHit;
template <typename ParentClass> class uShlIntervalHit;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using floatArray = nDDOUtility::cArray<float, 10>;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

template <>
class cShlParamIntervalHit<uShlIntervalHit<uShlBase>, cShlParamBase> : public cShlParamBase
{
public:
    class MyDTI;
public:
    using ThisClass = cShlParamIntervalHit<uShlIntervalHit<uShlBase>, cShlParamBase>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamIntervalHit();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    f32 mHitInterVal;  // offset: 0x160
    s32 mSeNo;  // offset: 0x164
    s32 mEfNo;  // offset: 0x168
    s32 mColNo;  // offset: 0x16c
    bool mIsUseRandamInterVal;  // offset: 0x170
    floatArray mRandamInterVal;  // offset: 0x174
    static MyDTI DTI;
};

template <>
class cShlParamIntervalHit<uShlIntervalHit<uShlStick>, cShlParamStick> : public cShlParamStick
{
public:
    class MyDTI;
public:
    using ThisClass = cShlParamIntervalHit<uShlIntervalHit<uShlStick>, cShlParamStick>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamIntervalHit();
    virtual void createProperty(MtPropertyList& proplist);  // vtable slot 4
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    f32 mHitInterVal;  // offset: 0x164
    s32 mSeNo;  // offset: 0x168
    s32 mEfNo;  // offset: 0x16c
    s32 mColNo;  // offset: 0x170
    bool mIsUseRandamInterVal;  // offset: 0x174
    floatArray mRandamInterVal;  // offset: 0x178
    static MyDTI DTI;
};

template <typename ParentClass>
class uShlIntervalHit : public ParentClass
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
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    uShlIntervalHit();
    virtual ~uShlIntervalHit();
    virtual void setup();  // vtable slot 6
    virtual void update();  // vtable slot 174
    virtual void kill();  // vtable slot 16
    void callbackInterval();
    void setIntervalCollision();
    void killIntervalCollision();
private:
    f32 mIntervalTimer;  // offset: 0x2ab0
    f32 mHitingTimer;  // offset: 0x2ab4
    bool mIsCreatedCol;  // offset: 0x2ab8
    bool mIsOnce;  // offset: 0x2ab9
    s32 mCounter;  // offset: 0x2abc
    cHitNode* mpIntervalAtkNode;  // offset: 0x2ac0
public:
    static MyDTI DTI;
};

inline cShlParamIntervalHit<uShlIntervalHit<uShlBase>, cShlParamBase>::cShlParamIntervalHit() : mHitInterVal(0.0f), mSeNo(-1), mEfNo(-1), mColNo(-1), mIsUseRandamInterVal(false) {
    for (u32 i = 0; i < 10u; i++) {
        mRandamInterVal.elems[i] = 0.0f;
    }
}

inline cShlParamIntervalHit<uShlIntervalHit<uShlStick>, cShlParamStick>::cShlParamIntervalHit() : mHitInterVal(0.0f), mSeNo(-1), mEfNo(-1), mColNo(-1), mIsUseRandamInterVal(false) {
    for (u32 i = 0; i < 10u; i++) {
        mRandamInterVal.elems[i] = 0.0f;
    }
}

template <typename ParentClass>
const MtDTI& uShlIntervalHit<ParentClass>::getDTI() const {
    return uShlIntervalHit<ParentClass>::DTI;
}

template <typename ParentClass>
uShlIntervalHit<ParentClass>::~uShlIntervalHit() {
}
