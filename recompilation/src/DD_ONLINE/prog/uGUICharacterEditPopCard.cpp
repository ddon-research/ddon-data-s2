// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUICharacterEditPopCard.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtSynchronize.h"
#include "cControl.h"
#include "cGUIUtility.h"
#include "cMenuBase.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cSystem.h"
#include "nNet.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sMenu.h"
#include "uGUIBase.h"
#include "uGUIsMenuBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

static const u8 ShareRanges[5] = {
    1,
    2,
    3,
    4,
    5,
};

const MtDTI& uGUICharacterEditPopCard::getDTI() const {
    return uGUICharacterEditPopCard::DTI;
}

inline MtAllocator* uGUICharacterEditPopCard::getAllocator() {
    return MtMemoryAllocator::getAllocator(uGUICharacterEditPopCard::DTI);
}

void* uGUICharacterEditPopCard::operator new(size_t sz, u32 align) {
    return uGUICharacterEditPopCard::getAllocator()->memAlloc(sz, align, uGUICharacterEditPopCard::DTI.getID());
}

inline void uGUICharacterEditPopCard::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUICharacterEditPopCard::DTI)->memFree(p_addr);
}

uGUICharacterEditPopCard::uGUICharacterEditPopCard() : uGUIsMenuBase(0u, false) {
    mpGUIRes = nullptr;
    mpCtrlH = nullptr;
    mpCtrlV = nullptr;
    mProc = PR_DEFAULT;
    mUnitType = TYPE_PLAYER;
    mBaseF = mBaseF | 1088u;
    mEndType = 1;
    mBasePointerPrio = 9;
    mPointerPrioRange = 1;
    setArcTag(rArchiveListArray::convTagId("uGUICharacterEditPopCard"), 0u, false);
}

__attribute__((noinline)) uGUICharacterEditPopCard::~uGUICharacterEditPopCard() {
    DDON_STUB("uGUICharacterEditPopCard::~uGUICharacterEditPopCard")
    /* stub */
}

bool uGUICharacterEditPopCard::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_POP_EDIT_GUI"), 129u, 1418975633l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_CHARACTER_EDIT_JOB_GMD", 0u);
}

__attribute__((weak)) void uGUICharacterEditPopCard::setup() {
    DDON_STUB("uGUICharacterEditPopCard::setup")
    /* stub */
}

void uGUICharacterEditPopCard::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUICharacterEditPopCard::move() {
    this->uGUIsMenuBase::move();
    mRefPulldown.uGUIBase::cReferenceUIPullDown::update();
}

__attribute__((weak)) void uGUICharacterEditPopCard::updatePtr() {
}

__attribute__((weak)) nNet::PAWN_SHARE_RANGE uGUICharacterEditPopCard::getShareRange() const {
    DDON_STUB("uGUICharacterEditPopCard::getShareRange")
    return {};
}

void uGUICharacterEditPopCard::updateInit() {
    if (sMenu::getInstance()->mPawnManager.isMove()) {
        mEndType = 1;
    }
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUICharacterEditPopCard::updateWait);
}

__attribute__((weak)) void uGUICharacterEditPopCard::updateWait() {
    DDON_STUB("uGUICharacterEditPopCard::updateWait")
    /* stub */
}

void uGUICharacterEditPopCard::updateExit() {
    end();
}

void uGUICharacterEditPopCard::moveInput() {
    mRefPulldown.execute();
    if (mProc != PR_DEFAULT) {
        return;
    }
    if (mpCtrlV != nullptr) {
        mpCtrlV->execute();
    }
    if (mpCtrlH == nullptr) {
        return;
    }
    mpCtrlH->execute();
}

