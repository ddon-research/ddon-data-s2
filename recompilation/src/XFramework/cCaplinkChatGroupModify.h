#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class ChatGroupModifyAns; }

namespace nCaplink {
    class ChatGroupModifyAns : public nCaplink::ContextListener
    {
    public:
        ChatGroupModifyAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink
