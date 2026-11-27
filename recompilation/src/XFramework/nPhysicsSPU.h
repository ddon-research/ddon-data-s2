#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "nPhysicsMathVector3.h"
#include "nPhysicsStruct.h"

// Forward declarations
namespace nPhysics { struct AABB; }
namespace nPhysics { struct COLLISION_INFORMATION; }
namespace nPhysics { struct CONSTRAINT; }
namespace nPhysics { struct CONSTRAINT_HEADER; }
namespace nPhysics { struct CONTACT_INFO; }
namespace nPhysics { class CONTACT_PAIR; }
namespace nPhysics { struct CONTACT_UPDATE_PARAMETER; }
namespace nPhysics { struct CURRENT_RIGID_BODY_DATA; }
namespace nPhysics { struct DELTA_VELOCITY; }
namespace nPhysics { class ISLAND; }
namespace nPhysics { namespace IoSPU { struct PROFILER_DATA; } }
namespace nPhysics { struct MERGE_SORT_INFO; }
namespace nPhysics { namespace Math { class Vector3; } }
namespace nPhysics { struct ORDERED_ID; }
namespace nPhysics { class POWER; }
namespace nPhysics { class QUANTIZATION_AABB; }
namespace nPhysics { struct RIGID_BODY_DATA; }
namespace nPhysics { struct RIGID_BODY_ID; }
namespace nPhysics { struct RIGID_BODY_INFORMATION; }
namespace nPhysics { struct RIGID_BODY_LINK; }
namespace nPhysics { struct RIGID_BODY_STATUS; }
namespace nPhysics { class SHAPES; }
namespace nPhysics { struct SOLVER_CONFIG; }
namespace nPhysics { class SORTED_PAIR; }
namespace nPhysics { class SORT_DATA; }
namespace nPhysics { struct UPDATE_RIGID_BODY_CONFIG; }

// Declarations
namespace nPhysics { namespace IoSPU { struct CALCULATE_ISLAND; } }
namespace nPhysics { namespace IoSPU { struct CALCULATE_VARIANCE; } }
namespace nPhysics { namespace IoSPU { struct DETECT_COLLISION_PAIR; } }
namespace nPhysics { namespace IoSPU { struct DETECT_COLLISION_WITH_SCROLL; } }
namespace nPhysics { namespace IoSPU { struct DETECT_PAIR; } }
namespace nPhysics { namespace IoSPU { struct DETECT_PHANTOM_PAIR; } }
namespace nPhysics { namespace IoSPU { struct MERGE_PAIR; } }
namespace nPhysics { namespace IoSPU { struct QUANTIZE_AABB; } }
namespace nPhysics { namespace IoSPU { struct SETUP_RIGID_BODY; } }
namespace nPhysics { namespace IoSPU { struct SOLVE_CONSTRAINT; } }
namespace nPhysics { namespace IoSPU { struct SORT; } }
namespace nPhysics { namespace IoSPU { struct SPLIT_CONSTRAINT; } }
namespace nPhysics { namespace IoSPU { struct SYNC_RIGID_BODY; } }
namespace nPhysics { namespace IoSPU { struct UPDATE_RIGID_BODY; } }

// Type aliases from DWARF
using f32 = float;
using s32 = int;
using s8 = signed char;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nPhysics {
    namespace IoSPU {
        struct alignas(16) CALCULATE_ISLAND
        {
        public:
            nPhysics::SORTED_PAIR* AddressPair;  // offset: 0x0
            u32 NumPair;  // offset: 0x8
            nPhysics::CONSTRAINT_HEADER* AddressConstraintHeader;  // offset: 0x10
            u32 NumConstraint;  // offset: 0x18
            u32 MaxRigidBody;  // offset: 0x1c
            u32 MaxMaterial;  // offset: 0x20
            u32 NumRigidBody;  // offset: 0x24
            u32* AddressRigidBodyID;  // offset: 0x28
            u32* AddressIslandIndexOfRigidBody;  // offset: 0x30
            nPhysics::ISLAND* AddressIsland;  // offset: 0x38
            u32 NumIsland;  // offset: 0x40
            u32 OutputNumIsland;  // offset: 0x44
        };
    }  // namespace IoSPU
}  // namespace nPhysics

namespace nPhysics {
    namespace IoSPU {
        struct CALCULATE_VARIANCE
        {
        public:
            const nPhysics::AABB* getAddressRigidBodyAABB() const;
            u32 getNumRigidBody() const;
            void setAddressRigidBodyAABB(nPhysics::AABB* address);
            void setNumRigidBody(const u32 num);
        public:
            nPhysics::Math::Vector3 PowerSum;  // offset: 0x0
            nPhysics::Math::Vector3 Sum;  // offset: 0x10
        };
    }  // namespace IoSPU
}  // namespace nPhysics

namespace nPhysics {
    namespace IoSPU {
        struct DETECT_COLLISION_PAIR
        {
        public:
            nPhysics::CONTACT_PAIR* AddressContactPair;  // offset: 0x0
            u32 NumPair;  // offset: 0x8
            nPhysics::SORTED_PAIR* AddressPair;  // offset: 0x10
            const nPhysics::SORTED_PAIR* AddressNewPair;  // offset: 0x18
            const nPhysics::SORTED_PAIR* AddressStockPair;  // offset: 0x20
            u32 NumStockPair;  // offset: 0x28
            const nPhysics::CONTACT_INFO* AddressRigidBodyScrollContactInfo;  // offset: 0x30
            const nPhysics::SHAPES* AddressRigidBodyShapes;  // offset: 0x38
            const nPhysics::RIGID_BODY_DATA* AddressPreservedRigidBodyData;  // offset: 0x40
            u32 MaxRigidBody;  // offset: 0x48
            u32 MaxMaterial;  // offset: 0x4c
            u32 OutputDisablePairCount;  // offset: 0x50
            nPhysics::CONTACT_UPDATE_PARAMETER ContactUpdateParameter;  // offset: 0x60
        };
    }  // namespace IoSPU
}  // namespace nPhysics

namespace nPhysics {
    namespace IoSPU {
        struct alignas(16) DETECT_COLLISION_WITH_SCROLL
        {
        public:
            nPhysics::AABB* AddressRigidBodyAABB;  // offset: 0x0
            nPhysics::SORTED_PAIR* OutputNewPair;  // offset: 0x8
            u32 OutputNumNewPair;  // offset: 0x10
            u32 StartBatch;  // offset: 0x14
            u32 NumBatch;  // offset: 0x18
            const nPhysics::CURRENT_RIGID_BODY_DATA* AddressRigidBodyData;  // offset: 0x20
            u32 MaxRigidBody;  // offset: 0x28
            nPhysics::SHAPES* AddressRigidBodyShapes;  // offset: 0x30
            u32 reserve1[9];  // offset: 0x38
            nPhysics::COLLISION_INFORMATION* AddressCollisionInformation;  // offset: 0x60
            nPhysics::CONTACT_INFO* AddressRigidBodyScrollContactInfo;  // offset: 0x68
            u32* OutputGroundLayerRigidBodyID;  // offset: 0x70
        };
    }  // namespace IoSPU
}  // namespace nPhysics

namespace nPhysics {
    namespace IoSPU {
        struct alignas(16) DETECT_PAIR
        {
        public:
            nPhysics::QUANTIZATION_AABB* AddressRestAABB;  // offset: 0x0
            s32 NumRestAABB;  // offset: 0x8
            nPhysics::QUANTIZATION_AABB* AddressProcessAABB;  // offset: 0x10
            u32 NumProcessAABB;  // offset: 0x18
            nPhysics::SORTED_PAIR* AddressNewPair;  // offset: 0x20
            u32 NumNewPair;  // offset: 0x28
            u32 MaxVariance;  // offset: 0x2c
            nPhysics::COLLISION_INFORMATION* AddressCollisionInformation;  // offset: 0x30
        };
    }  // namespace IoSPU
}  // namespace nPhysics

