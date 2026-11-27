#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../XFramework/sCollision.h"

// Forward declarations
class MtHermiteCurve;
class MtVector3;

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
    enum COMMON_CAM
    {
        COMMON_CAM_FREEZE = 75,
        COMMON_CAM_MYROOM_CHAIR = 117,
    };
}  // namespace nCameraGame

namespace nCameraGame {
    enum JOB02_CAM
    {
        JOB02_CS06 = 41,
        JOB02_WIRE_READY = 100,
        JOB02_WIRE_THROW = 101,
        JOB02_CS10_HIT_CAM = 103,
    };
}  // namespace nCameraGame

namespace nCameraGame {
    enum JOB04_CAM
    {
        JOB04_NORMAL_SHOT = 12,
        JOB04_NORMAL_SHOT_LV2 = 13,
        JOB04_HEAL_SPOT = 100,
        JOB04_HEAL_SPOT_LV2 = 101,
        JOB04_CIRCLE_SHIFT = 102,
        JOB04_CIRCLE_COMON = 103,
        JOB04_CIRCLE_COMON_LV2 = 104,
        JOB04_BLAST_OPTION = 107,
        JOB04_CHANT_FOLLOW_UP = 110,
    };
}  // namespace nCameraGame

namespace nCameraGame {
    enum JOB06_CAM
    {
        JOB06_CHANT_AIM = 0,
        JOB06_MAGIC_SHOT = 1,
        JOB06_MAGIC_SET = 2,
        JOB06_CHANT2_AIM_POINT = 100,
        JOB06_CHANT_AIM_POINT = 101,
        JOB06_MAGIC_SHOT_B = 102,
        JOB06_CHANT_FOLLOW_UP = 110,
        JOB06_CHANT_SOUL_BOMB = 114,
        JOB06_CS12_CHANT = 120,
        JOB06_CS12_SHOT1 = 121,
        JOB06_CS12_SHOT2 = 122,
        JOB06_CS12_SHOT3 = 123,
        JOB06_CS12_SHOT4 = 124,
        JOB06_CS12_SHOT5 = 125,
        JOB06_CS12_SHOT6 = 126,
        JOB06_CS12_SHOT7 = 127,
        JOB06_CS12_SHOT1_END = 128,
    };
}  // namespace nCameraGame

namespace nCameraGame {
    enum JOB09_CAM
    {
        JOB09_CS01_ATTACK = 31,
    };
}  // namespace nCameraGame

namespace nCameraGame {
    enum JOB10_CAM
    {
        JOB10_CS04_SET_Y = 35,
        JOB10_CS04_SET_XY = 36,
        JOB10_CS05_EXE_NEAR = 48,
        JOB10_CS05_EXE_NEAR_AIR = 49,
        JOB10_CS05_EXE_FAR = 50,
        JOB10_CS05_EXE_FAR_AIR = 51,
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

// Type aliases from DWARF
using f32 = float;

namespace nCameraGame {

    enum
    {
        CMN_PARAM_NML_00 = 0,
        CMN_PARAM_NML_01 = 1,
        CMN_PARAM_HARPY_RIDE = 2,
        CMN_PARAM_03 = 3,
        CMN_PARAM_04 = 4,
        CMN_PARAM_TALK_NML = 5,
        CMN_PARAM_TALK_SHOP = 6,
        CMN_PARAM_TALK_FORCE = 7,
        CMN_PARAM_HAGAIZIME = 8,
        CMN_PARAM_RIM_MAINPAWN = 9,
        CMN_PARAM_BALLISTA = 10,
        CMN_PARAM_BALLISTA_RIDE = 11,
        CMN_PARAM_RULER_BALL = 12,
        CMN_PARAM_13 = 13,
        CMN_PARAM_ARROW_FOLLOW = 14,
        CMN_PARAM_BOSS_LOOK = 15,
        CMN_PARAM_BOSS_LOOK_DRA = 16,
        CMN_PARAM_BOSS_LOOK_HDR = 17,
        CMN_PARAM_CATAPULT = 18,
        CMN_PARAM_CMC_TALK = 19,
        CMN_PARAM_GOB_CO_A = 20,
        CMN_PARAM_GRI_CO_A = 21,
        CMN_PARAM_GRI_CO_B = 22,
        CMN_PARAM_GRI_CO_C = 23,
        CMN_PARAM_GRI_CO_D = 24,
        CMN_PARAM_GRI_CO_E = 25,
        CMN_PARAM_PT_CO_A = 26,
        CMN_PARAM_PT_CO_B = 27,
        CMN_PARAM_GRI_SOLO_A = 28,
        CMN_PARAM_GRI_SOLO_B = 29,
        CMN_PARAM_30 = 30,
        CMN_PARAM_31 = 31,
        CMN_PARAM_32 = 32,
        CMN_PARAM_33 = 33,
        CMN_PARAM_DRA3_2 = 34,
        CMN_PARAM_DRA3_1 = 35,
        CMN_PARAM_36 = 36,
        CMN_PARAM_37 = 37,
        CMN_PARAM_RIM_LOOK = 38,
        CMN_PARAM_RIM_CMC0 = 39,
        CMN_PARAM_RIM_CMC1 = 40,
        CMN_PARAM_RIM_CMC2 = 41,
        CMN_PARAM_42 = 42,
        CMN_PARAM_43 = 43,
        CMN_PARAM_44 = 44,
        CMN_PARAM_DROWING = 45,
        CMN_PARAM_HITOMI_EAT = 46,
        CMN_PARAM_47 = 47,
        CMN_PARAM_DRA3_3 = 48,
        CMN_PARAM_49 = 49,
        CMN_PARAM_50 = 50,
        CMN_PARAM_DRA3_4 = 51,
        CMN_PARAM_52 = 52,
        CMN_PARAM_53 = 53,
        CMN_PARAM_54 = 54,
        CMN_PARAM_CLIMB_5800 = 55,
        CMN_PARAM_CLIMB_5000 = 56,
        CMN_PARAM_CLIMB_5400 = 57,
        CMN_PARAM_NML_FAR = 58,
        CMN_PARAM_NML_NEAR = 59,
        CMN_PARAM_CLIMB_5300 = 60,
        CMN_PARAM_CLIMB_5300_00_2 = 61,
        CMN_PARAM_CLIMB_5300_00_3 = 62,
        CMN_PARAM_CLIMB_5300_00_1 = 63,
        CMN_PARAM_CLIMB_5300_00_0 = 64,
        CMN_PARAM_CLIMB_5200 = 65,
        CMN_PARAM_CLIMB_5200_00 = 66,
        CMN_PARAM_CLIMB_5200_01 = 67,
        CMN_PARAM_CLIMB_5100 = 68,
        CMN_PARAM_CLIMB_0900 = 69,
        CMN_PARAM_CLIMB_5500 = 70,
        CMN_PARAM_71 = 71,
        CMN_PARAM_72 = 72,
        CMN_PARAM_CAUGHT_HARPY = 73,
        CMN_PARAM_74 = 74,
        CMN_PARAM_NOTICE_BOARD = 75,
        CMN_PARAM_76 = 76,
        CMN_PARAM_USE_RIDIL = 77,
        CMN_PARAM_PAWN_SCHOOL = 78,
        CMN_PARAM_HUGEBLE_RESTART = 79,
        CMN_PARAM_STONE_DAMAGE = 80,
        CMN_PARAM_PAWN_QUEST_HINT = 81,
        CMN_PARAM_82 = 82,
        CMN_PARAM_DAMAGE = 83,
        CMN_PARAM_84 = 84,
        CMN_PARAM_85 = 85,
        CMN_PARAM_CLIMB_5900 = 86,
        CMN_PARAM_CLIMB_5801 = 87,
        CMN_PARAM_88 = 88,
        CMN_PARAM_89 = 89,
        CMN_PARAM_90 = 90,
        CMN_PARAM_91 = 91,
        CMN_PARAM_92 = 92,
        CMN_PARAM_LOCK_DRAGON = 93,
        CMN_PARAM_94 = 94,
        CMN_PARAM_RIM_PROLOGE = 95,
        CMN_PARAM_RIM_PROLOGE_0 = 96,
        CMN_PARAM_RIM_PROLOGE_1 = 97,
        CMN_PARAM_98 = 98,
        CMN_PARAM_99 = 99,
        CMN_PARAM_HAGAI_FINISH_R = 100,
        CMN_PARAM_HAGAI_FINISH_L = 101,
        CMN_PARAM_TREAD_FINISH_R = 102,
        CMN_PARAM_TREAD_FINISH_L = 103,
    };

    bool scrollCollision(MtVector3& pos0, const MtVector3& pos1, const MtVector3& camVec, const sCollision::Param& param);
    void calcCameraPos(MtVector3& out, const MtVector3& center, f32 angX, f32 angY, f32 dist);
    bool addAnlgAngleMouse(f32& outA, f32 anlg, bool isRev);
    bool clampPadAnlg(f32& anlg, bool isRev);
    bool addAnlgAngleHermite(f32& outA, f32 anlg, f32 maxDeg, bool isRev, f32 fTime, const MtHermiteCurve& curve);
    bool scrollCollisionTarget(MtVector3& now, const MtVector3& old, const sCollision::Param& param);
    bool addAnlgAngle(f32& outA, f32 anlg, f32 maxDeg, bool isRev, f32 fTime);

}  // namespace nCameraGame
