#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "nPhysicsMathVector4.h"

// Forward declarations
namespace nPhysics { namespace Math { class Quaternion; } }
namespace nPhysics { namespace Math { class Vector3; } }
namespace nPhysics { namespace Math { class Vector4; } }

// Declarations
namespace nPhysics { namespace Math { class Matrix; } }

// Type aliases from DWARF
using u32 = unsigned int;

namespace nPhysics {
    namespace Math {
        class Matrix
        {
        public:
            Matrix();
            Matrix(const nPhysics::Math::Vector4&, const nPhysics::Math::Vector4&, const nPhysics::Math::Vector4&, const nPhysics::Math::Vector4&);
            Matrix(const nPhysics::Math::Quaternion& rotation, const nPhysics::Math::Vector3& position);
            ~Matrix();
            void operator=(const nPhysics::Math::Matrix&);
            nPhysics::Math::Vector4& operator[](const u32);
            const nPhysics::Math::Vector4& operator[](const u32 index) const;
            void identity();
            void set(const nPhysics::Math::Quaternion& rotation, const nPhysics::Math::Vector3& position);
            void set(const nPhysics::Math::Vector3&);
            void set(const nPhysics::Math::Quaternion&);
        private:
            nPhysics::Math::Vector4 mInstance[4];  // offset: 0x0
        };
    }  // namespace Math
}  // namespace nPhysics

inline nPhysics::Math::Matrix::Matrix() {
}
