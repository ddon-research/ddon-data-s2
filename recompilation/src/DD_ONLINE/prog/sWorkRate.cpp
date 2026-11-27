// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sWorkRate.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cSystem.h"
#include "../../XFramework/sMain.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sWorkRate::getDTI() const {
    return sWorkRate::DTI;
}

void* sWorkRate::operator new(size_t sz, u32 align) {
    return sWorkRate::getAllocator()->memAlloc(sz, align, sWorkRate::DTI.getID());
}

sWorkRate::sWorkRate() {
    DDON_STUB("sWorkRate::sWorkRate")
    /* stub */
}

sWorkRate::~sWorkRate() {
}

__attribute__((weak)) void sWorkRate::move() {
    DDON_STUB("sWorkRate::move")
    /* stub */
}

void sWorkRate::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mRate", &mRate[0], 32u, 6u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoveTimer", &mMoveTimer[0], 32u, 6u);
    s << MtProperty(static_cast<MtObject*>(this), "mPrio", &mPrio[0], 32u, 6u);
}

__attribute__((weak)) f32 sWorkRate::calc(u32 bit) {
    DDON_STUB("sWorkRate::calc")
    return {};
}

__attribute__((weak)) f32 sWorkRate::calcRaw(u32 bit) {
    DDON_STUB("sWorkRate::calcRaw")
    return {};
}

inline sWorkRate::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sWorkRate::MyDTI sWorkRate::DTI("sWorkRate", &::cSystem::DTI, 96ul, 0u, 0u);

sWorkRate* sWorkRate::mpInstance;

__attribute__((weak)) MtObject* sWorkRate::MyDTI::newInstance() const {
    DDON_STUB("sWorkRate::MyDTI::newInstance")
    return nullptr;
}

