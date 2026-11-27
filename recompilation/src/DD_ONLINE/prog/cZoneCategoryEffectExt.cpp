// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cZoneCategoryEffectExt.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cZoneContents.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

inline void* cZCEffectColorControlColorOff::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cZCEffectColorControlColorOff::DTI)->memAlloc(sz, align, ::cZCEffectColorControlColorOff::DTI.getID());
}
inline cZCEffectColorControlColorOff::cZCEffectColorControlColorOff() {
    mCorrectType = 6;
}

inline void* cZCEffectColorControlDisregard::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cZCEffectColorControlDisregard::DTI)->memAlloc(sz, align, ::cZCEffectColorControlDisregard::DTI.getID());
}
inline cZCEffectColorControlDisregard::cZCEffectColorControlDisregard() {
    mCorrectType = 5;
}

inline void* cZCEffectColorControlNightOff::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cZCEffectColorControlNightOff::DTI)->memAlloc(sz, align, ::cZCEffectColorControlNightOff::DTI.getID());
}
inline cZCEffectColorControlNightOff::cZCEffectColorControlNightOff() {
    mCorrectType = 4;
}

inline void* cZCEffectColorControlDayOff::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cZCEffectColorControlDayOff::DTI)->memAlloc(sz, align, ::cZCEffectColorControlDayOff::DTI.getID());
}
inline cZCEffectColorControlDayOff::cZCEffectColorControlDayOff() {
    mCorrectType = 3;
}

inline void* cZCEffectColorControlWater::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cZCEffectColorControlWater::DTI)->memAlloc(sz, align, ::cZCEffectColorControlWater::DTI.getID());
}
inline cZCEffectColorControlWater::cZCEffectColorControlWater() {
    mCorrectType = 2;
}

inline void* cZCEffectColorControlBase::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cZCEffectColorControlBase::DTI)->memAlloc(sz, align, ::cZCEffectColorControlBase::DTI.getID());
}
inline cZCEffectColorControlBase::cZCEffectColorControlBase() {
    mCorrectType = 1;
}

inline cZCEffectColorControl::cZCEffectColorControl() {
    setAttribute(0x8000u, true);
    setAttribute(0x10000u, true);
    mColor = MtColor::White;
    mColorBlend = 0.0f;
    mIntensity = 1.0f;
    mIntensityBlend = 0.0f;
    mShadowColor = MtColor::Black;
    mShadowColorBlend = 0.0f;
    mShadowIntensity = 1.0f;
    mShadowIntensityBlend = 0.0f;
    mEnvMapPowerScale = 1.0f;
    mUseSkyColor = false;
    mUseShadowColor = true;
    mUseMixColor = false;
    mUsePointLightSupplement = true;
}

const MtDTI& cZCEFLControl::getDTI() const {
    return cZCEFLControl::DTI;
}

cZCEFLControl::~cZCEFLControl() {
    if (mSetList.mLength != 0) {
        u32 v0_0 = mSetList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mSetList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mSetList.mpArray[i0_3];
                v1_0 = mSetList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mSetList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSetList.mpArray));
    }
    mSetList.mpArray = nullptr;
    mSetList.mBufsiz = 0;
    mSetList.mLength = 0;
}

void cZCEFLControl::createProperty(MtPropertyList& s) {
    this->cZoneContents::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mSetList", reinterpret_cast<MT_MFUNC>(&::cZCEFLControl::getResourceSet), reinterpret_cast<MT_MFUNC>(&::cZCEFLControl::setResourceSet), 160u, reinterpret_cast<MT_MFUNC>(&::cZCEFLControl::getResourceSetNum), reinterpret_cast<MT_MFUNC>(&::cZCEFLControl::setResourceSetNum));
}

MtUI* cZCEFLControl::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

cZCEFLControl::cResourceSet* cZCEFLControl::getResourceSet(u32 Index) {
    if (Index < mSetList.mLength) {
        return static_cast<cResourceSet*>(mSetList.getBuffer()[static_cast<int>(Index)]);
    } else {
        return nullptr;
    }
}

void cZCEFLControl::setResourceSet(cZCEFLControl::cResourceSet* pResourceSet, u32 Index) {
    if (Index < mSetList.mLength) {
        if (pResourceSet != mSetList.getBuffer()[static_cast<int>(Index)]) {
            if (mSetList.getBuffer()[static_cast<int>(Index)] != nullptr) {
                delete mSetList.getBuffer()[static_cast<int>(Index)];
                mSetList.getBuffer()[static_cast<int>(Index)] = nullptr;
            }
            mSetList.getBuffer()[static_cast<int>(Index)] = static_cast<MtObject*>(pResourceSet);
        }
    }
}

static auto ddon_emit_0x01a65ca0 __attribute__((used)) = &cZCEFLControl::getResourceSetNum;

__attribute__((weak)) void cZCEFLControl::setResourceSetNum(u32 Num) {
    u32 old = mSetList.length();
    mSetList.resize(Num);
    for (u32 i = old; i < Num; i++) {
        cZCEFLControl::cResourceSet* pResourceSet = new (16u) cZCEFLControl::cResourceSet;
        mSetList.mpArray[static_cast<s32>(i)] = pResourceSet;
    }
}

inline cZCEFLControl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZCEFLControl::MyDTI cZCEFLControl::DTI("cZCEFLControl", &::cZCEffectControl::DTI, 64ul, 0u, 0u);

MtObject* cZCEFLControl::MyDTI::newInstance() const {
    return new (16u) cZCEFLControl;
}

const MtDTI& cZCEFLControl::cResourceSet::getDTI() const {
    return cZCEFLControl::cResourceSet::DTI;
}

void* cZCEFLControl::cResourceSet::operator new(size_t sz, u32 align) {
    return cZCEFLControl::cResourceSet::getAllocator()->memAlloc(sz, align, cZCEFLControl::cResourceSet::DTI.getID());
}

cZCEFLControl::cResourceSet::cResourceSet() {
    mResourceType = 0;
    mIndexNo = 0;
    mElementNo = 0;
}

void cZCEFLControl::cResourceSet::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mResourceType", &mResourceType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIndexNo", &mIndexNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mElementNo", &mElementNo, 0u, 0u);
}

