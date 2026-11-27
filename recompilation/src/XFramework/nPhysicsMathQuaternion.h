#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
struct MtFloat4A;
class MtQuaternion;
namespace nPhysics { namespace Math { class Vector3; } }
namespace nPhysics { namespace Math { class Vector4; } }

// Declarations
namespace nPhysics { namespace Math { class Quaternion; } }

// Type aliases from DWARF
using f32 = float;

namespace nPhysics {
    namespace Math {
        class Quaternion
        {
        public:
            Quaternion();
            Quaternion(const f32 x, const f32 y, const f32 z, const f32 w);
            Quaternion(const nPhysics::Math::Vector3& base_direction, const nPhysics::Math::Vector3& target_direction);
            Quaternion(const f32* value);
            Quaternion(const nPhysics::Math::Vector4& value);
            Quaternion(const MtQuaternion& value);
            Quaternion(const MtFloat4A& value);
            ~Quaternion();
            void load(const f32* value);
            void load(const MtQuaternion& value);
            void load(const MtFloat4A& value);
            void load(const nPhysics::Math::Vector4& value);
            void load(const nPhysics::Math::Quaternion& value);
            void store(MtFloat4A& output) const;
            operator MtQuaternion() const;
            void operator=(const MtQuaternion& value);
            void operator=(const MtFloat4A&);
            void operator=(const nPhysics::Math::Vector4&);
            void operator=(const nPhysics::Math::Quaternion& value);
            void operator+=(const nPhysics::Math::Quaternion&);
            void operator*=(const nPhysics::Math::Quaternion& value);
            nPhysics::Math::Quaternion operator*(const nPhysics::Math::Quaternion& value) const;
            void store(MtQuaternion& output) const;
            f32 getX() const;
            f32 getY() const;
            f32 getZ() const;
            f32 getW() const;
            void setX(const f32);
            void setY(const f32);
            void setZ(const f32);
            void setW(const f32);
            f32 dot(const nPhysics::Math::Quaternion& value) const;
            void slerp(const nPhysics::Math::Quaternion& start, const nPhysics::Math::Quaternion& end, const f32 t);
            nPhysics::Math::Quaternion conjugate() const;
            nPhysics::Math::Quaternion normalize() const;
            void identity();
            nPhysics::Math::Quaternion multiply(const nPhysics::Math::Vector3& value);
            void rotationDirection(const nPhysics::Math::Vector3& base_direction, const nPhysics::Math::Vector3& target_direction);
            void rotationMinimum();
            void getRotationAxis(nPhysics::Math::Vector3& output_axis, f32& output_angle) const;
            nPhysics::Math::Vector3 getDirection() const;
            nPhysics::Math::Vector3 get_angular_velocity() const;
            static void check(const nPhysics::Math::Quaternion&);
        private:
            f32 X;  // offset: 0x0
            f32 Y;  // offset: 0x4
            f32 Z;  // offset: 0x8
            f32 W;  // offset: 0xc
        };
    }  // namespace Math
}  // namespace nPhysics

inline nPhysics::Math::Quaternion::Quaternion() {
}
