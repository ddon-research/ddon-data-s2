#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtString.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtString;

// Declarations
namespace nCaplink { class ChatGroupCreateAns; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using s32 = int;

namespace nCaplink {
    class ChatGroupCreateAns : public nCaplink::ContextListener
    {
    public:
        ChatGroupCreateAns();
        virtual void init();  // vtable slot 6
        void setChatGroupInfo(MT_CTSTR id, MT_CTSTR name, MT_CTSTR owner_unique_id, s32 last_chat_id, s32 member_total, s32 member_limmit, MT_CTSTR update_at);
        MT_CTSTR getGroupId() const;
        MT_CTSTR getGroupName() const;
        MT_CTSTR getOwnerUniqueId() const;
        s32 getLastChatId() const;
        s32 getMemberTotal() const;
        s32 getMemberLimmit() const;
        MT_CTSTR getUpdateAt() const;
    private:
        MtString mGroupId;  // offset: 0x20
        MtString mGroupName;  // offset: 0x28
        MtString mOwnerUniqueId;  // offset: 0x30
        s32 mLastChatId;  // offset: 0x38
        s32 mMemberTotal;  // offset: 0x3c
        s32 mMemberLimit;  // offset: 0x40
        MtString mUpdatedAt;  // offset: 0x48
    };
}  // namespace nCaplink
