// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlArrow.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "aStage.h"
#include "../../XFramework/cArea.h"
#include "cEfcHandle.h"
#include "cHitNode.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpMotionSe.h"
#include "cpObjCollision.h"
#include "cpOcdCtrl.h"
#include "cpShlShotCtrl.h"
#include "../../XFramework/nCollision.h"
#include "../../generated/shared/nDDOMath.h"
#include "nHumanMsg.h"
#include "../../generated/shared/nWeapon.h"
#include "../../XFramework/rCollision.h"
#include "../../XFramework/rCollisionHeightField.h"
#include "rEffectProvider.h"
#include "rObjCollision.h"
#include "../../XFramework/rSoundRequest.h"
#include "../../XFramework/sArea.h"
#include "../../XFramework/sCollision.h"
#include "sCollisionExt.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "uDDOModel.h"
#include "uShlBase.h"
#include "uShlSpeed.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamArrow::getDTI() const {
    return cShlParamArrow::DTI;
}

inline void cShlParamArrow::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamArrow::DTI)->memFree(p_addr);
}

MtDTI& cShlParamArrow::getShlDTI() const {
    return uShlArrow::DTI;
}

cShlParamArrow::~cShlParamArrow() {
}

void cShlParamArrow::createProperty(MtPropertyList& s) {
    this->cShlParamSpeed::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "isRepelled", &isRepelled, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "repelledDist", &repelledDist, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "canExplode", &canExplode, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "explodeShlType", &explodeShlType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "useModel", &useModel, 0u, 0u);
}

void cShlParamArrow::createPropertySE(MtPropertyList& s) {
    this->cShlParamSpeed::createPropertySE(s);
    s << MtProperty(static_cast<MtObject*>(this), "seNoMatHitSE", &seNoMatHitSE, 0u, 0u);
}

void cShlParamArrow::copy(const cShlParamBase* pParamBase) {
    this->cShlParamSpeed::copy(pParamBase);
    const cShlParamArrow* pParam = static_cast<const cShlParamArrow*>(pParamBase);
    canExplode = pParam->canExplode;
    isRepelled = pParam->isRepelled;
    repelledDist = pParam->repelledDist;
    seNoMatHitSE = pParam->seNoMatHitSE;
    explodeShlType = pParam->explodeShlType;
    useModel = pParam->useModel;
}

inline cShlParamArrow::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamArrow::MyDTI cShlParamArrow::DTI("cShlParamArrow", &::cShlParamSpeed::DTI, 512ul, 0u, 0u);

MtObject* cShlParamArrow::MyDTI::newInstance() const {
    return new (16u) cShlParamArrow;
}

const MtDTI& cShlParamArrowInc::getDTI() const {
    return cShlParamArrowInc::DTI;
}

MtDTI& cShlParamArrowInc::getShlDTI() const {
    return uShlArrowInc::DTI;
}

cShlParamArrowInc::~cShlParamArrowInc() {
}

void cShlParamArrowInc::createProperty(MtPropertyList& s) {
    this->cShlParamBase::createProperty(s);
}

void cShlParamArrowInc::copy(const cShlParamBase* pParamBase) {
    this->cShlParamBase::copy(pParamBase);
}

inline cShlParamArrowInc::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamArrowInc::MyDTI cShlParamArrowInc::DTI("cShlParamArrowInc", &::cShlParamBase::DTI, 352ul, 0u, 0u);

MtObject* cShlParamArrowInc::MyDTI::newInstance() const {
    return new (16u) cShlParamArrowInc;
}

const MtDTI& uShlArrow::getDTI() const {
    return uShlArrow::DTI;
}

const cShlParamArrow* uShlArrow::getShlParam() const {
    return static_cast<const cShlParamArrow*>(getShlParamBase());
}

uShlArrow::~uShlArrow() {
}

void uShlArrow::setup() {
    this->uShlSpeed::setup();
    if ((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(getShlParamBase()) + 493)) == 0) {
        return;
    }
    uDDOModel* t0 = mpOwner;
    if (t0 == nullptr) {
        return;
    }
    if (t0->isEnable()) {
        if ((t0->mUnitId & 16u) != 0) {
            if (t0->getOcdCtrlPtr()->isOcdActive(12292u)) {
                unsigned long t1 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 13376);
                if (t1 != 0) {
                    if (static_cast<unsigned char>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 40)) + 255) <= 9) {
                        u32 t2 = nHuman::getJobArrayIndex(static_cast<nHuman::JOB_ENUM>(*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t1) + 40)));
                        if (static_cast<int>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>((t1 + (static_cast<unsigned long>(t2) * 80)) + (static_cast<unsigned long>(nHuman::getCustomSkillIdArrayIndex(nHuman::CUSTOM_SKILL_ID_07)) * 4)) + 2376)) > 5) {
                            mExplosionLv = 2;
                        } else {
                            mExplosionLv = 1;
                        }
                        mExplosionType = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(getShlParamBase()) + 504);
                    } else {
                        mExplosionLv = 1;
                        mExplosionType = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(getShlParamBase()) + 504);
                    }
                } else {
                    mExplosionLv = 1;
                    mExplosionType = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(getShlParamBase()) + 504);
                }
            }
        }
    }
}

__attribute__((weak)) void uShlArrow::updateSub() {
    DDON_STUB("uShlArrow::updateSub")
    /* stub */
}

__attribute__((weak)) void uShlArrow::after() {
    DDON_STUB("uShlArrow::after")
    /* stub */
}

void uShlArrow::kill() {
    if (mprSECmn != nullptr) {
        mprSECmn->release();
        mprSECmn = nullptr;
    }
    if (mpEfcExplosionHandle != nullptr) {
        static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(mpEfcExplosionHandle, 4u);
        mpEfcExplosionHandle = nullptr;
    }
    this->uShlSpeed::kill();
}

void uShlArrow::updateEfcHandle() {
    this->uShlSpeed::updateEfcHandle();
    if (mpEfcExplosionHandle == nullptr) {
        return;
    }
    if (!static_cast<sEffectExt*>(sEffect::getInstance())->isInvalidHandle(mpEfcExplosionHandle)) {
        return;
    }
    mpEfcExplosionHandle->mpOwner = nullptr;
    mpEfcExplosionHandle = nullptr;
}

void uShlArrow::floorHit(const MtVector3& hitPos) {
    setSPShl();
}

__attribute__((weak)) void uShlArrow::setShlEfct() {
    DDON_STUB("uShlArrow::setShlEfct")
    /* stub */
}

__attribute__((weak)) void uShlArrow::requestShotSE() {
    DDON_STUB("uShlArrow::requestShotSE")
    /* stub */
}

__attribute__((weak)) void uShlArrow::setSPShl() {
    DDON_STUB("uShlArrow::setSPShl")
    /* stub */
}

void uShlArrow::requestSpLandHitSE(sCollision::TriangleInfo* info) {
    const unsigned int t0 = *reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(getShlParamBase()) + 500);
    if (static_cast<int>(t0) > -1) {
        cArea* t1 = sArea::getInstance()->mpArea[2];
        if (t1 != nullptr) {
            if (mpOwner != nullptr) {
                if ((mpOwner->mUnitId & 16u) != 0) {
                    if (info->HitHeightFieldHandle != 0xFFFFFFFFu) {
                        u32 reqNo = static_cast<aStage*>(t1)->getSoundAttributeRequestSeNo(t0, sCollision::getInstance()->getSbcHeightFieldByHandle(info->HitHeightFieldHandle)->getHeightFieldResource()->getGridMaterial(static_cast<u32>(info->HitHeightFieldU), static_cast<u32>(info->HitHeightFieldV), info->HitHeightFieldTriID).attr[0]);
                        cArea* t2 = sArea::getInstance()->mpArea[2];
                        if (info->HitHeightFieldHandle != 0xFFFFFFFFu) {
                            rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(sCollision::getInstance()->getSbcHeightFieldByHandle(info->HitHeightFieldHandle)->getHeightFieldResource()->getGridMaterial(static_cast<u32>(info->HitHeightFieldU), static_cast<u32>(info->HitHeightFieldV), info->HitHeightFieldTriID).attr[0], info->hit_pos);
                            static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                        } else {
                            if (info->pPartsInfo != nullptr) {
                                rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(info->pMaterialInfo->attr[0], info->hit_pos);
                                static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                            } else {
                                if (info->pHitScrGeometry != nullptr) {
                                    rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(info->getBasicCollisionUserAttribute(0u), info->hit_pos);
                                    static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                                } else {
                                    if (info->isHitDynamicSbc()) {
                                        rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(info->getDynamicSbcUserAttribute(0u), info->hit_pos);
                                        static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                                    } else {
                                        rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(0x3FFFFFFFu, info->hit_pos);
                                        static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                                    }
                                }
                            }
                        }
                    } else {
                        if (info->pPartsInfo != nullptr) {
                            u32 reqNo = static_cast<aStage*>(t1)->getSoundAttributeRequestSeNo(t0, info->pMaterialInfo->attr[0]);
                            cArea* t2 = sArea::getInstance()->mpArea[2];
                            if (info->HitHeightFieldHandle != 0xFFFFFFFFu) {
                                rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(sCollision::getInstance()->getSbcHeightFieldByHandle(info->HitHeightFieldHandle)->getHeightFieldResource()->getGridMaterial(static_cast<u32>(info->HitHeightFieldU), static_cast<u32>(info->HitHeightFieldV), info->HitHeightFieldTriID).attr[0], info->hit_pos);
                                static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                            } else {
                                if (info->pPartsInfo != nullptr) {
                                    rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(info->pMaterialInfo->attr[0], info->hit_pos);
                                    static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                                } else {
                                    if (info->pHitScrGeometry != nullptr) {
                                        rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(info->getBasicCollisionUserAttribute(0u), info->hit_pos);
                                        static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                                    } else {
                                        if (info->isHitDynamicSbc()) {
                                            rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(info->getDynamicSbcUserAttribute(0u), info->hit_pos);
                                            static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                                        } else {
                                            rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(0x3FFFFFFFu, info->hit_pos);
                                            static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                                        }
                                    }
                                }
                            }
                        } else {
                            if (info->pHitScrGeometry != nullptr) {
                                u32 reqNo = static_cast<aStage*>(t1)->getSoundAttributeRequestSeNo(t0, info->getBasicCollisionUserAttribute(0u));
                                cArea* t2 = sArea::getInstance()->mpArea[2];
                                if (info->HitHeightFieldHandle != 0xFFFFFFFFu) {
                                    rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(sCollision::getInstance()->getSbcHeightFieldByHandle(info->HitHeightFieldHandle)->getHeightFieldResource()->getGridMaterial(static_cast<u32>(info->HitHeightFieldU), static_cast<u32>(info->HitHeightFieldV), info->HitHeightFieldTriID).attr[0], info->hit_pos);
                                    static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                                } else {
                                    if (info->pPartsInfo != nullptr) {
                                        rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(info->pMaterialInfo->attr[0], info->hit_pos);
                                        static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                                    } else {
                                        if (info->pHitScrGeometry != nullptr) {
                                            rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(info->getBasicCollisionUserAttribute(0u), info->hit_pos);
                                            static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                                        } else {
                                            if (info->isHitDynamicSbc()) {
                                                rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(info->getDynamicSbcUserAttribute(0u), info->hit_pos);
                                                static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                                            } else {
                                                rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(0x3FFFFFFFu, info->hit_pos);
                                                static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                                            }
                                        }
                                    }
                                }
                            } else {
                                if (info->isHitDynamicSbc()) {
                                    u32 reqNo = static_cast<aStage*>(t1)->getSoundAttributeRequestSeNo(t0, info->getDynamicSbcUserAttribute(0u));
                                    cArea* t2 = sArea::getInstance()->mpArea[2];
                                    if (info->HitHeightFieldHandle != 0xFFFFFFFFu) {
                                        rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(sCollision::getInstance()->getSbcHeightFieldByHandle(info->HitHeightFieldHandle)->getHeightFieldResource()->getGridMaterial(static_cast<u32>(info->HitHeightFieldU), static_cast<u32>(info->HitHeightFieldV), info->HitHeightFieldTriID).attr[0], info->hit_pos);
                                        static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                                    } else {
                                        if (info->pPartsInfo != nullptr) {
                                            rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(info->pMaterialInfo->attr[0], info->hit_pos);
                                            static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                                        } else {
                                            if (info->pHitScrGeometry != nullptr) {
                                                rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(info->getBasicCollisionUserAttribute(0u), info->hit_pos);
                                                static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                                            } else {
                                                if (info->isHitDynamicSbc()) {
                                                    rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(info->getDynamicSbcUserAttribute(0u), info->hit_pos);
                                                    static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                                                } else {
                                                    rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(0x3FFFFFFFu, info->hit_pos);
                                                    static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    u32 reqNo = static_cast<aStage*>(t1)->getSoundAttributeRequestSeNo(t0, 0x3FFFFFFFu);
                                    cArea* t2 = sArea::getInstance()->mpArea[2];
                                    if (info->HitHeightFieldHandle != 0xFFFFFFFFu) {
                                        rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(sCollision::getInstance()->getSbcHeightFieldByHandle(info->HitHeightFieldHandle)->getHeightFieldResource()->getGridMaterial(static_cast<u32>(info->HitHeightFieldU), static_cast<u32>(info->HitHeightFieldV), info->HitHeightFieldTriID).attr[0], info->hit_pos);
                                        static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                                    } else {
                                        if (info->pPartsInfo != nullptr) {
                                            rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(info->pMaterialInfo->attr[0], info->hit_pos);
                                            static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                                        } else {
                                            if (info->pHitScrGeometry != nullptr) {
                                                rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(info->getBasicCollisionUserAttribute(0u), info->hit_pos);
                                                static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                                            } else {
                                                if (info->isHitDynamicSbc()) {
                                                    rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(info->getDynamicSbcUserAttribute(0u), info->hit_pos);
                                                    static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
                                                } else {
                                                    rSoundRequest* t3 = static_cast<aStage*>(t2)->getSoundAttributeRequest(0x3FFFFFFFu, info->hit_pos);
                                                    static_cast<sSoundExt*>(sSound::getInstance())->requestSeEx(t3, reqNo, static_cast<MtObject*>(this), info->hit_pos);
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

__attribute__((weak)) void uShlArrow::setWaterHitEfct(const MtVector3& pos) {
    DDON_STUB("uShlArrow::setWaterHitEfct")
    /* stub */
}

inline uShlArrow::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlArrow::MyDTI uShlArrow::DTI("uShlArrow", &::uShlSpeed::DTI, 11200ul, 0u, 0u);

MtObject* uShlArrow::MyDTI::newInstance() const {
    return new (16u) uShlArrow;
}

const MtDTI& uShlArrowInc::getDTI() const {
    return uShlArrowInc::DTI;
}

uShlArrowInc::~uShlArrowInc() {
}

void uShlArrowInc::setup() {
    this->uShlBase::setup();
}

void uShlArrowInc::updateSub() {
    this->uShlBase::updateSub();
    if (getParent() != nullptr) {
        mPos.x = getParent()->mPos.x;
        mPos.y = getParent()->mPos.y;
        mPos.z = getParent()->mPos.z;
        mPos.pad_ = 0.0f;
    } else {
        requestKill();
    }
}

void uShlArrowInc::kill() {
    this->uShlBase::kill();
}

inline uShlArrowInc::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlArrowInc::MyDTI uShlArrowInc::DTI("uShlArrowInc", &::uShlBase::DTI, 10928ul, 0u, 0u);

MtObject* uShlArrowInc::MyDTI::newInstance() const {
    return new (16u) uShlArrowInc;
}

