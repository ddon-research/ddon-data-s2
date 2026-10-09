#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "dataformats.h"
#include "nDrawBuffer.h"
#include "nDrawResource.h"
#include "rendertarget.h"
#include "texture.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtRect;
class MtSize;
class MtUI;
namespace nDraw { class DepthStencilView; }
namespace nDraw { struct MAPPED_TEXTURE; }
namespace sce { namespace Gnm { class DataFormat; } }
namespace sce { namespace Gnm { class RenderTarget; } }
namespace sce { namespace Gnm { class Texture; } }

// Declarations
namespace nDraw { class RenderTargetView; }
namespace nDraw { class Texture; }

namespace nDraw {
    enum FORMAT_TYPE
    {
        FORMAT_UNKNOWN = 0,
        FORMAT_R32G32B32A32_FLOAT = 1,
        FORMAT_R16G16B16A16_FLOAT = 2,
        FORMAT_R16G16B16A16_UNORM = 3,
        FORMAT_R16G16B16A16_SNORM = 4,
        FORMAT_R32G32_FLOAT = 5,
        FORMAT_R10G10B10A2_UNORM = 6,
        FORMAT_R8G8B8A8_UNORM = 7,
        FORMAT_R8G8B8A8_SNORM = 8,
        FORMAT_R8G8B8A8_UNORM_SRGB = 9,
        FORMAT_B4G4R4A4_UNORM = 10,
        FORMAT_R16G16_FLOAT = 11,
        FORMAT_R16G16_UNORM = 12,
        FORMAT_R16G16_SNORM = 13,
        FORMAT_R32_FLOAT = 14,
        FORMAT_D24_UNORM_S8_UINT = 15,
        FORMAT_R16_FLOAT = 16,
        FORMAT_R16_UNORM = 17,
        FORMAT_A8_UNORM = 18,
        FORMAT_BC1_UNORM = 19,
        FORMAT_BC1_UNORM_SRGB = 20,
        FORMAT_BC2_UNORM = 21,
        FORMAT_BC2_UNORM_SRGB = 22,
        FORMAT_BC3_UNORM = 23,
        FORMAT_BC3_UNORM_SRGB = 24,
        FORMAT_BCX_GRAYSCALE = 25,
        FORMAT_BCX_ALPHA = 26,
        FORMAT_BC5_SNORM = 27,
        FORMAT_B5G6R5_UNORM = 28,
        FORMAT_B5G5R5A1_UNORM = 29,
        FORMAT_BCX_NM1 = 30,
        FORMAT_BCX_NM2 = 31,
        FORMAT_BCX_RGBI = 32,
        FORMAT_BCX_RGBY = 33,
        FORMAT_B8G8R8X8_UNORM = 34,
        FORMAT_BCX_RGBI_SRGB = 35,
        FORMAT_BCX_RGBY_SRGB = 36,
        FORMAT_BCX_NH = 37,
        FORMAT_R11G11B10_FLOAT = 38,
        FORMAT_B8G8R8A8_UNORM = 39,
        FORMAT_B8G8R8A8_UNORM_SRGB = 40,
        FORMAT_BCX_RGBNL = 41,
        FORMAT_BCX_YCCA = 42,
        FORMAT_BCX_YCCA_SRGB = 43,
        FORMAT_R8_UNORM = 44,
        FORMAT_B8G8R8A8_UNORM_LE = 45,
        FORMAT_B10G10R10A2_UNORM_LE = 46,
        FORMAT_BCX_SRGBA = 47,
        FORMAT_BC7_UNORM = 48,
        FORMAT_BC7_UNORM_SRGB = 49,
        FORMAT_SE5M9M9M9 = 50,
        FORMAT_R10G10B10A2_FLOAT = 51,
        FORMAT_YVU420P2_CSC1 = 52,
        FORMAT_R8A8_UNORM = 53,
        FORMAT_A8_UNORM_WHITE = 54,
    };
}  // namespace nDraw

namespace nDraw {
    enum TEXMEMORY_TYPE
    {
        TEXMEMORY_NONE = 1,
        TEXMEMORY_VRAMorHOST = 2,
        TEXMEMORY_VRAM = 16,
        TEXMEMORY_HOST = 32,
        FORCE_TEXMEMORY_TYPE_SIZE = 255,
    };
}  // namespace nDraw

namespace nDraw {
    enum TEXTURE_TYPE
    {
        TT_UNDEFINED = 0,
        TT_1D = 1,
        TT_2D = 2,
        TT_3D = 3,
        TT_1DARRAY = 4,
        TT_2DARRAY = 5,
        TT_CUBE = 6,
        TT_CUBEARRAY = 7,
        TT_2DMS = 8,
        TT_2DMSARRAY = 9,
    };
}  // namespace nDraw

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
namespace nDraw { using GPUFORMAT_TYPE = sce::Gnm::DataFormat; }
namespace nDraw { using HRenderTarget = sce::Gnm::RenderTarget*; }
namespace nDraw { using HTexture = sce::Gnm::Texture*; }
using size_t = _Sizet;
using u32 = unsigned int;

namespace nDraw {
    class RenderTargetView : public nDraw::Resource
    {
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
        RenderTargetView(nDraw::Texture* ptex, u32 subresource);
        RenderTargetView(nDraw::HRenderTarget prendertarget, const MtSize& sz);
        virtual ~RenderTargetView();
        nDraw::HRenderTarget getHandle() const;
        u32 getWidth() const;
        u32 getHeight() const;
        u32 getMiscFlags() const;
        nDraw::Texture* getTexture() const;
        u32 getSubResource() const;
        nDraw::GPUFORMAT_TYPE getGPUFormat() const;
        void* getSurfaceAddress() const;
        bool isSRGB() const;
    protected:
        nDraw::Texture* mpTexture;  // offset: 0x18
        nDraw::HRenderTarget mpHandle;  // offset: 0x20
        u32 mWidth : 16;  // offset: 0x28
        u32 mHeight : 15;  // offset: 0x28
        u32 mSRGB : 1;  // offset: 0x28
        u32 mSubResource;  // offset: 0x2c
        u32 mMiscFlags;  // offset: 0x30
        nDraw::GPUFORMAT_TYPE mGPUFormatType;  // offset: 0x34
        sce::Gnm::RenderTarget mRenderTarget;  // offset: 0x38
        void* mpSurfaceAddress;  // offset: 0x68
    public:
        static MyDTI DTI;
    };
}  // namespace nDraw

namespace nDraw {
    class Texture : public nDraw::Buffer
    {
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
        Texture();
        Texture(u32 w, u32 miplevels, u32 arraysize, nDraw::FORMAT_TYPE fmt, nDraw::USAGE_TYPE usage, u32 misc_flags, nDraw::Texture* psharedtex, u32 share_offset, void* pinitvalues, nDraw::TEXMEMORY_TYPE memtype);
        Texture(u32 w, u32 h, u32 miplevels, u32 arraysize, nDraw::FORMAT_TYPE fmt, nDraw::USAGE_TYPE usage, u32 misc_flags, nDraw::Texture* psharedtex, u32 share_offset, void* pinitvalues, nDraw::TEXMEMORY_TYPE memtype);
        Texture(u32 w, u32 h, u32 d, u32 miplevels, u32 arraysize, nDraw::FORMAT_TYPE fmt, nDraw::USAGE_TYPE usage, u32 misc_flags, nDraw::Texture* psharedtex, u32 share_offset, void* pinitvalues);
        Texture(MT_CTSTR pool, MT_CTSTR name, u32 w, u32 miplevels, u32 arraysize, nDraw::FORMAT_TYPE fmt, nDraw::USAGE_TYPE usage, u32 misc_flags);
        Texture(MT_CTSTR pool, MT_CTSTR name, u32 w, u32 h, u32 miplevels, u32 arraysize, nDraw::FORMAT_TYPE fmt, nDraw::USAGE_TYPE usage, u32 misc_flags, nDraw::TEXMEMORY_TYPE memtype);
        Texture(MT_CTSTR pool, MT_CTSTR name, u32 w, u32 h, u32 d, u32 miplevels, u32 arraysize, nDraw::FORMAT_TYPE fmt, nDraw::USAGE_TYPE usage, u32 misc_flags);
        virtual void release();  // vtable slot 6
        virtual void suspend();  // vtable slot 7
        virtual void resume();  // vtable slot 8
        nDraw::MAPPED_TEXTURE map(u32 subresource, nDraw::MAP_TYPE type, const MtRect* prect);
        void unmap(u32 subresource);
        nDraw::TEXTURE_TYPE getType() const;
        u32 getWidth() const;
        u32 getHeight() const;
        u32 getDepth() const;
        u32 getArrayCount() const;
        u32 getLevelCount() const;
        nDraw::FORMAT_TYPE getFormat() const;
        nDraw::GPUFORMAT_TYPE getGPUFormat() const;
        void setTextureData(const u32& w, const u32& h, const nDraw::GPUFORMAT_TYPE format, void* pbin);
        bool isSRGB() const;
        bool isScratch() const;
        bool isMultiSample() const;
        nDraw::Texture* getSharedTexture() const;
        u32 getMiscFlags() const;
        nDraw::HTexture getHandle() const;
        bool operator==(const nDraw::Texture& src) const;
        bool operator!=(const nDraw::Texture&) const;
        nDraw::HTexture getShaderResourceView() const;
        u32 getViewNum() const;
        nDraw::RenderTargetView* getRenderTargetView(u32 subresource) const;
        nDraw::DepthStencilView* getDepthStencilView(u32 subresource) const;
        static u32 calcBitCount(nDraw::FORMAT_TYPE fmt);
        static MtSize calcBufferSize(u32 w, u32 h, u32 level, nDraw::FORMAT_TYPE fmt);
        static u32 calcMipLevelCount(u32 size);
        static bool isSRGBFormat(nDraw::FORMAT_TYPE fmt);
        static sce::Gnm::DataFormat getGPUFormatType(const nDraw::FORMAT_TYPE fmt);
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        void registerScratchTexture();
        void unregisterScratchTexture();
    protected:
        virtual ~Texture();
        void init(u32 type, u32 width, u32 height, u32 depth, u32 miplevel, u32 arraysize, nDraw::FORMAT_TYPE fmt, u32 misc_flags, MT_CTSTR pool, MT_CTSTR name);
        void create(nDraw::Texture* psharedtex, u32 offset, void* pinitvalues);
        bool compare(const nDraw::Texture& src) const;
        u32 getEncodeMode();
        void setEncodeMode(u32 v);
        u32 getDecodeMode();
        void setDecodeMode(u32 v);
        u32 getMSAAMode();
        void setMSAAMode(u32 v);
    protected:
        u32 mWidth : 16;  // offset: 0x28
        u32 mHeight : 14;  // offset: 0x2c
        u32 mSRGB : 1;  // offset: 0x2c
        u32 mScratch : 1;  // offset: 0x2c
        u32 mArrayCount : 8;  // offset: 0x2c
        u32 mLevelCount : 8;  // offset: 0x2c
        u32 mDepth : 11;  // offset: 0x30
        u32 mTextureType : 4;  // offset: 0x30
        u32 mFormatType;  // offset: 0x34
        u32 mMiscFlags;  // offset: 0x38
        nDraw::GPUFORMAT_TYPE mGPUFormatType;  // offset: 0x3c
        nDraw::HTexture mpTexture;  // offset: 0x40
        nDraw::Texture* mpSharedTexture;  // offset: 0x48
        nDraw::RenderTargetView* * mpRTView;  // offset: 0x50
        nDraw::DepthStencilView* * mpDSView;  // offset: 0x58
        u32 mViewNum;  // offset: 0x60
    private:
        sce::Gnm::Texture mTextureObject;  // offset: 0x64
        void* * mpMappingAddresses;  // offset: 0x88
    public:
        static MyDTI DTI;
    };
}  // namespace nDraw
