#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtSynchronize.h"

// Forward declarations
class MtCriticalSection;

// Declarations
class cSoundMeterRms;

// Type aliases from DWARF
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cSoundMeterRms
{
public:
    enum SamplesRMS
    {
        SamplesRMS_10 = 256,
        SamplesRMS_100 = 2560,
        SamplesRMS_300 = 7680,
    };
    enum BlocksRms
    {
        BlocksRms_100 = 11,
        BlocksRms_300 = 31,
    };
public:
    class Volume;
    class VolumeStereo;
    class VolumeSurround51;
public:
    class Volume
    {
    public:
        void floattodB();
    public:
        f32 v;  // offset: 0x0
    };
public:
    class VolumeStereo
    {
    public:
        void floattodB();
    public:
        f32 l;  // offset: 0x0
        f32 r;  // offset: 0x4
    };
public:
    class VolumeSurround51
    {
    public:
        void floattodB();
    public:
        f32 l;  // offset: 0x0
        f32 r;  // offset: 0x4
        f32 c;  // offset: 0x8
        f32 lf;  // offset: 0xc
        f32 ls;  // offset: 0x10
        f32 rs;  // offset: 0x14
    };
public:
    cSoundMeterRms();
    virtual ~cSoundMeterRms();
    u32 getAudioGranularitySamples();
    void initialize(const u8 channels);
    void measure();
    void update(f32* data_ptr, const size_t frames, const u8 channels);
    u8 getChannels() const;
    const Volume& getRmsMono() const;
    const VolumeStereo& getRmsStereo() const;
    const VolumeSurround51& getRmsSurround51() const;
private:
    void incrementIndexUpdating();
    static f32 calcFloat2Decibel(f32 v);
private:
    u8 mChannels;  // offset: 0x8
    size_t mIndexUpdating;  // offset: 0x10
    size_t mFramesResidual;  // offset: 0x18
    f32 mBlocks[186];  // offset: 0x20
    f32 mSummation[6];  // offset: 0x308
    f32 mRms[6];  // offset: 0x320
    Volume mRmsMono;  // offset: 0x338
    VolumeStereo mRmsStereo;  // offset: 0x33c
    VolumeSurround51 mRmsSurround51;  // offset: 0x344
    MtCriticalSection mMutex;  // offset: 0x360
};
