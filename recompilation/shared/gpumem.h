#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
namespace sce { namespace Gnm { class SizeAlign; } }

// Type aliases from DWARF
using __uint32_t = unsigned int;
using uint32_t = __uint32_t;
namespace sce { namespace Gnm { using AlignmentType = uint32_t; } }

namespace sce {
    namespace Gnm {
        class SizeAlign
        {
        public:
            SizeAlign();
            SizeAlign(uint32_t size, sce::Gnm::AlignmentType align);
        public:
            uint32_t m_size;  // offset: 0x0
            sce::Gnm::AlignmentType m_align;  // offset: 0x4
        };
    }  // namespace Gnm
}  // namespace sce
