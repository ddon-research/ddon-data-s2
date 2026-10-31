#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
namespace nActionManager { struct stActExParam; }

// Type aliases from DWARF
using f32 = float;
using u32 = unsigned int;

namespace nActionManager {
    struct stActExParam
    {
    public:
        bool mReplaceActParam;  // offset: 0x0
        u32 mUParam[4];  // offset: 0x4
        f32 mFParam[4];  // offset: 0x14
    };
}  // namespace nActionManager
