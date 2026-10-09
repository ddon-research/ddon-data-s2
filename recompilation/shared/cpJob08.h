#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cpJobBase.h"
#include "nDDOUtility.h"
#include "nHumanBow.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cEfcHandle;
class cHitInfo;
class cHitInfoAfter;
class rSoundRequest;

// Declarations
class cpJob08;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cpJob08 : public cpJobBase
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
    cpJob08();
    virtual ~cpJob08();
    virtual void setup();  // vtable slot 6
    virtual void reset();  // vtable slot 20
    virtual void update();  // vtable slot 16
    virtual void updateEfcHandle();  // vtable slot 10
    virtual void setupJobData();  // vtable slot 21
    virtual void setupCustomData(u32 csId, u32 index);  // vtable slot 23
    void lockOnDamageAdjust(u8 bowNetBit);
    virtual void makeShlDamageAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 44
    virtual void makeHealedAttackInfo(cHitInfoAfter* pHitInfo);  // vtable slot 47
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 30
    rSoundRequest* getShlCstmSe(u32 index);
    rSoundRequest* getShlCommonSe();
    bool isLockChargeMax() const;
    void setIsLockChargeMax(bool flg);
    nHumanBow::MGC_BOW_CHARGE_LV getSlaveLockOnStep() const;
    void setLockOnStep(nHumanBow::MGC_BOW_CHARGE_LV lv);
    nHumanBow::MGC_BOW_CHARGE_LV getLockOnStep() const;
    void setLockOnCharge1Max(f32 time);
    void setLockOnCharge2Max(f32 time);
    f32 getLockOnCharge1Max() const;
    f32 getLockOnCharge2Max() const;
    void setLockOnChrgeTime(f32 time);
    f32 getLockOnChrgeTime() const;
    void setLockOnRange(u32 timer);
    u32 getLockOnRange() const;
    bool isLcokOnJust() const;
    void setIsLockOnJust(bool flg);
    void setIsCs12End(bool);
    bool isCs12End() const;
    void setCs12Stamina(f32 stamina);
    void addAirHealCnt();
    u32 getAirHealCnt() const;
private:
    nDDOUtility::cArray<rSoundRequest*, 4> mpCstmSkillShlSeList;  // offset: 0x58
    rSoundRequest* mpShlCommonSe;  // offset: 0x78
    cEfcHandle* mpEfcElement;  // offset: 0x80
    nHumanBow::MGC_BOW_CHARGE_LV mSlaveLockOnStep;  // offset: 0x88
    bool mIsLockChargeFinish;  // offset: 0x8c
    nHumanBow::MGC_BOW_CHARGE_LV mLockOnStep;  // offset: 0x90
    f32 mLockOnCharge1Max;  // offset: 0x94
    f32 mLockOnCharge2Max;  // offset: 0x98
    f32 mLockOnChargeTime;  // offset: 0x9c
    u32 mLockOnRange;  // offset: 0xa0
    bool mIsJustLockOn;  // offset: 0xa4
    u32 mAirHealCnt;  // offset: 0xa8
    bool mIsCs12End;  // offset: 0xac
    f32 mCs12Stamina;  // offset: 0xb0
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline rSoundRequest* cpJob08::getShlCommonSe() {
    return this->mpShlCommonSe;
}
