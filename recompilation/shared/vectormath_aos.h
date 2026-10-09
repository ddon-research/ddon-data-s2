#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
namespace sce { namespace Vectormath { namespace Simd { namespace Aos { class Matrix3; } } } }
namespace sce { namespace Vectormath { namespace Simd { namespace Aos { class VecIdx; } } } }
namespace sce { namespace Vectormath { namespace Simd { class floatInVec; } } }

// Declarations
namespace sce { namespace Vectormath { namespace Simd { namespace Aos { class Point3; } } } }
namespace sce { namespace Vectormath { namespace Simd { namespace Aos { class Quat; } } } }
namespace sce { namespace Vectormath { namespace Simd { namespace Aos { class Vector2; } } } }
namespace sce { namespace Vectormath { namespace Simd { namespace Aos { class Vector3; } } } }
namespace sce { namespace Vectormath { namespace Simd { namespace Aos { class Vector4; } } } }

namespace sce {
namespace Vectormath {
namespace Simd {
    enum RotationOrder
    {
        kXYZ = 0,
        kYZX = 1,
        kZXY = 2,
        kXZY = 3,
        kYXZ = 4,
        kZYX = 5,
    };
}  // namespace Simd
}  // namespace Vectormath
}  // namespace sce

// Type aliases from DWARF
using vec_float4 = float __attribute__((ext_vector_type(4)));
using vec_float4_arg = const vec_float4;
using fast_float_vector_arg = vec_float4_arg;
using fast_float_vector_type = vec_float4;
namespace sce { namespace Vectormath { namespace Simd { namespace Aos { using Matrix3_arg = const sce::Vectormath::Simd::Aos::Matrix3&; } } } }
namespace sce { namespace Vectormath { namespace Simd { namespace Aos { using Point3_arg = const sce::Vectormath::Simd::Aos::Point3; } } } }
namespace sce { namespace Vectormath { namespace Simd { namespace Aos { using Quat_arg = const sce::Vectormath::Simd::Aos::Quat; } } } }
namespace sce { namespace Vectormath { namespace Simd { namespace Aos { using Vector2_arg = const sce::Vectormath::Simd::Aos::Vector2; } } } }
namespace sce { namespace Vectormath { namespace Simd { namespace Aos { using Vector3_arg = const sce::Vectormath::Simd::Aos::Vector3; } } } }
namespace sce { namespace Vectormath { namespace Simd { namespace Aos { using Vector4_arg = const sce::Vectormath::Simd::Aos::Vector4; } } } }
namespace sce { namespace Vectormath { namespace Simd { using floatInVec_arg = const sce::Vectormath::Simd::floatInVec; } } }
using vec_float2 = float __attribute__((ext_vector_type(2)));
using vec_float2_arg = const vec_float2;
using vec_float2_ext = float __attribute__((ext_vector_type(2)));
using vec_float2_ext_arg = const vec_float2_ext&;
using vec_float3_ext = float __attribute__((ext_vector_type(3)));
using vec_float3_ext_arg = const vec_float3_ext&;
using vec_float4_ext = float __attribute__((ext_vector_type(4)));
using vec_float4_ext_arg = const vec_float4_ext&;

namespace sce {
    namespace Vectormath {
        namespace Simd {
            namespace Aos {
                class Point3
                {
                public:
                    Point3();
                    Point3(const sce::Vectormath::Simd::Aos::Point3&);
                    Point3(float, float, float);
                    Point3(sce::Vectormath::Simd::floatInVec_arg, sce::Vectormath::Simd::floatInVec_arg, sce::Vectormath::Simd::floatInVec_arg);
                    Point3(sce::Vectormath::Simd::Aos::Vector2_arg, float);
                    Point3(sce::Vectormath::Simd::Aos::Vector2_arg, sce::Vectormath::Simd::floatInVec_arg);
                    explicit Point3(sce::Vectormath::Simd::Aos::Vector3_arg);
                    explicit Point3(float);
                    explicit Point3(sce::Vectormath::Simd::floatInVec_arg);
                    explicit Point3(vec_float4_arg);
                    explicit Point3(vec_float3_ext_arg);
                    vec_float3_ext getExtVector() const;
                    void setExtVector(vec_float3_ext_arg);
                    operator float __attribute__((ext_vector_type(3)))() const;
                    vec_float4 get128() const;
                    void set128(vec_float4_arg);
                protected:
                    vec_float4& get128Ref();
                public:
                    sce::Vectormath::Simd::Aos::Point3& operator=(sce::Vectormath::Simd::Aos::Point3_arg);
                    sce::Vectormath::Simd::Aos::Point3& setXY(sce::Vectormath::Simd::Aos::Vector2_arg);
                    const sce::Vectormath::Simd::Aos::Vector2 getXY() const;
                    sce::Vectormath::Simd::Aos::Point3& setX(float);
                    sce::Vectormath::Simd::Aos::Point3& setY(float);
                    sce::Vectormath::Simd::Aos::Point3& setZ(float);
                    sce::Vectormath::Simd::Aos::Point3& setX(sce::Vectormath::Simd::floatInVec_arg);
                    sce::Vectormath::Simd::Aos::Point3& setY(sce::Vectormath::Simd::floatInVec_arg);
                    sce::Vectormath::Simd::Aos::Point3& setZ(sce::Vectormath::Simd::floatInVec_arg);
                    const sce::Vectormath::Simd::floatInVec getX() const;
                    const sce::Vectormath::Simd::floatInVec getY() const;
                    const sce::Vectormath::Simd::floatInVec getZ() const;
                    sce::Vectormath::Simd::Aos::Point3& setElem(int, float);
                    sce::Vectormath::Simd::Aos::Point3& setElem(int, sce::Vectormath::Simd::floatInVec_arg);
                    const sce::Vectormath::Simd::floatInVec getElem(int) const;
                    sce::Vectormath::Simd::Aos::VecIdx operator[](int);
                    const sce::Vectormath::Simd::floatInVec operator[](int) const;
                    const sce::Vectormath::Simd::Aos::Vector3 operator-(sce::Vectormath::Simd::Aos::Point3_arg) const;
                    const sce::Vectormath::Simd::Aos::Point3 operator+(sce::Vectormath::Simd::Aos::Vector3_arg) const;
                    const sce::Vectormath::Simd::Aos::Point3 operator-(sce::Vectormath::Simd::Aos::Vector3_arg) const;
                    sce::Vectormath::Simd::Aos::Point3& operator+=(sce::Vectormath::Simd::Aos::Vector3_arg);
                    sce::Vectormath::Simd::Aos::Point3& operator-=(sce::Vectormath::Simd::Aos::Vector3_arg);
                    static const sce::Vectormath::Simd::Aos::Point3 origin();
                private:
                    vec_float4 mVec128;  // offset: 0x0
                };
            }  // namespace Aos
        }  // namespace Simd
    }  // namespace Vectormath
}  // namespace sce

