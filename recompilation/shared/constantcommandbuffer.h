#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "commandbuffer.h"

// Declarations
namespace sce { namespace Gnm { class ConstantCommandBuffer; } }

namespace sce {
    namespace Gnm {
        class ConstantCommandBuffer : public sce::Gnm::CommandBuffer
        {
        };
    }  // namespace Gnm
}  // namespace sce
