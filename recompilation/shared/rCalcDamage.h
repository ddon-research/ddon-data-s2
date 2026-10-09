#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "rTbl2.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtDataReader;
class MtObject;
class MtPropertyList;
class sObjCollision;

// Declarations
class cAdjLimitParam;
class cBlowSaveEmLvParam;
class cCalcDamageAtdmAdj;
class cCalcDamageAtdmAdjRate;
class cCalcDamageLvAdj;
class cDamageSaveEmLvParam;
class cDamageSpecialAdj;
class cDmJobAdjParam;
class cDmJobPawnAdjParam;
class cDmLvPawnAdjParam;
class cErosionShakeConvert;
class cShrinkBlowValue;
class rAdjLimitParam;
class rBlowSaveEmLvParam;
class rCalcDamageAtdmAdj;
class rCalcDamageAtdmAdjRate;
class rCalcDamageLvAdj;
class rDamageSaveEmLvParam;
class rDamageSpecialAdj;
class rDmJobAdjParam;
class rDmJobPawnAdjParam;
class rDmLvPawnAdjParam;
class rErosionShakeConvert;
class rShrinkBlowValue;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;

class cAdjLimitParam : public MtObject
{
public:
    enum ResStatus
    {
        DATA_VERSION = 5,
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
    cAdjLimitParam();
    // Address: 0x01a7a300 - 0x01a7a301 (1 bytes)
    virtual ~cAdjLimitParam() {}
public:
    f32 mGuardAtkAdjMax[5];  // offset: 0x8
    f32 mGuardAtkAdjMin[5];  // offset: 0x1c
    f32 mGuardDefAdjMax[5];  // offset: 0x30
    f32 mGuardDefAdjMin[5];  // offset: 0x44
    f32 mStaminaDamageAdjMax[5];  // offset: 0x58
    f32 mStaminaDamageAdjMin[5];  // offset: 0x6c
    f32 mHpDamageAtkAdjMax[7];  // offset: 0x80
    f32 mHpDamageAtkAdjMin[7];  // offset: 0x9c
    f32 mHpDamageDefAdjMax[7];  // offset: 0xb8
    f32 mHpDamageDefAdjMin[7];  // offset: 0xd4
    f32 mShrinkAtkAdjMax[5];  // offset: 0xf0
    f32 mShrinkAtkAdjMin[5];  // offset: 0x104
    f32 mShrinkDefAdjMax[5];  // offset: 0x118
    f32 mShrinkDefAdjMin[5];  // offset: 0x12c
    f32 mBlowAtkAdjMax[5];  // offset: 0x140
    f32 mBlowAtkAdjMin[5];  // offset: 0x154
    f32 mBlowDefAdjMax[5];  // offset: 0x168
    f32 mBlowDefAdjMin[5];  // offset: 0x17c
    f32 mShakeAtkAdjMax[5];  // offset: 0x190
    f32 mShakeAtkAdjMin[5];  // offset: 0x1a4
    f32 mShakeDefAdjMax[5];  // offset: 0x1b8
    f32 mShakeDefAdjMin[5];  // offset: 0x1cc
    f32 mDownAtkAdjMax[5];  // offset: 0x1e0
    f32 mDownAtkAdjMin[5];  // offset: 0x1f4
    f32 mDownDefAdjMax[5];  // offset: 0x208
    f32 mDownDefAdjMin[5];  // offset: 0x21c
    f32 mOcdAtkAdjMax[5];  // offset: 0x230
    f32 mOcdAtkAdjMin[5];  // offset: 0x244
    f32 mOcdDefAdjMax[5];  // offset: 0x258
    f32 mOcdDefAdjMin[5];  // offset: 0x26c
    f32 mHpHealAtkAdjMax[5];  // offset: 0x280
    f32 mHpHealAtkAdjMin[5];  // offset: 0x294
    f32 mHpHealDefAdjMax[5];  // offset: 0x2a8
    f32 mHpHealDefAdjMin[5];  // offset: 0x2bc
    f32 mStaminaHealAtkAdjMax[5];  // offset: 0x2d0
    f32 mStaminaHealAtkAdjMin[5];  // offset: 0x2e4
    f32 mStaminaHealDefAdjMax[5];  // offset: 0x2f8
    f32 mStaminaHealDefAdjMin[5];  // offset: 0x30c
    u16 mHolyAbsorpMax;  // offset: 0x320
    u16 mHolyAbsorpMin;  // offset: 0x322
    f32 mDamageMax;  // offset: 0x324
    f32 mDamageMin;  // offset: 0x328
    static MyDTI DTI;
};

class cBlowSaveEmLvParam : public MtObject
{
public:
    enum ResStatus
    {
        DATA_VERSION = 2,
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
    cBlowSaveEmLvParam();
    // Address: 0x01a796b0 - 0x01a796b1 (1 bytes)
    virtual ~cBlowSaveEmLvParam() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mKeyLv;  // offset: 0x8
    f32 mSaveRate;  // offset: 0xc
    static MyDTI DTI;
};

class cCalcDamageAtdmAdj : public MtObject
{
public:
    enum ResStatus
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
    cCalcDamageAtdmAdj();
    // Address: 0x01a77950 - 0x01a77951 (1 bytes)
    virtual ~cCalcDamageAtdmAdj() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    f32 mAtdmRate;  // offset: 0x8
    f32 mDamageAdj;  // offset: 0xc
    static MyDTI DTI;
};

class cCalcDamageAtdmAdjRate : public MtObject
{
public:
    enum ResStatus
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
    cCalcDamageAtdmAdjRate();
    // Address: 0x01a77d10 - 0x01a77d11 (1 bytes)
    virtual ~cCalcDamageAtdmAdjRate() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    f32 mKeyValue;  // offset: 0x8
    f32 mAtdmAdjRate;  // offset: 0xc
    static MyDTI DTI;
};

class cCalcDamageLvAdj : public MtObject
{
public:
    enum ResStatus
    {
        DATA_VERSION = 17,
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
    cCalcDamageLvAdj();
    // Address: 0x01a77580 - 0x01a77581 (1 bytes)
    virtual ~cCalcDamageLvAdj() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    s16 mLvDiff;  // offset: 0x8
    f32 mLvAdj[6];  // offset: 0xc
    static MyDTI DTI;
};

class cDamageSaveEmLvParam : public MtObject
{
public:
    enum ResStatus
    {
        DATA_VERSION = 2,
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
    cDamageSaveEmLvParam();
    // Address: 0x01a792e0 - 0x01a792e1 (1 bytes)
    virtual ~cDamageSaveEmLvParam() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mKeyLv;  // offset: 0x8
    f32 mSaveParamA;  // offset: 0xc
    f32 mSaveParamB;  // offset: 0x10
    f32 mSaveParamC;  // offset: 0x14
    static MyDTI DTI;
};

class cDamageSpecialAdj : public MtObject
{
public:
    enum ResStatus
    {
        DATA_VERSION = 2,
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
    cDamageSpecialAdj();
    // Address: 0x01a79b00 - 0x01a79b01 (1 bytes)
    virtual ~cDamageSpecialAdj() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    f32 mDamageRate;  // offset: 0x8
    static MyDTI DTI;
};

class cDmJobAdjParam : public MtObject
{
public:
    enum ResStatus
    {
        DATA_VERSION = 9,
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
    cDmJobAdjParam();
    // Address: 0x01a780d0 - 0x01a780d1 (1 bytes)
    virtual ~cDmJobAdjParam() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mJobType;  // offset: 0x8
    f32 mActionRateAdj;  // offset: 0xc
    f32 mDamageAdj;  // offset: 0x10
    f32 mStaminaDamageAdj;  // offset: 0x14
    f32 mEnchantDamageAdj;  // offset: 0x18
    f32 mAbilityBlowAdj;  // offset: 0x1c
    f32 mHumanEmOcdAdj;  // offset: 0x20
    f32 mTiredDamageAdj;  // offset: 0x24
    f32 mChanceDamageAdj;  // offset: 0x28
    f32 mAtDmRateMaxPhys;  // offset: 0x2c
    f32 mAtDmRateMaxMagic;  // offset: 0x30
    f32 mHealBaseMagicAdjAdd;  // offset: 0x34
    f32 mHealBaseMagicAdjMulti;  // offset: 0x38
    f32 mHealWepMagicAdjAdd;  // offset: 0x3c
    f32 mHealWepMagicAdjMulti;  // offset: 0x40
    f32 mShrinkBlowSaveAdj;  // offset: 0x44
    static MyDTI DTI;
};

class cDmJobPawnAdjParam : public MtObject
{
public:
    enum ResStatus
    {
        DATA_VERSION = 2,
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
    cDmJobPawnAdjParam();
    // Address: 0x01a78b50 - 0x01a78b51 (1 bytes)
    virtual ~cDmJobPawnAdjParam() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mJobType;  // offset: 0x8
    f32 mBaseAttackAdj;  // offset: 0xc
    f32 mBaseMagicAttackAdj;  // offset: 0x10
    f32 mBaseBlowShrinkAdj;  // offset: 0x14
    static MyDTI DTI;
};

class cDmLvPawnAdjParam : public MtObject
{
public:
    enum ResStatus
    {
        DATA_VERSION = 2,
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
    cDmLvPawnAdjParam();
    // Address: 0x01a78f20 - 0x01a78f21 (1 bytes)
    virtual ~cDmLvPawnAdjParam() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mKeyLv;  // offset: 0x8
    f32 mLvAdjRateBase;  // offset: 0xc
    f32 mLvAdjRateWep;  // offset: 0x10
    static MyDTI DTI;
};

class cErosionShakeConvert : public MtObject
{
    // inferred: rErosionShakeConvert::loadData names cErosionShakeConvert::mKeyShakesRate
    friend class rErosionShakeConvert;
    // inferred: sObjCollision::findErosionCoreAddTime names cErosionShakeConvert::mKeyShakesRate
    friend class sObjCollision;
public:
    enum ResStatus
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
    cErosionShakeConvert();
    // Address: 0x01a79f40 - 0x01a79f41 (1 bytes)
    virtual ~cErosionShakeConvert() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    f32 getKeyShakesRate() const;
    f32 getAddCoreTime() const;
private:
    f32 mKeyShakesRate;  // offset: 0x8
    f32 mAddCoreTime;  // offset: 0xc
public:
    static MyDTI DTI;
};

class cShrinkBlowValue : public MtObject
{
public:
    enum ResStatus
    {
        DATA_VERSION = 2,
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
    cShrinkBlowValue();
    // Address: 0x01a783e0 - 0x01a783e1 (1 bytes)
    virtual ~cShrinkBlowValue() {}
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
public:
    u32 mDamageType;  // offset: 0x8
    u32 mLv;  // offset: 0xc
    f32 mSpeedXZ;  // offset: 0x10
    f32 mAccelerateXZ;  // offset: 0x14
    f32 mSpeedY;  // offset: 0x18
    f32 mGravityY;  // offset: 0x1c
    static MyDTI DTI;
};

class rAdjLimitParam : public rTbl2<cAdjLimitParam>
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
    virtual bool loadData(MtDataReader& r, cAdjLimitParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rBlowSaveEmLvParam : public rTbl2<cBlowSaveEmLvParam>
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
    virtual bool loadData(MtDataReader& in, cBlowSaveEmLvParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rCalcDamageAtdmAdj : public rTbl2<cCalcDamageAtdmAdj>
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
    virtual bool loadData(MtDataReader& in, cCalcDamageAtdmAdj* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rCalcDamageAtdmAdjRate : public rTbl2<cCalcDamageAtdmAdjRate>
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
    virtual bool loadData(MtDataReader& in, cCalcDamageAtdmAdjRate* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rCalcDamageLvAdj : public rTbl2<cCalcDamageLvAdj>
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
    virtual bool loadData(MtDataReader& in, cCalcDamageLvAdj* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rDamageSaveEmLvParam : public rTbl2<cDamageSaveEmLvParam>
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
    virtual bool loadData(MtDataReader& in, cDamageSaveEmLvParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rDamageSpecialAdj : public rTbl2<cDamageSpecialAdj>
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
    virtual bool loadData(MtDataReader& in, cDamageSpecialAdj* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rDmJobAdjParam : public rTbl2<cDmJobAdjParam>
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
    virtual bool loadData(MtDataReader& in, cDmJobAdjParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rDmJobPawnAdjParam : public rTbl2<cDmJobPawnAdjParam>
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
    virtual bool loadData(MtDataReader& in, cDmJobPawnAdjParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rDmLvPawnAdjParam : public rTbl2<cDmLvPawnAdjParam>
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
    virtual bool loadData(MtDataReader& in, cDmLvPawnAdjParam* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rErosionShakeConvert : public rTbl2<cErosionShakeConvert>
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
    virtual bool loadData(MtDataReader& in, cErosionShakeConvert* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

class rShrinkBlowValue : public rTbl2<cShrinkBlowValue>
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
    virtual bool loadData(MtDataReader& in, cShrinkBlowValue* pData);  // vtable slot 16
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual u32 getDataVersion() const;  // vtable slot 20
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cBlowSaveEmLvParam::cBlowSaveEmLvParam() {
    this->mKeyLv = static_cast<u32>(0);
    this->mSaveRate = 0.0f;
}

// Inline, no code of its own: checked where it is inlined.
inline cCalcDamageAtdmAdj::cCalcDamageAtdmAdj() {
    this->mAtdmRate = 0.0f;
    this->mDamageAdj = 1.0f;
}

// Inline, no code of its own: checked where it is inlined.
inline cCalcDamageAtdmAdjRate::cCalcDamageAtdmAdjRate() {
    this->mKeyValue = 0.0f;
    this->mAtdmAdjRate = 1.0f;
}

// Inline, no code of its own: checked where it is inlined.
inline cDamageSaveEmLvParam::cDamageSaveEmLvParam() {
    this->mSaveParamB = 0.0f;
    this->mSaveParamC = 0.0f;
    this->mKeyLv = static_cast<u32>(0);
    this->mSaveParamA = 0.0f;
}

// Inline, no code of its own: checked where it is inlined.
inline cDamageSpecialAdj::cDamageSpecialAdj() {
    this->mDamageRate = 1.0f;
}

// Inline, no code of its own: checked where it is inlined.
inline cDmJobPawnAdjParam::cDmJobPawnAdjParam() {
    this->mJobType = static_cast<u32>(255);
    this->mBaseAttackAdj = 0.0f;
    this->mBaseMagicAttackAdj = 0.0f;
    this->mBaseBlowShrinkAdj = 0.0f;
}

// Inline, no code of its own: checked where it is inlined.
inline cDmLvPawnAdjParam::cDmLvPawnAdjParam() {
    this->mKeyLv = static_cast<u32>(0);
    this->mLvAdjRateBase = 0.0f;
    this->mLvAdjRateWep = 0.0f;
}

// Inline, no code of its own: checked where it is inlined.
inline cErosionShakeConvert::cErosionShakeConvert() {
    this->mKeyShakesRate = 4.0f;
    this->mAddCoreTime = 60.0f;
}

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline f32 cErosionShakeConvert::getAddCoreTime() const {
    return this->mAddCoreTime;
}

// Inline, no code of its own: checked where it is inlined.
inline cShrinkBlowValue::cShrinkBlowValue() {
    this->mDamageType = static_cast<u32>(0);
    this->mLv = static_cast<u32>(1);
    this->mSpeedY = 0.0f;
    this->mGravityY = 0.0f;
    this->mSpeedXZ = 0.0f;
    this->mAccelerateXZ = 0.0f;
}
