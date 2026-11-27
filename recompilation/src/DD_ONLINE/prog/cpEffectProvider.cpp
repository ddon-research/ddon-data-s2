// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cpEffectProvider.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cDelegate.h"
#include "cEfcMotSync.h"
#include "../../XFramework/cResource.h"
#include "cpComponent.h"
#include "rEffectProvider.h"
#include "uDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cpEffectProvider::getDTI() const {
    return cpEffectProvider::DTI;
}

void* cpEffectProvider::operator new(size_t sz, u32 align) {
    return cpEffectProvider::getAllocator()->memAlloc(sz, align, cpEffectProvider::DTI.getID());
}

cpEffectProvider::cpEffectProvider() {
    memset(static_cast<void*>(&mprResource[0]), 0, 256ul);
}

cpEffectProvider::~cpEffectProvider() {
    DDON_STUB("cpEffectProvider::~cpEffectProvider")
    /* stub */
}

__attribute__((weak)) void cpEffectProvider::setup() {
    DDON_STUB("cpEffectProvider::setup")
    /* stub */
}

void cpEffectProvider::after() {
    if (mpOwner != nullptr) {
        for (u32 i = 0; i != 16; i = i + 1u) {
            if (mpMotSync[i] != nullptr) {
                mpMotSync[i]->cEfcMotSync::moveSync(static_cast<uDDOModel*>(mpOwner));
            }
        }
    }
}

void cpEffectProvider::updatePtr() {
    this->cpComponent::updatePtr();
}

void cpEffectProvider::createProperty(MtPropertyList& s) {
    this->cpComponent::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mprResource", "resource", static_cast<void*>(&mprResource[0]), 32u, 16u);
}

__attribute__((weak)) void cpEffectProvider::setResource(rEffectProvider* pRes, cpEffectProvider::EPV_TYPE Type) {
    DDON_STUB("cpEffectProvider::setResource")
    /* stub */
}

void cpEffectProvider::releaseResource(cpEffectProvider::EPV_TYPE Type) {
    if (mprResource[Type] != nullptr) {
        mprResource[Type]->cResource::release();
        mprResource[Type] = nullptr;
    }
    if (mpMotSync[Type] == nullptr) {
        return;
    }
    delete mpMotSync[Type];
    mpMotSync[Type] = nullptr;
}

rEffectProvider* cpEffectProvider::getResource(cpEffectProvider::EPV_TYPE type) {
    return mprResource[type];
}

inline cpEffectProvider::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpEffectProvider::MyDTI cpEffectProvider::DTI("cpEffectProvider", &::cpComponent::DTI, 336ul, 0u, 0u);

MtObject* cpEffectProvider::MyDTI::newInstance() const {
    return new (16u) cpEffectProvider;
}

