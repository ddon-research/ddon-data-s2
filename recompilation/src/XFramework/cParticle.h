#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtColor.h"
#include "../MT/MtMath.h"
#include "nEffect.h"
#include "nPrim.h"
#include "rEffectAnim.h"
#include "rEffectList.h"

// Forward declarations
class MtColor;
struct MtFloat2;
struct MtFloat3;
class MtMatrix;
class MtVector3;
class cClothPolygonDrawParam;
class cClothZigzag;
class cEffectAnim;
class cParticleGenerator;
class cPrim;
class cUnit;
namespace nEffect { class SimpleCurve; }
namespace nPrim { struct Material; }
class rEffectAnim;

// Declarations
class cClothChain;
class cClothCurve;
class cClothStraight;
class cClothVertex;
class cEffectChain;
class cEffectStrip;
class cLineParticle;
class cMatrixParticle;
class cParticle;
class cParticleAnimParam;
class cParticleLifeCommon;
class cParticleLifeCurveframe;
class cParticleLifeFrame;
class cParticleMoveAdd;
class cParticleMoveBase;
class cParticleMoveCommon;
class cParticleMoveMul;
class cParticleMoveNone;
class cParticleMovePathChain;
class cParticleMovePathKeyframe;
class cParticleMovePathLine;
class cParticleMovePathStrip;
class cParticleMoveSpin;
class cPolygon;

// Type aliases from DWARF
using f32 = float;
using s32 = int;
using u32 = unsigned int;
using u8 = unsigned char;

class cClothStraight
{
public:
    MtVector3 getSubPos(const MtMatrix& Wmat) const;
public:
    MtVector3 mSubOfs;  // offset: 0x0
};

class cClothVertex
{
    friend class cParticleGenerator;
public:
    enum CLOTH_STATUS
    {
        CLOTH_STATUS_UPDATE_VERTEX = 1,
    };
public:
    static u32 getParamBuffSize(u32 ClothType, u32 VertexNum);
    void init(u8* pParamBuff, u32 ClothType, u32 VertexNum);
    void initClothChainVertex(cClothChain* pClothChain, const MtVector3& Pos0, const MtVector3& Pos1, f32 Scale, u32 DataIndex, f32 InpRate);
    void initClothChainVertexForce(cClothChain* pClothChain, const MtVector3& Pos0, const MtVector3& Pos1, f32 Scale, u32 DataIndex, f32 InpRate, const MtVector3& ForceVec);
    void updateClothStraightVertex(cClothStraight* pClothStraight, const MtVector3& Pos0, const MtVector3& Pos1, f32 Scale, u32 DataIndex, f32 InpRate);
    void updateClothChainVertex(cClothChain* pClothChain, const MtVector3& Pos0, const MtVector3& Pos1, f32 Scale, u32 DataIndex, f32 InpRate, f32 Dt);
    void updateClothChainVertexForce(cClothChain* pClothChain, const MtVector3& Pos0, const MtVector3& Pos1, f32 Scale, u32 DataIndex, f32 InpRate, f32 Dt, const MtVector3& ForceVec);
    void updateClothCurveVertex(rEffectList::EFL_PARAM_CLOTH_CURVE* pClothCurveParam, cClothCurve* pClothCurve, const MtVector3& Pos0, const MtVector3& Pos1, f32 Scale, u32 DataIndex, f32 InpRate);
    void updateClothZigzagVertex(rEffectList::EFL_PARAM_CLOTH_ZIGZAG* pClothZigzagParam, cClothZigzag* pClothZigzag, const MtVector3& Pos0, const MtVector3& Pos1, f32 Scale, u32 DataIndex, f32 InpRate);
    MtVector3* getPosArray();
    void applyWorldOffset(const MtVector3& Offset);
private:
    void initClothChainVertexCommon(cClothChain* pClothChain, const MtVector3& Pos0, const MtVector3& Pos1, f32 Scale, u32 DataIndex, f32 InpRate);
private:
    u32 mClothType : 8;  // offset: 0x0
    u32 mVertexNum : 8;  // offset: 0x0
    u32 mClothVertex0802 : 8;  // offset: 0x0
    u32 mClothVertex0803 : 8;  // offset: 0x0
    MtVector3* mPos;  // offset: 0x8
    u32 mClothVertex3208;  // offset: 0x10
    u32 mClothVertex320c;  // offset: 0x14
};

class cEffectChain
{
public:
    enum CHAIN_STATUS
    {
        CHAIN_STATUS_BLEND = 1,
        CHAIN_STATUS_CALC_LENGTH = 2,
        CHAIN_STATUS_KEYFRAME_LENGTH = 4,
        CHAIN_STATUS_KEYFRAME_ROT = 8,
        CHAIN_STATUS_KEYFRAME_BLEND_ROT = 16,
        CHAIN_STATUS_KEYFRAME_BLEND_RATE = 32,
        CHAIN_STATUS_CONSTRAIN_ORD = 64,
        CHAIN_STATUS_CONSTRAIN_REV = 128,
        CHAIN_STATUS_RESET = 256,
        CHAIN_STATUS_STRETCH_LENGTH = 512,
    };
    enum CHAIN_MODE
    {
        CHAIN_MODE_PARTICLE = 0,
        CHAIN_MODE_PATH = 1,
        CHAIN_MODE_CLOTH_POLYGON = 2,
    };
public:
    void initChain(rEffectList::EFL_PARAM_CHAIN* pChainParam, u32 DataIndex, f32 Length, const MtVector3& Vec, const MtVector3& ForceVec);
    void initBlendChain(rEffectList::EFL_PARAM_CHAIN* pChainParam, u32 DataIndex, f32 Length, const MtVector3& Vec0, const MtVector3& Vec1, const MtVector3& ForceVec);
    void calcChain(MtVector3* pOfs, MtVector3* pSpd, const MtVector3& AccelerationVec, f32 Length);
    void calcChainForce(MtVector3* pOfs, MtVector3* pSpd, const MtVector3& AccelerationVec, f32 Length, const MtVector3& ForceVec);
    void calcBlendChain(MtVector3* pOfs, MtVector3* pSpd, const MtVector3& AccelerationVec0, const MtVector3& AccelerationVec1, f32 Length);
    void calcBlendChainForce(MtVector3* pOfs, MtVector3* pSpd, const MtVector3& AccelerationVec0, const MtVector3& AccelerationVec1, f32 Length, const MtVector3& ForceVec);
    MtVector3 blendChainVector(const MtVector3& Vec0, const MtVector3& Vec1, u32 No, u32 Max);
    MtVector3* getChainSpd() const;
    MtVector3* getChainOfs(u32 DataIndex) const;
    void applyWorldOffset(const MtVector3& Offset);
public:
    f32 mLength;  // offset: 0x0
    f32 mLengthAdd;  // offset: 0x4
    f32 mTotalLength;  // offset: 0x8
    f32 mAcceleration;  // offset: 0xc
    f32 mFrameInf;  // offset: 0x10
    f32 mVertexInf;  // offset: 0x14
    f32 mBlendRate;  // offset: 0x18
    u32 mStatus : 12;  // offset: 0x1c
    u32 mMode : 4;  // offset: 0x1c
    u32 mOfsNum : 8;  // offset: 0x1c
    u32 mHoldOfsNum : 8;  // offset: 0x1c
    u32 mLengthKeyframeTimer : 16;  // offset: 0x20
    u32 mRotKeyframeTimer : 16;  // offset: 0x20
    u32 mBlendRotKeyframeTimer : 16;  // offset: 0x24
    u32 mBlendRateKeyframeTimer : 16;  // offset: 0x24
    f32 mForceRate;  // offset: 0x28
    f32 mForceVertexAttenuateCoef;  // offset: 0x2c
    MtFloat3 mRotKeyframeRate;  // offset: 0x30
    MtFloat3 mBlendRotKeyframeRate;  // offset: 0x3c
    f32 mBlendRateKeyframeRate;  // offset: 0x48
    f32 mOriginalLength;  // offset: 0x4c
    MtVector3 mWorldDir;  // offset: 0x50
    MtVector3 mLocalDir;  // offset: 0x60
    MtVector3 mLocalBlendDir;  // offset: 0x70
    MtVector3 mWorldPos;  // offset: 0x80
};

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

class cParticleAnimParam
{
public:
    u32 mAnimFlag;  // offset: 0x0
    u32 mSeqNo;  // offset: 0x4
    f32 mPatNoRate;  // offset: 0x8
    f32 mPatSpeed;  // offset: 0xc
    f32 mKeyframeRate;  // offset: 0x10
};

class cParticleLifeCommon
{
public:
    void curveLifeRate();
public:
    f32 mLifeRate;  // offset: 0x0
};

class cParticleLifeCurveframe : public cParticleLifeCommon
{
public:
    void reductionLifeFrame(u32 Shift);
public:
    u32 mLifeTimer : 16;  // offset: 0x4
    u32 mLifeRno : 8;  // offset: 0x4
    u32 mLifeCurveframe0807 : 8;  // offset: 0x4
    u32 mLifeCurveframe1608 : 16;  // offset: 0x8
    u32 mVanishFrame : 16;  // offset: 0x8
    u32 mCurveFrame : 16;  // offset: 0xc
    u32 mCurveTimer : 16;  // offset: 0xc
    nEffect::SimpleCurve mLifeRateCurve;  // offset: 0x10
};

class cParticleLifeFrame : public cParticleLifeCommon
{
public:
    void reductionLifeFrame(u32 Shift);
public:
    u32 mAppearFrame : 16;  // offset: 0x4
    u32 mKeepFrame : 16;  // offset: 0x4
    u32 mVanishFrame : 16;  // offset: 0x8
    u32 mLifeTimer : 16;  // offset: 0x8
    u32 mKeepHoldTimer : 16;  // offset: 0xc
    u32 mLifeRno : 8;  // offset: 0xc
    u32 mKeepHoldFlag : 1;  // offset: 0xc
    u32 mLifeFrame070f : 7;  // offset: 0xc
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

class cClothChain : public cClothStraight
{
public:
    MtVector3 interpolateDir(u32 No, u32 DataIndex, f32 InpRate) const;
    f32 interpolateLength(u32 DataIndex, f32 InpRate) const;
public:
    MtVector3 mDir[2][2];  // offset: 0x10
    f32 mLength[2];  // offset: 0x50
    f32 mLengthAdd;  // offset: 0x58
    u32 mConstOffTimer : 16;  // offset: 0x5c
    u32 mClothChain165e : 16;  // offset: 0x5c
    u32 mStatus : 16;  // offset: 0x60
    u32 mPreUpdateLoopNum : 16;  // offset: 0x60
    f32 mAcceleration;  // offset: 0x64
    f32 mFrameInf;  // offset: 0x68
    f32 mVertexInf;  // offset: 0x6c
    MtVector3 mLocalDir[2];  // offset: 0x70
    MtFloat3 mRotKeyframeRate[2];  // offset: 0x90
    f32 mDistConvRate;  // offset: 0xa8
    f32 mForceRate;  // offset: 0xac
    f32 mForceVertexAttenuateCoef;  // offset: 0xb0
    u32 mClothChain32b4;  // offset: 0xb4
    u32 mClothChain32b8;  // offset: 0xb8
    u32 mClothChain32bc;  // offset: 0xbc
};

class cClothCurve : public cClothStraight
{
public:
    MtVector3 interpolateDir(u32 DataIndex, f32 InpRate) const;
public:
    MtVector3 mDir[2];  // offset: 0x10
    MtVector3 mRot;  // offset: 0x30
    MtVector3 mRotAdd;  // offset: 0x40
    f32 mCurveCoef;  // offset: 0x50
    u32 mCurveType : 8;  // offset: 0x54
    u32 mClothCurve084d : 8;  // offset: 0x54
    u32 mCurveStatus : 16;  // offset: 0x54
    u32 mClothCurve3258;  // offset: 0x58
    u32 mClothCurve325c;  // offset: 0x5c
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

class cParticleMovePathChain : public cParticleMoveBase
{
public:
    MtVector3 mOfs;  // offset: 0x50
    MtVector3 mRot;  // offset: 0x60
};

class cParticleMovePathKeyframe : public cParticleMoveBase
{
public:
    cEffectStrip mStrip;  // offset: 0x50
    MtVector3 mRot;  // offset: 0x70
    MtFloat3 mOfsKeyframeRate;  // offset: 0x80
    u32 mMovePathKeyframe327c;  // offset: 0x8c
};

class cParticleMovePathLine : public cParticleMoveBase
{
public:
    cEffectStrip mStrip;  // offset: 0x50
    MtVector3 mRot;  // offset: 0x70
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

class cPolygon : public cMatrixParticle
{
public:
    struct CLOTH_POLYGON_PARAM;
    struct ADHESION_PARAM;
public:
    using CLOTH_POLYGON_PARAM = cPolygon::CLOTH_POLYGON_PARAM;
    using ADHESION_PARAM = cPolygon::ADHESION_PARAM;
public:
    struct CLOTH_POLYGON_PARAM
    {
    public:
        u32 ChainNum : 8;  // offset: 0x0
        u32 VertexNum : 8;  // offset: 0x0
        u32 Offset : 16;  // offset: 0x0
    };
public:
    struct ADHESION_PARAM
    {
    public:
        u32 InfoNum : 16;  // offset: 0x0
        u32 UpdateFlag : 8;  // offset: 0x0
        u32 Param0803 : 8;  // offset: 0x0
    };
public:
    bool initAnim(rEffectAnim* pAnim, const cParticleAnimParam& Param);
    void initTexScrollWorkOffset(u32 Offset);
    void initSrcColor(const MtColor& Color);
    void initSrcColorKeyframeRate(u32 Rate);
    void initColor(const MtColor& Color);
    void initWidth(f32 Width, f32 WidthAdd);
    void initHeight(f32 Height, f32 HeightAdd);
    cEffectAnim* getAnim();
    f32 getPatNoKeyframeRate() const;
    u32 getTexScrollWorkOffset() const;
    bool isTexScroll() const;
    const MtColor& getSrcColor() const;
    const MtColor& getCurColor() const;
    MtColor* getCurColorPtr();
    u32 getSrcColorKeyframeRate() const;
    f32 getCurWidth() const;
    f32 getWidthAdd() const;
    f32 getHeightAdd() const;
    f32 getNextWidth() const;
    f32 getNextHeight() const;
    f32 getTangentCoef() const;
    u32 getBinormalFlag() const;
    u32 getTangentFlag() const;
    void setSrcColor(const MtColor& Color);
    void setCurColor(const MtColor& Color);
    void setCurWidth(f32 Width);
    void setCurHeight(f32 Height);
    void updatePatNoRate();
    void updateCurColor();
    rEffectAnim::SEQ_PAT* getSeqPat(rEffectAnim* pAnim, f32 InpRate) const;
    MtFloat2 interpolateTexScrollOffset(f32 InpRate) const;
    MtColor interpolateColor(s32 IntInpRate) const;
    f32 interpolateWidth(f32 InpRate) const;
    f32 interpolateHeight(f32 InpRate) const;
    void initAdhesion();
    void setAdhesionSizeUpdate();
    void setAlwaysAdhesionUpdate();
    void clearAdhesionUpdate();
    void setAdhesionInfoNum(u32 Num);
    bool isAdhesionUpdate() const;
    u32 getAdhesionInfoNum() const;
    void initClothPolygon(rEffectList::EFL_PARTICLE_CLOTH_POLYGON* pClothPolygonParam);
    u32 getClothPolygonChainNum() const;
    u32 getClothPolygonVertexNum() const;
    u32 getClothPolygonOffset() const;
    void drawClothPolygon(cPrim* pPrim, MtVector3* pPosBuff, rEffectAnim::SEQ_PAT* pSeqPat, const cClothPolygonDrawParam& DrawParam);
protected:
    cEffectAnim mAnim;  // offset: 0xd0
    f32 mWidth[2];  // offset: 0xe0
    f32 mHeight[2];  // offset: 0xe8
    MtColor mColor[2];  // offset: 0xf0
    f32 mPatNoRate[2];  // offset: 0xf8
    f32 mTangentCoef;  // offset: 0x100
    u32 mBinormalFlag : 8;  // offset: 0x104
    u32 mTangentFlag : 8;  // offset: 0x104
    u32 mTexScrollWorkOffset : 16;  // offset: 0x104
    union
    {
    public:
        cPolygon::CLOTH_POLYGON_PARAM mClothPolygonParam;  // offset: 0x0
        cPolygon::ADHESION_PARAM mAdhesionParam;  // offset: 0x0
    };  // offset: 0x108
    u32 mSrcColorKeyframeRate : 16;  // offset: 0x10c
    u32 mPolygon16ee : 16;  // offset: 0x10c
    MtColor mSrcColor;  // offset: 0x110
    f32 mWidthAdd;  // offset: 0x114
    f32 mHeightAdd;  // offset: 0x118
    f32 mPatNoKeyframeRate;  // offset: 0x11c
};

class cParticleMoveAdd : public cParticleMoveBase
{
public:
    MtVector3 mSpeedVec;  // offset: 0x50
    MtVector3 mAccelerationVec;  // offset: 0x60
};
