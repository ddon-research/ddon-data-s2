#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "basegfxcontext.h"
#include "constants.h"
#include "lwcue_graphics.h"

// Forward declarations
namespace sce { namespace Gnm { class Buffer; } }
namespace sce { namespace Gnm { class Sampler; } }
namespace sce { namespace Gnm { class Texture; } }
namespace sce { namespace Gnmx { class BaseConstantUpdateEngine; } }
namespace sce { namespace Gnmx { class CsShader; } }
namespace sce { namespace Gnmx { class CsVsShader; } }
namespace sce { namespace Gnmx { class EsShader; } }
namespace sce { namespace Gnmx { class GsShader; } }
namespace sce { namespace Gnmx { class HsShader; } }
namespace sce { namespace Gnmx { struct InputResourceOffsets; } }
namespace sce { namespace Gnmx { class LightweightGraphicsConstantUpdateEngine; } }
namespace sce { namespace Gnmx { class LsShader; } }
namespace sce { namespace Gnmx { class PsShader; } }
namespace sce { namespace Gnmx { class VsShader; } }

// Declarations
namespace sce { namespace Gnmx { class LightweightGfxContext; } }

// Type aliases from DWARF
using __int32_t = int;
using __int64_t = long int;
using __uint32_t = unsigned int;
using __uint8_t = unsigned char;
using int32_t = __int32_t;
using int64_t = __int64_t;
using uint32_t = __uint32_t;
namespace sce { namespace Gnmx { using AllocResourceBufferCallback = uint32_t* (*)(sce::Gnmx::BaseConstantUpdateEngine*, uint32_t, uint32_t*, void*); } }
using uint8_t = __uint8_t;

