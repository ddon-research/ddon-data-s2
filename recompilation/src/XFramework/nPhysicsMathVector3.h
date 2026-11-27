#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
struct MtFloat3A;
struct MtFloat4A;
class MtVector3;
class MtVector4;
namespace nPhysics { namespace Math { class Matrix; } }
namespace nPhysics { namespace Math { class Matrix3; } }
namespace nPhysics { namespace Math { class Quaternion; } }
namespace nPhysics { namespace Math { class Vector4; } }

// Declarations
namespace nPhysics { namespace Math { class Vector3; } }

// Type aliases from DWARF
using f32 = float;
using s16 = short;
using s32 = int;
using u16 = unsigned short;
using u32 = unsigned int;

namespace nPhysics {
    namespace Math {
        class alignas(16) Vector3
        {
        public:
            Vector3();
            Vector3(const f32 x, const f32 y, const f32 z);
            Vector3(const f32* value);
            Vector3(const f32 value);
            Vector3(const u32 value);
            Vector3(const MtVector3& value);
            Vector3(const MtFloat3A& value);
            Vector3(const nPhysics::Math::Vector4& value);
            void load(const f32* value);
            void load(const f32 value);
            void load(const u32 value);
            void load(const MtVector3& value);
            void load(const MtVector4& value);
            void load(const MtFloat3A& value);
            void load(const nPhysics::Math::Vector3& value);
            void load(const nPhysics::Math::Vector4& value);
            void store(MtFloat3A& output) const;
            void store(MtFloat4A& output) const;
            void store(MtVector3& output) const;
            void store(f32* output) const;
            f32 getX() const;
            f32 getY() const;
            f32 getZ() const;
            f32 getW() const;
            u32 getXu() const;
            u32 getYu() const;
            u32 getZu() const;
            u32 getWu() const;
            s32 getXs() const;
            s32 getYs() const;
            s32 getZs() const;
            s32 getWs() const;
            void setX(const f32 value);
            void setY(const f32 value);
            void setZ(const f32 value);
            void setW(const f32 value);
            void setXu(const u32 value);
            void setYu(const u32 value);
            void setZu(const u32);
            void setWu(const u32 value);
            void setXs(const s32);
            void setYs(const s32);
            void setZs(const s32);
            void setWs(const s32 value);
            void setX(const nPhysics::Math::Vector3&);
            void setY(const nPhysics::Math::Vector3&);
            void setZ(const nPhysics::Math::Vector3&);
            void setW(const nPhysics::Math::Vector3& value);
            void clear();
            operator MtVector3() const;
            nPhysics::Math::Vector3 operator-() const;
            void operator=(const f32* value);
            void operator=(const nPhysics::Math::Vector3& value);
            void operator=(const nPhysics::Math::Vector4& value);
            void operator=(const MtVector3& value);
            void operator=(const MtVector4& value);
            void operator=(const MtFloat3A& value);
            void operator+=(const nPhysics::Math::Vector3& value);
            void operator-=(const nPhysics::Math::Vector3& value);
            void operator*=(const nPhysics::Math::Vector3& value);
            void operator*=(const f32 value);
            void operator&=(const nPhysics::Math::Vector3&);
            void operator|=(const nPhysics::Math::Vector3& value);
            void operator^=(const nPhysics::Math::Vector3&);
            nPhysics::Math::Vector3 operator+(const nPhysics::Math::Vector3& value) const;
            nPhysics::Math::Vector3 operator-(const nPhysics::Math::Vector3& value) const;
            nPhysics::Math::Vector3 operator*(const nPhysics::Math::Vector3& value) const;
            nPhysics::Math::Vector3 operator*(const f32 value) const;
            nPhysics::Math::Vector3 operator*(const nPhysics::Math::Quaternion&) const;
            nPhysics::Math::Vector3 operator&(const nPhysics::Math::Vector3&) const;
            nPhysics::Math::Vector3 operator|(const nPhysics::Math::Vector3&) const;
            nPhysics::Math::Vector3 operator^(const nPhysics::Math::Vector3&) const;
            nPhysics::Math::Vector3 operator>(const nPhysics::Math::Vector3& value) const;
            nPhysics::Math::Vector3 operator<(const nPhysics::Math::Vector3& value) const;
            nPhysics::Math::Vector3 operator>=(const nPhysics::Math::Vector3&) const;
            nPhysics::Math::Vector3 operator<=(const nPhysics::Math::Vector3&) const;
            nPhysics::Math::Vector3 operator==(const nPhysics::Math::Vector3&) const;
            nPhysics::Math::Vector3 operator!=(const nPhysics::Math::Vector3&) const;
            void multiply_add(const nPhysics::Math::Vector3& value1, const f32 value2);
            void multiply_subtract(const nPhysics::Math::Vector3& value1, const f32 value2);
            static nPhysics::Math::Vector3 Multiply(const nPhysics::Math::Vector3&, const nPhysics::Math::Vector3&);
            static nPhysics::Math::Vector3 MultiplyAdd(const nPhysics::Math::Vector3& value1, const f32 value2, const nPhysics::Math::Vector3& value3);
            static nPhysics::Math::Vector3 MultiplySubtract(const nPhysics::Math::Vector3& value1, const f32 value2, const nPhysics::Math::Vector3& value3);
            static nPhysics::Math::Vector3 MultiplyAdd(const nPhysics::Math::Vector3& value1, const nPhysics::Math::Vector3& value2, const nPhysics::Math::Vector3& value3);
            static nPhysics::Math::Vector3 MultiplySubtract(const nPhysics::Math::Vector3& value1, const nPhysics::Math::Vector3& value2, const nPhysics::Math::Vector3& value3);
            static void Check(const nPhysics::Math::Vector3& value);
            void lerp(const nPhysics::Math::Vector3& start, const nPhysics::Math::Vector3& end, const f32 t);
            nPhysics::Math::Vector3 maximize(const nPhysics::Math::Vector3& value) const;
            nPhysics::Math::Vector3 minimize(const nPhysics::Math::Vector3& value) const;
            nPhysics::Math::Vector3 packToS16x8FromS32x4x2(const nPhysics::Math::Vector3&) const;
            nPhysics::Math::Vector3 convertU32() const;
            nPhysics::Math::Vector3 convertS32() const;
            nPhysics::Math::Vector3 convertF32() const;
            f32 dot(const nPhysics::Math::Vector3& value) const;
            nPhysics::Math::Vector3 cross(const nPhysics::Math::Vector3& value) const;
            nPhysics::Math::Vector3 square_root() const;
            nPhysics::Math::Vector3 reciprocal_square_root() const;
            nPhysics::Math::Vector3 reciprocal_square_root_estimate() const;
            nPhysics::Math::Vector3 reciprocal() const;
            nPhysics::Math::Vector3 reciprocal_estimate() const;
            f32 length2() const;
            nPhysics::Math::Vector3 normalize() const;
            nPhysics::Math::Vector3 absolute() const;
            nPhysics::Math::Vector3 sin() const;
            nPhysics::Math::Vector3 sin_estimate() const;
            nPhysics::Math::Vector3 acos() const;
            nPhysics::Math::Vector3 acos_estimate() const;
            nPhysics::Math::Vector3 transformNormal(const nPhysics::Math::Matrix3& value) const;
            nPhysics::Math::Vector3 transformCoord(const nPhysics::Math::Matrix& value) const;
            bool isNull() const;
        private:
            union
            {
            public:
                f32 mF32[4];  // offset: 0x0
                u32 mU32[4];  // offset: 0x0
                s32 mS32[4];  // offset: 0x0
                u16 mU16[8];  // offset: 0x0
                s16 mS16[8];  // offset: 0x0
            };  // offset: 0x0
        };
    }  // namespace Math
}  // namespace nPhysics

inline nPhysics::Math::Vector3::Vector3() {
}
