#pragma once

#include <cstdint>
#include <cstddef>

namespace nWeapon {
    enum MODEL_TYPE
    {
        MODEL_TYPE_PRIMARY = 0,
        MODEL_TYPE_SECONDARY = 1,
        MODEL_TYPE_OTHER = 2,
    };
}  // namespace nWeapon

namespace nWeapon {
    enum NPC_ITEM_INDEX
    {
        NPC_ITEM_NONE = 0,
        NPC_ITEM_BUCKET = 1,
        NPC_ITEM_HOE = 2,
        NPC_ITEM_HAMMER = 3,
        NPC_ITEM_FEATHER_PEN = 4,
        NPC_ITEM_WOODEN_BOARD = 5,
        NPC_ITEM_TRAY = 6,
        NPC_ITEM_CUP_1 = 7,
        NPC_ITEM_JUG = 8,
        NPC_ITEM_CUP_2 = 9,
        NPC_ITEM_BLACK_BREAD = 10,
        NPC_ITEM_WHITE_BREAD = 11,
        NPC_ITEM_ROLL = 12,
        NPC_ITEM_MUSICAL_INSTRUMENT = 13,
        NPC_ITEM_VESSEL_OF_LINE = 14,
        NPC_ITEM_HAND_KNIFE = 15,
        NPC_ITEM_CHALICE_EM20402 = 16,
        NPC_ITEM_CHALICE_EM15840 = 17,
        NPC_ITEM_BOOK = 18,
        NPC_ITEM_CHALICE = 19,
        NPC_ITEM_MY_ROOM_BOOK = 20,
        NPC_ITEM_REVERSE_KNIFE = 21,
        NPC_ITEM_PRIMEVAL_DROP = 22,
        NPC_ITEM_NUM = 23,
    };
}  // namespace nWeapon

namespace nWeapon {
    enum OTHER_MODEL_INDEX
    {
        OTHER_MODEL_INDEX_LANTERN = 0,
        OTHER_MODEL_INDEX_RIGHT_HAND = 1,
        OTHER_MODEL_INDEX_LEFT_HAND = 2,
        OTHER_MODEL_INDEX_MUSIC = 3,
        OTHER_MODEL_INDEX_CHALICE_EM20402 = 4,
        OTHER_MODEL_INDEX_CHALICE_EM15840 = 5,
        OTHER_MODEL_INDEX_BOOK = 6,
        OTHER_MODEL_INDEX_HAMMER = 7,
        OTHER_MODEL_INDEX_REVERSE_KNIFE = 8,
        OTHER_MODEL_INDEX_PRIMEVAL_DROP = 9,
        OTHER_MODEL_NUM = 10,
    };
}  // namespace nWeapon

namespace nWeapon {
    enum WEAPON_CATEGORY
    {
        HAND = 0,
        WEPON_CATEGORY_TOP = 1,
        SWORD = 1,
        SHIELD = 2,
        GSWORD = 3,
        SHIELD_L = 4,
        MACE = 5,
        DAGGER = 6,
        BOW = 7,
        GUN = 8,
        BOW_MG = 9,
        QUIVER = 10,
        WAND = 11,
        WAND_DX = 12,
        LANCE = 13,
        WIRE = 14,
        WEAPON_CATEGORY_NUM = 15,
    };
}  // namespace nWeapon

namespace nWeapon {
    enum WPN_CTRL
    {
        WPN_CTRL_DEFAULT = 0,
        WPN_CTRL_HOLD = 1,
        WPN_CTRL_USE_DAMAGE_OFFSET = 2,
        WPN_CTRL_FORCE_DAMAGE_OFFSET = 3,
        WPN_CTRL_DISP = 4,
        WPN_CTRL_SPECIAL_OFFSET = 5,
        WPN_CTRL_NUM = 6,
    };
}  // namespace nWeapon

namespace nWeapon {
    enum WPN_MODEL_INDEX
    {
        WPN_MODEL_MAIN0 = 0,
        WPN_MODEL_SUB0 = 1,
        WPN_MODEL_MAIN1 = 2,
        WPN_MODEL_SUB1 = 3,
        WPN_MODEL_RIGHT = 4,
        WPN_MODEL_LEFT = 5,
        WPN_MODEL_ALL = 9,
    };
}  // namespace nWeapon
