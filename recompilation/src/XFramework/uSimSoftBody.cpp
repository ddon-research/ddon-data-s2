// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uSimSoftBody.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollision.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtGeomSphere.h"
#include "../MT/MtGeometry3D.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cDraw.h"
#include "cResource.h"
#include "cUnit.h"
#include "nCollisionNode.h"
#include "nDrawInputLayout.h"
#include "nDrawResource.h"
#include "nDrawTexture.h"
#include "nDrawVertexBuffer.h"
#include "rDeformWeightMap.h"
#include "rModel.h"
#include "sCollision.h"
#include "sMain.h"
#include "sRender.h"
#include "sScene.h"
#include "sShader2.h"
#include "sUnit.h"
#include "uBaseModel.h"
#include "uCoord.h"
#include "uGrassWind.h"
#include "uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uSimSoftBody::usage() {
}

const MtDTI& uSimSoftBody::getDTI() const {
    return uSimSoftBody::DTI;
}

void* uSimSoftBody::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uSimSoftBody::DTI)->memAlloc(sz, align, uSimSoftBody::DTI.mID);
}

uSimSoftBody::uSimSoftBody() {
    DDON_STUB("uSimSoftBody::uSimSoftBody")
    /* stub */
}

__attribute__((noinline)) uSimSoftBody::~uSimSoftBody() {
    DDON_STUB("uSimSoftBody::~uSimSoftBody")
    /* stub */
}

__attribute__((weak)) void uSimSoftBody::clear() {
    DDON_STUB("uSimSoftBody::clear")
    /* stub */
}

__attribute__((weak)) void uSimSoftBody::move() {
    DDON_STUB("uSimSoftBody::move")
    /* stub */
}

__attribute__((weak)) void uSimSoftBody::moveAfter() {
    DDON_STUB("uSimSoftBody::moveAfter")
    /* stub */
}

MtUI* uSimSoftBody::createUI(MtProperty& prop) {
    return this->cUnit::createUI(prop);
}

void uSimSoftBody::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mpTargetUnit", reinterpret_cast<MtObject* *>(&mpTargetUnit), 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRecalcNormal", &mRecalcNormal, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEnableVTF", &mEnableVTF, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEnableR2VB", &mEnableR2VB, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGrassWind", &mGrassWind, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDetailedWind", &mDetailedWind, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPseudoWind", &mPseudoWind, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWindScalePoint", &mWindScalePoint, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWindScaleDirection", &mWindScaleDirection, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWindGroupMask", &mWindGroupMask, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSbRayDirection0", &mSbRayDirection0, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSbRayStartPos0", &mSbRayStartPos0, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSbRayRadius0", &mSbRayRadius0, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSbRayPower0", &mSbRayPower0, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSbRayAttenuator0", &mSbRayAttenuator0, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSbRayDirection1", &mSbRayDirection1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSbRayStartPos1", &mSbRayStartPos1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSbRayRadius1", &mSbRayRadius1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSbRayPower1", &mSbRayPower1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSbRayAttenuator1", &mSbRayAttenuator1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColTest", &mColTest, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaxForce", &mMaxForce, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColMode", &mColMode, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBlowSpPos", &mBlowSpPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBlowSpRad", &mBlowSpRad, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSphereFriction", &mSphereFriction, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNCollision", &mNCollision, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNCGlobalWeight", &mNCGlobalWeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mImageSpaceCollision", &mImageSpaceCollision, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpISC", reinterpret_cast<MT_MFUNC>(&::uSimSoftBody::getUnitISC), reinterpret_cast<MT_MFUNC>(&::uSimSoftBody::setUnitISC), 144u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mApproxScrCollision", &mApproxScrCollision, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mScrCollision", &mScrCollision, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSbcType", &mSbcType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSbcFilter", &mSbcFilter, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mColliderCollision", reinterpret_cast<MT_MFUNC>(&::uSimSoftBody::getColliderCollision), reinterpret_cast<MT_MFUNC>(&::uSimSoftBody::setColliderCollision), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpColliderNode", reinterpret_cast<MtObject* *>(&mpColliderNode), 16u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColliderFilter", &mColliderFilter, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColliderType", &mColliderType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVtxColSize", &mVtxColSize, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAvoidZFight", &mAvoidZFight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpResWeightMap", "resource", reinterpret_cast<MT_MFUNC>(&::uSimSoftBody::getDeformWeightMap), reinterpret_cast<MT_MFUNC>(&::uSimSoftBody::setDeformWeightMap), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mSoundTrace", &mSoundTrace, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDevelopDrawScale", &mDevelopDrawScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDevelopDrawOffset", &mDevelopDrawOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpResSPS", "resource", reinterpret_cast<MT_MFUNC>(&::uSimSoftBody::getSPS), reinterpret_cast<MT_MFUNC>(&::uSimSoftBody::setSPS), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mSoundThreashold", &mSoundThreashold, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Rebuild Skinning Data", static_cast<MT_MFUNC>(&::uSimSoftBody::evRebuildSkinningData), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "Stop", static_cast<MT_MFUNC>(&::uSimSoftBody::evButtonStopSimulation), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "Start", static_cast<MT_MFUNC>(&::uSimSoftBody::evButtonStartSimulation), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "Simulation", &mSimON, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mResetRestart", &mResetRestart, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSimCulling", &mSimCulling, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Sim TimeStep", &mTimeStep, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAlpha", &mAlpha, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaxIterate", &mMaxIterate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGravity", &mGravity.x, 32u, 3u);
    s << MtProperty(static_cast<MtObject*>(this), "mWeightOffset", &mWeightOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsDbDisp", &mIsDbDisp, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSimState", &mSimState, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWorldCoeffTrans", &mWorldCoeffTrans, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWorldCoeffRot", &mWorldCoeffRot, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "BaseJointNo", &mBaseJointNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLocalOnly", &mLocalOnly, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpTexDepthNorm[0]", reinterpret_cast<MtObject* *>(&mpTexDepthNorm[0]), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpTexDepthNorm[1]", reinterpret_cast<MtObject* *>(&mpTexDepthNorm[1]), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpTexColTerrain[0]", reinterpret_cast<MtObject* *>(&mpTexColTerrain[0]), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUseLOD", &mUseLOD, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUse16bit", &mUse16bit, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUse8Weight", &mUse8Weight, 0u, 0u);
    this->cUnit::createProperty(s);
}

void uSimSoftBody::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    mWorldOffset = offset;
    mIsApplyWorldOffset = true;
}

__attribute__((weak)) void uSimSoftBody::toLocalSpaceGPU(cDraw* pdraw, u32 lodidx) {
    DDON_STUB("uSimSoftBody::toLocalSpaceGPU")
    /* stub */
}

__attribute__((weak)) void uSimSoftBody::draw(cDraw* pdraw) {
    DDON_STUB("uSimSoftBody::draw")
    /* stub */
}

__attribute__((weak)) u32 uSimSoftBody::callDrawPrim(cDraw* pdraw, u32 primIdx, u32 step) {
    DDON_STUB("uSimSoftBody::callDrawPrim")
    return {};
}

__attribute__((weak)) void uSimSoftBody::callDraw(cDraw* pdraw) {
    DDON_STUB("uSimSoftBody::callDraw")
    /* stub */
}

__attribute__((weak)) void uSimSoftBody::callDrawModel(cDraw* pdraw, rModel* pmod, nDraw::Material* * pmaterials, const MtVector3& cpos, s32 basecullmask, s32 shadow_cullmask) {
    DDON_STUB("uSimSoftBody::callDrawModel")
    /* stub */
}

__attribute__((weak)) void uSimSoftBody::setDeformWeightMap(rDeformWeightMap* p) {
    DDON_STUB("uSimSoftBody::setDeformWeightMap")
    /* stub */
}

