// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIPopPawnPoint.h"
#include "Protocol/PacketData/CharacterCommon.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "Protocol/PacketData/SupportPoint.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "cGUIUtility.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "nDDOUtility.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sItemManager.h"
#include "sMenu.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "uGUIBase.h"
#include "uGUISystemMsg.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

static const s32 CONTENTS_TO_STATUS_PARAM_TYPE[3] = {
    0,
    1,
    0,
};

static const s32 CLICK_TO_CONTENTS[4] = {
    0,
    1,
    2,
    2,
};

const MtDTI& uGUIPopPawnPoint::getDTI() const {
    return uGUIPopPawnPoint::DTI;
}

__attribute__((noinline)) uGUIPopPawnPoint::~uGUIPopPawnPoint() {
    if (mSupportRateVec.mLength != 0) {
        u32 v0_0 = mSupportRateVec.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mSupportRateVec.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mSupportRateVec.mpArray[i0_3];
                v1_0 = mSupportRateVec.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mSupportRateVec.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSupportRateVec.mpArray));
    }
    mSupportRateVec.mpArray = nullptr;
    mSupportRateVec.mBufsiz = 0;
    mSupportRateVec.mLength = 0;
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
}

bool uGUIPopPawnPoint::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_PAWN_POINT_GUI"), 129u, 1435226490l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_PAWN_POINT_GMD", 0u);
}

__attribute__((weak)) void uGUIPopPawnPoint::setup() {
    DDON_STUB("uGUIPopPawnPoint::setup")
    /* stub */
}

void uGUIPopPawnPoint::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpGUISystemMsg == nullptr) {
        return;
    }
    mpGUISystemMsg->kill();
    mpGUISystemMsg = nullptr;
}

void uGUIPopPawnPoint::updatePtr() {
    if (mpGUISystemMsg == nullptr) {
        return;
    }
    if (mpGUISystemMsg->isEnable()) {
        return;
    }
    mpGUISystemMsg = nullptr;
}

__attribute__((weak)) void uGUIPopPawnPoint::updateInit() {
    DDON_STUB("uGUIPopPawnPoint::updateInit")
    /* stub */
}

__attribute__((weak)) void uGUIPopPawnPoint::updateWait() {
    DDON_STUB("uGUIPopPawnPoint::updateWait")
    /* stub */
}

void uGUIPopPawnPoint::updateExit() {
    end();
}

void uGUIPopPawnPoint::moveInput() {
    if (mProc != PR_EDIT) {
        if (mProc == PR_EDIT_JOB) {
            mReference.mPulldown.execute();
            mReference.mNumBox[1].moveInput();
        } else {
            if (mProc == PR_EDIT_JOBPOINT) {
                mReference.mNumBox[1].moveInput();
                if (mpButtonCtrl != nullptr) {
                    mpButtonCtrl->execute();
                }
            }
        }
    } else {
        if (mpNumBoxCtrl != nullptr) {
            mpNumBoxCtrl->execute();
        }
        mReference.mPulldown.execute();
        mReference.mNumBox[1].moveInput();
        if (mpHCtrl != nullptr) {
            mpHCtrl->execute();
        }
        if (mpVCtrl != nullptr) {
            mpVCtrl->execute();
        }
        if (mpButtonCtrl != nullptr) {
            mpButtonCtrl->execute();
        }
    }
}

__attribute__((weak)) void uGUIPopPawnPoint::adjustCursor() {
    DDON_STUB("uGUIPopPawnPoint::adjustCursor")
    /* stub */
}

__attribute__((weak)) void uGUIPopPawnPoint::updatePointDisp() {
    DDON_STUB("uGUIPopPawnPoint::updatePointDisp")
    /* stub */
}

__attribute__((weak)) bool uGUIPopPawnPoint::setupPulldownJob() {
    DDON_STUB("uGUIPopPawnPoint::setupPulldownJob")
    return {};
}

__attribute__((weak)) void uGUIPopPawnPoint::setupRateData() {
    DDON_STUB("uGUIPopPawnPoint::setupRateData")
    /* stub */
}

__attribute__((weak)) void uGUIPopPawnPoint::moveEvent() {
    DDON_STUB("uGUIPopPawnPoint::moveEvent")
    /* stub */
}

__attribute__((weak)) void uGUIPopPawnPoint::evStart() {
    DDON_STUB("uGUIPopPawnPoint::evStart")
    /* stub */
}

__attribute__((weak)) u32 uGUIPopPawnPoint::evCtrlDecide(cControl::Message* msg) {
    DDON_STUB("uGUIPopPawnPoint::evCtrlDecide")
    return {};
}

u32 uGUIPopPawnPoint::evCtrlStart(cControl::Message* msg) {
    if (mpVCtrl != nullptr) {
        if (mpVCtrl->mCurrentPos == 1) {
            setInputEvent(68u);
        }
    }
    return 0;
}

u32 uGUIPopPawnPoint::evCtrlCancel(cControl::Message* msg) {
    setInputEvent(69u);
    return 0;
}

u32 uGUIPopPawnPoint::evCtrlAdjustCursorV(cControl::Message* msg) {
    setInputEvent(70u);
    return 0;
}

u32 uGUIPopPawnPoint::evCtrlAdjustCursorH(cControl::Message* msg) {
    setInputEvent(71u);
    return 0;
}

__attribute__((weak)) u32 uGUIPopPawnPoint::evCtrlMouse(cControl::Message* msg) {
    DDON_STUB("uGUIPopPawnPoint::evCtrlMouse")
    return {};
}

u32 uGUIPopPawnPoint::evCtrlNumBoxL(cControl::Message* msg) {
    if (mpVCtrl != nullptr) {
        if (mProc == PR_EDIT) {
            if (mpVCtrl->mCurrentPos == 1) {
                setInputEvent(72u);
            }
        }
    }
    return 0;
}

u32 uGUIPopPawnPoint::evCtrlNumBoxR(cControl::Message* msg) {
    if (mpVCtrl != nullptr) {
        if (mProc == PR_EDIT) {
            if (mpVCtrl->mCurrentPos == 1) {
                setInputEvent(73u);
            }
        }
    }
    return 0;
}

__attribute__((weak)) void uGUIPopPawnPoint::settingSupportPointUseInfo() {
    DDON_STUB("uGUIPopPawnPoint::settingSupportPointUseInfo")
    /* stub */
}

__attribute__((weak)) u32 uGUIPopPawnPoint::getConfirmationMessage(MT_STR in_str, u32* analyze) {
    DDON_STUB("uGUIPopPawnPoint::getConfirmationMessage")
    return {};
}

__attribute__((weak)) u32 uGUIPopPawnPoint::getResultMessage(MT_STR in_str, u32* analyze) {
    DDON_STUB("uGUIPopPawnPoint::getResultMessage")
    return {};
}

__attribute__((weak)) void uGUIPopPawnPoint::resetEdit() {
    DDON_STUB("uGUIPopPawnPoint::resetEdit")
    /* stub */
}

inline uGUIPopPawnPoint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPopPawnPoint::MyDTI uGUIPopPawnPoint::DTI("uGUIPopPawnPoint", &::uGUIBase::DTI, 5968ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIPopPawnPoint::MyDTI::newInstance() const {
    DDON_STUB("uGUIPopPawnPoint::MyDTI::newInstance")
    return nullptr;
}

