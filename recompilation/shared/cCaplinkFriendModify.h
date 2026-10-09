#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class FriendModifyAns; }

namespace nCaplink {
    class FriendModifyAns : public nCaplink::ContextListener
    {
    public:
        FriendModifyAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink
