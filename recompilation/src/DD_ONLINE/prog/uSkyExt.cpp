// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uSkyExt.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cDraw.h"
#include "../../XFramework/cUnit.h"
#include "../../generated/shared/nDDOMath.h"
#include "../../XFramework/nDrawConstantTable.h"
#include "../../XFramework/nDrawResource.h"
#include "../../XFramework/nDrawTexture.h"
#include "../../XFramework/rSky.h"
#include "../../XFramework/rTexture.h"
#include "rWeatherInfo.h"
#include "res_ptr.h"
#include "../../XFramework/sUnit.h"
#include "sWeatherManager.h"
#include "../../XFramework/uSky.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uSkyExt::getDTI() const {
    return uSkyExt::DTI;
}

void* uSkyExt::operator new(size_t sz, u32 align) {
    return uSkyExt::getAllocator()->memAlloc(sz, align, uSkyExt::DTI.getID());
}

uSkyExt::~uSkyExt() {
    DDON_STUB("uSkyExt::~uSkyExt")
    /* stub */
}

void uSkyExt::setup() {
    createBuffer();
    sUnit::getInstance()->setUnitGroupBit(static_cast<cUnit*>(this), 0x600000000100000ul);
}

__attribute__((weak)) void uSkyExt::move() {
    DDON_STUB("uSkyExt::move")
    /* stub */
}

void uSkyExt::setStarTexture(rTexture* pRes) {
    this->uSky::setStarTexture(pRes);
}

void uSkyExt::setStarIntensity(f32 starIntensity) {
    this->uSky::setStarIntensity(starIntensity);
}

void uSkyExt::setStarSize(f32 starSize) {
    this->uSky::setStarSize(starSize);
}

void uSkyExt::setStarrySkyIntensity(f32 starrySkyIntensity) {
    this->uSky::setStarrySkyIntensity(starrySkyIntensity);
}

void uSkyExt::setStarTwinkleAmplitude(f32 starTwinkleAmplitude) {
    this->uSky::setStarTwinkleAmplitude(starTwinkleAmplitude);
}

void uSkyExt::setStarCount(u32 cnt) {
    this->uSky::setStarCount(cnt);
}

MtVector3 uSkyExt::getBaseSunColor() const {
    return mBaseSunColor;
}

__attribute__((weak)) void uSkyExt::updateWeather() {
    DDON_STUB("uSkyExt::updateWeather")
    /* stub */
}

void uSkyExt::drawSun(cDraw* pdraw) {
    if (sWeatherManager::getInstance()->isDisableSun() != 0.0f) {
        return;
    }
    this->uSky::drawSun(pdraw);
}

__attribute__((weak)) void uSkyExt::drawMoon(cDraw* pdraw) {
    DDON_STUB("uSkyExt::drawMoon")
    /* stub */
}

MtVector3 uSkyExt::getSunDirforMoon() {
    return mSunDirforMoon;
}

void uSkyExt::createProperty(MtPropertyList& s) {
    this->uSky::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mBaseSunColor", &mBaseSunColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRotX", &mRotX, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRotZ", &mRotZ, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMoonScale", &mMoonScale, 0u, 0u);
}

MtVector3 uSkyExt::getMoonDirection() {
    return mMoonDirection;
}

inline uSkyExt::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uSkyExt::MyDTI uSkyExt::DTI("uSkyExt", &::uSky::DTI, 1344ul, 0u, 0u);

__attribute__((weak)) MtObject* uSkyExt::MyDTI::newInstance() const {
    DDON_STUB("uSkyExt::MyDTI::newInstance")
    return nullptr;
}

