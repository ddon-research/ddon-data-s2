#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "_rtc.h"
#include "np_npid.h"

// Forward declarations
struct SceNpId;
struct SceRtcTick;

// Declarations
struct SceNpScoreComment;
struct SceNpScoreGameInfo;
struct SceNpScorePlayerRankData;
struct SceNpScoreRankData;

// Type aliases from DWARF
using __int32_t = int;
using int32_t = __int32_t;
using SceNpScorePcId = int32_t;
using __uint32_t = unsigned int;
using uint32_t = __uint32_t;
using SceNpScoreRankNumber = uint32_t;
using __int64_t = long int;
using int64_t = __int64_t;
using SceNpScoreValue = int64_t;
using _Sizet = long unsigned int;
using __uint8_t = unsigned char;
using size_t = _Sizet;
using uint8_t = __uint8_t;

struct SceNpScoreComment
{
public:
    char utf8Comment[64];  // offset: 0x0
};

struct SceNpScoreGameInfo
{
public:
    size_t infoSize;  // offset: 0x0
    uint8_t data[189];  // offset: 0x8
    uint8_t pad2[3];  // offset: 0xc5
};

struct SceNpScoreRankData
{
public:
    SceNpId npId;  // offset: 0x0
    uint8_t reserved[49];  // offset: 0x24
    uint8_t pad0[3];  // offset: 0x55
    SceNpScorePcId pcId;  // offset: 0x58
    SceNpScoreRankNumber serialRank;  // offset: 0x5c
    SceNpScoreRankNumber rank;  // offset: 0x60
    SceNpScoreRankNumber highestRank;  // offset: 0x64
    int32_t hasGameData;  // offset: 0x68
    uint8_t pad1[4];  // offset: 0x6c
    SceNpScoreValue scoreValue;  // offset: 0x70
    SceRtcTick recordDate;  // offset: 0x78
};

struct SceNpScorePlayerRankData
{
public:
    int32_t hasData;  // offset: 0x0
    uint8_t pad0[4];  // offset: 0x4
    SceNpScoreRankData rankData;  // offset: 0x8
};
