// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUILoginBonus.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "Protocol/PacketData/StampBonus.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "rItemList.h"
#include "../../XFramework/rSoundRequest.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sItemManager.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/sUnit.h"
#include "../../XFramework/uCoord.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#include "uGUIPopDetail01.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUILoginBonus::getDTI() const {
    return uGUILoginBonus::DTI;
}

inline MtAllocator* uGUILoginBonus::getAllocator() {
    return MtMemoryAllocator::getAllocator(uGUILoginBonus::DTI);
}

void* uGUILoginBonus::operator new(size_t sz, u32 align) {
    return uGUILoginBonus::getAllocator()->memAlloc(sz, align, uGUILoginBonus::DTI.getID());
}

inline void uGUILoginBonus::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUILoginBonus::DTI)->memFree(p_addr);
}

__attribute__((noinline)) uGUILoginBonus::~uGUILoginBonus() {
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpSeRes == nullptr) {
        return;
    }
    mpSeRes->release();
    mpSeRes = nullptr;
}

void uGUILoginBonus::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
}

bool uGUILoginBonus::loadResource() {
    if (mpGUIRes == nullptr) {
        if ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_LOGINBONUS_GUI"), 129u, 1434077486l))) != nullptr) {
            if (loadGMDarc(getArcTag(0u), "RES_ID_STAMPBONUS_GMD", 0u)) {
                if ((mpSeRes == nullptr) && ((mpSeRes = static_cast<rSoundRequest*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ID_LOGIN_SRQR"), 129u, 0l))) == nullptr)) {
                    return false;
                }
                return true;
            }
        }
    } else {
        if (loadGMDarc(getArcTag(0u), "RES_ID_STAMPBONUS_GMD", 0u)) {
            if ((mpSeRes == nullptr) && ((mpSeRes = static_cast<rSoundRequest*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ID_LOGIN_SRQR"), 129u, 0l))) == nullptr)) {
                return false;
            }
            return true;
        }
    }
    return false;
}

__attribute__((weak)) void uGUILoginBonus::setup() {
    DDON_STUB("uGUILoginBonus::setup")
    /* stub */
}

void uGUILoginBonus::kill() {
    if (mpPopDetail != nullptr) {
        mpPopDetail->kill();
        mpPopDetail = nullptr;
    }
    this->uGUIBase::kill();
}

void uGUILoginBonus::updatePtr() {
    if (mpPopDetail == nullptr) {
        return;
    }
    if (mpPopDetail->isEnable()) {
        return;
    }
    mpPopDetail = nullptr;
}

__attribute__((weak)) void uGUILoginBonus::adjustScale() {
    DDON_STUB("uGUILoginBonus::adjustScale")
    /* stub */
}

void uGUILoginBonus::setStampEffect(u32 idx) {
    switch (mStat) {
        case 0:
        {
            setSequenceId(mListCumIcon[idx].mpInstEffect, 2u, true);
            setSequenceId(mListCumIcon[idx].mpInstStamp, 2u, true);
            if (mListCumIcon[idx].mpTexEf != nullptr) {
                mListCumIcon[idx].mpTexEf->setCurrentFrame(1.0f, true);
                if (mListCumIcon[idx].mpTexMsk != nullptr) {
                    mListCumIcon[idx].mpTexMsk->setCurrentFrame(1.0f, true);
                    if (mListCumIcon[idx].mpTexSt != nullptr) {
                        mListCumIcon[idx].mpTexSt->setCurrentFrame(1.0f, true);
                    }
                } else {
                    if (mListCumIcon[idx].mpTexSt != nullptr) {
                        mListCumIcon[idx].mpTexSt->setCurrentFrame(1.0f, true);
                    }
                }
            } else {
                if (mListCumIcon[idx].mpTexMsk != nullptr) {
                    mListCumIcon[idx].mpTexMsk->setCurrentFrame(1.0f, true);
                    if (mListCumIcon[idx].mpTexSt != nullptr) {
                        mListCumIcon[idx].mpTexSt->setCurrentFrame(1.0f, true);
                    }
                } else {
                    if (mListCumIcon[idx].mpTexSt != nullptr) {
                        mListCumIcon[idx].mpTexSt->setCurrentFrame(1.0f, true);
                    }
                }
            }
            break;
        }
        case 1:
        {
            setSequenceId(mListSeqIcon[idx].mpInstEffect, 2u, true);
            setSequenceId(mListSeqIcon[idx].mpInstStamp, 2u, true);
            if (mListSeqIcon[idx].mpTexEf != nullptr) {
                mListSeqIcon[idx].mpTexEf->setCurrentFrame(0.0f, true);
                if (mListSeqIcon[idx].mpTexMsk != nullptr) {
                    mListSeqIcon[idx].mpTexMsk->setCurrentFrame(0.0f, true);
                    if (mListSeqIcon[idx].mpTexSt != nullptr) {
                        mListSeqIcon[idx].mpTexSt->setCurrentFrame(0.0f, true);
                    }
                } else {
                    if (mListSeqIcon[idx].mpTexSt != nullptr) {
                        mListSeqIcon[idx].mpTexSt->setCurrentFrame(0.0f, true);
                    }
                }
            } else {
                if (mListSeqIcon[idx].mpTexMsk != nullptr) {
                    mListSeqIcon[idx].mpTexMsk->setCurrentFrame(0.0f, true);
                    if (mListSeqIcon[idx].mpTexSt != nullptr) {
                        mListSeqIcon[idx].mpTexSt->setCurrentFrame(0.0f, true);
                    }
                } else {
                    if (mListSeqIcon[idx].mpTexSt != nullptr) {
                        mListSeqIcon[idx].mpTexSt->setCurrentFrame(0.0f, true);
                    }
                }
            }
            break;
        }
        case 2:
        {
            setSequenceId(mListCumIcon[idx].mpInstEffect, 2u, true);
            setSequenceId(mListCumIcon[idx].mpInstStamp, 2u, true);
            if (mListCumIcon[idx].mpTexEf != nullptr) {
                mListCumIcon[idx].mpTexEf->setCurrentFrame(1.0f, true);
                if (mListCumIcon[idx].mpTexMsk != nullptr) {
                    mListCumIcon[idx].mpTexMsk->setCurrentFrame(1.0f, true);
                    if (mListCumIcon[idx].mpTexSt != nullptr) {
                        mListCumIcon[idx].mpTexSt->setCurrentFrame(1.0f, true);
                    }
                } else {
                    if (mListCumIcon[idx].mpTexSt != nullptr) {
                        mListCumIcon[idx].mpTexSt->setCurrentFrame(1.0f, true);
                    }
                }
            } else {
                if (mListCumIcon[idx].mpTexMsk != nullptr) {
                    mListCumIcon[idx].mpTexMsk->setCurrentFrame(1.0f, true);
                    if (mListCumIcon[idx].mpTexSt != nullptr) {
                        mListCumIcon[idx].mpTexSt->setCurrentFrame(1.0f, true);
                    }
                } else {
                    if (mListCumIcon[idx].mpTexSt != nullptr) {
                        mListCumIcon[idx].mpTexSt->setCurrentFrame(1.0f, true);
                    }
                }
            }
            break;
        }
        case 3:
        {
            setSequenceId(mListSeqIcon[idx].mpInstEffect, 2u, true);
            setSequenceId(mListSeqIcon[idx].mpInstStamp, 2u, true);
            if (mListSeqIcon[idx].mpTexEf != nullptr) {
                mListSeqIcon[idx].mpTexEf->setCurrentFrame(0.0f, true);
                if (mListSeqIcon[idx].mpTexMsk != nullptr) {
                    mListSeqIcon[idx].mpTexMsk->setCurrentFrame(0.0f, true);
                    if (mListSeqIcon[idx].mpTexSt != nullptr) {
                        mListSeqIcon[idx].mpTexSt->setCurrentFrame(0.0f, true);
                    }
                } else {
                    if (mListSeqIcon[idx].mpTexSt != nullptr) {
                        mListSeqIcon[idx].mpTexSt->setCurrentFrame(0.0f, true);
                    }
                }
            } else {
                if (mListSeqIcon[idx].mpTexMsk != nullptr) {
                    mListSeqIcon[idx].mpTexMsk->setCurrentFrame(0.0f, true);
                    if (mListSeqIcon[idx].mpTexSt != nullptr) {
                        mListSeqIcon[idx].mpTexSt->setCurrentFrame(0.0f, true);
                    }
                } else {
                    if (mListSeqIcon[idx].mpTexSt != nullptr) {
                        mListSeqIcon[idx].mpTexSt->setCurrentFrame(0.0f, true);
                    }
                }
            }
            break;
        }
        default:
        {
            break;
        }
    }
}

__attribute__((weak)) void uGUILoginBonus::callStampEffect() {
    DDON_STUB("uGUILoginBonus::callStampEffect")
    /* stub */
}

__attribute__((weak)) void uGUILoginBonus::reset() {
    DDON_STUB("uGUILoginBonus::reset")
    /* stub */
}

__attribute__((weak)) void uGUILoginBonus::makeItemName(MtString& rStr, MT_CTSTR name, u32 plus_value, u32 idx) {
    DDON_STUB("uGUILoginBonus::makeItemName")
    /* stub */
}

__attribute__((weak)) void uGUILoginBonus::setupCtrl() {
    DDON_STUB("uGUILoginBonus::setupCtrl")
    /* stub */
}

__attribute__((weak)) void uGUILoginBonus::setupMenu() {
    DDON_STUB("uGUILoginBonus::setupMenu")
    /* stub */
}

__attribute__((weak)) void uGUILoginBonus::setupListData(u32 idx) {
    DDON_STUB("uGUILoginBonus::setupListData")
    /* stub */
}

__attribute__((weak)) void uGUILoginBonus::setupServer() {
    DDON_STUB("uGUILoginBonus::setupServer")
    /* stub */
}

__attribute__((weak)) void uGUILoginBonus::initCumulative() {
    DDON_STUB("uGUILoginBonus::initCumulative")
    /* stub */
}

__attribute__((weak)) void uGUILoginBonus::initSequencial() {
    DDON_STUB("uGUILoginBonus::initSequencial")
    /* stub */
}

__attribute__((weak)) void uGUILoginBonus::updateInit() {
    DDON_STUB("uGUILoginBonus::updateInit")
    /* stub */
}

void uGUILoginBonus::updateWait() {
    switch (mStat) {
        case 0:
        {
            initCumulative();
            mpMatCtrl->resetItemNum(10, 5, static_cast<const u32*>(nullptr), mOldLocateCum, 0u);
            mListCumIcon[mpMatCtrl->mCurrentPos].mIcon.uGUIBase::cReferenceUIIconItem::update();
            if (mCtrlStat == 0) {
                static_cast<sGUIExt*>(sGUI::getInstance())->updatePointerGuide(getBasePointerPriority());
                callStampEffect();
                if (mpBtnCtrl != nullptr) {
                    if (mBtn.uGUIBase::cReferenceUIButton::isFocus()) {
                        (&mBtn)->update();
                        mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                        updateItemDetail();
                    } else {
                        mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                        updateItemDetail();
                    }
                } else {
                    mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                    updateItemDetail();
                }
            } else {
                callStampEffect();
                if (mpBtnCtrl != nullptr) {
                    if (mBtn.uGUIBase::cReferenceUIButton::isFocus()) {
                        (&mBtn)->update();
                        mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                        updateItemDetail();
                    } else {
                        mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                        updateItemDetail();
                    }
                } else {
                    mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                    updateItemDetail();
                }
            }
            break;
        }
        case 1:
        {
            initSequencial();
            mpMatCtrl->resetItemNum(8, 4, static_cast<const u32*>(nullptr), mOldLocateSeq, 0u);
            mListSeqIcon[mpMatCtrl->mCurrentPos].mIcon.uGUIBase::cReferenceUIIconItem::update();
            if (mCtrlStat == 0) {
                static_cast<sGUIExt*>(sGUI::getInstance())->updatePointerGuide(getBasePointerPriority());
                callStampEffect();
                if (mpBtnCtrl != nullptr) {
                    if (mBtn.uGUIBase::cReferenceUIButton::isFocus()) {
                        (&mBtn)->update();
                        mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                        updateItemDetail();
                    } else {
                        mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                        updateItemDetail();
                    }
                } else {
                    mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                    updateItemDetail();
                }
            } else {
                callStampEffect();
                if (mpBtnCtrl != nullptr) {
                    if (mBtn.uGUIBase::cReferenceUIButton::isFocus()) {
                        (&mBtn)->update();
                        mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                        updateItemDetail();
                    } else {
                        mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                        updateItemDetail();
                    }
                } else {
                    mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                    updateItemDetail();
                }
            }
            break;
        }
        case 2:
        {
            initCumulative();
            mpMatCtrl->resetItemNum(10, 5, static_cast<const u32*>(nullptr), mOldLocateCum, 0u);
            mListCumIcon[mpMatCtrl->mCurrentPos].mIcon.uGUIBase::cReferenceUIIconItem::update();
            if (mCtrlStat == 0) {
                static_cast<sGUIExt*>(sGUI::getInstance())->updatePointerGuide(getBasePointerPriority());
                callStampEffect();
                if (mpBtnCtrl != nullptr) {
                    if (mBtn.uGUIBase::cReferenceUIButton::isFocus()) {
                        (&mBtn)->update();
                        mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                        updateItemDetail();
                    } else {
                        mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                        updateItemDetail();
                    }
                } else {
                    mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                    updateItemDetail();
                }
            } else {
                callStampEffect();
                if (mpBtnCtrl != nullptr) {
                    if (mBtn.uGUIBase::cReferenceUIButton::isFocus()) {
                        (&mBtn)->update();
                        mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                        updateItemDetail();
                    } else {
                        mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                        updateItemDetail();
                    }
                } else {
                    mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                    updateItemDetail();
                }
            }
            break;
        }
        case 3:
        {
            initSequencial();
            mpMatCtrl->resetItemNum(8, 4, static_cast<const u32*>(nullptr), mOldLocateSeq, 0u);
            mListSeqIcon[mpMatCtrl->mCurrentPos].mIcon.uGUIBase::cReferenceUIIconItem::update();
            if (mCtrlStat == 0) {
                static_cast<sGUIExt*>(sGUI::getInstance())->updatePointerGuide(getBasePointerPriority());
                callStampEffect();
                if (mpBtnCtrl != nullptr) {
                    if (mBtn.uGUIBase::cReferenceUIButton::isFocus()) {
                        (&mBtn)->update();
                        mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                        updateItemDetail();
                    } else {
                        mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                        updateItemDetail();
                    }
                } else {
                    mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                    updateItemDetail();
                }
            } else {
                callStampEffect();
                if (mpBtnCtrl != nullptr) {
                    if (mBtn.uGUIBase::cReferenceUIButton::isFocus()) {
                        (&mBtn)->update();
                        mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                        updateItemDetail();
                    } else {
                        mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                        updateItemDetail();
                    }
                } else {
                    mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                    updateItemDetail();
                }
            }
            break;
        }
        default:
        {
            if (mCtrlStat == 0) {
                static_cast<sGUIExt*>(sGUI::getInstance())->updatePointerGuide(getBasePointerPriority());
                callStampEffect();
                if (mpBtnCtrl != nullptr) {
                    if (mBtn.uGUIBase::cReferenceUIButton::isFocus()) {
                        (&mBtn)->update();
                        mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                        updateItemDetail();
                    } else {
                        mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                        updateItemDetail();
                    }
                } else {
                    mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                    updateItemDetail();
                }
            } else {
                callStampEffect();
                if (mpBtnCtrl != nullptr) {
                    if (mBtn.uGUIBase::cReferenceUIButton::isFocus()) {
                        (&mBtn)->update();
                        mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                        updateItemDetail();
                    } else {
                        mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                        updateItemDetail();
                    }
                } else {
                    mCloseBtn.uGUIBase::cReferenceUICloseBtn::update();
                    updateItemDetail();
                }
            }
            break;
        }
    }
}

void uGUILoginBonus::updateExit() {
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[481] == sNetworkExt::NET_STAT_REQ) {
        return;
    }
    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[483] == sNetworkExt::NET_STAT_REQ) {
        return;
    }
    end();
    if (mpPopDetail == nullptr) {
        return;
    }
    mpPopDetail->mIsDraw = false;
}

__attribute__((weak)) void uGUILoginBonus::setupFocus() {
    DDON_STUB("uGUILoginBonus::setupFocus")
    /* stub */
}

__attribute__((weak)) void uGUILoginBonus::updateItemDetail() {
    DDON_STUB("uGUILoginBonus::updateItemDetail")
    /* stub */
}

void uGUILoginBonus::moveInput() {
    if (mpCtrl != nullptr) {
        mpCtrl->execute();
    }
    mCloseBtn.execute();
    if ((mStat & 0xFFFFFFFEu) == 2) {
        if (mpTabCtrl != nullptr) {
            mpTabCtrl->execute();
        }
    }
    if (mInputEventId == 70) {
        return;
    }
    if (mpMatCtrl != nullptr) {
        mpMatCtrl->execute();
    }
    if (mpBtnCtrl == nullptr) {
        return;
    }
    mpBtnCtrl->execute();
}

__attribute__((weak)) void uGUILoginBonus::moveEvent() {
    DDON_STUB("uGUILoginBonus::moveEvent")
    /* stub */
}

void uGUILoginBonus::evEnd() {
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUILoginBonus::updateExit);
}

__attribute__((weak)) void uGUILoginBonus::evAdjustCursor() {
    DDON_STUB("uGUILoginBonus::evAdjustCursor")
    /* stub */
}

u32 uGUILoginBonus::evCtrlEnd(cControl::Message* msg) {
    setInputEvent(72u);
    return 0;
}

u32 uGUILoginBonus::evCtrlDecide(cControl::Message* msg) {
    setInputEvent(66u);
    return 0;
}

u32 uGUILoginBonus::evCtrlAdjTab(cControl::Message* msg) {
    setInputEvent(71u);
    return 0;
}

u32 uGUILoginBonus::evCtrlAdjCursor(cControl::Message* msg) {
    if (msg != nullptr) {
        cMatrix* t0 = mpMatCtrl;
        if (t0 != nullptr) {
            cControl* t1 = msg->pSender;
            if (t0 == t1) {
                nGUIExt::MSG_REASON t2 = msg->reason;
                s32 t3 = t0->getCurrentRow();
                if ((t3 == 0) && (t2 == nGUIExt::TRG_DOWN)) {
                    s32 t5 = t0->getOldPos();
                    t0->setCurrentPos(t5, false);
                    if (mBtn.uGUIBase::cReferenceUIButton::isFocus()) {
                        nGUIExt::MSG_REASON t8 = msg->reason;
                        if (t8 == nGUIExt::BTN_START) {
                            mIsPushUpBtn = true;
                        }
                    }
                    setInputEvent(70u);
                    return 0;
                }
                s32 t4 = t0->getRow();
                if (t3 == (t4 - 1)) {
                    if (t2 == nGUIExt::BTN_START) {
                        s32 t5 = t0->getOldPos();
                        t0->setCurrentPos(t5, false);
                        if (mBtn.uGUIBase::cReferenceUIButton::isFocus()) {
                            nGUIExt::MSG_REASON t8 = msg->reason;
                            if (t8 == nGUIExt::BTN_START) {
                                mIsPushUpBtn = true;
                            }
                        }
                        setInputEvent(70u);
                        return 0;
                    }
                }
                if (mBtn.uGUIBase::cReferenceUIButton::isFocus()) {
                    nGUIExt::MSG_REASON t8 = msg->reason;
                    if (t8 == nGUIExt::BTN_START) {
                        mIsPushUpBtn = true;
                    }
                }
                setInputEvent(70u);
                return 0;
            } else {
                if (mBtn.uGUIBase::cReferenceUIButton::isFocus()) {
                    nGUIExt::MSG_REASON t8 = msg->reason;
                    if (t8 == nGUIExt::BTN_START) {
                        mIsPushUpBtn = true;
                    }
                }
                setInputEvent(70u);
                return 0;
            }
        } else {
            if (mBtn.uGUIBase::cReferenceUIButton::isFocus()) {
                nGUIExt::MSG_REASON t8 = msg->reason;
                if (t8 == nGUIExt::BTN_START) {
                    mIsPushUpBtn = true;
                }
            }
            setInputEvent(70u);
            return 0;
        }
    } else {
        setInputEvent(70u);
        return 0;
    }
}

u32 uGUILoginBonus::evCtrlLClick(cControl::Message* msg) {
    s32 t0 = msg->click_vol;
    if (t0 != -1) {
        mCtrlStat = 0;
        cMatrix* t1 = mpMatCtrl;
        if (t1 != nullptr) {
            t1->setCurrentPos(t0, false);
            mIsMatrixClick = true;
            cMatrix* t3 = mpMatCtrl;
            if (t3 != nullptr) {
                cControl* t4 = msg->pSender;
                if (t3 == t4) {
                    nGUIExt::MSG_REASON t5 = msg->reason;
                    s32 t6 = t3->getCurrentRow();
                    if ((t6 == 0) && (t5 == nGUIExt::TRG_DOWN)) {
                        s32 t8 = t3->getOldPos();
                        t3->setCurrentPos(t8, false);
                        if (mBtn.uGUIBase::cReferenceUIButton::isFocus()) {
                            nGUIExt::MSG_REASON t11 = msg->reason;
                            if (t11 == nGUIExt::BTN_START) {
                                mIsPushUpBtn = true;
                            }
                        }
                        setInputEvent(70u);
                        return 0;
                    }
                    s32 t7 = t3->getRow();
                    if (t6 == (t7 - 1)) {
                        if (t5 == nGUIExt::BTN_START) {
                            s32 t8 = t3->getOldPos();
                            t3->setCurrentPos(t8, false);
                            if (mBtn.uGUIBase::cReferenceUIButton::isFocus()) {
                                nGUIExt::MSG_REASON t11 = msg->reason;
                                if (t11 == nGUIExt::BTN_START) {
                                    mIsPushUpBtn = true;
                                }
                            }
                            setInputEvent(70u);
                            return 0;
                        }
                    }
                    if (mBtn.uGUIBase::cReferenceUIButton::isFocus()) {
                        nGUIExt::MSG_REASON t11 = msg->reason;
                        if (t11 == nGUIExt::BTN_START) {
                            mIsPushUpBtn = true;
                        }
                    }
                    setInputEvent(70u);
                    return 0;
                } else {
                    if (mBtn.uGUIBase::cReferenceUIButton::isFocus()) {
                        nGUIExt::MSG_REASON t11 = msg->reason;
                        if (t11 == nGUIExt::BTN_START) {
                            mIsPushUpBtn = true;
                        }
                    }
                    setInputEvent(70u);
                    return 0;
                }
            } else {
                if (mBtn.uGUIBase::cReferenceUIButton::isFocus()) {
                    nGUIExt::MSG_REASON t11 = msg->reason;
                    if (t11 == nGUIExt::BTN_START) {
                        mIsPushUpBtn = true;
                    }
                }
                setInputEvent(70u);
                return 0;
            }
        } else {
            mIsMatrixClick = true;
            if (msg != nullptr) {
                if (mBtn.uGUIBase::cReferenceUIButton::isFocus()) {
                    nGUIExt::MSG_REASON t11 = msg->reason;
                    if (t11 == nGUIExt::BTN_START) {
                        mIsPushUpBtn = true;
                    }
                }
            }
            setInputEvent(70u);
            return 0;
        }
    } else {
        mCtrlStat = 1;
        setInputEvent(66u);
        return 0;
    }
}

__attribute__((weak)) MtObject* uGUILoginBonus::MyDTI::newInstance() const {
    DDON_STUB("uGUILoginBonus::MyDTI::newInstance")
    return nullptr;
}

