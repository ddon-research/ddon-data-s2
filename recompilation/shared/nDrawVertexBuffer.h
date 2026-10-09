#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "nDrawBuffer.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;

// Declarations
namespace nDraw { class VertexBuffer; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
namespace nDraw { using HVertexBuffer = void*; }
using size_t = _Sizet;
using u32 = unsigned int;

namespace nDraw {
    class VertexBuffer : public nDraw::Buffer
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
        VertexBuffer(u32 size, nDraw::USAGE_TYPE usage, const void* pinitvalues);
        VertexBuffer(nDraw::VertexBuffer& src, nDraw::USAGE_TYPE usage);
        virtual void suspend();  // vtable slot 7
        virtual void resume();  // vtable slot 8
        void* map(nDraw::MAP_TYPE type);
        void unmap();
        nDraw::HVertexBuffer getHandle() const;
    protected:
        virtual ~VertexBuffer();
        void create(u32 size, const void* pinitvalues);
    protected:
        nDraw::HVertexBuffer mpVertexBuffer;  // offset: 0x30
    public:
        static MyDTI DTI;
    };
}  // namespace nDraw
