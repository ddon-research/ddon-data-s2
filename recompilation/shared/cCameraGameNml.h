#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cCamInterporate.h"
#include "nCameraGame.h"
#include "uCameraGame.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cCamImpBase;
class cCamInterporateRangeAng;
class cCamInterporateVec3;
class uCameraGame;

// Declarations
class cCamExParamNml;
class cCamImpNml;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cCamInterporateF32 = cCamInterporate<float>;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cCamExParamNml : public cCamExParam
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
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    cCamExParamNml();
    virtual ~cCamExParamNml();
    virtual void copy(const cCamExParam* pParam);  // vtable slot 8
    virtual cCamImpBase* createCamImpInstance(uCameraGame* pCamera) const;  // vtable slot 6
public:
    bool mIsResetAngle;  // offset: 0x1d4
    bool mIsResetAngleDetail;  // offset: 0x1d5
    bool mIsTargetFlipX;  // offset: 0x1d6
    bool mIsTargetOwner;  // offset: 0x1d7
    bool mDisableLargeCorrect;  // offset: 0x1d8
    f32 mMoveVecRate;  // offset: 0x1dc
    f32 mMoveVecInterRate;  // offset: 0x1e0
    f32 mMoveVecCtrlStopFrame;  // offset: 0x1e4
    f32 mMoveVecRateV;  // offset: 0x1e8
    f32 mMoveVecInterRateV;  // offset: 0x1ec
    f32 mMoveVecCtrlStopFrameV;  // offset: 0x1f0
    f32 mMoveVecVOffset;  // offset: 0x1f4
    f32 mMoveVecVOffsetTwn;  // offset: 0x1f8
    f32 mMoveVecVOffsetDgn;  // offset: 0x1fc
    f32 mMoveVecVScaleUp;  // offset: 0x200
    f32 mMoveVecVScaleDown;  // offset: 0x204
    f32 mCtrlSpeedRateX;  // offset: 0x208
    f32 mTargetMarginRateH;  // offset: 0x20c
    f32 mTargetMarginRateV;  // offset: 0x210
    f32 mTargetOffsetH;  // offset: 0x214
    f32 mTargetOffsetV;  // offset: 0x218
    f32 mTargetInterRateX;  // offset: 0x21c
    f32 mTargetInterRateY;  // offset: 0x220
    f32 mRotateXOffsetUp;  // offset: 0x224
    f32 mRotateXOffsetUpY;  // offset: 0x228
    f32 mRotateXOffsetDown;  // offset: 0x22c
    f32 mRotateXOffsetDownY;  // offset: 0x230
    f32 mResetDetailAngX;  // offset: 0x234
    f32 mResetDetailAngY;  // offset: 0x238
    static MyDTI DTI;
};

class cCamImpNml : public cCamImpBase
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
    cCamImpNml();
    virtual ~cCamImpNml();
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 6
    f32 getDistance();
protected:
    virtual void initSub(MtVector3& cameraPos, MtVector3& targetPos, f32& angX, f32& angY);  // vtable slot 9
    virtual void ctrlSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY);  // vtable slot 10
    virtual void moveSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY);  // vtable slot 11
    virtual void interporateSub(MtVector3& cameraPos, MtVector3& targetPos);  // vtable slot 12
    virtual void adjustSub(MtVector3& cameraPos, MtVector3& targetPos, MtVector3& idealCam, MtVector3& idealTar);  // vtable slot 13
    virtual void finalSub();  // vtable slot 14
    virtual nCameraGame::CAMERA_TYPE getType() const;  // vtable slot 7
protected:
    const cCamExParamNml* mpParamNml;  // offset: 0xb0
    f32 mResetAngX;  // offset: 0xb8
    f32 mResetAngY;  // offset: 0xbc
    f32 mInitAngX;  // offset: 0xc0
    f32 mInitAngY;  // offset: 0xc4
    bool mIsLargeCamera;  // offset: 0xc8
    bool mIsFlipX;  // offset: 0xc9
    cCamInterporateVec3 mWallPushVecInter;  // offset: 0xd0
    cCamInterporateF32 mWallPushDistInter;  // offset: 0x110
    MtVector3 camOld;  // offset: 0x130
    cCamInterporateF32 mInterMoveVecRateH;  // offset: 0x140
    f32 mMoveVecStopFrameH;  // offset: 0x158
    cCamInterporateF32 mInterMoveVecRateV;  // offset: 0x160
    f32 mMoveVecStopFrameV;  // offset: 0x178
    cCamInterporateRangeAng mInterLockX;  // offset: 0x180
    cCamInterporateRangeAng mInterLockY;  // offset: 0x198
    cCamInterporateVec3 mPlOfsInter;  // offset: 0x1b0
public:
    static MyDTI DTI;
};
