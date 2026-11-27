// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpEnemyLocalShel.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cComponentManager.h"
#include "cDelegate.h"
#include "../../XFramework/cResource.h"
#include "cThinkMgr.h"
#include "cpComponent.h"
#include "cpShlShotCtrl.h"
#include "cpStatusCheck.h"
#include "rEnemyLocalShelTable.h"
#include "uDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpEnemyLocalShel::getDTI() const {
    return cpEnemyLocalShel::DTI;
}

void* cpEnemyLocalShel::operator new(size_t sz, u32 align) {
    return cpEnemyLocalShel::getAllocator()->memAlloc(sz, align, cpEnemyLocalShel::DTI.getID());
}

cpEnemyLocalShel::cpEnemyLocalShel() {
    DDON_STUB("cpEnemyLocalShel::cpEnemyLocalShel")
    /* stub */
}

cpEnemyLocalShel::~cpEnemyLocalShel() {
    DDON_STUB("cpEnemyLocalShel::~cpEnemyLocalShel")
    /* stub */
}

__attribute__((weak)) void cpEnemyLocalShel::setup() {
    DDON_STUB("cpEnemyLocalShel::setup")
    /* stub */
}

void cpEnemyLocalShel::updatePtr() {
    this->cpComponent::updatePtr();
}

void cpEnemyLocalShel::compMoveAfter() {
    if (!mActive) {
        return;
    }
    mcSyncFlag.mSyncFlagOld = mcSyncFlag.mSyncFlag;
    mcSyncFlag.mSyncFlag = 0;
}

__attribute__((weak)) void cpEnemyLocalShel::setResource(rEnemyLocalShelTable* pRes) {
    DDON_STUB("cpEnemyLocalShel::setResource")
    /* stub */
}

void cpEnemyLocalShel::playResTableIdx(u32 idx) {
    if (mpEnemyLocalShelTableRes != nullptr) {
        if (mpEnemyLocalShelTableRes->getDataNum() != 0) {
            for (unsigned int i0_3 = 0;;) {
                cEnemyLocalShelTable* t0 = mpEnemyLocalShelTableRes->getData(i0_3);
                if (t0 != nullptr) {
                    if (t0->mIdx == idx) {
                        play(t0);
                    }
                }
                if ((i0_3 + 1u) < mpEnemyLocalShelTableRes->getDataNum()) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
}

__attribute__((weak)) bool cpEnemyLocalShel::play(const cEnemyLocalShelTable* pEmShelTable) {
    DDON_STUB("cpEnemyLocalShel::play")
    return {};
}

inline cpEnemyLocalShel::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpEnemyLocalShel::MyDTI cpEnemyLocalShel::DTI("cpEnemyLocalShel", &::cpComponent::DTI, 96ul, 0u, 0u);

__attribute__((weak)) MtObject* cpEnemyLocalShel::MyDTI::newInstance() const {
    DDON_STUB("cpEnemyLocalShel::MyDTI::newInstance")
    return nullptr;
}

