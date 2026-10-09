#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtPrimitive2D.h"
#include "cEffect.h"
#include "cParticle.h"
#include "cParticleManager.h"
#include "rEffectList.h"
#include "sGpuParticle.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtMatrix;
class MtObject;
class MtRangeF;
class MtVector3;
class cClothVertex;
class cDraw;
class cEffectAnim;
class cEffectChain;
class cEffectCulling;
class cEffectLineLength;
class cEffectPath;
class cEffectShadeLight;
class cEffectStrip;
class cEffectValueU32;
class cLineParticle;
class cMatrixParticle;
class cParticle;
class cParticleAnimParam;
class cParticleLifeCommon;
class cParticleMoveAdd;
class cParticleMoveCommon;
class cParticleMoveCustom;
class cParticleMoveMul;
class cParticleMoveNone;
class cParticleMovePathChain;
class cParticleMovePathKeyframe;
class cParticleMovePathLine;
class cParticleMovePathStrip;
class cParticleMoveSpin;
class cPrim;
namespace nPrim { struct Vertex; }
class rEffectList;
class uEffect;

// Declarations
class cParticleGenerator;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cParticleGenerator : public cParticleManager
{
public:
    class MyDTI;
    class ParticleParam;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class ParticleParam
    {
    public:
        ParticleParam(f32 SetRate, uEffect* pChild);
        void setOfs(const MtVector3& Ofs);
    public:
        cEffectStrip mStrip;  // offset: 0x0
        f32 mLifeRate;  // offset: 0x20
        f32 mSetRate;  // offset: 0x24
        uEffect* mpChild;  // offset: 0x28
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
    cParticleGenerator();
    virtual ~cParticleGenerator();
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
    virtual void updateWorldMatrix();  // vtable slot 16
    virtual void applyWorldOffset(const MtVector3& Offset);  // vtable slot 17
    virtual bool move();  // vtable slot 18
    virtual void updateConst();  // vtable slot 19
    // Address: 0x01b750a0 - 0x01b750a1 (1 bytes)
    virtual void update() {}  // vtable slot 20
    virtual bool isDraw(cDraw* pDraw) const;  // vtable slot 22
    cParticle* openParticle(u32 SetNo);
    cParticle* closeParticle(cParticle* pParticle);
    void closeParticleAll();
    cParticle* getMoveTopParticle();
    cParticle* getParticle(u32 No);
    MtVector3 getRangeScale();
    void setRangeScale(const MtVector3& Scale);
    cEffectCulling* getCulling();
    cEffectPath* getPath();
    cEffectShadeLight* getShadeLight();
    cClothVertex* getClothVertex();
    u8* getParticlePosBuff(cParticle* pParticle);
    cParticleLifeCommon* getParticleLifeCommon(cParticle* pParticle);
    cParticleMoveCommon* getParticleMoveCommon(cParticle* pParticle);
    cEffectCulling* getParticleCulling(cParticle* pParticle);
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
    const MtRangeF& getIntensity() const;
    void setIntensity(const MtRangeF&);
    const MtRangeF getOrgIntensity();
    bool isLighting() const;
    bool isClothChain() const;
    void unconstParticleLineClothChain(u32 Mode);
    static u32 getParticleMoveSize(u32 MoveType);
    void setStencilTest(bool);
    bool getStencilTest() const;
protected:
    u32 getLineParticlePosSize(u32 LineOfsNum, u32 LineType, u32 ClothType);
    bool constructParticleMapping(u32 ParticleSize, u32 ParticlePosSize);
    bool initCullingParam();
    void initParticleRotParam(rEffectList::EFL_PARAM_LINE_FIX* pParam);
    void initParticleRotParam(rEffectList::EFL_PARAM_LINE_LENGTH* pParam);
    void initParticleRotParam(rEffectList::EFL_PARAM_CLOTH_CHAIN* pParam);
    void initParticleRotParam(rEffectList::EFL_PARAM_CLOTH_CURVE* pParam);
    void initColor(u32 ColorPlaceType, MtColor* pOrgPlaceColor);
    void initColor(MtColor* pOrgColor, u32 ColorFlag);
    void initIntensity();
    bool initParticleMoveParam(u32 OriginalBuffSize);
    u32 getClothVertexBuffSize(u32 ClothType, u32 LineOfsNum);
    void setClothVertexBuff(u32 ClothType, u32 LineOfsNum, u32 BuffSize, u32 BuffOffset);
    void initPath();
    void movePath(bool ConstUpdateMode);
    u8* getPathBuff();
    void initCullingDir();
    void moveCullingDir();
    MtVector3 interpolateCullingDir(f32 InpRate);
    void updateDataIndex();
    u32 updateSingleGenerator();
    u32 updateLoopGenerator();
    virtual bool initParticle(cParticle* pParticle, ParticleParam& Param);  // vtable slot 23
    bool initParticlePos(cParticle* pParticle, cParticleMoveCommon* pParticleMove, ParticleParam& Param);
    void initParticleMove(cParticle* pParticle, cParticleMoveCommon* pParticleMove, ParticleParam& Param);
    virtual bool moveParticleLoop();  // vtable slot 24
    void moveParticleCullingLoop();
    bool moveParticleMove(cParticle* pParticle, cParticleMoveCommon* pParticleMove, bool ConstUpdateMode);
    bool isSynchroBoundary(cSynchronization::BoundaryParam& Param) const;
    void applyParticleWorldOffsetLoop(const MtVector3& Offset);
    void applyParticleLineWorldOffsetLoop(const MtVector3& Offset);
    void applyParticlePolygonStripWorldOffsetLoop(const MtVector3& Offset);
    void applyParticleClothPolygonWorldOffsetLoop(const MtVector3& Offset);
    void applyParticleMoveSpinWorldOffsetLoop(const MtVector3& Offset);
    void updateConstParticleLinePosLoop(void* pParam);
    void updateConstParticleMatrixLoop();
    void updateConstParticleMove(cParticle* pParticle);
    void updateParticleLineClothChainLoop(rEffectList::EFL_PARAM_CLOTH_CHAIN* pClothChainParam);
    void updateParticleLineClothCurveLoop(rEffectList::EFL_PARAM_CLOTH_CURVE* pClothCurveParam);
    void updateParticleLineClothZigzagLoop(rEffectList::EFL_PARAM_CLOTH_ZIGZAG* pClothZigzagParam);
    void updateParticleLineClothStraightLoop();
    void initParticleAnimParam(cParticle* pParticle, cParticleAnimParam& Param);
    bool moveParticleAnim(cParticle* pParticle, cEffectAnim* pAnim, f32 KeyframeRate);
    void initParticleIntensity(cParticle* pParticle);
    void moveParticleIntensity(cParticle* pParticle);
    f32 initParticleScale(cParticle* pParticle, f32 ScaleMin);
    bool moveParticleScale(cParticle* pParticle, f32 ScaleMin);
    void initParticleRot(cParticle* pParticle, MtVector3& Rot, MtVector3& RotAdd, MtRangeF* pRotRange, MtRangeF* pRotAddRange, u32 KeyframeRotParamOffset);
    void initParticleRot(cMatrixParticle* pMatrixParticle, MtRangeF* pRotRange, MtRangeF* pRotAddRange, u32 KeyframeRotParamOffset);
    void moveParticleRot(cParticle* pParticle, MtVector3& CurRot, const MtVector3& OldRot, MtVector3& RotAdd, u32 KeyframeRotParamOffset, f32 RotAddCoef);
    void moveParticleRot(cMatrixParticle* pMatrixParticle, u32 KeyframeRotParamOffset, f32 RotAddCoef);
    void initParticleModelScale(cParticle* pParticle, MtVector3& ModelScale, MtVector3& ModelScaleAdd, MtRangeF* pModelScaleRange, MtRangeF* pModelScaleAddRange, u32 KeyframeModelScaleParamOffset);
    u32 getParticleTexScrollWorkOffset() const;
    bool initParticleTexScroll(cParticle* pParticle, rEffectList::EFL_PARAM_TEX_SCROLL* pTexScrollParam, u32 WorkOffset);
    void moveParticleTexScroll(cParticle* pParticle, rEffectList::EFL_PARAM_TEX_SCROLL* pTexScrollParam, u32 WorkOffset);
    MtColor calcSrcColor();
    MtColor calcSrcPlaceColor();
    MtColor calcLifeColor(MtColor Color, f32 LifeRate);
    MtMatrix calcParticleMatrix(u32 ParticleFlag, const MtVector3& Rot, const MtVector3& Dir, f32 Scale);
    MtMatrix calcParticleMatrix(u32 ParticleFlag, const MtVector3& Rot, const MtVector3& Dir, const MtVector3& ModelScale);
    MtMatrix calcModelParticleMatrix(u32 ParticleFlag, const MtVector3& Rot, const MtVector3& Dir, const MtVector3& ModelScale);
    MtVector3 calcParticleParentRotation(cParticle* pParticle);
    void initParticleLineOfs(cLineParticle* pLineParticle, void* pParam, ParticleParam& Param);
    void initParticleLineFollowOfs(cLineParticle* pLineParticle);
    void initParticleLineFixOfs(cLineParticle* pLineParticle, rEffectList::EFL_PARAM_LINE_FIX* pLineFixParam);
    void initParticleLineFixEndOfs(cLineParticle* pLineParticle, rEffectList::EFL_PARAM_LINE_FIX_END* pLineFixEndParam, ParticleParam& Param);
    void initParticleLineChainOfs(cLineParticle* pLineParticle, rEffectList::EFL_PARAM_CHAIN* pChainParam);
    void initParticleLineLengthOfs(cLineParticle* pLineParticle, rEffectList::EFL_PARAM_LINE_LENGTH* pLineLengthParam);
    void initParticleLineLengthParam(cLineParticle* pLineParticle, cEffectLineLength* pLineLength, rEffectList::EFL_PARAM_LINE_LENGTH* pLineLengthParam);
    void initParticleLineZigzagOfs(cLineParticle* pLineParticle, rEffectList::EFL_PARAM_LINE_ZIGZAG* pLineZigzagParam);
    void initParticleLineClothChain(cLineParticle* pLineParticle, rEffectList::EFL_PARAM_CLOTH_CHAIN* pClothChainParam);
    void initParticleLineClothCurve(cLineParticle* pLineParticle, rEffectList::EFL_PARAM_CLOTH_CURVE* pClothCurveParam);
    void initParticleLineClothZigzag(cLineParticle* pLineParticle, rEffectList::EFL_PARAM_CLOTH_ZIGZAG* pClothZigzagParam);
    void initParticleLineClothStraight(cLineParticle* pLineParticle, rEffectList::EFL_PARAM_CLOTH_STRAIGHT* pClothStraightParam);
    void initParticleLineCustomOfs(cLineParticle* pLineParticle);
    bool moveParticleLineOfs(cLineParticle* pLineParticle, void* pParam);
    void moveParticleLineFollowOfs(cLineParticle* pLineParticle);
    void moveParticleLineFixOfs(cLineParticle* pLineParticle, rEffectList::EFL_PARAM_LINE_FIX* pLineFixParam);
    void moveParticleLineFixEndOfs(cLineParticle* pLineParticle, rEffectList::EFL_PARAM_LINE_FIX_END* pLineFixEndParam);
    void moveParticleLineChainOfs(cLineParticle* pLineParticle, rEffectList::EFL_PARAM_CHAIN* pChainParam);
    bool moveParticleLineLengthOfs(cLineParticle* pLineParticle, rEffectList::EFL_PARAM_LINE_LENGTH* pLineLengthParam);
    bool moveParticleLineLengthParam(cLineParticle* pLineParticle, cEffectLineLength* pLineLength, rEffectList::EFL_PARAM_LINE_LENGTH* pLineLengthParam);
    bool moveParticleLineZigzagOfs(cLineParticle* pLineParticle, rEffectList::EFL_PARAM_LINE_ZIGZAG* pLineZigzagParam);
    void moveParticleLineClothChain(cLineParticle* pLineParticle, rEffectList::EFL_PARAM_CLOTH_CHAIN* pClothChainParam);
    void moveParticleLineClothCurve(cLineParticle* pLineParticle, rEffectList::EFL_PARAM_CLOTH_CURVE* pClothCurveParam);
    void moveParticleLineClothZigzag(cLineParticle* pLineParticle, rEffectList::EFL_PARAM_CLOTH_ZIGZAG* pClothZigzagParam);
    void moveParticleLineCustomOfs(cLineParticle* pLineParticle);
    void calcParticleLineFollowOfs(cLineParticle* pLineParticle, bool UpdateOldFlag);
    void calcParticleLineFixOfs(cLineParticle* pLineParticle, rEffectList::EFL_PARAM_LINE_FIX* pLineFixParam, bool UpdateOldFlag);
    void calcParticleLineLengthOfs(cLineParticle* pLineParticle, rEffectList::EFL_PARAM_LINE_LENGTH* pLineLengthParam, bool UpdateOldFlag);
    void calcParticleLineZigzagOfs(cLineParticle* pLineParticle, rEffectList::EFL_PARAM_LINE_ZIGZAG* pLineZigzagParam, bool UpdateOldFlag);
    void calcParticleLineZigzagOfsAmplitude(cLineParticle* pLineParticle, rEffectList::EFL_PARAM_LINE_ZIGZAG* pLineZigzagParam);
    void initChain(cEffectChain* pChain, rEffectList::EFL_PARAM_CHAIN* pChainParam, const MtVector3& Pos, const MtVector3& Dir, u32 ParticleFlag);
    void moveChain(cEffectChain* pChain, rEffectList::EFL_PARAM_CHAIN* pChainParam, const MtVector3& Pos, const MtVector3& Dir, u32 ParticleFlag);
    void setVolumeBlendRate(cParticle* pParticle);
    u32 getLODSkipMask(cDraw* pDraw);
    void setTexture(cPrim* pPrim);
    void setBaseMap(cPrim* pPrim);
    void setVertexPos(cParticle* pParticle, nPrim::Vertex* pVertex, u32 OfsNum);
    u32 setVertexPosExt(cParticle* pParticle, nPrim::Vertex* pVertex, u32 OfsNum);
    u32 setVertexPosDiv(cParticle* pParticle, nPrim::Vertex* pVertex, u32 OfsNum, u32 DivNum);
    u32 setVertexPosDivExt(cParticle* pParticle, nPrim::Vertex* pVertex, u32 OfsNum, u32 DivNum);
    void setVertexPos(cParticle* pParticle, MtVector3* pPos, u32 OfsNum);
    u32 setVertexPosExt(cParticle* pParticle, MtVector3* pPos, u32 OfsNum);
    void setVertexClothPos(cParticle* pParticle, nPrim::Vertex* pVertex, u32 OfsNum);
    u32 setVertexClothPosDiv(cParticle* pParticle, nPrim::Vertex* pVertex, u32 OfsNum, u32 DivNum);
    void setVertexPos(cParticle* pParticle, sGpuParticle::Particle* pVertex, u32 OfsNum);
    u32 setVertexPosExt(cParticle* pParticle, sGpuParticle::Particle* pVertex, u32 OfsNum);
    u32 setVertexPosDiv(cParticle* pParticle, sGpuParticle::Particle* pVertex, u32 OfsNum, u32 DivNum);
    u32 setVertexPosDivExt(cParticle* pParticle, sGpuParticle::Particle* pVertex, u32 OfsNum, u32 DivNum);
    u32 calcVertexPosDiv(nPrim::Vertex* pVertex, MtVector3* pBasePos, u32 OfsNum, u32 DivNum);
    u32 calcVertexPosDiv(sGpuParticle::Particle* pVertex, MtVector3* pBasePos, u32 OfsNum, u32 DivNum);
    bool extractLinePos(nPrim::Vertex* pVertex, u32 Max, cEffectValueU32& Line);
    bool extractLinePos(MtVector3* pPos, u32 Max, cEffectValueU32& Line);
    bool extractLinePos(sGpuParticle::Particle* pVertex, u32 Max, cEffectValueU32& Line);
private:
    void resetGeneratorParam();
    void setSetFrame();
    bool setIntervalFrame();
    u32 correctSetNum(u32 SetNum);
    MtVector3 calcParticleOfs(u32 SetNo, u32 RangeType, u32 RangeDivideNum, MtRangeF* pRange, uEffect* pChild);
    MtVector3 calcParticleOfsKeyframe(u32 SetNo, uEffect* pChild);
    f32 getRangeDivideRate(u32 SetNo, u32 RangeType, u32 RangeDivideNum);
    MtVector3 calcParticleDir(const MtVector3& Ofs);
    bool initRangeStripOfs(cEffectStrip& Strip, MtVector3& Ofs, MtVector3& Dir, u32 SetNo);
    bool initRangeStripOfsVertex(cEffectStrip& Strip, MtVector3& Ofs, MtVector3& Dir, u32 SetNo);
    bool initRangeStripOfsPathLinear(cEffectStrip& Strip, MtVector3& Ofs, MtVector3& Dir, u32 SetNo);
    bool initRangeStripOfsPathHermite(cEffectStrip& Strip, MtVector3& Ofs, MtVector3& Dir, u32 SetNo);
    bool initRangeStripOfsPathSpline(cEffectStrip& Strip, MtVector3& Ofs, MtVector3& Dir, u32 SetNo);
    bool initRangeStripOfsModel(cEffectStrip& Strip, MtVector3& Ofs, MtVector3& Dir, u32 SetNo);
    void initRangeStripOfsPathCommon(cEffectStrip& Strip, u32 SetNo);
    bool calcRangeStripOfs(cEffectStrip& Strip, MtVector3& Ofs, MtVector3& Dir);
    bool calcRangeStripOfsVertex(cEffectStrip& Strip, MtVector3& Ofs, MtVector3& Dir);
    bool calcRangeStripOfsPathLinear(cEffectStrip& Strip, MtVector3& Ofs, MtVector3& Dir);
    bool calcRangeStripOfsPathHermite(cEffectStrip& Strip, MtVector3& Ofs, MtVector3& Dir);
    bool calcRangeStripOfsPathSpline(cEffectStrip& Strip, MtVector3& Ofs, MtVector3& Dir);
    bool calcRangeStripOfsModel(cEffectStrip& Strip, MtVector3& Ofs, MtVector3& Dir);
    MtVector3 calcMoveDir(const MtVector3& Rot, const MtVector3& Dir, u32 ParticleFlag);
    u32 moveParticlePosCollision(cParticleMoveCommon* pParticleMove, const MtVector3& OldPos, const MtVector3& OldSpeedVec, MtVector3& Pos, MtVector3& SpeedVec);
    u32 moveParticlePosEasyCollision(cParticleMoveCommon* pParticleMove, const MtVector3& OldPos, const MtVector3& OldSpeedVec, MtVector3& Pos, MtVector3& SpeedVec);
    u32 moveParticlePosCollisionEnd(cParticleMoveCommon* pParticleMove, const MtVector3& HitPos, const MtVector3& HitDir, f32 Radius, bool CorrectSphereFlag, MtVector3& Pos);
    u32 moveParticlePosCollisionBounce(cParticleMoveCommon* pParticleMove, const MtVector3& HitPos, const MtVector3& HitDir, const MtVector3& OldSpeedVec, f32 Radius, bool CorrectSphereFlag, MtVector3& Pos, MtVector3& SpeedVec);
    void setCollEffect(rEffectList* pEffectList, u32 GroupFlag, u32 MaterialFlag, const MtVector3& Dir, const MtVector3& Pos, u32 Order, u32 AxisType);
    bool correctParticlePosCollision(MtVector3& Pos, MtVector3& Ofs, MtVector3& Dir, bool DirFlag);
    u32 moveParticlePosStandardCollision(cParticleMoveCommon* pParticleMove, const MtVector3& OldPos, const MtVector3& OldSpeedVec, MtVector3& Pos, MtVector3& SpeedVec);
    u32 calcParticleMovePathStripPos(cParticleMovePathStrip* pParticleMove, MtVector3& Pos, u32 DataIndex);
    void updateParticleMovePathStripDistance(cParticleMovePathStrip* pParticleMove, u32 DataIndex);
    u32 calcParticleMovePathChainPos(cParticleMovePathChain* pParticleMove, MtVector3& Pos, u32 DataIndex, u32 PathDataIndex);
    u32 calcParticleMovePathKeyframePos(cParticleMovePathKeyframe* pParticleMove, const MtVector3& Ofs, MtVector3& Pos);
    u32 calcParticleMovePathLinePos(cParticleMovePathLine* pParticleMove, MtVector3& Pos, u32 DataIndex);
    MtVector3 calcParticleMovePathRangeStripPos(cEffectStrip& Strip, const MtVector3& Ofs);
    void shiftParticleMoveAdd(cParticle* pParticle, cParticleMoveAdd* pParticleMove, const MtVector3& SpeedVec);
    void calcPathStripLength(bool InitFlag);
    f32 getPathStripLengthHermite(f32* LengthArray, MtVector3* PosArray, f32 BaseLength, u32 DivideNum);
    f32 getPathStripLengthSpline(f32* LengthArray, MtVector3* PosArray, u32 Node, f32 BaseLength, u32 DivideNum);
    f32 getPathStripDistanceRate(f32* LengthArray, u32 LengthArrayNum, f32 Distance, f32 DistanceRate);
    void initPathChain();
    void movePathChain();
    MtVector3 getPath3DScale();
    void setPath3DScale(const MtVector3&);
    f32 getPathLengthScale();
    void setPathLengthScale(f32);
    u32 getPathStripLineNum();
    u32 getPathStripLengthArrayNum();
    u32 getPathStripLengthArraySize();
    f32 getPathStripLength();
    void initParticleMoveCommon(cParticleMoveCommon* pParticleMove, ParticleParam& Param);
    void initParticleMoveNone(cParticle* pParticle, cParticleMoveNone* pParticleMove, ParticleParam& Param);
    void initParticleMoveAdd(cParticle* pParticle, cParticleMoveAdd* pParticleMove, ParticleParam& Param);
    void initParticleMoveAddFast(cParticle* pParticle, cParticleMoveAdd* pParticleMove, ParticleParam& Param);
    void initParticleMoveMul(cParticle* pParticle, cParticleMoveMul* pParticleMove, ParticleParam& Param);
    void initParticleMoveMulFast(cParticle* pParticle, cParticleMoveMul* pParticleMove, ParticleParam& Param);
    void initParticleMovePathStrip(cParticle* pParticle, cParticleMovePathStrip* pParticleMove, ParticleParam& Param);
    void initParticleMovePathChain(cParticle* pParticle, cParticleMovePathChain* pParticleMove, ParticleParam& Param);
    void initParticleMovePathKeyframe(cParticle* pParticle, cParticleMovePathKeyframe* pParticleMove, ParticleParam& Param);
    void initParticleMovePathLine(cParticle* pParticle, cParticleMovePathLine* pParticleMove, ParticleParam& Param);
    void initParticleMoveCustom(cParticle* pParticle, cParticleMoveCustom* pParticleMove, ParticleParam& Param);
    void initParticleMoveSpin(cParticle* pParticle, cParticleMoveSpin* pParticleMove, ParticleParam& Param);
    void initParticleMoveSpinFast(cParticle* pParticle, cParticleMoveSpin* pParticleMove, ParticleParam& Param);
    void initParticleMoveSpinCommon(cParticle* pParticle, cParticleMoveSpin* pParticleMove, ParticleParam& Param);
    bool moveParticleMoveNone(cParticle* pParticle, cParticleMoveNone* pParticleMove, bool ConstUpdateMode);
    bool moveParticleMoveAdd(cParticle* pParticle, cParticleMoveAdd* pParticleMove);
    bool moveParticleMoveAddFast(cParticle* pParticle, cParticleMoveAdd* pParticleMove);
    bool moveParticleMoveMul(cParticle* pParticle, cParticleMoveMul* pParticleMove, bool CollisionFlag);
    bool moveParticleMoveMulFast(cParticle* pParticle, cParticleMoveMul* pParticleMove);
    bool moveParticleMovePathStrip(cParticle* pParticle, cParticleMovePathStrip* pParticleMove, bool ConstUpdateMode);
    bool moveParticleMovePathChain(cParticle* pParticle, cParticleMovePathChain* pParticleMove, bool ConstUpdateMode);
    bool moveParticleMovePathKeyframe(cParticle* pParticle, cParticleMovePathKeyframe* pParticleMove, bool ConstUpdateMode);
    bool moveParticleMovePathLine(cParticle* pParticle, cParticleMovePathLine* pParticleMove, bool ConstUpdateMode);
    bool moveParticleMoveCustom(cParticle* pParticle, cParticleMoveCustom* pParticleMove, bool ConstUpdateMode);
    bool moveParticleMoveSpin(cParticle* pParticle, cParticleMoveSpin* pParticleMove);
    bool moveParticleMoveSpinFast(cParticle* pParticle, cParticleMoveSpin* pParticleMove);
    bool moveParticleMoveSpinCommon(cParticle* pParticle, cParticleMoveSpin* pParticleMove, bool CollisionFlag);
    void correctParticleMoveAdd(cParticle* pParticle, cParticleMoveAdd* pParticleMove);
    void correctParticleMoveMul(cParticle* pParticle, cParticleMoveMul* pParticleMove);
    void correctParticleMoveSpin(cParticle* pParticle, cParticleMoveSpin* pParticleMove);
    void moveParticleMoveNoneLoop();
    void moveParticleMoveAddLoop();
    void moveParticleMoveAddFastLoop();
    void moveParticleMoveMulLoop();
    void moveParticleMoveMulFastLoop();
    void moveParticleMovePathStripLoop();
    void moveParticleMovePathChainLoop();
    void moveParticleMovePathKeyframeLoop();
    void moveParticleMovePathLineLoop();
    void moveParticleMoveCustomLoop();
    void moveParticleMoveSpinLoop();
    void moveParticleMoveSpinFastLoop();
    void moveParticleLifeFrameLoop();
    void moveParticleLifeKeyframeLoop();
    void moveParticleLifeHideframeLoop();
    void moveParticleLifeCurveframeLoop();
    void moveParticleMaterial();
protected:
    cParticle* mpMoveTopParticle;  // offset: 0xd0
    cParticle* mpMoveBotParticle;  // offset: 0xd8
    cParticle* mpStockTopParticle;  // offset: 0xe0
    cParticle* mpStockBotParticle;  // offset: 0xe8
    u32 mParticleStatus;  // offset: 0xf0
    u32 mParticleLifeOffset;  // offset: 0xf4
    u32 mParticleMoveOffset;  // offset: 0xf8
    u32 mParticleCullingOffset;  // offset: 0xfc
    u32 mParticleNum : 16;  // offset: 0x100
    u32 mParticleMoveNum : 16;  // offset: 0x100
    u32 mParticleSize : 16;  // offset: 0x104
    u32 mParticlePosSize : 16;  // offset: 0x104
    u32 mParticleLifeSize : 16;  // offset: 0x108
    u32 mParticleMoveSize : 16;  // offset: 0x108
    u32 mParticleCullingSize : 16;  // offset: 0x10c
    u32 mParticleFlagBase : 16;  // offset: 0x10c
    u32 mStripParentNo : 16;  // offset: 0x110
    u32 mSetTimer : 16;  // offset: 0x110
    u32 mRangeDivideNum : 16;  // offset: 0x114
    u32 mRangeType : 8;  // offset: 0x114
    u32 mRangeDirType : 8;  // offset: 0x114
    u32 mRangeDisperseType : 8;  // offset: 0x118
    u32 mLODType : 4;  // offset: 0x118
    u32 mAxisType : 4;  // offset: 0x118
    u32 mParticleRotOrder : 4;  // offset: 0x118
    u32 mParticleRotAxisType : 4;  // offset: 0x118
    u32 mParticleDirAxisType : 4;  // offset: 0x118
    u32 mGenerator043b : 4;  // offset: 0x118
    u32 mMoveRotOrder : 4;  // offset: 0x11c
    u32 mMoveRotAxisType : 4;  // offset: 0x11c
    u32 mCurDataIndex : 1;  // offset: 0x11c
    u32 mOldDataIndex : 1;  // offset: 0x11c
    u32 mSynchroUnitFlag : 1;  // offset: 0x11c
    u32 mRotInitFlag : 1;  // offset: 0x11c
    u32 mRotLocalFlag : 1;  // offset: 0x11c
    u32 mModelScaleAfterFlag : 1;  // offset: 0x11c
    u32 mPathInitFlag : 1;  // offset: 0x11c
    u32 mPatRotFlag : 1;  // offset: 0x11c
    u32 mVolumeBlendRate : 8;  // offset: 0x11c
    u32 mVolumeBlendRateRange : 8;  // offset: 0x11c
    rEffectList::EFL_PARAM_COLL* mpCollParam;  // offset: 0x120
    u32 mPrimAttribute;  // offset: 0x128
    f32 mParticleScaleBase;  // offset: 0x12c
    f32 mParticleScale;  // offset: 0x130
    MtMatrix mParticleScaleWmat;  // offset: 0x140
    MtVector3 mParticle3DScale;  // offset: 0x180
    MtVector3 mForceVec;  // offset: 0x190
    MtVector3 mRangeScale;  // offset: 0x1a0
    MtColor mColor[2];  // offset: 0x1b0
    MtColor mPlaceColor[2];  // offset: 0x1b8
    MtColor* mpOrgColor;  // offset: 0x1c0
    MtColor* mpOrgPlaceColor;  // offset: 0x1c8
    MtRangeF mIntensity;  // offset: 0x1d0
    MtRangeF* mpOrgIntensity;  // offset: 0x1d8
    u32 mColorFlag : 8;  // offset: 0x1e0
    u32 mDecreaseWaitTimer : 8;  // offset: 0x1e0
    u32 mDecreaseModNum : 8;  // offset: 0x1e0
    u32 mSetNumCorrectFlag : 1;  // offset: 0x1e0
    u32 mEachFrameMode : 1;  // offset: 0x1e0
    u32 mClothChainFlag : 1;  // offset: 0x1e0
    u32 mLiteParticleFlag : 1;  // offset: 0x1e0
    u32 mSynchroUnitLimitFlag : 1;  // offset: 0x1e0
    u32 mGenerator03e7 : 3;  // offset: 0x1e0
    u32 mSetParticleTotal;  // offset: 0x1e4
    u32 mSetFrameTotal;  // offset: 0x1e8
    f32 mSetFrameOfs;  // offset: 0x1ec
    f32 mIntervalFrameOfs;  // offset: 0x1f0
    u32 mSetNumKeyframeRandom : 16;  // offset: 0x1f4
    u32 mLoopCtr : 16;  // offset: 0x1f4
    f32 mSubPosDistCoef;  // offset: 0x1f8
    u8* mpExtendedBuff;  // offset: 0x200
    cEffectCulling* mpCulling;  // offset: 0x208
    cEffectPath* mpPath;  // offset: 0x210
    cEffectShadeLight* mpShadeLight;  // offset: 0x218
    cClothVertex* mpClothVertex;  // offset: 0x220
    bool mStencilTest;  // offset: 0x228
public:
    static MyDTI DTI;
};
