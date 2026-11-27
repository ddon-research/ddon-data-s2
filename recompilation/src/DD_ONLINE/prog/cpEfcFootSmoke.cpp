// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpEfcFootSmoke.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cpComponent.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "uDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpEfcFootSmoke::getDTI() const {
    return cpEfcFootSmoke::DTI;
}

void* cpEfcFootSmoke::operator new(size_t sz, u32 align) {
    return cpEfcFootSmoke::getAllocator()->memAlloc(sz, align, cpEfcFootSmoke::DTI.getID());
}

cpEfcFootSmoke::cpEfcFootSmoke() {
}

cpEfcFootSmoke::~cpEfcFootSmoke() {
}

void cpEfcFootSmoke::updatePtr() {
    this->cpComponent::updatePtr();
}

void cpEfcFootSmoke::callbackSequenceTrigger(cpSequenceCtrl* pSeqCtrl, u32 page, u32 bit, u16 work) {
    if (page != 2) {
        return;
    }
    if ((((bit - 2u) <= 3u) ? (bit - 2u) : 0xFFFFFFFFu) == 0xFFFFFFFFu) {
        return;
    }
    static_cast<sEffectExt*>(sEffect::getInstance())->setFootSmokeEffect(static_cast<uDDOModel*>(getOwner()), ((bit - 2u) <= 3u) ? (bit - 2u) : 0xFFFFFFFFu, static_cast<MtTypedArray<cEfcHandle>*>(nullptr));
}

inline cpEfcFootSmoke::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpEfcFootSmoke::MyDTI cpEfcFootSmoke::DTI("cpEfcFootSmoke", &::cpComponent::DTI, 80ul, 0u, 0u);

MtObject* cpEfcFootSmoke::MyDTI::newInstance() const {
    return new (16u) cpEfcFootSmoke;
}

