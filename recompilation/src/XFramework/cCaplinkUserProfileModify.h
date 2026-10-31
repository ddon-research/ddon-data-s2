#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class UserProfileModifyAns; }

namespace nCaplink {
    class UserProfileModifyAns : public nCaplink::ContextListener
    {
    public:
        UserProfileModifyAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink
