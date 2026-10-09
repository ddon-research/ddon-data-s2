#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "nDrawResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;

// Declarations
namespace nDraw { class Buffer; }
namespace nDraw { struct MAPPED_TEXTURE; }

namespace nDraw {
    enum MAP_TYPE
    {
        MAP_READ = 0,
        MAP_WRITE = 1,
        MAP_READ_WRITE = 2,
        MAP_WRITE_DISCARD = 3,
        MAP_WRITE_NO_OVERWRITE = 4,
    };
}  // namespace nDraw

namespace nDraw {
    enum USAGE_TYPE
    {
        USAGE_DEFAULT = 0,
        USAGE_DYNAMIC = 1,
        USAGE_RENDERTARGET = 2,
        USAGE_STAGING = 3,
        USAGE_MANAGED = 4,
        USAGE_DEPTHSTENCIL = 5,
        USAGE_DISPLAYBUFFER = 6,
    };
}  // namespace nDraw

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nDraw {
    class Buffer : public nDraw::Resource
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
        Buffer(nDraw::USAGE_TYPE usage);
        // Address: 0x01b82cd0 - 0x01b82cd1 (1 bytes)
        virtual void suspend() {}  // vtable slot 7
        virtual void resume();  // vtable slot 8
        nDraw::USAGE_TYPE getUsageType() const;
        u32 getBufferSize() const;
        void* getBufferPointer();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
        bool isDirty() const;
        void clearDirty();
        void setSuspend(bool);
        bool isSuspending() const;
    protected:
        virtual ~Buffer();
        void setDirty();
    protected:
        nDraw::USAGE_TYPE mUsageType;  // offset: 0x14
        u32 mBufSize;  // offset: 0x18
        void* mpBuffer;  // offset: 0x20
    private:
        bool mDirty;  // offset: 0x28
        bool mSuspend;  // offset: 0x29
    public:
        static MyDTI DTI;
    };
}  // namespace nDraw

namespace nDraw {
    struct MAPPED_TEXTURE
    {
    public:
        void* pdata;  // offset: 0x0
        u32 pitch;  // offset: 0x8
        u32 depth;  // offset: 0xc
    };
}  // namespace nDraw
