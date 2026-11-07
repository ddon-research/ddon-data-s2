#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../XFramework/nDraw.h"
#include "../../XFramework/nDrawMaterialStdEst.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector4;
class cDDMaterialCtrl;
class cDraw;
namespace nDraw { class Texture; }

// Declarations
namespace nDraw { class DDMrlStdEstObj; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nDraw {
    class DDMrlStdEstObj : public nDraw::MaterialStdEst
    {
        friend class ::cDDMaterialCtrl;
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
        DDMrlStdEstObj();
        virtual void update(f32 dt);  // vtable slot 8
        virtual u32 setDrawState(cDraw* pdraw, nDraw::PASS_TYPE overrideDrawPass);  // vtable slot 13
        void setBaseShaderMode(u32 mode);
        void setShaderMode(u32 mode = 2);
        void setAlphaClipThreshold(f32 val);
        f32 getAlphaClipThreshold();
        void setBlendAlphaThreshold(f32 val);
        f32 getBlendAlphaThreshold();
        void setBlendAlphaBand(f32 val);
        f32 getBlendAlphaBand();
        void setAlbedoBlendRate(f32);
        f32 getAlbedoBlendRate();
        void setEmissionFactor(f32);
        void setAlbedoBlendColor(const MtVector4&);
        MtVector4 getAlbedoBlendColor() const;
        void setAlbedoMapEx(nDraw::Texture* ptex);
        void setNormalMapEx(nDraw::Texture* ptex);
        void setSpecularMapEx(nDraw::Texture* ptex);
        void setEnvMapEx(nDraw::Texture* ptex);
        void setIsNoFreeze(bool set);
    protected:
        virtual ~DDMrlStdEstObj();
    private:
        u32 mBaseShaderMode;  // offset: 0xd0
        u32 mShaderMode;  // offset: 0xd4
        f32 mAlphaClipThreshold;  // offset: 0xd8
        f32 mBlendAlphaThreshold;  // offset: 0xdc
        f32 mBlendAlphaBand;  // offset: 0xe0
        f32 mAlbedoBlendRate;  // offset: 0xe4
        f32 mEmissionFactor;  // offset: 0xe8
        MtVector4 mAlbedoBlendColor;  // offset: 0xf0
        nDraw::Texture* mpAlbedoMapEx;  // offset: 0x100
        nDraw::Texture* mpNormalMapEx;  // offset: 0x108
        nDraw::Texture* mpSpecularMapEx;  // offset: 0x110
        nDraw::Texture* mpEnvMapEx;  // offset: 0x118
        bool mIsNoFreeze;  // offset: 0x120
    public:
        static MyDTI DTI;
    };
}  // namespace nDraw

inline void* nDraw::DDMrlStdEstObj::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void nDraw::DDMrlStdEstObj::setBaseShaderMode(u32 mode) {
    this->mBaseShaderMode = mode;
}

inline void nDraw::DDMrlStdEstObj::setShaderMode(u32 mode) {
    this->mShaderMode = 2;
}

inline void nDraw::DDMrlStdEstObj::setAlphaClipThreshold(f32 val) {
    this->mAlphaClipThreshold = val;
}

inline void nDraw::DDMrlStdEstObj::setBlendAlphaThreshold(f32 val) {
    this->mBlendAlphaThreshold = val;
}

inline void nDraw::DDMrlStdEstObj::setBlendAlphaBand(f32 val) {
    this->mBlendAlphaBand = val;
}
