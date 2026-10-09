#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class ChatReadAns; }

namespace nCaplink {
    class ChatReadAns : public nCaplink::ContextListener
    {
    public:
        ChatReadAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink
