#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
namespace nNetMsg { class cDecoder; }
namespace nNetwork { class Coder; }
namespace nNetwork { class Decoder; }
namespace nObjCondition { struct stOcdActiveInfo; }
namespace nObjCondition { struct stOcdActiveMsg; }

// Declarations
namespace nNetMsgData { struct stNetPos; }
namespace nNetMsgData { struct stVector3; }
namespace nNetMsgData { namespace Head { struct stMsgHead; } }

namespace nNetMsgData {
namespace nCtrl {
    enum NET_MSG_ID
    {
        NET_MSG_ID_NOTHING = 0,
        NET_MSG_ID_ACT_BASE = 1,
        NET_MSG_ID_ACT_NORMAL = 2,
        NET_MSG_ID_ACT_NORMAL_EX = 3,
        NET_MSG_ID_ACT_RESET = 4,
        NET_MSG_ID_ACT_RESET_EX = 5,
        NET_MSG_ID_ACT_ACTION_ONLY = 6,
        NET_MSG_ID_ACT_ACTION_ONLY_EX = 7,
        NET_MSG_ID_ACT_SHL_SHOT = 8,
        NET_MSG_ID_ACT_TARGET = 9,
        NET_MSG_ID_ACT_DIE = 10,
        NET_MSG_ID_ACT_ENEMY_CLIMB = 11,
        NET_MSG_ID_ACT_CLIFF_HANG = 12,
        NET_MSG_ID_ACT_BOW = 13,
        NET_MSG_ID_ACT_REVIVE_CMC = 14,
        NET_MSG_ID_ACT_WAND_MAGIC_SHL_SET = 15,
        NET_MSG_ID_ACT_MAGIC_ITEM = 16,
        NET_MSG_ID_ACT_THROW_ITEM = 17,
        NET_MSG_ID_ACT_LIFT_BIGIN_ITEM = 18,
        NET_MSG_ID_ACT_RESPAWN = 19,
        NET_MSG_ID_ACT_WALL_CLIMB = 20,
        NET_MSG_ID_PERIODIC_TOP = 21,
        NET_MSG_ID_PERIODIC_NORMAL = 21,
        NET_MSG_ID_PERIODIC_ANGLE_Y = 22,
        NET_MSG_ID_PERIODIC_POS = 23,
        NET_MSG_ID_PERIODIC_CONDITION = 24,
        NET_MSG_ID_PERIODIC_TARGET = 25,
        NET_MSG_ID_PERIODIC_NOTHING = 26,
        NET_MSG_ID_PERIODIC_CATCH = 27,
        NET_MSG_ID_PERIODIC_ENEMY_CLIMB = 28,
        NET_MSG_ID_PERIODIC_END = 28,
        NET_MSG_ID_PERIODIC_INTERFACE = 29,
        NET_MSG_ID_PERIODIC_BOTTOM = 30,
        NET_MSG_ID_CATCH_REQUEST = 30,
        NET_MSG_ID_CAUGHT_RESULT = 31,
        NET_MSG_ID_ACT_CAUGHT = 32,
        NET_MSG_ID_OM_PUT = 33,
        NET_MSG_ID_OM_THROW = 34,
        NET_MSG_ID_SHL_DELETE = 35,
        NET_MSG_ID_SHL_SHOT = 36,
        NET_MSG_ID_STICK_SHL = 37,
        NET_MSG_SHL_SLAVE_KILL_SEND = 38,
        NET_MSG_SHL_KILL_SYNC = 39,
        NET_MSG_STATE_LIVE = 40,
        NET_MSG_ID_EM5800 = 41,
        NET_MSG_ID_TARGET = 42,
        NET_MSG_ID_SLAVE_DAMAGE = 43,
        NET_MSG_ID_ACT_RESCUE = 44,
        NET_MSG_ID_ACT_RESCUE_ONLY = 45,
        NET_MSG_ID_ENEMYSTATUS_CTRL = 46,
        NET_MSG_ID_ENEMYWAITTING = 47,
        NET_MSG_ID_ENEMYSTARTWAIT = 48,
        NET_MSG_ID_CORE_POINT = 49,
        NET_MSG_ID_CORE_POINT_SLAVE = 50,
        NET_MSG_ID_OCD_HOLY_ABSORP = 51,
        NET_MSG_ID_ACT_DAMAGE = 52,
        NET_MSG_ID_MASTER_PARAM = 53,
        NET_MSG_ID_CUSTOM_SYNC = 54,
        NET_MSG_ID_SERVER_DAMAGE = 55,
        NET_MSG_ID_ACT_CATCH = 56,
        NET_MSG_ID_CS_CHANGE = 57,
        NET_MSG_ID_SOUL_ABSORP = 58,
        NET_MSG_ID_SHL_REQUEST_FROM_SLAVE = 59,
        NET_MSG_ID_NUM = 60,
        NET_MSG_ID_MAX = 127,
        NET_MSG_ID_ACT_LOBBY_OFF = 128,
        NET_MSG_ID_DEFAULT = 255,
        NET_MSG_ID_PERIODIC_DEFAULT = 255,
    };
}  // namespace nCtrl
}  // namespace nNetMsgData

