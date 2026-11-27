// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpEnemySound.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"
#include "cpComponent.h"
#include "cpMotionSe.h"
#include "rEmSoundTable.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "uDDOModel.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpEnemySound::getDTI() const {
    return cpEnemySound::DTI;
}

void* cpEnemySound::operator new(size_t sz, u32 align) {
    return cpEnemySound::getAllocator()->memAlloc(sz, align, cpEnemySound::DTI.getID());
}

cpEnemySound::cpEnemySound() {
    mpEmSoundTableRes = nullptr;
}

cpEnemySound::~cpEnemySound() {
    if (mpEmSoundTableRes == nullptr) {
        return;
    }
    mpEmSoundTableRes->release();
    mpEmSoundTableRes = nullptr;
}

void cpEnemySound::setup() {
    this->cpComponent::setup();
}

void cpEnemySound::updatePtr() {
    this->cpComponent::updatePtr();
}

__attribute__((weak)) void cpEnemySound::setResource(rEmSoundTable* pRes) {
    DDON_STUB("cpEnemySound::setResource")
    /* stub */
}

void cpEnemySound::playSoundIdx(u32 idx) {
    if (mpEmSoundTableRes != nullptr) {
        if (mpEmSoundTableRes->getDataNum() != 0) {
            for (unsigned int i0_3 = 0;;) {
                cEmSoundTable* t0 = mpEmSoundTableRes->getData(i0_3);
                if (t0 != nullptr) {
                    if (t0->mIdx == idx) {
                        playSound(t0);
                    }
                }
                if ((i0_3 + 1u) < mpEmSoundTableRes->getDataNum()) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
}

__attribute__((weak)) bool cpEnemySound::playSound(const cEmSoundTable* pEmSoundTable) {
    DDON_STUB("cpEnemySound::playSound")
    return {};
}

inline cpEnemySound::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpEnemySound::MyDTI cpEnemySound::DTI("cpEnemySound", &::cpComponent::DTI, 88ul, 0u, 0u);

MtObject* cpEnemySound::MyDTI::newInstance() const {
    return new (16u) cpEnemySound;
}

