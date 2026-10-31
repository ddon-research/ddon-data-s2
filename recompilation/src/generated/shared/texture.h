#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "constants.h"

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
