#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive3D.h"
#include "nDraw.h"
#include "rEffectList.h"
#include "sGpuParticle.h"

// Forward declarations
class MtAABB;
class MtAllocator;
class MtColor;
class MtDTI;
struct MtFloat3;
class MtMatrix;
class MtQuaternion;
class MtVector3;
class cDraw;
class cEffectJointAngle;
class cEffectJointKeyframe;
class cParticle;
class cParticleLifeCommon;
class cParticleLifeCurveframe;
class cParticleLifeFrame;
class cParticleLifeKeyframe;
class cPrim;
namespace nEffect { struct KEYFRAME_INDEX; }
class rSoundRequest;
class uEffect;
class uEffectExt;

// Declarations
class cEffectJoint;
class cEffectPath;
class cParticleManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cEffectJoint
{
    // inferred: uEffect::setupUnitGenerator names cEffectJoint::mUpdateConstWorldOfs.x
    friend class uEffect;
public:
    enum JNT_STATUS
    {
        JNT_STATUS_MOVE = 1,
        JNT_STATUS_CONST = 2,
        JNT_STATUS_KEYFRAME_SCALE = 16,
        JNT_STATUS_KEYFRAME_OFS = 32,
        JNT_STATUS_KEYFRAME_ANGLE = 64,
        JNT_STATUS_KEYFRAME = 240,
        JNT_STATUS_KEYFRAME_CONST = 112,
    };
    enum JNT_RNO_TBL
    {
        JNT_RNO_INIT = 0,
        JNT_RNO_WAIT = 1,
        JNT_RNO_MOVE = 2,
    };
public:
    void constructParam(uEffect* pOwner);
    void constructParam(uEffect* pOwner, u32 JointIndex, u32 JointNo);
    bool allocMemory();
    void freeMemory();
    u32 getAllocBuffSize() const;
    void initParam();
    void resetParam();
    void restart();
    void move();
    void updateLocalMatrix(MtMatrix& Lmat, MtVector3& Ofs);
    void updateLocalMatrixExtended(MtMatrix& Lmat, MtVector3& Ofs, f32 InpRate);
    void updateLocalSubMatrix(MtMatrix& Lmat, MtVector3& Ofs);
    void updateTimer();
    void updateDataIndex();
    void initRandCtr();
    u32 getStatus() const;
    bool isEnable() const;
    void setDisable();
    rEffectList::EFL_JOINT* getJointParam() const;
    u32 getJointNo() const;
    u32 getJointIndex() const;
    bool isConstUpdate() const;
    void setConstUpdateFlag(u32 Flag);
    bool isConst() const;
    const MtMatrix& getWorldMatrix() const;
    const MtMatrix& getSubWorldMatrix() const;
    void setWorldMatrix(const MtMatrix& Mat);
    void setSubWorldMatrix(const MtMatrix& Mat);
    MtVector3 getWorldPos() const;
    MtVector3 getSubWorldPos() const;
    const MtFloat3& getOfs() const;
    const MtFloat3& getSubOfs() const;
    void setSubOfs(MtFloat3& set);
    const MtQuaternion& getQuat() const;
    const MtQuaternion& getSubQuat() const;
    s32 getParentNo() const;
    s32 getSubParentNo() const;
    u32 getRelationType() const;
    u32 getSubRelationType() const;
    u32 getRelationScaleType() const;
    u32 getSubRelationScaleType() const;
    const MtVector3& getPrevWorldPos() const;
    void setPrevWorldPos(const MtVector3& Pos);
    const MtVector3& getUpdateConstWorldOfs() const;
    void setUpdateConstWorldOfs(const MtVector3& Ofs);
    const MtVector3& getScale() const;
    void setScale(const MtVector3& Scale);
    const MtFloat3& getScaleBase() const;
    f32 getLargestScale() const;
    u32 getOrder() const;
    u32 getSubWmatFlag() const;
    void setSubWmatFlag(bool);
    u32 getOfsScaleFlag() const;
    u32 getWaitFrame() const;
    u32 getTimer() const;
    bool isMatrixExtended() const;
    bool isBillboard() const;
    bool isBillboardLookAt() const;
    bool isParentSymmetry() const;
    bool isParentSymmetryScale() const;
    bool isSymmetryEnable() const;
    void setSymmetryEnable(bool Flag);
    MtMatrix calcScaleMatrix();
    void applyWorldOffset(const MtVector3& Offset);
private:
    u32 getRand();
    f32 getRandF();
    MtVector3 calcJointKeyframeVector(nEffect::KEYFRAME_INDEX* pIndex, const MtFloat3& Rate);
    u32 getKeyframeTimer(nEffect::KEYFRAME_INDEX* pIndex) const;
    u32 correctKeyframeTimer(nEffect::KEYFRAME_INDEX* pIndex) const;
private:
    MtMatrix mWmat;  // offset: 0x0
    MtMatrix mSubWmat;  // offset: 0x40
    MtFloat3 mOfs;  // offset: 0x80
    s32 mParentNo;  // offset: 0x8c
    MtQuaternion mQuat;  // offset: 0x90
    MtFloat3 mSubOfs;  // offset: 0xa0
    s32 mSubParentNo;  // offset: 0xac
    MtQuaternion mSubQuat;  // offset: 0xb0
    MtVector3 mPrevWorldPos;  // offset: 0xc0
    MtVector3 mUpdateConstWorldOfs;  // offset: 0xd0
    MtVector3 mScale;  // offset: 0xe0
    MtFloat3 mScaleBase;  // offset: 0xf0
    f32 mLargestScale;  // offset: 0xfc
    uEffect* mpOwner;  // offset: 0x100
    rEffectList::EFL_JOINT* mpJointParam;  // offset: 0x108
    u32 mJointIndex : 16;  // offset: 0x110
    u32 mJointNo : 16;  // offset: 0x110
    u32 mStatus : 8;  // offset: 0x114
    u32 mOrder : 4;  // offset: 0x114
    u32 mSubOrder : 4;  // offset: 0x114
    u32 mRelationType : 4;  // offset: 0x114
    u32 mRelationScaleType : 4;  // offset: 0x114
    u32 mSubRelationType : 4;  // offset: 0x114
    u32 mSubRelationScaleType : 4;  // offset: 0x114
    u32 mRno : 4;  // offset: 0x118
    u32 mCurDataIndex : 1;  // offset: 0x118
    u32 mOldDataIndex : 1;  // offset: 0x118
    u32 mSubWmatFlag : 1;  // offset: 0x118
    u32 mConstUpdateFlag : 1;  // offset: 0x118
    u32 mParentSymmetry : 1;  // offset: 0x118
    u32 mParentSymmetryScale : 1;  // offset: 0x118
    u32 mSymmetryEnable : 1;  // offset: 0x118
    u32 mOfsScaleFlag : 1;  // offset: 0x118
    u32 mBillboardEnable : 1;  // offset: 0x118
    u32 mBillboardLookAt : 1;  // offset: 0x118
    u32 mJoint02111 : 2;  // offset: 0x118
    u32 mStartRandCtr : 16;  // offset: 0x118
    u32 mRandCtr;  // offset: 0x11c
    u32 mTimer;  // offset: 0x120
    u32 mWaitFrame : 16;  // offset: 0x124
    u32 mWaitTimer : 16;  // offset: 0x124
    u32 mAllocBuffSize;  // offset: 0x128
    u8* mpExtendedBuff;  // offset: 0x130
    cEffectJointKeyframe* mpKeyframe;  // offset: 0x138
    cEffectJointAngle* mpAngle;  // offset: 0x140
};

