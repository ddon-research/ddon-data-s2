#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "nRegionStatus.h"

namespace nErosionEnemy {
    enum EROSION_BREAK_SHL_INDEX
    {
        EROSION_BREAK_SHL_INVALID = 0,
        EROSION_BREAK_SHL_INDEX_1 = 1,
        EROSION_BREAK_SHL_INDEX_2 = 2,
        EROSION_BREAK_SHL_INDEX_3 = 3,
        EROSION_BREAK_SHL_INDEX_4 = 4,
        EROSION_BREAK_SHL_INDEX_5 = 5,
        EROSION_BREAK_SHL_INDEX_6 = 6,
        EROSION_BREAK_SHL_INDEX_7 = 7,
        EROSION_BREAK_SHL_INDEX_8 = 8,
        EROSION_BREAK_SHL_INDEX_9 = 9,
        EROSION_BREAK_SHL_NUM = 10,
    };
}  // namespace nErosionEnemy

namespace nErosionEnemy {
    enum EROSION_COLLISION_INDEX
    {
        EROSION_COLNODE_INVALID = 0,
        EROSION_COLNODE_LIPUN_LV1 = 1,
        EROSION_COLNODE_LIPUN_LV2 = 2,
        EROSION_COLNODE_LIPUN_LV3 = 3,
        EROSION_COLNODE_LIPUN_LV4 = 4,
        EROSION_COLNODE_EMPTY_5 = 5,
        EROSION_COLNODE_BUF = 6,
        EROSION_COLNODE_EMPTY_7 = 7,
        EROSION_COLNODE_EMPTY_8 = 8,
        EROSION_COLNODE_LIPUN_CHECK_LV1 = 9,
        EROSION_COLNODE_LIPUN_CHECK_LV2 = 10,
        EROSION_COLNODE_LIPUN_CHECK_LV3 = 11,
        EROSION_COLNODE_LIPUN_HIT_NOTICE_LV1 = 12,
        EROSION_COLNODE_LIPUN_HIT_NOTICE_LV2 = 13,
        EROSION_COLNODE_LIPUN_HIT_NOTICE_LV3 = 14,
        EROSION_COLNODE_LIPUN_CHECK_LV4 = 15,
        EROSION_COLNODE_LIPUN_HIT_NOTICE_LV4 = 16,
    };
}  // namespace nErosionEnemy

namespace nErosionEnemy {
    enum EROSION_GENERATE_SHL_INDEX
    {
        EROSION_GENERATE_SHL_INVALID = 0,
        EROSION_GENERATE_SHL_INDEX_1 = 11,
        EROSION_GENERATE_SHL_INDEX_2 = 12,
        EROSION_GENERATE_SHL_INDEX_3 = 13,
        EROSION_GENERATE_SHL_INDEX_4 = 14,
        EROSION_GENERATE_SHL_INDEX_5 = 15,
        EROSION_GENERATE_SHL_INDEX_6 = 16,
        EROSION_GENERATE_SHL_INDEX_7 = 17,
        EROSION_GENERATE_SHL_INDEX_8 = 18,
        EROSION_GENERATE_SHL_INDEX_9 = 19,
        EROSION_GENERATE_SHL_INDEX_10 = 20,
    };
}  // namespace nErosionEnemy

namespace nErosionEnemy {
    enum EROSION_INIT_TYPE
    {
        EROSION_INIT_FROM_STAGE = 0,
        EROSION_INIT_ZERO = 1,
    };
}  // namespace nErosionEnemy

namespace nErosionEnemy {
    enum EROSION_MODE
    {
        EROSION_MODE_NONE = 0,
        EROSION_MODE_WAIT = 1,
        EROSION_MODE_ACTIVE = 2,
    };
}  // namespace nErosionEnemy

namespace nErosionEnemy {
    enum EROSION_MONTAGE_NO
    {
        EROSION_MOTAGE_CATE1 = 40,
        EROSION_MOTAGE_CATE2 = 41,
        EROSION_MOTAGE_CATE3 = 42,
        EROSION_MOTAGE_CATE4 = 43,
    };
}  // namespace nErosionEnemy

namespace nErosionEnemy {
    enum EROSION_PROGRESSION
    {
        EROSION_PROGRESSION_NONE = 0,
        EROSION_PROGRESSION_1 = 1,
        EROSION_PROGRESSION_2 = 2,
        EROSION_PROGRESSION_3 = 3,
        EROSION_PROGRESSION_MAX = 3,
        EROSION_PROGRESSION_4 = 4,
        EROSION_SUPER_PROGRESSION_MAX = 4,
    };
}  // namespace nErosionEnemy

namespace nErosionEnemy {
    enum EROSION_REGION_INIT_STATE
    {
        EROSION_REGION_INIT_STATE_NONE = 0,
        EROSION_REGION_INIT_STATE_ACTIVE = 1,
        EROSION_REGION_INIT_STATE_INACTIVE = 2,
    };
}  // namespace nErosionEnemy

namespace nErosionEnemy {
    enum EROSION_SCALE_CHANGE_TYPE
    {
        SCALE_CHANGE_NONE = 0,
        SCALE_CHANGE_RADIAL = 1,
        SCALE_CHANGE_TUBE = 2,
        SCALE_CHANGE_TYPE_NUM = 3,
    };
}  // namespace nErosionEnemy

namespace nErosionEnemy {
    enum EROSION_TIMER_STATE
    {
        EROSION_TIMER_STATE_WAIT = 0,
        EROSION_TIMER_STATE_ACTIVE = 1,
        EROSION_TIMER_STATE_MAX = 2,
    };
}  // namespace nErosionEnemy

namespace nErosionEnemy {
    enum EROSION_TYPE
    {
        EROSION_TYPE_NORMAL = 0,
        EROSION_TYPE_SUPER = 1,
    };
}  // namespace nErosionEnemy

namespace nErosionEnemy {

    bool isErosionRegion(nRegionStatus::P_REGION_CATEGORY category);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nErosionEnemy.cpp:30

}  // namespace nErosionEnemy
