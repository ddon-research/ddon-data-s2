#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtString.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtArray;
class MtString;
namespace nCaplink { class cChatUserInfo; }

// Declarations
namespace nCaplink { class ChatListGetAns; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using s32 = int;
using u32 = unsigned int;

namespace nCaplink {
    class ChatListGetAns : public nCaplink::ContextListener
    {
    public:
        ChatListGetAns();
        virtual void init();  // vtable slot 6
        void setChatGroupInfo(s32 status, MT_CTSTR group_name, s32 member_total, s32 member_limmit, s32 last_chat_id);
        void setChatUserInfoTbl(MtArray* user_list);
        s32 getChatStatus() const;
        MT_CTSTR getChatGroupName() const;
        s32 getChatMemberTotal() const;
        s32 getChatMemberLimmit() const;
        s32 getChatLastChatId() const;
        u32 getChatUserCount() const;
        nCaplink::cChatUserInfo* getChatUserInfo(s32 index) const;
    private:
        s32 mChatStatus;  // offset: 0x20
        MtString mChatGroupName;  // offset: 0x28
        s32 mChatMemberTotal;  // offset: 0x30
        s32 mChatMemberLimmit;  // offset: 0x34
        s32 mChatLastChatId;  // offset: 0x38
        MtArray mChatUserInfoTbl;  // offset: 0x40
    };
}  // namespace nCaplink
