// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rTexture.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataReader.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cResource.h"
#include "nDrawResource.h"
#include "nDrawTexture.h"
#include "sResource.h"
#include "sScene.h"
#include "sShader2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rTexture::getDTI() const {
    return rTexture::DTI;
}

inline void* rTexture::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rTexture::DTI)->memAlloc(sz, align, rTexture::DTI.mID);
}

inline void rTexture::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rTexture::DTI)->memFree(p_addr);
}

rTexture::rTexture() {
    mAttr = 16;
    mbStream = false;
    mOrgDepth = 0;
    mDetailBias = 0;
    mOrgWidth = 0;
    mOrgHeight = 0;
    mOrgInvWidth = 0.0f;
    mOrgInvHeight = 0.0f;
    mpTexture = nullptr;
}

__attribute__((weak)) bool rTexture::load(MtStream& r) {
    u32 t1 = sResource::getInstance()->getRTextureDataReaderBufferSizeByte();
    u32 t2 = r.getLength();
    MtDataReader in(r, t2 < t1 ? t2 : t1);
    rTexture::HEADER hdr;
    in.read(&hdr, sizeof(rTexture::HEADER));
    if (hdr.magic != 0x584554u) {
        return false;
    }
    if (hdr.version != getDataVersion()) {
        return false;
    }
    mOrgWidth = static_cast<u32>(hdr.width) << hdr.prebias;
    mOrgHeight = static_cast<u32>(hdr.height) << hdr.prebias;
    mOrgDepth = static_cast<u32>(hdr.depth) << hdr.prebias;
    mOrgInvWidth = 1.0f / static_cast<f32>(mOrgWidth);
    mOrgInvHeight = 1.0f / static_cast<f32>(mOrgHeight);
    if (hdr.type == nDraw::TT_CUBE) {
        in.read(&mSHFactor, sizeof(SHFACTOR));
    }
    uintptr* subresource_ofs = static_cast<uintptr*>(
        MtMemory::getAllocator(MtMemoryAllocator::TEMPORARY)->memAlloc(
            static_cast<size_t>(hdr.level_count) * static_cast<size_t>(hdr.array_count) * sizeof(uintptr), 16u));
    in.read(subresource_ofs, static_cast<u32>(hdr.level_count * hdr.array_count * sizeof(uintptr)));
    s32 bias = static_cast<s32>(sScene::getInstance()->getTextureDetail(getPath()))
             + static_cast<s32>(cResource::QUALITY_NORMAL - getQuality())
             - static_cast<s32>(hdr.prebias);
    if (bias < 0) {
        bias = 0;
    }
    if (bias > 5) {
        bias = 5;
    }
    u32 miplevel = nDraw::Texture::calcMipLevelCount(hdr.width > hdr.height ? hdr.width : hdr.height);
    u32 mipuse = 0;
    for (u32 i = 0; i < hdr.level_count; ++i) {
        mipuse |= 1u << (miplevel - i);
    }
    for (u32 i = 0; i < static_cast<u32>(bias); ++i) {
        if (i + 1u >= hdr.level_count) {
            break;
        }
        s32 lv = static_cast<s32>(miplevel - i);
        if (lv <= MIN_LOADBIAS) {
            break;
        }
        mipuse &= ~(1u << lv);
    }
    u32 dbias = 0;
    for (u32 i = 0; i < miplevel; ++i) {
        if ((mipuse & (1u << (miplevel - i))) != 0) {
            break;
        }
        ++dbias;
    }
    mDetailBias = dbias + hdr.prebias;
    u32 dw = hdr.width >> dbias;
    if (dw == 0) {
        dw = 1;
    }
    u32 dh = hdr.height >> dbias;
    if (dh == 0) {
        dh = 1;
    }
    u32 dd = hdr.depth >> dbias;
    if (dd == 0) {
        dd = 1;
    }
    s32 miplimite = static_cast<s32>(sScene::getInstance()->getTextureMipLimite(getPath()));
    for (s32 i = 0; i < miplimite; ++i) {
        mipuse &= ~(1u << (i + 1));
    }
    u32 dlv = 0;
    for (u32 i = 0; i < 32u; ++i) {
        if ((mipuse & (1u << i)) != 0) {
            ++dlv;
        }
    }
    s32 t3 = static_cast<s32>(hdr.level_count) - static_cast<s32>(dbias);
    if (t3 <= 0) {
        t3 = 1;
    }
    if (dlv > static_cast<u32>(t3)) {
        dlv = static_cast<u32>(t3);
    }
    if (dlv == 0) {
        dlv = 1;
    }
    nDraw::Texture* phandle = nullptr;
    switch (hdr.type) {
    case nDraw::TT_1D:
    case nDraw::TT_2D: {
        sce::Gnm::DataFormat format = nDraw::Texture::getGPUFormatType(static_cast<nDraw::FORMAT_TYPE>(hdr.format));
        sce::Gnm::TileMode tileMode = sce::Gnm::kTileModeDisplay_LinearAligned;
        sce::GpuAddress::computeSurfaceTileMode(&tileMode, static_cast<sce::GpuAddress::SurfaceType>(7), format, 1u);
        sce::Gnm::Texture tx;
        sce::Gnm::SizeAlign sa = tx.initAs2dArray(dw, dh, 1u, 0u, dlv, format, tileMode, sce::Gnm::kNumFragments1, false);
        void* pinitvalues = MtMemory::getAllocator(MtMemoryAllocator::TEMPORARY)->memAlloc(sa.m_size, 16u);
        in.skip(static_cast<u32>(subresource_ofs[dbias]) - in.getPosition());
        for (u32 j = 0; j < dlv; ++j) {
            u64 siz;
            u64 ofs;
            sce::GpuAddress::computeTextureSurfaceOffsetAndSize(&ofs, &siz, &tx, j, 0u);
            void* dst = static_cast<u8*>(pinitvalues) + ofs;
            in.read(dst, static_cast<u32>(siz));
        }
        phandle = new (16u) nDraw::Texture(
            dw, dh, dlv, 1u, static_cast<nDraw::FORMAT_TYPE>(hdr.format),
            nDraw::USAGE_DEFAULT, 0u, nullptr, 0u, pinitvalues, nDraw::TEXMEMORY_VRAM);
        MtMemory::getAllocator(MtMemoryAllocator::TEMPORARY)->memFree(pinitvalues);
        break;
    }
    case nDraw::TT_3D: {
        sce::Gnm::DataFormat format = nDraw::Texture::getGPUFormatType(static_cast<nDraw::FORMAT_TYPE>(hdr.format));
        sce::Gnm::TileMode tileMode = sce::Gnm::kTileModeDisplay_LinearAligned;
        sce::GpuAddress::computeSurfaceTileMode(&tileMode, static_cast<sce::GpuAddress::SurfaceType>(8), format, 1u);
        sce::Gnm::Texture tx;
        sce::Gnm::SizeAlign sa = tx.initAs3d(dw, dh, dd, dlv, format, tileMode);
        void* pinitvalues = MtMemory::getAllocator(MtMemoryAllocator::TEMPORARY)->memAlloc(sa.m_size, 16u);
        in.skip(static_cast<u32>(subresource_ofs[dbias]) - in.getPosition());
        for (u32 j = 0; j < dlv; ++j) {
            u64 siz;
            u64 ofs;
            sce::GpuAddress::computeTextureSurfaceOffsetAndSize(&ofs, &siz, &tx, j, 0u);
            void* dst = static_cast<u8*>(pinitvalues) + ofs;
            in.read(dst, static_cast<u32>(siz));
        }
        phandle = new (16u) nDraw::Texture(
            dw, dh, dd, dlv, 1u, static_cast<nDraw::FORMAT_TYPE>(hdr.format),
            nDraw::USAGE_DEFAULT, 0u, nullptr, 0u, pinitvalues);
        break;
    }
    case nDraw::TT_CUBE: {
        sce::Gnm::DataFormat format = nDraw::Texture::getGPUFormatType(static_cast<nDraw::FORMAT_TYPE>(hdr.format));
        sce::Gnm::TileMode tileMode = sce::Gnm::kTileModeDisplay_LinearAligned;
        sce::GpuAddress::computeSurfaceTileMode(&tileMode, static_cast<sce::GpuAddress::SurfaceType>(9), format, 1u);
        sce::Gnm::Texture tx;
        sce::Gnm::SizeAlign sa = tx.initAs2dArray(dw, dh, 1u, 0u, dlv, format, tileMode, sce::Gnm::kNumFragments1, true);
        void* pinitvalues = MtMemory::getAllocator(MtMemoryAllocator::TEMPORARY)->memAlloc(sa.m_size, 16u);
        for (u32 k = 0; k < hdr.array_count; ++k) {
            in.skip(static_cast<u32>(subresource_ofs[k * hdr.level_count + dbias]) - in.getPosition());
            for (u32 j = 0; j < dlv; ++j) {
                u64 siz;
                u64 ofs;
                sce::GpuAddress::computeTextureSurfaceOffsetAndSize(&ofs, &siz, &tx, j, k);
                void* dst = static_cast<u8*>(pinitvalues) + ofs;
                in.read(dst, static_cast<u32>(siz));
            }
        }
        phandle = new (16u) nDraw::Texture(
            dw, dh, dlv, 6u, static_cast<nDraw::FORMAT_TYPE>(hdr.format),
            nDraw::USAGE_DEFAULT, 8u, nullptr, 0u, pinitvalues, nDraw::TEXMEMORY_VRAM);
        MtMemory::getAllocator(MtMemoryAllocator::TEMPORARY)->memFree(pinitvalues);
        break;
    }
    default:
        break;
    }
    setHandle(phandle);
    MtMemory::getAllocator(MtMemoryAllocator::TEMPORARY)->memFree(subresource_ofs);
    return phandle != nullptr;
}

