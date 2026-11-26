// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uFullbodyIKHuman2.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cResource.h"
#include "cUnit.h"
#include "rModel.h"
#include "sResource.h"
#include "sUnit.h"
#include "uCnsIK.h"
#include "uCnsLookAt.h"
#include "uCnsMatrix.h"
#include "uConstraint.h"
#include "uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uFullbodyIKHuman2::usage() {
}

const MtDTI& uFullbodyIKHuman2::getDTI() const {
    return uFullbodyIKHuman2::DTI;
}

void* uFullbodyIKHuman2::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uFullbodyIKHuman2::DTI)->memAlloc(sz, align, uFullbodyIKHuman2::DTI.mID);
}

inline void uFullbodyIKHuman2::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uFullbodyIKHuman2::DTI)->memFree(p_addr);
}

uFullbodyIKHuman2::uFullbodyIKHuman2() {
    DDON_STUB("uFullbodyIKHuman2::uFullbodyIKHuman2")
    /* stub */
}

__attribute__((noinline)) uFullbodyIKHuman2::~uFullbodyIKHuman2() {
    DDON_STUB("uFullbodyIKHuman2::~uFullbodyIKHuman2")
    /* stub */
}

__attribute__((weak)) void uFullbodyIKHuman2::init(uModel* pModel, rFullbodyIKHuman2* pFBIKRes) {
    DDON_STUB("uFullbodyIKHuman2::init")
    /* stub */
}

__attribute__((weak)) void uFullbodyIKHuman2::assignJoint(u32 jnt_no, uFullbodyIKHuman2::FBIK_JOINT fbik_joint) {
    DDON_STUB("uFullbodyIKHuman2::assignJoint")
    /* stub */
}

void uFullbodyIKHuman2::setTargetModel(uModel* pModel) {
    if (pModel == nullptr) {
        return;
    }
    u32 t0 = (sUnit::mpInstance)->getMoveLineOrder(pModel->mMoveLine);
    if (t0 < (sUnit::mpInstance)->getMoveLineOrder(mMoveLine)) {
        mpTargetModel = pModel;
        if (mpResource != nullptr) {
            setResource(mpResource);
        }
    }
}

static auto ddon_emit_0x01b5f450 __attribute__((used)) = &uFullbodyIKHuman2::getTargetModel;

__attribute__((weak)) void uFullbodyIKHuman2::setResource(rFullbodyIKHuman2* pRes) {
    DDON_STUB("uFullbodyIKHuman2::setResource")
    /* stub */
}

static auto ddon_emit_0x01b5f460 __attribute__((used)) = &uFullbodyIKHuman2::getResource;

void uFullbodyIKHuman2::setup() {
    init(mpTargetModel, mpResource);
}

void uFullbodyIKHuman2::move() {
    updateFullbodyIK();
}

__attribute__((weak)) void uFullbodyIKHuman2::moveAfter() {
}

__attribute__((weak)) void uFullbodyIKHuman2::kill() {
    DDON_STUB("uFullbodyIKHuman2::kill")
    /* stub */
}

__attribute__((weak)) void uFullbodyIKHuman2::draw(cDraw* pDraw) {
}