namespace sce {
    namespace Vectormath {
        namespace Simd {
            namespace Aos {
                class Quat
                {
                public:
                    Quat();
                    Quat(const sce::Vectormath::Simd::Aos::Quat&);
                    Quat(float, float, float, float);
                    Quat(sce::Vectormath::Simd::floatInVec_arg, sce::Vectormath::Simd::floatInVec_arg, sce::Vectormath::Simd::floatInVec_arg, sce::Vectormath::Simd::floatInVec_arg);
                    Quat(sce::Vectormath::Simd::Aos::Vector3_arg, float);
                    Quat(sce::Vectormath::Simd::Aos::Vector3_arg, sce::Vectormath::Simd::floatInVec_arg);
                    explicit Quat(sce::Vectormath::Simd::Aos::Vector4_arg);
                    explicit Quat(sce::Vectormath::Simd::Aos::Matrix3_arg);
                    explicit Quat(float);
                    explicit Quat(sce::Vectormath::Simd::floatInVec_arg);
                    explicit Quat(vec_float4_arg);
                    explicit Quat(vec_float4_ext_arg);
                    vec_float4_ext getExtVector() const;
                    void setExtVector(vec_float4_ext_arg);
                    operator float __attribute__((ext_vector_type(4)))() const;
                    vec_float4 get128() const;
                    void set128(vec_float4_arg);
                protected:
                    vec_float4& get128Ref();
                public:
                    sce::Vectormath::Simd::Aos::Quat& operator=(sce::Vectormath::Simd::Aos::Quat_arg);
                    sce::Vectormath::Simd::Aos::Quat& setXY(sce::Vectormath::Simd::Aos::Vector2_arg);
                    sce::Vectormath::Simd::Aos::Quat& setXYZ(sce::Vectormath::Simd::Aos::Vector3_arg);
                    const sce::Vectormath::Simd::Aos::Vector2 getXY() const;
                    const sce::Vectormath::Simd::Aos::Vector3 getXYZ() const;
                    sce::Vectormath::Simd::Aos::Quat& setX(float);
                    sce::Vectormath::Simd::Aos::Quat& setY(float);
                    sce::Vectormath::Simd::Aos::Quat& setZ(float);
                    sce::Vectormath::Simd::Aos::Quat& setW(float);
                    sce::Vectormath::Simd::Aos::Quat& setX(sce::Vectormath::Simd::floatInVec_arg);
                    sce::Vectormath::Simd::Aos::Quat& setY(sce::Vectormath::Simd::floatInVec_arg);
                    sce::Vectormath::Simd::Aos::Quat& setZ(sce::Vectormath::Simd::floatInVec_arg);
                    sce::Vectormath::Simd::Aos::Quat& setW(sce::Vectormath::Simd::floatInVec_arg);
                    const sce::Vectormath::Simd::floatInVec getX() const;
                    const sce::Vectormath::Simd::floatInVec getY() const;
                    const sce::Vectormath::Simd::floatInVec getZ() const;
                    const sce::Vectormath::Simd::floatInVec getW() const;
                    sce::Vectormath::Simd::Aos::Quat& setElem(int, float);
                    sce::Vectormath::Simd::Aos::Quat& setElem(int, sce::Vectormath::Simd::floatInVec_arg);
                    const sce::Vectormath::Simd::floatInVec getElem(int) const;
                    sce::Vectormath::Simd::Aos::VecIdx operator[](int);
                    const sce::Vectormath::Simd::floatInVec operator[](int) const;
                    const sce::Vectormath::Simd::Aos::Quat operator+(sce::Vectormath::Simd::Aos::Quat_arg) const;
                    const sce::Vectormath::Simd::Aos::Quat operator-(sce::Vectormath::Simd::Aos::Quat_arg) const;
                    const sce::Vectormath::Simd::Aos::Quat operator*(sce::Vectormath::Simd::Aos::Quat_arg) const;
                    const sce::Vectormath::Simd::Aos::Quat operator*(float) const;
                    const sce::Vectormath::Simd::Aos::Quat operator/(float) const;
                    const sce::Vectormath::Simd::Aos::Quat operator*(sce::Vectormath::Simd::floatInVec_arg) const;
                    const sce::Vectormath::Simd::Aos::Quat operator/(sce::Vectormath::Simd::floatInVec_arg) const;
                    sce::Vectormath::Simd::Aos::Quat& operator+=(sce::Vectormath::Simd::Aos::Quat_arg);
                    sce::Vectormath::Simd::Aos::Quat& operator-=(sce::Vectormath::Simd::Aos::Quat_arg);
                    sce::Vectormath::Simd::Aos::Quat& operator*=(sce::Vectormath::Simd::Aos::Quat_arg);
                    sce::Vectormath::Simd::Aos::Quat& operator*=(float);
                    sce::Vectormath::Simd::Aos::Quat& operator/=(float);
                    sce::Vectormath::Simd::Aos::Quat& operator*=(sce::Vectormath::Simd::floatInVec_arg);
                    sce::Vectormath::Simd::Aos::Quat& operator/=(sce::Vectormath::Simd::floatInVec_arg);
                    const sce::Vectormath::Simd::Aos::Quat operator-() const;
                    static const sce::Vectormath::Simd::Aos::Quat identity();
                    static const sce::Vectormath::Simd::Aos::Quat zero();
                    static const sce::Vectormath::Simd::Aos::Vector3 euler(sce::Vectormath::Simd::Aos::Quat_arg, sce::Vectormath::Simd::RotationOrder);
                    static const sce::Vectormath::Simd::Aos::Vector4 axisAngle(sce::Vectormath::Simd::Aos::Quat_arg);
                    static const sce::Vectormath::Simd::Aos::Quat rotation(sce::Vectormath::Simd::Aos::Vector3_arg, sce::Vectormath::Simd::RotationOrder);
                    static const sce::Vectormath::Simd::Aos::Quat rotation(sce::Vectormath::Simd::Aos::Vector3_arg, sce::Vectormath::Simd::Aos::Vector3_arg);
                    static const sce::Vectormath::Simd::Aos::Quat rotation(float, sce::Vectormath::Simd::Aos::Vector3_arg);
                    static const sce::Vectormath::Simd::Aos::Quat rotation(sce::Vectormath::Simd::floatInVec_arg, sce::Vectormath::Simd::Aos::Vector3_arg);
                    static const sce::Vectormath::Simd::Aos::Quat rotationX(float);
                    static const sce::Vectormath::Simd::Aos::Quat rotationY(float);
                    static const sce::Vectormath::Simd::Aos::Quat rotationZ(float);
                    static const sce::Vectormath::Simd::Aos::Quat rotationX(sce::Vectormath::Simd::floatInVec_arg);
                    static const sce::Vectormath::Simd::Aos::Quat rotationY(sce::Vectormath::Simd::floatInVec_arg);
                    static const sce::Vectormath::Simd::Aos::Quat rotationZ(sce::Vectormath::Simd::floatInVec_arg);
                private:
                    vec_float4 mVec128;  // offset: 0x0
                };
            }  // namespace Aos
        }  // namespace Simd
    }  // namespace Vectormath
}  // namespace sce

namespace sce {
    namespace Vectormath {
        namespace Simd {
            namespace Aos {
                class Vector2
                {
                public:
                    Vector2();
                    Vector2(const sce::Vectormath::Simd::Aos::Vector2&);
                    Vector2(float, float);
                    Vector2(sce::Vectormath::Simd::floatInVec_arg, sce::Vectormath::Simd::floatInVec_arg);
                    explicit Vector2(float);
                    explicit Vector2(sce::Vectormath::Simd::floatInVec_arg);
                    explicit Vector2(vec_float2_arg);
                    explicit Vector2(vec_float2_ext_arg);
                    vec_float2_ext getExtVector() const;
                    void setExtVector(vec_float2_ext_arg);
                    operator float __attribute__((ext_vector_type(2)))() const;
                    vec_float2 get64() const;
                    fast_float_vector_type getFastVectorType() const;
                    void set64(vec_float2_arg);
                    void setFastVectorType(fast_float_vector_arg);
                protected:
                    vec_float2& get64Ref();
                public:
                    sce::Vectormath::Simd::Aos::Vector2& operator=(sce::Vectormath::Simd::Aos::Vector2_arg);
                    sce::Vectormath::Simd::Aos::Vector2& setX(float);
                    sce::Vectormath::Simd::Aos::Vector2& setY(float);
                    sce::Vectormath::Simd::Aos::Vector2& setX(sce::Vectormath::Simd::floatInVec_arg);
                    sce::Vectormath::Simd::Aos::Vector2& setY(sce::Vectormath::Simd::floatInVec_arg);
                    const sce::Vectormath::Simd::floatInVec getX() const;
                    const sce::Vectormath::Simd::floatInVec getY() const;
                    sce::Vectormath::Simd::Aos::Vector2& setElem(int, float);
                    sce::Vectormath::Simd::Aos::Vector2& setElem(int, sce::Vectormath::Simd::floatInVec_arg);
                    const sce::Vectormath::Simd::floatInVec getElem(int) const;
                    const sce::Vectormath::Simd::floatInVec operator[](int) const;
                    const sce::Vectormath::Simd::Aos::Vector2 operator+(sce::Vectormath::Simd::Aos::Vector2_arg) const;
                    const sce::Vectormath::Simd::Aos::Vector2 operator-(sce::Vectormath::Simd::Aos::Vector2_arg) const;
                    const sce::Vectormath::Simd::Aos::Vector2 operator*(float) const;
                    const sce::Vectormath::Simd::Aos::Vector2 operator/(float) const;
                    const sce::Vectormath::Simd::Aos::Vector2 operator*(sce::Vectormath::Simd::floatInVec_arg) const;
                    const sce::Vectormath::Simd::Aos::Vector2 operator/(sce::Vectormath::Simd::floatInVec_arg) const;
                    sce::Vectormath::Simd::Aos::Vector2& operator+=(sce::Vectormath::Simd::Aos::Vector2_arg);
                    sce::Vectormath::Simd::Aos::Vector2& operator-=(sce::Vectormath::Simd::Aos::Vector2_arg);
                    sce::Vectormath::Simd::Aos::Vector2& operator*=(float);
                    sce::Vectormath::Simd::Aos::Vector2& operator/=(float);
                    sce::Vectormath::Simd::Aos::Vector2& operator*=(sce::Vectormath::Simd::floatInVec_arg);
                    sce::Vectormath::Simd::Aos::Vector2& operator/=(sce::Vectormath::Simd::floatInVec_arg);
                    const sce::Vectormath::Simd::Aos::Vector2 operator-() const;
                    static const sce::Vectormath::Simd::Aos::Vector2 xAxis();
                    static const sce::Vectormath::Simd::Aos::Vector2 yAxis();
                    static const sce::Vectormath::Simd::Aos::Vector2 zero();
                private:
                    vec_float2 mVec64;  // offset: 0x0
                };
            }  // namespace Aos
        }  // namespace Simd
    }  // namespace Vectormath
}  // namespace sce

namespace sce {
    namespace Vectormath {
        namespace Simd {
            namespace Aos {
                class Vector3
                {
                public:
                    Vector3();
                    Vector3(const sce::Vectormath::Simd::Aos::Vector3&);
                    Vector3(float, float, float);
                    Vector3(sce::Vectormath::Simd::floatInVec_arg, sce::Vectormath::Simd::floatInVec_arg, sce::Vectormath::Simd::floatInVec_arg);
                    Vector3(sce::Vectormath::Simd::Aos::Vector2_arg, float);
                    Vector3(sce::Vectormath::Simd::Aos::Vector2_arg, sce::Vectormath::Simd::floatInVec_arg);
                    explicit Vector3(sce::Vectormath::Simd::Aos::Point3_arg);
                    explicit Vector3(float);
                    explicit Vector3(sce::Vectormath::Simd::floatInVec_arg);
                    explicit Vector3(vec_float4_arg);
                    explicit Vector3(vec_float3_ext_arg);
                    vec_float3_ext getExtVector() const;
                    void setExtVector(vec_float3_ext_arg);
                    operator float __attribute__((ext_vector_type(3)))() const;
                    vec_float4 get128() const;
                    void set128(vec_float4_arg);
                protected:
                    vec_float4& get128Ref();
                public:
                    sce::Vectormath::Simd::Aos::Vector3& operator=(sce::Vectormath::Simd::Aos::Vector3_arg);
                    sce::Vectormath::Simd::Aos::Vector3& setXY(sce::Vectormath::Simd::Aos::Vector2_arg);
                    const sce::Vectormath::Simd::Aos::Vector2 getXY() const;
                    sce::Vectormath::Simd::Aos::Vector3& setX(float);
                    sce::Vectormath::Simd::Aos::Vector3& setY(float);
                    sce::Vectormath::Simd::Aos::Vector3& setZ(float);
                    sce::Vectormath::Simd::Aos::Vector3& setX(sce::Vectormath::Simd::floatInVec_arg);
                    sce::Vectormath::Simd::Aos::Vector3& setY(sce::Vectormath::Simd::floatInVec_arg);
                    sce::Vectormath::Simd::Aos::Vector3& setZ(sce::Vectormath::Simd::floatInVec_arg);
                    const sce::Vectormath::Simd::floatInVec getX() const;
                    const sce::Vectormath::Simd::floatInVec getY() const;
                    const sce::Vectormath::Simd::floatInVec getZ() const;
                    sce::Vectormath::Simd::Aos::Vector3& setElem(int, float);
                    sce::Vectormath::Simd::Aos::Vector3& setElem(int, sce::Vectormath::Simd::floatInVec_arg);
                    const sce::Vectormath::Simd::floatInVec getElem(int) const;
                    sce::Vectormath::Simd::Aos::VecIdx operator[](int);
                    const sce::Vectormath::Simd::floatInVec operator[](int) const;
                    const sce::Vectormath::Simd::Aos::Vector3 operator+(sce::Vectormath::Simd::Aos::Vector3_arg) const;
                    const sce::Vectormath::Simd::Aos::Vector3 operator-(sce::Vectormath::Simd::Aos::Vector3_arg) const;
                    const sce::Vectormath::Simd::Aos::Point3 operator+(sce::Vectormath::Simd::Aos::Point3_arg) const;
                    const sce::Vectormath::Simd::Aos::Vector3 operator*(float) const;
                    const sce::Vectormath::Simd::Aos::Vector3 operator/(float) const;
                    const sce::Vectormath::Simd::Aos::Vector3 operator*(sce::Vectormath::Simd::floatInVec_arg) const;
                    const sce::Vectormath::Simd::Aos::Vector3 operator/(sce::Vectormath::Simd::floatInVec_arg) const;
                    sce::Vectormath::Simd::Aos::Vector3& operator+=(sce::Vectormath::Simd::Aos::Vector3_arg);
                    sce::Vectormath::Simd::Aos::Vector3& operator-=(sce::Vectormath::Simd::Aos::Vector3_arg);
                    sce::Vectormath::Simd::Aos::Vector3& operator*=(float);
                    sce::Vectormath::Simd::Aos::Vector3& operator/=(float);
                    sce::Vectormath::Simd::Aos::Vector3& operator*=(sce::Vectormath::Simd::floatInVec_arg);
                    sce::Vectormath::Simd::Aos::Vector3& operator/=(sce::Vectormath::Simd::floatInVec_arg);
                    const sce::Vectormath::Simd::Aos::Vector3 operator-() const;
                    static const sce::Vectormath::Simd::Aos::Vector3 xAxis();
                    static const sce::Vectormath::Simd::Aos::Vector3 yAxis();
                    static const sce::Vectormath::Simd::Aos::Vector3 zAxis();
                    static const sce::Vectormath::Simd::Aos::Vector3 zero();
                private:
                    vec_float4 mVec128;  // offset: 0x0
                };
            }  // namespace Aos
        }  // namespace Simd
    }  // namespace Vectormath
}  // namespace sce

