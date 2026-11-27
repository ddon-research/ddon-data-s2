// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIBazaarPopInfo.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIBazaarPopInfo::getDTI() const {
    return uGUIBazaarPopInfo::DTI;
}

void* uGUIBazaarPopInfo::operator new(size_t sz, u32 align) {
    return uGUIBazaarPopInfo::getAllocator()->memAlloc(sz, align, uGUIBazaarPopInfo::DTI.getID());
}

uGUIBazaarPopInfo::uGUIBazaarPopInfo() : uGUIBase(0u, false) {
    mBaseF = mBaseF | 64u;
    mpGUIRes = nullptr;
    setArcTag(rArchiveListArray::convTagId("uGUIBazaar"), 0u, false);
    mIsBegin = false;
}

uGUIBazaarPopInfo::~uGUIBazaarPopInfo() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIBazaarPopInfo::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
}

bool uGUIBazaarPopInfo::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_POP_BAZZARINFO_GUI"), 129u, 1418994382l))) == nullptr)) {
        return false;
    }
    return true;
}

void uGUIBazaarPopInfo::move() {
    this->uGUIBase::move();
}

__attribute__((weak)) void uGUIBazaarPopInfo::setup() {
    DDON_STUB("uGUIBazaarPopInfo::setup")
    /* stub */
}

void uGUIBazaarPopInfo::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

__attribute__((weak)) void uGUIBazaarPopInfo::updatePtr() {
}

__attribute__((weak)) void uGUIBazaarPopInfo::updateInit() {
    DDON_STUB("uGUIBazaarPopInfo::updateInit")
    /* stub */
}

__attribute__((weak)) void uGUIBazaarPopInfo::updateMove() {
}

inline uGUIBazaarPopInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIBazaarPopInfo::MyDTI uGUIBazaarPopInfo::DTI("uGUIBazaarPopInfo", &::uGUIBase::DTI, 2272ul, 0u, 0u);

MtObject* uGUIBazaarPopInfo::MyDTI::newInstance() const {
    return new (16u) uGUIBazaarPopInfo;
}

