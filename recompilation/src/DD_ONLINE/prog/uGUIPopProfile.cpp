// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIPopProfile.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "cGUIControlMgr.h"
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
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#include "uGUIsMenuBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIPopProfile::getDTI() const {
    return uGUIPopProfile::DTI;
}

uGUIPopProfile::~uGUIPopProfile() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIPopProfile::createProperty(MtPropertyList& s) {
    this->uGUIsMenuBase::createProperty(s);
}

bool uGUIPopProfile::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_POP_PROFILE_GUI"), 129u, 1418981403l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_POP_PROFILE_RES_GMD", 0u);
}

__attribute__((weak)) void uGUIPopProfile::setup() {
    DDON_STUB("uGUIPopProfile::setup")
    /* stub */
}

void uGUIPopProfile::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

__attribute__((weak)) void uGUIPopProfile::moveInput() {
    DDON_STUB("uGUIPopProfile::moveInput")
    /* stub */
}

void uGUIPopProfile::moveEvent() {
    if (mPulldownArray.mLength != 0) {
        for (unsigned int i0_3 = 0;;) {
            if (static_cast<cPulldown*>(mPulldownArray.getBuffer()[static_cast<int>(i0_3)])->mPulldown.moveEvent()) {
                return;
            } else {
                if ((i0_3 + 1u) < mPulldownArray.mLength) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
    if (static_cast<int>(getInputEvent()) <= 65) {
        if (static_cast<int>(getInputEvent()) <= 17) {
            if (getInputEvent() != 4) {
                if (getInputEvent() == 5) {
                    updateCursor();
                    s32 t1 = mControls.getCurrentPos(0u);
                    if (t1 != 3) {
                        if (t1 == 5) {
                            mControls.enablePadControls(1u);
                        } else {
                            mControls.disablePadControls(1u);
                        }
                    } else {
                        mControls.enablePadControls(1u);
                    }
                }
            } else {
                updateCursor();
                s32 t0 = mControls.getCurrentPos(0u);
                if (t0 != 3) {
                    if (t0 == 5) {
                        mControls.enablePadControls(1u);
                    } else {
                        mControls.disablePadControls(1u);
                    }
                } else {
                    mControls.enablePadControls(1u);
                }
                updateDecide();
            }
        } else {
            if (getInputEvent() != 18) {
                if (getInputEvent() == 20) {
                    updateCursor();
                    s32 t1 = mControls.getCurrentPos(0u);
                    if (t1 != 3) {
                        if (t1 == 5) {
                            mControls.enablePadControls(1u);
                        } else {
                            mControls.disablePadControls(1u);
                        }
                    } else {
                        mControls.enablePadControls(1u);
                    }
                } else {
                    if (getInputEvent() == 21) {
                        updateCursor();
                    }
                }
            } else {
                updateDecide();
            }
        }
    } else {
        if (getInputEvent() == 66) {
            updateCursor();
            s32 t0 = mControls.getCurrentPos(0u);
            if (t0 != 3) {
                if (t0 == 5) {
                    mControls.enablePadControls(1u);
                } else {
                    mControls.disablePadControls(1u);
                }
            } else {
                mControls.enablePadControls(1u);
            }
            updateDecide();
        }
    }
}

s32 uGUIPopProfile::getSMenuCursorX() {
    return uGUIBase::DISABLE_IDX;
}

__attribute__((weak)) s32 uGUIPopProfile::getSMenuCursorY() {
    DDON_STUB("uGUIPopProfile::getSMenuCursorY")
    return {};
}

void uGUIPopProfile::updateDispWait() {
    if (sMenu::getInstance()->mMatchingProfile.mMenuRno[0] != 2) {
        return;
    }
    updateInit();
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIPopProfile::updateInit);
}

__attribute__((weak)) void uGUIPopProfile::updateInit() {
    DDON_STUB("uGUIPopProfile::updateInit")
    /* stub */
}

__attribute__((weak)) void uGUIPopProfile::updateWait() {
    DDON_STUB("uGUIPopProfile::updateWait")
    /* stub */
}

__attribute__((weak)) void uGUIPopProfile::updateDecide() {
    DDON_STUB("uGUIPopProfile::updateDecide")
    /* stub */
}

__attribute__((weak)) void uGUIPopProfile::updateCursor() {
    DDON_STUB("uGUIPopProfile::updateCursor")
    /* stub */
}

u32 uGUIPopProfile::evCtrlMouseClick(cControl::Message* pMsg) {
    if (pMsg != nullptr) {
        switch (pMsg->mouse_hit_id) {
            case 0:
            {
                mRefTextbox.closeKeyboard(true);
                if (mInputEventId == 0) {
                    setInputEvent(66u);
                    return 1;
                } else {
                    return 1;
                }
                break;
            }
            case 1:
            {
                mRefTextbox.closeKeyboard(true);
                if (mInputEventId == 0) {
                    setInputEvent(66u);
                    return 1;
                } else {
                    return 1;
                }
                break;
            }
            case 2:
            {
                mRefTextbox.closeKeyboard(true);
                if (mInputEventId == 0) {
                    setInputEvent(66u);
                    return 1;
                } else {
                    return 1;
                }
                break;
            }
            case 3:
            {
                mControls.setCurrentPos(1u, pMsg->click_vol);
                mRefTextbox.closeKeyboard(true);
                mControls.getCurrentPos(1u);
                if (mInputEventId == 0) {
                    setInputEvent(66u);
                    return 1;
                } else {
                    return 1;
                }
                break;
            }
            case 5:
            {
                mControls.setCurrentPos(1u, pMsg->click_vol);
                mRefTextbox.closeKeyboard(true);
                if (pMsg->click_vol != 0) {
                    setInputEvent(5u);
                    if (mInputEventId == 0) {
                        setInputEvent(66u);
                        return 1;
                    } else {
                        return 1;
                    }
                } else {
                    setInputEvent(4u);
                    if (mInputEventId == 0) {
                        setInputEvent(66u);
                        return 1;
                    } else {
                        return 1;
                    }
                }
                break;
            }
            default:
            {
                if (mInputEventId == 0) {
                    setInputEvent(66u);
                    return 1;
                } else {
                    return 1;
                }
                break;
            }
        }
    } else {
        return 0;
    }
}

bool uGUIPopProfile::msgEventFunc(cControl::Message* msg) {
    if (msg != nullptr) {
        if (msg->reason == nGUIExt::TRG_CANCEL) {
            setInputEvent(5u);
            return false;
        } else {
            if (msg->reason == nGUIExt::TRG_DECIDE) {
                u32 pos = mControls.getCurrentPos(0u);
                if (pos == 5) {
                    setInputEvent(4u);
                    return false;
                } else {
                    if (pos == 3) {
                        s32 t0 = mControls.getCurrentPos(1u);
                        if (t0 == 1) {
                            if (!sMenu::getInstance()->mMatchingProfile.mProfile.mInviteWait) {
                                return false;
                            } else {
                                return true;
                            }
                        } else {
                            if (t0 == 0) {
                                if (!sMenu::getInstance()->mMatchingProfile.getProfileInviteWait()) {
                                    return true;
                                }
                            }
                            return false;
                        }
                    } else {
                        return true;
                    }
                }
            } else {
                return true;
            }
        }
    } else {
        return true;
    }
}

inline uGUIPopProfile::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPopProfile::MyDTI uGUIPopProfile::DTI("uGUIPopProfile", &::uGUIsMenuBase::DTI, 5456ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIPopProfile::MyDTI::newInstance() const {
    DDON_STUB("uGUIPopProfile::MyDTI::newInstance")
    return nullptr;
}

