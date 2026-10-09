#pragma once

#include <cstdint>
#include <cstddef>

namespace nStatusEnemy {
    enum CHECK_STATUS_TYPE
    {
        TYPE_NOT = 1,
        TYPE_MENTAL_NORMAL = 2,
        TYPE_MENTAL_ANGER = 3,
        TYPE_REGION_STATUS_HP_ZERO = 4,
        TYPE_REGION_STATUS_BEND = 5,
        TYPE_REGION_STATUS_BLOW = 6,
        TYPE_ACTION = 7,
        TYPE_OST = 8,
        TYPE_STATE = 9,
        TYPE_SEQUENCE = 10,
        TYPE_FRAME = 11,
        TYPE_NOT_SELECT = 12,
        TYPE_SETUP = 13,
        TYPE_NOT_ACTION = 14,
        TYPE_REGION_STATUS_HP_RANGE = 15,
        TYPE_THINKMGR_BIT = 16,
        TYPE_RETURN_TERRITORY = 17,
        TYPE_REGION_STATUS_HP_WIDE_PER = 18,
        TYPE_REGION_STATUS_HP_SMALL_CHECK = 19,
        TYPE_FRAME_HI_PRIORITY = 20,
        TYPE_EROSION_REAL_LEVEL = 21,
        TYPE_EROSION_LINPUN_LEVEL = 22,
        TYPE_NUM_END = 23,
    };
}  // namespace nStatusEnemy

namespace nStatusEnemy {
    enum CHECK_STATUS_TYPE_EX
    {
        TYPE_EX_NOT = 1,
        TYPE_EX_SETUP = 2,
        TYPE_EX_REGION_BREAK = 3,
        TYPE_EX_REGION_REGENERATE = 4,
        TYPE_EX_DEAD = 5,
        TYPE_EX_MOVE_FREEZE_ON = 6,
        TYPE_EX_MOVE_FREEZE_OFF = 7,
        TYPE_EX_UNIT_KILL = 8,
        TYPE_EX_NUM_END = 9,
    };
}  // namespace nStatusEnemy

namespace nStatusEnemy {
    enum STATUS_CHANGE_REASON
    {
        STATUS_CHANGE_REASON_SETUP = 0,
        STATUS_CHANGE_REASON_MOVE = 1,
    };
}  // namespace nStatusEnemy

namespace nStatusEnemy {
    enum WORKRATE_CHANGE_TYPE
    {
        WORKRATE_CHANGE_TYPE_SETUP = 0,
        WORKRATE_CHANGE_TYPE_SCRIPT = 1,
        WORKRATE_CHANGE_TYPE_PROG = 2,
        WORKRATE_CHANGE_TYPE_RECEIVE = 3,
    };
}  // namespace nStatusEnemy

namespace nStatusEnemy {
    enum WORKRATE_STATUS_TYPE
    {
        WORKRATE_STATUS_NONE = 0,
        WORKRATE_STATUS_SETUP = 1,
        WORKRATE_STATUS_SCRIPT = 2,
        WORKRATE_STATUS_PROG_INIT = 3,
        WORKRATE_STATUS_NORMAL = 3,
        WORKRATE_STATUS_RAGE = 4,
        WORKRATE_STATUS_END = 5,
        WORKRATE_STATUS_TYPE_NUM = 5,
        WORKRATE_STATUS_INVALID = 6,
    };
}  // namespace nStatusEnemy
