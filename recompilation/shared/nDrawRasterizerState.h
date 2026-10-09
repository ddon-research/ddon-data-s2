#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "constants.h"
#include "nDrawResource.h"
#include "regs.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
namespace sce { namespace Gnm { class PrimitiveSetup; } }

// Declarations
namespace nDraw { struct RASTERIZER_DESC; }
namespace nDraw { class RasterizerState; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nDraw {
    struct RASTERIZER_DESC
    {
    public:
        u32 fill_mode : 3;  // offset: 0x0
        u32 cull_mode : 3;  // offset: 0x0
        u32 front_counter : 1;  // offset: 0x0
        u32 dclip_enable : 1;  // offset: 0x0
        u32 scissor_enable : 1;  // offset: 0x0
        u32 msaa_enable : 1;  // offset: 0x0
        u32 aline_enable : 1;  // offset: 0x0
        s32 dbias;  // offset: 0x4
        f32 dbias_clamp;  // offset: 0x8
        f32 dbias_slope;  // offset: 0xc
    };
}  // namespace nDraw

namespace nDraw {
    class RasterizerState : public nDraw::Resource
    {
    public:
        class MyDTI;
        struct RASTERIZER_STATES;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct RASTERIZER_STATES
        {
        public:
            sce::Gnm::PrimitiveSetup primSetup;  // offset: 0x0
            sce::Gnm::ScanModeControlViewportScissor scissor;  // offset: 0x4
            sce::Gnm::ScanModeControlAa msaa;  // offset: 0x8
            f32 poFrontScale;  // offset: 0xc
            f32 poFrontOffset;  // offset: 0x10
            f32 poBackScale;  // offset: 0x14
            f32 poBackOffset;  // offset: 0x18
            f32 poClamp;  // offset: 0x1c
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
        RasterizerState(const nDraw::RASTERIZER_DESC* pdesc);
        const RASTERIZER_STATES* getHandle(bool clockwise) const;
        const nDraw::RASTERIZER_DESC* getDesc() const;
    private:
        virtual ~RasterizerState();
    protected:
        nDraw::RASTERIZER_DESC mDesc;  // offset: 0x14
    private:
        RASTERIZER_STATES mRasterizerStates[2];  // offset: 0x24
    public:
        static MyDTI DTI;
    };
}  // namespace nDraw
