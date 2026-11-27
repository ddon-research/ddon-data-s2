#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "nPhysicsMathVector3.h"

// Forward declarations
class MtMatrix;
namespace nPhysics { namespace Math { class Matrix; } }
namespace nPhysics { namespace Math { class Quaternion; } }
namespace nPhysics { namespace Math { class Vector3; } }

// Declarations
namespace nPhysics { namespace Math { class Matrix3; } }

// Type aliases from DWARF
using f32 = float;
using u32 = unsigned int;

namespace nPhysics {
    namespace Math {
        class Matrix3
        {
        public:
            Matrix3();
            Matrix3(const MtMatrix& value);
            Matrix3(const nPhysics::Math::Vector3& value);
            Matrix3(const nPhysics::Math::Vector3& value1, const nPhysics::Math::Vector3& value2, const nPhysics::Math::Vector3& value3);
            Matrix3(const nPhysics::Math::Matrix3& value);
            Matrix3(const nPhysics::Math::Matrix& value);
            Matrix3(const nPhysics::Math::Quaternion& value);
            ~Matrix3();
            void load(const MtMatrix& value);
            void load(const nPhysics::Math::Vector3& value);
            void load(const nPhysics::Math::Vector3& value1, const nPhysics::Math::Vector3& value2, const nPhysics::Math::Vector3& value3);
            void load(const nPhysics::Math::Matrix3& value);
            void load(const nPhysics::Math::Matrix& value);
            void load(const nPhysics::Math::Quaternion& value);
            void operator=(const nPhysics::Math::Quaternion&);
            void operator=(const nPhysics::Math::Matrix3& value);
            void operator+=(const nPhysics::Math::Matrix3& value);
            void operator*=(const f32 value);
            void operator*=(const nPhysics::Math::Vector3& value);
            nPhysics::Math::Matrix3 operator+(const nPhysics::Math::Matrix3& value) const;
            nPhysics::Math::Matrix3 operator*(const nPhysics::Math::Matrix3& value) const;
            nPhysics::Math::Matrix3 operator*(const f32) const;
            nPhysics::Math::Matrix3 operator*(const nPhysics::Math::Vector3& value) const;
            nPhysics::Math::Vector3& operator[](const u32 index);
            const nPhysics::Math::Vector3& operator[](const u32 index) const;
            void identity();
            void setRotation(const nPhysics::Math::Quaternion& rotation);
            nPhysics::Math::Matrix3 transpose() const;
            nPhysics::Math::Matrix3 orthogonalize() const;
            nPhysics::Math::Quaternion convert() const;
        private:
            nPhysics::Math::Vector3 mInstance[3];  // offset: 0x0
        };
    }  // namespace Math
}  // namespace nPhysics

inline nPhysics::Math::Matrix3::Matrix3() {
}
