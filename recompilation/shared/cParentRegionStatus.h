#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"
#include "cBlowShrinkInfo.h"
#include "nObjCollision.h"
#include "nRegionStatus.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class cBlowShrinkInfo;
class cHitInfoAfter;
class cParentRegionStatusParam;
class cpHpDamageCtrl;
class rRegionBreakInfo;
class uDDOModel;

// Declarations
class cParentRegionStatus;

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using u64 = __uint64_t;
using HP_DATATYPE = u64;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cParentRegionStatus : public MtObject
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
    cParentRegionStatus();
    virtual ~cParentRegionStatus();
    void update(f32 deltaTime);
    void callbackDamageAfter(cHitInfoAfter* pHitInfo);
    void addDamage(HP_DATATYPE damage, bool isNoDeath, nObjCollision::UNIT_INV_THROUGH_TYPE invThroughType);
    void setParamFromRes(cParentRegionStatusParam* paramRes, bool initSet);
    void setNo(u32);
    void setHp(HP_DATATYPE hp);
    void setHpMax(HP_DATATYPE hpMax);
    void setIsDead(bool flag);
    u32 getNo() const;
    u32 getBreakReactionNo() const;
    HP_DATATYPE getHp() const;
    HP_DATATYPE getHpMax() const;
    bool isDead() const;
    bool isMainRegion() const;
    bool isDamageToMain() const;
    bool healHp(HP_DATATYPE addHp, bool isForce);
    void subHp(HP_DATATYPE subHp);
    f32 getHpRate() const;
    void regenerateMaster(HP_DATATYPE addHp);
    void regenerateMasterSlave();
    bool isEnableRegenerate(bool isMaster) const;
    void suicideMaster();
    void suicideMasterSlave();
    bool isEnableSuicide(bool isMaster) const;
    void setModel(uDDOModel* pOwnerModel);
    void setOwnerClass(cpHpDamageCtrl* pOwnerClass);
    cBlowShrinkInfo* getShrinkInfo();
    cBlowShrinkInfo* getBlowInfo();
    void updatePtr();
    void resetParam();
    void applyRegionBreakInfo();
    nRegionStatus::P_REGION_CATEGORY getRegionCategory() const;
    nRegionStatus::REGION_REGENERATE_PRIORITY getRegenerateProprity() const;
private:
    const rRegionBreakInfo* getRegionBreakInfo() const;
    void setRegionBreakInfo(rRegionBreakInfo* pRes);
private:
    u32 mNo;  // offset: 0x8
    nRegionStatus::P_REGION_CATEGORY mRegionCategory;  // offset: 0xc
    bool mIsReGenerate;  // offset: 0x10
    nRegionStatus::REGION_REGENERATE_PRIORITY mRegenerateProprirty;  // offset: 0x14
    bool mIsDamageToMain;  // offset: 0x18
    cBlowShrinkInfo mShrinkInfo;  // offset: 0x20
    cBlowShrinkInfo mBlowInfo;  // offset: 0x58
    uDDOModel* mpOwnerModel;  // offset: 0x90
    cpHpDamageCtrl* mpOwnerHpDmageCtrl;  // offset: 0x98
    u32 mBreakReactionNo;  // offset: 0xa0
    rRegionBreakInfo* mpRegionBreakInfo;  // offset: 0xa8
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline nRegionStatus::P_REGION_CATEGORY cParentRegionStatus::getRegionCategory() const {
    return this->mRegionCategory;
}
