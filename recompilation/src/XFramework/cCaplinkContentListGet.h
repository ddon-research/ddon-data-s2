#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtJsonReader.h"
#include "../MT/MtString.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtDTI;
class MtObject;
class MtString;
namespace nCaplink { class cContentInfo; }

// Declarations
namespace nCaplink { class ContentListGetAns; }
namespace nCaplink { class ContentListGetReqCtx; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using f64 = double;
using s32 = int;
using s64 = __int64_t;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

namespace nCaplink {
    class ContentListGetAns : public nCaplink::ContextListener
    {
    public:
        ContentListGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setContentInfoTbl(MtArray& entry_list);
        u32 getContentTotal() const;
        u32 getContentCount() const;
        nCaplink::cContentInfo* getContentInfo(s32 index) const;
    private:
        s32 mTotal;  // offset: 0x20
        MtArray mContentInfoTbl;  // offset: 0x28
    };
}  // namespace nCaplink

namespace nCaplink {
    class ContentListGetReqCtx : public nCaplink::HttpRequestContext
    {
    public:
        class MyDTI;
        class JsonParser;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class JsonParser : public MtJsonReader::Handler
        {
        public:
            JsonParser();
            void setParent(nCaplink::ContentListGetReqCtx* parent);
            virtual void beginArray();  // vtable slot 2
            virtual void endArray();  // vtable slot 3
            virtual void beginObject();  // vtable slot 4
            virtual void endObject();  // vtable slot 5
            virtual void fieldName(MT_CTSTR chars, const u32 length);  // vtable slot 6
            virtual void string(MT_CTSTR chars, const u32 length);  // vtable slot 7
            virtual void number(u64 value);  // vtable slot 8
            virtual void number(s64 value);  // vtable slot 9
            virtual void number(f64 value);  // vtable slot 10
        private:
            bool mbArray;  // offset: 0x9
            bool mbTotal;  // offset: 0xa
            bool mbContentId;  // offset: 0xb
            bool mbContentName;  // offset: 0xc
            bool mbTagId;  // offset: 0xd
            bool mbTagName;  // offset: 0xe
            bool mbComment;  // offset: 0xf
            bool mbAppData;  // offset: 0x10
            bool mbAlive;  // offset: 0x11
            bool mbCode;  // offset: 0x12
            bool mbDetailMessage;  // offset: 0x13
            MtString mContentId;  // offset: 0x18
            MtString mContentName;  // offset: 0x20
            s32 mTagId;  // offset: 0x28
            MtString mTagName;  // offset: 0x30
            MtString mComment;  // offset: 0x38
            MtString mAppData;  // offset: 0x40
            s8 mAlive;  // offset: 0x48
            nCaplink::ContentListGetReqCtx* mpParent;  // offset: 0x50
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
        ContentListGetReqCtx();
        ContentListGetReqCtx(s32 offset, s32 count);
        virtual void update();  // vtable slot 8
        virtual void request();  // vtable slot 9
        void setTotal(s32 total);
        void addContentInfo(nCaplink::cContentInfo* info);
    private:
        s32 mOffset;  // offset: 0x68
        s32 mCount;  // offset: 0x6c
        s32 mTotal;  // offset: 0x70
        MtArray mContentInfoTbl;  // offset: 0x78
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline void* nCaplink::ContentListGetReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nCaplink::ContentListGetReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::ContentListGetReqCtx::DTI)->memFree(p_addr);
}
