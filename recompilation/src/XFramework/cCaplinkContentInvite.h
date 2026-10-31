#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class ContentInviteAns; }

namespace nCaplink {
    class ContentInviteAns : public nCaplink::ContextListener
    {
    public:
        ContentInviteAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink
