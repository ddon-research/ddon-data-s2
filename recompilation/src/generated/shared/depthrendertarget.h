#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "constants.h"

// Forward declarations
namespace sce { namespace Gnm { class SizeAlign; } }

// Declarations
namespace sce { namespace Gnm { class DepthRenderTarget; } }

// Type aliases from DWARF
using __uint32_t = unsigned int;
using uint32_t = __uint32_t;

namespace sce {
    namespace Gnm {
        class DepthRenderTarget
        {
        public:
            sce::Gnm::SizeAlign init(uint32_t width, uint32_t height, sce::Gnm::ZFormat zFormat, sce::Gnm::StencilFormat stencilFormat, sce::Gnm::TileMode depthTileModeHint, sce::Gnm::NumFragments numFragments, sce::Gnm::SizeAlign* stencilSizeAlign, sce::Gnm::SizeAlign* htileSizeAlign);
            sce::Gnm::SizeAlign init(uint32_t, uint32_t, uint32_t, sce::Gnm::ZFormat, sce::Gnm::StencilFormat, sce::Gnm::TileMode, sce::Gnm::NumFragments, sce::Gnm::SizeAlign*, sce::Gnm::SizeAlign*);
            sce::Gnm::SizeAlign init(uint32_t, uint32_t, uint32_t, uint32_t, sce::Gnm::ZFormat, sce::Gnm::StencilFormat, sce::Gnm::TileMode, sce::Gnm::NumFragments, sce::Gnm::SizeAlign*, sce::Gnm::SizeAlign*);
            void setHtileAccelerationEnable(bool);
            void setExpClearDepthAccelerationEnable(bool);
            void setExpClearStencilAccelerationEnable(bool);
            void setHtileStencilDisable(bool);
            void setZCompareBase(sce::Gnm::ZCompareBase);
            void setZReadAddress256ByteBlocks(uint32_t zReadAddr256);
            void setZReadAddress(void* zReadAddr);
            void setZWriteAddress256ByteBlocks(uint32_t zWriteAddr256);
            void setZWriteAddress(void* zWriteAddr);
            void setStencilReadAddress256ByteBlocks(uint32_t stencilReadAddr256);
            void setStencilReadAddress(void* stencilReadAddr);
            void setStencilWriteAddress256ByteBlocks(uint32_t stencilWriteAddr256);
            void setStencilWriteAddress(void* stencilWriteAddr);
            void setArrayView(uint32_t, uint32_t);
            void setHtileAddress256ByteBlocks(uint32_t);
            void setHtileAddress(void*);
            sce::Gnm::ZFormat getZFormat() const;
            sce::Gnm::TileMode getZTileMode() const;
            sce::Gnm::TileMode getStencilTileMode() const;
            sce::Gnm::NumFragments getNumFragments() const;
            bool getHtileAccelerationEnable() const;
            bool getExpClearDepthAccelerationEnable() const;
            bool getExpClearStencilAccelerationEnable() const;
            sce::Gnm::ZCompareBase getZCompareBase() const;
            bool getHtileStencilDisable() const;
            sce::Gnm::StencilFormat getStencilFormat() const;
            uint32_t getZReadAddress256ByteBlocks() const;
            void* getZReadAddress() const;
            uint32_t getZWriteAddress256ByteBlocks() const;
            void* getZWriteAddress() const;
            uint32_t getStencilReadAddress256ByteBlocks() const;
            void* getStencilReadAddress() const;
            uint32_t getStencilWriteAddress256ByteBlocks() const;
            void* getStencilWriteAddress() const;
            uint32_t getHtileAddress256ByteBlocks() const;
            void* getHtileAddress() const;
            uint32_t getPitchDiv8Minus1() const;
            uint32_t getHeightDiv8Minus1() const;
            uint32_t getSliceSizeDiv64Minus1() const;
            bool getLinearHtile() const;
            uint32_t getZSliceSizeInBytes() const;
            uint32_t getBaseArraySliceIndex() const;
            uint32_t getLastArraySliceIndex() const;
            uint32_t getPitch() const;
            uint32_t getWidth() const;
            uint32_t getHeight() const;
            uint32_t getPaddedHeight() const;
            void setAddresses(void* zAddress, void* stencilAddress);
            void setZFormat(sce::Gnm::ZFormat);
            void setNumFragments(sce::Gnm::NumFragments);
            void setStencilFormat(sce::Gnm::StencilFormat);
            void setPitchDiv8Minus1(uint32_t);
            void setHeightDiv8Minus1(uint32_t);
            void setSliceSizeDiv64Minus1(uint32_t);
            void setLinearHtile(bool);
        public:
            uint32_t m_regs[12];  // offset: 0x0
            uint32_t m_widthHeight;  // offset: 0x30
        };
    }  // namespace Gnm
}  // namespace sce
