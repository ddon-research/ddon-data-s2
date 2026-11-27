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
namespace nCaplink { class cNotifyAppInfo; }

// Declarations
namespace nCaplink { class NotifyAppListGetAns; }
namespace nCaplink { class NotifyAppListGetReqCtx; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using f64 = double;
using s32 = int;
using s64 = __int64_t;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

namespace nCaplink {
    class NotifyAppListGetAns : public nCaplink::ContextListener
    {
    public:
        NotifyAppListGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setNotifyAppInfoTbl(MtArray& entry_list);
        u32 getNotifyAppTotal() const;
        u32 getNotifyAppCount() const;
        nCaplink::cNotifyAppInfo* getNotifyAppInfo(s32 index) const;
        const MtArray* getNotifyAppInfoList();
    private:
        s32 mTotal;  // offset: 0x20
        MtArray mNotifyAppInfoTbl;  // offset: 0x28
    };
}  // namespace nCaplink

namespace nCaplink {
    class NotifyAppListGetReqCtx : public nCaplink::HttpRequestContext
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
            void setParent(nCaplink::NotifyAppListGetReqCtx* parent);
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
            bool mbNotifyId;  // offset: 0xb
            bool mbContentId;  // offset: 0xc
            bool mbMessage;  // offset: 0xd
            bool mbParam;  // offset: 0xe
            bool mbUniqueId;  // offset: 0xf
            bool mbNickname;  // offset: 0x10
            bool mbIcon;  // offset: 0x11
            bool mbNotifyType;  // offset: 0x12
            bool mbViewType;  // offset: 0x13
            bool mbUpdatedAt;  // offset: 0x14
            bool mbCode;  // offset: 0x15
            bool mbDetailMessage;  // offset: 0x16
            s32 mNotifyId;  // offset: 0x18
            MtString mContentId;  // offset: 0x20
            MtString mMessage;  // offset: 0x28
            MtString mParam;  // offset: 0x30
            MtString mUniqueId;  // offset: 0x38
            MtString mNickname;  // offset: 0x40
            MtString mIcon;  // offset: 0x48
            s32 mNotifyType;  // offset: 0x50
            s32 mViewType;  // offset: 0x54
            MtString mUpdatedAt;  // offset: 0x58
            nCaplink::NotifyAppListGetReqCtx* mpParent;  // offset: 0x60
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
        NotifyAppListGetReqCtx();
        NotifyAppListGetReqCtx(s32 offset, s32 count);
        virtual void update();  // vtable slot 8
        virtual void request();  // vtable slot 9
        void setTotal(s32 total);
        void addNotifyAppInfo(nCaplink::cNotifyAppInfo* info);
    private:
        MtString mUniqueId;  // offset: 0x68
        s32 mOffset;  // offset: 0x70
        s32 mCount;  // offset: 0x74
        s32 mTotal;  // offset: 0x78
        MtArray mNotifyAppInfoTbl;  // offset: 0x80
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline void* nCaplink::NotifyAppListGetReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nCaplink::NotifyAppListGetReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::NotifyAppListGetReqCtx::DTI)->memFree(p_addr);
}
