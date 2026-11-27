// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cZoneListenerEffect.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cZoneCategoryEffectExt.h"
#include "../../XFramework/cZoneContents.h"
#include "../../XFramework/cZoneListener.h"
#include "../../XFramework/nZone.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cZoneListenerEffect::getDTI() const {
    return cZoneListenerEffect::DTI;
}

MtVector3 cZoneListenerEffect::myPos() {
    return mCheckPos;
}

inline cZoneListenerEffect::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneListenerEffect::MyDTI cZoneListenerEffect::DTI("cZoneListenerEffect", &::cZoneListener::DTI, 64ul, 0u, 0u);

MtObject* cZoneListenerEffect::MyDTI::newInstance() const {
    return new (16u) cZoneListenerEffect;
}

const MtDTI& cZoneListenerEffectColor::getDTI() const {
    return cZoneListenerEffectColor::DTI;
}

cZoneListenerEffectColor::cZoneListenerEffectColor() {
    DDON_STUB("cZoneListenerEffectColor::cZoneListenerEffectColor")
    /* stub */
}

__attribute__((weak)) void cZoneListenerEffectColor::notified(const nZone::cLayoutElement& e) {
    DDON_STUB("cZoneListenerEffectColor::notified")
    /* stub */
}

const MtColor& cZoneListenerEffectColor::getColor() const {
    return mColor;
}

f32 cZoneListenerEffectColor::getColorBlend() const {
    return mColorBlend;
}

f32 cZoneListenerEffectColor::getIntensity() const {
    return mIntensity;
}

f32 cZoneListenerEffectColor::getIntensityBlend() const {
    return mIntensityBlend;
}

const MtColor& cZoneListenerEffectColor::getShadowColor() const {
    return mShadowColor;
}

f32 cZoneListenerEffectColor::getShadowColorBlend() const {
    return mShadowColorBlend;
}

f32 cZoneListenerEffectColor::getShadowIntensity() const {
    return mShadowIntensity;
}

f32 cZoneListenerEffectColor::getShadowIntensityBlend() const {
    return mShadowIntensityBlend;
}

f32 cZoneListenerEffectColor::getEnvMapPowerScale() const {
    return mEnvMapPowerScale;
}

inline cZoneListenerEffectColor::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneListenerEffectColor::MyDTI cZoneListenerEffectColor::DTI("cZoneListenerEffectColor", &::cZoneListenerEffect::DTI, 112ul, 0u, 0u);

__attribute__((weak)) MtObject* cZoneListenerEffectColor::MyDTI::newInstance() const {
    DDON_STUB("cZoneListenerEffectColor::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cZoneListenerEffectEFL::getDTI() const {
    return cZoneListenerEffectEFL::DTI;
}

cZoneListenerEffectEFL::cZoneListenerEffectEFL() {
    DDON_STUB("cZoneListenerEffectEFL::cZoneListenerEffectEFL")
    /* stub */
}

cZoneListenerEffectEFL::~cZoneListenerEffectEFL() {
    for (u32 i = 0; i != 32; i = i + 1u) {
        if (mpResourceSet[i] != nullptr) {
            delete mpResourceSet[i];
            mpResourceSet[i] = nullptr;
        }
    }
}

__attribute__((weak)) void cZoneListenerEffectEFL::notified(const nZone::cLayoutElement& e) {
    DDON_STUB("cZoneListenerEffectEFL::notified")
    /* stub */
}

MtVector3 cZoneListenerEffectEFL::myPos() {
    return mCheckPos;
}

void cZoneListenerEffectEFL::resetParam() {
    mpElement = nullptr;
    mCheckPos.x = MtVector3::Zero.x;
    mCheckPos.y = MtVector3::Zero.y;
    mCheckPos.z = MtVector3::Zero.z;
    mCheckPos.pad_ = 0.0f;
    for (u32 i = 0; i != 32; i = i + 1u) {
        if (mpResourceSet[i] != nullptr) {
            delete mpResourceSet[i];
            mpResourceSet[i] = nullptr;
        }
    }
}

s32 cZoneListenerEffectEFL::getLayoutIndex() const {
    if (mpElement != nullptr) {
        return static_cast<s32>(mpElement->getIndex());
    } else {
        return -1;
    }
}

const nZone::cLayoutElement* cZoneListenerEffectEFL::getLayoutElement() const {
    return mpElement;
}

inline cZoneListenerEffectEFL::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneListenerEffectEFL::MyDTI cZoneListenerEffectEFL::DTI("cZoneListenerEffectEFL", &::cZoneListener::DTI, 336ul, 0u, 0u);

__attribute__((weak)) MtObject* cZoneListenerEffectEFL::MyDTI::newInstance() const {
    DDON_STUB("cZoneListenerEffectEFL::MyDTI::newInstance")
    return nullptr;
}

