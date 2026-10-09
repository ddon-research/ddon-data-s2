#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtSynchronize.h"
#include "cSoundEffect.h"

// Forward declarations
class MtCriticalSection;

// Declarations
class cSoundCompressor;

// Type aliases from DWARF
using f32 = float;
using u32 = unsigned int;

class alignas(16) cSoundCompressor : public cSoundEffect
{
public:
    cSoundCompressor();
    virtual ~cSoundCompressor();
    void execute(f32* pBuffer, const u32 sampleNum, const u32 channelNum);
    bool getEnable();
    void setEnable(const bool enable);
    f32 getThreshold();
    void setThreshold(const f32 threshold);
    f32 getRatio();
    void setRatio(const f32 ratio);
    f32 getAttackTime();
    void setAttackTime(const f32 attackTime);
    f32 getReleaseTime();
    void setReleaseTime(const f32 releaseTime);
    f32 getPostGain();
    void setPostGain(const f32 postGain);
private:
    void initBuffer();
    void releaseBuffer();
    void updateParam();
    f32 getPeak(f32* pBuffer, const u32 sampleNum, const u32 channelNum);
    f32 clamp(const f32 val, const f32 min, const f32 max);
private:
    bool mIsInitialize;  // offset: 0x8
    bool mEnable;  // offset: 0x9
    f32 mThreshold;  // offset: 0xc
    f32 mRatio;  // offset: 0x10
    f32 mAttackTime;  // offset: 0x14
    f32 mReleaseTime;  // offset: 0x18
    f32 mPostGain;  // offset: 0x1c
    f32 mThresholdRatio;  // offset: 0x20
    f32 mAttackDelta;  // offset: 0x24
    f32 mReleaseDelta;  // offset: 0x28
    f32 mEnvelope;  // offset: 0x2c
    f32 mPostGainRatio;  // offset: 0x30
    f32 mPeak;  // offset: 0x34
    f32* mpLookaheadBuffer;  // offset: 0x38
    u32 mLookaheadBufferPos;  // offset: 0x40
    u32 mCalcGainSkipCount;  // offset: 0x44
    f32 mGain;  // offset: 0x48
    alignas(8) f32 mGainArray[32];  // offset: 0x50
    MtCriticalSection mParamSection;  // offset: 0xd0
public:
    static const f32 DEFAULT_THRESHOLD;
    static const f32 MIN_THRESHOLD;
    static const f32 MAX_THRESHOLD;
    static const f32 DEFAULT_RATIO;
    static const f32 MIN_RATIO;
    static const f32 MAX_RATIO;
    static const f32 DEFAULT_ATTACK_TIME;
    static const f32 MIN_ATTACK_TIME;
    static const f32 MAX_ATTACK_TIME;
    static const f32 DEFAULT_RELEASE_TIME;
    static const f32 MIN_RELEASE_TIME;
    static const f32 MAX_RELEASE_TIME;
    static const f32 DEFAULT_POST_GAIN;
    static const f32 MIN_POST_GAIN;
    static const f32 MAX_POST_GAIN;
private:
    static const u32 MAX_CHANNEL_NUM = 8;
    static const u32 LOOKAHEAD_SAMPLES = 256;
    static const u32 LOOKAHEAD_BUFFER_SIZE = 8192;
    static const u32 CALC_GAIN_SKIP_COUNT = 8;
};
