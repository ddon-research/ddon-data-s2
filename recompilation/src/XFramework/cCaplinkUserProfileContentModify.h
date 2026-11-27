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

// Declarations
namespace nCaplink { class UserProfileContentModifyAns; }
namespace nCaplink { class UserProfileContentModifyReqCtx; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __int64_t = long int;
using __uint64_t = long unsigned int;
using f64 = double;
using s64 = __int64_t;
using s8 = signed char;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

namespace nCaplink {
    class UserProfileContentModifyAns : public nCaplink::ContextListener
    {
    public:
        UserProfileContentModifyAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink

namespace nCaplink {
    class UserProfileContentModifyReqCtx : public nCaplink::HttpRequestContext
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
            void setParent(nCaplink::UserProfileContentModifyReqCtx* parent);
            virtual void fieldName(MT_CTSTR chars, const u32 length);  // vtable slot 6
            virtual void string(MT_CTSTR chars, const u32 length);  // vtable slot 7
            virtual void number(u64 value);  // vtable slot 8
            virtual void number(s64 value);  // vtable slot 9
            virtual void number(f64 value);  // vtable slot 10
        private:
            bool mbCode;  // offset: 0x9
            bool mbDetailMessage;  // offset: 0xa
            nCaplink::UserProfileContentModifyReqCtx* mpParent;  // offset: 0x10
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
        UserProfileContentModifyReqCtx();
        UserProfileContentModifyReqCtx(MT_CTSTR content_id, MT_CTSTR character_id, MT_CTSTR comment, s8 online_privacy, s8 visible);
        virtual void update();  // vtable slot 8
        virtual void request();  // vtable slot 9
    private:
        MtString mContentId;  // offset: 0x68
        MtString mCharacterName;  // offset: 0x70
        MtString mComment;  // offset: 0x78
        s8 mOnlinePrivacy;  // offset: 0x80
        s8 mVisible;  // offset: 0x81
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline void* nCaplink::UserProfileContentModifyReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline nCaplink::UserProfileContentModifyReqCtx::UserProfileContentModifyReqCtx() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nCaplink::UserProfileContentModifyReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::UserProfileContentModifyReqCtx::DTI)->memFree(p_addr);
}