static auto ddon_emit_0x01b64760 __attribute__((used)) = &uSimSoftBody::getDeformWeightMap;

__attribute__((weak)) void uSimSoftBody::setSPS(rSoundPhysicsSoftBody* p) {
    DDON_STUB("uSimSoftBody::setSPS")
    /* stub */
}

static auto ddon_emit_0x01b64770 __attribute__((used)) = &uSimSoftBody::getSPS;

__attribute__((weak)) void uSimSoftBody::createSimData() {
    DDON_STUB("uSimSoftBody::createSimData")
    /* stub */
}

__attribute__((weak)) void uSimSoftBody::broadPhaseCollision() {
    DDON_STUB("uSimSoftBody::broadPhaseCollision")
    /* stub */
}

void uSimSoftBody::colliderContactCallback(sCollision::CALLBACK_MODE mode, sCollision::Node* pThisNode, sCollision::Node* pNode, MtContact* pContact, u32 param, sCollision::TriangleInfo* pTriInfo, u32 HitGeomThisID, u32 HitGeomID, bool Hited) {
    if (mode != sCollision::PHASE_ENUM) {
        return;
    }
    MtGeomConvex* t0 = pNode->getGeometry(HitGeomID);
    mpColliderGeoms[mIntersectedColliderNum] = t0;
    mIntersectedColliderNum = ((mIntersectedColliderNum + 1u) <= 24u) ? (mIntersectedColliderNum + 1u) : 23u;
}

__attribute__((weak)) uISC* uSimSoftBody::getUnitISC() {
    DDON_STUB("uSimSoftBody::getUnitISC")
    return nullptr;
}

void uSimSoftBody::setUnitISC(uISC* pUnit) {
    mpISC = pUnit;
}

void uSimSoftBody::evRebuildSkinningData() {
    nDraw::VertexBuffer* t0 = getTargetVertexBuffer();
    rebuildSkinningData(t0, getTargetPrimitives());
}

__attribute__((weak)) void uSimSoftBody::initGPU(cDraw* pdraw, u32 lodidx) {
    DDON_STUB("uSimSoftBody::initGPU")
    /* stub */
}

__attribute__((weak)) void uSimSoftBody::integrateGPU(cDraw* pdraw, u32 lodidx) {
    DDON_STUB("uSimSoftBody::integrateGPU")
    /* stub */
}

__attribute__((weak)) void uSimSoftBody::solveConstGPU(cDraw* pdraw, u32 lodidx) {
    DDON_STUB("uSimSoftBody::solveConstGPU")
    /* stub */
}

__attribute__((weak)) void uSimSoftBody::solveConstIscGPU(cDraw* pdraw, u32 lodidx) {
    DDON_STUB("uSimSoftBody::solveConstIscGPU")
    /* stub */
}

__attribute__((weak)) void uSimSoftBody::solveEdgeConstGPU2(cDraw* pdraw, u32 batch, u32 lodidx) {
    DDON_STUB("uSimSoftBody::solveEdgeConstGPU2")
    /* stub */
}

__attribute__((weak)) void uSimSoftBody::psSkinningGPU(cDraw* pdraw, u32 lodidx, u32 mode) {
    DDON_STUB("uSimSoftBody::psSkinningGPU")
    /* stub */
}

__attribute__((weak)) void uSimSoftBody::psSkinningAddPosGPU(cDraw* pdraw, u32 lodidx) {
    DDON_STUB("uSimSoftBody::psSkinningAddPosGPU")
    /* stub */
}

__attribute__((weak)) void uSimSoftBody::createApproxScrCollisionGPU(cDraw* pdraw) {
    DDON_STUB("uSimSoftBody::createApproxScrCollisionGPU")
    /* stub */
}

void uSimSoftBody::setTargetUnit(uModel* pTU) {
    if (pTU->mpModel == nullptr) {
        return;
    }
    if ((pTU->mpModel->mAttr & 16u) == 0) {
        return;
    }
    if (mpResWeightMap == nullptr) {
        return;
    }
    if ((mpResWeightMap->mAttr & 16u) == 0) {
        return;
    }
    mpTargetUnit = pTU;
    createSimData();
}

void uSimSoftBody::restartSimulation(u32 loopNum) {
    applyWorldOffset(MtVector3::Zero, MtVector3::Zero);
    if (!mResetRestart) {
        if (loopNum == 0xFFFFFFFFu) {
            mInitOk = 0;
        }
    } else {
        mInitOk = 0;
    }
}

void uSimSoftBody::stopSimulation() {
    mSimON = false;
}

void uSimSoftBody::startSimulation(u32 loopNum) {
    if (mSimON) {
        return;
    }
    mSimON = true;
}

void uSimSoftBody::evButtonStartSimulation() {
    if (mSimON) {
        return;
    }
    mSimON = true;
}

void uSimSoftBody::evButtonStopSimulation() {
    mSimON = false;
}

void uSimSoftBody::enableApproxScrCollision() {
    mApproxScrCollision = true;
    mColTerrainListSize = 1;
    mCallCreateApproxScrCollisionGPU = true;
}

__attribute__((weak)) void uSimSoftBody::enableColliderCollision() {
    DDON_STUB("uSimSoftBody::enableColliderCollision")
    /* stub */
}

void uSimSoftBody::disableColliderCollision() {
    if (!mColliderCollision) {
        return;
    }
    if (mpColliderNode != nullptr) {
        delete mpColliderNode;
        mpColliderNode = nullptr;
    }
    mColliderCollision = false;
}

void uSimSoftBody::setColliderCollision(bool flag) {
    if (flag) {
        enableColliderCollision();
    } else {
        if (mColliderCollision) {
            if (mpColliderNode != nullptr) {
                delete mpColliderNode;
                mpColliderNode = nullptr;
            }
            mColliderCollision = false;
        }
    }
}

static auto ddon_emit_0x01b64700 __attribute__((used)) = &uSimSoftBody::getColliderCollision;

__attribute__((weak)) void uSimSoftBody::rebuildSkinningData(nDraw::VertexBuffer* pVB, const rModel::PRIMITIVE_INFO* pprim) {
    DDON_STUB("uSimSoftBody::rebuildSkinningData")
    /* stub */
}

void uSimSoftBody::setNullTarget() {
    mpTargetUnit = nullptr;
}

bool uSimSoftBody::hasTarget() const {
    if (mpTargetUnit != nullptr) {
        return mpTargetUnit->mpModel != nullptr;
    } else {
        return false;
    }
}

bool uSimSoftBody::isTargetEnable() const {
    return (mpTargetUnit->mBeFlag - 1u) <= 1u;
}

nDraw::VertexBuffer* uSimSoftBody::getTargetVertexBuffer() const {
    return mpTargetUnit->mpModel->mpVertexBuffer;
}

nDraw::IndexBuffer* uSimSoftBody::getTargetIndexBuffer() const {
    return mpTargetUnit->mpModel->mpIndexBuffer;
}

const rModel::PRIMITIVE_INFO* uSimSoftBody::getTargetPrimitives() const {
    return mpTargetUnit->mpModel->mPrimitiveInfo;
}

u32 uSimSoftBody::getTargetPrimitiveNum() const {
    return mpTargetUnit->mpModel->mPrimitiveNum;
}

u32 uSimSoftBody::getTargetJointNum() const {
    return mpTargetUnit->mJointNum;
}

bool uSimSoftBody::isTargetPartsDisp(u32 no) const {
    return ((static_cast<unsigned long>(mpTargetUnit->mPartsDisp[no >> 5]) >> static_cast<unsigned long>(no & 31u)) & 1ul) != 0;
}

