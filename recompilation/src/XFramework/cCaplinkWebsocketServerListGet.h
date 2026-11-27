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
namespace nCaplink { class cWebsocketServerInfo; }

// Declarations
namespace nCaplink { class WebsocketServerListGetAns; }
namespace nCaplink { class WebsocketServerListGetReqCtx; }

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
    class WebsocketServerListGetAns : public nCaplink::ContextListener
    {
    public:
        WebsocketServerListGetAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setWebsocketServerInfoTbl(MtArray* user_list);
        s32 getTotal() const;
        u32 getWebsocketServerInfoCount() const;
        nCaplink::cWebsocketServerInfo* getWebsocketServerInfo(s32 index) const;
    private:
        s32 mTotal;  // offset: 0x20
        MtArray mWebsocketServerInfoTbl;  // offset: 0x28
    };
}  // namespace nCaplink

namespace nCaplink {
    class WebsocketServerListGetReqCtx : public nCaplink::HttpRequestContext
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
            void setParent(nCaplink::WebsocketServerListGetReqCtx* parent);
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
            bool mbHostname;  // offset: 0xb
            bool mbPort;  // offset: 0xc
            bool mbPath;  // offset: 0xd
            bool mbLoadaverage;  // offset: 0xe
            bool mbConnections;  // offset: 0xf
            bool mbLastLifeDatetime;  // offset: 0x10
            bool mbCode;  // offset: 0x11
            bool mbDetailMessage;  // offset: 0x12
            MtString mHostname;  // offset: 0x18
            s32 mPort;  // offset: 0x20
            MtString mPath;  // offset: 0x28
            s32 mLoadaverage;  // offset: 0x30
            s32 mConnections;  // offset: 0x34
            MtString mLastLifeDatetime;  // offset: 0x38
            nCaplink::WebsocketServerListGetReqCtx* mpParent;  // offset: 0x40
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
        WebsocketServerListGetReqCtx();
        virtual void update();  // vtable slot 8
        virtual void request();  // vtable slot 9
        void setTotal(s32 total);
        void addWebsocketServerInfo(nCaplink::cWebsocketServerInfo* info);
    private:
        s32 mTotal;  // offset: 0x68
        MtArray mWebsocketServerInfoTbl;  // offset: 0x70
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline void* nCaplink::WebsocketServerListGetReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nCaplink::WebsocketServerListGetReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::WebsocketServerListGetReqCtx::DTI)->memFree(p_addr);
}
