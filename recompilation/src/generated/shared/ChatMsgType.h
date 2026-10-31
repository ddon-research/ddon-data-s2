#pragma once

#include <cstdint>
#include <cstddef>

namespace nChatMsgType {
    enum E_CHAT_MSG_TYPE
    {
        CHAT_MSG_TYPE_SAY = 0,
        CHAT_MSG_TYPE_SHOUT = 1,
        CHAT_MSG_TYPE_TELL = 2,
        CHAT_MSG_TYPE_SYSTEM = 3,
        CHAT_MSG_TYPE_PARTY = 4,
        CHAT_MSG_TYPE_SHOUT_ALL = 5,
        CHAT_MSG_TYPE_GROUP = 6,
        CHAT_MSG_TYPE_CLAN = 7,
        CHAT_MSG_TYPE_ENTRYBOARD = 8,
        CHAT_MSG_TYPE_MANAGEMENT_GUIDE_C = 9,
        CHAT_MSG_TYPE_MANAGEMENT_GUIDE_N = 10,
        CHAT_MSG_TYPE_MANAGEMENT_ALERT_C = 11,
        CHAT_MSG_TYPE_MANAGEMENT_ALERT_N = 12,
        CHAT_MSG_TYPE_CLAN_NOTICE = 13,
    };
}  // namespace nChatMsgType
