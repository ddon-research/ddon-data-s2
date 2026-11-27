// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uFullbodyIKHumanDDO.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpIKCtrl.h"
#include "../../XFramework/rModel.h"
#include "../../XFramework/sResource.h"
#include "../../XFramework/sUnit.h"
#include "../../XFramework/uCnsIK.h"
#include "../../XFramework/uCnsLookAt.h"
#include "../../XFramework/uCnsMatrix.h"
#include "../../XFramework/uConstraint.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uFullbodyIKHumanDDO::getDTI() const {
    return uFullbodyIKHumanDDO::DTI;
}

void* uFullbodyIKHumanDDO::operator new(size_t sz, u32 align) {
    return uFullbodyIKHumanDDO::getAllocator()->memAlloc(sz, align, uFullbodyIKHumanDDO::DTI.getID());
}

uFullbodyIKHumanDDO::uFullbodyIKHumanDDO() {
    DDON_STUB("uFullbodyIKHumanDDO::uFullbodyIKHumanDDO")
    /* stub */
}

__attribute__((noinline)) uFullbodyIKHumanDDO::~uFullbodyIKHumanDDO() {
    DDON_STUB("uFullbodyIKHumanDDO::~uFullbodyIKHumanDDO")
    /* stub */
}

__attribute__((weak)) void uFullbodyIKHumanDDO::init(uModel* pModel, rFullbodyIKHuman2* pFBIKRes) {
    DDON_STUB("uFullbodyIKHumanDDO::init")
    /* stub */
}

__attribute__((weak)) void uFullbodyIKHumanDDO::assignJoint(u32 jnt_no, uFullbodyIKHumanDDO::FBIK_JOINT fbik_joint) {
    DDON_STUB("uFullbodyIKHumanDDO::assignJoint")
    /* stub */
}

void uFullbodyIKHumanDDO::setTargetModel(uModel* pModel) {
    if (pModel == nullptr) {
        return;
    }
    u32 t0 = sUnit::getInstance()->getMoveLineOrder(pModel->mMoveLine);
    if (t0 < sUnit::getInstance()->getMoveLineOrder(mMoveLine)) {
        mpTargetModel = pModel;
        if (mpResource != nullptr) {
            setResource(mpResource);
        }
    }
}

static auto ddon_emit_0x01ad7490 __attribute__((used)) = &uFullbodyIKHumanDDO::getTargetModel;

__attribute__((weak)) void uFullbodyIKHumanDDO::setResource(rFullbodyIKHuman2* pRes) {
    DDON_STUB("uFullbodyIKHumanDDO::setResource")
    /* stub */
}

static auto ddon_emit_0x01ad74a0 __attribute__((used)) = &uFullbodyIKHumanDDO::getResource;

void uFullbodyIKHumanDDO::setup() {
    init(mpTargetModel, mpResource);
}

void uFullbodyIKHumanDDO::move() {
    updateFullbodyIK();
}

__attribute__((weak)) void uFullbodyIKHumanDDO::moveAfter() {
}

__attribute__((weak)) void uFullbodyIKHumanDDO::kill() {
    DDON_STUB("uFullbodyIKHumanDDO::kill")
    /* stub */
}

__attribute__((weak)) void uFullbodyIKHumanDDO::draw(cDraw* pDraw) {
}

void uFullbodyIKHumanDDO::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpTargetModel", reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHumanDDO::getTargetModel), reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHumanDDO::setTargetModel), 144u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpResource", "resource", reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHumanDDO::getResource), reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHumanDDO::setResource), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
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
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "EffectorJoint", reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHumanDDO::getEffectorJoint), reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHumanDDO::setEffectorJoint), 160u, reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHumanDDO::getEffectorJointNum), reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHumanDDO::setEffectorJointNum));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "JointAssign", reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHumanDDO::getAssignedJoint), reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHumanDDO::setAssignedJoint), 161u, reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHumanDDO::getAssignedJointNum), reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHumanDDO::setAssignedJointNum));
    s << MtProperty(static_cast<MtObject*>(this), "mRArm", static_cast<MtObject*>(&mRArm), 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLArm", static_cast<MtObject*>(&mLArm), 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRLeg", static_cast<MtObject*>(&mRLeg), 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLLeg", static_cast<MtObject*>(&mLLeg), 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLookAt", static_cast<MtObject*>(&mLookAt), 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mState", &mState, 1u, 0u);
    this->uModel::createProperty(s);
}

