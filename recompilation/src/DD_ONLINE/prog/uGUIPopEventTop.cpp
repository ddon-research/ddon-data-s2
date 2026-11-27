// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "uGUIPopEventTop.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "../../XFramework/cResource.h"
#include "nQuest.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sQuestManagerExt.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#include "uGUIsMenuBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIPopEventTop::getDTI() const {
    return uGUIPopEventTop::DTI;
}

void* uGUIPopEventTop::operator new(size_t sz, u32 align) {
    return uGUIPopEventTop::getAllocator()->memAlloc(sz, align, uGUIPopEventTop::DTI.getID());
}

uGUIPopEventTop::uGUIPopEventTop() : uGUIsMenuBase(2u, false) {
    mEndType = 0;
    memset(static_cast<void*>(&mDataInst), 0, 740ul);
    mbSetupInfo = false;
    mpHCtrl = nullptr;
    mpVCtrl = nullptr;
    mpButtonCtrl = nullptr;
    setArcTag(rArchiveListArray::convTagId("uGUIPopEventTop"), 0u, false);
}

uGUIPopEventTop::~uGUIPopEventTop() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIPopEventTop::createProperty(MtPropertyList& s) {
    this->uGUIsMenuBase::createProperty(s);
}

bool uGUIPopEventTop::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_POP_EVENT_TOP_GUI"), 129u, 1440567314l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(rArchiveListArray::convTagId("uGUIEntryBoard"), "RES_ID_ENTRY_BOARD_GMD", 0u);
}

__attribute__((weak)) void uGUIPopEventTop::setup() {
    DDON_STUB("uGUIPopEventTop::setup")
    /* stub */
}

void uGUIPopEventTop::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIPopEventTop::move() {
    this->uGUIsMenuBase::move();
}

void uGUIPopEventTop::updateInit() {
    updateInfo();
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIPopEventTop::updateWait);
}

void uGUIPopEventTop::updateWait() {
    updateInfo();
}

__attribute__((weak)) void uGUIPopEventTop::updateInfo() {
    DDON_STUB("uGUIPopEventTop::updateInfo")
    /* stub */
}

__attribute__((weak)) bool uGUIPopEventTop::changeSizeWindow() {
    DDON_STUB("uGUIPopEventTop::changeSizeWindow")
    return {};
}

u32 uGUIPopEventTop::evCtrlVMove(cControl::Message* msg) {
    return 0;
}

u32 uGUIPopEventTop::evCtrlDecide(cControl::Message* msg) {
    return 0;
}

u32 uGUIPopEventTop::evCtrlCancel(cControl::Message* msg) {
    return 0;
}

inline uGUIPopEventTop::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPopEventTop::MyDTI uGUIPopEventTop::DTI("uGUIPopEventTop", &::uGUIsMenuBase::DTI, 3168ul, 0u, 0u);

MtObject* uGUIPopEventTop::MyDTI::newInstance() const {
    return new (16u) uGUIPopEventTop;
}

