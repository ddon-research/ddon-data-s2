// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIPopPawnList.h"
#include "Protocol/PacketData/Community.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cCharacterData.h"
#include "cControl.h"
#include "cGUIControlMgr.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "cMenuBase.h"
#include "../../XFramework/cResource.h"
#include "nCharacterData.h"
#include "nDDOUtility.h"
#include "nJobParam.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "sAIPawnTalkMgr.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sMenu.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

static const u32 PawnMotionSituations[7] = {
    1,
    2,
    4,
    6,
    7,
    8,
    9,
};

const MtDTI& uGUIPopPawnList::getDTI() const {
    return uGUIPopPawnList::DTI;
}

__attribute__((noinline)) uGUIPopPawnList::~uGUIPopPawnList() {
    DDON_STUB("uGUIPopPawnList::~uGUIPopPawnList")
    /* stub */
}

bool uGUIPopPawnList::loadResource() {
    if (mpGUIRes == nullptr) {
        if ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_POP_PAWNLIST_GUI"), 129u, 1419224085l))) != nullptr) {
            if (loadGMDarc(getArcTag(0u), "RES_ID_PAWN_REACTION_GMD", 0u)) {
                return loadGMDarc(getArcTag(0u), "RES_ID_EMOTE_TEXT_PAWN_GMD", 1u);
            }
        }
    } else {
        if (loadGMDarc(getArcTag(0u), "RES_ID_PAWN_REACTION_GMD", 0u)) {
            return loadGMDarc(getArcTag(0u), "RES_ID_EMOTE_TEXT_PAWN_GMD", 1u);
        }
    }
    return false;
}

void uGUIPopPawnList::setup() {
    this->uGUIBase::setup();
    if (!mIsEndLoadResource) {
        return;
    }
    setPriority(static_cast<sGUIExt*>(sGUI::getInstance())->issuePriority(12u), true);
    setPlay(true);
    setupInstancesAndObjects();
    setupControls();
    if (sMenu::getInstance()->mMenuCustomize.isMove()) {
        return;
    }
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIPopPawnList::updateInit);
}

void uGUIPopPawnList::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIPopPawnList::move() {
    this->uGUIBase::move();
}

void uGUIPopPawnList::show() {
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIPopPawnList::updateInit);
}

void uGUIPopPawnList::updateInit() {
    initPulldownData(0);
    initPulldownData(1);
    initPulldownData(2);
    initPulldownData(3);
    initPulldownData(4);
    initPulldownData(5);
    initPulldownData(6);
    applySetting();
    mProc = PR_MAIN;
    setInstanceVisible(static_cast<cGUIInstance*>(mData.mpINST_Null_all), true);
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIPopPawnList::updateWait);
}

__attribute__((weak)) void uGUIPopPawnList::updateWait() {
    DDON_STUB("uGUIPopPawnList::updateWait")
    /* stub */
}

void uGUIPopPawnList::moveInput() {
    if (!isWindowActive()) {
        return;
    }
    mPulldowns.elems[0].mPulldown.execute();
    cReferenceUIPullDown::STATE t0 = mPulldowns.elems[0].mPulldown.mState;
    mPulldowns.elems[1].mPulldown.execute();
    cReferenceUIPullDown::STATE t1 = mPulldowns.elems[1].mPulldown.mState;
    mPulldowns.elems[2].mPulldown.execute();
    cReferenceUIPullDown::STATE t2 = mPulldowns.elems[2].mPulldown.mState;
    mPulldowns.elems[3].mPulldown.execute();
    cReferenceUIPullDown::STATE t3 = mPulldowns.elems[3].mPulldown.mState;
    mPulldowns.elems[4].mPulldown.execute();
    cReferenceUIPullDown::STATE t4 = mPulldowns.elems[4].mPulldown.mState;
    mPulldowns.elems[5].mPulldown.execute();
    cReferenceUIPullDown::STATE t5 = mPulldowns.elems[5].mPulldown.mState;
    mPulldowns.elems[6].mPulldown.execute();
    if (((((((static_cast<unsigned long>(t0) | static_cast<unsigned long>(t1)) | static_cast<unsigned long>(t2)) | static_cast<unsigned long>(t3)) | static_cast<unsigned long>(t4)) | static_cast<unsigned long>(t5)) | static_cast<unsigned long>(mPulldowns.elems[6].mPulldown.mState)) == 0) {
        mControlMgr.moveInput();
    }
}

