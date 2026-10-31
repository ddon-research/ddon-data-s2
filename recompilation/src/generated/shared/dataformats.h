#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "constants.h"

// Declarations
namespace sce { namespace Gnm { class DataFormat; } }

// Type aliases from DWARF
using __uint32_t = unsigned int;
using uint32_t = __uint32_t;

namespace sce {
    namespace Gnm {
        class DataFormat
        {
        public:
            static sce::Gnm::DataFormat build(sce::Gnm::ZFormat);
            void init(sce::Gnm::SurfaceFormat, sce::Gnm::TextureChannelType, sce::Gnm::TextureChannel, sce::Gnm::TextureChannel, sce::Gnm::TextureChannel, sce::Gnm::TextureChannel);
            sce::Gnm::SurfaceFormat getSurfaceFormat() const;
            sce::Gnm::RenderTargetFormat getRenderTargetFormat() const;
            sce::Gnm::BufferFormat getBufferFormat() const;
            sce::Gnm::ZFormat getZFormat() const;
            sce::Gnm::TextureChannelType getTextureChannelType() const;
            sce::Gnm::BufferChannelType getBufferChannelType() const;
            sce::Gnm::TextureChannel getChannel(uint32_t) const;
            bool supportsRenderTarget() const;
            bool supportsBuffer() const;
            bool supportsTexture() const;
            bool supportsDepthRenderTarget() const;
            bool getRenderTargetChannelOrder(sce::Gnm::RenderTargetChannelOrder*) const;
            bool getRenderTargetChannelType(sce::Gnm::RenderTargetChannelType*) const;
            uint32_t getBytesPerElement() const;
        public:
            union
            {
            public:
                class
                {
                public:
                    uint32_t m_surfaceFormat : 8;  // offset: 0x0
                    uint32_t m_channelType : 4;  // offset: 0x0
                    uint32_t m_channelX : 3;  // offset: 0x0
                    uint32_t m_channelY : 3;  // offset: 0x0
                    uint32_t m_channelZ : 3;  // offset: 0x0
                    uint32_t m_channelW : 3;  // offset: 0x0
                    uint32_t m_unused : 8;  // offset: 0x0
                } m_bits;  // offset: 0x0
                uint32_t m_asInt;  // offset: 0x0
            };  // offset: 0x0
        };
    }  // namespace Gnm
}  // namespace sce
