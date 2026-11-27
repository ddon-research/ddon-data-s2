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
namespace nCaplink { class cFreeTagInfo; }

// Declarations
namespace nCaplink { class FriendTagFreeListGetAns; }
namespace nCaplink { class FriendTagFreeListGetReqCtx; }

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
    class FriendTagFreeListGetAns : public nCaplink::ContextListener
    {
    public:
        FriendTagFreeListGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setFreeTagInfoTbl(MtArray& entry_list);
        u32 getFreeTagTotal() const;
        u32 getFreeTagCount() const;
        nCaplink::cFreeTagInfo* getFreeTagInfo(s32 index) const;
    private:
        s32 mTotal;  // offset: 0x20
        MtArray mFreeTagInfoTbl;  // offset: 0x28
    };
}  // namespace nCaplink

namespace nCaplink {
    class FriendTagFreeListGetReqCtx : public nCaplink::HttpRequestContext
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
            void setParent(nCaplink::FriendTagFreeListGetReqCtx* parent);
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
            bool mbUniqueId;  // offset: 0xb
            bool mbTagId;  // offset: 0xc
            bool mbAlive;  // offset: 0xd
            bool mbUpdateAt;  // offset: 0xe
            bool mbCode;  // offset: 0xf
            bool mbDetailMessage;  // offset: 0x10
            MtString mUniqueId;  // offset: 0x18
            s32 mTagId;  // offset: 0x20
            s8 mAlive;  // offset: 0x24
            MtString mUpdateAt;  // offset: 0x28
            nCaplink::FriendTagFreeListGetReqCtx* mpParent;  // offset: 0x30
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
        FriendTagFreeListGetReqCtx();
        FriendTagFreeListGetReqCtx(MT_CTSTR from_datetime, s32 offset, s32 count);
        virtual void update();  // vtable slot 8
        virtual void request();  // vtable slot 9
        void setTotal(s32 total);
        void addFreeTagInfo(nCaplink::cFreeTagInfo* info);
    private:
        MtString mFromDatetime;  // offset: 0x68
        s32 mOffset;  // offset: 0x70
        s32 mCount;  // offset: 0x74
        s32 mTotal;  // offset: 0x78
        MtArray mFreeTagInfoTbl;  // offset: 0x80
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline void* nCaplink::FriendTagFreeListGetReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nCaplink::FriendTagFreeListGetReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::FriendTagFreeListGetReqCtx::DTI)->memFree(p_addr);
}
