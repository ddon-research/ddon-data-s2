// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpShlShotCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtSynchronize.h"
#include "../../XFramework/cArea.h"
#include "cContextInterface.h"
#include "cContextPlayerInfo.h"
#include "cDelegate.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "cpErosionEnemyBase.h"
#include "cpObjCollision.h"
#include "nDDOUtility.h"
#include "nHumanMsg.h"
#include "rShotReqInfo2.h"
#include "../../XFramework/sArea.h"
#include "sLockOnManager.h"
#include "../../XFramework/sMain.h"
#include "sObjCondition.h"
#include "sSetManager.h"
#include "sShlManager.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uEnemy.h"
#include "uHuman.h"
#include "../../XFramework/uModel.h"
#include "uShlBase.h"
#include "uShlHoming.h"
#include "uShlSpeed.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpShlShotCtrl::getDTI() const {
    return cpShlShotCtrl::DTI;
}

void* cpShlShotCtrl::operator new(size_t sz, u32 align) {
    return cpShlShotCtrl::getAllocator()->memAlloc(sz, align, cpShlShotCtrl::DTI.getID());
}

cpShlShotCtrl::cpShlShotCtrl() {
    DDON_STUB("cpShlShotCtrl::cpShlShotCtrl")
    /* stub */
}

__attribute__((noinline)) cpShlShotCtrl::~cpShlShotCtrl() {
    DDON_STUB("cpShlShotCtrl::~cpShlShotCtrl")
    /* stub */
}

__attribute__((weak)) void cpShlShotCtrl::setup() {
    DDON_STUB("cpShlShotCtrl::setup")
    /* stub */
}

__attribute__((weak)) void cpShlShotCtrl::move() {
    DDON_STUB("cpShlShotCtrl::move")
    /* stub */
}

void cpShlShotCtrl::updatePtr() {
    this->cpComponent::updatePtr();
    if (mpShlOwner == nullptr) {
        return;
    }
    if (mpShlOwner->isEnable()) {
        return;
    }
    mpShlOwner = nullptr;
}

__attribute__((weak)) void cpShlShotCtrl::after() {
    DDON_STUB("cpShlShotCtrl::after")
    /* stub */
}

__attribute__((weak)) void cpShlShotCtrl::createProperty(MtPropertyList& s) {
}

__attribute__((weak)) uShlBase* cpShlShotCtrl::shotShell(cpShlShotCtrl::cShlShotReqInfo* pInfo) {
    DDON_STUB("cpShlShotCtrl::shotShell")
    return nullptr;
}

__attribute__((weak)) void cpShlShotCtrl::requestShotShellFromResource(u32 index) {
    DDON_STUB("cpShlShotCtrl::requestShotShellFromResource")
    /* stub */
}

__attribute__((weak)) bool cpShlShotCtrl::requestShotShellFromResource2(u32 index) {
    DDON_STUB("cpShlShotCtrl::requestShotShellFromResource2")
    return {};
}

__attribute__((weak)) bool cpShlShotCtrl::selectShotInfo(u32 index, cShotReqInfo2::SHOT_REQ_INFO* info) {
    DDON_STUB("cpShlShotCtrl::selectShotInfo")
    return {};
}

__attribute__((weak)) void cpShlShotCtrl::setShotReqInfo2(rShotReqInfo2* pParam) {
    DDON_STUB("cpShlShotCtrl::setShotReqInfo2")
    /* stub */
}

__attribute__((weak)) uShlBase* cpShlShotCtrl::requestShotShell(cpShlShotCtrl::cShlShotReqInfo& info, bool isNow) {
    DDON_STUB("cpShlShotCtrl::requestShotShell")
    return nullptr;
}

__attribute__((weak)) void cpShlShotCtrl::setShlParamList(rShlParamList* pParam) {
    DDON_STUB("cpShlShotCtrl::setShlParamList")
    /* stub */
}

__attribute__((weak)) void cpShlShotCtrl::setCommonShlParamList(rShlParamList* pParam) {
    DDON_STUB("cpShlShotCtrl::setCommonShlParamList")
    /* stub */
}

__attribute__((weak)) void cpShlShotCtrl::setShotReqInfo(rShotReqInfo* pParam) {
    DDON_STUB("cpShlShotCtrl::setShotReqInfo")
    /* stub */
}

void cpShlShotCtrl::registShellRequestMsg(const nHuman::stShellRequestMsg& srcMsg) {
    bool* v0_0 = &mShlReqArray.elems[0].mIsSeted;
    for (unsigned int i0_1 = 0; i0_1 <= 7u; v0_0 += 20, i0_1 = i0_1 + 1u) {
        if (!(*v0_0)) {
            mShlReqArray.elems[i0_1].mReqMsg.mShlOwnerUID = srcMsg.mShlOwnerUID;
            mShlReqArray.elems[i0_1].mReqMsg.mTargetUID = srcMsg.mTargetUID;
            mShlReqArray.elems[i0_1].mReqMsg.mShotSys = srcMsg.mShotSys;
            mShlReqArray.elems[i0_1].mReqMsg.mShotGroup = srcMsg.mShotGroup;
            mShlReqArray.elems[i0_1].mReqMsg.mShotIndex = srcMsg.mShotIndex;
            mShlReqArray.elems[i0_1].mReqMsg.mLockOnIndex = srcMsg.mLockOnIndex;
            *v0_0 = true;
            return;
        }
    }
}

__attribute__((weak)) void cpShlShotCtrl::checkShellRequest() {
    DDON_STUB("cpShlShotCtrl::checkShellRequest")
    /* stub */
}

inline cpShlShotCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpShlShotCtrl::MyDTI cpShlShotCtrl::DTI("cpShlShotCtrl", &::cpComponent::DTI, 352ul, 0u, 0u);

__attribute__((weak)) MtObject* cpShlShotCtrl::MyDTI::newInstance() const {
    DDON_STUB("cpShlShotCtrl::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cpShlShotCtrl::cShlShotReqInfo::getDTI() const {
    return cpShlShotCtrl::cShlShotReqInfo::DTI;
}

cpShlShotCtrl::cShlShotReqInfo::~cShlShotReqInfo() {
    return;
}

__attribute__((weak)) void cpShlShotCtrl::cShlShotReqInfo::createProperty(MtPropertyList& s) {
}

void cpShlShotCtrl::cShlShotReqInfo::copyParam(const cpShlShotCtrl::cShlShotReqInfo& info) {
    mPos.x = info.mPos.x;
    mPos.y = info.mPos.y;
    mPos.z = info.mPos.z;
    mPos.pad_ = 0.0f;
    mDirection.x = info.mDirection.x;
    mDirection.y = info.mDirection.y;
    mDirection.z = info.mDirection.z;
    mDirection.pad_ = 0.0f;
    mTargetPos.x = info.mTargetPos.x;
    mTargetPos.y = info.mTargetPos.y;
    mTargetPos.z = info.mTargetPos.z;
    mTargetPos.pad_ = 0.0f;
    mTargetUId = info.mTargetUId;
    mLockOnIndex = info.mLockOnIndex;
    mShlUId = info.mShlUId;
    mShotGroup = info.mShotGroup;
    mShotIndex = info.mShotIndex;
    mShotTimer = info.mShotTimer;
    mIsCalcDirTargetPos = info.mIsCalcDirTargetPos;
    mShotSts_Guard = info.getShotStsPrivate();
    mIsInherit = info.mIsInherit;
    mIsNotifyDelete = info.mIsNotifyDelete;
    mWork = info.mWork;
    const bool t0 = info.mIsUseShotCoordMatrix;
    mIsUseShotCoordMatrix = t0;
    if (t0) {
        mShlMatrix.m[0].x = info.mShlMatrix.m[0].x;
        mShlMatrix.m[0].y = info.mShlMatrix.m[0].y;
        mShlMatrix.m[0].z = info.mShlMatrix.m[0].z;
        mShlMatrix.m[0].w = info.mShlMatrix.m[0].w;
        mShlMatrix.m[1].x = info.mShlMatrix.m[1].x;
        mShlMatrix.m[1].y = info.mShlMatrix.m[1].y;
        mShlMatrix.m[1].z = info.mShlMatrix.m[1].z;
        mShlMatrix.m[1].w = info.mShlMatrix.m[1].w;
        mShlMatrix.m[2].x = info.mShlMatrix.m[2].x;
        mShlMatrix.m[2].y = info.mShlMatrix.m[2].y;
        mShlMatrix.m[2].z = info.mShlMatrix.m[2].z;
        mShlMatrix.m[2].w = info.mShlMatrix.m[2].w;
        mShlMatrix.m[3].x = info.mShlMatrix.m[3].x;
        mShlMatrix.m[3].y = info.mShlMatrix.m[3].y;
        mShlMatrix.m[3].z = info.mShlMatrix.m[3].z;
        mShlMatrix.m[3].w = info.mShlMatrix.m[3].w;
    }
    mIsConst = info.mIsConst;
    mConstUId = info.mConstUId;
    mConstJoint = info.mConstJoint;
    mSharedUID[0] = info.mSharedUID[0];
    mSharedUID[1] = info.mSharedUID[1];
    mSharedUID[2] = info.mSharedUID[2];
    mSharedUID[3] = info.mSharedUID[3];
    mSharedUID[4] = info.mSharedUID[4];
    mSharedUID[5] = info.mSharedUID[5];
    mSharedUID[6] = info.mSharedUID[6];
    mSharedUID[7] = info.mSharedUID[7];
}

void cpShlShotCtrl::cShlShotReqInfo::copySharedUID(cpObjCollisionBase* pSrc) {
    if (pSrc == nullptr) {
        return;
    }
    mSharedUID[0] = pSrc->mSharedUID[0];
    mSharedUID[1] = pSrc->mSharedUID[1];
    mSharedUID[2] = pSrc->mSharedUID[2];
    mSharedUID[3] = pSrc->mSharedUID[3];
    mSharedUID[4] = pSrc->mSharedUID[4];
    mSharedUID[5] = pSrc->mSharedUID[5];
    mSharedUID[6] = pSrc->mSharedUID[6];
    mSharedUID[7] = pSrc->mSharedUID[7];
}

inline cpShlShotCtrl::cShlShotReqInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpShlShotCtrl::cShlShotReqInfo::MyDTI cpShlShotCtrl::cShlShotReqInfo::DTI("cpShlShotCtrl::cShlShotReqInfo", &::MtObject::DTI, 208ul, 0u, 0u);

MtObject* cpShlShotCtrl::cShlShotReqInfo::MyDTI::newInstance() const {
    return new (16u) cpShlShotCtrl::cShlShotReqInfo;
}

template MtTypedArray<cpShlShotCtrl::cShlShotReqInfo>::~MtTypedArray();

