#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
namespace nDraw { struct SHADER_STATE; }

namespace nDraw {
    enum COMPARISON_FUNC
    {
        CMP_NEVER = 0,
        CMP_LESS = 1,
        CMP_EQUAL = 2,
        CMP_LESS_EQUAL = 3,
        CMP_GREATER = 4,
        CMP_NOT_EQUAL = 5,
        CMP_GREATER_EQUAL = 6,
        CMP_ALWAYS = 7,
    };
}  // namespace nDraw

namespace nDraw {
    enum DRAW_MODE
    {
        MODE_DEFAULT = 1,
        MODE_REFLECTION = 2,
        MODE_SHADOW0_RECV = 4,
        MODE_SHADOW0_CAST = 8,
        MODE_ENV = 16,
        MODE_MOTIONBLUR = 32,
        MODE_SHADOW1_RECV = 256,
        MODE_SHADOW1_CAST = 512,
        MODE_REFRACTION = 2048,
        MODE_OUTLINE = 4096,
        MODE_STATIC_SHADOW = 8192,
        MODE_INDIRECT_LIGHT = 16384,
        MODE_ZPREPASS = 32768,
    };
}  // namespace nDraw

namespace nDraw {
    enum DRAW_VIEW
    {
        VIEW_0 = 0,
        VIEW_1 = 1,
        VIEW_2 = 2,
        VIEW_3 = 3,
        VIEW_4 = 4,
        VIEW_5 = 5,
        VIEW_6 = 6,
        VIEW_7 = 7,
        VIEW_OVERLAY = 8,
        VIEW_COMMON = 9,
        MAX_VIEW = 10,
    };
}  // namespace nDraw

namespace nDraw {
    enum EARLY_STENCIL_CULLING
    {
        EARLY_STENCIL_CULLING_DISABLE = 0,
        EARLY_STENCIL_CULLING_WRITE_ENABLE = 1,
        EARLY_STENCIL_CULLING_TEST_ENABLE = 2,
        MAX_EARLY_STENCIL_CULLING = 3,
    };
}  // namespace nDraw

namespace nDraw {
    enum FEATURE_LV
    {
        FEATURE_LV_CURRENT = -1,
        FEATURE_LV_9_1 = 0,
        FEATURE_LV_9_2 = 1,
        FEATURE_LV_9_3 = 2,
        FEATURE_LV_10_0 = 3,
        FEATURE_LV_10_1 = 4,
        FEATURE_LV_11 = 5,
        FEATURE_LV_360 = 6,
        FEATURE_LV_PS3 = 7,
        FEATURE_LV_LITE = 8,
        FEATURE_LV_VITA = 9,
        FEATURE_LV_CAFE = 10,
        FEATURE_LV_PS4 = 11,
        FEATURE_LV_XB1 = 12,
        __FEATURE_LV__S32 = -2147483647,
    };
}  // namespace nDraw

namespace nDraw {
    enum PASS_TYPE
    {
        PASS_SUBSCENE = 0,
        PASS_BEGIN = 1,
        PASS_BACKFACE_ZPASS = 2,
        PASS_ZPREPASS = 3,
        PASS_GBUFFER = 4,
        PASS_GBUFFER_OVERLAP = 5,
        PASS_LIGHT_MASK = 6,
        PASS_LIGHTING = 7,
        PASS_GBUFFER_TRANS = 8,
        PASS_LIGHTING_TRANS = 9,
        PASS_AMBIENT_MASK = 10,
        PASS_TANGENT = 11,
        PASS_SOLID = 12,
        PASS_ALPHA_MASK = 13,
        PASS_FILL = 14,
        PASS_OVERLAP = 15,
        PASS_WATER = 16,
        PASS_TRANSPARENT = 17,
        PASS_ZPOSTPASS = 18,
        PASS_EFFECT = 19,
        PASS_PREFILTER = 20,
        PASS_DISTORTION = 21,
        PASS_FILTER = 22,
        PASS_SCREEN = 23,
        PASS_END = 24,
        MAX_PASS = 25,
    };
}  // namespace nDraw

namespace nDraw {
    enum PRIMITIVE_TOPOLOGY
    {
        PT_POINTLIST = 0,
        PT_LINELIST = 1,
        PT_LINESTRIP = 2,
        PT_TRIANGLELIST = 3,
        PT_TRIANGLESTRIP = 4,
        PT_LINELIST_ADJ = 5,
        PT_LINESTRIP_ADJ = 6,
        PT_TRIANGLELIST_ADJ = 7,
        PT_TRIANGLESTRIP_ADJ = 8,
        PT_RECTLIST = 9,
        PT_QUADLIST = 10,
        PT_1_CONTROL_POINT_PATCHLIST = 11,
        PT_2_CONTROL_POINT_PATCHLIST = 12,
        PT_3_CONTROL_POINT_PATCHLIST = 13,
        PT_4_CONTROL_POINT_PATCHLIST = 14,
        PT_5_CONTROL_POINT_PATCHLIST = 15,
    };
}  // namespace nDraw

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using u32 = unsigned int;
using uintptr = __uintptr_t;

namespace nDraw {
    struct SHADER_STATE
    {
    public:
        union
        {
        public:
            uintptr ivalue;  // offset: 0x0
            void* pvalue;  // offset: 0x0
        };  // offset: 0x0
        u32 crc;  // offset: 0x8
        u32 padding;  // offset: 0xc
    };
}  // namespace nDraw
