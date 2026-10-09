#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
namespace sce { namespace Vectormath { namespace Simd { class floatInVec; } } }

// Declarations
namespace sce { namespace Vectormath { namespace Simd { namespace Aos { class VecIdx; } } } }

// Type aliases from DWARF
namespace sce { namespace Vectormath { namespace Simd { using floatInVec_arg = const sce::Vectormath::Simd::floatInVec; } } }
using vec_float4 = float __attribute__((ext_vector_type(4)));

namespace sce {
    namespace Vectormath {
        namespace Simd {
            namespace Aos {
                class VecIdx
                {
                public:
                    VecIdx(vec_float4&, int);
                    VecIdx(const sce::Vectormath::Simd::Aos::VecIdx&);
                    float getAsFloat() const;
                    operator floatInVec() const;
                    operator float() const;
                    float operator=(float);
                    sce::Vectormath::Simd::floatInVec operator=(sce::Vectormath::Simd::floatInVec_arg);
                    sce::Vectormath::Simd::floatInVec operator=(const sce::Vectormath::Simd::Aos::VecIdx&);
                    sce::Vectormath::Simd::floatInVec operator*=(float);
                    sce::Vectormath::Simd::floatInVec operator*=(sce::Vectormath::Simd::floatInVec_arg);
                    sce::Vectormath::Simd::floatInVec operator/=(float);
                    sce::Vectormath::Simd::floatInVec operator/=(sce::Vectormath::Simd::floatInVec_arg);
                    sce::Vectormath::Simd::floatInVec operator+=(float);
                    sce::Vectormath::Simd::floatInVec operator+=(sce::Vectormath::Simd::floatInVec_arg);
                    sce::Vectormath::Simd::floatInVec operator-=(float);
                    sce::Vectormath::Simd::floatInVec operator-=(sce::Vectormath::Simd::floatInVec_arg);
                private:
                    vec_float4& ref;  // offset: 0x0
                    int i;  // offset: 0x8
                    char padding[4];  // offset: 0xc
                };
            }  // namespace Aos
        }  // namespace Simd
    }  // namespace Vectormath
}  // namespace sce
