// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uSkyLight.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "nWeather.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

inline void* cDayNightLightParam::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cDayNightLightParam::DTI)->memAlloc(sz, align, ::cDayNightLightParam::DTI.getID());
}

const MtDTI& cDayNightLightParam::getDTI() const {
    return cDayNightLightParam::DTI;
}

inline void cDayNightLightParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cDayNightLightParam::DTI)->memFree(p_addr);
}

cDayNightLightParam::cDayNightLightParam() {
    mLightColor = MtVector3::One;
    mRevColor = MtVector3::Zero;
    mLightDir = MtVector3::AxisY;
    mLightShadowAtten.x = 1.0f;
    mLightShadowAtten.y = 0.0f;
}

__attribute__((weak)) void cDayNightLightParam::lerp(const cDayNightLightParam& a, const cDayNightLightParam& b, f32 rate) {
    DDON_STUB("cDayNightLightParam::lerp")
    /* stub */
}

void cDayNightLightParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mLightColor", &mLightColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRevColor", &mRevColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLightDir", &mLightDir, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "LightShadowGroup0", &mLightShadowAtten.x, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "LightShadowGroup1", &mLightShadowAtten.y, 0u, 0u);
}

inline cDayNightLightParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cDayNightLightParam::MyDTI cDayNightLightParam::DTI("cDayNightLightParam", &::cWeatherObjectRes::DTI, 80ul, 0u, 0u);

__attribute__((weak)) MtObject* cDayNightLightParam::MyDTI::newInstance() const {
    return new (16u) ::cDayNightLightParam;
}

