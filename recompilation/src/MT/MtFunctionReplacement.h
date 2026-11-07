#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
namespace MtReplaceFunc { namespace detail { struct lookup_table; } }

// Type aliases from DWARF
using s32 = int;

namespace MtReplaceFunc {
    namespace detail {

        // Forward declarations
        struct lookup_table;

        struct lookup_table
        {
        public:
            static const s32 tolower_table[];
            static const s32 toupper_table[];
        };

        char* _strupr(char* string);
        char* _strlwr(char* string);

    }  // namespace detail
}  // namespace MtReplaceFunc
