#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class NotifyTimeModifyAns; }

namespace nCaplink {
    class NotifyTimeModifyAns : public nCaplink::ContextListener
    {
    public:
        NotifyTimeModifyAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink
