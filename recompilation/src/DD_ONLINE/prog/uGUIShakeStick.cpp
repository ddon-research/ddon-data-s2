// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIShakeStick.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sQuestManagerExt.h"
#include "../../XFramework/sSavedata.h"
#include "sSavedataExt.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIShakeStick::getDTI() const {
    return uGUIShakeStick::DTI;
}

void* uGUIShakeStick::operator new(size_t sz, u32 align) {
    return uGUIShakeStick::getAllocator()->memAlloc(sz, align, uGUIShakeStick::DTI.getID());
}

uGUIShakeStick::uGUIShakeStick() : uGUIBase(0u, false) {
    mpINST_Null_charges = nullptr;
    mActPltType = 0;
    mCurrent = 0.0f;
    mpInstAnim_lever = nullptr;
    mpInstAnim_gauge = nullptr;
    mpOBJ_fix_gauge_f_gauge = nullptr;
    mpGUIRes = nullptr;
    mBaseF = mBaseF | 32u;
    mEndType = 1;
    setArcTag(rArchiveListArray::convTagId("uGUIShakeStick"), 0u, false);
}

uGUIShakeStick::~uGUIShakeStick() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

bool uGUIShakeStick::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ACTION00_GUI"), 129u, 1460980947l))) == nullptr)) {
        return false;
    }
    return true;
}

__attribute__((weak)) void uGUIShakeStick::setup() {
    DDON_STUB("uGUIShakeStick::setup")
    /* stub */
}

void uGUIShakeStick::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

__attribute__((weak)) void uGUIShakeStick::setCount(s32 count, s32 countMax) {
    DDON_STUB("uGUIShakeStick::setCount")
    /* stub */
}

void uGUIShakeStick::setSuccess() {
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIShakeStick::updateSuccess);
    mRoutine = 0;
}

void uGUIShakeStick::updateInit() {
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIShakeStick::updateHide);
}

__attribute__((weak)) void uGUIShakeStick::updateHide() {
    DDON_STUB("uGUIShakeStick::updateHide")
    /* stub */
}

__attribute__((weak)) void uGUIShakeStick::updateWait() {
    DDON_STUB("uGUIShakeStick::updateWait")
    /* stub */
}

__attribute__((weak)) void uGUIShakeStick::updateSuccess() {
    DDON_STUB("uGUIShakeStick::updateSuccess")
    /* stub */
}

inline uGUIShakeStick::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIShakeStick::MyDTI uGUIShakeStick::DTI("uGUIShakeStick", &::uGUIBase::DTI, 2640ul, 0u, 0u);

MtObject* uGUIShakeStick::MyDTI::newInstance() const {
    return new (16u) uGUIShakeStick;
}

