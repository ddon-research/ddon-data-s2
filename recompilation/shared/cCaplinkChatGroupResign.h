#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class ChatGroupResignAns; }

namespace nCaplink {
    class ChatGroupResignAns : public nCaplink::ContextListener
    {
    public:
        ChatGroupResignAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink
