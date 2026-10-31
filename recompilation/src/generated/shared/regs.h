#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "constants.h"

// Declarations
namespace sce { namespace Gnm { class AlphaToMaskControl; } }
namespace sce { namespace Gnm { class BlendControl; } }
namespace sce { namespace Gnm { class ClipControl; } }
namespace sce { namespace Gnm { class DbRenderControl; } }
namespace sce { namespace Gnm { class DepthEqaaControl; } }
namespace sce { namespace Gnm { class DepthStencilControl; } }
namespace sce { namespace Gnm { class GraphicsShaderControl; } }
namespace sce { namespace Gnm { class HtileStencilControl; } }
namespace sce { namespace Gnm { class PrimitiveSetup; } }
namespace sce { namespace Gnm { class RenderOverride2Control; } }
namespace sce { namespace Gnm { class RenderOverrideControl; } }
namespace sce { namespace Gnm { class StencilControl; } }
namespace sce { namespace Gnm { class StencilOpControl; } }
namespace sce { namespace Gnm { class ViewportTransformControl; } }

// Type aliases from DWARF
using __uint32_t = unsigned int;
using __uint8_t = unsigned char;
using uint32_t = __uint32_t;
using uint8_t = __uint8_t;

namespace sce {
    namespace Gnm {
        class AlphaToMaskControl
        {
        public:
            void init();
            void setEnabled(sce::Gnm::AlphaToMaskMode);
            void setPixelDitherThresholds(sce::Gnm::AlphaToMaskDitherThreshold, sce::Gnm::AlphaToMaskDitherThreshold, sce::Gnm::AlphaToMaskDitherThreshold, sce::Gnm::AlphaToMaskDitherThreshold);
            void setDitherMode(sce::Gnm::AlphaToMaskDitherMode);
        public:
            uint32_t m_reg;  // offset: 0x0
        };
    }  // namespace Gnm
}  // namespace sce

namespace sce {
    namespace Gnm {
        class BlendControl
        {
        public:
            void init();
            void setBlendEnable(bool);
            void setColorEquation(sce::Gnm::BlendMultiplier, sce::Gnm::BlendFunc, sce::Gnm::BlendMultiplier);
            void setAlphaEquation(sce::Gnm::BlendMultiplier, sce::Gnm::BlendFunc, sce::Gnm::BlendMultiplier);
            void setSeparateAlphaEnable(bool);
        public:
            uint32_t m_reg;  // offset: 0x0
        };
    }  // namespace Gnm
}  // namespace sce

namespace sce {
    namespace Gnm {
        class ClipControl
        {
        public:
            void init();
            void setClipSpace(sce::Gnm::ClipControlClipSpace);
        public:
            uint32_t m_reg;  // offset: 0x0
        };
    }  // namespace Gnm
}  // namespace sce

namespace sce {
    namespace Gnm {
        class DbRenderControl
        {
        public:
            void init();
            void setDepthClearEnable(bool);
            void setStencilClearEnable(bool);
        public:
            uint32_t m_reg;  // offset: 0x0
        };
    }  // namespace Gnm
}  // namespace sce

namespace sce {
    namespace Gnm {
        class DepthEqaaControl
        {
        public:
            uint32_t m_reg;  // offset: 0x0
        };
    }  // namespace Gnm
}  // namespace sce

namespace sce {
    namespace Gnm {
        class DepthStencilControl
        {
        public:
            void init();
            void setDepthControl(sce::Gnm::DepthControlZWrite, sce::Gnm::CompareFunc);
            void setStencilFunction(sce::Gnm::CompareFunc);
            void setStencilFunctionBack(sce::Gnm::CompareFunc);
            void setSeparateStencilEnable(bool);
            void setDepthEnable(bool);
            void setStencilEnable(bool);
        public:
            uint32_t m_reg;  // offset: 0x0
        };
    }  // namespace Gnm
}  // namespace sce

namespace sce {
    namespace Gnm {
        class GraphicsShaderControl
        {
        public:
            uint32_t m_regPgmRsrc3[6];  // offset: 0x0
            uint32_t m_regVsLateAlloc;  // offset: 0x18
        };
    }  // namespace Gnm
}  // namespace sce

namespace sce {
    namespace Gnm {
        class HtileStencilControl
        {
        public:
            uint32_t m_reg;  // offset: 0x0
        };
    }  // namespace Gnm
}  // namespace sce

namespace sce {
    namespace Gnm {
        class PrimitiveSetup
        {
        public:
            void init();
            void setCullFace(sce::Gnm::PrimitiveSetupCullFaceMode);
            void setFrontFace(sce::Gnm::PrimitiveSetupFrontFace);
            void setPolygonMode(sce::Gnm::PrimitiveSetupPolygonMode, sce::Gnm::PrimitiveSetupPolygonMode);
            void setPolygonOffsetEnable(sce::Gnm::PrimitiveSetupPolygonOffsetMode, sce::Gnm::PrimitiveSetupPolygonOffsetMode);
        public:
            uint32_t m_reg;  // offset: 0x0
        };
    }  // namespace Gnm
}  // namespace sce

namespace sce {
    namespace Gnm {
        class RenderOverride2Control
        {
        public:
            uint32_t m_reg;  // offset: 0x0
        };
    }  // namespace Gnm
}  // namespace sce

namespace sce {
    namespace Gnm {
        class RenderOverrideControl
        {
        public:
            uint32_t m_reg;  // offset: 0x0
        };
    }  // namespace Gnm
}  // namespace sce

namespace sce {
    namespace Gnm {
        class StencilControl
        {
        public:
            void init();
        public:
            uint8_t m_testVal;  // offset: 0x0
            uint8_t m_mask;  // offset: 0x1
            uint8_t m_writeMask;  // offset: 0x2
            uint8_t m_opVal;  // offset: 0x3
        };
    }  // namespace Gnm
}  // namespace sce

namespace sce {
    namespace Gnm {
        class StencilOpControl
        {
        public:
            void init();
            void setStencilOps(sce::Gnm::StencilOp, sce::Gnm::StencilOp, sce::Gnm::StencilOp);
            void setStencilOpsBack(sce::Gnm::StencilOp, sce::Gnm::StencilOp, sce::Gnm::StencilOp);
        public:
            uint32_t m_reg;  // offset: 0x0
        };
    }  // namespace Gnm
}  // namespace sce

namespace sce {
    namespace Gnm {
        class ViewportTransformControl
        {
        public:
            void init();
            void setPassThroughEnable(bool);
        public:
            uint32_t m_reg;  // offset: 0x0
        };
    }  // namespace Gnm
}  // namespace sce
