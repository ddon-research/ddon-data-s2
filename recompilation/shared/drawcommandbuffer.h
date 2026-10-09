#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "commandbuffer.h"
#include "constants.h"

// Forward declarations
namespace sce { namespace Gnm { class AaSampleLocationControl; } }
namespace sce { namespace Gnm { class AlphaToMaskControl; } }
namespace sce { namespace Gnm { class BlendControl; } }
namespace sce { namespace Gnm { class ClipControl; } }
namespace sce { namespace Gnm { class DbRenderControl; } }
namespace sce { namespace Gnm { class DepthEqaaControl; } }
namespace sce { namespace Gnm { class DepthRenderTarget; } }
namespace sce { namespace Gnm { class DepthStencilControl; } }
namespace sce { namespace Gnm { class GraphicsShaderControl; } }
namespace sce { namespace Gnm { class GsStageRegisters; } }
namespace sce { namespace Gnm { class HsStageRegisters; } }
namespace sce { namespace Gnm { class HtileStencilControl; } }
namespace sce { namespace Gnm { class OcclusionQueryResults; } }
namespace sce { namespace Gnm { class PrimitiveSetup; } }
namespace sce { namespace Gnm { class PsStageRegisters; } }
namespace sce { namespace Gnm { class RenderOverride2Control; } }
namespace sce { namespace Gnm { class RenderOverrideControl; } }
namespace sce { namespace Gnm { class StencilControl; } }
namespace sce { namespace Gnm { class StencilOpControl; } }
namespace sce { namespace Gnm { class StreamoutBufferMapping; } }
namespace sce { namespace Gnm { class TessellationRegisters; } }
namespace sce { namespace Gnm { class ViewportTransformControl; } }
namespace sce { namespace Gnm { class VsStageRegisters; } }

// Declarations
namespace sce { namespace Gnm { class DrawCommandBuffer; } }

// Type aliases from DWARF
using __int16_t = short;
using __int32_t = int;
using __uint16_t = unsigned short;
using __uint32_t = unsigned int;
using __uint64_t = long unsigned int;
using __uint8_t = unsigned char;
using int16_t = __int16_t;
using int32_t = __int32_t;
using uint16_t = __uint16_t;
using uint32_t = __uint32_t;
using uint64_t = __uint64_t;
using uint8_t = __uint8_t;

namespace sce {
    namespace Gnm {
        class DrawCommandBuffer : public sce::Gnm::CommandBuffer
        {
        public:
            DrawCommandBuffer();
            void setShaderType(sce::Gnm::ShaderType);
            void initializeDefaultHardwareState();
            void initializeToDefaultContextState();
            void setupEsGsRingRegisters(uint32_t);
            void flushStreamout();
            void setStreamoutBufferDimensions(sce::Gnm::StreamoutBufferId, uint32_t, uint32_t);
            void setStreamoutMapping(const sce::Gnm::StreamoutBufferMapping*);
            void writeStreamoutBufferUpdate(sce::Gnm::StreamoutBufferId, sce::Gnm::StreamoutBufferUpdateWrite, sce::Gnm::StreamoutBufferUpdateSaveFilledSize, void*, uint64_t);
            void writeStreamoutBufferOffset(sce::Gnm::StreamoutBufferId, uint32_t);
            void setVsShaderStreamoutEnable(bool);
            void setupDrawOpaqueParameters(void*, uint32_t, uint32_t);
            void setGraphicsShaderControl(sce::Gnm::GraphicsShaderControl);
            void setGraphicsShaderControl(sce::Gnm::ShaderStage, uint16_t, uint32_t, uint32_t);
            void setComputeShaderControl(uint32_t, uint32_t, uint32_t);
            void setComputeResourceManagement(sce::Gnm::ShaderEngine, uint16_t);
            void setGraphicsResourceManagement(sce::Gnm::ShaderEngine, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);
            void setGraphicsScratchSize(uint32_t, uint32_t);
            void setComputeScratchSize(uint32_t, uint32_t);
            void setViewportTransformControl(sce::Gnm::ViewportTransformControl);
            void setClipControl(sce::Gnm::ClipControl);
            void setUserClipPlane(uint32_t, float, float, float, float);
            void setClipRectangle(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
            void setClipRectangleRule(uint16_t);
            void setPrimitiveSetup(sce::Gnm::PrimitiveSetup);
            void setPrimitiveResetIndexEnable(bool);
            void setPrimitiveResetIndex(uint32_t);
            void setVertexQuantization(sce::Gnm::VertexQuantizationMode, sce::Gnm::VertexQuantizationRoundMode, sce::Gnm::VertexQuantizationCenterMode);
            void setWindowOffset(int16_t, int16_t);
            void setScreenScissor(int32_t, int32_t, int32_t, int32_t);
            void setWindowScissor(uint32_t, uint32_t, uint32_t, uint32_t, sce::Gnm::WindowOffsetMode);
            void setGenericScissor(uint32_t, uint32_t, uint32_t, uint32_t, sce::Gnm::WindowOffsetMode);
            void setViewportScissor(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, sce::Gnm::WindowOffsetMode);
            void setViewport(uint32_t, float, float, const float*, const float*);
            void setScanModeControl(sce::Gnm::ScanModeControlAa, sce::Gnm::ScanModeControlViewportScissor);
            void setAaSampleCount(sce::Gnm::NumSamples, uint32_t);
            void setAaSampleCount(sce::Gnm::NumSamples);
            void setPsShaderRate(sce::Gnm::PsShaderRate);
            void setRenderOverrideControl(sce::Gnm::RenderOverrideControl);
            void setRenderOverride2Control(sce::Gnm::RenderOverride2Control);
            void setAaSampleMask(uint64_t);
            void setAaSampleLocations(uint32_t*);
            void setCentroidPriority(uint64_t);
            void setAaSampleLocationControl(const sce::Gnm::AaSampleLocationControl*);
            void setLineWidth(uint16_t);
            void setPointSize(uint16_t, uint16_t);
            void setPointMinMax(uint16_t, uint16_t);
            void setPolygonOffsetClamp(float);
            void setPolygonOffsetZFormat(sce::Gnm::ZFormat);
            void setPolygonOffsetFront(float, float);
            void setPolygonOffsetBack(float, float);
            void setHardwareScreenOffset(uint32_t, uint32_t);
            void setGuardBands(float, float, float, float);
            void setGuardBandClip(float, float);
            void setGuardBandDiscard(float, float);
            void setInstanceStepRate(uint32_t, uint32_t);
            void setPsShaderUsage(const uint32_t*, uint32_t);
            void setActiveShaderStages(sce::Gnm::ActiveShaderStages);
            void setGsMode(sce::Gnm::GsMode, sce::Gnm::GsMaxOutputPrimitiveDwordSize);
            void setGsMode(sce::Gnm::GsMode, sce::Gnm::GsMaxOutputVertexCount);
            void setGsOnChipControl(uint32_t, uint32_t);
            void setEmbeddedPsShader(sce::Gnm::EmbeddedPsShader);
            void updatePsShader(const sce::Gnm::PsStageRegisters*);
            void setEmbeddedVsShader(sce::Gnm::EmbeddedVsShader, uint32_t);
            void updateVsShader(const sce::Gnm::VsStageRegisters*, uint32_t);
            void updateGsShader(const sce::Gnm::GsStageRegisters*);
            void updateHsShader(const sce::Gnm::HsStageRegisters*, const sce::Gnm::TessellationRegisters*);
            void setBorderColorTableAddr(void*);
            void readDataFromGds(sce::Gnm::EndOfShaderEventType, void*, uint32_t, uint32_t);
            void* allocateFromCommandBuffer(uint32_t, sce::Gnm::EmbeddedDataAlignment);
            void setUserDataRegion(sce::Gnm::ShaderStage, uint32_t, const uint32_t*, uint32_t);
            void setDepthRenderTarget(const sce::Gnm::DepthRenderTarget*);
            void setDepthClearValue(float);
            void setStencilClearValue(uint8_t);
            void setCmaskClearColor(uint32_t, const uint32_t*);
            void setRenderTargetMask(uint32_t);
            void setBlendControl(uint32_t, sce::Gnm::BlendControl);
            void setBlendColor(float, float, float, float);
            void setStencil(sce::Gnm::StencilControl);
            void setStencilSeparate(sce::Gnm::StencilControl, sce::Gnm::StencilControl);
            void setAlphaToMaskControl(sce::Gnm::AlphaToMaskControl);
            void setHtileStencil0(sce::Gnm::HtileStencilControl);
            void setHtileStencil1(sce::Gnm::HtileStencilControl);
            void setCbControl(sce::Gnm::CbMode, sce::Gnm::RasterOp);
            void setDepthStencilControl(sce::Gnm::DepthStencilControl);
            void setDepthStencilDisable();
            void setDepthBoundsRange(float, float);
            void setStencilOpControl(sce::Gnm::StencilOpControl);
            void setDbRenderControl(sce::Gnm::DbRenderControl);
            void setDbCountControl(sce::Gnm::DbCountControlPerfectZPassCounts, uint32_t);
            void setDbCountControl(sce::Gnm::DbCountControlZPassIncrement, sce::Gnm::DbCountControlPerfectZPassCounts, uint32_t);
            void setDepthEqaaControl(sce::Gnm::DepthEqaaControl);
            void setPrimitiveIdEnable(bool);
            void setVgtControl(uint8_t, sce::Gnm::VgtPartialVsWaveMode);
            void setVertexReuseEnable(bool);
            void setPrimitiveType(sce::Gnm::PrimitiveType);
            void setIndexSize(sce::Gnm::IndexSize, sce::Gnm::CachePolicy);
            void setIndexSize(sce::Gnm::IndexSize);
            void setNumInstances(uint32_t);
            void setIndexOffset(uint32_t);
            void drawIndexAuto(uint32_t);
            void drawOpaqueAuto();
            void drawIndexInline(uint32_t, const void*, uint32_t);
            void drawIndex(uint32_t, const void*);
            void setIndexBuffer(const void*);
            void setIndexCount(uint32_t);
            void drawIndexOffset(uint32_t, uint32_t);
            void setBaseIndirectArgs(void*);
            void drawIndirect(uint32_t, sce::Gnm::ShaderStage, uint8_t, uint8_t);
            void drawIndirectMulti(uint32_t, uint32_t, sce::Gnm::ShaderStage, uint8_t, uint8_t);
            void drawIndexIndirect(uint32_t, sce::Gnm::ShaderStage, uint8_t, uint8_t);
            void drawIndexIndirectMulti(uint32_t, uint32_t, sce::Gnm::ShaderStage, uint8_t, uint8_t);
            void enableOrderedAppendAllocationCounter(uint32_t, uint32_t, sce::Gnm::ShaderStage, uint32_t, uint32_t);
            void disableOrderedAppendAllocationCounter(uint32_t);
            void dispatch(uint32_t, uint32_t, uint32_t);
            void dispatchIndirect(uint32_t);
            void writeOcclusionQuery(sce::Gnm::OcclusionQueryOp, sce::Gnm::OcclusionQueryResults*);
            void setZPassPredicationEnable(sce::Gnm::OcclusionQueryResults*, sce::Gnm::PredicationZPassHint, sce::Gnm::PredicationZPassAction);
            void setZPassPredicationDisable();
            void writeDataInline(void*, const void*, uint32_t, sce::Gnm::WriteDataConfirmMode);
            void writeDataInlineThroughL2(void*, const void*, uint32_t, sce::Gnm::CachePolicy, sce::Gnm::WriteDataConfirmMode);
            void triggerEvent(sce::Gnm::EventType);
            void writeAtEndOfPipe(sce::Gnm::EndOfPipeEventType, sce::Gnm::EventWriteDest, void*, sce::Gnm::EventWriteSource, uint64_t, sce::Gnm::CacheAction, sce::Gnm::CachePolicy);
            void writeAtEndOfPipeWithInterrupt(sce::Gnm::EndOfPipeEventType, sce::Gnm::EventWriteDest, void*, sce::Gnm::EventWriteSource, uint64_t, sce::Gnm::CacheAction, sce::Gnm::CachePolicy);
            void triggerEndOfPipeInterrupt(sce::Gnm::EndOfPipeEventType, sce::Gnm::CacheAction);
            void writeAtEndOfShader(sce::Gnm::EndOfShaderEventType, void*, uint32_t);
            void waitOnAddress(void*, uint32_t, sce::Gnm::WaitCompareFunc, uint32_t);
            void stallCommandBufferParser();
            void waitOnAddressAndStallCommandBufferParser(void*, uint32_t, uint32_t);
            void waitOnRegister(uint16_t, uint32_t, sce::Gnm::WaitCompareFunc, uint32_t);
            void waitForGraphicsWrites(uint32_t, uint32_t, uint32_t, sce::Gnm::CacheAction, uint32_t, sce::Gnm::StallCommandBufferParserMode);
            void flushShaderCachesAndWait(sce::Gnm::CacheAction, uint32_t, sce::Gnm::StallCommandBufferParserMode);
            void signalSemaphore(uint64_t*, sce::Gnm::SemaphoreSignalBehavior, sce::Gnm::SemaphoreUpdateConfirmMode);
            void waitSemaphore(uint64_t*, sce::Gnm::SemaphoreWaitBehavior);
            void writeEventStats(sce::Gnm::EventStats, void*);
            void insertNop(uint32_t);
            void setThreadTraceDispatchDrawMarker(uint16_t);
            void setMarker(const char*);
            void setMarker(const char*, uint32_t);
            void pushMarker(const char*);
            void pushMarker(const char*, uint32_t);
            void popMarker();
            void markDispatchDrawAcbAddress(const uint32_t*, const uint32_t*);
            void markDispatchDrawAcbAddress(const uint32_t*);
            void prefetchIntoL2(void*, uint32_t);
            void waitUntilSafeForRendering(uint32_t, uint32_t);
            uint64_t pause(uint32_t);
            void resume(uint64_t);
            void fillAndResume(uint64_t, void*, uint32_t);
            void chainCommandBufferAndResume(uint64_t, void*, uint64_t);
            void chainCommandBuffer(void*, uint64_t);
        };
    }  // namespace Gnm
}  // namespace sce
