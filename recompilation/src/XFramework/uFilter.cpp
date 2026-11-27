// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uFilter.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtEaseCurve.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive2D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cDraw.h"
#include "cResource.h"
#include "cUnit.h"
#include "nDrawBlendState.h"
#include "nDrawResource.h"
#include "nDrawTexture.h"
#include "rTexture.h"
#include "sCamera.h"
#include "sRender.h"
#include "sResource.h"
#include "sScene.h"
#include "sUnit.h"
#include "uCamera.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uBloomFilter::getDTI() const {
    return uBloomFilter::DTI;
}

uBloomFilter::~uBloomFilter() {
    DDON_STUB("uBloomFilter::~uBloomFilter")
    /* stub */
}

void uBloomFilter::draw(cDraw* pdraw) {
    if (pdraw->mContext.pscene == nullptr) {
        return;
    }
    uBloomFilter::drawBloom(pdraw, static_cast<uFilter*>(this), mParam, 1.0f);
}

void uBloomFilter::createProperty(MtPropertyList& s) {
    this->uFilter::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mBloomDispersion", &mParam.mBloomDispersion, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBloomThrethold", &mParam.mBloomThreshold, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBloomColor", &mParam.mBloomColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mConeFilter", &mParam.mConeFilter, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpRTBloom[0]", reinterpret_cast<MtObject* *>(&mParam.mpRTBloom[0]), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStencilID", &mParam.mStencilID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLegacy", &mParam.mLegacy, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCTREmulation", &uBloomFilter::mCTREmulation, 0u, 0u);
}

MtUI* uBloomFilter::createUI(MtProperty& prop) {
    return this->cUnit::createUI(prop);
}

__attribute__((weak)) void uBloomFilter::move() {
    DDON_STUB("uBloomFilter::move")
    /* stub */
}

__attribute__((weak)) void uBloomFilter::drawBloom(cDraw* pdraw, uFilter* pOwner, const uBloomFilter::BloomParam& Param, f32 Transparency) {
    DDON_STUB("uBloomFilter::drawBloom")
    /* stub */
}

__attribute__((weak)) void uBloomFilter::drawBloomPass(cDraw* pdraw, uFilter* pOwner, const uBloomFilter::BloomParam& Param) {
    DDON_STUB("uBloomFilter::drawBloomPass")
    /* stub */
}

inline uBloomFilter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uBloomFilter::MyDTI uBloomFilter::DTI("uBloomFilter", &::uFilter::DTI, 256ul, 0u, 0u);

bool uBloomFilter::mCTREmulation;

__attribute__((weak)) MtObject* uBloomFilter::MyDTI::newInstance() const {
    DDON_STUB("uBloomFilter::MyDTI::newInstance")
    return nullptr;
}

void uBloomFilter::BloomParam::init() {
    mBloomColor.x = MtVector3::One.x;
    mBloomColor.y = MtVector3::One.y;
    mBloomColor.z = MtVector3::One.z;
    mBloomColor.pad_ = 0.0f;
    mBloomDispersion = 8.0f;
    mBloomThreshold = 1.0f;
    mAttenuationEnable = false;
    mCullingEnable = false;
    mScreenAttenuateFlag = false;
    mConeFilter = true;
    mLegacy = false;
    mStencilID = -1;
}

__attribute__((weak)) void uBloomFilter::BloomParam::update(const uBloomFilter::BloomParam& Param) {
    DDON_STUB("uBloomFilter::BloomParam::update")
    /* stub */
}

__attribute__((weak)) void uBloomFilter::BloomParam::createTextures(uFilter* pOwner) {
    DDON_STUB("uBloomFilter::BloomParam::createTextures")
    /* stub */
}

void uBloomFilter::BloomParam::releaseTextures() {
    if (mpRTGlareTemp[0] != nullptr) {
        mpRTGlareTemp[0]->release();
        mpRTGlareTemp[0] = nullptr;
    }
    if (mpRTBloom[0] != nullptr) {
        mpRTBloom[0]->release();
        mpRTBloom[0] = nullptr;
    }
    if (mpRTGlareTemp[1] != nullptr) {
        mpRTGlareTemp[1]->release();
        mpRTGlareTemp[1] = nullptr;
    }
    if (mpRTBloom[1] != nullptr) {
        mpRTBloom[1]->release();
        mpRTBloom[1] = nullptr;
    }
    if (mpRTGlareTemp[2] != nullptr) {
        mpRTGlareTemp[2]->release();
        mpRTGlareTemp[2] = nullptr;
    }
    if (mpRTBloom[2] != nullptr) {
        mpRTBloom[2]->release();
        mpRTBloom[2] = nullptr;
    }
    if (mpRTGlareTemp[3] != nullptr) {
        mpRTGlareTemp[3]->release();
        mpRTGlareTemp[3] = nullptr;
    }
    if (mpRTBloom[3] != nullptr) {
        mpRTBloom[3]->release();
        mpRTBloom[3] = nullptr;
    }
}

bool uBloomFilter::BloomParam::isTexturesCreated() const {
    if (mpRTGlareTemp[0] != nullptr) {
        if (mpRTBloom[0] != nullptr) {
            if (mpRTGlareTemp[1] != nullptr) {
                if (mpRTBloom[1] != nullptr) {
                    if (mpRTGlareTemp[2] != nullptr) {
                        if (mpRTBloom[2] != nullptr) {
                            if (mpRTGlareTemp[3] != nullptr) {
                                return mpRTBloom[3] != nullptr;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

__attribute__((weak)) void uBloomFilter::BloomParam::setAttenuation(f32 StartZ, f32 EndZ) {
    mStartZ = StartZ;
    mEndZ = EndZ;
    mAttenuationEnable = (*reinterpret_cast<u32*>(&mStartZ) | *reinterpret_cast<u32*>(&mEndZ)) != 0;
}

const MtDTI& uColorCorrectFilter::getDTI() const {
    return uColorCorrectFilter::DTI;
}

uColorCorrectFilter::uColorCorrectFilter() {
    DDON_STUB("uColorCorrectFilter::uColorCorrectFilter")
    /* stub */
}

uColorCorrectFilter::~uColorCorrectFilter() {
    DDON_STUB("uColorCorrectFilter::~uColorCorrectFilter")
    /* stub */
}

__attribute__((weak)) void uColorCorrectFilter::move() {
    DDON_STUB("uColorCorrectFilter::move")
    /* stub */
}

void uColorCorrectFilter::draw(cDraw* pdraw) {
    if (pdraw->mContext.pscene == nullptr) {
        return;
    }
    uColorCorrectFilter::drawColorCorrect(pdraw, static_cast<uFilter*>(this), mParam, 1.0f);
}

MtUI* uColorCorrectFilter::createUI(MtProperty& prop) {
    return this->cUnit::createUI(prop);
}

void uColorCorrectFilter::createProperty(MtPropertyList& s) {
    this->uFilter::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mCorrector", static_cast<MtObject*>(&mCorrector[0]), 32u, 16u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_HERMITECURVE, "ToneCurveRGB", reinterpret_cast<MT_MFUNC>(&::uColorCorrectFilter::getToneCurve), reinterpret_cast<MT_MFUNC>(&::uColorCorrectFilter::setToneCurve), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mGamma", &mParam.mGamma, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpToneMap", reinterpret_cast<MtObject* *>(&mParam.mpToneMap), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mToneCurveR", &mParam.mToneCurveR, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mToneCurveG", &mParam.mToneCurveG, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mToneCurveB", &mParam.mToneCurveB, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVolumeInterpolateQuality", &mParam.mVolumeInterpolateQuality, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpVolumeColorCorrect", "resource", static_cast<void*>(&mParam.mpVolumeColorCorrect), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mParam.mPos, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mStartZ", reinterpret_cast<MT_MFUNC>(&::uColorCorrectFilter::getAttenuationStartZ), reinterpret_cast<MT_MFUNC>(&::uColorCorrectFilter::setAttenuationStartZ), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mEndZ", reinterpret_cast<MT_MFUNC>(&::uColorCorrectFilter::getAttenuationEndZ), reinterpret_cast<MT_MFUNC>(&::uColorCorrectFilter::setAttenuationEndZ), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mAttenuationEnable", &mParam.mAttenuationEnable, 1u, 0u);
}

static auto ddon_emit_0x01b5eb70 __attribute__((used)) = &uColorCorrectFilter::getAttenuationStartZ;

__attribute__((weak)) void uColorCorrectFilter::setAttenuationStartZ(f32 StartZ) {
    DDON_STUB("uColorCorrectFilter::setAttenuationStartZ")
    /* stub */
}

static auto ddon_emit_0x01b5ebb0 __attribute__((used)) = &uColorCorrectFilter::getAttenuationEndZ;

__attribute__((weak)) void uColorCorrectFilter::setAttenuationEndZ(f32 EndZ) {
    DDON_STUB("uColorCorrectFilter::setAttenuationEndZ")
    /* stub */
}

__attribute__((weak)) void uColorCorrectFilter::drawColorCorrect(cDraw* pdraw, uFilter* pOwner, const uColorCorrectFilter::ColorCorrectParam& Param, f32 Transparency) {
    DDON_STUB("uColorCorrectFilter::drawColorCorrect")
    /* stub */
}

__attribute__((weak)) void uColorCorrectFilter::setToneCurve(const MtHermiteCurve& curve) {
    DDON_STUB("uColorCorrectFilter::setToneCurve")
    /* stub */
}

MtHermiteCurve uColorCorrectFilter::getToneCurve() {
    return mParam.mToneCurveR;
}

inline uColorCorrectFilter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uColorCorrectFilter::MyDTI uColorCorrectFilter::DTI("uColorCorrectFilter", &::uFilter::DTI, 2272ul, 0u, 0u);

__attribute__((weak)) MtObject* uColorCorrectFilter::MyDTI::newInstance() const {
    DDON_STUB("uColorCorrectFilter::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uColorCorrectFilter::Corrector::getDTI() const {
    return uColorCorrectFilter::Corrector::DTI;
}

MtUI* uColorCorrectFilter::Corrector::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void uColorCorrectFilter::Corrector::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mEnable", &mParams.mEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mType", &mParams.mType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFactor", &mParams.mFactor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFactor2", &mParams.mFactor2, 0u, 0u);
}

inline uColorCorrectFilter::Corrector::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uColorCorrectFilter::Corrector::MyDTI uColorCorrectFilter::Corrector::DTI("uColorCorrectFilter::Corrector", &::MtObject::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* uColorCorrectFilter::Corrector::MyDTI::newInstance() const {
    DDON_STUB("uColorCorrectFilter::Corrector::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) MtMatrix uColorCorrectFilter::Params::getMatrix() const {
    DDON_STUB("uColorCorrectFilter::Params::getMatrix")
    __builtin_unreachable();
}

__attribute__((weak)) void uColorCorrectFilter::ColorCorrectParam::init() {
    DDON_STUB("uColorCorrectFilter::ColorCorrectParam::init")
    /* stub */
}

__attribute__((weak)) void uColorCorrectFilter::ColorCorrectParam::update(const uColorCorrectFilter::ColorCorrectParam& Param) {
    DDON_STUB("uColorCorrectFilter::ColorCorrectParam::update")
    /* stub */
}

__attribute__((weak)) void uColorCorrectFilter::ColorCorrectParam::createTextures() {
    DDON_STUB("uColorCorrectFilter::ColorCorrectParam::createTextures")
    /* stub */
}

void uColorCorrectFilter::ColorCorrectParam::releaseTextures() {
    if (mpToneMap != nullptr) {
        mpToneMap->release();
        mpToneMap = nullptr;
    }
    if (mpVolumeColorCorrect == nullptr) {
        return;
    }
    mpVolumeColorCorrect->release();
    mpVolumeColorCorrect = nullptr;
}

bool uColorCorrectFilter::ColorCorrectParam::isTexturesCreated() const {
    if (mpToneMap != nullptr) {
        return mpVolumeColorCorrect != nullptr;
    } else {
        return false;
    }
}

__attribute__((weak)) void uColorCorrectFilter::ColorCorrectParam::setAttenuation(f32 StartZ, f32 EndZ) {
    DDON_STUB("uColorCorrectFilter::ColorCorrectParam::setAttenuation")
    /* stub */
}

__attribute__((weak)) void uColorCorrectFilter::ColorCorrectParam::updateMatrix() {
    DDON_STUB("uColorCorrectFilter::ColorCorrectParam::updateMatrix")
    /* stub */
}

const MtDTI& uDOFFilter::getDTI() const {
    return uDOFFilter::DTI;
}

__attribute__((noinline)) uDOFFilter::~uDOFFilter() {
    DDON_STUB("uDOFFilter::~uDOFFilter")
    /* stub */
}

__attribute__((weak)) void uDOFFilter::move() {
}

void uDOFFilter::sync() {
    if (!(sRender::mpInstance)->mSRGBEnable) {
        if (mbGSDOF) {
            if (mpDiaphragm == nullptr) {
                mpDiaphragm = static_cast<rTexture*>((sResource::mpInstance)->create(rTexture::DTI, "system\\texture\\diaphragm_MM", 1u));
            }
            if (mpTempAccTexture == nullptr) {
                mpTempAccTexture = new (16u) nDraw::Texture(uDOFFilter::DTI.mName, "TempTexture", static_cast<unsigned int>((sRender::mpInstance)->mScreenSize.wh), static_cast<u32>((sRender::mpInstance)->mScreenSize.wh >> 32), 1u, 1u, nDraw::FORMAT_R16G16B16A16_FLOAT, nDraw::USAGE_RENDERTARGET, 2u, nDraw::TEXMEMORY_VRAM);
            }
        } else {
            if (mpTempTexture[0] == nullptr) {
                mpTempTexture[0] = new (16u) nDraw::Texture(uDOFFilter::DTI.mName, "TempTexture00", static_cast<u32>(static_cast<int>(static_cast<unsigned long>((sRender::mpInstance)->mScreenSize.wh) + static_cast<unsigned long>(static_cast<unsigned int>((sRender::mpInstance)->mScreenSize.wh) >> 31)) >> 1), static_cast<u32>(static_cast<int>(((sRender::mpInstance)->mScreenSize.wh >> 32) + ((sRender::mpInstance)->mScreenSize.wh >> 63)) >> 1), 1u, 1u, nDraw::FORMAT_B8G8R8A8_UNORM, nDraw::USAGE_RENDERTARGET, 2u, nDraw::TEXMEMORY_VRAM);
            }
            if (mpTempTexture[1] == nullptr) {
                mpTempTexture[1] = new (16u) nDraw::Texture(uDOFFilter::DTI.mName, "TempTexture01", static_cast<u32>(static_cast<int>(static_cast<unsigned long>((sRender::mpInstance)->mScreenSize.wh) + static_cast<unsigned long>(static_cast<unsigned int>((sRender::mpInstance)->mScreenSize.wh) >> 31)) >> 1), static_cast<u32>(static_cast<int>(((sRender::mpInstance)->mScreenSize.wh >> 32) + ((sRender::mpInstance)->mScreenSize.wh >> 63)) >> 1), 1u, 1u, nDraw::FORMAT_B8G8R8A8_UNORM, nDraw::USAGE_RENDERTARGET, 2u, nDraw::TEXMEMORY_VRAM);
            }
        }
    } else {
        if (mbGSDOF) {
            if (mpDiaphragm == nullptr) {
                mpDiaphragm = static_cast<rTexture*>((sResource::mpInstance)->create(rTexture::DTI, "system\\texture\\diaphragm_MM", 1u));
            }
            if (mpTempAccTexture == nullptr) {
                mpTempAccTexture = new (16u) nDraw::Texture(uDOFFilter::DTI.mName, "TempTexture", static_cast<unsigned int>((sRender::mpInstance)->mScreenSize.wh), static_cast<u32>((sRender::mpInstance)->mScreenSize.wh >> 32), 1u, 1u, nDraw::FORMAT_R16G16B16A16_FLOAT, nDraw::USAGE_RENDERTARGET, 2u, nDraw::TEXMEMORY_VRAM);
            }
        } else {
            if (mpTempTexture[0] == nullptr) {
                mpTempTexture[0] = new (16u) nDraw::Texture(uDOFFilter::DTI.mName, "TempTexture00", static_cast<u32>(static_cast<int>(static_cast<unsigned long>((sRender::mpInstance)->mScreenSize.wh) + static_cast<unsigned long>(static_cast<unsigned int>((sRender::mpInstance)->mScreenSize.wh) >> 31)) >> 1), static_cast<u32>(static_cast<int>(((sRender::mpInstance)->mScreenSize.wh >> 32) + ((sRender::mpInstance)->mScreenSize.wh >> 63)) >> 1), 1u, 1u, nDraw::FORMAT_B8G8R8A8_UNORM_SRGB, nDraw::USAGE_RENDERTARGET, 2u, nDraw::TEXMEMORY_VRAM);
            }
            if (mpTempTexture[1] == nullptr) {
                mpTempTexture[1] = new (16u) nDraw::Texture(uDOFFilter::DTI.mName, "TempTexture01", static_cast<u32>(static_cast<int>(static_cast<unsigned long>((sRender::mpInstance)->mScreenSize.wh) + static_cast<unsigned long>(static_cast<unsigned int>((sRender::mpInstance)->mScreenSize.wh) >> 31)) >> 1), static_cast<u32>(static_cast<int>(((sRender::mpInstance)->mScreenSize.wh >> 32) + ((sRender::mpInstance)->mScreenSize.wh >> 63)) >> 1), 1u, 1u, nDraw::FORMAT_B8G8R8A8_UNORM_SRGB, nDraw::USAGE_RENDERTARGET, 2u, nDraw::TEXMEMORY_VRAM);
            }
        }
    }
}

void uDOFFilter::draw(cDraw* pdraw) {
    if (mbGSDOF) {
        drawGSDOF(pdraw);
    } else {
        drawNormalDOF(pdraw);
    }
}

MtUI* uDOFFilter::createUI(MtProperty& prop) {
    return this->cUnit::createUI(prop);
}

void uDOFFilter::createProperty(MtPropertyList& s) {
    this->uFilter::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mType", &mType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBlurType", &mBlurType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBlurSize", &mBlurSize, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGradateColor", &mGradateColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mBlurCount", reinterpret_cast<MT_MFUNC>(&::uDOFFilter::getBlurCount), reinterpret_cast<MT_MFUNC>(&::uDOFFilter::setBlurCount), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mNearBlurLimit", &mNearBlurLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFarBlurLimit", &mFarBlurLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mFocal", reinterpret_cast<MT_MFUNC>(&::uDOFFilter::getFocal), reinterpret_cast<MT_MFUNC>(&::uDOFFilter::setFocal), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mNear", reinterpret_cast<MT_MFUNC>(&::uDOFFilter::getNear), reinterpret_cast<MT_MFUNC>(&::uDOFFilter::setNear), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mFar", reinterpret_cast<MT_MFUNC>(&::uDOFFilter::getFar), reinterpret_cast<MT_MFUNC>(&::uDOFFilter::setFar), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mbGSDOF", reinterpret_cast<MT_MFUNC>(&::uDOFFilter::isGSDOF), reinterpret_cast<MT_MFUNC>(&::uDOFFilter::setGSDOF), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mAperture", &mAperture, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFocalLength", &mFocalLength, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCoCScale", &mCoCScale, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCoCBias", &mCoCBias, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLowCoCScale", &mLowCoCScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpTempTexture[0]", reinterpret_cast<MtObject* *>(&mpTempTexture[0]), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpTempTexture[1]", reinterpret_cast<MtObject* *>(&mpTempTexture[1]), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpTempAccTexture", reinterpret_cast<MtObject* *>(&mpTempAccTexture), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpDiaphragm", "resource", static_cast<void*>(&mpDiaphragm), 0u, 0u);
}

void uDOFFilter::setGSDOF(bool enable) {
    mbGSDOF = enable;
}

static auto ddon_emit_0x01b5e920 __attribute__((used)) = &uDOFFilter::isGSDOF;

static auto ddon_emit_0x01b5e910 __attribute__((used)) = &uDOFFilter::getBlurCount;

void uDOFFilter::setBlurCount(u32 n) {
    if (mBlurCount == n) {
        return;
    }
    mBlurCount = n;
}

f32 uDOFFilter::getNear() {
    return mNear;
}

void uDOFFilter::setNear(f32 f) {
    mNear = f;
    if (f > mFocal) {
        mNear = mFocal;
        if ((sCamera::mpInstance)->mViewport[0].mpCamera != nullptr) {
            if ((sCamera::mpInstance)->mViewport[0].mpCamera->mNearPlane > mNear) {
                mNear = (sCamera::mpInstance)->mViewport[0].mpCamera->mNearPlane;
            }
        }
        if (0.0f > mNear) {
            mNear = 0.0f;
        }
    } else {
        if ((sCamera::mpInstance)->mViewport[0].mpCamera != nullptr) {
            if ((sCamera::mpInstance)->mViewport[0].mpCamera->mNearPlane > f) {
                mNear = (sCamera::mpInstance)->mViewport[0].mpCamera->mNearPlane;
                if (0.0f > mNear) {
                    mNear = 0.0f;
                }
            } else {
                if (0.0f > f) {
                    mNear = 0.0f;
                }
            }
        } else {
            if (0.0f > f) {
                mNear = 0.0f;
            }
        }
    }
}

f32 uDOFFilter::getFar() {
    return mFar;
}

void uDOFFilter::setFar(f32 f) {
    mFar = f;
    if (mFocal > f) {
        mFar = mFocal;
        if ((sCamera::mpInstance)->mViewport[0].mpCamera != nullptr) {
            if (mFar > (sCamera::mpInstance)->mViewport[0].mpCamera->mFarPlane) {
                mFar = (sCamera::mpInstance)->mViewport[0].mpCamera->mFarPlane;
            }
        }
    } else {
        if ((sCamera::mpInstance)->mViewport[0].mpCamera != nullptr) {
            if (f > (sCamera::mpInstance)->mViewport[0].mpCamera->mFarPlane) {
                mFar = (sCamera::mpInstance)->mViewport[0].mpCamera->mFarPlane;
            }
        }
    }
}

f32 uDOFFilter::getFocal() {
    return mFocal;
}

void uDOFFilter::setFocal(f32 f) {
    mFocal = f;
}

__attribute__((weak)) void uDOFFilter::drawNormalDOF(cDraw* pdraw) {
    DDON_STUB("uDOFFilter::drawNormalDOF")
    /* stub */
}

__attribute__((weak)) void uDOFFilter::drawGSDOF(cDraw* pdraw) {
    DDON_STUB("uDOFFilter::drawGSDOF")
    /* stub */
}

inline uDOFFilter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uDOFFilter::MyDTI uDOFFilter::DTI("uDOFFilter", &::uFilter::DTI, 224ul, 0u, 0u);

__attribute__((weak)) MtObject* uDOFFilter::MyDTI::newInstance() const {
    DDON_STUB("uDOFFilter::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uFilter::getDTI() const {
    return uFilter::DTI;
}

uFilter::uFilter() {
    mDrawMode = 1;
    mPass = 5;
    mPriority = 1;
    mScreenLayer = 0;
}

uFilter::~uFilter() {
}

__attribute__((weak)) void uFilter::createProperty(MtPropertyList& s) {
    this->cUnit::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mPass", &mPass, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPriority", &mPriority, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mScreenLayer", &mScreenLayer, 0u, 0u);
}

MtUI* uFilter::createUI(MtProperty& prop) {
    return this->cUnit::createUI(prop);
}

u64 uFilter::getSystemUnitGroup() const {
    return 1;
}

__attribute__((weak)) void uFilter::copyRegion(cDraw* pdraw, const MtRect& dst_rect, const MtRect& src_rect, const MtSize& src_size) {
    DDON_STUB("uFilter::copyRegion")
    /* stub */
}

__attribute__((weak)) void uFilter::drawRegion(cDraw* pdraw, const MtRect& dst_rect, const MtRect& src_rect, const MtSize& src_size) {
    DDON_STUB("uFilter::drawRegion")
    /* stub */
}

__attribute__((weak)) void uFilter::setSampleCount(cDraw* pdraw, u32 nSamples) {
    DDON_STUB("uFilter::setSampleCount")
    /* stub */
}

__attribute__((weak)) void uFilter::drawImage(cDraw* pdraw, const MtRect& dstRect, const MtRect& srcRect, const MtSize& srcTex, MtColor c, f32 tl, f32 tt, f32 tw, f32 th) {
    DDON_STUB("uFilter::drawImage")
    /* stub */
}

__attribute__((weak)) void uFilter::drawImage(cDraw* pdraw, f32 off_x, f32 off_y, MtColor c, f32 tl, f32 tt, f32 tw, f32 th) {
    DDON_STUB("uFilter::drawImage")
    /* stub */
}

__attribute__((weak)) f32 uFilter::calcCullingAngleRate(f32 CullingRate, f32 CullingAngleStart, f32 CullingAngleEnd, bool CullingBothDir, bool CullingOverlap, const MtVector3& CameraDir, const MtVector3& ParticleDir) {
    DDON_STUB("uFilter::calcCullingAngleRate")
    return {};
}

__attribute__((weak)) f32 uFilter::calcScreenAttenuate(cDraw* pDraw, f32 ScreenAttenuateRate, f32 ScreenAttenuateDist, const MtVector3& Pos) {
    DDON_STUB("uFilter::calcScreenAttenuate")
    return {};
}

inline uFilter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uFilter::MyDTI uFilter::DTI("uFilter", &::cUnit::DTI, 88ul, 0u, 1u);

MtObject* uFilter::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& uGodRaysFilter::getDTI() const {
    return uGodRaysFilter::DTI;
}

uGodRaysFilter::uGodRaysFilter() {
    DDON_STUB("uGodRaysFilter::uGodRaysFilter")
    /* stub */
}

uGodRaysFilter::~uGodRaysFilter() {
    DDON_STUB("uGodRaysFilter::~uGodRaysFilter")
    /* stub */
}

void uGodRaysFilter::createProperty(MtPropertyList& s) {
    this->uFilter::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mMode", reinterpret_cast<MT_MFUNC>(&::uGodRaysFilter::getMode), reinterpret_cast<MT_MFUNC>(&::uGodRaysFilter::setMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mQuality", reinterpret_cast<MT_MFUNC>(&::uGodRaysFilter::getLevel), reinterpret_cast<MT_MFUNC>(&::uGodRaysFilter::setLevel), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mCutoff", reinterpret_cast<MT_MFUNC>(&::uGodRaysFilter::isCutoff), reinterpret_cast<MT_MFUNC>(&::uGodRaysFilter::setCutoff), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mUseLDR", reinterpret_cast<MT_MFUNC>(&::uGodRaysFilter::isUseLDR), reinterpret_cast<MT_MFUNC>(&::uGodRaysFilter::setUseLDR), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mUseShadow", reinterpret_cast<MT_MFUNC>(&::uGodRaysFilter::isShadow), reinterpret_cast<MT_MFUNC>(&::uGodRaysFilter::setShadow), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mIterativeNum", reinterpret_cast<MT_MFUNC>(&::uGodRaysFilter::getIterativeNum), reinterpret_cast<MT_MFUNC>(&::uGodRaysFilter::setIterativeNum), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mUseGray", reinterpret_cast<MT_MFUNC>(&::uGodRaysFilter::isGray), reinterpret_cast<MT_MFUNC>(&::uGodRaysFilter::setGray), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mDecay", &mParam.mDecay, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mScale", &mParam.mScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mUsePoint", reinterpret_cast<MT_MFUNC>(&::uGodRaysFilter::isUsePoint), reinterpret_cast<MT_MFUNC>(&::uGodRaysFilter::setUsePoint), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mDirection", &mParam.mDirection, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDirectionLength", &mParam.mDirectionLength, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPoint", &mParam.mPoint, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOcclusionSphereRadius", &mParam.mOcclusionSphereRadius, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mUseOcclusionBlurWidth", reinterpret_cast<MT_MFUNC>(&::uGodRaysFilter::isOcclusionBlurWidthEnable), reinterpret_cast<MT_MFUNC>(&::uGodRaysFilter::setOcclusionBlurWidthEnable), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mUseOcclusionAlpha", reinterpret_cast<MT_MFUNC>(&::uGodRaysFilter::isOcclusionAlphaEnable), reinterpret_cast<MT_MFUNC>(&::uGodRaysFilter::setOcclusionAlphaEnable), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mOcclusionBlurWidthScale", &mParam.mOcclusionBlurWidthScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOcclusionBlurWidthOffset", &mParam.mOcclusionBlurWidthOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaskWeight", &mParam.mMaskWeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaskRadius", &mParam.mMaskRadius, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mThreshold", &mParam.mThreshold, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShadowThreshold", &mParam.mShadowThreshold, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStartZ", &mParam.mStartZ, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEndZ", &mParam.mEndZ, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShadowFactor", &mParam.mShadowFactor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGamma", &mParam.mGamma, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColor", &mParam.mColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpFinal", reinterpret_cast<MtObject* *>(&mParam.mpFinal), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpOcclusionFactor", reinterpret_cast<MtObject* *>(&mParam.mpOcclusionFactor), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpTempTexture", reinterpret_cast<MtObject* *>(&mParam.mpTempTexture), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpBlur", reinterpret_cast<MtObject* *>(&mParam.mpBlur[0]), 35u, 5u);
}

MtUI* uGodRaysFilter::createUI(MtProperty& prop) {
    return this->cUnit::createUI(prop);
}

void uGodRaysFilter::moveAfter() {
    if (!mUpdate) {
        return;
    }
    mParam.releaseTextures();
    mParam.createTextures(static_cast<uFilter*>(this));
    mUpdate = false;
}

void uGodRaysFilter::draw(cDraw* pdraw) {
    if (!mUpdate) {
        uGodRaysFilter::drawGodRays(pdraw, static_cast<uFilter*>(this), mParam, 1.0f);
    }
}

__attribute__((weak)) void uGodRaysFilter::drawGodRays(cDraw* pdraw, uFilter* pOwner, const uGodRaysFilter::GodRaysParam& Param, f32 Transparency) {
    DDON_STUB("uGodRaysFilter::drawGodRays")
    /* stub */
}

__attribute__((weak)) void uGodRaysFilter::drawGodRaysPolarCoordinate(cDraw* pdraw, const uGodRaysFilter::GodRaysParam& Param) {
    DDON_STUB("uGodRaysFilter::drawGodRaysPolarCoordinate")
    /* stub */
}

__attribute__((weak)) void uGodRaysFilter::drawGodRaysOrthonormalCoordinate(cDraw* pdraw, const uGodRaysFilter::GodRaysParam& Param) {
    DDON_STUB("uGodRaysFilter::drawGodRaysOrthonormalCoordinate")
    /* stub */
}

__attribute__((weak)) void uGodRaysFilter::drawGodRaysOrthonormalCoordinateFast(cDraw* pdraw, const uGodRaysFilter::GodRaysParam& Param) {
    DDON_STUB("uGodRaysFilter::drawGodRaysOrthonormalCoordinateFast")
    /* stub */
}

void uGodRaysFilter::setMode(u32 mode) {
    if (((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 144)) & 15u) != mode) {
        mUpdate = true;
    }
    mParam.mMode = mode;
}

u32 uGodRaysFilter::getMode() {
    return (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 144)) & 15u;
}

void uGodRaysFilter::setLevel(u32 quality) {
    if ((((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 144)) >> 4) & 15u) != quality) {
        mUpdate = true;
    }
    mParam.mQuality = quality;
}

u32 uGodRaysFilter::getLevel() {
    return ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 144)) >> 4) & 15u;
}

bool uGodRaysFilter::isShadow() {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 146)) & 8) >> 3);
}

__attribute__((weak)) void uGodRaysFilter::setShadow(bool b) {
    if (mParam.mShadow ? !b : b) {
        mUpdate = true;
    }
    mParam.mShadow = b;
}

bool uGodRaysFilter::isUsePoint() {
    return static_cast<bool>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 146)) & 1);
}

__attribute__((weak)) void uGodRaysFilter::setUsePoint(bool b) {
    DDON_STUB("uGodRaysFilter::setUsePoint")
    /* stub */
}

bool uGodRaysFilter::isUseLDR() {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 146)) & 2) >> 1);
}

__attribute__((weak)) void uGodRaysFilter::setUseLDR(bool b) {
    DDON_STUB("uGodRaysFilter::setUseLDR")
    /* stub */
}

bool uGodRaysFilter::isCutoff() {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 146)) & 4) >> 2);
}

__attribute__((weak)) void uGodRaysFilter::setCutoff(bool b) {
    DDON_STUB("uGodRaysFilter::setCutoff")
    /* stub */
}

u32 uGodRaysFilter::getIterativeNum() {
    return ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 144)) >> 8) & 255u;
}

__attribute__((weak)) void uGodRaysFilter::setIterativeNum(u32 IterativeNum) {
    DDON_STUB("uGodRaysFilter::setIterativeNum")
    /* stub */
}

bool uGodRaysFilter::isGray() {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 146)) & 16) >> 4);
}

__attribute__((weak)) void uGodRaysFilter::setGray(bool b) {
    DDON_STUB("uGodRaysFilter::setGray")
    /* stub */
}

bool uGodRaysFilter::isOcclusionAlphaEnable() {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 147)) & 16) >> 4);
}

__attribute__((weak)) void uGodRaysFilter::setOcclusionAlphaEnable(bool b) {
    DDON_STUB("uGodRaysFilter::setOcclusionAlphaEnable")
    /* stub */
}

bool uGodRaysFilter::isOcclusionBlurWidthEnable() {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 147)) & 32) >> 5);
}

__attribute__((weak)) void uGodRaysFilter::setOcclusionBlurWidthEnable(bool b) {
    DDON_STUB("uGodRaysFilter::setOcclusionBlurWidthEnable")
    /* stub */
}

inline uGodRaysFilter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGodRaysFilter::MyDTI uGodRaysFilter::DTI("uGodRaysFilter", &::uFilter::DTI, 336ul, 0u, 0u);

__attribute__((weak)) MtObject* uGodRaysFilter::MyDTI::newInstance() const {
    DDON_STUB("uGodRaysFilter::MyDTI::newInstance")
    return nullptr;
}

void uGodRaysFilter::GodRaysParam::init() {
    mColor.x = MtVector4::One.x;
    mColor.y = MtVector4::One.y;
    mColor.z = MtVector4::One.z;
    mColor.w = MtVector4::One.w;
    mDirection.x = MtVector3::AxisY.x;
    mDirection.y = MtVector3::AxisY.y;
    mDirection.z = MtVector3::AxisY.z;
    mDirection.pad_ = 0.0f;
    mPoint.x = MtVector3::Zero.x;
    mPoint.y = MtVector3::Zero.y;
    mPoint.z = MtVector3::Zero.z;
    mPoint.pad_ = 0.0f;
    mMaskRadius = 1000.0f;
    mMaskWeight = 1.0f;
    mDecay = 0.9f;
    mThreshold = 0.0f;
    mGamma = 1.0f;
    mDirectionLength = 10000.0f;
    mShadowFactor = 0.0f;
    mShadowThreshold = 1.0f;
    mStartZ = 10000.0f;
    mEndZ = 20000.0f;
    mScale = 1.0f;
    mpOcclusionFactor = nullptr;
    mpTempTexture = nullptr;
    mpFinal = nullptr;
    mpBlur[4] = nullptr;
    mpBlur[3] = nullptr;
    mpBlur[2] = nullptr;
    mpBlur[1] = nullptr;
    mpBlur[0] = nullptr;
    mOcclusionSphereRadius = 0.5f;
    mMode = 2;
    mQuality = 1;
    mIterativeNum = 3;
    mUsePoint = 0;
    mUseLDR = 0;
    mCutoff = 1;
    mShadow = 0;
    mGray = 0;
    mCullingEnable = 0;
    mScreenAttenuateFlag = 0;
    mOcclusionAlphaEnable = 0;
    mOcclusionBlurWidthEnable = 0;
    mOcclusionBlurWidthOffset = 1.0f;
    mOcclusionBlurWidthScale = 0.0f;
}

__attribute__((weak)) void uGodRaysFilter::GodRaysParam::update(const uGodRaysFilter::GodRaysParam& Param) {
    DDON_STUB("uGodRaysFilter::GodRaysParam::update")
    /* stub */
}

__attribute__((weak)) void uGodRaysFilter::GodRaysParam::createTextures(uFilter* pOwner) {
    DDON_STUB("uGodRaysFilter::GodRaysParam::createTextures")
    /* stub */
}

__attribute__((weak)) void uGodRaysFilter::GodRaysParam::releaseTextures() {
    if (mpBlur[0] != nullptr) {
        mpBlur[0]->release();
        mpBlur[0] = nullptr;
    }
    if (mpBlur[1] != nullptr) {
        mpBlur[1]->release();
        mpBlur[1] = nullptr;
    }
    if (mpBlur[2] != nullptr) {
        mpBlur[2]->release();
        mpBlur[2] = nullptr;
    }
    if (mpBlur[3] != nullptr) {
        mpBlur[3]->release();
        mpBlur[3] = nullptr;
    }
    if (mpBlur[4] != nullptr) {
        mpBlur[4]->release();
        mpBlur[4] = nullptr;
    }
    if (mpFinal != nullptr) {
        mpFinal->release();
        mpFinal = nullptr;
    }
    if (mpTempTexture != nullptr) {
        mpTempTexture->release();
        mpTempTexture = nullptr;
    }
    if (mpOcclusionFactor != nullptr) {
        mpOcclusionFactor->release();
        mpOcclusionFactor = nullptr;
    }
}

bool uGodRaysFilter::GodRaysParam::isTexturesCreated() const {
    if (mpFinal != nullptr) {
        if (mpTempTexture != nullptr) {
            if (mpOcclusionFactor != nullptr) {
                if (mpBlur[0] != nullptr) {
                    if (mpBlur[1] != nullptr) {
                        if (mpBlur[2] != nullptr) {
                            if (mpBlur[3] != nullptr) {
                                return mpBlur[4] != nullptr;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

const MtDTI& uMotionBlurFilter::getDTI() const {
    return uMotionBlurFilter::DTI;
}

void* uMotionBlurFilter::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uMotionBlurFilter::DTI)->memAlloc(sz, align, uMotionBlurFilter::DTI.mID);
}

uMotionBlurFilter::uMotionBlurFilter() {
    DDON_STUB("uMotionBlurFilter::uMotionBlurFilter")
    /* stub */
}

__attribute__((noinline)) uMotionBlurFilter::~uMotionBlurFilter() {
    DDON_STUB("uMotionBlurFilter::~uMotionBlurFilter")
    /* stub */
}

__attribute__((weak)) void uMotionBlurFilter::sync() {
    DDON_STUB("uMotionBlurFilter::sync")
    /* stub */
}

void uMotionBlurFilter::draw(cDraw* pdraw) {
    if (!(sRender::mpInstance)->mIsDrawFilterArray[13]) {
        return;
    }
    if (mReconstructBlur) {
        drawReconstructBlur(pdraw);
    } else {
        drawStretchBlur(pdraw);
    }
}

MtUI* uMotionBlurFilter::createUI(MtProperty& prop) {
    return this->cUnit::createUI(prop);
}

void uMotionBlurFilter::createProperty(MtPropertyList& s) {
    this->uFilter::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mStretchBlur", &mStretchBlur, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCameraBlur", &mCameraBlur, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMedianBlur", &mMedianBlur, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mReconstructBlur", reinterpret_cast<MT_MFUNC>(&::uMotionBlurFilter::isReconstructBlur), reinterpret_cast<MT_MFUNC>(&::uMotionBlurFilter::setReconstructBlur), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mDepthLimit", &mDepthLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFeedbackNum", &mFeedbackNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSampleLevel", reinterpret_cast<s32*>(&mSampleLevel), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mResolution", reinterpret_cast<s32*>(&mResolution), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVelocityResolution", reinterpret_cast<s32*>(&mVelocityResolution), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFBLimit", &mFBLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFBScale", &mFBScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFBDepthBias", &mFBDepthBias, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOBLimit", &mOBLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSBScale", &mSBScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSBDepthBias", &mSBDepthBias, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRBScale", &mRBScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpVelocityMap", reinterpret_cast<MtObject* *>(&mpVelocityMap), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpTempTexture", reinterpret_cast<MtObject* *>(&mpTempTexture), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpBlurTempTexture", reinterpret_cast<MtObject* *>(&mpBlurTempTexture), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpTileMax", reinterpret_cast<MtObject* *>(&mpTileMax), 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpNeighborMax", reinterpret_cast<MtObject* *>(&mpNeighborMax), 3u, 0u);
}

void uMotionBlurFilter::setReconstructBlur(bool enable) {
    mReconstructBlur = enable;
    mPrevFrameVelocityResolution = __VRESOLUTION__U32;
}

static auto ddon_emit_0x01b5eaf0 __attribute__((used)) = &uMotionBlurFilter::isReconstructBlur;

__attribute__((weak)) void uMotionBlurFilter::drawStretchBlur(cDraw* pdraw) {
    DDON_STUB("uMotionBlurFilter::drawStretchBlur")
    /* stub */
}

__attribute__((weak)) void uMotionBlurFilter::drawReconstructBlur(cDraw* pdraw) {
    DDON_STUB("uMotionBlurFilter::drawReconstructBlur")
    /* stub */
}

inline uMotionBlurFilter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uMotionBlurFilter::MyDTI uMotionBlurFilter::DTI("uMotionBlurFilter", &::uFilter::DTI, 200ul, 0u, 0u);

__attribute__((weak)) MtObject* uMotionBlurFilter::MyDTI::newInstance() const {
    DDON_STUB("uMotionBlurFilter::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uRadialBlurFilter::getDTI() const {
    return uRadialBlurFilter::DTI;
}

uRadialBlurFilter::~uRadialBlurFilter() {
    DDON_STUB("uRadialBlurFilter::~uRadialBlurFilter")
    /* stub */
}

void uRadialBlurFilter::draw(cDraw* pdraw) {
    if (pdraw->mContext.pscene == nullptr) {
        return;
    }
    uRadialBlurFilter::drawRadialBlur(pdraw, static_cast<uFilter*>(this), mParam, 1.0f);
}

MtUI* uRadialBlurFilter::createUI(MtProperty& prop) {
    return this->cUnit::createUI(prop);
}

void uRadialBlurFilter::createProperty(MtPropertyList& s) {
    this->uFilter::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mBlendStateType", reinterpret_cast<MT_MFUNC>(&::uRadialBlurFilter::getBlendStateType), reinterpret_cast<MT_MFUNC>(&::uRadialBlurFilter::setBlendStateType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mMode", reinterpret_cast<MT_MFUNC>(&::uRadialBlurFilter::getMode), reinterpret_cast<MT_MFUNC>(&::uRadialBlurFilter::setMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mSamples", reinterpret_cast<MT_MFUNC>(&::uRadialBlurFilter::getSamples), reinterpret_cast<MT_MFUNC>(&::uRadialBlurFilter::setSamples), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mBlurStart", &mParam.mBlurStart, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBlurWidth", &mParam.mBlurWidth, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBrightThreshold", &mParam.mBrightThreshold, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColor", &mParam.mColor, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCenter", &mParam.mCenter, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStartW", &mParam.mStartW, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEndW", &mParam.mEndW, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStartH", &mParam.mStartH, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEndH", &mParam.mEndH, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWPos", &mParam.mPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStartZ", &mParam.mStartZ, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEndZ", &mParam.mEndZ, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "MaskTexture", "resource", reinterpret_cast<MT_MFUNC>(&::uRadialBlurFilter::getMaskTexture), reinterpret_cast<MT_MFUNC>(&::uRadialBlurFilter::setMaskTexture), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_FLOAT2, "lt", reinterpret_cast<MT_MFUNC>(&::uRadialBlurFilter::getMaskLT), reinterpret_cast<MT_MFUNC>(&::uRadialBlurFilter::setMaskLT), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_FLOAT2, "rb", reinterpret_cast<MT_MFUNC>(&::uRadialBlurFilter::getMaskRB), reinterpret_cast<MT_MFUNC>(&::uRadialBlurFilter::setMaskRB), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mUseOcclusionBlurWidth", reinterpret_cast<MT_MFUNC>(&::uRadialBlurFilter::isOcclusionBlurWidthEnable), reinterpret_cast<MT_MFUNC>(&::uRadialBlurFilter::setOcclusionBlurWidthEnable), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "mUseOcclusionAlpha", reinterpret_cast<MT_MFUNC>(&::uRadialBlurFilter::isOcclusionAlphaEnable), reinterpret_cast<MT_MFUNC>(&::uRadialBlurFilter::setOcclusionAlphaEnable), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mOcclusionSphereRadius", &mParam.mOcclusionSphereRadius, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOcclusionBlurWidthScale", &mParam.mOcclusionBlurWidthScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOcclusionBlurWidthOffset", &mParam.mOcclusionBlurWidthOffset, 0u, 0u);
}

__attribute__((weak)) void uRadialBlurFilter::setMode(u32 m) {
    DDON_STUB("uRadialBlurFilter::setMode")
    /* stub */
}

u32 uRadialBlurFilter::getMode() {
    return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 160);
}

u32 uRadialBlurFilter::getSamples() {
    return ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 160)) >> 8) & 255u;
}

__attribute__((weak)) void uRadialBlurFilter::setSamples(u32 n) {
    DDON_STUB("uRadialBlurFilter::setSamples")
    /* stub */
}

__attribute__((weak)) void uRadialBlurFilter::setBlendStateType(u32 t) {
    DDON_STUB("uRadialBlurFilter::setBlendStateType")
    /* stub */
}

u32 uRadialBlurFilter::getBlendStateType() {
    return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 162);
}

static auto ddon_emit_0x01b5e9f0 __attribute__((used)) = &uRadialBlurFilter::getMaskTexture;

__attribute__((weak)) void uRadialBlurFilter::setMaskTexture(rTexture* ptex) {
    DDON_STUB("uRadialBlurFilter::setMaskTexture")
    /* stub */
}

__attribute__((weak)) const MtFloat2 uRadialBlurFilter::getMaskLT() {
    DDON_STUB("uRadialBlurFilter::getMaskLT")
    __builtin_unreachable();
}

static auto ddon_emit_0x01b5ea20 __attribute__((used)) = &uRadialBlurFilter::setMaskLT;

__attribute__((weak)) const MtFloat2 uRadialBlurFilter::getMaskRB() {
    DDON_STUB("uRadialBlurFilter::getMaskRB")
    __builtin_unreachable();
}

static auto ddon_emit_0x01b5ea60 __attribute__((used)) = &uRadialBlurFilter::setMaskRB;

bool uRadialBlurFilter::isOcclusionBlurWidthEnable() {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 255)) & 2) >> 1);
}

__attribute__((weak)) void uRadialBlurFilter::setOcclusionBlurWidthEnable(bool b) {
    DDON_STUB("uRadialBlurFilter::setOcclusionBlurWidthEnable")
    /* stub */
}

bool uRadialBlurFilter::isOcclusionAlphaEnable() {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 255)) & 4) >> 2);
}

__attribute__((weak)) void uRadialBlurFilter::setOcclusionAlphaEnable(bool b) {
    DDON_STUB("uRadialBlurFilter::setOcclusionAlphaEnable")
    /* stub */
}

__attribute__((weak)) void uRadialBlurFilter::drawRadialBlur(cDraw* pdraw, uFilter* pOwner, const uRadialBlurFilter::RadialBlurParam& Param, f32 Transparency) {
    DDON_STUB("uRadialBlurFilter::drawRadialBlur")
    /* stub */
}

inline uRadialBlurFilter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uRadialBlurFilter::MyDTI uRadialBlurFilter::DTI("uRadialBlurFilter", &::uFilter::DTI, 304ul, 0u, 0u);

__attribute__((weak)) MtObject* uRadialBlurFilter::MyDTI::newInstance() const {
    DDON_STUB("uRadialBlurFilter::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) void uRadialBlurFilter::RadialBlurParam::init() {
    DDON_STUB("uRadialBlurFilter::RadialBlurParam::init")
    /* stub */
}

__attribute__((weak)) void uRadialBlurFilter::RadialBlurParam::update(const uRadialBlurFilter::RadialBlurParam& Param) {
    DDON_STUB("uRadialBlurFilter::RadialBlurParam::update")
    /* stub */
}

__attribute__((weak)) void uRadialBlurFilter::RadialBlurParam::createTextures(uFilter* pOwner) {
    DDON_STUB("uRadialBlurFilter::RadialBlurParam::createTextures")
    /* stub */
}

void uRadialBlurFilter::RadialBlurParam::releaseTextures() {
    if (mpOcclusionFactor != nullptr) {
        mpOcclusionFactor->release();
        mpOcclusionFactor = nullptr;
    }
    if (mpLinearRTexture == nullptr) {
        return;
    }
    mpLinearRTexture->release();
    mpLinearRTexture = nullptr;
}

bool uRadialBlurFilter::RadialBlurParam::isTexturesCreated() const {
    if (mpOcclusionFactor != nullptr) {
        return mpLinearRTexture != nullptr;
    } else {
        return false;
    }
}

