// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIPopPartyMember.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "Protocol/PacketData/Party.h"
#include "cControl.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "cMenuBase.h"
#include "../../XFramework/cResource.h"
#include "nDDOUtility.h"
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

const MtDTI& uGUIPopPartyMember::getDTI() const {
    return uGUIPopPartyMember::DTI;
}

uGUIPopPartyMember::~uGUIPopPartyMember() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

bool uGUIPopPartyMember::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_INFO_PARTY_GUI"), 129u, 1419223161l))) == nullptr)) {
        return false;
    }
    return loadGMDarc(getArcTag(0u), "RES_ID_POPPARTYMEMBER_RES_GMD", 0u);
}

__attribute__((weak)) void uGUIPopPartyMember::setup() {
    DDON_STUB("uGUIPopPartyMember::setup")
    /* stub */
}

void uGUIPopPartyMember::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIPopPartyMember::move() {
    this->uGUIsMenuBase::move();
}

s32 uGUIPopPartyMember::getSMenuCursorY() {
    if (mpCtrlV != nullptr) {
        return mpCtrlV->getCurrentPos();
    } else {
        return 0;
    }
}

bool uGUIPopPartyMember::show() {
    if (mIsSetup) {
        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIPopPartyMember::updateInit);
        return true;
    } else {
        return false;
    }
}

void uGUIPopPartyMember::moveInput() {
    if (mpCtrlV == nullptr) {
        return;
    }
    mpCtrlV->execute();
}

__attribute__((weak)) void uGUIPopPartyMember::moveEvent() {
}

__attribute__((weak)) void uGUIPopPartyMember::updateInit() {
    DDON_STUB("uGUIPopPartyMember::updateInit")
    /* stub */
}

__attribute__((weak)) void uGUIPopPartyMember::updateWait() {
    DDON_STUB("uGUIPopPartyMember::updateWait")
    /* stub */
}

u32 uGUIPopPartyMember::evCtrlDecide(cControl::Message* msg) {
    setInputEvent(5u);
    return 0;
}

u32 uGUIPopPartyMember::evCtrlCancel(cControl::Message* msg) {
    setInputEvent(5u);
    return 0;
}

__attribute__((weak)) void uGUIPopPartyMember::partyMemberSetup(uGUIPopPartyMember::PartyMember& partyMember, cGUIInstNull* pINST_Null_list, f32 offsetY) {
    DDON_STUB("uGUIPopPartyMember::partyMemberSetup")
    /* stub */
}

__attribute__((weak)) void uGUIPopPartyMember::partyMemberSetParam(uGUIPopPartyMember::PartyMember& partyMember, const CDataPartyMember& dataPartyMember) {
    DDON_STUB("uGUIPopPartyMember::partyMemberSetParam")
    /* stub */
}

__attribute__((weak)) void uGUIPopPartyMember::partyMemberSetParam(uGUIPopPartyMember::PartyMember& partyMember, MT_CTSTR name, u32 onlineStatus, u32 jobId, u32 jobLv, bool isPawn) {
    DDON_STUB("uGUIPopPartyMember::partyMemberSetParam")
    /* stub */
}

inline uGUIPopPartyMember::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPopPartyMember::MyDTI uGUIPopPartyMember::DTI("uGUIPopPartyMember", &::uGUIsMenuBase::DTI, 4368ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIPopPartyMember::MyDTI::newInstance() const {
    DDON_STUB("uGUIPopPartyMember::MyDTI::newInstance")
    return nullptr;
}

