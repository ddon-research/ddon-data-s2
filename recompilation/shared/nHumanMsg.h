#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "nHuman.h"

// Forward declarations
class cContextCharacter;

// Declarations
namespace nHuman { struct stShellRequestInfo; }
namespace nHuman { struct stShellRequestMsg; }

namespace nHuman {
    enum CUSTOM_SKILL_GROUP
    {
        CUSTOM_SKILL_GROUP_NONE = -1,
        CUSTOM_SKILL_GROUP_1 = 0,
        CUSTOM_SKILL_GROUP_2 = 1,
        CUSTOM_SKILL_GROUP_NUM = 2,
        CUSTOM_SKILL_GROUP_DEFAULT = 0,
        CSUTOM_SKILL_GROUP_CURRENT = 1000,
        CUSTOM_SKILL_GROUP_INIT = 0,
    };
}  // namespace nHuman

// Type aliases from DWARF
using u32 = unsigned int;
using u8 = unsigned char;

namespace nHuman {

    enum
    {
        CSMSG_BIT_SLOT = 0,
        CSMSG_BIT_GROUP = 4,
    };

    enum
    {
        SEQ_PAGE_CANCEL_SEQ = 1,
        SEQ_C_MOVE = 0,
        SEQ_C_NORMAL_ATTACK = 1,
        SEQ_C_NORMAL_ATTACK_PRE = 2,
        SEQ_C_JUMP = 3,
        SEQ_C_JUMP_PRE = 4,
        SEQ_C_SKILL = 5,
        SEQ_C_SKILL_PRE = 6,
        SEQ_C_EVASION = 7,
        SEQ_C_EVASION_PRE = 8,
        SEQ_C_SPECIAL_0 = 9,
        SEQ_C_SPECIAL_1 = 10,
        SEQ_C_CHG_STAT = 11,
        SEQ_C_COMB_END = 12,
        SEQ_C_NO_CHECK = 65535,
        SEQ_PAGE_SEQ_CNT = 1,
        SEQ_STAMINA_RECOVER = 14,
        SEQ_STAMINA_DECREASE = 15,
        SEQ_SEQ_CNT0 = 16,
        SEQ_SEQ_CNT1 = 17,
        SEQ_JOB_GENERAL = 18,
        SEQ_C_SUPER_ARMOR = 23,
    };

    enum
    {
        MOTION_CTRL_BOTTOM = 0,
        MOTION_CTRL_TOP = 1,
        MOTION_CTRL_FACE = 2,
        MOTION_CTRL_NUM = 3,
    };

    enum
    {
        CHARGE_LEVEL_0 = 0,
        CHARGE_LEVEL_1 = 1,
        CHARGE_LEVEL_2 = 2,
        CHARGE_LEVEL_3 = 3,
        CHARGE_LEVEL_4 = 4,
        CHARGE_LEVEL_5 = 5,
        CHARGE_LEVEL_NUM = 6,
    };

    enum
    {
        COL_BANK_COMMON = 0,
        COL_BANK_JOB_ATTACK = 1,
        COL_BANK_CUSTOM = 2,
        COL_BANK_EROSION = 13,
        COL_BANK_HMEM_ATK = 14,
    };

    enum
    {
        MBANK_HUMAN_COMMON = 0,
        MBANK_HUMAN_DAMAGE = 256,
        MBANK_HUMAN_GRIP = 512,
        MBANK_HUMAN_JOB_CM = 768,
        MBANK_HUMAN_JOB_AT = 1024,
        MBANK_HUMAN_SP = 1280,
        MBANK_HUMAN_EMO = 1536,
        MBANK_HUMAN_CAUGHT = 1792,
        MBANK_HUMAN_NPC = 2048,
        MBANK_HUMAN_ENEMY = 2304,
        MBANK_HUMAN_MY_ROOM = 2304,
        MBANK_HUMAN_DEMO = 2560,
        MBANK_HUMAN_FACIAL = 2816,
        MBANK_HUMAN_FINGER = 3072,
        MBANK_HUMAN_NPC_SS = 3328,
        MBANK_HUMAN_JOB_AT_2 = 3584,
    };

