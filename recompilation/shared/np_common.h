#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
struct SceNpAgeRestriction;

// Declarations
struct SceNpAuthorizationCode;
struct SceNpClientId;
struct SceNpContentRestriction;
struct SceNpInvitationId;
struct SceNpParentalControlInfo;
struct SceNpSessionId;
struct SceNpTitleId;
struct SceNpTitleSecret;

enum SceNpGamePresenceStatus
{
    SCE_NP_GAME_PRESENCE_STATUS_OFFLINE = 0,
    SCE_NP_GAME_PRESENCE_STATUS_ONLINE = 1,
};

enum SceNpState
{
    SCE_NP_STATE_UNKNOWN = 0,
    SCE_NP_STATE_SIGNED_OUT = 1,
    SCE_NP_STATE_SIGNED_IN = 2,
};

// Type aliases from DWARF
using _Sizet = long unsigned int;
using __int32_t = int;
using __int8_t = signed char;
using __uint8_t = unsigned char;
using int32_t = __int32_t;
using int8_t = __int8_t;
using size_t = _Sizet;
using uint8_t = __uint8_t;

struct SceNpAuthorizationCode
{
public:
    char code[129];  // offset: 0x0
    uint8_t padding[7];  // offset: 0x81
};

struct SceNpClientId
{
public:
    char id[129];  // offset: 0x0
    uint8_t padding[7];  // offset: 0x81
};

struct SceNpContentRestriction
{
public:
    size_t size;  // offset: 0x0
    int8_t defaultAgeRestriction;  // offset: 0x8
    char padding[3];  // offset: 0x9
    int32_t ageRestrictionCount;  // offset: 0xc
    const SceNpAgeRestriction* ageRestriction;  // offset: 0x10
};

struct SceNpInvitationId
{
public:
    char data[60];  // offset: 0x0
    char term;  // offset: 0x3c
    char padding[3];  // offset: 0x3d
};

struct SceNpParentalControlInfo
{
public:
    bool contentRestriction;  // offset: 0x0
    bool chatRestriction;  // offset: 0x1
    bool ugcRestriction;  // offset: 0x2
};

struct SceNpSessionId
{
public:
    char data[45];  // offset: 0x0
    char term;  // offset: 0x2d
    char padding[2];  // offset: 0x2e
};

struct SceNpTitleId
{
public:
    char id[13];  // offset: 0x0
    uint8_t padding[3];  // offset: 0xd
};

struct SceNpTitleSecret
{
public:
    uint8_t data[128];  // offset: 0x0
};