namespace sce {
    namespace Vectormath {
        namespace Simd {
            namespace Aos {
                class Vector4
                {
                public:
                    Vector4();
                    Vector4(const sce::Vectormath::Simd::Aos::Vector4& vec);
                    Vector4(float _x, float _y, float _z, float _w);
                    Vector4(sce::Vectormath::Simd::floatInVec_arg, sce::Vectormath::Simd::floatInVec_arg, sce::Vectormath::Simd::floatInVec_arg, sce::Vectormath::Simd::floatInVec_arg);
                    Vector4(sce::Vectormath::Simd::Aos::Vector2_arg, float, float);
                    Vector4(sce::Vectormath::Simd::Aos::Vector2_arg, sce::Vectormath::Simd::floatInVec_arg, sce::Vectormath::Simd::floatInVec_arg);
                    Vector4(sce::Vectormath::Simd::Aos::Vector2_arg, sce::Vectormath::Simd::Aos::Vector2_arg);
                    Vector4(sce::Vectormath::Simd::Aos::Vector3_arg, float);
                    Vector4(sce::Vectormath::Simd::Aos::Vector3_arg, sce::Vectormath::Simd::floatInVec_arg);
                    explicit Vector4(sce::Vectormath::Simd::Aos::Vector3_arg);
                    explicit Vector4(sce::Vectormath::Simd::Aos::Point3_arg);
                    explicit Vector4(sce::Vectormath::Simd::Aos::Quat_arg);
                    explicit Vector4(float);
                    explicit Vector4(sce::Vectormath::Simd::floatInVec_arg);
                    explicit Vector4(vec_float4_arg vf4);
                    explicit Vector4(vec_float4_ext_arg);
                    vec_float4_ext getExtVector() const;
                    void setExtVector(vec_float4_ext_arg);
                    operator float __attribute__((ext_vector_type(4)))() const;
                    vec_float4 get128() const;
                    void set128(vec_float4_arg);
                protected:
                    vec_float4& get128Ref();
                public:
                    sce::Vectormath::Simd::Aos::Vector4& operator=(sce::Vectormath::Simd::Aos::Vector4_arg vec);
                    sce::Vectormath::Simd::Aos::Vector4& setXY(sce::Vectormath::Simd::Aos::Vector2_arg);
                    sce::Vectormath::Simd::Aos::Vector4& setXYZ(sce::Vectormath::Simd::Aos::Vector3_arg);
                    const sce::Vectormath::Simd::Aos::Vector2 getXY() const;
                    const sce::Vectormath::Simd::Aos::Vector3 getXYZ() const;
                    sce::Vectormath::Simd::Aos::Vector4& setX(float);
                    sce::Vectormath::Simd::Aos::Vector4& setY(float);
                    sce::Vectormath::Simd::Aos::Vector4& setZ(float);
                    sce::Vectormath::Simd::Aos::Vector4& setW(float);
                    sce::Vectormath::Simd::Aos::Vector4& setX(sce::Vectormath::Simd::floatInVec_arg);
                    sce::Vectormath::Simd::Aos::Vector4& setY(sce::Vectormath::Simd::floatInVec_arg);
                    sce::Vectormath::Simd::Aos::Vector4& setZ(sce::Vectormath::Simd::floatInVec_arg);
                    sce::Vectormath::Simd::Aos::Vector4& setW(sce::Vectormath::Simd::floatInVec_arg);
                    const sce::Vectormath::Simd::floatInVec getX() const;
                    const sce::Vectormath::Simd::floatInVec getY() const;
                    const sce::Vectormath::Simd::floatInVec getZ() const;
                    const sce::Vectormath::Simd::floatInVec getW() const;
                    sce::Vectormath::Simd::Aos::Vector4& setElem(int, float);
                    sce::Vectormath::Simd::Aos::Vector4& setElem(int, sce::Vectormath::Simd::floatInVec_arg);
                    const sce::Vectormath::Simd::floatInVec getElem(int) const;
                    sce::Vectormath::Simd::Aos::VecIdx operator[](int);
                    const sce::Vectormath::Simd::floatInVec operator[](int) const;
                    const sce::Vectormath::Simd::Aos::Vector4 operator+(sce::Vectormath::Simd::Aos::Vector4_arg) const;
                    const sce::Vectormath::Simd::Aos::Vector4 operator-(sce::Vectormath::Simd::Aos::Vector4_arg) const;
                    const sce::Vectormath::Simd::Aos::Vector4 operator*(float) const;
                    const sce::Vectormath::Simd::Aos::Vector4 operator/(float) const;
                    const sce::Vectormath::Simd::Aos::Vector4 operator*(sce::Vectormath::Simd::floatInVec_arg) const;
                    const sce::Vectormath::Simd::Aos::Vector4 operator/(sce::Vectormath::Simd::floatInVec_arg) const;
                    sce::Vectormath::Simd::Aos::Vector4& operator+=(sce::Vectormath::Simd::Aos::Vector4_arg);
                    sce::Vectormath::Simd::Aos::Vector4& operator-=(sce::Vectormath::Simd::Aos::Vector4_arg);
                    sce::Vectormath::Simd::Aos::Vector4& operator*=(float);
                    sce::Vectormath::Simd::Aos::Vector4& operator/=(float);
                    sce::Vectormath::Simd::Aos::Vector4& operator*=(sce::Vectormath::Simd::floatInVec_arg);
                    sce::Vectormath::Simd::Aos::Vector4& operator/=(sce::Vectormath::Simd::floatInVec_arg);
                    const sce::Vectormath::Simd::Aos::Vector4 operator-() const;
                    static const sce::Vectormath::Simd::Aos::Vector4 xAxis();
                    static const sce::Vectormath::Simd::Aos::Vector4 yAxis();
                    static const sce::Vectormath::Simd::Aos::Vector4 zAxis();
                    static const sce::Vectormath::Simd::Aos::Vector4 wAxis();
                    static const sce::Vectormath::Simd::Aos::Vector4 zero();
                private:
                    vec_float4 mVec128;  // offset: 0x0
                };
            }  // namespace Aos
        }  // namespace Simd
    }  // namespace Vectormath
}  // namespace sce
