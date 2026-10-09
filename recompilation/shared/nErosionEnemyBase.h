#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class uDDOModel;

namespace nErosionEnemyBase {
    enum EROSION_LEVEL
    {
        EROSION_LEVEL_NONE = 0,
        EROSION_LEVEL_1 = 1,
        EROSION_LEVEL_2 = 2,
        EROSION_LEVEL_3 = 3,
        EROSION_LEVEL_4 = 4,
        EROSION_LEVEL_MAX = 4,
        EROSION_LEVEL_SMALL_MAX = 1,
        EROSION_LEVEL_NUM = 5,
        EROSION_LEVEL_SMALL_NUM = 2,
    };
}  // namespace nErosionEnemyBase

namespace nErosionEnemyBase {
    enum EROSION_STATUS
    {
        EROSION_STATUS_NORMAL = 0,
        EROSION_STATUS_CANCEL = 1,
    };
}  // namespace nErosionEnemyBase

// Type aliases from DWARF
using u32 = unsigned int;

namespace nErosionEnemyBase {

    u32 getErosionColBank(uDDOModel* pOwner);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nErosionEnemyBase.cpp:33

}  // namespace nErosionEnemyBase
