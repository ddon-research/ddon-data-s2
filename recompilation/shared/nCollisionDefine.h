#pragma once

#include <cstdint>
#include <cstddef>

namespace nCollision {
    enum COLLISION_TYPE
    {
        COLLISION_TYPE_INTERSECT = 0,
        COLLISION_TYPE_CLOSEST = 1,
        COLLISION_TYPE_CLOSEST_XZ = 2,
        COLLISION_TYPE_FIND = 3,
        COLLISION_TYPE_CONTACT = 4,
        COLLISION_TYPE_MAX = 5,
    };
}  // namespace nCollision
