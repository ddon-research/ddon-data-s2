#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtObject.h"
#include "cEfcHandle.h"
#include "cEmRandomCtrl.h"
#include "cErosionRegion.h"
#include "cpErosionEnemyBase.h"
#include "nDDOUtility.h"
#include "nErosionEnemy.h"
#include "nErosionEnemyBase.h"
#include "nRegionStatus.h"
#include "rErosionRegion.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cEfcHandle;
class cEmRandomCtrl;
class cErosionRegion;
class cErosionRegionRes;
class cErosionSuperInfoRes;
class cHitInfoAfter;
class cHitNode;
class cpCorePointCtrl;
class cpHpDamageCtrl;
class rErosionInfoRes;
class rErosionRegion;
class rErosionRegionScaleChange;
class rErosionSuperInfoRes;
class rSoundRequest;
class uEnemy;

// Declarations
class cTentacleInfo;
class cpErosionEnemy;
class cpErosionSuperEnemy;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using cErosionRegionArray = nDDOUtility::cArray<cErosionRegion, 4>;
using cTentacleInfoArray = nDDOUtility::cArray<cTentacleInfo, 4>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class cTentacleInfo : public MtObject
{
public:
    enum
    {
        SUB_TENTACLE_STATE_NONE = 0,
        SUB_TENTACLE_STATE_PAUSE = 1,
        SUB_TENTACLE_STATE_GET_UP = 2,
        SUB_TENTACLE_STATE_MOVE = 3,
        SUB_TENTACLE_STATE_STOP = 4,
    };
    enum
    {
        EFFECT_TYPE_DEF_TENTACLE = 0,
        EFFECT_TYPE_EROSION_TENTACLE = 1,
        EFFECT_TYPE_TENTACLE_BREAK_BY_COREPOINT = 2,
        EFFECT_TYPE_TENTACLE_BREAK_BY_EROSION = 3,
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
    cTentacleInfo();
    // Address: 0x019812a0 - 0x019812a1 (1 bytes)
    virtual ~cTentacleInfo() {}
    void updatePtr();
    void setOwner(uEnemy* pEnemy);
    void update();
    void updateApply();
    void setSyncBit(u64 no);
    void setSyncBitErosion(u64 no);
    void registTantacleInfo(const cErosionSuperInfoRes& erosionData);
    void requsetAllTentacle();
    void requsetTentacleStop();
    void requsetAllTentacleGetUp();
    s32 getCorePointType() const;
    bool isTentacleActive() const;
    void makeDamageDefenceInfo(cHitInfoAfter& info);
private:
    void updateTentacleMove();
    void updateTentacleStop();
    void callbackStop();
    void callbackPause();
    void getTentacleEffecIndex(u32 type, s32& index, s32& no);
    s32 getTentacleEffectJointNo(const s32 index, const s32 no);
private:
    cErosionSuperInfoRes mErosionSuperInfo;  // offset: 0x8
    u32 mTentacleState;  // offset: 0x20
    u32 mTentacleStateOld;  // offset: 0x24
    u64 mSyncBit;  // offset: 0x28
    u64 mSyncBitErosion;  // offset: 0x30
    bool mRequestTentacle;  // offset: 0x38
    bool mRequestTentacleStop;  // offset: 0x39
    bool mRequestTentacleGetUp;  // offset: 0x3a
    bool mSetEffect;  // offset: 0x3b
    bool mSetEffectErosion;  // offset: 0x3c
    uEnemy* mpEnemy;  // offset: 0x40
    f32 mTimeCountGetUp;  // offset: 0x48
    f32 mTimeCountNoCheckCorePoint;  // offset: 0x4c
public:
    static MyDTI DTI;
};

class cpErosionEnemy : public cpErosionEnemyBase
{
    // inferred: cpHpDamageCtrl::regionErosionRegenerateCateInit names cpErosionEnemy::mErosionProgression
    friend class cpHpDamageCtrl;
public:
    class MyDTI;
    struct stRegenerateOrder;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stRegenerateOrder
    {
    public:
        stRegenerateOrder();
        void clear();
        void setInfo(s32 index, nRegionStatus::REGION_REGENERATE_PRIORITY priority);
        void setInfo(const cpErosionEnemy::stRegenerateOrder& src);
        nRegionStatus::REGION_REGENERATE_PRIORITY getPriority() const;
        bool isSeted() const;
        s32 getIndex() const;
    private:
        s32 mRegionIndex;  // offset: 0x0
        nRegionStatus::REGION_REGENERATE_PRIORITY mPriority;  // offset: 0x4
        bool mIsSeted;  // offset: 0x8
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
    cpErosionEnemy();
    virtual ~cpErosionEnemy();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 8
    virtual void before();  // vtable slot 15
    virtual void update();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 9
    virtual void updateEfcHandle();  // vtable slot 10
    virtual void setupBeforeContext(bool initSet);  // vtable slot 17
    virtual void setupContextErosion(bool recvFlag, bool initSet);  // vtable slot 18
    virtual void callbackRegenerateErosionRegion(nRegionStatus::P_REGION_CATEGORY category);  // vtable slot 19
    virtual void callbackBreakErosionRegion(nRegionStatus::P_REGION_CATEGORY category);  // vtable slot 20
    virtual bool callbackErosionCancel(cHitInfoAfter* pHitInfo);  // vtable slot 21
    void callbackDamageAfter_apply(cHitInfoAfter* pHitInfo);
    virtual bool isEnableErosionRegenerate() const;  // vtable slot 23
    virtual bool isErosionRegionActive(nRegionStatus::P_REGION_CATEGORY category) const;  // vtable slot 24
    bool isErosionRegionActiveInit(nRegionStatus::P_REGION_CATEGORY category) const;
    virtual bool isErosionRegionActiveAll() const;  // vtable slot 25
    virtual bool isErosionRegionActiveNone() const;  // vtable slot 30
    void setErosionInfoRes(rErosionInfoRes* pRes);
    void setErosionRegionRes(rErosionRegion* pRes);
    void setErosionScaleChangeRes(rErosionRegionScaleChange* pRes);
    rErosionRegionScaleChange* getErosionScaleChangeRes() const;
    nErosionEnemy::EROSION_PROGRESSION getErosionProgression() const;
    nErosionEnemy::EROSION_TIMER_STATE getErosionTimerState() const;
    nRegionStatus::P_REGION_TYPE getInactiveRegionNo_PriorityHigh() const;
    f32 getErosionCancelTime() const;
    nErosionEnemy::EROSION_INIT_TYPE getErosionInitType() const;
protected:
    void releaseErosionRegionRes();
    void registErosionRegion(const cErosionRegionRes& data, u32 index);
    void clearErosionRegion();
    void updateErosionLevel();
    void updateErosionRegenerateTimer();
    virtual void callbackChangeErosionCurrentLevel(nErosionEnemyBase::EROSION_LEVEL level, nErosionEnemyBase::EROSION_LEVEL oldLevel, bool initSet);  // vtable slot 27
    virtual void callbackChangeErosionRealLevel(nErosionEnemyBase::EROSION_LEVEL level, nErosionEnemyBase::EROSION_LEVEL oldLevel, bool initSet);  // vtable slot 28
    void changeErosionLevelEffect(nErosionEnemyBase::EROSION_LEVEL level, nErosionEnemyBase::EROSION_LEVEL oldLevel, bool initSet);
    void changeErosionLevelCollision(nErosionEnemyBase::EROSION_LEVEL level, nErosionEnemyBase::EROSION_LEVEL oldLevel, bool initSet);
    void changeErosionLevelSound(nErosionEnemyBase::EROSION_LEVEL level, nErosionEnemyBase::EROSION_LEVEL oldLevel, bool initSet);
    void changeErosionLevelTimer(nErosionEnemyBase::EROSION_LEVEL level, nErosionEnemyBase::EROSION_LEVEL oldLevel, bool initSet);
    void killErosionCheckNode();
    bool isTimerCount() const;
    bool isErosionActiveSituation() const;
    void changeErosionTimerState(nErosionEnemy::EROSION_TIMER_STATE state);
    void setupRandomErosionTimer();
    f32 calcErosionTimerRate() const;
    void makeRegenerateOrder();
    cpCorePointCtrl* getCorePointCtrl() const;
protected:
    cErosionRegionArray mErosionRegionArray;  // offset: 0xa8
    s32 mErosionRegionNum;  // offset: 0x268
    rErosionInfoRes* mpErosionInfoRes;  // offset: 0x270
    rErosionRegion* mpErosionRegionRes;  // offset: 0x278
    rErosionRegionScaleChange* mpErosionScaleChangeRes;  // offset: 0x280
    cHitNode* mpErosionCheckNode;  // offset: 0x288
    nErosionEnemy::EROSION_PROGRESSION mErosionProgression;  // offset: 0x290
    nErosionEnemy::EROSION_TIMER_STATE mErosionTimerState;  // offset: 0x294
    nErosionEnemyBase::EROSION_LEVEL mErosionRealLevelMax;  // offset: 0x298
    f32 mErosionRegenerateTimer;  // offset: 0x29c
    f32 mErosionRegenerateTimerRate;  // offset: 0x2a0
    f32 mErosionCancelTime;  // offset: 0x2a4
    cEmRandomCtrl mErosionRandomCtrl;  // offset: 0x2a8
    stRegenerateOrder mRegenerateOrder[4];  // offset: 0x2b8
    nErosionEnemy::EROSION_TYPE mErosionType;  // offset: 0x2e8
    nErosionEnemy::EROSION_INIT_TYPE mErosionInitType;  // offset: 0x2ec
public:
    static MyDTI DTI;
};

class cpErosionSuperEnemy : public cpErosionEnemy
{
public:
    enum
    {
        TENTACLE_STATE_NONE = 0,
        TENTACLE_STATE_INIT = 1,
        TENTACLE_STATE_REQUSET = 2,
        TENTACLE_STATE_REQUSET_GET_UP = 3,
        TENTACLE_STATE_MOVE = 4,
        TENTACLE_STATE_STOP = 5,
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
    cpErosionSuperEnemy();
    virtual void setup();  // vtable slot 6
    virtual void updatePtr();  // vtable slot 9
    virtual void updateEfcHandle();  // vtable slot 10
    virtual void update();  // vtable slot 16
    virtual void kill();  // vtable slot 8
    void setErosionSuperInfoRes(rErosionSuperInfoRes* pRes);
    bool isTentacleActive(s32 coretype);
    void makeDamageDefenceInfo(cHitInfoAfter& info);
    void callbackGetUpFromChanceDown();
    void setErosionSuperSoundRes(rSoundRequest* pRes);
    rSoundRequest* getErosionSuperSoundRes() const;
    void requestTentacleNoticeSe(s32 joint);
    bool isAllTentacleOff();
private:
    void updateTentacle();
    bool isUpdateTentacle();
    void setupCameraEffect();
    void updateCameraEffect();
    void activeCameraEffect();
    void disactiveCameraEffect();
    bool isEnableCreateCameraEffect() const;
private:
    rErosionSuperInfoRes* mprErosionSuperInfoRes;  // offset: 0x2f0
    u32 mTentacleState;  // offset: 0x2f8
    cTentacleInfoArray mTentacleInfoArray;  // offset: 0x300
    bool mFlgGetUpFromChanceDown;  // offset: 0x440
    MtTypedArray<cEfcHandle> mEfcCameraHandleArray;  // offset: 0x448
    bool mEfcCameraAdded;  // offset: 0x468
    bool mEfcCameraSeted;  // offset: 0x469
    rSoundRequest* mpErosionSuperSoundRes;  // offset: 0x470
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline rSoundRequest* cpErosionSuperEnemy::getErosionSuperSoundRes() const {
    return this->mpErosionSuperSoundRes;
}
