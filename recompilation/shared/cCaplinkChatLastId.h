#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class ChatLastIdAns; }

// Type aliases from DWARF
using s32 = int;

namespace nCaplink {
    class ChatLastIdAns : public nCaplink::ContextListener
    {
    public:
        ChatLastIdAns();
        virtual void init();  // vtable slot 6
        void setLastChatId(s32 last_chat_id);
        s32 getLastChatId() const;
    private:
        s32 mLastChatId;  // offset: 0x20
    };
}  // namespace nCaplink
