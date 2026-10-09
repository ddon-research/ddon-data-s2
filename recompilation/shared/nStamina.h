#pragma once

#include <cstdint>
#include <cstddef>

namespace nStamina {
    enum CONTINUATION_TYPE
    {
        TYPE_ALWAYS = 0,
        TYPE_ONE_TIME = 1,
    };
}  // namespace nStamina

namespace nStamina {
    enum UPDATE_TYPE
    {
        TYPE_DECREASE = 0,
        TYPE_RECOVERY = 1,
    };
}  // namespace nStamina

namespace nStamina {
    enum VALUE_TYPE
    {
        TYPE_REAL = 0,
        TYPE_RATE = 1,
    };
}  // namespace nStamina