namespace nPhysics {
    namespace IoSPU {
        struct DETECT_PHANTOM_PAIR
        {
        public:
            nPhysics::QUANTIZATION_AABB* AddressRigidBodyAABB;  // offset: 0x0
            u32 NumRigidBodyAABB;  // offset: 0x8
            nPhysics::QUANTIZATION_AABB* AddressPhantomAABB;  // offset: 0x10
            u32 NumPhantomAABB;  // offset: 0x18
            nPhysics::RIGID_BODY_ID* AddressNewPair;  // offset: 0x20
            u32 NumNewPair;  // offset: 0x28
            nPhysics::COLLISION_INFORMATION* AddressRigidBodyCollisionInformation;  // offset: 0x30
            nPhysics::COLLISION_INFORMATION* AddressPhantomCollisionInformation;  // offset: 0x38
            u32 reserve[3];  // offset: 0x40
            u32 MaxVariance;  // offset: 0x4c
        };
    }  // namespace IoSPU
}  // namespace nPhysics

namespace nPhysics {
    namespace IoSPU {
        struct alignas(16) MERGE_PAIR
        {
        public:
            nPhysics::SORTED_PAIR* AddressOldPair;  // offset: 0x0
            u32 NumOldPair;  // offset: 0x8
            nPhysics::SORTED_PAIR* AddressNewPair;  // offset: 0x10
            u32 NumNewPair;  // offset: 0x18
            nPhysics::SORTED_PAIR* AddressDisableOldPair;  // offset: 0x20
            u32 reserve[3];  // offset: 0x28
            u32 OutputNumEnablePair;  // offset: 0x34
            u32 OutputNumDisablePair;  // offset: 0x38
            u32 OutputNumNewPair;  // offset: 0x3c
            u32 OutputStartOldPairIndex;  // offset: 0x40
        };
    }  // namespace IoSPU
}  // namespace nPhysics

namespace nPhysics {
    namespace IoSPU {
        struct QUANTIZE_AABB
        {
        public:
            nPhysics::AABB* AddressRigidBodyAABB;  // offset: 0x0
            nPhysics::QUANTIZATION_AABB* OutputQuantizationRigidBodyAABB;  // offset: 0x8
            nPhysics::AABB* AddressPhantomAABB;  // offset: 0x10
            nPhysics::QUANTIZATION_AABB* OutputQuantizationPhantomAABB;  // offset: 0x18
            u32 NumRigidBody;  // offset: 0x20
            u32 MaxVariance;  // offset: 0x24
            u32 NumRigidBodyOutsideArea;  // offset: 0x28
            u32 padding1;  // offset: 0x2c
            u32* OutputRigidBodyIDOutsideArea;  // offset: 0x30
            u32 padding2;  // offset: 0x38
            u32 padding3;  // offset: 0x3c
            f32 QuantizationOffset[3];  // offset: 0x40
            u32 NumPhantom;  // offset: 0x4c
            nPhysics::Math::Vector3 QuantizationScale;  // offset: 0x50
        };
    }  // namespace IoSPU
}  // namespace nPhysics

namespace nPhysics {
    namespace IoSPU {
        struct SETUP_RIGID_BODY
        {
        public:
            const u32* AddressRigidBodyID;  // offset: 0x0
            u32 StartBatch;  // offset: 0x8
            u32 NumBatch;  // offset: 0xc
            const nPhysics::SHAPES* AddressRigidBodyShapes;  // offset: 0x10
            nPhysics::POWER* AddressRigidBodyPower;  // offset: 0x18
            nPhysics::CURRENT_RIGID_BODY_DATA* AddressCurrentRigidBodyData;  // offset: 0x20
            nPhysics::RIGID_BODY_STATUS* AddressRigidBodyStatus;  // offset: 0x28
            nPhysics::RIGID_BODY_INFORMATION* AddressRigidBodyInformation;  // offset: 0x30
            nPhysics::SHAPES* OutputTransformedRigidBodyShapes;  // offset: 0x38
            nPhysics::AABB* OutputRigidBodyAABB;  // offset: 0x40
            nPhysics::RIGID_BODY_DATA* OutputPreservedRigidBodyData;  // offset: 0x48
            f32 CollisionMargin;  // offset: 0x50
            nPhysics::Math::Vector3 StepGravity;  // offset: 0x60
        };
    }  // namespace IoSPU
}  // namespace nPhysics