void uGUIPopPawnList::moveEvent() {
    mPulldowns.elems[0].mPulldown.moveEvent();
    mPulldowns.elems[1].mPulldown.moveEvent();
    mPulldowns.elems[2].mPulldown.moveEvent();
    mPulldowns.elems[3].mPulldown.moveEvent();
    mPulldowns.elems[4].mPulldown.moveEvent();
    mPulldowns.elems[5].mPulldown.moveEvent();
    mPulldowns.elems[6].mPulldown.moveEvent();
    if (mInputEventId != 67) {
        return;
    }
    s32 t0 = mControlMgr.getCurrentPos(0u);
    if (static_cast<unsigned int>(t0) <= 6) {
        if (mPulldowns.elems[static_cast<unsigned int>(t0)].mPulldown.mIsForbid) {
            if (mPulldowns.elems[static_cast<unsigned int>(t0)].mPulldown.mState != uGUIBase::cReferenceUIPullDown::STATE_NONE) {
                mPulldownId = static_cast<PULLDOWN_ID>(t0);
                mProc = PR_PULLDOWN;
            }
        } else {
            if (mPulldowns.elems[static_cast<unsigned int>(t0)].mPulldown.mState == uGUIBase::cReferenceUIPullDown::STATE_NONE) {
                mPulldowns.elems[static_cast<unsigned int>(t0)].mPulldown.mState = uGUIBase::cReferenceUIPullDown::STATE_OPEN_INIT;
            }
            mPulldownId = static_cast<PULLDOWN_ID>(t0);
            mProc = PR_PULLDOWN;
        }
    }
}

__attribute__((weak)) void uGUIPopPawnList::setupControls() {
    DDON_STUB("uGUIPopPawnList::setupControls")
    /* stub */
}

u32 uGUIPopPawnList::evCtrlMoveFocus(cControl::Message* msg) {
    setInputEvent(66u);
    return 0;
}

u32 uGUIPopPawnList::evCtrlDecide(cControl::Message* msg) {
    if (msg != nullptr) {
        if (msg->reason == nGUIExt::MOUSE_LCLICK) {
            if (msg->click_vol > -1) {
                mControlMgr.setCurrentPos(0u, msg->click_vol);
            }
        }
    }
    if (mControlMgr.getCurrentPos(0u) == 7) {
        setInputEvent(4u);
    } else {
        setInputEvent(67u);
    }
    return 0;
}

u32 uGUIPopPawnList::evCtrlCancel(cControl::Message* msg) {
    if (sMenu::getInstance()->mMenuCustomize.isMove()) {
        mSMENUcancel = true;
        mProc = PR_STOP;
    }
    static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(0u, 5u);
    return 0;
}

__attribute__((weak)) void uGUIPopPawnList::initPulldownData(s32 pulldownId) {
    DDON_STUB("uGUIPopPawnList::initPulldownData")
    /* stub */
}

__attribute__((weak)) void uGUIPopPawnList::applySetting() {
    DDON_STUB("uGUIPopPawnList::applySetting")
    /* stub */
}

__attribute__((weak)) void uGUIPopPawnList::setupInstancesAndObjects() {
    DDON_STUB("uGUIPopPawnList::setupInstancesAndObjects")
    /* stub */
}

inline uGUIPopPawnList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPopPawnList::MyDTI uGUIPopPawnList::DTI("uGUIPopPawnList", &::uGUIBase::DTI, 23376ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIPopPawnList::MyDTI::newInstance() const {
    DDON_STUB("uGUIPopPawnList::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) void uGUIPopPawnList::Pulldown::setup(f32 yOffset, uGUIBase* guiBase, cGUIInstNull* pINST_Null, cGUIInstNull* pINST_duplicated) {
    DDON_STUB("uGUIPopPawnList::Pulldown::setup")
    /* stub */
}