MtUI* cZCEFLControl::cResourceSet::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cZCEFLControl::cResourceSet::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZCEFLControl::cResourceSet::MyDTI cZCEFLControl::cResourceSet::DTI("cZCEFLControl::cResourceSet", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cZCEFLControl::cResourceSet::MyDTI::newInstance() const {
    return new (16u) cZCEFLControl::cResourceSet;
}

const MtDTI& cZCEffectColorControl::getDTI() const {
    return cZCEffectColorControl::DTI;
}

void cZCEffectColorControl::createProperty(MtPropertyList& s) {
    this->cZoneContents::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mCorrectType", &mCorrectType, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUseSkyColor", &mUseSkyColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUseShadowColor", &mUseShadowColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUseMixColor", &mUseMixColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUsePointLightSupplement", &mUsePointLightSupplement, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColor", &mColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColorBlend", &mColorBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIntensity", &mIntensity, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIntensityBlend", &mIntensityBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShadowColor", &mShadowColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShadowColorBlend", &mShadowColorBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShadowIntensity", &mShadowIntensity, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShadowIntensityBlend", &mShadowIntensityBlend, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEnvMapPowerScale", &mEnvMapPowerScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Default Color Set", static_cast<MT_MFUNC>(&::cZCEffectColorControl::setDefaultColor), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "Color to ShadowColor", static_cast<MT_MFUNC>(&::cZCEffectColorControl::copyColorToShadowColor), 10u);
}

MtUI* cZCEffectColorControl::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void cZCEffectColorControl::setDefaultColor() {
    DDON_STUB("cZCEffectColorControl::setDefaultColor")
    /* stub */
}

void cZCEffectColorControl::copyColorToShadowColor() {
    mShadowColor.rgba = mColor.rgba;
}

inline cZCEffectColorControl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZCEffectColorControl::MyDTI cZCEffectColorControl::DTI("cZCEffectColorControl", &::cZoneContents::DTI, 72ul, 0u, 0u);

__attribute__((weak)) MtObject* cZCEffectColorControl::MyDTI::newInstance() const {
    DDON_STUB("cZCEffectColorControl::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cZCEffectColorControlBase::getDTI() const {
    return cZCEffectColorControlBase::DTI;
}

inline cZCEffectColorControlBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZCEffectColorControlBase::MyDTI cZCEffectColorControlBase::DTI("cZCEffectColorControlBase", &::cZCEffectColorControl::DTI, 72ul, 0u, 0u);

__attribute__((weak)) MtObject* cZCEffectColorControlBase::MyDTI::newInstance() const {
    return new (16u) ::cZCEffectColorControlBase;
}

const MtDTI& cZCEffectColorControlColorOff::getDTI() const {
    return cZCEffectColorControlColorOff::DTI;
}

inline cZCEffectColorControlColorOff::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZCEffectColorControlColorOff::MyDTI cZCEffectColorControlColorOff::DTI("cZCEffectColorControlColorOff", &::cZCEffectColorControl::DTI, 72ul, 0u, 0u);

__attribute__((weak)) MtObject* cZCEffectColorControlColorOff::MyDTI::newInstance() const {
    return new (16u) ::cZCEffectColorControlColorOff;
}

const MtDTI& cZCEffectColorControlDayOff::getDTI() const {
    return cZCEffectColorControlDayOff::DTI;
}

inline cZCEffectColorControlDayOff::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZCEffectColorControlDayOff::MyDTI cZCEffectColorControlDayOff::DTI("cZCEffectColorControlDayOff", &::cZCEffectColorControl::DTI, 72ul, 0u, 0u);

__attribute__((weak)) MtObject* cZCEffectColorControlDayOff::MyDTI::newInstance() const {
    return new (16u) ::cZCEffectColorControlDayOff;
}

const MtDTI& cZCEffectColorControlDisregard::getDTI() const {
    return cZCEffectColorControlDisregard::DTI;
}

inline cZCEffectColorControlDisregard::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZCEffectColorControlDisregard::MyDTI cZCEffectColorControlDisregard::DTI("cZCEffectColorControlDisregard", &::cZCEffectColorControl::DTI, 72ul, 0u, 0u);

__attribute__((weak)) MtObject* cZCEffectColorControlDisregard::MyDTI::newInstance() const {
    return new (16u) ::cZCEffectColorControlDisregard;
}

const MtDTI& cZCEffectColorControlNightOff::getDTI() const {
    return cZCEffectColorControlNightOff::DTI;
}

inline cZCEffectColorControlNightOff::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZCEffectColorControlNightOff::MyDTI cZCEffectColorControlNightOff::DTI("cZCEffectColorControlNightOff", &::cZCEffectColorControl::DTI, 72ul, 0u, 0u);

__attribute__((weak)) MtObject* cZCEffectColorControlNightOff::MyDTI::newInstance() const {
    return new (16u) ::cZCEffectColorControlNightOff;
}

const MtDTI& cZCEffectColorControlWater::getDTI() const {
    return cZCEffectColorControlWater::DTI;
}

inline cZCEffectColorControlWater::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZCEffectColorControlWater::MyDTI cZCEffectColorControlWater::DTI("cZCEffectColorControlWater", &::cZCEffectColorControl::DTI, 72ul, 0u, 0u);

__attribute__((weak)) MtObject* cZCEffectColorControlWater::MyDTI::newInstance() const {
    return new (16u) ::cZCEffectColorControlWater;
}

const MtDTI& cZCEffectControl::getDTI() const {
    return cZCEffectControl::DTI;
}

inline cZCEffectControl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cZCEffectControl::MyDTI cZCEffectControl::DTI("cZCEffectControl", &::cZoneContents::DTI, 32ul, 0u, 0u);

MtObject* cZCEffectControl::MyDTI::newInstance() const {
    return new (16u) cZCEffectControl;
}

template MtTypedArray<cZCEFLControl::cResourceSet>::~MtTypedArray();

