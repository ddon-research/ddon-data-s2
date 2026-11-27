// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpEfcTouchDownSmoke.h"
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

const MtDTI& cpEfcTouchDownSmoke::getDTI() const {
    return cpEfcTouchDownSmoke::DTI;
}

void* cpEfcTouchDownSmoke::operator new(size_t sz, u32 align) {
    return cpEfcTouchDownSmoke::getAllocator()->memAlloc(sz, align, cpEfcTouchDownSmoke::DTI.getID());
}

cpEfcTouchDownSmoke::cpEfcTouchDownSmoke() {
}

cpEfcTouchDownSmoke::~cpEfcTouchDownSmoke() {
}

void cpEfcTouchDownSmoke::updatePtr() {
    this->cpComponent::updatePtr();
}

void cpEfcTouchDownSmoke::callbackSequenceTrigger(cpSequenceCtrl* pSeqCtrl, u32 page, u32 bit, u16 work) {
    if (page != 2) {
        return;
    }
    if (bit != 6) {
        return;
    }
    static_cast<sEffectExt*>(sEffect::getInstance())->setTouchDownSmokeEffect(static_cast<uDDOModel*>(getOwner()));
}

inline cpEfcTouchDownSmoke::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpEfcTouchDownSmoke::MyDTI cpEfcTouchDownSmoke::DTI("cpEfcTouchDownSmoke", &::cpComponent::DTI, 80ul, 0u, 0u);

MtObject* cpEfcTouchDownSmoke::MyDTI::newInstance() const {
    return new (16u) cpEfcTouchDownSmoke;
}

