#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtObject.h"
#include "../shared/MtPrimitive2D.h"
#include "../shared/nDraw.h"
#include "../shared/nGUI.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtMatrix;
class MtRect;
class MtVector2;
class MtVector4;
class cDraw;
namespace nDraw { class DepthStencilView; }
namespace nDraw { class IndexBuffer; }
namespace nDraw { class RenderTargetView; }
namespace nDraw { class Texture; }
namespace nDraw { class VertexBuffer; }
namespace nGUI { struct TEXTURE; }

// Declarations
namespace nGUI { class Draw; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;
using SO_HANDLE = u32;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u8 = unsigned char;

namespace nGUI {
    class Draw : public ::MtObject
    {
    public:
        enum TECHNIQUE_PASS
        {
            TECHNIQUE_PASS_POLYGON = 0,
            TECHNIQUE_PASS_TEXTURE = 1,
            TECHNIQUE_PASS_BLEND = 2,
            TECHNIQUE_PASS_DEVELOP = 3,
            TECHNIQUE_PASS_DEVELOP_LINE = 4,
            TECHNIQUE_PASS_NUM = 5,
        };
        enum STENCIL_STATE
        {
            STENCIL_STATE_NONE = 0,
            STENCIL_STATE_WRITE = 1,
            STENCIL_STATE_APPLY = 2,
            STENCIL_STATE_APPLY_REVERSE = 3,
            STENCIL_STATE_UPDATE = 4,
            STENCIL_STATE_NUM = 5,
        };
    public:
        class MyDTI;
        struct STENCIL_INFO;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct STENCIL_INFO
        {
        public:
            u32 type : 8;  // offset: 0x0
            u32 maskCount : 8;  // offset: 0x0
            u32 padding : 16;  // offset: 0x0
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
        Draw(cDraw* pDraw, bool _3d);
        // Address: 0x01b915c0 - 0x01b915c1 (1 bytes)
        virtual ~Draw() {}
        static void setup();
        cDraw* getDraw() const;
        bool is3D() const;
        bool isVisible() const;
        void setDrawStencil(bool v);
        bool isDrawStencil() const;
        void setStencilRef(u8 v);
        u8 getStencilRef() const;
        u32 getTechniquePass() const;
        void setVertexBuffer(nDraw::VertexBuffer* pVertexBuffer, u32 byteOffset);
        void setIndexBuffer(nDraw::IndexBuffer* pIndexBuffer, u32 byteOffset);
        void setWorldMatrix(const MtMatrix& mat, u32 type);
        const MtMatrix& getWorldMatrix();
        const MtMatrix* getInvViewMatrix() const;
        void setBaseZ(f32 baseZ);
        f32 getBaseZ() const;
        void setMatrix3D(const MtMatrix& matrix);
        void setMatrix2D(const MtMatrix& matrix);
        void setTexture(nGUI::TEXTURE* texture);
        void setStaticColor(const MtColor& color);
        void setFontTexture(nDraw::Texture* pTexture);
        void clearFontTexture();
        void pushColorConstantBuffer(const MtVector4& colorScale, const MtVector4& ambientColor);
        void popColorConstantBuffer();
        void setColorAttribute(bool valid, f32 saturation);
        void setBlendState(nGUI::BlendState::BLEND_MODE mode);
        void setSamplerState(nGUI::SamplerState::SAMPLER_MODE state, bool useGUIWrap);
        bool setDrawPass(u32 pass);
        u32 getDrawPass() const;
        nDraw::PASS_TYPE getNDrawPass() const;
        void setTechnique(u32 pass);
        void setDepthState(u32 state);
        u32 getDepthState() const;
        void beginMask(u32 type);
        void applyMask(u32 type);
        void endMask(u32 type);
        void setOffset(const MtVector2& offset);
        void setScale(const MtVector2& scale);
        void setEnableScissor(bool v);
        bool isEnableScissor() const;
        void setScissorRect(const MtRect& rect);
        void getScissorRect(MtRect& rect);
    private:
        Draw();
        void beginStencilMask(u32 type);
        void applyStencilMask();
        void endStencilMask();
        void beginAlphaMask(u32 type);
        void applyAlphaMask();
        void endAlphaMask();
        void setVisible(bool v);
    private:
        cDraw* mpDraw;  // offset: 0x8
        u32 mColorStackCount : 8;  // offset: 0x10
        u32 mDrawPass : 4;  // offset: 0x10
        u32 mTechniquePass : 4;  // offset: 0x10
        u32 mDepthState : 4;  // offset: 0x10
        u32 mStencilState : 4;  // offset: 0x10
        u32 mBillboard : 4;  // offset: 0x10
        u32 mAttr;  // offset: 0x14
        nGUI::TEXTURE* mpTexture;  // offset: 0x18
        nDraw::Texture* mpFontTexture;  // offset: 0x20
        nDraw::PASS_TYPE mNDrawPass;  // offset: 0x28
        union
        {
        public:
            struct
            {
            public:
                u32 mStencilMaskCount : 8;  // offset: 0x0
                u32 mStencilRefCount : 8;  // offset: 0x0
                u32 mStencilStart : 8;  // offset: 0x0
                u32 mStencilMaskStackCount : 4;  // offset: 0x0
            };  // offset: 0x0
            struct
            {
            public:
                u32 mStencilRef : 8;  // offset: 0x0
            };  // offset: 0x0
        };  // offset: 0x2c
        STENCIL_INFO mStencilMaskStack[16];  // offset: 0x30
        f32 mBaseZ;  // offset: 0x70
        f32 mViewZ;  // offset: 0x74
        f32 mScreenZ;  // offset: 0x78
        u32 mAlphaMaskStackCount : 4;  // offset: 0x7c
        u32 mAlphaMaskApply : 1;  // offset: 0x7c
        nDraw::RenderTargetView* mpRenderTargetBackup;  // offset: 0x80
        nDraw::DepthStencilView* mpDepthStencilBackup;  // offset: 0x88
        u32 mAlphaMaskStack[16];  // offset: 0x90
        MtVector2 mOffset;  // offset: 0xd0
        MtVector2 mScale;  // offset: 0xd8
        MtRect mScissorRect;  // offset: 0xe0
        MtVector4 mColorScaleStack[16];  // offset: 0xf0
        MtVector4 mAmbientColorStack[16];  // offset: 0x1f0
    public:
        static MyDTI DTI;
    private:
        static const u32 ATTR_3D = 1;
        static const u32 ATTR_VISIBLE = 2;
        static const u32 ATTR_DRAW_STENCIL = 4;
        static const u32 ATTR_ENALBE_SCISSOR = 8;
        static u32 PassTable[5];
        static SO_HANDLE DepthStencil[5][5];
    };
}  // namespace nGUI
