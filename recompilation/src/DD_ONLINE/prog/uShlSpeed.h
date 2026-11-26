#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "nShlBase.h"
#include "uShlBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cEfcHandle;
class cHitGeom;
class cHitInfo;
namespace nShlBase { class cShlFuwaMove; }

// Declarations
class cShlParamSpeed;
class uShlSpeed;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamSpeed : public cShlParamBase
{
public:
    enum
    {
        SO_HIT_SHL_OBJ_HIT = 1,
        SO_HIT_SHL_FLOOR_HIT = 2,
        SO_HIT_SHL_DIE_DIST = 4,
        SO_TURN_MOVE_VEC = 8,
        SO_ENCHANT_SE = 16,
        SO_NO_HIT_SCR_TARGET = 32,
        SO_NO_GRAVITY_TARGET = 64,
        SO_NOHIT_SCR_HIT_OBJ = 128,
        SO_INIT_SCR_CHECK_OFF = 256,
        SO_HIT_STOP_NO_GRAVITY = 512,
        SO_SHL_FLOOR_CONTROLER = 1024,
        SO_SHL_OBJ_HIT_NODEAD = 2048,
        SO_SHL_THROUGH_GROUND_HIT = 4096,
        SO_HIT_SHL_GUARD_HIT = 8192,
        SO_USE_SCR_NORMAL = 16384,
        SO_FUWA_Y_ONLY = 32768,
        SO_SPEED_DEFAULT = 15,
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
    cShlParamSpeed();
    virtual ~cShlParamSpeed();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 8
    virtual void createPropertySE(MtPropertyList& s);  // vtable slot 9
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    f32 spd;  // offset: 0x160
    f32 spdMax;  // offset: 0x164
    f32 spdAccel;  // offset: 0x168
    f32 spdAccelDist;  // offset: 0x16c
    f32 gravity;  // offset: 0x170
    f32 gravityMax;  // offset: 0x174
    f32 gravityAccel;  // offset: 0x178
    f32 gravityDist;  // offset: 0x17c
    f32 dieDist;  // offset: 0x180
    u32 dieFlag;  // offset: 0x184
    bool isTurnMoveVec;  // offset: 0x188
    f32 hitSlowRate;  // offset: 0x18c
    f32 hitSlowFrame;  // offset: 0x190
    f32 hitAdjustPosRate;  // offset: 0x194
    s32 hitAdjustCount;  // offset: 0x198
    bool isFuwaMove;  // offset: 0x19c
    f32 fuwaPeriod;  // offset: 0x1a0
    f32 fuwaScale;  // offset: 0x1a4
    f32 fuwaRandom;  // offset: 0x1a8
    bool isAutoLockon;  // offset: 0x1ac
    f32 lockonDist;  // offset: 0x1b0
    f32 lockonDeg;  // offset: 0x1b4
    u32 lockonOption;  // offset: 0x1b8
    f32 dirAdjustDist;  // offset: 0x1bc
    s32 hitShlNo;  // offset: 0x1c0
    s32 floorHitShlNo;  // offset: 0x1c4
    bool isEnchantShotSE;  // offset: 0x1c8
    u32 shlOptionSpeed;  // offset: 0x1cc
    s32 epvNoScrHit;  // offset: 0x1d0
    cShlParamBase::HIT_MARK_TYPE scrHitEfType;  // offset: 0x1d4
    s32 epvNoHitSlow;  // offset: 0x1d8
    cShlParamBase::RESOURCE_TYPE seHitScrResType;  // offset: 0x1dc
    s32 seNoScrHit;  // offset: 0x1e0
    s32 seNoHitSlow;  // offset: 0x1e4
    s32 seNoHitSlowStop;  // offset: 0x1e8
    bool useGravityMin;  // offset: 0x1ec
    static MyDTI DTI;
};

class uShlSpeed : public uShlBase
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
    const cShlParamSpeed* getShlParam() const;
    uShlSpeed();
    virtual ~uShlSpeed();
    virtual void setup();  // vtable slot 6
    virtual void initSub();  // vtable slot 177
    virtual void updateSub();  // vtable slot 175
    virtual void kill();  // vtable slot 16
    virtual void updateEfcHandle();  // vtable slot 58
    void setDieDistRate(f32);
    virtual void callbackAttack(cHitInfo* pHitInfo);  // vtable slot 83
protected:
    bool isDie();
    void movePos();
    virtual void movePosSub(f32 speed) {}  // vtable slot 186
    virtual void moveSpeedSub() {}  // vtable slot 187
    virtual u32 getCollisionIndex() const;  // vtable slot 181
    virtual void floorHit(const MtVector3& hitPos) {}  // vtable slot 188
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    virtual void progKillReqOrg() {}  // vtable slot 189
    f32 getSpeed() const;
    void setSpeed(f32 value);
    f32 getSpeedAccel() const;
    void setSpeedAccel(f32);
    f32 getSpeedMax() const;
    void setSpeedMax(f32 value);
    f32 getGravity() const;
    void setGravity(f32);
    f32 getDistance() const;
    void setDistance(f32);
    void checkScr();
    f32 getShlSpeedDeltaTime();
    uShlBase* createNextShlWithNormal(u32 index, u32 shotSts, bool isNow, const MtVector3& normal);
private:
    void setScrHitEfct(const MtVector3& pos, f32 scale);
protected:
    void setIsmIsThroughWater(bool flag);
public:
    void addExtendSpeedMax(f32 speed);
    virtual bool callbackRegistInterPolateGeom(MtVector3& oldPos, const MtVector3& currentPos, f32 radius, const cHitGeom* pGeom);  // vtable slot 144
protected:
    f32 mSpeedZ;  // offset: 0x2ab0
    f32 mSpeedAccel;  // offset: 0x2ab4
    f32 mSpeedMax;  // offset: 0x2ab8
    f32 mGravity;  // offset: 0x2abc
    f32 mDistance;  // offset: 0x2ac0
    f32 mDieDistRate;  // offset: 0x2ac4
    f32 mHitSlowFrame;  // offset: 0x2ac8
    f32 mExtendSpeedMax;  // offset: 0x2acc
    f32 mSpeedDeltaTime;  // offset: 0x2ad0
    cEfcHandle* mpHitSlowEfcHandle;  // offset: 0x2ad8
    f32 mHitSlowEfctWait;  // offset: 0x2ae0
    nShlBase::cShlFuwaMove mFuwaMove;  // offset: 0x2af0
    s32 mHitAdjustCount;  // offset: 0x2b80
    bool mIsThroughWater;  // offset: 0x2b84
    bool mIsEndThroughEffect;  // offset: 0x2b85
public:
    static MyDTI DTI;
};

