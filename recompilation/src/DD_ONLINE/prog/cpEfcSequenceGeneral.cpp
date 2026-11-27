// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpEfcSequenceGeneral.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cEfcHandle.h"
#include "cpComponent.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "uDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpEfcSequenceGeneral::getDTI() const {
    return cpEfcSequenceGeneral::DTI;
}

void* cpEfcSequenceGeneral::operator new(size_t sz, u32 align) {
    return cpEfcSequenceGeneral::getAllocator()->memAlloc(sz, align, cpEfcSequenceGeneral::DTI.getID());
}

cpEfcSequenceGeneral::cpEfcSequenceGeneral() {
    DDON_STUB("cpEfcSequenceGeneral::cpEfcSequenceGeneral")
    /* stub */
}

cpEfcSequenceGeneral::~cpEfcSequenceGeneral() {
}

__attribute__((weak)) void cpEfcSequenceGeneral::updateEfcHandle() {
    DDON_STUB("cpEfcSequenceGeneral::updateEfcHandle")
    /* stub */
}

void cpEfcSequenceGeneral::callbackSequenceTrigger(cpSequenceCtrl* pSeqCtrl, u32 page, u32 bit, u16 work) {
    if (page != 2) {
        return;
    }
    MtObject* t0 = getOwner();
    if (bit == 8) {
        sEffect* t1 = sEffect::getInstance();
        static_cast<sEffectExt*>(t1)->setSequenceGeneralEffect(static_cast<uDDOModel*>(t0), work, 53u, &mEfcHandle[1]);
    } else {
        if (bit == 7) {
            sEffect* t2 = sEffect::getInstance();
            static_cast<sEffectExt*>(t2)->setSequenceGeneralEffect(static_cast<uDDOModel*>(t0), work, 52u, &mEfcHandle[0]);
        }
    }
}

void cpEfcSequenceGeneral::callbackSequenceRelease(cpSequenceCtrl* pSeqCtrl, u32 page, u32 bit, u16 work) {
    if (page != 2) {
        return;
    }
    if (bit == 8) {
        static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(&mEfcHandle[1], 1u);
    } else {
        if (bit == 7) {
            static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(&mEfcHandle[0], 1u);
        }
    }
}

void cpEfcSequenceGeneral::callbackSetMotion(u32 blend, u32 mot_no, f32 hokan, f32 frame, f32 speed, u32 attr) {
    static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(&mEfcHandle[0], 1u);
    static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(&mEfcHandle[1], 1u);
}

inline cpEfcSequenceGeneral::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpEfcSequenceGeneral::MyDTI cpEfcSequenceGeneral::DTI("cpEfcSequenceGeneral", &::cpComponent::DTI, 144ul, 0u, 0u);

__attribute__((weak)) MtObject* cpEfcSequenceGeneral::MyDTI::newInstance() const {
    DDON_STUB("cpEfcSequenceGeneral::MyDTI::newInstance")
    return nullptr;
}

