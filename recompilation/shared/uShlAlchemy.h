#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "uShlStick.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cEfcHandle;
class cHitInfo;
class cShlParamAlchemy;
class cShlParamAlchemyCS03;

// Declarations
class uShlAlchemy;
class uShlAlchemyCS03;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uShlAlchemy : public uShlStick
{
public:
    enum ALCHEMY_COLOR_LV
    {
        ALCHEMY_COLOR_LV_DEFALUT = 0,
        ALCHEMY_COLOR_LV_1 = 1,
        ALCHEMY_COLOR_LV_2 = 2,
        ALCHEMY_COLOR_LV_MAX = 2,
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
    const cShlParamAlchemy* getShlParam() const;
    uShlAlchemy();
    virtual ~uShlAlchemy();
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
    virtual void initSub();  // vtable slot 177
    virtual void updateEfcHandle();  // vtable slot 58
    virtual void kill();  // vtable slot 16
    void setAlchemyValue(f32 value);
    void addAlchemyValue(f32 value, bool flg_add_value);
    bool isMaxValue();
    f32 getAlchemyValue() const;
    void resetAccumulateEvaluation();
    void setDefaultMaxValue(bool flg);
    void resetReduceTime();
protected:
    virtual void evAlchemyValueZero();  // vtable slot 188
    void requestStopLoopSe();
    virtual void updateStickAngle();  // vtable slot 187
private:
    void updateAlchemyModel(bool flg_add_value);
    void updateParts(s32 lv);
    void updateColor(s32 lv);
    bool setupInfo();
    void setupSe();
    void checkAbility(f32& add_value);
    void eventMaxLvGrow();
    void requestMaxSe(bool requestMaxSE);
    void updateAlchemyValue();
public:
    bool getStateBurst();
    void setStateBurst(const bool flg);
    virtual void callbackChecked(cHitInfo* pHitInfo);  // vtable slot 124
    bool getUseBurstRelease();
    void setUseBurstRelease(const bool flg);
private:
    cEfcHandle* mpAlchemyMaxEfcHandle;  // offset: 0x2ab0
    s32 mOldColorLv;  // offset: 0x2ab8
    s32 mOldPartsLv;  // offset: 0x2abc
    f32 mAlchemyReduceTime;  // offset: 0x2ac0
    f32 mAlchemyValue;  // offset: 0x2ac4
    bool mFlgSetInfo;  // offset: 0x2ac8
    bool mMaxLvGrow;  // offset: 0x2ac9
    bool mFlgMaxGrowLoopSeRequest;  // offset: 0x2aca
    bool mFlgDefaultMaxValue;  // offset: 0x2acb
    bool mStateBurst;  // offset: 0x2acc
    bool mUseBurstRelease;  // offset: 0x2acd
public:
    static MyDTI DTI;
};

class uShlAlchemyCS03 : public uShlAlchemy
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
    const cShlParamAlchemyCS03* getShlParam() const;
    uShlAlchemyCS03();
    virtual void setup();  // vtable slot 6
    virtual void updateSub();  // vtable slot 175
    virtual void callbackDamage(cHitInfo* pHitInfo);  // vtable slot 88
    void checkDamageAlchemy(cHitInfo* pHitInfo);
    f32 getDamageAlchemyValue(const f32 damage_rate);
    bool canDamageAlchemy();
    void deleteDamageAlchemy();
    void requestDeleteDamageAlchemy();
protected:
    virtual void evAlchemyValueZero();  // vtable slot 188
    virtual void initSub();  // vtable slot 177
protected:
    bool mFlgDamageAlchemy;  // offset: 0x2ace
    f32 mSlaveDispOffTimer;  // offset: 0x2ad0
    bool mRequestDeleteDamageAlchemy;  // offset: 0x2ad4
    f32 mCS3TransparencyRate;  // offset: 0x2ad8
    f32 mCS3BaseTransparencyRate;  // offset: 0x2adc
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline uShlAlchemy::uShlAlchemy() {
    this->mAlchemyValue = 0.0f;
    this->mOldColorLv = static_cast<s32>(-1);
    this->mOldPartsLv = static_cast<s32>(-1);
    this->mFlgSetInfo = false;
    this->mpAlchemyMaxEfcHandle = static_cast<cEfcHandle*>(nullptr);
    this->mMaxLvGrow = false;
    this->mFlgMaxGrowLoopSeRequest = false;
    this->mAlchemyReduceTime = -1.0f;
    this->mFlgDefaultMaxValue = false;
    this->mStateBurst = false;
    this->mUseBurstRelease = false;
}

// Inline, no code of its own: checked where it is inlined.
inline f32 uShlAlchemy::getAlchemyValue() const {
    return this->mAlchemyValue;
}
