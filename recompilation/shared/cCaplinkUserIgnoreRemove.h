#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class UserIgnoreRemoveAns; }

namespace nCaplink {
    class UserIgnoreRemoveAns : public nCaplink::ContextListener
    {
    public:
        UserIgnoreRemoveAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink
