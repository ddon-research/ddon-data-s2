#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
namespace nDraw { struct InputLayouts; }
namespace nDraw { struct SHADER_PARAM; }
namespace nDraw { struct VARIABLE; }
namespace nPS4 { class GeometryShaderObject; }
namespace nPS4 { class PixelShaderObject; }
namespace nPS4 { class VertexShaderObject; }

// Declarations
namespace nDraw { struct OBJECT; }
namespace nDraw { struct SHADER; }
namespace nDraw { struct SHADER_CODE; }
namespace nDraw { struct SHADER_DESC; }
namespace nDraw { struct SHADER_PARAMINFO; }
namespace nDraw { struct SQ_BASE; }

namespace nDraw {
    enum CLASS_TYPE
    {
        CT_UNDEFINED = 0,
        CT_VOID = 1,
        CT_SCALAR = 2,
        CT_VECTOR = 3,
        CT_MATRIX = 4,
        CT_STRUCT = 5,
        CT_OBJECT = 6,
    };
}  // namespace nDraw

namespace nDraw {
    enum DATA_TYPE
    {
        DT_UNDEFINED = 0,
        DT_FLOAT = 1,
        DT_HALF = 2,
        DT_BOOL = 3,
        DT_INT = 4,
        DT_UINT = 5,
        DT_DOUBLE = 6,
        DT_STRING = 7,
        DT_VOID = 8,
    };
}  // namespace nDraw

namespace nDraw {
    enum OBJECT_TYPE
    {
        OT_CBUFFER = 0,
        OT_TEXTURE = 1,
        OT_FUNCTION = 2,
        OT_SAMPLER = 3,
        OT_BLEND = 4,
        OT_DEPTHSTENCIL = 5,
        OT_RASTERIZER = 6,
        OT_TECHNIQUE = 7,
        OT_STRUCT = 8,
        OT_INPUTLAYOUT = 9,
        OT_SAMPLERCMP = 10,
        OT_POINTSTREAM = 11,
        OT_LINESTREAM = 12,
        OT_TRIANGLESTREAM = 13,
        OT_INPUTPATCH = 14,
        OT_OUTPUTPATCH = 15,
    };
}  // namespace nDraw

namespace nDraw {
    enum SHADER_TYPE
    {
        SHADER_VS = 0,
        SHADER_PS = 1,
        SHADER_GS = 2,
        SHADER_HS = 3,
        SHADER_DS = 4,
        SHADER_CS = 5,
        SHADER_ES = 6,
    };
}  // namespace nDraw

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
namespace nDraw { using HComputeShader = void*; }
namespace nDraw { using HDomainShader = void*; }
namespace nDraw { using HGeometryShader = nPS4::GeometryShaderObject*; }
namespace nDraw { using HHullShader = void*; }
namespace nDraw { using HInputLayout = nDraw::InputLayouts*; }
namespace nDraw { using HPixelShader = nPS4::PixelShaderObject*; }
namespace nDraw { using HVertexShader = nPS4::VertexShaderObject*; }
using u32 = unsigned int;

namespace nDraw {
    struct OBJECT
    {
    public:
        MT_CTSTR name;  // offset: 0x0
        MT_CTSTR sname;  // offset: 0x8
        u32 type : 6;  // offset: 0x10
        u32 attr : 16;  // offset: 0x10
        u32 annotation_num : 10;  // offset: 0x10
        u32 sindex : 16;  // offset: 0x14
        u32 index : 16;  // offset: 0x14
        u32 hash;  // offset: 0x18
        u32 padding1;  // offset: 0x1c
        nDraw::VARIABLE* annotations;  // offset: 0x20
    };
}  // namespace nDraw

namespace nDraw {
    struct SHADER_CODE
    {
    public:
        u32 reserved : 1;  // offset: 0x0
        u32 compiled : 1;  // offset: 0x0
        u32 regcount : 8;  // offset: 0x0
        u32 codesize : 22;  // offset: 0x0
        u32 crc;  // offset: 0x4
        void* pcode;  // offset: 0x8
    };
}  // namespace nDraw

namespace nDraw {
    struct SHADER_DESC
    {
    public:
        u32 colorout : 8;  // offset: 0x0
        u32 depthout : 1;  // offset: 0x0
        u32 discard : 1;  // offset: 0x0
        u32 compiled : 1;  // offset: 0x0
        u32 reserved : 21;  // offset: 0x0
        u32 padding;  // offset: 0x4
    };
}  // namespace nDraw

namespace nDraw {
    struct SHADER_PARAMINFO
    {
    public:
        u32 param_num : 8;  // offset: 0x0
        u32 sampler_num : 8;  // offset: 0x0
        u32 texture_num : 8;  // offset: 0x0
        u32 cbuffer_num : 8;  // offset: 0x0
    };
}  // namespace nDraw

namespace nDraw {
    struct SQ_BASE
    {
    public:
        u32 type : 4;  // offset: 0x0
        u32 reserved : 28;  // offset: 0x0
    };
}  // namespace nDraw

namespace nDraw {
    struct SHADER
    {
    public:
        nDraw::SHADER_DESC desc;  // offset: 0x0
        nDraw::SHADER_PARAM* params;  // offset: 0x8
        nDraw::SHADER_PARAMINFO vs_param;  // offset: 0x10
        nDraw::SHADER_PARAMINFO ps_param;  // offset: 0x14
        nDraw::SHADER_PARAMINFO gs_param;  // offset: 0x18
        nDraw::SHADER_PARAMINFO hs_param;  // offset: 0x1c
        nDraw::SHADER_PARAMINFO ds_param;  // offset: 0x20
        nDraw::SHADER_PARAMINFO cs_param;  // offset: 0x24
        nDraw::HVertexShader pvs;  // offset: 0x28
        nDraw::HPixelShader pps;  // offset: 0x30
        nDraw::HGeometryShader pgs;  // offset: 0x38
        nDraw::HHullShader phs;  // offset: 0x40
        nDraw::HDomainShader pds;  // offset: 0x48
        nDraw::HComputeShader pcs;  // offset: 0x50
        nDraw::HInputLayout playout;  // offset: 0x58
        u32* resources;  // offset: 0x60
        u32 resource_num;  // offset: 0x68
        u32 padding;  // offset: 0x6c
    };
}  // namespace nDraw
