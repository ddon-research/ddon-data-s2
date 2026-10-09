#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cBlowShrinkDmInfo.h"
#include "cHitInfoAfterLocal.h"
#include "cOcdDamageInfo.h"
#include "nObjCollision.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtVector3;
class cAttackParam;
class cBlowShrinkDmInfo;
class cCalcDamageLvAdj;
class cChildRegionStatus;
class cCollGeom;
class cCollNode;
class cDamageMsg;
class cDmJobAdjParam;
class cHitInfoAfterLocal;
class cOcdDamageInfo;
class cParentRegionStatus;
class cpJob08;
class rAttackParam;
class uDDOModel;

// Declarations
class cHealedInfo;
class cHitInfoAfter;
class cHitInfoAfterCommon;
class cHpDamageInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;

class cHealedInfo : public MtObject
{
    // inferred: cpJob08::makeHealedAttackInfo names cHitInfoAfter::mHealedInfo.mHpHealAtkAdj[0]
    friend class cpJob08;
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
    cHealedInfo();
    f32 getHpHealAttackAdj(nObjCollision::HP_HEAL_ATTACK_ADJ_TYPE type) const;
    f32 getHpHealDefenceAdj(nObjCollision::HP_HEAL_DEFENCE_ADJ_TYPE type) const;
    f32 getStaminaHealAttackAdj(nObjCollision::STAMINA_HEAL_ATTACK_ADJ_TYPE type) const;
    f32 getStaminaHealDefenceAdj(nObjCollision::STAMINA_HEAL_DEFENCE_ADJ_TYPE type) const;
    void addHpHealAttackAdj(nObjCollision::HP_HEAL_ATTACK_ADJ_TYPE type, f32 Adj);
    void addHpHealDefenceAdj(nObjCollision::HP_HEAL_DEFENCE_ADJ_TYPE, f32);
    void addStaminaHealAttackAdj(nObjCollision::STAMINA_HEAL_ATTACK_ADJ_TYPE type, f32 Adj);
    void addStaminaHealDefenceAdj(nObjCollision::STAMINA_HEAL_DEFENCE_ADJ_TYPE, f32);
    void clear();
public:
    f32 mMagicBase;  // offset: 0x8
    f32 mMagicWep;  // offset: 0xc
    f32 mHpHealVal;  // offset: 0x10
    f32 mStaminaHealVal;  // offset: 0x14
private:
    f32 mHpHealAtkAdj[4];  // offset: 0x18
    f32 mHpHealDefAdj[4];  // offset: 0x28
    f32 mStaminaHealAtkAdj[4];  // offset: 0x38
    f32 mStaminaHealDefAdj[4];  // offset: 0x48
public:
    f32 mPawnAdjMagicBase;  // offset: 0x58
    f32 mPawnAdjMagicWep;  // offset: 0x5c
    static MyDTI DTI;
};

class cHitInfoAfterCommon : public MtObject
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
    cHitInfoAfterCommon();
    virtual ~cHitInfoAfterCommon();
    void makeInfoFromDmMsg(const cDamageMsg* pDmMsg, uDDOModel* pReceiver);
    uDDOModel* getAttckerPtr() const;
    f32 getLvAdj(nObjCollision::LV_ADJ_TYPE type) const;
    void clear();
private:
    void operator=(const cHitInfoAfterCommon&);
    cHitInfoAfterCommon(const cHitInfoAfterCommon&);
public:
    bool mIsFriend;  // offset: 0x8
    uDDOModel* mpAtkModel;  // offset: 0x10
    uDDOModel* mpDfdModel;  // offset: 0x18
    MtVector3 mDamageDir;  // offset: 0x20
    u32 mAttackAttr;  // offset: 0x30
    const cCollNode* mpDfdCollNode;  // offset: 0x38
    const cCollGeom* mpDfdCollGeom;  // offset: 0x40
    u16 mAtkAdjustUniqueId;  // offset: 0x48
    u32 mHitStopSlowResultType;  // offset: 0x4c
    cAttackParam* mpAttackParam;  // offset: 0x50
    rAttackParam* mpAttackParamTable;  // offset: 0x58
    const cAttackParam* mpAttackParamOrg;  // offset: 0x60
    cChildRegionStatus* mpChildRegion;  // offset: 0x68
    cParentRegionStatus* mpParentRegion[2];  // offset: 0x70
    const cCalcDamageLvAdj* mpLvAdjData;  // offset: 0x80
    const cDmJobAdjParam* mpAtkDmJobAdjParam;  // offset: 0x88
    bool mIsAttackerShl;  // offset: 0x90
    uDDOModel* mpShlOwnerModel;  // offset: 0x98
    static MyDTI DTI;
};

class cHpDamageInfo : public MtObject
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
    cHpDamageInfo();
    void getInfoFromCM(const cHitInfoAfterCommon& info);
    f32 getDamageAttackAdj(nObjCollision::HP_DAMAGE_ATTACK_ADJ_TYPE type) const;
    f32 getDamageDefenceAdj(nObjCollision::HP_DAMAGE_DEFENCE_ADJ_TYPE type) const;
    void addDamageAttackAdj(nObjCollision::HP_DAMAGE_ATTACK_ADJ_TYPE type, f32 Adj);
    void addDamageDefenceAdj(nObjCollision::HP_DAMAGE_DEFENCE_ADJ_TYPE type, f32 Adj);
    void clear();
    f32 calcAttackAdjWithType() const;
    f32 calcDefenceAdjWithType() const;
