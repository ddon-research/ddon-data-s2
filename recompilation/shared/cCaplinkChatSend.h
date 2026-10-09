#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtString.h"
#include "cCaplinkContext.h"

// Forward declarations
class MtString;

// Declarations
namespace nCaplink { class ChatSendAns; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using s32 = int;

namespace nCaplink {
    class ChatSendAns : public nCaplink::ContextListener
    {
    public:
        ChatSendAns();
        virtual void init();  // vtable slot 6
        void setChatId(s32 chat_id);
        void setChatMessage(MT_CTSTR message);
        s32 getChatId() const;
        MT_CTSTR getChatMessage() const;
    private:
        s32 mChatId;  // offset: 0x20
        MtString mChatMessage;  // offset: 0x28
    };
}  // namespace nCaplink
