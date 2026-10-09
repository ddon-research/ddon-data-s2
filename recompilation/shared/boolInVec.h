#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
namespace sce { namespace Vectormath { namespace Simd { class floatInVec; } } }

// Declarations
namespace sce { namespace Vectormath { namespace Simd { class boolInVec; } } }

// Type aliases from DWARF
using vec_uint4 = uint32_t __attribute__((ext_vector_type(4)));
using vec_uint4_arg = const vec_uint4;
using fast_uint_vector_arg = vec_uint4_arg;
using fast_uint_vector_type = vec_uint4;
namespace sce { namespace Vectormath { namespace Simd { using boolInVec_arg = const sce::Vectormath::Simd::boolInVec; } } }
namespace sce { namespace Vectormath { namespace Simd { using floatInVec_arg = const sce::Vectormath::Simd::floatInVec; } } }
using vec_uint2 = uint32_t __attribute__((ext_vector_type(2)));
using vec_uint2_arg = const vec_uint2;

namespace sce {
    namespace Vectormath {
        namespace Simd {
            class boolInVec
            {
            public:
                boolInVec();
                boolInVec(const sce::Vectormath::Simd::boolInVec&);
                boolInVec(sce::Vectormath::Simd::floatInVec_arg);
                explicit boolInVec(bool);
                explicit boolInVec(vec_uint2_arg, int);
                explicit boolInVec(vec_uint4_arg, int);
                explicit boolInVec(vec_uint2_arg);
                explicit boolInVec(vec_uint4_arg);
                bool getAsBool() const;
                operator bool() const;
                vec_uint4 get128() const;
                void set128(vec_uint4_arg);
                vec_uint2 get64() const;
                void set64(vec_uint2_arg);
                fast_uint_vector_type getFastVectorType() const;
                void setFastVectorType(fast_uint_vector_arg);
                const sce::Vectormath::Simd::boolInVec operator!() const;
                sce::Vectormath::Simd::boolInVec& operator=(sce::Vectormath::Simd::boolInVec_arg);
                sce::Vectormath::Simd::boolInVec& operator&=(sce::Vectormath::Simd::boolInVec_arg);
                sce::Vectormath::Simd::boolInVec& operator^=(sce::Vectormath::Simd::boolInVec_arg);
                sce::Vectormath::Simd::boolInVec& operator|=(sce::Vectormath::Simd::boolInVec_arg);
            private:
                vec_uint4 mData;  // offset: 0x0
            };
        }  // namespace Simd
    }  // namespace Vectormath
}  // namespace sce
