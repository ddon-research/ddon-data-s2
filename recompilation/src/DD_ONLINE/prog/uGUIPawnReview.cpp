// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIPawnReview.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "cGUIControlMgr.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "cMenuBase.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "nDDOUtility.h"
#include "../../XFramework/nGUI.h"
#include "nNet.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/rRenderTargetTexture.h"
#include "../../XFramework/rTexture.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sMenu.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "../../XFramework/sUnit.h"
#include "uGUIBase.h"
#include "uUIMockUp.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

static const u32 FeedbackItemNullInstanceIds[3] = {
    49,
    50,
    51,
};

static const u32 FeedbackItemStarsInstanceIds[3] = {
    52,
    53,
    54,
};

static const u32 FeedbackItemMessagesInstanceIds[3] = {
    10,
    11,
    12,
};

static const u32 REVIEW_TITLE_MSG_IDS[3] = {
    2,
    3,
    4,
};

static const u32 COUNT_TITLE_MSG_IDS[3] = {
    0,
    5,
    6,
};

static const char COUNT_FORMAT[6] = {
    37,
    117,
    47,
    37,
    117,
    0,
};

const MtDTI& uGUIPawnReview::getDTI() const {
    return uGUIPawnReview::DTI;
}

uGUIPawnReview::~uGUIPawnReview() {
    if (mpMockUp != nullptr) {
        mpMockUp->kill();
        mpMockUp = nullptr;
    }
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

bool uGUIPawnReview::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_PAWNREVIEW_GUI"), 129u, 1436162091l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_PAWNREVIEW_RES_GMD", 0u);
}

__attribute__((weak)) void uGUIPawnReview::setup() {
    DDON_STUB("uGUIPawnReview::setup")
    /* stub */
}

void uGUIPawnReview::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIPawnReview::move() {
    this->uGUIBase::move();
}

void uGUIPawnReview::updatePtr() {
    if (mpMockUp == nullptr) {
        return;
    }
    if (mpMockUp->isEnable()) {
        return;
    }
    mpMockUp = nullptr;
}

__attribute__((weak)) s32 uGUIPawnReview::getSMenuCursorY() {
    DDON_STUB("uGUIPawnReview::getSMenuCursorY")
    return {};
}

bool uGUIPawnReview::show() {
    if (mIsSetup) {
        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIPawnReview::updateInit);
        return true;
    } else {
        return false;
    }
}

__attribute__((weak)) void uGUIPawnReview::updateFeedback(nNet::FEEDBACK_TYPE feedbackType, const nNet::stFeedbackData* feedbackData) {
    DDON_STUB("uGUIPawnReview::updateFeedback")
    /* stub */
}

__attribute__((weak)) void uGUIPawnReview::updateInit() {
    DDON_STUB("uGUIPawnReview::updateInit")
    /* stub */
}

void uGUIPawnReview::updateWait() {
    if (mData.mpINST_msg_loadicon_root != nullptr) {
        if ((mData.mpINST_msg_loadicon_root->mAttr & 1u) != 0) {
            if (mpMockUp != nullptr) {
                if (mpMockUp->isComplete()) {
                    mpMockUp->setDisp(true);
                    if (mData.mpINST_msg_loadicon_root != nullptr) {
                        mData.mpINST_msg_loadicon_root->setVisible(false);
                    }
                }
            }
        }
    }
    updateFocus();
    if (mRefrenceUIArray.mLength == 0) {
        return;
    }
    u32 i = 0;
    do {
        static_cast<cReferenceUIBase*>(mRefrenceUIArray.getBuffer()[static_cast<int>(i)])->update();
        i += 1u;
    } while (i < mRefrenceUIArray.mLength);
}

void uGUIPawnReview::moveInput() {
    if (!isWindowActive()) {
        return;
    }
    if (!sMenu::getInstance()->mPawnManager.isMove()) {
        return;
    }
    if (!sMenu::getInstance()->mPawnReturn.isUpdateCursor()) {
        return;
    }
    mControlMgr.moveInput();
    mCloseButton.execute();
}

__attribute__((weak)) void uGUIPawnReview::moveEvent() {
}

__attribute__((weak)) void uGUIPawnReview::setupControls() {
    DDON_STUB("uGUIPawnReview::setupControls")
    /* stub */
}

__attribute__((weak)) void uGUIPawnReview::updateFocus() {
    DDON_STUB("uGUIPawnReview::updateFocus")
    /* stub */
}

u32 uGUIPawnReview::evCtrlMoveFocus(cControl::Message* msg) {
    setInputEvent(66u);
    return 0;
}

u32 uGUIPawnReview::evCtrlDecide(cControl::Message* msg) {
    if (msg != nullptr) {
        if (msg->reason == nGUIExt::MOUSE_LCLICK) {
            if (msg->click_vol > -1) {
                mControlMgr.setCurrentPos(0u, msg->click_vol);
            }
        }
    }
    setInputEvent(4u);
    return 0;
}

u32 uGUIPawnReview::evCtrlCancel(cControl::Message* msg) {
    setInputEvent(5u);
    return 0;
}

void uGUIPawnReview::initMockUp() {
    if (!sMenu::getInstance()->mPawnManager.isMove()) {
        return;
    }
    if ((mpMockUp = new (16u) uUIMockUp) == nullptr) {
        return;
    }
    sUnit* t1 = sUnit::getInstance();
    t1->addBottom(static_cast<MOVE_LINE>(t1->getNextMoveLineId(mMoveLine)), static_cast<cUnit*>(mpMockUp), getUnitGroup());
    if (mpGUIRes != nullptr) {
        nGUI::TEXTURE* const tex = mpGUIRes->getTextureFromId(4u);
        if (tex != nullptr) {
            mpMockUp->setRenderTargetTexture(static_cast<rRenderTargetTexture*>(tex->pTexture));
        }
        mpMockUp->mCamDistDef = 300.0f;
        mpMockUp->mCamYOfsDef = 105.0f;
        mpMockUp->mIsHideEnable = true;
    } else {
        mpMockUp->mCamDistDef = 300.0f;
        mpMockUp->mCamYOfsDef = 105.0f;
        mpMockUp->mIsHideEnable = true;
    }
}

__attribute__((weak)) void uGUIPawnReview::applyPawnParam() {
    DDON_STUB("uGUIPawnReview::applyPawnParam")
    /* stub */
}

__attribute__((weak)) void uGUIPawnReview::feedbackItemSetup() {
    DDON_STUB("uGUIPawnReview::feedbackItemSetup")
    /* stub */
}

inline uGUIPawnReview::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPawnReview::MyDTI uGUIPawnReview::DTI("uGUIPawnReview", &::uGUIBase::DTI, 5104ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIPawnReview::MyDTI::newInstance() const {
    DDON_STUB("uGUIPawnReview::MyDTI::newInstance")
    return nullptr;
}