MtUI* uFullbodyIKHumanDDO::createUI(MtProperty& prop) {
    return this->uModel::createUI(prop);
}

__attribute__((weak)) void uFullbodyIKHumanDDO::updateFullbodyIK() {
    if (mpTargetModel == nullptr) {
        return;
    }
    if (mpTargetModel->isEnable()) {
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

void uFullbodyIKHumanDDO::updateTargetModel(bool Update) {
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

uFullbodyIKHumanDDO::Node* uFullbodyIKHumanDDO::getNode(uFullbodyIKHumanDDO::FBIK_JOINT JointNo) {
    if (static_cast<int>(JointNo) <= 254) {
        if (static_cast<int>(JointNo) <= 9) {
            switch (JointNo) {
                case JT_CENTER:
                {
                    return &mNode[0];
                }
                case JT_UPPER_BODY:
                {
                    return &mNode[22];
                }
                case JT_CHEST:
                {
                    return &mNode[24];
                }
                case JT_LOWER_BODY:
                {
                    return &mNode[23];
                }
                default:
                {
                    return &mNode[26];
                }
            }
        } else {
            if (static_cast<int>(JointNo) <= 19) {
                switch (static_cast<unsigned int>(JointNo - 10)) {
                    case 0:
                    {
                        return &mNode[15];
                    }
                    case 1:
                    {
                        return &mNode[1];
                    }
                    case 2:
                    {
                        return &mNode[2];
                    }
                    case 3:
                    {
                        return &mNode[3];
                    }
                    default:
                    {
                        return &mNode[26];
                    }
                }
            } else {
                if (static_cast<int>(JointNo) <= 29) {
                    switch (static_cast<unsigned int>(JointNo - 20)) {
                        case 0:
                        {
                            return &mNode[16];
                        }
                        case 1:
                        {
                            return &mNode[4];
                        }
                        case 2:
                        {
                            return &mNode[5];
                        }
                        case 3:
                        {
                            return &mNode[6];
                        }
                        default:
                        {
                            return &mNode[26];
                        }
                    }
                } else {
                    if (static_cast<int>(JointNo) <= 39) {
                        if (JointNo != JT_RIGHT_THIGH) {
                            if (JointNo == JT_RIGHT_KNEE) {
                                return &mNode[8];
                            } else {
                                if (JointNo == JT_RIGHT_FOOT) {
                                    return &mNode[9];
                                } else {
                                    return &mNode[26];
                                }
                            }
                        } else {
                            return &mNode[7];
                        }
                    } else {
                        if (static_cast<int>(JointNo) <= 49) {
                            if (JointNo != JT_LEFT_THIGH) {
                                if (JointNo == JT_LEFT_KNEE) {
                                    return &mNode[11];
                                } else {
                                    if (JointNo == JT_LEFT_FOOT) {
                                        return &mNode[12];
                                    } else {
                                        return &mNode[26];
                                    }
                                }
                            } else {
                                return &mNode[10];
                            }
                        } else {
                            if (static_cast<int>(JointNo) <= 59) {
                                if (JointNo == JT_NECK) {
                                    return &mNode[14];
                                } else {
                                    if (JointNo == JT_HEAD) {
                                        return &mNode[13];
                                    } else {
                                        return &mNode[26];
                                    }
                                }
                            } else {
                                switch (static_cast<unsigned int>(JointNo - 60)) {
                                    case 0:
                                    {
                                        return &mNode[17];
                                    }
                                    case 1:
                                    {
                                        return &mNode[18];
                                    }
                                    case 2:
                                    {
                                        return &mNode[19];
                                    }
                                    case 3:
                                    {
                                        return &mNode[20];
                                    }
                                    case 4:
                                    {
                                        return &mNode[21];
                                    }
                                    case 10:
                                    {
                                        return &mNode[25];
                                    }
                                    default:
                                    {
                                        return &mNode[26];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        return &mNode[26];
    }
}

__attribute__((weak)) void uFullbodyIKHumanDDO::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uFullbodyIKHumanDDO::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) void uFullbodyIKHumanDDO::prepare() {
    DDON_STUB("uFullbodyIKHumanDDO::prepare")
    /* stub */
}

__attribute__((weak)) void uFullbodyIKHumanDDO::calc() {
    DDON_STUB("uFullbodyIKHumanDDO::calc")
    /* stub */
}

__attribute__((weak)) void uFullbodyIKHumanDDO::finish() {
    DDON_STUB("uFullbodyIKHumanDDO::finish")
    /* stub */
}

__attribute__((weak)) void uFullbodyIKHumanDDO::copyJointMatrix(uFullbodyIKHumanDDO::FBIK_JOINT_IDX fbik_jnt_idx, uFullbodyIKHumanDDO::FBIK_JOINT_IDX fbik_alt_jnt_idx) {
    DDON_STUB("uFullbodyIKHumanDDO::copyJointMatrix")
    /* stub */
}

__attribute__((weak)) void uFullbodyIKHumanDDO::setEffector(uFullbodyIKHumanDDO::Node* pNode) {
    DDON_STUB("uFullbodyIKHumanDDO::setEffector")
    /* stub */
}

u32 uFullbodyIKHumanDDO::getAssignedJointNum() {
    return 24;
}

__attribute__((weak)) void uFullbodyIKHumanDDO::setAssignedJointNum(u32 n) {
}

uFullbodyIKHumanDDO::Node* uFullbodyIKHumanDDO::getAssignedJoint(u32 idx) {
    return &mNode[idx];
}

__attribute__((weak)) void uFullbodyIKHumanDDO::setAssignedJoint(uFullbodyIKHumanDDO::Node* node, u32 idx) {
}

u32 uFullbodyIKHumanDDO::getEffectorJointNum() {
    return 6;
}

__attribute__((weak)) void uFullbodyIKHumanDDO::setEffectorJointNum(u32 n) {
}

uFullbodyIKHumanDDO::Node* uFullbodyIKHumanDDO::getEffectorJoint(u32 idx) {
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

__attribute__((weak)) void uFullbodyIKHumanDDO::setEffectorJoint(uFullbodyIKHumanDDO::Node* node, u32 idx) {
}

__attribute__((weak)) void uFullbodyIKHumanDDO::recomputeLocalMatrix() {
    DDON_STUB("uFullbodyIKHumanDDO::recomputeLocalMatrix")
    /* stub */
}

__attribute__((weak)) MtQuaternion uFullbodyIKHumanDDO::makeRotQuat(const MtVector3& start, const MtVector3& end, f32 blend) const {
    DDON_STUB("uFullbodyIKHumanDDO::makeRotQuat")
    __builtin_unreachable();
}

inline uFullbodyIKHumanDDO::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uFullbodyIKHumanDDO::MyDTI uFullbodyIKHumanDDO::DTI("uFullbodyIKHumanDDO", &::uModel::DTI, 43616ul, 0u, 0u);

__attribute__((weak)) MtObject* uFullbodyIKHumanDDO::MyDTI::newInstance() const {
    DDON_STUB("uFullbodyIKHumanDDO::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uFullbodyIKHumanDDO::Node::getDTI() const {
    return uFullbodyIKHumanDDO::Node::DTI;
}

void uFullbodyIKHumanDDO::Node::createProperty(MtPropertyList& s) {
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

MtUI* uFullbodyIKHumanDDO::Node::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline uFullbodyIKHumanDDO::Node::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uFullbodyIKHumanDDO::Node::MyDTI uFullbodyIKHumanDDO::Node::DTI("uFullbodyIKHumanDDO::Node", &::MtObject::DTI, 272ul, 0u, 0u);

MtObject* uFullbodyIKHumanDDO::Node::MyDTI::newInstance() const {
    return new (16u) uFullbodyIKHumanDDO::Node;
}

const MtDTI& uFullbodyIKHumanDDO::uCnsUpVectorCalc::getDTI() const {
    return uFullbodyIKHumanDDO::uCnsUpVectorCalc::DTI;
}

uFullbodyIKHumanDDO::uCnsUpVectorCalc::~uCnsUpVectorCalc() {
}

__attribute__((weak)) void uFullbodyIKHumanDDO::uCnsUpVectorCalc::draw(cDraw* pDraw) {
}

__attribute__((weak)) void uFullbodyIKHumanDDO::uCnsUpVectorCalc::setResource(cResource* pRes) {
}

cResource* uFullbodyIKHumanDDO::uCnsUpVectorCalc::getResource() {
    return nullptr;
}

void uFullbodyIKHumanDDO::uCnsUpVectorCalc::createProperty(MtPropertyList& s) {
    this->uConstraint::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "Joint", reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHumanDDO::uCnsUpVectorCalc::getJoint), reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHumanDDO::uCnsUpVectorCalc::setJointForProperty), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mJoint", &mJoint, 1u, 0u);
}

MtUI* uFullbodyIKHumanDDO::uCnsUpVectorCalc::createUI(MtProperty& prop) {
    return this->uConstraint::createUI(prop);
}

static auto ddon_emit_0x01ad7410 __attribute__((used)) = &uFullbodyIKHumanDDO::uCnsUpVectorCalc::getJoint;

__attribute__((weak)) void uFullbodyIKHumanDDO::uCnsUpVectorCalc::adjust(uModel::Joint* pJnt, uModel* pModel) {
    DDON_STUB("uFullbodyIKHumanDDO::uCnsUpVectorCalc::adjust")
    /* stub */
}

void uFullbodyIKHumanDDO::uCnsUpVectorCalc::remove() {
    removeConstraint();
}

void uFullbodyIKHumanDDO::uCnsUpVectorCalc::update() {
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

void uFullbodyIKHumanDDO::uCnsUpVectorCalc::setJointForProperty(u32 JntNo) {
    mJoint = JntNo;
    if (getModel() == nullptr) {
        return;
    }
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

inline uFullbodyIKHumanDDO::uCnsUpVectorCalc::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uFullbodyIKHumanDDO::uCnsUpVectorCalc::MyDTI uFullbodyIKHumanDDO::uCnsUpVectorCalc::DTI("uFullbodyIKHumanDDO::uCnsUpVectorCalc", &::uConstraint::DTI, 176ul, 0u, 2u);

MtObject* uFullbodyIKHumanDDO::uCnsUpVectorCalc::MyDTI::newInstance() const {
    return new (16u) uFullbodyIKHumanDDO::uCnsUpVectorCalc;
}

const MtDTI& uFullbodyIKHumanDDO::uCnsFBIKMatrix::getDTI() const {
    return uFullbodyIKHumanDDO::uCnsFBIKMatrix::DTI;
}

uFullbodyIKHumanDDO::uCnsFBIKMatrix::~uCnsFBIKMatrix() {
    removeConstraint();
}

__attribute__((weak)) void uFullbodyIKHumanDDO::uCnsFBIKMatrix::draw(cDraw* pDraw) {
}

__attribute__((weak)) void uFullbodyIKHumanDDO::uCnsFBIKMatrix::setResource(cResource* pRes) {
}

cResource* uFullbodyIKHumanDDO::uCnsFBIKMatrix::getResource() {
    return nullptr;
}

void uFullbodyIKHumanDDO::uCnsFBIKMatrix::createProperty(MtPropertyList& s) {
    this->uConstraint::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "Joint", reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHumanDDO::uCnsFBIKMatrix::getJoint), reinterpret_cast<MT_MFUNC>(&::uFullbodyIKHumanDDO::uCnsFBIKMatrix::setJointForProperty), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mMat", &mMat, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJoint", &mJoint, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFBIKJntNo", &mFBIKJntNo, 1u, 0u);
}

MtUI* uFullbodyIKHumanDDO::uCnsFBIKMatrix::createUI(MtProperty& prop) {
    return this->uConstraint::createUI(prop);
}

static auto ddon_emit_0x01ad73a0 __attribute__((used)) = &uFullbodyIKHumanDDO::uCnsFBIKMatrix::getJoint;

__attribute__((weak)) void uFullbodyIKHumanDDO::uCnsFBIKMatrix::adjust(uModel::Joint* pJnt, uModel* pModel) {
    DDON_STUB("uFullbodyIKHumanDDO::uCnsFBIKMatrix::adjust")
    /* stub */
}

void uFullbodyIKHumanDDO::uCnsFBIKMatrix::remove() {
    removeConstraint();
}

void uFullbodyIKHumanDDO::uCnsFBIKMatrix::update() {
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

void uFullbodyIKHumanDDO::uCnsFBIKMatrix::setJointForProperty(u32 JntNo) {
    mJoint = JntNo;
    if (getModel() == nullptr) {
        return;
    }
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

inline uFullbodyIKHumanDDO::uCnsFBIKMatrix::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uFullbodyIKHumanDDO::uCnsFBIKMatrix::MyDTI uFullbodyIKHumanDDO::uCnsFBIKMatrix::DTI("uFullbodyIKHumanDDO::uCnsFBIKMatrix", &::uConstraint::DTI, 256ul, 0u, 2u);

MtObject* uFullbodyIKHumanDDO::uCnsFBIKMatrix::MyDTI::newInstance() const {
    return new (16u) uFullbodyIKHumanDDO::uCnsFBIKMatrix;
}

