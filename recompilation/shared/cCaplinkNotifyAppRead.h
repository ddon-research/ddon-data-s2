#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class NotifyAppReadAns; }

namespace nCaplink {
    class NotifyAppReadAns : public nCaplink::ContextListener
    {
    public:
        NotifyAppReadAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink
