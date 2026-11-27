// Reconstructed from the game's DWARF debug information.
#include <new>
#include <math.h>
#include "cpOcdCtrl.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cContextInterface.h"
#include "cContextPlayerInfo.h"
#include "cDelegate.h"
#include "cEffectCycleCtrl.h"
#include "cHitInfoAfter.h"
#include "cOcdBadStatus.h"
#include "cOcdBase.h"
#include "cOcdCache.h"
#include "cOcdDamageInfo.h"
#include "cOcdInfo.h"
#include "cOcdMsgCtrl2.h"
#include "cOcdParamRes.h"
#include "cOcdPriority.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpActionManager.h"
#include "cpActionRequest.h"
#include "cpComponent.h"
#include "cpDDMrlMgr.h"
#include "cpHpDamageCtrl.h"
#include "../../generated/shared/nAction.h"
#include "../../generated/shared/nDDOShader.h"
#include "nDDOUtility.h"
#include "nObjCollision.h"
#include "nObjCondition.h"
#include "rAttackParam.h"
#include "rOcdElectricParam.h"
#include "rOcdIrAdj.h"
#include "rOcdParam.h"
#include "rOutlineParamList.h"
#include "../../XFramework/rSoundRequest.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "sObjCollision.h"
#include "sObjCondition.h"
#include "sQuestManagerExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "sWorkRate.h"
#include "uDDOModel.h"
#include "uEnemy.h"
#include "uHuman.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpOcdCtrl::getDTI() const {
    return cpOcdCtrl::DTI;
}

void* cpOcdCtrl::operator new(size_t sz, u32 align) {
    return cpOcdCtrl::getAllocator()->memAlloc(sz, align, cpOcdCtrl::DTI.getID());
}

cpOcdCtrl::cpOcdCtrl() {
    DDON_STUB("cpOcdCtrl::cpOcdCtrl")
    /* stub */
}

cpOcdCtrl::~cpOcdCtrl() {
    if (mpOcdStatusCommonParamRes != nullptr) {
        mpOcdStatusCommonParamRes->release();
        mpOcdStatusCommonParamRes = nullptr;
    }
    if (mpOcdStatusParamRes != nullptr) {
        mpOcdStatusParamRes->release();
        mpOcdStatusParamRes = nullptr;
    }
    if (mpOcdImmuneParamRes != nullptr) {
        mpOcdImmuneParamRes->release();
        mpOcdImmuneParamRes = nullptr;
    }
    if (mpOcdElectricParam == nullptr) {
        return;
    }
    mpOcdElectricParam->release();
    mpOcdElectricParam = nullptr;
}

__attribute__((weak)) void cpOcdCtrl::setup() {
    DDON_STUB("cpOcdCtrl::setup")
    /* stub */
}

__attribute__((weak)) void cpOcdCtrl::before() {
    DDON_STUB("cpOcdCtrl::before")
    /* stub */
}

__attribute__((weak)) void cpOcdCtrl::update() {
    DDON_STUB("cpOcdCtrl::update")
    /* stub */
}

__attribute__((weak)) void cpOcdCtrl::updatePtr() {
    DDON_STUB("cpOcdCtrl::updatePtr")
    /* stub */
}

__attribute__((weak)) void cpOcdCtrl::updateEfcHandle() {
    DDON_STUB("cpOcdCtrl::updateEfcHandle")
    /* stub */
}

__attribute__((weak)) void cpOcdCtrl::kill() {
    DDON_STUB("cpOcdCtrl::kill")
    /* stub */
}

void cpOcdCtrl::setOwner(MtObject* pOwner) {
    mpOwner = pOwner;
    mpModel = static_cast<uDDOModel*>(pOwner);
    mOcdMsgCtrl2.setOwner(this, static_cast<uDDOModel*>(pOwner));
}

__attribute__((weak)) void cpOcdCtrl::callbackDie(cUnitDieInfo& dieInfo) {
}

void cpOcdCtrl::callbackDamageAfter_make(cHitInfoAfter* pHitInfo) {
    if (isInvalid()) {
        return;
    }
    if (pHitInfo == nullptr) {
        return;
    }
    uDDOModel* pAttacker = pHitInfo->mCommonInfo.getAttckerPtr();
    if (pAttacker == nullptr) {
        return;
    }
    uDDOModel* t0 = pHitInfo->mCommonInfo.mpDfdModel;
    if (t0 == nullptr) {
        return;
    }
    if (pHitInfo->mCommonInfo.mIsAttackerShl) {
        pAttacker->makeOcdAttackInfoShl(pHitInfo);
    } else {
        pAttacker->makeOcdAttackInfo(pHitInfo);
    }
    t0->makeOcdDefenceInfo(pHitInfo);
}

void cpOcdCtrl::callbackDamageAfter_calc(cHitInfoAfter* pHitInfo) {
    if (isInvalid()) {
        return;
    }
    if (pHitInfo == nullptr) {
        return;
    }
    if (!pHitInfo->isCalcOcd()) {
        return;
    }
    calcOcdDamage(pHitInfo);
}

void cpOcdCtrl::callbackDamageAfter_apply(cHitInfoAfter* pHitInfo) {
    if (!isInvalid()) {
        if (pHitInfo != nullptr) {
            if (pHitInfo->isCalcOcd()) {
                if (!pHitInfo->checkAttackParamFlag(0x40000000ul)) {
                    if (mOcdList[1].mLength != 0) {
                        for (unsigned int i0_3 = 0;;) {
                            if (mOcdList[1].getBuffer()[static_cast<int>(i0_3)] != nullptr) {
                                if (static_cast<cOcdInfo*>(mOcdList[1].getBuffer()[static_cast<int>(i0_3)])->mpObjCondition != nullptr) {
                                    if (pHitInfo->mOcdDamageInfo.getOcdDataFromIndex(i0_3) != nullptr) {
                                        static_cast<cOcdInfo*>(mOcdList[1].getBuffer()[static_cast<int>(i0_3)])->mpObjCondition->callbackDamage(pHitInfo);
                                    }
                                }
                            }
                            if ((i0_3 + 1u) < mOcdList[1].mLength) {
                                i0_3 += 1u;
                            } else {
                                break;
                            }
                        }
                    }
                }
                const cAttackParam* pAttackParam = pHitInfo->mCommonInfo.mpAttackParam;
                if (pAttackParam != nullptr) {
                    if (pAttackParam->mAttackID == 60) {
                        reqOcdApply(16385u, nObjCondition::OCD_REASON_HIT, 60.0f, 0u, nObjCollision::INV_THROUGH_TYPE_NONE);
                        return;
                    } else {
                        if (pAttackParam->mAttackID == 14) {
                            if (!mIsInvalid) {
                                u32 v3_12 = pAttackParam->mGoodStatusFlag;
                                for (unsigned int i3_3 = 1; i3_3 != 28; i3_3 += 1u) {
                                    if (((static_cast<unsigned long>(v3_12) >> static_cast<unsigned long>((i3_3 - 1u) & 31u)) & 1ul) != 0) {
                                        reqOcdCure(i3_3);
                                    }
                                }
                                u64 v6_11 = pAttackParam->mBadStatusFlag2;
                                for (unsigned int i6_3 = 0; i6_3 != 31; i6_3 = i6_3 + 1u) {
                                    if (((static_cast<unsigned long>(v6_11) >> static_cast<unsigned long>(i6_3 & 63u)) & 1ul) != 0) {
                                        reqOcdCure(i6_3 + 4097u);
                                    }
                                }
                            }
                        } else {
                            if (pAttackParam->mAttackID == 13) {
                                if (!mIsInvalid) {
                                    u32 v9_12 = pAttackParam->mGoodStatusFlag;
                                    for (unsigned int i9_3 = 1; i9_3 != 28; i9_3 += 1u) {
                                        if (((static_cast<unsigned long>(v9_12) >> static_cast<unsigned long>((i9_3 - 1u) & 31u)) & 1ul) != 0) {
                                            reqOcdApply(i9_3, nObjCondition::OCD_REASON_HIT, 60.0f, 0u, nObjCollision::INV_THROUGH_TYPE_NONE);
                                        }
                                    }
                                    u64 v12_11 = pAttackParam->mBadStatusFlag2;
                                    for (unsigned int i12_3 = 0; i12_3 != 31; i12_3 = i12_3 + 1u) {
                                        if (((static_cast<unsigned long>(v12_11) >> static_cast<unsigned long>(i12_3 & 63u)) & 1ul) != 0) {
                                            reqOcdApply(i12_3 + 4097u, nObjCondition::OCD_REASON_HIT, 60.0f, 0u, nObjCollision::INV_THROUGH_TYPE_NONE);
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

__attribute__((weak)) void cpOcdCtrl::addOcdDamage(u32 OcdUID, f32 damage, nObjCondition::OCD_REASON reason, f32 cacheTime) {
    DDON_STUB("cpOcdCtrl::addOcdDamage")
    /* stub */
}

void cpOcdCtrl::callbackApplyDamageVisual(cHitInfoAfter* pHitInfo) {
    if (isInvalid()) {
        return;
    }
    if (pHitInfo == nullptr) {
        return;
    }
    if (mpModel == nullptr) {
        return;
    }
    uDDOModel* t0 = pHitInfo->mCommonInfo.getAttckerPtr();
    if (t0 == nullptr) {
        return;
    }
    if (pHitInfo->mCommonInfo.mpDfdModel == nullptr) {
        return;
    }
    if (!pHitInfo->mCommonInfo.mpDfdModel->isAbnormalConditionActive(4111u)) {
        return;
    }
    if ((t0->mUnitId & 4u) == 0) {
        return;
    }
    if (!cOcdHolyAbsorp::isHpAbsorpAble(t0)) {
        return;
    }
    t0->requestOutline(1u);
}

__attribute__((weak)) void cpOcdCtrl::callbackHitShlCondition_Catch(u32 OcdUID, const cShlConditionInfo* pInfo) {
    DDON_STUB("cpOcdCtrl::callbackHitShlCondition_Catch")
    /* stub */
}

__attribute__((weak)) void cpOcdCtrl::callbackAltitudeFall() {
    DDON_STUB("cpOcdCtrl::callbackAltitudeFall")
    /* stub */
}

__attribute__((weak)) void cpOcdCtrl::callbackSetCaught() {
    DDON_STUB("cpOcdCtrl::callbackSetCaught")
    /* stub */
}

__attribute__((weak)) void cpOcdCtrl::callbackChecked(cHitInfo* pHitInfo) {
}

__attribute__((weak)) void cpOcdCtrl::setOcdList(u32 bank, cOcdInfo* pList, u32 length) {
    DDON_STUB("cpOcdCtrl::setOcdList")
    /* stub */
}

__attribute__((weak)) void cpOcdCtrl::setStatusCommonParamRes(rOcdStatusParamRes* pRes) {
    DDON_STUB("cpOcdCtrl::setStatusCommonParamRes")
    /* stub */
}

__attribute__((weak)) const cOcdStatusParamRes* cpOcdCtrl::getOcdStatusParamResData(u32 OcdUID) {
    DDON_STUB("cpOcdCtrl::getOcdStatusParamResData")
    return nullptr;
}

__attribute__((weak)) void cpOcdCtrl::setStatusParamRes(rOcdStatusParamRes* pRes) {
    DDON_STUB("cpOcdCtrl::setStatusParamRes")
    /* stub */
}

__attribute__((weak)) void cpOcdCtrl::setImmuneParamRes(rOcdImmuneParamRes* pRes) {
    DDON_STUB("cpOcdCtrl::setImmuneParamRes")
    /* stub */
}

MtTypedArray<cOcdInfo>& cpOcdCtrl::getOcdList(u32 bank) {
    if (bank > 6u) {
        return mOcdList[0];
    } else {
        return mOcdList[bank];
    }
}

__attribute__((weak)) cOcdBase* cpOcdCtrl::getObjCondition(u32 OcdUID) {
    DDON_STUB("cpOcdCtrl::getObjCondition")
    return nullptr;
}

__attribute__((weak)) u32 cpOcdCtrl::getMainReaction() {
    DDON_STUB("cpOcdCtrl::getMainReaction")
    return {};
}

__attribute__((weak)) u32 cpOcdCtrl::getFallReaction() {
    DDON_STUB("cpOcdCtrl::getFallReaction")
    return {};
}

__attribute__((weak)) void cpOcdCtrl::setupStatusParam() {
    DDON_STUB("cpOcdCtrl::setupStatusParam")
    /* stub */
}

__attribute__((weak)) void cpOcdCtrl::calcOcdDamage(cHitInfoAfter* pHitInfo) {
    DDON_STUB("cpOcdCtrl::calcOcdDamage")
    /* stub */
}

f32 cpOcdCtrl::calcOcdIrAdj(cHitInfoAfter* pHitInfo) const {
    if (pHitInfo != nullptr) {
        uDDOModel* pAtkModel = pHitInfo->mCommonInfo.getAttckerPtr();
        if (pAtkModel != nullptr) {
            uDDOModel* pDfdModel = pHitInfo->mCommonInfo.mpDfdModel;
            if (pDfdModel != nullptr) {
                if ((pDfdModel->mUnitId & 1026u) != 0) {
                    sObjCondition* t0 = sObjCondition::getInstance();
                    const cOcdIrAdj* pIrData = t0->getOcdIrAdjData(pDfdModel->getLv());
                    const cOcdIrAdjPL* pIrPLData = sObjCondition::getInstance()->getOcdIrAdjPLData(pHitInfo->mOcdDamageInfo.mWepItemRank);
                    if (pIrData != nullptr) {
                        if (pIrPLData != nullptr) {
                            f32 itemRank = pIrPLData->getOcdRank();
                            if ((pIrData->getOcdRank() + -2.0f) >= itemRank) {
                                return powf(0.5f, 0.5f * ((pIrData->getOcdRank() + -2.0f) - itemRank));
                            } else {
                                return 1.0f;
                            }
                        } else {
                            return 1.0f;
                        }
                    } else {
                        return 1.0f;
                    }
                } else {
                    return 1.0f;
                }
            } else {
                return 1.0f;
            }
        } else {
            return 1.0f;
        }
    } else {
        return 1.0f;
    }
}

__attribute__((weak)) void cpOcdCtrl::checkAnnihilation(cOcdInfo* pOcdInfo) {
    DDON_STUB("cpOcdCtrl::checkAnnihilation")
    /* stub */
}

__attribute__((weak)) void cpOcdCtrl::checkTimerEndNextOcd(cOcdInfo* pOcdInfo) {
    DDON_STUB("cpOcdCtrl::checkTimerEndNextOcd")
    /* stub */
}

__attribute__((weak)) void cpOcdCtrl::checkReqestOcdMode(cOcdInfo* pOcdInfo) {
    DDON_STUB("cpOcdCtrl::checkReqestOcdMode")
    /* stub */
}

__attribute__((weak)) nObjCondition::OCD_MODE_REQ_RESULT cpOcdCtrl::checkOcdInit(const cOcdInfo* pOcdInfo) {
    DDON_STUB("cpOcdCtrl::checkOcdInit")
    return {};
}

__attribute__((weak)) void cpOcdCtrl::applyReqResult(cOcdInfo* pOcdInfo, bool isCallFunction) {
    DDON_STUB("cpOcdCtrl::applyReqResult")
    /* stub */
}

void cpOcdCtrl::checkOcdRequest(bool isCallFunction) {
    unsigned int i0_8 = 0;
    u32 v1_0;
    unsigned int i1_7;
    u32 v2_0;
    for (;;) {
        if (mOcdList[i0_8].mLength != 0) {
            v1_0 = mOcdList[i0_8].mLength;
            i1_7 = 0;
            for (;;) {
                if (mOcdList[i0_8].getBuffer()[static_cast<int>(i1_7)] == nullptr) {
                    v2_0 = v1_0;
                } else {
                    if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mOcdList[i0_8].getBuffer()[static_cast<int>(i1_7)]) + 8)) == 0) {
                        v2_0 = v1_0;
                    } else {
                        checkReqestOcdMode(static_cast<cOcdInfo*>(mOcdList[i0_8].getBuffer()[static_cast<int>(i1_7)]));
                        v2_0 = mOcdList[i0_8].mLength;
                    }
                }
                if ((i1_7 + 1u) < v2_0) {
                    v1_0 = v2_0;
                    i1_7 += 1u;
                } else {
                    break;
                }
            }
        }
        if ((i0_8 + 1u) != 7) {
            i0_8 = i0_8 + 1u;
        } else {
            break;
        }
    }
    unsigned int i5_8 = 0;
    u32 v6_0;
    unsigned int i6_3;
    u32 v7_0;
    for (;;) {
        if (mOcdList[i5_8].mLength != 0) {
            v6_0 = mOcdList[i5_8].mLength;
            i6_3 = 0;
            for (;;) {
                if (mOcdList[i5_8].getBuffer()[static_cast<int>(i6_3)] == nullptr) {
                    v7_0 = v6_0;
                } else {
                    if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mOcdList[i5_8].getBuffer()[static_cast<int>(i6_3)]) + 8)) == 0) {
                        v7_0 = v6_0;
                    } else {
                        checkAnnihilation(static_cast<cOcdInfo*>(mOcdList[i5_8].getBuffer()[static_cast<int>(i6_3)]));
                        v7_0 = mOcdList[i5_8].mLength;
                    }
                }
                if ((i6_3 + 1u) < v7_0) {
                    v6_0 = v7_0;
                    i6_3 += 1u;
                } else {
                    break;
                }
            }
        }
        if ((i5_8 + 1u) != 7) {
            i5_8 = i5_8 + 1u;
        } else {
            break;
        }
    }
    unsigned int i15_10;
    if (mIsInvalid) {
        i15_10 = 0;
    } else {
        unsigned int i10_0 = 0;
        u32 v11_0;
        unsigned int i11_7;
        u32 v12_0;
        for (;;) {
            if (mOcdList[i10_0].mLength != 0) {
                v11_0 = mOcdList[i10_0].mLength;
                i11_7 = 0;
                for (;;) {
                    if (mOcdList[i10_0].getBuffer()[static_cast<int>(i11_7)] == nullptr) {
                        v12_0 = v11_0;
                    } else {
                        static_cast<cOcdInfo*>(mOcdList[i10_0].getBuffer()[static_cast<int>(i11_7)])->turnOffChengeRequest();
                        v12_0 = mOcdList[i10_0].mLength;
                    }
                    if ((i11_7 + 1u) < v12_0) {
                        v11_0 = v12_0;
                        i11_7 += 1u;
                    } else {
                        break;
                    }
                }
            }
            if ((i10_0 + 1u) != 7) {
                i10_0 = i10_0 + 1u;
            } else {
                break;
            }
        }
        i15_10 = 0;
    }
    u32 v16_0;
    unsigned int i16_3;
    u32 v17_0;
    for (;;) {
        if (mOcdList[i15_10].mLength != 0) {
            v16_0 = mOcdList[i15_10].mLength;
            i16_3 = 0;
            for (;;) {
                if (mOcdList[i15_10].getBuffer()[static_cast<int>(i16_3)] == nullptr) {
                    v17_0 = v16_0;
                } else {
                    if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mOcdList[i15_10].getBuffer()[static_cast<int>(i16_3)]) + 8)) == 0) {
                        v17_0 = v16_0;
                    } else {
                        checkTimerEndNextOcd(static_cast<cOcdInfo*>(mOcdList[i15_10].getBuffer()[static_cast<int>(i16_3)]));
                        v17_0 = mOcdList[i15_10].mLength;
                    }
                }
                if ((i16_3 + 1u) < v17_0) {
                    v16_0 = v17_0;
                    i16_3 += 1u;
                } else {
                    break;
                }
            }
        }
        if ((i15_10 + 1u) != 7) {
            i15_10 = i15_10 + 1u;
        } else {
            break;
        }
    }
    unsigned int i20_8 = 0;
    u32 v21_0;
    unsigned int i21_7;
    u32 v22_0;
    for (;;) {
        if (mOcdList[i20_8].mLength != 0) {
            v21_0 = mOcdList[i20_8].mLength;
            i21_7 = 0;
            for (;;) {
                if (mOcdList[i20_8].getBuffer()[static_cast<int>(i21_7)] == nullptr) {
                    v22_0 = v21_0;
                } else {
                    if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mOcdList[i20_8].getBuffer()[static_cast<int>(i21_7)]) + 8)) == 0) {
                        v22_0 = v21_0;
                    } else {
                        applyReqResult(static_cast<cOcdInfo*>(mOcdList[i20_8].getBuffer()[static_cast<int>(i21_7)]), isCallFunction);
                        v22_0 = mOcdList[i20_8].mLength;
                    }
                }
                if ((i21_7 + 1u) < v22_0) {
                    v21_0 = v22_0;
                    i21_7 += 1u;
                } else {
                    break;
                }
            }
        }
        if ((i20_8 + 1u) != 7) {
            i20_8 = i20_8 + 1u;
        } else {
            break;
        }
    }
}

__attribute__((weak)) void cpOcdCtrl::reqOcdApply(u32 OcdUID, nObjCondition::OCD_REASON reason, f32 cacheTime, u32 option, nObjCollision::UNIT_INV_THROUGH_TYPE invThroughType) {
    DDON_STUB("cpOcdCtrl::reqOcdApply")
    /* stub */
}

void cpOcdCtrl::reqOcdApplyForce(u32 OcdUID, nObjCondition::OCD_REASON reason, f32 cacheTime) {
    reqOcdApply(OcdUID, reason, cacheTime, 1u, nObjCollision::INV_THROUGH_TYPE_NONE);
}

__attribute__((weak)) void cpOcdCtrl::reqOcdApplyCustom(u32 OcdUID, const cOcdCustomReqInfo& reqInfo, nObjCondition::OCD_REASON reason, f32 cacheTime, s32 priority) {
    DDON_STUB("cpOcdCtrl::reqOcdApplyCustom")
    /* stub */
}

__attribute__((weak)) void cpOcdCtrl::reqOcdCure(u32 OcdUID) {
    if (mIsInvalid) {
        return;
    }
    if (mpModel == nullptr) {
        return;
    }
    if (mpModel->isEnable()) {
        if (mpModel->isMaster()) {
            if (((OcdUID >> 12) & 15u) <= 6u) {
                if (mOcdList[(OcdUID >> 12) & 15u].mLength != 0) {
                    if (((OcdUID & 0xFFFF0FFFu) - 1u) < mOcdList[(OcdUID >> 12) & 15u].mLength) {
                        if (mOcdList[(OcdUID >> 12) & 15u].getBuffer()[static_cast<int>((OcdUID & 0xFFFF0FFFu) - 1u)] != nullptr) {
                            if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mOcdList[(OcdUID >> 12) & 15u].getBuffer()[static_cast<int>((OcdUID & 0xFFFF0FFFu) - 1u)]) + 8)) != 0) {
                                if (!mIsInvalid) {
                                    if (mOcdList[(OcdUID >> 12) & 15u].getBuffer()[(OcdUID & 0xFFFF0FFFu) - 1u] != nullptr) {
                                        if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mOcdList[(OcdUID >> 12) & 15u].getBuffer()[(OcdUID & 0xFFFF0FFFu) - 1u]) + 8)) != 0) {
                                            if (static_cast<cOcdInfo*>(mOcdList[(OcdUID >> 12) & 15u].getBuffer()[(OcdUID & 0xFFFF0FFFu) - 1u])->isActive()) {
                                                static_cast<cOcdInfo*>(mOcdList[(OcdUID >> 12) & 15u].getBuffer()[static_cast<int>((OcdUID & 0xFFFF0FFFu) - 1u)])->reqChangeOcdMode(nObjCondition::OCD_REQ_END, nObjCollision::INV_THROUGH_TYPE_NONE);
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

__attribute__((weak)) void cpOcdCtrl::reqOcdCureForce(u32 OcdUID) {
    DDON_STUB("cpOcdCtrl::reqOcdCureForce")
    /* stub */
}

__attribute__((weak)) void cpOcdCtrl::reqOcdChargeClear(u32 OcdUID) {
    DDON_STUB("cpOcdCtrl::reqOcdChargeClear")
    /* stub */
}

bool cpOcdCtrl::isOcdActive(u32 OcdUID) const {
    if (!mIsInvalid) {
        if (((OcdUID >> 12) & 15u) <= 6u) {
            if (mOcdList[(OcdUID >> 12) & 15u].mLength != 0) {
                if (((OcdUID & 0xFFFF0FFFu) - 1u) < mOcdList[(OcdUID >> 12) & 15u].mLength) {
                    if (mOcdList[(OcdUID >> 12) & 15u].mpArray[(OcdUID & 0xFFFF0FFFu) - 1u] != nullptr) {
                        if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mOcdList[(OcdUID >> 12) & 15u].mpArray[(OcdUID & 0xFFFF0FFFu) - 1u]) + 8)) != 0) {
                            return static_cast<cOcdInfo*>(mOcdList[(OcdUID >> 12) & 15u].mpArray[(OcdUID & 0xFFFF0FFFu) - 1u])->isActive();
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool cpOcdCtrl::isOcdActiveOld(u32 OcdUID) const {
    return ((static_cast<unsigned long>(mOcdActiveBitOld[(OcdUID >> 12) & 15u]) >> static_cast<unsigned long>((OcdUID - 1u) & 31u)) & 1ul) != 0;
}

__attribute__((weak)) bool cpOcdCtrl::isOcdApplyAble(u32 OcdUID) {
    DDON_STUB("cpOcdCtrl::isOcdApplyAble")
    return {};
}

bool cpOcdCtrl::isOcdAlreadyRequest(u32 OcdUID) {
    if (!mIsInvalid) {
        if (((OcdUID >> 12) & 15u) <= 6u) {
            if (mOcdList[(OcdUID >> 12) & 15u].mLength != 0) {
                if (((OcdUID & 0xFFFF0FFFu) - 1u) < mOcdList[(OcdUID >> 12) & 15u].mLength) {
                    if (mOcdList[(OcdUID >> 12) & 15u].getBuffer()[static_cast<int>((OcdUID & 0xFFFF0FFFu) - 1u)] != nullptr) {
                        if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mOcdList[(OcdUID >> 12) & 15u].getBuffer()[static_cast<int>((OcdUID & 0xFFFF0FFFu) - 1u)]) + 8)) != 0) {
                            return static_cast<cOcdInfo*>(mOcdList[(OcdUID >> 12) & 15u].getBuffer()[static_cast<int>((OcdUID & 0xFFFF0FFFu) - 1u)])->getOcdModeReq() == nObjCondition::OCD_REQ_INIT;
                        }
                    }
                }
            }
        }
    }
    return false;
}

__attribute__((weak)) void cpOcdCtrl::resetActiveTimer(u32 OcdUID) {
    DDON_STUB("cpOcdCtrl::resetActiveTimer")
    /* stub */
}

__attribute__((weak)) cOcdStatusParam* cpOcdCtrl::getStatusParam(u32 OcdUID) {
    DDON_STUB("cpOcdCtrl::getStatusParam")
    return nullptr;
}

__attribute__((weak)) cOcdImmuneParam* cpOcdCtrl::getImmuneParam(u32 OcdUID) {
    DDON_STUB("cpOcdCtrl::getImmuneParam")
    return nullptr;
}

__attribute__((weak)) f32 cpOcdCtrl::getOcdFreeParam(u32 OcdUID, u32 index) {
    DDON_STUB("cpOcdCtrl::getOcdFreeParam")
    return {};
}

void cpOcdCtrl::addOcdSystemFlag(u32 flag) {
    mOcdSystemFlag = flag | mOcdSystemFlag;
}

bool cpOcdCtrl::isOcdSystemFlagActive(nObjCondition::OCD_SYSTEM_FLAG flag) const {
    if (mIsInvalid) {
        return false;
    }
    return (mOcdSystemFlag & flag) != 0;
}

void cpOcdCtrl::cancelOcdReqest() {
    if (!mIsInvalid) {
        u32 bank = 0;
        u32 v1_0;
        unsigned int i1_3;
        u32 v2_0;
        for (;;) {
            if (mOcdList[bank].mLength != 0) {
                v1_0 = mOcdList[bank].mLength;
                i1_3 = 0;
                for (;;) {
                    if (mOcdList[bank].getBuffer()[static_cast<int>(i1_3)] == nullptr) {
                        v2_0 = v1_0;
                    } else {
                        static_cast<cOcdInfo*>(mOcdList[bank].getBuffer()[static_cast<int>(i1_3)])->turnOffChengeRequest();
                        v2_0 = mOcdList[bank].mLength;
                    }
                    if ((i1_3 + 1u) < v2_0) {
                        v1_0 = v2_0;
                        i1_3 += 1u;
                    } else {
                        break;
                    }
                }
            }
            if ((bank + 1u) != 7) {
                bank = bank + 1u;
            } else {
                break;
            }
        }
    }
}

void cpOcdCtrl::cancelOcdReqest(u32 OcdUID) {
    if (mIsInvalid) {
        return;
    }
    if (((OcdUID >> 12) & 15u) <= 6u) {
        if (mOcdList[(OcdUID >> 12) & 15u].mLength != 0) {
            if (((OcdUID & 0xFFFF0FFFu) - 1u) < mOcdList[(OcdUID >> 12) & 15u].mLength) {
                if (mOcdList[(OcdUID >> 12) & 15u].getBuffer()[static_cast<int>((OcdUID & 0xFFFF0FFFu) - 1u)] != nullptr) {
                    if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(mOcdList[(OcdUID >> 12) & 15u].getBuffer()[static_cast<int>((OcdUID & 0xFFFF0FFFu) - 1u)]) + 8)) != 0) {
                        static_cast<cOcdInfo*>(mOcdList[(OcdUID >> 12) & 15u].getBuffer()[static_cast<int>((OcdUID & 0xFFFF0FFFu) - 1u)])->turnOffChengeRequest();
                    }
                }
            }
        }
    }
}

bool cpOcdCtrl::isRecoverEnd() const {
    return mOcdMsgCtrl2.mIsRecoverEnd;
}

__attribute__((weak)) bool cpOcdCtrl::isUseSleepChangeTime() const {
    DDON_STUB("cpOcdCtrl::isUseSleepChangeTime")
    return {};
}

void cpOcdCtrl::notifyReceiveMsg(bool recvFlag) {
    if (mIsInvalid) {
        return;
    }
    mOcdMsgCtrl2.mIsReceiveMsg = true;
    mOcdMsgCtrl2.mInitFlag = recvFlag;
}

__attribute__((weak)) void cpOcdCtrl::callInit(u32 OcdUID, bool initFlag) {
    DDON_STUB("cpOcdCtrl::callInit")
    /* stub */
}

__attribute__((weak)) void cpOcdCtrl::callFinal(u32 OcdUID) {
    DDON_STUB("cpOcdCtrl::callFinal")
    /* stub */
}

__attribute__((weak)) void cpOcdCtrl::callMulti(u32 OcdUID, bool initFlag) {
    DDON_STUB("cpOcdCtrl::callMulti")
    /* stub */
}

__attribute__((weak)) void cpOcdCtrl::callbackReceiveActive(u32 OcdUID, bool initFlag, bool isAction) {
    DDON_STUB("cpOcdCtrl::callbackReceiveActive")
    /* stub */
}

__attribute__((weak)) u32 cpOcdCtrl::checkResetActOcd(const cOcdActiveReqArray& activeArray) const {
    DDON_STUB("cpOcdCtrl::checkResetActOcd")
    return {};
}

__attribute__((weak)) void cpOcdCtrl::setOcdElectricRes(rOcdElectricParam* pResOcdElec) {
    DDON_STUB("cpOcdCtrl::setOcdElectricRes")
    /* stub */
}

void cpOcdCtrl::registOcdShader(nDDOShader::SHADER_MODE_ENUM shaderType, u32 priority, s32 lv) {
    if (priority >= mShaderPriority) {
        mShaderPriority = priority;
        mOcdShaderType = shaderType;
        mOcdShaderLv = lv;
    }
}

bool cpOcdCtrl::checkOcdDamageCache(const cOcdCache& newChach) {
    if (mIsInvalid) {
        return false;
    } else {
        if (newChach.mReason != nObjCondition::OCD_REASON_NONE) {
            if (!mOcdDamageCacheArray.elems[(static_cast<unsigned int>(newChach.mReason) <= 2) ? newChach.mReason : nObjCondition::OCD_REASON_NONE].mIsActive) {
                mOcdDamageCacheArray.elems[(static_cast<unsigned int>(newChach.mReason) <= 2) ? newChach.mReason : nObjCondition::OCD_REASON_NONE].copy(newChach);
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    }
}

void cpOcdCtrl::setupOcdCycleEffect() {
    mCycleEffectReqInfo.elems[1].mEffLoopTime = 30.0f;
    mCycleEffectReqInfo.elems[1].mPartType = nEffectCycle::PART_TYPE_REST;
    mCycleEffectReqInfo.elems[2].mEffLoopTime = 30.0f;
    const cOutlineParam* t0 = static_cast<sEffectExt*>(sEffect::getInstance())->getOutlineParam(sEffectExt::OUTLINE_HEALING_SPOT);
    if (t0 != nullptr) {
        mCycleEffectReqInfo.elems[2].mEffLoopTime = t0->mFrame;
    }
    if (mpModel != nullptr) {
        if ((mpModel->mUnitId & 16u) != 0) {
            mCycleEffectReqInfo.elems[2].mEpvIndex = 1;
            mCycleEffectReqInfo.elems[2].mEpvElement = 23;
            mCycleEffectReqInfo.elems[2].mIsEffect = true;
            mCycleEffectReqInfo.elems[2].mEpvFinishIndex = 1;
            mCycleEffectReqInfo.elems[2].mEpvFinishElement = 24;
            mCycleEffectReqInfo.elems[2].mIsEndEffect = true;
        }
    }
    mCycleEffectReqInfo.elems[2].mOutLineIndex = 4;
    mCycleEffectReqInfo.elems[2].mIsOutLine = true;
    mCycleEffectReqInfo.elems[2].mPartType = nEffectCycle::PART_TYPE_EFFCT_CALL;
    mCycleEffectReqInfo.elems[3].mEffLoopTime = 30.0f;
    const cOutlineParam* t1 = static_cast<sEffectExt*>(sEffect::getInstance())->getOutlineParam(sEffectExt::OUTLINE_HOLY_ABSORB);
    if (t1 != nullptr) {
        mCycleEffectReqInfo.elems[3].mEffLoopTime = t1->mFrame;
    }
    if (mpModel != nullptr) {
        if ((mpModel->mUnitId & 16u) != 0) {
            mCycleEffectReqInfo.elems[3].mEpvIndex = 1;
            mCycleEffectReqInfo.elems[3].mEpvElement = 29;
            mCycleEffectReqInfo.elems[3].mIsEffect = true;
            mCycleEffectReqInfo.elems[3].mEpvFinishIndex = 1;
            mCycleEffectReqInfo.elems[3].mEpvFinishElement = 30;
            mCycleEffectReqInfo.elems[3].mIsEndEffect = true;
        }
    }
    mCycleEffectReqInfo.elems[3].mIsOutLine = true;
    mCycleEffectReqInfo.elems[3].mOutLineIndex = 5;
    mCycleEffectReqInfo.elems[3].mPartType = nEffectCycle::PART_TYPE_EFFCT_CALL;
    mCycleEffectReqInfo.elems[4].mEffLoopTime = 30.0f;
    const cOutlineParam* t2 = static_cast<sEffectExt*>(sEffect::getInstance())->getOutlineParam(sEffectExt::OUTLINE_ST_DOWN_TRG);
    if (t2 != nullptr) {
        mCycleEffectReqInfo.elems[4].mEffLoopTime = t2->mFrame;
    }
    if (mpModel != nullptr) {
        if ((mpModel->mUnitId & 16u) != 0) {
            mCycleEffectReqInfo.elems[4].mEpvIndex = 1;
            mCycleEffectReqInfo.elems[4].mEpvElement = 5;
            mCycleEffectReqInfo.elems[4].mIsEffect = true;
            mCycleEffectReqInfo.elems[4].mEpvFinishIndex = -1;
            mCycleEffectReqInfo.elems[4].mEpvFinishElement = -1;
            mCycleEffectReqInfo.elems[4].mIsEndEffect = false;
        }
    }
    mCycleEffectReqInfo.elems[4].mIsOutLine = true;
    mCycleEffectReqInfo.elems[4].mOutLineIndex = 9;
    mCycleEffectReqInfo.elems[4].mPartType = nEffectCycle::PART_TYPE_EFFCT_CALL;
    mCycleEffectReqInfo.elems[5].mEffLoopTime = 30.0f;
    const cOutlineParam* t3 = static_cast<sEffectExt*>(sEffect::getInstance())->getOutlineParam(sEffectExt::OUTLINE_ST_UP_TRG);
    if (t3 != nullptr) {
        mCycleEffectReqInfo.elems[5].mEffLoopTime = t3->mFrame;
    }
    uDDOModel* v7_3 = mpModel;
    if (v7_3 != nullptr) {
        if ((v7_3->mUnitId & 16u) != 0) {
            mCycleEffectReqInfo.elems[5].mEpvIndex = 1;
            mCycleEffectReqInfo.elems[5].mEpvElement = 4;
            mCycleEffectReqInfo.elems[5].mIsEffect = true;
            mCycleEffectReqInfo.elems[5].mEpvFinishIndex = -1;
            mCycleEffectReqInfo.elems[5].mEpvFinishElement = -1;
            mCycleEffectReqInfo.elems[5].mIsEndEffect = false;
        }
    }
    mCycleEffectReqInfo.elems[5].mIsOutLine = true;
    mCycleEffectReqInfo.elems[5].mOutLineIndex = 8;
    mCycleEffectReqInfo.elems[5].mPartType = nEffectCycle::PART_TYPE_EFFCT_CALL;
    mEffectCycleCtrl.setOwner(v7_3);
}

__attribute__((weak)) void cpOcdCtrl::updateOcdCycleEffect() {
    DDON_STUB("cpOcdCtrl::updateOcdCycleEffect")
    /* stub */
}

void cpOcdCtrl::notifyMoveFreeze() {
    mIsMoveFreeze = true;
}

__attribute__((weak)) void cpOcdCtrl::checkBadOcdEndEffect() {
    DDON_STUB("cpOcdCtrl::checkBadOcdEndEffect")
    /* stub */
}

__attribute__((weak)) f32 cpOcdCtrl::getOcdEndurance(u32 OcdUID) {
    DDON_STUB("cpOcdCtrl::getOcdEndurance")
    return {};
}

__attribute__((weak)) f32 cpOcdCtrl::getOcdEnduranceMax(u32 OcdUID) {
    DDON_STUB("cpOcdCtrl::getOcdEnduranceMax")
    return {};
}

__attribute__((weak)) f32 cpOcdCtrl::getOcdAccumulation(u32 OcdUID) {
    DDON_STUB("cpOcdCtrl::getOcdAccumulation")
    return {};
}

inline cpOcdCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpOcdCtrl::MyDTI cpOcdCtrl::DTI("cpOcdCtrl", &::cpComponent::DTI, 1344ul, 0u, 0u);

__attribute__((weak)) MtObject* cpOcdCtrl::MyDTI::newInstance() const {
    DDON_STUB("cpOcdCtrl::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<cOcdInfo>::~MtTypedArray();

