// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIBazaar.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "cItemParam.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "nGUIItem.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "rItemList.h"
#include "../../XFramework/rSoundRequest.h"
#include "sBazaarManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sItemManager.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/sUnit.h"
#include "../../XFramework/uCoord.h"
#include "../../XFramework/uGUI.h"
#include "uGUIAnnounce.h"
#include "uGUIBase.h"
#include "uGUIBazaarDealSheet.h"
#include "uGUIBazaarHistory.h"
#include "uGUIBazaarItemSearch.h"
#include "uGUIBazaarPopBuy.h"
#include "uGUIBazaarPopInfo.h"
#include "uGUIBazaarPopItemList.h"
#include "uGUIBazaarPopPriceSetting.h"
#include "uGUIItem01.h"
#include "uGUIPopCmd01.h"
#include "uGUIPopDetail01.h"
#include "uGUIPopTopSel.h"
#include "uGUISystemMsg.h"
#include "uGUIUseItemBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIBazaar::getDTI() const {
    return uGUIBazaar::DTI;
}

__attribute__((noinline)) uGUIBazaar::~uGUIBazaar() {
    if (mpTopSel != nullptr) {
        mpTopSel->kill();
        mpTopSel = nullptr;
    }
    if (mpItemSearch != nullptr) {
        mpItemSearch->kill();
        mpItemSearch = nullptr;
    }
    if (mpDealSheet != nullptr) {
        mpDealSheet->kill();
        mpDealSheet = nullptr;
    }
    if (mpInfo != nullptr) {
        mpInfo->kill();
        mpInfo = nullptr;
    }
    if (mpPopItemList != nullptr) {
        mpPopItemList->kill();
        mpPopItemList = nullptr;
    }
    if (mpPopPriceSetting != nullptr) {
        mpPopPriceSetting->kill();
        mpPopPriceSetting = nullptr;
    }
    if (mpPopBuy != nullptr) {
        mpPopBuy->kill();
        mpPopBuy = nullptr;
    }
    if (mpPopCmd != nullptr) {
        mpPopCmd->kill();
        mpPopCmd = nullptr;
    }
    if (mpAnnounce != nullptr) {
        mpAnnounce->kill();
        mpAnnounce = nullptr;
    }
    if (mpHistory != nullptr) {
        mpHistory->kill();
        mpHistory = nullptr;
    }
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpGMDRes != nullptr) {
        mpGMDRes->release();
        mpGMDRes = nullptr;
    }
    if (mpSeRes != nullptr) {
        mpSeRes->release();
        mpSeRes = nullptr;
    }
}

void uGUIBazaar::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
}

bool uGUIBazaar::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_BAZZAR_POS_GUI"), 129u, 1423703258l))) == nullptr)) {
        return false;
    }
    if ((mpGMDRes == nullptr) && ((mpGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_BAZAAR_GMD"), 129u, 0l))) == nullptr)) {
        return false;
    }
    if ((mpSeRes == nullptr) && ((mpSeRes = static_cast<rSoundRequest*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ID_BAZAAR_SRQR"), 129u, 0l))) == nullptr)) {
        return false;
    }
    return true;
}

void uGUIBazaar::move() {
    this->uGUIBase::move();
    if (!mIsEndLoadResource) {
        return;
    }
    if (mFlowNow != 1) {
        return;
    }
    dispCheckBazaarIcon(false);
}

__attribute__((weak)) void uGUIBazaar::setup() {
    DDON_STUB("uGUIBazaar::setup")
    /* stub */
}

void uGUIBazaar::kill() {
    if (mpTopSel != nullptr) {
        mpTopSel->kill();
        mpTopSel = nullptr;
    }
    if (mpItemSearch != nullptr) {
        mpItemSearch->kill();
        mpItemSearch = nullptr;
    }
    if (mpDealSheet != nullptr) {
        mpDealSheet->kill();
        mpDealSheet = nullptr;
    }
    if (mpInfo != nullptr) {
        mpInfo->kill();
        mpInfo = nullptr;
    }
    if (mpPopItemList != nullptr) {
        mpPopItemList->kill();
        mpPopItemList = nullptr;
    }
    if (mpPopPriceSetting != nullptr) {
        mpPopPriceSetting->kill();
        mpPopPriceSetting = nullptr;
    }
    if (mpPopItemBox != nullptr) {
        mpPopItemBox->kill();
        mpPopItemBox = nullptr;
    }
    if (mpGUISystemMsg != nullptr) {
        mpGUISystemMsg->kill();
        mpGUISystemMsg = nullptr;
    }
    if (mpPopCmd != nullptr) {
        mpPopCmd->kill();
        mpPopCmd = nullptr;
    }
    if (mpAnnounce != nullptr) {
        mpAnnounce->kill();
        mpAnnounce = nullptr;
    }
    this->uGUIBase::kill();
}

void uGUIBazaar::updatePtr() {
    if (mpTopSel != nullptr) {
        if (!mpTopSel->cUnit::isEnable()) {
            mpTopSel = nullptr;
        }
    }
    if (mpItemSearch != nullptr) {
        if (!mpItemSearch->isEnable()) {
            mpItemSearch = nullptr;
        }
    }
    if (mpDealSheet != nullptr) {
        if (!mpDealSheet->isEnable()) {
            mpDealSheet = nullptr;
        }
    }
    if (mpInfo != nullptr) {
        if (!mpInfo->isEnable()) {
            mpInfo = nullptr;
        }
    }
    if (mpPopItemList != nullptr) {
        if (!mpPopItemList->isEnable()) {
            mpPopItemList = nullptr;
        }
    }
    if (mpPopPriceSetting != nullptr) {
        if (!mpPopPriceSetting->isEnable()) {
            mpPopPriceSetting = nullptr;
        }
    }
    if (mpPopCmd != nullptr) {
        if (!mpPopCmd->isEnable()) {
            mpPopCmd = nullptr;
        }
    }
    if (mpAnnounce != nullptr) {
        if (!mpAnnounce->isEnable()) {
            mpAnnounce = nullptr;
        }
    }
}

__attribute__((weak)) void uGUIBazaar::setFlowId(u32 flowId) {
    DDON_STUB("uGUIBazaar::setFlowId")
    /* stub */
}

static auto ddon_emit_0x01adfa50 __attribute__((used)) = &uGUIBazaar::callbackCmd00;

static auto ddon_emit_0x01adfa60 __attribute__((used)) = &uGUIBazaar::callbackCmd01;

static auto ddon_emit_0x01adfa70 __attribute__((used)) = &uGUIBazaar::callbackCmdCancel;

__attribute__((weak)) s32 uGUIBazaar::getSMenuCursorY() {
    DDON_STUB("uGUIBazaar::getSMenuCursorY")
    return {};
}

__attribute__((weak)) void uGUIBazaar::moveInput() {
    DDON_STUB("uGUIBazaar::moveInput")
    /* stub */
}

void uGUIBazaar::moveEvent() {
    if (static_cast<int>(getInputEvent()) <= 65) {
        if (getInputEvent() != 4) {
            if (getInputEvent() == 5) {
                eventCancel();
            }
        } else {
            eventDecide();
        }
    } else {
        if (getInputEvent() != 68) {
            if (getInputEvent() == 67) {
                eventCancel();
            } else {
                if (getInputEvent() == 66) {
                    eventDecide();
                }
            }
        } else {
            mIsShortCut = false;
            if (mFlowNow == 21) {
                mIsShortCut = true;
                if (mpDealSheet != nullptr) {
                    mpDealSheet->hide();
                }
            }
        }
    }
}

__attribute__((weak)) void uGUIBazaar::adjustScale() {
    DDON_STUB("uGUIBazaar::adjustScale")
    /* stub */
}

void uGUIBazaar::updateInit() {
    mDetectionMasterTimer = 30.0f * static_cast<float>(sBazaarManager::getInstance()->mBazzarSearchSuccessionTime);
    mInvocationMasterTimer = 30.0f * static_cast<float>(sBazaarManager::getInstance()->mBazzarSearchSuccessionCautionTime);
    mDetectionTimer = 0.0f;
    mDetectionCountLimit = sBazaarManager::getInstance()->GetBazzarSearchSuccessionCount();
    mDetectionCount = 0;
    mInvocationTimer = 0.0f;
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaar::updateMove);
}

void uGUIBazaar::updateMove() {
    if (mInvocationTimer > 0.0f) {
        mInvocationTimer = mInvocationTimer - mDeltaTime;
        if (0.0f >= mInvocationTimer) {
            mInvocationTimer = 0.0f;
            mDetectionTimer = 0.0f;
            mDetectionCount = 0;
        }
    } else {
        if (mDetectionTimer > 0.0f) {
            mDetectionTimer = mDetectionTimer - mDeltaTime;
            if (0.0f >= mDetectionTimer) {
                mDetectionTimer = 0.0f;
                mDetectionCount = 0;
            }
        }
    }
}

__attribute__((weak)) void uGUIBazaar::eventDecide() {
    DDON_STUB("uGUIBazaar::eventDecide")
    /* stub */
}

__attribute__((weak)) void uGUIBazaar::eventCancel() {
    switch (mFlowNow - 2u) {
        case 0:
        {
            if (mpItemSearch != nullptr) {
                mpItemSearch->hide();
            }
            break;
        }
        case 1:
        {
            if (mpItemSearch != nullptr) {
                mpItemSearch->hide();
            }
            break;
        }
        case 2:
        {
            if (mpPopItemList != nullptr) {
                mpPopItemList->hide();
                if (mpHistory != nullptr) {
                    mpHistory->mItemNo = mSelectItemNo;
                    mpHistory->hide();
                }
            } else {
                if (mpHistory != nullptr) {
                    mpHistory->mItemNo = mSelectItemNo;
                    mpHistory->hide();
                }
            }
            break;
        }
        case 3:
        {
            if (mpPopBuy != nullptr) {
                mpPopBuy->hide();
            }
            break;
        }
        case 8:
        {
            if (mpTopSel != nullptr) {
                mpTopSel->hide();
            }
            break;
        }
        case 9:
        {
            if (mpPopItemBox != nullptr) {
                mpPopItemBox->kill();
                mpPopItemBox = nullptr;
            }
            break;
        }
        case 10:
        {
            if (mpPopPriceSetting != nullptr) {
                mpPopPriceSetting->hide();
                if (mpHistory != nullptr) {
                    mpHistory->hide();
                    if (mpPopItemBox != nullptr) {
                        mpPopItemBox->setDetailVisible(true);
                        mpPopItemBox->setMouseTouchCtrl(true);
                    }
                } else {
                    if (mpPopItemBox != nullptr) {
                        mpPopItemBox->setDetailVisible(true);
                        mpPopItemBox->setMouseTouchCtrl(true);
                    }
                }
            } else {
                if (mpHistory != nullptr) {
                    mpHistory->hide();
                    if (mpPopItemBox != nullptr) {
                        mpPopItemBox->setDetailVisible(true);
                        mpPopItemBox->setMouseTouchCtrl(true);
                    }
                } else {
                    if (mpPopItemBox != nullptr) {
                        mpPopItemBox->setDetailVisible(true);
                        mpPopItemBox->setMouseTouchCtrl(true);
                    }
                }
            }
            break;
        }
        case 11:
        {
            if (mpPopPriceSetting != nullptr) {
                mpPopPriceSetting->hide();
                if (mpHistory != nullptr) {
                    mpHistory->hide();
                    if (mpPopItemBox != nullptr) {
                        mpPopItemBox->setDetailVisible(true);
                        mpPopItemBox->setMouseTouchCtrl(true);
                    }
                } else {
                    if (mpPopItemBox != nullptr) {
                        mpPopItemBox->setDetailVisible(true);
                        mpPopItemBox->setMouseTouchCtrl(true);
                    }
                }
            } else {
                if (mpHistory != nullptr) {
                    mpHistory->hide();
                    if (mpPopItemBox != nullptr) {
                        mpPopItemBox->setDetailVisible(true);
                        mpPopItemBox->setMouseTouchCtrl(true);
                    }
                } else {
                    if (mpPopItemBox != nullptr) {
                        mpPopItemBox->setDetailVisible(true);
                        mpPopItemBox->setMouseTouchCtrl(true);
                    }
                }
            }
            break;
        }
        case 14:
        {
            if (mpPopItemBox != nullptr) {
                mpPopItemBox->refresh();
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaar::updateMove);
            } else {
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaar::updateMove);
            }
            break;
        }
        case 15:
        {
            if (mpPopItemBox != nullptr) {
                mpPopItemBox->refresh();
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaar::updateMove);
            } else {
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaar::updateMove);
            }
            break;
        }
        case 18:
        {
            if (mpPopItemBox != nullptr) {
                mpPopItemBox->kill();
                mpPopItemBox = nullptr;
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaar::updateMove);
            } else {
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaar::updateMove);
            }
            break;
        }
        case 19:
        {
            if (mpDealSheet != nullptr) {
                mpDealSheet->hide();
            }
            break;
        }
        case 22:
        {
            if (mpDealSheet != nullptr) {
                mpDealSheet->begin();
            }
            break;
        }
        case 23:
        {
            if (mpDealSheet != nullptr) {
                mpDealSheet->begin();
            }
            break;
        }
        case 24:
        {
            if (mpDealSheet != nullptr) {
                mpDealSheet->begin();
            }
            break;
        }
        case 26:
        {
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaar::updateMove);
            break;
        }
        case 27:
        {
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaar::updateMove);
            break;
        }
        case 29:
        {
            if (mpDealSheet != nullptr) {
                mpDealSheet->begin();
            }
            break;
        }
        case 30:
        {
            if (mpDealSheet != nullptr) {
                mpDealSheet->begin();
            }
            break;
        }
        default:
        {
            break;
        }
    }
}

__attribute__((weak)) void uGUIBazaar::dispCheckBazaarIcon(bool isUpdate) {
    DDON_STUB("uGUIBazaar::dispCheckBazaarIcon")
    /* stub */
}

void uGUIBazaar::movePriceSetConfirm() {
    if (mpGUISystemMsg != nullptr) {
        if (mpGUISystemMsg->mResult == RESULT_EXIT) {
            if (mpGUISystemMsg->getChoicePos(-1) != 0) {
                setInputEvent(5u);
            } else {
                setInputEvent(4u);
            }
            if (mpGUISystemMsg != nullptr) {
                mpGUISystemMsg->mEndType = 0;
                mpGUISystemMsg->end();
            }
            mpGUISystemMsg = nullptr;
            static_cast<sGUIExt*>(sGUI::getInstance())->reqWindowActive(static_cast<uGUIBase*>(this));
        }
    } else {
        setInputEvent(5u);
        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIBazaar::updateMove);
    }
}

__attribute__((weak)) void uGUIBazaar::createItemBox() {
    DDON_STUB("uGUIBazaar::createItemBox")
    /* stub */
}

void uGUIBazaar::createPriceSetConfirm() {
    if (mpPopPriceSetting == nullptr) {
        return;
    }
    u32 itemNo = mpPopPriceSetting->getItemNo();
    if (itemNo == 0) {
        return;
    }
    s32 itemNum = mpPopPriceSetting->getItemNum();
    if (itemNum > 0) {
        s32 itemPrice = mpPopPriceSetting->getItemPrice();
        if ((mpGUISystemMsg = new (16u) uGUISystemMsg(0u, 0u, false)) != nullptr) {
            rItemList::rItemParam* prItemParam = sItemManager::getInstance()->getItemParam(itemNo);
            if (prItemParam != nullptr) {
                prItemParam->getItemName();
                mpGUISystemMsg->setMsgAnalyzerWork(0u, static_cast<s32>(itemNo));
                mpGUISystemMsg->setMsgAnalyzerWork(1u, itemNum);
                mpGUISystemMsg->setMsgAnalyzerWork(2u, itemNum * itemPrice);
                mpGUISystemMsg->setMsgAnalyzerWork(3u, 5);
                mpGUISystemMsg->setMsgAnalyzerWork(4u, static_cast<s32>((static_cast<unsigned long>(static_cast<unsigned int>((itemNum * itemPrice) * 5)) * 0x51EB851F) >> 37));
                MT_CTSTR pStr = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 59u);
                MT_CTSTR pYes = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 1u);
                MT_CTSTR pNo = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 2u);
                uGUISystemMsg* pGUI = mpGUISystemMsg;
                pGUI->setText(pStr, -1);
                if (pYes != nullptr) {
                    pGUI->addChoiceInfo(pYes, 0u, nHuman::JOB_ID_NONE, -1, true);
                    if (pNo != nullptr) {
                        pGUI->addChoiceInfo(pNo, 0u, nHuman::JOB_ID_NONE, -1, true);
                        mpGUISystemMsg->mMode = 2;
                        mpGUISystemMsg->setDefaultChoicePos(0, -1);
                        mpGUISystemMsg->setCancelChoicePos(1, -1);
                        mpGUISystemMsg->mMsgAnalyzeAutoClear = false;
                        f32 t1 = static_cast<cGUIInstNull*>(mpInstSystemMsg)->mPosition.y;
                        f32 t2 = static_cast<cGUIInstNull*>(mpInstSystemMsg)->mPosition.z;
                        mpGUISystemMsg->mPos.x = static_cast<cGUIInstNull*>(mpInstSystemMsg)->mPosition.x;
                        mpGUISystemMsg->mPos.y = t1;
                        mpGUISystemMsg->mPos.z = t2;
                        mpGUISystemMsg->mPos.pad_ = 0.0f;
                        sUnit* t3 = sUnit::getInstance();
                        t3->addBottom(static_cast<MOVE_LINE>(t3->getNextMoveLineId(mMoveLine)), static_cast<cUnit*>(mpGUISystemMsg), getUnitGroup());
                    } else {
                        mpGUISystemMsg->mMode = 2;
                        mpGUISystemMsg->setDefaultChoicePos(0, -1);
                        mpGUISystemMsg->setCancelChoicePos(1, -1);
                        mpGUISystemMsg->mMsgAnalyzeAutoClear = false;
                        f32 t1 = static_cast<cGUIInstNull*>(mpInstSystemMsg)->mPosition.y;
                        f32 t2 = static_cast<cGUIInstNull*>(mpInstSystemMsg)->mPosition.z;
                        mpGUISystemMsg->mPos.x = static_cast<cGUIInstNull*>(mpInstSystemMsg)->mPosition.x;
                        mpGUISystemMsg->mPos.y = t1;
                        mpGUISystemMsg->mPos.z = t2;
                        mpGUISystemMsg->mPos.pad_ = 0.0f;
                        sUnit* t3 = sUnit::getInstance();
                        t3->addBottom(static_cast<MOVE_LINE>(t3->getNextMoveLineId(mMoveLine)), static_cast<cUnit*>(mpGUISystemMsg), getUnitGroup());
                    }
                } else {
                    mpGUISystemMsg->mMode = 2;
                    mpGUISystemMsg->setDefaultChoicePos(0, -1);
                    mpGUISystemMsg->setCancelChoicePos(1, -1);
                    mpGUISystemMsg->mMsgAnalyzeAutoClear = false;
                    f32 t1 = static_cast<cGUIInstNull*>(mpInstSystemMsg)->mPosition.y;
                    f32 t2 = static_cast<cGUIInstNull*>(mpInstSystemMsg)->mPosition.z;
                    mpGUISystemMsg->mPos.x = static_cast<cGUIInstNull*>(mpInstSystemMsg)->mPosition.x;
                    mpGUISystemMsg->mPos.y = t1;
                    mpGUISystemMsg->mPos.z = t2;
                    mpGUISystemMsg->mPos.pad_ = 0.0f;
                    sUnit* t3 = sUnit::getInstance();
                    t3->addBottom(static_cast<MOVE_LINE>(t3->getNextMoveLineId(mMoveLine)), static_cast<cUnit*>(mpGUISystemMsg), getUnitGroup());
                }
            }
        }
    }
}

__attribute__((weak)) void uGUIBazaar::createBuyConfirm() {
    DDON_STUB("uGUIBazaar::createBuyConfirm")
    /* stub */
}

__attribute__((weak)) void uGUIBazaar::createExhibitCancelConfirm() {
    DDON_STUB("uGUIBazaar::createExhibitCancelConfirm")
    /* stub */
}

void uGUIBazaar::createExhibitCancelAnnounce(bool isSuccess) {
    s32 listNo = mpDealSheet->getSelectBazaarListIdx();
    if (listNo > -1) {
        sBazaarManager::cBazaarCharListData* pData = sBazaarManager::getInstance()->mCharInfoCtrl.getBazaarCharListData(static_cast<u32>(listNo));
        if (pData != nullptr) {
            u32 itemNo = pData->getItemId();
            if (itemNo != 0) {
                rItemList::rItemParam* prItemParam = sItemManager::getInstance()->getItemParam(itemNo);
                if (prItemParam != nullptr) {
                    if (isSuccess) {
                        MT_CTSTR t0 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 75u);
                        static_cast<sGUIExt*>(sGUI::getInstance())->requestAnnounce(t0, 0u, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), itemNo, 0u, true);
                    } else {
                        MT_CTSTR t1 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 84u);
                        static_cast<sGUIExt*>(sGUI::getInstance())->requestAnnounce(t1, 1u, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), itemNo, 0u, true);
                    }
                }
            }
        }
    }
}

