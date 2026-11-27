// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIClanEmblem.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive2D.h"
#include "../../XFramework/cGUIInstance.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sOmManager.h"
#include "../../XFramework/uCoord.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIClanEmblem::getDTI() const {
    return uGUIClanEmblem::DTI;
}

void* uGUIClanEmblem::operator new(size_t sz, u32 align) {
    return uGUIClanEmblem::getAllocator()->memAlloc(sz, align, uGUIClanEmblem::DTI.getID());
}

uGUIClanEmblem::uGUIClanEmblem() : uGUIBase(0u, false), mpGUIRes(static_cast<rGUI*>(nullptr)) {
    mEndType = 1;
    mBaseF = mBaseF | 1024u;
    setArcTag(rArchiveListArray::convTagId("uGUIClanEmblem"), 0u, false);
}

uGUIClanEmblem::~uGUIClanEmblem() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIClanEmblem::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
}

bool uGUIClanEmblem::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_CLANEMBLEM_GUI"), 129u, 1413352445l))) == nullptr)) {
        return false;
    }
    return true;
}

__attribute__((weak)) void uGUIClanEmblem::setup() {
    DDON_STUB("uGUIClanEmblem::setup")
    /* stub */
}

void uGUIClanEmblem::kill() {
    this->uGUIBase::kill();
}

void uGUIClanEmblem::updateMove() {
    mEmblem.applyParam(static_cast<sNetworkExt*>(sNetwork::getInstance())->mpGameServer->mMyClanParam);
    mEmblem.updateArcLoader(getDeltaTime());
}

inline uGUIClanEmblem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIClanEmblem::MyDTI uGUIClanEmblem::DTI("uGUIClanEmblem", &::uGUIBase::DTI, 2528ul, 0u, 0u);

MtObject* uGUIClanEmblem::MyDTI::newInstance() const {
    return new (16u) uGUIClanEmblem;
}

