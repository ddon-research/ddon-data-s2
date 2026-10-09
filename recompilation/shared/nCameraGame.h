#pragma once

#include <cstdint>
#include <cstddef>

namespace nCameraGame {
    enum CAMERA_TYPE
    {
        TYPE_NML = 0,
        TYPE_TPS = 1,
        TYPE_TALK = 2,
        TYPE_FPS = 3,
        TYPE_LOCK = 4,
        TYPE_QFPS = 5,
        TYPE_MAGIC = 6,
        TYPE_ANIM = 7,
        TYPE_SDR = 8,
        TYPE_MOT = 9,
        TYPE_MOT_T = 10,
        TYPE_ANIM_T = 11,
        TYPE_TARGET = 12,
        TYPE_EM_CLIMB = 13,
        TYPE_TEMPLATE = 14,
        TYPE_PHOTO = 15,
        TYPE_NML2 = 16,
        TYPE_TPS2 = 17,
        TYPE_ANIM2 = 18,
    };
}  // namespace nCameraGame

namespace nCameraGame {
    enum TARGET_TYPE
    {
        TARGET_TYPE_PLAYER = 0,
        TARGET_TYPE_REQ_OWNER = 1,
        TARGET_TYPE_WORLD = 2,
        TARGET_TYPE_SHL = 3,
        TARGET_TYPE_TALK = 4,
        TARGET_TYPE_SET_EM = 5,
        TARGET_TYPE_SET_NPC = 6,
        TARGET_TYPE_SET_OM = 7,
        TARGET_TYPE_PL_EX = 8,
        TARGET_TYPE_TEMP_A = 9,
        TARGET_TYPE_TEMP_B = 10,
    };
}  // namespace nCameraGame

namespace nCameraGame {
    enum TEMP_TYPE
    {
        TEMP_TYPE_WORLD = 0,
        TEMP_TYPE_UNIT = 1,
    };
}  // namespace nCameraGame
