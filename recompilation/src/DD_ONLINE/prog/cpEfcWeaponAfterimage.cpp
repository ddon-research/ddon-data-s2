// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpEfcWeaponAfterimage.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cComponentManager.h"
#include "cEfcHandle.h"
#include "cEquipData.h"
#include "../../XFramework/cUnit.h"
#include "cpComponent.h"
#include "cpEquip.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "uDDOModel.h"
#include "uWeapon.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpEfcWeaponAfterimage::getDTI() const {
    return cpEfcWeaponAfterimage::DTI;
}

void* cpEfcWeaponAfterimage::operator new(size_t sz, u32 align) {
    return cpEfcWeaponAfterimage::getAllocator()->memAlloc(sz, align, cpEfcWeaponAfterimage::DTI.getID());
}

cpEfcWeaponAfterimage::cpEfcWeaponAfterimage() {
    DDON_STUB("cpEfcWeaponAfterimage::cpEfcWeaponAfterimage")
    /* stub */
}

cpEfcWeaponAfterimage::~cpEfcWeaponAfterimage() {
}

void cpEfcWeaponAfterimage::move() {
    if (mpWeaponRight == nullptr) {
        static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(&mEfcHandleRight, 3u);
    }
    if (mpWeaponLeft == nullptr) {
        static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(&mEfcHandleLeft, 3u);
    }
}

void cpEfcWeaponAfterimage::updatePtr() {
    this->cpComponent::updatePtr();
    if (mpWeaponRight != nullptr) {
        if (!mpWeaponRight->isEnable()) {
            mpWeaponRight = nullptr;
        }
    }
    if (mpWeaponLeft == nullptr) {
        return;
    }
    if (mpWeaponLeft->isEnable()) {
        return;
    }
    mpWeaponLeft = nullptr;
}

__attribute__((weak)) void cpEfcWeaponAfterimage::updateEfcHandle() {
    DDON_STUB("cpEfcWeaponAfterimage::updateEfcHandle")
    /* stub */
}

__attribute__((weak)) void cpEfcWeaponAfterimage::callbackSequenceTrigger(cpSequenceCtrl* pSeqCtrl, u32 page, u32 bit, u16 work) {
    DDON_STUB("cpEfcWeaponAfterimage::callbackSequenceTrigger")
    /* stub */
}

__attribute__((weak)) void cpEfcWeaponAfterimage::callbackSequenceRelease(cpSequenceCtrl* pSeqCtrl, u32 page, u32 bit, u16 work) {
    DDON_STUB("cpEfcWeaponAfterimage::callbackSequenceRelease")
    /* stub */
}

void cpEfcWeaponAfterimage::callbackSetMotion(u32 blend, u32 mot_no, f32 hokan, f32 frame, f32 speed, u32 attr) {
    static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(&mEfcHandleRight, 1u);
    static_cast<sEffectExt*>(sEffect::getInstance())->endEffect(&mEfcHandleLeft, 1u);
}

inline cpEfcWeaponAfterimage::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpEfcWeaponAfterimage::MyDTI cpEfcWeaponAfterimage::DTI("cpEfcWeaponAfterimage", &::cpComponent::DTI, 160ul, 0u, 0u);

__attribute__((weak)) MtObject* cpEfcWeaponAfterimage::MyDTI::newInstance() const {
    DDON_STUB("cpEfcWeaponAfterimage::MyDTI::newInstance")
    return nullptr;
}

