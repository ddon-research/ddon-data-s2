// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIDialogTextBox.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "../../XFramework/cResource.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIDialogTextBox::getDTI() const {
    return uGUIDialogTextBox::DTI;
}

void* uGUIDialogTextBox::operator new(size_t sz, u32 align) {
    return uGUIDialogTextBox::getAllocator()->memAlloc(sz, align, uGUIDialogTextBox::DTI.getID());
}

uGUIDialogTextBox::~uGUIDialogTextBox() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

bool uGUIDialogTextBox::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_POP_INPUT_FORM_GUI"), 129u, 1419160100l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_DIALOGTEXTBOX_RES_GMD", 0u);
}

__attribute__((weak)) void uGUIDialogTextBox::setup() {
    DDON_STUB("uGUIDialogTextBox::setup")
    /* stub */
}

void uGUIDialogTextBox::kill() {
    this->uGUIBase::kill();
}

void uGUIDialogTextBox::moveInput() {
    mTextBox.execute();
    if (mTextBox.isWakeupKeyboard()) {
        return;
    }
    if (mpVL == nullptr) {
        return;
    }
    mpVL->execute();
    if (mpVL == nullptr) {
        return;
    }
    if (mpVL->mCurrentPos != 1) {
        return;
    }
    if (mpHL == nullptr) {
        return;
    }
    mpHL->execute();
}

void uGUIDialogTextBox::moveEvent() {
    if (getInputEvent() == 68) {
        evDecide();
        return;
    }
    if (getInputEvent() == 67) {
        mIsCancel = true;
        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIDialogTextBox::updateExit);
        return;
    }
    if (getInputEvent() != 66) {
        return;
    }
    if (mRefrenceUIArray.mLength == 0) {
        if (mpVL != nullptr) {
            if (mpVL->mCurrentPos != 0) {
                if (mpHL != nullptr) {
                    if (mpHL->mCurrentPos != 0) {
                        mBtnN.uGUIBase::cReferenceUIButton::setFocus(true);
                    } else {
                        mBtnY.uGUIBase::cReferenceUIButton::setFocus(true);
                    }
                } else {
                    mBtnY.uGUIBase::cReferenceUIButton::setFocus(true);
                }
            } else {
                mTextBox.uGUIBase::cReferenceUITextBox::setFocus(true);
            }
        } else {
            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(true);
        }
        return;
    }
    unsigned int i3 = 0;
    do {
        static_cast<cReferenceUIBase*>(mRefrenceUIArray.getBuffer()[static_cast<int>(i3)])->setFocus(false);
        i3 += 1u;
    } while (i3 < mRefrenceUIArray.mLength);
    if (mpVL != nullptr) {
        if (mpVL->mCurrentPos != 0) {
            if (mpHL != nullptr) {
                if (mpHL->mCurrentPos != 0) {
                    mBtnN.uGUIBase::cReferenceUIButton::setFocus(true);
                } else {
                    mBtnY.uGUIBase::cReferenceUIButton::setFocus(true);
                }
            } else {
                mBtnY.uGUIBase::cReferenceUIButton::setFocus(true);
            }
        } else {
            mTextBox.uGUIBase::cReferenceUITextBox::setFocus(true);
        }
    } else {
        mTextBox.uGUIBase::cReferenceUITextBox::setFocus(true);
    }
}

void uGUIDialogTextBox::updateInit() {
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIDialogTextBox::updateWait);
}

__attribute__((weak)) void uGUIDialogTextBox::updateWait() {
    DDON_STUB("uGUIDialogTextBox::updateWait")
    /* stub */
}

void uGUIDialogTextBox::updateExit() {
    end();
}

u32 uGUIDialogTextBox::evCtrlMove(cControl::Message* msg) {
    setInputEvent(66u);
    return 0;
}

u32 uGUIDialogTextBox::evCtrlCancel(cControl::Message* msg) {
    setInputEvent(67u);
    return 0;
}

u32 uGUIDialogTextBox::evCtrlDecide(cControl::Message* msg) {
    if (msg != nullptr) {
        if (msg->reason == nGUIExt::MOUSE_LCLICK) {
            if (msg->click_vol > -1) {
                if (mpHL != nullptr) {
                    mpHL->setCurrentPos(msg->click_vol, false);
                }
            }
        }
        if (msg->current == 1) {
            msg->changeSE = 0;
        }
        setInputEvent(68u);
    }
    return 0;
}

__attribute__((weak)) void uGUIDialogTextBox::evDecide() {
    DDON_STUB("uGUIDialogTextBox::evDecide")
    /* stub */
}

inline uGUIDialogTextBox::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIDialogTextBox::MyDTI uGUIDialogTextBox::DTI("uGUIDialogTextBox", &::uGUIBase::DTI, 3600ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIDialogTextBox::MyDTI::newInstance() const {
    DDON_STUB("uGUIDialogTextBox::MyDTI::newInstance")
    return nullptr;
}

