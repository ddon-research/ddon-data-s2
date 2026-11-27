// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "uGUIEntryBoardPopRecruit.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "cGUIUtility.h"
#include "cMenuBase.h"
#include "../../XFramework/cResource.h"
#include "nDDOUtility.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sMenu.h"
#include "../../XFramework/uCoord.h"
#include "uGUIBase.h"
#include "uGUIsMenuBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIEntryBoardPopRecruit::getDTI() const {
    return uGUIEntryBoardPopRecruit::DTI;
}

uGUIEntryBoardPopRecruit::uGUIEntryBoardPopRecruit() : uGUIsMenuBase(4u, false) {
    memset(static_cast<void*>(&mDataInst), 0, 180ul);
    mBtnSize = 0.0f;
    mpClickCtrk = nullptr;
    mpLevelCtrl = nullptr;
    mpHCtrl = nullptr;
    mpVCtrl = nullptr;
    mpButtonCtrl = nullptr;
    mbCtrlValid = true;
    mCheckId = 0;
    mDecideId = 0;
    mCancelId = 0;
    mEndType = 0;
    setArcTag(rArchiveListArray::convTagId("uGUIEntryBoardPopRecruit"), 0u, false);
}

uGUIEntryBoardPopRecruit::~uGUIEntryBoardPopRecruit() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

bool uGUIEntryBoardPopRecruit::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ENTRYBOARD_POP_RECRUIT_GUI"), 129u, 1465176837l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(rArchiveListArray::convTagId("uGUIEntryBoard"), "RES_ID_ENTRY_BOARD_GMD", 0u);
}

__attribute__((weak)) void uGUIEntryBoardPopRecruit::setup() {
    DDON_STUB("uGUIEntryBoardPopRecruit::setup")
    /* stub */
}

void uGUIEntryBoardPopRecruit::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIEntryBoardPopRecruit::clearCtrl() {
    if (mpVCtrl != nullptr) {
        mpVCtrl->setCurrentPos(4, false);
    }
    if (mpHCtrl != nullptr) {
        mpHCtrl->setCurrentPos(1, false);
    }
    if (mRefrenceUIArray.mLength != 0) {
        for (unsigned int i0_3 = 0;;) {
            static_cast<cReferenceUIBase*>(mRefrenceUIArray.getBuffer()[static_cast<int>(i0_3)])->setFocus(false);
            if ((i0_3 + 1u) < mRefrenceUIArray.mLength) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
}

void uGUIEntryBoardPopRecruit::updateInit() {
    updateWait();
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIEntryBoardPopRecruit::updateWait);
}

__attribute__((weak)) void uGUIEntryBoardPopRecruit::updateWait() {
    DDON_STUB("uGUIEntryBoardPopRecruit::updateWait")
    /* stub */
}

s32 uGUIEntryBoardPopRecruit::getSMenuCursorX() {
    return uGUIBase::DISABLE_IDX;
}

__attribute__((weak)) s32 uGUIEntryBoardPopRecruit::getSMenuCursorY() {
    DDON_STUB("uGUIEntryBoardPopRecruit::getSMenuCursorY")
    return {};
}

__attribute__((weak)) void uGUIEntryBoardPopRecruit::calcItemNum() {
    DDON_STUB("uGUIEntryBoardPopRecruit::calcItemNum")
    /* stub */
}

__attribute__((weak)) void uGUIEntryBoardPopRecruit::moveInput() {
    DDON_STUB("uGUIEntryBoardPopRecruit::moveInput")
    /* stub */
}

__attribute__((weak)) void uGUIEntryBoardPopRecruit::moveEvent() {
}

u32 uGUIEntryBoardPopRecruit::evCtrlDecide(cControl::Message* msg) {
    setInputEvent(4u);
    return 0;
}

u32 uGUIEntryBoardPopRecruit::evCtrlCancel(cControl::Message* msg) {
    setInputEvent(5u);
    return 0;
}

__attribute__((weak)) u32 uGUIEntryBoardPopRecruit::evCtrlClick(cControl::Message* msg) {
    DDON_STUB("uGUIEntryBoardPopRecruit::evCtrlClick")
    return {};
}

u32 uGUIEntryBoardPopRecruit::evCtrlDown(cControl::Message* msg) {
    if (mpVCtrl != nullptr) {
        if (mpHCtrl != nullptr) {
            if (mpVCtrl->getCurrentPos() == 3) {
                mpHCtrl->setCurrentPos(0, false);
            } else {
                if (mpVCtrl->getCurrentPos() == 2) {
                    if (static_cast<unsigned int>(mpHCtrl->getCurrentPos() + 6) > 9) {
                        mpVCtrl->setCurrentPos(3, false);
                        if (mpHCtrl != nullptr) {
                            mpHCtrl->setCurrentPos(0, false);
                        }
                    }
                }
            }
        }
    }
    return 0;
}

inline uGUIEntryBoardPopRecruit::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIEntryBoardPopRecruit::MyDTI uGUIEntryBoardPopRecruit::DTI("uGUIEntryBoardPopRecruit", &::uGUIsMenuBase::DTI, 4720ul, 0u, 0u);

MtObject* uGUIEntryBoardPopRecruit::MyDTI::newInstance() const {
    return new (16u) uGUIEntryBoardPopRecruit;
}

