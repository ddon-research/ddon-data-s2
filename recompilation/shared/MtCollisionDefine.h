#pragma once

#include <cstdint>
#include <cstddef>

namespace MtCollisionUtil {
    enum AABB_VORONOI_ID
    {
        AABB_X_MIN_BIT = 1,
        AABB_X_MAX_BIT = 2,
        AABB_Y_MIN_BIT = 4,
        AABB_Y_MAX_BIT = 8,
        AABB_Z_MIN_BIT = 16,
        AABB_Z_MAX_BIT = 32,
        AABB_VORONOI_INTERNAL = 0,
        AABB_VORONOI_P_YZX0 = 1,
        AABB_VORONOI_P_YZX1 = 2,
        AABB_VORONOI_P_ZXY0 = 4,
        AABB_VORONOI_P_ZXY1 = 8,
        AABB_VORONOI_P_XYZ0 = 16,
        AABB_VORONOI_P_XYZ1 = 32,
        AABB_VORONOI_E_XY0Z0 = 20,
        AABB_VORONOI_E_XY1Z0 = 24,
        AABB_VORONOI_E_XY0Z1 = 36,
        AABB_VORONOI_E_XY1Z1 = 40,
        AABB_VORONOI_E_YZ0X0 = 17,
        AABB_VORONOI_E_YZ1X0 = 33,
        AABB_VORONOI_E_YZ0X1 = 18,
        AABB_VORONOI_E_YZ1X1 = 34,
        AABB_VORONOI_E_ZX0Y0 = 5,
        AABB_VORONOI_E_ZX1Y0 = 6,
        AABB_VORONOI_E_ZX0Y1 = 9,
        AABB_VORONOI_E_ZX1Y1 = 10,
        AABB_VORONOI_V_X0Y0Z0 = 21,
        AABB_VORONOI_V_X1Y0Z0 = 22,
        AABB_VORONOI_V_X0Y1Z0 = 25,
        AABB_VORONOI_V_X1Y1Z0 = 26,
        AABB_VORONOI_V_X0Y0Z1 = 37,
        AABB_VORONOI_V_X1Y0Z1 = 38,
        AABB_VORONOI_V_X0Y1Z1 = 41,
        AABB_VORONOI_V_X1Y1Z1 = 42,
    };
}  // namespace MtCollisionUtil