void uFullbodyIKHuman2::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpTargetModel", reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHuman2::getTargetModel), reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHuman2::setTargetModel), 144u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpResource", "resource", reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHuman2::getResource), reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHuman2::setResource), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mPri", &mPri, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIteration", &mIteration, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUpperBodyRotRate", &mUpperBodyRotRate, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUpperBodyTransRate", &mUpperBodyTransRate, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUpperBodySyncRate", &mUpperBodySyncRate, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLowerBodyRotRate", &mLowerBodyRotRate, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLowerBodyTransRate", &mLowerBodyTransRate, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLowerBodySyncRate", &mLowerBodySyncRate, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHeadLookAtRate", &mHeadLookAtRate, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUpperBodyLookAtRate", &mUpperBodyLookAtRate, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLowerBodyLookAtRate", &mLowerBodyLookAtRate, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWaistHeightLimit", &mWaistHeightLimit, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpineHandleLength", &mSpineHandleLength, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRCollarRotBlend", &mRCollarRotBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLCollarRotBlend", &mLCollarRotBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRCollarUpBlend", &mRCollarUpBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRCollarDownBlend", &mRCollarDownBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRCollarFrontBlend", &mRCollarFrontBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRCollarBackBlend", &mRCollarBackBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLCollarUpBlend", &mLCollarUpBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLCollarDownBlend", &mLCollarDownBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLCollarFrontBlend", &mLCollarFrontBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLCollarBackBlend", &mLCollarBackBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUseSpineRot", &mUseSpineRot, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpineUpperRotRate", &mSpineUpperRotRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpine0RotRate", &mSpine0RotRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpine1RotRate", &mSpine1RotRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpine2RotRate", &mSpine2RotRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpine3RotRate", &mSpine3RotRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpine4RotRate", &mSpine4RotRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLookAtWorldCoordRot", &mLookAtWorldCoordRot, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUpdateTargetModel", &mUpdateTargetModel, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "EffectorJoint", reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHuman2::getEffectorJoint), reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHuman2::setEffectorJoint), 160u, reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHuman2::getEffectorJointNum), reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHuman2::setEffectorJointNum));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "JointAssign", reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHuman2::getAssignedJoint), reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHuman2::setAssignedJoint), 161u, reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHuman2::getAssignedJointNum), reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHuman2::setAssignedJointNum));
    s << MtProperty(static_cast<MtObject*>(this), "mRArm", static_cast<MtObject*>(&mRArm), 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLArm", static_cast<MtObject*>(&mLArm), 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRLeg", static_cast<MtObject*>(&mRLeg), 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLLeg", static_cast<MtObject*>(&mLLeg), 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLookAt", static_cast<MtObject*>(&mLookAt), 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mState", &mState, 1u, 0u);
    this->uModel::createProperty(s);
}

MtUI* uFullbodyIKHuman2::createUI(MtProperty& prop) {
    return this->uModel::createUI(prop);
}

__attribute__((weak)) void uFullbodyIKHuman2::updateFullbodyIK() {
    if (mpTargetModel == nullptr) {
        return;
    }
    if ((mpTargetModel->mBeFlag - 1u) <= 1u) {
        if (mNode[0].mAssigned) {
            if (mNode[1].mAssigned) {
                if (mNode[2].mAssigned) {
                    if (mNode[3].mAssigned) {
                        if (mNode[4].mAssigned) {
                            if (mNode[5].mAssigned) {
                                if (mNode[6].mAssigned) {
                                    if (mNode[7].mAssigned) {
                                        if (mNode[8].mAssigned) {
                                            if (mNode[9].mAssigned) {
                                                if (mNode[10].mAssigned) {
                                                    if (mNode[11].mAssigned) {
                                                        if (mNode[12].mAssigned) {
                                                            (&mUpperBody)->move();
                                                            (&mLowerBody)->move();
                                                            (&mCenter)->move();
                                                            (&mRArm)->move();
                                                            (&mLArm)->move();
                                                            (&mRLeg)->move();
                                                            (&mLLeg)->move();
                                                            (&mRHand)->move();
                                                            (&mLHand)->move();
                                                            (&mRFoot)->move();
                                                            (&mLFoot)->move();
                                                            mLookAt.uCnsLookAt::move();
                                                            (&mRCollar)->move();
                                                            (&mLCollar)->move();
                                                            prepare();
                                                            calc();
                                                            finish();
                                                            updateTargetModel(mUpdateTargetModel);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void uFullbodyIKHuman2::updateTargetModel(bool Update) {
    if (Update) {
        mCnsFBIKMatrix[0].mEnable = true;
        mCnsFBIKMatrix[1].mEnable = true;
        mCnsFBIKMatrix[2].mEnable = true;
        mCnsFBIKMatrix[3].mEnable = true;
        mCnsFBIKMatrix[4].mEnable = true;
        mCnsFBIKMatrix[5].mEnable = true;
        mCnsFBIKMatrix[6].mEnable = true;
        mCnsFBIKMatrix[7].mEnable = true;
        mCnsFBIKMatrix[8].mEnable = true;
        mCnsFBIKMatrix[9].mEnable = true;
        mCnsFBIKMatrix[10].mEnable = true;
        mCnsFBIKMatrix[11].mEnable = true;
        mCnsFBIKMatrix[12].mEnable = true;
        mCnsFBIKMatrix[13].mEnable = true;
        mCnsFBIKMatrix[14].mEnable = true;
        mCnsFBIKMatrix[15].mEnable = true;
        mCnsFBIKMatrix[16].mEnable = true;
        mCnsFBIKMatrix[17].mEnable = true;
        mCnsFBIKMatrix[18].mEnable = true;
        mCnsFBIKMatrix[19].mEnable = true;
        mCnsFBIKMatrix[20].mEnable = true;
        mCnsFBIKMatrix[21].mEnable = true;
        mCnsFBIKMatrix[22].mEnable = true;
        mCnsFBIKMatrix[23].mEnable = true;
        mCnsFBIKMatrix[24].mEnable = true;
        mCnsFBIKMatrix[25].mEnable = true;
        mCnsFBIKMatrix[26].mEnable = true;
        mpTargetModel->updateWorldMatrix();
    }
    mCnsFBIKMatrix[0].mEnable = false;
    mCnsFBIKMatrix[1].mEnable = false;
    mCnsFBIKMatrix[2].mEnable = false;
    mCnsFBIKMatrix[3].mEnable = false;
    mCnsFBIKMatrix[4].mEnable = false;
    mCnsFBIKMatrix[5].mEnable = false;
    mCnsFBIKMatrix[6].mEnable = false;
    mCnsFBIKMatrix[7].mEnable = false;
    mCnsFBIKMatrix[8].mEnable = false;
    mCnsFBIKMatrix[9].mEnable = false;
    mCnsFBIKMatrix[10].mEnable = false;
    mCnsFBIKMatrix[11].mEnable = false;
    mCnsFBIKMatrix[12].mEnable = false;
    mCnsFBIKMatrix[13].mEnable = false;
    mCnsFBIKMatrix[14].mEnable = false;
    mCnsFBIKMatrix[15].mEnable = false;
    mCnsFBIKMatrix[16].mEnable = false;
    mCnsFBIKMatrix[17].mEnable = false;
    mCnsFBIKMatrix[18].mEnable = false;
    mCnsFBIKMatrix[19].mEnable = false;
    mCnsFBIKMatrix[20].mEnable = false;
    mCnsFBIKMatrix[21].mEnable = false;
    mCnsFBIKMatrix[22].mEnable = false;
    mCnsFBIKMatrix[23].mEnable = false;
    mCnsFBIKMatrix[24].mEnable = false;
    mCnsFBIKMatrix[25].mEnable = false;
    mCnsFBIKMatrix[26].mEnable = false;
}

__attribute__((weak)) uFullbodyIKHuman2::FBIK_JOINT uFullbodyIKHuman2::getFBIKJointNoFromIndex(uFullbodyIKHuman2::FBIK_JOINT_IDX FBIKJntIdx) {
    FBIK_JOINT JntNo = JT_NULL;
    switch (FBIKJntIdx) {
    case IDX_CENTER:
        JntNo = JT_CENTER;
        break;
    case IDX_RIGHT_SHOULDER:
        JntNo = JT_RIGHT_SHOULDER;
        break;
    case IDX_RIGHT_ELBOW:
        JntNo = JT_RIGHT_ELBOW;
        break;
    case IDX_RIGHT_HAND:
        JntNo = JT_RIGHT_HAND;
        break;
    case IDX_LEFT_SHOULDER:
        JntNo = JT_LEFT_SHOULDER;
        break;
    case IDX_LEFT_ELBOW:
        JntNo = JT_LEFT_ELBOW;
        break;
    case IDX_LEFT_HAND:
        JntNo = JT_LEFT_HAND;
        break;
    case IDX_RIGHT_THIGH:
        JntNo = JT_RIGHT_THIGH;
        break;
    case IDX_RIGHT_KNEE:
        JntNo = JT_RIGHT_KNEE;
        break;
    case IDX_RIGHT_FOOT:
        JntNo = JT_RIGHT_FOOT;
        break;
    case IDX_LEFT_THIGH:
        JntNo = JT_LEFT_THIGH;
        break;
    case IDX_LEFT_KNEE:
        JntNo = JT_LEFT_KNEE;
        break;
    case IDX_LEFT_FOOT:
        JntNo = JT_LEFT_FOOT;
        break;
    case IDX_HEAD:
        JntNo = JT_HEAD;
        break;
    case IDX_NECK:
        JntNo = JT_NECK;
        break;
    case IDX_RIGHT_COLLAR:
        JntNo = JT_RIGHT_COLLAR;
        break;
    case IDX_LEFT_COLLAR:
        JntNo = JT_LEFT_COLLAR;
        break;
    case IDX_SPINE0:
        JntNo = JT_SPINE0;
        break;
    case IDX_SPINE1:
        JntNo = JT_SPINE1;
        break;
    case IDX_SPINE2:
        JntNo = JT_SPINE2;
        break;
    case IDX_SPINE3:
        JntNo = JT_SPINE3;
        break;
    case IDX_SPINE4:
        JntNo = JT_SPINE4;
        break;
    case IDX_UPPER_BODY:
        JntNo = JT_UPPER_BODY;
        break;
    case IDX_LOWER_BODY:
        JntNo = JT_LOWER_BODY;
        break;
    case IDX_CHEST:
        JntNo = JT_CHEST;
        break;
    case IDX_LOOK_AT:
        JntNo = JT_LOOK_AT;
        break;
    case IDX_NULL:
        JntNo = JT_NULL;
        break;
    default:
        break;
    }
    return JntNo;
}

__attribute__((weak)) uFullbodyIKHuman2::Node* uFullbodyIKHuman2::getNode(uFullbodyIKHuman2::FBIK_JOINT JointNo) {
    DDON_STUB("uFullbodyIKHuman2::getNode")
    return nullptr;
}

__attribute__((weak)) void uFullbodyIKHuman2::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uFullbodyIKHuman2::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) void uFullbodyIKHuman2::prepare() {
    DDON_STUB("uFullbodyIKHuman2::prepare")
    /* stub */
}

__attribute__((weak)) void uFullbodyIKHuman2::calc() {
    DDON_STUB("uFullbodyIKHuman2::calc")
    /* stub */
}

__attribute__((weak)) void uFullbodyIKHuman2::finish() {
    DDON_STUB("uFullbodyIKHuman2::finish")
    /* stub */
}

__attribute__((weak)) void uFullbodyIKHuman2::copyJointMatrix(uFullbodyIKHuman2::FBIK_JOINT_IDX fbik_jnt_idx, uFullbodyIKHuman2::FBIK_JOINT_IDX fbik_alt_jnt_idx) {
    DDON_STUB("uFullbodyIKHuman2::copyJointMatrix")
    /* stub */
}

__attribute__((weak)) void uFullbodyIKHuman2::setEffector(uFullbodyIKHuman2::Node* pNode) {
    DDON_STUB("uFullbodyIKHuman2::setEffector")
    /* stub */
}

u32 uFullbodyIKHuman2::getAssignedJointNum() {
    return 24;
}

__attribute__((weak)) void uFullbodyIKHuman2::setAssignedJointNum(u32 n) {
}

uFullbodyIKHuman2::Node* uFullbodyIKHuman2::getAssignedJoint(u32 idx) {
    return &mNode[idx];
}

__attribute__((weak)) void uFullbodyIKHuman2::setAssignedJoint(uFullbodyIKHuman2::Node* node, u32 idx) {
}

u32 uFullbodyIKHuman2::getEffectorJointNum() {
    return 6;
}

__attribute__((weak)) void uFullbodyIKHuman2::setEffectorJointNum(u32 n) {
}

uFullbodyIKHuman2::Node* uFullbodyIKHuman2::getEffectorJoint(u32 idx) {
    switch (idx) {
        case 0:
        {
            return &mNode[3];
        }
        case 1:
        {
            return &mNode[6];
        }
        case 2:
        {
            return &mNode[9];
        }
        case 3:
        {
            return &mNode[12];
        }
        case 4:
        {
            return &mNode[0];
        }
        case 5:
        {
            return &mNode[25];
        }
        default:
        {
            return nullptr;
        }
    }
}

__attribute__((weak)) void uFullbodyIKHuman2::setEffectorJoint(uFullbodyIKHuman2::Node* node, u32 idx) {
}

__attribute__((weak)) MtMatrix uFullbodyIKHuman2::makeRotMatrix(const MtVector3& v1, const MtVector3& v2, f32 rate) {
    DDON_STUB("uFullbodyIKHuman2::makeRotMatrix")
    __builtin_unreachable();
}

__attribute__((weak)) void uFullbodyIKHuman2::recomputeLocalMatrix() {
    DDON_STUB("uFullbodyIKHuman2::recomputeLocalMatrix")
    /* stub */
}

__attribute__((weak)) MtQuaternion uFullbodyIKHuman2::makeRotQuat(const MtVector3& start, const MtVector3& end, f32 blend) const {
    DDON_STUB("uFullbodyIKHuman2::makeRotQuat")
    __builtin_unreachable();
}

inline uFullbodyIKHuman2::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uFullbodyIKHuman2::MyDTI uFullbodyIKHuman2::DTI("uFullbodyIKHuman2", &::uModel::DTI, 43616ul, 0u, 0u);

__attribute__((weak)) MtObject* uFullbodyIKHuman2::MyDTI::newInstance() const {
    DDON_STUB("uFullbodyIKHuman2::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uFullbodyIKHuman2::Node::getDTI() const {
    return uFullbodyIKHuman2::Node::DTI;
}

inline void uFullbodyIKHuman2::Node::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uFullbodyIKHuman2::Node::DTI)->memFree(p_addr);
}

void uFullbodyIKHuman2::Node::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mActive", &mActive, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBlend", &mBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEff", &mEff, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWMat", &mWMat, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOrgMat", &mOrgMat, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJntNo", &mJntNo, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFBIKJntNo", &mFBIKJntNo, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAssigned", &mAssigned, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRotate", &mRotate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffOffset", &mEffOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpEffTgtModel", reinterpret_cast<MtObject* *>(&mpEffTgtModel), 16u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffTgtJntNo", &mEffTgtJntNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffTgtAlign", &mEffTgtAlign, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mResist", &mResist, 0u, 0u);
}

MtUI* uFullbodyIKHuman2::Node::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline uFullbodyIKHuman2::Node::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uFullbodyIKHuman2::Node::MyDTI uFullbodyIKHuman2::Node::DTI("uFullbodyIKHuman2::Node", &::MtObject::DTI, 272ul, 0u, 0u);

__attribute__((weak)) MtObject* uFullbodyIKHuman2::Node::MyDTI::newInstance() const {
    DDON_STUB("uFullbodyIKHuman2::Node::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uFullbodyIKHuman2::uCnsUpVectorCalc::getDTI() const {
    return uFullbodyIKHuman2::uCnsUpVectorCalc::DTI;
}

inline void uFullbodyIKHuman2::uCnsUpVectorCalc::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uFullbodyIKHuman2::uCnsUpVectorCalc::DTI)->memFree(p_addr);
}

uFullbodyIKHuman2::uCnsUpVectorCalc::~uCnsUpVectorCalc() {
}

__attribute__((weak)) void uFullbodyIKHuman2::uCnsUpVectorCalc::draw(cDraw* pDraw) {
}

__attribute__((weak)) void uFullbodyIKHuman2::uCnsUpVectorCalc::setResource(cResource* pRes) {
}

cResource* uFullbodyIKHuman2::uCnsUpVectorCalc::getResource() {
    return nullptr;
}

void uFullbodyIKHuman2::uCnsUpVectorCalc::createProperty(MtPropertyList& s) {
    this->uConstraint::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "Joint", reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHuman2::uCnsUpVectorCalc::getJoint), reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHuman2::uCnsUpVectorCalc::setJointForProperty), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mJoint", &mJoint, 1u, 0u);
}

MtUI* uFullbodyIKHuman2::uCnsUpVectorCalc::createUI(MtProperty& prop) {
    return this->uConstraint::createUI(prop);
}

static auto ddon_emit_0x01b5f3d0 __attribute__((used)) = &uFullbodyIKHuman2::uCnsUpVectorCalc::getJoint;

__attribute__((weak)) void uFullbodyIKHuman2::uCnsUpVectorCalc::adjust(uModel::Joint* pJnt, uModel* pModel) {
    DDON_STUB("uFullbodyIKHuman2::uCnsUpVectorCalc::adjust")
    /* stub */
}

void uFullbodyIKHuman2::uCnsUpVectorCalc::remove() {
    removeConstraint();
}

void uFullbodyIKHuman2::uCnsUpVectorCalc::update() {
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

void uFullbodyIKHuman2::uCnsUpVectorCalc::setJointForProperty(u32 JntNo) {
    mJoint = JntNo;
    if (getModel() == nullptr) {
        return;
    }
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

inline uFullbodyIKHuman2::uCnsUpVectorCalc::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uFullbodyIKHuman2::uCnsUpVectorCalc::MyDTI uFullbodyIKHuman2::uCnsUpVectorCalc::DTI("uFullbodyIKHuman2::uCnsUpVectorCalc", &::uConstraint::DTI, 176ul, 0u, 2u);

__attribute__((weak)) MtObject* uFullbodyIKHuman2::uCnsUpVectorCalc::MyDTI::newInstance() const {
    DDON_STUB("uFullbodyIKHuman2::uCnsUpVectorCalc::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uFullbodyIKHuman2::uCnsFBIKMatrix::getDTI() const {
    return uFullbodyIKHuman2::uCnsFBIKMatrix::DTI;
}

inline void uFullbodyIKHuman2::uCnsFBIKMatrix::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uFullbodyIKHuman2::uCnsFBIKMatrix::DTI)->memFree(p_addr);
}

uFullbodyIKHuman2::uCnsFBIKMatrix::~uCnsFBIKMatrix() {
    removeConstraint();
}

__attribute__((weak)) void uFullbodyIKHuman2::uCnsFBIKMatrix::draw(cDraw* pDraw) {
}

__attribute__((weak)) void uFullbodyIKHuman2::uCnsFBIKMatrix::setResource(cResource* pRes) {
}

cResource* uFullbodyIKHuman2::uCnsFBIKMatrix::getResource() {
    return nullptr;
}

void uFullbodyIKHuman2::uCnsFBIKMatrix::createProperty(MtPropertyList& s) {
    this->uConstraint::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "Joint", reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHuman2::uCnsFBIKMatrix::getJoint), reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHuman2::uCnsFBIKMatrix::setJointForProperty), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mMat", &mMat, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJoint", &mJoint, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFBIKJntNo", &mFBIKJntNo, 1u, 0u);
}

MtUI* uFullbodyIKHuman2::uCnsFBIKMatrix::createUI(MtProperty& prop) {
    return this->uConstraint::createUI(prop);
}

static auto ddon_emit_0x01b5f360 __attribute__((used)) = &uFullbodyIKHuman2::uCnsFBIKMatrix::getJoint;

__attribute__((weak)) void uFullbodyIKHuman2::uCnsFBIKMatrix::adjust(uModel::Joint* pJnt, uModel* pModel) {
    DDON_STUB("uFullbodyIKHuman2::uCnsFBIKMatrix::adjust")
    /* stub */
}

void uFullbodyIKHuman2::uCnsFBIKMatrix::remove() {
    removeConstraint();
}

void uFullbodyIKHuman2::uCnsFBIKMatrix::update() {
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

void uFullbodyIKHuman2::uCnsFBIKMatrix::setJointForProperty(u32 JntNo) {
    mJoint = JntNo;
    if (getModel() == nullptr) {
        return;
    }
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

inline uFullbodyIKHuman2::uCnsFBIKMatrix::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uFullbodyIKHuman2::uCnsFBIKMatrix::MyDTI uFullbodyIKHuman2::uCnsFBIKMatrix::DTI("uFullbodyIKHuman2::uCnsFBIKMatrix", &::uConstraint::DTI, 256ul, 0u, 2u);

__attribute__((weak)) MtObject* uFullbodyIKHuman2::uCnsFBIKMatrix::MyDTI::newInstance() const {
    DDON_STUB("uFullbodyIKHuman2::uCnsFBIKMatrix::MyDTI::newInstance")
    return nullptr;
}

