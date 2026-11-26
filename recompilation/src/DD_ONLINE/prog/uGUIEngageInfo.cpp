// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIEngageInfo.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cGUIObject.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/nGUI.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sSoundManager.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIEngageInfo::getDTI() const {
    return uGUIEngageInfo::DTI;
}

inline MtAllocator* uGUIEngageInfo::getAllocator() {
    return MtMemoryAllocator::getAllocator(uGUIEngageInfo::DTI);
}

void* uGUIEngageInfo::operator new(size_t sz, u32 align) {
    return uGUIEngageInfo::getAllocator()->memAlloc(sz, align, uGUIEngageInfo::DTI.getID());
}

inline void uGUIEngageInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGUIEngageInfo::DTI)->memFree(p_addr);
}

uGUIEngageInfo::uGUIEngageInfo() : uGUIBase(0u, false) {
    mpOBJ_msg_enemy_m_enemy = nullptr;
    mpGUIRes = nullptr;
    mBaseF = mBaseF | 32u;
    mEndType = 1;
    setArcTag(rArchiveListArray::convTagId("uGUIEngageInfo"), 0u, false);
}

uGUIEngageInfo::~uGUIEngageInfo() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

bool uGUIEngageInfo::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_ENEMY_ENGAGE_GUI"), 129u, 1400142948l))) == nullptr)) {
        return false;
    }
    return true;
}

void uGUIEngageInfo::setup() {
    this->uGUIBase::setup();
    if (!mIsEndLoadResource) {
        return;
    }
    setPriority(static_cast<sGUIExt*>(sGUI::getInstance())->issuePriority(7u), true);
    setPlay(true);
    MT_CTSTR t0 = static_cast<sGUIExt*>(sGUI::getInstance())->getMsgFromIdxInfo(static_cast<sGUIExt*>(sGUI::getInstance())->getMsgHud(), 29u);
    cGUIObject* t1 = getObjectFromId(2u, 3u);
    mpOBJ_msg_enemy_m_enemy = static_cast<cGUIObjMessage*>(t1);
    setObjectMessage(t1, t0, 0u, false);
    setFlowAndInit(2u, false);
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIEngageInfo::updateInit);
}

void uGUIEngageInfo::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIEngageInfo::updateInit() {
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIEngageInfo::updateWait);
}

void uGUIEngageInfo::updateWait() {
    nGUI::FLOW* pFlow = getPlayingFlow();
    sBattleState::SYS_BATTLE_STATE state = sSoundManager::getInstance()->getBattleState();
    if (state == sBattleState::SYS_STATE_BATTLE) {
        if (sGame::getInstance()->mCharData.mCharData.mOption.mIsEngageDisp) {
            if (pFlow == nullptr) {
                setPlay(true);
            }
        } else {
            if (pFlow != nullptr) {
                if (pFlow->id == 3) {
                    if (isEndFlowAnimation(false)) {
                        setFlowAndInit(5u, false);
                    }
                }
            }
        }
    } else {
        if (pFlow != nullptr) {
            if (pFlow->id == 3) {
                if (isEndFlowAnimation(false)) {
                    setFlowAndInit(5u, false);
                }
            }
        }
    }
}

inline uGUIEngageInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIEngageInfo::MyDTI uGUIEngageInfo::DTI("uGUIEngageInfo", &::uGUIBase::DTI, 2272ul, 0u, 0u);

MtObject* uGUIEngageInfo::MyDTI::newInstance() const {
    return new (16u) uGUIEngageInfo;
}

