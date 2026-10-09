#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class uDDOModel;

// Declarations
class cpKeepAtkAdjust;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cpKeepAtkAdjust : public cpComponent
{
    // inferred: uDDOModel::resetAtkAdjust names cpKeepAtkAdjust::mActive
    friend class uDDOModel;
public:
    enum
    {
        ADJUST_PARAM_TYPE_RATE = 0,
        ADJUST_PARAM_TYPE_ENCHANT = 1,
        ADJUST_PARAM_TYPE_POISON = 2,
        ADJUST_PARAM_TYPE_OIL = 3,
        ADJUST_PARAM_TYPE_SLEEP = 4,
        ADJUST_PARAM_TYPE_SILENT = 5,
        ADJUST_PARAM_TYPE_SLOW = 6,
    };
public:
    class MyDTI;
    class cAtkAdjust;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cAtkAdjust : public MtObject
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
        cAtkAdjust();
        // Address: 0x01a5bcb0 - 0x01a5bcb1 (1 bytes)
        virtual ~cAtkAdjust() {}
    public:
        u16 mUniqueId;  // offset: 0x8
        u32 mType;  // offset: 0xc
        f32 mAtkRate;  // offset: 0x10
        f32 mBlowRate;  // offset: 0x14
        f32 mShrinkRate;  // offset: 0x18
        f32 mMgcRate;  // offset: 0x1c
        f32 mMgcBowMAtkRate;  // offset: 0x20
        f32 mMgcBowHealRate;  // offset: 0x24
        f32 mMgcBowOcdRate;  // offset: 0x28
        f32 mPoisonValue;  // offset: 0x2c
        f32 mOilValue;  // offset: 0x30
        f32 mSleepValue;  // offset: 0x34
        f32 mSilentValue;  // offset: 0x38
        f32 mSlowValue;  // offset: 0x3c
        f32 mEnchantTime;  // offset: 0x40
        f32 mEnchantRate;  // offset: 0x44
        f32 mAilmentDamage;  // offset: 0x48
        static MyDTI DTI;
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
    cpKeepAtkAdjust();
    virtual ~cpKeepAtkAdjust();
    virtual void setup();  // vtable slot 6
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
private:
    void updateIndex();
    u16 createUniqeuID();
    const cAtkAdjust* getAtkAdjust(u16 uniqueId) const;
public:
    void resetActive();
    u16 getCurrentUniqueId();
    u16 getNowUniqueId();
    void setNowUniqueId(u16 uniqueId);
    void setAtkAdjust(f32 atkRate, f32 blowRate, f32 shrinkRate);
    void setMgcAdjust(f32 mgcRate);
    void setMgcBowAdjust(f32 atkRate, f32 healRate, f32 ocdRate);
    f32 getAtkRate(u16 uniqueId) const;
    f32 getMgcRate(u16 uniqueId) const;
    f32 getMgcBowAdjust(u16 uniqueId, u32 type) const;
    f32 getBlowRate(u16 uniqueId) const;
    f32 getShrinkRate(u16 uniqueId) const;
    void setOcdAdjust(f32 value, u32 type);
    f32 getOcdValue(u16 uniqueId, u32 type) const;
    void setEnchantAdjust(f32 EnchantTime, f32 EnchantRate, f32 AilmentDamage);
    void getEnchantAdjust(u16 uniqueId, f32& EnchantTime, f32& EnchantRate, f32& AilmentDamage) const;
public:
    uDDOModel* mpModel;  // offset: 0x50
private:
    cAtkAdjust mKeepAtkAdjust[32];  // offset: 0x58
    u32 mNowIndex;  // offset: 0xa58
    u16 mNowUniqueId;  // offset: 0xa5c
    bool mActive;  // offset: 0xa5e
public:
    static MyDTI DTI;
    static const u16 UNIQUE_ID_NONE = 0;
    static const u32 KEEP_PARAM_NUM = 32;
};

// Inline, no code of its own: checked where it is inlined.
inline u16 cpKeepAtkAdjust::getNowUniqueId() {
    return this->mNowUniqueId;
}

// Inline, no code of its own: checked where it is inlined.
inline cpKeepAtkAdjust::cAtkAdjust::cAtkAdjust() {
    this->mUniqueId = static_cast<u16>(0);
    this->mMgcBowMAtkRate = 0.0f;
    this->mMgcBowHealRate = 0.0f;
    this->mShrinkRate = 0.0f;
    this->mMgcRate = 0.0f;
    this->mAtkRate = 0.0f;
    this->mBlowRate = 0.0f;
    this->mSlowValue = 0.0f;
    this->mEnchantTime = 0.0f;
    this->mSleepValue = 0.0f;
    this->mSilentValue = 0.0f;
    this->mPoisonValue = 0.0f;
    this->mOilValue = 0.0f;
    this->mEnchantRate = 1.0f;
    this->mAilmentDamage = 0.0f;
    this->mMgcBowOcdRate = 0.0f;
}
