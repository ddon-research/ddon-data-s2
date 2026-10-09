#pragma once

#include <cstdint>
#include <cstddef>

namespace nUnicode {
    enum CHARACTER_TYPE
    {
        CHARACTER_TYPE_NORMAL = 0,
        CHARACTER_TYPE_SURROGATE_UPPER = 1,
        CHARACTER_TYPE_SURROGATE_LOWER = 2,
    };
}  // namespace nUnicode

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_WCHAR = wchar_t;
using MT_CWSTR = const MT_WCHAR*;
using MT_STR = MT_CHAR*;
using MT_WSTR = MT_WCHAR*;
using u32 = unsigned int;

namespace nUnicode {

    CHARACTER_TYPE GetCharType(MT_WCHAR c);
    u32 GetLength(MT_CWSTR wstr);
    u32 GetCharForwardLength(MT_WCHAR c);
    u32 GetCharBackwardLength(MT_WCHAR c);
    u32 GetBackward(MT_WSTR wstr, u32 wcharIndex);
    u32 DeleteBackward(MT_WSTR wstr, u32 index);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nUnicode.cpp:175
    u32 GetForward(MT_WSTR wstr, u32 wcharIndex);
    u32 DeleteForward(MT_WSTR wstr, u32 wcharIndex);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nUnicode.cpp:202
    u32 AdjustIndex(u32 wcharIndex, MT_CWSTR wstr);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nUnicode.cpp:229
    u32 Copy(MT_WSTR dst, MT_CWSTR src, u32 maxCharacterCount);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nUnicode.cpp:275
    u32 GetCharacterCount(MT_CWSTR wstr, u32 wcharCount);
    u32 GetIndexFromCount(MT_CWSTR wstr, u32 characterCount);
    u32 Insert(MT_WSTR dst, MT_CWSTR src, u32 wcharIndex, u32 maxCharacterCount);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nUnicode.cpp:312
    u32 ConvertUcs16toUtf8(MT_STR dst, MT_CWSTR wsrc, u32 maxCharacterCount);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nUnicode.cpp:377
    u32 ConvertUtf8toUcs16(MT_WSTR wdst, MT_CTSTR src, u32 maxCharacterCount);  // Capcom: D:\publishDDO_PS4_02_02_Master\DDO_02_02\DD_ONLINE\prog/nUnicode.cpp:431

}  // namespace nUnicode
