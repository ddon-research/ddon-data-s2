#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class ChatGroupMemberRejectAns; }

namespace nCaplink {
    class ChatGroupMemberRejectAns : public nCaplink::ContextListener
    {
    public:
        ChatGroupMemberRejectAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink
