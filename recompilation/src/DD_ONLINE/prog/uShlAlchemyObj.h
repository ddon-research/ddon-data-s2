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
class MtQuaternion;
class MtVector3;
class cEfcHandle;
class cHitInfo;
namespace nShlBase { class cShlFuwaMove; }
class uDDOModel;

// Declarations
class cShlParamAlchemyObj;
class uShlAlchemyObj;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cShlParamAlchemyObj : public cShlParamBase
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
    virtual MtDTI& getShlDTI() const;  // vtable slot 6
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void createPropertyEffect(MtPropertyList& s);  // vtable slot 8
    virtual void createPropertySE(MtPropertyList& s);  // vtable slot 9
    cShlParamAlchemyObj();
    virtual ~cShlParamAlchemyObj();
    virtual void copy(const cShlParamBase* pParamBase);  // vtable slot 11
public:
    bool mDamageActive;  // offset: 0x160
    u32 mHp;  // offset: 0x164
    s32 mPushCollisionNo;  // offset: 0x168
    u32 mPushGroup;  // offset: 0x16c
    s32 mActiveEffect;  // offset: 0x170
    s32 mActiveSe;  // offset: 0x174
    bool isFuwaMove;  // offset: 0x178
    f32 fuwaPeriod;  // offset: 0x17c
    f32 fuwaScale;  // offset: 0x180
    f32 fuwaRandom;  // offset: 0x184
    bool mIsWaitForKill;  // offset: 0x188
    f32 mWaitForKillFrame;  // offset: 0x18c
    f32 mKillDistance;  // offset: 0x190
    bool mFlgUseAreaEffect;  // offset: 0x194
    u32 mAreaEffectTime;  // offset: 0x198
    s32 mDamageCameraShake;  // offset: 0x19c
    s32 mDamageCameraShake2;  // offset: 0x1a0
    f32 mLimitHeight;  // offset: 0x1a4
    f32 mLimitHeightSpeed;  // offset: 0x1a8
    static MyDTI DTI;
};

class uShlAlchemyObj : public uShlBase
{
public:
    enum ANGLE_ROTATE_RNO
    {
        ARR_STOP = 0,
        ARR_MOVE = 1,
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
    const cShlParamAlchemyObj* getShlParam() const;
    uShlAlchemyObj();
    virtual ~uShlAlchemyObj();
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    virtual void updateSub();  // vtable slot 175
    void updateAngle();
    bool rotThetaB2A(f32 tar_ang, f32& now_ang, f32 turn_ang);
    virtual void callbackDamage(cHitInfo* pInfo);  // vtable slot 88
    void requestAngle(const MtQuaternion& quat);
    void progKillRequest();
    void requestActiveEffect();
    void requestActiveSe(uDDOModel* pTarget);
    virtual void updateEfcHandle();  // vtable slot 58
protected:
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
private:
    void procRequest();
    void requestActiveEffectCore();
    void requestActiveSeCore();
    void checkDistance();
    void updateLandHoming();
protected:
    void setAddCollision(s32 index);
protected:
    s32 mHp;  // offset: 0x2ab0
    f32 mFinalAngY;  // offset: 0x2ab4
    u32 mAngleRotateRno;  // offset: 0x2ab8
    nShlBase::cShlFuwaMove mFuwaMove;  // offset: 0x2ac0
    f32 mKillWaitFrame;  // offset: 0x2b50
    cEfcHandle* mpEfcAreaHandle;  // offset: 0x2b58
    bool mCameraShakeOnce;  // offset: 0x2b60
    bool mFlgRequestActiveEffect;  // offset: 0x2b61
    bool mFlgRequestActiveSe;  // offset: 0x2b62
    uDDOModel* mpRequestActiveSeTarget;  // offset: 0x2b68
    f32 mLandHomingPosY;  // offset: 0x2b70
    u32 mLandHomingRno;  // offset: 0x2b74
public:
    static MyDTI DTI;
};

inline void* cShlParamAlchemyObj::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cShlParamAlchemyObj::cShlParamAlchemyObj() {
    this->mHp = 1;
    this->mPushCollisionNo = -1;
    this->mPushGroup = 0;
    this->mActiveEffect = -1;
    this->mActiveSe = -1;
    this->mDamageActive = false;
    this->isFuwaMove = false;
    this->fuwaPeriod = 100.0f;
    this->fuwaScale = 30.0f;
    this->fuwaRandom = 0.3f;
    this->mIsWaitForKill = false;
    this->mWaitForKillFrame = 10.0f;
    this->mKillDistance = 5000.0f;
    this->mFlgUseAreaEffect = false;
    this->mAreaEffectTime = 0;
    this->mDamageCameraShake = -1;
    this->mDamageCameraShake2 = -1;
    this->mLimitHeight = -1.0f;
    this->mLimitHeightSpeed = 50.0f;
}

inline void* uShlAlchemyObj::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void* cShlParamAlchemyObj::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cShlParamAlchemyObj::DTI)->memAlloc(sz, align, ::cShlParamAlchemyObj::DTI.::MtDTI::getID());
}

inline void uShlAlchemyObj::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uShlAlchemyObj::DTI)->memFree(p_addr);
}

inline const cShlParamAlchemyObj* uShlAlchemyObj::getShlParam() const {
    return static_cast<const cShlParamAlchemyObj*>(this->::uShlBase::mpShlParam2);
}
