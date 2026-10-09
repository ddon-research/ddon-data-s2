#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtString.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtString;

// Declarations
namespace nCaplink { class NotifyAns; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using s32 = int;
using s8 = signed char;

namespace nCaplink {
    class NotifyAns : public nCaplink::ContextListener
    {
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
