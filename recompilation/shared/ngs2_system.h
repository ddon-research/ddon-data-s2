#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
struct SceNgs2ContextBufferInfo;
struct SceNgs2UserFxProcessContext;
struct SceNgs2WaveformBlock;
struct SceNgs2WaveformFormat;
struct SceNgs2WaveformInfo;

// Type aliases from DWARF
using _Sizet = long unsigned int;
using __uint32_t = unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using size_t = _Sizet;
using uint32_t = __uint32_t;
using uintptr_t = __uintptr_t;

struct SceNgs2ContextBufferInfo
{
public:
    void* hostBuffer;  // offset: 0x0
    size_t hostBufferSize;  // offset: 0x8
    uintptr_t reserved[5];  // offset: 0x10
    uintptr_t userData;  // offset: 0x38
};

struct SceNgs2UserFxProcessContext
{
public:
    float* * aChannelData;  // offset: 0x0
    uintptr_t userData0;  // offset: 0x8
    uintptr_t userData1;  // offset: 0x10
    uintptr_t userData2;  // offset: 0x18
    uint32_t flags;  // offset: 0x20
    uint32_t numChannels;  // offset: 0x24
    uint32_t numGrainSamples;  // offset: 0x28
    uint32_t sampleRate;  // offset: 0x2c
};

struct SceNgs2WaveformBlock
{
public:
    uint32_t dataOffset;  // offset: 0x0
    uint32_t dataSize;  // offset: 0x4
    uint32_t numRepeats;  // offset: 0x8
    uint32_t numSkipSamples;  // offset: 0xc
    uint32_t numSamples;  // offset: 0x10
    uint32_t reserved;  // offset: 0x14
    uintptr_t userData;  // offset: 0x18
};

struct SceNgs2WaveformFormat
{
public:
    uint32_t waveformType;  // offset: 0x0
    uint32_t numChannels;  // offset: 0x4
    uint32_t sampleRate;  // offset: 0x8
    uint32_t configData;  // offset: 0xc
    uint32_t frameOffset;  // offset: 0x10
    uint32_t frameMargin;  // offset: 0x14
};

struct SceNgs2WaveformInfo
{
public:
    SceNgs2WaveformFormat format;  // offset: 0x0
    uint32_t dataOffset;  // offset: 0x18
    uint32_t dataSize;  // offset: 0x1c
    uint32_t loopBeginPosition;  // offset: 0x20
    uint32_t loopEndPosition;  // offset: 0x24
    uint32_t numSamples;  // offset: 0x28
    uint32_t audioUnitSize;  // offset: 0x2c
    uint32_t numAudioUnitSamples;  // offset: 0x30
    uint32_t numAudioUnitPerFrame;  // offset: 0x34
    uint32_t audioFrameSize;  // offset: 0x38
    uint32_t numAudioFrameSamples;  // offset: 0x3c
    uint32_t numDelaySamples;  // offset: 0x40
    uint32_t numBlocks;  // offset: 0x44
    SceNgs2WaveformBlock aBlock[4];  // offset: 0x48
};
