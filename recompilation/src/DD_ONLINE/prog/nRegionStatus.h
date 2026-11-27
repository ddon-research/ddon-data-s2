#pragma once

#include <cstdint>
#include <cstddef>

namespace nRegionStatus {
    enum CORE_POINT_TYPE
    {
        CORE_POINT_NONE = 0,
        CORE_POINT_TYPE_CORE_POINT = 1,
        CORE_POINT_TYPE_EROSION_MASK_INIT = 2,
        CORE_POINT_TYPE_EROSION_MASK_1 = 2,
        CORE_POINT_TYPE_EROSION_MASK_2 = 3,
        CORE_POINT_TYPE_EROSION_MASK_3 = 4,
        CORE_POINT_TYPE_EROSION_MASK_4 = 5,
        CORE_POINT_TYPE_EROSION_MASK_END = 5,
        CORE_POINT_TYPE_EROSION_TENTACLE_INIT = 6,
        CORE_POINT_TYPE_EROSION_TENTACLE_1 = 6,
        CORE_POINT_TYPE_EROSION_TENTACLE_2 = 7,
        CORE_POINT_TYPE_EROSION_TENTACLE_3 = 8,
        CORE_POINT_TYPE_EROSION_TENTACLE_4 = 9,
        CORE_POINT_TYPE_EROSION_TENTACLE_END = 9,
        CORE_POINT_TYPE_NUM = 10,
        CORE_POINT_TYPE_ALL = 11,
        CORE_POINT_TYPE_EROSION_ALL = 12,
        CORE_POINT_TYPE_EROSION_TENTACLE_ALL = 13,
    };
}  // namespace nRegionStatus

namespace nRegionStatus {
    enum ENDURANCE_CURE_RATE_TYPE
    {
        ENDURANCE_CURE_RATE_NONE = 0,
        ENDURANCE_CURE_RATE_RAGE = 1,
        ENDURANCE_CURE_RATE_ELECT = 2,
        ENDURANCE_CURE_RATE_TYPE_NUM = 3,
    };
}  // namespace nRegionStatus

namespace nRegionStatus {
    enum HIT_STOP_DEFFENCE_ATTR
    {
        HIT_STOP_DEFFECE_ATTR_NORMAL = 0,
        HIT_STOP_DEFFECE_ATTR_HIT_STOP_NONE = 1,
        HIT_STOP_DEFFECE_ATTR_HIT_SLOW_NONE = 2,
        HIT_STOP_DEFFECE_ATTR_HIT_STOP_SLOW_NONE = 3,
        HIT_STOP_DEFENCE_ATTR_NUM = 4,
    };
}  // namespace nRegionStatus

namespace nRegionStatus {
    enum PARENT_REGION_TYPE
    {
        PARENT_HP = 0,
        PARENT_SHRINK_BLOW = 1,
        PARENT_TYPE_NUM = 2,
    };
}  // namespace nRegionStatus

namespace nRegionStatus {
    enum P_REGION_CATEGORY
    {
        P_REGION_CATEGORY_NORMAL = 0,
        P_REGION_CATEGORY_EROSION_INIT = 1,
        P_REGION_CATEGORY_EROSION_1 = 1,
        P_REGION_CATEGORY_EROSION_2 = 2,
        P_REGION_CATEGORY_EROSION_3 = 3,
        P_REGION_CATEGORY_EROSION_4 = 4,
        P_REGION_CATEGORY_EROSION_END = 4,
        P_REGION_CATEGORY_NUM = 5,
        P_REGION_CATEGORY_EROSION_NUM = 4,
    };
}  // namespace nRegionStatus

namespace nRegionStatus {
    enum P_REGION_TYPE
    {
        P_REGION_MAIN = 0,
        P_REGION_INIT = 1,
        P_REGION_1 = 1,
        P_REGION_2 = 2,
        P_REGION_3 = 3,
        P_REGION_4 = 4,
        P_REGION_5 = 5,
        P_REGION_6 = 6,
        P_REGION_7 = 7,
        P_REGION_8 = 8,
        P_REGION_MAX = 9,
        P_REGION_NUM = 10,
        P_REGION_INVALID = 11,
    };
}  // namespace nRegionStatus

