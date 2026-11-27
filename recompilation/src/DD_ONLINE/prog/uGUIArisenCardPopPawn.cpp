// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIArisenCardPopPawn.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "../../XFramework/cResource.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIArisenCardPopPawn::getDTI() const {
    return uGUIArisenCardPopPawn::DTI;
}

void* uGUIArisenCardPopPawn::operator new(size_t sz, u32 align) {
    return uGUIArisenCardPopPawn::getAllocator()->memAlloc(sz, align, uGUIArisenCardPopPawn::DTI.getID());
}

uGUIArisenCardPopPawn::~uGUIArisenCardPopPawn() {
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpGMDRes == nullptr) {
        return;
    }
    mpGMDRes->release();
    mpGMDRes = nullptr;
}

void uGUIArisenCardPopPawn::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
}

MtUI* uGUIArisenCardPopPawn::createUI(MtProperty& prop) {
    return this->uGUI::createUI(prop);
}

bool uGUIArisenCardPopPawn::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_POP_PAWN_PROFILE_GUI"), 129u, 1417501097l))) == nullptr)) {
        return false;
    }
    if ((mpGMDRes == nullptr) && ((mpGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ARISENCARD_POP_PAWN_GMD"), 129u, 0l))) == nullptr)) {
        return false;
    }
    return true;
}

__attribute__((weak)) void uGUIArisenCardPopPawn::updatePtr() {
}

void uGUIArisenCardPopPawn::setup() {
    this->uGUIBase::setup();
    if (!mIsEndLoadResource) {
        return;
    }
    setPriority(static_cast<sGUIExt*>(sGUI::getInstance())->issuePriority(11u), true);
    setPlay(true);
    initCommon();
    updateLineDisp();
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIArisenCardPopPawn::updateWait);
}

void uGUIArisenCardPopPawn::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpGMDRes == nullptr) {
        return;
    }
    mpGMDRes->release();
    mpGMDRes = nullptr;
}

void uGUIArisenCardPopPawn::moveInput() {
    if (mIsModeKeyboard) {
        mTextBox.execute();
        if (mTextBox.isEndKeyboard()) {
            mIsModeKeyboard = false;
            mTextBox.closeKeyboard(true);
            if (mpCtrl != nullptr) {
                mpCtrl->mCtrlF = mpCtrl->mCtrlF & 0xFFFFFFF7u;
            }
        }
    } else {
        if (mpCtrl != nullptr) {
            mpCtrl->execute();
        }
    }
}

void uGUIArisenCardPopPawn::moveEvent() {
    switch (getInputEvent() - 66u) {
        case 0:
        {
            end();
            break;
        }
        case 1:
        {
            updateLineDisp();
            break;
        }
        case 2:
        {
            mButtonOK.uGUIBase::cReferenceUIButton::setFocus(mSelectButton == 0);
            mButtonNG.uGUIBase::cReferenceUIButton::setFocus(mSelectButton == 1);
            break;
        }
        case 3:
        {
            mTextBox.wakeupKeyboard();
            mIsModeKeyboard = true;
            if (mpCtrl != nullptr) {
                mpCtrl->mCtrlF = mpCtrl->mCtrlF | 8u;
            }
            break;
        }
        case 4:
        {
            mTextBox.closeKeyboard(true);
            end();
            break;
        }
        default:
        {
            break;
        }
    }
}

void uGUIArisenCardPopPawn::updateWait() {
    (&mButtonOK)->update();
    (&mButtonNG)->update();
    mTextBox.uGUIBase::cReferenceUITextBox::update();
}

u32 uGUIArisenCardPopPawn::evCtrlCancel(cControl::Message* pMsg) {
    mSelectButton = 1;
    setInputEvent(66u);
    return 1;
}

u32 uGUIArisenCardPopPawn::evCtrlDecide(cControl::Message* pMsg) {
    if (mpCtrl != nullptr) {
        if (mpCtrl->getCurrentPos() == 1) {
            setInputEvent(66u);
            return 1;
        } else {
            if (mpCtrl->getCurrentPos() == 0) {
                setInputEvent(69u);
                return 1;
            } else {
                return 0;
            }
        }
    } else {
        return 0;
    }
}

u32 uGUIArisenCardPopPawn::evCtrlCursorUD(cControl::Message* pMsg) {
    setInputEvent(67u);
    return 1;
}

u32 uGUIArisenCardPopPawn::evCtrlCursorLR(cControl::Message* pMsg) {
    if (mpCtrl != nullptr) {
        if (mpCtrl->mCurrentPos == 1) {
            mSelectButton = static_cast<u32>(mSelectButton == 0);
            setInputEvent(68u);
            return 1;
        }
    }
    return 0;
}

u32 uGUIArisenCardPopPawn::evCtrlMouseClick(cControl::Message* pMsg) {
    if (pMsg != nullptr) {
        if (pMsg->mouse_hit_id == 1) {
            mSelectButton = static_cast<u32>(pMsg->click_vol != 0);
            setInputEvent(70u);
            return 1;
        }
        if (pMsg->mouse_hit_id == 0) {
            setInputEvent(69u);
        }
    }
    return 0;
}

__attribute__((weak)) void uGUIArisenCardPopPawn::initCommon() {
    DDON_STUB("uGUIArisenCardPopPawn::initCommon")
    /* stub */
}

__attribute__((weak)) void uGUIArisenCardPopPawn::updateLineDisp() {
    if (mpCtrl == nullptr) {
        return;
    }
    if (mpCtrl->getCurrentPos() == 1) {
        mTextBox.uGUIBase::cReferenceUITextBox::setFocus(false);
        mButtonOK.uGUIBase::cReferenceUIButton::setFocus(mSelectButton == 0);
        mButtonNG.uGUIBase::cReferenceUIButton::setFocus(mSelectButton == 1);
    } else {
        if (mpCtrl->getCurrentPos() == 0) {
            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(true);
            mButtonOK.uGUIBase::cReferenceUIButton::setFocus(false);
            mButtonNG.uGUIBase::cReferenceUIButton::setFocus(false);
        }
    }
}

inline uGUIArisenCardPopPawn::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIArisenCardPopPawn::MyDTI uGUIArisenCardPopPawn::DTI("uGUIArisenCardPopPawn", &::uGUIBase::DTI, 3456ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIArisenCardPopPawn::MyDTI::newInstance() const {
    DDON_STUB("uGUIArisenCardPopPawn::MyDTI::newInstance")
    return nullptr;
}

