// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rWeatherEffectParam.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "../../generated/shared/nDDOMath.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cEffectCorrectParam::getDTI() const {
    return cEffectCorrectParam::DTI;
}

inline void cEffectCorrectParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cEffectCorrectParam::DTI)->memFree(p_addr);
}

cEffectCorrectParam::cEffectCorrectParam() {
    mTime = 0;
    mEfcColorParam.Color.rgba = MtColor::White.rgba;
    mEfcColorParam.ColorBlend = 0.0f;
    mEfcColorParam.Intensity = 1.0f;
    mEfcColorParam.IntensityBlend = 0.0f;
    mEfcColorParam.EnvMapPowerScale = 1.0f;
    mEfcColorParam.ShadowColor.rgba = MtColor::White.rgba;
    mEfcColorParam.ShadowColorBlend = 0.0f;
    mEfcColorParam.ShadowIntensity = 1.0f;
    mEfcColorParam.ShadowIntensityBlend = 0.0f;
}

cEffectCorrectParam::~cEffectCorrectParam() {
}

void cEffectCorrectParam::load(MtDataReader& r) {
    mTime = r.readU32();
    mEfcColorParam.Color.rgba = r.readU32();
    mEfcColorParam.ColorBlend = r.readF32();
    mEfcColorParam.Intensity = r.readF32();
    mEfcColorParam.IntensityBlend = r.readF32();
    mEfcColorParam.EnvMapPowerScale = r.readF32();
    mEfcColorParam.ShadowColor.rgba = r.readU32();
    mEfcColorParam.ShadowColorBlend = r.readF32();
    mEfcColorParam.ShadowIntensity = r.readF32();
    mEfcColorParam.ShadowIntensityBlend = r.readF32();
}

void cEffectCorrectParam::lerpEffectColorParam(stEffectColorParam* pDst, const stEffectColorParam& a, const stEffectColorParam& b, f32 rate) {
    pDst->Color.rgba = static_cast<u32>(((static_cast<unsigned long>((((((b.Color.rgba >> 8) & 255u) - ((a.Color.rgba >> 8) & 255u)) * static_cast<int>(256.0f * rate)) + (a.Color.rgba & 0xFFFFFF00u)) & 0xFF00u) | static_cast<unsigned long>((((a.Color.rgba >> 16) * 0x10000u) + ((((((b.Color.rgba >> 16) & 255u) - ((a.Color.rgba >> 16) & 255u)) * static_cast<int>(256.0f * rate)) >> 8) * 0x10000u)) & 0xFF0000u)) | static_cast<unsigned long>(static_cast<unsigned char>(a.Color.rgba + (static_cast<unsigned int>((static_cast<unsigned char>(b.Color.rgba) - static_cast<unsigned char>(a.Color.rgba)) * static_cast<int>(256.0f * rate)) >> 8)))) | static_cast<unsigned long>(((a.Color.rgba >> 24) * 0x1000000u) + (((((b.Color.rgba >> 24) - (a.Color.rgba >> 24)) * static_cast<int>(256.0f * rate)) >> 8) * 0x1000000u)));
    pDst->ColorBlend = nDDOMath::lerp(a.ColorBlend, b.ColorBlend, rate);
    pDst->Intensity = nDDOMath::lerp(a.Intensity, b.Intensity, rate);
    pDst->IntensityBlend = nDDOMath::lerp(a.IntensityBlend, b.IntensityBlend, rate);
    pDst->EnvMapPowerScale = nDDOMath::lerp(a.EnvMapPowerScale, b.EnvMapPowerScale, rate);
    pDst->ShadowColor.rgba = static_cast<u32>(((static_cast<unsigned long>((((((b.ShadowColor.rgba >> 8) & 255u) - ((a.ShadowColor.rgba >> 8) & 255u)) * static_cast<int>(256.0f * rate)) + (a.ShadowColor.rgba & 0xFFFFFF00u)) & 0xFF00u) | static_cast<unsigned long>((((a.ShadowColor.rgba >> 16) * 0x10000u) + ((((((b.ShadowColor.rgba >> 16) & 255u) - ((a.ShadowColor.rgba >> 16) & 255u)) * static_cast<int>(256.0f * rate)) >> 8) * 0x10000u)) & 0xFF0000u)) | static_cast<unsigned long>(static_cast<unsigned char>(a.ShadowColor.rgba + (static_cast<unsigned int>((static_cast<unsigned char>(b.ShadowColor.rgba) - static_cast<unsigned char>(a.ShadowColor.rgba)) * static_cast<int>(256.0f * rate)) >> 8)))) | static_cast<unsigned long>(((a.ShadowColor.rgba >> 24) * 0x1000000u) + (((((b.ShadowColor.rgba >> 24) - (a.ShadowColor.rgba >> 24)) * static_cast<int>(256.0f * rate)) >> 8) * 0x1000000u)));
    pDst->ShadowColorBlend = nDDOMath::lerp(a.ShadowColorBlend, b.ShadowColorBlend, rate);
    pDst->ShadowIntensity = nDDOMath::lerp(a.ShadowIntensity, b.ShadowIntensity, rate);
    pDst->ShadowIntensityBlend = nDDOMath::lerp(a.ShadowIntensityBlend, b.ShadowIntensityBlend, rate);
}

inline cEffectCorrectParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEffectCorrectParam::MyDTI cEffectCorrectParam::DTI("cEffectCorrectParam", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cEffectCorrectParam::MyDTI::newInstance() const {
    return new (16u) cEffectCorrectParam;
}

const MtDTI& rWeatherEffectParam::getDTI() const {
    return rWeatherEffectParam::DTI;
}

inline void rWeatherEffectParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rWeatherEffectParam::DTI)->memFree(p_addr);
}

__attribute__((noinline)) rWeatherEffectParam::~rWeatherEffectParam() {
    unsigned int i0_10 = 0;
    u32 v1_0;
    unsigned int i1_3;
    u32 v2_0;
    u32 v3_1;
    for (;;) {
        if (mpParamList[i0_10].mAutoDelete) {
            if (mpParamList[i0_10].mLength == 0) {
                v3_1 = 0;
            } else {
                v1_0 = mpParamList[i0_10].mLength;
                i1_3 = 0;
                for (;;) {
                    if (mpParamList[i0_10].mpArray[i1_3] == nullptr) {
                        v2_0 = v1_0;
                    } else {
                        delete mpParamList[i0_10].mpArray[i1_3];
                        v2_0 = mpParamList[i0_10].mLength;
                    }
                    if ((i1_3 + 1u) < v2_0) {
                        v1_0 = v2_0;
                        i1_3 += 1u;
                    } else {
                        v3_1 = v2_0;
                        break;
                    }
                }
            }
            memset(static_cast<void*>(mpParamList[i0_10].mpArray), 0, static_cast<size_t>(v3_1) * 8);
        }
        mpParamList[i0_10].mLength = 0;
        if ((i0_10 + 1u) != 7) {
            i0_10 = i0_10 + 1u;
        } else {
            break;
        }
    }
}

bool rWeatherEffectParam::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if ((&r)->readU32() == 0x706577) {
        if ((&r)->readU32() == 3) {
            nDDOIO::readMtArray(r, mpParamList[0]);
            nDDOIO::readMtArray(r, mpParamList[1]);
            nDDOIO::readMtArray(r, mpParamList[2]);
            nDDOIO::readMtArray(r, mpParamList[3]);
            nDDOIO::readMtArray(r, mpParamList[4]);
            nDDOIO::readMtArray(r, mpParamList[5]);
            nDDOIO::readMtArray(r, mpParamList[6]);
            return true;
        }
    }
    return false;
}

__attribute__((weak)) bool rWeatherEffectParam::save(MtStream& out) {
    MtDataWriter w(out, 4096u, 4096u);
    nDDOIO::writeData(w, 0x706577u);
    nDDOIO::writeData(w, 3u);
    for (u32 type = 0; type < 7; type++) {
        (&w)->writeU32(mpParamList[type].length());
        for (u32 t0 = 0; t0 < mpParamList[type].length(); t0++) {
            static_cast<cEffectCorrectParam*>(mpParamList[type].getBuffer()[(s32)t0])->save(w);
        }
    }
    return true;
}

MT_CTSTR rWeatherEffectParam::getExt() const {
    return "wep";
}

const cEffectCorrectParam* rWeatherEffectParam::getCorrectParam(u32 type, u32 index) const {
    if (type <= 6u) {
        if (index < mpParamList[type].mLength) {
            return static_cast<const cEffectCorrectParam*>(mpParamList[type].mpArray[index]);
        }
    }
    return nullptr;
}

u32 rWeatherEffectParam::getCorrectParamNum(u32 type) const {
    if (type <= 6u) {
        return mpParamList[type].mLength;
    } else {
        return 0;
    }
}

__attribute__((weak)) bool rWeatherEffectParam::calcEffectColorParam(stEffectColorParam* pDst, u32 ctype, u32 wtTime) {
    DDON_STUB("rWeatherEffectParam::calcEffectColorParam")
    return {};
}

inline rWeatherEffectParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rWeatherEffectParam::MyDTI rWeatherEffectParam::DTI("rWeatherEffectParam", &::cResource::DTI, 336ul, 0u, 0u);

__attribute__((weak)) MtObject* rWeatherEffectParam::MyDTI::newInstance() const {
    return new (16u) rWeatherEffectParam;
}

template MtTypedArray<cEffectCorrectParam>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<cEffectCorrectParam>&);

