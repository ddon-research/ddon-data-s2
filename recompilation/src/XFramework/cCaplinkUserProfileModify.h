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
namespace nCaplink { class UserProfileModifyAns; }
namespace nCaplink { class UserProfileModifyReqCtx; }

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
    class UserProfileModifyAns : public nCaplink::ContextListener
    {
    public:
        UserProfileModifyAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink

namespace nCaplink {
    class UserProfileModifyReqCtx : public nCaplink::HttpRequestContext
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
            void setParent(nCaplink::UserProfileModifyReqCtx* parent);
            virtual void fieldName(MT_CTSTR chars, const u32 length);  // vtable slot 6
            virtual void string(MT_CTSTR chars, const u32 length);  // vtable slot 7
            virtual void number(u64 value);  // vtable slot 8
            virtual void number(s64 value);  // vtable slot 9
            virtual void number(f64 value);  // vtable slot 10
        private:
            bool mbCode;  // offset: 0x9
            bool mbDetailMessage;  // offset: 0xa
            nCaplink::UserProfileModifyReqCtx* mpParent;  // offset: 0x10
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
        UserProfileModifyReqCtx();
        UserProfileModifyReqCtx(MT_CTSTR nickname, s32 icon_id, MT_CTSTR comment, s32 timeline_skin_id, s32 profile_skin_id, s8 timeline_privacy, s8 profile_privacy, s8 captalk_privacy, s8 find_search);
        virtual void update();  // vtable slot 8
        virtual void request();  // vtable slot 9
    private:
        MtString mUniqueId;  // offset: 0x68
        MtString mNickname;  // offset: 0x70
        s32 mIconId;  // offset: 0x78
        MtString mComment;  // offset: 0x80
        s32 mTimelineSkinId;  // offset: 0x88
        s32 mProfileSkinId;  // offset: 0x8c
        s8 mTimelinePrivacy;  // offset: 0x90
        s8 mProfilePrivacy;  // offset: 0x91
        s8 mCaptalkPrivacy;  // offset: 0x92
        s8 mFindSearch;  // offset: 0x93
        s8 mAlive;  // offset: 0x94
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline void* nCaplink::UserProfileModifyReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline nCaplink::UserProfileModifyReqCtx::UserProfileModifyReqCtx() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nCaplink::UserProfileModifyReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::UserProfileModifyReqCtx::DTI)->memFree(p_addr);
}
