#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtJsonReader.h"
#include "../MT/MtString.h"
#include "cCaplinkContext.h"
#include "cCaplinkDataDef.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
namespace nCaplink { class cUserProfile; }
class sCaplinkManager;
class uGUICaplinkProfile;

// Declarations
namespace nCaplink { class UserProfileGetAns; }
namespace nCaplink { class UserProfileGetReqCtx; }

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
    class UserProfileGetAns : public nCaplink::ContextListener
    {
        friend class ::sCaplinkManager;
        friend class ::uGUICaplinkProfile;
    public:
        UserProfileGetAns();
        virtual void init();  // vtable slot 6
        const nCaplink::cUserProfile* getUserProfile() const;
        void setUserProfile(const nCaplink::cUserProfile& user_profile);
    private:
        nCaplink::cUserProfile mUserProfile;  // offset: 0x20
    };
}  // namespace nCaplink

namespace nCaplink {
    class UserProfileGetReqCtx : public nCaplink::HttpRequestContext
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
            void setParent(nCaplink::UserProfileGetReqCtx* parent);
            virtual void fieldName(MT_CTSTR chars, const u32 length);  // vtable slot 6
            virtual void string(MT_CTSTR chars, const u32 length);  // vtable slot 7
            virtual void number(u64 value);  // vtable slot 8
            virtual void number(s64 value);  // vtable slot 9
            virtual void number(f64 value);  // vtable slot 10
        private:
            bool mbUniqueId;  // offset: 0x9
            bool mbNickname;  // offset: 0xa
            bool mbIcon;  // offset: 0xb
            bool mbIcon_s;  // offset: 0xc
            bool mbComment;  // offset: 0xd
            bool mbTimelineSkinId;  // offset: 0xe
            bool mbTimelineSkinUrl;  // offset: 0xf
            bool mbProfileSkinId;  // offset: 0x10
            bool mbProfileSkinUrl;  // offset: 0x11
            bool mbContentTotal;  // offset: 0x12
            bool mbTimelinePrivacy;  // offset: 0x13
            bool mbProfilePrivacy;  // offset: 0x14
            bool mbCaptalkPrivacy;  // offset: 0x15
            bool mbFindSearch;  // offset: 0x16
            bool mbFriendTotal;  // offset: 0x17
            bool mbTagsTotal;  // offset: 0x18
            bool mbFriendTagsTotal;  // offset: 0x19
            bool mbIgnoresTotal;  // offset: 0x1a
            bool mbCode;  // offset: 0x1b
            bool mbDetailMessage;  // offset: 0x1c
            nCaplink::UserProfileGetReqCtx* mpParent;  // offset: 0x20
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
        UserProfileGetReqCtx();
        UserProfileGetReqCtx(MT_CTSTR unique_id);
        virtual void update();  // vtable slot 8
        virtual void request();  // vtable slot 9
        void setUniqueId(MT_CTSTR unique_id);
        void setNickname(MT_CTSTR nickname);
        void setIcon(MT_CTSTR icon);
        void setIcon_s(MT_CTSTR icon_s);
        void setComment(MT_CTSTR comment);
        void setTimelineSkinId(s32 timeline_skin_id);
        void setTimelineSkinUrl(MT_CTSTR timeline_skin_url);
        void setProfileSkinId(s32 profile_skin_id);
        void setProfileSkinUrl(MT_CTSTR profile_skin_url);
        void setContentTotal(s32 content_total);
        void setTimelinePrivacy(s8 timeline_privacy);
        void setProfilePrivacy(s8 profile_privacy);
        void setCaptalkPrivacy(s8 captalk_privacy);
        void setFindSearch(s8 find_srearch);
        void setFriendsTotal(s32 friends_total);
        void setTagsTotal(s32 tags_total);
        void setFriendTagsTotal(s32 friend_tags_total);
        void setIgnoresTotal(s32 ignores_total);
    private:
        MtString mUniqueId;  // offset: 0x68
        MtString mNickname;  // offset: 0x70
        MtString mIcon;  // offset: 0x78
        MtString mIcon_s;  // offset: 0x80
        MtString mComment;  // offset: 0x88
        s32 mTimelineSkinId;  // offset: 0x90
        MtString mTimelineSkinUrl;  // offset: 0x98
        s32 mProfileSkinId;  // offset: 0xa0
        MtString mProfileSkinUrl;  // offset: 0xa8
        s32 mContentTotal;  // offset: 0xb0
        s8 mTimelinePrivacy;  // offset: 0xb4
        s8 mProfilePrivacy;  // offset: 0xb5
        s8 mCaptalkPrivacy;  // offset: 0xb6
        s8 mFindSearch;  // offset: 0xb7
        s32 mFriendsTotal;  // offset: 0xb8
        s32 mTagsTotal;  // offset: 0xbc
        s32 mFriendTagsTotal;  // offset: 0xc0
        s32 mIgnoresTotal;  // offset: 0xc4
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline void* nCaplink::UserProfileGetReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline nCaplink::UserProfileGetReqCtx::UserProfileGetReqCtx() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nCaplink::UserProfileGetReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::UserProfileGetReqCtx::DTI)->memFree(p_addr);
}
