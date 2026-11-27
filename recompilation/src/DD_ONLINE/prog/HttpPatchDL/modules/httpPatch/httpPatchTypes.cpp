// Reconstructed from the game's DWARF debug information.
#include <new>
#include "httpPatchTypes.h"
#include "../../../../../MT/MtAllocator.h"
#include "../../../../../MT/MtDTI.h"
#include "../../../../../MT/MtMemoryAllocator.h"
#include "../../../../../MT/MtObject.h"
#include "../../../../../MT/MtString.h"
#include "utility/hash.h"
#include "httpPatch.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& via::module::http_patch::ParallelsFileData::getDTI() const {
    return via::module::http_patch::ParallelsFileData::DTI;
}

void* via::module::http_patch::ParallelsFileData::operator new[](size_t sz, u32 align) {
    return ::via::module::http_patch::ParallelsFileData::getAllocator()->memAlloc(sz, align, ::via::module::http_patch::ParallelsFileData::DTI.getID());
}

__attribute__((weak)) void via::module::http_patch::ParallelsFileData::operator delete(void* p_addr) {
    ::via::module::http_patch::ParallelsFileData::getAllocator()->memFree(p_addr);
}

void via::module::http_patch::ParallelsFileData::operator delete[](void* p_addr) {
    ::via::module::http_patch::ParallelsFileData::getAllocator()->memFree(p_addr);
}

inline via::module::http_patch::ParallelsFileData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

via::module::http_patch::ParallelsFileData::MyDTI via::module::http_patch::ParallelsFileData::DTI("ParallelsFileData", &::MtObject::DTI, 376ul, 0u, 0u);

__attribute__((weak)) MtObject* via::module::http_patch::ParallelsFileData::MyDTI::newInstance() const {
    DDON_STUB("via::module::http_patch::ParallelsFileData::MyDTI::newInstance")
    return nullptr;
}

