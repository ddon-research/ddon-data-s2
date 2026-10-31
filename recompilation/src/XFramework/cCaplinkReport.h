#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class ReportAns; }

namespace nCaplink {
    class ReportAns : public nCaplink::ContextListener
    {
    public:
        ReportAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink
