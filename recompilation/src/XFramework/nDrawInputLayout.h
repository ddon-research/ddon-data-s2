#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "nDrawResource.h"

// Forward declarations
struct D3D11_INPUT_ELEMENT_DESC;
class MtAllocator;
class MtDTI;
class MtObject;
namespace nDraw { struct INPUT_ELEMENT; }

// Declarations
namespace nDraw { class InputLayout; }

namespace nDraw {
    enum INPUT_ELEMENT_FORMAT
    {
        IEF_UNDEFINED = 0,
        IEF_F32 = 1,
        IEF_F16 = 2,
        IEF_S16 = 3,
        IEF_U16 = 4,
        IEF_S16N = 5,
        IEF_U16N = 6,
        IEF_S8 = 7,
        IEF_U8 = 8,
        IEF_S8N = 9,
        IEF_U8N = 10,
        IEF_SCMP3N = 11,
        IEF_UCMP3N = 12,
        IEF_U8NL = 13,
        IEF_COLOR4N = 14,
        IEF_MAX = 15,
    };
}  // namespace nDraw

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
namespace nDraw { using GPUINPUT_ELEMENT = D3D11_INPUT_ELEMENT_DESC; }
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nDraw {
    class InputLayout : public nDraw::Resource
    {
    public:
        enum FETCH_DECODER
        {
            FD_DEFAULT = 0,
            FD_COLOR4N = 1,
            FD_SCMP3N = 2,
            FD_UCMP3N = 3,
            FD_U8N = 4,
            FD_S8N = 5,
            FD_U8 = 6,
            FD_S8 = 7,
            FD_U16N = 8,
            FD_S16N = 9,
            FD_U16 = 10,
            FD_S16 = 11,
            FD_U8N_TO_S8N = 12,
            FD_U8N_TO_S8 = 13,
            FD_U8N_TO_U8 = 14,
            FD_U8N_TO_U8NL = 15,
            FD_S8N_TO_U8N = 16,
            FD_S8N_TO_U8 = 17,
            FD_S8N_TO_S8 = 18,
            FD_S8N_TO_U8NL = 19,
            FD_U8_TO_S8N = 20,
            FD_U8_TO_S8 = 21,
            FD_U8_TO_U8N = 22,
            FD_U8_TO_U8NL = 23,
            FD_S8_TO_S8N = 24,
            FD_S8_TO_U8 = 25,
            FD_S8_TO_U8N = 26,
            FD_S8_TO_U8NL = 27,
            FD_U16N_TO_S16N = 28,
            FD_U16N_TO_S16 = 29,
            FD_U16N_TO_U16 = 30,
            FD_S16N_TO_S16 = 31,
            FD_S16N_TO_U16 = 32,
            FD_S16N_TO_U16N = 33,
            FD_U16_TO_S16N = 34,
            FD_U16_TO_S16 = 35,
            FD_U16_TO_U16N = 36,
            FD_S16_TO_S16N = 37,
            FD_S16_TO_U16 = 38,
            FD_S16_TO_U16N = 39,
        };
    public:
        class MyDTI;
        struct INPUT_SEMANTIC;
        struct FETCH_INFO;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct INPUT_SEMANTIC
        {
        public:
            MT_CTSTR sname;  // offset: 0x0
            u32 sindex;  // offset: 0x8
        };
    public:
        struct FETCH_INFO
        {
        public:
            u32 enable : 1;  // offset: 0x0
            u32 index : 8;  // offset: 0x0
            u32 slot : 8;  // offset: 0x0
            u32 decoder : 15;  // offset: 0x0
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
        InputLayout(const nDraw::INPUT_ELEMENT* elements, u32 element_num);
        virtual ~InputLayout();
        FETCH_INFO getGPUFetchInfo(MT_CTSTR sname, u32 sindex, u32 element_index) const;
        const nDraw::INPUT_ELEMENT* getElements() const;
        u32 getElementNum() const;
        const nDraw::GPUINPUT_ELEMENT* getGPUElements() const;
        bool isInstanceData() const;
        u32 getGPUElementNum() const;
        u32 getStride() const;
        u32 write(void* pdst_base, MT_CTSTR sname, u32 sindex, const f32* psrc) const;
        u32 read(f32* pdst, MT_CTSTR sname, u32 sindex, const void* psrc_base) const;
        static u32 getElementCount(const nDraw::INPUT_ELEMENT& e);
        static u32 getElementSize(const nDraw::INPUT_ELEMENT& e);
        static u32 getFormatSize(nDraw::INPUT_ELEMENT_FORMAT ief);
        static u32 write(void* pdst_base, const nDraw::INPUT_ELEMENT& e, const f32* psrc);
        static u32 read(f32* pdst, const nDraw::INPUT_ELEMENT& e, const void* psrc_base);
        static u32 getGPUElementSize(const nDraw::GPUINPUT_ELEMENT& e);
        static u32 getGPUElementCount(const nDraw::GPUINPUT_ELEMENT& e);
        static const INPUT_SEMANTIC& getInputSemantic(u32 index);
    protected:
        void addVertexElement(nDraw::GPUINPUT_ELEMENT* velements, u32& velement_num, u32 slot, u32 input_format, s32 input_num, u32 offset, bool instance);
    protected:
        nDraw::GPUINPUT_ELEMENT* mGPUElements;  // offset: 0x18
        u32 mGPUElementNum;  // offset: 0x20
        nDraw::INPUT_ELEMENT* mElements;  // offset: 0x28
        u32 mElementNum;  // offset: 0x30
        u32 mStride;  // offset: 0x34
        bool mIsInstanceData;  // offset: 0x38
    public:
        static MyDTI DTI;
        static const u32 MAX_INPUT_SEMANTICS = 16;
    protected:
        static const INPUT_SEMANTIC mInputSemantics[16];
    };
}  // namespace nDraw
