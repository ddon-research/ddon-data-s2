// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rWeatherInfo.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "../../generated/shared/nDDOMath.h"
#include "nDDOUtility.h"
#include "nWeather.h"
#include "../../XFramework/rModel.h"
#include "../../XFramework/rScheduler.h"
#include "../../XFramework/rSky.h"
#include "../../XFramework/rSoundRequest.h"
#include "rTbl2.h"
#include "../../XFramework/rTexture.h"
#include "rWeatherEffectParam.h"
#include "rWeatherScript.h"
#include "res_ptr.h"
#include "../../XFramework/sResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

#ifndef DDON_SIGNATURE_PROBE
extern template __attribute__((noinline)) void rTbl2<cWeatherInfo>::allocData(unsigned int);
extern template __attribute__((noinline)) void rTbl2<cWeatherParamEfcInfo>::allocData(unsigned int);
#endif

const MtDTI& cWeatherCloudModel::getDTI() const {
    return cWeatherCloudModel::DTI;
}

inline void cWeatherCloudModel::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cWeatherCloudModel::DTI)->memFree(p_addr);
}

cWeatherCloudModel::~cWeatherCloudModel() {
}

__attribute__((weak)) void cWeatherCloudModel::load(MtDataReader& r) {
    char t0[64];
    const MtDTI* t1;
    r.readString(t0, 64u);
    if (t0[0] != '\0') {
        t1 = MtDTI::from(t0, cResource::DTI);
        r.readString(t0, 64u);
        mpModel.mpPtr = static_cast<rModel*>(sResource::getInstance()->create(*t1, t0, 1u));
    }
    nDDOIO::readData(r, mColorType);
    nDDOIO::readData(r, mSunColorScale);
    nDDOIO::readData(r, mSaturationScale);
    nDDOIO::readData(r, mIntensityScale);
    nDDOIO::readData(r, mFogMulRate);
    nDDOIO::readData(r, mFogAddRate);
    nDDOIO::readData(r, mViewType);
}

inline cWeatherCloudModel::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWeatherCloudModel::MyDTI cWeatherCloudModel::DTI("cWeatherCloudModel", &::cWeatherObjectRes::DTI, 48ul, 0u, 0u);

MtObject* cWeatherCloudModel::MyDTI::newInstance() const {
    return new (16u) cWeatherCloudModel;
}

const MtDTI& cWeatherFogInfo::getDTI() const {
    return cWeatherFogInfo::DTI;
}

inline void* cWeatherFogInfo::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cWeatherFogInfo::DTI)->memAlloc(sz, align, cWeatherFogInfo::DTI.getID());
}

inline void cWeatherFogInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cWeatherFogInfo::DTI)->memFree(p_addr);
}

__attribute__((weak)) void cWeatherFogInfo::lerp(cWeatherFogInfo* pDst, const cWeatherFogInfo& a, const cWeatherFogInfo& b, f32 rate) {
    DDON_STUB("cWeatherFogInfo::lerp")
    /* stub */
}

inline cWeatherFogInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWeatherFogInfo::MyDTI cWeatherFogInfo::DTI("cWeatherFogInfo", &::cWeatherObjectRes::DTI, 48ul, 0u, 0u);

MtObject* cWeatherFogInfo::MyDTI::newInstance() const {
    return new (16u) cWeatherFogInfo;
}

const MtDTI& cWeatherInfo::getDTI() const {
    return cWeatherInfo::DTI;
}

inline void cWeatherInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cWeatherInfo::DTI)->memFree(p_addr);
}

cWeatherInfo::cWeatherInfo() {
    mID = 0;
    mToFrame = 200.0f;
    mWaterLRate = 1.0f;
}

cWeatherInfo::~cWeatherInfo() {
}

inline cWeatherInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWeatherInfo::MyDTI cWeatherInfo::DTI("cWeatherInfo", &::cWeatherObjectRes::DTI, 304ul, 0u, 0u);

__attribute__((weak)) MtObject* cWeatherInfo::MyDTI::newInstance() const {
    DDON_STUB("cWeatherInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cWeatherParam::getDTI() const {
    return cWeatherParam::DTI;
}

inline void* cWeatherParam::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cWeatherParam::DTI)->memAlloc(sz, align, cWeatherParam::DTI.getID());
}

inline void cWeatherParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cWeatherParam::DTI)->memFree(p_addr);
}

cWeatherParam::cWeatherParam() {
    mSunColor.x = 21.6f;
    mSunColor.y = 23.49f;
    mSunColor.z = 27.0f;
    mSunColor.pad_ = 0.0f;
    mMieScattering.x = 7.554876f;
    mMieScattering.y = 7.554876f;
    mMieScattering.z = 7.554876f;
    mMieScattering.pad_ = 0.0f;
    mMieDensity = 1.0f;
    mCloudHeight = 4000.0f;
    mCloudiness = 0.0f;
    mCloudThickness = 100.0f;
    mCloudScattering = 0.0f;
    mCloudEccentricity = 0.4f;
    mMoonLRate = 1.0f;
    mSunIntensityRate = 1.0f;
    mEnvMapBaseScale = 1.0f;
    mFogDensity = 1.0f;
}

__attribute__((weak)) void cWeatherParam::lerp(cWeatherParam* pDst, const cWeatherParam& a, const cWeatherParam& b, f32 rate) {
    DDON_STUB("cWeatherParam::lerp")
    /* stub */
}

__attribute__((weak)) void cWeatherParam::setupDefault(cWeatherParam* pDst) {
    DDON_STUB("cWeatherParam::setupDefault")
    /* stub */
}

inline cWeatherParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWeatherParam::MyDTI cWeatherParam::DTI("cWeatherParam", &::cWeatherObjectRes::DTI, 96ul, 0u, 0u);

MtObject* cWeatherParam::MyDTI::newInstance() const {
    return new (16u) cWeatherParam;
}

const MtDTI& cWeatherParamEfcInfo::getDTI() const {
    return cWeatherParamEfcInfo::DTI;
}

inline void cWeatherParamEfcInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cWeatherParamEfcInfo::DTI)->memFree(p_addr);
}

cWeatherParamEfcInfo::~cWeatherParamEfcInfo() {
}

inline cWeatherParamEfcInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWeatherParamEfcInfo::MyDTI cWeatherParamEfcInfo::DTI("cWeatherParamEfcInfo", &::cWeatherObjectRes::DTI, 24ul, 0u, 0u);

__attribute__((weak)) MtObject* cWeatherParamEfcInfo::MyDTI::newInstance() const {
    return new (16u) cWeatherParamEfcInfo;
}

const MtDTI& cWeatherParamInfo::getDTI() const {
    return cWeatherParamInfo::DTI;
}

inline void cWeatherParamInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cWeatherParamInfo::DTI)->memFree(p_addr);
}

cWeatherParamInfo::~cWeatherParamInfo() {
}

inline cWeatherParamInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cWeatherParamInfo::MyDTI cWeatherParamInfo::DTI("cWeatherParamInfo", &::cWeatherObjectRes::DTI, 240ul, 0u, 0u);

__attribute__((weak)) MtObject* cWeatherParamInfo::MyDTI::newInstance() const {
    return new (16u) cWeatherParamInfo;
}

const MtDTI& rWeatherFogInfo::getDTI() const {
    return rWeatherFogInfo::DTI;
}

inline void* rWeatherFogInfo::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rWeatherFogInfo::DTI)->memAlloc(sz, align, rWeatherFogInfo::DTI.getID());
}

inline void rWeatherFogInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rWeatherFogInfo::DTI)->memFree(p_addr);
}

bool rWeatherFogInfo::loadData(MtDataReader& in, cWeatherFogInfo* pData) {
    pData->mTime = in.readU32();
    pData->mStart = in.readF32();
    pData->mEnd = in.readF32();
    pData->mExponentDensity = in.readF32();
    pData->mColor = in.readV3();
    return true;
}

MT_CTSTR rWeatherFogInfo::getExt() const {
    return "wtf";
}

u32 rWeatherFogInfo::getDataVersion() const {
    return 3;
}

inline rWeatherFogInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rWeatherFogInfo::MyDTI rWeatherFogInfo::DTI("rWeatherFogInfo", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rWeatherFogInfo::MyDTI::newInstance() const {
    return new (16u) rWeatherFogInfo;
}

const MtDTI& rWeatherInfoTbl::getDTI() const {
    return rWeatherInfoTbl::DTI;
}

inline void* rWeatherInfoTbl::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rWeatherInfoTbl::DTI)->memAlloc(sz, align, rWeatherInfoTbl::DTI.getID());
}

