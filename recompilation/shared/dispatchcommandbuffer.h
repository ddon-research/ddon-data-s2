#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "commandbuffer.h"
#include "constants.h"

// Forward declarations
namespace sce { namespace Gnm { class Buffer; } }
namespace sce { namespace Gnm { class CsStageRegisters; } }
namespace sce { namespace Gnm { class DispatchIndirectArgs; } }
namespace sce { namespace Gnm { class Sampler; } }
namespace sce { namespace Gnm { class Texture; } }

// Declarations
namespace sce { namespace Gnm { class DispatchCommandBuffer; } }

// Type aliases from DWARF
using __uint16_t = unsigned short;
using __uint32_t = unsigned int;
using __uint64_t = long unsigned int;
using uint16_t = __uint16_t;
using uint32_t = __uint32_t;
using uint64_t = __uint64_t;

namespace sce {
    namespace Gnm {
        class DispatchCommandBuffer : public sce::Gnm::CommandBuffer
        {
        public:
            DispatchCommandBuffer();
            void initializeDefaultHardwareState();
            void setComputeShaderControl(uint32_t, uint32_t, uint32_t);
            void setComputeResourceManagement(sce::Gnm::ShaderEngine, uint16_t);
            void setCsShader(const sce::Gnm::CsStageRegisters*);
            void setBulkyCsShader(const sce::Gnm::CsStageRegisters*);
            void readDataFromGds(void*, uint32_t, uint32_t);
            void readDataFromGds(sce::Gnm::EndOfShaderEventType, void*, uint32_t, uint32_t);
            void* allocateFromCommandBuffer(uint32_t, sce::Gnm::EmbeddedDataAlignment);
            void setVsharpInUserData(uint32_t, const sce::Gnm::Buffer*);
            void setTsharpInUserData(uint32_t, const sce::Gnm::Texture*);
            void setSsharpInUserData(uint32_t, const sce::Gnm::Sampler*);
            void setPointerInUserData(uint32_t, void*);
            void setUserData(uint32_t, uint32_t);
            void setUserDataRegion(uint32_t, const uint32_t*, uint32_t);
            void setScratchSize(uint32_t, uint32_t);
            void dispatch(uint32_t, uint32_t, uint32_t);
            void dispatchIndirect(sce::Gnm::DispatchIndirectArgs*);
            void enableOrderedAppendAllocationCounter(uint32_t, uint32_t, uint32_t, uint32_t);
            void disableOrderedAppendAllocationCounter(uint32_t);
            void writeDataInline(void*, const void*, uint32_t, sce::Gnm::WriteDataConfirmMode);
            void writeDataInlineThroughL2(void*, const void*, uint32_t, sce::Gnm::CachePolicy, sce::Gnm::WriteDataConfirmMode);
            void triggerEvent(sce::Gnm::EventType);
            void triggerReleaseMemEventInterrupt(sce::Gnm::ReleaseMemEventType, sce::Gnm::CacheAction);
            void writeReleaseMemEventWithInterrupt(sce::Gnm::ReleaseMemEventType, sce::Gnm::EventWriteDest, void*, sce::Gnm::EventWriteSource, uint64_t, sce::Gnm::CacheAction, sce::Gnm::CachePolicy);
            void writeReleaseMemEvent(sce::Gnm::ReleaseMemEventType, sce::Gnm::EventWriteDest, void*, sce::Gnm::EventWriteSource, uint64_t, sce::Gnm::CacheAction, sce::Gnm::CachePolicy);
            void waitOnAddress(void*, uint32_t, sce::Gnm::WaitCompareFunc, uint32_t);
            void waitForGraphicsWrites(uint32_t, uint32_t, uint32_t, sce::Gnm::CacheAction, uint32_t);
            void flushShaderCachesAndWait(sce::Gnm::CacheAction, uint32_t);
            void insertNop(uint32_t);
            void setMarker(const char*);
            void setMarker(const char*, uint32_t);
            void pushMarker(const char*);
            void pushMarker(const char*, uint32_t);
            void popMarker();
            void prefetchIntoL2(void*, uint32_t);
            void signalSemaphore(uint64_t*, sce::Gnm::SemaphoreSignalBehavior, sce::Gnm::SemaphoreUpdateConfirmMode);
            void waitSemaphore(uint64_t*, sce::Gnm::SemaphoreWaitBehavior);
            void setQueuePriority(uint32_t, uint32_t);
            void enableQueueQuantumTimer(uint32_t, sce::Gnm::QuantumScale, uint32_t);
            void disableQueueQuantumTimer(uint32_t);
            uint64_t pause(uint32_t);
            void resume(uint64_t);
            void fillAndResume(uint64_t, void*, uint32_t);
            void chainCommandBufferAndResume(uint64_t, void*, uint64_t);
            void writeResumeEvent(sce::Gnm::ReleaseMemEventType, uint64_t, sce::Gnm::CacheAction, sce::Gnm::CachePolicy);
            void writeResumeEventWithInterrupt(sce::Gnm::ReleaseMemEventType, uint64_t, sce::Gnm::CacheAction, sce::Gnm::CachePolicy);
            void waitForResume(uint64_t);
            void writeResume(uint64_t);
            void callCommandBuffer(void*, uint64_t);
            void chainCommandBuffer(void*, uint64_t);
        };
    }  // namespace Gnm
}  // namespace sce
