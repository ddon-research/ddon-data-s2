#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "constants.h"

// Forward declarations
namespace sce { namespace Gnm { class DataFormat; } }

// Declarations
namespace sce { namespace Gnm { class Buffer; } }

// Type aliases from DWARF
using __uint32_t = unsigned int;
using uint32_t = __uint32_t;

namespace sce {
    namespace Gnm {
        class Buffer
        {
        public:
            void initAsVertexBuffer(void*, sce::Gnm::DataFormat, uint32_t, uint32_t);
            void initAsConstantBuffer(void*, uint32_t);
            void initAsTessellationFactorBuffer(void*, uint32_t);
            void setBaseAddress(void*);
            void setStride(uint32_t);
            void setNumElements(uint32_t);
            void setChannelOrder(sce::Gnm::BufferChannel, sce::Gnm::BufferChannel, sce::Gnm::BufferChannel, sce::Gnm::BufferChannel);
            void setSwizzle(sce::Gnm::BufferSwizzleElementSize, sce::Gnm::BufferSwizzleStride);
            void disableSwizzle();
            void* getBaseAddress() const;
            uint32_t getStride() const;
            uint32_t getSize() const;
            uint32_t getNumElements() const;
            bool isBuffer() const;
            bool isSwizzled() const;
            sce::Gnm::BufferSwizzleElementSize getSwizzleElementSize() const;
            sce::Gnm::BufferSwizzleStride getSwizzleStride() const;
        public:
            uint32_t m_regs[4];  // offset: 0x0
        };
    }  // namespace Gnm
}  // namespace sce
