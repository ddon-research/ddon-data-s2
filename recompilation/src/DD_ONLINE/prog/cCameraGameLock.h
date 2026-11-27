#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "cCamInterporate.h"
#include "../../generated/shared/nCameraGame.h"
#include "uCameraGame.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cCamImpBase;
class cCamInterporateRange;
class cCamInterporateRangeAng;
class uBaseModel;
class uCameraGame;

// Declarations
class cCamExParamLock;
class cCamImpLock;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cCamExParamLock : public cCamExParam
{
public:
    enum
    {
        OP_ADJUST_TARGET_HEIGHT = 1,
        OP_ANGLE_KEEP = 2,
        OP_LOCK2CAM_DIST = 4,
        OP_NO_EDIT_ADJUST = 8,
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
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    cCamExParamLock();
    virtual ~cCamExParamLock();
    virtual cCamImpBase* createCamImpInstance(uCameraGame* pCamera) const;  // vtable slot 6
    virtual void copy(const cCamExParam* pParam);  // vtable slot 8
public:
    nCameraGame::TARGET_TYPE mTargetType;  // offset: 0x1d4
    u32 mTargetGroup;  // offset: 0x1d8
    u32 mTargetId;  // offset: 0x1dc
    s32 mTargetJoint;  // offset: 0x1e0
    MtVector3 mTargetOffset;  // offset: 0x1f0
    u32 mOptionFlag;  // offset: 0x200
    f32 mOffsetH;  // offset: 0x204
    f32 mOffsetV;  // offset: 0x208
    f32 mMarginH;  // offset: 0x20c
    f32 mMarginV;  // offset: 0x210
    f32 mAngLimitX;  // offset: 0x214
    f32 mMarginChangeAngV;  // offset: 0x218
    f32 mMarginHLimit;  // offset: 0x21c
    f32 mMarginInterTime;  // offset: 0x220
    MtVector3 mLockOnPosMargin;  // offset: 0x230
    f32 mLockOnPosInterRate;  // offset: 0x240
    bool isTalkAdjust;  // offset: 0x244
    static MyDTI DTI;
};

class cCamImpLock : public cCamImpBase
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
    cCamImpLock();
    virtual ~cCamImpLock();
protected:
    virtual void initSub(MtVector3& cameraPos, MtVector3& targetPos, f32& angX, f32& angY);  // vtable slot 9
    virtual void ctrlSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY);  // vtable slot 10
    virtual void moveSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY);  // vtable slot 11
    virtual void interporateSub(MtVector3& cameraPos, MtVector3& targetPos);  // vtable slot 12
    virtual void adjustSub(MtVector3& cameraPos, MtVector3& targetPos, MtVector3& idealCam, MtVector3& idealTar);  // vtable slot 13
    virtual void finalSub();  // vtable slot 14
    virtual nCameraGame::CAMERA_TYPE getType() const;  // vtable slot 7
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 6
private:
    const uBaseModel* getLockonTarget();
    void calcTargetPos();
private:
    const cCamExParamLock* mpParamLock;  // offset: 0xb0
    bool mInitLock;  // offset: 0xb8
    f32 mIdealRotX;  // offset: 0xbc
    f32 mIdealRotY;  // offset: 0xc0
    cCamInterporateRangeAng mInterLockX;  // offset: 0xc8
    cCamInterporateRangeAng mInterLockY;  // offset: 0xe0
    f32 mRevWait;  // offset: 0xf8
    f32 mMarginWait;  // offset: 0xfc
    MtVector3 mLockOnPos;  // offset: 0x100
    MtVector3 mLockOnPosInit;  // offset: 0x110
    cCamInterporateRange mInterLockPos;  // offset: 0x120
public:
    static MyDTI DTI;
};

