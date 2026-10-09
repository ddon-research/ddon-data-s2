#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtMath.h"
#include "cResource.h"
#include "nDrawMaterial.h"

// Forward declarations
class MtAllocator;
class MtDTI;
struct MtFloat4;
class MtObject;
class MtStream;
namespace nDraw { class Material; }
namespace nDraw { class Texture; }
class rTexture;

// Declarations
class rMaterial;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;
using SO_HANDLE = u32;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u16 = unsigned short;

class rMaterial : public cResource
{
public:
    class MyDTI;
    struct HEADER;
    struct TEXTURE_INFO;
    struct LUT_INFO;
    struct MATERIAL_INFO;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct HEADER
    {
    public:
        u32 magic;  // offset: 0x0
        u32 version;  // offset: 0x4
        u32 material_num;  // offset: 0x8
        u32 texture_num;  // offset: 0xc
        u32 shader_version;  // offset: 0x10
        u32 padding1;  // offset: 0x14
        rMaterial::TEXTURE_INFO* textures;  // offset: 0x18
        rMaterial::MATERIAL_INFO* materials;  // offset: 0x20
    };
public:
    struct LUT_INFO
    {
    public:
        u32 type;  // offset: 0x0
        u32 format;  // offset: 0x4
        u32 width;  // offset: 0x8
        u32 height;  // offset: 0xc
        f32 min_value;  // offset: 0x10
        f32 max_value;  // offset: 0x14
        f32 param1;  // offset: 0x18
        f32 param2;  // offset: 0x1c
        u16 hermite_x[8];  // offset: 0x20
        u16 hermite_y[8];  // offset: 0x30
    };
public:
    struct MATERIAL_INFO
    {
    public:
        u32 dti;  // offset: 0x0
        u32 padding;  // offset: 0x4
        u32 name;  // offset: 0x8
        u32 state_bufsize;  // offset: 0xc
        SO_HANDLE bsstate;  // offset: 0x10
        SO_HANDLE dsstate;  // offset: 0x14
        SO_HANDLE rsstate;  // offset: 0x18
        u32 state_num : 12;  // offset: 0x1c
        u32 reserved1 : 1;  // offset: 0x1c
        u32 id : 16;  // offset: 0x1c
        u32 fog : 1;  // offset: 0x1c
        u32 tangent : 1;  // offset: 0x1c
        u32 half_lambert : 1;  // offset: 0x1c
        u32 stencil_ref : 8;  // offset: 0x20
        u32 alphatest_ref : 8;  // offset: 0x20
        u32 polygon_offset : 4;  // offset: 0x20
        u32 alphatest : 1;  // offset: 0x20
        u32 alphatest_func : 3;  // offset: 0x20
        u32 draw_pass : 5;  // offset: 0x20
        u32 layer_id : 2;  // offset: 0x20
        u32 deferred_lighting : 1;  // offset: 0x20
        MtFloat4 blend_factor;  // offset: 0x24
        u32 animation_bufsize;  // offset: 0x34
        nDraw::Material::STATE* states;  // offset: 0x38
        nDraw::Animation::ANIMATION_LIST* animation_list;  // offset: 0x40
    };
public:
    struct TEXTURE_INFO
    {
    public:
        u32 dti;  // offset: 0x0
        u32 padding;  // offset: 0x4
        rTexture* ptex;  // offset: 0x8
        nDraw::Texture* plut;  // offset: 0x10
        union
        {
        public:
            MT_CHAR rpath[64];  // offset: 0x0
            rMaterial::LUT_INFO lutinfo;  // offset: 0x0
        };  // offset: 0x18
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
    rMaterial();
    virtual ~rMaterial();
    virtual MT_CTSTR getExt() const;  // vtable slot 7
    virtual void clear();  // vtable slot 15
    virtual bool load(MtStream& in);  // vtable slot 11
    virtual bool loadEnd();  // vtable slot 10
    virtual nDraw::Material* getMaterial(MT_CTSTR name);  // vtable slot 16
    virtual nDraw::Material* getMaterial(u32 index);  // vtable slot 17
    virtual u32 getMaterialNum();  // vtable slot 18
    virtual u32 getTextureNum();  // vtable slot 19
    rTexture* getTextureResource(u32 textureIndex);
    rTexture* getTextureResource(nDraw::Texture* ptex);
    u32 getMaterialIndexFromName(MT_CTSTR name);
    static void createLUT(void* pdst, const LUT_INFO& info);
protected:
    HEADER* mpHeader;  // offset: 0x70
    nDraw::Material* * mpMaterials;  // offset: 0x78
public:
    static MyDTI DTI;
    static const u32 INVALID_INDEX = 2147483647;
protected:
    static const u32 DATA_VERSION = 34;
};
