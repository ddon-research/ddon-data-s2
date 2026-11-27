#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "uShlStick.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cEfcHandle;
class cHitInfo;
class cShlParamBase;
class cpJob09;

// Declarations
class cShlParamAlchemy;
class cShlParamAlchemyCS03;
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

class cShlParamAlchemy : public cShlParamStick
{
public:
    enum ALCHEMY_TYPE
    {
        AT_NORMAL = 0,
        AT_DAMAGE = 1,
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
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertySE(MtPropertyList& s);  // vtable slot 9
    cShlParamAlchemy();
    virtual ~cShlParamAlchemy();
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    f32 mReduceAlchemyValueTime;  // offset: 0x164
    f32 mSubAlchemyValueOnce;  // offset: 0x168
    f32 mSubAlchemyValueTime;  // offset: 0x16c
    f32 mAlchemyEvaRate;  // offset: 0x170
    f32 mAlchemyEvaMin;  // offset: 0x174
    u32 mAlchemyType;  // offset: 0x178
    f32 mChipScale[4];  // offset: 0x17c
    s32 mMaxValueRequestSe;  // offset: 0x18c
    s32 mMaxValueLoopSe;  // offset: 0x190
    s32 mMaxValueLoopStopSe;  // offset: 0x194
    s32 mMaxPartsDownSe;  // offset: 0x198
    s32 mCheckedCollsiionIndexForCS13;  // offset: 0x19c
    static MyDTI DTI;
};

class cShlParamAlchemyCS03 : public cShlParamAlchemy
{
public:
    class MyDTI;
    class cDamageAlchemyValueInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cDamageAlchemyValueInfo : public MtObject
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
        cDamageAlchemyValueInfo();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void copy(cShlParamAlchemyCS03::cDamageAlchemyValueInfo* pData);
    public:
        f32 mMinRate;  // offset: 0x8
        f32 mMaxRate;  // offset: 0xc
        f32 mAlchemyValue;  // offset: 0x10
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
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    cShlParamAlchemyCS03();
    virtual ~cShlParamAlchemyCS03();
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    MtTypedArray<cDamageAlchemyValueInfo> mArrDamageAlchemyInfo;  // offset: 0x1a0
    f32 mDamageAlchemyMaxTimer;  // offset: 0x1c0
    f32 mSlaveDispOffTimer;  // offset: 0x1c4
    static MyDTI DTI;
};

class uShlAlchemy : public uShlStick
{
    friend class cpJob09;
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

inline void* cShlParamAlchemy::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamAlchemy::cShlParamAlchemy() {
    this->mReduceAlchemyValueTime = 300.0f;
    this->mSubAlchemyValueOnce = 1.0f;
    this->mSubAlchemyValueTime = 1.0f;
    this->mAlchemyEvaRate = 0.6f;
    this->mAlchemyType = 0;
    this->mChipScale[0] = 1.0f;
    this->mChipScale[1] = 1.25f;
    this->mChipScale[2] = 1.5f;
    this->mChipScale[3] = 1.75f;
    this->mCheckedCollsiionIndexForCS13 = -1;
    this->mMaxValueLoopStopSe = -1;
    this->mMaxPartsDownSe = -1;
    this->mMaxValueRequestSe = -1;
    this->mMaxValueLoopSe = -1;
    this->mAlchemyEvaMin = 100.0f;
}

inline void* cShlParamAlchemyCS03::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamAlchemyCS03::cShlParamAlchemyCS03() {
    this->mDamageAlchemyMaxTimer = 900.0f;
    this->mSlaveDispOffTimer = 150.0f;
    this->mArrDamageAlchemyInfo.::MtArray::mAutoDelete = true;
}

inline void* cShlParamAlchemyCS03::cDamageAlchemyValueInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamAlchemyCS03::cDamageAlchemyValueInfo::cDamageAlchemyValueInfo() {
    this->mMinRate = 0.0f;
    this->mMaxRate = -1.0f;
    this->mAlchemyValue = 100.0f;
}

inline void* uShlAlchemy::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uShlAlchemy::uShlAlchemy() {
    this->mAlchemyValue = 0.0f;
    this->mOldColorLv = -1;
    this->mOldPartsLv = -1;
    this->mFlgSetInfo = false;
    this->mpAlchemyMaxEfcHandle = nullptr;
    this->mMaxLvGrow = false;
    this->mFlgMaxGrowLoopSeRequest = false;
    this->mAlchemyReduceTime = -1.0f;
    this->mFlgDefaultMaxValue = false;
    this->mStateBurst = false;
    this->mUseBurstRelease = false;
}

inline f32 uShlAlchemy::getAlchemyValue() const {
    return this->mAlchemyValue;
}

inline void* uShlAlchemyCS03::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline bool uShlAlchemyCS03::canDamageAlchemy() {
    return this->mFlgDamageAlchemy;
}

inline void uShlAlchemyCS03::requestDeleteDamageAlchemy() {
    this->mRequestDeleteDamageAlchemy = true;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cShlParamAlchemy::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamAlchemy::DTI)->memAlloc(sz, align, ::cShlParamAlchemy::DTI.::MtDTI::getID());
}

inline void* cShlParamAlchemyCS03::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamAlchemyCS03::DTI)->memAlloc(sz, align, ::cShlParamAlchemyCS03::DTI.::MtDTI::getID());
}

inline void cShlParamAlchemyCS03::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cShlParamAlchemyCS03::DTI)->memFree(p_addr);
}

inline void* cShlParamAlchemyCS03::cDamageAlchemyValueInfo::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamAlchemyCS03::cDamageAlchemyValueInfo::DTI)->memAlloc(sz, align, ::cShlParamAlchemyCS03::cDamageAlchemyValueInfo::DTI.::MtDTI::getID());
}

inline void cShlParamAlchemyCS03::cDamageAlchemyValueInfo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cShlParamAlchemyCS03::cDamageAlchemyValueInfo::DTI)->memFree(p_addr);
}

inline void* uShlAlchemy::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uShlAlchemy::DTI)->memAlloc(sz, align, ::uShlAlchemy::DTI.::MtDTI::getID());
}

inline void uShlAlchemy::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlAlchemy::DTI)->memFree(p_addr);
}

inline void uShlAlchemyCS03::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlAlchemyCS03::DTI)->memFree(p_addr);
}
