#pragma once

#include <cstdint>
#include <cstddef>

namespace sce {
namespace Gnm {
    enum ActiveShaderStages
    {
        kActiveShaderStagesVsPs = 0,
        kActiveShaderStagesEsGsVsPs = 176,
        kActiveShaderStagesLsHsVsPs = 69,
        kActiveShaderStagesLsHsEsGsVsPs = 173,
        kActiveShaderStagesDispatchDrawVsPs = 512,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum AlphaToMaskDitherMode
    {
        kAlphaToMaskDitherModeDisabled = 0,
        kAlphaToMaskDitherModeEnabled = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum AlphaToMaskDitherThreshold
    {
        kAlphaToMaskDitherThreshold0 = 0,
        kAlphaToMaskDitherThreshold1 = 1,
        kAlphaToMaskDitherDisabled = 2,
        kAlphaToMaskDitherThreshold3 = 3,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum AlphaToMaskMode
    {
        kAlphaToMaskDisable = 0,
        kAlphaToMaskEnable = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum BlendFunc
    {
        kBlendFuncAdd = 0,
        kBlendFuncSubtract = 1,
        kBlendFuncMin = 2,
        kBlendFuncMax = 3,
        kBlendFuncReverseSubtract = 4,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum BlendMultiplier
    {
        kBlendMultiplierZero = 0,
        kBlendMultiplierOne = 1,
        kBlendMultiplierSrcColor = 2,
        kBlendMultiplierOneMinusSrcColor = 3,
        kBlendMultiplierSrcAlpha = 4,
        kBlendMultiplierOneMinusSrcAlpha = 5,
        kBlendMultiplierDestAlpha = 6,
        kBlendMultiplierOneMinusDestAlpha = 7,
        kBlendMultiplierDestColor = 8,
        kBlendMultiplierOneMinusDestColor = 9,
        kBlendMultiplierSrcAlphaSaturate = 10,
        kBlendMultiplierConstantColor = 13,
        kBlendMultiplierOneMinusConstantColor = 14,
        kBlendMultiplierSrc1Color = 15,
        kBlendMultiplierInverseSrc1Color = 16,
        kBlendMultiplierSrc1Alpha = 17,
        kBlendMultiplierInverseSrc1Alpha = 18,
        kBlendMultiplierConstantAlpha = 19,
        kBlendMultiplierOneMinusConstantAlpha = 20,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum BufferChannel
    {
        kBufferChannelConstant0 = 0,
        kBufferChannelConstant1 = 1,
        kBufferChannelX = 4,
        kBufferChannelY = 5,
        kBufferChannelZ = 6,
        kBufferChannelW = 7,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum BufferChannelType
    {
        kBufferChannelTypeUNorm = 0,
        kBufferChannelTypeSNorm = 1,
        kBufferChannelTypeUScaled = 2,
        kBufferChannelTypeSScaled = 3,
        kBufferChannelTypeUInt = 4,
        kBufferChannelTypeSInt = 5,
        kBufferChannelTypeSNormNoZero = 6,
        kBufferChannelTypeFloat = 7,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum BufferFormat
    {
        kBufferFormatInvalid = 0,
        kBufferFormat8 = 1,
        kBufferFormat16 = 2,
        kBufferFormat8_8 = 3,
        kBufferFormat32 = 4,
        kBufferFormat16_16 = 5,
        kBufferFormat10_11_11 = 6,
        kBufferFormat11_11_10 = 7,
        kBufferFormat10_10_10_2 = 8,
        kBufferFormat2_10_10_10 = 9,
        kBufferFormat8_8_8_8 = 10,
        kBufferFormat32_32 = 11,
        kBufferFormat16_16_16_16 = 12,
        kBufferFormat32_32_32 = 13,
        kBufferFormat32_32_32_32 = 14,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum BufferSwizzleElementSize
    {
        kBufferSwizzleElementSize2 = 0,
        kBufferSwizzleElementSize4 = 1,
        kBufferSwizzleElementSize8 = 2,
        kBufferSwizzleElementSize16 = 3,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum BufferSwizzleStride
    {
        kBufferSwizzleStride8 = 0,
        kBufferSwizzleStride16 = 1,
        kBufferSwizzleStride32 = 2,
        kBufferSwizzleStride64 = 3,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum CacheAction
    {
        kCacheActionNone = 0,
        kCacheActionWriteBackAndInvalidateL1andL2 = 56,
        kCacheActionWriteBackL2Volatile = 59,
        kCacheActionWriteBackAndInvalidateL2Volatile = 59,
        kCacheActionInvalidateL2Volatile = 51,
        kCacheActionInvalidateL1 = 16,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum CachePolicy
    {
        kCachePolicyLru = 0,
        kCachePolicyStream = 1,
        kCachePolicyBypass = 2,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum CbMode
    {
        kCbModeDisable = 0,
        kCbModeNormal = 1,
        kCbModeEliminateFastClear = 2,
        kCbModeResolve = 3,
        kCbModeFmaskDecompress = 5,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum ClipControlClipSpace
    {
        kClipControlClipSpaceDX = 1,
        kClipControlClipSpaceOGL = 0,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum CompareFunc
    {
        kCompareFuncNever = 0,
        kCompareFuncLess = 1,
        kCompareFuncEqual = 2,
        kCompareFuncLessEqual = 3,
        kCompareFuncGreater = 4,
        kCompareFuncNotEqual = 5,
        kCompareFuncGreaterEqual = 6,
        kCompareFuncAlways = 7,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum DbCountControlPerfectZPassCounts
    {
        kDbCountControlPerfectZPassCountsDisable = 0,
        kDbCountControlPerfectZPassCountsEnable = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum DbCountControlZPassIncrement
    {
        kDbCountControlZPassIncrementEnable = 0,
        kDbCountControlZPassIncrementDisable = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum DepthControlZWrite
    {
        kDepthControlZWriteDisable = 0,
        kDepthControlZWriteEnable = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum DispatchOrderedAppendMode
    {
        kDispatchOrderedAppendModeDisabled = 0,
        kDispatchOrderedAppendModeIndexPerWavefront = 1,
        kDispatchOrderedAppendModeIndexPerThreadgroup = 3,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum DmaDataBlockingMode
    {
        kDmaDataBlockingDisable = 0,
        kDmaDataBlockingEnable = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum EmbeddedDataAlignment
    {
        kEmbeddedDataAlignment4 = 2,
        kEmbeddedDataAlignment8 = 3,
        kEmbeddedDataAlignment16 = 4,
        kEmbeddedDataAlignment64 = 6,
        kEmbeddedDataAlignment128 = 7,
        kEmbeddedDataAlignment256 = 8,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum EmbeddedPsShader
    {
        kEmbeddedPsShaderDummy = 0,
        kNumEmbeddedPsShaders = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum EmbeddedVsShader
    {
        kEmbeddedVsShaderFullScreen = 0,
        kNumEmbeddedVsShaders = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum EndOfPipeEventType
    {
        kEopFlushCbDbCaches = 4,
        kEopFlushAndInvalidateCbDbCaches = 20,
        kEopCbDbReadsDone = 40,
        kEopCsDone = 40,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum EndOfShaderEventType
    {
        kEosCsDone = 47,
        kEosPsDone = 48,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum EventStats
    {
        kEventStatsZPassDone = 0,
        kEventStatsSamplePipelinestat = 1,
        kEventStatsSampleStreamoutstats0 = 2,
        kEventStatsSampleStreamoutstats1 = 3,
        kEventStatsSampleStreamoutstats2 = 4,
        kEventStatsSampleStreamoutstats3 = 5,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum EventType
    {
        kEventTypeCacheFlush = 6,
        kEventTypeCsPartialFlush = 7,
        kEventTypeVsPartialFlush = 15,
        kEventTypePsPartialFlush = 16,
        kEventTypeFlushHsOutput = 17,
        kEventTypeFlushLsOutput = 18,
        kEventTypeCacheFlushAndInvEvent = 22,
        kEventTypePerfCounterStart = 23,
        kEventTypePerfCounterStop = 24,
        kEventTypePipelineStatsStart = 25,
        kEventTypePipelineStatsStop = 26,
        kEventTypePerfCounterSample = 27,
        kEventTypeFlushEsOutput = 28,
        kEventTypeFlushGsOutput = 29,
        kEventTypeSoVgtstreamoutFlush = 31,
        kEventTypeResetVertexCount = 33,
        kEventTypeBlockContextDone = 34,
        kEventTypeVgtFlush = 36,
        kEventTypeSqNonEvent = 38,
        kEventTypeScSendDbViewportZ = 39,
        kEventTypeDbCacheFlushAndInvalidate = 42,
        kEventTypeFlushAndInvalidateDbMeta = 44,
        kEventTypeFlushAndInvalidateCbMeta = 46,
        kEventTypeFlushAndInvalidateCbPixelData = 49,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum EventWriteDest
    {
        kEventWriteDestMemory = 0,
        kEventWriteDestTcL2 = 1,
        kEventWriteDestTcL2Volatile = 17,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum EventWriteSource
    {
        kEventWriteSource32BitsImmediate = 1,
        kEventWriteSource64BitsImmediate = 2,
        kEventWriteSourceGlobalClockCounter = 3,
        kEventWriteSourceGpuCoreClockCounter = 4,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum GsMaxOutputPrimitiveDwordSize
    {
        kGsMaxOutputPrimitiveDwordSize1024 = 0,
        kGsMaxOutputPrimitiveDwordSize512 = 1,
        kGsMaxOutputPrimitiveDwordSize256 = 2,
        kGsMaxOutputPrimitiveDwordSize128 = 3,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum GsMaxOutputVertexCount
    {
        kGsMaxOutputVertexCount1024 = 0,
        kGsMaxOutputVertexCount512 = 1,
        kGsMaxOutputVertexCount256 = 2,
        kGsMaxOutputVertexCount128 = 3,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum GsMode
    {
        kGsModeDisable = 0,
        kGsModeEnable = 1572867,
        kGsModeEnableOnChip = 6291459,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum IndexSize
    {
        kIndexSize16 = 0,
        kIndexSize32 = 1,
        kIndexSize16ForDispatchDraw = 16,
        kIndexSize32ForDispatchDraw = 17,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum NumFragments
    {
        kNumFragments1 = 0,
        kNumFragments2 = 1,
        kNumFragments4 = 2,
        kNumFragments8 = 3,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum NumSamples
    {
        kNumSamples1 = 0,
        kNumSamples2 = 1,
        kNumSamples4 = 2,
        kNumSamples8 = 3,
        kNumSamples16 = 4,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum OcclusionQueryOp
    {
        kOcclusionQueryOpClearAndBegin = 0,
        kOcclusionQueryOpEnd = 1,
        kOcclusionQueryOpBeginWithoutClear = 2,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum PredicationZPassAction
    {
        kPredicationZPassActionDrawIfNotVisible = 0,
        kPredicationZPassActionDrawIfVisible = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum PredicationZPassHint
    {
        kPredicationZPassHintWait = 0,
        kPredicationZPassHintDraw = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum PrimitiveSetupCullFaceMode
    {
        kPrimitiveSetupCullFaceNone = 0,
        kPrimitiveSetupCullFaceFront = 1,
        kPrimitiveSetupCullFaceBack = 2,
        kPrimitiveSetupCullFaceFrontAndBack = 3,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum PrimitiveSetupFrontFace
    {
        kPrimitiveSetupFrontFaceCw = 1,
        kPrimitiveSetupFrontFaceCcw = 0,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum PrimitiveSetupPolygonMode
    {
        kPrimitiveSetupPolygonModePoint = 0,
        kPrimitiveSetupPolygonModeLine = 1,
        kPrimitiveSetupPolygonModeFill = 2,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum PrimitiveSetupPolygonOffsetMode
    {
        kPrimitiveSetupPolygonOffsetEnable = 1,
        kPrimitiveSetupPolygonOffsetDisable = 0,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum PrimitiveType
    {
        kPrimitiveTypeNone = 0,
        kPrimitiveTypePointList = 1,
        kPrimitiveTypeLineList = 2,
        kPrimitiveTypeLineStrip = 3,
        kPrimitiveTypeTriList = 4,
        kPrimitiveTypeTriFan = 5,
        kPrimitiveTypeTriStrip = 6,
        kPrimitiveTypePatch = 9,
        kPrimitiveTypeLineListAdjacency = 10,
        kPrimitiveTypeLineStripAdjacency = 11,
        kPrimitiveTypeTriListAdjacency = 12,
        kPrimitiveTypeTriStripAdjacency = 13,
        kPrimitiveTypeRectList = 17,
        kPrimitiveTypeLineLoop = 18,
        kPrimitiveTypeQuadList = 19,
        kPrimitiveTypeQuadStrip = 20,
        kPrimitiveTypePolygon = 21,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum PsShaderRate
    {
        kPsShaderRatePerPixel = 0,
        kPsShaderRatePerSample = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum QuantumScale
    {
        kQuantumScale5us = 0,
        kQuantumScale1ms = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum RasterOp
    {
        kRasterOpBlackness = 0,
        kRasterOpNor = 5,
        kRasterOpAndInverted = 10,
        kRasterOpCopyInverted = 15,
        kRasterOpAndReverse = 68,
        kRasterOpInvert = 85,
        kRasterOpXor = 90,
        kRasterOpNand = 95,
        kRasterOpAnd = 136,
        kRasterOpEquiv = 153,
        kRasterOpNoop = 170,
        kRasterOpOrInverted = 175,
        kRasterOpCopy = 204,
        kRasterOpOrReverse = 221,
        kRasterOpOr = 238,
        kRasterOpSet = 255,
        kRasterOpSrcCopy = 204,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum ReleaseMemEventType
    {
        kReleaseMemEventCsDone = 47,
        kReleaseMemEventFlushCbDbCaches = 4,
        kReleaseMemEventFlushAndInvalidateCbDbCaches = 20,
        kReleaseMemEventCbDbReadsDone = 40,
        kReleaseMemEventFlushAndInvalidateDbCache = 43,
        kReleaseMemEventFlushAndInvalidateCbCache = 45,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum RenderTargetChannelOrder
    {
        kRenderTargetChannelOrderStandard = 0,
        kRenderTargetChannelOrderAlt = 1,
        kRenderTargetChannelOrderReversed = 2,
        kRenderTargetChannelOrderAltReversed = 3,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum RenderTargetChannelType
    {
        kRenderTargetChannelTypeUNorm = 0,
        kRenderTargetChannelTypeSNorm = 1,
        kRenderTargetChannelTypeUInt = 4,
        kRenderTargetChannelTypeSInt = 5,
        kRenderTargetChannelTypeSrgb = 6,
        kRenderTargetChannelTypeFloat = 7,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum RenderTargetFormat
    {
        kRenderTargetFormatInvalid = 0,
        kRenderTargetFormat8 = 1,
        kRenderTargetFormat16 = 2,
        kRenderTargetFormat8_8 = 3,
        kRenderTargetFormat32 = 4,
        kRenderTargetFormat16_16 = 5,
        kRenderTargetFormat10_11_11 = 6,
        kRenderTargetFormat11_11_10 = 7,
        kRenderTargetFormat10_10_10_2 = 8,
        kRenderTargetFormat2_10_10_10 = 9,
        kRenderTargetFormat8_8_8_8 = 10,
        kRenderTargetFormat32_32 = 11,
        kRenderTargetFormat16_16_16_16 = 12,
        kRenderTargetFormat32_32_32_32 = 14,
        kRenderTargetFormat5_6_5 = 16,
        kRenderTargetFormat1_5_5_5 = 17,
        kRenderTargetFormat5_5_5_1 = 18,
        kRenderTargetFormat4_4_4_4 = 19,
        kRenderTargetFormat8_24 = 20,
        kRenderTargetFormat24_8 = 21,
        kRenderTargetFormatX24_8_32 = 22,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum SamplerModulationFactor
    {
        kSamplerModulationFactor0_0000 = 0,
        kSamplerModulationFactor0_1250 = 1,
        kSamplerModulationFactor0_3125 = 2,
        kSamplerModulationFactor0_4375 = 3,
        kSamplerModulationFactor0_5625 = 4,
        kSamplerModulationFactor0_6875 = 5,
        kSamplerModulationFactor0_8750 = 6,
        kSamplerModulationFactor1_0000 = 7,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum ScanModeControlAa
    {
        kScanModeControlAaDisable = 0,
        kScanModeControlAaEnable = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum ScanModeControlViewportScissor
    {
        kScanModeControlViewportScissorDisable = 0,
        kScanModeControlViewportScissorEnable = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum SemaphoreSignalBehavior
    {
        kSemaphoreSignalBehaviorIncrement = 0,
        kSemaphoreSignalBehaviorSet = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum SemaphoreUpdateConfirmMode
    {
        kSemaphoreUpdateConfirmDisabled = 0,
        kSemaphoreUpdateConfirmEnabled = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum SemaphoreWaitBehavior
    {
        kSemaphoreWaitBehaviorDecrement = 0,
        kSemaphoreWaitBehaviorNone = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum ShaderEngine
    {
        kShaderEngine0 = 0,
        kShaderEngine1 = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum ShaderGlobalResourceType
    {
        kShaderGlobalResourceScratchRingForGraphic = 0,
        kShaderGlobalResourceScratchRingForCompute = 1,
        kShaderGlobalResourceEsGsWriteDescriptor = 2,
        kShaderGlobalResourceEsGsReadDescriptor = 3,
        kShaderGlobalResourceGsVsWriteDescriptor0 = 4,
        kShaderGlobalResourceGsVsWriteDescriptor1 = 5,
        kShaderGlobalResourceGsVsWriteDescriptor2 = 6,
        kShaderGlobalResourceGsVsWriteDescriptor3 = 7,
        kShaderGlobalResourceGsVsReadDescriptor = 8,
        kShaderGlobalResourceTessFactorBuffer = 9,
        kShaderGlobalResourceOffChipLds0 = 10,
        kShaderGlobalResourceOffChipLds1 = 11,
        kShaderGlobalResourceCount = 12,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum ShaderStage
    {
        kShaderStageCs = 0,
        kShaderStagePs = 1,
        kShaderStageVs = 2,
        kShaderStageGs = 3,
        kShaderStageEs = 4,
        kShaderStageHs = 5,
        kShaderStageLs = 6,
        kShaderStageCount = 7,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum ShaderType
    {
        kShaderTypeGraphics = 0,
        kShaderTypeCompute = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum StallCommandBufferParserMode
    {
        kStallCommandBufferParserEnable = 0,
        kStallCommandBufferParserDisable = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum StencilOp
    {
        kStencilOpKeep = 0,
        kStencilOpZero = 1,
        kStencilOpOnes = 2,
        kStencilOpReplaceTest = 3,
        kStencilOpReplaceOp = 4,
        kStencilOpAddClamp = 5,
        kStencilOpSubClamp = 6,
        kStencilOpInvert = 7,
        kStencilOpAddWrap = 8,
        kStencilOpSubWrap = 9,
        kStencilOpAnd = 10,
        kStencilOpOr = 11,
        kStencilOpXor = 12,
        kStencilOpNand = 13,
        kStencilOpNor = 14,
        kStencilOpXnor = 15,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum StreamoutBufferId
    {
        kStreamoutBuffer0 = 0,
        kStreamoutBuffer1 = 1,
        kStreamoutBuffer2 = 2,
        kStreamoutBuffer3 = 3,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum StreamoutBufferUpdateSaveFilledSize
    {
        kStreamoutBufferUpdateDontSaveFilledSize = 0,
        kStreamoutBufferUpdateSaveFilledSize = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum StreamoutBufferUpdateWrite
    {
        kStreamoutBufferUpdateWriteImmediate = 0,
        kStreamoutBufferUpdateWriteBufferFilledSize = 1,
        kStreamoutBufferUpdateWriteIndirect = 2,
        kStreamoutBufferUpdateWriteNone = 3,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum SurfaceFormat
    {
        kSurfaceFormatInvalid = 0,
        kSurfaceFormat8 = 1,
        kSurfaceFormat16 = 2,
        kSurfaceFormat8_8 = 3,
        kSurfaceFormat32 = 4,
        kSurfaceFormat16_16 = 5,
        kSurfaceFormat10_11_11 = 6,
        kSurfaceFormat11_11_10 = 7,
        kSurfaceFormat10_10_10_2 = 8,
        kSurfaceFormat2_10_10_10 = 9,
        kSurfaceFormat8_8_8_8 = 10,
        kSurfaceFormat32_32 = 11,
        kSurfaceFormat16_16_16_16 = 12,
        kSurfaceFormat32_32_32 = 13,
        kSurfaceFormat32_32_32_32 = 14,
        kSurfaceFormat5_6_5 = 16,
        kSurfaceFormat1_5_5_5 = 17,
        kSurfaceFormat5_5_5_1 = 18,
        kSurfaceFormat4_4_4_4 = 19,
        kSurfaceFormat8_24 = 20,
        kSurfaceFormat24_8 = 21,
        kSurfaceFormatX24_8_32 = 22,
        kSurfaceFormatGB_GR = 32,
        kSurfaceFormatBG_RG = 33,
        kSurfaceFormat5_9_9_9 = 34,
        kSurfaceFormatBc1 = 35,
        kSurfaceFormatBc2 = 36,
        kSurfaceFormatBc3 = 37,
        kSurfaceFormatBc4 = 38,
        kSurfaceFormatBc5 = 39,
        kSurfaceFormatBc6 = 40,
        kSurfaceFormatBc7 = 41,
        kSurfaceFormatFmask8_S2_F1 = 44,
        kSurfaceFormatFmask8_S4_F1 = 45,
        kSurfaceFormatFmask8_S8_F1 = 46,
        kSurfaceFormatFmask8_S2_F2 = 47,
        kSurfaceFormatFmask8_S4_F2 = 48,
        kSurfaceFormatFmask8_S4_F4 = 49,
        kSurfaceFormatFmask16_S16_F1 = 50,
        kSurfaceFormatFmask16_S8_F2 = 51,
        kSurfaceFormatFmask32_S16_F2 = 52,
        kSurfaceFormatFmask32_S8_F4 = 53,
        kSurfaceFormatFmask32_S8_F8 = 54,
        kSurfaceFormatFmask64_S16_F4 = 55,
        kSurfaceFormatFmask64_S16_F8 = 56,
        kSurfaceFormat4_4 = 57,
        kSurfaceFormat6_5_5 = 58,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum TextureChannel
    {
        kTextureChannelConstant0 = 0,
        kTextureChannelConstant1 = 1,
        kTextureChannelX = 4,
        kTextureChannelY = 5,
        kTextureChannelZ = 6,
        kTextureChannelW = 7,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum TextureChannelType
    {
        kTextureChannelTypeUNorm = 0,
        kTextureChannelTypeSNorm = 1,
        kTextureChannelTypeUScaled = 2,
        kTextureChannelTypeSScaled = 3,
        kTextureChannelTypeUInt = 4,
        kTextureChannelTypeSInt = 5,
        kTextureChannelTypeSNormNoZero = 6,
        kTextureChannelTypeFloat = 7,
        kTextureChannelTypeSrgb = 9,
        kTextureChannelTypeUBNorm = 10,
        kTextureChannelTypeUBNormNoZero = 11,
        kTextureChannelTypeUBInt = 12,
        kTextureChannelTypeUBScaled = 13,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum TextureType
    {
        kTextureType1d = 8,
        kTextureType2d = 9,
        kTextureType3d = 10,
        kTextureTypeCubemap = 11,
        kTextureType1dArray = 12,
        kTextureType2dArray = 13,
        kTextureType2dMsaa = 14,
        kTextureType2dArrayMsaa = 15,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum TileMode
    {
        kTileModeDepth_2dThin_64 = 0,
        kTileModeDepth_2dThin_128 = 1,
        kTileModeDepth_2dThin_256 = 2,
        kTileModeDepth_2dThin_512 = 3,
        kTileModeDepth_2dThin_1K = 4,
        kTileModeDepth_1dThin = 5,
        kTileModeDepth_2dThinPrt_256 = 6,
        kTileModeDepth_2dThinPrt_1K = 7,
        kTileModeDisplay_LinearAligned = 8,
        kTileModeDisplay_1dThin = 9,
        kTileModeDisplay_2dThin = 10,
        kTileModeDisplay_ThinPrt = 11,
        kTileModeDisplay_2dThinPrt = 12,
        kTileModeThin_1dThin = 13,
        kTileModeThin_2dThin = 14,
        kTileModeThin_3dThin = 15,
        kTileModeThin_ThinPrt = 16,
        kTileModeThin_2dThinPrt = 17,
        kTileModeThin_3dThinPrt = 18,
        kTileModeThick_1dThick = 19,
        kTileModeThick_2dThick = 20,
        kTileModeThick_3dThick = 21,
        kTileModeThick_ThickPrt = 22,
        kTileModeThick_2dThickPrt = 23,
        kTileModeThick_3dThickPrt = 24,
        kTileModeThick_2dXThick = 25,
        kTileModeThick_3dXThick = 26,
        kTileModeDisplay_LinearGeneral = 31,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum VertexQuantizationCenterMode
    {
        kVertexQuantizationCenterAtZero = 0,
        kVertexQuantizationCenterAtHalf = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum VertexQuantizationMode
    {
        kVertexQuantizationMode16_8 = 5,
        kVertexQuantizationMode14_10 = 6,
        kVertexQuantizationMode12_12 = 7,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum VertexQuantizationRoundMode
    {
        kVertexQuantizationRoundModeTruncate = 0,
        kVertexQuantizationRoundModeRound = 1,
        kVertexQuantizationRoundModeRoundToEven = 2,
        kVertexQuantizationRoundModeRoundToOdd = 3,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum VgtPartialVsWaveMode
    {
        kVgtPartialVsWaveDisable = 0,
        kVgtPartialVsWaveEnable = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum VgtSwitchOnEopMode
    {
        kVgtSwitchOnEopDisable = 0,
        kVgtSwitchOnEopEnable = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum WaitCompareFunc
    {
        kWaitCompareFuncAlways = 0,
        kWaitCompareFuncLess = 1,
        kWaitCompareFuncLessEqual = 2,
        kWaitCompareFuncEqual = 3,
        kWaitCompareFuncNotEqual = 4,
        kWaitCompareFuncGreaterEqual = 5,
        kWaitCompareFuncGreater = 6,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum WindowOffsetMode
    {
        kWindowOffsetDisable = 0,
        kWindowOffsetEnable = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum WriteDataConfirmMode
    {
        kWriteDataConfirmDisable = 0,
        kWriteDataConfirmEnable = 1,
    };
}  // namespace Gnm
}  // namespace sce

namespace sce {
namespace Gnm {
    enum ZFormat
    {
        kZFormatInvalid = 0,
        kZFormat16 = 1,
        kZFormat32Float = 3,
    };
}  // namespace Gnm
}  // namespace sce
