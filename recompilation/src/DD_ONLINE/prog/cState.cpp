// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cState.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "cContextInterface.h"
#include "cContextPlayerInfo.h"
#include "cGUIUtility.h"
#include "cNetGameServer.h"
#include "../../XFramework/cUnit.h"
#include "cpActionManager.h"
#include "cpActionRequest.h"
#include "cpOcdCtrl.h"
#include "cpReturnTerritory.h"
#include "cpStateManager.h"
#include "nDDOUtility.h"
#include "../../XFramework/rGUIMessage.h"
#include "sChat.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sQuestManagerExt.h"
#include "sSetManager.h"
#include "../../XFramework/uBaseModel.h"
#include "uDDOModel.h"
#include "uHuman.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cState::getDTI() const {
    return cState::DTI;
}

cState::cState() {
    mpModel = nullptr;
    mStateNo = -1;
    mNextState = -1;
}

cState::~cState() {
}

void cState::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mStateNo", &mStateNo, 0u, 0u);
}

MtUI* cState::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void cState::init() {
}

__attribute__((weak)) void cState::move() {
}

__attribute__((weak)) void cState::final() {
}

inline cState::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cState::MyDTI cState::DTI("cState", &::MtObject::DTI, 24ul, 0u, 1u);

MtObject* cState::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& cStateAction::getDTI() const {
    return cStateAction::DTI;
}

cStateAction::cStateAction() {
    mDefaultShrinkAction = 0xFFFFFFFF;
    mDefaultFallAction = 0xFFFFFFFF;
    mDefaultBlowAction = 0xFFFFFFFF;
    mDefaultEndAction = 0xFFFFFFFF;
    mDefaultLandAction = 0xFFFFFFFF;
}

__attribute__((weak)) void cStateAction::createProperty(MtPropertyList& s) {
    DDON_STUB("cStateAction::createProperty")
    /* stub */
}

inline cStateAction::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cStateAction::MyDTI cStateAction::DTI("cStateAction", &::cState::DTI, 48ul, 0u, 0u);

MtObject* cStateAction::MyDTI::newInstance() const {
    return new (16u) cStateAction;
}

const MtDTI& cStateInfo::getDTI() const {
    return cStateInfo::DTI;
}

void* cStateInfo::operator new(size_t sz, u32 align) {
    return cStateInfo::getAllocator()->memAlloc(sz, align, cStateInfo::DTI.getID());
}

inline cStateInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cStateInfo::MyDTI cStateInfo::DTI("cStateInfo", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cStateInfo::MyDTI::newInstance() const {
    return new (16u) cStateInfo;
}

inline cStateLive::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cStateLive::MyDTI cStateLive::DTI("cStateLive", &::cState::DTI, 24ul, 0u, 1u);

MtObject* cStateLive::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& cStateLiveAlive::getDTI() const {
    return cStateLiveAlive::DTI;
}

inline cStateLiveAlive::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cStateLiveAlive::MyDTI cStateLiveAlive::DTI("cStateLiveAlive", &::cStateLive::DTI, 24ul, 0u, 0u);

MtObject* cStateLiveAlive::MyDTI::newInstance() const {
    return new (16u) cStateLiveAlive;
}

const MtDTI& cStateLiveInjured::getDTI() const {
    return cStateLiveInjured::DTI;
}

__attribute__((weak)) void cStateLiveInjured::init() {
    DDON_STUB("cStateLiveInjured::init")
    /* stub */
}

__attribute__((weak)) void cStateLiveInjured::move() {
    DDON_STUB("cStateLiveInjured::move")
    /* stub */
}

void cStateLiveInjured::final() {
    mpModel->clearTouchType(nDDOModel::TOUCH_NONE);
    if ((mpModel->mUnitId & 16u) == 0) {
        return;
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(mpModel) + 10007) = 1;
}

__attribute__((weak)) void cStateLiveInjured::addInjurePlayer(u32 newId) {
    DDON_STUB("cStateLiveInjured::addInjurePlayer")
    /* stub */
}

__attribute__((weak)) f32 cStateLiveInjured::checkIsInjured() {
    DDON_STUB("cStateLiveInjured::checkIsInjured")
    return {};
}

void cStateLiveInjured::checkAbility() {
    for (unsigned int i0_9 = 0; i0_9 != 8; i0_9 = i0_9 + 1u) {
        if (mUniqueId.elems[i0_9] != 0) {
            uBaseModel* pUnit = sSetManager::getInstance()->getLayoutUnit(mUniqueId.elems[i0_9]);
            if (pUnit != nullptr) {
                if (pUnit->isEnable()) {
                    if (static_cast<uDDOModel*>(pUnit)->isHuman()) {
                        if (static_cast<uHuman*>(pUnit)->getContextPlayerInfo() != nullptr) {
                            s32 frame60;
                            s32 frame64;
                            if (static_cast<uHuman*>(pUnit)->getContextPlayerInfo()->checkAbility(nAbility::ABILITY_0055, frame60, frame64, 0u)) {
                                mpModel->catchAbnormalCondition(1u, static_cast<float>(frame64), nObjCondition::OCD_REASON_NONE, -1.0f, false, nObjCondition::IMMUNE_BOOST_LV_INVALID);
                            }
                            uHuman* pHu = static_cast<uHuman*>(pUnit);
                            s32 frame68;
                            s32 frame72;
                            if (pHu->getContextPlayerInfo()->checkAbility(nAbility::ABILITY_0056, frame68, frame72, 0u)) {
                                mpModel->catchAbnormalCondition(3u, static_cast<float>(frame72), nObjCondition::OCD_REASON_NONE, -1.0f, false, nObjCondition::IMMUNE_BOOST_LV_INVALID);
                            }
                            s32 frame76;
                            s32 frame80;
                            if (pHu->getContextPlayerInfo()->checkAbility(nAbility::ABILITY_0057, frame76, frame80, 0u)) {
                                mpModel->catchAbnormalCondition(2u, static_cast<float>(frame80), nObjCondition::OCD_REASON_NONE, -1.0f, false, nObjCondition::IMMUNE_BOOST_LV_INVALID);
                            }
                            s32 frame84;
                            s32 frame88;
                            if (pHu->getContextPlayerInfo()->checkAbility(nAbility::ABILITY_0058, frame84, frame88, 0u)) {
                                mpModel->catchAbnormalCondition(4u, static_cast<float>(frame88), nObjCondition::OCD_REASON_NONE, -1.0f, false, nObjCondition::IMMUNE_BOOST_LV_INVALID);
                            }
                            s32 frame92;
                            s32 frame96;
                            if (pHu->getContextPlayerInfo()->checkAbility(nAbility::ABILITY_0059, frame92, frame96, 0u)) {
                                mpModel->catchAbnormalCondition(18u, static_cast<float>(frame96), nObjCondition::OCD_REASON_NONE, -1.0f, false, nObjCondition::IMMUNE_BOOST_LV_INVALID);
                            }
                            s32 frame100;
                            s32 frame104;
                            if (pHu->getContextPlayerInfo()->checkAbility(nAbility::ABILITY_0424, frame100, frame104, 0u)) {
                                mpModel->catchAbnormalCondition(19u, static_cast<float>(frame104), nObjCondition::OCD_REASON_NONE, -1.0f, false, nObjCondition::IMMUNE_BOOST_LV_INVALID);
                            }
                        }
                    }
                }
            }
        }
    }
}

inline cStateLiveInjured::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cStateLiveInjured::MyDTI cStateLiveInjured::DTI("cStateLiveInjured", &::cStateLive::DTI, 80ul, 0u, 0u);

MtObject* cStateLiveInjured::MyDTI::newInstance() const {
    return new (16u) cStateLiveInjured;
}

const MtDTI& cStateLiveLost::getDTI() const {
    return cStateLiveLost::DTI;
}

__attribute__((weak)) void cStateLiveLost::init() {
    DDON_STUB("cStateLiveLost::init")
    /* stub */
}

__attribute__((weak)) void cStateLiveLost::move() {
    DDON_STUB("cStateLiveLost::move")
    /* stub */
}

void cStateLiveLost::final() {
    mpModel->clearTouchType(nDDOModel::TOUCH_NONE);
    if ((mpModel->mUnitId & 16u) == 0) {
        return;
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(mpModel) + 10007) = 1;
}

inline cStateLiveLost::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cStateLiveLost::MyDTI cStateLiveLost::DTI("cStateLiveLost", &::cStateLive::DTI, 32ul, 0u, 0u);

MtObject* cStateLiveLost::MyDTI::newInstance() const {
    return new (16u) cStateLiveLost;
}

const MtDTI& cStateLiveLostEnd::getDTI() const {
    return cStateLiveLostEnd::DTI;
}

void cStateLiveLostEnd::init() {
    sGame::getInstance()->reqPawnTalkLost(mpModel);
}

void cStateLiveLostEnd::move() {
    if ((mpModel->mUnitId & 64u) == 0) {
        return;
    }
    if (mpModel->getActMgrPtr() == nullptr) {
        return;
    }
    if (!mpModel->getActMgrPtr()->isEndAction()) {
        return;
    }
    sGame::getInstance()->lostPawn(mpModel);
}

__attribute__((weak)) void cStateLiveLostEnd::final() {
}

inline cStateLiveLostEnd::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cStateLiveLostEnd::MyDTI cStateLiveLostEnd::DTI("cStateLiveLostEnd", &::cStateLive::DTI, 24ul, 0u, 0u);

MtObject* cStateLiveLostEnd::MyDTI::newInstance() const {
    return new (16u) cStateLiveLostEnd;
}

const MtDTI& cStateLiveReturnTerritory::getDTI() const {
    return cStateLiveReturnTerritory::DTI;
}

__attribute__((weak)) void cStateLiveReturnTerritory::init() {
    DDON_STUB("cStateLiveReturnTerritory::init")
    /* stub */
}

__attribute__((weak)) void cStateLiveReturnTerritory::move() {
    DDON_STUB("cStateLiveReturnTerritory::move")
    /* stub */
}

__attribute__((weak)) void cStateLiveReturnTerritory::final() {
}

__attribute__((weak)) void cStateLiveReturnTerritory::createProperty(MtPropertyList& s) {
    DDON_STUB("cStateLiveReturnTerritory::createProperty")
    /* stub */
}

inline cStateLiveReturnTerritory::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cStateLiveReturnTerritory::MyDTI cStateLiveReturnTerritory::DTI("cStateLiveReturnTerritory", &::cStateLive::DTI, 32ul, 0u, 0u);

MtObject* cStateLiveReturnTerritory::MyDTI::newInstance() const {
    return new (16u) cStateLiveReturnTerritory;
}

