#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class TagVisibleModifyAns; }

namespace nCaplink {
    class TagVisibleModifyAns : public nCaplink::ContextListener
    {
    public:
        TagVisibleModifyAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink
