#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
namespace nPhysics { namespace Listener { class Status; } }

namespace nPhysics {
    namespace Listener {
        class Status
        {
        public:
            virtual void callbackSleep();  // vtable slot 2
            virtual void callbackWakeup();  // vtable slot 3
        };
    }  // namespace Listener
}  // namespace nPhysics
