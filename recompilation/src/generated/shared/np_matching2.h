#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
struct SceNpCommunicationId;
struct SceNpCommunicationPassphrase;
struct SceNpId;

// Declarations
struct SceNpMatching2CreateContextParam;

// Type aliases from DWARF
using __uint32_t = unsigned int;
using uint32_t = __uint32_t;
using SceNpServiceLabel = uint32_t;
using _Sizet = long unsigned int;
using size_t = _Sizet;

struct SceNpMatching2CreateContextParam
{
public:
    const SceNpId* npId;  // offset: 0x0
    const SceNpCommunicationId* commId;  // offset: 0x8
    const SceNpCommunicationPassphrase* passPhrase;  // offset: 0x10
    SceNpServiceLabel serviceLabel;  // offset: 0x18
    size_t size;  // offset: 0x20
};
