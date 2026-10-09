#pragma once

#include <cstdint>
#include <cstddef>

namespace nAction {
    enum ACT_PRIO
    {
        PRIO_LOWEST = 1,
        PRIO_NML_LOWEST = 2,
        PRIO_NML_HIGHEST = 3,
        PRIO_DMG_LOWEST = 4,
        PRIO_DMG_GUARD_BREAK = 5,
        PRIO_DMG_QUAKE = 6,
        PRIO_DMG_STORM = 7,
        PRIO_DMG_SHRINK = 8,
        PRIO_REACTION = 9,
        PRIO_REGION_BREAK = 10,
        PRIO_DMG_BAD_STATE = 11,
        PRIO_ALTITUDE_FALL = 12,
        PRIO_DMG_BLOW = 13,
        PRIO_DMG_CONST = 14,
        PRIO_DMG_FREEZE = 15,
        PRIO_DMG_YOROYORO = 16,
        PRIO_DMG_SHAKE = 17,
        PRIO_DMG_DOWN = 18,
        PRIO_DMG_FREEZE_PL = 19,
        PRIO_DMG_STONE_PL = 20,
        PRIO_DMG_HUGEBLE = 21,
        PRIO_DMG_ABYSS = 22,
        PRIO_DMG_HIGHEST = 23,
        PRIO_DIE_LOWEST = 24,
        PRIO_DIE_NORMAL = 25,
        PRIO_DIE_STONE = 26,
        PRIO_DIE_MYSELF = 27,
        PRIO_DIE_HIGHEST = 28,
        PRIO_HIGHEST = 255,
    };
}  // namespace nAction

namespace nAction {
    enum REACT_TRG
    {
        REACT_TRG_NOTHING = 0,
        REACT_TRG_SHRINK = 1,
        REACT_TRG_BLOW = 2,
        REACT_TRG_DOWN = 3,
        REACT_TRG_TIRED = 4,
        REACT_TRG_REGION_BREAK = 8,
        REACT_TRG_ALL_REGION_BREAK = 9,
        REACT_TRG_REGION_HIT = 10,
        REACT_TRG_EROSION_BREAK = 16,
        REACT_TRG_ALL_EROSION_BREAK = 17,
        REACT_TRG_BIT_TABLE = 32,
        REACT_TRG_YOROYORO = 33,
        REACT_TRG_CONTINUE_DAMAGE = 34,
        REACT_TRG_GUARD = 35,
        REACT_TRG_NUM = 64,
    };
}  // namespace nAction
