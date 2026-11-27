// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUICharacterSelect.h"
#include "Protocol/PacketData/Character.h"
#include "Protocol/PacketData/GP.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtRandom.h"
#include "../../MT/MtString.h"
#include "cCharacterData.h"
#include "cControl.h"
#include "cEditParam.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "cNetGameServer.h"
#include "cNetLoginServer.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "nCharacterData.h"
#include "nDDOUtility.h"
#include "nHumanMsg.h"
#include "nJobParam.h"
#include "../../generated/shared/nKeyCustom.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "sArchiveManager.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "uEditSaveLoadFlow.h"
#include "uGUIAnnounce.h"
#include "uGUIBase.h"
#include "uGUISystemMsg.h"
#include "uGUIsMenuBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUICharacterSelect::getDTI() const {
    return uGUICharacterSelect::DTI;
}

void* uGUICharacterSelect::operator new(size_t sz, u32 align) {
    return uGUICharacterSelect::getAllocator()->memAlloc(sz, align, uGUICharacterSelect::DTI.getID());
}

__attribute__((noinline)) uGUICharacterSelect::~uGUICharacterSelect() {
    DDON_STUB("uGUICharacterSelect::~uGUICharacterSelect")
    /* stub */
}

bool uGUICharacterSelect::loadResource() {
    if (mpGUIRes == nullptr) {
        if ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_CHARACTER_SELECT_GUI"), 129u, 1466067039l))) != nullptr) {
            if (loadGMDarc(getArcTag(0u), "RES_ID_CHARACTERSELECT_RES_GMD", 0u)) {
                return loadGMDarc(getArcTag(0u), "RES_ID_POP_PROFILE_RES_GMD", 1u);
            }
        }
    } else {
        if (loadGMDarc(getArcTag(0u), "RES_ID_CHARACTERSELECT_RES_GMD", 0u)) {
            return loadGMDarc(getArcTag(0u), "RES_ID_POP_PROFILE_RES_GMD", 1u);
        }
    }
    return false;
}

__attribute__((weak)) void uGUICharacterSelect::setup() {
    DDON_STUB("uGUICharacterSelect::setup")
    /* stub */
}

void uGUICharacterSelect::kill() {
    this->uGUIBase::kill();
    if (mpAnnounce != nullptr) {
        mpAnnounce->kill();
        mpAnnounce = nullptr;
    }
    if (mpGUISystemMsg != nullptr) {
        mpGUISystemMsg->kill();
        mpGUISystemMsg = nullptr;
    }
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUICharacterSelect::move() {
    if (mData.mpINST_msg_loadicon00 != nullptr) {
        mData.mpINST_msg_loadicon00->setVisible(false);
    }
    mRefCursor.uGUIBase::cReferenceUIVlCursor::update();
    mRefNumPager.uGUIBase::cReferenceUINumPager::update();
    this->uGUIsMenuBase::move();
}

void uGUICharacterSelect::updatePtr() {
    if (mpAnnounce != nullptr) {
        if (!mpAnnounce->isEnable()) {
            mpAnnounce = nullptr;
        }
    }
    if (mpGUISystemMsg != nullptr) {
        if (!mpGUISystemMsg->isEnable()) {
            mpGUISystemMsg = nullptr;
        }
    }
    if (mpSaveLoadFlow == nullptr) {
        return;
    }
    if (mpSaveLoadFlow->isEnable()) {
        return;
    }
    mpSaveLoadFlow = nullptr;
}

void uGUICharacterSelect::adjustScale() {
    const f32 fScaleRate = getScaleForDefaultResolution(1.0f);
    cGUIInstNull* t0 = mpInstNullBase;
    if (t0 == nullptr) {
        return;
    }
    t0->setScaleX(fScaleRate);
    t0->setScaleY(fScaleRate);
    t0->setScaleZ(fScaleRate);
}

__attribute__((weak)) void uGUICharacterSelect::updateListDraw() {
    DDON_STUB("uGUICharacterSelect::updateListDraw")
    /* stub */
}

bool uGUICharacterSelect::isSafeCharacterData() {
    if (mppCharacterData != nullptr) {
        if ((*mppCharacterData) != nullptr) {
            if (mpCharacterDataNum != nullptr) {
                return mIsWakeup;
            }
        }
    }
    return false;
}

__attribute__((weak)) void uGUICharacterSelect::wakeup() {
    DDON_STUB("uGUICharacterSelect::wakeup")
    /* stub */
}

__attribute__((weak)) void uGUICharacterSelect::moveInput() {
    DDON_STUB("uGUICharacterSelect::moveInput")
    /* stub */
}

__attribute__((weak)) void uGUICharacterSelect::moveEvent() {
    DDON_STUB("uGUICharacterSelect::moveEvent")
    /* stub */
}

__attribute__((weak)) void uGUICharacterSelect::updateRight(s32 idx) {
    DDON_STUB("uGUICharacterSelect::updateRight")
    /* stub */
}

__attribute__((weak)) void uGUICharacterSelect::updateBonusCource() {
    DDON_STUB("uGUICharacterSelect::updateBonusCource")
    /* stub */
}

__attribute__((weak)) void uGUICharacterSelect::updateSave() {
    DDON_STUB("uGUICharacterSelect::updateSave")
    /* stub */
}

__attribute__((weak)) void uGUICharacterSelect::updateClanMenu() {
    DDON_STUB("uGUICharacterSelect::updateClanMenu")
    /* stub */
}

__attribute__((weak)) void uGUICharacterSelect::createNameList(u32 num) {
    DDON_STUB("uGUICharacterSelect::createNameList")
    /* stub */
}

__attribute__((weak)) void uGUICharacterSelect::createHorizonInfo(u32 num) {
    DDON_STUB("uGUICharacterSelect::createHorizonInfo")
    /* stub */
}

__attribute__((weak)) void uGUICharacterSelect::adjustControl() {
    DDON_STUB("uGUICharacterSelect::adjustControl")
    /* stub */
}

__attribute__((weak)) void uGUICharacterSelect::updateInit() {
    DDON_STUB("uGUICharacterSelect::updateInit")
    /* stub */
}

__attribute__((weak)) void uGUICharacterSelect::updateWait() {
    DDON_STUB("uGUICharacterSelect::updateWait")
    /* stub */
}

__attribute__((weak)) void uGUICharacterSelect::updateError() {
    DDON_STUB("uGUICharacterSelect::updateError")
    /* stub */
}

__attribute__((weak)) void uGUICharacterSelect::updateExit() {
    DDON_STUB("uGUICharacterSelect::updateExit")
    /* stub */
}

u32 uGUICharacterSelect::evCtrlVMove(cControl::Message* msg) {
    adjustControl();
    setInputEvent(74u);
    return 0;
}

__attribute__((weak)) u32 uGUICharacterSelect::evCtrlVMoveEx(cControl::Message* msg) {
    DDON_STUB("uGUICharacterSelect::evCtrlVMoveEx")
    return {};
}

__attribute__((weak)) u32 uGUICharacterSelect::evCtrlDecide(cControl::Message* msg) {
    DDON_STUB("uGUICharacterSelect::evCtrlDecide")
    return {};
}

u32 uGUICharacterSelect::evCtrlDecideDeleteButton(cControl::Message* msg) {
    setInputEvent(76u);
    return 0;
}

u32 uGUICharacterSelect::evCtrlCancel(cControl::Message* msg) {
    if (mProc == PR_DELETE_COMPLETE) {
        setInputEvent(73u);
    } else {
        setInputEvent(67u);
    }
    return 0;
}

__attribute__((weak)) u32 uGUICharacterSelect::evCtrlStart(cControl::Message* msg) {
    DDON_STUB("uGUICharacterSelect::evCtrlStart")
    return {};
}

__attribute__((weak)) u32 uGUICharacterSelect::evCtrlTopButton(cControl::Message* msg) {
    DDON_STUB("uGUICharacterSelect::evCtrlTopButton")
    return {};
}

__attribute__((weak)) u32 uGUICharacterSelect::evCtrlPageMove(cControl::Message* msg) {
    DDON_STUB("uGUICharacterSelect::evCtrlPageMove")
    return {};
}

__attribute__((weak)) void uGUICharacterSelect::addUnderHelp(nKeyCustom::KB_CUSTOM type, MT_CTSTR msg) {
    DDON_STUB("uGUICharacterSelect::addUnderHelp")
    /* stub */
}

__attribute__((weak)) void uGUICharacterSelect::updateUnderHelp() {
    DDON_STUB("uGUICharacterSelect::updateUnderHelp")
    /* stub */
}

inline uGUICharacterSelect::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICharacterSelect::MyDTI uGUICharacterSelect::DTI("uGUICharacterSelect", &::uGUIsMenuBase::DTI, 5408ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUICharacterSelect::MyDTI::newInstance() const {
    DDON_STUB("uGUICharacterSelect::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUICharacterSelect::cGUINameList::getDTI() const {
    return uGUICharacterSelect::cGUINameList::DTI;
}

inline uGUICharacterSelect::cGUINameList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICharacterSelect::cGUINameList::MyDTI uGUICharacterSelect::cGUINameList::DTI("uGUICharacterSelect::cGUINameList", &::MtObject::DTI, 192ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUICharacterSelect::cGUINameList::MyDTI::newInstance() const {
    DDON_STUB("uGUICharacterSelect::cGUINameList::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUICharacterSelect::cHorizonInfo::getDTI() const {
    return uGUICharacterSelect::cHorizonInfo::DTI;
}

inline uGUICharacterSelect::cHorizonInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICharacterSelect::cHorizonInfo::MyDTI uGUICharacterSelect::cHorizonInfo::DTI("uGUICharacterSelect::cHorizonInfo", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* uGUICharacterSelect::cHorizonInfo::MyDTI::newInstance() const {
    return new (16u) uGUICharacterSelect::cHorizonInfo;
}

const MtDTI& uGUICharacterSelect::cGUIGPList::getDTI() const {
    return uGUICharacterSelect::cGUIGPList::DTI;
}

inline uGUICharacterSelect::cGUIGPList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICharacterSelect::cGUIGPList::MyDTI uGUICharacterSelect::cGUIGPList::DTI("uGUICharacterSelect::cGUIGPList", &::MtObject::DTI, 80ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUICharacterSelect::cGUIGPList::MyDTI::newInstance() const {
    DDON_STUB("uGUICharacterSelect::cGUIGPList::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUICharacterSelect::cGUIUnderHelpMsg::getDTI() const {
    return uGUICharacterSelect::cGUIUnderHelpMsg::DTI;
}

inline uGUICharacterSelect::cGUIUnderHelpMsg::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUICharacterSelect::cGUIUnderHelpMsg::MyDTI uGUICharacterSelect::cGUIUnderHelpMsg::DTI("uGUICharacterSelect::cGUIUnderHelpMsg", &::MtObject::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUICharacterSelect::cGUIUnderHelpMsg::MyDTI::newInstance() const {
    DDON_STUB("uGUICharacterSelect::cGUIUnderHelpMsg::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<uGUIBase::cReferenceUIChargesInfo>::~MtTypedArray();

template MtTypedArray<uGUICharacterSelect::cGUIGPList>::~MtTypedArray();

template MtTypedArray<uGUICharacterSelect::cGUINameList>::~MtTypedArray();

template MtTypedArray<uGUICharacterSelect::cGUIUnderHelpMsg>::~MtTypedArray();

template MtTypedArray<uGUICharacterSelect::cHorizonInfo>::~MtTypedArray();

