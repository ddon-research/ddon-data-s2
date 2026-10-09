#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "_rtc.h"

// Forward declarations
struct SceImeEvent;
struct SceRtcTick;

// Declarations
struct SceImeColor;
struct SceImeKeyboardInfo;
struct SceImeKeyboardParam;
struct SceImeKeycode;
struct SceImeParamExtended;
struct SceImeTextAreaProperty;

enum SceImeEnterLabel
{
    SCE_IME_ENTER_LABEL_DEFAULT = 0,
    SCE_IME_ENTER_LABEL_SEND = 1,
    SCE_IME_ENTER_LABEL_SEARCH = 2,
    SCE_IME_ENTER_LABEL_GO = 3,
};

enum SceImeHorizontalAlignment
{
    SCE_IME_HALIGN_LEFT = 0,
    SCE_IME_HALIGN_CENTER = 1,
    SCE_IME_HALIGN_RIGHT = 2,
};

enum SceImeInputMethod
{
    SCE_IME_INPUT_METHOD_DEFAULT = 0,
};

typedef enum
{
    SCE_IME_KEYBOARD_DEVICE_TYPE_KEYBOARD = 0,
    SCE_IME_KEYBOARD_DEVICE_TYPE_OSK = 1,
} SceImeKeyboardDeviceType;

enum SceImeKeyboardStatus
{
    SCE_IME_KEYBOARD_STATE_DISCONNECTED = 0,
    SCE_IME_KEYBOARD_STATE_CONNECTED = 1,
};

enum SceImeKeyboardType
{
    SCE_IME_KEYBOARD_TYPE_NONE = 0,
    SCE_IME_KEYBOARD_TYPE_DANISH = 1,
    SCE_IME_KEYBOARD_TYPE_GERMAN = 2,
    SCE_IME_KEYBOARD_TYPE_GERMAN_SW = 3,
    SCE_IME_KEYBOARD_TYPE_ENGLISH_US = 4,
    SCE_IME_KEYBOARD_TYPE_ENGLISH_GB = 5,
    SCE_IME_KEYBOARD_TYPE_SPANISH = 6,
    SCE_IME_KEYBOARD_TYPE_SPANISH_LA = 7,
    SCE_IME_KEYBOARD_TYPE_FINNISH = 8,
    SCE_IME_KEYBOARD_TYPE_FRENCH = 9,
    SCE_IME_KEYBOARD_TYPE_FRENCH_BR = 10,
    SCE_IME_KEYBOARD_TYPE_FRENCH_CA = 11,
    SCE_IME_KEYBOARD_TYPE_FRENCH_SW = 12,
    SCE_IME_KEYBOARD_TYPE_ITALIAN = 13,
    SCE_IME_KEYBOARD_TYPE_DUTCH = 14,
    SCE_IME_KEYBOARD_TYPE_NORWEGIAN = 15,
    SCE_IME_KEYBOARD_TYPE_POLISH = 16,
    SCE_IME_KEYBOARD_TYPE_PORTUGUESE_BR = 17,
    SCE_IME_KEYBOARD_TYPE_PORTUGUESE_PT = 18,
    SCE_IME_KEYBOARD_TYPE_RUSSIAN = 19,
    SCE_IME_KEYBOARD_TYPE_SWEDISH = 20,
    SCE_IME_KEYBOARD_TYPE_TURKISH = 21,
    SCE_IME_KEYBOARD_TYPE_JAPANESE_ROMAN = 22,
    SCE_IME_KEYBOARD_TYPE_JAPANESE_KANA = 23,
    SCE_IME_KEYBOARD_TYPE_KOREAN = 24,
    SCE_IME_KEYBOARD_TYPE_SM_CHINESE = 25,
    SCE_IME_KEYBOARD_TYPE_TR_CHINESE_ZY = 26,
    SCE_IME_KEYBOARD_TYPE_TR_CHINESE_PY_HK = 27,
    SCE_IME_KEYBOARD_TYPE_TR_CHINESE_PY_TW = 28,
    SCE_IME_KEYBOARD_TYPE_TR_CHINESE_CG = 29,
    SCE_IME_KEYBOARD_TYPE_ARABIC_AR = 30,
};

enum SceImePanelPriority
{
    SCE_IME_PANEL_PRIORITY_DEFAULT = 0,
    SCE_IME_PANEL_PRIORITY_ALPHABET = 1,
    SCE_IME_PANEL_PRIORITY_SYMBOL = 2,
    SCE_IME_PANEL_PRIORITY_ACCENT = 3,
};

enum SceImeTextAreaMode
{
    SCE_IME_TEXT_AREA_MODE_DISABLE = 0,
    SCE_IME_TEXT_AREA_MODE_EDIT = 1,
    SCE_IME_TEXT_AREA_MODE_PREEDIT = 2,
    SCE_IME_TEXT_AREA_MODE_SELECT = 3,
};

enum SceImeType
{
    SCE_IME_TYPE_DEFAULT = 0,
    SCE_IME_TYPE_BASIC_LATIN = 1,
    SCE_IME_TYPE_URL = 2,
    SCE_IME_TYPE_MAIL = 3,
    SCE_IME_TYPE_NUMBER = 4,
};

enum SceImeVerticalAlignment
{
    SCE_IME_VALIGN_TOP = 0,
    SCE_IME_VALIGN_CENTER = 1,
    SCE_IME_VALIGN_BOTTOM = 2,
};

// Type aliases from DWARF
using SceImeEventHandler = void(*)(void*, const SceImeEvent*);
using __uint16_t = unsigned short;
using uint16_t = __uint16_t;
using __uint32_t = unsigned int;
using uint32_t = __uint32_t;
using SceImeExtKeyboardFilter = int(*)(const SceImeKeycode*, uint16_t*, uint32_t*, void*);
using __int32_t = int;
using int32_t = __int32_t;
using SceUserServiceUserId = int32_t;
using __int8_t = signed char;
using __uint8_t = unsigned char;
using int8_t = __int8_t;
using uint8_t = __uint8_t;

struct SceImeColor
{
public:
    uint8_t r;  // offset: 0x0
    uint8_t g;  // offset: 0x1
    uint8_t b;  // offset: 0x2
    uint8_t a;  // offset: 0x3
};

struct SceImeKeyboardInfo
{
public:
    SceUserServiceUserId userId;  // offset: 0x0
    SceImeKeyboardDeviceType device;  // offset: 0x4
    SceImeKeyboardType type;  // offset: 0x8
    uint32_t repeatDelay;  // offset: 0xc
    uint32_t repeatRate;  // offset: 0x10
    SceImeKeyboardStatus status;  // offset: 0x14
    int8_t reserved[12];  // offset: 0x18
};

struct SceImeKeyboardParam
{
public:
    uint32_t option;  // offset: 0x0
    int8_t reserved1[4];  // offset: 0x4
    void* arg;  // offset: 0x8
    SceImeEventHandler handler;  // offset: 0x10
    int8_t reserved2[8];  // offset: 0x18
};

struct SceImeKeycode
{
public:
    uint16_t keycode;  // offset: 0x0
    wchar_t character;  // offset: 0x2
    uint32_t status;  // offset: 0x4
    SceImeKeyboardType type;  // offset: 0x8
    SceUserServiceUserId userId;  // offset: 0xc
    uint32_t resourceId;  // offset: 0x10
    SceRtcTick timestamp;  // offset: 0x18
};

struct SceImeParamExtended
{
public:
    uint32_t option;  // offset: 0x0
    SceImeColor colorBase;  // offset: 0x4
    SceImeColor colorLine;  // offset: 0x8
    SceImeColor colorTextField;  // offset: 0xc
    SceImeColor colorPreedit;  // offset: 0x10
    SceImeColor colorButtonDefault;  // offset: 0x14
    SceImeColor colorButtonFunction;  // offset: 0x18
    SceImeColor colorButtonSymbol;  // offset: 0x1c
    SceImeColor colorText;  // offset: 0x20
    SceImeColor colorSpecial;  // offset: 0x24
    SceImePanelPriority priority;  // offset: 0x28
    const char* additionalDictionaryPath;  // offset: 0x30
    SceImeExtKeyboardFilter extKeyboardFilter;  // offset: 0x38
    uint32_t disableDevice;  // offset: 0x40
    uint32_t extKeyboardMode;  // offset: 0x44
    int8_t reserved[60];  // offset: 0x48
};

struct SceImeTextAreaProperty
{
public:
    SceImeTextAreaMode mode;  // offset: 0x0
    uint32_t index;  // offset: 0x4
    int32_t length;  // offset: 0x8
};
