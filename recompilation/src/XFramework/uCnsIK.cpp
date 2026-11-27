// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uCnsIK.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cResource.h"
#include "cUnit.h"
#include "rCnsIK.h"
#include "sCollision.h"
#include "uConstraint.h"
#include "uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uCnsIK::usage() {
}

const MtDTI& uCnsIK::getDTI() const {
    return uCnsIK::DTI;
}

__attribute__((weak)) bool uCnsIK::setupJointInfo(uModel* pModel, uCnsIK::JointInfo* JointInfoTbl, s32 Num, uConstraint::DIRECTION DirVector, uConstraint::DIRECTION UpVector) {
    DDON_STUB("uCnsIK::setupJointInfo")
    return {};
}

__attribute__((weak)) void uCnsIK::calcLocalMatrix(uModel* pModel, uCnsIK::JointInfo* JointInfoTbl, s32 Num) {
    DDON_STUB("uCnsIK::calcLocalMatrix")
    /* stub */
}

__attribute__((weak)) void uCnsIK::calc2BoneIK(uCnsIK::JointInfo& JointInfo0, uCnsIK::JointInfo& JointInfo1, uCnsIK::JointInfo& JointInfo2, MtVector3& EffDir, MtMatrix& BaseIKMat, MtMatrix& LimitBaseMat) {
    DDON_STUB("uCnsIK::calc2BoneIK")
    /* stub */
}

__attribute__((weak)) void uCnsIK::calc3BoneIK(uCnsIK::JointInfo& JointInfo0, uCnsIK::JointInfo& JointInfo1, uCnsIK::JointInfo& JointInfo2, uCnsIK::JointInfo& JointInfo3, MtVector3& EffDir, MtMatrix& BaseIKMat, MtMatrix& LimitBaseMat) {
    DDON_STUB("uCnsIK::calc3BoneIK")
    /* stub */
}

__attribute__((weak)) bool uCnsIK::limitEffector(MtMatrix& BaseIKMat, MtVector3& EffDir, MtVector3& EffPos, MtVector3& EffUp, MtVector3* pLastVBase, const MtMatrix& BaseWMat, f32 PitchMin, f32 PitchMax, f32 RotMin, f32 RotMax, f32 DistMin, f32 DistMax) {
    DDON_STUB("uCnsIK::limitEffector")
    return {};
}

__attribute__((weak)) bool uCnsIK::limit(MtMatrix& Mat, const MtMatrix& PMat, f32 min, f32 max, MtVector3* pLastV) {
    DDON_STUB("uCnsIK::limit")
    return {};
}

__attribute__((weak)) s32 uCnsIK::checkGround(MtVector3& Pos, sCollision::TriangleInfo* pTriInfo) {
    DDON_STUB("uCnsIK::checkGround")
    return {};
}

__attribute__((noinline)) uCnsIK::~uCnsIK() {
    DDON_STUB("uCnsIK::~uCnsIK")
    /* stub */
}

MT_CTSTR uCnsIK::getName() {
    if (mpCnsIKRes != nullptr) {
        return &mpCnsIKRes->mPath[0];
    } else {
        return this->cUnit::getName();
    }
}

MtUI* uCnsIK::createUI(MtProperty& prop) {
    return this->uConstraint::createUI(prop);
}

void uCnsIK::createProperty(MtPropertyList& s) {
    this->uConstraint::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mpCnsIKRes", "resource", reinterpret_cast<MT_MFUNC>(&::uCnsIK::getResource), reinterpret_cast<MT_MFUNC>(&::uCnsIK::setResource), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "Dir", reinterpret_cast<s32*>(&(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 484))), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Up", reinterpret_cast<s32*>(&(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 488))), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUseScale", &mUseScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJointNum", &mJointNum, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffNo", &mEffNo, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mJointInfo", reinterpret_cast<MT_MFUNC>(&::uCnsIK::getJointInfo), reinterpret_cast<MT_MFUNC>(&::uCnsIK::setJointInfo), 160u, reinterpret_cast<MT_MFUNC>(&::uCnsIK::getJointInfoNum), reinterpret_cast<MT_MFUNC>(&::uCnsIK::setJointInfoNum));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "IK Status", reinterpret_cast<MT_MFUNC>(&::uCnsIK::getStatus), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
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
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_MATRIX, "mEffectorRot", reinterpret_cast<MT_MFUNC>(&::uCnsIK::getEffectorMat), reinterpret_cast<MT_MFUNC>(&::uCnsIK::setEffectorRot), 2176u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mEffectorTargetModelEnable", &mEffectorTargetModelEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUpVectorTargetModelEnable", &mUpVectorTargetModelEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpEffectorTargetModel", reinterpret_cast<MT_MFUNC>(&::uCnsIK::getEffectorTargetModel), reinterpret_cast<MT_MFUNC>(&::uCnsIK::setEffectorTargetModel), 144u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpUpVectorTargetModel", reinterpret_cast<MT_MFUNC>(&::uCnsIK::getUpVectorTargetModel), reinterpret_cast<MT_MFUNC>(&::uCnsIK::setUpVectorTargetModel), 144u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mEffectorTargetJointNo", reinterpret_cast<MT_MFUNC>(&::uCnsIK::getEffectorTargetJointNo), reinterpret_cast<MT_MFUNC>(&::uCnsIK::setEffectorTargetJointNo), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mUpVectorTargetJointNo", reinterpret_cast<MT_MFUNC>(&::uCnsIK::getUpVectorTargetJointNo), reinterpret_cast<MT_MFUNC>(&::uCnsIK::setUpVectorTargetJointNo), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
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

void uCnsIK::createSCollisionParam(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "CollisionType", &mCollisionParam.type, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "CollisionFilter", &mCollisionParam.filter, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "CollisionCheckGroupBit", &mCollisionParam.checkGroupBit, 0u, 0u);
}

void uCnsIK::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    mEffectorPos.x = offset.x + mEffectorPos.x;
    mEffectorPos.y = offset.y + mEffectorPos.y;
    mEffectorPos.z = offset.z + mEffectorPos.z;
    mUpVectorPos.x = offset.x + mUpVectorPos.x;
    mUpVectorPos.y = offset.y + mUpVectorPos.y;
    mUpVectorPos.z = offset.z + mUpVectorPos.z;
}

__attribute__((weak)) void uCnsIK::adjust(uModel::Joint* pJoint, uModel* pModel) {
    DDON_STUB("uCnsIK::adjust")
    /* stub */
}

__attribute__((weak)) void uCnsIK::update() {
    DDON_STUB("uCnsIK::update")
    /* stub */
}

void uCnsIK::remove() {
    removeConstraint();
    mJointInfo[1].mCnsJoint.removeConstraint();
    mJointInfo[2].mCnsJoint.removeConstraint();
    mJointInfo[3].mCnsJoint.removeConstraint();
    mEffectorPosEnable = false;
}

__attribute__((weak)) void uCnsIK::evSetJoints(uModel::Joint* * pJnts, u32 Num) {
    DDON_STUB("uCnsIK::evSetJoints")
    /* stub */
}

__attribute__((weak)) void uCnsIK::evSetJoint(MtProperty& prop) {
}

void uCnsIK::setModel(uModel* pModel) {
    this->uConstraint::setModel(pModel);
    mpEffectorTargetModel = pModel;
    mpUpVectorTargetModel = pModel;
}

__attribute__((weak)) void uCnsIK::setResource(cResource* pRes) {
    DDON_STUB("uCnsIK::setResource")
    /* stub */
}

cResource* uCnsIK::getResource() {
    return mpCnsIKRes;
}

void uCnsIK::setEffectorTargetModel(uModel* pModel) {
    mpEffectorTargetModel = pModel;
    mEffectorPosEnable = false;
}

static auto ddon_emit_0x01b67330 __attribute__((used)) = &uCnsIK::getEffectorTargetModel;

void uCnsIK::setEffectorTargetJointNo(u32 JntNo) {
    mEffectorTargetJointNo = JntNo;
}

static auto ddon_emit_0x01b67350 __attribute__((used)) = &uCnsIK::getEffectorTargetJointNo;

void uCnsIK::setUpVectorTargetModel(uModel* pModel) {
    mpUpVectorTargetModel = pModel;
    mUpVectorPosEnable = false;
}

static auto ddon_emit_0x01b67340 __attribute__((used)) = &uCnsIK::getUpVectorTargetModel;

void uCnsIK::setUpVectorTargetJointNo(u32 JntNo) {
    mUpVectorTargetJointNo = JntNo;
}

static auto ddon_emit_0x01b67360 __attribute__((used)) = &uCnsIK::getUpVectorTargetJointNo;

static auto ddon_emit_0x01b67230 __attribute__((used)) = &uCnsIK::getJointInfo;

__attribute__((weak)) void uCnsIK::setJointInfo(uCnsIK::JointInfo* pJointInfo, s32 Idx) {
    DDON_STUB("uCnsIK::setJointInfo")
    /* stub */
}

__attribute__((weak)) void uCnsIK::setJointInfoNum(s32 Num) {
}

static auto ddon_emit_0x01b67300 __attribute__((used)) = &uCnsIK::getJointInfoNum;

u32 uCnsIK::getDependentJointNum() {
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

uModel::Joint* uCnsIK::getDependentJoint(u32 Idx) {
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

__attribute__((weak)) void uCnsIK::draw(cDraw* pDraw) {
}

void uCnsIK::setPri(u32 Pri) {
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

void uCnsIK::set(uModel* pModel, rCnsIK* pCnsIKRes) {
    setModel(pModel);
    setResource(static_cast<cResource*>(pCnsIKRes));
    mGroundLevel = -100000000.0f;
}

static auto ddon_emit_0x01b67320 __attribute__((used)) = &uCnsIK::getStatus;

void uCnsIK::setEffectorPos(const MtVector3& Pos) {
    mEffectorPos.x = Pos.x;
    mEffectorPos.y = Pos.y;
    mEffectorPos.z = Pos.z;
    mEffectorPos.pad_ = 0.0f;
    mEffectorPosEnable = true;
}

void uCnsIK::setEffectorRot(const MtMatrix& mat) {
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

__attribute__((weak)) MtMatrix uCnsIK::getEffectorMat() {
    DDON_STUB("uCnsIK::getEffectorMat")
    __builtin_unreachable();
}

void uCnsIK::setUpVectorPos(const MtVector3& Pos) {
    mUpVectorPos.x = Pos.x;
    mUpVectorPos.y = Pos.y;
    mUpVectorPos.z = Pos.z;
    mUpVectorPos.pad_ = 0.0f;
    mUpVectorPosEnable = true;
}

MtUI* uCnsIK::createSCollisionUI(MtProperty& prop) {
    return nullptr;
}

inline uCnsIK::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCnsIK::MyDTI uCnsIK::DTI("uCnsIK", &::uConstraint::DTI, 3872ul, 0u, 0u);

__attribute__((weak)) MtObject* uCnsIK::MyDTI::newInstance() const {
    DDON_STUB("uCnsIK::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uCnsIK::JointInfo::getDTI() const {
    return uCnsIK::JointInfo::DTI;
}

uCnsIK::JointInfo::~JointInfo() {
}

__attribute__((weak)) bool uCnsIK::JointInfo::setJntNo(s32 JntNo) {
    DDON_STUB("uCnsIK::JointInfo::setJntNo")
    return {};
}

static auto ddon_emit_0x01b67170 __attribute__((used)) = &uCnsIK::JointInfo::getJntNo;

void uCnsIK::JointInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "mJntNo", reinterpret_cast<MT_MFUNC>(&::uCnsIK::JointInfo::getJntNo), reinterpret_cast<MT_MFUNC>(&::uCnsIK::JointInfo::setJntNoForProperty), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
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

MtUI* uCnsIK::JointInfo::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void uCnsIK::JointInfo::setJntNoForProperty(s32 JntNo) {
    DDON_STUB("uCnsIK::JointInfo::setJntNoForProperty")
    /* stub */
}

inline uCnsIK::JointInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCnsIK::JointInfo::MyDTI uCnsIK::JointInfo::DTI("uCnsIK::JointInfo", &::MtObject::DTI, 672ul, 0u, 0u);

__attribute__((weak)) MtObject* uCnsIK::JointInfo::MyDTI::newInstance() const {
    DDON_STUB("uCnsIK::JointInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uCnsIK::uCnsJoint::getDTI() const {
    return uCnsIK::uCnsJoint::DTI;
}

__attribute__((weak)) void uCnsIK::uCnsJoint::adjust(uModel::Joint* pJoint, uModel* pModel) {
    DDON_STUB("uCnsIK::uCnsJoint::adjust")
    /* stub */
}

void uCnsIK::uCnsJoint::createProperty(MtPropertyList& s) {
    this->uConstraint::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mIsEffector", &mIsEffector, 0u, 0u);
}

cResource* uCnsIK::uCnsJoint::getResource() {
    return nullptr;
}

inline uCnsIK::uCnsJoint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCnsIK::uCnsJoint::MyDTI uCnsIK::uCnsJoint::DTI("uCnsIK::uCnsJoint", &::uConstraint::DTI, 176ul, 0u, 2u);

__attribute__((weak)) MtObject* uCnsIK::uCnsJoint::MyDTI::newInstance() const {
    DDON_STUB("uCnsIK::uCnsJoint::MyDTI::newInstance")
    return nullptr;
}

