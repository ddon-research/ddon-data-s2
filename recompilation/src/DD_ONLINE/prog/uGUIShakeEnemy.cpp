// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIShakeEnemy.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sPlayerManager.h"
#include "uDDOModel.h"
#include "uGUIBase.h"
#include "uHuman.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIShakeEnemy::getDTI() const {
    return uGUIShakeEnemy::DTI;
}

void* uGUIShakeEnemy::operator new(size_t sz, u32 align) {
    return uGUIShakeEnemy::getAllocator()->memAlloc(sz, align, uGUIShakeEnemy::DTI.getID());
}

uGUIShakeEnemy::~uGUIShakeEnemy() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

bool uGUIShakeEnemy::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_GAUGE_SHAKE_GUI"), 129u, 1473821653l))) == nullptr)) {
        return false;
    }
    return true;
}

__attribute__((weak)) void uGUIShakeEnemy::setup() {
    DDON_STUB("uGUIShakeEnemy::setup")
    /* stub */
}

void uGUIShakeEnemy::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIShakeEnemy::updateInit() {
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIShakeEnemy::updateWait);
}

void uGUIShakeEnemy::updateWait() {
    updateDisp();
}

__attribute__((weak)) void uGUIShakeEnemy::updateDisp() {
    if (mpInstNullD == nullptr || mpInstButton == nullptr) {
        return;
    }
    
    bool is_visible = false;
    uHuman* pPlayer = sPlayerManager::getInstance()->getMyPlayer();
    constexpr u32 t5 = 0x3590;
    // workaround
    if (pPlayer != nullptr && *reinterpret_cast<const uHuman::CLIMB_JOLT_TYPE*>(
            reinterpret_cast<const char*>(pPlayer) + t5) != uHuman::CLIMB_JOLT_NONE) {
        uDDOModel* pModel = pPlayer->getClimbEnemy();
        if (pModel != nullptr && pModel->mIsEnemy) {
            is_visible = true;
            if (mInputGuideMonitor.checkUpdate()) {
                nGUIExt::StringKeyCustomIconTag t1;
                cGUIUtility::getIconTag(t1, static_cast<nKeyCustom::KB_CUSTOM>(0x17),
                    cGUIUtility::ICON_TAG_OUT_TYPE_ALL, cGUIUtility::ICON_TAG_JOINT_TYPE_PLUS, 0u);
                if (mpOBJ_btn_m_btn_txt != nullptr) {
                    // workaround
                    mpOBJ_btn_m_btn_txt->setMessage(reinterpret_cast<const char*>(&t1) + sizeof(u32),
                        *reinterpret_cast<const u32*>(&t1));
                }
            }
        }
    }
    
    mpInstNullD->setVisible(is_visible);
    mpInstNullD->setExecute(is_visible);
    
    constexpr u32 t6 = 0x10;
    // workaround
    u32& t2 = *reinterpret_cast<u32*>(reinterpret_cast<char*>(this) + t6);
    u32 t3 = t2;
    u32 t4 = t3 & 0x4807u;
    t2 = !is_visible ? (t3 & ~0x800u) : (t3 | 0x800u);
    if (t4 == 0x4802u && (t2 & 0x4807u) != 0x4802u) {
        callbackChangeVisibleTrueToFalse();
    }
}

inline uGUIShakeEnemy::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIShakeEnemy::MyDTI uGUIShakeEnemy::DTI("uGUIShakeEnemy", &::uGUIBase::DTI, 2304ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIShakeEnemy::MyDTI::newInstance() const {
    DDON_STUB("uGUIShakeEnemy::MyDTI::newInstance")
    return nullptr;
}