public:
    f32 mAttackBasePhys;  // offset: 0x8
    f32 mAttackWeaponPhys;  // offset: 0xc
    f32 mAttackBaseMagic;  // offset: 0x10
    f32 mAttackWeaponMagic;  // offset: 0x14
    f32 mDefenceBasePhys;  // offset: 0x18
    f32 mDefenceWeaponPhys;  // offset: 0x1c
    f32 mDefenceBaseMagic;  // offset: 0x20
    f32 mDefenceWeaponMagic;  // offset: 0x24
    f32 mEnchantRate;  // offset: 0x28
    f32 mAtDmAdjRatePhys;  // offset: 0x2c
    f32 mAtDmAdjRateMagic;  // offset: 0x30
    f32 mLvAdj;  // offset: 0x34
    f32 mJobAdjEnchantDamage;  // offset: 0x38
    f32 mJobActionRateAdj;  // offset: 0x3c
    f32 mPawnAdjAttackBasePhys;  // offset: 0x40
    f32 mPawnAdjAttackBaseMagic;  // offset: 0x44
    f32 mPawnAdjAtDfRate;  // offset: 0x48
    f32 mPawnAdjFinalDamage;  // offset: 0x4c
    f32 mNormalDamage;  // offset: 0x50
    f32 mEnchantDamage;  // offset: 0x54
    f32 mDamage;  // offset: 0x58
    f32 mDamageGui;  // offset: 0x5c
    bool mIsRelustNoDamage;  // offset: 0x60
    bool mIsPhysDamage;  // offset: 0x61
    u32 mAttackReactionType;  // offset: 0x64
private:
    f32 mDamageAttackAdj[6];  // offset: 0x68
    f32 mDamageDefenceAdj[6];  // offset: 0x80
public:
    static MyDTI DTI;
};

class cHitInfoAfter : public MtObject
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
    cHitInfoAfter();
    virtual ~cHitInfoAfter();
    void makeInfoFromDmMsg(const cDamageMsg* pDmMsg, uDDOModel* pReceiver);
    void clearHitInfoAfter();
    bool checkAttackParamFlag(u64 flag) const;
    bool checkAttackParamAngleFlag(u32 flag) const;
    bool checkAttackParamGuard(nObjCollision::GUARD_ANGLE_TYPE type) const;
    bool checkAttackParamAttackId(u32 attackId) const;
    bool isWeakRegionDamage() const;
    bool isReceiveInfo() const;
    nObjCollision::HIT_INFO_TYPE getHitInfoType();
    void setHitInfoType(nObjCollision::HIT_INFO_TYPE type);
    void setResultBounusType(nObjCollision::RESULT_BONOUS_TYPE type);
    nObjCollision::RESULT_BONOUS_TYPE getResultBounusType() const;
    bool isCalcHpDamage() const;
    bool isCalcShrinkBlow() const;
    bool isCalcShake() const;
    bool isCalcStromQuake() const;
    bool isCalcFlick() const;
    bool isCalcOcd() const;
    bool isUseVisualEffect() const;
private:
    void operator=(const cHitInfoAfter&);
    cHitInfoAfter(const cHitInfoAfter&);
public:
    cHitInfoAfterCommon mCommonInfo;  // offset: 0x10
    cHpDamageInfo mHpDamageInfo;  // offset: 0xb0
    cBlowShrinkDmInfo mBlowShrinkDmInfo;  // offset: 0x148
    cOcdDamageInfo mOcdDamageInfo;  // offset: 0x278
    cHealedInfo mHealedInfo;  // offset: 0x8e8
    cHitInfoAfterLocal mLocalInfo;  // offset: 0x950
private:
    nObjCollision::HIT_INFO_TYPE mHitInfoType;  // offset: 0x980
    bool mIsHpDamage;  // offset: 0x984
    bool mIsShrinkBlow;  // offset: 0x985
    bool mIsShake;  // offset: 0x986
    bool mIsStromQuake;  // offset: 0x987
    bool mIsFlick;  // offset: 0x988
    bool mIsOcd;  // offset: 0x989
    bool mIsVisualEffect;  // offset: 0x98a
    nObjCollision::RESULT_BONOUS_TYPE mResultBounusType;  // offset: 0x98c
    bool mIsReceiveInfo;  // offset: 0x990
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// approximate: only approximate callers check this inline body
inline cHealedInfo::cHealedInfo() {
    this->mPawnAdjMagicBase = 0.0f;
    this->mPawnAdjMagicWep = 0.0f;
    this->mStaminaHealDefAdj[2] = 0.0f;
    this->mStaminaHealDefAdj[3] = 0.0f;
    this->mStaminaHealDefAdj[0] = 0.0f;
    this->mStaminaHealDefAdj[1] = 0.0f;
    this->mStaminaHealAtkAdj[2] = 0.0f;
    this->mStaminaHealAtkAdj[3] = 0.0f;
    this->mStaminaHealAtkAdj[0] = 0.0f;
    this->mStaminaHealAtkAdj[1] = 0.0f;
    this->mHpHealDefAdj[2] = 0.0f;
    this->mHpHealDefAdj[3] = 0.0f;
    this->mHpHealDefAdj[0] = 0.0f;
    this->mHpHealDefAdj[1] = 0.0f;
    this->mHpHealAtkAdj[2] = 0.0f;
    this->mHpHealAtkAdj[3] = 0.0f;
    this->mHpHealAtkAdj[0] = 0.0f;
    this->mHpHealAtkAdj[1] = 0.0f;
    this->mHpHealVal = 0.0f;
    this->mStaminaHealVal = 0.0f;
    this->mMagicBase = 0.0f;
    this->mMagicWep = 0.0f;
}

// Inline, no code of its own: checked where it is inlined.
inline bool cHitInfoAfter::isCalcHpDamage() const {
    return this->mIsHpDamage;
}

// Inline, no code of its own: checked where it is inlined.
inline bool cHitInfoAfter::isCalcOcd() const {
    return this->mIsOcd;
}
