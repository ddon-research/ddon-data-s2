// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sSyncPoint.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cSystem.h"
#include "nSyncPoint.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sSyncPoint::getDTI() const {
    return sSyncPoint::DTI;
}

void* sSyncPoint::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(sSyncPoint::DTI)->memAlloc(sz, align, sSyncPoint::DTI.mID);
}

sSyncPoint::sSyncPoint() {
    DDON_STUB("sSyncPoint::sSyncPoint")
    /* stub */
}

sSyncPoint::~sSyncPoint() {
    DDON_STUB("sSyncPoint::~sSyncPoint")
    /* stub */
}

MtUI* sSyncPoint::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

void sSyncPoint::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "Pool size", &sSyncPoint::MAX_CALLBACK_POOL, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCallbackInfo", static_cast<MtObject*>(&mCallbackInfo[0]), 35u, 6u);
}

__attribute__((weak)) bool sSyncPoint::init(u32 sizeBuffer) {
    DDON_STUB("sSyncPoint::init")
    return {};
}

__attribute__((weak)) void sSyncPoint::updateStatus(nSyncPoint::eSyncPoint sp) {
    DDON_STUB("sSyncPoint::updateStatus")
    /* stub */
}

inline sSyncPoint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sSyncPoint::MyDTI sSyncPoint::DTI("sSyncPoint", &::cSystem::DTI, 168ul, 0u, 0u);

u32 sSyncPoint::MAX_CALLBACK_POOL;

sSyncPoint* sSyncPoint::mpInstance;

__attribute__((weak)) MtObject* sSyncPoint::MyDTI::newInstance() const {
    DDON_STUB("sSyncPoint::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& sSyncPoint::syncPointElement::getDTI() const {
    return sSyncPoint::syncPointElement::DTI;
}

sSyncPoint::syncPointElement::~syncPointElement() {
}

void sSyncPoint::syncPointElement::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mCallbackWPtr", &mCallbackWPtr, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCallbackRPtr", &mCallbackRPtr, 0u, 0u);
}

inline sSyncPoint::syncPointElement::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sSyncPoint::syncPointElement::MyDTI sSyncPoint::syncPointElement::DTI("sSyncPoint::syncPointElement", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* sSyncPoint::syncPointElement::MyDTI::newInstance() const {
    return new (16u) sSyncPoint::syncPointElement;
}

