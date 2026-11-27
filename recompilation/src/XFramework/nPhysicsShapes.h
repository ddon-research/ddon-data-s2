#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "nPhysicsMathVector3.h"
#include "nPhysicsShape.h"
#include "nPhysicsStruct.h"

// Forward declarations
class MtCapsule;
class MtCylinder;
class MtOBB;
class MtSphere;
namespace nPhysics { struct AABB; }
namespace nPhysics { namespace Math { class Matrix; } }
namespace nPhysics { namespace Math { class Vector3; } }
namespace nPhysics { class SHAPE; }

// Declarations
namespace nPhysics { class SHAPES; }

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;

namespace nPhysics {
    class SHAPES
    {
    public:
        SHAPES();
        ~SHAPES();
        u32 get_num_shape() const;
        u32 get_status() const;
        nPhysics::Math::Vector3 get_velocity() const;
        u32 get_scroll_filter() const;
        u32 get_scroll_type() const;
        void set_velocity(const nPhysics::Math::Vector3& velocity);
        void set_status(const u32 status);
        void set_scroll_filter(const u32 filter);
        void set_scroll_type(const u32 type);
        void add(const MtSphere& sphere, const s32 material);
        void add(const MtCapsule& capsule, const s32 material);
        void add(const MtCylinder& cylinder, const s32 material);
        void add(const MtOBB& obb, const s32 material);
        nPhysics::SHAPES transform(const nPhysics::Math::Matrix& transform_matrix) const;
        const nPhysics::SHAPE& get_shape(const u32 index) const;
        nPhysics::AABB& get_circumscribed_aabb();
        void clear();
        void operator=(const nPhysics::SHAPES& source);
    private:
        u32 NumShape;  // offset: 0x0
        u32 Status;  // offset: 0x4
        u32 ScrollType;  // offset: 0x8
        u32 ScrollFilter;  // offset: 0xc
        nPhysics::AABB CircumscribedAABB;  // offset: 0x10
        nPhysics::Math::Vector3 Velocity;  // offset: 0x40
        nPhysics::SHAPE Shape[4];  // offset: 0x50
    public:
        static const u32 MAX_OBJECT = 4;
    };
}  // namespace nPhysics