void uGUICharacterEditPopCard::moveEvent() {
    if (mRefPulldown.moveEvent()) {
        return;
    }
    if (static_cast<int>(getInputEvent()) <= 65) {
        if (getInputEvent() != 4) {
            if (getInputEvent() == 5) {
                mExitType = EXIT_TYPE_CANCEL;
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUICharacterEditPopCard::updateExit);
            }
        } else {
            if (mpCtrlV != nullptr) {
                if (mpCtrlV->getCurrentPos() != 1) {
                    if (mpCtrlV->getCurrentPos() == 0) {
                        mProc = PR_PULLDOWN;
                        if (!mRefPulldown.mIsForbid) {
                            if (mRefPulldown.mState == uGUIBase::cReferenceUIPullDown::STATE_NONE) {
                                mRefPulldown.mState = uGUIBase::cReferenceUIPullDown::STATE_OPEN_INIT;
                            }
                        }
                    }
                } else {
                    mExitType = EXIT_TYPE_OK;
                    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUICharacterEditPopCard::updateExit);
                }
            } else {
                mProc = PR_PULLDOWN;
                if (!mRefPulldown.mIsForbid) {
                    if (mRefPulldown.mState == uGUIBase::cReferenceUIPullDown::STATE_NONE) {
                        mRefPulldown.mState = uGUIBase::cReferenceUIPullDown::STATE_OPEN_INIT;
                    }
                }
            }
        }
    } else {
        switch (getInputEvent() - 66u) {
            case 0:
            {
                if (mpCtrlV != nullptr) {
                    if (mpCtrlV->getCurrentPos() != 1) {
                        if (mpCtrlV->getCurrentPos() == 0) {
                            mProc = PR_PULLDOWN;
                            if (!mRefPulldown.mIsForbid) {
                                if (mRefPulldown.mState == uGUIBase::cReferenceUIPullDown::STATE_NONE) {
                                    mRefPulldown.mState = uGUIBase::cReferenceUIPullDown::STATE_OPEN_INIT;
                                }
                            }
                        }
                    } else {
                        mExitType = EXIT_TYPE_OK;
                        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUICharacterEditPopCard::updateExit);
                    }
                } else {
                    mProc = PR_PULLDOWN;
                    if (!mRefPulldown.mIsForbid) {
                        if (mRefPulldown.mState == uGUIBase::cReferenceUIPullDown::STATE_NONE) {
                            mRefPulldown.mState = uGUIBase::cReferenceUIPullDown::STATE_OPEN_INIT;
                        }
                    }
                }
                break;
            }
            case 1:
            {
                mExitType = EXIT_TYPE_CANCEL;
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUICharacterEditPopCard::updateExit);
                break;
            }
            case 2:
            {
                mProc = PR_PULLDOWN;
                if (!mRefPulldown.mIsForbid) {
                    if (mRefPulldown.mState == uGUIBase::cReferenceUIPullDown::STATE_NONE) {
                        mRefPulldown.mState = uGUIBase::cReferenceUIPullDown::STATE_OPEN_INIT;
                    }
                }
                break;
            }
            case 3:
            {
                static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 4u);
                mExitType = EXIT_TYPE_OK;
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUICharacterEditPopCard::updateExit);
                break;
            }
            case 4:
            {
                static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 5u);
                mExitType = EXIT_TYPE_CANCEL;
                mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUICharacterEditPopCard::updateExit);
                break;
            }
            default:
            {
                break;
            }
        }
    }
}

u32 uGUICharacterEditPopCard::evCtrlDecide(cControl::Message* msg) {
    if (mpCtrlV != nullptr) {
        if (mpCtrlV->getCurrentPos() == 1) {
            if (mpCtrlH != nullptr) {
                if (mpCtrlH->mCurrentPos != 0) {
                    if (sMenu::getInstance()->mPawnManager.isMove()) {
                        setInputEvent(5u);
                    } else {
                        setInputEvent(67u);
                    }
                } else {
                    if (sMenu::getInstance()->mPawnManager.isMove()) {
                        setInputEvent(4u);
                    } else {
                        setInputEvent(66u);
                    }
                }
            } else {
                if (sMenu::getInstance()->mPawnManager.isMove()) {
                    setInputEvent(4u);
                } else {
                    setInputEvent(66u);
                }
            }
        } else {
            if (mpCtrlV->getCurrentPos() == 0) {
                setInputEvent(66u);
            }
        }
    } else {
        setInputEvent(66u);
    }
    return 0;
}

u32 uGUICharacterEditPopCard::evCtrlCancel(cControl::Message* msg) {
    if (sMenu::getInstance()->mPawnManager.isMove()) {
        setInputEvent(5u);
    } else {
        setInputEvent(67u);
    }
    return 0;
}

inline void uGUICharacterEditPopCard::evInputDecideBottun() {
    static_cast<sGUIExt*>(sGUI::mpInstance)->requestSE(0u, 4u);
}

u32 uGUICharacterEditPopCard::evCtrlMouseClick(cControl::Message* msg) {
    if (msg->mouse_hit_id != 2) {
        if (msg->mouse_hit_id == 1) {
            if (sMenu::getInstance()->mPawnManager.isMove()) {
                setInputEvent(4u);
            } else {
                setInputEvent(69u);
            }
        } else {
            if (msg->mouse_hit_id == 0) {
                setInputEvent(68u);
            }
        }
    } else {
        if (sMenu::getInstance()->mPawnManager.isMove()) {
            setInputEvent(5u);
        } else {
            setInputEvent(70u);
        }
    }
    return 0;
}

__attribute__((weak)) s32 uGUICharacterEditPopCard::getSMenuCursorY() {
    DDON_STUB("uGUICharacterEditPopCard::getSMenuCursorY")
    return {};
}

inline uGUICharacterEditPopCard::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICharacterEditPopCard::MyDTI uGUICharacterEditPopCard::DTI("uGUICharacterEditPopCard", &::uGUIsMenuBase::DTI, 4784ul, 0u, 0u);

MtObject* uGUICharacterEditPopCard::MyDTI::newInstance() const {
    return new (16u) uGUICharacterEditPopCard;
}

