#pragma once

#include <cstdint>
#include <cstddef>

namespace nDDOGame {
    enum ELEMENT_TYPE
    {
        ELEMENT_TYPE_INVALID = 0,
        ELEMENT_TYPE_INIT = 1,
        ELEMENT_TYPE_START_ELEMENT = 2,
        ELEMENT_TYPE_NONE = 1,
        ELEMENT_TYPE_FIRE = 2,
        ELEMENT_TYPE_ICE = 3,
        ELEMENT_TYPE_THUNDER = 4,
        ELEMENT_TYPE_HOLY = 5,
        ELEMENT_TYPE_DARK = 6,
        ELEMENT_TYPE_NUM = 7,
        ELEMENT_TYPE_ELEMENT_NUM = 5,
    };
}  // namespace nDDOGame