namespace nPhysics {
    namespace IoSPU {
        struct alignas(16) SOLVE_CONSTRAINT
        {
        public:
            nPhysics::CURRENT_RIGID_BODY_DATA* AddressCurrentRigidBodyData;  // offset: 0x0
            nPhysics::DELTA_VELOCITY* AddressDeltaVelocity;  // offset: 0x8
            const nPhysics::RIGID_BODY_STATUS* AddressRigidBodyStatus;  // offset: 0x10
            const u32* AddressNumBlockPerPhase;  // offset: 0x18
            nPhysics::CONTACT_PAIR* AddressContactPair;  // offset: 0x20
            nPhysics::CONSTRAINT* AddressConstraint;  // offset: 0x28
            const u32* AddressRigidBodyID;  // offset: 0x30
            const s8* AddressRigidBodyLayer;  // offset: 0x38
            const nPhysics::ORDERED_ID* AddressOrderedPairID;  // offset: 0x40
            const nPhysics::ORDERED_ID* AddressOrderedConstraintID;  // offset: 0x48
            const u32* AddressNumOrderedPairID;  // offset: 0x50
            const u32* AddressNumOrderedConstraintID;  // offset: 0x58
            const u32* AddressNumPairIDPerBlock;  // offset: 0x60
            const u32* AddressNumConstraintIDPerBlock;  // offset: 0x68
            const nPhysics::SORTED_PAIR* AddressPair;  // offset: 0x70
            const nPhysics::CONSTRAINT_HEADER* AddressConstraintHeader;  // offset: 0x78
            u32 NumBatchOrderedPairID;  // offset: 0x80
            u32 NumBatchOrderedConstraintID;  // offset: 0x84
            u32 TaskID;  // offset: 0x88
            u32 NumPhase;  // offset: 0x8c
            u32 NumPrefetch;  // offset: 0x90
            u32 NumUseSPU;  // offset: 0x94
            u32 LoopCount;  // offset: 0x98
            u32 MaxMaterial;  // offset: 0x9c
            u32 NumBlock;  // offset: 0xa0
            f32 StepTime;  // offset: 0xa4
            f32 SPS;  // offset: 0xa8
            u32 NumPair;  // offset: 0xac
            u32 NumRigidBody;  // offset: 0xb0
            u32 MaxRigidBody;  // offset: 0xb4
            u32 reserve;  // offset: 0xb8
            nPhysics::IoSPU::PROFILER_DATA* AddressProfiler;  // offset: 0xc0
            nPhysics::SOLVER_CONFIG SolverConfig;  // offset: 0xc8
        };
    }  // namespace IoSPU
}  // namespace nPhysics

namespace nPhysics {
    namespace IoSPU {
        struct SORT
        {
        public:
            nPhysics::SORT_DATA* AddressWorkSortData;  // offset: 0x0
            nPhysics::SORT_DATA* AddressSortData;  // offset: 0x8
            u32 StartBatch;  // offset: 0x10
            u32 NumBatch;  // offset: 0x14
            u32 NumSortData;  // offset: 0x18
            u32 NumUseSPU;  // offset: 0x1c
            u32 TaskID;  // offset: 0x20
            u32 reserve;  // offset: 0x24
            nPhysics::MERGE_SORT_INFO* AddressMergeSortInfo;  // offset: 0x28
            u32 NumMergeSortInfo;  // offset: 0x30
            u32 reserve1[2];  // offset: 0x34
            u32* AddressWorkKey;  // offset: 0x40
            u32* AddressWorkAddress;  // offset: 0x48
            u32* AddressWorkShelter1;  // offset: 0x50
            u32* AddressWorkShelter2;  // offset: 0x58
        };
    }  // namespace IoSPU
}  // namespace nPhysics

