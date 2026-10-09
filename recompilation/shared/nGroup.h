#pragma once

#include <cstdint>
#include <cstddef>

namespace nGroup {
    enum ID_CONTEXT
    {
        ID_CONTEXT_CHARACTER = 0,
        ID_CONTEXT_WORLD = 1,
        ID_CONTEXT_HUMAN = 2,
        ID_CONTEXT_MONSTER = 3,
        ID_CONTEXT_PLAYER_IFNO = 4,
        ID_CONTEXT_INSTANCE = 5,
        ID_CONTEXT_INSTANCE_CHAR = 6,
        ID_CONTEXT_INSTANCE_HM = 7,
        ID_CONTEXT_INSTANCE_PL = 8,
        ID_CONTEXT_INSTANCE_EM = 9,
        ID_CONTEXT_INSTANCE_NPC = 10,
        ID_CONTEXT_INSTANCE_OM = 11,
        ID_CONTEXT_INSTANCE_HMEM = 12,
        ID_CONTEXT_MAX = 13,
    };
}  // namespace nGroup
