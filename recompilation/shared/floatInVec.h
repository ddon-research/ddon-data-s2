#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
namespace sce { namespace Vectormath { namespace Simd { class boolInVec; } } }

// Declarations
namespace sce { namespace Vectormath { namespace Simd { class floatInVec; } } }

// Type aliases from DWARF
using vec_float4 = float __attribute__((ext_vector_type(4)));
using vec_float4_arg = const vec_float4;
using fast_float_vector_arg = vec_float4_arg;
using fast_float_vector_type = vec_float4;
namespace sce { namespace Vectormath { namespace Simd { using boolInVec_arg = const sce::Vectormath::Simd::boolInVec; } } }
namespace sce { namespace Vectormath { namespace Simd { using floatInVec_arg = const sce::Vectormath::Simd::floatInVec; } } }
using vec_float2 = float __attribute__((ext_vector_type(2)));
using vec_float2_arg = const vec_float2;

namespace sce {
    namespace Vectormath {
        namespace Simd {
            class floatInVec
            {
            public:
                floatInVec();
                floatInVec(const sce::Vectormath::Simd::floatInVec&);
                floatInVec(sce::Vectormath::Simd::boolInVec_arg);
                floatInVec(vec_float2_arg, int);
                floatInVec(vec_float4_arg, int);
                explicit floatInVec(vec_float2_arg);
                explicit floatInVec(vec_float4_arg);
                explicit floatInVec(float);
                float getAsFloat() const;
                operator float() const;
                vec_float4 get128() const;
                void set128(vec_float4_arg);
                vec_float2 get64() const;
                void set64(vec_float2_arg);
                fast_float_vector_type getFastVectorType() const;
                void setFastVectorType(fast_float_vector_arg);
                const sce::Vectormath::Simd::floatInVec operator++(int);
                const sce::Vectormath::Simd::floatInVec operator--(int);
                sce::Vectormath::Simd::floatInVec& operator++();
                sce::Vectormath::Simd::floatInVec& operator--();
                const sce::Vectormath::Simd::floatInVec operator-() const;
                sce::Vectormath::Simd::floatInVec& operator=(sce::Vectormath::Simd::floatInVec_arg);
                sce::Vectormath::Simd::floatInVec& operator*=(sce::Vectormath::Simd::floatInVec_arg);
                sce::Vectormath::Simd::floatInVec& operator/=(sce::Vectormath::Simd::floatInVec_arg);
                sce::Vectormath::Simd::floatInVec& operator+=(sce::Vectormath::Simd::floatInVec_arg);
                sce::Vectormath::Simd::floatInVec& operator-=(sce::Vectormath::Simd::floatInVec_arg);
            private:
                vec_float4 mData;  // offset: 0x0
            };
        }  // namespace Simd
    }  // namespace Vectormath
}  // namespace sce