namespace sce {
    namespace Gnmx {
        class LightweightGfxContext : public sce::Gnmx::BaseGfxContext
        {
        public:
            void setActiveResourceSlotCount(sce::Gnm::ShaderStage, uint32_t);
            void setActiveRwResourceSlotCount(sce::Gnm::ShaderStage, uint32_t);
            void setActiveSamplerSlotCount(sce::Gnm::ShaderStage, uint32_t);
            void setActiveVertexBufferSlotCount(sce::Gnm::ShaderStage, uint32_t);
            void setActiveConstantBufferSlotCount(sce::Gnm::ShaderStage, uint32_t);
            void setActiveStreamoutBufferSlotCount(uint32_t);
            void setGsModeOff();
            void setUserResourceTable(sce::Gnm::ShaderStage, const sce::Gnm::Texture*);
            void setUserRwResourceTable(sce::Gnm::ShaderStage, const sce::Gnm::Texture*);
            void setUserSamplerTable(sce::Gnm::ShaderStage, const sce::Gnm::Sampler*);
            void setUserConstantBufferTable(sce::Gnm::ShaderStage, const sce::Gnm::Buffer*);
            void setUserVertexTable(sce::Gnm::ShaderStage, const sce::Gnm::Buffer*);
            void init(void*, int32_t, void*, int32_t, void*, uint32_t);
            void init(uint32_t*, int32_t, uint32_t*, int32_t, uint32_t*, uint32_t);
            void init(void*, int32_t, void*, int32_t, void*);
            void init(uint32_t*, int32_t, uint32_t*, int32_t, uint32_t*);
            void setResourceBufferFullCallback(sce::Gnmx::AllocResourceBufferCallback, void*);
            void reset();
            void setActiveShaderStages(sce::Gnm::ActiveShaderStages activeStages);
            void setEsShader(const sce::Gnmx::EsShader* esb, uint32_t shaderModifier, const void* fetchShader, const sce::Gnmx::InputResourceOffsets* table);
            void setEsShader(const sce::Gnmx::EsShader*, const sce::Gnmx::InputResourceOffsets*);
            void setOnChipEsShader(const sce::Gnmx::EsShader*, uint32_t, uint32_t, const void*, const sce::Gnmx::InputResourceOffsets*);
            void setOnChipEsShader(const sce::Gnmx::EsShader*, uint32_t, const sce::Gnmx::InputResourceOffsets*);
            void setEsFetchShader(uint32_t, const void*);
            void setGsVsShaders(const sce::Gnmx::GsShader* gsb, const sce::Gnmx::InputResourceOffsets* gsTable);
            void setOnChipGsVsShaders(const sce::Gnmx::GsShader*, uint32_t, const sce::Gnmx::InputResourceOffsets*);
            void setLsShader(const sce::Gnmx::LsShader*, uint32_t, const void*, const sce::Gnmx::InputResourceOffsets*);
            void setLsShader(const sce::Gnmx::LsShader*, const sce::Gnmx::InputResourceOffsets*);
            void setLsFetchShader(uint32_t, const void*);
            void setHsShader(const sce::Gnmx::HsShader*, const sce::Gnmx::InputResourceOffsets*, uint32_t);
            void setLsHsShaders(sce::Gnmx::LsShader*, uint32_t, void*, const sce::Gnmx::InputResourceOffsets*, const sce::Gnmx::HsShader*, const sce::Gnmx::InputResourceOffsets*, uint32_t);
            void setVsShader(const sce::Gnmx::VsShader* vsb, uint32_t shaderModifier, const void* fetchShader, const sce::Gnmx::InputResourceOffsets* table);
            void setVsShader(const sce::Gnmx::VsShader* vsb, const sce::Gnmx::InputResourceOffsets* table);
            void setVsFetchShader(uint32_t, const void*);
            void setEmbeddedVsShader(sce::Gnm::EmbeddedVsShader, uint32_t);
            void setPsShader(const sce::Gnmx::PsShader* psb, const sce::Gnmx::InputResourceOffsets* table);
            void setEmbeddedPsShader(sce::Gnm::EmbeddedPsShader);
            void setCsShader(const sce::Gnmx::CsShader*, const sce::Gnmx::InputResourceOffsets*);
            void setCsVsShaders(const sce::Gnmx::CsVsShader*, uint32_t, void*, const sce::Gnmx::InputResourceOffsets*, uint32_t, void*, const sce::Gnmx::InputResourceOffsets*);
            void setAsynchronousComputeShader(const sce::Gnmx::CsShader*, uint32_t, void*, const sce::Gnmx::InputResourceOffsets*);
            void setOnChipEsGsLdsLayout(uint32_t);
            void setStreamoutBuffers(int32_t, int32_t, const sce::Gnm::Buffer*);
            void setAppendConsumeCounterRange(sce::Gnm::ShaderStage, uint32_t, uint32_t);
            void setGdsMemoryRange(sce::Gnm::ShaderStage, uint32_t, uint32_t);
            void setConstantBuffers(sce::Gnm::ShaderStage stage, uint32_t startSlot, uint32_t numSlots, const sce::Gnm::Buffer* buffers);
            void setVertexBuffers(sce::Gnm::ShaderStage stage, uint32_t startSlot, uint32_t numSlots, const sce::Gnm::Buffer* buffers);
            void setBuffers(sce::Gnm::ShaderStage, uint32_t, uint32_t, const sce::Gnm::Buffer*);
            void setRwBuffers(sce::Gnm::ShaderStage, uint32_t, uint32_t, const sce::Gnm::Buffer*);
            void setTextures(sce::Gnm::ShaderStage stage, uint32_t startSlot, uint32_t numSlots, const sce::Gnm::Texture* textures);
            void setRwTextures(sce::Gnm::ShaderStage, uint32_t, uint32_t, const sce::Gnm::Texture*);
            void setSamplers(sce::Gnm::ShaderStage stage, uint32_t startSlot, uint32_t numSlots, const sce::Gnm::Sampler* samplers);
            void setUserSrtBuffer(sce::Gnm::ShaderStage, const void*, uint32_t);
            void setGlobalResourceTableAddr(void*);
            void setGlobalDescriptor(sce::Gnm::ShaderGlobalResourceType, const sce::Gnm::Buffer*);
            void setBoolConstants(sce::Gnm::ShaderStage, uint32_t, uint32_t, const uint32_t*);
            void setFloatConstants(sce::Gnm::ShaderStage, uint32_t, uint32_t, const float*);
            void drawIndexAuto(uint32_t indexCount);
            void drawIndexAuto(uint32_t, uint32_t, uint32_t);
            void drawOpaque();
            void drawOpaque(uint32_t, uint32_t);
            void drawIndexInline(uint32_t, const void*, uint32_t);
            void drawIndexInline(uint32_t, const void*, uint32_t, uint32_t, uint32_t);
            void drawIndex(uint32_t, const void*);
            void drawIndex(uint32_t, const void*, uint32_t, uint32_t);
            void drawIndexOffset(uint32_t indexOffset, uint32_t indexCount);
            void drawIndexOffset(uint32_t, uint32_t, uint32_t, uint32_t);
            void drawIndirect(uint32_t);
            void drawIndirectMulti(uint32_t, uint32_t);
            void drawIndirectMulti(uint32_t, uint32_t, sce::Gnm::ShaderStage, uint8_t, uint8_t);
            void drawIndexIndirect(uint32_t);
            void drawIndexIndirectMulti(uint32_t, uint32_t);
            void drawIndexIndirectMulti(uint32_t, uint32_t, sce::Gnm::ShaderStage, uint8_t, uint8_t);
            void dispatch(uint32_t, uint32_t, uint32_t);
            void dispatchIndirect(uint32_t);
            void setEsGsRingBuffer(void*, uint32_t, uint32_t);
            void setGsVsRingBuffers(void*, uint32_t, const uint32_t*, uint32_t);
            void setTessellationDataConstantBuffer(void*, sce::Gnm::ShaderStage);
            void setTessellationFactorBuffer(void*);
            int32_t submit();
            int32_t submitAndFlip(uint32_t, uint32_t, uint32_t, int64_t);
            int32_t validate();
        public:
            sce::Gnmx::LightweightGraphicsConstantUpdateEngine m_lwcue;  // offset: 0x2d0
        };
    }  // namespace Gnmx
}  // namespace sce