inline void* cCamExParamLock::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline cCamExParamLock::cCamExParamLock() : mTargetType(static_cast<nCameraGame::TARGET_TYPE>(2)), mTargetGroup(0u), mTargetId(0u), mTargetJoint(0), mTargetOffset(0.0f, 0.0f, 1000.0f), mOptionFlag(0u), mOffsetH(0.0f), mOffsetV(-0.25f), mMarginH(0.25f), mMarginV(0.04f), mAngLimitX(1.0471977f), mMarginChangeAngV(0.3f), mMarginHLimit(0.65f), mMarginInterTime(30.0f), mLockOnPosMargin(0.0f, 0.0f, 0.0f), mLockOnPosInterRate(1.0f), isTalkAdjust(false) {
    this->::cCamExParam::mType = static_cast<nCameraGame::CAMERA_TYPE>(4);
}

inline void* cCamImpLock::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

template <typename ParentClass>
class cCamExParamLockCore : public ParentClass
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
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    cCamExParamLockCore();
    virtual ~cCamExParamLockCore();
    virtual cCamImpBase* createCamImpInstance(uCameraGame* pCamera) const;  // vtable slot 6
    virtual void copy(const cCamExParam* pParam);  // vtable slot 8
public:
    nCameraGame::TARGET_TYPE mTargetType;  // offset: 0x1f8
    u32 mTargetGroup;  // offset: 0x1fc
    u32 mTargetId;  // offset: 0x200
    s32 mTargetJoint;  // offset: 0x204
    MtVector3 mTargetOffset;  // offset: 0x210
    f32 mOffsetH;  // offset: 0x220
    f32 mOffsetV;  // offset: 0x224
    f32 mMarginH;  // offset: 0x228
    f32 mMarginV;  // offset: 0x22c
    f32 mAngLimitX;  // offset: 0x230
    f32 mMarginChangeAngV;  // offset: 0x234
    f32 mMarginHLimit;  // offset: 0x238
    f32 mMarginInterTime;  // offset: 0x23c
    MtVector3 mLockOnPosMargin;  // offset: 0x240
    f32 mLockOnPosInterRate;  // offset: 0x250
    static MyDTI DTI;
};

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"

template <typename ParentClass>
inline cCamExParamLockCore<ParentClass>::cCamExParamLockCore() : mTargetType(static_cast<nCameraGame::TARGET_TYPE>(2)), mTargetGroup(0u), mTargetId(0u), mTargetJoint(0), mTargetOffset(0.0f, 0.0f, 0.0f), mOffsetH(0.0f), mOffsetV(-0.25f), mMarginH(0.25f), mMarginV(0.04f), mAngLimitX(1.0471977f), mMarginChangeAngV(0.3f), mMarginHLimit(0.65f), mMarginInterTime(30.0f), mLockOnPosMargin(0.0f, 0.0f, 0.0f), mLockOnPosInterRate(1.0f) {
}

template <typename ParentClass>
inline cCamExParamLockCore<ParentClass>::~cCamExParamLockCore() {
}

template <typename ParentClass>
void cCamExParamLockCore<ParentClass>::createProperty(MtPropertyList& s) {
    this->ParentClass::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "mTargetType", reinterpret_cast<s32*>(&this->mTargetType), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mTargetGroup", &this->mTargetGroup, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mTargetId", &this->mTargetId, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mTargetJoint", &this->mTargetJoint, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mTargetOffset", &this->mTargetOffset, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mOffsetH", &this->mOffsetH, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mOffsetV", &this->mOffsetV, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mMarginH", &this->mMarginH, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mMarginV", &this->mMarginV, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mAngLimitX", &this->mAngLimitX, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mMarginChangeAngV", &this->mMarginChangeAngV, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mMarginHLimit", &this->mMarginHLimit, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mMarginInterTime", &this->mMarginInterTime, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mLockOnPosMargin", &this->mLockOnPosMargin, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mLockOnPosInterRate", &this->mLockOnPosInterRate, 0u, 0u);
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* cCamExParamLock::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::cCamExParamLock::DTI);
}

inline void cCamImpLock::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cCamImpLock::DTI)->memFree(p_addr);
}
