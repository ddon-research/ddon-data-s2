#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtString.h"
#include "nHuman.h"

// Forward declarations
class MtColor;
class MtString;

// Declarations
namespace nGUIExt { struct HeadUiInfo; }
namespace nGUIExt { struct JobParam; }
namespace nGUIExt { class OcdIconInterface; }
namespace nGUIExt { struct OcdIconParam; }
namespace nGUIExt { struct stMsgAnalyzerWork; }
namespace nGUIExt { struct stWindowActive; }

namespace nGUIExt {
    enum BROWSER_RESULT
    {
        BROWSER_RESULT_NONE = 0,
        BROWSER_RESULT_CANCEL = 1,
        BROWSER_RESULT_EXIT = 2,
    };
}  // namespace nGUIExt

namespace nGUIExt {
    enum CHARA_EDIT
    {
        CHARA_EDIT_NONE = 0,
        CHARA_EDIT_PLAYER = 1,
        CHARA_EDIT_PAWN = 2,
        CHARA_EDIT_BEAUTY_PARLOR_PLAYER = 3,
        CHARA_EDIT_BEAUTY_PARLOR_PAWN = 4,
        CHARA_EDIT_MAX = 5,
    };
}  // namespace nGUIExt

namespace nGUIExt {
    enum CUSTOM_SKILL_PALLET
    {
        CUSTOM_SKILL_PALLET_L1 = 0,
        CUSTOM_SKILL_PALLET_L2 = 1,
        CUSTOM_SKILL_PALLET_R1 = 2,
        CUSTOM_SKILL_PALLET_R2 = 3,
        CUSTOM_SKILL_PALLET_NUM = 4,
    };
}  // namespace nGUIExt

namespace nGUIExt {
    enum DAMAGE_UI_MODEL_TYPE
    {
        DAMAGE_UI_MODEL_ME = 0,
        DAMAGE_UI_MODEL_PARTY = 1,
        DAMAGE_UI_MODEL_ENEMY = 2,
        DAMAGE_UI_MODEL_OTHER = 3,
    };
}  // namespace nGUIExt

namespace nGUIExt {
    enum HEAD_UI_TYPE
    {
        HEAD_UI_TYPE_MY_PLAYER = 0,
        HEAD_UI_TYPE_PARTY_MEMBER = 1,
        HEAD_UI_TYPE_HUMAN = 2,
        HEAD_UI_TYPE_ENEMY = 3,
        HEAD_UI_TYPE_NPC = 4,
        HEAD_UI_TYPE_NPC_ATTEND = 5,
        HEAD_UI_TYPE_NPC_SERVICE = 6,
        HEAD_UI_TYPE_OM_SERVICE = 7,
        HEAD_UI_TYPE_OM_TOOL = 8,
        HEAD_UI_TYPE_OM_WARP = 9,
        HEAD_UI_TYPE_OM_KEY_DOOR = 10,
        HEAD_UI_TYPE_OM_WALL = 11,
        HEAD_UI_TYPE_OM_QUEST = 12,
        HEAD_UI_TYPE_OM = 13,
        HEAD_UI_TYPE_OM_HAKURYUU = 14,
        HEAD_UI_TYPE_NUM = 15,
        HEAD_UI_TYPE_INVALID = -1,
    };
}  // namespace nGUIExt

namespace nGUIExt {
    enum ICONTAGKB
    {
        ICONTAGKB_NONE = 0,
        ICONTAGKB_2WAY = 1,
        ICONTAGKB_4WAY = 2,
        ICONTAGKB_MAX = 3,
    };
}  // namespace nGUIExt

namespace nGUIExt {
    enum MSG_REASON
    {
        BTN_START = 0,
        TRG_UP = 0,
        TRG_DOWN = 1,
        TRG_LEFT = 2,
        TRG_RIGHT = 3,
        TRG_DECIDE = 4,
        TRG_CANCEL = 5,
        TRG_CHKOUT = 6,
        TRG_TOPBTN = 7,
        TRG_START = 8,
        TRG_SELECT = 9,
        TRG_LT = 10,
        TRG_RT = 11,
        TRG_LB = 12,
        TRG_RB = 13,
        TRG_L3 = 14,
        TRG_R3 = 15,
        TRG_CHAT = 16,
        BTN_END = 17,
        TRG_AR_UP = 17,
        TRG_AR_DOWN = 18,
        TRG_AR_LEFT = 19,
        TRG_AR_RIGHT = 20,
        BTN_END_EXT = 21,
        KEYBOARD_START = 22,
        KEYBOARD_TAB = 22,
        KEYBOARD_CHAT_CHANNEL_BACK = 23,
        KEYBOARD_CHAT_CHANNEL_NEXT = 24,
        KEYBOARD_CHAT_ADDRESS_BACK = 25,
        KEYBOARD_CHAT_ADDRESS_NEXT = 26,
        KEYBOARD_CHAT_ADDRESS_CLAN = 27,
        KEYBOARD_CHAT_ADDRESS_ENTRYBOARD = 28,
        KEYBOARD_CHAT_ADDRESS_GROUP = 29,
        KEYBOARD_CHAT_ADDRESS_SHOUT = 30,
        KEYBOARD_CHAT_ADDRESS_PARTY = 31,
        KEYBOARD_CHAT_ADDRESS_SAY = 32,
        KEYBOARD_CHAT_ADDRESS_TELL = 33,
        KEYBOARD_END = 34,
        MOUSE_START = 35,
        MOUSE_OUT = 35,
        MOUSE_OVER = 36,
        MOUSE_LCLICK = 37,
        MOUSE_MCLICK = 38,
        MOUSE_DBLCLICK = 39,
        MOUSE_LDRAG = 40,
        MOUSE_MDRAG = 41,
        MOUSE_LDROP = 42,
        MOUSE_MDROP = 43,
        MOUSE_WHEEL_FORWARD = 44,
        MOUSE_WHEEL_BACK = 45,
        MOUSE_END = 46,
        MESSAGE_REASON_MAX = 46,
        NOT_SELECT = 47,
        CLICK_NOT_SELECT = 48,
        CURSOR_NO_MOVE = 49,
        MESSAGE_REASON_SE_MAX = 50,
        NUMBOX_START_DIRECT_BTN = 8,
        NUMBOX_SHORTCUT_BTN = 4,
        MOUSE_DECIDE = 37,
        MOUSE_SELECT = 38,
    };
}  // namespace nGUIExt

namespace nGUIExt {
    enum NAME_TYPE
    {
        NAME_TYPE_FIRST_NONE = 0,
        NAME_TYPE_FIRST_FULL = 1,
        NAME_TYPE_FIRST_INITIAL = 2,
        NAME_TYPE_FIRST_MASK = 15,
        NAME_TYPE_LAST_NONE = 0,
        NAME_TYPE_LAST_FULL = 16,
        NAME_TYPE_LAST_INITIAL = 32,
        NAME_TYPE_LAST_MASK = 240,
        NAME_TYPE_CLAN = 256,
        NAME_TYPE_FULL_FULL = 17,
        NAME_TYPE_FULL_NONE = 1,
        NAME_TYPE_FULL_INITIAL = 33,
        NAME_TYPE_NONE_FULL = 16,
        NAME_TYPE_INITIAL_FULL = 18,
        NAME_TYPE_FULL_FULL_CLAN = 273,
        NAME_TYPE_FULL_NONE_CLAN = 257,
        NAME_TYPE_FULL_INITIAL_CLAN = 289,
        NAME_TYPE_NONE_FULL_CLAN = 272,
        NAME_TYPE_INITIAL_FULL_CLAN = 274,
    };
}  // namespace nGUIExt

namespace nGUIExt {
    enum NG_WORD_TYPE
    {
        NG_WORD_CHAT = 0,
        NG_WORD_NAME = 1,
        NG_WORD_TYPE_NUM = 2,
    };
}  // namespace nGUIExt

namespace nGUIExt {
    enum OCD_ICON_ANIM
    {
        OCD_ICON_ANIM_NONE = 0,
        OCD_ICON_ANIM_ACCUMULATING = 1,
        OCD_ICON_ANIM_OCCURRED = 2,
    };
}  // namespace nGUIExt

namespace nGUIExt {
    enum OCD_ICON_CATEGORY
    {
        OCD_ICON_CATEGORY_GOOD = 0,
        OCD_ICON_CATEGORY_BAD = 1,
        OCD_ICON_CATEGORY_HUMAN = 2,
        OCD_ICON_CATEGORY_NUM = 3,
    };
}  // namespace nGUIExt

namespace nGUIExt {
    enum REQ_DIALOG_TYPE
    {
        DIALOG_TYPE_NORMAL = 0,
        DIALOG_TYPE_NO_BUTTON = 1,
        DIALOG_TYPE_ROW_BUTTON = 2,
    };
}  // namespace nGUIExt

namespace nGUIExt {
    enum TARGET
    {
        TARGET_PLAYER = 0,
        TARGET_PAWN = 1,
    };
}  // namespace nGUIExt

namespace nGUIExt {
    enum WINDOWACTIVE_PRIO
    {
        WINDOWACTIVE_PRIO_DEFAULT = 0,
        WINDOWACTIVE_PRIO_CHATSUBMENU = 1,
        WINDOWACTIVE_PRIO_ERRORDIALOG = 2,
    };
}  // namespace nGUIExt

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using s8 = signed char;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

namespace nGUIExt {
    struct HeadUiInfo
    {
    public:
        u32 mFlags;  // offset: 0x0
        s32 mDistanceH;  // offset: 0x4
        s32 mDistanceV;  // offset: 0x8
        s32 mTranslucentPercent;  // offset: 0xc
        MtColor mNameColor;  // offset: 0x10
        MtColor mNameAmbientColor;  // offset: 0x14
        static const u32 FLAG_NONE = 0;
        static const u32 FLAG_DEPTH_OFF_ALWAYS = 1;
        static const u32 FLAG_DISTANCE_DARK_ADJUST = 256;
    };
}  // namespace nGUIExt

namespace nGUIExt {
    struct JobParam
    {
    public:
        nHuman::JOB_ENUM mJobId;  // offset: 0x0
        u32 mJobNameMsgId;  // offset: 0x4
        u32 mJobInfoMsgId;  // offset: 0x8
        u32 mMainWeaponCategory;  // offset: 0xc
        u32 mSubWeaponCategory;  // offset: 0x10
    };
}  // namespace nGUIExt

namespace nGUIExt {
    class OcdIconInterface
    {
    protected:
        OcdIconInterface();
        virtual ~OcdIconInterface() {}
    public:
        virtual u32 getOcdIconParamNum() const = 0;  // vtable slot 2
        virtual nGUIExt::OCD_ICON_CATEGORY getOcdIconCategory(u32) const = 0;  // vtable slot 3
        virtual nGUIExt::OcdIconParam& refOcdIconParam(u32) = 0;  // vtable slot 4
        virtual bool isOcdActive(u32) const = 0;  // vtable slot 5
        virtual bool isOcdAccumulating(u32) const = 0;  // vtable slot 6
        virtual void setOcdIcon(u32, u32, nGUIExt::OCD_ICON_ANIM, f32) = 0;  // vtable slot 7
    };
}  // namespace nGUIExt

namespace nGUIExt {
    struct OcdIconParam
    {
    public:
        void init();
    public:
        u32 mIndex;  // offset: 0x0
        f32 mFrame;  // offset: 0x4
        u64 mOcdBitmap;  // offset: 0x8
        u64 mAccumulatingOcdBitmap;  // offset: 0x10
        nGUIExt::OCD_ICON_ANIM mIconAnim;  // offset: 0x18
    };
}  // namespace nGUIExt

namespace nGUIExt {
    struct stMsgAnalyzerWork
    {
    public:
        bool mEnable;  // offset: 0x0
        s32 mAnalyzeNum;  // offset: 0x4
        MtString mAnalyzeMsg;  // offset: 0x8
    };
}  // namespace nGUIExt

namespace nGUIExt {
    struct stWindowActive
    {
    public:
        void clear();
        void set(s32, nGUIExt::WINDOWACTIVE_PRIO);
        void set(const nGUIExt::stWindowActive& Window);
        void setMgrNo(s32 MgrNo);
        s32 getMgrNo() const;
        void setPrio(nGUIExt::WINDOWACTIVE_PRIO Prio);
        nGUIExt::WINDOWACTIVE_PRIO getPrio() const;
        bool isInvalid() const;
    public:
        s8 mMgrNo;  // offset: 0x0
        u8 mPrio;  // offset: 0x1
    };
}  // namespace nGUIExt
