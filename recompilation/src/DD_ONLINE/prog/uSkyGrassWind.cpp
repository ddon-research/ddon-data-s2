// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uSkyGrassWind.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "sWeatherManager.h"
#include "../../XFramework/uGrassWind.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uSkyGrassWind::getDTI() const {
    return uSkyGrassWind::DTI;
}

void* uSkyGrassWind::operator new(size_t sz, u32 align) {
    return uSkyGrassWind::getAllocator()->memAlloc(sz, align, uSkyGrassWind::DTI.getID());
}

uSkyGrassWind::~uSkyGrassWind() {
}

__attribute__((weak)) void uSkyGrassWind::move() {
    DDON_STUB("uSkyGrassWind::move")
    /* stub */
}

inline uSkyGrassWind::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uSkyGrassWind::MyDTI uSkyGrassWind::DTI("uSkyGrassWind", &::uGrassWindDirection::DTI, 4192ul, 0u, 0u);

__attribute__((weak)) MtObject* uSkyGrassWind::MyDTI::newInstance() const {
    DDON_STUB("uSkyGrassWind::MyDTI::newInstance")
    return nullptr;
}

