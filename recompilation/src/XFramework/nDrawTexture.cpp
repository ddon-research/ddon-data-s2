// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "nDrawTexture.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemory.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtPrimitive2D.h"
#include "../MT/MtPropertyList.h"
#include "cSystem.h"
#include "../generated/shared/dataformats.h"
#include "../generated/shared/depthrendertarget.h"
#include "nDrawBuffer.h"
#include "nDrawResource.h"
#include "../generated/shared/rendertarget.h"
#include "sRender.h"
#include "../generated/shared/texture.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nDraw::DepthStencilView::getDTI() const {
    return nDraw::DepthStencilView::DTI;
}

nDraw::DepthStencilView::DepthStencilView(nDraw::Texture* ptex, u32 subresource) {
    DDON_STUB("nDraw::DepthStencilView::DepthStencilView")
    /* stub */
}

nDraw::DepthStencilView::~DepthStencilView() {
    if (mpHandle == nullptr) {
        return;
    }
    mpDepthAddress = nullptr;
    ::MtMemory::mpAllocatorType[6]->memFree(mpStencilAddress);
    mpStencilAddress = nullptr;
    ::MtMemory::mpAllocatorType[6]->memFree(mpHtileAddress);
    mpHtileAddress = nullptr;
    mpHandle = nullptr;
}

__attribute__((weak)) nDraw::HDepthStencil nDraw::DepthStencilView::getHandle() const {
    DDON_STUB("nDraw::DepthStencilView::getHandle")
    return {};
}

inline nDraw::DepthStencilView::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nDraw::DepthStencilView::MyDTI nDraw::DepthStencilView::DTI("nDraw::DepthStencilView", &::nDraw::Resource::DTI, 136ul, 0u, 0u);

__attribute__((weak)) MtObject* nDraw::DepthStencilView::MyDTI::newInstance() const {
    DDON_STUB("nDraw::DepthStencilView::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nDraw::RenderTargetView::getDTI() const {
    return nDraw::RenderTargetView::DTI;
}

nDraw::RenderTargetView::~RenderTargetView() {
    if (mpHandle == nullptr) {
        return;
    }
    mpSurfaceAddress = nullptr;
    mpHandle = nullptr;
}

__attribute__((weak)) nDraw::HRenderTarget nDraw::RenderTargetView::getHandle() const {
    DDON_STUB("nDraw::RenderTargetView::getHandle")
    return {};
}

inline nDraw::RenderTargetView::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nDraw::RenderTargetView::MyDTI nDraw::RenderTargetView::DTI("nDraw::RenderTargetView", &::nDraw::Resource::DTI, 112ul, 0u, 0u);

__attribute__((weak)) MtObject* nDraw::RenderTargetView::MyDTI::newInstance() const {
    DDON_STUB("nDraw::RenderTargetView::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nDraw::Texture::getDTI() const {
    return nDraw::Texture::DTI;
}

void* nDraw::Texture::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nDraw::Texture::DTI)->memAlloc(sz, align, ::nDraw::Texture::DTI.mID);
}

nDraw::Texture::Texture(u32 w, u32 miplevels, u32 arraysize, nDraw::FORMAT_TYPE fmt, nDraw::USAGE_TYPE usage, u32 misc_flags, nDraw::Texture* psharedtex, u32 share_offset, void* pinitvalues, nDraw::TEXMEMORY_TYPE memtype) : nDraw::Buffer(usage) {
    init(static_cast<u32>((arraysize <= 1u) ? 1 : 4), w, 1u, 1u, miplevels, arraysize, fmt, misc_flags, MT_CTSTR(), MT_CTSTR());
    create(psharedtex, u32(), pinitvalues);
}

