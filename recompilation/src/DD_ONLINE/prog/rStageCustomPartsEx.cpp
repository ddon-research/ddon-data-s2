// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rStageCustomPartsEx.h"
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
#include "../../MT/MtString.h"
#include "cAreaHit.h"
#include "../../generated/shared/nDDOIO.h"
#include "rStageCustomParts.h"
#include "uSkyFog.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rStageCustomPartsEx::getDTI() const {
    return rStageCustomPartsEx::DTI;
}

inline void* rStageCustomPartsEx::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rStageCustomPartsEx::DTI)->memAlloc(sz, align, rStageCustomPartsEx::DTI.getID());
}

inline void rStageCustomPartsEx::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rStageCustomPartsEx::DTI)->memFree(p_addr);
}

rStageCustomPartsEx::~rStageCustomPartsEx() {
    destruct();
}

MT_CTSTR rStageCustomPartsEx::getExt() const {
    return "scpx";
}

__attribute__((weak)) void rStageCustomPartsEx::destruct() {
    InfoEx* pArrayInfoEx = static_cast<InfoEx*>(this->mpArrayInfo);
    for (u32 i = 0; i < this->mArrayInfoNum; i++) {
        InfoEx* p = &pArrayInfoEx[i];
        p->~InfoEx();
    }
    MtMemoryAllocator::getAllocator(rStageCustomPartsEx::DTI)->memFree(static_cast<void*>(this->mpArrayInfo));
    this->mpArrayInfo = nullptr;
    this->mArrayInfoNum = 0;
    
    FilterEx* pArrayFilterEx = static_cast<FilterEx*>(this->mpArrayFilter);
    for (u32 i = 0; i < this->mArrayFilterNum; i++) {
        FilterEx* p = &pArrayFilterEx[i];
        p->~FilterEx();
    }
    MtMemoryAllocator::getAllocator(rStageCustomPartsEx::DTI)->memFree(static_cast<void*>(this->mpArrayFilter));
    this->mpArrayFilter = nullptr;
    this->mArrayFilterNum = 0;
    
    for (u32 i = 0; i < this->mArrayColorFogNum; i++) {
        this->mpArrayColorFog[i].~ColorFog();
    }
    MtMemoryAllocator::getAllocator(rStageCustomPartsEx::DTI)->memFree(static_cast<void*>(this->mpArrayColorFog));
    this->mpArrayColorFog = nullptr;
    this->mArrayColorFogNum = 0;
    
    for (u32 i = 0; i < this->mArrayHemiSphLightNum; i++) {
        this->mpArrayHemiSphLight[i].~HemiSphLight();
    }
    MtMemoryAllocator::getAllocator(rStageCustomPartsEx::DTI)->memFree(static_cast<void*>(this->mpArrayHemiSphLight));
    this->mpArrayHemiSphLight = nullptr;
    this->mArrayHemiSphLightNum = 0;
    
    for (u32 i = 0; i < this->mArrayInfiLightNum; i++) {
        this->mpArrayInfiLight[i].~InfiLight();
    }
    MtMemoryAllocator::getAllocator(rStageCustomPartsEx::DTI)->memFree(static_cast<void*>(this->mpArrayInfiLight));
    this->mpArrayInfiLight = nullptr;
    this->mArrayInfiLightNum = 0;
    
    for (u32 i = 0; i < this->mArrayPatternNum; i++) {
        this->mpArrayPattern[i].~Pattern();
    }
    MtMemoryAllocator::getAllocator(rStageCustomPartsEx::DTI)->memFree(static_cast<void*>(this->mpArrayPattern));
    this->mpArrayPattern = nullptr;
    this->mArrayPatternNum = 0;
}

