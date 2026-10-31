#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class cSoundMeterRms;

// Declarations
class cSoundSilentDetectFilter;

// Type aliases from DWARF
using f32 = float;
using u32 = unsigned int;

class cSoundSilentDetectFilter
{
public:
    cSoundSilentDetectFilter();
    virtual ~cSoundSilentDetectFilter();
    void init(const bool enable, const u32 channelNum);
    void executeProcess(f32* pData, const u32 frames, const u32 channels);
    bool isEnable();
    u32 getAudioGranularitySamples();
    bool isSilent(f32 threshold);
private:
    bool mEnable;  // offset: 0x8
    bool mIsInitialize;  // offset: 0x9
    u32 mChannelNum;  // offset: 0xc
    cSoundMeterRms* mpRms300;  // offset: 0x10
};
