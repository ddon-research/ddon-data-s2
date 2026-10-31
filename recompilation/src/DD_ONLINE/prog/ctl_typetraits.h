#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
namespace ctl { namespace traits { template <typename T> struct add_pointer; } }

namespace ctl {
    namespace traits {
        template <typename T>
        struct add_pointer
        {
        public:
            using type = T*;
        };
    }  // namespace traits
}  // namespace ctl
