// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIArisenCardPop.h"
#include "Protocol/PacketData/Achievement.h"
#include "Protocol/PacketData/Common.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "Protocol/UserSession/S2C.h"
#include "cContextInterface.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rAchievement.h"
#include "rArchiveListArray.h"
#include "rCharacterEdit.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "sContextManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "../../XFramework/uGUI.h"
#include "uGUIArisenCard.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIArisenCardPop::getDTI() const {
    return uGUIArisenCardPop::DTI;
}

void* uGUIArisenCardPop::operator new(size_t sz, u32 align) {
    return uGUIArisenCardPop::getAllocator()->memAlloc(sz, align, uGUIArisenCardPop::DTI.getID());
}

__attribute__((noinline)) uGUIArisenCardPop::~uGUIArisenCardPop() {
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpGMDRes != nullptr) {
        mpGMDRes->release();
        mpGMDRes = nullptr;
    }
    if (mpBGGMDRes != nullptr) {
        mpBGGMDRes->release();
        mpBGGMDRes = nullptr;
    }
    if (mpAchieveRes != nullptr) {
        mpAchieveRes->release();
        mpAchieveRes = nullptr;
    }
    if (mpCategoryGMDRes != nullptr) {
        mpCategoryGMDRes->release();
        mpCategoryGMDRes = nullptr;
    }
    if (mpArisenCardGMDRes != nullptr) {
        mpArisenCardGMDRes->release();
        mpArisenCardGMDRes = nullptr;
    }
    if (mMode == 0) {
        static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->clearArisenCardBGListPacket();
    }
}

bool uGUIArisenCardPop::loadResource() {
    if (mpGUIRes == nullptr) {
        if ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_POP_CARD_GUI"), 129u, 1428024849l))) == nullptr) {
            return false;
        }
    }
    if (mpGMDRes == nullptr) {
        if ((mpGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ARISENCARD_POP_GMD"), 129u, 0l))) == nullptr) {
            return false;
        }
    }
    if (mpBGGMDRes == nullptr) {
        if ((mpBGGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ARISENCARD_BACKGROUND_NAME_GMD"), 129u, 0l))) == nullptr) {
            return false;
        }
    }
    if (mpAchieveRes == nullptr) {
        if ((mpAchieveRes = static_cast<rAchievementHeader*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ACHIEVEMENTTOTALINFO_ACH"), 129u, 0l))) == nullptr) {
            return false;
        }
    }
    if (mpCategoryGMDRes == nullptr) {
        if ((mpCategoryGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ACHIEVEMENT_CATEGORY_GMD"), 129u, 0l))) == nullptr) {
            return false;
        }
    }
    if (mpArisenCardGMDRes == nullptr) {
        if ((mpArisenCardGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ARISENCARD_GMD"), 129u, 0l))) == nullptr) {
            return false;
        }
    }
    return true;
}

void uGUIArisenCardPop::updatePtr() {
    if (mpCard == nullptr) {
        return;
    }
    if (mpCard->isEnable()) {
        return;
    }
    mpCard = nullptr;
}

void uGUIArisenCardPop::setup() {
    this->uGUIBase::setup();
    bool t2 = mIsEndLoadResource;
    if (!t2) {
        return;
    }
    sGUI* t3 = sGUI::getInstance();
    u32 t4 = static_cast<sGUIExt*>(t3)->issuePriority(11u);
    setPriority(t4, true);
    setPlay(true);
    u32 t8 = mMode;
    if (t8 != 0) {
        if (t8 == 1) {
            initAchieve();
            unsigned long t10 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 2128);
            if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
                mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIArisenCardPop::requestAchieveServer);
                mServerCommandStatusRsv = 450;
                mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIArisenCardPop::callbackAchieveServer);
                mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
                unsigned long t19 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 0);
                unsigned long t23 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 0)) + 664);
                cGUIInstance* t21 = getInstance(176u, false);
                mClose.setup(static_cast<uGUIBase*>(this), t21, static_cast<cReferenceUICloseBtn::CloseFunc>(&::uGUIArisenCardPop::evCtrlCancel));
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIArisenCardPop::updateWaitInit);
                f32 t24 = mPos.x;
                f32 t25 = mPos.y;
                float t26 = 8.0f;
                mBasePointerPos.x = t24 + t26;
                float t27 = -4.0f;
                mBasePointerPos.y = t25 + t27;
            } else {
                mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIArisenCardPop::requestAchieveServer);
                mServerCommandStatus = 450;
                mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIArisenCardPop::callbackAchieveServer);
                mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
                *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 2108) = 0;
                unsigned long t19 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 0);
                unsigned long t23 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 0)) + 664);
                cGUIInstance* t21 = getInstance(176u, false);
                mClose.setup(static_cast<uGUIBase*>(this), t21, static_cast<cReferenceUICloseBtn::CloseFunc>(&::uGUIArisenCardPop::evCtrlCancel));
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIArisenCardPop::updateWaitInit);
                f32 t24 = mPos.x;
                f32 t25 = mPos.y;
                float t26 = 8.0f;
                mBasePointerPos.x = t24 + t26;
                float t27 = -4.0f;
                mBasePointerPos.y = t25 + t27;
            }
            cGUIInstance* t28 = getInstance(79u, false);
            mpOtherActiveBar = static_cast<cGUIInstAnimation*>(t28);
        } else {
            if (t8 == 2) {
                initEmotion();
                initEmotionFrame();
                initEmotionList();
                setCategoryFocus(true);
                cGUIInstance* t17 = getInstance(176u, false);
                mClose.setup(static_cast<uGUIBase*>(this), t17, static_cast<cReferenceUICloseBtn::CloseFunc>(&::uGUIArisenCardPop::evCtrlCancel));
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIArisenCardPop::updateWait);
                f32 t24 = mPos.x;
                f32 t25 = mPos.y;
                float t26 = 8.0f;
                mBasePointerPos.x = t24 + t26;
                float t27 = -4.0f;
                mBasePointerPos.y = t25 + t27;
                cGUIInstance* t28 = getInstance(79u, false);
                mpOtherActiveBar = static_cast<cGUIInstAnimation*>(t28);
            } else {
                f32 t24 = mPos.x;
                f32 t25 = mPos.y;
                float t26 = 8.0f;
                mBasePointerPos.x = t24 + t26;
                float t27 = -4.0f;
                mBasePointerPos.y = t25 + t27;
                cGUIInstance* t28 = getInstance(79u, false);
                mpOtherActiveBar = static_cast<cGUIInstAnimation*>(t28);
            }
        }
    } else {
        initImage();
        unsigned long t12 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 2128);
        if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
            mpServerRequestFuncRsv = static_cast<ServerRequestFunc>(&::uGUIArisenCardPop::requestBGServer);
            mServerCommandStatusRsv = 468;
            mpServerSuccessFuncRsv = static_cast<ServerSuccessCallBack>(&::uGUIArisenCardPop::callbackBGServer);
            mpServerFailedFuncRsv = static_cast<uGUIBase::ServerFailedCallBack>(0);
            unsigned long t20 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 0);
            unsigned long t23 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 0)) + 664);
            cGUIInstance* t21 = getInstance(175u, false);
            mClose.setup(static_cast<uGUIBase*>(this), t21, static_cast<cReferenceUICloseBtn::CloseFunc>(&::uGUIArisenCardPop::evCtrlCancel));
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIArisenCardPop::updateWaitInit);
            f32 t24 = mPos.x;
            f32 t25 = mPos.y;
            float t26 = 8.0f;
            mBasePointerPos.x = t24 + t26;
            float t27 = -4.0f;
            mBasePointerPos.y = t25 + t27;
        } else {
            mpServerRequestFunc = static_cast<ServerRequestFunc>(&::uGUIArisenCardPop::requestBGServer);
            mServerCommandStatus = 468;
            mpServerSuccessFunc = static_cast<ServerSuccessCallBack>(&::uGUIArisenCardPop::callbackBGServer);
            mpServerFailedFunc = static_cast<uGUIBase::ServerFailedCallBack>(0);
            *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 2108) = 0;
            unsigned long t20 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 0);
            unsigned long t23 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 0)) + 664);
            cGUIInstance* t21 = getInstance(175u, false);
            mClose.setup(static_cast<uGUIBase*>(this), t21, static_cast<cReferenceUICloseBtn::CloseFunc>(&::uGUIArisenCardPop::evCtrlCancel));
            mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIArisenCardPop::updateWaitInit);
            f32 t24 = mPos.x;
            f32 t25 = mPos.y;
            float t26 = 8.0f;
            mBasePointerPos.x = t24 + t26;
            float t27 = -4.0f;
            mBasePointerPos.y = t25 + t27;
        }
        cGUIInstance* t28 = getInstance(79u, false);
        mpOtherActiveBar = static_cast<cGUIInstAnimation*>(t28);
    }
}

void uGUIArisenCardPop::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpGMDRes != nullptr) {
        mpGMDRes->release();
        mpGMDRes = nullptr;
    }
    if (mpBGGMDRes != nullptr) {
        mpBGGMDRes->release();
        mpBGGMDRes = nullptr;
    }
    if (mpAchieveRes != nullptr) {
        mpAchieveRes->release();
        mpAchieveRes = nullptr;
    }
    if (mpCategoryGMDRes != nullptr) {
        mpCategoryGMDRes->release();
        mpCategoryGMDRes = nullptr;
    }
    if (mpArisenCardGMDRes == nullptr) {
        return;
    }
    mpArisenCardGMDRes->release();
    mpArisenCardGMDRes = nullptr;
}

void uGUIArisenCardPop::setFocusForActiveBar(bool IsActive) {
    if (mpEmotionFrameActiveBar != nullptr) {
        if (mIsSliderMode) {
            mpEmotionFrameActiveBar->setVisible(IsActive);
            if (mMode != 0) {
                if (mpOtherActiveBar != nullptr) {
                    mpOtherActiveBar->setVisible(!IsActive);
                }
            } else {
                this->uGUIBase::setFocusForActiveBar(!IsActive);
            }
        } else {
            mpEmotionFrameActiveBar->setVisible(false);
            if (mMode != 0) {
                if (mpOtherActiveBar != nullptr) {
                    mpOtherActiveBar->setVisible(IsActive);
                }
            } else {
                this->uGUIBase::setFocusForActiveBar(IsActive);
            }
        }
    } else {
        if (mMode != 0) {
            if (mpOtherActiveBar != nullptr) {
                mpOtherActiveBar->setVisible(IsActive);
            }
        } else {
            this->uGUIBase::setFocusForActiveBar(IsActive);
        }
    }
}

void uGUIArisenCardPop::setMode(u32 Mode) {
    mMode = Mode;
}

void uGUIArisenCardPop::moveInput() {
    if (mpServerRequestFunc != static_cast<uGUIBase::ServerRequestFunc>(0)) {
        return;
    }
    if (moveInputSlider()) {
        return;
    }
    mClose.execute();
    if (mMode != 2) {
        if (mMode == 1) {
            mScrollList.executeCtrl();
            mScrollMenu.executeCtrl();
        } else {
            if (mMode == 0) {
                mScrollBG.executeCtrl();
            }
        }
    } else {
        mScrollList.executeCtrl();
        mScrollMenu.executeCtrl();
    }
}

__attribute__((weak)) void uGUIArisenCardPop::moveEvent() {
    DDON_STUB("uGUIArisenCardPop::moveEvent")
    /* stub */
}

__attribute__((weak)) bool uGUIArisenCardPop::moveInputSlider() {
    if (mIsSliderMode) {
        if (mpSliderCtrl != nullptr) {
            if (mInputEventId == 0) {
                if (mpSliderCtrl->mCurrentPos != 0) {
                    if (mSlider.executeMouse()) {
                        if (mpSliderCtrl != nullptr) {
                            mpSliderCtrl->setCurrentPos(0, false);
                        }
                        setInputEvent(82u);
                    }
                } else {
                    if (mSlider.execute(false)) {
                        setInputEvent(82u);
                    }
                }
            }
            mpSliderCtrl->execute();
            mCloseFrame.execute();
        } else {
            sleepSlider();
        }
        return true;
    } else {
        return false;
    }
}

void uGUIArisenCardPop::updateWaitInit() {
    static_cast<sGUIExt*>(sGUI::getInstance())->hidePointer(getBasePointerPriority());
    updateWait();
}

__attribute__((weak)) void uGUIArisenCardPop::updateWait() {
    mClose.uGUIBase::cReferenceUICloseBtn::update();
    if (mIsSliderMode) {
        if (mpSliderCtrl != nullptr) {
            if (mpSliderCtrl->getCurrentPos() == 1) {
                mSlider.uGUIBase::cReferenceUIEditSlider::setFocus(false);
                mSliderButton.uGUIBase::cReferenceUIButton::setFocus(true);
            } else {
                if (mpSliderCtrl->getCurrentPos() == 0) {
                    mSlider.uGUIBase::cReferenceUIEditSlider::setFocus(true);
                    mSliderButton.uGUIBase::cReferenceUIButton::setFocus(false);
                }
            }
        }
        mCloseFrame.uGUIBase::cReferenceUICloseBtn::update();
        (&mSlider)->update();
        (&mSliderButton)->update();
    }
    mMainCursor.uGUIBase::cReferenceUIVlCursor::update();
    mSubCursor.uGUIBase::cReferenceUIVlCursor::update();
    mScrollBG.uGUIBase::cScrollList::update(getDeltaTime());
    mScrollMenu.uGUIBase::cScrollList::update(getDeltaTime());
    mScrollList.uGUIBase::cScrollList::update(getDeltaTime());
}

u32 uGUIArisenCardPop::evCtrlCancel(cControl::Message* pMsg) {
    setInputEvent(66u);
    return 1;
}

u32 uGUIArisenCardPop::evCtrlDecide(cControl::Message* pMsg) {
    if (mMode != 2) {
        if (mMode == 1) {
            if (mListNum != 0) {
                setInputEvent(73u);
            }
            return 1;
        } else {
            if (mMode == 0) {
                setInputEvent(68u);
                return 1;
            } else {
                return 0;
            }
        }
    } else {
        if (mListNum != 0) {
            setInputEvent(78u);
        }
        return 1;
    }
}

u32 uGUIArisenCardPop::evCtrlCancelSub(cControl::Message* pMsg) {
    if (mMode == 2) {
        setInputEvent(77u);
        return 1;
    } else {
        if (mMode == 1) {
            setInputEvent(72u);
            return 1;
        } else {
            return 0;
        }
    }
}

u32 uGUIArisenCardPop::evCtrlDecideSub(cControl::Message* pMsg) {
    if (mMode == 2) {
        setInputEvent(79u);
        return 1;
    } else {
        if (mMode == 1) {
            setInputEvent(74u);
            return 1;
        } else {
            return 0;
        }
    }
}

u32 uGUIArisenCardPop::evCtrlEmotionFrameCancel(cControl::Message* pMsg) {
    setInputEvent(80u);
    return 1;
}

u32 uGUIArisenCardPop::evCtrlEmotionFrameDecide(cControl::Message* pMsg) {
    if (mpSliderCtrl != nullptr) {
        if (mpSliderCtrl->mCurrentPos == 1) {
            setInputEvent(81u);
        }
    }
    return 1;
}

u32 uGUIArisenCardPop::evCtrlEmotionFrameMoveUD(cControl::Message* pMsg) {
    setInputEvent(83u);
    return 1;
}

u32 uGUIArisenCardPop::evCtrlEmotionFrameMouseClick(cControl::Message* pMsg) {
    if (mpSliderCtrl != nullptr) {
        if (mpSliderCtrl->mCurrentPos == 1) {
            setInputEvent(81u);
        }
    }
    return 1;
}

__attribute__((weak)) void uGUIArisenCardPop::initImage() {
    DDON_STUB("uGUIArisenCardPop::initImage")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCardPop::initAchieve() {
    DDON_STUB("uGUIArisenCardPop::initAchieve")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCardPop::initAchieveList() {
    DDON_STUB("uGUIArisenCardPop::initAchieveList")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCardPop::initEmotion() {
    DDON_STUB("uGUIArisenCardPop::initEmotion")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCardPop::initEmotionFrame() {
    DDON_STUB("uGUIArisenCardPop::initEmotionFrame")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCardPop::initEmotionList() {
    DDON_STUB("uGUIArisenCardPop::initEmotionList")
    /* stub */
}

void uGUIArisenCardPop::updateBGDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index) {
    s32 j0;
    if (pDispItem == nullptr) {
        return;
    }
    cGUIInstAnimation* pinst = static_cast<cGUIInstAnimation*>(pDispItem->mpInstPointerTarget);
    if (pinst != nullptr) {
        pinst->setExecute(true);
        pinst->setVisible(true);
        pinst->setPositionY(mListBasePosY + (mListOfsY * static_cast<float>(Index)));
        if (mScrollBG.mpVCtrl != nullptr) {
            j0 = mScrollBG.mpVCtrl->getCurrentPos();
        } else {
            j0 = 0;
        }
        if (Index == static_cast<unsigned int>(j0)) {
            pinst->setSequenceId(4u);
        }
    }
    const nUserSession::CPacket_S2C_GET_AVAILABLE_BACKGROUND_LIST_RES* pdata = static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getArisenCardBGListPacket();
    if (pdata == nullptr) {
        return;
    }
    if (Index < pdata->m_BackgroundIdList.mLength) {
        if (static_cast<CDataCommonU32*>(pdata->m_BackgroundIdList.mpArray[Index])->m_unvalue != 0) {
            cScrollDispList* pdisp = static_cast<cScrollDispList*>(pDispItem);
            cGUIObjMessage* t0 = pdisp->mpText;
            if (t0 != nullptr) {
                setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpBGGMDRes, static_cast<CDataCommonU32*>(pdata->m_BackgroundIdList.mpArray[Index])->m_unvalue - 1u), 0u, false);
            }
        }
    }
}

void uGUIArisenCardPop::updateBGHide(uGUIBase::cScrollListItemBase* pDispItem) {
    if (pDispItem->mpInstPointerTarget == nullptr) {
        return;
    }
    pDispItem->mpInstPointerTarget->setExecute(false);
    pDispItem->mpInstPointerTarget->setVisible(false);
}

void uGUIArisenCardPop::updateAchieveMenuDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index) {
    s32 j0;
    cGUIInstAnimation* pinst = static_cast<cGUIInstAnimation*>(pDispItem->mpInstPointerTarget);
    if (pinst != nullptr) {
        pinst->setExecute(true);
        pinst->setVisible(true);
        pinst->setPositionY(mMenuBasePosY + (mMenuOfsY * static_cast<float>(Index)));
        if (mScrollMenu.mpVCtrl != nullptr) {
            j0 = mScrollMenu.mpVCtrl->getCurrentPos();
        } else {
            j0 = 0;
        }
        if (Index == static_cast<unsigned int>(j0)) {
            pinst->setSequenceId(4u);
        }
    }
    cScrollDispList* pdisp = static_cast<cScrollDispList*>(pDispItem);
    cGUIObjMessage* t0 = pdisp->mpText;
    if (t0 == nullptr) {
        return;
    }
    setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpCategoryGMDRes, Index), 0u, false);
}

void uGUIArisenCardPop::updateAchieveMenuHide(uGUIBase::cScrollListItemBase* pDispItem) {
    if (pDispItem->mpInstPointerTarget == nullptr) {
        return;
    }
    pDispItem->mpInstPointerTarget->setExecute(false);
    pDispItem->mpInstPointerTarget->setVisible(false);
}

void uGUIArisenCardPop::updateAchieveDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index) {
    s32 j0;
    cGUIInstAnimation* pinst = static_cast<cGUIInstAnimation*>(pDispItem->mpInstPointerTarget);
    if (pinst != nullptr) {
        pinst->setExecute(true);
        pinst->setVisible(true);
        pinst->setPositionY(mListBasePosY + (mListOfsY * static_cast<float>(Index)));
        if (mScrollList.mpVCtrl != nullptr) {
            j0 = mScrollList.mpVCtrl->getCurrentPos();
        } else {
            j0 = 0;
        }
        if (Index == static_cast<unsigned int>(j0)) {
            pinst->setSequenceId(4u);
        }
    }
    cScrollDispList* pdisp = static_cast<cScrollDispList*>(pDispItem);
    cGUIObjMessage* t0 = pdisp->mpText;
    if (t0 == nullptr) {
        return;
    }
    if (mListNum != 0) {
        cScrollListInfo* pinfo = static_cast<cScrollListInfo*>(pListItem);
        if (pinfo->mMsgId != 0xFFFFFFFFu) {
            setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getAchievementName(pinfo->mMsgId), 0u, false);
        } else {
            setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(mpArisenCardGMDRes, 77u), 0u, false);
        }
    } else {
        setObjectMessage(static_cast<cGUIObject*>(t0), "", 0u, false);
    }
}

void uGUIArisenCardPop::updateAchieveHide(uGUIBase::cScrollListItemBase* pDispItem) {
    if (pDispItem->mpInstPointerTarget == nullptr) {
        return;
    }
    pDispItem->mpInstPointerTarget->setExecute(false);
    pDispItem->mpInstPointerTarget->setVisible(false);
}

void uGUIArisenCardPop::updateEmotionMenuDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index) {
    s32 j0;
    cGUIInstAnimation* pinst = static_cast<cGUIInstAnimation*>(pDispItem->mpInstPointerTarget);
    if (pinst != nullptr) {
        pinst->setExecute(true);
        pinst->setVisible(true);
        pinst->setPositionY(mMenuBasePosY + (mMenuOfsY * static_cast<float>(Index)));
        if (mScrollMenu.mpVCtrl != nullptr) {
            j0 = mScrollMenu.mpVCtrl->getCurrentPos();
        } else {
            j0 = 0;
        }
        if (Index == static_cast<unsigned int>(j0)) {
            pinst->setSequenceId(4u);
        }
    }
    cScrollDispList* pdisp = static_cast<cScrollDispList*>(pDispItem);
    cGUIObjMessage* t0 = pdisp->mpText;
    if (t0 == nullptr) {
        return;
    }
    setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgEmotionCtgrMessage(Index), 0u, false);
}

void uGUIArisenCardPop::updateEmotionMenuHide(uGUIBase::cScrollListItemBase* pDispItem) {
    if (pDispItem->mpInstPointerTarget == nullptr) {
        return;
    }
    pDispItem->mpInstPointerTarget->setExecute(false);
    pDispItem->mpInstPointerTarget->setVisible(false);
}

void uGUIArisenCardPop::updateEmotionDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index) {
    s32 j0;
    cGUIInstAnimation* pinst = static_cast<cGUIInstAnimation*>(pDispItem->mpInstPointerTarget);
    if (pinst != nullptr) {
        pinst->setExecute(true);
        pinst->setVisible(true);
        pinst->setPositionY(mListBasePosY + (mListOfsY * static_cast<float>(Index)));
        if (mScrollList.mpVCtrl != nullptr) {
            j0 = mScrollList.mpVCtrl->getCurrentPos();
        } else {
            j0 = 0;
        }
        if (Index == static_cast<unsigned int>(j0)) {
            pinst->setSequenceId(4u);
        }
    }
    cScrollDispList* pdisp = static_cast<cScrollDispList*>(pDispItem);
    cGUIObjMessage* t0 = pdisp->mpText;
    if (t0 == nullptr) {
        return;
    }
    if (mListNum != 0) {
        setObjectMessage(static_cast<cGUIObject*>(t0), static_cast<sGUIExt*>(sGUI::getInstance())->getMsgProfileEmotionMessageFromIndex(mCategoryNo, Index), 0u, false);
    } else {
        setObjectMessage(static_cast<cGUIObject*>(t0), "", 0u, false);
    }
}

void uGUIArisenCardPop::updateEmotionHide(uGUIBase::cScrollListItemBase* pDispItem) {
    if (pDispItem->mpInstPointerTarget == nullptr) {
        return;
    }
    pDispItem->mpInstPointerTarget->setExecute(false);
    pDispItem->mpInstPointerTarget->setVisible(false);
}

__attribute__((weak)) void uGUIArisenCardPop::setCategoryFocus(bool IsFocus) {
    DDON_STUB("uGUIArisenCardPop::setCategoryFocus")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCardPop::wakeupSlider() {
    DDON_STUB("uGUIArisenCardPop::wakeupSlider")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCardPop::sleepSlider() {
    DDON_STUB("uGUIArisenCardPop::sleepSlider")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCardPop::updateEmotion() {
    DDON_STUB("uGUIArisenCardPop::updateEmotion")
    /* stub */
}

bool uGUIArisenCardPop::requestBGServer() {
    return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getAvailableBackgroundList();
}

__attribute__((weak)) void uGUIArisenCardPop::callbackBGServer() {
    DDON_STUB("uGUIArisenCardPop::callbackBGServer")
    /* stub */
}

bool uGUIArisenCardPop::requestAchieveServer() {
    return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getAchievementProgress();
}

__attribute__((weak)) void uGUIArisenCardPop::callbackAchieveServer() {
    DDON_STUB("uGUIArisenCardPop::callbackAchieveServer")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCardPop::updateSubListCursor() {
    DDON_STUB("uGUIArisenCardPop::updateSubListCursor")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCardPop::decideAchieve() {
    DDON_STUB("uGUIArisenCardPop::decideAchieve")
    /* stub */
}

inline uGUIArisenCardPop::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIArisenCardPop::MyDTI uGUIArisenCardPop::DTI("uGUIArisenCardPop", &::uGUIBase::DTI, 11856ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIArisenCardPop::MyDTI::newInstance() const {
    DDON_STUB("uGUIArisenCardPop::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIArisenCardPop::cScrollDispList::getDTI() const {
    return uGUIArisenCardPop::cScrollDispList::DTI;
}

inline uGUIArisenCardPop::cScrollDispList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIArisenCardPop::cScrollDispList::MyDTI uGUIArisenCardPop::cScrollDispList::DTI("uGUIArisenCardPop::cScrollDispList", &::uGUIBase::cScrollListItemBase::DTI, 96ul, 0u, 0u);

MtObject* uGUIArisenCardPop::cScrollDispList::MyDTI::newInstance() const {
    return new (16u) uGUIArisenCardPop::cScrollDispList;
}

const MtDTI& uGUIArisenCardPop::cScrollListInfo::getDTI() const {
    return uGUIArisenCardPop::cScrollListInfo::DTI;
}

inline uGUIArisenCardPop::cScrollListInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIArisenCardPop::cScrollListInfo::MyDTI uGUIArisenCardPop::cScrollListInfo::DTI("uGUIArisenCardPop::cScrollListInfo", &::uGUIBase::cScrollListInfoBase::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIArisenCardPop::cScrollListInfo::MyDTI::newInstance() const {
    DDON_STUB("uGUIArisenCardPop::cScrollListInfo::MyDTI::newInstance")
    return nullptr;
}