const MtVector3& uSimSoftBody::getTargetPos() const {
    return mpTargetUnit->mPos;
}

MtVector3 uSimSoftBody::calcTargetBaseCenterPos() {
    return mpTargetUnit->calcBaseCenterPos();
}

u32 uSimSoftBody::getTargetLODLevel(s32 dist) {
    return mpTargetUnit->getLODLevel(dist);
}

void uSimSoftBody::setTargetPrimState(cDraw* pdraw, const rModel::PRIMITIVE_INFO* pp) {
    mpTargetUnit->setPrimState(pdraw, pp);
}

const MtMatrix& uSimSoftBody::getTargetJointMatrix(s32 jointIndex) const {
    if (jointIndex > -1) {
        return mpTargetUnit->mJoint[static_cast<unsigned int>(jointIndex)].mWmat;
    } else {
        return mpTargetUnit->mWmat;
    }
}

__attribute__((weak)) const MtMatrix uSimSoftBody::getTargetJointLocalMatrix(s32 jointIndex) const {
    DDON_STUB("uSimSoftBody::getTargetJointLocalMatrix")
    __builtin_unreachable();
}

s32 uSimSoftBody::getTargetJointIndexFromNo(s32 no) const {
    if (no > -1) {
        if (static_cast<int>(mpTargetUnit->mJointNum) >= static_cast<int>(mpTargetUnit->mJointTable[static_cast<unsigned char>(no)])) {
            return mpTargetUnit->mJointTable[static_cast<unsigned char>(no)];
        }
    }
    return -1;
}

s32 uSimSoftBody::cullingTargetModel(cDraw* pdraw) {
    return mpTargetUnit->cullingModel(pdraw);
}

void uSimSoftBody::setTargetCommonState(cDraw* pdraw) {
    mpTargetUnit->setCommonState(pdraw);
}

void uSimSoftBody::updateTargetBoundary() {
    mpTargetUnit->updateBoundary();
}

const MtSphere& uSimSoftBody::getTargetBoundingSphere() const {
    return mpTargetUnit->mBoundingSphere;
}

void uSimSoftBody::getTargetBoundingAABB(MtAABB& aabb) const {
    const MtSphere& t0 = getTargetBoundingSphere();
    const f32 t1 = t0.r;
    const f32 t2 = t0.pos.y;
    const f32 t3 = t0.pos.z;
    aabb.minpos.x = t0.pos.x - t1;
    aabb.minpos.y = t2 - t1;
    aabb.minpos.z = t3 - t1;
    aabb.minpos.pad_ = 0.0f;
    const f32 t4 = t0.pos.y;
    const f32 t5 = t0.pos.z;
    aabb.maxpos.x = t1 + t0.pos.x;
    aabb.maxpos.y = t1 + t4;
    aabb.maxpos.z = t1 + t5;
    aabb.maxpos.pad_ = 0.0f;
}

__attribute__((weak)) void uSimSoftBody::getTargetTightBoundingAABB(MtAABB& aabb) const {
    DDON_STUB("uSimSoftBody::getTargetTightBoundingAABB")
    /* stub */
}

__attribute__((weak)) void uSimSoftBody::createSkinningMatrix(MtVector4* pdst, u32 jnt_num) {
    DDON_STUB("uSimSoftBody::createSkinningMatrix")
    /* stub */
}

bool uSimSoftBody::isThisUnit(cUnit* punit) {
    if (punit != mpTargetUnit) {
        return punit == mpTargetUnit->mpParent;
    } else {
        return true;
    }
}

inline uSimSoftBody::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uSimSoftBody::MyDTI uSimSoftBody::DTI("uSimSoftBody", &::cUnit::DTI, 3696ul, 0u, 0u);

__attribute__((weak)) MtObject* uSimSoftBody::MyDTI::newInstance() const {
    DDON_STUB("uSimSoftBody::MyDTI::newInstance")
    return nullptr;
}