bool rTexture::compact(MtStream& out) {
    return false;
}

void rTexture::clear() {
    if (mpTexture == nullptr) {
        return;
    }
    mpTexture->release();
    mpTexture = nullptr;
}

MtUI* rTexture::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

MT_CTSTR rTexture::getExt() const {
    return "tex";
}

void rTexture::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mpTexture", reinterpret_cast<MtObject* *>(&mpTexture), 19u, 0u);
    if (mpTexture == nullptr) {
        return;
    }
    mpTexture->createProperty(s);
}

rTexture::~rTexture() {
    if (mpTexture == nullptr) {
        return;
    }
    mpTexture->release();
    mpTexture = nullptr;
}

void rTexture::setHandle(nDraw::Texture* ptex) {
    if (mpTexture != nullptr) {
        clear();
    }
    mpTexture = ptex;
}

inline rTexture::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rTexture::MyDTI rTexture::DTI("rTexture", &::cResource::DTI, 264ul, 0u, 0u);

MtObject* rTexture::MyDTI::newInstance() const {
    return new (16u) rTexture;
}

const MtDTI& rTextureMemory::getDTI() const {
    return rTextureMemory::DTI;
}

void* rTextureMemory::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rTextureMemory::DTI)->memAlloc(sz, align, rTextureMemory::DTI.mID);
}

inline void rTextureMemory::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rTextureMemory::DTI)->memFree(p_addr);
}

rTextureMemory::rTextureMemory(nDraw::Texture* ptex) {
    DDON_STUB("rTextureMemory::rTextureMemory")
    /* stub */
}

rTextureMemory::~rTextureMemory() {
    DDON_STUB("rTextureMemory::~rTextureMemory")
    /* stub */
}

inline rTextureMemory::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rTextureMemory::MyDTI rTextureMemory::DTI("rTextureMemory", &::rTexture::DTI, 264ul, 0u, 0u);

__attribute__((weak)) MtObject* rTextureMemory::MyDTI::newInstance() const {
    DDON_STUB("rTextureMemory::MyDTI::newInstance")
    return nullptr;
}

