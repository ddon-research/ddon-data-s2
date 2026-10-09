#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class FriendEntryReplyAns; }

namespace nCaplink {
    class FriendEntryReplyAns : public nCaplink::ContextListener
    {
    public:
        FriendEntryReplyAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink
