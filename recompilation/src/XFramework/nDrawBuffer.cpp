// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nDrawBuffer.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPropertyList.h"
#include "nDrawResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nDraw::Buffer::getDTI() const {
    return nDraw::Buffer::DTI;
}

nDraw::Buffer::Buffer(nDraw::USAGE_TYPE usage) {
    mUsageType = usage;
    mBufSize = 0;
    mpBuffer = nullptr;
    mDirty = false;
}

__attribute__((weak)) void nDraw::Buffer::resume() {
}

static auto ddon_emit_0x01b82c90 __attribute__((used)) = &nDraw::Buffer::getUsageType;

__attribute__((weak)) void nDraw::Buffer::createProperty(MtPropertyList& s) {
    DDON_STUB("nDraw::Buffer::createProperty")
    /* stub */
}

MtUI* nDraw::Buffer::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

nDraw::Buffer::~Buffer() {
}

inline nDraw::Buffer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nDraw::Buffer::MyDTI nDraw::Buffer::DTI("nDraw::Buffer", &::nDraw::Resource::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* nDraw::Buffer::MyDTI::newInstance() const {
    DDON_STUB("nDraw::Buffer::MyDTI::newInstance")
    return nullptr;
}

