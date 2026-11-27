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
    const cShlParamTarasukuLight* pParam = static_cast<const cShlParamTarasukuLight*>(pParamBase);
    
    cShlParamSpeed::copy(pParamBase);
    isSpecifyTargetPos = pParam->isSpecifyTargetPos;
    hmgRad = pParam->hmgRad;
    hmgRadFrame = pParam->hmgRadFrame;
    hmgBgnDist = pParam->hmgBgnDist;
    hmgEndTargetDist = pParam->hmgEndTargetDist;
    hmgEndRad = pParam->hmgEndRad;
    hmgEndFrame = pParam->hmgEndFrame;
    hmgEndWaitHmgRad = pParam->hmgEndWaitHmgRad;
    hmgEndWaitSpdMax = pParam->hmgEndWaitSpdMax;
    hmgEndWaitEndFrame = pParam->hmgEndWaitEndFrame;
    hmgEndHmgRad = pParam->hmgEndHmgRad;
    hmgEndSpdMax = pParam->hmgEndSpdMax;
    hmgType = pParam->hmgType;
    hmInitSpd = pParam->hmInitSpd;
    hmAccel = pParam->hmAccel;
    hmMaxSpped = pParam->hmMaxSpped;
    hmHmgRad = pParam->hmHmgRad;
    hmEndTargetDist = pParam->hmEndTargetDist;
    hmEndRad = pParam->hmEndRad;
    hmRotate = pParam->hmRotate;
    hmIsRotateRndFlip = pParam->hmIsRotateRndFlip;
    seNoHoming = pParam->seNoHoming;
    homingSeDeg = pParam->homingSeDeg;
    
    if (hmgEndFrame <= 0.0f)
        hmgEndFrame = -1.0f;
    
    mOffsetY = pParam->mOffsetY;
    mGroundLength = pParam->mGroundLength;
}

inline cShlParamTarasukuLight::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamTarasukuLight::MyDTI cShlParamTarasukuLight::DTI("cShlParamTarasukuLight", &::cShlParamHoming::DTI, 592ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamTarasukuLight::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamTarasukuLight::DTI)->memAlloc(sizeof(cShlParamTarasukuLight), 16u, cShlParamTarasukuLight::DTI.getID())) cShlParamTarasukuLight;
}

const MtDTI& uShlTarasukuLight::getDTI() const {
    return uShlTarasukuLight::DTI;
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