    enum
    {
        JPRM_JUMP = 0,
        JPRM_DASHJUMP = 1,
        JPRM_NORMAL_FALL = 2,
        JPRM_SHRINK_S_FRONT = 3,
        JPRM_SHRINK_S_BACK = 4,
        JPRM_SHRINK_L_FRONT = 5,
        JPRM_SHRINK_L_BACK = 6,
        JPRM_GUARD_BREAK = 7,
        JPRM_ENEMY_CLIMB_JUMP = 8,
        JPRM_ITEM_THROW_AIR = 9,
        JPRM_ENEMY_CLIMB_END = 10,
        JPRM_BOW_JAMP = 11,
        JPRM_DASHJUMP_CLIFF = 12,
        JPRM_BRING_OM_JUMP = 13,
        JPRM_CATAPULT_JUMP = 14,
        JPRM_CATAPULT_JUMP_LV1 = 15,
        JPRM_CATAPULT_JUMP_LV2 = 16,
        JPRM_CATAPULT_JUMP_LV3 = 17,
        JPRM_CATAPULT_JUMP_LV4 = 18,
        JPRM_CATAPULT_JUMP_LV5 = 19,
        JPRM_CATAPULT_JUMP_LV6 = 20,
        JPRM_CATCH_JUMP = 21,
        JPRM_CATCH_LADDER_JUMP = 22,
        JPRM_SLIDE_LADDER = 23,
        JPRM_CLIMB_STAMINA_ENPTY_FALL = 24,
        JPRM_JOB09_FRIGHT_BOARD_LAND1 = 25,
        JPRM_JOB09_FRIGHT_BOARD_LAND2 = 26,
        JPRM_JOB09_FRIGHT_BOARD_LAND3 = 27,
        JPRM_JOB09_FRIGHT_BOARD_LAND4 = 28,
        JPRM_JOB09_FRIGHT_BOARD_LAND5 = 29,
        JPRM_JOB09_FRIGHT_BOARD_AIR1 = 30,
        JPRM_JOB09_FRIGHT_BOARD_AIR2 = 31,
        JPRM_JOB09_FRIGHT_BOARD_AIR3 = 32,
        JPRM_JOB09_FRIGHT_BOARD_AIR4 = 33,
        JPRM_JOB09_FRIGHT_BOARD_AIR5 = 34,
        JPRM_CATCH_JUMP_NEAR_LAND = 35,
        JPRM_JUMP_AWAKENING = 36,
        JPRM_JUMP_RABBIT_JUMP_S = 37,
        JPRM_JUMP_RABBIT_JUMP_M = 38,
        JPRM_JUMP_RABBIT_JUMP_L = 39,
    };

    enum
    {
        COL_PROG_CHECK = 0,
        COL_PROG_CHECKED = 1,
        COL_PROG_CATCH_CHECK = 2,
        COL_PROG_CATCH_CHECKED = 3,
        COL_PROG_WIRE = 4,
        COL_PROG_WIRE_JUMP = 5,
        COL_PROG_OM_CATCH_CHECK = 6,
        COL_PROG_CATAPULT_CHECKED = 7,
        COL_PROG_CATAPULT_HUMIKOMI = 8,
        COL_PROG_SLEEP_DAMAGE = 9,
        COL_PROG_NPC_CHECKE = 10,
        COL_PROG_AIM = 11,
        COL_PROG_PAWN_OM_CHECKE = 12,
        COL_PROG_SOFTBODY = 13,
        COL_PROG_LOBBY_OBJ_COL = 14,
        COL_PROG_EROSION_RESCUE = 15,
        COL_JOB02_EVASION_TEST = 109,
    };

    // Forward declarations
    struct stShellRequestInfo;
    struct stShellRequestMsg;

    struct stShellRequestMsg
    {
    public:
        stShellRequestMsg();
        void clear();
        void copy(const nHuman::stShellRequestMsg& src);
    public:
        u32 mShlOwnerUID;  // offset: 0x0
        u32 mTargetUID;  // offset: 0x4
        u32 mShotSys;  // offset: 0x8
        u8 mShotGroup;  // offset: 0xc
        u8 mShotIndex;  // offset: 0xd
        u8 mLockOnIndex;  // offset: 0xe
    };

    struct stShellRequestInfo
    {
        // inferred: cContextCharacter::getShellRequestInfoNum names cContextCharacter::mSheRequestArray[0].mIsSeted
        friend class ::cContextCharacter;
    public:
        stShellRequestInfo();
        void clear();
        void setReqMsg(const nHuman::stShellRequestMsg& msg);
        const nHuman::stShellRequestMsg& getReqMsg() const;
        bool isSeted() const;
    private:
        nHuman::stShellRequestMsg mReqMsg;  // offset: 0x0
        bool mIsSeted;  // offset: 0x10
    };

    u32 getJobArrayIndex(JOB_ENUM jobId);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nHuman.cpp:947
    u32 getRoleArrayIndex(ROLE_ENUM roleId);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nHuman.cpp:958
    u32 getCustomSkillIdArrayIndex(CUSTOM_SKILL_ENUM id);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nHuman.cpp:970
    bool isEnableCustomSkillId(CUSTOM_SKILL_ENUM id);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nHuman.cpp:989
    bool CSGroupConvertCSMsg2Info(const u8 csSlotMsg, CUSTOM_SKILL_GROUP& group, u8& slot);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nHuman.cpp:1010
    bool CSGroupConvertInfo2CSMsg(const u8 group, const u8 slot, u8& csSlotMsg);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nHuman.cpp:1031
    u32 getNormalSkillIdArrayIndex(GROW_NORMAL_SKILL_ENUM id);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nHuman.cpp:1047
    bool isEnableNormalSkillId(GROW_NORMAL_SKILL_ENUM id);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nHuman.cpp:1065

}  // namespace nHuman
