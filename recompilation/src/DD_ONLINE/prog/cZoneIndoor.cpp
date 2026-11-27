// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cZoneIndoor.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOMath.h"
#include "uSoundTrigger.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

inline void* cZoneIndoorLight::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cZoneIndoorLight::DTI)->memAlloc(sz, align, ::cZoneIndoorLight::DTI.getID());
}
inline cZoneIndoorLight::cZoneIndoorLight() {
    mLightInfiniteRate = 1.0f;
    mLightHemiRateDay = 0.5f;
    mLightHemiRateDayRev = 0.5f;
    mLightHemiRateNight = 2.0f;
    mLightHemiRateNightRev = 2.0f;
    mLightSubRateDay = 2.0f;
    mLightSubRateNight = 2.0f;
    mUseSkyFogParam = false;
    mSkyColorFogUseFrame = 30.0f;
}

const MtDTI& cIndoorSkyFogParam::getDTI() const {
    return cIndoorSkyFogParam::DTI;
}

cIndoorSkyFogParam::cIndoorSkyFogParam() {
    mWeatherId = 0;
    mIntensity = 1.0f;
    mDensity = 1.0f;
    mStart = 1000.0f;
    mEnd = 3000.0f;
    mId = 0;
}

void cIndoorSkyFogParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mWeatherId", &mWeatherId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIntensity", &mIntensity, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDensity", &mDensity, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStart", &mStart, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEnd", &mEnd, 0u, 0u);
}

__attribute__((weak)) void cIndoorSkyFogParam::setupFromCopy(const cIndoorSkyFogParam* pData) {
    DDON_STUB("cIndoorSkyFogParam::setupFromCopy")
    /* stub */
}

void cIndoorSkyFogParam::setupFromLerp(cIndoorSkyFogParam* pStart, cIndoorSkyFogParam* pEnd, f32 rate) {
    mIntensity = nDDOMath::lerp(pStart->mIntensity, pEnd->mIntensity, rate);
    mDensity = nDDOMath::lerp(pStart->mDensity, pEnd->mDensity, rate);
    mStart = nDDOMath::lerp(pStart->mStart, pEnd->mStart, rate);
    mEnd = nDDOMath::lerp(pStart->mEnd, pEnd->mEnd, rate);
    mId = pStart->mId;
}

inline cIndoorSkyFogParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cIndoorSkyFogParam::MyDTI cIndoorSkyFogParam::DTI("cIndoorSkyFogParam", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cIndoorSkyFogParam::MyDTI::newInstance() const {
    return new (16u) cIndoorSkyFogParam;
}

const MtDTI& cZoneIndoorGrassOff::getDTI() const {
    return cZoneIndoorGrassOff::DTI;
}

inline cZoneIndoorGrassOff::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneIndoorGrassOff::MyDTI cZoneIndoorGrassOff::DTI("cZoneIndoorGrassOff", &::nSoundTrigger::cCategory::DTI, 32ul, 0u, 0u);

MtObject* cZoneIndoorGrassOff::MyDTI::newInstance() const {
    return new (16u) cZoneIndoorGrassOff;
}

const MtDTI& cZoneIndoorLight::getDTI() const {
    return cZoneIndoorLight::DTI;
}

__attribute__((noinline)) cZoneIndoorLight::~cZoneIndoorLight() {
    if (mDayFogParamArray.mLength != 0) {
        u32 v0_0 = mDayFogParamArray.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mDayFogParamArray.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mDayFogParamArray.mpArray[i0_3];
                v1_0 = mDayFogParamArray.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mDayFogParamArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mDayFogParamArray.mpArray));
    }
    mDayFogParamArray.mpArray = nullptr;
    mDayFogParamArray.mBufsiz = 0;
    mDayFogParamArray.mLength = 0;
    if (mNightFogParamArray.mLength != 0) {
        u32 v3_0 = mNightFogParamArray.mLength;
        unsigned int i3_3 = 0;
        u32 v4_0;
        for (;;) {
            if (mNightFogParamArray.mpArray[i3_3] == nullptr) {
                v4_0 = v3_0;
            } else {
                delete mNightFogParamArray.mpArray[i3_3];
                v4_0 = mNightFogParamArray.mLength;
            }
            if ((i3_3 + 1u) < v4_0) {
                v3_0 = v4_0;
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mNightFogParamArray.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mNightFogParamArray.mpArray));
    }
    mNightFogParamArray.mpArray = nullptr;
    mNightFogParamArray.mBufsiz = 0;
    mNightFogParamArray.mLength = 0;
}

__attribute__((weak)) const cIndoorSkyFogParam* cZoneIndoorLight::getDayFogParam(u32 WeatherId) {
    DDON_STUB("cZoneIndoorLight::getDayFogParam")
    return nullptr;
}

__attribute__((weak)) const cIndoorSkyFogParam* cZoneIndoorLight::getNightFogParam(u32 WeatherId) {
    DDON_STUB("cZoneIndoorLight::getNightFogParam")
    return nullptr;
}

void cZoneIndoorLight::createProperty(MtPropertyList& s) {
    this->nSoundTrigger::cCategory::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mLightInfiniteRate", &mLightInfiniteRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLightHemiRateDay", &mLightHemiRateDay, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLightHemiRateDayRev", &mLightHemiRateDayRev, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLightHemiRateNight", &mLightHemiRateNight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLightHemiRateNightRev", &mLightHemiRateNightRev, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLightSubRateDay", &mLightSubRateDay, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLightSubRateNight", &mLightSubRateNight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUseSkyFogParam", &mUseSkyFogParam, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDayFogParamArray", static_cast<MtObject*>(&mDayFogParamArray), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNightFogParamArray", static_cast<MtObject*>(&mNightFogParamArray), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSkyColorFogUseFrame", &mSkyColorFogUseFrame, 0u, 0u);
}

inline cZoneIndoorLight::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneIndoorLight::MyDTI cZoneIndoorLight::DTI("cZoneIndoorLight", &::nSoundTrigger::cCategory::DTI, 128ul, 0u, 0u);

__attribute__((weak)) MtObject* cZoneIndoorLight::MyDTI::newInstance() const {
    return new (16u) ::cZoneIndoorLight;
}

const MtDTI& cZoneIndoorScrlEfcOff::getDTI() const {
    return cZoneIndoorScrlEfcOff::DTI;
}

inline cZoneIndoorScrlEfcOff::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneIndoorScrlEfcOff::MyDTI cZoneIndoorScrlEfcOff::DTI("cZoneIndoorScrlEfcOff", &::nSoundTrigger::cCategory::DTI, 32ul, 0u, 0u);

MtObject* cZoneIndoorScrlEfcOff::MyDTI::newInstance() const {
    return new (16u) cZoneIndoorScrlEfcOff;
}

const MtDTI& cZoneIndoorWeatherEffectOff::getDTI() const {
    return cZoneIndoorWeatherEffectOff::DTI;
}

inline cZoneIndoorWeatherEffectOff::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneIndoorWeatherEffectOff::MyDTI cZoneIndoorWeatherEffectOff::DTI("cZoneIndoorWeatherEffectOff", &::nSoundTrigger::cCategory::DTI, 32ul, 0u, 0u);

MtObject* cZoneIndoorWeatherEffectOff::MyDTI::newInstance() const {
    return new (16u) cZoneIndoorWeatherEffectOff;
}

const MtDTI& cZoneIndoorWindCtrl::getDTI() const {
    return cZoneIndoorWindCtrl::DTI;
}

inline cZoneIndoorWindCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZoneIndoorWindCtrl::MyDTI cZoneIndoorWindCtrl::DTI("cZoneIndoorWindCtrl", &::nSoundTrigger::cCategory::DTI, 32ul, 0u, 0u);

MtObject* cZoneIndoorWindCtrl::MyDTI::newInstance() const {
    return new (16u) cZoneIndoorWindCtrl;
}

template MtTypedArray<cIndoorSkyFogParam>::~MtTypedArray();

