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
namespace nCaplink { class NotifyAns; }
namespace nCaplink { class NotifyReqCtx; }

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
    class NotifyAns : public nCaplink::ContextListener
    {
        friend class ::sCaplinkManager;
    public:
        NotifyAns();
        virtual void init();  // vtable slot 6
        s32 getFriendTotal() const;
        s32 getFriendTagContentTotal() const;
        s32 getFriendTagFreeTotal() const;
        s32 getFriendRequestReceiveTotal() const;
        s32 getTagTotal() const;
        s32 getContentInviteTotal() const;
        s32 getLastPostId() const;
        s32 getAppNotifyTotal() const;
        s32 getStampTotal() const;
        s8 getStampUpdate() const;
        s32 getContentTotal() const;
        s8 getContentUpdate() const;
        s32 getResourcePresetTotal() const;
        s8 getResourcePresetUpdate() const;
        s8 getProfileUpdate() const;
        MT_CTSTR getNextDatetime() const;
        s32 getInterval() const;
        MT_CTSTR getMantenanceFromDatetime() const;
        void setFriendTotal(s32 friend_total);
        void setFriendTagContentTotal(s32 friend_tag_content_total);
        void setFriendTagFreeTotal(s32 friend_tag_free_total);
        void setFriendRequestReceiveTotal(s32 friend_request_recv_total);
        void setTagTotal(s32 tag_total);
        void setContentInviteTotal(s32 content_invite_total);
        void setLastPostId(s32 last_post_id);
        void setAppNotifyTotal(s32 app_notify_total);
        void setStampTotal(s32 stamp_total);
        void setStampUpdate(s8 stamp_update);
        void setContentTotal(s32 content_total);
        void setContentUpdate(s8 content_update);
        void setResourcePresetTotal(s32 resource_preset_total);
        void setResourcePresetUpdate(s8 resource_preset_update);
        void setProfileUpdate(s8 profile_update);
        void setNextDatetime(MT_CTSTR next_datetime);
        void setInterval(s32 interval);
        void setMantenanceFromDatetime(MT_CTSTR mantenance_from_datetime);
    private:
        s32 mFriendTotal;  // offset: 0x20
        s32 mFriendTagContentTotal;  // offset: 0x24
        s32 mFriendTagFreeTotal;  // offset: 0x28
        s32 mFriendRequestReceiveTotal;  // offset: 0x2c
        s32 mTagTotal;  // offset: 0x30
        s32 mContentInviteTotal;  // offset: 0x34
        s32 mLastPostId;  // offset: 0x38
        s32 mAppNotifyTotal;  // offset: 0x3c
        s32 mStampTotal;  // offset: 0x40
        s8 mStampUpdate;  // offset: 0x44
        s32 mContentTotal;  // offset: 0x48
        s8 mContentUpdate;  // offset: 0x4c
        s32 mResourcePresetTotal;  // offset: 0x50
        s8 mResourcePresetUpdate;  // offset: 0x54
        s8 mProfileUpdate;  // offset: 0x55
        MtString mNextDatetime;  // offset: 0x58
        s32 mInterval;  // offset: 0x60
        MtString mMantenanceFromDatetime;  // offset: 0x68
    };
}  // namespace nCaplink

namespace nCaplink {
    class NotifyReqCtx : public nCaplink::HttpRequestContext
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
            void setParent(nCaplink::NotifyReqCtx* parent);
            virtual void fieldName(MT_CTSTR chars, const u32 length);  // vtable slot 6
            virtual void string(MT_CTSTR chars, const u32 length);  // vtable slot 7
            virtual void number(u64 value);  // vtable slot 8
            virtual void number(s64 value);  // vtable slot 9
            virtual void number(f64 value);  // vtable slot 10
        private:
            bool mbFriendTotal;  // offset: 0x9
            bool mbFriendTagContentTotal;  // offset: 0xa
            bool mbFriendTagFreeTotal;  // offset: 0xb
            bool mbFriendRequestReceiveTotal;  // offset: 0xc
            bool mbTagTotal;  // offset: 0xd
            bool mbContentInviteTotal;  // offset: 0xe
            bool mbLastPostId;  // offset: 0xf
            bool mbAppNotifyTotal;  // offset: 0x10
            bool mbStampTotal;  // offset: 0x11
            bool mbStampUpdate;  // offset: 0x12
            bool mbContentTotal;  // offset: 0x13
            bool mbContentUpdate;  // offset: 0x14
            bool mbResourcePresetTotal;  // offset: 0x15
            bool mbResourcePresetUpdate;  // offset: 0x16
            bool mbProfileUpdate;  // offset: 0x17
            bool mbNextDatetime;  // offset: 0x18
            bool mbInterval;  // offset: 0x19
            bool mbMantenanceFromDatetime;  // offset: 0x1a
            bool mbCode;  // offset: 0x1b
            bool mbDetailMessage;  // offset: 0x1c
            nCaplink::NotifyReqCtx* mpParent;  // offset: 0x20
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
        NotifyReqCtx();
        NotifyReqCtx(MT_CTSTR friend_from_datetime, MT_CTSTR friend_tag_content_from_datetime, MT_CTSTR friend_tag_free_from_datetime, MT_CTSTR friend_request_receive_from_datetime, MT_CTSTR tag_from_datetime, MT_CTSTR content_invite_from_datetime, MT_CTSTR stamp_from_datetime, MT_CTSTR content_from_datetime, MT_CTSTR resource_preset_from_datetime, MT_CTSTR profile_from_datetime);
        virtual void update();  // vtable slot 8
        void setFriendTotal(s32 friend_total);
        void setFriendTagContentTotal(s32 friend_tag_content_total);
        void setFriendTagFreeTotal(s32 friend_tag_free_total);
        void setFriendRequestReceiveTotal(s32 friend_request_recv_total);
        void setTagTotal(s32 tag_total);
        void setContentInviteTotal(s32 content_invite_total);
        void setLastPostId(s32 last_post_id);
        void setAppNotifyTotal(s32 app_notify_total);
        void setStampTotal(s32 stamp_total);
        void setStampUpdate(s8 stamp_update);
        void setContentTotal(s32 content_total);
        void setContentUpdate(s8 content_update);
        void setResourcePresetTotal(s32 resource_preset_total);
        void setResourcePresetUpdate(s8 resource_preset_update);
        void setProfileUpdate(s8 profile_update);
        void setNextDatetime(MT_CTSTR next_datetime);
        void setInterval(s32 interval);
        void setMantenanceFromDatetime(MT_CTSTR mantenance_from_datetime);
    private:
        virtual void request();  // vtable slot 9
    private:
        MtString mFriendFromDatetime;  // offset: 0x68
        MtString mFriendTagContentFromDatetime;  // offset: 0x70
        MtString mFriendTagFreeFromDatetime;  // offset: 0x78
        MtString mFriendRequestReceiveFromDatetime;  // offset: 0x80
        MtString mTagFromDatetime;  // offset: 0x88
        MtString mContentInviteFromDatetime;  // offset: 0x90
        MtString mStampFromDatetime;  // offset: 0x98
        MtString mContentFromDatetime;  // offset: 0xa0
        MtString mResourcePresetFromDatetime;  // offset: 0xa8
        MtString mProfileFromDatetime;  // offset: 0xb0
        s32 mFriendTotal;  // offset: 0xb8
        s32 mFriendTagContentTotal;  // offset: 0xbc
        s32 mFriendTagFreeTotal;  // offset: 0xc0
        s32 mFriendRequestReceiveTotal;  // offset: 0xc4
        s32 mTagTotal;  // offset: 0xc8
        s32 mContentInviteTotal;  // offset: 0xcc
        s32 mLastPostId;  // offset: 0xd0
        s32 mAppNotifyTotal;  // offset: 0xd4
        s32 mStampTotal;  // offset: 0xd8
        s8 mStampUpdate;  // offset: 0xdc
        s32 mContentTotal;  // offset: 0xe0
        s8 mContentUpdate;  // offset: 0xe4
        s32 mResourcePresetTotal;  // offset: 0xe8
        s8 mResourcePresetUpdate;  // offset: 0xec
        s8 mProfileUpdate;  // offset: 0xed
        MtString mNextDatetime;  // offset: 0xf0
        s32 mInterval;  // offset: 0xf8
        MtString mMantenanceFromDatetime;  // offset: 0x100
    public:
        static MyDTI DTI;
    };
}  // namespace nCaplink

inline void* nCaplink::NotifyReqCtx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nCaplink::NotifyReqCtx::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nCaplink::NotifyReqCtx::DTI)->memFree(p_addr);
}
