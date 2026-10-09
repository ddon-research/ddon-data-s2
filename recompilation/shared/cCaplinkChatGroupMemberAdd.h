#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class ChatGroupMemberAddAns; }

namespace nCaplink {
    class ChatGroupMemberAddAns : public nCaplink::ContextListener
    {
    public:
        ChatGroupMemberAddAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink
