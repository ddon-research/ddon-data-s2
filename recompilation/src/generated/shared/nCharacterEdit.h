#pragma once

#include <cstdint>
#include <cstddef>

namespace nCharacterEdit {
    enum EDIT_NAME_CHECK
    {
        NAME_CHECK_INIT = 0,
        NAME_CHECK_OK = 1,
        NAME_CHECK_NONE_BOTH = 2,
        NAME_CHECK_NONE_EACH = 3,
        NAME_CHECK_FORBIT_LENGTH = 4,
        NAME_CHECK_FORBIT_NAME_FORBIT_CHAR = 5,
        NAME_CHECK_OTHER = 6,
    };
}  // namespace nCharacterEdit

namespace nCharacterEdit {
    enum EDIT_NAME_TYPE
    {
        EDIT_NAME_FIRST = 0,
        EDIT_NAME_LAST = 1,
        EDIT_NAME_TYPE_NUM = 2,
    };
}  // namespace nCharacterEdit

namespace nCharacterEdit {
    enum EQUIP_PRESET_OPOTION
    {
        PRESET_OPTION_NOHEAD = 1,
        PRESET_OPTION_MINE = 2,
    };
}  // namespace nCharacterEdit