namespace nRegionStatus {
    enum REGION_C_CHANGE_TYPE
    {
        REGION_C_CHANGE_TYPE_SETUP = 0,
        REGION_C_CHANGE_TYPE_SCRIPT = 1,
        REGION_C_CHANGE_TYPE_PROG = 2,
        REGION_C_CHANGE_TYPE_RECEIVE = 3,
    };
}  // namespace nRegionStatus

namespace nRegionStatus {
    enum REGION_C_STATUS_PRIO
    {
        REGION_C_STATUS_PRIO_NONE = 1,
        REGION_C_STATUS_PRIO_SETUP = 1,
        REGION_C_STATUS_PRIO_SCRIPT = 1000,
        REGION_C_STATUS_PRIO_NORMAL = 500,
        REGION_C_STATUS_PRIO_RAGE = 800,
        REGION_C_STATUS_PRIO_SHAKED = 801,
        REGION_C_STATUS_PRIO_CHANCE_DOWN = 802,
        REGION_C_STATUS_PRIO_OCD = 600,
        REGION_C_STATUS_PRIO_ORIGINAL1 = 901,
        REGION_C_STATUS_PRIO_ORIGINAL2 = 900,
        REGION_C_STATUS_PRIO_INVALID = 0,
    };
}  // namespace nRegionStatus

namespace nRegionStatus {
    enum REGION_C_STATUS_TYPE
    {
        REGION_C_STATUS_NONE = 0,
        REGION_C_STATUS_SETUP = 1,
        REGION_C_STATUS_SCRIPT = 2,
        REGION_C_STATUS_PROG_INIT = 3,
        REGION_C_STATUS_NORMAL = 3,
        REGION_C_STATUS_RAGE = 4,
        REGION_C_STATUS_SHAKED = 5,
        REGION_C_STATUS_CHANCE_DOWN = 6,
        REGION_C_STATUS_EM_ORIGINAL_01 = 7,
        REGION_C_STATUS_EM_ORIGINAL_02 = 8,
        REGION_C_STATUS_END = 9,
        REGION_C_STATUS_TYPE_NUM = 9,
        REGION_C_STATUS_INVALID = 10,
    };
}  // namespace nRegionStatus

namespace nRegionStatus {
    enum REGION_REGENERATE_PRIORITY
    {
        REGION_REGENERATE_PRIORITY_HIGH_HIGH = 100,
        REGION_REGENERATE_PRIORITY_HIGH = 75,
        REGION_REGENERATE_PRIORITY_MIDLE = 50,
        REGION_REGENERATE_PRIORITY_LOW = 25,
        REGION_REGENERATE_PRIORITY_LOW_LOW = 10,
        REGION_REGENERATE_PRIORITY_MAX = 100,
        REGION_REGENERATE_PRIORITY_MIN = 10,
    };
}  // namespace nRegionStatus

namespace nRegionStatus {
    enum RESION_SURFACE_TYPE
    {
        SURFACE_INIT = 0,
        SURFACE_LIQUID = 0,
        SURFACE_MEAT = 1,
        SURFACE_BONE = 2,
        SURFACE_WOOD = 3,
        SURFACE_STONE = 4,
        SURFACE_IRON = 5,
        SURFACE_SMOKE = 6,
        SURFACE_GOLD = 7,
        SURFACE_WEEK1 = 8,
        SURFACE_WEEK2 = 9,
        SURFACE_ICE = 10,
        SURFACE_EROSION = 11,
        SURFACE_NUM = 12,
    };
}  // namespace nRegionStatus

// Declarations
namespace nRegionStatus { struct stCorePointSlaveMsg; }

// Type aliases from DWARF
using u16 = unsigned short;

namespace nRegionStatus {

    // Forward declarations
    struct stCorePointSlaveMsg;

    struct stCorePointSlaveMsg
    {
    public:
        stCorePointSlaveMsg();
        void clear();
        void copy(const nRegionStatus::stCorePointSlaveMsg& src);
    public:
        u16 mRegionCorePointID;  // offset: 0x0
        u16 mActiveTimer;  // offset: 0x2
        bool mIsStandby;  // offset: 0x4
    };

    bool isCorePointErosion(CORE_POINT_TYPE type);
    bool isCorePointErosionTentacle(CORE_POINT_TYPE type);

}  // namespace nRegionStatus
