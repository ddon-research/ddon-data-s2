#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "nDrawResource.h"
#include "../generated/shared/sampler.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
namespace sce { namespace Gnm { class Sampler; } }

// Declarations
namespace nDraw { struct SAMPLER_DESC; }
namespace nDraw { class SamplerState; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
namespace nDraw { using HSamplerState = sce::Gnm::Sampler*; }
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

namespace nDraw {
    struct SAMPLER_DESC
    {
    public:
        u32 filter : 8;  // offset: 0x0
        u32 address_u : 3;  // offset: 0x0
        u32 address_v : 3;  // offset: 0x0
        u32 address_w : 3;  // offset: 0x0
        u32 max_aniso : 5;  // offset: 0x0
        u32 cmp_func : 4;  // offset: 0x0
        f32 lod_bias;  // offset: 0x4
        u32 padding1;  // offset: 0x8
        f32 lod_min;  // offset: 0xc
        f32 lod_max;  // offset: 0x10
        u64 padding2;  // offset: 0x18
        u64 padding3;  // offset: 0x20
        f32 border_color[4];  // offset: 0x28
    };
}  // namespace nDraw

namespace nDraw {
    class SamplerState : public nDraw::Resource
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
        SamplerState(const nDraw::SAMPLER_DESC* pdesc);
        nDraw::HSamplerState getHandle() const;
        const nDraw::SAMPLER_DESC* getDesc() const;
    protected:
        virtual ~SamplerState();
    protected:
        nDraw::SAMPLER_DESC mDesc;  // offset: 0x18
        sce::Gnm::Sampler mSamplerState;  // offset: 0x50
    public:
        static MyDTI DTI;
    };
}  // namespace nDraw

inline void* nDraw::SamplerState::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
