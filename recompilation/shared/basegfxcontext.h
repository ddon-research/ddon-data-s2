#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "constantcommandbuffer.h"
#include "constants.h"
#include "dispatchcommandbuffer.h"
#include "dispatchdraw.h"
#include "drawcommandbuffer.h"

// Forward declarations
namespace sce { namespace Gnm { class AaSampleLocationControl; } }
namespace sce { namespace Gnm { class AlphaToMaskControl; } }
namespace sce { namespace Gnm { class BlendControl; } }
namespace sce { namespace Gnm { class ClipControl; } }
namespace sce { namespace Gnm { class CommandBuffer; } }
namespace sce { namespace Gnm { class ConstantCommandBuffer; } }
namespace sce { namespace Gnm { class DbRenderControl; } }
namespace sce { namespace Gnm { class DepthEqaaControl; } }
namespace sce { namespace Gnm { class DepthRenderTarget; } }
namespace sce { namespace Gnm { class DepthStencilControl; } }
namespace sce { namespace Gnm { class DispatchCommandBuffer; } }
namespace sce { namespace Gnm { class DrawCommandBuffer; } }
namespace sce { namespace Gnm { class GraphicsShaderControl; } }
namespace sce { namespace Gnm { class GsStageRegisters; } }
namespace sce { namespace Gnm { class HsStageRegisters; } }
namespace sce { namespace Gnm { class HtileStencilControl; } }
namespace sce { namespace Gnm { class OcclusionQueryResults; } }
namespace sce { namespace Gnm { class PrimitiveSetup; } }
namespace sce { namespace Gnm { class PsStageRegisters; } }
namespace sce { namespace Gnm { class RenderOverride2Control; } }
namespace sce { namespace Gnm { class RenderOverrideControl; } }
namespace sce { namespace Gnm { class RenderTarget; } }
namespace sce { namespace Gnm { class StencilControl; } }
namespace sce { namespace Gnm { class StencilOpControl; } }
namespace sce { namespace Gnm { class StreamoutBufferMapping; } }
namespace sce { namespace Gnm { class TessellationRegisters; } }
namespace sce { namespace Gnm { class ViewportTransformControl; } }
namespace sce { namespace Gnm { class VsStageRegisters; } }
namespace sce { namespace Gnmx { class ComputeQueue; } }
namespace sce { namespace Gnmx { class DispatchDrawTriangleCullV1SharedData; } }
namespace sce { namespace Gnmx { class ResourceBarrier; } }

// Declarations
namespace sce { namespace Gnmx { class BaseGfxContext; } }

// Type aliases from DWARF
using __int16_t = short;
using __int32_t = int;
using __uint16_t = unsigned short;
using __uint32_t = unsigned int;
using __uint64_t = long unsigned int;
using __uint8_t = unsigned char;
using int16_t = __int16_t;
using int32_t = __int32_t;
namespace sce { namespace Gnmx { using GnmxConstantCommandBuffer = sce::Gnm::ConstantCommandBuffer; } }
namespace sce { namespace Gnmx { using GnmxDispatchCommandBuffer = sce::Gnm::DispatchCommandBuffer; } }
namespace sce { namespace Gnmx { using GnmxDrawCommandBuffer = sce::Gnm::DrawCommandBuffer; } }
using uint16_t = __uint16_t;
using uint32_t = __uint32_t;
using uint64_t = __uint64_t;
using uint8_t = __uint8_t;

namespace sce {
    namespace Gnmx {
        class BaseGfxContext
        {
        public:
            class SubmissionRange;
            class BufferFullCallback;
        public:
            using DispatchDrawSharedData = sce::Gnmx::DispatchDrawTriangleCullV1SharedData;
            using BufferFullCallbackFunc = bool(*)(sce::Gnmx::BaseGfxContext*, sce::Gnm::CommandBuffer*, uint32_t, void*);
        public:
            class SubmissionRange
            {
            public:
                uint32_t m_dcbStartDwordOffset;  // offset: 0x0
                uint32_t m_dcbSizeInDwords;  // offset: 0x4
                uint32_t m_acbStartDwordOffset;  // offset: 0x8
                uint32_t m_acbSizeInDwords;  // offset: 0xc
                uint32_t m_ccbStartDwordOffset;  // offset: 0x10
                uint32_t m_ccbSizeInDwords;  // offset: 0x14
            };
        public:
            class BufferFullCallback
            {
            public:
                sce::Gnmx::BaseGfxContext::BufferFullCallbackFunc m_func;  // offset: 0x0
                void* m_userData;  // offset: 0x8
            };
        public:
            BaseGfxContext();
            ~BaseGfxContext();
            void setDispatchDrawComputeQueue(sce::Gnmx::ComputeQueue*);
            void initializeDefaultHardwareState();
            void initializeToDefaultContextState();
            void setGraphicsShaderControl(sce::Gnm::GraphicsShaderControl);
            void setGraphicsShaderControl(sce::Gnm::ShaderStage, uint16_t, uint32_t, uint32_t);
            void setAsynchronousComputeShaderControl(uint32_t, uint32_t, uint32_t);
            void setAsynchronousComputeResourceManagement(sce::Gnm::ShaderEngine, uint16_t);
            void setIndexSize(sce::Gnm::IndexSize indexSize);
            void setIndexBuffer(const void* indexAddr);
            void setPrimitiveType(sce::Gnm::PrimitiveType primType);
            void setNumInstances(uint32_t numInstances);
            void setVgtControl(uint8_t, sce::Gnm::VgtPartialVsWaveMode);
            void setVgtControl(uint8_t, sce::Gnm::VgtPartialVsWaveMode, sce::Gnm::VgtSwitchOnEopMode);
            void writeImmediateAtEndOfPipe(sce::Gnm::EndOfPipeEventType, void*, uint64_t, sce::Gnm::CacheAction);
            void writeImmediateDwordAtEndOfPipe(sce::Gnm::EndOfPipeEventType, void*, uint64_t, sce::Gnm::CacheAction);
            void writeResourceBarrier(const sce::Gnmx::ResourceBarrier*);
            void writeTimestampAtEndOfPipe(sce::Gnm::EndOfPipeEventType eventType, void* dstGpuAddr, sce::Gnm::CacheAction cacheAction);
            void writeImmediateAtEndOfPipeWithInterrupt(sce::Gnm::EndOfPipeEventType, void*, uint64_t, sce::Gnm::CacheAction);
            void writeTimestampAtEndOfPipeWithInterrupt(sce::Gnm::EndOfPipeEventType, void*, sce::Gnm::CacheAction);
            void setGsModeOff();
            void endDispatchDraw(sce::Gnm::IndexSize, const void*, uint8_t, sce::Gnm::VgtPartialVsWaveMode);
            void endDispatchDraw(sce::Gnm::IndexSize, const void*, uint8_t, sce::Gnm::VgtPartialVsWaveMode, sce::Gnm::VgtSwitchOnEopMode);
            void endDispatchDraw(sce::Gnm::IndexSize, const void*);
            void endDispatchDraw();
            void setRenderTarget(uint32_t, const sce::Gnm::RenderTarget*);
            void fillData(void*, uint32_t, uint32_t, sce::Gnm::DmaDataBlockingMode);
            void copyData(void*, const void*, uint32_t, sce::Gnm::DmaDataBlockingMode);
            void* embedData(const void*, uint32_t, sce::Gnm::EmbeddedDataAlignment);
            void setAaDefaultSampleLocations(sce::Gnm::NumSamples);
            void setupScreenViewport(uint32_t, uint32_t, uint32_t, uint32_t, float, float);
            void setupDispatchDrawClipCullSettings(uint32_t);
            void setDispatchDrawNumInstances(uint32_t);
            void setDispatchDrawInstanceStepRate(uint32_t, uint32_t);
            void clearAppendConsumeCounters(uint32_t, uint32_t, uint32_t, uint32_t);
            void writeAppendConsumeCounters(uint32_t, uint32_t, uint32_t, const void*);
            void readAppendConsumeCounters(void*, uint32_t, uint32_t, uint32_t);
            void setShaderType(sce::Gnm::ShaderType);
            void flushStreamout();
            void setStreamoutBufferDimensions(sce::Gnm::StreamoutBufferId, uint32_t, uint32_t);
            void setStreamoutMapping(const sce::Gnm::StreamoutBufferMapping*);
            void writeStreamoutBufferUpdate(sce::Gnm::StreamoutBufferId, sce::Gnm::StreamoutBufferUpdateWrite, sce::Gnm::StreamoutBufferUpdateSaveFilledSize, void*, uint64_t);
            void writeStreamoutBufferOffset(sce::Gnm::StreamoutBufferId, uint32_t);
            void setVsShaderStreamoutEnable(bool);
            void setupDrawOpaqueParameters(void*, uint32_t, uint32_t);
            void setComputeShaderControl(uint32_t, uint32_t, uint32_t);
            void setComputeResourceManagement(sce::Gnm::ShaderEngine, uint16_t);
            void setGraphicsResourceManagement(sce::Gnm::ShaderEngine, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);
            void setGraphicsScratchSize(uint32_t, uint32_t);
            void setComputeScratchSize(uint32_t, uint32_t);
            void setViewportTransformControl(sce::Gnm::ViewportTransformControl vportControl);
            void setClipControl(sce::Gnm::ClipControl reg);
            void setUserClipPlane(uint32_t, float, float, float, float);
            void setClipRectangle(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t);
            void setClipRectangleRule(uint16_t);
            void setPrimitiveSetup(sce::Gnm::PrimitiveSetup reg);
            void setPrimitiveResetIndexEnable(bool enable);
            void setPrimitiveResetIndex(uint32_t resetIndex);
            void setVertexQuantization(sce::Gnm::VertexQuantizationMode, sce::Gnm::VertexQuantizationRoundMode, sce::Gnm::VertexQuantizationCenterMode);
            void setWindowOffset(int16_t, int16_t);
            void setScreenScissor(int32_t left, int32_t top, int32_t right, int32_t bottom);
            void setWindowScissor(uint32_t, uint32_t, uint32_t, uint32_t, sce::Gnm::WindowOffsetMode);
            void setGenericScissor(uint32_t, uint32_t, uint32_t, uint32_t, sce::Gnm::WindowOffsetMode);
            void setViewportScissor(uint32_t viewportId, uint32_t left, uint32_t top, uint32_t right, uint32_t bottom, sce::Gnm::WindowOffsetMode windowOffsetEnable);
            void setViewport(uint32_t viewportId, float dmin, float dmax, const float* scale, const float* offset);
            void setScanModeControl(sce::Gnm::ScanModeControlAa msaa, sce::Gnm::ScanModeControlViewportScissor viewportScissor);
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
            void setPolygonOffsetClamp(float clamp);
            void setPolygonOffsetZFormat(sce::Gnm::ZFormat format);
            void setPolygonOffsetFront(float scale, float offset);
            void setPolygonOffsetBack(float scale, float offset);
            void setHardwareScreenOffset(uint32_t offsetX, uint32_t offsetY);
            void setGuardBands(float horzClip, float vertClip, float horzDiscard, float vertDiscard);
            void setGuardBandClip(float, float);
            void setGuardBandDiscard(float, float);
            void setInstanceStepRate(uint32_t, uint32_t);
            void setPsShaderUsage(const uint32_t*, uint32_t);
            void setGsOnChipControl(uint32_t, uint32_t);
            void updatePsShader(const sce::Gnm::PsStageRegisters*);
            void updateVsShader(const sce::Gnm::VsStageRegisters*, uint32_t);
            void updateGsShader(const sce::Gnm::GsStageRegisters*);
            void updateHsShader(const sce::Gnm::HsStageRegisters*, const sce::Gnm::TessellationRegisters*);
            void setBorderColorTableAddr(void* tableAddr);
            void readDataFromGds(sce::Gnm::EndOfShaderEventType, void*, uint32_t, uint32_t);
            void* allocateFromCommandBuffer(uint32_t sizeInBytes, sce::Gnm::EmbeddedDataAlignment alignment);
            void setUserDataRegion(sce::Gnm::ShaderStage, uint32_t, const uint32_t*, uint32_t);
            void setDepthRenderTarget(const sce::Gnm::DepthRenderTarget* depthTarget);
            void setDepthClearValue(float clearValue);
            void setStencilClearValue(uint8_t clearValue);
            void setCmaskClearColor(uint32_t, const uint32_t*);
            void setRenderTargetMask(uint32_t mask);
            void setBlendControl(uint32_t rtSlot, sce::Gnm::BlendControl blendControl);
            void setBlendColor(float red, float green, float blue, float alpha);
            void setStencil(sce::Gnm::StencilControl stencilControl);
            void setStencilSeparate(sce::Gnm::StencilControl, sce::Gnm::StencilControl);
            void setAlphaToMaskControl(sce::Gnm::AlphaToMaskControl alphaToMaskControl);
            void setHtileStencil0(sce::Gnm::HtileStencilControl);
            void setHtileStencil1(sce::Gnm::HtileStencilControl);
            void setCbControl(sce::Gnm::CbMode, sce::Gnm::RasterOp);
            void setDepthStencilControl(sce::Gnm::DepthStencilControl depthControl);
            void setDepthStencilDisable();
            void setDepthBoundsRange(float, float);
            void setStencilOpControl(sce::Gnm::StencilOpControl stencilControl);
            void setDbRenderControl(sce::Gnm::DbRenderControl reg);
            void setDbCountControl(sce::Gnm::DbCountControlPerfectZPassCounts, uint32_t);
            void setDbCountControl(sce::Gnm::DbCountControlZPassIncrement, sce::Gnm::DbCountControlPerfectZPassCounts, uint32_t);
            void setDepthEqaaControl(sce::Gnm::DepthEqaaControl);
            void setPrimitiveIdEnable(bool);
            void setVertexReuseEnable(bool);
            void setIndexOffset(uint32_t offset);
            void drawOpaqueAuto();
            void setIndexCount(uint32_t indexCount);
            void setBaseIndirectArgs(void*);
            void enableOrderedAppendAllocationCounter(uint32_t, uint32_t, sce::Gnm::ShaderStage, uint32_t, uint32_t);
            void disableOrderedAppendAllocationCounter(uint32_t);
            void writeOcclusionQuery(sce::Gnm::OcclusionQueryOp, sce::Gnm::OcclusionQueryResults*);
            void setZPassPredicationEnable(sce::Gnm::OcclusionQueryResults*, sce::Gnm::PredicationZPassHint, sce::Gnm::PredicationZPassAction);
            void setZPassPredicationDisable();
            void writeDataInline(void*, const void*, uint32_t, sce::Gnm::WriteDataConfirmMode);
            void writeDataInlineThroughL2(void*, const void*, uint32_t, sce::Gnm::CachePolicy, sce::Gnm::WriteDataConfirmMode);
            void triggerEvent(sce::Gnm::EventType);
            void writeAtEndOfPipe(sce::Gnm::EndOfPipeEventType, sce::Gnm::EventWriteDest, void*, sce::Gnm::EventWriteSource, uint64_t, sce::Gnm::CacheAction, sce::Gnm::CachePolicy);
            void writeAtEndOfPipeWithInterrupt(sce::Gnm::EndOfPipeEventType eventType, sce::Gnm::EventWriteDest dstSelector, void* dstGpuAddr, sce::Gnm::EventWriteSource srcSelector, uint64_t immValue, sce::Gnm::CacheAction cacheAction, sce::Gnm::CachePolicy cachePolicy);
            void triggerEndOfPipeInterrupt(sce::Gnm::EndOfPipeEventType, sce::Gnm::CacheAction);
            void writeAtEndOfShader(sce::Gnm::EndOfShaderEventType, void*, uint32_t);
            void waitOnAddress(void*, uint32_t, sce::Gnm::WaitCompareFunc, uint32_t);
            void stallCommandBufferParser();
            void waitOnAddressAndStallCommandBufferParser(void*, uint32_t, uint32_t);
            void waitOnRegister(uint16_t, uint32_t, sce::Gnm::WaitCompareFunc, uint32_t);
            void waitForGraphicsWrites(uint32_t baseAddr256, uint32_t sizeIn256ByteBlocks, uint32_t targetMask, sce::Gnm::CacheAction cacheAction, uint32_t extendedCacheMask, sce::Gnm::StallCommandBufferParserMode commandBufferStallMode);
            void flushShaderCachesAndWait(sce::Gnm::CacheAction, uint32_t, sce::Gnm::StallCommandBufferParserMode);
            void signalSemaphore(uint64_t*, sce::Gnm::SemaphoreSignalBehavior, sce::Gnm::SemaphoreUpdateConfirmMode);
            void waitSemaphore(uint64_t*, sce::Gnm::SemaphoreWaitBehavior);
            void writeEventStats(sce::Gnm::EventStats, void*);
            void insertNop(uint32_t);
            void setMarker(const char*);
            void setMarker(const char*, uint32_t);
            void pushMarker(const char*);
            void pushMarker(const char*, uint32_t);
            void popMarker();
            void prefetchIntoL2(void*, uint32_t);
            void waitUntilSafeForRendering(uint32_t videoOutHandle, uint32_t displayBufferIndex);
            uint64_t pause(uint32_t);
            void resume(uint64_t);
            void fillAndResume(uint64_t, void*, uint32_t);
            void chainCommandBufferAndResume(uint64_t, void*, uint64_t);
            void chainCommandBuffer(void*, uint64_t);
        public:
            sce::Gnmx::GnmxDrawCommandBuffer m_dcb;  // offset: 0x0
            sce::Gnmx::GnmxDispatchCommandBuffer m_acb;  // offset: 0x40
            sce::Gnmx::GnmxConstantCommandBuffer m_ccb;  // offset: 0x80
            sce::Gnmx::ComputeQueue* m_pQueue;  // offset: 0xc0
            DispatchDrawSharedData m_dispatchDrawSharedData;  // offset: 0xc8
            DispatchDrawSharedData* m_pDispatchDrawSharedData;  // offset: 0xf0
            uint32_t m_dispatchDrawIndexDeallocMask;  // offset: 0xf8
            uint16_t m_dispatchDrawNumInstancesMinus1;  // offset: 0xfc
            uint16_t m_dispatchDrawInstanceStepRate0Minus1;  // offset: 0xfe
            uint16_t m_dispatchDrawInstanceStepRate1Minus1;  // offset: 0x100
            uint16_t m_dispatchDrawFlags;  // offset: 0x102
            const uint32_t* m_currentDcbSubmissionStart;  // offset: 0x108
            const uint32_t* m_currentAcbSubmissionStart;  // offset: 0x110
            const uint32_t* m_currentCcbSubmissionStart;  // offset: 0x118
            const uint32_t* m_actualDcbEnd;  // offset: 0x120
            const uint32_t* m_actualAcbEnd;  // offset: 0x128
            const uint32_t* m_actualCcbEnd;  // offset: 0x130
            SubmissionRange m_submissionRanges[16];  // offset: 0x138
            uint32_t m_submissionCount;  // offset: 0x2b8
            BufferFullCallback m_cbFullCallback;  // offset: 0x2c0
            static const uint16_t kDispatchDrawFlagInDispatchDraw = 1;
            static const uint16_t kDispatchDrawFlagIrbValid = 2;
            static const uint32_t kIndexSizeFlagDispatchDraw = 16;
            static const uint32_t kMaxNumStoredSubmissions = 16;
        };
    }  // namespace Gnmx
}  // namespace sce
