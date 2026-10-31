#pragma once

#include <cstdint>
#include <cstddef>

namespace nErosionEnemySmall {
    enum EROSION_SMALL_MODE
    {
        EROSION_SMALL_MODE_NORMAL = 0,
        EROSION_SMALL_MODE_SOURCE = 1,
        EROSION_SMALL_MODE_END = 1,
        EROSION_SMALL_MODE_NUM = 2,
    };
}  // namespace nErosionEnemySmall

namespace nErosionEnemySmall {
    enum EROSION_SMALL_STATUS
    {
        EROSION_SMALL_STATUS_NORMAL = 0,
        EROSION_SMALL_STATUS_CANCEL = 1,
        EROSION_SMALL_STATUS_CANCEL_WAIT = 2,
    };
}  // namespace nErosionEnemySmall

namespace nErosionEnemySmall {
    enum EROSION_TYPE_SMALL
    {
        EROSION_TYPE_SMALL_NORMAL = 0,
        EROSION_TYPE_SMALL_SUPER = 1,
    };
}  // namespace nErosionEnemySmall
