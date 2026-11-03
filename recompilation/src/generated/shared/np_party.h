#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "np_npid.h"

// Forward declarations
struct SceNpId;

// Declarations
struct SceNpPartyMemberInfo;
struct SceNpPartyRoomLeftInfo;

// Type aliases from DWARF
using __uint8_t = unsigned char;
using uint8_t = __uint8_t;
using SceNpPartyMemberFlags = uint8_t;
using __uint32_t = unsigned int;
using uint32_t = __uint32_t;
using SceNpPartyRoomLeftReason = uint32_t;
using __uint16_t = unsigned short;
using uint16_t = __uint16_t;
using SceNpPartyRoomMemberId = uint16_t;

struct SceNpPartyMemberInfo
{
public:
    SceNpId npId;  // offset: 0x0
    SceNpPartyRoomMemberId memberId;  // offset: 0x24
    SceNpPartyMemberFlags memberFlags;  // offset: 0x26
    uint8_t reserved;  // offset: 0x27
    uint16_t reserved1;  // offset: 0x28
    uint8_t reserved2[128];  // offset: 0x2a
};

struct SceNpPartyRoomLeftInfo
{
public:
    SceNpPartyRoomMemberId memberId;  // offset: 0x0
    SceNpId npId;  // offset: 0x2
    uint8_t reserved[2];  // offset: 0x26
    SceNpPartyRoomLeftReason reason;  // offset: 0x28
};
