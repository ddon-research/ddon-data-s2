#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtSynchronize.h"
#include "cSoundEffect.h"

// Forward declarations
class MtCriticalSection;

// Declarations
class cSoundLimitter;

// Type aliases from DWARF
using f32 = float;
using u32 = unsigned int;

class cSoundLimitter : public cSoundEffect
{
public:
    cSoundLimitter();
    virtual ~cSoundLimitter();
    void execute(f32* pBuffer, const u32 sampleNum, const u32 channelNum);
    bool getEnable();
    void setEnable(const bool enable);
    f32 getThreshold();
    void setThreshold(const f32 threshold);
    f32 getOutCeiling();
    void setOutCeiling(const f32 outCeiling);
private:
    void updateParam();
    f32 clamp(const f32 val, const f32 min, const f32 max);
private:
    bool mEnable;  // offset: 0x8
    f32 mThreshold;  // offset: 0xc
    f32 mOutCeiling;  // offset: 0x10
    f32 mThresholdRatio;  // offset: 0x14
    f32 mOutCeilingRatio;  // offset: 0x18
    MtCriticalSection mParamSection;  // offset: 0x20
public:
    static const f32 DEFAULT_THRESHOLD;
    static const f32 MIN_THRESHOLD;
    static const f32 MAX_THRESHOLD;
    static const f32 DEFAULT_OUT_CEILING;
    static const f32 MIN_OUT_CEILING;
    static const f32 MAX_OUT_CEILING;
};
