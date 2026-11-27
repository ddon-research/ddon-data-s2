#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "nDrawResource.h"
#include "../generated/shared/regs.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
namespace sce { namespace Gnm { class AlphaToMaskControl; } }
namespace sce { namespace Gnm { class BlendControl; } }

// Declarations
namespace nDraw { struct BLEND_DESC; }
namespace nDraw { class BlendState; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nDraw {
    struct BLEND_DESC
    {
    public:
        u32 atc_enable : 1;  // offset: 0x0
        u32 blend_enable : 8;  // offset: 0x0
        u32 blend_src : 8;  // offset: 0x0
        u32 blend_dest : 8;  // offset: 0x0
        u32 blend_op : 7;  // offset: 0x0
        u32 blend_asrc : 8;  // offset: 0x4
        u32 blend_adest : 8;  // offset: 0x4
        u32 blend_aop : 7;  // offset: 0x4
        u8 wmask[8];  // offset: 0x7
    };
}  // namespace nDraw

namespace nDraw {
    class BlendState : public nDraw::Resource
    {
    public:
        class MyDTI;
        struct BLEND_STATES;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct BLEND_STATES
        {
        public:
            sce::Gnm::BlendControl blendControl;  // offset: 0x0
            u32 renderTargetMask;  // offset: 0x4
            sce::Gnm::AlphaToMaskControl alphaToMaskControl;  // offset: 0x8
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
        BlendState(const nDraw::BLEND_DESC* pdesc);
        const BLEND_STATES* getHandle() const;
        const nDraw::BLEND_DESC* getDesc() const;
    private:
        virtual ~BlendState();
    protected:
        nDraw::BLEND_DESC mDesc;  // offset: 0x14
    private:
        BLEND_STATES mBlendStates;  // offset: 0x24
    public:
        static MyDTI DTI;
    };
}  // namespace nDraw

inline void* nDraw::BlendState::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nDraw::BlendState::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nDraw::BlendState::DTI)->memFree(p_addr);
}
