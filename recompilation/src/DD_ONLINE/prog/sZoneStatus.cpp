// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sZoneStatus.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtSynchronize.h"
#include "../../XFramework/cAIObject.h"
#include "../../XFramework/cSystem.h"
#include "cZoneCategoryStatus.h"
#include "../../XFramework/cZoneContents.h"
#include "../../XFramework/cZoneListener.h"
#include "cZoneListenerMulti.h"
#include "nDDOUtility.h"
#include "../../XFramework/nZone.h"
#include "sNpcManager.h"
#include "sPlayerManager.h"
#include "sUnitManager.h"
#include "../../XFramework/uBaseModel.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "uNpc.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sZoneStatus::getDTI() const {
    return sZoneStatus::DTI;
}

void* sZoneStatus::operator new(size_t sz, u32 align) {
    return sZoneStatus::getAllocator()->memAlloc(sz, align, sZoneStatus::DTI.getID());
}

sZoneStatus::sZoneStatus() {
    DDON_STUB("sZoneStatus::sZoneStatus")
    /* stub */
}

sZoneStatus::~sZoneStatus() {
    DDON_STUB("sZoneStatus::~sZoneStatus")
    /* stub */
}

__attribute__((weak)) void sZoneStatus::move() {
    DDON_STUB("sZoneStatus::move")
    /* stub */
}

void sZoneStatus::reset() {
    mZoneStatusStack.releaseZoneAll();
}

u32 sZoneStatus::addZoneStatus(rZone* pZone, const MtVector3& pos) {
    return mZoneStatusStack.addZone(pZone, pos);
}

void sZoneStatus::eraseZoneStatus(u32 handle) {
    mZoneStatusStack.releaseZone(handle);
}

void sZoneStatus::releaseZoneStatus() {
    mZoneStatusStack.releaseZoneAll();
}

__attribute__((weak)) bool sZoneStatus::updateZoneStatus(uHuman* pChar) {
    DDON_STUB("sZoneStatus::updateZoneStatus")
    return {};
}

__attribute__((weak)) bool sZoneStatus::callbackNotified(uHuman* pChar, const nZone::cLayoutElement& e) {
    DDON_STUB("sZoneStatus::callbackNotified")
    return {};
}

inline sZoneStatus::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sZoneStatus::MyDTI sZoneStatus::DTI("sZoneStatus", &::cSystem::DTI, 72ul, 0u, 0u);

sZoneStatus* sZoneStatus::mpInstance;

__attribute__((weak)) MtObject* sZoneStatus::MyDTI::newInstance() const {
    DDON_STUB("sZoneStatus::MyDTI::newInstance")
    return nullptr;
}

