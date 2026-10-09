#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cDraw.h"
#include "nDrawResource.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cDraw;
namespace nDraw { struct OBJECT; }
namespace nDraw { struct SHADER_STATE; }

// Declarations
namespace nDraw { class CommandCache; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;
using SO_HANDLE = u32;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u16 = unsigned short;

namespace nDraw {
    class CommandCache : public nDraw::Resource
    {
    public:
        class MyDTI;
        struct PATCH_INFO;
        struct INDEX_STACK;
        struct LIST_STACK;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct PATCH_INFO
        {
        public:
            u32 mode : 1;  // offset: 0x0
            u32 index : 12;  // offset: 0x0
            u32 adr_num : 19;  // offset: 0x0
            u32* offsets;  // offset: 0x8
        };
    public:
        struct INDEX_STACK
        {
        public:
            u32 index;  // offset: 0x0
            nDraw::CommandCache::LIST_STACK* plist;  // offset: 0x8
        };
    public:
        struct LIST_STACK
        {
        public:
            void* padr;  // offset: 0x0
            void* pcb;  // offset: 0x8
            nDraw::CommandCache::LIST_STACK* pnext;  // offset: 0x10
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
        CommandCache(const cDraw::TAG* tags, u32 tag_num, const nDraw::SHADER_STATE* states);
        bool isValid(cDraw* pdraw);
        bool drawEntry(cDraw* pdraw);
        void setDisable(u32 tag_index);
        void setEnable(u32 tag_index);
        void trace();
        void setLimitDetect(bool);
        bool isLimitDetect() const;
        u32 getCacheCRC() const;
    protected:
        virtual ~CommandCache();
        bool isLocalObject(const nDraw::OBJECT* pobj, void* padr);
        void copyCommand(const cDraw::TAG* tags, u32 tag_num, const nDraw::SHADER_STATE* states);
        u32 calcCommandSize(const cDraw::TAG* tags, u32 tag_num, u32& index_stack_count, INDEX_STACK* index_stack, LIST_STACK* list_stack);
        void* allocBuf(u32 size);
        void addGlobalFunc(SO_HANDLE handle, const nDraw::SHADER_STATE* states);
        u32 calcGlobalCRC(const nDraw::SHADER_STATE* states);
    protected:
        void* mpBuffer;  // offset: 0x18
        u32 mBufSize;  // offset: 0x20
        u32 mBufPt;  // offset: 0x24
        cDraw::TAG* mTags;  // offset: 0x28
        PATCH_INFO mPatchInfos[32];  // offset: 0x30
        u32 mTagNum : 16;  // offset: 0x230
        u32 mValidTagNum : 16;  // offset: 0x230
        u32 mGlobalFuncNum : 26;  // offset: 0x234
        u32 mPatchNum : 6;  // offset: 0x234
        u32* mVisibleFlags;  // offset: 0x238
        u32 mCRC;  // offset: 0x240
        bool mLimitDetect;  // offset: 0x244
        u16 mGlobalFunc[64];  // offset: 0x246
        static const u32 MAX_INDEX_STACK = 256;
        static const u32 MAX_LIST_STACK = 2048;
        static const u32 MAX_PATCH = 32;
        static const u32 MAX_GLOBAL_FUNC = 64;
    public:
        static MyDTI DTI;
    };
}  // namespace nDraw
