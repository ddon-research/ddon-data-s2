#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtMath.h"
#include "nPrim.h"

// Forward declarations
class MtColor;
struct MtFloat3;
class MtVector3;
class cParticleGenerator;
class cUnit;
namespace nPrim { struct Material; }

// Declarations
class cEffectStrip;
class cLineParticle;
class cMatrixParticle;
class cParticle;
class cParticleMoveAdd;
class cParticleMoveBase;
class cParticleMoveCommon;
class cParticleMoveMul;
class cParticleMoveNone;
class cParticleMovePathKeyframe;
class cParticleMovePathStrip;
class cParticleMoveSpin;

// Type aliases from DWARF
using f32 = float;
using s32 = int;
using u32 = unsigned int;

class cEffectStrip
{
public:
    void init(const MtVector3& Ofs);
public:
    MtVector3 mOfs;  // offset: 0x0
    u32 mPartsNo : 16;  // offset: 0x10
    u32 mRno : 8;  // offset: 0x10
    u32 mCalcDirFlag : 1;  // offset: 0x10
    u32 mCalcWorldDirFlag : 1;  // offset: 0x10
    u32 mSkiningFlag : 1;  // offset: 0x10
    u32 mPathLoopFlag : 1;  // offset: 0x10
    u32 mStripReserved0413 : 4;  // offset: 0x10
    u32 mVertexNo : 16;  // offset: 0x14
    u32 mVertexNum : 16;  // offset: 0x14
    f32 mBlendRate0;  // offset: 0x18
    f32 mBlendRate1;  // offset: 0x1c
};

class cParticle
{
    // inferred: cParticleGenerator::closeParticle names cParticle::mpNext
    friend class cParticleGenerator;
public:
    enum PTCL_STATUS
    {
        PTCL_STATUS_UNIQUE0 = 1,
        PTCL_STATUS_UNIQUE1 = 2,
        PTCL_STATUS_UNIQUE2 = 4,
        PTCL_STATUS_UNIQUE3 = 8,
        PTCL_STATUS_UNIQUE4 = 16,
        PTCL_STATUS_UNIQUE5 = 32,
        PTCL_STATUS_UNIQUE6 = 64,
        PTCL_STATUS_UNIQUE7 = 128,
        PTCL_STATUS_CALC_SCALE = 256,
        PTCL_STATUS_CALC_LENGTH = 512,
        PTCL_STATUS_CALC_ROT = 1024,
        PTCL_STATUS_CALC_TEX_SCRL_U = 2048,
        PTCL_STATUS_CALC_TEX_SCRL_V = 4096,
        PTCL_STATUS_RESET_CLOTH = 8192,
        PTCL_STATUS_SYMMETRY = 16384,
        PTCL_STATUS_CURVE_MODEL_SCALE_ADD = 32768,
        PTCL_STATUS_KEYFRAME_INTENSITY = 65536,
        PTCL_STATUS_KEYFRAME_COLOR = 131072,
        PTCL_STATUS_KEYFRAME_PLACE_COLOR = 262144,
        PTCL_STATUS_KEYFRAME_PAT_NO = 524288,
        PTCL_STATUS_KEYFRAME_SCALE = 1048576,
        PTCL_STATUS_KEYFRAME_ROT = 2097152,
        PTCL_STATUS_KEYFRAME_LENGTH = 4194304,
        PTCL_STATUS_KEYFRAME_MODEL_SCALE = 8388608,
        PTCL_STATUS_KEYFRAME_UNIQUE0 = 16777216,
        PTCL_STATUS_KEYFRAME_UNIQUE1 = 33554432,
        PTCL_STATUS_KEYFRAME_UNIQUE2 = 67108864,
        PTCL_STATUS_KEYFRAME_UNIQUE3 = 134217728,
        PTCL_STATUS_KEYFRAME_LIFE_RATE = 268435456,
        PTCL_STATUS_KEYFRAME_TEX_SCRL_U = 536870912,
        PTCL_STATUS_KEYFRAME_TEX_SCRL_V = 1073741824,
        PTCL_STATUS_KEYFRAME_FORBID = -2147483648,
        PTCL_STATUS_UPDATE_SCALE = 1048832,
        PTCL_STATUS_UPDATE_ROT = 2098176,
        PTCL_STATUS_UPDATE_TEX_SCRL_U = 536872960,
        PTCL_STATUS_UPDATE_TEX_SCRL_V = 1073745920,
        PTCL_STATUS_CALC_ANGLE = 1,
        PTCL_STATUS_CALC_WIDTH = 2,
        PTCL_STATUS_CALC_HEIGHT = 4,
        PTCL_STATUS_CALC_A_RATIO = 8,
        PTCL_STATUS_KEYFRAME_ANGLE = 16777216,
        PTCL_STATUS_KEYFRAME_WIDTH = 33554432,
        PTCL_STATUS_KEYFRAME_HEIGHT = 67108864,
        PTCL_STATUS_CALC_HEAD_SIZE = 1,
        PTCL_STATUS_CALC_PLACE_SIZE = 2,
        PTCL_STATUS_OVERFLOW_SIZE = 4,
        PTCL_STATUS_KEYFRAME_HEAD_SIZE = 16777216,
        PTCL_STATUS_KEYFRAME_PLACE_SIZE = 33554432,
        PTCL_STATUS_UPDATE_PARTS_NO = 1,
        PTCL_STATUS_UPDATE_MATERIAL = 2,
        PTCL_STATUS_INIT_PARTS_NO = 4,
        PTCL_STATUS_CALC_PARTS_NO = 8,
        PTCL_STATUS_CONSTANT_MODEL_UV = 16,
        PTCL_STATUS_KEYFRAME_PARTS_NO = 16777216,
        PTCL_STATUS_KEYFRAME_PARTS_SPEED = 33554432,
        PTCL_STATUS_KEYFRAME_UPPER_RADIUS = 16777216,
        PTCL_STATUS_KEYFRAME_LOWER_RADIUS = 33554432,
        PTCL_STATUS_KEYFRAME_UPPER_HEIGHT = 67108864,
        PTCL_STATUS_KEYFRAME_LOWER_HEIGHT = 134217728,
        PTCL_STATUS_CALC_FILTER_COLOR = 1,
        PTCL_STATUS_CALC_FILTER_INTENSITY = 2,
        PTCL_STATUS_CALC_ATT_DIST = 1,
        PTCL_STATUS_CALC_ATT_DIST_SPOT = 2,
        PTCL_STATUS_CALC_RADIUS = 1,
        PTCL_STATUS_FOLLOW_CANCEL = 1,
    };
    enum PTCL_FLAG
    {
        PTCL_FLAG_KILL = 1,
        PTCL_FLAG_KEEP_HOLD_OFF = 2,
        PTCL_FLAG_STOP_ANIM = 4,
        PTCL_FLAG_STOP_ROT = 8,
        PTCL_FLAG_HIT = 16,
        PTCL_FLAG_BOUNCE = 32,
        PTCL_FLAG_UPDATE_LIFE = 64,
        PTCL_FLAG_CALC_DIR = 128,
        PTCL_FLAG_CALC_WORLD_DIR = 256,
        PTCL_FLAG_MOVE_ROT_LOCAL = 512,
        PTCL_FLAG_PATH_END = 1024,
        PTCL_FLAG_CONST_UPDATE = 2048,
        PTCL_FLAG_UPDATE_SIZE = 4096,
        PTCL_FLAG_ATTENUATE_ROT = 8192,
        PTCL_FLAG_DEPEND_DIR = 16384,
        PTCL_FLAG_RESERVED = 32768,
    };
    enum PTCL_RNO_LINE_FIX_END
    {
        PTCL_RNO_LINE_FIX_END_NONE = 0,
        PTCL_RNO_LINE_FIX_END_CHECK = 1,
        PTCL_RNO_LINE_FIX_END_RELEASE = 2,
    };
    enum PTCL_COLL_STATUS
    {
        PTCL_COLL_STATUS_CALC_RADIUS = 1,
    };
    enum PTCL_MOVE_RNO_TBL
    {
        PTCL_MOVE_RNO_STOP = 0,
        PTCL_MOVE_RNO_COLL = 1,
        PTCL_MOVE_RNO_MOVE = 2,
        PTCL_MOVE_RNO_KILL = 3,
    };
    enum PTCL_MOVE_STATUS
    {
        PTCL_MOVE_STATUS_CALC_PATH = 1,
        PTCL_MOVE_STATUS_CALC_ROT = 2,
        PTCL_MOVE_STATUS_KEYFRAME_ROT = 16,
        PTCL_MOVE_STATUS_KEYFRAME_FIXROT = 32,
        PTCL_MOVE_STATUS_KEYFRAME_SPEED = 64,
        PTCL_MOVE_STATUS_KEYFRAME_FALL_SPEED = 128,
        PTCL_MOVE_STATUS_CORRECT_INIT = 256,
        PTCL_MOVE_STATUS_CORRECT = 512,
        PTCL_MOVE_STATUS_CORRECT_RELEASE = 1024,
        PTCL_MOVE_STATUS_CALC_PATH_REACH = 2048,
        PTCL_MOVE_STATUS_CALC_PATH_REACH_REVERSE = 4096,
        PTCL_MOVE_STATUS_HIT_CANCEL = 192,
        PTCL_MOVE_STATUS_CALC_PATH_REACH_CONTROL = 6144,
    };
    enum PTCL_LIFE_RNO_TBL
    {
        PTCL_LIFE_RNO_HIDE = 0,
        PTCL_LIFE_RNO_APPEAR = 1,
        PTCL_LIFE_RNO_KEEP = 2,
        PTCL_LIFE_RNO_VANISH = 3,
        PTCL_LIFE_RNO_FINISH = 4,
    };
public:
    void constructParam(cParticle* pPrev, cParticle* pNext, u32 No);
    void start(u32 SetNo, u32 Status);
    void setVolumeBlendRate(u32 Rate);
    cParticle* getPrev() const;
    cParticle* getNext() const;
    cParticle* getNext(u32 SkipMask) const;
    cParticle* skip(u32 SkipMask);
    void setPrev(cParticle* pPrev);
    void setNext(cParticle* pNext);
    void setAnimEnableFlag(bool Flag);
    bool isEnable() const;
    void update(u32 Flag);
    const void* calcOffset(u32 Offset) const;
    u32 getOldDataIndex() const;
    u32 getCurDataIndex() const;
    u32 getVolumeBlendRate() const;
    u32 getParticleNo() const;
    u32 getSetNo() const;
    u32 isAnimEnable() const;
    u32 getTimer() const;
    u32 getFlag() const;
    void setFlag(u32 Flag);
    void addFlag(u32 Flag);
    bool isKill() const;
    u32 getStatus() const;
    void enableStatus(u32 Status);
    void disableStatus(u32 Status);
    void initMaterial(u32 BlendState, u32 AnimFlag, u32 PrimAttribute);
    void initIntensity(f32 Intensity);
    void initIntIntensity(u32 Intensity);
    void initIntensityKeyframeRate(f32 Rate);
    f32 getIntensityKeyframeRate() const;
    void setIntensity(f32 Intensity);
    void updateIntensity();
    u32 getCurIntIntensity() const;
    u32* getCurIntIntensityPtr();
    void setCurIntIntensity(u32);
    void initScale(f32 Scale, f32 ScaleAdd);
    const nPrim::Material& getMaterial() const;
    void setOldPos(const MtVector3& Pos);
    void setCurPos(const MtVector3& Pos);
    void initPos(const MtVector3& Pos);
    void applyWorldOffset(const MtVector3& Offset);
    const MtVector3& getOldPos() const;
    const MtVector3& getCurPos() const;
    f32 getOldScale() const;
    f32 getCurScale() const;
    f32 getScaleAdd() const;
    void setCurScale(f32 Scale);
    void setScaleAdd(f32 ScaleAdd);
    MtVector3 interpolatePos(f32 InpRate) const;
    f32 interpolateScale(f32 InpRate) const;
    u32 interpolateIntensity(s32 IntInpRate) const;
    void prefetch1();
    void prefetch2();
    void prefetch3();
    void prefetch4();
    cParticle* prefetchNext1(u32 SkipMask);
    cParticle* prefetchNext2(u32 SkipMask);
    cParticle* prefetchNext3(u32 SkipMask);
    cParticle* prefetchNext4(u32 SkipMask);
    bool updateSynchroEnable();
    cUnit* getSynchroUnit() const;
    void setSynchroUnit(cUnit* pUnit);
    void kill();
protected:
    cParticle* mpPrev;  // offset: 0x0
    cParticle* mpNext;  // offset: 0x8
    u32 mParticleNo : 16;  // offset: 0x10
    u32 mSetNo : 16;  // offset: 0x10
    u32 mFlag : 16;  // offset: 0x14
    u32 mVolumeBlendRate : 8;  // offset: 0x14
    u32 mCurDataIndex : 1;  // offset: 0x14
    u32 mOldDataIndex : 1;  // offset: 0x14
    u32 mEnableFlag : 1;  // offset: 0x14
    u32 mAnimEnableFlag : 1;  // offset: 0x14
    u32 mGeneralFlag0 : 1;  // offset: 0x14
    u32 mGeneralFlag1 : 1;  // offset: 0x14
    u32 mGeneralFlag2 : 1;  // offset: 0x14
    u32 mGeneralFlag3 : 1;  // offset: 0x14
    u32 mStatus;  // offset: 0x18
    u32 mTimer;  // offset: 0x1c
    nPrim::Material mMaterial;  // offset: 0x20
    MtVector3 mPos[2];  // offset: 0x30
    f32 mScale[2];  // offset: 0x50
    f32 mScaleAdd;  // offset: 0x58
    cUnit* mpSynchroUnit;  // offset: 0x60
    u32 mIntensity[2];  // offset: 0x68
    f32 mSrcIntensity;  // offset: 0x70
    f32 mSrcIntensityKeyframeRate;  // offset: 0x74
};

class cParticleMoveCommon
{
public:
    bool isStop() const;
    bool isKill() const;
    void updateCurDir(const MtVector3& Dir);
public:
    MtVector3 mCurDir;  // offset: 0x0
    u32 mMoveRno : 2;  // offset: 0x10
    u32 mGravityScaleFlag : 1;  // offset: 0x10
    u32 mMoveCommon0100 : 1;  // offset: 0x10
    u32 mCollStatus : 4;  // offset: 0x10
    u32 mBounceCtr : 8;  // offset: 0x10
    u32 mCollCancelTimer : 8;  // offset: 0x10
    u32 mForceType : 8;  // offset: 0x10
    f32 mForceRate;  // offset: 0x14
    f32 mCollRadius;  // offset: 0x18
    f32 mBounceRate;  // offset: 0x1c
};

class cParticleMoveNone : public cParticleMoveCommon
{
public:
    cEffectStrip mStrip;  // offset: 0x20
};

class cLineParticle : public cParticle
{
public:
    void initSrcHeadColor(const MtColor& Color);
    void initSrcHeadColorKeyframeRate(u32 Rate);
    void initHeadColor(const MtColor& Color);
    void initSrcPlaceColor(const MtColor& Color);
    void initSrcPlaceColorKeyframeRate(u32 Rate);
    void initPlaceColor(const MtColor& Color);
    u32 getLineType() const;
    u32 getLineOfsNum() const;
    u32 getColorPlaceNo() const;
    u32 getColorPlaceType() const;
    bool isColorPlace() const;
    u32 getClothType() const;
    const MtColor& getSrcHeadColor() const;
    const MtColor& getCurHeadColor() const;
    u32 getSrcHeadColorKeyframeRate() const;
    const MtColor& getSrcPlaceColor() const;
    const MtColor& getCurPlaceColor() const;
    u32 getSrcPlaceColorKeyframeRate() const;
    MtColor* getCurColorPtr();
    void setSrcHeadColor(const MtColor& Color);
    void setCurHeadColor(const MtColor& Color);
    void setSrcPlaceColor(const MtColor& Color);
    void setCurPlaceColor(const MtColor& Color);
    void updateCurHeadColor();
    void updateCurPlaceColor();
    MtColor interpolateHeadColor(s32 IntInpRate) const;
    MtColor interpolatePlaceColor(s32 IntInpRate) const;
protected:
    MtColor mColor[2][2];  // offset: 0x78
    MtColor mSrcHeadColor;  // offset: 0x88
    MtColor mSrcPlaceColor;  // offset: 0x8c
    u32 mSrcHeadColorKeyframeRate : 16;  // offset: 0x90
    u32 mSrcPlaceColorKeyframeRate : 16;  // offset: 0x90
    u32 mLineType : 8;  // offset: 0x94
    u32 mLineOfsNum : 8;  // offset: 0x94
    u32 mColorPlaceNo : 8;  // offset: 0x94
    u32 mColorPlaceType : 4;  // offset: 0x94
    u32 mClothType : 4;  // offset: 0x94
};

class cMatrixParticle : public cParticle
{
public:
    void initRot(const MtVector3& Rot, const MtVector3& RotAdd);
    void initDir(const MtVector3& Dir);
    const MtVector3& getCurRot() const;
    const MtVector3& getOldRot() const;
    const MtVector3& getRotAdd() const;
    const MtVector3& getCurDir() const;
    const MtVector3& getOldDir() const;
    void setCurRot(const MtVector3& Rot);
    void setRotAdd(const MtVector3&);
    void setCurDir(const MtVector3& Dir);
    void setOldDir(const MtVector3& Dir);
    void updateRot();
    void updateRotAdd(f32 Coef);
    MtVector3 interpolateRot(f32 InpRate) const;
    MtVector3 interpolateDir(f32 InpRate) const;
protected:
    MtVector3 mRot[2];  // offset: 0x80
    MtVector3 mDir[2];  // offset: 0xa0
    MtVector3 mRotAdd;  // offset: 0xc0
};

class cParticleMoveBase : public cParticleMoveCommon
{
public:
    f32 mSpeed;  // offset: 0x20
    f32 mAcceleration;  // offset: 0x24
    f32 mGravity;  // offset: 0x28
    f32 mFallSpeed;  // offset: 0x2c
    union
    {
    public:
        f32 mRotKeyframeRate[3];  // offset: 0x0
        u32 mRotKeyframeRandom[3];  // offset: 0x0
    };  // offset: 0x30
    f32 mSpeedKeyframeRate;  // offset: 0x3c
    f32 mFallSpeedKeyframeRate;  // offset: 0x40
    u32 mMoveStatus : 16;  // offset: 0x44
    u32 mReleaseTimer : 16;  // offset: 0x44
    f32 mDistance[2];  // offset: 0x48
};