inline void rWeatherInfoTbl::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rWeatherInfoTbl::DTI)->memFree(p_addr);
}

bool rWeatherInfoTbl::loadData(MtDataReader& in, cWeatherInfo* pData) {
    pData->mID = in.readU16();
    pData->mToFrame = in.readF32();
    pData->mWaterLRate = in.readF32();
    cWeatherAttrFlag* held0 = &pData->mWeatherAttrFlag;
    u32 t0 = in.readU32();
    in.read(static_cast<void*>(held0), t0 * 4u);
    pData->mScriptsEfc.load(in);
    pData->mScriptsSound.load(in);
    return true;
}

MT_CTSTR rWeatherInfoTbl::getExt() const {
    return "wta";
}

u32 rWeatherInfoTbl::getDataVersion() const {
    return 16;
}

inline rWeatherInfoTbl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rWeatherInfoTbl::MyDTI rWeatherInfoTbl::DTI("rWeatherInfoTbl", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rWeatherInfoTbl::MyDTI::newInstance() const {
    return new (16u) rWeatherInfoTbl;
}

const MtDTI& rWeatherParamEfcInfo::getDTI() const {
    return rWeatherParamEfcInfo::DTI;
}

inline void* rWeatherParamEfcInfo::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rWeatherParamEfcInfo::DTI)->memAlloc(sz, align, rWeatherParamEfcInfo::DTI.getID());
}

inline void rWeatherParamEfcInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rWeatherParamEfcInfo::DTI)->memFree(p_addr);
}

__attribute__((weak)) bool rWeatherParamEfcInfo::loadData(MtDataReader& in, cWeatherParamEfcInfo* pData) {
    nDDOIO::readData(in, pData->mWeatherID);
    char t0[64];
    const MtDTI* t1;
    in.readString(t0, 64u);
    if (t0[0] != '\0') {
        t1 = MtDTI::from(t0, cResource::DTI);
        in.readString(t0, 64u);
        pData->mpEfcParam.mpPtr = static_cast<rWeatherEffectParam*>(sResource::getInstance()->create(*t1, t0, 1u));
    }
    return true;
}

MT_CTSTR rWeatherParamEfcInfo::getExt() const {
    return "wte";
}

u32 rWeatherParamEfcInfo::getDataVersion() const {
    return 1;
}

inline rWeatherParamEfcInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rWeatherParamEfcInfo::MyDTI rWeatherParamEfcInfo::DTI("rWeatherParamEfcInfo", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rWeatherParamEfcInfo::MyDTI::newInstance() const {
    return new (16u) rWeatherParamEfcInfo;
}

const MtDTI& rWeatherParamInfoTbl::getDTI() const {
    return rWeatherParamInfoTbl::DTI;
}

inline void* rWeatherParamInfoTbl::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rWeatherParamInfoTbl::DTI)->memAlloc(sz, align, rWeatherParamInfoTbl::DTI.getID());
}

inline void rWeatherParamInfoTbl::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rWeatherParamInfoTbl::DTI)->memFree(p_addr);
}

__attribute__((weak)) bool rWeatherParamInfoTbl::loadData(MtDataReader& in, cWeatherParamInfo* pData) {
    pData->mWeatherParam.load(in);
    nDDOIO::readData(in, pData->mWeatherID);
    nDDOIO::readData(in, pData->mWeatherSoundVolume);
    nDDOIO::readData(in, pData->mWeatherStarIntensity);
    nDDOIO::readData(in, pData->mLightMainIntensityScale);
    nDDOIO::readData(in, pData->mLightMainSatuationScale);
    nDDOIO::readData(in, pData->mLightSubDayColor);
    nDDOIO::readData(in, pData->mLightHemiDayColor);
    nDDOIO::readData(in, pData->mLightHemiDayRevColor);
    char t0[64];
    const MtDTI* t1;
    in.readString(t0, 64u);
    if (t0[0] != '\0') {
        t1 = MtDTI::from(t0, cResource::DTI);
        in.readString(t0, 64u);
        pData->mpFogParam.mpPtr = static_cast<rWeatherFogInfo*>(sResource::getInstance()->create(*t1, t0, 1u));
    }
    in.readString(t0, 64u);
    if (t0[0] != '\0') {
        t1 = MtDTI::from(t0, cResource::DTI);
        in.readString(t0, 64u);
        pData->mpSoundReq.mpPtr = static_cast<rSoundRequest*>(sResource::getInstance()->create(*t1, t0, 1u));
    }
    nDDOIO::readMtArray(in, pData->mClouds);
    return true;
}

MT_CTSTR rWeatherParamInfoTbl::getExt() const {
    return "wtl";
}

u32 rWeatherParamInfoTbl::getDataVersion() const {
    return 12;
}

inline rWeatherParamInfoTbl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rWeatherParamInfoTbl::MyDTI rWeatherParamInfoTbl::DTI("rWeatherParamInfoTbl", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rWeatherParamInfoTbl::MyDTI::newInstance() const {
    return new (16u) rWeatherParamInfoTbl;
}

const MtDTI& rWeatherStageInfo::getDTI() const {
    return rWeatherStageInfo::DTI;
}

inline void rWeatherStageInfo::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rWeatherStageInfo::DTI)->memFree(p_addr);
}

rWeatherStageInfo::~rWeatherStageInfo() {
}

__attribute__((weak)) void rWeatherStageInfo::createProperty(MtPropertyList& s) {
    DDON_STUB("rWeatherStageInfo::createProperty")
    /* stub */
}

MT_CTSTR rWeatherStageInfo::getExt() const {
    return "wsi";
}

__attribute__((weak)) bool rWeatherStageInfo::load(MtStream& in) {
    char t0[64];
    const MtDTI* t1;
    MtDataReader r(in, 4096u);
    u32 magic;
    u32 version;
    nDDOIO::readData(r, magic);
    nDDOIO::readData(r, version);
    if (magic != MAGIC_NUM || version != DATA_VERSION) {
        return false;
    }
    r.readString(t0, 64u);
    if (t0[0] != '\0') {
        t1 = MtDTI::from(t0, cResource::DTI);
        r.readString(t0, 64u);
        mpSkyRes.mpPtr = static_cast<rSky*>(sResource::getInstance()->create(*t1, t0, 1u));
    }
    r.readString(t0, 64u);
    if (t0[0] != '\0') {
        t1 = MtDTI::from(t0, cResource::DTI);
        r.readString(t0, 64u);
        mpRefSkyRes.mpPtr = static_cast<rSky*>(sResource::getInstance()->create(*t1, t0, 1u));
    }
    r.readString(t0, 64u);
    if (t0[0] != '\0') {
        t1 = MtDTI::from(t0, cResource::DTI);
        r.readString(t0, 64u);
        mpModelScheduler.mpPtr = static_cast<rScheduler*>(sResource::getInstance()->create(*t1, t0, 1u));
    }
    r.readString(t0, 64u);
    if (t0[0] != '\0') {
        t1 = MtDTI::from(t0, cResource::DTI);
        r.readString(t0, 64u);
        mpStarModel.mpPtr = static_cast<rModel*>(sResource::getInstance()->create(*t1, t0, 1u));
    }
    r.readString(t0, 64u);
    if (t0[0] != '\0') {
        t1 = MtDTI::from(t0, cResource::DTI);
        r.readString(t0, 64u);
        mpStarTex.mpPtr = static_cast<rTexture*>(sResource::getInstance()->create(*t1, t0, 1u));
    }
    r.readString(t0, 64u);
    if (t0[0] != '\0') {
        t1 = MtDTI::from(t0, cResource::DTI);
        r.readString(t0, 64u);
        mpStarCatalog.mpPtr = static_cast<rStarCatalog*>(sResource::getInstance()->create(*t1, t0, 1u));
    }
    nDDOIO::readData(r, mStarSize);
    nDDOIO::readData(r, mStarrySkyIntensity);
    nDDOIO::readData(r, mStarTwinkleAmplitude);
    for (u32 i = 0; i < 2; i++) {
        nDDOIO::readData(r, mEnvMapBaseColor[i]);
    }
    for (u32 i = 0; i < 2; i++) {
        nDDOIO::readData(r, mEnvMapBlendColorScale[i]);
    }
    return true;
}

__attribute__((weak)) bool rWeatherStageInfo::save(MtStream& out) {
    MtDataWriter w(out, 4096u, 4096u);
    u32 magic = MAGIC_NUM;
    u32 version = DATA_VERSION;
    nDDOIO::writeData(w, magic);
    nDDOIO::writeData(w, version);
    cResource* t0;
    t0 = mpSkyRes.mpPtr;
    if (t0 != nullptr) {
        w.writeString(t0->getDTI().getName());
        w.writeString(t0->getPath());
    } else {
        w.writeString("");
    }
    t0 = mpRefSkyRes.mpPtr;
    if (t0 != nullptr) {
        w.writeString(t0->getDTI().getName());
        w.writeString(t0->getPath());
    } else {
        w.writeString("");
    }
    t0 = mpModelScheduler.mpPtr;
    if (t0 != nullptr) {
        w.writeString(t0->getDTI().getName());
        w.writeString(t0->getPath());
    } else {
        w.writeString("");
    }
    t0 = mpStarModel.mpPtr;
    if (t0 != nullptr) {
        w.writeString(t0->getDTI().getName());
        w.writeString(t0->getPath());
    } else {
        w.writeString("");
    }
    t0 = mpStarTex.mpPtr;
    if (t0 != nullptr) {
        w.writeString(t0->getDTI().getName());
        w.writeString(t0->getPath());
    } else {
        w.writeString("");
    }
    t0 = mpStarCatalog.mpPtr;
    if (t0 != nullptr) {
        w.writeString(t0->getDTI().getName());
        w.writeString(t0->getPath());
    } else {
        w.writeString("");
    }
    nDDOIO::writeData(w, mStarSize);
    nDDOIO::writeData(w, mStarrySkyIntensity);
    nDDOIO::writeData(w, mStarTwinkleAmplitude);
    for (u32 i = 0; i < 2; i++) {
        MtFloat3 t1;
        t1.x = mEnvMapBaseColor[i].x;
        t1.y = mEnvMapBaseColor[i].y;
        t1.z = mEnvMapBaseColor[i].z;
        w.writeV3(t1);
    }
    for (u32 i = 0; i < 2; i++) {
        nDDOIO::writeData(w, mEnvMapBlendColorScale[i]);
    }
    return true;
}

inline rWeatherStageInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rWeatherStageInfo::MyDTI rWeatherStageInfo::DTI("rWeatherStageInfo", &::cResource::DTI, 224ul, 0u, 0u);

__attribute__((weak)) MtObject* rWeatherStageInfo::MyDTI::newInstance() const {
    return new (16u) rWeatherStageInfo;
}

template MtTypedArray<cWeatherCloudModel>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<cWeatherCloudModel>&);

template cWeatherFogInfo* rTbl2<cWeatherFogInfo>::getData(unsigned int);

template cWeatherInfo* rTbl2<cWeatherInfo>::getData(unsigned int);

template cWeatherParamEfcInfo* rTbl2<cWeatherParamEfcInfo>::getData(unsigned int);

template cWeatherParamInfo* rTbl2<cWeatherParamInfo>::getData(unsigned int);

template bool rTbl2<cWeatherFogInfo>::load(MtStream&);

template bool rTbl2<cWeatherInfo>::load(MtStream&);

template bool rTbl2<cWeatherParamEfcInfo>::load(MtStream&);

template bool rTbl2<cWeatherParamInfo>::load(MtStream&);

template bool rTbl2<cWeatherFogInfo>::loadCore(MtDataReader&);

template bool rTbl2<cWeatherInfo>::loadCore(MtDataReader&);

template bool rTbl2<cWeatherParamEfcInfo>::loadCore(MtDataReader&);

template bool rTbl2<cWeatherParamInfo>::loadCore(MtDataReader&);

template const cWeatherFogInfo* rTbl2<cWeatherFogInfo>::getData(unsigned int) const;

template const cWeatherInfo* rTbl2<cWeatherInfo>::getData(unsigned int) const;

template const cWeatherParamEfcInfo* rTbl2<cWeatherParamEfcInfo>::getData(unsigned int) const;

template const cWeatherParamInfo* rTbl2<cWeatherParamInfo>::getData(unsigned int) const;

template unsigned int rTbl2<cWeatherFogInfo>::getDataNum() const;

template unsigned int rTbl2<cWeatherInfo>::getDataNum() const;

template unsigned int rTbl2<cWeatherParamEfcInfo>::getDataNum() const;

template unsigned int rTbl2<cWeatherParamInfo>::getDataNum() const;

template rTbl2<cWeatherFogInfo>::~rTbl2();

template rTbl2<cWeatherInfo>::~rTbl2();

template rTbl2<cWeatherParamEfcInfo>::~rTbl2();

template rTbl2<cWeatherParamInfo>::~rTbl2();

