#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class UserProfileContentModifyAns; }

namespace nCaplink {
    class UserProfileContentModifyAns : public nCaplink::ContextListener
    {
    public:
        UserProfileContentModifyAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink
