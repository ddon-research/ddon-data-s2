// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uCameraGame.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtEaseCurve.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "../../MT/MtSynchronize.h"
#include "aStage.h"
#include "cCamInterporate.h"
#include "cCameraGameAnim.h"
#include "cCameraGameLock.h"
#include "cCameraGameMot.h"
#include "cCameraGameNml.h"
#include "cCameraGamePhoto.h"
#include "cCameraGameTemplate.h"
#include "cCameraGameTps.h"
#include "../../XFramework/cSystem.h"
#include "../../XFramework/cUnit.h"
#include "cpHugeble.h"
#include "cpStateManager.h"
#include "../../generated/shared/nCameraGame.h"
#include "../../generated/shared/nDDOMath.h"
#include "nDDOUtility.h"
#include "nLayout.h"
#include "rCameraParamList.h"
#include "../../XFramework/rCollisionHeightField.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "../../XFramework/sCollision.h"
#include "sEnemyManager.h"
#include "sEventManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sInputManager.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sMouse.h"
#include "sMouseExt.h"
#include "sNpcManager.h"
#include "sOmManager.h"
#include "../../XFramework/sPad.h"
#include "sPadExt.h"
#include "sPlayerManager.h"
#include "../../XFramework/sSavedata.h"
#include "sSavedataExt.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "sUnitManager.h"
#include "sWorkRate.h"
#include "../../XFramework/uCamera.h"
#include "uCameraBase.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "../../XFramework/uFilter.h"
#include "uGUIGaugeArts.h"
#include "uGUIGaugeArtsV01_03.h"
#include "uGUIGaugeSorcery.h"
#include "../../XFramework/uModel.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCamExParam::getDTI() const {
    return cCamExParam::DTI;
}

void cCamExParam::createProperty(MtPropertyList& s) {
    createPropertyCommon(s);
    createPropertyCameraTarget(s);
    createPropertyCoord(s);
    createPropertyInterporate(s);
    createPropertyCtrl(s);
    createPropertyChangeInterporate(s);
    createPropertyAdjust(s);
    createPropertyEx(s);
}

__attribute__((weak)) void cCamExParam::createPropertyCommon(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mType", reinterpret_cast<s32*>(&mType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mComment", &mComment, 8192u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPriority", &mPriority, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRelVer", &mRelVer, 8192u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mConditionFlag", &mConditionFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mConditionPlDist", &mConditionPlDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mConditionCamDist", &mConditionCamDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mQuakeNo", &mQuakeNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsWaitCameraEnd", &mIsWaitCameraEnd, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEnableFrame", &mEnableFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCantReqFrame", &mCantReqFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRequestGroup", &mRequestGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCantReqGroupBit", &mCantReqGroupBit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCangReqFrameGroup", &mCangReqFrameGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsKeepAngle", &mIsKeepAngle, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mKeepAngleType", reinterpret_cast<s32*>(&mKeepAngleType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mKeepTargetPos", &mKeepTargetPos, 0u, 0u);
}

__attribute__((weak)) void cCamExParam::createPropertyCameraTarget(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mCameraTarget", reinterpret_cast<s32*>(&mCameraTarget), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroup", &mGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mId", &mId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetJoint", &mTargetJoint, 0u, 0u);
}

__attribute__((weak)) void cCamExParam::createPropertyCoord(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mDistance", &mDistance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mHeight", &mHeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOffsetX", &mOffsetX, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOffsetZ", &mOffsetZ, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFov", &mFov, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRoll", &mRoll, 0u, 0u);
}

__attribute__((weak)) void cCamExParam::createPropertyInterporate(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mInterCamRate", &mInterCamRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMargin", &mMargin, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMarginAdjPow", &mMarginAdjPow, 0u, 0u);
}

__attribute__((weak)) void cCamExParam::createPropertyCtrl(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mCtrlOption", &mCtrlOption, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAngLimitXMin", &mAngLimitXMin, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAngLimitXMax", &mAngLimitXMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCtrlCurve", &mCtrlCurve, 0u, 0u);
}

__attribute__((weak)) void cCamExParam::createPropertyChangeInterporate(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mStartInterType", reinterpret_cast<s32*>(&mStartInterType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStartFrameType", reinterpret_cast<s32*>(&mStartFrameType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStartInterFrame", &mStartInterFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStartInterCurve", &mStartInterCurve, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEndInterType", reinterpret_cast<s32*>(&mEndInterType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEndFrameType", reinterpret_cast<s32*>(&mEndFrameType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEndInterFrame", &mEndInterFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEndInterCurve", &mEndInterCurve, 0u, 0u);
}

__attribute__((weak)) void cCamExParam::createPropertyAdjust(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mScrAdjustType", reinterpret_cast<s32*>(&mScrAdjustType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mScrAdjustFlag", &mScrAdjustFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mScrAdjustHeight", &mScrAdjustHeight, 0u, 0u);
}

__attribute__((weak)) void cCamExParam::createPropertyEx(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mDofFilterFlag", &mDofFilterFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDOFFilterNearBlurLimit", &mDOFFilterNearBlurLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDOFFilterFarBlurLimit", &mDOFFilterFarBlurLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDOFFilterNear", &mDOFFilterNear, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDOFFilterFar", &mDOFFilterFar, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDOFFilterFocal", &mDOFFilterFocal, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDOFFilterGradateColor", &mDOFFilterGradateColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSysFlag", &mSysFlag, 0u, 0u);
}

cCamExParam::~cCamExParam() {
}

__attribute__((weak)) cCamExParam* cCamExParam::createParamInstanceFromType() {
    DDON_STUB("cCamExParam::createParamInstanceFromType")
    return nullptr;
}

__attribute__((weak)) void cCamExParam::copy(const cCamExParam* pParam) {
    DDON_STUB("cCamExParam::copy")
    /* stub */
}

inline cCamExParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamExParam::MyDTI cCamExParam::DTI("cCamExParam", &::MtObject::DTI, 480ul, 0u, 1u);

MtObject* cCamExParam::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& cCamExParamSdr::getDTI() const {
    return cCamExParamSdr::DTI;
}

inline void cCamExParamSdr::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cCamExParamSdr::DTI)->memFree(p_addr);
}

void cCamExParamSdr::createProperty(MtPropertyList& s) {
    createPropertyCommon(s);
    createPropertyCameraTarget(s);
    createPropertyCoord(s);
    createPropertyInterporate(s);
    createPropertyCtrl(s);
    createPropertyChangeInterporate(s);
    createPropertyAdjust(s);
    createPropertyEx(s);
    s << MtProperty(static_cast<MtObject*>(this), "mSdrParamArray", static_cast<MtObject*>(&mSdrParamArray), 0u, 0u);
}

cCamExParamSdr::~cCamExParamSdr() {
}

__attribute__((weak)) cCamImpBase* cCamExParamSdr::createCamImpInstance(uCameraGame* pCamera) const {
    DDON_STUB("cCamExParamSdr::createCamImpInstance")
    return nullptr;
}

__attribute__((weak)) void cCamExParamSdr::copy(const cCamExParam* pParam) {
    DDON_STUB("cCamExParamSdr::copy")
    /* stub */
}

inline cCamExParamSdr::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamExParamSdr::MyDTI cCamExParamSdr::DTI("cCamExParamSdr", &::cCamExParam::DTI, 512ul, 0u, 0u);

__attribute__((weak)) MtObject* cCamExParamSdr::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cCamExParamSdr::DTI)->memAlloc(sizeof(cCamExParamSdr), 16u, cCamExParamSdr::DTI.getID())) cCamExParamSdr;
}

const MtDTI& cCamExParamSdr::cSdrParam::getDTI() const {
    return cCamExParamSdr::cSdrParam::DTI;
}

inline void* cCamExParamSdr::cSdrParam::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cCamExParamSdr::cSdrParam::DTI)->memAlloc(sz, align, cCamExParamSdr::cSdrParam::DTI.getID());
}

inline void cCamExParamSdr::cSdrParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cCamExParamSdr::cSdrParam::DTI)->memFree(p_addr);
}

void cCamExParamSdr::cSdrParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIndex", &mIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFrame", &mFrame, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mChFlag", &mChFlag, 0u, 0u);
}

inline cCamExParamSdr::cSdrParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamExParamSdr::cSdrParam::MyDTI cCamExParamSdr::cSdrParam::DTI("cCamExParamSdr::cSdrParam", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cCamExParamSdr::cSdrParam::MyDTI::newInstance() const {
    return new (16u) cCamExParamSdr::cSdrParam;
}

const MtDTI& cCamExParamTarget::getDTI() const {
    return cCamExParamTarget::DTI;
}

inline void cCamExParamTarget::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cCamExParamTarget::DTI)->memFree(p_addr);
}

void cCamExParamTarget::createProperty(MtPropertyList& s) {
    createPropertyCommon(s);
    createPropertyCameraTarget(s);
    createPropertyCoord(s);
    createPropertyInterporate(s);
    createPropertyCtrl(s);
    createPropertyChangeInterporate(s);
    createPropertyAdjust(s);
    createPropertyEx(s);
    s << MtProperty(static_cast<MtObject*>(this), "mCameraOffset", &mCameraOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetType", reinterpret_cast<s32*>(&mTargetType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetGroup", &mTargetGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetId", &mTargetId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetJoint", &mTargetJoint, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetOffset", &mTargetOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetMargin", &mTargetMargin, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveDirLookScale", &mMoveDirLookScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveDirLookRate", &mMoveDirLookRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOptionFlag", &mOptionFlag, 0u, 0u);
}

cCamExParamTarget::~cCamExParamTarget() {
}

__attribute__((weak)) cCamImpBase* cCamExParamTarget::createCamImpInstance(uCameraGame* pCamera) const {
    DDON_STUB("cCamExParamTarget::createCamImpInstance")
    return nullptr;
}

__attribute__((weak)) void cCamExParamTarget::copy(const cCamExParam* pParam) {
    DDON_STUB("cCamExParamTarget::copy")
    /* stub */
}

inline cCamExParamTarget::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamExParamTarget::MyDTI cCamExParamTarget::DTI("cCamExParamTarget", &::cCamExParam::DTI, 560ul, 0u, 0u);

__attribute__((weak)) MtObject* cCamExParamTarget::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cCamExParamTarget::DTI)->memAlloc(sizeof(cCamExParamTarget), 16u, cCamExParamTarget::DTI.getID())) cCamExParamTarget;
}

const MtDTI& cCamImpBase::getDTI() const {
    return cCamImpBase::DTI;
}

inline void cCamImpBase::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cCamImpBase::DTI)->memFree(p_addr);
}

cCamImpBase::cCamImpBase() {
    DDON_STUB("cCamImpBase::cCamImpBase")
    /* stub */
}

cCamImpBase::~cCamImpBase() {
}

__attribute__((weak)) void cCamImpBase::createProperty(MtPropertyList& s) {
    DDON_STUB("cCamImpBase::createProperty")
    /* stub */
}

__attribute__((weak)) void cCamImpBase::init(const uDDOModel* pOwner, MtVector3& cameraPos, MtVector3& targetPos, f32& angX, f32& angY, bool isInterporate) {
    DDON_STUB("cCamImpBase::init")
    /* stub */
}

__attribute__((weak)) void cCamImpBase::ctrl(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
    DDON_STUB("cCamImpBase::ctrl")
    /* stub */
}

__attribute__((weak)) void cCamImpBase::move(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
    DDON_STUB("cCamImpBase::move")
    /* stub */
}

void cCamImpBase::interporate(MtVector3& cameraPos, MtVector3& targetPos) {
    if (mIsInterporate) {
        mpC->exeInterporate();
    }
    interporateSub(cameraPos, targetPos);
}

__attribute__((weak)) void cCamImpBase::adjust(MtVector3& cameraPos, MtVector3& targetPos, MtVector3& idealCam, MtVector3& idealTar) {
    DDON_STUB("cCamImpBase::adjust")
    /* stub */
}

__attribute__((weak)) void cCamImpBase::final(bool isInterporate) {
    DDON_STUB("cCamImpBase::final")
    /* stub */
}

__attribute__((weak)) void cCamImpBase::setEndInterporate(const cCamExParam* pParam) {
    DDON_STUB("cCamImpBase::setEndInterporate")
    /* stub */
}

__attribute__((weak)) const uCoord* cCamImpBase::getCameraTarget() const {
    DDON_STUB("cCamImpBase::getCameraTarget")
    return nullptr;
}

__attribute__((weak)) MtVector3 cCamImpBase::getCameraTargetPos() const {
    DDON_STUB("cCamImpBase::getCameraTargetPos")
    __builtin_unreachable();
}

__attribute__((weak)) const uBaseModel* cCamImpBase::getCameraTarget(const uCameraGame* pCam, const cCamExParam* pParam, nCameraGame::TARGET_TYPE type, u32 group, u32 id) {
    DDON_STUB("cCamImpBase::getCameraTarget")
    return nullptr;
}

__attribute__((weak)) void cCamImpBase::calcTargetPos(uCameraGame* pCam, nCameraGame::TARGET_TYPE targetType, MtVector3& pos, const MtVector3& ofs, s32 joint, u32 group, u32 id, u32 sysFlag) {
    DDON_STUB("cCamImpBase::calcTargetPos")
    /* stub */
}

f32 cCamImpBase::adjustAddPlayerHeight(f32 addHeight) {
    if (0.0f > addHeight) {
        return 0.4f * addHeight;
    } else {
        return 0.8f * addHeight;
    }
}

f32 cCamImpBase::adjustAddPlayerDistance(f32 addHeight) {
    if (0.0f > addHeight) {
        return 0.8f * addHeight;
    } else {
        return 1.2f * addHeight;
    }
}

__attribute__((weak)) void cCamImpBase::cameraCtrl(bool isRStick) {
    DDON_STUB("cCamImpBase::cameraCtrl")
    /* stub */
}

__attribute__((weak)) bool cCamImpBase::checkCameraReset() const {
    DDON_STUB("cCamImpBase::checkCameraReset")
    return {};
}

inline cCamImpBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamImpBase::MyDTI cCamImpBase::DTI("cCamImpBase", &::MtObject::DTI, 176ul, 0u, 1u);

MtObject* cCamImpBase::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& cCamImpSdr::getDTI() const {
    return cCamImpSdr::DTI;
}

inline void cCamImpSdr::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cCamImpSdr::DTI)->memFree(p_addr);
}

cCamImpSdr::~cCamImpSdr() {
    if (mpImple == nullptr) {
        return;
    }
    delete mpImple;
    mpImple = nullptr;
}

__attribute__((weak)) void cCamImpSdr::initSub(MtVector3& cameraPos, MtVector3& targetPos, f32& angX, f32& angY) {
    DDON_STUB("cCamImpSdr::initSub")
    /* stub */
}

__attribute__((weak)) void cCamImpSdr::ctrlSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
    DDON_STUB("cCamImpSdr::ctrlSub")
    /* stub */
}

__attribute__((weak)) void cCamImpSdr::moveSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
    DDON_STUB("cCamImpSdr::moveSub")
    /* stub */
}

void cCamImpSdr::interporateSub(MtVector3& cameraPos, MtVector3& targetPos) {
    cCamImpBase* t0 = mpImple;
    if (t0 == nullptr) {
        return;
    }
    if (t0->mIsInterporate) {
        t0->mpC->exeInterporate();
    }
    t0->interporateSub(cameraPos, targetPos);
}

void cCamImpSdr::adjustSub(MtVector3& cameraPos, MtVector3& targetPos, MtVector3& idealCam, MtVector3& idealTar) {
    if (mpImple == nullptr) {
        return;
    }
    mpImple->adjust(cameraPos, targetPos, idealCam, idealTar);
}

void cCamImpSdr::finalSub() {
    if (mpImple == nullptr) {
        return;
    }
    mpImple->final(true);
    if (mpImple == nullptr) {
        return;
    }
    delete mpImple;
    mpImple = nullptr;
}

nCameraGame::CAMERA_TYPE cCamImpSdr::getType() const {
    return nCameraGame::TYPE_SDR;
}

__attribute__((weak)) void cCamImpSdr::createProperty(MtPropertyList& s) {
}

inline cCamImpSdr::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamImpSdr::MyDTI cCamImpSdr::DTI("cCamImpSdr", &::cCamImpBase::DTI, 208ul, 0u, 0u);

__attribute__((weak)) MtObject* cCamImpSdr::MyDTI::newInstance() const {
    DDON_STUB("cCamImpSdr::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cCamImpTarget::getDTI() const {
    return cCamImpTarget::DTI;
}

inline void cCamImpTarget::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cCamImpTarget::DTI)->memFree(p_addr);
}

cCamImpTarget::~cCamImpTarget() {
    DDON_STUB("cCamImpTarget::~cCamImpTarget")
    /* stub */
}

__attribute__((weak)) void cCamImpTarget::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("cCamImpTarget::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) void cCamImpTarget::initSub(MtVector3& cameraPos, MtVector3& targetPos, f32& angX, f32& angY) {
    DDON_STUB("cCamImpTarget::initSub")
    /* stub */
}

__attribute__((weak)) void cCamImpTarget::ctrlSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
    DDON_STUB("cCamImpTarget::ctrlSub")
    /* stub */
}

void cCamImpTarget::moveSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
    mLastTargetPos.x = idealTar.x;
    mLastTargetPos.y = idealTar.y;
    mLastTargetPos.z = idealTar.z;
    mLastTargetPos.pad_ = 0.0f;
    cCamImpBase::calcTargetPos(mpC, mpParamTar->mTargetType, idealTar, mpParamTar->mTargetOffset, mpParamTar->mTargetJoint, mpParamTar->mTargetGroup, mpParamTar->mTargetId, mpParamTar->mSysFlag);
    f32 t0 = idealTar.y;
    f32 t1 = idealTar.z;
    mMoveDirLookVec.x = idealTar.x - mLastTargetPos.x;
    mMoveDirLookVec.y = t0 - mLastTargetPos.y;
    mMoveDirLookVec.z = t1 - mLastTargetPos.z;
    mMoveDirLookVec.pad_ = 0.0f;
    if ((mpParamTar->mSysFlag & 128u) != 0) {
        cCamImpBase::calcTargetPos(mpC, mpParamTar->mCameraTarget, idealCam, mpParamTar->mCameraOffset, mpParamTar->mTargetJoint, mpParamTar->mGroup, mpParamTar->mId, mpParamTar->mSysFlag);
    } else {
        cCamImpBase::calcTargetPos(mpC, mpParamTar->mCameraTarget, idealCam, mpParamTar->mCameraOffset, 0, mpParamTar->mGroup, mpParamTar->mId, mpParamTar->mSysFlag);
    }
    if (mCtrlX > 0.52359885f) {
        mCtrlX = 0.52359885f;
    } else {
        if (-0.17453295f > mCtrlX) {
            mCtrlX = -0.17453295f;
        }
    }
    if (mCtrlY > 0.78539824f) {
        mCtrlY = 0.78539824f;
    } else {
        if (-0.78539824f > mCtrlY) {
            mCtrlY = -0.78539824f;
        }
    }
}

__attribute__((weak)) void cCamImpTarget::interporateSub(MtVector3& cameraPos, MtVector3& targetPos) {
    DDON_STUB("cCamImpTarget::interporateSub")
    /* stub */
}

__attribute__((weak)) void cCamImpTarget::adjustSub(MtVector3& cameraPos, MtVector3& targetPos, MtVector3& idealCam, MtVector3& idealTar) {
}

__attribute__((weak)) void cCamImpTarget::finalSub() {
}

nCameraGame::CAMERA_TYPE cCamImpTarget::getType() const {
    return nCameraGame::TYPE_TARGET;
}

inline cCamImpTarget::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamImpTarget::MyDTI cCamImpTarget::DTI("cCamImpTarget", &::cCamImpBase::DTI, 448ul, 0u, 0u);

__attribute__((weak)) MtObject* cCamImpTarget::MyDTI::newInstance() const {
    DDON_STUB("cCamImpTarget::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) void cCamInterPreset::initialize(const MtVector3& cameraPos, const MtVector3& targetPos, f32 roll, f32 fov, const MtVector3& playerPos, const MtHermiteCurve& curve, f32 time, cCamInterPreset::INTER_TYPE type, cCamInterPreset::FRAME_TYPE fType) {
    DDON_STUB("cCamInterPreset::initialize")
    /* stub */
}

__attribute__((weak)) void cCamInterPreset::interporate(MtVector3& cameraPos, MtVector3& targetPos, f32& roll, f32& fov, const MtVector3& playerPos, f32 time) {
    DDON_STUB("cCamInterPreset::interporate")
    /* stub */
}

const MtDTI& nCameraGame::cTemplateParam::getDTI() const {
    return nCameraGame::cTemplateParam::DTI;
}

inline MtAllocator* nCameraGame::cTemplateParam::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::nCameraGame::cTemplateParam::DTI);
}

void* nCameraGame::cTemplateParam::operator new(size_t sz, u32 align) {
    return ::nCameraGame::cTemplateParam::getAllocator()->memAlloc(sz, align, ::nCameraGame::cTemplateParam::DTI.getID());
}

__attribute__((weak)) void nCameraGame::cTemplateParam::operator delete(void* p_addr) {
    ::nCameraGame::cTemplateParam::getAllocator()->memFree(p_addr);
}

void nCameraGame::cTemplateParam::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "mIndex", &mIndex, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mChFlag", reinterpret_cast<s32*>(&mChFlag), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mFrame", &mFrame, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mTargetTypeA", reinterpret_cast<s32*>(&mTargetTypeA), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mUnitTypeA", reinterpret_cast<s32*>(&mUnitTypeA), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mTargetGroup_A", &mTargetGroup_A, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mTargetID_A", &mTargetID_A, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mOffsetA", &mOffsetA, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mTargetTypeB", reinterpret_cast<s32*>(&mTargetTypeB), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mUnitTypeB", reinterpret_cast<s32*>(&mUnitTypeB), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mTargetGroup_B", &mTargetGroup_B, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mTargetID_B", &mTargetID_B, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mOffsetB", &mOffsetB, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mAnimSpeed", &mAnimSpeed, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mAnimStartFrame", &mAnimStartFrame, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mAnimDistScale", &mAnimDistScale, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mIsUseCustomInter", &mIsUseCustomInter, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mInterType", reinterpret_cast<s32*>(&mInterType), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mInterFrameType", reinterpret_cast<s32*>(&mInterFrameType), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mInterFrame", &mInterFrame, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mInterCurve", &mInterCurve, 0u, 0u);
}

__attribute__((weak)) const uCoord* nCameraGame::cTemplateParam::getTempTarget(nCameraGame::cTemplateParam::UNIT_TYPE type, u32 group, u32 id) const {
    DDON_STUB("nCameraGame::cTemplateParam::getTempTarget")
    return nullptr;
}

inline nCameraGame::cTemplateParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nCameraGame::cTemplateParam::MyDTI nCameraGame::cTemplateParam::DTI("nCameraGame::cTemplateParam", &::MtObject::DTI, 304ul, 0u, 0u);

__attribute__((weak)) MtObject* nCameraGame::cTemplateParam::MyDTI::newInstance() const {
    return new (16u) ::nCameraGame::cTemplateParam;
}

const MtDTI& uCameraGame::getDTI() const {
    return uCameraGame::DTI;
}

inline MtAllocator* uCameraGame::getAllocator() {
    return MtMemoryAllocator::getAllocator(uCameraGame::DTI);
}

void* uCameraGame::operator new(size_t sz, u32 align) {
    return uCameraGame::getAllocator()->memAlloc(sz, align, uCameraGame::DTI.getID());
}

inline void uCameraGame::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uCameraGame::DTI)->memFree(p_addr);
}

uCameraGame::uCameraGame() {
    DDON_STUB("uCameraGame::uCameraGame")
    /* stub */
}

uCameraGame::~uCameraGame() {
    DDON_STUB("uCameraGame::~uCameraGame")
    /* stub */
}

__attribute__((weak)) void uCameraGame::init() {
    DDON_STUB("uCameraGame::init")
    /* stub */
}

__attribute__((weak)) void uCameraGame::update(const f32 deltaTime, const f32 deltaSec) {
    DDON_STUB("uCameraGame::update")
    /* stub */
}

__attribute__((weak)) void uCameraGame::updatePtr() {
    DDON_STUB("uCameraGame::updatePtr")
    /* stub */
}

void uCameraGame::move() {
    if (!mbInitial) {
        init();
    }
}

__attribute__((weak)) void uCameraGame::moveAfter() {
    DDON_STUB("uCameraGame::moveAfter")
    /* stub */
}

void uCameraGame::createProperty(MtPropertyList& s) {
    this->uCameraBase::createProperty(s);
}

__attribute__((weak)) void uCameraGame::kill() {
    DDON_STUB("uCameraGame::kill")
    /* stub */
}

__attribute__((weak)) void uCameraGame::copy(const uCameraGame* pParam) {
    DDON_STUB("uCameraGame::copy")
    /* stub */
}

bool uCameraGame::isStageCamera(u32 no) const {
    aStage* pStage = static_cast<sAreaExt*>(sArea::getInstance())->getCurrentStage();
    if (pStage != nullptr) {
        const cCamExParam* t0 = pStage->getCameraParamFld(no);
        if (mpImple->mpParam != t0) {
            const cCamExParam* t1 = pStage->getCameraParamEvt(no);
            if (mpImple->mpParam != t1) {
                return false;
            } else {
                return true;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

bool uCameraGame::isEventCamera(u32 no) const {
    if (sEventManager::getInstance() != nullptr) {
        const cCamExParam* t0 = sEventManager::getInstance()->getEventCameraParam(no);
        if (mpImple->mpParam != t0) {
            return false;
        } else {
            return true;
        }
    } else {
        return false;
    }
}

__attribute__((weak)) void uCameraGame::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uCameraGame::applyWorldOffset")
    /* stub */
}

MtMatrix uCameraGame::getViewMat() {
    MtMatrix vm;
    vm.setLookAtRH(mCameraPos, mTargetPos, mCameraUp);
    return vm;
}

MtMatrix uCameraGame::getProjMat() {
    MtMatrix pj;
    pj.setPerspectiveFovRH(mNearPlane, mFarPlane, mFov * 0.017453294f, mAspect);
    if (mFovType != FOV_V) {
        f32 t0 = mAspect;
        pj.m[0].x = pj.m[0].x / (1.0f / t0);
        pj.m[1].y = t0 * pj.m[1].y;
        return pj;
    } else {
        return pj;
    }
}

__attribute__((weak)) bool uCameraGame::requestExCamera(const cCamExParam* pParam, const uDDOModel* pResourceOwner, const uDDOModel* pOwner, bool isForceSet) {
    DDON_STUB("uCameraGame::requestExCamera")
    return {};
}

__attribute__((weak)) bool uCameraGame::canChangeExCamera(const cCamExParam* pParam, const uDDOModel* pOwner) const {
    DDON_STUB("uCameraGame::canChangeExCamera")
    return {};
}

bool uCameraGame::isAnmEnd() const {
    return mpImple->isAnmEnd();
}

s32 uCameraGame::getCut() const {
    if (mpImple != nullptr) {
        return mpImple->getCut();
    } else {
        return 0;
    }
}

void uCameraGame::addPhotoFov(f32 fov) {
    mPhotoAddFov = mPhotoAddFov + fov;
    if (-38.0f > mPhotoAddFov) {
        mPhotoAddFov = -38.0f;
    } else {
        if (mPhotoAddFov > 20.0f) {
            mPhotoAddFov = 20.0f;
        }
    }
}

__attribute__((weak)) MtVector3 uCameraGame::getPushVec() const {
    DDON_STUB("uCameraGame::getPushVec")
    __builtin_unreachable();
}

__attribute__((weak)) void uCameraGame::initDOFFilterParam() {
    DDON_STUB("uCameraGame::initDOFFilterParam")
    /* stub */
}

void uCameraGame::setDOFFilterNear(f32 val) {
    if (mpDOFFilter == nullptr) {
        return;
    }
    if (mpDOFFilter->isEnable()) {
        mpDOFFilter->setNear(val);
    }
}

void uCameraGame::setDOFFilterNearBlurLimit(f32 nearBlurLimit) {
    if (mpDOFFilter == nullptr) {
        return;
    }
    if (mpDOFFilter->isEnable()) {
        mpDOFFilter->mNearBlurLimit = nearBlurLimit;
    }
}

void uCameraGame::setDOFFilterFarBlurLimit(f32 farBlurLimit) {
    if (mpDOFFilter == nullptr) {
        return;
    }
    if (mpDOFFilter->isEnable()) {
        mpDOFFilter->mFarBlurLimit = farBlurLimit;
    }
}

void uCameraGame::setDOFFilterFar(f32 val) {
    if (mpDOFFilter == nullptr) {
        return;
    }
    if (mpDOFFilter->isEnable()) {
        mpDOFFilter->setFar(val);
    }
}

void uCameraGame::setDOFFilterFocal(f32 focal) {
    if (mpDOFFilter == nullptr) {
        return;
    }
    if (mpDOFFilter->isEnable()) {
        mpDOFFilter->setFocal(focal);
    }
}

__attribute__((weak)) void uCameraGame::resetDOFFilterParam() {
    DDON_STUB("uCameraGame::resetDOFFilterParam")
    /* stub */
}

__attribute__((weak)) void uCameraGame::createMotionBlurFilter() {
    DDON_STUB("uCameraGame::createMotionBlurFilter")
    /* stub */
}

void uCameraGame::killMotionBlurFilter() {
    if (mpMotionBlurFilter == nullptr) {
        return;
    }
    mpMotionBlurFilter->kill();
    mpMotionBlurFilter = nullptr;
}

__attribute__((weak)) void uCameraGame::resetPos() {
    DDON_STUB("uCameraGame::resetPos")
    /* stub */
}

__attribute__((weak)) void uCameraGame::camCtrl(bool isRStick) {
    DDON_STUB("uCameraGame::camCtrl")
    /* stub */
}

__attribute__((weak)) void uCameraGame::initInterParam(f32 camSpring, f32 tarSpring) {
    DDON_STUB("uCameraGame::initInterParam")
    /* stub */
}

__attribute__((weak)) void uCameraGame::initInterSpring(f32 camSpring, f32 tarSpring) {
    DDON_STUB("uCameraGame::initInterSpring")
    /* stub */
}

__attribute__((weak)) void uCameraGame::exeInterporate() {
    DDON_STUB("uCameraGame::exeInterporate")
    /* stub */
}

__attribute__((weak)) void uCameraGame::behindPlayer(f32& angX, f32& angY) {
    DDON_STUB("uCameraGame::behindPlayer")
    /* stub */
}

__attribute__((weak)) void uCameraGame::lookTarget(f32& angX, f32& angY) {
    DDON_STUB("uCameraGame::lookTarget")
    /* stub */
}

__attribute__((weak)) void uCameraGame::dodgeScroll() {
}

__attribute__((weak)) f32 uCameraGame::getCameraWorkRate() const {
    DDON_STUB("uCameraGame::getCameraWorkRate")
    return {};
}

nCameraGame::CAMERA_TYPE uCameraGame::getCamType() const {
    return mpImple->getType();
}

nCameraGame::TARGET_TYPE uCameraGame::getCameraTargetType() const {
    return mpImple->getParam()->mCameraTarget;
}

__attribute__((weak)) void uCameraGame::updateChangeCamera() {
    DDON_STUB("uCameraGame::updateChangeCamera")
    /* stub */
}

inline uCameraGame::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCameraGame::MyDTI uCameraGame::DTI("uCameraGame", &::uCameraBase::DTI, 4320ul, 0u, 0u);

__attribute__((weak)) MtObject* uCameraGame::MyDTI::newInstance() const {
    DDON_STUB("uCameraGame::MyDTI::newInstance")
    return nullptr;
}

