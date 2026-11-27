// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cZoneCategoryLight.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cZoneContents.h"
#include "uSkyFog.h"
#include "uSkyLight.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

inline void* cZoneCategoryDayNightHemiSphere::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cZoneCategoryDayNightHemiSphere::DTI)->memAlloc(sz, align, ::cZoneCategoryDayNightHemiSphere::DTI.getID());
}
inline cZoneCategoryDayNightHemiSphere::cZoneCategoryDayNightHemiSphere() {
}

inline void* cZoneCategoryDayNightColorFog::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cZoneCategoryDayNightColorFog::DTI)->memAlloc(sz, align, ::cZoneCategoryDayNightColorFog::DTI.getID());
}
inline cZoneCategoryDayNightColorFog::cZoneCategoryDayNightColorFog() {
}

const MtDTI& cZoneCategoryDayNightColorFog::getDTI() const {
    return cZoneCategoryDayNightColorFog::DTI;
}

u32 cZoneCategoryDayNightColorFog::getCategoryType() const {
    return 2;
}

void cZoneCategoryDayNightColorFog::createProperty(MtPropertyList& s) {
    this->cZoneContents::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "DayFogParam", static_cast<MtObject*>(&mDayParam), 4u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "NightFogParam", static_cast<MtObject*>(&mNightParam), 4u, 0u);
}

inline cZoneCategoryDayNightColorFog::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneCategoryDayNightColorFog::MyDTI cZoneCategoryDayNightColorFog::DTI("cZoneCategoryDayNightColorFog", &::cZoneCategoryLight::DTI, 256ul, 0u, 0u);

__attribute__((weak)) MtObject* cZoneCategoryDayNightColorFog::MyDTI::newInstance() const {
    return new (16u) ::cZoneCategoryDayNightColorFog;
}

const MtDTI& cZoneCategoryDayNightHemiSphere::getDTI() const {
    return cZoneCategoryDayNightHemiSphere::DTI;
}

u32 cZoneCategoryDayNightHemiSphere::getCategoryType() const {
    return 1;
}

void cZoneCategoryDayNightHemiSphere::createProperty(MtPropertyList& s) {
    this->cZoneContents::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "DayHemiParam", static_cast<MtObject*>(&mDayParam), 4u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "NightHemiParam", static_cast<MtObject*>(&mNightParam), 4u, 0u);
}

inline cZoneCategoryDayNightHemiSphere::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneCategoryDayNightHemiSphere::MyDTI cZoneCategoryDayNightHemiSphere::DTI("cZoneCategoryDayNightHemiSphere", &::cZoneCategoryLight::DTI, 192ul, 0u, 0u);

__attribute__((weak)) MtObject* cZoneCategoryDayNightHemiSphere::MyDTI::newInstance() const {
    return new (16u) ::cZoneCategoryDayNightHemiSphere;
}

const MtDTI& cZoneCategoryLight::getDTI() const {
    return cZoneCategoryLight::DTI;
}

u32 cZoneCategoryLight::getCategoryType() const {
    return 0;
}

inline cZoneCategoryLight::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneCategoryLight::MyDTI cZoneCategoryLight::DTI("cZoneCategoryLight", &::cZoneContents::DTI, 32ul, 0u, 0u);

MtObject* cZoneCategoryLight::MyDTI::newInstance() const {
    return new (16u) cZoneCategoryLight;
}

