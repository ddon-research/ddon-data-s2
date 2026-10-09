#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
namespace nKeyCommand { struct stGenericParam; }
namespace nKeyCommand { struct stKeyCommand; }
namespace nKeyCommand { struct stKeyCommandForFunction; }

namespace nKeyCommand {
    enum KEY_CMD_FUNC_SP
    {
        CND_SP_NONE = -1,
        CND_SP_LIMITED_HEAL_CIRCLE_ACT = 0,
        CND_SP_LIMITED_CLIMB_HEAL_CIRCLE_ACT = 1,
        CND_SP_LIMITED_ATTACK_CIRCLE = 2,
        CND_SP_LIMITED_DEFENCE_CIRCLE = 3,
        CND_SP_LIMITED_GUARD_BIT = 4,
        CND_SP_LIMITED_SOUL_FULL = 5,
        CND_SP_LIMITED_IRON_FIELD = 6,
        CND_SP_LIMITED_SAINT_CIRCLE = 7,
        CND_SP_LIMITED_CLIMB_SAINT_CIRCLE = 8,
        CND_SP_ENABLE_TRANS_UKEMI_ACT = 9,
        CND_SP_JOB02_CS11_END = 10,
        CND_SP_ALL_DELEATE_CIRCLE = 11,
        CND_SP_LIMITED_SOLACE_CIRCLE = 12,
        CND_SP_LIMITED_BLAST_OPTION = 13,
        CND_SP_CANT_BOOST_SPIRIT = 14,
        CND_SP_IS_NOW_BOOSTING = 15,
        CND_SP_MAX = 16,
    };
}  // namespace nKeyCommand

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using s32 = int;
using u32 = unsigned int;
using u64 = __uint64_t;

namespace nKeyCommand {
    struct stGenericParam
    {
    public:
        s32 mS32Value;  // offset: 0x0
    };
}  // namespace nKeyCommand

namespace nKeyCommand {
    struct stKeyCommand
    {
    public:
        u32 mActionNo;  // offset: 0x0
        u32 mLastActionNo;  // offset: 0x4
        u32 mInputType;  // offset: 0x8
        u32 mPressType;  // offset: 0xc
        u32 mMoveType;  // offset: 0x10
        u64 mObjStatus;  // offset: 0x18
        u64 mObjStatusNone;  // offset: 0x20
        u32 mCancelSequence;  // offset: 0x28
        u32 mReserveCancelSequence;  // offset: 0x2c
        u32 mAttr;  // offset: 0x30
        u32 mCondition;  // offset: 0x34
        u32 mSpInputType;  // offset: 0x38
        s32 mCustomSkillID;  // offset: 0x3c
        bool mIsEnableMenuUI;  // offset: 0x40
    };
}  // namespace nKeyCommand

namespace nKeyCommand {
    struct stKeyCommandForFunction
    {
    public:
        s32 mFunctionNo;  // offset: 0x0
        u32 mInputType;  // offset: 0x4
        u32 mPressType;  // offset: 0x8
        nKeyCommand::KEY_CMD_FUNC_SP mCondition;  // offset: 0xc
        s32 mCustomSkillID;  // offset: 0x10
    };
}  // namespace nKeyCommand