class cEffectPath
{
public:
    MtVector3 mScale;  // offset: 0x0
    MtFloat3 m3DScale;  // offset: 0x10
    f32 mLengthScale;  // offset: 0x1c
};

class cParticleManager : public MtObject
{
    // inferred: uEffect::doFinish names cParticleManager::mpNext
    friend class uEffect;
    // inferred: uEffectExt::correctModelEnvMapPower names cParticleManager::mManagerNo
    friend class uEffectExt;
public:
    enum DRAW_TYPE
    {
        DRAW_TYPE_BILLBOARD = 0,
        DRAW_TYPE_POLYLINE = 1,
        DRAW_TYPE_POLYGON = 2,
        DRAW_TYPE_TEXLINE = 3,
        DRAW_TYPE_LINE = 4,
        DRAW_TYPE_MODEL = 5,
        DRAW_TYPE_PRIM_MODEL = 6,
        DRAW_TYPE_LENS_FLARE = 7,
        DRAW_TYPE_POLYGON_STRIP = 8,
        DRAW_TYPE_BILLBOARD_STRIP = 9,
        DRAW_TYPE_SIZE_BILLBOARD = 10,
        DRAW_TYPE_AXIS_POLYGON = 11,
        DRAW_TYPE_REPEAT_POLYLINE = 12,
        DRAW_TYPE_TRAIL = 13,
        DRAW_TYPE_LIGHT_SHAFT = 14,
        DRAW_TYPE_CLOTH_POLYLINE = 15,
        DRAW_TYPE_CLOTH_TEXLINE = 16,
        DRAW_TYPE_CLOTH_LINE = 17,
        DRAW_TYPE_CLOTH_POLYGON = 18,
        DRAW_TYPE_CLOTH_REPEAT_POLYLINE = 19,
        DRAW_TYPE_MASS_BILLBOARD = 20,
        DRAW_TYPE_POINT = 21,
        DRAW_TYPE_GPU_LINE = 22,
        DRAW_TYPE_GPU_BILLBOARD = 23,
        DRAW_TYPE_GPU_POLYLINE = 24,
        DRAW_TYPE_CULLING_BILLBOARD = 25,
        DRAW_TYPE_CULLING_POLYLINE = 26,
        DRAW_TYPE_CULLING_POLYGON = 27,
        DRAW_TYPE_CULLING_TEXLINE = 28,
        DRAW_TYPE_CULLING_LINE = 29,
        DRAW_TYPE_CULLING_MODEL = 30,
        DRAW_TYPE_CULLING_PRIM_MODEL = 31,
        DRAW_TYPE_CULLING_POLYGON_STRIP = 32,
        DRAW_TYPE_CULLING_BILLBOARD_STRIP = 33,
        DRAW_TYPE_CULLING_SIZE_BILLBOARD = 34,
        DRAW_TYPE_CULLING_AXIS_POLYGON = 35,
        DRAW_TYPE_CULLING_REPEAT_POLYLINE = 36,
        DRAW_TYPE_CULLING_TRAIL = 37,
        DRAW_TYPE_CULLING_LIGHT_SHAFT = 38,
        DRAW_TYPE_CULLING_CLOTH_POLYLINE = 39,
        DRAW_TYPE_CULLING_CLOTH_TEXLINE = 40,
        DRAW_TYPE_CULLING_CLOTH_LINE = 41,
        DRAW_TYPE_CULLING_CLOTH_POLYGON = 42,
        DRAW_TYPE_CULLING_CLOTH_REPEAT_POLYLINE = 43,
        DRAW_TYPE_CULLING_MASS_BILLBOARD = 44,
        DRAW_TYPE_CULLING_POINT = 45,
        DRAW_TYPE_CULLING_GPU_LINE = 46,
        DRAW_TYPE_CULLING_GPU_BILLBOARD = 47,
        DRAW_TYPE_CULLING_GPU_POLYLINE = 48,
        DRAW_TYPE_CUSTOM = 49,
        DRAW_TYPE_ADHESION = 50,
        DRAW_TYPE_NO_VOLUME_BLEND = 51,
        DRAW_TYPE_FILTER = 52,
        DRAW_TYPE_LIGHT = 53,
        DRAW_TYPE_HIT = 54,
        DRAW_TYPE_NONE = 55,
    };
    enum MAN_RNO_TBL
    {
        MAN_RNO_INIT = 0,
        MAN_RNO_WAIT = 1,
        MAN_RNO_READY = 2,
        MAN_RNO_SET = 3,
        MAN_RNO_INTERVAL = 4,
        MAN_RNO_FINISH = 5,
        MAN_RNO_REVIVAL = 6,
        MAN_RNO_KILL = 7,
    };
    enum MAN_STATUS
    {
        MAN_STATUS_MOVE = 1,
        MAN_STATUS_DRAW = 2,
        MAN_STATUS_PARTICLE_MOVE = 4,
        MAN_STATUS_REQUEST_VIB = 16,
        MAN_STATUS_REQUEST_VIB_STOP = 32,
        MAN_STATUS_REQUEST_SE = 64,
        MAN_STATUS_KEYFRAME_RESERVED01 = 256,
        MAN_STATUS_KEYFRAME_SET_NUM = 512,
        MAN_STATUS_KEYFRAME_RANGE = 1024,
        MAN_STATUS_KEYFRAME_RESERVED8 = 2048,
        MAN_STATUS_KEYFRAME_RESERVE10 = 4096,
        MAN_STATUS_KEYFRAME_SHADE_LIGHT_OFS = 8192,
        MAN_STATUS_KEYFRAME_SHADE_LIGHT_COLOR = 16384,
        MAN_STATUS_KEYFRAME_SHADE_LIGHT_RANGE = 32768,
        MAN_STATUS_KEYFRAME = 65280,
        MAN_STATUS_SETUP = 65536,
        MAN_STATUS_SETUP_WORLD_MATRIX = 131072,
        MAN_STATUS_VANISH = 536870912,
        MAN_STATUS_CHILD_KEEP_HOLD_OFF = 1073741824,
        MAN_STATUS_FINISH = -2147483648,
        MAN_STATUS_ACTIVE = 7,
        MAN_STATUS_REQUEST = 112,
        MAN_STATUS_CLEAR_AFTER = 1610612736,
        MAN_STATUS_KEYFRAME_SHADE_LIGHT = 57344,
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
    cParticleManager();
    virtual ~cParticleManager();
    virtual bool constructParam(uEffect* pOwner, u32 ListNo, u32 ManagerNo);  // vtable slot 6
    virtual bool setParticleBuff(u8* pBuff);  // vtable slot 7
    virtual void initParam();  // vtable slot 8
    virtual void resetParam();  // vtable slot 9
    virtual void restart();  // vtable slot 10
    virtual void finish(bool Mode);  // vtable slot 11
    virtual void setup();  // vtable slot 12
    virtual u32 getParticleNum() const;  // vtable slot 13
    virtual u32 getParticleMoveNum() const;  // vtable slot 14
    virtual bool allocMemory();  // vtable slot 15
    u32 getAllocBuffSize() const;
    virtual void updateWorldMatrix() = 0;  // vtable slot 16
    virtual void applyWorldOffset(const MtVector3&) = 0;  // vtable slot 17
    virtual bool move() = 0;  // vtable slot 18
    virtual void updateConst() = 0;  // vtable slot 19
    virtual void update() = 0;  // vtable slot 20
    virtual void draw(cDraw*, s32, u8*) = 0;  // vtable slot 21
    virtual bool isDraw(cDraw* pDraw) const;  // vtable slot 22
    rSoundRequest* getSoundRequest() const;
    u32 getSeReqNo() const;
    u32 getSeOptionFlag() const;
    cParticleManager* getNext() const;
    void setNext(cParticleManager* pNext);
    u32 getManagerNo() const;
    u32 getListNo() const;
    cEffectJoint* getJoint() const;
    u32 getJointNo() const;
    void setJointNo(u32 JointNo);
    u32 getJointIndex() const;
    void setJoint(cEffectJoint* pJoint);
    u32 getParticleBuffSize() const;
    void initRandCtr();
    u32 getStatus() const;
    u32 getRno() const;
    bool isMove() const;
    bool isVanish() const;
    bool isFirstSetup() const;
    bool isFirstSetupWorldMatrix() const;
    rEffectList::ResourceInfo* getResourceInfo() const;
    rEffectList::EFL_GENERATOR* getGeneratorParam() const;
    rEffectList::EFL_PARTICLE_COMMON* getParticleParam() const;
    rEffectList::EFL_LIFE_FRAME* getLifeParam() const;
    rEffectList::EFL_MOVE_COMMON* getMoveParam() const;
    f32 getTextureInvW() const;
    f32 getTextureInvH() const;
    u32 getGeneratorType() const;
    u32 getParticleType() const;
    u32 getLifeType() const;
    u32 getMoveType() const;
    const MtMatrix& getWorldMatrix() const;
    const MtMatrix& getSubWorldMatrix() const;
    void setSubWorldMatrix(MtMatrix&);
    void setSubWorldMatrixFlag(bool);
    MtVector3 getWorldPos() const;
    MtVector3 getSubWorldPos() const;
    const MtVector3& getPrevWorldPos() const;
    const MtVector3& getUpdateConstWorldOfs() const;
    MtMatrix calcScaleMatrix();
    const MtVector3& getScale() const;
    f32 getLargestScale() const;
    bool isConstUpdate() const;
    u32 getDrawMode() const;
    nDraw::PASS_TYPE getDrawPass() const;
    u32 getDrawType() const;
    u32 getColorCorrectType() const;
    u32 getStartRandCtr() const;
    u32 getTimer() const;
    void doKeepHoldOff();
    bool isKeepHold() const;
    bool isFinish() const;
protected:
    void setRequest();
    void stopRequest();
    u32 getParticleLifeSize() const;
    void initParticleLifeFrame(cParticle* pParticle, cParticleLifeFrame* pParticleLife);
    void initParticleLifeKeyframe(cParticle* pParticle, cParticleLifeKeyframe* pParticleLife);
    void initParticleLifeHideframe(cParticle* pParticle, cParticleLifeFrame* pParticleLife);
    void initParticleLifeCurveframe(cParticle* pParticle, cParticleLifeCurveframe* pParticleLife);
    bool moveParticleLifeFrame(cParticle* pParticle, cParticleLifeFrame* pParticleLife);
    bool moveParticleLifeKeyframe(cParticle* pParticle, cParticleLifeKeyframe* pParticleLife);
    bool moveParticleLifeHideframe(cParticle* pParticle, cParticleLifeFrame* pParticleLife);
    bool moveParticleLifeCurveframe(cParticle* pParticle, cParticleLifeCurveframe* pParticleLife);
    u32 getRemainderLifeFrame(cParticleLifeCommon* pParticleLifeCommon) const;
    u32 updateBoundaryControl();
    void updateLevelCorrection();
    bool isCulling(cDraw* pDraw) const;
    s32 setPrimEnv(cDraw* pDraw, cPrim* pPrim);
    s32 setPrimEnv(cDraw* pDraw);
    bool setCullingParam(rEffectList::EFL_PARAM_CULLING* pDesParam, rEffectList::EFL_PARAM_CULLING* pOrgParam);
    u32 getRand();
    u32 getParticleRand();
    f32 getRandF();
    f32 getParticleRandF();
    u32 getRandFix8();
    u32 getParticleRandFix8();
    bool isSynchroVanish() const;
    bool isRevival() const;
    u32 getKeyframeTimer(nEffect::KEYFRAME_INDEX* pIndex) const;
    u32 getKeyframeTimer(nEffect::KEYFRAME_INDEX* pIndex, cParticle* pParticle) const;
    u32 correctKeyframeTimer(nEffect::KEYFRAME_INDEX* pIndex) const;
    u32 correctKeyframeTimer(nEffect::KEYFRAME_INDEX* pIndex, cParticle* pParticle) const;
    MtVector3 calcGeneratorKeyframeVector(nEffect::KEYFRAME_INDEX* pIndex, const MtFloat3& Rate);
    MtColor calcGeneratorKeyframeColor(nEffect::KEYFRAME_INDEX* pIndex, u32 Rate);
    f32 calcGeneratorKeyframeF32(nEffect::KEYFRAME_INDEX* pIndex, f32 Rate);
private:
    bool isBoundaryCulling(u32 ViewportNo) const;
    bool isBoundaryPause() const;
    void resetRandCtr();
public:
    bool isLimitedRestart() const;
    void releaseLimitedRestart();
protected:
    uEffect* mpOwner;  // offset: 0x8
    cParticleManager* mpNext;  // offset: 0x10
    u32 mStatus;  // offset: 0x18
    u32 mManagerNo : 16;  // offset: 0x1c
    u32 mListNo : 16;  // offset: 0x1c
    cEffectJoint* mpJoint;  // offset: 0x20
    u32 mJointNo : 16;  // offset: 0x28
    u32 mJointIndex : 16;  // offset: 0x28
    u32 mParticleBuffSize;  // offset: 0x2c
    u8* mpParticleBuff;  // offset: 0x30
    rEffectList::ResourceInfo* mpResourceInfo;  // offset: 0x38
    sGpuParticle::Context* mpContext;  // offset: 0x40
    rEffectList::EFL_GENERATOR* mpGeneratorParam;  // offset: 0x48
    rEffectList::EFL_PARTICLE_COMMON* mpParticleParam;  // offset: 0x50
    rEffectList::EFL_LIFE_FRAME* mpLifeParam;  // offset: 0x58
    rEffectList::EFL_MOVE_COMMON* mpMoveParam;  // offset: 0x60
    u32 mParticleType : 8;  // offset: 0x68
    u32 mGeneratorType : 4;  // offset: 0x68
    u32 mLifeType : 4;  // offset: 0x68
    u32 mMoveType : 4;  // offset: 0x68
    u32 mWorkMoveType : 4;  // offset: 0x68
    u32 mColorCorrectType : 4;  // offset: 0x68
    u32 mKeepHoldFlag : 1;  // offset: 0x68
    u32 mConstUpdateFlag : 1;  // offset: 0x68
    u32 mLifeRateCurveFlag : 1;  // offset: 0x68
    u32 mOtDepthBiasFlag : 1;  // offset: 0x68
    u32 mDrawMode : 8;  // offset: 0x6c
    u32 mDrawPass : 8;  // offset: 0x6c
    u32 mDrawType : 8;  // offset: 0x6c
    u32 mRno : 8;  // offset: 0x6c
    u32 mRandCtr;  // offset: 0x70
    u32 mParticleRandCtr;  // offset: 0x74
    u32 mStartRandCtr : 16;  // offset: 0x78
    u32 mPrimRotOptionFlag : 8;  // offset: 0x78
    u32 mBoundaryFlag : 4;  // offset: 0x78
    u32 mParticleVolume : 4;  // offset: 0x78
    u32 mManager324c;  // offset: 0x7c
    MtAABB mBoundingBox;  // offset: 0x80
    f32 mBoundingRadius;  // offset: 0xa0
    f32 mBoundingDistanceSQ;  // offset: 0xa4
    u32 mTimer;  // offset: 0xa8
    u32 mGeneratorOptionFlag;  // offset: 0xac
    u32 mParticleOptionFlag;  // offset: 0xb0
    u32 mAllocBuffSize;  // offset: 0xb4
    f32 mTimeInterpolationRate;  // offset: 0xb8
    s32 mIntTimeInterpolationRate;  // offset: 0xbc
    u32 mLightGroupFlag;  // offset: 0xc0
    s32 mVibrationId;  // offset: 0xc4
    u32 mSeReqNo : 16;  // offset: 0xc8
    u32 mSeOptionFlag : 16;  // offset: 0xc8
    u32 mManager329c;  // offset: 0xcc
public:
    static MyDTI DTI;
};
