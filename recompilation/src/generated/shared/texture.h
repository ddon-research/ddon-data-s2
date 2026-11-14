#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "constants.h"

#include "dataformats.h"
#include "gpumem.h"

// Forward declarations
namespace sce { namespace Gnm { class DataFormat; } }
namespace sce { namespace Gnm { class SizeAlign; } }

// Declarations
namespace sce { namespace Gnm { class Texture; } }

// Type aliases from DWARF
using __uint32_t = unsigned int;
using __uint8_t = unsigned char;
using uint32_t = __uint32_t;
using uint8_t = __uint8_t;

namespace sce {
    namespace Gnm {
        class Texture
        {
        public:
            sce::Gnm::SizeAlign initAs1d(uint32_t width, uint32_t numMipLevels, sce::Gnm::DataFormat format, sce::Gnm::TileMode tileModeHint);
            sce::Gnm::SizeAlign initAs1dArray(uint32_t width, uint32_t numSlices, uint32_t numMipLevels, sce::Gnm::DataFormat format, sce::Gnm::TileMode tileModeHint);
            sce::Gnm::SizeAlign initAs2d(uint32_t width, uint32_t height, uint32_t numMipLevels, sce::Gnm::DataFormat format, sce::Gnm::TileMode tileModeHint, sce::Gnm::NumFragments numFragments);
            sce::Gnm::SizeAlign initAs2dArray(uint32_t width, uint32_t height, uint32_t numSlices, uint32_t numMipLevels, sce::Gnm::DataFormat format, sce::Gnm::TileMode tileModeHint, sce::Gnm::NumFragments numFragments, bool isCubemap);
            sce::Gnm::SizeAlign initAs2dArray(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, sce::Gnm::DataFormat, sce::Gnm::TileMode, sce::Gnm::NumFragments, bool);
            sce::Gnm::SizeAlign initAsCubemap(uint32_t width, uint32_t height, uint32_t numMipLevels, sce::Gnm::DataFormat format, sce::Gnm::TileMode tileModeHint);
            sce::Gnm::SizeAlign initAsCubemapArray(uint32_t width, uint32_t height, uint32_t numCubemaps, uint32_t numMipLevels, sce::Gnm::DataFormat format, sce::Gnm::TileMode tileModeHint);
            sce::Gnm::SizeAlign initAs3d(uint32_t, uint32_t, uint32_t, uint32_t, sce::Gnm::DataFormat, sce::Gnm::TileMode);
            sce::Gnm::SizeAlign initAsFmask(uint32_t, uint32_t, uint32_t, uint32_t, sce::Gnm::TileMode, sce::Gnm::NumSamples, sce::Gnm::NumFragments);
            sce::Gnm::SizeAlign initAsFmask(uint32_t, uint32_t, uint32_t, sce::Gnm::TileMode, sce::Gnm::NumSamples, sce::Gnm::NumFragments);
            void setBaseAddress256ByteBlocks(uint32_t baseAddr256);
            void setBaseAddress(void* baseAddr);
            void setMinLodClamp(uint32_t);
            void setArrayView(uint32_t, uint32_t);
            void setChannelType(sce::Gnm::TextureChannelType);
            void setChannelOrder(sce::Gnm::TextureChannel, sce::Gnm::TextureChannel, sce::Gnm::TextureChannel, sce::Gnm::TextureChannel);
            void setMinLodWarning(uint32_t);
            uint32_t getMinLodWarning() const;
            void setMipStatsCounterIndex(uint8_t);
            uint8_t getMipStatsCounterIndex() const;
            void setMipStatsEnable(bool);
            bool isMipStatsEnabled() const;
            sce::Gnm::TextureType getTextureType() const;
            uint32_t getBaseAddress256ByteBlocks() const;
            void* getBaseAddress() const;
            void setSamplerModulationFactor(sce::Gnm::SamplerModulationFactor);
            sce::Gnm::SamplerModulationFactor getSamplerModulationFactor() const;
            sce::Gnm::TileMode getTileMode() const;
            uint32_t getMinLodClamp() const;
            uint32_t getPitchMinus1() const;
            uint32_t getWidthMinus1() const;
            uint32_t getHeightMinus1() const;
            uint32_t getDepthMinus1() const;
            sce::Gnm::DataFormat getDataFormat() const;
            uint32_t getBaseArraySliceIndex() const;
            uint32_t getLastArraySliceIndex() const;
            uint32_t getBaseMipLevel() const;
            uint32_t getLastMipLevel() const;
            bool isPaddedToPow2() const;
            sce::Gnm::NumFragments getNumFragments() const;
            uint32_t getWidth() const;
            uint32_t getHeight() const;
            uint32_t getDepth() const;
            uint32_t getPitch() const;
            bool isTexture() const;
            void setTextureType(sce::Gnm::TextureType texType);
            void setTileMode(sce::Gnm::TileMode);
            void setPitchMinus1(uint32_t pitchMinus1);
            void setWidthMinus1(uint32_t widthMinus1);
            void setHeightMinus1(uint32_t heightMinus1);
            void setDepthMinus1(uint32_t);
            void setDataFormat(sce::Gnm::DataFormat);
            void setIsPaddedToPow2(bool);
        public:
            uint32_t m_regs[8];  // offset: 0x0
        };
    }  // namespace Gnm
}  // namespace sce

inline sce::Gnm::TileMode sce::Gnm::Texture::getTileMode() const {
    return static_cast<sce::Gnm::TileMode>((this->m_regs[3] >> 20) & 0x1fu);
}

inline void sce::Gnm::Texture::setBaseAddress256ByteBlocks(uint32_t baseAddr256) {
    this->m_regs[0] = baseAddr256;
}

inline void sce::Gnm::Texture::setBaseAddress(void* baseAddr) {
    this->setBaseAddress256ByteBlocks(static_cast<uint32_t>(reinterpret_cast<uintptr_t>(baseAddr) >> 8));
}

inline sce::Gnm::SizeAlign sce::Gnm::Texture::initAs1d(uint32_t width, uint32_t numMipLevels, sce::Gnm::DataFormat format, sce::Gnm::TileMode tileModeHint) {
    return this->initAs2d(width, 1u, numMipLevels, format, tileModeHint, sce::Gnm::kNumFragments1);
}

inline sce::Gnm::SizeAlign sce::Gnm::Texture::initAs1dArray(uint32_t width, uint32_t numSlices, uint32_t numMipLevels, sce::Gnm::DataFormat format, sce::Gnm::TileMode tileModeHint) {
    return this->initAs2dArray(width, 1u, numSlices, numMipLevels, format, tileModeHint, sce::Gnm::kNumFragments1, false);
}

inline sce::Gnm::SizeAlign sce::Gnm::Texture::initAs2d(uint32_t width, uint32_t height, uint32_t numMipLevels, sce::Gnm::DataFormat format, sce::Gnm::TileMode tileModeHint, sce::Gnm::NumFragments numFragments) {
    for (int i = 0; i < 8; ++i) this->m_regs[i] = 0;
    uint32_t pitch = (tileModeHint == sce::Gnm::kTileModeDisplay_LinearAligned) ? ((width + 63u) & ~63u) : width;
    if (pitch == 0) pitch = 1u;
    this->m_regs[1] = format.m_asInt;
    this->m_regs[2] = ((width - 1u) & 0x3fffu) | (((height - 1u) & 0x3fffu) << 14);
    this->m_regs[3] = (static_cast<uint32_t>(sce::Gnm::kTextureType2d) << 28) | ((static_cast<uint32_t>(tileModeHint) & 0x1fu) << 20);
    this->m_regs[4] = ((pitch - 1u) & 0x3fffu) << 13;
    uint32_t bpe = 16u;
    switch (format.m_bits.m_surfaceFormat) {
    case sce::Gnm::kSurfaceFormat8: bpe = 1u; break;
    case sce::Gnm::kSurfaceFormat16:
    case sce::Gnm::kSurfaceFormat8_8:
    case sce::Gnm::kSurfaceFormat5_6_5:
    case sce::Gnm::kSurfaceFormat1_5_5_5:
    case sce::Gnm::kSurfaceFormat5_5_5_1:
    case sce::Gnm::kSurfaceFormat4_4_4_4: bpe = 2u; break;
    case sce::Gnm::kSurfaceFormat32:
    case sce::Gnm::kSurfaceFormat16_16:
    case sce::Gnm::kSurfaceFormat10_11_11:
    case sce::Gnm::kSurfaceFormat11_11_10:
    case sce::Gnm::kSurfaceFormat10_10_10_2:
    case sce::Gnm::kSurfaceFormat2_10_10_10:
    case sce::Gnm::kSurfaceFormat8_8_8_8:
    case sce::Gnm::kSurfaceFormat8_24:
    case sce::Gnm::kSurfaceFormat24_8:
    case sce::Gnm::kSurfaceFormat5_9_9_9: bpe = 4u; break;
    case sce::Gnm::kSurfaceFormat32_32:
    case sce::Gnm::kSurfaceFormat16_16_16_16: bpe = 8u; break;
    case sce::Gnm::kSurfaceFormat32_32_32_32: bpe = 16u; break;
    default: bpe = 16u; break;
    }
    uint32_t sz = pitch * height * bpe * (1u << static_cast<uint32_t>(numFragments));
    if (numMipLevels > 1u) sz *= 2u;
    return sce::Gnm::SizeAlign(sz, 256u);
}

inline sce::Gnm::SizeAlign sce::Gnm::Texture::initAs2dArray(uint32_t width, uint32_t height, uint32_t numSlices, uint32_t numMipLevels, sce::Gnm::DataFormat format, sce::Gnm::TileMode tileModeHint, sce::Gnm::NumFragments numFragments, bool isCubemap) {
    sce::Gnm::SizeAlign sa = this->initAs2d(width, height, numMipLevels, format, tileModeHint, numFragments);
    this->m_regs[3] = (this->m_regs[3] & ~(0xfu << 28)) | (static_cast<uint32_t>(isCubemap ? sce::Gnm::kTextureTypeCubemap : sce::Gnm::kTextureType2dArray) << 28);
    if (numSlices > 1u) sa.m_size *= numSlices;
    return sa;
}

inline sce::Gnm::SizeAlign sce::Gnm::Texture::initAsCubemap(uint32_t width, uint32_t height, uint32_t numMipLevels, sce::Gnm::DataFormat format, sce::Gnm::TileMode tileModeHint) {
    return this->initAs2dArray(width, height, 6u, numMipLevels, format, tileModeHint, sce::Gnm::kNumFragments1, true);
}

inline sce::Gnm::SizeAlign sce::Gnm::Texture::initAsCubemapArray(uint32_t width, uint32_t height, uint32_t numCubemaps, uint32_t numMipLevels, sce::Gnm::DataFormat format, sce::Gnm::TileMode tileModeHint) {
    return this->initAs2dArray(width, height, numCubemaps * 6u, numMipLevels, format, tileModeHint, sce::Gnm::kNumFragments1, true);
}

inline sce::Gnm::SizeAlign sce::Gnm::Texture::initAs3d(uint32_t width, uint32_t height, uint32_t depth, uint32_t numMipLevels, sce::Gnm::DataFormat format, sce::Gnm::TileMode tileModeHint) {
    sce::Gnm::SizeAlign sa = this->initAs2d(width, height, numMipLevels, format, tileModeHint, sce::Gnm::kNumFragments1);
    this->m_regs[3] = (this->m_regs[3] & ~(0xfu << 28)) | (static_cast<uint32_t>(sce::Gnm::kTextureType3d) << 28);
    if (depth > 1u) sa.m_size *= depth;
    return sa;
}
