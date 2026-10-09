#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
struct SceUserServiceLoginUserIdList;

enum SceUserServiceUserColor
{
    SCE_USER_SERVICE_USER_COLOR_BLUE = 0,
    SCE_USER_SERVICE_USER_COLOR_RED = 1,
    SCE_USER_SERVICE_USER_COLOR_GREEN = 2,
    SCE_USER_SERVICE_USER_COLOR_PINK = 3,
};

// Type aliases from DWARF
using __int32_t = int;
using int32_t = __int32_t;
using SceUserServiceUserId = int32_t;

struct SceUserServiceLoginUserIdList
{
public:
    SceUserServiceUserId userId[4];  // offset: 0x0
};
