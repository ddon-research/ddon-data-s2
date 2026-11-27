// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIPopPartyList.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cCharacterData.h"
#include "cControl.h"
#include "cGUIControlMgr.h"
#include "../../XFramework/cGUIInstance.h"
#include "cGUIUtility.h"
#include "cMenuBase.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "nDDOUtility.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sMenu.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sQuestManagerExt.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIPopPartyList::getDTI() const {
    return uGUIPopPartyList::DTI;
}

void* uGUIPopPartyList::operator new(size_t sz, u32 align) {
    return uGUIPopPartyList::getAllocator()->memAlloc(sz, align, uGUIPopPartyList::DTI.getID());
}

__attribute__((noinline)) uGUIPopPartyList::~uGUIPopPartyList() {
    DDON_STUB("uGUIPopPartyList::~uGUIPopPartyList")
    /* stub */
}

bool uGUIPopPartyList::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_POP_PARTYLIST_GUI"), 129u, 1463726175l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_POP_PARTY_LIST_RES_GMD", 0u);
}

__attribute__((weak)) void uGUIPopPartyList::setup() {
    DDON_STUB("uGUIPopPartyList::setup")
    /* stub */
}

void uGUIPopPartyList::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIPopPartyList::move() {
    this->uGUIBase::move();
}

s32 uGUIPopPartyList::getSMenuCursorX() {
    return uGUIBase::DISABLE_IDX;
}

s32 uGUIPopPartyList::getSMenuCursorY() {
    const s32 pos_v = mControlMgr.getCurrentPos(0u);
    const s32 pos_button = mControlMgr.getCurrentPos(2u);
    if (static_cast<unsigned int>(mProc - 1) <= 2) {
        switch (static_cast<unsigned int>(pos_v)) {
            case 0:
            {
                return (sMenu::mpInstance)->mQuickMatch.cMenuBase::getMenuId(1);
            }
            case 1:
            {
                return (sMenu::mpInstance)->mQuickMatch.cMenuBase::getMenuId(2);
            }
            case 2:
            {
                return (sMenu::mpInstance)->mQuickMatch.cMenuBase::getMenuId(3);
            }
            case 3:
            {
                return (sMenu::mpInstance)->mQuickMatch.cMenuBase::getMenuId(static_cast<s32>(static_cast<unsigned long>(pos_button != 0) | 4));
            }
            default:
            {
                return (sMenu::mpInstance)->mQuickMatch.cMenuBase::getMenuId(0);
            }
        }
    } else {
        if (mProc == PR_PLAYER_SEARCH) {
            switch (static_cast<unsigned int>(pos_v)) {
                case 0:
                {
                    return (sMenu::mpInstance)->mSearchFilter.cMenuBase::getConvertCursorIdx(7);
                }
                case 1:
                {
                    return (sMenu::mpInstance)->mSearchFilter.cMenuBase::getConvertCursorIdx(9);
                }
                case 2:
                {
                    return (sMenu::mpInstance)->mSearchFilter.cMenuBase::getConvertCursorIdx(1);
                }
                case 3:
                {
                    return (sMenu::mpInstance)->mSearchFilter.cMenuBase::getConvertCursorIdx(1);
                }
                case 4:
                {
                    return (sMenu::mpInstance)->mSearchFilter.cMenuBase::getConvertCursorIdx(2);
                }
                case 5:
                {
                    return (sMenu::mpInstance)->mSearchFilter.cMenuBase::getConvertCursorIdx(2);
                }
                case 6:
                {
                    return (sMenu::mpInstance)->mSearchFilter.cMenuBase::getConvertCursorIdx(static_cast<s32>(static_cast<unsigned long>(pos_button != 0) | 42));
                }
                default:
                {
                    return (sMenu::mpInstance)->mSearchFilter.cMenuBase::getConvertCursorIdx(0);
                }
            }
        } else {
            return 0;
        }
    }
}

__attribute__((weak)) void uGUIPopPartyList::updateInit() {
    DDON_STUB("uGUIPopPartyList::updateInit")
    /* stub */
}

__attribute__((weak)) void uGUIPopPartyList::updateWait() {
    DDON_STUB("uGUIPopPartyList::updateWait")
    /* stub */
}

__attribute__((weak)) void uGUIPopPartyList::executeFocus() {
    DDON_STUB("uGUIPopPartyList::executeFocus")
    /* stub */
}

__attribute__((weak)) void uGUIPopPartyList::setupControls() {
    DDON_STUB("uGUIPopPartyList::setupControls")
    /* stub */
}

void uGUIPopPartyList::moveInput() {
    if (!isWindowActive()) {
        return;
    }
    mPulldowns.elems[0].mPulldown.execute();
    cReferenceUIPullDown::STATE t0 = mPulldowns.elems[0].mPulldown.mState;
    mPulldowns.elems[1].mPulldown.execute();
    if ((static_cast<unsigned long>(t0) | static_cast<unsigned long>(mPulldowns.elems[1].mPulldown.mState)) != 0) {
        return;
    }
    cReferenceUINumBox::MODE t1 = mRefNumBoxs.elems[0].getMode();
    mRefNumBoxs.elems[0].moveInput();
    cReferenceUINumBox::MODE t2 = mRefNumBoxs.elems[1].getMode();
    mRefNumBoxs.elems[1].moveInput();
    if (t2 == uGUIBase::cReferenceUINumBox::MODE_EDIT) {
        return;
    }
    if (t1 == uGUIBase::cReferenceUINumBox::MODE_EDIT) {
        return;
    }
    mControlMgr.moveInput();
    if (mpButtonCtrl == nullptr) {
        return;
    }
    mpButtonCtrl->execute();
}

void uGUIPopPartyList::moveEvent() {
    mPulldowns.elems[0].mPulldown.moveEvent();
    mPulldowns.elems[1].mPulldown.moveEvent();
    mRefNumBoxs.elems[0].moveEvent();
    mRefNumBoxs.elems[1].moveEvent();
    if (getInputEvent() != 69) {
        if (getInputEvent() == 68) {
            evMoveNumBoxR();
        } else {
            if (getInputEvent() == 67) {
                evMoveNumBoxL();
            }
        }
    } else {
        evDecide();
    }
}

u32 uGUIPopPartyList::evCtrlMove(cControl::Message* msg) {
    setInputEvent(66u);
    return 0;
}

__attribute__((weak)) u32 uGUIPopPartyList::evCtrlMoveNumBoxL(cControl::Message* msg) {
    DDON_STUB("uGUIPopPartyList::evCtrlMoveNumBoxL")
    return {};
}

__attribute__((weak)) void uGUIPopPartyList::evMoveNumBoxL() {
    DDON_STUB("uGUIPopPartyList::evMoveNumBoxL")
    /* stub */
}

__attribute__((weak)) u32 uGUIPopPartyList::evCtrlMoveNumBoxR(cControl::Message* msg) {
    DDON_STUB("uGUIPopPartyList::evCtrlMoveNumBoxR")
    return {};
}

__attribute__((weak)) void uGUIPopPartyList::evMoveNumBoxR() {
    DDON_STUB("uGUIPopPartyList::evMoveNumBoxR")
    /* stub */
}

u32 uGUIPopPartyList::evCtrlDecideStart(cControl::Message* msg) {
    const s32 pos_v = mControlMgr.getCurrentPos(0u);
    if (mProc == PR_PLAYER_SEARCH) {
        if ((pos_v & -2) == 4) {
            setInputEvent(69u);
        }
    } else {
        setInputEvent(69u);
    }
    return 0;
}

__attribute__((weak)) u32 uGUIPopPartyList::evCtrlDecide(cControl::Message* msg) {
    DDON_STUB("uGUIPopPartyList::evCtrlDecide")
    return {};
}

__attribute__((weak)) void uGUIPopPartyList::evDecide() {
    DDON_STUB("uGUIPopPartyList::evDecide")
    /* stub */
}

u32 uGUIPopPartyList::evCtrlCancel(cControl::Message* msg) {
    for (unsigned int i0_1 = 0; i0_1 <= 1u; i0_1 += 1u) {
        if (mPulldowns.elems[i0_1].mPulldown.mState != uGUIBase::cReferenceUIPullDown::STATE_NONE) {
            return 0;
        }
    }
    setInputEvent(5u);
    return 0;
}

inline uGUIPopPartyList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPopPartyList::MyDTI uGUIPopPartyList::DTI("uGUIPopPartyList", &::uGUIBase::DTI, 8880ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIPopPartyList::MyDTI::newInstance() const {
    DDON_STUB("uGUIPopPartyList::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIPopPartyList::cJob::getDTI() const {
    return uGUIPopPartyList::cJob::DTI;
}

inline uGUIPopPartyList::cJob::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPopPartyList::cJob::MyDTI uGUIPopPartyList::cJob::DTI("uGUIPopPartyList::cJob", &::MtObject::DTI, 192ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIPopPartyList::cJob::MyDTI::newInstance() const {
    DDON_STUB("uGUIPopPartyList::cJob::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUIQuickPartyCancel::getDTI() const {
    return uGUIQuickPartyCancel::DTI;
}

uGUIQuickPartyCancel::~uGUIQuickPartyCancel() {
}

void uGUIQuickPartyCancel::setup() {
    this->uGUIPopPartyList::setup();
}

void uGUIQuickPartyCancel::moveInput() {
    if (!isWindowActive()) {
        return;
    }
    mControlMgr.moveInput();
    if (mpButtonCtrl == nullptr) {
        return;
    }
    mpButtonCtrl->execute();
}

s32 uGUIQuickPartyCancel::getSMenuCursorY() {
    const s32 pos_button = mControlMgr.getCurrentPos(2u);
    if (pos_button == 1) {
        return (sMenu::mpInstance)->mQuickMatchCancel.cMenuBase::getConvertCursorIdx(6);
    } else {
        if (pos_button == 0) {
            return (sMenu::mpInstance)->mQuickMatchCancel.cMenuBase::getConvertCursorIdx(5);
        } else {
            return (sMenu::mpInstance)->mQuickMatchCancel.cMenuBase::getConvertCursorIdx(0);
        }
    }
}

inline uGUIQuickPartyCancel::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIQuickPartyCancel::MyDTI uGUIQuickPartyCancel::DTI("uGUIQuickPartyCancel", &::uGUIPopPartyList::DTI, 8880ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIQuickPartyCancel::MyDTI::newInstance() const {
    DDON_STUB("uGUIQuickPartyCancel::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<uGUIPopPartyList::cJob>::~MtTypedArray();

