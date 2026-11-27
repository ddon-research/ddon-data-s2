#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "nPhysicsMathVector4.h"

// Forward declarations
namespace nPhysics { namespace Math { class Vector3; } }
namespace nPhysics { namespace Math { class Vector4; } }

// Declarations
namespace nPhysics { class POWER; }

// Type aliases from DWARF
using u32 = unsigned int;

namespace nPhysics {
    class POWER
    {
    public:
        void add_force(const nPhysics::Math::Vector4& force);
        void add_torque(const nPhysics::Math::Vector4& torque);
        nPhysics::Math::Vector3 get_force();
        nPhysics::Math::Vector3 get_torque();
    private:
        nPhysics::Math::Vector4 Force[4];  // offset: 0x0
        nPhysics::Math::Vector4 Torque[4];  // offset: 0x40
        static const u32 MAX_STACK_OF_FORCE = 4;
        static const u32 MAX_STACK_OF_TORQUE = 4;
    };
}  // namespace nPhysics
