#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtMath.h"
#include "nPrim.h"
#include "rEffect2D.h"
#include "rEffectAnim.h"

// Forward declarations
class MtColor;
struct MtFloat2;
class MtMatrix;
class MtPoint;
class MtSize;
class MtVector3;
class MtVector4;
class cAnimParticle2D;
class cDraw;
class cEffectValueU32;
class cLine2D;
class cModel2D;
class cPolyline2D;
class cPrim;
class cTexline2D;
namespace nEffect { struct KEYFRAME_INDEX; }
namespace nPrim { struct Material; }
namespace nPrim { struct Rect; }
namespace nPrim { struct Vertex; }
class uEffect2D;

// Declarations
class cParticle2D;
class cParticle2DGenerator;

// Type aliases from DWARF
using f32 = float;
using s32 = int;
using u32 = unsigned int;
using u8 = unsigned char;

class cParticle2D
{
public:
    enum PTCL_FLAG
    {
        PTCL_FLAG_KILL = 1,
        PTCL_FLAG_KEEP_HOLD_OFF = 2,
        PTCL_FLAG_UPDATE_LIFE = 4,
        PTCL_FLAG_CALC_DIR = 8,
    };
    enum PTCL_LIFE_RNO_TBL
    {
        PTCL_LIFE_RNO_HIDE = 0,
        PTCL_LIFE_RNO_APPEAR = 1,
        PTCL_LIFE_RNO_KEEP = 2,
        PTCL_LIFE_RNO_VANISH = 3,
        PTCL_LIFE_RNO_FINISH = 4,
    };
    enum PTCL_STATUS
    {
        PTCL_STATUS_UNIQUE0 = 1,
        PTCL_STATUS_UNIQUE1 = 2,
        PTCL_STATUS_UNIQUE2 = 4,
        PTCL_STATUS_UNIQUE3 = 8,
        PTCL_STATUS_CALC_SCALE = 16,
        PTCL_STATUS_CALC_SCALE_XY = 32,
        PTCL_STATUS_CALC_ANGLE = 64,
        PTCL_STATUS_CALC_LENGTH = 128,
        PTCL_STATUS_CALC_TEX_SCRL_U = 256,
        PTCL_STATUS_CALC_TEX_SCRL_V = 512,
        PTCL_STATUS_CALC_UNIQUE0 = 1024,
        PTCL_STATUS_CALC_UNIQUE1 = 2048,
        PTCL_STATUS_CALC_ALL = 4080,
        PTCL_STATUS_KEYFRAME_INTENSITY = 4096,
        PTCL_STATUS_KEYFRAME_COLOR = 8192,
        PTCL_STATUS_KEYFRAME_PLACE_COLOR = 16384,
        PTCL_STATUS_KEYFRAME_PAT_NO = 32768,
        PTCL_STATUS_KEYFRAME_SCALE = 65536,
        PTCL_STATUS_KEYFRAME_SCALE_XY = 131072,
        PTCL_STATUS_KEYFRAME_ANGLE = 262144,
        PTCL_STATUS_KEYFRAME_LENGTH = 524288,
        PTCL_STATUS_KEYFRAME_LIFE_RATE = 1048576,
        PTCL_STATUS_KEYFRAME_MOVE_ROT = 2097152,
        PTCL_STATUS_KEYFRAME_MOVE_SPEED = 4194304,
        PTCL_STATUS_KEYFRAME_MOVE_GRV_SPEED = 8388608,
        PTCL_STATUS_KEYFRAME_TEX_SCRL_U = 16777216,
        PTCL_STATUS_KEYFRAME_TEX_SCRL_V = 33554432,
        PTCL_STATUS_KEYFRAME_UNIQUE0 = 67108864,
        PTCL_STATUS_KEYFRAME_UNIQUE1 = 134217728,
        PTCL_STATUS_KEYFRAME_ALL = 268431360,
        PTCL_STATUS_RESERVED0 = 268435456,
        PTCL_STATUS_RESERVED1 = 536870912,
        PTCL_STATUS_RESERVED2 = 1073741824,
        PTCL_STATUS_RESERVED3 = -2147483648,
        PTCL_STATUS_CALC_HEAD_SIZE = 1024,
        PTCL_STATUS_CALC_PLACE_SIZE = 2048,
        PTCL_STATUS_KEYFRAME_HEAD_SIZE = 67108864,
        PTCL_STATUS_KEYFRAME_PLACE_SIZE = 134217728,
        PTCL_STATUS_MODEL_ANIM_INIT = 1,
        PTCL_STATUS_MODEL_ANIM_MOVE = 2,
        PTCL_STATUS_CALC_ROT = 1024,
        PTCL_STATUS_KEYFRAME_MODEL_SCALE = 67108864,
        PTCL_STATUS_KEYFRAME_ROT = 134217728,
    };
public:
    void constructParam(cParticle2D* pPrev, cParticle2D* pNext, u32 No);
    void start(u32 SetNo);
    cParticle2D* getPrev() const;
    cParticle2D* getNext() const;
    void setPrev(cParticle2D* pPrev);
    void setNext(cParticle2D* pNext);
    bool isEnable() const;
    void update(u32 Flag);
    void* calcOffset(u32 Offset);
    u32 getOldDataIndex() const;
    u32 getCurDataIndex() const;
    u32 getParticleNo() const;
    u32 getSetNo() const;
    u32 getTimer() const;
    u32 getFlag() const;
    void setFlag(u32 Flag);
    void addFlag(u32 Flag);
    bool isKill() const;
    u32 getStatus() const;
    void enableStatus(u32 Status);
    void disableStatus(u32 Status);
    f32 getLifeRate();
    void setLifeRate(f32 LifeRate);
    u32 getLineType() const;
    u32 getLineOfsNum() const;
    void initMaterial(u32 No, u32 BlendState, u32 AnimFlag, u32 PrimAttribute);
    void initIntensity(u32 Intensity);
    void initIntIntensity(u32 Intensity);
    void initIntensityKeyframeRate(f32 Rate);
    void initPos(const MtFloat2& Pos);
    const nPrim::Material& getMaterial(u32 No) const;
    u32 getCurIntensity();
    u32* getCurIntIntensityPtr();
    f32 getIntensityKeyframeRate() const;
    f32 getBaseScale() const;
    f32 getBaseScaleAdd() const;
    const MtFloat2& getOldPos() const;
    const MtFloat2& getCurPos() const;
    void setBaseIntensity(u32 Intensity);
    void setBaseScale(f32 Scale);
    void setBaseScaleAdd(f32 ScaleAdd);
    void setOldPos(const MtFloat2&);
    void setCurPos(const MtFloat2& Pos);
    void updateIntensity();
    bool updateBaseScale(f32 BaseScaleAddCoef);
    u32 interpolateIntensity(s32 IntInpRate);
    void prefetch1();
    void prefetch2();
    void prefetch3();
    void prefetch4();
    void kill();
protected:
    cParticle2D* mpPrev;  // offset: 0x0
    cParticle2D* mpNext;  // offset: 0x8
    u32 mParticleNo : 16;  // offset: 0x10
    u32 mSetNo : 16;  // offset: 0x10
    u32 mFlag : 16;  // offset: 0x14
    u32 mEnableFlag : 1;  // offset: 0x14
    u32 mCurDataIndex : 1;  // offset: 0x14
    u32 mOldDataIndex : 1;  // offset: 0x14
    u32 mParticle050e : 5;  // offset: 0x14
    u32 mParticle080f : 8;  // offset: 0x14
    u32 mStatus;  // offset: 0x18
    u32 mTimer;  // offset: 0x1c
    nPrim::Material mMaterial[3];  // offset: 0x20
    MtFloat2 mPos[2];  // offset: 0x38
    f32 mBaseScale;  // offset: 0x48
    f32 mBaseScaleAdd;  // offset: 0x4c
    f32 mLifeRate;  // offset: 0x50
    u32 mLineType : 8;  // offset: 0x54
    u32 mLineOfsNum : 8;  // offset: 0x54
    u32 mParticle084e : 8;  // offset: 0x54
    u32 mParticle084f : 8;  // offset: 0x54
    u32 mIntensity[2];  // offset: 0x58
    u32 mBaseIntensity;  // offset: 0x60
    f32 mIntensityKeyframeRate;  // offset: 0x64
};

class cParticle2DGenerator
{
public:
    enum GEN_STATUS
    {
        GEN_STATUS_MOVE = 1,
        GEN_STATUS_DRAW = 2,
        GEN_STATUS_PARTICLE_MOVE = 4,
        GEN_STATUS_KEYFRAME_SET_NUM = 16,
        GEN_STATUS_KEYFRAME_RANGE = 32,
        GEN_STATUS_FINISH = 32768,
        GEN_STATUS_ACTIVE = 7,
        GEN_STATUS_KEYFRAME = 48,
    };
    enum GEN_RNO_TBL
    {
        GEN_RNO_INIT = 0,
        GEN_RNO_WAIT = 1,
        GEN_RNO_READY = 2,
        GEN_RNO_SET = 3,
        GEN_RNO_INTERVAL = 4,
        GEN_RNO_FINISH = 5,
    };
public:
    class ParticleParam;
public:
    class ParticleParam
    {
    public:
        ParticleParam();
    public:
        MtFloat2 mOfs;  // offset: 0x0
        MtFloat2 mDir;  // offset: 0x8
    };
public:
    void constructParam(uEffect2D* pOwner, u32 ParticleNum, u32 ParticleTotalSize, u8* pParticleBuffTop);
    bool setResourceParam(u32 ListNo, u32 GeneratorNo);
    void initParam();
    void resetParam();
    void restart();
    void finish();
    void updatePosition();
    bool move();
    void draw(cDraw* pDraw, cPrim* pPrim, s32 Transparency, u32 DrawTargetNo, u8* pDrawBuff);
    u32 getStatus() const;
    u32 getColorCorrectType() const;
    rEffect2D::ResourceInfo* getResourceInfo() const;
    rEffect2D::E2D_GENERATOR* getGeneratorParam() const;
    rEffect2D::E2D_PARTICLE_COMMON* getParticleParam() const;
    rEffect2D::E2D_LIFE_FRAME* getLifeParam() const;
    rEffect2D::E2D_MOVE_COMMON* getMoveParam() const;
    u32 getGeneratorType() const;
    u32 getParticleType() const;
    u32 getLifeType() const;
    u32 getMoveType() const;
    u32 getGeneratorNo() const;
    u32 getListNo() const;
    u32 getStartRandCtr() const;
    void setRandCtr(u32 RandCtr);
    cParticle2D* openParticle(u32 SetNo);
    cParticle2D* closeParticle(cParticle2D* pParticle);
    void closeParticleAll();
    cParticle2D* getMoveTopParticle();
    cParticle2D* getParticle(u32 No);
    u32 getParticleNum() const;
    u32 getParticleMoveNum() const;
    u32 getTimer() const;
    const MtFloat2& getScreenPos() const;
    const MtColor& getColor(u32) const;
    const MtColor& getPlaceColor(u32) const;
    void setColor(const MtColor&, u32);
    void setPlaceColor(const MtColor&, u32);
    void setAllColor(const MtColor&);
    const MtColor& getOrgColor(u32) const;
    const MtColor& getOrgPlaceColor(u32) const;
    u32 getColorFlag() const;
    bool isColorEnable() const;
    bool isPlaceColorEnable() const;
    bool isColorBlend() const;
    void applyWorldOffset(const MtVector3& Offset);
    void setKeepHoldFlag(u32 Flag);
    bool isFinish() const;
    bool isDraw() const;
private:
    u32 getRand();
    f32 getRandF();
    u32 getRandFix8();
    void initColor(u32 ColorPlaceType, MtColor* pOrgPlaceColor);
    void updateDataIndex();
    u32 updateGenerator();
    void updateLevelCorrection();
    bool initParticle(cParticle2D* pParticle);
    void initParticlePos(cParticle2D* pParticle, ParticleParam& Param);
    void initParticleLifeFrame(cParticle2D* pParticle);
    void initParticleLifeKeyframe(cParticle2D* pParticle);
    void initParticleLifeHideframe(cParticle2D* pParticle);
    void initParticleLifeCurveframe(cParticle2D* pParticle);
    void initParticleMoveNone(cParticle2D* pParticle, const ParticleParam& Param);
    void initParticleMoveAdd(cParticle2D* pParticle, const ParticleParam& Param);
    void initParticleMoveMul(cParticle2D* pParticle, const ParticleParam& Param);
    void initParticleMoveCustom(cParticle2D* pParticle, const ParticleParam& Param);
    void initParticleSprite(cParticle2D* pParticle);
    void initParticlePolyline(cParticle2D* pParticle);
    void initParticleTexline(cParticle2D* pParticle);
    void initParticleLine(cParticle2D* pParticle);
    void initParticleModel(cParticle2D* pParticle);
    void initPrimMaterial(cParticle2D* pParticle, u32 AnimFlag);
    u32 initAnim(cAnimParticle2D* pAnimParticle, u32 AnimFlag);
    void initIntensity(cParticle2D* pParticle);
    void initBaseScale(cParticle2D* pParticle);
    MtColor calcBaseColor();
    MtColor calcBasePlaceColor();
    MtColor calcLifeColor(MtColor Color, f32 LifeRate);
    void initParticleLineOfs(cParticle2D* pParticle, void* pParam);
    void initParticleLineFollowOfs(cParticle2D* pParticle);
    void initParticleLineFixOfs(cParticle2D* pParticle, rEffect2D::E2D_PARAM_LINE_FIX* pLineFixParam);
    void initParticleLineLengthOfs(cParticle2D* pParticle, rEffect2D::E2D_PARAM_LINE_LENGTH* pLineLengthParam);
    void calcParticleLineFixOfs(cParticle2D* pParticle, rEffect2D::E2D_PARAM_LINE_FIX* pLineFixParam, bool UpdateOldFlag);
    void calcParticleLineLengthOfs(cParticle2D* pParticle, rEffect2D::E2D_PARAM_LINE_LENGTH* pLineLengthParam, bool UpdateOldFlag);
    MtMatrix calcParticleMatrix(f32 Angle, const MtFloat2& Dir, u32 ParticleFlag);
    void initParticleModelTexScroll(cModel2D* pModel);
    void moveParticleSpriteLoop();
    void moveParticlePolylineLoop();
    void moveParticleTexlineLoop();
    void moveParticleLineLoop();
    void moveParticleModelLoop();
    bool moveParticleSprite(cParticle2D* pParticle);
    bool moveParticlePolyline(cParticle2D* pParticle);
    bool moveParticleTexline(cParticle2D* pParticle);
    bool moveParticleLine(cParticle2D* pParticle);
    bool moveParticleModel(cParticle2D* pParticle);
    bool moveParticleCommon(cParticle2D* pParticle);
    bool moveParticleMoveNone(cParticle2D* pParticle);
    bool moveParticleMoveAdd(cParticle2D* pParticle);
    bool moveParticleMoveMul(cParticle2D* pParticle);
    bool moveParticleMoveCustom(cParticle2D* pParticle);
    bool moveParticleLifeFrame(cParticle2D* pParticle);
    bool moveParticleLifeKeyframe(cParticle2D* pParticle);
    bool moveParticleLifeHideframe(cParticle2D* pParticle);
    bool moveParticleLifeCurveframe(cParticle2D* pParticle);
    bool moveAnim(cAnimParticle2D* pAnimParticle);
    void moveIntensity(cParticle2D* pParticle);
    bool moveBaseScale(cParticle2D* pParticle);
    bool moveParticleLineOfs(cParticle2D* pParticle, void* pParam);
    void moveParticleLineFollowOfs(cParticle2D* pParticle);
    void moveParticleLineFixOfs(cParticle2D* pParticle, rEffect2D::E2D_PARAM_LINE_FIX* pLineFixParam);
    bool moveParticleLineLengthOfs(cParticle2D* pParticle, rEffect2D::E2D_PARAM_LINE_LENGTH* pLineLengthParam);
    void moveParticleModelTexScroll(cModel2D* pModel);
    void drawParticleSpriteLoop(cDraw* pDraw, cPrim* pPrim, s32 Transparency, u32 DrawTargetNo);
    void drawParticlePolylineLoop(cDraw* pDraw, cPrim* pPrim, s32 Transparency, u32 DrawTargetNo, u8* pDrawBuff);
    void drawParticleTexlineLoop(cDraw* pDraw, cPrim* pPrim, s32 Transparency, u32 DrawTargetNo, u8* pDrawBuff);
    void drawParticleLineLoop(cDraw* pDraw, cPrim* pPrim, s32 Transparency, u32 DrawTargetNo, u8* pDrawBuff);
    void drawParticleModelLoop(cDraw* pDraw, cPrim* pPrim, s32 Transparency, u32 DrawTargetNo);
    MtVector4 getDrawPos(cDraw* pDraw) const;
    MtVector4 getDrawScale(cDraw* pDraw) const;
    MtVector4 getDrawLineScale(cDraw* pDraw) const;
    MtVector4 getDrawPolylineScale(cDraw* pDraw, f32* pSizeScale) const;
    MtSize getViewportSize(cDraw* pDraw) const;
    s32 getDrawPriorityDepth() const;
    f32 correctParticlePos(f32 Pos, s32 Size);
    MtVector4 calcParticleSpriteRange(const MtFloat2& Pos, const MtFloat2& Scale, const MtPoint& PatCenter, rEffectAnim::SEQ_PAT* pSeqPat, u32 FixAngle);
    MtVector4 calcParticlePolylineRange(const MtFloat2& Pos, MtFloat2* pOfs, u32 VertexNum, f32 HeadSize, f32 PlaceSize);
    MtVector4 calcParticleLineRange(const MtFloat2& Pos, MtFloat2* pOfs, u32 VertexNum);
    u32 calcParticleRepeat(MtFloat2* pPosArray, const MtFloat2& Pos, const MtFloat2& Ofs, const MtSize& Size, const MtVector4& Range);
    void setVertexOfs(cParticle2D* pParticle, MtFloat2* pOfsBuff, u32 OfsNum, const MtVector4& DrawScale);
    u32 setVertexOfsExt(cParticle2D* pParticle, MtFloat2* pOfsBuff, u32 OfsNum, const MtVector4& DrawScale);
    u32 setVertexOfsDiv(cParticle2D* pParticle, MtFloat2* pOfsBuff, u32 OfsNum, u32 DivNum, const MtVector4& DrawScale);
    u32 setVertexOfsDivExt(cParticle2D* pParticle, MtFloat2* pOfsBuff, u32 OfsNum, u32 DivNum, const MtVector4& DrawScale);
    u32 calcVertexOfsDiv(MtFloat2* pOfsBuff, MtFloat2* pBaseOfsBuff, u32 OfsNum, u32 DivNum);
    bool extractLineOfs(MtFloat2* pOfsBuff, u32 Max, cEffectValueU32& Line);
    void setVertexPos(nPrim::Vertex* pVertex, const MtFloat2& Pos, MtFloat2* pOfsBuff, u32 VertexNum);
    bool setPolylineVertexParam(cPolyline2D* pPolyline, nPrim::Vertex* pVertex, nPrim::Rect& Rect, const MtVector4& Param, s32 Transparency);
    bool setPolylineVertexParamExt(cPolyline2D* pPolyline, nPrim::Vertex* pVertex, nPrim::Rect& Rect, const MtVector4& Param, s32 Transparency, u32 VertexNum);
    bool setTexlineVertexParam(cTexline2D* pTexline, nPrim::Vertex* pVertex, s32 Transparency);
    bool setTexlineVertexParamExt(cTexline2D* pTexline, nPrim::Vertex* pVertex, s32 Transparency, u32 VertexNum);
    void setTexlineVertexPattern(cTexline2D* pTexline, nPrim::Vertex* pVertex, u32 VertexNum);
    bool setLineVertexParam(cLine2D* pLine, nPrim::Vertex* pVertex, s32 Transparency);
    bool setLineVertexParamExt(cLine2D* pLine, nPrim::Vertex* pVertex, s32 Transparency, u32 VertexNum);
    MtMatrix calcParticleModelDrawMatrix(const MtVector3& Scale, const MtVector3& Rot, u32 RotOrder);
    u32 getKeyframeTimer(nEffect::KEYFRAME_INDEX* pIndex) const;
    u32 getKeyframeTimer(nEffect::KEYFRAME_INDEX* pIndex, cParticle2D* pParticle) const;
private:
    uEffect2D* mpOwner;  // offset: 0x0
    u32 mGeneratorNo : 16;  // offset: 0x8
    u32 mListNo : 16;  // offset: 0x8
    u32 mStatus : 16;  // offset: 0xc
    u32 mParticleTotalSize : 16;  // offset: 0xc
    u32 mParticleNum : 16;  // offset: 0x10
    u32 mParticleMoveNum : 16;  // offset: 0x10
    MtMatrix mLmat;  // offset: 0x20
    MtVector3 mWorldPos;  // offset: 0x60
    MtFloat2 mScreenPos;  // offset: 0x70
    rEffect2D::ResourceInfo* mpResourceInfo;  // offset: 0x78
    u32 mGeneratorType : 8;  // offset: 0x80
    u32 mParticleType : 8;  // offset: 0x80
    u32 mLifeType : 8;  // offset: 0x80
    u32 mMoveType : 8;  // offset: 0x80
    rEffect2D::E2D_GENERATOR* mpGeneratorParam;  // offset: 0x88
    rEffect2D::E2D_PARTICLE_COMMON* mpParticleParam;  // offset: 0x90
    rEffect2D::E2D_LIFE_FRAME* mpLifeParam;  // offset: 0x98
    rEffect2D::E2D_MOVE_COMMON* mpMoveParam;  // offset: 0xa0
    u32 mRandCtr;  // offset: 0xa8
    u32 mStartRandCtr : 16;  // offset: 0xac
    u32 mWaitFrame : 16;  // offset: 0xac
    u32 mParticlePosOffset : 16;  // offset: 0xb0
    u32 mParticleLifeOffset : 16;  // offset: 0xb0
    u32 mParticleMoveOffset : 16;  // offset: 0xb4
    u32 mRno : 8;  // offset: 0xb4
    u32 mColorCorrectType : 4;  // offset: 0xb4
    u32 mCurDataIndex : 1;  // offset: 0xb4
    u32 mOldDataIndex : 1;  // offset: 0xb4
    u32 mEachFrameMode : 1;  // offset: 0xb4
    u32 mKeepHoldFlag : 1;  // offset: 0xb4
    cParticle2D* mpMoveTopParticle;  // offset: 0xb8
    cParticle2D* mpMoveBotParticle;  // offset: 0xc0
    cParticle2D* mpStockTopParticle;  // offset: 0xc8
    cParticle2D* mpStockBotParticle;  // offset: 0xd0
    u8* mpParticleBuff;  // offset: 0xd8
    u32 mPrimAttribute[3];  // offset: 0xe0
    u32 mTimer;  // offset: 0xec
    u32 mSetTimer : 16;  // offset: 0xf0
    u32 mLoopCtr : 16;  // offset: 0xf0
    u32 mSetParticleTotal;  // offset: 0xf4
    u32 mSetFrameTotal;  // offset: 0xf8
    f32 mSetFrameOfs;  // offset: 0xfc
    f32 mIntervalFrameOfs;  // offset: 0x100
    u32 mSetNumKeyframeRandom;  // offset: 0x104
    u32 mColorFlag : 8;  // offset: 0x108
    u32 mGenerator08cd : 8;  // offset: 0x108
    u32 mGenerator08ce : 8;  // offset: 0x108
    u32 mGenerator08cf : 8;  // offset: 0x108
    MtColor mColor[2];  // offset: 0x10c
    MtColor mPlaceColor[2];  // offset: 0x114
    MtColor* mpOrgColor;  // offset: 0x120
    MtColor* mpOrgPlaceColor;  // offset: 0x128
    u32 mGeneratorOptionFlag;  // offset: 0x130
    u32 mGenerator32ec;  // offset: 0x134
};
