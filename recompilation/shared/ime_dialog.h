#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "ime_types.h"

// Declarations
struct SceImeDialogParam;

// Type aliases from DWARF
using __int32_t = int;
using int32_t = __int32_t;
using __uint32_t = unsigned int;
using uint32_t = __uint32_t;
using SceImeTextFilter = int32_t(*)(wchar_t*, uint32_t*, const wchar_t*, uint32_t);
using SceUserServiceUserId = int32_t;
using __int8_t = signed char;
using __uint64_t = long unsigned int;
using int8_t = __int8_t;
using uint64_t = __uint64_t;

struct SceImeDialogParam
{
public:
    SceUserServiceUserId userId;  // offset: 0x0
    SceImeType type;  // offset: 0x4
    uint64_t supportedLanguages;  // offset: 0x8
    SceImeEnterLabel enterLabel;  // offset: 0x10
    SceImeInputMethod inputMethod;  // offset: 0x14
    SceImeTextFilter filter;  // offset: 0x18
    uint32_t option;  // offset: 0x20
    uint32_t maxTextLength;  // offset: 0x24
    wchar_t* inputTextBuffer;  // offset: 0x28
    float posx;  // offset: 0x30
    float posy;  // offset: 0x34
    SceImeHorizontalAlignment horizontalAlignment;  // offset: 0x38
    SceImeVerticalAlignment verticalAlignment;  // offset: 0x3c
    const wchar_t* placeholder;  // offset: 0x40
    const wchar_t* title;  // offset: 0x48
    int8_t reserved[16];  // offset: 0x50
};
