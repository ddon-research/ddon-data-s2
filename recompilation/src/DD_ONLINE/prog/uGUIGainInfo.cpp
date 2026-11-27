// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIGainInfo.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "../../XFramework/nGUI.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIGainInfo::getDTI() const {
    return uGUIGainInfo::DTI;
}

void* uGUIGainInfo::operator new(size_t sz, u32 align) {
    return uGUIGainInfo::getAllocator()->memAlloc(sz, align, uGUIGainInfo::DTI.getID());
}

uGUIGainInfo::uGUIGainInfo() : uGUIBase(0u, false) {
    mData1 = 0;
    mWait = 0.0f;
    mType = 0;
    mData0 = 0;
    mpObjMsgText1 = nullptr;
    mpObjMsgText0 = nullptr;
    mpInstAnimText1 = nullptr;
    mpInstAnimText0 = nullptr;
    mpInstNullBonus = nullptr;
    mpInstNullAll = nullptr;
    mpGUIRes = nullptr;
    mWaitMax = 2.0f;
    mNullBonusPosY = 0.0f;
    mIsSleep = false;
    mBaseF = mBaseF | 32u;
    mEndType = 1;
    setArcTag(rArchiveListArray::convTagId("uGUIGainInfo"), 0u, false);
}

uGUIGainInfo::~uGUIGainInfo() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

bool uGUIGainInfo::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_NUMBER00_GUI"), 129u, 1414745402l))) == nullptr)) {
        return false;
    }
    return true;
}

void uGUIGainInfo::setup() {
    this->uGUIBase::setup();
    if (!mIsEndLoadResource) {
        return;
    }
    setPriority(static_cast<sGUIExt*>(sGUI::getInstance())->issuePriority(12u), true);
    setPlay(false);
    mpInstNullAll = static_cast<cGUIInstNull*>(getInstance(16u, false));
    mpInstNullBonus = static_cast<cGUIInstNull*>(getInstance(13u, false));
    mpInstAnimText0 = static_cast<cGUIInstAnimation*>(getInstance(8u, false));
    mpInstAnimText1 = static_cast<cGUIInstAnimation*>(getInstance(11u, false));
    mpObjMsgText0 = static_cast<cGUIObjMessage*>(getObjectFromId(8u, 21u));
    mpObjMsgText1 = static_cast<cGUIObjMessage*>(getObjectFromId(11u, 21u));
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGainInfo::updateSleep);
}

void uGUIGainInfo::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

bool uGUIGainInfo::isEndAnimation() {
    nGUI::FLOW* pFlow = getPlayingFlow();
    if (pFlow != nullptr) {
        return pFlow->id == 2;
    } else {
        return false;
    }
}

__attribute__((weak)) void uGUIGainInfo::setSleep(bool bSleep) {
    DDON_STUB("uGUIGainInfo::setSleep")
    /* stub */
}

__attribute__((weak)) void uGUIGainInfo::updateSleep() {
}

void uGUIGainInfo::updateInit() {
    static const u32 type_table[8] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        3,
    };
    static const u32 se_table[8] = {
        203,
        201,
        202,
        204,
        205,
        207,
        206,
        1,
    };
    if (mType <= 7u) {
        static_cast<sGUIExt*>(sGUI::getInstance())->requestSE(type_table[mType], se_table[mType]);
    }
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGainInfo::updateIn);
}

void uGUIGainInfo::updateIn() {
    nGUI::FLOW* t0 = getPlayingFlow();
    if (t0 != getFlow(3u)) {
        return;
    }
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGainInfo::updateWait);
}

void uGUIGainInfo::updateWait() {
    mWait = getDeltaTime() + mWait;
    if (mWait > (sMain::getInstance()->getFps() * mWaitMax)) {
        setFlowAndInit(5u, false);
        mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGainInfo::updateOut);
    }
}

__attribute__((weak)) void uGUIGainInfo::updateOut() {
}

inline uGUIGainInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIGainInfo::MyDTI uGUIGainInfo::DTI("uGUIGainInfo", &::uGUIBase::DTI, 2336ul, 0u, 0u);

MtObject* uGUIGainInfo::MyDTI::newInstance() const {
    return new (16u) uGUIGainInfo;
}

