#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtVector3;
class cpJob06;
class uShlBase;

// Declarations
class cHitInfoAfterLocal;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cHitInfoAfterLocal : public MtObject
{
    // inferred: cpJob06::makeShlDamageAttackInfo names cHitInfoAfter::mLocalInfo.mHitPos
    friend class cpJob06;
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
    cHitInfoAfterLocal();
    void copy(const cHitInfoAfterLocal param);
    void clear();
    const MtVector3& getHitPos() const;
    void setHitPos(const MtVector3& NewValue);
    void setShlAtkPtr(uShlBase* pShlPtr);
    uShlBase* getShlAtkPtr() const;
    void setForceStop(f32 time, u8 flag);
    f32 getHitStopTime() const;
    u8 getHitStopFlag() const;
    bool isForceHitStop() const;
private:
    void setHitStopTime(f32 time);
    void setHitStopFlag(u8 flag);
    void setIsForceHitStop(bool isForce);
    const MtVector3& getHitPosPrivate() const;
    void setHitPosPrivate(const MtVector3& NewValue);
private:
    MtVector3 mHitPos;  // offset: 0x10
    uShlBase* mpShlAtkPtr;  // offset: 0x20
    f32 mHitStopTime;  // offset: 0x28
    u8 mHitStopFlag;  // offset: 0x2c
    bool mIsForceHitStop;  // offset: 0x2d
public:
    static MyDTI DTI;
};
