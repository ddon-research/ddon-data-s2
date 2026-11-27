// Reconstructed from the game's DWARF debug information.
#include <new>
#include "aInit.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "aBase.h"
#include "../../XFramework/cArea.h"
#include "cAreaExt.h"
#include "cSystemCheck.h"
#include "rArchiveListArray.h"
#include "sArchiveManager.h"
#include "../../XFramework/sArea.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "sInputManager.h"
#include "../../XFramework/sPad.h"
#include "sPadExt.h"
#include "../../XFramework/sSavedata.h"
#include "sSavedataExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& aInit::getDTI() const {
    return aInit::DTI;
}

aInit::~aInit() {
}

__attribute__((weak)) bool aInit::load() {
    DDON_STUB("aInit::load")
    return {};
}

void aInit::init() {
    static_cast<sSavedataExt*>(sSavedata::getInstance())->settingSaveDataConfig();
    mSystemCheck.loadResource();
    mSystemCheck.init();
}

__attribute__((weak)) void aInit::move() {
    DDON_STUB("aInit::move")
    /* stub */
}

void aInit::final() {
    this->cAreaExt::final();
    mSystemCheck.releaseResource();
    cArcLoaderBase* const t0 = sArchiveManager::INVALID_TICKET;
    if (mArcTicket == t0) {
        return;
    }
    sArchiveManager::getInstance()->returnTicket(mArcTicket);
    mArcTicket = t0;
}

const MtDTI& aInit::getParentType() {
    return aBase::DTI;
}

MT_CTSTR aInit::getShaderSegment() {
    return "root";
}

inline aInit::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

aInit::MyDTI aInit::DTI("aInit", &::cAreaExt::DTI, 112ul, 0u, 0u);

__attribute__((weak)) MtObject* aInit::MyDTI::newInstance() const {
    DDON_STUB("aInit::MyDTI::newInstance")
    return nullptr;
}