inline void* cShlParamSpeed::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamSpeed::cShlParamSpeed() {
    this->dieDist = 0.0f;
    this->gravityAccel = 0.0f;
    this->gravityDist = 0.0f;
    this->gravity = 0.0f;
    this->gravityMax = 0.0f;
    this->spdAccel = 0.0f;
    this->spdAccelDist = 0.0f;
    this->spd = 0.0f;
    this->spdMax = 0.0f;
    this->dieFlag = 7;
    this->isTurnMoveVec = true;
    this->hitSlowRate = 1.0f;
    this->hitSlowFrame = 0.0f;
    this->hitAdjustPosRate = 0.0f;
    this->hitAdjustCount = -1;
    this->isFuwaMove = false;
    this->fuwaPeriod = 100.0f;
    this->fuwaScale = 30.0f;
    this->fuwaRandom = 0.3f;
    this->isAutoLockon = false;
    this->lockonDist = 3000.0f;
    this->lockonDeg = 30.0f;
    this->lockonOption = 0;
    this->dirAdjustDist = -1.0f;
    this->hitShlNo = -1;
    this->floorHitShlNo = -1;
    this->isEnchantShotSE = false;
    this->shlOptionSpeed = 15;
    this->epvNoScrHit = -1;
    this->scrHitEfType = static_cast<cShlParamBase::HIT_MARK_TYPE>(0);
    this->epvNoHitSlow = -1;
    this->seHitScrResType = static_cast<cShlParamBase::RESOURCE_TYPE>(3);
    this->seNoScrHit = -1;
    this->seNoHitSlow = -1;
    this->seNoHitSlowStop = -1;
    this->useGravityMin = false;
}

inline void* uShlSpeed::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void uShlSpeed::setSpeed(f32 value) {
    this->mSpeedZ = value;
}

inline void uShlSpeed::setSpeedMax(f32 value) {
    this->mSpeedMax = value;
}

inline void uShlSpeed::addExtendSpeedMax(f32 speed) {
    this->mExtendSpeedMax = this->mExtendSpeedMax + speed;
}
