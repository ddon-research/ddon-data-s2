#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class ChatGroupRemoveAns; }

namespace nCaplink {
    class ChatGroupRemoveAns : public nCaplink::ContextListener
    {
    public:
        ChatGroupRemoveAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink
