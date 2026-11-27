#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
struct SceAvPlayerAudioEx;
struct SceAvPlayerFrameInfoEx;
union SceAvPlayerStreamDetailsEx;
struct SceAvPlayerTimedTextEx;
struct SceAvPlayerVideoEx;

// Type aliases from DWARF
using __uint16_t = unsigned short;
using __uint32_t = unsigned int;
using __uint64_t = long unsigned int;
using __uint8_t = unsigned char;
using uint16_t = __uint16_t;
using uint32_t = __uint32_t;
using uint64_t = __uint64_t;
using uint8_t = __uint8_t;

struct SceAvPlayerAudioEx
{
public:
    uint16_t channelCount;  // offset: 0x0
    uint8_t reserved[2];  // offset: 0x2
    uint32_t sampleRate;  // offset: 0x4
    uint32_t size;  // offset: 0x8
    uint8_t languageCode[4];  // offset: 0xc
    uint8_t reserved1[64];  // offset: 0x10
};

struct SceAvPlayerTimedTextEx
{
public:
    uint8_t languageCode[4];  // offset: 0x0
    uint8_t reserved[12];  // offset: 0x4
    uint8_t reserved1[64];  // offset: 0x10
};

struct SceAvPlayerVideoEx
{
public:
    uint32_t width;  // offset: 0x0
    uint32_t height;  // offset: 0x4
    float aspectRatio;  // offset: 0x8
    uint8_t languageCode[4];  // offset: 0xc
    uint32_t framerate;  // offset: 0x10
    uint32_t cropLeftOffset;  // offset: 0x14
    uint32_t cropRightOffset;  // offset: 0x18
    uint32_t cropTopOffset;  // offset: 0x1c
    uint32_t cropBottomOffset;  // offset: 0x20
    uint32_t pitch;  // offset: 0x24
    uint8_t reserved1[40];  // offset: 0x28
};

union SceAvPlayerStreamDetailsEx
{
public:
    SceAvPlayerAudioEx audio;  // offset: 0x0
    SceAvPlayerVideoEx video;  // offset: 0x0
    SceAvPlayerTimedTextEx subs;  // offset: 0x0
    uint8_t reserved1[80];  // offset: 0x0
};

struct SceAvPlayerFrameInfoEx
{
public:
    void* pData;  // offset: 0x0
    uint8_t reserved[4];  // offset: 0x8
    uint64_t timeStamp;  // offset: 0x10
    SceAvPlayerStreamDetailsEx details;  // offset: 0x18
};
