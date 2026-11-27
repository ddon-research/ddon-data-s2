// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUINpcWindow.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive2D.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "nQuest.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sQuestManagerExt.h"
#include "uGUIBase.h"
#include "uGUISystemMsg.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUINpcWindow::getDTI() const {
    return uGUINpcWindow::DTI;
}

void* uGUINpcWindow::operator new(size_t sz, u32 align) {
    return uGUINpcWindow::getAllocator()->memAlloc(sz, align, uGUINpcWindow::DTI.getID());
}

uGUINpcWindow::~uGUINpcWindow() {
    if (mpGUIMsg != nullptr) {
        mpGUIMsg->release();
        mpGUIMsg = nullptr;
    }
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

bool uGUINpcWindow::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_NPCWINDOW04_GUI"), 129u, 1432186983l))) == nullptr)) {
        return false;
    }
    if ((mpGUIMsg == nullptr) && ((mpGUIMsg = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_NPCWINDOW_RES_GMD"), 129u, 0l))) == nullptr)) {
        return false;
    }
    return true;
}

__attribute__((weak)) void uGUINpcWindow::setup() {
    DDON_STUB("uGUINpcWindow::setup")
    /* stub */
}

void uGUINpcWindow::kill() {
    this->uGUISystemMsg::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUINpcWindow::draw(cDraw* pDraw) {
    if (!mIsDraw) {
        return;
    }
    this->uGUIBase::draw(pDraw);
}

void uGUINpcWindow::restart() {
    mRequestRestart = true;
    mIsMessageWait = true;
    mMode = 0;
    if (mArrayPageInfo.mLength != 0) {
        u32 v0_0 = mArrayPageInfo.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mArrayPageInfo.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mArrayPageInfo.mpArray[i0_3];
                v1_0 = mArrayPageInfo.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mArrayPageInfo.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mArrayPageInfo.mpArray));
    }
    mArrayPageInfo.mpArray = nullptr;
    mArrayPageInfo.mBufsiz = 0;
    mArrayPageInfo.mLength = 0;
    mCurrentPage = 0;
    if (mpCtrl != nullptr) {
        mpCtrl->setPresetSE(4u, 8u);
    }
    mScrollList.clearInfo();
    setWindowActive(true);
}

void uGUINpcWindow::finish() {
    if (!mIsFinish) {
        mIsFinish = true;
        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUINpcWindow::updateOutStart);
        setWindowActive(false);
    }
}

void uGUINpcWindow::move() {
    mIsMessageWaitTemp = false;
    if (mRequestRestart) {
        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 7u);
        mRequestRestart = false;
        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUINpcWindow::updateInit);
    }
    this->uGUISystemMsg::move();
    if (mReqUpdateDisp) {
        mReqUpdateDisp = false;
        updateDisp(false);
    }
    mIsMessageWait = mIsMessageWaitTemp;
}

__attribute__((weak)) void uGUINpcWindow::setNpcName(MT_CTSTR name) {
    DDON_STUB("uGUINpcWindow::setNpcName")
    /* stub */
}

MtVector2 uGUINpcWindow::getChoiceWindowPos() {
    MtVector2 vRet;
    vRet.x = 0.0f;
    vRet.y = 0.0f;
    if (mpInstNullChoice != nullptr) {
        const MtDTI& t0 = mpInstNullChoice->getDTI();
        MT_CTSTR v0_1 = cGUIInstNull::DTI.mName;
        const MtDTI* v0_0 = &t0;
        const MtDTI* v2_0;
        for (;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                f32 v2_9 = static_cast<cGUIInstNull*>(mpInstNullChoice)->mPosition.x;
                f32 v2_10 = static_cast<cGUIInstNull*>(mpInstNullChoice)->mPosition.y;
                vRet.x = v2_9;
                vRet.y = v2_10;
                if (mpInstNull != nullptr) {
                    const MtDTI& t1 = mpInstNull->getDTI();
                    MT_CTSTR v2_1 = cGUIInstNull::DTI.mName;
                    v2_0 = &t1;
                    for (;;) {
                        if (v2_1 != v2_0->mName) {
                            if (v2_0->mpParent != nullptr) {
                                v2_0 = v2_0->mpParent;
                            } else {
                                break;
                            }
                        } else {
                            f32 t2 = static_cast<cGUIInstNull*>(mpInstNull)->mPosition.y;
                            vRet.x = mAlignmentPosition[((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mpInstNull) + 144)) >> 8) & 15u].x + (static_cast<cGUIInstNull*>(mpInstNull)->mPosition.x + v2_9);
                            vRet.y = mAlignmentPosition[((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mpInstNull) + 144)) >> 8) & 15u].y + (t2 + v2_10);
                            goto loop_ca9618_end;
                        }
                    }
                }
                break;
            }
        }
        loop_ca9618_end:;
    }
    return vRet;
}

bool uGUINpcWindow::isMessageWait() {
    return mIsMessageWait;
}

void uGUINpcWindow::moveInput() {
    this->uGUISystemMsg::moveInput();
}

void uGUINpcWindow::moveEvent() {
    if (mScrollList.moveEvent()) {
        updateQuestGuide();
        this->uGUISystemMsg::moveEvent();
    } else {
        if (mInputEventId == 68) {
            mScrollList.setListPos(false);
            updateQuestGuide();
        } else {
            this->uGUISystemMsg::moveEvent();
        }
    }
}

__attribute__((weak)) void uGUINpcWindow::updateWait() {
    DDON_STUB("uGUINpcWindow::updateWait")
    /* stub */
}

__attribute__((weak)) void uGUINpcWindow::updateDisp(bool bInit) {
    DDON_STUB("uGUINpcWindow::updateDisp")
    /* stub */
}

void uGUINpcWindow::updateInit() {
    mIsMessageWaitTemp = true;
    mIsFinish = false;
    mIsDraw = true;
    mCurrentPage = 0;
    if (mArrayPageInfo.mLength != 0) {
        u32 v0_0 = mArrayPageInfo.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mArrayPageInfo.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                static_cast<uGUISystemMsg::cPageInfo*>(mArrayPageInfo.mpArray[i0_3])->initChoicePos();
                v1_0 = mArrayPageInfo.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mToolTip.mpInstance != nullptr) {
        mToolTip.mpInstance->setVisible(false);
    }
    if (mpCtrl != nullptr) {
        mpCtrl->setFocus(true);
    }
    mScrollList.setFocus(true);
    if (mpInstNull != nullptr) {
        mpInstNull->setVisible(true);
    }
    updateDisp(true);
    setFlowAndInit(4u, false);
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUINpcWindow::updateIn);
}

void uGUINpcWindow::updateIn() {
    mIsMessageWaitTemp = true;
    if (!mIsFlowEnd) {
        return;
    }
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUINpcWindow::updateWait);
}

void uGUINpcWindow::updateOutStart() {
    static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 10u);
    mIsFinish = true;
    setFlowAndInit(5u, false);
    if (mpCtrl != nullptr) {
        mpCtrl->setFocus(false);
    }
    mScrollList.setFocus(false);
    setObjectMessage(mpObjName, static_cast<MT_CTSTR>(nullptr), 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(mpObjText), static_cast<MT_CTSTR>(nullptr), 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(mpObjMsgChoiceInfo[0]), static_cast<MT_CTSTR>(nullptr), 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(mpObjMsgChoiceInfo[1]), static_cast<MT_CTSTR>(nullptr), 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(mpObjMsgChoiceInfo[2]), static_cast<MT_CTSTR>(nullptr), 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(mpObjMsgChoiceInfo[3]), static_cast<MT_CTSTR>(nullptr), 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(mpObjMsgChoiceInfo[4]), static_cast<MT_CTSTR>(nullptr), 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(mpObjMsgChoiceInfo[5]), static_cast<MT_CTSTR>(nullptr), 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(mpObjMsgChoiceInfo[6]), static_cast<MT_CTSTR>(nullptr), 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(mpObjMsgChoiceInfo[7]), static_cast<MT_CTSTR>(nullptr), 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(mpObjMsgChoiceInfo[8]), static_cast<MT_CTSTR>(nullptr), 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(mpObjMsgChoiceInfo[9]), static_cast<MT_CTSTR>(nullptr), 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(mpObjMsgChoiceInfo[10]), static_cast<MT_CTSTR>(nullptr), 0u, false);
    setObjectMessage(static_cast<cGUIObject*>(mpObjMsgChoiceInfo[11]), static_cast<MT_CTSTR>(nullptr), 0u, false);
    mToolTip.setMessage("");
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUINpcWindow::updateOut);
}

void uGUINpcWindow::updateOut() {
    mIsFinish = true;
    mIsDraw = false;
}

__attribute__((weak)) void uGUINpcWindow::updateEnd() {
}

__attribute__((weak)) void uGUINpcWindow::initScrollList() {
    DDON_STUB("uGUINpcWindow::initScrollList")
    /* stub */
}

__attribute__((weak)) void uGUINpcWindow::updateScrollList() {
    DDON_STUB("uGUINpcWindow::updateScrollList")
    /* stub */
}

__attribute__((weak)) void uGUINpcWindow::updateQuestGuide() {
    DDON_STUB("uGUINpcWindow::updateQuestGuide")
    /* stub */
}

__attribute__((weak)) void uGUINpcWindow::updateScrollListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index) {
    DDON_STUB("uGUINpcWindow::updateScrollListDisp")
    /* stub */
}

__attribute__((weak)) void uGUINpcWindow::updateScrollListHide(uGUIBase::cScrollListItemBase* pDispItem) {
}

inline uGUINpcWindow::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUINpcWindow::MyDTI uGUINpcWindow::DTI("uGUINpcWindow", &::uGUISystemMsg::DTI, 13600ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUINpcWindow::MyDTI::newInstance() const {
    DDON_STUB("uGUINpcWindow::MyDTI::newInstance")
    return nullptr;
}

