// Reconstructed from the game's DWARF debug information.
#include <new>
#include "aMenu.h"
#include "Protocol/PacketData/Common.h"
#include "Protocol/PacketData/Item.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCharSet.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "aBase.h"
#include "aTitle.h"
#include "../../XFramework/cArea.h"
#include "cAreaExt.h"
#include "cCharacterData.h"
#include "cContextInterface.h"
#include "cMenuBase.h"
#include "cNetGameServer.h"
#include "cNetLoginServer.h"
#include "cNetSessionManager.h"
#include "cOpeningMovie.h"
#include "cPlayPointInfo.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "nCharacterData.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUIMessage.h"
#include "sArchiveManager.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "sBazaarManager.h"
#include "../../XFramework/sCamera.h"
#include "sChat.h"
#include "sContextManager.h"
#include "sCraftManager.h"
#include "sDialogBase.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sItemManager.h"
#include "../../XFramework/sMain.h"
#include "sMenu.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "uCharacterEdit.h"
#include "uCharacterSelect.h"
#include "uGUIBase.h"
#include "uGUICharacterSelect.h"
#include "uGUISystemMsg.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& aMenu::getDTI() const {
    return aMenu::DTI;
}

aMenu::aMenu() {
    DDON_STUB("aMenu::aMenu")
    /* stub */
}

aMenu::~aMenu() {
}

__attribute__((weak)) bool aMenu::load() {
    DDON_STUB("aMenu::load")
    return {};
}

__attribute__((weak)) void aMenu::init() {
    DDON_STUB("aMenu::init")
    /* stub */
}

__attribute__((weak)) void aMenu::move() {
    DDON_STUB("aMenu::move")
    /* stub */
}

__attribute__((weak)) void aMenu::final() {
    DDON_STUB("aMenu::final")
    /* stub */
}

const MtDTI& aMenu::getParentType() {
    return aBase::DTI;
}

MT_CTSTR aMenu::getShaderSegment() {
    return "root";
}

__attribute__((weak)) s32 aMenu::moveMovie() {
    DDON_STUB("aMenu::moveMovie")
    return {};
}

__attribute__((weak)) s32 aMenu::moveDecideGameServer() {
    DDON_STUB("aMenu::moveDecideGameServer")
    return {};
}

__attribute__((weak)) s32 aMenu::moveConnectGameServer() {
    DDON_STUB("aMenu::moveConnectGameServer")
    return {};
}

__attribute__((weak)) s32 aMenu::moveDisconnectLoginServer() {
    DDON_STUB("aMenu::moveDisconnectLoginServer")
    return {};
}

__attribute__((weak)) s32 aMenu::moveDisconnectGameServer() {
    DDON_STUB("aMenu::moveDisconnectGameServer")
    return {};
}

__attribute__((weak)) s32 aMenu::moveConnectLoginServer() {
    DDON_STUB("aMenu::moveConnectLoginServer")
    return {};
}

inline aMenu::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

aMenu::MyDTI aMenu::DTI("aMenu", &::cAreaExt::DTI, 224ul, 0u, 0u);

__attribute__((weak)) MtObject* aMenu::MyDTI::newInstance() const {
    DDON_STUB("aMenu::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<CDataCommonU32>::~MtTypedArray();

