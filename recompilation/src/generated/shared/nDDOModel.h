#pragma once

#include <cstdint>
#include <cstddef>

namespace nDDOModel {
    enum AWAKENING_BRACELET_TYPE
    {
        AWAKE_TYPE_NONE = 0,
        AWAKE_TYPE_RUN = 1,
        AWAKE_TYPE_JUMP = 2,
        AWAKE_TYPE_CLIMB_EM = 4,
        AWAKE_TYPE_WEIGHT = 8,
        AWAKE_TYPE_NUM = 4,
    };
}  // namespace nDDOModel

namespace nDDOModel {
    enum LOCKON_TARGET_TYPE
    {
        TYPE_COMMON = 0,
        TYPE_ATTACK = 1,
        TYPE_SUPPORT = 2,
        TYPE_NO_EFF = 3,
    };
}  // namespace nDDOModel

namespace nDDOModel {
    enum SEQ_OST_BIT
    {
        SEQ_OST_FREE00 = 16777216,
        SEQ_OST_FREE01 = 33554432,
        SEQ_OST_FREE02 = 67108864,
        SEQ_OST_FREE03 = 134217728,
        SEQ_OST_FREE04 = 268435456,
        SEQ_OST_AIR = 536870912,
        SEQ_OST_LAND = 1073741824,
    };
}  // namespace nDDOModel

namespace nDDOModel {
    enum SEQ_OST_NO
    {
        SEQ_OST_NO_FREE00 = 24,
        SEQ_OST_NO_FREE01 = 25,
        SEQ_OST_NO_FREE02 = 26,
        SEQ_OST_NO_FREE03 = 27,
        SEQ_OST_NO_FREE04 = 28,
        SEQ_OST_NO_AIR = 29,
        SEQ_OST_NO_LAND = 30,
    };
}  // namespace nDDOModel

namespace nDDOModel {
    enum TOUCH_RELEASE_TYPE
    {
        TOUCH_RELEASE_NONE = 0,
        TOUCH_RELEASE_FINISH = 1,
        TOUCH_RELEASE_NOT_FOUND = 2,
        TOUCH_RELEASE_DAMAGE = 3,
        TOUCH_RELEASE_DEAD = 4,
        TOUCH_RELEASE_EVENT_END = 5,
    };
}  // namespace nDDOModel

namespace nDDOModel {
    enum TOUCH_TYPE
    {
        TOUCH_NONE = -1,
        TOUCH_OM_PL_STOP = 0,
        TOUCH_OM_PL_MOVE = 1,
        TOUCH_RESCUE = 2,
        TOUCH_RESCUE_ADD = 3,
        TOUCH_REVIVE = 4,
        TOUCH_NPC = 5,
        TOUCH_CATAPULT = 6,
        TOUCH_STAMINA_RESCUE = 7,
        TOUCH_OCD_RESCUE_STUN = 8,
        TOUCH_OCD_RESCUE_SLEEP = 9,
        TOUCH_OCD_RESCUE_SPREAD = 10,
        TOUCH_OCD_RESCUE_FREEZE = 11,
        TOUCH_PLAYER_DEFAULT = 12,
        TOUCH_OCD_RESCUE_EROSION = 13,
        TOUCH_TYPE_NUM = 14,
    };
}  // namespace nDDOModel
