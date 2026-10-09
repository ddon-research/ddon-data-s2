#pragma once

#include <cstdint>
#include <cstddef>

namespace nSequence {
    enum SEQ_CALLBACK_NO
    {
        SEQ_CALLBACK_COL_TRG = 0,
        SEQ_CALLBACK_COL_REL = 1,
        SEQ_CALLBACK_EFF_MOT_BASE_TRG = 2,
        SEQ_CALLBACK_EFF_MOT_BASE_REL = 3,
        SEQ_CALLBACK_EFF_MOT_BLEND_1_TRG = 4,
        SEQ_CALLBACK_EFF_MOT_BLEND_1_REL = 5,
        SEQ_CALLBACK_NO_MAX = 10,
    };
}  // namespace nSequence