nDraw::Texture::Texture(u32 w, u32 h, u32 miplevels, u32 arraysize, nDraw::FORMAT_TYPE fmt, nDraw::USAGE_TYPE usage, u32 misc_flags, nDraw::Texture* psharedtex, u32 share_offset, void* pinitvalues, nDraw::TEXMEMORY_TYPE memtype) : nDraw::Buffer(usage) {
    if (((misc_flags >> 8) & 15u) != 0) {
        init(static_cast<u32>(static_cast<unsigned long>(arraysize > 1u) | 8), w, h, 1u, miplevels, arraysize, fmt, misc_flags, MT_CTSTR(), MT_CTSTR());
    } else {
        if ((misc_flags & 8u) == 0) {
            init(static_cast<u32>((arraysize <= 1u) ? 2 : 5), w, h, 1u, miplevels, arraysize, fmt, misc_flags, MT_CTSTR(), MT_CTSTR());
        } else {
            init(6u, w, h, 1u, miplevels, arraysize, fmt, misc_flags, MT_CTSTR(), MT_CTSTR());
        }
    }
    create(psharedtex, u32(), pinitvalues);
}

nDraw::Texture::Texture(u32 w, u32 h, u32 d, u32 miplevels, u32 arraysize, nDraw::FORMAT_TYPE fmt, nDraw::USAGE_TYPE usage, u32 misc_flags, nDraw::Texture* psharedtex, u32 share_offset, void* pinitvalues) : nDraw::Buffer(usage) {
    init(3u, w, h, d, miplevels, arraysize, fmt, misc_flags, MT_CTSTR(), MT_CTSTR());
    create(psharedtex, u32(), pinitvalues);
}

__attribute__((weak)) void nDraw::Texture::release() {
    s32 ref = decRefCount();
    if (ref > 1) {
        return;
    }
    if (mScratch != 0) {
        if (ref != 1) {
            return;
        }
        if (!terminate(1)) {
            return;
        }
        sRender::getInstance()->removeScratchTexture(this);
    } else {
        if (ref != 0) {
            return;
        }
    }
    if (isProtect()) {
        sRender::getInstance()->addProtectResource(this);
    } else {
        delete this;
    }
}

__attribute__((weak)) void nDraw::Texture::suspend() {
}

void nDraw::Texture::resume() {
    this->::nDraw::Buffer::resume();
}

__attribute__((weak)) nDraw::MAPPED_TEXTURE nDraw::Texture::map(u32 subresource, nDraw::MAP_TYPE type, const MtRect* prect) {
        u32 levelIndex = subresource % mLevelCount;
        u32 arrayIndex = subresource / mLevelCount;
        void* pdata = nullptr;
        u32 pitch = 0;
        nDraw::MAPPED_TEXTURE mt;
        if (mpTexture->getTileMode() == sce::Gnm::kTileModeDisplay_LinearAligned) {
            u64 ofs;
            u64 siz;
            sce::GpuAddress::computeTextureSurfaceOffsetAndSize(&ofs, &siz, mpTexture, levelIndex, arrayIndex);
            pdata = static_cast<u8*>(mpBuffer) + ofs;
            pitch = mpTexture->getPitch() * (calcBitCount(static_cast<nDraw::FORMAT_TYPE>(mFormatType)) >> 3);
        } else {
            if (mpMappingAddresses == nullptr) {
                const size_t alloc_size = static_cast<size_t>(mArrayCount) * mLevelCount * sizeof(void*);
                mpMappingAddresses = static_cast<void**>(MtMemoryAllocator::getAllocator(DTI)->memAlloc(alloc_size, 16));
                memset(mpMappingAddresses, 0, alloc_size);
            }
            if (mpMappingAddresses[subresource] == nullptr) {
                sce::GpuAddress::TilingParameters tileParams;
                tileParams.initFromTexture(mpTexture, levelIndex, arrayIndex);
                u64 mapSize;
                sce::Gnm::AlignmentType mapAlign;
                sce::GpuAddress::computeUntiledSurfaceSize(&mapSize, &mapAlign, &tileParams);
                void* pdst = MtMemory::mpAllocatorType[MtMemoryAllocator::ONION]->memAlloc(mapSize, mapAlign);
                u64 ofs;
                u64 siz;
                sce::GpuAddress::computeTextureSurfaceOffsetAndSize(&ofs, &siz, mpTexture, levelIndex, arrayIndex);
                void* psrc = static_cast<u8*>(mpBuffer) + ofs;
                sce::GpuAddress::detileSurface(pdst, psrc, &tileParams);
                mpMappingAddresses[subresource] = pdst;
            }
            pdata = mpMappingAddresses[subresource];
            pitch = mpTexture->getWidth() * (calcBitCount(static_cast<nDraw::FORMAT_TYPE>(mFormatType)) >> 3);
        }
        mt.pdata = pdata;
        mt.pitch = pitch >> levelIndex;
        mt.depth = mt.pitch * (mpTexture->getHeight() >> levelIndex);
        return mt;
}

__attribute__((weak)) void nDraw::Texture::unmap(u32 subresource) {
    if (mpMappingAddresses != nullptr && mpMappingAddresses[subresource] != nullptr) {
        u32 levelIndex = subresource % mLevelCount;
        u32 arrayIndex = subresource / mLevelCount;
        sce::GpuAddress::TilingParameters tileParams;
        tileParams.initFromTexture(mpTexture, levelIndex, arrayIndex);
        u64 ofs;
        u64 siz;
        sce::GpuAddress::computeTextureSurfaceOffsetAndSize(&ofs, &siz, mpTexture, levelIndex, arrayIndex);
        void* pdst = static_cast<u8*>(mpBuffer) + ofs;
        void* psrc = mpMappingAddresses[subresource];
        sce::GpuAddress::tileSurface(pdst, psrc, &tileParams);
    }
}

static auto ddon_emit_0x01b82e90 __attribute__((used)) = &nDraw::Texture::getWidth;

__attribute__((weak)) u32 nDraw::Texture::getHeight() const {
    DDON_STUB("nDraw::Texture::getHeight")
    return {};
}

static auto ddon_emit_0x01b82f00 __attribute__((used)) = &nDraw::Texture::getDepth;

static auto ddon_emit_0x01b82f10 __attribute__((used)) = &nDraw::Texture::getArrayCount;

static auto ddon_emit_0x01b82e80 __attribute__((used)) = &nDraw::Texture::getLevelCount;

static auto ddon_emit_0x01b82f20 __attribute__((used)) = &nDraw::Texture::getFormat;

__attribute__((weak)) nDraw::GPUFORMAT_TYPE nDraw::Texture::getGPUFormat() const {
    DDON_STUB("nDraw::Texture::getGPUFormat")
    __builtin_unreachable();
}

__attribute__((weak)) void nDraw::Texture::setTextureData(const u32& w, const u32& h, const nDraw::GPUFORMAT_TYPE format, void* pbin) {
    DDON_STUB("nDraw::Texture::setTextureData")
    /* stub */
}

static auto ddon_emit_0x01b82ec0 __attribute__((used)) = &nDraw::Texture::isSRGB;

static auto ddon_emit_0x01b82eb0 __attribute__((used)) = &nDraw::Texture::getMiscFlags;

__attribute__((weak)) nDraw::HTexture nDraw::Texture::getHandle() const {
    DDON_STUB("nDraw::Texture::getHandle")
    return {};
}

__attribute__((weak)) u32 nDraw::Texture::getViewNum() const {
    DDON_STUB("nDraw::Texture::getViewNum")
    return {};
}

__attribute__((weak)) nDraw::RenderTargetView* nDraw::Texture::getRenderTargetView(u32 subresource) const {
    DDON_STUB("nDraw::Texture::getRenderTargetView")
    return nullptr;
}

__attribute__((weak)) nDraw::DepthStencilView* nDraw::Texture::getDepthStencilView(u32 subresource) const {
    DDON_STUB("nDraw::Texture::getDepthStencilView")
    return nullptr;
}

__attribute__((weak)) u32 nDraw::Texture::calcBitCount(nDraw::FORMAT_TYPE fmt) {
    switch (fmt) {
    case FORMAT_R32G32B32A32_FLOAT: return 128;
    case FORMAT_R16G16B16A16_FLOAT:
    case FORMAT_R16G16B16A16_UNORM:
    case FORMAT_R16G16B16A16_SNORM:
    case FORMAT_R32G32_FLOAT: return 64;
    case FORMAT_R10G10B10A2_UNORM:
    case FORMAT_R8G8B8A8_UNORM:
    case FORMAT_R8G8B8A8_SNORM:
    case FORMAT_R8G8B8A8_UNORM_SRGB: return 32;
    case FORMAT_B4G4R4A4_UNORM: return 16;
    case FORMAT_R16G16_FLOAT:
    case FORMAT_R16G16_UNORM:
    case FORMAT_R16G16_SNORM:
    case FORMAT_R32_FLOAT:
    case FORMAT_D24_UNORM_S8_UINT: return 32;
    case FORMAT_R16_FLOAT:
    case FORMAT_R16_UNORM: return 16;
    case FORMAT_A8_UNORM: return 8;
    case FORMAT_BC1_UNORM:
    case FORMAT_BC1_UNORM_SRGB: return 4;
    case FORMAT_BC2_UNORM:
    case FORMAT_BC2_UNORM_SRGB:
    case FORMAT_BC3_UNORM:
    case FORMAT_BC3_UNORM_SRGB: return 8;
    case FORMAT_BCX_GRAYSCALE:
    case FORMAT_BCX_ALPHA: return 4;
    case FORMAT_BC5_SNORM: return 8;
    case FORMAT_B5G6R5_UNORM:
    case FORMAT_B5G5R5A1_UNORM: return 16;
    case FORMAT_BCX_NM1: return 4;
    case FORMAT_BCX_NM2:
    case FORMAT_BCX_RGBI:
    case FORMAT_BCX_RGBY: return 8;
    case FORMAT_B8G8R8X8_UNORM: return 32;
    case FORMAT_BCX_RGBI_SRGB:
    case FORMAT_BCX_RGBY_SRGB:
    case FORMAT_BCX_NH: return 8;
    case FORMAT_R11G11B10_FLOAT:
    case FORMAT_B8G8R8A8_UNORM:
    case FORMAT_B8G8R8A8_UNORM_SRGB: return 32;
    case FORMAT_BCX_RGBNL: return 4;
    case FORMAT_BCX_YCCA:
    case FORMAT_BCX_YCCA_SRGB: return 8;
    case FORMAT_R8_UNORM: return 8;
    case FORMAT_B8G8R8A8_UNORM_LE:
    case FORMAT_B10G10R10A2_UNORM_LE: return 32;
    case FORMAT_BCX_SRGBA:
    case FORMAT_BC7_UNORM:
    case FORMAT_BC7_UNORM_SRGB: return 8;
    case FORMAT_SE5M9M9M9:
    case FORMAT_R10G10B10A2_FLOAT: return 32;
    case FORMAT_YVU420P2_CSC1: return 12;
    case FORMAT_R8A8_UNORM: return 16;
    case FORMAT_A8_UNORM_WHITE: return 8;
    default: return 32;
    }
}

__attribute__((weak)) MtSize nDraw::Texture::calcBufferSize(u32 w, u32 h, u32 level, nDraw::FORMAT_TYPE fmt) {
    MtSize dz;
    MtSize sz;
    w >>= level;
    if (w == 0) w = 1;
    h >>= level;
    if (h == 0) h = 1;
    switch (fmt) {
    case FORMAT_BC2_UNORM:
    case FORMAT_BC2_UNORM_SRGB:
    case FORMAT_BC3_UNORM:
    case FORMAT_BC3_UNORM_SRGB:
    case FORMAT_BC5_SNORM:
    case FORMAT_BCX_NM2:
    case FORMAT_BCX_RGBI:
    case FORMAT_BCX_RGBY:
    case FORMAT_BCX_RGBI_SRGB:
    case FORMAT_BCX_RGBY_SRGB:
    case FORMAT_BCX_NH:
    case FORMAT_BCX_YCCA:
    case FORMAT_BCX_YCCA_SRGB:
    case FORMAT_BCX_SRGBA:
    case FORMAT_BC7_UNORM:
    case FORMAT_BC7_UNORM_SRGB: {
        s32 bw = (static_cast<s32>(w) + 3) / 4;
        sz.w = (static_cast<s32>(w) + 3 < 4) ? 16 : (bw * 16);
        s32 bh = (static_cast<s32>(h) + 3) / 4;
        sz.h = (bh > 0) ? bh : 1;
        break;
    }
    case FORMAT_BC1_UNORM:
    case FORMAT_BC1_UNORM_SRGB:
    case FORMAT_BCX_GRAYSCALE:
    case FORMAT_BCX_ALPHA:
    case FORMAT_BCX_NM1:
    case FORMAT_BCX_RGBNL: {
        s32 bw = (static_cast<s32>(w) + 3) / 4;
        sz.w = (static_cast<s32>(w) + 3 < 4) ? 8 : (bw * 8);
        s32 bh = (static_cast<s32>(h) + 3) / 4;
        sz.h = (bh > 0) ? bh : 1;
        break;
    }
    case FORMAT_YVU420P2_CSC1:
        sz.w = (static_cast<s32>(w) * 12) / 8;
        sz.h = h;
        break;
    default:
        sz.w = (((w * calcBitCount(fmt)) / 8) + 3) / 4 * 4;
        sz.h = h;
        break;
    }
    return sz;
}

__attribute__((weak)) u32 nDraw::Texture::calcMipLevelCount(u32 size) {
        u32 n = 0;
        while ((1u << n) <= size) {
            n++;
        }
        return n;
}

__attribute__((weak)) sce::Gnm::DataFormat nDraw::Texture::getGPUFormatType(const nDraw::FORMAT_TYPE fmt) {
    static const sce::Gnm::DataFormat customDataFormatA8UnormWhite = {{0x01, 0x0, 0x1, 0x1, 0x1, 0x4, 0x0}};
    static const sce::Gnm::DataFormat d3dfmt[55] = {
        {{0x00, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
        {{0x0e, 0x7, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x0c, 0x7, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x0c, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x0c, 0x1, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x0b, 0x7, 0x4, 0x5, 0x0, 0x1, 0x0}},
        {{0x09, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x0a, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x0a, 0x1, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x0a, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x13, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x05, 0x7, 0x4, 0x5, 0x0, 0x1, 0x0}},
        {{0x05, 0x0, 0x4, 0x5, 0x0, 0x1, 0x0}},
        {{0x05, 0x1, 0x4, 0x5, 0x0, 0x1, 0x0}},
        {{0x04, 0x7, 0x4, 0x0, 0x0, 0x1, 0x0}},
        sce::Gnm::DataFormat::build(sce::Gnm::kZFormat32Float),
        {{0x02, 0x7, 0x4, 0x0, 0x0, 0x1, 0x0}},
        {{0x02, 0x0, 0x4, 0x0, 0x0, 0x1, 0x0}},
        {{0x01, 0x0, 0x0, 0x0, 0x0, 0x4, 0x0}},
        {{0x23, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x23, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x24, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x24, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x25, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x25, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x26, 0x0, 0x4, 0x0, 0x0, 0x1, 0x0}},
        {{0x26, 0x1, 0x4, 0x0, 0x0, 0x1, 0x0}},
        {{0x27, 0x1, 0x4, 0x5, 0x0, 0x1, 0x0}},
        {{0x10, 0x0, 0x6, 0x5, 0x4, 0x1, 0x0}},
        {{0x11, 0x0, 0x6, 0x5, 0x4, 0x7, 0x0}},
        {{0x23, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x27, 0x0, 0x4, 0x5, 0x0, 0x1, 0x0}},
        {{0x25, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x25, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x0a, 0x0, 0x6, 0x5, 0x4, 0x1, 0x0}},
        {{0x25, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x25, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x25, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x06, 0x7, 0x4, 0x5, 0x6, 0x1, 0x0}},
        {{0x0a, 0x0, 0x6, 0x5, 0x4, 0x7, 0x0}},
        {{0x0a, 0x0, 0x6, 0x5, 0x4, 0x7, 0x0}},
        {{0x23, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x25, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x25, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x01, 0x0, 0x4, 0x0, 0x0, 0x1, 0x0}},
        {{0x0a, 0x0, 0x6, 0x5, 0x4, 0x7, 0x0}},
        {{0x09, 0x0, 0x6, 0x5, 0x4, 0x7, 0x0}},
        {{0x25, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x29, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x29, 0x0, 0x4, 0x5, 0x6, 0x7, 0x0}},
        {{0x22, 0x7, 0x4, 0x5, 0x6, 0x1, 0x0}},
        {{0x00, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
        {{0x00, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
        {{0x00, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}},
        customDataFormatA8UnormWhite,
    };
    return d3dfmt[fmt];
}

MtUI* nDraw::Texture::createUI(MtProperty& prop) {
    return this->::nDraw::Buffer::createUI(prop);
}

__attribute__((weak)) void nDraw::Texture::createProperty(MtPropertyList& s) {
    DDON_STUB("nDraw::Texture::createProperty")
    /* stub */
}

void nDraw::Texture::registerScratchTexture() {
    addRef();
}

__attribute__((weak)) void nDraw::Texture::unregisterScratchTexture() {
}

__attribute__((noinline)) nDraw::Texture::~Texture() {
        if (mpRTView != nullptr) {
            for (u32 i = 0; i < mViewNum; ++i) {
                if (mpRTView[i] != nullptr) {
                    mpRTView[i]->release();
                    mpRTView[i] = nullptr;
                }
            }
            MtMemoryAllocator::getAllocator(DTI)->memFree(mpRTView);
            mpRTView = nullptr;
        }
        if (mpDSView != nullptr) {
            for (u32 i = 0; i < mViewNum; ++i) {
                if (mpDSView[i] != nullptr) {
                    mpDSView[i]->release();
                    mpDSView[i] = nullptr;
                }
            }
            MtMemoryAllocator::getAllocator(DTI)->memFree(mpDSView);
            mpDSView = nullptr;
        }
        mViewNum = 0;
        if (mpSharedTexture != nullptr) {
            mpSharedTexture->release();
            mpSharedTexture = nullptr;
        } else if (mpBuffer != nullptr) {
            MtMemory::mpAllocatorType[MtMemoryAllocator::GARLIC]->memFree(mpBuffer);
        }
        mpBuffer = nullptr;
        if (mpMappingAddresses != nullptr) {
            u32 subresourceNum = mArrayCount * mLevelCount;
            if (subresourceNum != 0) {
                for (u32 i = 0; i < subresourceNum; ++i) {
                    if (mpMappingAddresses[i] != nullptr) {
                        MtMemory::mpAllocatorType[MtMemoryAllocator::ONION]->memFree(mpMappingAddresses[i]);
                    }
                }
            }
            MtMemoryAllocator::getAllocator(DTI)->memFree(mpMappingAddresses);
            mpMappingAddresses = nullptr;
        }
}

__attribute__((weak)) void nDraw::Texture::init(u32 type, u32 width, u32 height, u32 depth, u32 miplevel, u32 arraysize, nDraw::FORMAT_TYPE fmt, u32 misc_flags, MT_CTSTR pool, MT_CTSTR name) {
        mpTexture = nullptr;
        mWidth = width;
        mHeight = height;
        mDepth = depth;
        mLevelCount = miplevel;
        mArrayCount = arraysize;
        mFormatType = fmt;
        mMiscFlags = misc_flags;
        mpSharedTexture = nullptr;
        mTextureType = type;
        mScratch = 0;
        mViewNum = 0;
        mpDSView = nullptr;
        mpRTView = nullptr;
        mpMappingAddresses = nullptr;
    
        if ((mMiscFlags & 0xff000u) == 0) {
            switch (fmt) {
            case FORMAT_BCX_GRAYSCALE:
            case FORMAT_BCX_ALPHA:
            case FORMAT_BC5_SNORM:
                mMiscFlags |= 0x2000u;
                break;
            case FORMAT_BCX_NM1:
                mMiscFlags |= 0x8000u;
                break;
            case FORMAT_BCX_NM2:
                mMiscFlags |= 0x9000u;
                break;
            case FORMAT_BCX_RGBI:
            case FORMAT_BCX_RGBI_SRGB:
                mMiscFlags |= 0x4000u;
                break;
            case FORMAT_BCX_RGBY:
            case FORMAT_BCX_RGBY_SRGB:
                mMiscFlags |= 0xf000u;
                break;
            case FORMAT_BCX_NH:
                mMiscFlags |= 0x14000u;
                break;
            case FORMAT_BCX_RGBNL:
                mMiscFlags |= 0x15000u;
                break;
            case FORMAT_BCX_YCCA:
            case FORMAT_BCX_YCCA_SRGB:
                mMiscFlags |= 0x16000u;
                break;
            case FORMAT_BCX_SRGBA:
                mMiscFlags |= 0x18000u;
                break;
            default:
                break;
            }
        }
        if ((mMiscFlags & 0xf00000u) == 0 && fmt == FORMAT_BCX_NH) {
            mMiscFlags |= 0xb00000u;
        }
        bool sRGBEmulation = isSRGBFormat(fmt);
        mSRGB = sRGBEmulation;
        if (sRGBEmulation && (mUsageType == USAGE_RENDERTARGET || mUsageType == USAGE_DISPLAYBUFFER)) {
            if (fmt == FORMAT_R8G8B8A8_UNORM_SRGB || fmt == FORMAT_B8G8R8A8_UNORM_SRGB) {
                mMiscFlags |= 0x80000u;
            }
        }
        if (mLevelCount == 0) {
            u32 maxSize = (width > height) ? width : height;
            if (type == TT_3D && depth > maxSize) {
                maxSize = depth;
            }
            mLevelCount = calcMipLevelCount(maxSize);
        }
        if (name != nullptr) {
            calcCRC(name, static_cast<u32>(strlen(name)));
        }
        mGPUFormatType = getGPUFormatType(fmt);
        if (mUsageType == USAGE_DYNAMIC || mUsageType == USAGE_STAGING || mUsageType == USAGE_MANAGED) {
            mMiscFlags |= 0x10u;
        }
        if (mMiscFlags & 0x10u) {
            switch (fmt) {
            case FORMAT_BC1_UNORM:
            case FORMAT_BC1_UNORM_SRGB:
            case FORMAT_BC2_UNORM:
            case FORMAT_BC2_UNORM_SRGB:
            case FORMAT_BC3_UNORM:
            case FORMAT_BC3_UNORM_SRGB:
            case FORMAT_BCX_GRAYSCALE:
            case FORMAT_BCX_ALPHA:
            case FORMAT_BC5_SNORM:
            case FORMAT_BCX_NM1:
            case FORMAT_BCX_NM2:
            case FORMAT_BCX_RGBI:
            case FORMAT_BCX_RGBY:
            case FORMAT_BCX_RGBI_SRGB:
            case FORMAT_BCX_RGBY_SRGB:
            case FORMAT_BCX_NH:
            case FORMAT_BCX_RGBNL:
            case FORMAT_BCX_YCCA:
            case FORMAT_BCX_YCCA_SRGB:
            case FORMAT_BCX_SRGBA:
            case FORMAT_BC7_UNORM:
            case FORMAT_BC7_UNORM_SRGB:
            case FORMAT_YVU420P2_CSC1:
                mMiscFlags &= ~0x10u;
                break;
            default:
                break;
            }
        }
}

__attribute__((weak)) void nDraw::Texture::create(nDraw::Texture* psharedtex, u32 offset, void* pinitvalues) {
        mpTexture = &mTextureObject;
        memset(&mTextureObject, 0, sizeof(mTextureObject));
        s32 usageType = mUsageType;
        if (psharedtex != nullptr &&
            mWidth == psharedtex->mWidth &&
            mHeight == psharedtex->mHeight &&
            mDepth == psharedtex->mDepth &&
            mTextureType == psharedtex->mTextureType &&
            mFormatType == psharedtex->mFormatType &&
            mSRGB == psharedtex->mSRGB &&
            ((mMiscFlags ^ psharedtex->mMiscFlags) & 0xf00002u) == 0) {
            mpSharedTexture = psharedtex;
            mpSharedTexture->addRef();
            mpTexture = mpSharedTexture->mpTexture;
            mGPUFormatType = mpSharedTexture->mGPUFormatType;
            mpBuffer = mpSharedTexture->mpBuffer;
            mBufSize = mpSharedTexture->mBufSize;
            mArrayCount = mpSharedTexture->mArrayCount;
            mLevelCount = mpSharedTexture->mLevelCount;
            mViewNum = mpSharedTexture->mViewNum;
        }
        if (mpSharedTexture == nullptr) {
            const u32 w = mWidth;
            const u32 h = mHeight;
            const u32 depth = mDepth;
            const u32 arrayCount = mArrayCount;
            const u32 mipLv = mLevelCount;
            sce::Gnm::TileMode tileMode = sce::Gnm::kTileModeDisplay_LinearAligned;
            if (usageType == USAGE_DISPLAYBUFFER) {
                mUsageType = USAGE_RENDERTARGET;
                usageType = USAGE_RENDERTARGET;
                sce::GpuAddress::computeSurfaceTileMode(&tileMode, sce::GpuAddress::kSurfaceTypeColorTargetDisplayable, mGPUFormatType, 1);
            } else if (usageType == USAGE_DEPTHSTENCIL) {
                sce::GpuAddress::computeSurfaceTileMode(&tileMode, sce::GpuAddress::kSurfaceTypeDepthOnlyTarget, mGPUFormatType, 1);
            } else if (usageType == USAGE_RENDERTARGET) {
                sce::GpuAddress::SurfaceType st = (mTextureType == TT_3D) ? sce::GpuAddress::kSurfaceTypeTextureVolume : sce::GpuAddress::kSurfaceTypeColorTarget;
                sce::GpuAddress::computeSurfaceTileMode(&tileMode, st, mGPUFormatType, 1);
            } else if ((mMiscFlags & 0x10u) == 0) {
                sce::GpuAddress::SurfaceType st = (mTextureType == TT_3D) ? sce::GpuAddress::kSurfaceTypeTextureVolume : sce::GpuAddress::kSurfaceTypeTextureFlat;
                sce::GpuAddress::computeSurfaceTileMode(&tileMode, st, mGPUFormatType, 1);
            }
            sce::Gnm::SizeAlign sizeAlign = {0, 0};
            switch (mTextureType) {
            case TT_1D:
                sizeAlign = mpTexture->initAs1d(w, mipLv, mGPUFormatType, tileMode);
                break;
            case TT_1DARRAY:
                sizeAlign = mpTexture->initAs1dArray(w, arrayCount, mipLv, mGPUFormatType, tileMode);
                break;
            case TT_2D:
                sizeAlign = mpTexture->initAs2d(w, h, mipLv, mGPUFormatType, tileMode, sce::Gnm::kNumFragments1);
                break;
            case TT_2DARRAY:
                sizeAlign = mpTexture->initAs2dArray(w, h, arrayCount, mipLv, mGPUFormatType, tileMode, sce::Gnm::kNumFragments1, false);
                break;
            case TT_CUBE:
                sizeAlign = mpTexture->initAsCubemap(w, h, mipLv, mGPUFormatType, tileMode);
                break;
            case TT_CUBEARRAY:
                sizeAlign = mpTexture->initAsCubemapArray(w, h, arrayCount / 6, mipLv, mGPUFormatType, tileMode);
                break;
            case TT_3D:
                sizeAlign = mpTexture->initAs3d(w, h, depth, mipLv, mGPUFormatType, tileMode);
                break;
            default:
                break;
            }
            mBufSize = sizeAlign.m_size;
            mpBuffer = MtMemory::mpAllocatorType[MtMemoryAllocator::GARLIC]->memAlloc(sizeAlign.m_size, sizeAlign.m_align);
            mpTexture->setBaseAddress(mpBuffer);
            if (pinitvalues != nullptr && mpBuffer != nullptr) {
                memcpy(mpBuffer, pinitvalues, sizeAlign.m_size);
            }
        }
}

u32 nDraw::Texture::getEncodeMode() {
    return mMiscFlags & 0xF00000u;
}

void nDraw::Texture::setEncodeMode(u32 v) {
    mMiscFlags = v | (mMiscFlags & 0xFF0FFFFFu);
}

u32 nDraw::Texture::getDecodeMode() {
    return mMiscFlags & 0x3F000u;
}

void nDraw::Texture::setDecodeMode(u32 v) {
    mMiscFlags = v | (mMiscFlags & 0xFFF00FFFu);
}

u32 nDraw::Texture::getMSAAMode() {
    return mMiscFlags & 3840u;
}

void nDraw::Texture::setMSAAMode(u32 v) {
    mMiscFlags = v | (mMiscFlags & 0xFFFFF0FFu);
}

inline nDraw::Texture::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nDraw::Texture::MyDTI nDraw::Texture::DTI("nDraw::Texture", &::nDraw::Buffer::DTI, 144ul, 0u, 0u);

__attribute__((weak)) MtObject* nDraw::Texture::MyDTI::newInstance() const {
    DDON_STUB("nDraw::Texture::MyDTI::newInstance")
    return nullptr;
}

