#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
namespace nStage { struct stEventParam; }
struct stStageSplitData;

namespace nStage {
    enum STG_ZONE
    {
        STG_ZONE_COLOR = 0,
        STG_ZONE_WIND = 1,
        STG_ZONE_GENE = 2,
        STG_ZONE_LIGHT = 3,
        STG_ZONE_NUM = 4,
    };
}  // namespace nStage

// Type aliases from DWARF
using f32 = float;
using s16 = short;
using s32 = int;
using u16 = unsigned short;
using u8 = unsigned char;

namespace nStage {
    struct stEventParam
    {
    public:
        s16 mEventId;  // offset: 0x0
        u16 mType;  // offset: 0x2
        s16 mStartStage;  // offset: 0x4
        s16 mStartPosNo;  // offset: 0x6
        u8 mStartFadeType;  // offset: 0x8
        u8 mEndFadeType;  // offset: 0x9
    };
}  // namespace nStage

struct stStageSplitData
{
public:
    s32 mStageNo;  // offset: 0x0
    f32 mStartPosX;  // offset: 0x4
    f32 mStartPosZ;  // offset: 0x8
    u16 mSplitNumX;  // offset: 0xc
    u16 mSplitNumZ;  // offset: 0xe
    f32 mLengthX;  // offset: 0x10
    f32 mLengthZ;  // offset: 0x14
};
