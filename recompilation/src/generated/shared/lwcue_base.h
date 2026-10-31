#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "constants.h"

// Forward declarations
namespace sce { namespace Gnm { class Buffer; } }

// Declarations
namespace sce { namespace Gnmx { class BaseConstantUpdateEngine; } }
namespace sce { namespace Gnmx { struct InputResourceOffsets; } }
namespace sce { namespace Gnmx { namespace LightweightConstantUpdateEngine { struct ShaderResourceBindingValidation; } } }
namespace sce { namespace Gnmx { class ResourceBufferCallback; } }

// Type aliases from DWARF
using __int32_t = int;
using __uint16_t = unsigned short;
using __uint32_t = unsigned int;
using __uint8_t = unsigned char;
using int32_t = __int32_t;
using uint32_t = __uint32_t;
namespace sce { namespace Gnmx { using AllocResourceBufferCallback = uint32_t* (*)(sce::Gnmx::BaseConstantUpdateEngine*, uint32_t, uint32_t*, void*); } }
using uint16_t = __uint16_t;
using uint8_t = __uint8_t;

namespace sce {
    namespace Gnmx {
        struct InputResourceOffsets
        {
        public:
            void initSupportedResourceCounts();
        public:
            uint16_t requiredBufferSizeInDwords;  // offset: 0x0
            uint8_t shaderStage;  // offset: 0x2
            bool isSrtShader;  // offset: 0x3
            uint8_t fetchShaderPtrSgpr;  // offset: 0x4
            uint8_t vertexBufferPtrSgpr;  // offset: 0x5
            uint8_t streamOutPtrSgpr;  // offset: 0x6
            uint8_t userExtendedData1PtrSgpr;  // offset: 0x7
            uint8_t constBufferPtrSgpr;  // offset: 0x8
            uint8_t resourcePtrSgpr;  // offset: 0x9
            uint8_t rwResourcePtrSgpr;  // offset: 0xa
            uint8_t samplerPtrSgpr;  // offset: 0xb
            uint8_t globalInternalPtrSgpr;  // offset: 0xc
            uint8_t appendConsumeCounterSgpr;  // offset: 0xd
            uint8_t gdsMemoryRangeSgpr;  // offset: 0xe
            uint8_t ldsEsGsSizeSgpr;  // offset: 0xf
            uint8_t userSrtDataSgpr;  // offset: 0x10
            uint8_t userSrtDataCount;  // offset: 0x11
            uint8_t gdsKickRingBufferOffsetSgpr;  // offset: 0x12
            uint8_t vertexRingBufferOffsetSgpr;  // offset: 0x13
            uint8_t dispatchDrawPtrSgpr;  // offset: 0x14
            uint8_t dispatchDrawInstancesSgpr;  // offset: 0x15
            uint16_t constBufferArrayDwOffset;  // offset: 0x16
            uint16_t vertexBufferArrayDwOffset;  // offset: 0x18
            uint16_t resourceArrayDwOffset;  // offset: 0x1a
            uint16_t rwResourceArrayDwOffset;  // offset: 0x1c
            uint16_t samplerArrayDwOffset;  // offset: 0x1e
            uint16_t streamOutArrayDwOffset;  // offset: 0x20
            uint16_t resourceDwOffset[16];  // offset: 0x22
            uint16_t rwResourceDwOffset[16];  // offset: 0x42
            uint16_t samplerDwOffset[16];  // offset: 0x62
            uint16_t constBufferDwOffset[20];  // offset: 0x82
            uint16_t vertexBufferDwOffset[16];  // offset: 0xaa
            uint16_t streamOutDwOffset[4];  // offset: 0xca
            uint8_t resourceSlotCount;  // offset: 0xd2
            uint8_t rwResourceSlotCount;  // offset: 0xd3
            uint8_t samplerSlotCount;  // offset: 0xd4
            uint8_t constBufferSlotCount;  // offset: 0xd5
            uint8_t vertexBufferSlotCount;  // offset: 0xd6
        };
    }  // namespace Gnmx
}  // namespace sce

namespace sce {
    namespace Gnmx {
        namespace LightweightConstantUpdateEngine {
            struct ShaderResourceBindingValidation
            {
            public:
                bool resourceOffsetIsBound[16];  // offset: 0x0
                bool rwResourceOffsetIsBound[16];  // offset: 0x10
                bool samplerOffsetIsBound[16];  // offset: 0x20
                bool vertexBufferOffsetIsBound[16];  // offset: 0x30
                bool constBufferOffsetIsBound[20];  // offset: 0x40
                bool appendConsumeCounterIsBound;  // offset: 0x54
                bool gdsMemoryRangeIsBound;  // offset: 0x55
            };
        }  // namespace LightweightConstantUpdateEngine
    }  // namespace Gnmx
}  // namespace sce

namespace sce {
    namespace Gnmx {
        class ResourceBufferCallback
        {
        public:
            sce::Gnmx::AllocResourceBufferCallback m_func;  // offset: 0x0
            void* m_userData;  // offset: 0x8
        };
    }  // namespace Gnmx
}  // namespace sce

namespace sce {
    namespace Gnmx {
        class BaseConstantUpdateEngine
        {
        public:
            void setShaderCodePrefetchEnable(bool);
            void setGlobalResourceTableAddr(void*);
            void setResourceBufferFullCallback(sce::Gnmx::AllocResourceBufferCallback, void*);
            uint32_t getRemainingResourceBufferSpaceInDwords();
            uint32_t getUsedResourceBufferSpaceInDwords();
            void setGlobalDescriptor(sce::Gnm::ShaderGlobalResourceType, const sce::Gnm::Buffer*);
            bool resourceBufferHasSpace(uint32_t);
        public:
            int32_t m_bufferCount;  // offset: 0x0
            int32_t m_bufferIndex;  // offset: 0x4
            uint32_t* m_bufferCurrent;  // offset: 0x8
            uint32_t* m_bufferCurrentBegin;  // offset: 0x10
            uint32_t* m_bufferCurrentEnd;  // offset: 0x18
            uint32_t* m_bufferBegin[4];  // offset: 0x20
            uint32_t* m_bufferEnd[4];  // offset: 0x40
            sce::Gnmx::ResourceBufferCallback m_resourceBufferCallback;  // offset: 0x60
            bool m_prefetchShaderCode;  // offset: 0x70
            sce::Gnm::Buffer* m_globalInternalResourceTableAddr;  // offset: 0x78
        };
    }  // namespace Gnmx
}  // namespace sce