void uGUIBazaar::createReExhibitConfirm() {
    if (mpDealSheet != nullptr) {
        s32 listNo = mpDealSheet->getSelectBazaarListIdx();
        if (listNo > -1) {
            sBazaarManager::cBazaarCharListData* pData = sBazaarManager::getInstance()->mCharInfoCtrl.getBazaarCharListData(static_cast<u32>(listNo));
            if (pData != nullptr) {
                u32 itemNo = pData->getItemId();
                if (itemNo != 0) {
                    s32 itemPrice = mpPopPriceSetting->getItemPrice();
                    s32 itemNum = mpPopPriceSetting->getItemNum();
                    if ((mpGUISystemMsg = new (16u) uGUISystemMsg(0u, 0u, false)) != nullptr) {
                        rItemList::rItemParam* prItemParam = sItemManager::getInstance()->getItemParam(itemNo);
                        if (prItemParam != nullptr) {
                            prItemParam->getItemName();
                            mpGUISystemMsg->setMsgAnalyzerWork(0u, static_cast<s32>(itemNo));
                            mpGUISystemMsg->setMsgAnalyzerWork(1u, itemNum);
                            mpGUISystemMsg->setMsgAnalyzerWork(2u, itemPrice * itemNum);
                            mpGUISystemMsg->setMsgAnalyzerWork(3u, 5);
                            mpGUISystemMsg->setMsgAnalyzerWork(4u, static_cast<s32>((static_cast<unsigned long>(static_cast<unsigned int>((itemPrice * itemNum) * 5)) * 0x51EB851F) >> 37));
                            MT_CTSTR pStr = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpGMDRes, 77u);
                            MT_CTSTR pYes = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 1u);
                            MT_CTSTR pNo = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgCommonMessage(), 2u);
                            uGUISystemMsg* pGUI = mpGUISystemMsg;
                            pGUI->setText(pStr, -1);
                            if (pYes != nullptr) {
                                pGUI->addChoiceInfo(pYes, 0u, nHuman::JOB_ID_NONE, -1, true);
                                if (pNo != nullptr) {
                                    pGUI->addChoiceInfo(pNo, 0u, nHuman::JOB_ID_NONE, -1, true);
                                    mpGUISystemMsg->mMode = 2;
                                    mpGUISystemMsg->setDefaultChoicePos(1, -1);
                                    mpGUISystemMsg->setCancelChoicePos(1, -1);
                                    mpGUISystemMsg->mMsgAnalyzeAutoClear = false;
                                    f32 t1 = static_cast<cGUIInstNull*>(mpInstSystemMsg)->mPosition.y;
                                    f32 t2 = static_cast<cGUIInstNull*>(mpInstSystemMsg)->mPosition.z;
                                    mpGUISystemMsg->mPos.x = static_cast<cGUIInstNull*>(mpInstSystemMsg)->mPosition.x;
                                    mpGUISystemMsg->mPos.y = t1;
                                    mpGUISystemMsg->mPos.z = t2;
                                    mpGUISystemMsg->mPos.pad_ = 0.0f;
                                    sUnit* t3 = sUnit::getInstance();
                                    t3->addBottom(static_cast<MOVE_LINE>(t3->getNextMoveLineId(mMoveLine)), static_cast<cUnit*>(mpGUISystemMsg), getUnitGroup());
                                } else {
                                    mpGUISystemMsg->mMode = 2;
                                    mpGUISystemMsg->setDefaultChoicePos(1, -1);
                                    mpGUISystemMsg->setCancelChoicePos(1, -1);
                                    mpGUISystemMsg->mMsgAnalyzeAutoClear = false;
                                    f32 t1 = static_cast<cGUIInstNull*>(mpInstSystemMsg)->mPosition.y;
                                    f32 t2 = static_cast<cGUIInstNull*>(mpInstSystemMsg)->mPosition.z;
                                    mpGUISystemMsg->mPos.x = static_cast<cGUIInstNull*>(mpInstSystemMsg)->mPosition.x;
                                    mpGUISystemMsg->mPos.y = t1;
                                    mpGUISystemMsg->mPos.z = t2;
                                    mpGUISystemMsg->mPos.pad_ = 0.0f;
                                    sUnit* t3 = sUnit::getInstance();
                                    t3->addBottom(static_cast<MOVE_LINE>(t3->getNextMoveLineId(mMoveLine)), static_cast<cUnit*>(mpGUISystemMsg), getUnitGroup());
                                }
                            } else {
                                mpGUISystemMsg->mMode = 2;
                                mpGUISystemMsg->setDefaultChoicePos(1, -1);
                                mpGUISystemMsg->setCancelChoicePos(1, -1);
                                mpGUISystemMsg->mMsgAnalyzeAutoClear = false;
                                f32 t1 = static_cast<cGUIInstNull*>(mpInstSystemMsg)->mPosition.y;
                                f32 t2 = static_cast<cGUIInstNull*>(mpInstSystemMsg)->mPosition.z;
                                mpGUISystemMsg->mPos.x = static_cast<cGUIInstNull*>(mpInstSystemMsg)->mPosition.x;
                                mpGUISystemMsg->mPos.y = t1;
                                mpGUISystemMsg->mPos.z = t2;
                                mpGUISystemMsg->mPos.pad_ = 0.0f;
                                sUnit* t3 = sUnit::getInstance();
                                t3->addBottom(static_cast<MOVE_LINE>(t3->getNextMoveLineId(mMoveLine)), static_cast<cUnit*>(mpGUISystemMsg), getUnitGroup());
                            }
                        } else {
                            setInputEvent(67u);
                        }
                    } else {
                        setInputEvent(67u);
                    }
                } else {
                    setInputEvent(67u);
                }
            } else {
                setInputEvent(67u);
            }
        } else {
            setInputEvent(67u);
        }
    } else {
        setInputEvent(67u);
    }
}

__attribute__((weak)) void uGUIBazaar::createCaution() {
    DDON_STUB("uGUIBazaar::createCaution")
    /* stub */
}

__attribute__((weak)) void uGUIBazaar::setBazaar2TopSel() {
    DDON_STUB("uGUIBazaar::setBazaar2TopSel")
    /* stub */
}

__attribute__((weak)) bool uGUIBazaar::isBoxFull(u32 itemNo, u32 Num) {
    DDON_STUB("uGUIBazaar::isBoxFull")
    return {};
}

inline uGUIBazaar::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBazaar::MyDTI uGUIBazaar::DTI("uGUIBazaar", &::uGUIBase::DTI, 2528ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIBazaar::MyDTI::newInstance() const {
    DDON_STUB("uGUIBazaar::MyDTI::newInstance")
    return nullptr;
}

