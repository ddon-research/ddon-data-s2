#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
namespace nObjCollision { struct stDmageVecInfo; }

namespace nObjCollision {
    enum BLOW_ATTACK_ADJ_TYPE
    {
        BLOW_ATTACK_ADJ_ABILITY = 0,
        BLOW_ATTACK_ADJ_ITEM = 1,
        BLOW_ATTACK_ADJ_QUEST = 2,
        BLOW_ATTACK_ADJ_STATUS = 3,
        BLOW_ATTACK_ADJ_TYPE_NUM = 4,
        BLOW_ATTACK_ADJ_SUM = 4,
        BLOW_ATTACK_ADJ_TYPE_NUM_MAX = 5,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum BLOW_DEFENCE_ADJ_TYPE
    {
        BLOW_DEFENCE_ADJ_ABILITY = 0,
        BLOW_DEFENCE_ADJ_ITEM = 1,
        BLOW_DEFENCE_ADJ_QUEST = 2,
        BLOW_DEFENCE_ADJ_STATUS = 3,
        BLOW_DEFENCE_ADJ_TYPE_NUM = 4,
        BLOW_DEFENCE_ADJ_SUM = 4,
        BLOW_DEFENCE_ADJ_TYPE_NUM_MAX = 5,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum BLOW_REASON
    {
        BLOW_REASON_NONE = 0,
        BLOW_REASON_ENDURANCE = 1,
        BLOW_REASON_FORCE = 2,
        BLOW_REASON_RAGE_SHRINK = 3,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum CALC_DAMADE_KIND
    {
        KIND_CALC_DMAGE = 0,
        KIND_CALC_HEAL = 1,
        KIND_CALL_SE_EFF = 2,
        KIND_DISP_GUI = 3,
        KIND_HIT_STOP = 4,
        KIND_APPLY_ENDURANCE = 5,
        KIND_NUM = 6,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum CALC_DAMADE_MODE
    {
        MODE_NON = 0,
        MODE_SEND = 1,
        MODE_LOCAL_ACT = 2,
        MODE_LOCAL_NONE = 3,
        MODE_NUM = 4,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum CALC_DAMAGE_UNIT_TYPE
    {
        PLMS = 0,
        PLSL = 1,
        PAWNMS = 2,
        PAWNSL = 3,
        NPLMS = 4,
        NPLSL = 5,
        LOCMS = 6,
        LOCSL = 7,
        UNIT_TYPE_NUM = 8,
        NON_TYPE = 9,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum DAMAGE_ATTR_ENUM
    {
        DAMAGE_NO_DAMAGE = 0,
        DAMAGE_NO_DEATH = 1,
        DAMAGE_NO_HP_INV = 2,
        DAMAGE_NO_REGION_BREAK = 3,
        DAMAGE_NO_HEAL = 4,
        DAMAGE_NO_BLOW_INV = 5,
        DAMAGE_NO_SHRINK_INV = 6,
        DAMAGE_NO_DOWN_INV = 7,
        DAMAGE_NO_SHAKE_INV = 8,
        DAMAGE_NO_BLOW_REACT = 9,
        DAMAGE_NO_SHRINK_REACT = 10,
        DAMAGE_NO_DOWN_REACT = 11,
        DAMAGE_NO_SHAKE_REACT = 12,
        DAMAGE_NO_OCD_INIT = 13,
        DAMAGE_NO_OCD_INIT_BAD = 14,
        DAMAGE_NO_OCD_INV = 15,
        DAMAGE_NO_OCD_EFFECT = 16,
        DAMAGE_OCD_TIMER_STOP = 17,
        DAMAGE_NO_OCD_ENDU_CURE = 18,
        DAMAGE_CURE_BAD_STATUS = 19,
        DAMAGE_NO_HIT_SE_EFF = 20,
        DAMAGE_NO_HIT_STOP = 21,
        DAMAGE_NO_DAMAGE_GUI = 22,
        DAMAGE_NO_STORM_QUAKE = 23,
        DAMAGE_NO_SHAKE = 24,
        DAMAGE_NO_SHRINK_REACT_AIR = 25,
        DAMAGE_NO_CATCH = 26,
        DAMAGE_INV_DAMAGE_UI = 27,
        DAMAGE_NO_NUM = 28,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum DAMAGE_BONOUS_TYPE_FLAG
    {
        BONOUS_RAGE_SHRINK_BOUNUS_FLAG = 2,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum DAMAGE_SPECIAL_ADJ
    {
        DAMAGE_SPECIAL_ADJ_NONE = 0,
        DAMAGE_SPECIAL_ADJ_VER2 = 1,
        ENEMY_BLOOD_STAIN_LV_NUM = 2,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum DM_REACTION_DIR
    {
        DIR_FRONT = 0,
        DIR_BACK = 1,
        DIR_LEFT = 2,
        DIR_RIGHT = 3,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum DOWN_ATTACK_ADJ_TYPE
    {
        DOWN_ATTACK_ADJ_ABILITY = 0,
        DOWN_ATTACK_ADJ_ITEM = 1,
        DOWN_ATTACK_ADJ_QUEST = 2,
        DOWN_ATTACK_ADJ_STATUS = 3,
        DOWN_ATTACK_ADJ_TYPE_NUM = 4,
        DOWN_ATTACK_ADJ_SUM = 4,
        DOWN_ATTACK_ADJ_TYPE_NUM_MAX = 5,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum DOWN_DEFENCE_ADJ_TYPE
    {
        DOWN_DEFENCE_ADJ_ABILITY = 0,
        DOWN_DEFENCE_ADJ_ITEM = 1,
        DOWN_DEFENCE_ADJ_QUEST = 2,
        DOWN_DEFENCE_ADJ_STATUS = 3,
        DOWN_DEFENCE_ADJ_TYPE_NUM = 4,
        DOWN_DEFENCE_ADJ_SUM = 4,
        DOWN_DEFENCE_ADJ_TYPE_NUM_MAX = 5,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum FORCE_REACTION_TYPE
    {
        FORCE_REACTION_NONE = 0,
        FORCE_REACTION_ATTACK_PARAM = 1,
        FORCE_REACTION_COMPONENT = 2,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum GUARD_ANGLE_TYPE
    {
        GUARD_ANGLE_NORMAL = 0,
        GUARD_ANGLE_ALL_RANGE = 1,
        GUARD_ANGLE_NO_GUARD = 2,
        GUARD_ANGLE_NUM = 3,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum GUARD_ATTACK_ADJ_TYPE
    {
        GUARD_ATTACK_ADJ_ABILITY = 0,
        GUARD_ATTACK_ADJ_ITEM = 1,
        GUARD_ATTACK_ADJ_QUEST = 2,
        GUARD_ATTACK_ADJ_STATUS = 3,
        GUARD_ATTACK_ADJ_TYPE_NUM = 4,
        GUARD_ATTACK_ADJ_SUM = 4,
        GUARD_ATTACK_ADJ_TYPE_NUM_MAX = 5,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum GUARD_DEFENCE_ADJ_TYPE
    {
        GUARD_DEFENCE_ADJ_ABILITY = 0,
        GUARD_DEFENCE_ADJ_ITEM = 1,
        GUARD_DEFENCE_ADJ_QUEST = 2,
        GUARD_DEFENCE_ADJ_STATUS = 3,
        GUARD_DEFENCE_ADJ_TYPE_NUM = 4,
        GUARD_DEFENCE_ADJ_SUM = 4,
        GUARD_DEFENCE_ADJ_TYPE_NUM_MAX = 5,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum HIT_GROUP_BIT
    {
        HIT_GROUP_PLAYER_B = 1,
        HIT_GROUP_ENEMY_B = 2,
        HIT_GROUP_BIG_ENEMY_B = 4,
        HIT_GROUP_NPC_B = 8,
        HIT_GROUP_OM_B = 16,
        HIT_GROUP_TRAP_OM_B = 32,
        HIT_GROUP_TARU_OM_B = 64,
        HIT_GROUP_PL_KIBAKU_B = 128,
        HIT_GROUP_EM_KIBAKU_B = 256,
        HIT_GROUP_NONE_B = 0,
        HIT_GROUP_ALL_B = 16777215,
        HIT_GROUP_CMD_MASK_B = -16777216,
        HIT_GROUP_ALL_OM_B = 112,
        HIT_GROUP_OPPONENT_B = 33554319,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum HIT_INFO_TYPE
    {
        HIT_INFO_TYPE_NORMAL = 0,
        HIT_INFO_TYPE_SHRINK_BOUNUS = 1,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum HP_DAMAGE_ATTACK_ADJ_TYPE
    {
        HP_DAMAGE_ATTACK_ADJ_ABILITY = 0,
        HP_DAMAGE_ATTACK_ADJ_ITEM = 1,
        HP_DAMAGE_ATTACK_ADJ_QUEST = 2,
        HP_DAMAGE_ATTACK_ADJ_STATUS = 3,
        HP_DAMAGE_ATTACK_ADJ_COMMON_NUM = 4,
        HP_DAMAGE_ATTACK_ADJ_PHYS = 4,
        HP_DAMAGE_ATTACK_ADJ_MAGIC = 5,
        HP_DAMAGE_ATTACK_ADJ_TYPE_NUM = 6,
        HP_DAMAGE_ATTACK_ADJ_SUM = 6,
        HP_DAMAGE_ATTACK_ADJ_TYPE_NUM_MAX = 7,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum HP_DAMAGE_DEFENCE_ADJ_TYPE
    {
        HP_DAMAGE_DEFENCE_ADJ_ABILITY = 0,
        HP_DAMAGE_DEFENCE_ADJ_ITEM = 1,
        HP_DAMAGE_DEFENCE_ADJ_QUEST = 2,
        HP_DAMAGE_DEFENCE_ADJ_STATUS = 3,
        HP_DAMAGE_DEFENCE_ADJ_COMMON_NUM = 4,
        HP_DAMAGE_DEFENCE_ADJ_PHYS = 4,
        HP_DAMAGE_DEFENCE_ADJ_MAGIC = 5,
        HP_DAMAGE_DEFENCE_ADJ_TYPE_NUM = 6,
        HP_DAMAGE_DEFENCE_ADJ_SUM = 6,
        HP_DAMAGE_DEFENCE_ADJ_TYPE_NUM_MAX = 7,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum HP_HEAL_ATTACK_ADJ_TYPE
    {
        HP_HEAL_ATTACK_ADJ_ABILITY = 0,
        HP_HEAL_ATTACK_ADJ_ITEM = 1,
        HP_HEAL_ATTACK_ADJ_QUEST = 2,
        HP_HEAL_ATTACK_ADJ_STATUS = 3,
        HP_HEAL_ATTACK_ADJ_TYPE_NUM = 4,
        HP_HEAL_ATTACK_ADJ_SUM = 4,
        HP_HEAL_ATTACK_ADJ_TYPE_NUM_MAX = 5,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum HP_HEAL_DEFENCE_ADJ_TYPE
    {
        HP_HEAL_DEFENCE_ADJ_ABILITY = 0,
        HP_HEAL_DEFENCE_ADJ_ITEM = 1,
        HP_HEAL_DEFENCE_ADJ_QUEST = 2,
        HP_HEAL_DEFENCE_ADJ_STATUS = 3,
        HP_HEAL_DEFENCE_ADJ_TYPE_NUM = 4,
        HP_HEAL_DEFENCE_ADJ_SUM = 4,
        HP_HEAL_DEFENCE_ADJ_TYPE_NUM_MAX = 5,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum LV_ADJ_TYPE
    {
        LV_ADJ_DAMAGE = 0,
        LV_ADJ_SHRINK = 1,
        LV_ADJ_BLOW = 2,
        LV_ADJ_OCD = 3,
        LV_ADJ_DOWN = 4,
        LV_ADJ_STAMINA_DAMAGE = 5,
        LV_ADJ_NUM = 6,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum OCD_ATTACK_ADJ_TYPE
    {
        OCD_ATTACK_ADJ_ABILITY = 0,
        OCD_ATTACK_ADJ_ITEM = 1,
        OCD_ATTACK_ADJ_QUEST = 2,
        OCD_ATTACK_ADJ_STATUS = 3,
        OCD_ATTACK_ADJ_TYPE_NUM = 4,
        OCD_ATTACK_ADJ_SUM = 4,
        OCD_ATTACK_ADJ_TYPE_NUM_MAX = 5,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum OCD_DEFENCE_ADJ_TYPE
    {
        OCD_DEFENCE_ADJ_ABILITY = 0,
        OCD_DEFENCE_ADJ_ITEM = 1,
        OCD_DEFENCE_ADJ_QUEST = 2,
        OCD_DEFENCE_ADJ_STATUS = 3,
        OCD_DEFENCE_ADJ_TYPE_NUM = 4,
        OCD_DEFENCE_ADJ_SUM = 4,
        OCD_DEFENCE_ADJ_TYPE_NUM_MAX = 5,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum REACTION_TYPE
    {
        REACTION_NONE = 0,
        REACTION_DOWN = 1,
        REACTION_BLOW = 2,
        REACTION_SHAKE = 3,
        REACTION_SHRINK = 4,
        REACTION_STORM = 5,
        REACTION_QUAKE = 6,
        REACTION_TYPE_NUM = 7,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum RESULT_BONOUS_PRIORITY
    {
        RESULT_BONOUS_PRIORITY_NONE = 0,
        RESULT_BONOUS_PRIORITY_SHRINK = 100,
        RESULT_BONOUS_PRIORITY_OTHER_DAMAGE = 200,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum RESULT_BONOUS_TYPE
    {
        RESULT_BONOUS_NONE = 0,
        RESULT_BONOUS_RAGE_SHRINK_BOUNUS = 1,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum SHAKE_ATTACK_ADJ_TYPE
    {
        SHAKE_ATTACK_ADJ_ABILITY = 0,
        SHAKE_ATTACK_ADJ_ITEM = 1,
        SHAKE_ATTACK_ADJ_QUEST = 2,
        SHAKE_ATTACK_ADJ_STATUS = 3,
        SHAKE_ATTACK_ADJ_TYPE_NUM = 4,
        SHAKE_ATTACK_ADJ_SUM = 4,
        SHAKE_ATTACK_ADJ_TYPE_NUM_MAX = 5,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum SHAKE_CHANCE_TYPE
    {
        SHAKE_CHANCE_TYPE_SEQUENCE = 0,
        SHAKE_CHANCE_TYPE_SHRINK = 1,
        SHAKE_CHANCE_TYPE_NUM = 2,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum SHAKE_DEFENCE_ADJ_TYPE
    {
        SHAKE_DEFENCE_ADJ_ABILITY = 0,
        SHAKE_DEFENCE_ADJ_ITEM = 1,
        SHAKE_DEFENCE_ADJ_QUEST = 2,
        SHAKE_DEFENCE_ADJ_STATUS = 3,
        SHAKE_DEFENCE_ADJ_TYPE_NUM = 4,
        SHAKE_DEFENCE_ADJ_SUM = 4,
        SHAKE_DEFENCE_ADJ_TYPE_NUM_MAX = 5,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum SHRINK_ATTACK_ADJ_TYPE
    {
        SHRINK_ATTACK_ADJ_ABILITY = 0,
        SHRINK_ATTACK_ADJ_ITEM = 1,
        SHRINK_ATTACK_ADJ_QUEST = 2,
        SHRINK_ATTACK_ADJ_STATUS = 3,
        SHRINK_ATTACK_ADJ_TYPE_NUM = 4,
        SHRINK_ATTACK_ADJ_SUM = 4,
        SHRINK_ATTACK_ADJ_TYPE_NUM_MAX = 5,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum SHRINK_BLOW_TYPE
    {
        SHRINK_BLOW_TYPE_SHRINK_S = 0,
        SHRINK_BLOW_TYPE_SHRINK_L = 1,
        SHRINK_BLOW_TYPE_BLOW_BLOW = 2,
        SHRINK_BLOW_TYPE_BLOW_LAUNCH = 3,
        SHRINK_BLOW_TYPE_BLOW_SLAM = 4,
        SHRINK_BLOW_TYPE_BLOW_COLLAPSE = 5,
        SHRINK_BLOW_TYPE_BLOW_WIND = 6,
        SHRINK_BLOW_TYPE_BLOW_GROUND_NUM = 7,
        SHTINK_BLOW_AIR_SHIT = 8,
        SHTINK_BLOW_AIR_MASK = 256,
        SHRINK_BLOW_TYPE_SHRINK_S_AIR = 256,
        SHRINK_BLOW_TYPE_SHRINK_L_AIR = 257,
        SHRINK_BLOW_TYPE_BLOW_BLOW_AIR = 258,
        SHRINK_BLOW_TYPE_BLOW_LAUNCH_AIR = 259,
        SHRINK_BLOW_TYPE_BLOW_SLAM_AIR = 260,
        SHRINK_BLOW_TYPE_BLOW_COLLAPSE_AIR = 261,
        SHRINK_BLOW_TYPE_BLOW_WIND_AIR = 262,
        SHRINK_BLOW_TYPE_NON = 263,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum SHRINK_DEFENCE_ADJ_TYPE
    {
        SHRINK_DEFENCE_ADJ_ABILITY = 0,
        SHRINK_DEFENCE_ADJ_ITEM = 1,
        SHRINK_DEFENCE_ADJ_QUEST = 2,
        SHRINK_DEFENCE_ADJ_STATUS = 3,
        SHRINK_DEFENCE_ADJ_TYPE_NUM = 4,
        SHRINK_DEFENCE_ADJ_SUM = 4,
        SHRINK_DEFENCE_ADJ_TYPE_NUM_MAX = 5,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum STAMINA_DAMAGE_ADJ_TYPE
    {
        STAMINA_DAMAGE_ADJ_ABILITY = 0,
        STAMINA_DAMAGE_ADJ_ITEM = 1,
        STAMINA_DAMAGE_ADJ_QUEST = 2,
        STAMINA_DAMAGE_ADJ_STATUS = 3,
        STAMINA_DAMAGE_ADJ_TYPE_NUM = 4,
        STAMINA_DAMAGE_ADJ_SUM = 4,
        STAMINA_DAMAGE_ADJ_TYPE_NUM_MAX = 5,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum STAMINA_HEAL_ATTACK_ADJ_TYPE
    {
        STAMINA_HEAL_ATTACK_ADJ_ABILITY = 0,
        STAMINA_HEAL_ATTACK_ADJ_ITEM = 1,
        STAMINA_HEAL_ATTACK_ADJ_QUEST = 2,
        STAMINA_HEAL_ATTACK_ADJ_STATUS = 3,
        STAMINA_HEAL_ATTACK_ADJ_TYPE_NUM = 4,
        STAMINA_HEAL_ATTACK_ADJ_SUM = 4,
        STAMINA_HEAL_ATTACK_ADJ_TYPE_NUM_MAX = 5,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum STAMINA_HEAL_DEFENCE_ADJ_TYPE
    {
        STAMINA_HEAL_DEFENCE_ADJ_ABILITY = 0,
        STAMINA_HEAL_DEFENCE_ADJ_ITEM = 1,
        STAMINA_HEAL_DEFENCE_ADJ_QUEST = 2,
        STAMINA_HEAL_DEFENCE_ADJ_STATUS = 3,
        STAMINA_HEAL_DEFENCE_ADJ_TYPE_NUM = 4,
        STAMINA_HEAL_DEFENCE_ADJ_SUM = 4,
        STAMINA_HEAL_DEFENCE_ADJ_TYPE_NUM_MAX = 5,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum UNIT_INV_THROUGH_TYPE
    {
        INV_THROUGH_TYPE_NONE = 0,
        INV_THROUGH_TYPE_INIT = 1,
        INV_THROUGH_TYPE_NO_GUARD = 1,
        INV_THROUGH_TYPE_REACT_COMP = 2,
        INV_THROUGH_TYPE_NUM = 3,
    };
}  // namespace nObjCollision

namespace nObjCollision {
    enum UNIT_INV_TYPE
    {
        INV_TYPE_NONE = 0,
        INV_TYPE_INIT = 1,
        INV_TYPE_SUPER_ARMOR = 1,
        INV_TYPE_NO_DAMAGECOOLISION = 2,
        INV_TYPE_NO_DAMAGE = 3,
        INV_TYPE_NO_REACTION = 4,
        INV_TYPE_SUPER_ARMOR_FOR_PLAYER = 5,
        INV_TYPE_NO_DAMAGE_NPC = 6,
        INV_TYPE_CALL_WAITTING = 7,
        INV_TYPE_NO_OCD = 8,
        INV_TYPE_HANDS_OF_GOD = 9,
        INV_TYPE_NO_DAMAGE_NO_SE_NO_EFF = 10,
        INV_TYPE_TUTORIAL_ENEMY = 11,
        INV_TYPE_GOLD_BODY = 12,
        INV_TYPE_GOLD_STONE_BUFF = 13,
        INV_TYPE_REACTION_RESTRAINT = 14,
        INV_TYPE_REACTION_RESTRAINT_BLOW = 15,
        INV_TYPE_RIM_WARP = 16,
        INV_TYPE_SLEEP_CHANCE_DOWN = 17,
        INV_TYPE_AFTER_SHRINK_RAGE = 18,
        INV_TYPE_NO_OCD_NOT_CURE = 19,
        INV_TYPE_TRAINING_ROOM = 20,
        INV_TYPE_GRAZE_ENTRY = 21,
        INV_TYPE_GRAZE = 22,
        INV_TYPE_NO_REACTION_ACTIVE_HITSTOP = 23,
        INV_TYPE_NUM = 24,
    };
}  // namespace nObjCollision

// Type aliases from DWARF
using f32 = float;

namespace nObjCollision {
    struct stDmageVecInfo
    {
    public:
        stDmageVecInfo();
        void copy(const nObjCollision::stDmageVecInfo*);
    public:
        f32 mSpeedXZ;  // offset: 0x0
        f32 mAccelerateXZ;  // offset: 0x4
        f32 mSpeedY;  // offset: 0x8
        f32 mGravityY;  // offset: 0xc
    };
}  // namespace nObjCollision
