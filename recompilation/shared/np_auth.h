#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
struct SceNpClientId;
struct SceNpOnlineId;

// Declarations
struct SceNpAuthGetAuthorizationCodeParameter;

// Type aliases from DWARF
using _Sizet = long unsigned int;
using size_t = _Sizet;

struct SceNpAuthGetAuthorizationCodeParameter
{
public:
    size_t size;  // offset: 0x0
    const SceNpOnlineId* pOnlineId;  // offset: 0x8
    const SceNpClientId* pClientId;  // offset: 0x10
    const char* pScope;  // offset: 0x18
};
