// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rShaderCache.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtString.h"
#include "cResource.h"
#include "nDrawShader.h"
#include "sShader2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rShaderCache::getDTI() const {
    return rShaderCache::DTI;
}

MT_CTSTR rShaderCache::getExt() const {
    return "sch";
}

rShaderCache::~rShaderCache() {
    MtMemoryAllocator::getAllocator(rShaderCache::DTI)->memFree(static_cast<void*>(mpHeader));
}

__attribute__((weak)) bool rShaderCache::remappingShaderKey(nDraw::SHADER_KEY* pskey) {
    DDON_STUB("rShaderCache::remappingShaderKey")
    return {};
}

__attribute__((weak)) bool rShaderCache::load(MtStream& in) {
    DDON_STUB("rShaderCache::load")
    return {};
}

inline rShaderCache::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rShaderCache::MyDTI rShaderCache::DTI("rShaderCache", &::cResource::DTI, 120ul, 0u, 0u);

MtObject* rShaderCache::MyDTI::newInstance() const {
    return new (16u) rShaderCache;
}

