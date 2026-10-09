#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cpComponent.h"
#include "nErosionEnemyBase.h"
#include "nRegionStatus.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;
class cHitInfo;
class cHitInfoAfter;
class cHitNode;
class rAttackParam;
class rEffectProvider;
class rSoundRequest;
class uCharacter;

// Declarations
class cpErosionEnemyBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class cpErosionEnemyBase : public cpComponent
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
    cpErosionEnemyBase();
    virtual ~cpErosionEnemyBase();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 8
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    // Address: 0x0197b8e0 - 0x0197b8e1 (1 bytes)
    virtual void before() {}  // vtable slot 15
    virtual void update();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 9
    virtual void updateEfcHandle();  // vtable slot 10
    virtual void setupBeforeContext(bool initSet);  // vtable slot 17
    // Address: 0x0197b8f0 - 0x0197b8f1 (1 bytes)
    virtual void setupContextErosion(bool recvFlag, bool initSet) {}  // vtable slot 18
    // Address: 0x0197b900 - 0x0197b901 (1 bytes)
    virtual void callbackRegenerateErosionRegion(nRegionStatus::P_REGION_CATEGORY category) {}  // vtable slot 19
    // Address: 0x0197b910 - 0x0197b911 (1 bytes)
    virtual void callbackBreakErosionRegion(nRegionStatus::P_REGION_CATEGORY category) {}  // vtable slot 20
    virtual bool callbackErosionCancel(cHitInfoAfter* pHitInfo);  // vtable slot 21
    void setErosionSoundRes(rSoundRequest* pRes);
    rSoundRequest* getErosionSoundRes() const;
    virtual void setErosionAttackParam(rAttackParam* pRes, nErosionEnemyBase::EROSION_LEVEL level);  // vtable slot 22
    void releaseErosionAttackParam(nErosionEnemyBase::EROSION_LEVEL level);
    nErosionEnemyBase::EROSION_LEVEL getErosionCurrentLevel() const;
    nErosionEnemyBase::EROSION_LEVEL getErosionRealLevel() const;
    void callErosionEeffect(s32 indexNo, s32 elementNo, s32 JointNo, const MtVector3& offset);
    virtual bool isEnableErosionRegenerate() const;  // vtable slot 23
    virtual bool isErosionRegionActive(nRegionStatus::P_REGION_CATEGORY category) const;  // vtable slot 24
    virtual bool isErosionRegionActiveAll() const;  // vtable slot 25
    // Address: 0x0197b950 - 0x0197b951 (1 bytes)
    virtual void callbackChecked(cHitInfo* pHitInfo) {}  // vtable slot 26
    bool isErosionEnemy() const;
    bool isErosionEnemySmall() const;
    bool isErosionEnemySuper() const;
protected:
    bool reqChangeErosionCurrentLevel(nErosionEnemyBase::EROSION_LEVEL level, nErosionEnemyBase::EROSION_LEVEL oldLevel, bool initSet, bool isForce);
    bool reqChangeErosionRealLevel(nErosionEnemyBase::EROSION_LEVEL level, nErosionEnemyBase::EROSION_LEVEL oldLevel, bool initSet, bool isForce);
    virtual void callbackChangeErosionCurrentLevel(nErosionEnemyBase::EROSION_LEVEL level, nErosionEnemyBase::EROSION_LEVEL oldLevel, bool initSet);  // vtable slot 27
    virtual void callbackChangeErosionRealLevel(nErosionEnemyBase::EROSION_LEVEL level, nErosionEnemyBase::EROSION_LEVEL oldLevel, bool initSet);  // vtable slot 28
    rEffectProvider* getErosionEpv() const;
    void reqSetSynchronizeEffect(u64 syncFlag, u32 endType, s32 indexNo, s32 elementNo, s32 JointNo, const MtVector3& offset);
    void reqEndSynchronizeEffect(s32 indexNo, s32 elementNo);
    void reqOnSyncFlag(u64 syncFlag);
    void setErosionStatus(nErosionEnemyBase::EROSION_STATUS status);
    nErosionEnemyBase::EROSION_STATUS getErosionStatus() const;
    rAttackParam* getErosionAttackParam(nErosionEnemyBase::EROSION_LEVEL level) const;
    virtual bool isErosionCancelStatus(bool isCheckOcdCnacel) const;  // vtable slot 29
    void killErosionLinpunNode();
    s32 getLinpunEvpIndex() const;
private:
    void setErosionCurrentLevel(nErosionEnemyBase::EROSION_LEVEL level);
    void setErosionRealLevel(nErosionEnemyBase::EROSION_LEVEL level);
    nErosionEnemyBase::EROSION_LEVEL getErosionCancelLevel() const;
protected:
    uCharacter* mpEnemy;  // offset: 0x50
    cHitNode* mpErosionLinpunNode;  // offset: 0x58
    bool mIsErosionEnemy;  // offset: 0x60
    bool mIsErosionEnemySmall;  // offset: 0x61
    bool mIsErosionEnemySuper;  // offset: 0x62
private:
    rAttackParam* mpErosionAttackParamRes[5];  // offset: 0x68
    rSoundRequest* mpErosionSoundRes;  // offset: 0x90
    nErosionEnemyBase::EROSION_STATUS mErosionStatus;  // offset: 0x98
    nErosionEnemyBase::EROSION_LEVEL mErosionRealLevel;  // offset: 0x9c
    nErosionEnemyBase::EROSION_LEVEL mErosionCurrentLevel;  // offset: 0xa0
    s32 mLinpunEpvIndexNo;  // offset: 0xa4
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline rSoundRequest* cpErosionEnemyBase::getErosionSoundRes() const {
    return this->mpErosionSoundRes;
}

// Inline, no code of its own: checked where it is inlined.
inline bool cpErosionEnemyBase::isErosionEnemy() const {
    return this->mIsErosionEnemy;
}

// Inline, no code of its own: checked where it is inlined.
inline bool cpErosionEnemyBase::isErosionEnemySmall() const {
    return this->mIsErosionEnemySmall;
}

// Inline, no code of its own: checked where it is inlined.
inline bool cpErosionEnemyBase::isErosionEnemySuper() const {
    return this->mIsErosionEnemySuper;
}

// Inline, no code of its own: checked where it is inlined.
inline nErosionEnemyBase::EROSION_STATUS cpErosionEnemyBase::getErosionStatus() const {
    return this->mErosionStatus;
}
