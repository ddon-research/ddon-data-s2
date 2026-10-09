#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "constants.h"

// Declarations
namespace sce { namespace Gnm { class CommandBuffer; } }
namespace sce { namespace Gnm { class CommandBufferFlags; } }
namespace sce { namespace Gnm { class CommandCallback; } }

// Type aliases from DWARF
using __uint32_t = unsigned int;
using __uint64_t = long unsigned int;
using uint32_t = __uint32_t;
namespace sce { namespace Gnm { using CommandCallbackFunc = bool(*)(sce::Gnm::CommandBuffer*, uint32_t, void*); } }
using uint64_t = __uint64_t;

namespace sce {
    namespace Gnm {
        class CommandBufferFlags
        {
        public:
            uint64_t m_predicationEnabled : 1;  // offset: 0x0
            uint64_t m_shaderType : 1;  // offset: 0x0
            uint64_t m_reserved : 62;  // offset: 0x0
        };
    }  // namespace Gnm
}  // namespace sce

namespace sce {
    namespace Gnm {
        class CommandCallback
        {
        public:
            sce::Gnm::CommandCallbackFunc m_func;  // offset: 0x0
            void* m_userData;  // offset: 0x8
        };
    }  // namespace Gnm
}  // namespace sce

namespace sce {
    namespace Gnm {
        class CommandBuffer
        {
        public:
            uint32_t getSizeInBytes() const;
            uint32_t getRemainingBufferSpaceInDwords();
            bool reserveSpaceInDwords(uint32_t);
            void* allocateFromTheEndOfTheBuffer(uint32_t, sce::Gnm::EmbeddedDataAlignment);
            uint32_t sizeOfEndBufferAllocationInDword() const;
            void resetBuffer();
        public:
            uint32_t* m_beginptr;  // offset: 0x0
            uint32_t* m_endptr;  // offset: 0x8
            uint32_t* m_cmdptr;  // offset: 0x10
            sce::Gnm::CommandCallback m_callback;  // offset: 0x18
            sce::Gnm::CommandBufferFlags m_flags;  // offset: 0x28
            uint64_t m_reserved;  // offset: 0x30
            uint32_t m_bufferSizeInDwords;  // offset: 0x38
            uint32_t m_reserved2;  // offset: 0x3c
        };
    }  // namespace Gnm
}  // namespace sce
