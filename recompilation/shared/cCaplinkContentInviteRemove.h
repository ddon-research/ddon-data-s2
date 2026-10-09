#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class ContentInviteRemoveAns; }

namespace nCaplink {
    class ContentInviteRemoveAns : public nCaplink::ContextListener
    {
    public:
        ContentInviteRemoveAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink
