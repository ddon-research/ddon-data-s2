#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "buffer.h"
#include "constants.h"
#include "lwcue_base.h"

// Forward declarations
namespace sce { namespace Gnm { class Buffer; } }
namespace sce { namespace Gnm { class DispatchCommandBuffer; } }
namespace sce { namespace Gnm { class DrawCommandBuffer; } }
namespace sce { namespace Gnm { class Sampler; } }
namespace sce { namespace Gnm { class Texture; } }
namespace sce { namespace Gnmx { class CsShader; } }
namespace sce { namespace Gnmx { class CsVsShader; } }
namespace sce { namespace Gnmx { class EsShader; } }
namespace sce { namespace Gnmx { class GsShader; } }
namespace sce { namespace Gnmx { class HsShader; } }
namespace sce { namespace Gnmx { struct InputResourceOffsets; } }
namespace sce { namespace Gnmx { namespace LightweightConstantUpdateEngine { struct ShaderResourceBindingValidation; } } }
namespace sce { namespace Gnmx { class LsShader; } }
namespace sce { namespace Gnmx { class PsShader; } }
namespace sce { namespace Gnmx { class VsShader; } }

// Declarations
namespace sce { namespace Gnmx { class LightweightGraphicsConstantUpdateEngine; } }

// Type aliases from DWARF
using __int32_t = int;
using __uint16_t = unsigned short;
using __uint32_t = unsigned int;
using __uint8_t = unsigned char;
using int32_t = __int32_t;
namespace sce { namespace Gnmx { using GnmxDispatchCommandBuffer = sce::Gnm::DispatchCommandBuffer; } }
namespace sce { namespace Gnmx { using GnmxDrawCommandBuffer = sce::Gnm::DrawCommandBuffer; } }
using uint16_t = __uint16_t;
using uint32_t = __uint32_t;
using uint8_t = __uint8_t;

namespace sce {
    namespace Gnmx {
        class LightweightGraphicsConstantUpdateEngine : public sce::Gnmx::BaseConstantUpdateEngine
        {
        public:
            void invalidateShaderStage(sce::Gnm::ShaderStage);
            void setDrawCommandBuffer(sce::Gnmx::GnmxDrawCommandBuffer*);
            void setDispatchDrawCommandBuffer(sce::Gnmx::GnmxDispatchCommandBuffer*);
            void setActiveShaderStages(sce::Gnm::ActiveShaderStages activeStages);
            void setEsShader(const sce::Gnmx::EsShader*, uint32_t, const void*, const sce::Gnmx::InputResourceOffsets*);
            void setEsShader(const sce::Gnmx::EsShader*, const sce::Gnmx::InputResourceOffsets*);
            void setOnChipEsShader(const sce::Gnmx::EsShader*, uint32_t, uint32_t, const void*, const sce::Gnmx::InputResourceOffsets*);
            void setOnChipEsShader(const sce::Gnmx::EsShader*, uint32_t, const sce::Gnmx::InputResourceOffsets*);
            void setEsFetchShader(uint32_t, const void*);
            void setGsVsShaders(const sce::Gnmx::GsShader*, const sce::Gnmx::InputResourceOffsets*);
            void setOnChipGsVsShaders(const sce::Gnmx::GsShader*, uint32_t, const sce::Gnmx::InputResourceOffsets*);
            void setOnChipEsGsLdsLayout(uint32_t);
            void setOnChipEsExportVertexSizeInDword(uint16_t);
            void setStreamoutBuffers(int32_t, int32_t, const sce::Gnm::Buffer*);
            void setLsShader(const sce::Gnmx::LsShader*, uint32_t, const void*, const sce::Gnmx::InputResourceOffsets*);
            void setLsShader(const sce::Gnmx::LsShader*, const sce::Gnmx::InputResourceOffsets*);
            void setLsFetchShader(uint32_t, const void*);
            void setHsShader(const sce::Gnmx::HsShader*, const sce::Gnmx::InputResourceOffsets*, uint32_t);
            void setVsShader(const sce::Gnmx::VsShader*, uint32_t, const void*, const sce::Gnmx::InputResourceOffsets*);
            void setVsShader(const sce::Gnmx::VsShader* shader, const sce::Gnmx::InputResourceOffsets* table);
            void setVsFetchShader(uint32_t, const void*);
            void setPsShader(const sce::Gnmx::PsShader*, const sce::Gnmx::InputResourceOffsets*);
            void setCsShader(const sce::Gnmx::CsShader*, const sce::Gnmx::InputResourceOffsets*);
            void setCsVsShaders(const sce::Gnmx::CsVsShader*, uint32_t, void*, const sce::Gnmx::InputResourceOffsets*, uint32_t, void*, const sce::Gnmx::InputResourceOffsets*);
            void setAsynchronousComputeShader(const sce::Gnmx::CsShader*, uint32_t, void*, const sce::Gnmx::InputResourceOffsets*);
            void setAppendConsumeCounterRange(sce::Gnm::ShaderStage, uint32_t, uint32_t);
            void setGdsMemoryRange(sce::Gnm::ShaderStage, uint32_t, uint32_t);
            void setConstantBuffers(sce::Gnm::ShaderStage, int32_t, int32_t, const sce::Gnm::Buffer*);
            void setVertexBuffers(sce::Gnm::ShaderStage, int32_t, int32_t, const sce::Gnm::Buffer*);
            void setBuffers(sce::Gnm::ShaderStage, int32_t, int32_t, const sce::Gnm::Buffer*);
            void setRwBuffers(sce::Gnm::ShaderStage, int32_t, int32_t, const sce::Gnm::Buffer*);
            void setTextures(sce::Gnm::ShaderStage, int32_t, int32_t, const sce::Gnm::Texture*);
            void setRwTextures(sce::Gnm::ShaderStage, int32_t, int32_t, const sce::Gnm::Texture*);
            void setSamplers(sce::Gnm::ShaderStage, int32_t, int32_t, const sce::Gnm::Sampler*);
            void setUserSrtBuffer(sce::Gnm::ShaderStage, const void*, uint32_t);
            void preDraw();
            void preDispatch();
            void setDispatchDrawData(const void*, uint32_t);
            void setVertexAndInstanceOffset(uint32_t, uint32_t);
            bool isVertexOrInstanceOffsetEnabled() const;
            const void* getBoundShader(sce::Gnm::ShaderStage);
            sce::Gnm::ActiveShaderStages getActiveShaderStages();
            void setPsInputUsageTable(uint32_t*);
            void setInternalSrtBuffer(sce::Gnm::ShaderStage, const void*);
        public:
            sce::Gnmx::GnmxDrawCommandBuffer* m_drawCommandBuffer;  // offset: 0x80
            sce::Gnmx::GnmxDispatchCommandBuffer* m_asyncDispatchCommandBuffer;  // offset: 0x88
            uint32_t m_scratchBuffer[12288];  // offset: 0x90
            sce::Gnm::ActiveShaderStages m_activeShaderStages;  // offset: 0xc090
            const void* m_boundShader[8];  // offset: 0xc098
            uint32_t m_boundShaderAppendConsumeCounterRange[8];  // offset: 0xc0d8
            uint32_t m_boundShaderGdsMemoryRange[8];  // offset: 0xc0f8
            const void* m_boundFetchShader[8];  // offset: 0xc118
            uint32_t m_boundShaderModifier[8];  // offset: 0xc158
            const sce::Gnmx::InputResourceOffsets* m_boundShaderResourceOffsets[8];  // offset: 0xc178
            bool m_dirtyShader[8];  // offset: 0xc1b8
            bool m_dirtyShaderResources[8];  // offset: 0xc1c0
            bool m_dirtyShaderUpdateOnly[8];  // offset: 0xc1c8
            uint16_t m_shaderBindingIsValid;  // offset: 0xc1d0
            const uint32_t* m_psInputsTable;  // offset: 0xc1d8
            sce::Gnmx::InputResourceOffsets m_fixedGsVsShaderResourceOffsets;  // offset: 0xc1e0
            sce::Gnmx::InputResourceOffsets m_fixedGsVsStreamOutShaderResourceOffsets;  // offset: 0xc2b8
            sce::Gnmx::InputResourceOffsets m_fixedOnChipGsVsShaderResourceOffsets;  // offset: 0xc390
            sce::Gnmx::InputResourceOffsets m_fixedOnChipGsVsStreamOutShaderResourceOffsets;  // offset: 0xc468
            sce::Gnm::GsMode m_gsMode;  // offset: 0xc540
            sce::Gnm::GsMaxOutputPrimitiveDwordSize m_gsMaxOutput;  // offset: 0xc544
            uint16_t m_onChipEsVertsPerSubGroup;  // offset: 0xc548
            uint16_t m_onChipEsExportVertexSizeInDword;  // offset: 0xc54a
            uint32_t m_onChipLdsSizeIn512Bytes;  // offset: 0xc54c
            uint32_t m_tessellationCurrentTgPatchCount;  // offset: 0xc550
            sce::Gnm::Buffer m_tessellationCurrentCb;  // offset: 0xc554
            bool m_tessellationAutoManageReservedCb;  // offset: 0xc564
            const void* m_pDispatchDrawData;  // offset: 0xc568
            uint8_t m_dispatchDrawIndexDeallocNumBits;  // offset: 0xc570
            sce::Gnm::DispatchOrderedAppendMode m_dispatchDrawOrderedAppendMode;  // offset: 0xc574
            uint32_t m_sizeofDispatchDrawData;  // offset: 0xc578
            bool m_dispatchDrawActive;  // offset: 0xc57c
            sce::Gnmx::LightweightConstantUpdateEngine::ShaderResourceBindingValidation m_boundShaderResourcesValidation[8];  // offset: 0xc57d
        };
    }  // namespace Gnmx
}  // namespace sce
