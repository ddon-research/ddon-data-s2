#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtGeomSphere.h"
#include "MtMath.h"
#include "cUnit.h"
#include "rModel.h"
#include "sCollision.h"

// Forward declarations
class MtAABB;
class MtAllocator;
struct MtContact;
class MtDTI;
struct MtFloat2;
struct MtFloat3;
struct MtFloat3x3;
struct MtFloat3x4;
struct MtFloat4;
class MtGeomConvex;
class MtGeomSphere;
struct MtHalf4;
class MtMatrix;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtQuaternion;
class MtSphere;
class MtTriangle;
class MtUI;
class MtVector3;
class MtVector4;
class cBakeModelEx;
class cDraw;
class cSoundPhysicsSoftBody;
class cpSoftBody;
namespace nDraw { class IndexBuffer; }
namespace nDraw { class Material; }
namespace nDraw { class Texture; }
namespace nDraw { class VertexBuffer; }
class rDeformWeightMap;
class rModel;
class rSoundPhysicsSoftBody;
class uISC;
class uModel;

// Declarations
class uSimSoftBody;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class uSimSoftBody : public cUnit
{
    // inferred: cBakeModelEx::checkSoftBodyResource names uSimSoftBody::mpTargetUnit
    friend class cBakeModelEx;
    // inferred: cpSoftBody::setSimSoftBody names uSimSoftBody::mColliderType
    friend class cpSoftBody;
public:
    enum SIMSTATE
    {
        SIM_STOP = 0,
        SIM_RUN = 1,
        SIM_RESTART = 2,
    };
    enum REBUILD_STATES
    {
        REBUILD_NONE = 1,
        REBUILD_PROCESSING = 2,
        REBUILD_FINISH = 4,
        REBUIDL_FORCE_DWORD = -1,
    };
public:
    class MyDTI;
    struct LOCAL_PRIMITIVE_INFO;
    struct SoftBodyLWMatrix;
    struct LOD;
    struct MtHalf4x2;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct LOCAL_PRIMITIVE_INFO
    {
    public:
        bool mIsCpuSkinning;  // offset: 0x0
        u32 mVertexBase;  // offset: 0x4
    };
public:
    struct alignas(8) SoftBodyLWMatrix
    {
    public:
        MtFloat3x4 LWMatrix;  // offset: 0x0
        MtFloat3x4 DiffMatrix;  // offset: 0x30
        MtFloat3x4 DiffMatrixInv;  // offset: 0x60
        MtFloat3x4 LWMatrixInv;  // offset: 0x90
    };
public:
    struct LOD
    {
    public:
        u32 mInitOk;  // offset: 0x0
        u32 mSwapPrev;  // offset: 0x4
        u32 mSwapCurr;  // offset: 0x8
        u32 mSwapNext;  // offset: 0xc
        u32 mSwapCurrDraw;  // offset: 0x10
        nDraw::Texture* mpTexSkin[2];  // offset: 0x18
        nDraw::Texture* mpTexColN[2];  // offset: 0x28
        nDraw::Texture* mpTexSwapX[2][4];  // offset: 0x38
        nDraw::Texture* mpTexFixPrimVtx;  // offset: 0x78
        nDraw::Texture* mpTexFixJoint;  // offset: 0x80
        nDraw::Texture* mpTexFixWeight;  // offset: 0x88
        nDraw::Texture* mpTexFixNormal;  // offset: 0x90
    };
public:
    struct MtHalf4x2
    {
    public:
        MtHalf4 v0;  // offset: 0x0
        MtHalf4 v1;  // offset: 0x8
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
    uSimSoftBody();
    virtual ~uSimSoftBody();
    void clear();
    virtual void move();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 15
    void applyWorldOffsetGPU(cDraw* pdraw, u32 lodidx);
    void toLocalSpaceGPU(cDraw* pdraw, u32 lodidx);
    virtual void draw(cDraw* pdraw);  // vtable slot 12
    u32 callDrawPrim(cDraw* pdraw, u32 primIdx, u32 step);
    void callDraw(cDraw* pdraw);
    void callDrawModel(cDraw* pdraw, rModel* pmod, nDraw::Material* * pmaterials, const MtVector3& cpos, s32 basecullmask, s32 shadow_cullmask);
    void setDeformWeightMap(rDeformWeightMap* p);
    rDeformWeightMap* getDeformWeightMap();
    void setSPS(rSoundPhysicsSoftBody* p);
    rSoundPhysicsSoftBody* getSPS();
protected:
    void createSimData();
    void AccumulateForces();
    void broadPhaseCollision();
    u32 getHashIdx(const MtVector3&, f32, u32);
    void pointTriangleConstraint(MtVector3* argQ, MtVector3* argP1, MtVector3* argP2, MtVector3* argP3, f32 h, bool checkBackFace);
    f32 erf(f32 x);
    f32 p_gamma(f32 a, f32 x, f32 loggamma_a);
    f32 q_gamma(f32 a, f32 x, f32 loggamma_a);
    f32 gaussianDistribution(f32, f32, f32);
    f32 normGaussianDistribution(f32);
    void matrixToQuaternion(const MtFloat3x3& m, MtQuaternion& q);
    void matrixToQuaternion2(const MtFloat3x3& m, MtQuaternion& q);
    void quaternionToMatrix(const MtQuaternion& q, MtFloat3x3& m);
    f32 ReciprocalSqrt(f32 x);
    f32 normalPack(const MtFloat3&);
    f32 normalPack(const MtVector3& a);
    MtFloat3 normalUnpack(f32);
    f32 unsignedPack(const MtFloat3&);
    f32 unsignedPack(const MtVector3&);
    MtFloat3 unsignedUnpack(f32);
    void packU8U8(u8, u8, f32&);
    void unpackU8U8(f32, u8&, u8&);
    f32 packU8U8(u8 in1, u8 in2);
    void transferCpu2Gpu(nDraw::Texture* dst, void* src, s32 xPixel, s32 yLine, s32 pixelByte);
    void transferGpu2Cpu(void* dst, nDraw::Texture* src, s32 xPixel, s32 yLine, s32 pixelByte);
    void updateBounding();
    void colliderContactCallback(sCollision::CALLBACK_MODE mode, sCollision::Node* pThisNode, sCollision::Node* pNode, MtContact* pContact, u32 param, sCollision::TriangleInfo* pTriInfo, u32 HitGeomThisID, u32 HitGeomID, bool Hited);
    MtVector3 citeFGrassLocalWind(MtVector3&, MtVector4*, MtVector4*, MtVector4&);
    MtVector3 citeFGrassLocalWindPoint(MtVector3&, MtVector4*, MtVector4*, MtVector4&);
    MtVector3 citeFGrassLocalWindDirection(MtVector3&, MtVector4*, MtVector4*, MtVector4&);
    MtFloat2 citeFGrassSinCosCurve(f32);
    f32 lerp(f32, f32, f32);
    void getBarycentricCoordinates(const MtTriangle&, const MtVector3&, MtVector3&);
    uISC* getUnitISC();
    void setUnitISC(uISC* pUnit);
    void evRebuildSkinningData();
    void initGPU(cDraw* pdraw, u32 lodidx);
    void integrateGPU(cDraw* pdraw, u32 lodidx);
    void solveConstGPU(cDraw* pdraw, u32 lodidx);
    void solveConstIscGPU(cDraw* pdraw, u32 lodidx);
    void solveEdgeConstGPU2(cDraw* pdraw, u32 batch, u32 lodidx);
    void psSkinningGPU(cDraw* pdraw, u32 lodidx, u32 mode);
    void psSkinningAddPosGPU(cDraw* pdraw, u32 lodidx);
    void lodTransGPU(cDraw* pdraw, u32 lodidx_s, u32 lodidx_t);
    void createDepthNormGPU(cDraw* pdraw);
    void createApproxScrCollisionGPU(cDraw* pdraw);
public:
    uModel* getTargetUnit();
    void setTargetUnit(uModel* pTU);
    bool isEditMode();
    void restartSimulation(u32 loopNum);
    void enableResetRestart();
    void disableResetRestart();
    bool isResetRestart();
    void enableSimCulling();
    void disableSimCulling();
    void stopSimulation();
    void startSimulation(u32 loopNum);
    void evButtonStartSimulation();
    void evButtonStopSimulation();
    void enableGrassWind();
    void disableGrassWind();
    void enableDetailedGrassWind();
    void disableDetailedGrassWind();
    void enablePseudoGrassWind();
    void disablePseudoGrassWind();
    void setGrassWindScale(f32);
    void setGrassWindScalePoint(f32);
    void setGrassWindScaleDirection(f32 scale);
    f32 getGrassWindScale();
    f32 getGrassWindScalePoint();
    f32 getGrassWindScaleDirection();
    void setWeightOffset(f32);
    f32 getWeightOffset();
    void setWorldCoeffTrans(f32 WorldCoeffTrans);
    f32 getWorldCoeffTrans();
    void setWorldCoeffRot(f32 WorldCoeffRot);
    f32 getWorldCoeffRot();
    void setBaseJointNo(s32 baseJointNo);
    s32 getBaseJointNo();
    void enableLocalOnly();
    void disableLocalOnly();
    void setMaxIterate(u32);
    u32 getMaxIterate();
    void setAlpha(f32);
    f32 getAlpha();
    void setGravity(const MtVector3&);
    MtVector3 getGravity();
    void enableScrCollision();
    void disableScrCollision();
    void enableISCollision();
    void disableISCollision();
    void enableNCollision();
    void disableNCollision();
    void setNCGlobalWeight(f32 globalWeight);
    f32 getNCGlobalWeight();
    void setAvoidZFightLength(f32);
    f32 getAvoidZFightLength();
    void setVtxColSize(f32);
    f32 getVtxColSize();
    void enableApproxScrCollision();
    void disableApproxScrCollision();
    void enableColliderCollision();
    void disableColliderCollision();
    void setSbcType(u32 type);
    void setSbcFilter(u32 filter);
    void setColliderType(u32 type);
    void setWindGroupMask(u32);
    void setColliderFilter(u32);
    void setColliderCollision(bool flag);
    bool getColliderCollision();
    void setCullGeom(MtGeomConvex*);
    void disableCullGeom();
    void enableLOD();
    void disableLOD();
    void enable8Weight();
    void disable8Weight();
    void setRayDirection(const MtVector3&, u32);
    void setRayStartPosition(const MtVector3&, u32);
    void setRayRadius(f32, u32);
    void setRayPower(f32, u32);
    void setRayAttenuator(f32, u32);
private:
    void* memAlloc(u32 size, u32 align);
    void memFree(void* p_addr);
public:
    void rebuildSkinningData(nDraw::VertexBuffer* pVB, const rModel::PRIMITIVE_INFO* pprim);
    bool isProcessingRebuild();
protected:
    virtual void setNullTarget();  // vtable slot 24
    virtual bool hasTarget() const;  // vtable slot 25
    virtual bool isTargetEnable() const;  // vtable slot 26
    virtual nDraw::VertexBuffer* getTargetVertexBuffer() const;  // vtable slot 27
    virtual nDraw::IndexBuffer* getTargetIndexBuffer() const;  // vtable slot 28
    virtual const rModel::PRIMITIVE_INFO* getTargetPrimitives() const;  // vtable slot 29
    virtual u32 getTargetPrimitiveNum() const;  // vtable slot 30
    virtual u32 getTargetJointNum() const;  // vtable slot 31
    virtual bool isTargetPartsDisp(u32 no) const;  // vtable slot 32
    virtual const MtVector3& getTargetPos() const;  // vtable slot 33
    virtual MtVector3 calcTargetBaseCenterPos();  // vtable slot 34
    virtual u32 getTargetLODLevel(s32 dist);  // vtable slot 35
    virtual void setTargetPrimState(cDraw* pdraw, const rModel::PRIMITIVE_INFO* pp);  // vtable slot 36
    virtual const MtMatrix& getTargetJointMatrix(s32 jointIndex) const;  // vtable slot 37
    virtual const MtMatrix getTargetJointLocalMatrix(s32 jointIndex) const;  // vtable slot 38
    virtual s32 getTargetJointIndexFromNo(s32 no) const;  // vtable slot 39
    virtual s32 cullingTargetModel(cDraw* pdraw);  // vtable slot 40
    virtual void setTargetCommonState(cDraw* pdraw);  // vtable slot 41
    virtual void updateTargetBoundary();  // vtable slot 42
    virtual const MtSphere& getTargetBoundingSphere() const;  // vtable slot 43
    virtual void getTargetBoundingAABB(MtAABB& aabb) const;  // vtable slot 44
    virtual void getTargetTightBoundingAABB(MtAABB& aabb) const;  // vtable slot 45
    virtual void createSkinningMatrix(MtVector4* pdst, u32 jnt_num);  // vtable slot 46
    virtual bool isThisUnit(cUnit* punit);  // vtable slot 47
public:
    MtVector3 mWorldOffset;  // offset: 0x50
    bool mIsApplyWorldOffset;  // offset: 0x60
protected:
    u32 mNumParticles;  // offset: 0x64
    MtVector3* mpSwapX[3];  // offset: 0x68
    u32 mSwapPrev;  // offset: 0x80
    u32 mSwapCurr;  // offset: 0x84
    u32 mSwapNext;  // offset: 0x88
    MtVector3* mpA;  // offset: 0x90
    u32 mSimTriListNum;  // offset: 0x98
    u32 mConstraintsTail;  // offset: 0x9c
    u32 mSwapPrevCpu;  // offset: 0xa0
    u32 mSwapCurrCpu;  // offset: 0xa4
    u32 mSwapNextCpu;  // offset: 0xa8
    u32 mVtxListNum;  // offset: 0xac
    MtVector3* mpSkinX;  // offset: 0xb0
    rDeformWeightMap* mpResWeightMap;  // offset: 0xb8
    u32 mTriListNum;  // offset: 0xc0
    u32 mVbufNo;  // offset: 0xc4
    u32 mVbufNoCpuQuat;  // offset: 0xc8
    u32 mFrameCount;  // offset: 0xcc
    u32 mFrameCountCpuQuat;  // offset: 0xd0
    u32 mTblListNum;  // offset: 0xd4
    u32 mSkinListTail;  // offset: 0xd8
    bool mCallCreateApproxScrCollisionGPU;  // offset: 0xdc
public:
    f32 mAlpha;  // offset: 0xe0
    f32 mBeta;  // offset: 0xe4
    MtVector3 mGravity;  // offset: 0xf0
    f32 mTimeStep;  // offset: 0x100
    f32 mTimeStep2;  // offset: 0x104
    f32 mTimeStepSq;  // offset: 0x108
    f32 mOldTimeStep;  // offset: 0x10c
    f32 mDelta;  // offset: 0x110
    f32 mWeightOffset;  // offset: 0x114
    u32 mNumIterate;  // offset: 0x118
    u32 mMaxIterate;  // offset: 0x11c
    f32 mMaxStretch;  // offset: 0x120
    MtVector3 mBlowSpPos;  // offset: 0x130
    f32 mBlowSpRad;  // offset: 0x140
    f32 mMaxForce;  // offset: 0x144
    f32 mSphereFriction;  // offset: 0x148
    bool mWeightDisp;  // offset: 0x14c
    bool mCentroidConst;  // offset: 0x14d
    bool mSimON;  // offset: 0x14e
    bool mResetRestart;  // offset: 0x14f
    bool mSimCulling;  // offset: 0x150
    bool mIterateControlON;  // offset: 0x151
    bool mColTest;  // offset: 0x152
    bool mColMode;  // offset: 0x153
    bool mResUpdate;  // offset: 0x154
    bool mRecalcNormal;  // offset: 0x155
    bool mIsDbDisp;  // offset: 0x156
    f32 mSoundThreashold;  // offset: 0x158
    bool mEditSoundID;  // offset: 0x15c
    bool mSoundTrace;  // offset: 0x15d
    u32 mSoundID;  // offset: 0x160
    rSoundPhysicsSoftBody* mpResSPS;  // offset: 0x168
    cSoundPhysicsSoftBody* mpSound;  // offset: 0x170
    MtVector3 mPrevPos;  // offset: 0x180
    bool mSoundSkip;  // offset: 0x190
    u32 mDevelopDrawOffset;  // offset: 0x194
    f32 mDevelopDrawScale;  // offset: 0x198
    MtFloat4* mpSoundBuffer;  // offset: 0x1a0
protected:
    f32 mTimeAcc;  // offset: 0x1a8
    f32 mTimeAcc2;  // offset: 0x1ac
    u32 mVfrIterate;  // offset: 0x1b0
    u32 mVfrIterate2;  // offset: 0x1b4
    u32 mSwapCurrDraw;  // offset: 0x1b8
    bool mEnableVTF;  // offset: 0x1bc
    bool mEnableR2VB;  // offset: 0x1bd
    nDraw::Texture* mpTexPosFlagLink[3];  // offset: 0x1c0
    nDraw::Texture* mpTexFaceNormal;  // offset: 0x1d8
    nDraw::Texture* mpTexVtxNormal;  // offset: 0x1e0
    nDraw::Texture* mpTexVtxNormalBlend;  // offset: 0x1e8
    nDraw::Texture* mpTexOrgQuat;  // offset: 0x1f0
    nDraw::Texture* mpTexQuat;  // offset: 0x1f8
    nDraw::Texture* mpTexVtxNormalFlag;  // offset: 0x200
    LOCAL_PRIMITIVE_INFO* mpLocalPrimInfo;  // offset: 0x208
    nDraw::VertexBuffer* mpSoftBodyVB[3];  // offset: 0x210
    u32 mSoftBodyVBstride;  // offset: 0x228
    u32 mPriority;  // offset: 0x22c
    MtVector3* * mpPrimVtxPt[3];  // offset: 0x230
    u32 mPrimVtxNum;  // offset: 0x248
    nDraw::Texture* mpTexCpuQuat[3];  // offset: 0x250
    u32 mPrimTriNum;  // offset: 0x268
    u32 mCalcNormalInit;  // offset: 0x26c
    bool mCreatedSBBase;  // offset: 0x270
    u32 mSimState;  // offset: 0x274
    s32 mCullmask[4];  // offset: 0x278
    MtGeomConvex* mpCullGeom;  // offset: 0x288
    MtVector4* mpSkinningBuffer;  // offset: 0x290
    MtVector4* mpRebuildSkinningBuffer;  // offset: 0x298
    uModel* mpTargetUnit;  // offset: 0x2a0
    u32 mCallDrawCount;  // offset: 0x2a8
    bool mFlagPushCtx;  // offset: 0x2ac
    bool mApproxScrCollision;  // offset: 0x2ad
    bool mScrCollision;  // offset: 0x2ae
    bool mColliderCollision;  // offset: 0x2af
    bool mGrassWind;  // offset: 0x2b0
    bool mDetailedWind;  // offset: 0x2b1
    bool mPseudoWind;  // offset: 0x2b2
    MtVector3 mDetailWindHeading;  // offset: 0x2c0
    f32 mDetailWindStrength;  // offset: 0x2d0
    u32 mWindGroupMask;  // offset: 0x2d4
    MtVector3 mSbRayDirection0;  // offset: 0x2e0
    MtVector3 mSbRayStartPos0;  // offset: 0x2f0
    f32 mSbRayRadius0;  // offset: 0x300
    f32 mSbRayAttenuator0;  // offset: 0x304
    f32 mSbRayPower0;  // offset: 0x308
    MtVector3 mSbRayDirection1;  // offset: 0x310
    MtVector3 mSbRayStartPos1;  // offset: 0x320
    f32 mSbRayRadius1;  // offset: 0x330
    f32 mSbRayAttenuator1;  // offset: 0x334
    f32 mSbRayPower1;  // offset: 0x338
    u32 mSbcType;  // offset: 0x33c
    u32 mSbcFilter;  // offset: 0x340
    u32 mColliderType;  // offset: 0x344
    u32 mColliderFilter;  // offset: 0x348
    sCollision::Node* mpColliderNode;  // offset: 0x350
    MtGeomConvex* mpColliderGeoms[24];  // offset: 0x358
    u32 mIntersectedColliderNum;  // offset: 0x418
    MtGeomSphere mBounding;  // offset: 0x420
    f32 mWindScalePoint;  // offset: 0x440
    f32 mWindScaleDirection;  // offset: 0x444
    MtVector4 mDirectGrassWind[8];  // offset: 0x450
    f32 mDirectGrassWindStrength[8];  // offset: 0x4d0
    nDraw::Texture* mpTexColSphere[3];  // offset: 0x4f0
    u32 mColSphereListSize;  // offset: 0x508
    nDraw::Texture* mpTexColTriangle[3];  // offset: 0x510
    u32 mColTriangleListSize;  // offset: 0x528
    nDraw::Texture* mpTexColBox[3];  // offset: 0x530
    u32 mColBoxListSize;  // offset: 0x548
    nDraw::Texture* mpTexColEllipsoid[3];  // offset: 0x550
    u32 mColEllipsoidListSize;  // offset: 0x568
    nDraw::Texture* mpTexColCapsule[3];  // offset: 0x570
    u32 mColCapsuleListSize;  // offset: 0x588
    f32 mTerrainXMin;  // offset: 0x58c
    f32 mTerrainXUnit;  // offset: 0x590
    f32 mTerrainZMin;  // offset: 0x594
    f32 mTerrainZUnit;  // offset: 0x598
    u32 mTerrainNumSlices;  // offset: 0x59c
    nDraw::Texture* mpTexColTerrain[3];  // offset: 0x5a0
    u32 mColTerrainListSize;  // offset: 0x5b8
    bool mImageSpaceCollision;  // offset: 0x5bc
    MtMatrix mVP[8];  // offset: 0x5c0
    MtVector3 mViewVecInv[8];  // offset: 0x7c0
    MtMatrix mVP2[8];  // offset: 0x840
    MtVector3 mViewVecInv2[8];  // offset: 0xa40
    nDraw::Texture* mpTexColN[2];  // offset: 0xac0
    bool mNCollision;  // offset: 0xad0
    f32 mNCGlobalWeight;  // offset: 0xad4
    f32 mVtxColSize;  // offset: 0xad8
    f32 mAvoidZFight;  // offset: 0xadc
    bool mGHasTerrainTex;  // offset: 0xae0
    nDraw::Texture* mpTexSwapX[2][4];  // offset: 0xae8
    nDraw::Texture* mpTexConstDiff;  // offset: 0xb28
    nDraw::Texture* mpTexAccmDiff;  // offset: 0xb30
    nDraw::Texture* mpTexSkin[3];  // offset: 0xb38
    nDraw::Texture* mpTexSkin2[2][2];  // offset: 0xb50
    nDraw::Texture* mpTexDepthNorm[8];  // offset: 0xb70
    nDraw::Texture* mpTexFilterDepthNorm;  // offset: 0xbb0
    nDraw::Texture* mpDepthStencil;  // offset: 0xbb8
    u32 mSkinCurr;  // offset: 0xbc0
    f32 mExtrapolation;  // offset: 0xbc4
    f32 mExtraCoeff;  // offset: 0xbc8
    SoftBodyLWMatrix mLWMatrix;  // offset: 0xbd0
    MtMatrix mPrevMat;  // offset: 0xc90
    MtVector3 mPrevTrans;  // offset: 0xcd0
    MtQuaternion mPrevQuat;  // offset: 0xce0
    bool mLocalOnly;  // offset: 0xcf0
    uISC* mpISC;  // offset: 0xcf8
    LOD* mpLOD;  // offset: 0xd00
    u8 mNumLOD;  // offset: 0xd08
    MtHalf4x2* mpSpuFixPrimVtxNormal;  // offset: 0xd10
    MtFloat4* mpSpuFixJoint;  // offset: 0xd18
    MtFloat4* mpSpuFixWeight;  // offset: 0xd20
    MtHalf4x2* mpRebuildSpuFixPrimVtxNormal;  // offset: 0xd28
    MtFloat4* mpRebuildSpuFixJoint;  // offset: 0xd30
    MtFloat4* mpRebuildSpuFixWeight;  // offset: 0xd38
    LOCAL_PRIMITIVE_INFO* mpRebuildLocalPrimInfo;  // offset: 0xd40
    u32 mRebuildJointNum;  // offset: 0xd48
    MtMatrix mRebuildPrevMat;  // offset: 0xd50
    u32 mOldJointNum;  // offset: 0xd90
    bool mUseLOD;  // offset: 0xd94
    bool mUse16bit;  // offset: 0xd95
    bool mUse8Weight;  // offset: 0xd96
    u32 mCurrLOD;  // offset: 0xd98
    u32 mPrevLodIdx;  // offset: 0xd9c
    f32 mWorldCoeffTrans;  // offset: 0xda0
    f32 mWorldCoeffRot;  // offset: 0xda4
    s32 mBaseJointNo;  // offset: 0xda8
    u32 mRelaxationIterations;  // offset: 0xdac
    u32 mInitOk;  // offset: 0xdb0
    MtVector4* mpFixedOrgX;  // offset: 0xdb8
    bool mIsDeforming;  // offset: 0xdc0
    MtVector3 mWindData;  // offset: 0xdd0
    MtMatrix mApproxScrPj;  // offset: 0xde0
    MtVector3 mApproxScrPos;  // offset: 0xe20
    MtVector3 mApproxScrTgt;  // offset: 0xe30
    MtVector3 mApproxScrUp;  // offset: 0xe40
    MtVector3 mApproxScrExtent;  // offset: 0xe50
public:
    u32 mBuildState;  // offset: 0xe60
    static MyDTI DTI;
protected:
    static const u32 MAX_SOFTMODELVBUF = 3;
    static const u32 MAX_COLLIDER_NUM = 24;
    static const u32 TEX_WH = 128;
    static const u32 COL_MAX_NUM = 8;
    static const u32 TEX_DEPTH_NORM_SIZE = 32;
    static const u32 COL_TEX_SIZE = 64;
};

// Inline, no code of its own: checked where it is inlined.
inline void uSimSoftBody::enableResetRestart() {
    this->mResetRestart = true;
}
