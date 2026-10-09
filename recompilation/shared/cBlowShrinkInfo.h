#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "nRegionStatus.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
class cBlowShrinkInfo;
class cDurableInfoBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cDurableInfoBase : public MtObject
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
    cDurableInfoBase();
    virtual ~cDurableInfoBase() {}
public:
    static MyDTI DTI;
};

class cBlowShrinkInfo : public cDurableInfoBase
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
    cBlowShrinkInfo();
    // Address: 0x01951330 - 0x01951331 (1 bytes)
    virtual ~cBlowShrinkInfo() {}
    void update(f32 deltaTime);
    void updateEndurance(f32 attackValue);
    void updateEnduranceForceActive();
    void addRateDamage(f32 rate, bool isReaction);
    void copy(const cBlowShrinkInfo& srcInfo);
    void reset();
    bool holdOneEndurance();
    void setCureSpeedRate(nRegionStatus::ENDURANCE_CURE_RATE_TYPE type, f32 rate);
    void reCalcCureSpeedRate();
public:
    bool mIsActive;  // offset: 0x8
    f32 mEndurance;  // offset: 0xc
    f32 mEnduranceBaseMax;  // offset: 0x10
    f32 mEnduranceMax;  // offset: 0x14
    f32 mCureSpeed;  // offset: 0x18
    f32 mCureSpeedRateResult;  // offset: 0x1c
    f32 mResetTimer;  // offset: 0x20
    f32 mResetTimerMax;  // offset: 0x24
    bool mIsTimerActive;  // offset: 0x28
private:
    f32 mCureSpeedRate[3];  // offset: 0x2c
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline cDurableInfoBase::cDurableInfoBase() {
}
