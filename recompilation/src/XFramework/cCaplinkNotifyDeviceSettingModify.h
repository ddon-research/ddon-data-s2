#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "cCaplinkContext.h"

// Declarations
namespace nCaplink { class NotifyDeviceSettingModifyAns; }

namespace nCaplink {
    class NotifyDeviceSettingModifyAns : public nCaplink::ContextListener
    {
    public:
        NotifyDeviceSettingModifyAns();
        virtual void init();  // vtable slot 6
    };
}  // namespace nCaplink
