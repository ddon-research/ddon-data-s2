#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "buffer.h"

// Forward declarations
namespace sce { namespace Gnm { class Buffer; } }

// Declarations
namespace sce { namespace Gnmx { class DispatchDrawTriangleCullV1SharedData; } }

// Type aliases from DWARF
using __uint16_t = unsigned short;
using uint16_t = __uint16_t;

namespace sce {
    namespace Gnmx {
        class DispatchDrawTriangleCullV1SharedData
        {
        public:
            sce::Gnm::Buffer m_bufferIrb;  // offset: 0x0
            uint16_t m_gdsOffsetOfIrbWptr;  // offset: 0x10
            uint16_t m_cullSettings;  // offset: 0x12
            float m_quantErrorScreenX;  // offset: 0x14
            float m_quantErrorScreenY;  // offset: 0x18
            float m_gbHorizClipAdjust;  // offset: 0x1c
            float m_gbVertClipAdjust;  // offset: 0x20
        };
    }  // namespace Gnmx
}  // namespace sce
