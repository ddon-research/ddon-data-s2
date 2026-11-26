// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlTarasukuLight.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/sCollision.h"
#include "sCollisionExt.h"
#include "uShlBase.h"
#include "uShlHoming.h"
#include "uShlSpeed.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamTarasukuLight::getDTI() const {
    return cShlParamTarasukuLight::DTI;
}

inline void cShlParamTarasukuLight::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamTarasukuLight::DTI)->memFree(p_addr);
}

MtDTI& cShlParamTarasukuLight::getShlDTI() const {
    return uShlTarasukuLight::DTI;
}

cShlParamTarasukuLight::~cShlParamTarasukuLight() {
}

void cShlParamTarasukuLight::createProperty(MtPropertyList& s) {
    this->cShlParamHoming::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mOffsetY", &mOffsetY, 0u, 0u);
}

__attribute__((weak)) void cShlParamTarasukuLight::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamTarasukuLight::copy")
    /* stub */
}

inline cShlParamTarasukuLight::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamTarasukuLight::MyDTI cShlParamTarasukuLight::DTI("cShlParamTarasukuLight", &::cShlParamHoming::DTI, 592ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamTarasukuLight::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamTarasukuLight::DTI)->memAlloc(sizeof(cShlParamTarasukuLight), 16u, cShlParamTarasukuLight::DTI.getID())) cShlParamTarasukuLight;
}

const MtDTI& uShlTarasukuLight::getDTI() const {
    return uShlTarasukuLight::DTI;
}

inline void* uShlTarasukuLight::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uShlTarasukuLight::DTI)->memAlloc(sz, align, uShlTarasukuLight::DTI.getID());
}

inline void uShlTarasukuLight::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uShlTarasukuLight::DTI)->memFree(p_addr);
}

inline const cShlParamTarasukuLight* uShlTarasukuLight::getShlParam() const {
    return static_cast<const cShlParamTarasukuLight*>(mpShlParam2);
}

uShlTarasukuLight::~uShlTarasukuLight() {
    DDON_STUB("uShlTarasukuLight::~uShlTarasukuLight")
    /* stub */
}

__attribute__((weak)) void uShlTarasukuLight::updateSub() {
    DDON_STUB("uShlTarasukuLight::updateSub")
    /* stub */
}

inline uShlTarasukuLight::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlTarasukuLight::MyDTI uShlTarasukuLight::DTI("uShlTarasukuLight", &::uShlHoming::DTI, 11232ul, 0u, 0u);

MtObject* uShlTarasukuLight::MyDTI::newInstance() const {
    return new (16u) uShlTarasukuLight;
}

