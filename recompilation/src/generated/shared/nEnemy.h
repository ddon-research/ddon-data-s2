#pragma once

#include <cstdint>
#include <cstddef>

namespace nEnemy {
    enum CUSTOM_WORK_TYPE
    {
        CUSTOM_WORK_HOVER_ALTITUDE00 = 256,
        CUSTOM_WORK_HOVER_ALTITUDE01 = 512,
        CUSTOM_WORK_HOVER_BASE_MODE = 1024,
        CUSTOM_WORK_EROSION_SMALL = 2048,
        CUSTOM_WORK_SUICIDE_REGION_1 = 16384,
        CUSTOM_WORK_SUICIDE_REGION_2 = 32768,
    };
}  // namespace nEnemy

namespace nEnemy {
    enum DMG_TIMER_TYPE
    {
        DTT_NOTHING = 0,
        DTT_FROM_BLOW = 1,
        DTT_FROM_CRUSH = 2,
        DTT_FROM_TAKE_DOWN = 3,
        DTT_FROM_SWAYED = 4,
        DTT_FROM_YOROYORO = 5,
        DTT_MAX = 6,
    };
}  // namespace nEnemy

namespace nEnemy {
    enum DM_DIR_JUDGE_TYPE
    {
        DIR_TYPE_ONLY_FRONT = 0,
        DIR_TYPE_2DIR_FB = 1,
        DIR_TYPE_2DIR_LR = 2,
        DIR_TYPE_4DIR = 3,
        DIR_TYPE_NUM = 4,
    };
}  // namespace nEnemy

namespace nEnemy {
    enum DOWN_DIR
    {
        DOWN_DIR_NOTHING = 0,
        DOWN_DIR_UTSUBUSE = 1,
        DOWN_DIR_AOMUKE = 2,
        DOWN_DIR_LEFT = 3,
        DOWN_DIR_RIGHT = 4,
    };
}  // namespace nEnemy

namespace nEnemy {
    enum EM_ADJUST_PARAM
    {
        EM_ADJUST_EROSION_FRAME = 0,
        EM_ADJUST_EROSION_MASK_RATE_1 = 1,
        EM_ADJUST_EROSION_MASK_RATE_2 = 2,
        EM_ADJUST_EROSION_MASK_RATE_3 = 3,
        EM_ADJUST_EROSION_MASK_RATE_4 = 4,
        EM_ADJUST_EROSION_SMALL_SCLAE = 5,
        EM_ADJUST_EROSION_YOJI_ADD_EVA = 6,
        EM_ADJUST_EROSION_YOJI_SUB_EVA = 7,
        EM_ADJUST_EROSION_LIFESPAN_MAN_EATER = 8,
        EM_ADJUST_SHRINK_RAGE_SLOWRATE = 9,
        EM_ADJUST_SHRINK_RAGE_SLOWTIME = 10,
        EM_ADJUST_SHRINK_RAGE_INTERFRAME = 11,
        EM_ADJUST_GORE_YOROYORO_VALUE = 12,
        EM_ADJUST_GORE_YOROYORO_RECOVER_SPEED = 13,
        EM_ADJUST_SUPER_EROSION_COREPOINT_ADJ = 14,
        EM_ADJUST_SUPER_EROSION_TENTACLE_MIN_TIME = 15,
        EM_ADJUST_GORE_YOROYORO_CORE_POINT_ADJ = 16,
        EM_ADJUST_TARASUK_JOB05_PROVOKE_EX_DIST = 17,
        EM_ADJUST_SPIRIT_DRAGON_ATTACK_OM_SHAKE_BASE_ATTACK = 18,
        EM_ADJUST_NUM = 19,
    };
}  // namespace nEnemy

namespace nEnemy {
    enum EM_GUARD_REACTION_CHECK_TYPE
    {
        EM_GUARD_REACTION_NON = 0,
        EM_GUARD_REACTION_CHECK = 1,
    };
}  // namespace nEnemy

namespace nEnemy {
    enum EM_REACT_NO
    {
        EM_REACT_ERROR = 0,
        EM_REACT_NONE = 1,
        EM_REACT_ALL = 2,
    };
}  // namespace nEnemy

namespace nEnemy {
    enum EM_STATUS_ADJ_INDEX
    {
        EM_RAGE_ADJ = 0,
    };
}  // namespace nEnemy

namespace nEnemy {
    enum EM_THINK_MODE
    {
        EM_THINK_MODE_NORMAL = 0,
        EM_THINK_MODE_BATTLE = 1,
        EM_THINK_MODE_MAX = 2,
    };
}  // namespace nEnemy

namespace nEnemy {
    enum ENEMY_BLOOD_STAIN_LV
    {
        ENEMY_BLOOD_STAIN_LV_0 = 0,
        ENEMY_BLOOD_STAIN_LV_1 = 1,
        ENEMY_BLOOD_STAIN_LV_2 = 2,
        ENEMY_BLOOD_STAIN_LV_3 = 3,
        ENEMY_BLOOD_STAIN_LV_NUM = 4,
    };
}  // namespace nEnemy

namespace nEnemy {
    enum ENEMY_BLOOD_STAIN_TYPE
    {
        ENEMY_BLOOD_STAIN_TYPE_HP = 0,
        ENEMY_BLOOD_STAIN_TYPE_REGION = 1,
        ENEMY_BLOOD_STAIN_TYPE_NONE = 2,
        ENEMY_BLOOD_STAIN_TYPE_NUM = 3,
    };
}  // namespace nEnemy

namespace nEnemy {
    enum ENEMY_BODY_SIZE
    {
        SIZE_SMALL = 0,
        SIZE_NORMAL = 1,
        SIZE_LARGE = 2,
        SIZE_VERY_LARGE = 3,
        SIZE_NUM = 4,
        SIZE_UNKOWN = 5,
    };
}  // namespace nEnemy

namespace nEnemy {
    enum ENEMY_CATEGORY
    {
        EM_CATEGORY_INVALID = 0,
        EM_CATEGORY_INIT = 1,
        EM_CATEGORY_DEMI_HUMAN = 1,
        EM_CATEGORY_BEAST = 2,
        EM_CATEGORY_KIZIN = 3,
        EM_CATEGORY_ZOMBIE = 4,
        EM_CATEGORY_SKELETON = 5,
        EM_CATEGORY_WINGED = 6,
        EM_CATEGORY_GIANT = 7,
        EM_CATEGORY_SOFT_BODY = 8,
        EM_CATEGORY_GHOST = 9,
        EM_CATEGORY_CURSE = 10,
        EM_CATEGORY_ART_EVIL = 11,
        EM_CATEGORY_HUMAN = 12,
        EM_CATEGORY_ALCHEMY = 13,
        EM_CATEGORY_DRAGON = 14,
        EM_CATEGORY_EVIL = 15,
        EM_CATEGORY_EROSION = 16,
        EM_CATEGORY_NUM = 17,
    };
}  // namespace nEnemy

namespace nEnemy {
    enum ENEMY_MODE
    {
        ENEMY_MODE_NORMAL = 0,
        ENEMY_MODE_NPC = 1,
    };
}  // namespace nEnemy

namespace nEnemy {
    enum JMP_ATK_SPD_PARAM
    {
        JMP_ATK_SPD_PARAM1 = 0,
        JMP_ATK_SPD_PARAM2 = 1,
        JMP_ATK_SPD_PARAM3 = 2,
        JMP_ATK_SPD_PARAM4 = 3,
        JMP_ATK_SPD_PARAM_MAX = 4,
    };
}  // namespace nEnemy

namespace nEnemy {
    enum PARAM_RESET_TYPE
    {
        PARAM_RESET_TYPE_ALL = 0,
        PARAM_RESET_TYPE_SECOND_SET = 1,
        PARAM_RESET_TYPE_OCD = 2,
    };
}  // namespace nEnemy

namespace nEnemy {
    enum REGION_BREAK_REACTION_NO
    {
        REGION_BREAK_REACTION_INVALID = 0,
        REGION_BREAK_REACTION_1 = 1,
        REGION_BREAK_REACTION_2 = 2,
        REGION_BREAK_REACTION_3 = 3,
        REGION_BREAK_REACTION_4 = 4,
        REGION_BREAK_REACTION_5 = 5,
        REGION_BREAK_REACTION_6 = 6,
        REGION_BREAK_REACTION_7 = 7,
        REGION_BREAK_REACTION_8 = 8,
        REGION_BREAK_REACTION_9 = 9,
        REGION_BREAK_REACTION_10 = 10,
        REGION_BREAK_REACTION_END = 11,
        REGION_BREAK_REACTION_NUM = 10,
        REGION_BREAK_REACTION_NON = -1,
    };
}  // namespace nEnemy

namespace nEnemy {
    enum RESOURCE_TYPE
    {
        MODEL_RES = 0,
        MATERIAL_CHANGE = 1,
        MOTION_RES_CO = 2,
        MOTION_RES_AT = 3,
        MOTION_RES_AT1 = 4,
        MOTION_RES_DM = 5,
        MOTION_RES_EX = 6,
        MOTION_RES_NP = 7,
        MOTION_RES_CO2 = 8,
        MOTION_RES_AT2 = 9,
        MOTION_RES_DM2 = 10,
        MOTION_RES_EX2 = 11,
        MOTION_RES_WEP_CO = 12,
        MOTION_RES_WEP_AT = 13,
        MOTION_RES_WEP_DM = 14,
        MOTION_RES_WEP_EX = 15,
        MOTION_PARAM_CO = 16,
        MOTION_PARAM_AT = 17,
        MOTION_PARAM_AT1 = 18,
        MOTION_PARAM_DM = 19,
        MOTION_PARAM_EX = 20,
        MOTION_PARAM_NP = 21,
        MOTION_PARAM_CO2 = 22,
        MOTION_PARAM_AT2 = 23,
        MOTION_PARAM_DM2 = 24,
        MOTION_PARAM_EX2 = 25,
        MOTION_PARAM_WEP_CO = 26,
        MOTION_PARAM_WEP_AT = 27,
        MOTION_PARAM_WEP_DM = 28,
        MOTION_PARAM_WEP_EX = 29,
        RKTHINK_RES = 30,
        OBJCOL_RES = 31,
        ATKCOL_RES = 32,
        OBJCOLPROG_RES = 33,
        STATUS_CHANGE_RES = 34,
        STATUS_LOCALEST_RES = 35,
        AI_SENSOR_RES = 36,
        C_REGION_PARAM = 37,
        P_REGION_PARAM = 38,
        CHARA_PARAM = 39,
        LOCK_ON = 40,
        BIT_COL = 41,
        BIT_PARTS = 42,
        BIT_WORKRATE = 43,
        BIT_SCALE = 44,
        BIT_LOCAL = 45,
        BIT_LOCAL2 = 46,
        TABLE_PARTS = 47,
        TABLE_WORKRATE = 48,
        TABLE_SCALE = 49,
        TABLE_RAGE = 50,
        SHELL_PARAM_LIST = 51,
        SHOT_REQ_INFO = 52,
        SHELL_PARAM_GROUP_0 = 53,
        SHELL_PARAM_GROUP_1 = 54,
        CATCH_INFO_PARAM = 55,
        CAUGHT_INFO_PARAM = 56,
        EM_DMG_TIMER_TBL = 57,
        SOUNDREQ_SE = 58,
        SOUNDREQ_VO_A = 59,
        SOUNDREQ_VO_B = 60,
        SOUNDREQ_VO_END = 61,
        MOTIONSE_VO = 62,
        EFFECT_COMMON = 63,
        EFFECT_ORIGINAL = 64,
        SHELL_SE = 65,
        TABLE_EMSOUND = 66,
        TABLE_EMEFFECT = 67,
        TABLE_EMMATERIAL = 68,
        OCD_STATUS_PARAM = 69,
        OCD_IMMUNE_PARAM = 70,
        LV_UP_PARAM = 71,
        JOINTEX2 = 72,
        TINYCHAIN = 73,
        CAMERA_PARAM_LIST = 74,
        AIPAWNEM_TBL = 75,
        AIPAWNEM_PARAM = 76,
        HM_EM_PARAM = 77,
        MONTAGE = 78,
        BIT_MONTAGE = 79,
        JOINT_ORDER = 80,
        HEAD_CTRL = 81,
        LEG_CTRL = 82,
        SHAKE_CTRL_DAMAGE = 83,
        SHAKE_CTRL_SHAKE = 84,
        IK_CTRL = 85,
        RES_SOFT_BODY = 86,
        RES_VIBLATION_ONLY = 87,
        RES_OCD_ELECTRIC = 88,
        RES_STATUS_ADJ = 89,
        BIT_SYNCBIT = 90,
        RES_HMEM_MGC_CHANT = 91,
        RES_CONST_MODEL_PARAM = 92,
        RES_EM_REACT_RES00 = 93,
        RES_EM_REACT_RES01 = 94,
        RES_EM_REACT_RES02 = 95,
        RES_EM_REACT_RES03 = 96,
        RES_EM_REACT_RES04 = 97,
        RES_EM_REACT_RES05 = 98,
        RES_EM_REACT_RES06 = 99,
        RES_EM_REACT_RES07 = 100,
        RES_EM_STATUS_CHECK = 101,
        RES_EM_LOCAL_SHEL = 102,
        RES_C_REGION_HMEM = 103,
        EFFECT_ORIGINAL_EX = 104,
        RES_REACTION = 105,
        RES_EM_WARP_PARAM = 106,
        RES_EM_EROSION_REGION = 107,
        RES_EM_EROSION_SHL = 108,
        RES_EM_EROSION_ATTACK_0 = 109,
        RES_EM_EROSION_ATTACK_1 = 110,
        RES_EM_EROSION_ATTACK_2 = 111,
        RES_EM_EROSION_ATTACK_3 = 112,
        RES_EM_EROSION_ATTACK_4 = 113,
        RES_EM_EROSION_SOUND = 114,
        RES_EM_BLOOD_STAIN = 115,
        SHOT_REQ_INFO2 = 116,
        RES_EM_EROSION_INFO = 117,
        RES_EM_WALL_MARIA = 118,
        RES_EM_EROSION_SMALL_INFO = 119,
        RES_EM_EROSION_SUPER_INFO = 120,
        RES_EM_EROSION_SUPER_SOUND = 121,
        RESOURCE_TYPE_NUM = 122,
        RESOURCE_TYPE_INVALID = -1,
    };
}  // namespace nEnemy

namespace nEnemy {
    enum TURN_TYPE
    {
        TURN_TYPE_TARGET = 0,
        TURN_TYPE_OPPOSITE = 1,
        TURN_TYPE_FIXED = 2,
    };
}  // namespace nEnemy
