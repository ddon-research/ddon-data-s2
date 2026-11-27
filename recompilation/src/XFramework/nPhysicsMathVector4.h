#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
struct MtFloat3A;
struct MtFloat4A;
class MtVector3;
class MtVector4;
namespace nPhysics { namespace Math { class Quaternion; } }
namespace nPhysics { namespace Math { class Vector3; } }

// Declarations
namespace nPhysics { namespace Math { class Vector4; } }

// Type aliases from DWARF
using f32 = float;
using s16 = short;
using s32 = int;
using u16 = unsigned short;
using u32 = unsigned int;

namespace nPhysics {
    namespace Math {
        class Vector4
        {
        public:
            Vector4();
            Vector4(const f32 x, const f32 y, const f32 z, const f32 w);
            Vector4(const u32, const u32, const u32, const u32);
            Vector4(const f32*);
            Vector4(const f32 value);
            Vector4(const MtVector4& value);
            Vector4(const MtFloat4A&);
            Vector4(const nPhysics::Math::Vector3& value);
            Vector4(const nPhysics::Math::Quaternion&);
            void load(const f32*);
            void load(const f32 value);
            void load(const MtVector3& value);
            void load(const MtVector4& value);
            void load(const MtFloat3A& value);
            void load(const MtFloat4A&);
            void load(const nPhysics::Math::Vector3& value);
            void load(const nPhysics::Math::Vector4& value);
            void load(const nPhysics::Math::Quaternion& value);
            void store(f32*) const;
            void store(MtFloat3A& output) const;
            void store(MtFloat4A&) const;
            void store(MtVector3& output) const;
            void store(MtVector4& output) const;
            f32 getX() const;
            f32 getY() const;
            f32 getZ() const;
            f32 getW() const;
            u32 getXu() const;
            u32 getYu() const;
            u32 getZu() const;
            u32 getWu() const;
            void setX(const f32 value);
            void setY(const f32 value);
            void setZ(const f32 value);
            void setW(const f32 value);
            void setXu(const u32 value);
            void setYu(const u32);
            void setZu(const u32);
            void setWu(const u32);
            void clear();
            operator MtVector4() const;
            nPhysics::Math::Vector4 operator-() const;
            nPhysics::Math::Vector4 maximize(const nPhysics::Math::Vector4&) const;
            nPhysics::Math::Vector4 minimize(const nPhysics::Math::Vector4&) const;
            nPhysics::Math::Vector4 packToU16x8FromU32x4x2(const nPhysics::Math::Vector4&) const;
            void operator=(const nPhysics::Math::Vector3& value);
            void operator=(const nPhysics::Math::Vector4& value);
            void operator=(const nPhysics::Math::Quaternion& value);
            void operator=(const MtVector4&);
            void operator=(const MtFloat4A&);
            void operator+=(const nPhysics::Math::Vector4& value);
            void operator-=(const nPhysics::Math::Vector4& value);
            void operator*=(const nPhysics::Math::Vector4& value);
            void operator&=(const nPhysics::Math::Vector4&);
            void operator|=(const nPhysics::Math::Vector4&);
            void operator^=(const nPhysics::Math::Vector4&);
            nPhysics::Math::Vector4 operator+(const nPhysics::Math::Vector4& value) const;
            nPhysics::Math::Vector4 operator-(const nPhysics::Math::Vector4& value) const;
            nPhysics::Math::Vector4 operator*(const nPhysics::Math::Vector4& value) const;
            nPhysics::Math::Vector4 operator&(const nPhysics::Math::Vector4&) const;
            nPhysics::Math::Vector4 operator|(const nPhysics::Math::Vector4&) const;
            nPhysics::Math::Vector4 operator^(const nPhysics::Math::Vector4&) const;
            nPhysics::Math::Vector4 operator>(const nPhysics::Math::Vector4&) const;
            nPhysics::Math::Vector4 operator<(const nPhysics::Math::Vector4&) const;
            nPhysics::Math::Vector4 operator>=(const nPhysics::Math::Vector4&) const;
            nPhysics::Math::Vector4 operator<=(const nPhysics::Math::Vector4&) const;
            nPhysics::Math::Vector4 operator==(const nPhysics::Math::Vector4&) const;
            nPhysics::Math::Vector4 operator!=(const nPhysics::Math::Vector4&) const;
            void add_int(const nPhysics::Math::Vector4&);
            void subtract_int(const nPhysics::Math::Vector4&);
            static nPhysics::Math::Vector4 MultiplyAdd(const nPhysics::Math::Vector4&, const nPhysics::Math::Vector4&, const nPhysics::Math::Vector4&);
            static nPhysics::Math::Vector4 MultiplySubtract(const nPhysics::Math::Vector4&, const nPhysics::Math::Vector4&, const nPhysics::Math::Vector4&);
            static void check(const nPhysics::Math::Vector3&);
            nPhysics::Math::Vector4 reciprocal() const;
            nPhysics::Math::Vector4 reciprocal_estimate() const;
            void greaterInt(const nPhysics::Math::Vector4&, const nPhysics::Math::Vector4&);
            void rotateLeft32();
            void rotateRight32();
            bool isNull() const;
            bool collideAABB(const nPhysics::Math::Vector4& value) const;
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

inline nPhysics::Math::Vector4::Vector4() {
}
