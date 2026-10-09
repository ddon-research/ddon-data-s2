#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class ChatGroupMemberLeaveAns; }

namespace nCaplink {
    class ChatGroupMemberLeaveAns : public nCaplink::ContextListener
    {
    public:
        ChatGroupMemberLeaveAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink
