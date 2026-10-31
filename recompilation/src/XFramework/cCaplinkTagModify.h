#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class TagModifyAns; }

namespace nCaplink {
    class TagModifyAns : public nCaplink::ContextListener
    {
    public:
        TagModifyAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink
