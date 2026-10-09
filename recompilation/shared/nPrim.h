#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtColor.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
struct MtFloat3;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
namespace nDraw { class Texture; }
class rTexture;

// Declarations
namespace nPrim { struct DepthOrder; }
namespace nPrim { struct Material; }
namespace nPrim { struct MetaDataHeader; }
namespace nPrim { class PrimVertex; }
namespace nPrim { struct TexCoord; }
namespace nPrim { struct Texture; }
namespace nPrim { struct Vertex; }
namespace nPrim { struct VertexFormat; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

namespace nPrim {
    struct DepthOrder
    {
    public:
        DepthOrder();
        nPrim::DepthOrder& operator=(const nPrim::DepthOrder& dd);
        operator unsigned int() const;
        nPrim::DepthOrder& operator=(u32);
    public:
        union
        {
        public:
            struct
            {
            public:
                u32 subpri : 12;  // offset: 0x0
                u32 depth : 15;  // offset: 0x0
                u32 disp_lv : 5;  // offset: 0x0
            };  // offset: 0x0
            struct
            {
            public:
                u32 pri : 27;  // offset: 0x0
                u32 pass : 5;  // offset: 0x0
            };  // offset: 0x0
            u32 order;  // offset: 0x0
        };  // offset: 0x0
    };
}  // namespace nPrim

namespace nPrim {
    struct Material
    {
    public:
        enum AttributeType
        {
            ATTR_REFRACT = 1,
            ATTR_NOREDUCTION = 2,
            ATTR_POINTFILTER = 4,
            ATTR_NOZTEST = 8,
            ATTR_ZWRITE = 16,
            ATTR_OCCLUSION = 32,
            ATTR_NOALPHAWRITE = 64,
            ATTR_LIGHTING = 128,
            ATTR_DEPTHBLEND = 256,
            ATTR_VOLUME = 512,
            ATTR_DEPTHVOLUME = 1024,
            ATTR_PARALLAX = 2048,
            ATTR_NOFOG = 4096,
            ATTR_STEST = 8192,
            ATTR_FRESNEL = 65536,
            ATTR_CULLING = 131072,
            ATTR_NOTONEMAP = 262144,
            ATTR_UVCLAMP = 524288,
            ATTR_EXVOLUME = 1048576,
            ATTR_BLUR = 2097152,
            ATTR_TEXELCOORD = 4194304,
            ATTR_SHADING = 8388608,
            ATTR_ZBLUR = 16777216,
            ATTR_ZBLUREX = 33554432,
            ATTR_DEPTHCOMPARE = 67108864,
            ATTR_CLOUD = 268435456,
            ATTR_LV_CORRECTION = 536870912,
            ATTR_ALPHA_CORRECTION = 1073741824,
            ATTR_LENS_FLARE = -2147483648,
            ATTR_REFRACT_ALPHA = 16777216,
            ATTR_REFRACT_UV = 33554432,
            ATTR_SYMMETRY = 32,
            ATTR_METADATA = -259456864,
            ATTR_DISTORTION = 2097153,
        };
        enum PrimType
        {
            TYPE_POINT = 0,
            TYPE_LINE = 1,
            TYPE_POLYLINE = 2,
            TYPE_POLYGON = 3,
            TYPE_PARTICLE = 4,
            TYPE_SPRITE = 5,
            TYPE_LINE_S = 6,
            TYPE_POLYLINE_S = 7,
            TYPE_2D_POINT = 8,
            TYPE_2D_LINE = 9,
            TYPE_2D_POLYLINE = 10,
            TYPE_2D_POLYGON = 11,
            TYPE_2D_PARTICLE = 12,
            TYPE_2D_SPRITE = 13,
            TYPE_2D_LINE_S = 14,
            TYPE_2D_POLYLINE_S = 15,
            TYPE_MODEL = 16,
            TYPE_CLOUD_BILLBOARD = 17,
            TYPE_CLOUD = 18,
            PRIM_TYPE_MAX = 19,
        };
        enum TransformType
        {
            XFORM_HFLIP = 1,
            XFORM_VFLIP = 2,
            XFORM_LROTATE90 = 4,
        };
    public:
        Material();
        Material(const u64 mat);
        Material(u32 bs, u32 attr, u32 trans);
        operator unsigned long() const;
        nPrim::Material& operator=(const u64);
        nPrim::Material& operator=(const nPrim::Material& mat);
        bool operator==(const nPrim::Material&) const;
        bool operator!=(const nPrim::Material&) const;
        void enableAttribute(u32 attr);
        void disableAttribute(u32 attr);
    public:
        union
        {
        public:
            struct
            {
            public:
                u32 type : 5;  // offset: 0x0
                u32 bs_idx : 11;  // offset: 0x0
                u32 tex_handle : 10;  // offset: 0x0
                u32 transform : 4;  // offset: 0x0
                u32 pad : 2;  // offset: 0x0
                u32 attribute;  // offset: 0x4
            };  // offset: 0x0
            u64 data;  // offset: 0x0
        };  // offset: 0x0
        static nPrim::Material Default;
        static nPrim::Material NoZTest;
        static nPrim::Material AlphaBlend;
        static nPrim::Material AddAlpha;
    };
}  // namespace nPrim

namespace nPrim {
    struct MetaDataHeader
    {
    public:
        MetaDataHeader();
        nPrim::MetaDataHeader& operator=(const nPrim::MetaDataHeader& data);
        bool operator==(const nPrim::MetaDataHeader&);
        void clear();
    public:
        void* p_data[8];  // offset: 0x0
    };
}  // namespace nPrim

namespace nPrim {
    class PrimVertex : public ::MtObject
    {
    public:
        enum AvailableAttr
        {
            ENABLE_POS = 1,
            ENABLE_COL = 2,
            ENABLE_SCALE = 4,
            ENABLE_HDRI = 8,
            ENABLE_BINORM = 16,
            ENABLE_UV = 32,
            ENABLE_NORM = 64,
            ENABLE_TANGENT = 128,
            ENABLE_ALL = -1,
        };
    public:
        class MyDTI;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        static void usage();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        PrimVertex(u32 attr_flag);
        PrimVertex(const nPrim::Vertex&, u32);
        // Address: 0x01b82c00 - 0x01b82c01 (1 bytes)
        virtual ~PrimVertex() {}
        nPrim::PrimVertex& operator=(const nPrim::Vertex& vv);
        nPrim::PrimVertex& operator=(const nPrim::PrimVertex& vv);
        nPrim::Vertex getVertex() const;
        virtual void createProperty(MtPropertyList& prop_list);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        MtFloat3 pos;  // offset: 0x8
        MtColor col;  // offset: 0x14
        f32 scale;  // offset: 0x18
        u32 hdr_intensity;  // offset: 0x1c
        u32 binormal;  // offset: 0x20
        u32 reserved;  // offset: 0x24
        f32 tex_u;  // offset: 0x28
        f32 tex_v;  // offset: 0x2c
        MtVector3 normal;  // offset: 0x30
        MtVector3 tangent;  // offset: 0x40
        u32 attr;  // offset: 0x50
        static MyDTI DTI;
    };
}  // namespace nPrim

namespace nPrim {
    struct TexCoord
    {
    public:
        TexCoord();
        TexCoord(const nPrim::TexCoord& tc);
        TexCoord(f32 uu, f32 vv);
        TexCoord(rTexture*, s32, s32);
        nPrim::TexCoord operator+() const;
        nPrim::TexCoord operator-() const;
        nPrim::TexCoord& operator+=(const nPrim::TexCoord&);
        nPrim::TexCoord& operator+=(f32);
        nPrim::TexCoord& operator-=(const nPrim::TexCoord&);
        nPrim::TexCoord& operator-=(f32);
        nPrim::TexCoord& operator*=(const nPrim::TexCoord&);
        nPrim::TexCoord& operator*=(f32);
        nPrim::TexCoord operator+(const nPrim::TexCoord&) const;
        nPrim::TexCoord operator+(f32) const;
        nPrim::TexCoord operator-(const nPrim::TexCoord&) const;
        nPrim::TexCoord operator-(f32) const;
        nPrim::TexCoord operator*(const nPrim::TexCoord&) const;
        nPrim::TexCoord operator*(f32) const;
    public:
        f32 u;  // offset: 0x0
        f32 v;  // offset: 0x4
    };
}  // namespace nPrim

namespace nPrim {
    struct Texture
    {
    public:
        enum TextureFlags
        {
            RESOURCE_TEXBASE = 1,
            RESOURCE_TEXTURE = 2,
            RESOURCE_NORMAL = 4,
            RESOURCE_MASK = 8,
            RESOURCE_ALPHA = 16,
        };
    public:
        Texture();
        Texture(rTexture* base, rTexture* normal, rTexture* mask, rTexture* alpha);
        Texture(nDraw::Texture* texbase, rTexture* normal, rTexture* mask, rTexture* alpha);
        Texture(const nPrim::Texture&);
        bool operator==(const nPrim::Texture& tex);
    public:
        u32 flags;  // offset: 0x0
        union
        {
        public:
            rTexture* p_base;  // offset: 0x0
            nDraw::Texture* p_texbase;  // offset: 0x0
            void* ptr;  // offset: 0x0
        };  // offset: 0x8
        rTexture* p_normal;  // offset: 0x10
        rTexture* p_mask;  // offset: 0x18
        rTexture* p_alpha;  // offset: 0x20
    };
}  // namespace nPrim

namespace nPrim {
    struct Vertex
    {
    public:
        Vertex();
        Vertex(const MtFloat3&);
        Vertex(const MtFloat3& ipos, const MtColor& icolor);
        Vertex(const MtFloat3&, const MtColor&, const nPrim::TexCoord&);
        Vertex(const MtFloat3&, const MtColor&, const nPrim::TexCoord&, f32);
        Vertex(const MtFloat3& ipos, const MtColor& icolor, const nPrim::TexCoord& uv, f32 iscale, u32 ihdr_intensity);
        Vertex(const MtFloat3& ipos, const MtColor& icolor, const nPrim::TexCoord& uv, f32 iscale, u32 ihdr_intensity, const MtVector3& inormal, const MtVector3& itangent);
    public:
        MtFloat3 pos;  // offset: 0x0
        MtColor col;  // offset: 0xc
        f32 scale;  // offset: 0x10
        u32 hdr_intensity : 16;  // offset: 0x14
        u32 binormal : 8;  // offset: 0x14
        u32 reserved : 8;  // offset: 0x14
        nPrim::TexCoord tex_coord;  // offset: 0x18
        MtVector3 normal;  // offset: 0x20
        MtVector3 tangent;  // offset: 0x30
    };
}  // namespace nPrim

namespace nPrim {
    struct VertexFormat
    {
    public:
        MtFloat3 pos;  // offset: 0x0
        u32 color;  // offset: 0xc
        s32 u : 16;  // offset: 0x10
        s32 v : 16;  // offset: 0x10
        u32 zofs : 16;  // offset: 0x14
        u32 intensity : 16;  // offset: 0x14
        union
        {
        public:
            struct
            {
            public:
                u32 spr_scale : 16;  // offset: 0x0
                u32 spr_rot : 16;  // offset: 0x0
                u32 spr_w : 8;  // offset: 0x4
                u32 spr_h : 8;  // offset: 0x4
                u32 spr_aspect_ratio : 8;  // offset: 0x4
                u32 spr_volume : 8;  // offset: 0x4
            };  // offset: 0x0
            struct
            {
            public:
                u32 nt_spr_rot : 16;  // offset: 0x0
                u32 nt_spr_w : 16;  // offset: 0x0
                u32 nt_spr_h : 16;  // offset: 0x4
                u32 nt_spr_volume : 16;  // offset: 0x4
            };  // offset: 0x0
            struct
            {
            public:
                u32 polyline_w : 16;  // offset: 0x0
                u32 polyline_reserved : 16;  // offset: 0x0
                u32 polyline_tangent_x : 8;  // offset: 0x4
                u32 polyline_tangent_y : 8;  // offset: 0x4
                u32 polyline_tangent_z : 8;  // offset: 0x4
                u32 polyline_volume : 8;  // offset: 0x4
            };  // offset: 0x0
            struct
            {
            public:
                u32 poly_normal_x : 8;  // offset: 0x0
                u32 poly_normal_y : 8;  // offset: 0x0
                u32 poly_normal_z : 8;  // offset: 0x0
                u32 poly_binormal : 8;  // offset: 0x0
                u32 poly_tangent_x : 8;  // offset: 0x4
                u32 poly_tangent_y : 8;  // offset: 0x4
                u32 poly_tangent_z : 8;  // offset: 0x4
                u32 poly_volume : 8;  // offset: 0x4
            };  // offset: 0x0
        };  // offset: 0x18
    };
}  // namespace nPrim