__attribute__((weak)) bool rStageCustomPartsEx::load(MtStream& in) {
    MtDataReader r(in, 0x1000);
    if (r.readU32() != 0x78706373) {
        return false;
    }
    u32 ver = r.readU32();
    if (ver != DATA_VERSION) {
        return false;
    }
    mParam.load(r);
    
    const u32 nArrayInfo = r.readU32();
    void* pArrayInfo = nullptr;
    if (nArrayInfo != 0) {
        pArrayInfo = getAllocator()->memAlloc(sizeof(InfoEx) * nArrayInfo, 16);
        for (u32 i = 0; i < nArrayInfo; ++i) {
            InfoEx* pInfo = new (&static_cast<InfoEx*>(pArrayInfo)[i]) InfoEx();
            pInfo->load(r);
        }
    }
    mpArrayInfo = static_cast<Info*>(pArrayInfo);
    mArrayInfoNum = nArrayInfo;
    
    const u32 nArrayFilter = r.readU32();
    void* pArrayFilter = nullptr;
    if (nArrayFilter != 0) {
        pArrayFilter = getAllocator()->memAlloc(sizeof(FilterEx) * nArrayFilter, 16);
        for (u32 i = 0; i < nArrayFilter; ++i) {
            FilterEx* pFilter = new (&static_cast<FilterEx*>(pArrayFilter)[i]) FilterEx();
            pFilter->load(r);
        }
    }
    mpArrayFilter = static_cast<Filter*>(pArrayFilter);
    mArrayFilterNum = nArrayFilter;
    
    const u32 nArrayColorFog = r.readU32();
    void* pArrayColorFog = nullptr;
    if (nArrayColorFog != 0) {
        pArrayColorFog = getAllocator()->memAlloc(sizeof(ColorFog) * nArrayColorFog, 16);
        for (u32 i = 0; i < nArrayColorFog; ++i) {
            ColorFog* pColorFog = new (&static_cast<ColorFog*>(pArrayColorFog)[i]) ColorFog();
            pColorFog->load(r);
        }
    }
    mpArrayColorFog = static_cast<ColorFog*>(pArrayColorFog);
    mArrayColorFogNum = nArrayColorFog;
    
    const u32 nArrayHemiSphLight = r.readU32();
    void* pArrayHemiSphLight = nullptr;
    if (nArrayHemiSphLight != 0) {
        pArrayHemiSphLight = getAllocator()->memAlloc(sizeof(HemiSphLight) * nArrayHemiSphLight, 16);
        for (u32 i = 0; i < nArrayHemiSphLight; ++i) {
            HemiSphLight* pHemiSphLight = new (&static_cast<HemiSphLight*>(pArrayHemiSphLight)[i]) HemiSphLight();
            pHemiSphLight->load(r);
        }
    }
    mpArrayHemiSphLight = static_cast<HemiSphLight*>(pArrayHemiSphLight);
    mArrayHemiSphLightNum = nArrayHemiSphLight;
    
    const u32 nArrayInfiLight = r.readU32();
    void* pArrayInfiLight = nullptr;
    if (nArrayInfiLight != 0) {
        pArrayInfiLight = getAllocator()->memAlloc(sizeof(InfiLight) * nArrayInfiLight, 16);
        for (u32 i = 0; i < nArrayInfiLight; ++i) {
            InfiLight* pInfiLight = new (&static_cast<InfiLight*>(pArrayInfiLight)[i]) InfiLight();
            pInfiLight->load(r);
        }
    }
    mpArrayInfiLight = static_cast<InfiLight*>(pArrayInfiLight);
    mArrayInfiLightNum = nArrayInfiLight;
    
    const u32 nArrayPattern = r.readU32();
    void* pArrayPattern = nullptr;
    if (nArrayPattern != 0) {
        pArrayPattern = getAllocator()->memAlloc(sizeof(Pattern) * nArrayPattern, 16);
        for (u32 i = 0; i < nArrayPattern; ++i) {
            Pattern* pPattern = new (&static_cast<Pattern*>(pArrayPattern)[i]) Pattern();
            pPattern->load(r);
        }
    }
    mpArrayPattern = static_cast<Pattern*>(pArrayPattern);
    mArrayPatternNum = nArrayPattern;
    
    return true;
}

__attribute__((weak)) bool rStageCustomPartsEx::save(MtStream& out) {
        MtDataWriter w(out, 0x1000, 0x1000);
        MtFloat3 t1;
        w.writeU32(0x78706373);
        w.writeU32(DATA_VERSION);
        mParam.save(w);
        w.writeU32(mArrayInfoNum);
        InfoEx* pArrayInfoEx = (InfoEx*)mpArrayInfo;
        for (u32 i = 0; i < mArrayInfoNum; ++i) {
            InfoEx* pInfo = &pArrayInfoEx[i];
            pInfo->Info::save(w);
            nDDOIO::writeMtArray(w, pInfo->mAreaParamList);
        }
        w.writeU32(mArrayFilterNum);
        FilterEx* pArrayFilterEx = (FilterEx*)mpArrayFilter;
        for (u32 i = 0; i < mArrayFilterNum; ++i) {
            FilterEx* pFilter = &pArrayFilterEx[i];
            pFilter->Filter::save(w);
        }
        w.writeU32(mArrayColorFogNum);
        for (u32 i = 0; i < mArrayColorFogNum; ++i) {
            ColorFog* pColorFog = &mpArrayColorFog[i];
            pColorFog->save(w);
        }
        w.writeU32(mArrayHemiSphLightNum);
        for (u32 i = 0; i < mArrayHemiSphLightNum; ++i) {
            HemiSphLight* pHemiSphLight = &mpArrayHemiSphLight[i];
            t1.x = pHemiSphLight->mLightColor.x;
            t1.y = pHemiSphLight->mLightColor.y;
            t1.z = pHemiSphLight->mLightColor.z;
            w.writeV3(t1);
            t1.x = pHemiSphLight->mRevColor.x;
            t1.y = pHemiSphLight->mRevColor.y;
            t1.z = pHemiSphLight->mRevColor.z;
            w.writeV3(t1);
            t1.x = pHemiSphLight->mNightColor.x;
            t1.y = pHemiSphLight->mNightColor.y;
            t1.z = pHemiSphLight->mNightColor.z;
            w.writeV3(t1);
            t1.x = pHemiSphLight->mNightRevColor.x;
            t1.y = pHemiSphLight->mNightRevColor.y;
            t1.z = pHemiSphLight->mNightRevColor.z;
            w.writeV3(t1);
        }
        w.writeU32(mArrayInfiLightNum);
        for (u32 i = 0; i < mArrayInfiLightNum; ++i) {
            InfiLight* pInfiLight = &mpArrayInfiLight[i];
            t1.x = pInfiLight->mLightColor.x;
            t1.y = pInfiLight->mLightColor.y;
            t1.z = pInfiLight->mLightColor.z;
            w.writeV3(t1);
            t1.x = pInfiLight->mNightColor.x;
            t1.y = pInfiLight->mNightColor.y;
            t1.z = pInfiLight->mNightColor.z;
            w.writeV3(t1);
        }
        w.writeU32(mArrayPatternNum);
        for (u32 i = 0; i < mArrayPatternNum; ++i) {
            Pattern* pPattern = &mpArrayPattern[i];
            nDDOIO::writeData(w, pPattern->mColorFogNo);
            nDDOIO::writeData(w, pPattern->mHemiSphLightNo);
            nDDOIO::writeData(w, pPattern->mInfiLightNo);
        }
        return true;
}

__attribute__((weak)) rStageCustomParts::Info* rStageCustomPartsEx::getInfo(u32 index) const {
    DDON_STUB("rStageCustomPartsEx::getInfo")
    return nullptr;
}

u32 rStageCustomPartsEx::getInfoNum() const {
    return mArrayInfoNum;
}

__attribute__((weak)) rStageCustomParts::Filter* rStageCustomPartsEx::getFilter(u32 index) const {
    DDON_STUB("rStageCustomPartsEx::getFilter")
    return nullptr;
}

u32 rStageCustomPartsEx::getFilterNum() const {
    return mArrayFilterNum;
}

rStageCustomPartsEx::Pattern* rStageCustomPartsEx::getPattern(u32 index) const {
    if (index < getPatternNum()) {
        return &mpArrayPattern[index];
    } else {
        return nullptr;
    }
}

u32 rStageCustomPartsEx::getPatternNum() const {
    return mArrayPatternNum;
}

rStageCustomPartsEx::ColorFog* rStageCustomPartsEx::getColorFog(u32 index) const {
    if (index < getColorFogNum()) {
        return &mpArrayColorFog[index];
    } else {
        return nullptr;
    }
}

u32 rStageCustomPartsEx::getColorFogNum() const {
    return mArrayColorFogNum;
}

rStageCustomPartsEx::HemiSphLight* rStageCustomPartsEx::getHemiSphLight(u32 index) const {
    if (index < getHemiSphLightNum()) {
        return &mpArrayHemiSphLight[index];
    } else {
        return nullptr;
    }
}

u32 rStageCustomPartsEx::getHemiSphLightNum() const {
    return mArrayHemiSphLightNum;
}

rStageCustomPartsEx::InfiLight* rStageCustomPartsEx::getInfiLight(u32 index) const {
    if (index < getInfiLightNum()) {
        return &mpArrayInfiLight[index];
    } else {
        return nullptr;
    }
}

u32 rStageCustomPartsEx::getInfiLightNum() const {
    return mArrayInfiLightNum;
}

rStageCustomParts::Info* rStageCustomPartsEx::searchInfo(u32 areaNo) const {
    if (getInfoNum() != 0) {
        for (unsigned int i0_3 = 0;;) {
            if (getInfo(i0_3)->mAreaNo == areaNo) {
                return getInfo(i0_3);
            } else {
                if ((i0_3 + 1u) < getInfoNum()) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
    return nullptr;
}

inline rStageCustomPartsEx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStageCustomPartsEx::MyDTI rStageCustomPartsEx::DTI("rStageCustomPartsEx", &::rStageCustomParts::DTI, 224ul, 0u, 0u);

MtObject* rStageCustomPartsEx::MyDTI::newInstance() const {
    return new (16u) rStageCustomPartsEx;
}

const MtDTI& rStageCustomPartsEx::Pattern::getDTI() const {
    return rStageCustomPartsEx::Pattern::DTI;
}

inline void* rStageCustomPartsEx::Pattern::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rStageCustomPartsEx::Pattern::DTI)->memAlloc(sz, align, rStageCustomPartsEx::Pattern::DTI.getID());
}

rStageCustomPartsEx::Pattern::~Pattern() {
}

__attribute__((weak)) void rStageCustomPartsEx::Pattern::createProperty(MtPropertyList& s) {
    DDON_STUB("rStageCustomPartsEx::Pattern::createProperty")
    /* stub */
}

inline rStageCustomPartsEx::Pattern::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStageCustomPartsEx::Pattern::MyDTI rStageCustomPartsEx::Pattern::DTI("rStageCustomPartsEx::Pattern", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* rStageCustomPartsEx::Pattern::MyDTI::newInstance() const {
    return new (16u) rStageCustomPartsEx::Pattern;
}

const MtDTI& rStageCustomPartsEx::ColorFog::getDTI() const {
    return rStageCustomPartsEx::ColorFog::DTI;
}

rStageCustomPartsEx::ColorFog::~ColorFog() {
}

__attribute__((weak)) void rStageCustomPartsEx::ColorFog::createProperty(MtPropertyList& s) {
    DDON_STUB("rStageCustomPartsEx::ColorFog::createProperty")
    /* stub */
}

bool rStageCustomPartsEx::ColorFog::load(MtDataReader& r) {
    mBase.mHeightStart = r.readF32();
    mBase.mHeightEnd = r.readF32();
    mBase.mHeightDensity = r.readF32();
    mBase.mHeightColor = r.readV3();
    mBase.mStart = r.readF32();
    mBase.mEnd = r.readF32();
    mBase.mDensity = r.readF32();
    mBase.mColor = r.readV3();
    mBase.mDiffuseBlendFactor = r.readF32();
    mNight.mHeightStart = r.readF32();
    mNight.mHeightEnd = r.readF32();
    mNight.mHeightDensity = r.readF32();
    mNight.mHeightColor = r.readV3();
    mNight.mStart = r.readF32();
    mNight.mEnd = r.readF32();
    mNight.mDensity = r.readF32();
    mNight.mColor = r.readV3();
    nDDOIO::readData(r, mNight.mDiffuseBlendFactor);
    return true;
}

__attribute__((weak)) bool rStageCustomPartsEx::ColorFog::save(MtDataWriter& w) {
    nDDOIO::writeData(w, mBase.mHeightStart);
    nDDOIO::writeData(w, mBase.mHeightEnd);
    nDDOIO::writeData(w, mBase.mHeightDensity);
    nDDOIO::writeData(w, mBase.mHeightColor);
    nDDOIO::writeData(w, mBase.mStart);
    nDDOIO::writeData(w, mBase.mEnd);
    nDDOIO::writeData(w, mBase.mDensity);
    nDDOIO::writeData(w, mBase.mColor);
    nDDOIO::writeData(w, mBase.mDiffuseBlendFactor);
    nDDOIO::writeData(w, mNight.mHeightStart);
    nDDOIO::writeData(w, mNight.mHeightEnd);
    nDDOIO::writeData(w, mNight.mHeightDensity);
    nDDOIO::writeData(w, mNight.mHeightColor);
    nDDOIO::writeData(w, mNight.mStart);
    nDDOIO::writeData(w, mNight.mEnd);
    nDDOIO::writeData(w, mNight.mDensity);
    nDDOIO::writeData(w, mNight.mColor);
    nDDOIO::writeData(w, mNight.mDiffuseBlendFactor);
    return true;
}

__attribute__((weak)) void rStageCustomPartsEx::ColorFog::clear() {
    mBase.mHeightStart = 100.0f;
    mBase.mHeightEnd = 0.0f;
    mBase.mHeightDensity = 1.0f;
    mBase.mHeightColor = MtVector3::One;
    mBase.mStart = 1000.0f;
    mBase.mEnd = 30000.0f;
    mBase.mDensity = 1.0f;
    mBase.mColor = MtVector3::One;
    mBase.mDiffuseBlendFactor = 1.0f;
    
    mNight.mHeightStart = 100.0f;
    mNight.mHeightEnd = 0.0f;
    mNight.mHeightDensity = 1.0f;
    mNight.mHeightColor = MtVector3::One;
    mNight.mStart = 1000.0f;
    mNight.mEnd = 30000.0f;
    mNight.mDensity = 1.0f;
    mNight.mColor = MtVector3::One;
    mNight.mDiffuseBlendFactor = 1.0f;
    
    mComment = "";
}

inline rStageCustomPartsEx::ColorFog::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStageCustomPartsEx::ColorFog::MyDTI rStageCustomPartsEx::ColorFog::DTI("rStageCustomPartsEx::ColorFog", &::MtObject::DTI, 256ul, 0u, 0u);

__attribute__((weak)) MtObject* rStageCustomPartsEx::ColorFog::MyDTI::newInstance() const {
    DDON_STUB("rStageCustomPartsEx::ColorFog::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& rStageCustomPartsEx::HemiSphLight::getDTI() const {
    return rStageCustomPartsEx::HemiSphLight::DTI;
}

inline void* rStageCustomPartsEx::HemiSphLight::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rStageCustomPartsEx::HemiSphLight::DTI)->memAlloc(sz, align, rStageCustomPartsEx::HemiSphLight::DTI.getID());
}

inline rStageCustomPartsEx::HemiSphLight::HemiSphLight() {
    mLightColor.x = MtVector3::One.x;
    mLightColor.y = MtVector3::One.y;
    mLightColor.z = MtVector3::One.z;
    mLightColor.pad_ = 0.0f;
    mRevColor.x = MtVector3::Zero.x;
    mRevColor.y = MtVector3::Zero.y;
    mRevColor.z = MtVector3::Zero.z;
    mRevColor.pad_ = 0.0f;
    mNightColor.x = MtVector3::One.x;
    mNightColor.y = MtVector3::One.y;
    mNightColor.z = MtVector3::One.z;
    mNightColor.pad_ = 0.0f;
    mNightRevColor.x = MtVector3::Zero.x;
    mNightRevColor.y = MtVector3::Zero.y;
    mNightRevColor.z = MtVector3::Zero.z;
    mNightRevColor.pad_ = 0.0f;
}

rStageCustomPartsEx::HemiSphLight::~HemiSphLight() {
}

__attribute__((weak)) void rStageCustomPartsEx::HemiSphLight::createProperty(MtPropertyList& s) {
    DDON_STUB("rStageCustomPartsEx::HemiSphLight::createProperty")
    /* stub */
}

inline rStageCustomPartsEx::HemiSphLight::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStageCustomPartsEx::HemiSphLight::MyDTI rStageCustomPartsEx::HemiSphLight::DTI("rStageCustomPartsEx::HemiSphLight", &::MtObject::DTI, 96ul, 0u, 0u);

MtObject* rStageCustomPartsEx::HemiSphLight::MyDTI::newInstance() const {
    return new (16u) rStageCustomPartsEx::HemiSphLight;
}

const MtDTI& rStageCustomPartsEx::InfiLight::getDTI() const {
    return rStageCustomPartsEx::InfiLight::DTI;
}

inline void* rStageCustomPartsEx::InfiLight::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rStageCustomPartsEx::InfiLight::DTI)->memAlloc(sz, align, rStageCustomPartsEx::InfiLight::DTI.getID());
}

inline rStageCustomPartsEx::InfiLight::InfiLight() {
    mLightColor.x = MtVector3::One.x;
    mLightColor.y = MtVector3::One.y;
    mLightColor.z = MtVector3::One.z;
    mLightColor.pad_ = 0.0f;
    mNightColor.x = MtVector3::One.x;
    mNightColor.y = MtVector3::One.y;
    mNightColor.z = MtVector3::One.z;
    mNightColor.pad_ = 0.0f;
}

rStageCustomPartsEx::InfiLight::~InfiLight() {
}

__attribute__((weak)) void rStageCustomPartsEx::InfiLight::createProperty(MtPropertyList& s) {
    DDON_STUB("rStageCustomPartsEx::InfiLight::createProperty")
    /* stub */
}

inline rStageCustomPartsEx::InfiLight::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStageCustomPartsEx::InfiLight::MyDTI rStageCustomPartsEx::InfiLight::DTI("rStageCustomPartsEx::InfiLight", &::MtObject::DTI, 64ul, 0u, 0u);

MtObject* rStageCustomPartsEx::InfiLight::MyDTI::newInstance() const {
    return new (16u) rStageCustomPartsEx::InfiLight;
}

const MtDTI& rStageCustomPartsEx::AreaParam::getDTI() const {
    return rStageCustomPartsEx::AreaParam::DTI;
}

void* rStageCustomPartsEx::AreaParam::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rStageCustomPartsEx::AreaParam::DTI)->memAlloc(sz, align, rStageCustomPartsEx::AreaParam::DTI.getID());
}

inline void rStageCustomPartsEx::AreaParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rStageCustomPartsEx::AreaParam::DTI)->memFree(p_addr);
}

__attribute__((noinline)) rStageCustomPartsEx::AreaParam::~AreaParam() {
    clear();
}

__attribute__((weak)) void rStageCustomPartsEx::AreaParam::createProperty(MtPropertyList& s) {
    DDON_STUB("rStageCustomPartsEx::AreaParam::createProperty")
    /* stub */
}

inline rStageCustomPartsEx::AreaParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStageCustomPartsEx::AreaParam::MyDTI rStageCustomPartsEx::AreaParam::DTI("rStageCustomPartsEx::AreaParam", &::MtObject::DTI, 64ul, 0u, 0u);

MtObject* rStageCustomPartsEx::AreaParam::MyDTI::newInstance() const {
    return new (16u) rStageCustomPartsEx::AreaParam;
}

const MtDTI& rStageCustomPartsEx::InfoEx::getDTI() const {
    return rStageCustomPartsEx::InfoEx::DTI;
}

inline void* rStageCustomPartsEx::InfoEx::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rStageCustomPartsEx::InfoEx::DTI)->memAlloc(sz, align, rStageCustomPartsEx::InfoEx::DTI.getID());
}

inline void rStageCustomPartsEx::InfoEx::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rStageCustomPartsEx::InfoEx::DTI)->memFree(p_addr);
}

__attribute__((noinline)) rStageCustomPartsEx::InfoEx::~InfoEx() {
    clear();
}

__attribute__((weak)) void rStageCustomPartsEx::InfoEx::createProperty(MtPropertyList& s) {
    DDON_STUB("rStageCustomPartsEx::InfoEx::createProperty")
    /* stub */
}

__attribute__((weak)) rStageCustomPartsEx::AreaParam* rStageCustomPartsEx::InfoEx::getAreaParam(const MtVector3& pos, s32 filterNo) {
    DDON_STUB("rStageCustomPartsEx::InfoEx::getAreaParam")
    return nullptr;
}

inline rStageCustomPartsEx::InfoEx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStageCustomPartsEx::InfoEx::MyDTI rStageCustomPartsEx::InfoEx::DTI("rStageCustomPartsEx::InfoEx", &::rStageCustomParts::Info::DTI, 872ul, 0u, 0u);

MtObject* rStageCustomPartsEx::InfoEx::MyDTI::newInstance() const {
    return new (16u) rStageCustomPartsEx::InfoEx;
}

const MtDTI& rStageCustomPartsEx::FilterEx::getDTI() const {
    return rStageCustomPartsEx::FilterEx::DTI;
}

inline void* rStageCustomPartsEx::FilterEx::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rStageCustomPartsEx::FilterEx::DTI)->memAlloc(sz, align, rStageCustomPartsEx::FilterEx::DTI.getID());
}

rStageCustomPartsEx::FilterEx::~FilterEx() {
}

__attribute__((weak)) void rStageCustomPartsEx::FilterEx::createProperty(MtPropertyList& s) {
    DDON_STUB("rStageCustomPartsEx::FilterEx::createProperty")
    /* stub */
}

inline rStageCustomPartsEx::FilterEx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStageCustomPartsEx::FilterEx::MyDTI rStageCustomPartsEx::FilterEx::DTI("rStageCustomPartsEx::FilterEx", &::rStageCustomParts::Filter::DTI, 88ul, 0u, 0u);

MtObject* rStageCustomPartsEx::FilterEx::MyDTI::newInstance() const {
    return new (16u) rStageCustomPartsEx::FilterEx;
}

template MtTypedArray<rStageCustomPartsEx::AreaParam>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<AreaHitShape>&);

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rStageCustomPartsEx::AreaParam>&);

namespace nDDOIO {
template <>
void writeMtArray<rStageCustomPartsEx::AreaParam>(MtDataWriter& w, MtTypedArray<rStageCustomPartsEx::AreaParam>& ar) {
    w.writeU32(ar.length());
    for (u32 i = 0; i < ar.length(); i++) {
        ar[i]->save(w);
    }
}
}

