#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "constants.h"

// Forward declarations
namespace sce { namespace Gnm { class DataFormat; } }
namespace sce { namespace Gnm { class SizeAlign; } }
namespace sce { namespace Gnm { class Texture; } }

// Declarations
namespace sce { namespace Gnm { class RenderTarget; } }

// Type aliases from DWARF
using __int32_t = int;
using __uint32_t = unsigned int;
using int32_t = __int32_t;
using uint32_t = __uint32_t;

namespace sce {
    namespace Gnm {
        class RenderTarget
        {
        public:
            sce::Gnm::SizeAlign init(uint32_t, uint32_t, uint32_t, sce::Gnm::DataFormat, sce::Gnm::TileMode, sce::Gnm::NumSamples, sce::Gnm::NumFragments, sce::Gnm::SizeAlign*, sce::Gnm::SizeAlign*);
            sce::Gnm::SizeAlign init(uint32_t, uint32_t, uint32_t, uint32_t, sce::Gnm::DataFormat, sce::Gnm::TileMode, sce::Gnm::NumSamples, sce::Gnm::NumFragments, sce::Gnm::SizeAlign*, sce::Gnm::SizeAlign*);
            int32_t initFromTexture(const sce::Gnm::Texture*, uint32_t);
            void setBaseAddress256ByteBlocks(uint32_t baseAddr256);
            void setBaseAddress(void* baseAddr);
            void setArrayView(uint32_t, uint32_t);
            void setForceDestAlphaToOne(bool);
            void setFmaskCompressionEnable(bool);
            void setCmaskFastClearEnable(bool);
            void setCmaskAddress256ByteBlocks(uint32_t);
            void setCmaskAddress(void*);
            void setFmaskAddress256ByteBlocks(uint32_t);
            void setFmaskAddress(void*);
            void disableFmaskCompressionForMrtWithCmask();
            uint32_t getPitchDiv8Minus1() const;
            uint32_t getSliceSizeDiv64Minus1() const;
            uint32_t getBaseArraySliceIndex() const;
            uint32_t getLastArraySliceIndex() const;
            sce::Gnm::DataFormat getDataFormat() const;
            void setDenormSupportEnable(bool);
            bool getDenormSupportEnable() const;
            sce::Gnm::TileMode getTileMode() const;
            sce::Gnm::TileMode getFmaskTileMode() const;
            bool getLinearCmask() const;
            bool getForceDestAlphaToOne() const;
            bool getFmaskCompressionEnable() const;
            bool getCmaskFastClearEnable() const;
            sce::Gnm::NumSamples getNumSamples() const;
            sce::Gnm::NumFragments getNumFragments() const;
            uint32_t getWidth() const;
            uint32_t getHeight() const;
            uint32_t getBaseAddress256ByteBlocks() const;
            void* getBaseAddress() const;
            uint32_t getCmaskAddress256ByteBlocks() const;
            void* getCmaskAddress() const;
            uint32_t getFmaskAddress256ByteBlocks() const;
            void* getFmaskAddress() const;
            uint32_t getCmaskSliceNumBlocksMinus1() const;
            uint32_t getFmaskSliceNumTilesMinus1() const;
            uint32_t getPitchInBytes() const;
            uint32_t getPitch() const;
            uint32_t getAlignedHeight() const;
            uint32_t getCmaskSliceSizeInBytes() const;
            uint32_t getSliceSizeInBytes() const;
            void setAddresses(void*, void*, void*);
            void setWidth(uint32_t);
            void setHeight(uint32_t);
            void setPitchDiv8Minus1(uint32_t);
            void setFmaskPitchDiv8Minus1(uint32_t);
            void setSliceSizeDiv64Minus1(uint32_t);
            void setTileMode(sce::Gnm::TileMode);
            void setFmaskTileMode(sce::Gnm::TileMode);
            void setLinearCmask(bool);
            void setNumSamples(sce::Gnm::NumSamples);
            void setNumFragments(sce::Gnm::NumFragments);
            void setCmaskSliceNumBlocksMinus1(uint32_t);
            void setFmaskSliceNumTilesMinus1(uint32_t);
        public:
            uint32_t m_regs[11];  // offset: 0x0
        };
    }  // namespace Gnm
}  // namespace sce
