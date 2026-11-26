// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlMgcArrowErosion.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtRandom.h"
#include "cGeneralPoint.h"
#include "cGeneralPointPtr.h"
#include "../../XFramework/cUnit.h"
#include "cpCorePointCtrl.h"
#include "cpHpDamageCtrl.h"
#include "cpLockOn.h"
#include "cpObjCollision.h"
#include "cpShlShotCtrl.h"
#include "rEffectProvider.h"
#include "../../XFramework/sCollision.h"
#include "sCollisionExt.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "sLockOnManager.h"
#include "sSetManager.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uEnemy.h"
#include "uShlBase.h"
#include "uShlHoming.h"
#include "uShlSpeed.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamConstErosion::getDTI() const {
    return cShlParamConstErosion::DTI;
}

inline void* cShlParamConstErosion::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamConstErosion::DTI)->memAlloc(sz, align, cShlParamConstErosion::DTI.getID());
}

inline void cShlParamConstErosion::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamConstErosion::DTI)->memFree(p_addr);
}

MtDTI& cShlParamConstErosion::getShlDTI() const {
    return uShlConstErosion::DTI;
}

void cShlParamConstErosion::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
    const cShlParamConstErosion* pParam = static_cast<const cShlParamConstErosion*>(pParamBase);
    mOnlyAttackLockOnTarget = pParam->mOnlyAttackLockOnTarget;
    mIsConstLockOnTarget = pParam->mIsConstLockOnTarget;
}

void cShlParamConstErosion::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mOnlyAttackLockOnTarget", &mOnlyAttackLockOnTarget, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsConstLockOnTarget", &mIsConstLockOnTarget, 0u, 0u);
}

void cShlParamConstErosion::createPropertyEffect(MtPropertyList& s) {
    this->cShlParamBase::createPropertyEffect(s);
}

inline cShlParamConstErosion::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamConstErosion::MyDTI cShlParamConstErosion::DTI("cShlParamConstErosion", &::cShlParamBase::DTI, 368ul, 0u, 0u);

MtObject* cShlParamConstErosion::MyDTI::newInstance() const {
    return new (16u) cShlParamConstErosion;
}

const MtDTI& cShlParamMgcArrowErosion::getDTI() const {
    return cShlParamMgcArrowErosion::DTI;
}

inline void cShlParamMgcArrowErosion::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamMgcArrowErosion::DTI)->memFree(p_addr);
}

MtDTI& cShlParamMgcArrowErosion::getShlDTI() const {
    return uShlMgcArrowErosion::DTI;
}

__attribute__((weak)) void cShlParamMgcArrowErosion::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamMgcArrowErosion::copy")
    /* stub */
}

void cShlParamMgcArrowErosion::createProperty(MtPropertyList& s) {
    this->cShlParamHoming::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mUpdateKill", &mUpdateKill, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOnlyAttackLockOnTarget", &mOnlyAttackLockOnTarget, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsConstLockOnTarget", &mIsConstLockOnTarget, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mScrCheckHeight", &mScrCheckHeight, 0u, 0u);
}

void cShlParamMgcArrowErosion::createPropertyEffect(MtPropertyList& s) {
    this->cShlParamSpeed::createPropertyEffect(s);
    s << MtProperty(static_cast<MtObject*>(this), "mLandEffect", &mLandEffect, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLandEffectNo", &mLandEffectNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLandEffectTimer", &mLandEffectTimer, 0u, 0u);
}

void cShlParamMgcArrowErosion::createPropertySE(MtPropertyList& s) {
    this->cShlParamHoming::createPropertySE(s);
    s << MtProperty(static_cast<MtObject*>(this), "mLandSeNo", &mLandSeNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEffectTimesPerLandSe", &mEffectTimesPerLandSe, 0u, 0u);
}

inline cShlParamMgcArrowErosion::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamMgcArrowErosion::MyDTI cShlParamMgcArrowErosion::DTI("cShlParamMgcArrowErosion", &::cShlParamHoming::DTI, 624ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamMgcArrowErosion::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamMgcArrowErosion::DTI)->memAlloc(sizeof(cShlParamMgcArrowErosion), 16u, cShlParamMgcArrowErosion::DTI.getID())) cShlParamMgcArrowErosion;
}

const MtDTI& cShlParamMgcArrowErosionCtrl::getDTI() const {
    return cShlParamMgcArrowErosionCtrl::DTI;
}

inline void* cShlParamMgcArrowErosionCtrl::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShlParamMgcArrowErosionCtrl::DTI)->memAlloc(sz, align, cShlParamMgcArrowErosionCtrl::DTI.getID());
}

inline void cShlParamMgcArrowErosionCtrl::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamMgcArrowErosionCtrl::DTI)->memFree(p_addr);
}

MtDTI& cShlParamMgcArrowErosionCtrl::getShlDTI() const {
    return uShlMgcArrowErosionCtrl::DTI;
}

__attribute__((weak)) void cShlParamMgcArrowErosionCtrl::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamMgcArrowErosionCtrl::copy")
    /* stub */
}

void cShlParamMgcArrowErosionCtrl::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mShlNoShoot", &mShlNoShoot, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShlNoErosionNext", &mShlNoErosionNext, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShlNoErosionNextSameTarget", &mShlNoErosionNextSameTarget, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSearchDistance", &mSearchDistance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mErosionMaxCountForSameTarget", &mErosionMaxCountForSameTarget, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBeforeErosionShlTime", &mBeforeErosionShlTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBeforeErosionShlTimeArrow", &mBeforeErosionShlTimeArrow, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSameTargetErosionWaitTimer", &mSameTargetErosionWaitTimer, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAfterErosionShlTime", &mAfterErosionShlTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mErosionMaxCount", &mErosionMaxCount, 0u, 0u);
}

inline cShlParamMgcArrowErosionCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamMgcArrowErosionCtrl::MyDTI cShlParamMgcArrowErosionCtrl::DTI("cShlParamMgcArrowErosionCtrl", &::cShlParamBase::DTI, 400ul, 0u, 0u);

MtObject* cShlParamMgcArrowErosionCtrl::MyDTI::newInstance() const {
    return new (16u) cShlParamMgcArrowErosionCtrl;
}

const MtDTI& uShlConstErosion::getDTI() const {
    return uShlConstErosion::DTI;
}

inline void* uShlConstErosion::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShlConstErosion::DTI)->memAlloc(sz, align, uShlConstErosion::DTI.getID());
}

inline void uShlConstErosion::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlConstErosion::DTI)->memFree(p_addr);
}

inline const cShlParamConstErosion* uShlConstErosion::getShlParam() const {
    return static_cast<const cShlParamConstErosion*>(mpShlParam2);
}

void uShlConstErosion::setup() {
    this->uShlBase::setup();
    const cShlParamBase* t0 = getShlParamBase();
    if (t0 == nullptr) {
        return;
    }
    if ((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(t0) + 352)) != 0) {
        if (mLockOnTarget.get() != nullptr) {
            uDDOModel* t1 = mLockOnTarget.get()->getDDOModelOwner();
            if (t1 != nullptr) {
                getObjCollisionPtr()->mGripAttackOnly.add(t1);
            }
            if ((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(t0) + 353)) != 0) {
                cGeneralPoint* t2 = mLockOnTarget.get();
                if (t2 != nullptr) {
                    uDDOModel* t3 = t2->getDDOModelOwner();
                    if (t3 != nullptr) {
                        setParent(static_cast<uCoord*>(t3), static_cast<s32>(t2->mJntNo));
                    }
                }
            }
        } else {
            if ((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(t0) + 353)) != 0) {
                cGeneralPoint* t2 = mLockOnTarget.get();
                if (t2 != nullptr) {
                    uDDOModel* t3 = t2->getDDOModelOwner();
                    if (t3 != nullptr) {
                        setParent(static_cast<uCoord*>(t3), static_cast<s32>(t2->mJntNo));
                    }
                }
            }
        }
    } else {
        if ((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(t0) + 353)) != 0) {
            cGeneralPoint* t2 = mLockOnTarget.get();
            if (t2 != nullptr) {
                uDDOModel* t3 = t2->getDDOModelOwner();
                if (t3 != nullptr) {
                    setParent(static_cast<uCoord*>(t3), static_cast<s32>(t2->mJntNo));
                }
            }
        }
    }
}

void uShlConstErosion::updatePtr() {
    this->uShlBase::updatePtr();
}

void uShlConstErosion::updateSub() {
    this->uShlBase::updateSub();
    if (mpShlParam2 == nullptr) {
        requestKill();
    }
}

inline uShlConstErosion::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlConstErosion::MyDTI uShlConstErosion::DTI("uShlConstErosion", &::uShlBase::DTI, 10928ul, 0u, 0u);

MtObject* uShlConstErosion::MyDTI::newInstance() const {
    return new (16u) uShlConstErosion;
}

const MtDTI& uShlMgcArrowErosion::getDTI() const {
    return uShlMgcArrowErosion::DTI;
}

inline void* uShlMgcArrowErosion::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShlMgcArrowErosion::DTI)->memAlloc(sz, align, uShlMgcArrowErosion::DTI.getID());
}

inline void uShlMgcArrowErosion::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlMgcArrowErosion::DTI)->memFree(p_addr);
}

inline const cShlParamMgcArrowErosion* uShlMgcArrowErosion::getShlParam() const {
    return static_cast<const cShlParamMgcArrowErosion*>(mpShlParam2);
}

inline uShlMgcArrowErosion::uShlMgcArrowErosion() {
    mpShlCtrl = nullptr;
    mFlgHitAttackTest = false;
    mLandEffectTimer = 0.0f;
    mOldEffectPos = MtVector3::Zero;
    mLandEffectCount = 0;
}

__attribute__((weak)) void uShlMgcArrowErosion::setup() {
    DDON_STUB("uShlMgcArrowErosion::setup")
    /* stub */
}

void uShlMgcArrowErosion::updatePtr() {
    this->uShlBase::updatePtr();
    if (mpShlCtrl == nullptr) {
        return;
    }
    if (mpShlCtrl->isEnable()) {
        return;
    }
    mpShlCtrl = nullptr;
}

void uShlMgcArrowErosion::updateSub() {
    this->uShlSpeed::updateSub();
    const cShlParamBase* t0 = getShlParamBase();
    if (t0 != nullptr) {
        if (mpOwner->isMaster()) {
            if ((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(t0) + 584)) != 0) {
                if (mpShlCtrl != nullptr) {
                    if (mFlgHitAttackTest) {
                        if ((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(t0) + 597)) != 0) {
                            updateLandEffect();
                        } else {
                            requestKill();
                        }
                    } else {
                        updateLandEffect();
                    }
                } else {
                    requestKill();
                }
            } else {
                if (mFlgHitAttackTest) {
                    if ((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(t0) + 597)) != 0) {
                        updateLandEffect();
                    } else {
                        requestKill();
                    }
                } else {
                    updateLandEffect();
                }
            }
        } else {
            if (mFlgHitAttackTest) {
                if ((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(t0) + 597)) != 0) {
                    updateLandEffect();
                } else {
                    requestKill();
                }
            } else {
                updateLandEffect();
            }
        }
    } else {
        requestKill();
    }
}

__attribute__((weak)) void uShlMgcArrowErosion::callbackAttack(cHitInfo* pInfo) {
    DDON_STUB("uShlMgcArrowErosion::callbackAttack")
    /* stub */
}

__attribute__((weak)) void uShlMgcArrowErosion::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uShlMgcArrowErosion::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) void uShlMgcArrowErosion::updateLandEffect() {
    DDON_STUB("uShlMgcArrowErosion::updateLandEffect")
    /* stub */
}

inline uShlMgcArrowErosion::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlMgcArrowErosion::MyDTI uShlMgcArrowErosion::DTI("uShlMgcArrowErosion", &::uShlHoming::DTI, 11280ul, 0u, 0u);

MtObject* uShlMgcArrowErosion::MyDTI::newInstance() const {
    return new (16u) uShlMgcArrowErosion;
}

const MtDTI& uShlMgcArrowErosionCtrl::getDTI() const {
    return uShlMgcArrowErosionCtrl::DTI;
}

inline void* uShlMgcArrowErosionCtrl::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShlMgcArrowErosionCtrl::DTI)->memAlloc(sz, align, uShlMgcArrowErosionCtrl::DTI.getID());
}

inline void uShlMgcArrowErosionCtrl::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlMgcArrowErosionCtrl::DTI)->memFree(p_addr);
}

inline const cShlParamMgcArrowErosionCtrl* uShlMgcArrowErosionCtrl::getShlParam() const {
    return static_cast<const cShlParamMgcArrowErosionCtrl*>(mpShlParam2);
}

void uShlMgcArrowErosionCtrl::setup() {
    this->uShlBase::setup();
    mErosionRno = 1;
}

__attribute__((weak)) void uShlMgcArrowErosionCtrl::updateSub() {
    DDON_STUB("uShlMgcArrowErosionCtrl::updateSub")
    /* stub */
}

void uShlMgcArrowErosionCtrl::updatePtr() {
    this->uShlBase::updatePtr();
    if (mpShlChild == nullptr) {
        return;
    }
    if (mpShlChild->isEnable()) {
        return;
    }
    mpShlChild = nullptr;
}

void uShlMgcArrowErosionCtrl::moveAfter() {
    this->uShlBase::moveAfter();
    if (!isMaster()) {
        return;
    }
    if (mErosionRno != 2) {
        return;
    }
    if (!mReqErosionInfo.mIsActive) {
        return;
    }
    mNowErosionInfo.mIsActive = true;
    mNowErosionInfo.mLockedOnNum = mReqErosionInfo.mLockedOnNum;
    mNowErosionInfo.mLockOnIndex[0] = mReqErosionInfo.mLockOnIndex[0];
    mNowErosionInfo.mTargetUID = mReqErosionInfo.mTargetUID;
    mNowErosionJnt = mReqErosionJnt;
    mReqErosionInfo.mLockOnIndex[9] = -1;
    mReqErosionInfo.mLockOnIndex[7] = -1;
    mReqErosionInfo.mLockOnIndex[8] = -1;
    mReqErosionInfo.mLockOnIndex[5] = -1;
    mReqErosionInfo.mLockOnIndex[6] = -1;
    mReqErosionInfo.mLockOnIndex[3] = -1;
    mReqErosionInfo.mLockOnIndex[4] = -1;
    mReqErosionInfo.mLockOnIndex[1] = -1;
    mReqErosionInfo.mLockOnIndex[2] = -1;
    mReqErosionInfo.mTargetUID = 0xFFFFFFFF;
    mReqErosionInfo.mLockOnIndex[0] = -1;
    mReqErosionInfo.mLockedOnNum = 0;
    mReqErosionInfo.mIsActive = false;
    mReqErosionJnt = -1;
}

__attribute__((weak)) bool uShlMgcArrowErosionCtrl::searchFunc(cpLockOn::cLockOnTarget* pLockOnTarget) {
    DDON_STUB("uShlMgcArrowErosionCtrl::searchFunc")
    return {};
}

static auto ddon_emit_0x01b1e570 __attribute__((used)) = &uShlMgcArrowErosionCtrl::searchFuncAttack;

__attribute__((weak)) void uShlMgcArrowErosionCtrl::moveErosionCtrl(bool& is_dead) {
    DDON_STUB("uShlMgcArrowErosionCtrl::moveErosionCtrl")
    /* stub */
}

__attribute__((weak)) s32 uShlMgcArrowErosionCtrl::getNowTargetNextLockOnID(s32& Jnt) {
    DDON_STUB("uShlMgcArrowErosionCtrl::getNowTargetNextLockOnID")
    return {};
}

inline uShlMgcArrowErosionCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlMgcArrowErosionCtrl::MyDTI uShlMgcArrowErosionCtrl::DTI("uShlMgcArrowErosionCtrl", &::uShlBase::DTI, 11648ul, 0u, 0u);

MtObject* uShlMgcArrowErosionCtrl::MyDTI::newInstance() const {
    return new (16u) uShlMgcArrowErosionCtrl;
}

