#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class NotifyDeviceSettingAns; }

// Type aliases from DWARF
using s8 = signed char;

namespace nCaplink {
    class NotifyDeviceSettingAns : public nCaplink::ContextListener
    {
    public:
        NotifyDeviceSettingAns();
        virtual void init();  // vtable slot 6
        void setParam(s8 all, s8 profile, s8 fri, s8 timeline, s8 chat, s8 game);
        s8 getAll() const;
        s8 getProfile() const;
        s8 getFriend() const;
        s8 getTimeline() const;
        s8 getChat() const;
        s8 getGame() const;
    private:
        s8 mAll;  // offset: 0x20
        s8 mProfile;  // offset: 0x21
        s8 mFriend;  // offset: 0x22
        s8 mTimeline;  // offset: 0x23
        s8 mChat;  // offset: 0x24
        s8 mGame;  // offset: 0x25
    };
}  // namespace nCaplink
