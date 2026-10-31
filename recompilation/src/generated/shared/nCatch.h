#pragma once

#include <cstdint>
#include <cstddef>

namespace nCatch {
    enum BEARDOWN_EFFECTIVE
    {
        BEARDOWN_EFFECTIVE_NORMAL = 0,
        BEARDOWN_EFFECTIVE_GOOD = 1,
        BEARDOWN_EFFECTIVE_BAD = 2,
        BEARDOWN_EFFECTIVE_NOTHING = 3,
        BEARDOWN_EFFECTIVE_MAX = 3,
    };
}  // namespace nCatch

namespace nCatch {
    enum CATCH_TYPE
    {
        CATCH_TYPE_NOTHING = 0,
        CATCH_TYPE_HUMAN_BEARDOWN = 1,
        CATCH_TYPE_CYCLOPS = 2,
        CATCH_TYPE_OGRE = 3,
        CATCH_TYPE_BRING_OM = 4,
        CATCH_TYPE_GOLEM = 5,
        CATCH_TYPE_UNDEAD = 6,
        CATCH_TYPE_HARPY = 7,
        CATCH_TYPE_ORC = 8,
        CATCH_TYPE_SKELTON = 9,
        CATCH_TYPE_BIND_ANCHOR = 10,
        CATCH_TYPE_SYMBOL_DRAGON = 11,
        CATCH_TYPE_GOLD_DRAGON = 12,
        CATCH_TYPE_CHIMERA = 13,
        CATCH_TYPE_CLIMB_ENEMY = 14,
        CATCH_TYPE_GARGOYLE = 15,
        CATCH_TYPE_ELIMINATOR = 16,
        CATCH_TYPE_JOB03_CS14 = 17,
        CATCH_TYPE_02_00_BOSS = 18,
        CATCH_TYPE_MEDUSA = 19,
        CATCH_TYPE_ALLIGATOR_SAURIAN = 20,
        CATCH_TYPE_BLACK_KNIGHT = 21,
        CATCH_TYPE_NUM = 22,
    };
}  // namespace nCatch

namespace nCatch {
    enum ESCAPE_TYPE
    {
        ESCAPE_TYPE_NOTHING = 0,
        ESCAPE_TYPE_ESCAPE = 1,
        ESCAPE_TYPE_CANCEL = 2,
        ESCAPE_TYPE_ERASE = 3,
    };
}  // namespace nCatch

namespace nCatch {
    enum RELEASE_TYPE
    {
        RELEASE_TYPE_NOTHING = 0,
        RELEASE_TYPE_CANCEL = 1,
        RELEASE_TYPE_TGT_DEAD = 2,
    };
}  // namespace nCatch
