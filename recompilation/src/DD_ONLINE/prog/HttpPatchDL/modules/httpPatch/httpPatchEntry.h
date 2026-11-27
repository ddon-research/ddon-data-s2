#pragma once

#include <cstdint>
#include <cstddef>

namespace via {
namespace module {
    enum ModuleError_Type
    {
        ModuleError_None = 0,
        ModuleError_Critical = 1,
        ModuleError_NoMemory = 2,
        ModuleError_CreateFailed = 3,
    };
}  // namespace module
}  // namespace via

// Declarations
namespace via { class HttpPatchModule; }

namespace via {
    class HttpPatchModule
    {
    public:
        HttpPatchModule();
        ~HttpPatchModule();
        via::module::ModuleError_Type initialize();
        via::module::ModuleError_Type terminate();
        void update();
    };
}  // namespace via

inline via::HttpPatchModule::HttpPatchModule() {
}
