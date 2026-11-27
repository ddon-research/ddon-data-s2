// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpEnemyEffect.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"
#include "cpComponent.h"
#include "cpEffectProvider.h"
#include "cpEffectStatusManager.h"
#include "rEmEffectTable.h"
#include "rTable.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "uDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpEnemyEffect::getDTI() const {
    return cpEnemyEffect::DTI;
}

void* cpEnemyEffect::operator new(size_t sz, u32 align) {
    return cpEnemyEffect::getAllocator()->memAlloc(sz, align, cpEnemyEffect::DTI.getID());
}

cpEnemyEffect::cpEnemyEffect() {
    mpEmEffectTableRes = nullptr;
}

cpEnemyEffect::~cpEnemyEffect() {
    if (mpEmEffectTableRes == nullptr) {
        return;
    }
    mpEmEffectTableRes->release();
    mpEmEffectTableRes = nullptr;
}

void cpEnemyEffect::setup() {
    this->cpComponent::setup();
}

void cpEnemyEffect::updatePtr() {
    this->cpComponent::updatePtr();
}

__attribute__((weak)) void cpEnemyEffect::setResource(rEmEffectTable* pRes) {
    DDON_STUB("cpEnemyEffect::setResource")
    /* stub */
}

void cpEnemyEffect::playEffectResTableIdx(u32 idx) {
    if (mpEmEffectTableRes != nullptr) {
        if (mpEmEffectTableRes->getDataNum() != 0) {
            for (unsigned int i0_3 = 0;;) {
                MtObject* t0 = mpEmEffectTableRes->getDataBase(i0_3);
                if (t0 != nullptr) {
                    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(t0) + 8)) == idx) {
                        playEffect(static_cast<const cEmEffectTable*>(t0));
                    }
                }
                if ((i0_3 + 1u) < mpEmEffectTableRes->getDataNum()) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
}

__attribute__((weak)) bool cpEnemyEffect::playEffect(const cEmEffectTable* pEmEffectTable) {
    DDON_STUB("cpEnemyEffect::playEffect")
    return {};
}

inline cpEnemyEffect::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpEnemyEffect::MyDTI cpEnemyEffect::DTI("cpEnemyEffect", &::cpComponent::DTI, 88ul, 0u, 0u);

MtObject* cpEnemyEffect::MyDTI::newInstance() const {
    return new (16u) cpEnemyEffect;
}

