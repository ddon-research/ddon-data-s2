#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtJsonReader.h"
#include "../MT/MtString.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class sCaplinkManager;

// Declarations
namespace nCaplink { class FriendReleaseAns; }
namespace nCaplink { class FriendReleaseReqCtx; }

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
    class FriendReleaseAns : public nCaplink::ContextListener
    {
        friend class ::sCaplinkManager;
    public:
        FriendReleaseAns();
        virtual void init();  // vtable slot 6
        void setTotal(s32 total);
        void setLimmit(s32 limmit);
        s32 getTotal();
        s32 getLimmit();
    private:
        s32 mTotal;  // offset: 0x20
        s32 mLimmit;  // offset: 0x24
    };
}  // namespace nCaplink

namespace nCaplink {
    class FriendReleaseReqCtx : public nCaplink::HttpRequestContext
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
            void setParent(nCaplink::FriendReleaseReqCtx* parent);
            virtual void fieldName(MT_CTSTR chars, const u32 length);  // vtable slot 6
            virtual void string(MT_CTSTR chars, const u32 length);  // vtable slot 7
            virtual void number(u64 value);  // vtable slot 8
            virtual void number(s64 value);  // vtable slot 9
            virtual void number(f64 value);  // vtable slot 10
        private:
            bool mbTotal;  // offset: 0x9
            bool mbLimmit;  // offset: 0xa
            bool mbCode;  // offset: 0xb
            bool mbDetailMessage;  // offset: 0xc
            nCaplink::FriendReleaseReqCtx* mpParent;  // offset: 0x10
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
        FriendReleaseReqCtx();
        FriendReleaseReqCtx(MT_CTSTR unique_id);
        virtual void update();  // vtable slot 8
        virtual void request();  // vtable slot 9
        void setTotal(s32 total);
        void setLimmit(s32 limmit);
    private:
        MtString mUniqueId;  // offset: 0x68
        s32 mTotal;  // offset: 0x70
        s32 mLimmit;  // offset: 0x74
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline void* nCaplink::FriendReleaseReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline nCaplink::FriendReleaseReqCtx::FriendReleaseReqCtx() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nCaplink::FriendReleaseReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::FriendReleaseReqCtx::DTI)->memFree(p_addr);
}
