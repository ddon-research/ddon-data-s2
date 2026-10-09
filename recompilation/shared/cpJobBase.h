#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
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
    // Address: 0x01981680 - 0x01981681 (1 bytes)
    virtual void callbackUpdateAfter() {}  // vtable slot 17
    virtual void after();  // vtable slot 18
    // Address: 0x01a5a910 - 0x01a5a911 (1 bytes)
    virtual void init() {}  // vtable slot 19
    virtual void updatePtr();  // vtable slot 9
    virtual void reset();  // vtable slot 20
    virtual void setupJobData();  // vtable slot 21
    // Address: 0x01a5a920 - 0x01a5a921 (1 bytes)
    virtual void setupJobDataSafeArea() {}  // vtable slot 22
    // Address: 0x01981690 - 0x01981691 (1 bytes)
    virtual void setupCustomData(u32 csId, u32 index) {}  // vtable slot 23
    // Address: 0x019816a0 - 0x019816a1 (1 bytes)
    virtual void callbackReplaceHitInfo_Atk(cHitInfo* pHitInfo) {}  // vtable slot 24
    // Address: 0x019816b0 - 0x019816b1 (1 bytes)
    virtual void callbackReplaceHitInfo_Def(cHitInfo* pHitInfo) {}  // vtable slot 25
    // Address: 0x019816c0 - 0x019816c1 (1 bytes)
    virtual void callbackGuard(cHitInfo* pHitInfo) {}  // vtable slot 26
    // Address: 0x019816d0 - 0x019816d1 (1 bytes)
    virtual void callbackGuard_make(cHitInfo* pHitInfo) {}  // vtable slot 27
    // Address: 0x019816e0 - 0x019816e1 (1 bytes)
    virtual void callbackGuard_calc(cHitInfo* pHitInfo) {}  // vtable slot 28
    virtual void callbackGuardEffect(cHitInfo* pHitInfo);  // vtable slot 29
    // Address: 0x01a5b2a0 - 0x01a5b2a1 (1 bytes)
    virtual void callbackAttack(cHitInfo* pHitInfo) {}  // vtable slot 30
    // Address: 0x019816f0 - 0x019816f1 (1 bytes)
    virtual void callbackHitLand() {}  // vtable slot 31
    // Address: 0x01981700 - 0x01981701 (1 bytes)
    virtual void callbackReqOcdAction(cOcdInfo& OcdInfo, bool initFlag) {}  // vtable slot 32
    // Address: 0x01a5a930 - 0x01a5a931 (1 bytes)
    virtual void callbackDamage(cHitInfo* pHitLocalInfo) {}  // vtable slot 33
    // Address: 0x01981710 - 0x01981711 (1 bytes)
    virtual void callbackAttackTest(cHitInfo* pHitInfo) {}  // vtable slot 34
    // Address: 0x01981720 - 0x01981721 (1 bytes)
    virtual void callbackAttackTest_ShlNotify(cHitInfo* pHitInfo) {}  // vtable slot 35
    // Address: 0x01a5a940 - 0x01a5a941 (1 bytes)
    virtual void callbackDamageTest(cHitInfo* pHitInfo) {}  // vtable slot 36
    // Address: 0x01a5a950 - 0x01a5a951 (1 bytes)
    virtual void callbackCaughtTest(cHitInfo* pHitInfo) {}  // vtable slot 37
    // Address: 0x01981730 - 0x01981731 (1 bytes)
    virtual void callbackDamageAfter(cHitInfoAfter* pHitInfo) {}  // vtable slot 38
    // Address: 0x01981740 - 0x01981741 (1 bytes)
    virtual void callbackDamageAfter_make(cHitInfoAfter* pHitInfo) {}  // vtable slot 39
    // Address: 0x01981750 - 0x01981751 (1 bytes)
    virtual void callbackDamageAfter_calc(cHitInfoAfter* pHitInfo) {}  // vtable slot 40
    // Address: 0x01981760 - 0x01981761 (1 bytes)
    virtual void callbackDamageAfter_apply(cHitInfoAfter* pHitInfo) {}  // vtable slot 41
    // Address: 0x01981770 - 0x01981771 (1 bytes)
    virtual void makeBlowShrinkAttackInfo(cBlowShrinkDmInfo* pInfo, uDDOModel* pAttacker, uDDOModel* pDefender, u32 atkAdjustUniqueId) {}  // vtable slot 42
    // Address: 0x01981780 - 0x01981781 (1 bytes)
    virtual void makeDamageAttackInfo(cHitInfoAfter* pDamageInfo) {}  // vtable slot 43
    // Address: 0x01a5a960 - 0x01a5a961 (1 bytes)
    virtual void makeShlDamageAttackInfo(cHitInfoAfter* pInfo) {}  // vtable slot 44
    // Address: 0x01981790 - 0x01981791 (1 bytes)
    virtual void makeOcdAttackInfo(cHitInfoAfter* pHitInfo) {}  // vtable slot 45
    // Address: 0x019817a0 - 0x019817a1 (1 bytes)
    virtual void makeOcdAttackInfoShl(cHitInfoAfter* pHitInfo) {}  // vtable slot 46
    // Address: 0x019817b0 - 0x019817b1 (1 bytes)
    virtual void makeHealedAttackInfo(cHitInfoAfter* pHitInfo) {}  // vtable slot 47
    // Address: 0x019817c0 - 0x019817c1 (1 bytes)
    virtual void callbackCatch(cHitInfo* pHitInfo) {}  // vtable slot 48
    // Address: 0x019817d0 - 0x019817d1 (1 bytes)
    virtual void callbackCatch_Shl(cShlNotifyInfo* pInfo) {}  // vtable slot 49
    // Address: 0x019817e0 - 0x019817e1 (1 bytes)
    virtual void callbackDie() {}  // vtable slot 50
    // Address: 0x019817f0 - 0x019817f1 (1 bytes)
    virtual void callbackOcdSeal() {}  // vtable slot 51
    // Address: 0x01981800 - 0x01981801 (1 bytes)
    virtual void callbackCreateShl(uShlBase* pShl) {}  // vtable slot 52
    // Address: 0x01981810 - 0x01981811 (1 bytes)
    virtual void callbackEquipJob(nCharacterData::EQUIP_SLOT_TYPE category) {}  // vtable slot 53
    // Address: 0x01981820 - 0x01981821 (1 bytes)
    virtual void callbackCSChange() {}  // vtable slot 54
    // Address: 0x01981830 - 0x01981831 (1 bytes)
    virtual void callbackWarpInStage() {}  // vtable slot 55
    // Address: 0x01981840 - 0x01981841 (1 bytes)
    virtual void notifyDeleteShell(s32 work) {}  // vtable slot 56
    void chargeNetwork();
    virtual u32 replaceCollisionAttr(u32 attr, const cCollNode* pCollNode);  // vtable slot 57
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    // Address: 0x01981860 - 0x01981861 (1 bytes)
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

// Inline, no code of its own: checked where it is inlined.
inline cpJobBase::cpJobBase() {
    this->mpHuman = static_cast<uHuman*>(nullptr);
}
