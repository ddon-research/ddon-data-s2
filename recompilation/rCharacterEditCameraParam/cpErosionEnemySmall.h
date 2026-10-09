#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cpErosionEnemyBase.h"
#include "../shared/nErosionEnemyBase.h"
#include "nErosionEnemySmall.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cHitInfo;
class cHitInfoAfter;
class cHitNode;
class rErosionSmallInfoRes;

// Declarations
class cpErosionEnemySmall;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpErosionEnemySmall : public cpErosionEnemyBase
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
    cpErosionEnemySmall();
    virtual ~cpErosionEnemySmall();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 8
    virtual void update();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 9
    virtual void updateEfcHandle();  // vtable slot 10
    virtual void setupBeforeContext(bool initSet);  // vtable slot 17
    virtual void setupContextErosion(bool recvFlag, bool initSet);  // vtable slot 18
    virtual bool isErosionRegionActiveAll() const;  // vtable slot 25
    virtual void callbackChecked(cHitInfo* pHitInfo);  // vtable slot 26
    virtual bool callbackErosionCancel(cHitInfoAfter* pHitInfo);  // vtable slot 21
    void setErosionSmallInfoRes(rErosionSmallInfoRes* pRes);
    f32 getEnemyErosionScaleRate() const;
protected:
    virtual bool isErosionCancelStatus(bool isCheckOcdCnacel) const;  // vtable slot 29
private:
    void checkReciveMsg();
    void updateErosionCancelTimer();
    void activeteErosion();
    void updateErosionLevel();
    void updateErosionMode();
    virtual void callbackChangeErosionCurrentLevel(nErosionEnemyBase::EROSION_LEVEL level, nErosionEnemyBase::EROSION_LEVEL oldLevel, bool initSet);  // vtable slot 27
    virtual void callbackChangeErosionRealLevel(nErosionEnemyBase::EROSION_LEVEL level, nErosionEnemyBase::EROSION_LEVEL oldLevel, bool initSet);  // vtable slot 28
    void changeErosionLevelEffect(nErosionEnemyBase::EROSION_LEVEL level, nErosionEnemyBase::EROSION_LEVEL oldLevel, bool initSet);
    void changeErosionLevelCollision(nErosionEnemyBase::EROSION_LEVEL level, nErosionEnemyBase::EROSION_LEVEL oldLevel, bool initSet);
    void changeErosionLevelSound(nErosionEnemyBase::EROSION_LEVEL level, nErosionEnemyBase::EROSION_LEVEL oldLevel, bool initSet);
    void setErosionSmallMode(nErosionEnemySmall::EROSION_SMALL_MODE mode);
    void setErosionCancelStatus(nErosionEnemySmall::EROSION_SMALL_STATUS status);
    void killErosionCheckNode();
    void killErosionCheckedNode();
    bool isErosionActiveSituation() const;
    nErosionEnemySmall::EROSION_SMALL_MODE getErosionSmallMode() const;
    nErosionEnemySmall::EROSION_SMALL_STATUS getErosionCancelStatus() const;
private:
    rErosionSmallInfoRes* mpErosionSmallInfoRes;  // offset: 0xa8
    nErosionEnemySmall::EROSION_SMALL_MODE mErosionSmallMode;  // offset: 0xb0
    nErosionEnemySmall::EROSION_SMALL_STATUS mErosionCancelStatus;  // offset: 0xb4
    cHitNode* mpErosionCheckedNode;  // offset: 0xb8
    cHitNode* mpErosionCheckNode;  // offset: 0xc0
    f32 mErosionScaleRate;  // offset: 0xc8
    f32 mErosionActiveTimerMax;  // offset: 0xcc
    f32 mErosionActiveTimer;  // offset: 0xd0
    f32 mErosionCancelTimerMax;  // offset: 0xd4
    f32 mErosionCancelTimer;  // offset: 0xd8
    f32 mErosionCancelWaitTimerMax;  // offset: 0xdc
    f32 mErosionCancelWaitTimer;  // offset: 0xe0
protected:
    nErosionEnemySmall::EROSION_TYPE_SMALL mErosionSmallType;  // offset: 0xe4
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline nErosionEnemySmall::EROSION_SMALL_MODE cpErosionEnemySmall::getErosionSmallMode() const {
    return this->mErosionSmallMode;
}

// Inline, no code of its own: checked where it is inlined.
inline nErosionEnemySmall::EROSION_SMALL_STATUS cpErosionEnemySmall::getErosionCancelStatus() const {
    return this->mErosionCancelStatus;
}
