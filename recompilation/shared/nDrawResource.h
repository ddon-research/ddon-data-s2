#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtObject.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtPropertyList;

// Declarations
namespace nDraw { class Resource; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

namespace nDraw {
    class Resource : public ::MtObject
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
        Resource();
        bool addRef();
        virtual void release();  // vtable slot 6
        const s32& getRefCount() const;
        void protect();
        bool isProtect() const;
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        u32 getCRC() const;
        void setCRC(u32 crc);
        static void setRenderFrame(s32 f);
        static void setProtectFrame(s32 f);
    protected:
        s32 getRenderFrame() const;
        void calcCRC(const void* pbuf, u32 bytes);
        void setDmyU32(u32);
        void setDmyBool(bool);
        bool incRefCount();
        s32 decRefCount();
        bool terminate(s32 destruction_seed);
    private:
        s32 mRefFrame;  // offset: 0x8
        s32 mRefCount;  // offset: 0xc
        u32 mCRC;  // offset: 0x10
    public:
        static MyDTI DTI;
    protected:
        static const s32 INVALID_REF = -1000;
    private:
        static s32 mRenderFrame;
        static s32 mProtectFrame;
    };
}  // namespace nDraw
