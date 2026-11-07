#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "constants.h"

// Declarations
namespace sce { namespace Gnm { class Sampler; } }

// Type aliases from DWARF
using __int32_t = int;
using __uint16_t = unsigned short;
using __uint32_t = unsigned int;
using __uint8_t = unsigned char;
using int32_t = __int32_t;
using uint16_t = __uint16_t;
using uint32_t = __uint32_t;
using uint8_t = __uint8_t;

namespace sce {
    namespace Gnm {
        class Sampler
        {
        public:
            void init();
            void setWrapMode(sce::Gnm::WrapMode x, sce::Gnm::WrapMode y, sce::Gnm::WrapMode z);
            void setXyFilterMode(sce::Gnm::FilterMode magFilter, sce::Gnm::FilterMode minFilter);
            void setMipFilterMode(sce::Gnm::MipFilterMode mipFilter);
            void setZFilterMode(sce::Gnm::ZFilterMode zFilter);
            void setAnisotropyRatio(sce::Gnm::AnisotropyRatio anisotropyRatio);
            void setBorderColor(sce::Gnm::BorderColor borderColorMode);
            void setBorderColorTableIndex(uint32_t index);
            void setDepthCompareFunction(sce::Gnm::DepthCompare depthCompareFunc);
            void setForceUnnormalized(bool);
            void setAnisotropyThreshold(uint8_t);
            void setLodRange(uint32_t minLod, uint32_t maxLod);
            void setMipClampRegionSize(uint8_t);
            void setZClampRegionSize(uint8_t);
            void setLodBias(int32_t bias, int32_t secBias);
            void setForceDegamma(bool);
            void setAnisotropyBias(uint8_t);
            void setTruncateEnable(bool);
            void setDisableCubeWrap(bool);
            sce::Gnm::WrapMode getWrapModeX() const;
            sce::Gnm::WrapMode getWrapModeY() const;
            sce::Gnm::WrapMode getWrapModeZ() const;
            sce::Gnm::FilterMode getMagFilterMode() const;
            sce::Gnm::FilterMode getMinFilterMode() const;
            sce::Gnm::ZFilterMode getZFilterMode() const;
            sce::Gnm::MipFilterMode getMipFilterMode() const;
            uint32_t getMinLod() const;
            uint32_t getMaxLod() const;
            uint16_t getLodBias() const;
            uint16_t getLodBiasSecondary() const;
            sce::Gnm::AnisotropyRatio getAnisotropyRatio() const;
            sce::Gnm::DepthCompare getDepthCompareFunction() const;
            bool getForceDegamma() const;
            bool getForceUnnormalized() const;
            uint32_t getAnisotropyThreshold() const;
            sce::Gnm::BorderColor getBorderColor() const;
            uint32_t getBorderColorTableIndex() const;
        public:
            uint32_t m_regs[4];  // offset: 0x0
        };
    }  // namespace Gnm
}  // namespace sce
