#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class FriendEntryCancelAns; }

namespace nCaplink {
    class FriendEntryCancelAns : public nCaplink::ContextListener
    {
    public:
        FriendEntryCancelAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink
