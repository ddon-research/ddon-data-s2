// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCameraGameAnim.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtEaseCurve.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "aStage.h"
#include "../../XFramework/cArea.h"
#include "cCamInterporate.h"
#include "cContextInterface.h"
#include "cEditParam.h"
#include "../../generated/shared/nCameraGame.h"
#include "../../generated/shared/nDDOMath.h"
#include "nDDOUtility.h"
#include "rCharacterEdit.h"
#include "../../XFramework/sArea.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "sContextManager.h"
#include "sEventManager.h"
#include "../../XFramework/sMain.h"
#include "sPlayerManager.h"
#include "sWorldOffset.h"
#include "../../XFramework/uCamera.h"
#include "uCameraBase.h"
#include "uCameraGame.h"
#include "../../XFramework/uCoord.h"
#include "uHuman.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

template <>
cCamExParamLockCore<cCamExParamAnim>::MyDTI cCamExParamLockCore<cCamExParamAnim>::DTI;
inline void cCamExParamAnimTar::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cCamExParamAnimTar::DTI)->memFree(p_addr);
}

void* cCamExParamAnimTar::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(cCamExParamAnimTar::DTI)->memAlloc(sz, align, cCamExParamAnimTar::DTI.getID());
}

const MtDTI& cCamExParamAnimTar::getDTI() const {
    return cCamExParamAnimTar::DTI;
}

cCamExParamAnimTar::~cCamExParamAnimTar() {
}

void cCamExParamAnimTar::createProperty(MtPropertyList& s) {
    this->::cCamExParamLockCore<cCamExParamAnim>::createProperty(s);
}

inline cCamExParamAnimTar::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

template <>
inline cCamExParamLockCore<cCamExParamAnim>::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

template <>
MtObject* cCamExParamLockCore<cCamExParamAnim>::MyDTI::newInstance() const {
    return nullptr;
}

MtObject* cCamExParamAnimTar::MyDTI::newInstance() const {
    return new (16u) cCamExParamAnimTar;
}

const MtDTI& cCamExParamAnim::getDTI() const {
    return cCamExParamAnim::DTI;
}

void* cCamExParamAnim::operator new(size_t sz, u32 align) {
    return cCamExParamAnim::getAllocator()->memAlloc(sz, align, cCamExParamAnim::DTI.getID());
}

inline void cCamExParamAnim::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cCamExParamAnim::DTI)->memFree(p_addr);
}

__attribute__((weak)) void cCamExParamAnim::createProperty(MtPropertyList& s) {
    createPropertyCommon(s);
    createPropertyCameraTarget(s);
    createPropertyCoord(s);
    createPropertyInterporate(s);
    createPropertyCtrl(s);
    createPropertyChangeInterporate(s);
    createPropertyAdjust(s);
    createPropertyEx(s);
    s << MtProperty(static_cast<MtObject*>(this), "mOptionFlag", &mOptionFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCameraInfoList", static_cast<MtObject*>(&mCameraInfoList), 0u, 0u);
}

cCamExParamAnim::cCamExParamAnim() {
    mOptionFlag = 1u;
    this->::cCamExParam::mType = static_cast<nCameraGame::CAMERA_TYPE>(7);
    mStartInterType = static_cast<cCamInterPreset::INTER_TYPE>(3);
    mEndInterType = static_cast<cCamInterPreset::INTER_TYPE>(3);
    mCameraInfoList.setAutoDelete(true);
    mScrAdjustFlag = 248u;
}

cCamExParamAnim::~cCamExParamAnim() {
}

__attribute__((weak)) cCamImpBase* cCamExParamAnim::createCamImpInstance(uCameraGame* pCamera) const {
    DDON_STUB("cCamExParamAnim::createCamImpInstance")
    return nullptr;
}

__attribute__((weak)) void cCamExParamAnim::copy(const cCamExParam* pParam) {
    DDON_STUB("cCamExParamAnim::copy")
    /* stub */
}

inline cCamExParamAnim::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamExParamAnim::MyDTI cCamExParamAnim::DTI("cCamExParamAnim", &::cCamExParam::DTI, 512ul, 0u, 0u);

__attribute__((weak)) MtObject* cCamExParamAnim::MyDTI::newInstance() const {
    return new (16u) cCamExParamAnim;
}

const MtDTI& cCamExParamAnim2::getDTI() const {
    return cCamExParamAnim2::DTI;
}

void* cCamExParamAnim2::operator new(size_t sz, u32 align) {
    return cCamExParamAnim2::getAllocator()->memAlloc(sz, align, cCamExParamAnim2::DTI.getID());
}

inline void cCamExParamAnim2::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cCamExParamAnim2::DTI)->memFree(p_addr);
}

void cCamExParamAnim2::createProperty(MtPropertyList& s) {
    this->cCamExParamAnim::createProperty(s);
}

cCamExParamAnim2::~cCamExParamAnim2() {
}

__attribute__((weak)) cCamImpBase* cCamExParamAnim2::createCamImpInstance(uCameraGame* pCamera) const {
    DDON_STUB("cCamExParamAnim2::createCamImpInstance")
    return nullptr;
}

__attribute__((weak)) void cCamExParamAnim2::copy(const cCamExParam* pParam) {
    DDON_STUB("cCamExParamAnim2::copy")
    /* stub */
}

inline cCamExParamAnim2::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamExParamAnim2::MyDTI cCamExParamAnim2::DTI("cCamExParamAnim2", &::cCamExParamAnim::DTI, 512ul, 0u, 0u);

cCamExParamAnimTar::MyDTI cCamExParamAnimTar::DTI("cCamExParamAnimTar", &::cCamExParamLockCore<cCamExParamAnim>::DTI, 608ul, 0u, 0u);

template <>
cCamExParamLockCore<cCamExParamAnim>::MyDTI cCamExParamLockCore<cCamExParamAnim>::DTI("cCamExParamLockCore<cCamExParamAnim>", &::cCamExParamAnim::DTI, 608ul, 0u, 3u);

__attribute__((weak)) MtObject* cCamExParamAnim2::MyDTI::newInstance() const {
    return new (16u) cCamExParamAnim2;
}

const MtDTI& cCamImpAnim::getDTI() const {
    return cCamImpAnim::DTI;
}

cCamImpAnim::cCamImpAnim() {
    DDON_STUB("cCamImpAnim::cCamImpAnim")
    /* stub */
}

cCamImpAnim::~cCamImpAnim() {
}

__attribute__((weak)) void cCamImpAnim::initSub(MtVector3& cameraPos, MtVector3& targetPos, f32& angX, f32& angY) {
    DDON_STUB("cCamImpAnim::initSub")
    /* stub */
}

__attribute__((weak)) void cCamImpAnim::ctrlSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
}

__attribute__((weak)) void cCamImpAnim::moveSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
    DDON_STUB("cCamImpAnim::moveSub")
    /* stub */
}

void cCamImpAnim::interporateSub(MtVector3& cameraPos, MtVector3& targetPos) {
    uCameraGame* t0 = mpC;
    cameraPos = t0->mIdealPosCam;
    targetPos = t0->mIdealPosTar;
}

__attribute__((weak)) void cCamImpAnim::adjustSub(MtVector3& cameraPos, MtVector3& targetPos, MtVector3& idealCam, MtVector3& idealTar) {
}

void cCamImpAnim::finalSub() {
    if (mQuake > -1) {
        mQuake = -1;
        static_cast<sCameraExt*>(sCamera::getInstance())->cancelQuakeTask(7ul);
    }
    mpC->killMotionBlurFilter();
}

nCameraGame::CAMERA_TYPE cCamImpAnim::getType() const {
    return nCameraGame::TYPE_ANIM;
}

__attribute__((weak)) void cCamImpAnim::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("cCamImpAnim::applyWorldOffset")
    /* stub */
}

void cCamImpAnim::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mTimer", &mTimer, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSeqNum", &mSeqNum, 0u, 0u);
}

__attribute__((weak)) uintptr cCamImpAnim::HermiteExport(u32 seqNum, const cCameraSeqInfo* seqList, u8* pAnimDatBuff) {
    DDON_STUB("cCamImpAnim::HermiteExport")
    return {};
}

__attribute__((weak)) s32 cCamImpAnim::getAnimationParam(f32 time, cCameraSeqInfo& reInfo, f32& rate) {
    DDON_STUB("cCamImpAnim::getAnimationParam")
    return {};
}

f32 cCamImpAnim::adjustAddPlayerHeight(f32 addHeight) {
    return 0.8f * addHeight;
}

__attribute__((weak)) void cCamImpAnim::updateInitMat(bool isRotate) {
    DDON_STUB("cCamImpAnim::updateInitMat")
    /* stub */
}

inline cCamImpAnim::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamImpAnim::MyDTI cCamImpAnim::DTI("cCamImpAnim", &::cCamImpBase::DTI, 7616ul, 0u, 0u);

__attribute__((weak)) MtObject* cCamImpAnim::MyDTI::newInstance() const {
    DDON_STUB("cCamImpAnim::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cCamImpAnimTar::getDTI() const {
    return cCamImpAnimTar::DTI;
}

cCamImpAnimTar::~cCamImpAnimTar() {
    DDON_STUB("cCamImpAnimTar::~cCamImpAnimTar")
    /* stub */
}

void cCamImpAnimTar::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    mInterLockPos.mNow.x = offset.x + mInterLockPos.mNow.x;
    mInterLockPos.mNow.y = offset.y + mInterLockPos.mNow.y;
    mInterLockPos.mNow.z = offset.z + mInterLockPos.mNow.z;
}

__attribute__((weak)) bool cCamImpAnimTar::calcAnimTarPos(MtVector3& lockonPos) {
    DDON_STUB("cCamImpAnimTar::calcAnimTarPos")
    return {};
}

__attribute__((weak)) void cCamImpAnimTar::initSub(MtVector3& cameraPos, MtVector3& targetPos, f32& angX, f32& angY) {
    DDON_STUB("cCamImpAnimTar::initSub")
    /* stub */
}

__attribute__((weak)) void cCamImpAnimTar::ctrlSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
}

__attribute__((weak)) void cCamImpAnimTar::moveSub(MtVector3& idealCam, MtVector3& idealTar, f32& angX, f32& angY) {
    DDON_STUB("cCamImpAnimTar::moveSub")
    /* stub */
}

void cCamImpAnimTar::interporateSub(MtVector3& cameraPos, MtVector3& targetPos) {
    uCameraGame* t0 = mpC;
    cameraPos = t0->mIdealPosCam;
    targetPos = t0->mIdealPosTar;
}

void cCamImpAnimTar::adjustSub(MtVector3& cameraPos, MtVector3& targetPos, MtVector3& idealCam, MtVector3& idealTar) {
    mpC->dodgeScroll();
}

__attribute__((weak)) void cCamImpAnimTar::finalSub() {
}

nCameraGame::CAMERA_TYPE cCamImpAnimTar::getType() const {
    return nCameraGame::TYPE_ANIM_T;
}

inline cCamImpAnimTar::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCamImpAnimTar::MyDTI cCamImpAnimTar::DTI("cCamImpAnimTar", &::cCamImpAnim::DTI, 7744ul, 0u, 0u);

__attribute__((weak)) MtObject* cCamImpAnimTar::MyDTI::newInstance() const {
    DDON_STUB("cCamImpAnimTar::MyDTI::newInstance")
    return nullptr;
}

