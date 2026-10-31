#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
namespace nMenu { struct MENU_PARTS; }

namespace nMenu {
    enum MENU_RET
    {
        MENU_RET_FAILED = -1,
        MENU_RET_CONTINUE = 0,
        MENU_RET_SUCCESS = 1,
        MENU_RET_CANCEL = 2,
        MENU_RET_EXIT = 3,
        MENU_RET_BUSY = 4,
    };
}  // namespace nMenu

// Type aliases from DWARF
using u32 = unsigned int;

namespace nMenu {
    struct MENU_PARTS
    {
    public:
        u32 attr;  // offset: 0x0
        u32 param;  // offset: 0x4
    };
}  // namespace nMenu
