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
namespace nDraw { class OcclusionQuery; }
namespace nDraw { class Query; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
namespace nDraw { using HQuery = void*; }
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nDraw {
    class Query : public nDraw::Buffer
    {
    public:
        enum QUERY_TYPE
        {
            TYPE_OCCLUSION = 0,
        };
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
        Query(QUERY_TYPE type);
        virtual void suspend();  // vtable slot 7
        virtual void resume();  // vtable slot 8
    protected:
        virtual ~Query();
        bool getData(void* pdata, s32* frame);
    private:
        void begin();
        void end();
    private:
        u32 mWriteBuffer;  // offset: 0x2c
        u32 mReadBuffer;  // offset: 0x30
        bool mBusy;  // offset: 0x34
        u32 mType;  // offset: 0x38
        s32 mQueryIssuedFrame[4];  // offset: 0x3c
        nDraw::HQuery mpQuery[4];  // offset: 0x50
        u32 mDataSize;  // offset: 0x70
    public:
        static MyDTI DTI;
    private:
        static const u32 BUFFER_NUM = 4;
    };
}  // namespace nDraw

namespace nDraw {
    class OcclusionQuery : public nDraw::Query
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
        OcclusionQuery();
        u32 get(s32* frame);
    private:
        virtual ~OcclusionQuery();
    public:
        static MyDTI DTI;
    };
}  // namespace nDraw
