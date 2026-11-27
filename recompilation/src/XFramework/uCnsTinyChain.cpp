// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uCnsTinyChain.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollision.h"
#include "../MT/MtDTI.h"
#include "../MT/MtGeomCapsule.h"
#include "../MT/MtGeomSphere.h"
#include "../MT/MtGeometry3D.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cResource.h"
#include "nCollisionNode.h"
#include "rCnsTinyChain.h"
#include "sCollision.h"
#include "sMain.h"
#include "sScene.h"
#include "uCnsGroup.h"
#include "uConstraint.h"
#include "uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uCnsTinyChain::usage() {
}

const MtDTI& uCnsTinyChain::getDTI() const {
    return uCnsTinyChain::DTI;
}

void* uCnsTinyChain::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uCnsTinyChain::DTI)->memAlloc(sz, align, uCnsTinyChain::DTI.mID);
}

uCnsTinyChain::~uCnsTinyChain() {
    DDON_STUB("uCnsTinyChain::~uCnsTinyChain")
    /* stub */
}

void uCnsTinyChain::createProperty(MtPropertyList& s) {
    this->uCnsGroup::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mAttr", &mAttr, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGravityScaling", &mGravityScaling, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGlobalDamping", &mGlobalDamping, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGlobalTransForceCoef", &mGlobalTransForceCoef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpringScaling", &mSpringScaling, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWindScaling", &mWindScaling, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mReflectScaling", &mReflectScaling, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroundLevel", &mGroundLevel, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Restart", static_cast<MT_MFUNC>(&::uCnsTinyChain::restart), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "Warp", static_cast<MT_MFUNC>(&::uCnsTinyChain::warpChain), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "Reset Param", static_cast<MT_MFUNC>(&::uCnsTinyChain::resetChainParam), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "mStabilizeNum", &mStabilizeNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStepTime", &mStepTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSolveStrNum", &mSolveStrNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSolveAngNum", &mSolveAngNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSolveSelColNum", &mSolveSelColNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSolveChnColNum", &mSolveChnColNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSolveMdlColNum", &mSolveMdlColNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSolveScrColNum", &mSolveScrColNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Reset Depned", static_cast<MT_MFUNC>(&::uCnsTinyChain::reset), 10u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpModelCol", reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::getModelCol), reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::setModelCol), 144u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpModelColRes", "resource", reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::getModelColRes), reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::setModelColRes), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpTransParent", reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::getTransParent), reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::setTransParent), 144u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mTransParentMat", &mTransParentMat, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTransParentBlend", &mTransParentBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLocalWind", &mLocalWind, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWindNum", &mWindNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWindCycle", &mWindCycle[0], 32u, 5u);
    s << MtProperty(static_cast<MtObject*>(this), "mWindAmp", &mWindAmp[0], 32u, 5u);
}

MtUI* uCnsTinyChain::createUI(MtProperty& prop) {
    return this->uCnsGroup::createUI(prop);
}

void uCnsTinyChain::move() {
    if ((mAttr & 0x800000u) == 0) {
        this->uCnsGroup::move();
        if (mpModelCol != nullptr) {
            if ((mpModelCol->mBeFlag - 1u) > 1u) {
                mpModelCol = nullptr;
            }
        }
        if (mpTransParent != nullptr) {
            if ((mpTransParent->mBeFlag - 1u) > 1u) {
                mpTransParent = nullptr;
            }
        }
        if (mRestart == 2) {
            setConstraintEnable(true);
            mRestart = 0;
        } else {
            if (mRestart == 1) {
                setConstraintEnable(false);
                mRestart = 2;
            }
        }
        mPrevEnable = mEnable;
        registCollider();
    }
}

void uCnsTinyChain::moveAfter() {
    if (mpModel == nullptr) {
        return;
    }
    if ((mAttr & 0x10000000u) == 0) {
        return;
    }
    mAfterEnable = true;
    mpModel->updateWorldMatrix();
    mAfterEnable = false;
}

__attribute__((weak)) void uCnsTinyChain::draw(cDraw* pDraw) {
}

__attribute__((weak)) void uCnsTinyChain::applyWorldOffset(const MtVector3& offset, const MtVector3& abusolute_offset) {
    DDON_STUB("uCnsTinyChain::applyWorldOffset")
    /* stub */
}

void uCnsTinyChain::setResource(cResource* pRes) {
    if (pRes != nullptr) {
        const MtDTI& t0 = pRes->getDTI();
        MT_CTSTR v0_1 = rCnsTinyChain::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                setCnsTinyChainRes(static_cast<rCnsTinyChain*>(pRes));
                return;
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
    if (mpResource != nullptr) {
        mpResource->release();
        mpResource = nullptr;
    }
}

cResource* uCnsTinyChain::getResource() {
    return mpResource;
}

__attribute__((weak)) void uCnsTinyChain::setCnsTinyChainRes(rCnsTinyChain* pRes) {
    DDON_STUB("uCnsTinyChain::setCnsTinyChainRes")
    /* stub */
}

u32 uCnsTinyChain::getDependentJointNum() {
    return mDependJointNum;
}

uModel::Joint* uCnsTinyChain::getDependentJoint(u32 idx) {
    if (mpDependJoints[idx] != 0xFF) {
        uModel* t0 = getModel();
        return &t0->mJoint[mpDependJoints[idx]];
    } else {
        return nullptr;
    }
}

__attribute__((weak)) bool uCnsTinyChain::preupdate() {
    DDON_STUB("uCnsTinyChain::preupdate")
    return {};
}

__attribute__((weak)) void uCnsTinyChain::reset() {
    DDON_STUB("uCnsTinyChain::reset")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::adjustChain(uModel::Joint* pjnt, uModel* pmod) {
    DDON_STUB("uCnsTinyChain::adjustChain")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::warp(const MtMatrix& before, const MtMatrix& after) {
    DDON_STUB("uCnsTinyChain::warp")
    /* stub */
}

void uCnsTinyChain::warpChain() {
    mWarpFlag = true;
}

void uCnsTinyChain::restart() {
    mRestart = 1;
}

__attribute__((weak)) void uCnsTinyChain::setConstraintEnable(bool flg) {
    DDON_STUB("uCnsTinyChain::setConstraintEnable")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::resetChainParam() {
    DDON_STUB("uCnsTinyChain::resetChainParam")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::setModelColRes(rChainCol* pres) {
    DDON_STUB("uCnsTinyChain::setModelColRes")
    /* stub */
}

static auto ddon_emit_0x01b681e0 __attribute__((used)) = &uCnsTinyChain::getModelColRes;

void uCnsTinyChain::setModelCol(uModel* pModel) {
    mpModelCol = pModel;
    if (pModel != nullptr) {
        mModelColScale = pModel->mScale.y;
    } else {
        mModelColScale = 1.0f;
    }
}

static auto ddon_emit_0x01b681d0 __attribute__((used)) = &uCnsTinyChain::getModelCol;

void uCnsTinyChain::setTransParent(uModel* parent_model_ptr) {
    if (parent_model_ptr == mpTransParent) {
        return;
    }
    mpTransParent = parent_model_ptr;
    if (parent_model_ptr == nullptr) {
        return;
    }
    mTransParentMatOld.m[0].x = parent_model_ptr->mWmat.m[0].x;
    mTransParentMatOld.m[0].y = parent_model_ptr->mWmat.m[0].y;
    mTransParentMatOld.m[0].z = parent_model_ptr->mWmat.m[0].z;
    mTransParentMatOld.m[0].w = parent_model_ptr->mWmat.m[0].w;
    mTransParentMatOld.m[1].x = parent_model_ptr->mWmat.m[1].x;
    mTransParentMatOld.m[1].y = parent_model_ptr->mWmat.m[1].y;
    mTransParentMatOld.m[1].z = parent_model_ptr->mWmat.m[1].z;
    mTransParentMatOld.m[1].w = parent_model_ptr->mWmat.m[1].w;
    mTransParentMatOld.m[2].x = parent_model_ptr->mWmat.m[2].x;
    mTransParentMatOld.m[2].y = parent_model_ptr->mWmat.m[2].y;
    mTransParentMatOld.m[2].z = parent_model_ptr->mWmat.m[2].z;
    mTransParentMatOld.m[2].w = parent_model_ptr->mWmat.m[2].w;
    mTransParentMatOld.m[3].x = parent_model_ptr->mWmat.m[3].x;
    mTransParentMatOld.m[3].y = parent_model_ptr->mWmat.m[3].y;
    mTransParentMatOld.m[3].z = parent_model_ptr->mWmat.m[3].z;
    mTransParentMatOld.m[3].w = parent_model_ptr->mWmat.m[3].w;
}

static auto ddon_emit_0x01b681f0 __attribute__((used)) = &uCnsTinyChain::getTransParent;

__attribute__((weak)) uCnsGroup::cGroup* uCnsTinyChain::createGroup(u32 idx) {
    DDON_STUB("uCnsTinyChain::createGroup")
    return nullptr;
}

__attribute__((weak)) void uCnsTinyChain::resetGroupRef() {
    DDON_STUB("uCnsTinyChain::resetGroupRef")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::calcCost() {
    DDON_STUB("uCnsTinyChain::calcCost")
    /* stub */
}

__attribute__((weak)) const MtCapsule uCnsTinyChain::getCapsule(const nChain::ColInfo& data) {
    DDON_STUB("uCnsTinyChain::getCapsule")
    __builtin_unreachable();
}

__attribute__((weak)) const MtOBB uCnsTinyChain::getOBB(const nChain::ColInfo& data) {
    DDON_STUB("uCnsTinyChain::getOBB")
    __builtin_unreachable();
}

void uCnsTinyChain::registCollider() {
    if (mGroupNum != 0) {
        u32 v0_0 = mGroupNum;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            cChainGroup* t0 = mppChainGroups[i0_3];
            if (!t0->mIsReady) {
                v1_0 = v0_0;
            } else {
                if ((t0->mAttr & 32u) == 0) {
                    v1_0 = v0_0;
                } else {
                    t0->updateColliderNode();
                    (sCollision::mpInstance)->mCollider.sCollision::Collider::entryNode(&t0->mColNode, t0->mColType);
                    v1_0 = mGroupNum;
                }
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
}

__attribute__((weak)) void uCnsTinyChain::callBackObjectCollision(sCollision::CALLBACK_MODE Mode, sCollision::Node* pThisNode, sCollision::Node* pNode, MtContact* pContact, uintptr Param, sCollision::TriangleInfo* pTriInfo, u32 HitGeomThisID, u32 HitGeomID, bool Hited) {
    DDON_STUB("uCnsTinyChain::callBackObjectCollision")
    /* stub */
}

inline uCnsTinyChain::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCnsTinyChain::MyDTI uCnsTinyChain::DTI("uCnsTinyChain", &::uCnsGroup::DTI, 992ul, 0u, 0u);

__attribute__((weak)) MtObject* uCnsTinyChain::MyDTI::newInstance() const {
    DDON_STUB("uCnsTinyChain::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uCnsTinyChain::cChainGroup::getDTI() const {
    return uCnsTinyChain::cChainGroup::DTI;
}

uCnsTinyChain::cChainGroup::~cChainGroup() {
}

void uCnsTinyChain::cChainGroup::createProperty(MtPropertyList& s) {
    this->uCnsGroup::cGroup::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "AttrCollision", reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::cChainGroup::getAttrCollision), reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::cChainGroup::setAttrCollision), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "AttrForce", reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::cChainGroup::getAttrForce), reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::cChainGroup::setAttrForce), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mGravity", &mGravity, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDamping", &mDamping, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTransForceCoef", &mTransForceCoef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFrictionCoef", &mFrictionCoef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mReflectCoef", &mReflectCoef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpringCoef", &mSpringCoef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWindCoef", &mWindCoef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLimitForce", &mLimitForce, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColAttribute", &mColAttribute, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColGroup", &mColGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColType", &mColType, 0u, 0u);
}

MtUI* uCnsTinyChain::cChainGroup::createUI(MtProperty& prop) {
    return this->uCnsGroup::cGroup::createUI(prop);
}

__attribute__((weak)) void uCnsTinyChain::cChainGroup::init() {
    DDON_STUB("uCnsTinyChain::cChainGroup::init")
    /* stub */
}

void uCnsTinyChain::cChainGroup::reset() {
    mpCnsChain->reset();
}

u32 uCnsTinyChain::cChainGroup::getDependentJointNum(u32 idx) {
    if (idx != 0) {
        return 0;
    } else {
        return mpCnsGroup->getDependentJointNum();
    }
}

__attribute__((weak)) void uCnsTinyChain::cChainGroup::adjust(u32 idx, uModel::Joint* pJnt, uModel* pMod) {
    DDON_STUB("uCnsTinyChain::cChainGroup::adjust")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::cChainGroup::calcOffset() {
    DDON_STUB("uCnsTinyChain::cChainGroup::calcOffset")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::cChainGroup::updateNode() {
    DDON_STUB("uCnsTinyChain::cChainGroup::updateNode")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::cChainGroup::updateRotate() {
    DDON_STUB("uCnsTinyChain::cChainGroup::updateRotate")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::cChainGroup::resetParam() {
    DDON_STUB("uCnsTinyChain::cChainGroup::resetParam")
    /* stub */
}

__attribute__((weak)) uCnsGroup::cNode* uCnsTinyChain::cChainGroup::createNode(u32 idx) {
    DDON_STUB("uCnsTinyChain::cChainGroup::createNode")
    return nullptr;
}

__attribute__((weak)) void uCnsTinyChain::cChainGroup::resetNodeRef() {
    DDON_STUB("uCnsTinyChain::cChainGroup::resetNodeRef")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::cChainGroup::accumulateForce() {
    DDON_STUB("uCnsTinyChain::cChainGroup::accumulateForce")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::cChainGroup::solveFriction(const MtVector3& pos, MtVector3& old, const MtVector3& v) {
    DDON_STUB("uCnsTinyChain::cChainGroup::solveFriction")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::cChainGroup::solveReflect(const MtVector3& pos, MtVector3& old, const MtVector3& v) {
    DDON_STUB("uCnsTinyChain::cChainGroup::solveReflect")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::cChainGroup::solveStretch() {
    DDON_STUB("uCnsTinyChain::cChainGroup::solveStretch")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::cChainGroup::solveAngleLimit2() {
    DDON_STUB("uCnsTinyChain::cChainGroup::solveAngleLimit2")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::cChainGroup::subChainColSphere(uCnsTinyChain::cChainNode& node, uCnsTinyChain::cChainNode* * ppChainNodes, u32 startIdx, u32 num) {
    DDON_STUB("uCnsTinyChain::cChainGroup::subChainColSphere")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::cChainGroup::subChainColCapsule(uCnsTinyChain::cChainNode& node, uCnsTinyChain::cChainNode& nodeNext, uCnsTinyChain::cChainNode* * ppChainNodes, u32 startIdx, u32 num) {
    DDON_STUB("uCnsTinyChain::cChainGroup::subChainColCapsule")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::cChainGroup::modelColSphere(u32 idx) {
    DDON_STUB("uCnsTinyChain::cChainGroup::modelColSphere")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::cChainGroup::modelColCapsule(u32 idx) {
    DDON_STUB("uCnsTinyChain::cChainGroup::modelColCapsule")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::cChainGroup::solveScrollCollision() {
    DDON_STUB("uCnsTinyChain::cChainGroup::solveScrollCollision")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::cChainGroup::solveColliderCollision() {
    DDON_STUB("uCnsTinyChain::cChainGroup::solveColliderCollision")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::cChainGroup::dragCapsuleEx(uCnsTinyChain::cChainNode& node0, uCnsTinyChain::cChainNode& node1, f32 rsq, const MtVector3& drag, const MtVector3* pContactPos) {
    DDON_STUB("uCnsTinyChain::cChainGroup::dragCapsuleEx")
    /* stub */
}

__attribute__((weak)) void uCnsTinyChain::cChainGroup::updateColliderNode() {
    DDON_STUB("uCnsTinyChain::cChainGroup::updateColliderNode")
    /* stub */
}

static auto ddon_emit_0x01b68190 __attribute__((used)) = &uCnsTinyChain::cChainGroup::getAttrForce;

static auto ddon_emit_0x01b681a0 __attribute__((used)) = &uCnsTinyChain::cChainGroup::setAttrForce;

u32 uCnsTinyChain::cChainGroup::getAttrCollision() {
    return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 44);
}

__attribute__((weak)) void uCnsTinyChain::cChainGroup::setAttrCollision(u32 attr) {
    DDON_STUB("uCnsTinyChain::cChainGroup::setAttrCollision")
    /* stub */
}

inline uCnsTinyChain::cChainGroup::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCnsTinyChain::cChainGroup::MyDTI uCnsTinyChain::cChainGroup::DTI("uCnsTinyChain::cChainGroup", &::uCnsGroup::cGroup::DTI, 464ul, 0u, 0u);

__attribute__((weak)) MtObject* uCnsTinyChain::cChainGroup::MyDTI::newInstance() const {
    DDON_STUB("uCnsTinyChain::cChainGroup::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uCnsTinyChain::cChainNode::getDTI() const {
    return uCnsTinyChain::cChainNode::DTI;
}

uCnsTinyChain::cChainNode::cChainNode(uCnsTinyChain::cChainGroup* pChainGroup, u32 idx) {
    DDON_STUB("uCnsTinyChain::cChainNode::cChainNode")
    /* stub */
}

uCnsTinyChain::cChainNode::~cChainNode() {
}

void uCnsTinyChain::cChainNode::createProperty(MtPropertyList& s) {
    this->uCnsGroup::cNode::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mAttach", reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::cChainNode::getAttach), reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::cChainNode::setAttach), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mRotMode", reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::cChainNode::getRotMode), reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::cChainNode::setRotMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mRefJntNo", reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::cChainNode::getRefJointNo), reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::cChainNode::setRefJointNo), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mMat", &mMat, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mAttr", reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::cChainNode::getAttr), reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::cChainNode::setAttr), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mMass", &mMass, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mElasticCoef", &mElasticCoef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWindCoef", &mWindCoef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "ShapeObject", reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::cChainNode::getShapeObject), reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::cChainNode::setShapeObject), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "ShapeScroll", reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::cChainNode::getShapeScroll), reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::cChainNode::setShapeScroll), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mR", &mR, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mAngleMode", reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::cChainNode::getAngleMode), reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::cChainNode::setAngleMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mAngleLimit", reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::cChainNode::getAngleLimit), reinterpret_cast<MT_MFUNC>(&::uCnsTinyChain::cChainNode::setAngleLimit), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mAngleAxis", &mAngleAxis, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJointScale", &mJointScale, 1u, 0u);
}

MtUI* uCnsTinyChain::cChainNode::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

static auto ddon_emit_0x01b680e0 __attribute__((used)) = &uCnsTinyChain::cChainNode::setAttr;

static auto ddon_emit_0x01b680d0 __attribute__((used)) = &uCnsTinyChain::cChainNode::getAttr;

static auto ddon_emit_0x01b68080 __attribute__((used)) = &uCnsTinyChain::cChainNode::setAttach;

__attribute__((weak)) u32 uCnsTinyChain::cChainNode::getAttach() const {
    DDON_STUB("uCnsTinyChain::cChainNode::getAttach")
    return {};
}

static auto ddon_emit_0x01b680a0 __attribute__((used)) = &uCnsTinyChain::cChainNode::setRotMode;

static auto ddon_emit_0x01b68090 __attribute__((used)) = &uCnsTinyChain::cChainNode::getRotMode;

static auto ddon_emit_0x01b680c0 __attribute__((used)) = &uCnsTinyChain::cChainNode::setRefJointNo;

static auto ddon_emit_0x01b680b0 __attribute__((used)) = &uCnsTinyChain::cChainNode::getRefJointNo;

static auto ddon_emit_0x01b68140 __attribute__((used)) = &uCnsTinyChain::cChainNode::setAngleMode;

static auto ddon_emit_0x01b68130 __attribute__((used)) = &uCnsTinyChain::cChainNode::getAngleMode;

__attribute__((weak)) void uCnsTinyChain::cChainNode::setAngleLimit(f32 lim) {
    DDON_STUB("uCnsTinyChain::cChainNode::setAngleLimit")
    /* stub */
}

static auto ddon_emit_0x01b68150 __attribute__((used)) = &uCnsTinyChain::cChainNode::getAngleLimit;

void uCnsTinyChain::cChainNode::setShapeObject(u32 shape) {
    mShapeObject = shape;
    mpChainGroup->mResetColliderNode = true;
}

static auto ddon_emit_0x01b680f0 __attribute__((used)) = &uCnsTinyChain::cChainNode::getShapeObject;

static auto ddon_emit_0x01b68120 __attribute__((used)) = &uCnsTinyChain::cChainNode::setShapeScroll;

static auto ddon_emit_0x01b68110 __attribute__((used)) = &uCnsTinyChain::cChainNode::getShapeScroll;

inline uCnsTinyChain::cChainNode::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCnsTinyChain::cChainNode::MyDTI uCnsTinyChain::cChainNode::DTI("uCnsTinyChain::cChainNode", &::uCnsGroup::cNode::DTI, 432ul, 0u, 0u);

__attribute__((weak)) MtObject* uCnsTinyChain::cChainNode::MyDTI::newInstance() const {
    DDON_STUB("uCnsTinyChain::cChainNode::MyDTI::newInstance")
    return nullptr;
}

