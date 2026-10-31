#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cpComponent.h"
#include "nCharacterData.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cBlowShrinkDmInfo;
class cCollNode;
class cHitInfo;
class cHitInfoAfter;
class cOcdInfo;
class cShlNotifyInfo;
class uDDOModel;
class uHuman;
class uShlBase;

// Declarations
class cpJobBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cpJobBase : public cpComponent
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
    cpJobBase();
    virtual ~cpJobBase();
    virtual void setup();  // vtable slot 6
    virtual void before();  // vtable slot 15
    virtual void update();  // vtable slot 16
    virtual void callbackUpdateAfter() {}  // vtable slot 17
    virtual void after();  // vtable slot 18
    virtual void init() {}  // vtable slot 19
    virtual void updatePtr();  // vtable slot 9
    virtual void reset();  // vtable slot 20
    virtual void setupJobData();  // vtable slot 21
    virtual void setupJobDataSafeArea() {}  // vtable slot 22
    virtual void setupCustomData(u32 csId, u32 index) {}  // vtable slot 23
    virtual void callbackReplaceHitInfo_Atk(cHitInfo* pHitInfo) {}  // vtable slot 24
    virtual void callbackReplaceHitInfo_Def(cHitInfo* pHitInfo) {}  // vtable slot 25
    virtual void callbackGuard(cHitInfo* pHitInfo) {}  // vtable slot 26
    virtual void callbackGuard_make(cHitInfo* pHitInfo) {}  // vtable slot 27
    virtual void callbackGuard_calc(cHitInfo* pHitInfo) {}  // vtable slot 28
    virtual void callbackGuardEffect(cHitInfo* pHitInfo);  // vtable slot 29
    virtual void callbackAttack(cHitInfo* pHitInfo) {}  // vtable slot 30
    virtual void callbackHitLand() {}  // vtable slot 31
    virtual void callbackReqOcdAction(cOcdInfo& OcdInfo, bool initFlag) {}  // vtable slot 32
    virtual void callbackDamage(cHitInfo* pHitLocalInfo) {}  // vtable slot 33
    virtual void callbackAttackTest(cHitInfo* pHitInfo) {}  // vtable slot 34
    virtual void callbackAttackTest_ShlNotify(cHitInfo* pHitInfo) {}  // vtable slot 35
    virtual void callbackDamageTest(cHitInfo* pHitInfo) {}  // vtable slot 36
    virtual void callbackCaughtTest(cHitInfo* pHitInfo) {}  // vtable slot 37
    virtual void callbackDamageAfter(cHitInfoAfter* pHitInfo) {}  // vtable slot 38
    virtual void callbackDamageAfter_make(cHitInfoAfter* pHitInfo) {}  // vtable slot 39
    virtual void callbackDamageAfter_calc(cHitInfoAfter* pHitInfo) {}  // vtable slot 40
    virtual void callbackDamageAfter_apply(cHitInfoAfter* pHitInfo) {}  // vtable slot 41
    virtual void makeBlowShrinkAttackInfo(cBlowShrinkDmInfo* pInfo, uDDOModel* pAttacker, uDDOModel* pDefender, u32 atkAdjustUniqueId) {}  // vtable slot 42
    virtual void makeDamageAttackInfo(cHitInfoAfter* pDamageInfo) {}  // vtable slot 43
    virtual void makeShlDamageAttackInfo(cHitInfoAfter* pInfo) {}  // vtable slot 44
    virtual void makeOcdAttackInfo(cHitInfoAfter* pHitInfo) {}  // vtable slot 45
    virtual void makeOcdAttackInfoShl(cHitInfoAfter* pHitInfo) {}  // vtable slot 46
    virtual void makeHealedAttackInfo(cHitInfoAfter* pHitInfo) {}  // vtable slot 47
    virtual void callbackCatch(cHitInfo* pHitInfo) {}  // vtable slot 48
    virtual void callbackCatch_Shl(cShlNotifyInfo* pInfo) {}  // vtable slot 49
    virtual void callbackDie() {}  // vtable slot 50
    virtual void callbackOcdSeal() {}  // vtable slot 51
    virtual void callbackCreateShl(uShlBase* pShl) {}  // vtable slot 52
    virtual void callbackEquipJob(nCharacterData::EQUIP_SLOT_TYPE category) {}  // vtable slot 53
    virtual void callbackCSChange() {}  // vtable slot 54
    virtual void callbackWarpInStage() {}  // vtable slot 55
    virtual void notifyDeleteShell(s32 work) {}  // vtable slot 56
    void chargeNetwork();
    virtual u32 replaceCollisionAttr(u32 attr, const cCollNode* pCollNode);  // vtable slot 57
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void checkReplaceInfo(cHitInfoAfter& HitInfo) {}  // vtable slot 58
protected:
    void setJobMotion(MT_CTSTR tag, MT_CTSTR id, u32 bank);
    void setJobMotionParam(MT_CTSTR tag, MT_CTSTR id, u32 bank);
    void setJobParam(MT_CTSTR tag, MT_CTSTR id);
    void setJumpParam(MT_CTSTR tag, MT_CTSTR id);
    void setCollision(MT_CTSTR tag, MT_CTSTR id, u32 bank);
    void setShlParam(MT_CTSTR tag, MT_CTSTR id);
    void setEpvData(MT_CTSTR tag, MT_CTSTR id);
    void setJobSe(MT_CTSTR tag, MT_CTSTR id);
    void setStaminaParam(MT_CTSTR tag, MT_CTSTR id);
    void setCameraParam(MT_CTSTR tag, MT_CTSTR id);
    void setMagicChantParam(MT_CTSTR tag, MT_CTSTR id);
protected:
    uHuman* mpHuman;  // offset: 0x50
public:
    static MyDTI DTI;
};

inline cpJobBase::cpJobBase() {
    this->mpHuman = nullptr;
}
