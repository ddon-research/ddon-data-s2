#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "nDraw.h"
#include "nDrawMaterial.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class MtVector3;
class cDraw;
namespace nDraw { class Texture; }

// Declarations
namespace nDraw { class MaterialSSS; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nDraw {
    class MaterialSSS : public nDraw::Material
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
        MaterialSSS();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        virtual void update(f32 dt);  // vtable slot 8
    protected:
        virtual u32 setDrawState(cDraw* pdraw, nDraw::PASS_TYPE overrideDrawPass);  // vtable slot 13
        virtual bool beginDraw(cDraw* pdraw, u32 pass);  // vtable slot 14
        virtual void endDraw(cDraw* pdraw, u32 pass);  // vtable slot 15
        virtual ~MaterialSSS();
        void fillMargin(cDraw* pdraw, nDraw::Texture* ptex);
        void blurDiffuse(cDraw* pdraw, nDraw::Texture* pdst, nDraw::Texture* psrc);
        void releaseTexture();
        void createTexture();
        u32 getMapSize() const;
        void setMapSize(u32 size);
        u32 getLayerNum() const;
        void setLayerNum(u32 num);
    protected:
        nDraw::Texture* mpDistortionTexture;  // offset: 0xd0
        nDraw::Texture* mpTempTexture;  // offset: 0xd8
        nDraw::Texture* mpDiffuseTexture[6];  // offset: 0xe0
        nDraw::Texture* mpLightMaskTexture;  // offset: 0x110
        u32 mMapSize;  // offset: 0x118
        u32 mLayerNum;  // offset: 0x11c
        MtVector3 mBlendWeights[6];  // offset: 0x120
    public:
        static MyDTI DTI;
    protected:
        static const u32 DTEX_NUM = 6;
        static const u32 DTEX_SIZE = 256;
    };
}  // namespace nDraw

inline void* nDraw::MaterialSSS::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