namespace nPhysics {
    namespace IoSPU {
        struct SPLIT_CONSTRAINT
        {
        public:
            nPhysics::RIGID_BODY_DATA* AddressRigidBodyData;  // offset: 0x0
            nPhysics::RIGID_BODY_LINK* AddressRigidBodyLink;  // offset: 0x8
            u8* AddressNumRigidBodyLink;  // offset: 0x10
            nPhysics::CONTACT_PAIR* AddressContactPair;  // offset: 0x18
            nPhysics::ORDERED_ID* OutputOrderedPairID;  // offset: 0x20
            nPhysics::ORDERED_ID* OutputOrderedConstraintID;  // offset: 0x28
            u32* OutputNumPairIDPerBlock;  // offset: 0x30
            u32* OutputNumConstraintIDPerBlock;  // offset: 0x38
            u32* OutputNumOrderedPairID;  // offset: 0x40
            u32* OutputNumOrderedConstraintID;  // offset: 0x48
            nPhysics::SORTED_PAIR* AddressPair;  // offset: 0x50
            nPhysics::CONSTRAINT_HEADER* AddressConstraintHeader;  // offset: 0x58
            u32 NumPair;  // offset: 0x60
            u32 NumConstraint;  // offset: 0x64
            u32 NumDisablePair;  // offset: 0x68
            u32 NumBatchOrderedPairID;  // offset: 0x6c
            u32 NumBatchOrderedConstraintID;  // offset: 0x70
            u32 NumUseSPU;  // offset: 0x74
            u32 OutputNumPhase;  // offset: 0x78
            u32 OutputNumBlock;  // offset: 0x7c
            u32* OutputNumBlockPerPhase;  // offset: 0x80
            s8* AddressRigidBodyLayer;  // offset: 0x88
            nPhysics::IoSPU::PROFILER_DATA* AddressProfiler;  // offset: 0x90
            u32* AddressGroundLayerRigidBodyID;  // offset: 0x98
            u32 NumGroundLayerRigidBody;  // offset: 0xa0
            u32 MinimumGranularity;  // offset: 0xa4
            u32 MaximumGranularity;  // offset: 0xa8
            u32 MaxMaterial;  // offset: 0xac
            u32 MaxRigidBody;  // offset: 0xb0
            u32 MaxContactPair;  // offset: 0xb4
            u32 MaxConstraint;  // offset: 0xb8
            u32 MaxPrefetch;  // offset: 0xbc
        };
    }  // namespace IoSPU
}  // namespace nPhysics

namespace nPhysics {
    namespace IoSPU {
        struct SYNC_RIGID_BODY
        {
        public:
            u32 NumRigidBody;  // offset: 0x0
            const u32* AddressRigidBodyID;  // offset: 0x8
            f32 InterpolationTime;  // offset: 0x10
            const nPhysics::RIGID_BODY_DATA* AddressPreservedRigidBodyData;  // offset: 0x18
            const nPhysics::CURRENT_RIGID_BODY_DATA* AddressCurrentRigidBodyData;  // offset: 0x20
            nPhysics::RIGID_BODY_DATA* OutputInterpolationRigidBodyData;  // offset: 0x28
            nPhysics::RIGID_BODY_STATUS* AddressRigidBodyStatus;  // offset: 0x30
            u8* AddressIslandWakeupTrigger;  // offset: 0x38
            u32* AddressIslandIndexOfRigidBody;  // offset: 0x40
            u32 MaxRigidBody;  // offset: 0x48
            u32* reserve[2];  // offset: 0x50
        };
    }  // namespace IoSPU
}  // namespace nPhysics

namespace nPhysics {
    namespace IoSPU {
        struct UPDATE_RIGID_BODY
        {
        public:
            nPhysics::CURRENT_RIGID_BODY_DATA* AddressRigidBodyData;  // offset: 0x0
            const nPhysics::DELTA_VELOCITY* AddressDeltaVelocity;  // offset: 0x8
            nPhysics::RIGID_BODY_INFORMATION* AddressRigidBodyInformation;  // offset: 0x10
            nPhysics::RIGID_BODY_STATUS* AddressRigidBodyStatus;  // offset: 0x18
            u32* AddressRigidBodyID;  // offset: 0x20
            s8* AddressRigidBodyLayer;  // offset: 0x28
            nPhysics::IoSPU::PROFILER_DATA* AddressProfiler;  // offset: 0x30
            u32 StartBatch;  // offset: 0x38
            u32 NumBatch;  // offset: 0x3c
            u32 MaxRigidBody;  // offset: 0x40
            u32* AddressIslandIndexOfRigidBody;  // offset: 0x48
            u32* AddressIslandStatus;  // offset: 0x50
            nPhysics::UPDATE_RIGID_BODY_CONFIG Config;  // offset: 0x60
        };
    }  // namespace IoSPU
}  // namespace nPhysics
