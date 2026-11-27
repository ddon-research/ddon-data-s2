// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uCnsDDOIK.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cDelegate.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpIKCtrl.h"
#include "../../XFramework/rCnsIK.h"
#include "../../XFramework/sCollision.h"
#include "../../XFramework/uConstraint.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uCnsDDOIK::getDTI() const {
    return uCnsDDOIK::DTI;
}

void* uCnsDDOIK::operator new(size_t sz, u32 align) {
    return uCnsDDOIK::getAllocator()->memAlloc(sz, align, uCnsDDOIK::DTI.getID());
}

__attribute__((weak)) MtVector3 uCnsDDOIK::calcUpVectorArmR() {
    DDON_STUB("uCnsDDOIK::calcUpVectorArmR")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector3 uCnsDDOIK::calcUpVectorArmL() {
    DDON_STUB("uCnsDDOIK::calcUpVectorArmL")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector3 uCnsDDOIK::calcUpVectorLeg() {
    DDON_STUB("uCnsDDOIK::calcUpVectorLeg")
    __builtin_unreachable();
}

__attribute__((weak)) bool uCnsDDOIK::setupJointInfo(uModel* pModel, uCnsDDOIK::JointInfo* JointInfoTbl, s32 Num, uConstraint::DIRECTION DirVector, uConstraint::DIRECTION UpVector) {
    DDON_STUB("uCnsDDOIK::setupJointInfo")
    return {};
}

__attribute__((weak)) void uCnsDDOIK::calcLocalMatrix(uModel* pModel, uCnsDDOIK::JointInfo* JointInfoTbl, s32 Num) {
    DDON_STUB("uCnsDDOIK::calcLocalMatrix")
    /* stub */
}

__attribute__((weak)) void uCnsDDOIK::calc2BoneIK(uCnsDDOIK::JointInfo& JointInfo0, uCnsDDOIK::JointInfo& JointInfo1, uCnsDDOIK::JointInfo& JointInfo2, MtVector3& EffDir, MtMatrix& BaseIKMat, MtMatrix& LimitBaseMat) {
    DDON_STUB("uCnsDDOIK::calc2BoneIK")
    /* stub */
}

__attribute__((weak)) void uCnsDDOIK::calc3BoneIK(uCnsDDOIK::JointInfo& JointInfo0, uCnsDDOIK::JointInfo& JointInfo1, uCnsDDOIK::JointInfo& JointInfo2, uCnsDDOIK::JointInfo& JointInfo3, MtVector3& EffDir, MtMatrix& BaseIKMat, MtMatrix& LimitBaseMat) {
    DDON_STUB("uCnsDDOIK::calc3BoneIK")
    /* stub */
}

__attribute__((weak)) bool uCnsDDOIK::limitEffector(MtMatrix& BaseIKMat, MtVector3& EffDir, MtVector3& EffPos, MtVector3& EffUp, MtVector3* pLastVBase, const MtMatrix& BaseWMat, f32 PitchMin, f32 PitchMax, f32 RotMin, f32 RotMax, f32 DistMin, f32 DistMax) {
    DDON_STUB("uCnsDDOIK::limitEffector")
    return {};
}

__attribute__((weak)) bool uCnsDDOIK::limit(MtMatrix& Mat, const MtMatrix& PMat, f32 min, f32 max, MtVector3* pLastV) {
    DDON_STUB("uCnsDDOIK::limit")
    return {};
}

__attribute__((weak)) s32 uCnsDDOIK::checkGround(MtVector3& Pos, sCollision::TriangleInfo* pTriInfo) {
    DDON_STUB("uCnsDDOIK::checkGround")
    return {};
}

__attribute__((weak)) MtVector3 uCnsDDOIK::calcUpVectorArm(const MtVector3& InnerUpOffset, const MtVector3& OuterUpOffset, f32 ip_sign) {
    DDON_STUB("uCnsDDOIK::calcUpVectorArm")
    __builtin_unreachable();
}

__attribute__((noinline)) uCnsDDOIK::~uCnsDDOIK() {
    if (mpCnsIKRes == nullptr) {
        return;
    }
    mpCnsIKRes->release();
    mpCnsIKRes = nullptr;
}

MT_CTSTR uCnsDDOIK::getName() {
    if (mpCnsIKRes != nullptr) {
        return &mpCnsIKRes->mPath[0];
    } else {
        return this->cUnit::getName();
    }
}

MtUI* uCnsDDOIK::createUI(MtProperty& prop) {
    return this->uConstraint::createUI(prop);
}

void uCnsDDOIK::createProperty(MtPropertyList& s) {
    this->uConstraint::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mpCnsIKRes", "resource", reinterpret_cast<MT_MFUNC>(&::uCnsDDOIK::getResource), reinterpret_cast<MT_MFUNC>(&::uCnsDDOIK::setResource), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "Dir", reinterpret_cast<s32*>(&(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 484))), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Up", reinterpret_cast<s32*>(&(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 488))), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUseScale", &mUseScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJointNum", &mJointNum, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffNo", &mEffNo, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mJointInfo", reinterpret_cast<MT_MFUNC>(&::uCnsDDOIK::getJointInfo), reinterpret_cast<MT_MFUNC>(&::uCnsDDOIK::setJointInfo), 160u, reinterpret_cast<MT_MFUNC>(&::uCnsDDOIK::getJointInfoNum), reinterpret_cast<MT_MFUNC>(&::uCnsDDOIK::setJointInfoNum));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "IK Status", reinterpret_cast<MT_MFUNC>(&::uCnsDDOIK::getStatus), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mEffectorControl", &mEffectorControl, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOffsetMat", &mOffsetMat, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCenterRefJntNo", &mCenterRefJntNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCenterPosOffset", &mCenterPosOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTransScale", &mTransScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Manipulate EffectorPos", &mEffectorPosEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Manipulate Up Vector", &mUpVectorPosEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectorPos", &mEffectorPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUpVectorPos", &mUpVectorPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Manipulate EffectorRot", &mEffectorRotEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_MATRIX, "mEffectorRot", reinterpret_cast<MT_MFUNC>(&::uCnsDDOIK::getEffectorMat), reinterpret_cast<MT_MFUNC>(&::uCnsDDOIK::setEffectorRot), 2176u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mEffectorTargetModelEnable", &mEffectorTargetModelEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUpVectorTargetModelEnable", &mUpVectorTargetModelEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpEffectorTargetModel", reinterpret_cast<MT_MFUNC>(&::uCnsDDOIK::getEffectorTargetModel), reinterpret_cast<MT_MFUNC>(&::uCnsDDOIK::setEffectorTargetModel), 144u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpUpVectorTargetModel", reinterpret_cast<MT_MFUNC>(&::uCnsDDOIK::getUpVectorTargetModel), reinterpret_cast<MT_MFUNC>(&::uCnsDDOIK::setUpVectorTargetModel), 144u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mEffectorTargetJointNo", reinterpret_cast<MT_MFUNC>(&::uCnsDDOIK::getEffectorTargetJointNo), reinterpret_cast<MT_MFUNC>(&::uCnsDDOIK::setEffectorTargetJointNo), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mUpVectorTargetJointNo", reinterpret_cast<MT_MFUNC>(&::uCnsDDOIK::getUpVectorTargetJointNo), reinterpret_cast<MT_MFUNC>(&::uCnsDDOIK::setUpVectorTargetJointNo), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mEffectorLimitEnable", &mEffectorLimitEnable, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJointLimitEnable", &mJointLimitEnable, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffPitchMin", &mEffPitchMin, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffPitchMax", &mEffPitchMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffRotMin", &mEffRotMin, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffRotMax", &mEffRotMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffDistMin", &mEffDistMin, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffDistMax", &mEffDistMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Effector Limit Mode", reinterpret_cast<s32*>(&(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 3296))), 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Joint Limit Mode", reinterpret_cast<s32*>(&(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 3300))), 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Limit Coordinate", reinterpret_cast<s32*>(&(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 3312))), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Limit Coordinate Offset", &mLimitCoordOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Effector Behavior", reinterpret_cast<s32*>(&(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 3308))), 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCollisionEnable", &mCollisionEnable, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Collision Mode", reinterpret_cast<s32*>(&(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 3304))), 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHeelOffset", &mHeelOffset, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHeelHeight", &mHeelHeight, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Fit Heel", &mFit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Ground Distance Adapt", &mGroundDistAdapt, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFitDir", &mFitDir, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFitUp", &mFitUp, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Check Upper", &mCheckGroundLengthUpper, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Check Lower", &mCheckGroundLengthLower, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Ground Level", &mGroundLevel, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Ground Normal", &mGroundNormal, 2048u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroundDistance", &mGroundDistance, 3u, 0u);
    createSCollisionParam(s);
}

void uCnsDDOIK::createSCollisionParam(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "CollisionType", &mCollisionParam.type, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "CollisionFilter", &mCollisionParam.filter, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "CollisionCheckGroupBit", &mCollisionParam.checkGroupBit, 0u, 0u);
}

void uCnsDDOIK::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    mEffectorPos.x = offset.x + mEffectorPos.x;
    mEffectorPos.y = offset.y + mEffectorPos.y;
    mEffectorPos.z = offset.z + mEffectorPos.z;
    mUpVectorPos.x = offset.x + mUpVectorPos.x;
    mUpVectorPos.y = offset.y + mUpVectorPos.y;
    mUpVectorPos.z = offset.z + mUpVectorPos.z;
}

__attribute__((weak)) void uCnsDDOIK::adjust(uModel::Joint* pJoint, uModel* pModel) {
    DDON_STUB("uCnsDDOIK::adjust")
    /* stub */
}

__attribute__((weak)) void uCnsDDOIK::update() {
    DDON_STUB("uCnsDDOIK::update")
    /* stub */
}

void uCnsDDOIK::remove() {
    removeConstraint();
    mJointInfo[1].mCnsJoint.removeConstraint();
    mJointInfo[2].mCnsJoint.removeConstraint();
    mJointInfo[3].mCnsJoint.removeConstraint();
    mEffectorPosEnable = false;
}

__attribute__((weak)) void uCnsDDOIK::evSetJoints(uModel::Joint* * pJnts, u32 Num) {
    DDON_STUB("uCnsDDOIK::evSetJoints")
    /* stub */
}

__attribute__((weak)) void uCnsDDOIK::evSetJoint(MtProperty& prop) {
}

void uCnsDDOIK::setModel(uModel* pModel) {
    this->uConstraint::setModel(pModel);
    mpEffectorTargetModel = pModel;
    mpUpVectorTargetModel = pModel;
}

__attribute__((weak)) void uCnsDDOIK::setResource(cResource* pRes) {
    DDON_STUB("uCnsDDOIK::setResource")
    /* stub */
}

cResource* uCnsDDOIK::getResource() {
    return mpCnsIKRes;
}

void uCnsDDOIK::setEffectorTargetModel(uModel* pModel) {
    mpEffectorTargetModel = pModel;
    mEffectorPosEnable = false;
}

static auto ddon_emit_0x01ad3720 __attribute__((used)) = &uCnsDDOIK::getEffectorTargetModel;

void uCnsDDOIK::setEffectorTargetJointNo(u32 JntNo) {
    mEffectorTargetJointNo = JntNo;
}

static auto ddon_emit_0x01ad3740 __attribute__((used)) = &uCnsDDOIK::getEffectorTargetJointNo;

void uCnsDDOIK::setUpVectorTargetModel(uModel* pModel) {
    mpUpVectorTargetModel = pModel;
    mUpVectorPosEnable = false;
}

static auto ddon_emit_0x01ad3730 __attribute__((used)) = &uCnsDDOIK::getUpVectorTargetModel;

void uCnsDDOIK::setUpVectorTargetJointNo(u32 JntNo) {
    mUpVectorTargetJointNo = JntNo;
}

static auto ddon_emit_0x01ad3750 __attribute__((used)) = &uCnsDDOIK::getUpVectorTargetJointNo;

static auto ddon_emit_0x01ad3620 __attribute__((used)) = &uCnsDDOIK::getJointInfo;

__attribute__((weak)) void uCnsDDOIK::setJointInfo(uCnsDDOIK::JointInfo* pJointInfo, s32 Idx) {
    DDON_STUB("uCnsDDOIK::setJointInfo")
    /* stub */
}

__attribute__((weak)) void uCnsDDOIK::setJointInfoNum(s32 Num) {
}

static auto ddon_emit_0x01ad36f0 __attribute__((used)) = &uCnsDDOIK::getJointInfoNum;

u32 uCnsDDOIK::getDependentJointNum() {
    if (mEffectorTargetModelEnable) {
        if (mpEffectorTargetModel != nullptr) {
            if (mpEffectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3832)] != 0xFF) {
                if (mUpVectorTargetModelEnable) {
                    if (mpUpVectorTargetModel != nullptr) {
                        if (mpUpVectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3848)] != 0xFF) {
                            return static_cast<u32>(!((&mpEffectorTargetModel->mJoint[mpEffectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3832)]]) == nullptr) + !((&mpUpVectorTargetModel->mJoint[mpUpVectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3848)]]) == nullptr));
                        }
                    }
                }
                return !((&mpEffectorTargetModel->mJoint[mpEffectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3832)]]) == nullptr);
            }
        }
    }
    if (mUpVectorTargetModelEnable) {
        if (mpUpVectorTargetModel != nullptr) {
            if (mpUpVectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3848)] != 0xFF) {
                return !((&mpUpVectorTargetModel->mJoint[mpUpVectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3848)]]) == nullptr);
            }
        }
    }
    return 0;
}

uModel::Joint* uCnsDDOIK::getDependentJoint(u32 Idx) {
    if (mEffectorTargetModelEnable) {
        if (!mUpVectorTargetModelEnable) {
            if (mpEffectorTargetModel != nullptr) {
                if ((mpEffectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3832)] != 0xFF) && ((&mpEffectorTargetModel->mJoint[mpEffectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3832)]]) != nullptr)) {
                    return &mpEffectorTargetModel->mJoint[mpEffectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3832)]];
                }
            }
        } else {
            if (Idx != 1) {
                if (Idx == 0) {
                    if (mpEffectorTargetModel != nullptr) {
                        if ((mpEffectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3832)] != 0xFF) && ((&mpEffectorTargetModel->mJoint[mpEffectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3832)]]) != nullptr)) {
                            return &mpEffectorTargetModel->mJoint[mpEffectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3832)]];
                        }
                    }
                    if (mpUpVectorTargetModel != nullptr) {
                        if ((mpUpVectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3848)] != 0xFF) && ((&mpUpVectorTargetModel->mJoint[mpUpVectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3848)]]) != nullptr)) {
                            return &mpUpVectorTargetModel->mJoint[mpUpVectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3848)]];
                        }
                    }
                }
            } else {
                if (mpUpVectorTargetModel != nullptr) {
                    if ((mpUpVectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3848)] != 0xFF) && ((&mpUpVectorTargetModel->mJoint[mpUpVectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3848)]]) != nullptr)) {
                        return &mpUpVectorTargetModel->mJoint[mpUpVectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3848)]];
                    }
                }
            }
        }
    } else {
        if (mUpVectorTargetModelEnable) {
            if (mpUpVectorTargetModel != nullptr) {
                if ((mpUpVectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3848)] != 0xFF) && ((&mpUpVectorTargetModel->mJoint[mpUpVectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3848)]]) != nullptr)) {
                    return &mpUpVectorTargetModel->mJoint[mpUpVectorTargetModel->mJointTable[*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 3848)]];
                }
            }
        }
    }
    return nullptr;
}

__attribute__((weak)) void uCnsDDOIK::draw(cDraw* pDraw) {
}

void uCnsDDOIK::setPri(u32 Pri) {
    this->uConstraint::setPri(Pri);
    for (s32 i = 0; i <= 3; i += 1) {
        if (mJointInfo[i].mJntNo == -1) {
            break;
        } else {
            if (i > 0) {
                (&mJointInfo[i].mCnsJoint)->setPri(mPri);
            }
        }
    }
}

void uCnsDDOIK::set(uModel* pModel, rCnsIK* pCnsIKRes) {
    setModel(pModel);
    setResource(static_cast<cResource*>(pCnsIKRes));
    mGroundLevel = -100000000.0f;
}

static auto ddon_emit_0x01ad3710 __attribute__((used)) = &uCnsDDOIK::getStatus;

void uCnsDDOIK::setEffectorPos(const MtVector3& Pos) {
    mEffectorPos = Pos;
    mEffectorPosEnable = true;
}

void uCnsDDOIK::setEffectorRot(const MtMatrix& mat) {
    mEffectorMat.m[0].x = mat.m[0].x;
    mEffectorMat.m[0].y = mat.m[0].y;
    mEffectorMat.m[0].z = mat.m[0].z;
    mEffectorMat.m[0].w = mat.m[0].w;
    mEffectorMat.m[1].x = mat.m[1].x;
    mEffectorMat.m[1].y = mat.m[1].y;
    mEffectorMat.m[1].z = mat.m[1].z;
    mEffectorMat.m[1].w = mat.m[1].w;
    mEffectorMat.m[2].x = mat.m[2].x;
    mEffectorMat.m[2].y = mat.m[2].y;
    mEffectorMat.m[2].z = mat.m[2].z;
    mEffectorMat.m[2].w = mat.m[2].w;
    mEffectorMat.m[3].x = mat.m[3].x;
    mEffectorMat.m[3].y = mat.m[3].y;
    mEffectorMat.m[3].z = mat.m[3].z;
    mEffectorMat.m[3].w = mat.m[3].w;
}

__attribute__((weak)) MtMatrix uCnsDDOIK::getEffectorMat() {
    DDON_STUB("uCnsDDOIK::getEffectorMat")
    __builtin_unreachable();
}

MtUI* uCnsDDOIK::createSCollisionUI(MtProperty& prop) {
    return nullptr;
}

inline uCnsDDOIK::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCnsDDOIK::MyDTI uCnsDDOIK::DTI("uCnsDDOIK", &::uConstraint::DTI, 3904ul, 0u, 0u);

__attribute__((weak)) MtObject* uCnsDDOIK::MyDTI::newInstance() const {
    DDON_STUB("uCnsDDOIK::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uCnsDDOIK::JointInfo::getDTI() const {
    return uCnsDDOIK::JointInfo::DTI;
}

uCnsDDOIK::JointInfo::~JointInfo() {
}

static auto ddon_emit_0x01ad3530 __attribute__((used)) = &uCnsDDOIK::JointInfo::getJntNo;

void uCnsDDOIK::JointInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "mJntNo", reinterpret_cast<MT_MFUNC>(&::uCnsDDOIK::JointInfo::getJntNo), reinterpret_cast<MT_MFUNC>(&::uCnsDDOIK::JointInfo::setJntNoForProperty), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mRotMin", &mRotMin, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRotMax", &mRotMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mReverse", &mReverse, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOffset", &mOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mScaleOffset", &mScaleOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLen", &mLen, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCnsJoint", static_cast<MtObject*>(&mCnsJoint), 2u, 0u);
    if (mpJoint == nullptr) {
        return;
    }
    s << MtProperty(static_cast<MtObject*>(this), "mpJoint", reinterpret_cast<MtObject* *>(&mpJoint), 18u, 0u);
}

MtUI* uCnsDDOIK::JointInfo::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void uCnsDDOIK::JointInfo::setJntNoForProperty(s32 JntNo) {
    DDON_STUB("uCnsDDOIK::JointInfo::setJntNoForProperty")
    /* stub */
}

inline uCnsDDOIK::JointInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCnsDDOIK::JointInfo::MyDTI uCnsDDOIK::JointInfo::DTI("uCnsDDOIK::JointInfo", &::MtObject::DTI, 672ul, 0u, 0u);

MtObject* uCnsDDOIK::JointInfo::MyDTI::newInstance() const {
    return new (16u) uCnsDDOIK::JointInfo;
}

const MtDTI& uCnsDDOIK::uCnsJoint::getDTI() const {
    return uCnsDDOIK::uCnsJoint::DTI;
}

__attribute__((weak)) void uCnsDDOIK::uCnsJoint::adjust(uModel::Joint* pJoint, uModel* pModel) {
    DDON_STUB("uCnsDDOIK::uCnsJoint::adjust")
    /* stub */
}

void uCnsDDOIK::uCnsJoint::createProperty(MtPropertyList& s) {
    this->uConstraint::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mIsEffector", &mIsEffector, 0u, 0u);
}

cResource* uCnsDDOIK::uCnsJoint::getResource() {
    return nullptr;
}

inline uCnsDDOIK::uCnsJoint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCnsDDOIK::uCnsJoint::MyDTI uCnsDDOIK::uCnsJoint::DTI("uCnsDDOIK::uCnsJoint", &::uConstraint::DTI, 176ul, 0u, 2u);

MtObject* uCnsDDOIK::uCnsJoint::MyDTI::newInstance() const {
    return new (16u) uCnsDDOIK::uCnsJoint;
}