namespace nNetMsgData {
namespace nGame {
    enum NET_MSG_ID_GAME
    {
        NET_MSG_ID_GAME_NOTHING = 0,
        NET_MSG_ID_GAME_STAGE = 1,
        NET_MSG_ID_GAME_REVIVE_STOCK = 2,
        NET_MSG_ID_GAME_PERIOD = 3,
        NET_MSG_ID_GAME_FLAG = 4,
        NET_MSG_ID_GAME_OM = 5,
        NET_MSG_ID_GAME_PAWN_ENTRY_PARTY = 6,
        NET_MSG_ID_GAME_PAWN_MSG = 7,
        NET_MSG_ID_GAME_ENTRY_PARTY = 8,
        NET_MSG_ID_GAME_DROP_ITEM = 9,
        NET_MSG_ID_GAME_SET_EM_DIE = 10,
        NET_MSG_ID_GAME_OPEN_DOOR = 11,
        NET_MSG_ID_GAME_FREEMARKER = 12,
        NET_MSG_ID_GAME_LOST_RETURN_REQ = 13,
        NET_MSG_ID_GAME_PAWN_ORDER = 14,
        NET_MSG_ID_GAME_NUM = 15,
        NET_MSG_ID_GAME_MAX = 127,
    };
}  // namespace nGame
}  // namespace nNetMsgData

namespace nNetMsgData {
namespace nGame {
    enum NET_MSG_ID_GAME_EASY
    {
        NET_MSG_ID_GAME_EASY_NOTHING = 15,
        NET_MSG_ID_GAME_EASY_WEAPON_LOAD = 16,
        NET_MSG_ID_GAME_EASY_PRT_SET = 17,
        NET_MSG_ID_GAME_EASY_PRT_INFO = 18,
        NET_MSG_ID_GAME_EASY_AREA_RELEASE = 19,
        NET_MSG_ID_GAME_EASY_EVENT = 20,
        NET_MSG_ID_GAME_EASY_NPC_MESSAGE = 21,
        NET_MSG_ID_GAME_EASY_AREA_JUMP_SYNC = 22,
        NET_MSG_ID_GAME_EASY_NUM = 23,
    };
}  // namespace nGame
}  // namespace nNetMsgData

namespace nNetMsgData {
namespace nItemMgr {
    enum NET_MSG_ID_ITEM
    {
        NET_MSG_ID_ITEM_NOTHING = 0,
        NET_MSG_ID_ITEM_NUM = 1,
        NET_MSG_ID_ITEM_MAX = 127,
    };
}  // namespace nItemMgr
}  // namespace nNetMsgData

namespace nNetMsgData {
namespace nSetMgr {
    enum NET_MSG_ID_SET
    {
        NET_MSG_ID_SET_NOTHING = 0,
        NET_MSG_ID_SET_BASE = 1,
        NET_MSG_ID_SET_REQUEST_MASTER = 2,
        NET_MSG_ID_SET_CHANGE_MASTER = 3,
        NET_MSG_ID_SET_RELEASE_MASTER = 4,
        NET_MSG_ID_SET_MASTER_INFO = 5,
        NET_MSG_ID_SET_THROW_MASTER = 6,
        NET_MSG_ID_SET_REQUEST_CREATE_CONTEXT = 7,
        NET_MSG_ID_SET_CREATE_CONTEXT = 8,
        NET_MSG_ID_SET_NUM = 9,
        NET_MSG_ID_SET_MAX = 127,
    };
}  // namespace nSetMgr
}  // namespace nNetMsgData

namespace nNetMsgData {
namespace nTool {
    enum NET_MSG_ID_TOOL
    {
        NET_MSG_ID_TOOL_NOTHING = 0,
        NET_MSG_ID_TOOL_BASE = 1,
        NET_MSG_ID_TOOL_PAWN_SET = 2,
        NET_MSG_ID_TOOL_NUM = 3,
        NET_MSG_ID_TOOL_MAX = 127,
    };
}  // namespace nTool
}  // namespace nNetMsgData

namespace nNetMsgData {
namespace nTool {
    enum NET_MSG_ID_TOOL_EASY
    {
        NET_MSG_ID_TOOL_EASY_NOTHING = 3,
        NET_MSG_ID_TOOL_EASY_DIP = 4,
        NET_MSG_ID_TOOL_EASY_DAMAGE_PROFILE_START = 5,
        NET_MSG_ID_TOOL_EASY_DAMAGE_PROFILE_END = 6,
        NET_MSG_ID_TOOL_EASY_DAMAGE_PROFILE_NODE = 7,
        NET_MSG_ID_TOOL_EASY_TEST = 8,
        NET_MSG_ID_TOOL_EASY_NUM = 9,
    };
}  // namespace nTool
}  // namespace nNetMsgData

// Type aliases from DWARF
using f32 = float;
using f64 = double;
using s32 = int;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nNetMsgData {

    enum
    {
        NET_MSG_CHEAT_ERROR = 0,
        NET_MSG_CHEAT_ONE_KILL = 1,
        NET_MSG_CHEAT_BIG_DAMAGE_DEATH = 2,
        NET_MSG_CHEAT_PLAYER_INVISIBLE_HP = 3,
        NET_MSG_CHEAT_HP_ALTER = 4,
        NET_MSG_CHEAT_WARP_PLAYER = 5,
        NET_MSG_CHEAT_POS_ATTRACTED = 6,
        NET_MSG_CHEAT_GOLD_STONE = 7,
        NET_MSG_CHEAT_PLAYER_INVISIBLE_COL = 8,
        NET_MSG_CHEAT_OCD_ALTER = 9,
        NET_MSG_CHEAT_BUY_LOT_LESS_MONEY = 10,
        NET_MSG_CHEAT_INVTYPE_ALTER_PL = 11,
        NET_MSG_CHEAT_INVTYPE_ALTER_EM = 12,
        NET_MSG_CHEAT_INVTYPE_ALTER_GOLD = 13,
        NET_MSG_CHEAT_INVTYPE_ALTER_OTHER = 14,
        NET_MSG_CHEAT_ADD_VELOCITY = 15,
        NET_MSG_CHEAT_MAGIC_BIG_DAMAGE = 16,
        NET_MSG_CHEAT_CHARGE_FAST = 17,
        NET_MSG_CHEAT_DOUBLE_JOIN_MY_PAWN = 97,
        NET_MSG_CHEAT_DOUBLE_JOIN_RENTED_PAWN = 98,
        NET_MSG_CHEAT_CLIENT_TIME_OUT = 99,
    };

    // Forward declarations
    struct stNetPos;
    struct stVector3;

    struct stNetPos
    {
    public:
        f64 x;  // offset: 0x0
        f32 y;  // offset: 0x8
        f64 z;  // offset: 0x10
    };

    struct stVector3
    {
    public:
        f32 x;  // offset: 0x0
        f32 y;  // offset: 0x4
        f32 z;  // offset: 0x8
    };

    void popNetPos(stNetPos& dstPos, nNetMsg::cDecoder& dec);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE/prog/nNetMsgData.cpp:418
    void popNormalPos(stVector3& dstPos, nNetMsg::cDecoder& dec);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE/prog/nNetMsgData.cpp:425
    void* memAlloc(u32 size, u32 align);
    void memFree(void* pMem);
    u32 createIncludePacketCtrl(u32 msgId);
    bool isIncludePacket(u32 bit, u32 includePacket);
    void decomposeOcdActiveMsg(nObjCondition::stOcdActiveInfo& dstInfo, const nObjCondition::stOcdActiveMsg& srcMsg);
    void pop(void* buff, u32 size, nNetMsg::cDecoder& dec);
    void composeOcdActiveMsg(nObjCondition::stOcdActiveMsg& dstMsg, const nObjCondition::stOcdActiveInfo& srcInfo);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE/prog/nNetMsgData.cpp:2748
    u8 getOcdMsgBankMask();  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE/prog/nNetMsgData.cpp:2797
    u8 getOcdMsgActiveMask();  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE/prog/nNetMsgData.cpp:2815

}  // namespace nNetMsgData

namespace nNetMsgData {
    namespace Head {

        // Forward declarations
        struct stMsgHead;

        struct stMsgHead
        {
        public:
            u8 getMsgGroup() const;
            u8 getMsgId() const;
        public:
            s32 mSessionId;  // offset: 0x0
            u32 mRpcId;  // offset: 0x4
            u32 mMsgIdFull;  // offset: 0x8
            u32 mSearchId;  // offset: 0xc
        };

        void serialize(stMsgHead* pHead, nNetwork::Coder& cod);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE/prog/nNetMsgData.cpp:441
        void deserializeCore(stMsgHead* pHead, nNetwork::Decoder& dec);
        stMsgHead* deserialize(nNetwork::Decoder& dec);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE/prog/nNetMsgData.cpp:471
        void freeData(stMsgHead* pData);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE/prog/nNetMsgData.cpp:487

    }  // namespace Head
}  // namespace nNetMsgData
