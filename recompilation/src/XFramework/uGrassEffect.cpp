// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGrassEffect.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cResource.h"
#include "cUnit.h"
#include "rGrassWind.h"
#include "sMain.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGrassEffect::getDTI() const {
    return uGrassEffect::DTI;
}

inline void uGrassEffect::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uGrassEffect::DTI)->memFree(p_addr);
}

uGrassEffect::uGrassEffect(u32 Priority) {
    DDON_STUB("uGrassEffect::uGrassEffect")
    /* stub */
}

uGrassEffect::~uGrassEffect() {
    if (mpResource == nullptr) {
        return;
    }
    mpResource->release();
    mpResource = nullptr;
}

void uGrassEffect::createProperty(MtPropertyList& s) {
    this->cUnit::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mpResource", "resource", reinterpret_cast<MT_MFUNC>(&::uGrassEffect::getResource), reinterpret_cast<MT_MFUNC>(&::uGrassEffect::setResource), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "Priority", reinterpret_cast<MT_MFUNC>(&::uGrassEffect::getPriority), reinterpret_cast<MT_MFUNC>(&::uGrassEffect::setPriority), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MtUI* uGrassEffect::createUI(MtProperty& prop) {
    return this->cUnit::createUI(prop);
}

void uGrassEffect::setup() {
    if (mpResource == nullptr) {
        return;
    }
    mSync.synchronization(static_cast<cUnit*>(this), mpResource);
}

u32 uGrassEffect::getPriority() const {
    return mPriority;
}

void uGrassEffect::setPriority(u32 priority) {
    mPriority = priority;
}

void uGrassEffect::setResource(rGrassWind* p_resource) {
    if (mpResource != nullptr) {
        mpResource->release();
        mpResource = nullptr;
    }
    if (p_resource == nullptr) {
        return;
    }
    mpResource = p_resource;
    p_resource->addRef();
    mSync.synchronization(static_cast<cUnit*>(this), mpResource);
    mPriority = mpResource->mPriority;
}

rGrassWind* uGrassEffect::getResource() {
    return mpResource;
}

void uGrassEffect::play() {
    if (mpResource == nullptr) {
        return;
    }
    mSync.play((sMain::mpInstance)->mDeltaTime * mSpeed);
}

inline uGrassEffect::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGrassEffect::MyDTI uGrassEffect::DTI("uGrassEffect", &::cUnit::DTI, 3968ul, 0u, 1u);

MtObject* uGrassEffect::MyDTI::newInstance() const {
    return nullptr;
}