class cParticleMoveMul : public cParticleMoveBase
{
public:
    MtVector3 mSpeedVec;  // offset: 0x50
};

class cParticleMovePathKeyframe : public cParticleMoveBase
{
public:
    cEffectStrip mStrip;  // offset: 0x50
    MtVector3 mRot;  // offset: 0x70
    MtFloat3 mOfsKeyframeRate;  // offset: 0x80
    u32 mMovePathKeyframe327c;  // offset: 0x8c
};

class cParticleMovePathStrip : public cParticleMoveBase
{
public:
    cEffectStrip mStrip;  // offset: 0x50
    MtVector3 mRot;  // offset: 0x70
    f32 mDistanceRate[2];  // offset: 0x80
    u32 mReachFrame : 16;  // offset: 0x88
    u32 mReachTimer : 16;  // offset: 0x88
    u32 mMovePathStrip327c;  // offset: 0x8c
};

class cParticleMoveSpin : public cParticleMoveMul
{
public:
    MtVector3 getCirclePos(const MtVector3& Scale, u32 RotOrder) const;
    MtVector3 getCirclePos(const MtVector3& Scale, u32 RotOrder, u32 RotAxisType) const;
public:
    MtVector3 mCircleCenterPos;  // offset: 0x60
    MtVector3 mCircleRot;  // offset: 0x70
    MtVector3 mCircleRotAdd;  // offset: 0x80
    f32 mCircleRadius;  // offset: 0x90
    f32 mCircleRadiusAdd;  // offset: 0x94
    f32 mCircleAngle;  // offset: 0x98
    f32 mCircleAngleAdd;  // offset: 0x9c
};

class cParticleMoveAdd : public cParticleMoveBase
{
public:
    MtVector3 mSpeedVec;  // offset: 0x50
    MtVector3 mAccelerationVec;  // offset: 0x60
};
