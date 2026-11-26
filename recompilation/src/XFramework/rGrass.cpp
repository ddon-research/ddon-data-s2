// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rGrass.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataReader.h"
#include "../MT/MtEaseCurve.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtStream.h"
#include "../MT/MtString.h"
#include "cBVHGrass.h"
#include "cDraw.h"
#include "cResource.h"
#include "nDrawVertexBuffer.h"
#include "rTexture.h"
#include "sResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rGrass::getDTI() const {
    return rGrass::DTI;
}

inline void rGrass::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rGrass::DTI)->memFree(p_addr);
}

rGrass::rGrass() {
    setAttribute(18);
    mHeader.magic = 0x535247;
    mHeader.version = DATA_VERSION;
    mpVertexBuffer = nullptr;
    mVertexStride = 12;
    mVertexCount = 0;
    mUseComp = true;
    mpNativeClusters = nullptr;
    clear();
    mGrassType = GT_QUAD;
    mMaxLength = 100.0f;
    mSettingList[0].setRatio(1.0f);
}

__attribute__((noinline)) rGrass::~rGrass() {
    clear();
}

void rGrass::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mSettingList", static_cast<MtObject*>(&mSettingList[0]), 33u, 8u);
    s << MtProperty(static_cast<MtObject*>(this), "mClusters", static_cast<MtObject*>(&mClusters), 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUseComp", &mUseComp, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaxLength", &mMaxLength, 1u, 0u);
}

__attribute__((weak)) bool rGrass::load(MtStream& stream) {
    bool ret = false;
    u32 t1 = sResource::getInstance()->getRGrassDataReaderBufferSizeByte();
    u32 t2 = stream.getLength();
    if (t2 < t1) {
        t1 = t2;
    }
    MtDataReader in(stream, t1);
    HEADER header;
    in.read(&header, sizeof(HEADER));
    if (header.magic == mHeader.magic && header.version == mHeader.version) {
        mHeader.dummy = header.dummy;
        in.read(&mUseComp, sizeof(bool));
        in.read(&mGrassType, sizeof(u32));
        in.read(&mVertexCount, sizeof(u32));
        in.read(&mVertexStride, sizeof(u32));
        in.read(&mMaxLength, sizeof(f32));
        mpVertexBuffer = new (16) nDraw::VertexBuffer(mVertexCount * mVertexStride, nDraw::USAGE_DEFAULT, nullptr);
        u8* pvf = static_cast<u8*>(mpVertexBuffer->map(nDraw::MAP_WRITE_DISCARD));
        void* temp = MtMemory::getAllocator(MtMemoryAllocator::TEMPORARY)->memAlloc(mVertexCount * mVertexStride, 16);
        in.read(temp, mVertexCount * mVertexStride);
        memcpy(pvf, temp, mVertexCount * mVertexStride);
        MtMemory::getAllocator(MtMemoryAllocator::TEMPORARY)->memFree(temp);
        mpVertexBuffer->unmap();
        u32 cluster_num = mClusters.length();
        in.read(&cluster_num, sizeof(u32));
        mpNativeClusters = new (16) cCluster[cluster_num];
        mClusters.setAutoDelete(false);
        for (u32 i = 0; i < cluster_num; i++) {
            cCluster* pc = &mpNativeClusters[i];
            pc->load(in);
            mClusters.add(pc);
            MtAABB aabb;
            aabb.minpos = MtVector3(
                pc->mDequantizationCoordOffset.x - mMaxLength,
                pc->mDequantizationCoordOffset.y - mMaxLength,
                pc->mDequantizationCoordOffset.z - mMaxLength);
            aabb.maxpos = MtVector3(
                pc->mDequantizationCoordOffset.x + pc->mDequantizationCoordScale.x + mMaxLength,
                pc->mDequantizationCoordOffset.y + pc->mDequantizationCoordScale.y + mMaxLength,
                pc->mDequantizationCoordOffset.z + pc->mDequantizationCoordScale.z + mMaxLength);
            mCluster.addParam(new cNodeParam<cCluster>(pc, aabb, 0));
        }
        mCluster.build(128);
        u32 count = 0;
        in.read(&count, sizeof(u32));
        for (u32 i = 0; i < count; i++) {
            mSettingList[i].load(in);
        }
        ret = true;
    }
    return ret;
}

__attribute__((weak)) bool rGrass::save(MtStream& out) {
    out.write(&mHeader, sizeof(HEADER));
    u32 cluster_num = 0;
    for (u32 i = 0; i < mClusters.length(); i++) {
        cluster_num += static_cast<cCluster*>(mClusters.getBuffer()[i])->mVertexCount != 0 ? 1 : 0;
    }
    out.write(&mUseComp, sizeof(bool));
    out.write(&mGrassType, sizeof(u32));
    out.write(&mVertexCount, sizeof(u32));
    out.write(&mVertexStride, sizeof(u32));
    out.write(&mMaxLength, sizeof(f32));
    u8* pvf = static_cast<u8*>(mpVertexBuffer->map(nDraw::MAP_READ));
    out.write(pvf, mVertexCount * mVertexStride);
    mpVertexBuffer->unmap();
    out.write(&cluster_num, sizeof(u32));
    for (u32 i = 0; i < mClusters.length(); i++) {
        if (static_cast<cCluster*>(mClusters.getBuffer()[i])->mVertexCount != 0) {
            static_cast<cCluster*>(mClusters.getBuffer()[i])->save(out);
        }
    }
    u32 max_setting = MAX_SETTING;
    out.write(&max_setting, sizeof(u32));
    for (u32 i = 0; i < MAX_SETTING; i++) {
        mSettingList[i].save(out);
    }
    return true;
}

__attribute__((weak)) void rGrass::clear() {
    mParams.deleteAll(true);
    if (mClusters.isAutoDelete()) {
        mClusters.deleteAll(true);
    } else {
        if (mpNativeClusters != nullptr) {
            delete[] mpNativeClusters;
            mpNativeClusters = nullptr;
        }
        mClusters.clear(true);
    }
    mCluster.deleteAll();
    if (mpVertexBuffer != nullptr) {
        mpVertexBuffer->release();
        mpVertexBuffer = nullptr;
    }
}

MT_CTSTR rGrass::getExt() const {
    return "grs";
}

MtArray* rGrass::getParams() {
    return &mParams;
}

inline rGrass::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rGrass::MyDTI rGrass::DTI("rGrass", &::cResource::DTI, 10784ul, 0u, 0u);

__attribute__((weak)) MtObject* rGrass::MyDTI::newInstance() const {
    return new (16) rGrass;
}

const MtDTI& rGrass::cCluster::getDTI() const {
    return rGrass::cCluster::DTI;
}

inline void rGrass::cCluster::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rGrass::cCluster::DTI)->memFree(p_addr);
}

rGrass::cCluster::~cCluster() {
}

void rGrass::cCluster::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mVertexCount", &mVertexCount, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIndexCount", &mIndexCount, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVertexBase", &mVertexBase, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDequantizationCoordScale", &mDequantizationCoordScale, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDequantizationCoordOffset", &mDequantizationCoordOffset, 1u, 0u);
}

bool rGrass::cCluster::load(MtStream& in) {
    in.read(static_cast<void*>(&mVertexBase), 4u);
    in.read(static_cast<void*>(&mVertexCount), 4u);
    in.read(static_cast<void*>(&mIndexCount), 4u);
    in.read(static_cast<void*>(&mDequantizationCoordScale), 16u);
    in.read(static_cast<void*>(&mDequantizationCoordOffset), 16u);
    return true;
}

bool rGrass::cCluster::save(MtStream& out) {
    out.write(static_cast<const void*>(&mVertexBase), 4u);
    out.write(static_cast<const void*>(&mVertexCount), 4u);
    out.write(static_cast<const void*>(&mIndexCount), 4u);
    out.write(static_cast<const void*>(&mDequantizationCoordScale), 16u);
    out.write(static_cast<const void*>(&mDequantizationCoordOffset), 16u);
    return true;
}

__attribute__((weak)) void rGrass::cCluster::draw(cDraw* pdraw, u32 index, const u32 max_index, const u32 verte_offset, const u32 max_vertex) {
    DDON_STUB("rGrass::cCluster::draw")
    /* stub */
}

inline rGrass::cCluster::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rGrass::cCluster::MyDTI rGrass::cCluster::DTI("rGrass::cCluster", &::MtObject::DTI, 336ul, 0u, 0u);

__attribute__((weak)) MtObject* rGrass::cCluster::MyDTI::newInstance() const {
    return new (16) rGrass::cCluster;
}

const MtDTI& rGrass::cSetting::getDTI() const {
    return rGrass::cSetting::DTI;
}

rGrass::cSetting::cSetting() {
    mpNormalMap = nullptr;
    mpMaskMap = nullptr;
    mpAlbedoMap = nullptr;
    mTranslucent = 1.0f;
    mSpecularPower = 5.0f;
    mRatio = 0.0f;
    mScale = 100.0f;
    mAspect = 1.0f;
    mColorOne = MtColor::White;
    mColorTwo = MtColor::White;
    mGlobalWindParam.x = 100.0f;
    mGlobalWindParam.y = 1.0f;
    mGlobalWindParam.z = 0.0f;
    mGlobalWindParam.w = 0.0f;
    mCurveBeginValue = 0.0f;
    mCurveEndValue = 1.0f;
    mColorOffset = MtVector4::One;
    mColorScale = MtVector4::Zero;
    mWeightCurve = MtHermiteCurve::Linear;
    mChainGrass = mChain.chain;
    mChainGrassNormal = mChain.normal;
    mChainGrassTangent = mChain.tangent;
    const MtVector4 UV[16] = {
        MtVector4(1.0f, 1.0f, 0.0f, 0.0f),
        MtVector4(0.0f, 1.0f, 0.0f, 0.0f),
        MtVector4(1.0f, 0.66667f, 0.0f, 0.0f),
        MtVector4(0.0f, 0.66667f, 0.0f, 0.0f),
        MtVector4(1.0f, 0.33333f, 0.0f, 0.0f),
        MtVector4(0.0f, 0.33333f, 0.0f, 0.0f),
        MtVector4(1.0f, 0.0f, 0.0f, 0.0f),
        MtVector4(0.0f, 0.0f, 0.0f, 0.0f),
        MtVector4(1.0f, 1.0f, 0.0f, 0.0f),
        MtVector4(0.0f, 1.0f, 0.0f, 0.0f),
        MtVector4(1.0f, 0.66667f, 0.0f, 0.0f),
        MtVector4(0.0f, 0.66667f, 0.0f, 0.0f),
        MtVector4(1.0f, 0.33333f, 0.0f, 0.0f),
        MtVector4(0.0f, 0.33333f, 0.0f, 0.0f),
        MtVector4(1.0f, 0.0f, 0.0f, 0.0f),
        MtVector4(0.0f, 0.0f, 0.0f, 0.0f),
    };
    memcpy(mChain.uv, UV, sizeof(UV));
}

rGrass::cSetting::~cSetting() {
    if (mpAlbedoMap != nullptr) {
        mpAlbedoMap->release();
        mpAlbedoMap = nullptr;
    }
    if (mpMaskMap != nullptr) {
        mpMaskMap->release();
        mpMaskMap = nullptr;
    }
    if (mpNormalMap == nullptr) {
        return;
    }
    mpNormalMap->release();
    mpNormalMap = nullptr;
}

void rGrass::cSetting::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mpAlbedoMap", "resource", reinterpret_cast<MT_MFUNC>(&::rGrass::cSetting::getAlbedoTexture), reinterpret_cast<MT_MFUNC>(&::rGrass::cSetting::setAlbedoTexture), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpMaskMap", "resource", reinterpret_cast<MT_MFUNC>(&::rGrass::cSetting::getMaskTexture), reinterpret_cast<MT_MFUNC>(&::rGrass::cSetting::setMaskTexture), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mpNormalMap", "resource", reinterpret_cast<MT_MFUNC>(&::rGrass::cSetting::getNormalTexture), reinterpret_cast<MT_MFUNC>(&::rGrass::cSetting::setNormalTexture), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mColorOne", &mColorOne, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColorTwo", &mColorTwo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpecularPower", &mSpecularPower, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTranslucent", &mTranslucent, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBegin", &mBegin, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWidth", &mWidth, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRatio", &mRatio, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWeightCurve", &mWeightCurve, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mScale", reinterpret_cast<MT_MFUNC>(&::rGrass::cSetting::getScale), reinterpret_cast<MT_MFUNC>(&::rGrass::cSetting::setScale), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "mAspect", reinterpret_cast<MT_MFUNC>(&::rGrass::cSetting::getAspect), reinterpret_cast<MT_MFUNC>(&::rGrass::cSetting::setAspect), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mChainGrassParams[0]", static_cast<MtObject*>(&mChainGrassParams[0]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mChainGrassParams[1]", static_cast<MtObject*>(&mChainGrassParams[1]), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAmplification", &mGlobalWindParam.x, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFrequency", &mGlobalWindParam.y, 0u, 0u);
}

MtUI* rGrass::cSetting::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) bool rGrass::cSetting::load(MtDataReader& in) {
    in.read(&mCurveBeginValue, sizeof(f32));
    in.read(&mCurveEndValue, sizeof(f32));
    in.read(&mRatio, sizeof(f32));
    in.read(mChain.chain, sizeof(mChain.chain));
    in.read(mChain.normal, sizeof(mChain.normal));
    in.read(mChain.tangent, sizeof(mChain.tangent));
    in.read(&mScale, sizeof(f32));
    in.read(&mAspect, sizeof(f32));
    in.read(&mBegin, sizeof(f32));
    in.read(&mWidth, sizeof(f32));
    in.read(&mGlobalWindParam, sizeof(MtVector4));
    in.read(&mColorOffset, sizeof(MtVector4));
    in.read(&mColorScale, sizeof(MtVector4));
    in.read(&mSpecularPower, sizeof(f32));
    u32 path_length;
    in.read(&path_length, sizeof(u32));
    if (path_length != 0) {
        MT_CHAR path[1024];
        u32 dti_id;
        in.read(&dti_id, sizeof(u32));
        in.read(path, path_length);
        rTexture* pTexture = static_cast<rTexture*>(sResource::getInstance()->create(*MtDTI::from(dti_id), path, sResource::MODE_BLOCKING));
        setAlbedoTexture(pTexture);
        if (pTexture != nullptr) {
            pTexture->release();
        }
    }
    in.read(&path_length, sizeof(u32));
    if (path_length != 0) {
        MT_CHAR path[1024];
        u32 dti_id;
        in.read(&dti_id, sizeof(u32));
        in.read(path, path_length);
        rTexture* pTexture = static_cast<rTexture*>(sResource::getInstance()->create(*MtDTI::from(dti_id), path, sResource::MODE_BLOCKING));
        setMaskTexture(pTexture);
        if (pTexture != nullptr) {
            pTexture->release();
        }
    }
    in.read(&path_length, sizeof(u32));
    if (path_length != 0) {
        MT_CHAR path[1024];
        u32 dti_id;
        in.read(&dti_id, sizeof(u32));
        in.read(path, path_length);
        rTexture* pTexture = static_cast<rTexture*>(sResource::getInstance()->create(*MtDTI::from(dti_id), path, sResource::MODE_BLOCKING));
        setNormalTexture(pTexture);
        if (pTexture != nullptr) {
            pTexture->release();
        }
    }
    return true;
}

__attribute__((weak)) bool rGrass::cSetting::load(MtStream& in) {
    in.read(&mCurveBeginValue, sizeof(f32));
    in.read(&mCurveEndValue, sizeof(f32));
    in.read(&mRatio, sizeof(f32));
    in.read(mChain.chain, sizeof(mChain.chain));
    in.read(mChain.normal, sizeof(mChain.normal));
    in.read(mChain.tangent, sizeof(mChain.tangent));
    in.read(&mScale, sizeof(f32));
    in.read(&mAspect, sizeof(f32));
    in.read(&mBegin, sizeof(f32));
    in.read(&mWidth, sizeof(f32));
    in.read(&mGlobalWindParam, sizeof(MtVector4));
    in.read(&mColorOffset, sizeof(MtVector4));
    in.read(&mColorScale, sizeof(MtVector4));
    in.read(&mSpecularPower, sizeof(f32));
    u32 path_length;
    in.read(&path_length, sizeof(u32));
    if (path_length != 0) {
        MT_CHAR path[1024];
        u32 dti_id;
        in.read(&dti_id, sizeof(u32));
        in.read(path, path_length);
        rTexture* pTexture = static_cast<rTexture*>(sResource::getInstance()->create(*MtDTI::from(dti_id), path, sResource::MODE_BLOCKING));
        setAlbedoTexture(pTexture);
        if (pTexture != nullptr) {
            pTexture->release();
        }
    }
    in.read(&path_length, sizeof(u32));
    if (path_length != 0) {
        MT_CHAR path[1024];
        u32 dti_id;
        in.read(&dti_id, sizeof(u32));
        in.read(path, path_length);
        rTexture* pTexture = static_cast<rTexture*>(sResource::getInstance()->create(*MtDTI::from(dti_id), path, sResource::MODE_BLOCKING));
        setMaskTexture(pTexture);
        if (pTexture != nullptr) {
            pTexture->release();
        }
    }
    in.read(&path_length, sizeof(u32));
    if (path_length != 0) {
        MT_CHAR path[1024];
        u32 dti_id;
        in.read(&dti_id, sizeof(u32));
        in.read(path, path_length);
        rTexture* pTexture = static_cast<rTexture*>(sResource::getInstance()->create(*MtDTI::from(dti_id), path, sResource::MODE_BLOCKING));
        setNormalTexture(pTexture);
        if (pTexture != nullptr) {
            pTexture->release();
        }
    }
    return true;
}

__attribute__((weak)) bool rGrass::cSetting::save(MtStream& out) {
    out.write(&mCurveBeginValue, sizeof(f32));
    out.write(&mCurveEndValue, sizeof(f32));
    out.write(&mRatio, sizeof(f32));
    out.write(mChain.chain, sizeof(mChain.chain));
    out.write(mChain.normal, sizeof(mChain.normal));
    out.write(mChain.tangent, sizeof(mChain.tangent));
    out.write(&mScale, sizeof(f32));
    out.write(&mAspect, sizeof(f32));
    out.write(&mBegin, sizeof(f32));
    out.write(&mWidth, sizeof(f32));
    out.write(&mGlobalWindParam, sizeof(MtVector4));
    out.write(&mColorOffset, sizeof(MtVector4));
    out.write(&mColorScale, sizeof(MtVector4));
    out.write(&mSpecularPower, sizeof(f32));
    if (mpAlbedoMap != nullptr) {
        u32 path_length = MtString(mpAlbedoMap->getPath()).length() + 1;
        out.write(&path_length, sizeof(u32));
        u32 dti_id = mpAlbedoMap->getDTI().getID();
        out.write(&dti_id, sizeof(u32));
        out.write(mpAlbedoMap->getPath(), path_length);
    } else {
        u32 Zero = 0;
        out.write(&Zero, sizeof(u32));
    }
    if (mpMaskMap != nullptr) {
        u32 path_length = MtString(mpMaskMap->getPath()).length() + 1;
        out.write(&path_length, sizeof(u32));
        u32 dti_id = mpMaskMap->getDTI().getID();
        out.write(&dti_id, sizeof(u32));
        out.write(mpMaskMap->getPath(), path_length);
    } else {
        u32 Zero = 0;
        out.write(&Zero, sizeof(u32));
    }
    if (mpNormalMap != nullptr) {
        u32 path_length = MtString(mpNormalMap->getPath()).length() + 1;
        out.write(&path_length, sizeof(u32));
        u32 dti_id = mpNormalMap->getDTI().getID();
        out.write(&dti_id, sizeof(u32));
        out.write(mpNormalMap->getPath(), path_length);
    } else {
        u32 Zero = 0;
        out.write(&Zero, sizeof(u32));
    }
    return true;
}

__attribute__((weak)) void rGrass::cSetting::update() {
    DDON_STUB("rGrass::cSetting::update")
    /* stub */
}

static auto ddon_emit_0x01b91a90 __attribute__((used)) = &rGrass::cSetting::getAlbedoTexture;

void rGrass::cSetting::setAlbedoTexture(rTexture* ptex) {
    if (mpAlbedoMap != nullptr) {
        mpAlbedoMap->release();
        mpAlbedoMap = nullptr;
    }
    if (ptex != nullptr) {
        if ((ptex->mAttr & 8u) != 0) {
            mpAlbedoMap = static_cast<rTexture*>((sResource::mpInstance)->create(rTexture::DTI, &ptex->mPath[0], 1u));
        } else {
            mpAlbedoMap = ptex;
            ptex->addRef();
        }
    } else {
        mpAlbedoMap = nullptr;
    }
}

static auto ddon_emit_0x01b91aa0 __attribute__((used)) = &rGrass::cSetting::getMaskTexture;

void rGrass::cSetting::setMaskTexture(rTexture* ptex) {
    if (mpMaskMap != nullptr) {
        mpMaskMap->release();
        mpMaskMap = nullptr;
    }
    if (ptex != nullptr) {
        if ((ptex->mAttr & 8u) != 0) {
            mpMaskMap = static_cast<rTexture*>((sResource::mpInstance)->create(rTexture::DTI, &ptex->mPath[0], 1u));
        } else {
            mpMaskMap = ptex;
            ptex->addRef();
        }
    } else {
        mpMaskMap = nullptr;
    }
}

static auto ddon_emit_0x01b91ab0 __attribute__((used)) = &rGrass::cSetting::getNormalTexture;

void rGrass::cSetting::setNormalTexture(rTexture* ptex) {
    if (mpNormalMap != nullptr) {
        mpNormalMap->release();
        mpNormalMap = nullptr;
    }
    if (ptex != nullptr) {
        if ((ptex->mAttr & 8u) != 0) {
            mpNormalMap = static_cast<rTexture*>((sResource::mpInstance)->create(rTexture::DTI, &ptex->mPath[0], 1u));
        } else {
            mpNormalMap = ptex;
            ptex->addRef();
        }
    } else {
        mpNormalMap = nullptr;
    }
}

static auto ddon_emit_0x01b91ad0 __attribute__((used)) = &rGrass::cSetting::setScale;

static auto ddon_emit_0x01b91ac0 __attribute__((used)) = &rGrass::cSetting::getScale;

static auto ddon_emit_0x01b91af0 __attribute__((used)) = &rGrass::cSetting::setAspect;

static auto ddon_emit_0x01b91ae0 __attribute__((used)) = &rGrass::cSetting::getAspect;

inline rGrass::cSetting::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rGrass::cSetting::MyDTI rGrass::cSetting::DTI("rGrass::cSetting", &::MtObject::DTI, 1312ul, 0u, 0u);

__attribute__((weak)) MtObject* rGrass::cSetting::MyDTI::newInstance() const {
    return new (16) rGrass::cSetting;
}

const MtDTI& rGrass::cChainGrass::getDTI() const {
    return rGrass::cChainGrass::DTI;
}

inline void rGrass::cChainGrass::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rGrass::cChainGrass::DTI)->memFree(p_addr);
}

void rGrass::cChainGrass::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mDirection", &mDirection, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPower", &mPower, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTheta", &mTheta, 0u, 0u);
}

MtUI* rGrass::cChainGrass::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline rGrass::cChainGrass::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rGrass::cChainGrass::MyDTI rGrass::cChainGrass::DTI("rGrass::cChainGrass", &::MtObject::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* rGrass::cChainGrass::MyDTI::newInstance() const {
    return new (16) rGrass::cChainGrass;
}

template void cNodeParam<rGrass::cCluster>::createProperty(MtPropertyList&);

template cNodeParam<rGrass::cCluster>::~cNodeParam();

