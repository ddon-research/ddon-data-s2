// Reconstructed from the game's DWARF debug information.
#include <new>
#include <libsysmodule.h>
#include "sMovie.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "cSystem.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sMovie::getDTI() const {
    return sMovie::DTI;
}

void* sMovie::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(sMovie::DTI)->memAlloc(sz, align, sMovie::DTI.mID);
}

sMovie::sMovie(MtAllocator* palloc, u32 work_mem_size) {
    sMovie::mpInstance = this;
    sceSysmoduleLoadModule(static_cast<uint16_t>(165));
}

sMovie::~sMovie() {
    sceSysmoduleUnloadModule(static_cast<uint16_t>(165));
    sMovie::mpInstance = nullptr;
}

MtUI* sMovie::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

void sMovie::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
}

__attribute__((weak)) void sMovie::move() {
}

inline sMovie::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sMovie::MyDTI sMovie::DTI("sMovie", &::cSystem::DTI, 24ul, 0u, 0u);

sMovie* sMovie::mpInstance;

__attribute__((weak)) MtObject* sMovie::MyDTI::newInstance() const {
    DDON_STUB("sMovie::MyDTI::newInstance")
    return nullptr;
}

