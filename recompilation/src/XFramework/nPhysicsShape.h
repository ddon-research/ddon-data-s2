#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "nPhysicsMathVector4.h"

// Forward declarations
class MtAABB;
class MtCapsule;
class MtCylinder;
class MtLineSegment;
class MtOBB;
class MtSphere;
class MtTriangle;
class MtVector3;
namespace nPhysics { struct AABB; }
namespace nPhysics { namespace Math { class Matrix; } }
namespace nPhysics { namespace Math { class Vector3; } }
namespace nPhysics { namespace Math { class Vector4; } }
namespace nPhysics { class Phantom; }
namespace nPhysics { class SHAPES; }

// Declarations
namespace nPhysics { class SHAPE; }

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;

namespace nPhysics {
    class alignas(16) SHAPE
    {
        friend class nPhysics::Phantom;
        friend class nPhysics::SHAPES;
    public:
        enum TYPE
        {
            TYPE_UNKNOWN = 0,
            TYPE_SPHERE = 1,
            TYPE_CAPSULE = 2,
            TYPE_CYLINDER = 3,
            TYPE_OBB = 4,
            TYPE_TRIANGLE = 5,
            TYPE_LINE_SEGMENT = 6,
            TYPE_MAX = 7,
        };
    public:
        using MOVE_SHAPE = nPhysics::SHAPE(*)(const nPhysics::SHAPE&, const nPhysics::Math::Vector3&);
        using TRANSFORM_SHAPE = void(*)(nPhysics::SHAPE&, nPhysics::AABB&, const nPhysics::SHAPE&, const nPhysics::Math::Matrix&);
        using GET_CIRCUMSCRIBED_AABB = nPhysics::AABB(*)(const nPhysics::SHAPE&);
        using GET_SUPPORT_MAPPING = nPhysics::Math::Vector3(*)(const nPhysics::SHAPE&, const nPhysics::Math::Vector3&);
        using GET_INTERNAL_POSITION = nPhysics::Math::Vector3(*)(const nPhysics::SHAPE&);
    private:
        void set_type(const u32 type);
        void set_attribute(const u32 attribute);
        static nPhysics::SHAPE MoveSphereOrOBB(const nPhysics::SHAPE& shape, const nPhysics::Math::Vector3& offset);
        static nPhysics::SHAPE MoveCapsuleOrCylinderOrLineSegment(const nPhysics::SHAPE& shape, const nPhysics::Math::Vector3& offset);
        static nPhysics::SHAPE MoveTriangle(const nPhysics::SHAPE& shape, const nPhysics::Math::Vector3& offset);
        static void TransformSphere(nPhysics::SHAPE& output_shape, nPhysics::AABB& circumscribed_aabb, const nPhysics::SHAPE& input_shape, const nPhysics::Math::Matrix& transform_matrix);
        static void TransformCapsuleOrCylinder(nPhysics::SHAPE& output_shape, nPhysics::AABB& circumscribed_aabb, const nPhysics::SHAPE& input_shape, const nPhysics::Math::Matrix& transform_matrix);
        static void TransformOBB(nPhysics::SHAPE& output_shape, nPhysics::AABB& circumscribed_aabb, const nPhysics::SHAPE& input_shape, const nPhysics::Math::Matrix& transform_matrix);
        static void TransformLineSegment(nPhysics::SHAPE& output_shape, nPhysics::AABB& circumscribed_aabb, const nPhysics::SHAPE& input_shape, const nPhysics::Math::Matrix& transform_matrix);
        static nPhysics::AABB GetCircumscribedAABBForSphere(const nPhysics::SHAPE& shape);
        static nPhysics::AABB GetCircumscribedAABBForCapsuleOrCylinder(const nPhysics::SHAPE& shape);
        static nPhysics::AABB GetCircumscribedAABBForOBB(const nPhysics::SHAPE& shape);
        static nPhysics::AABB GetCircumscribedAABBForLineSegment(const nPhysics::SHAPE& shape);
        static nPhysics::Math::Vector3 GetSupportMappingSphere(const nPhysics::SHAPE& shape, const nPhysics::Math::Vector3& direction);
        static nPhysics::Math::Vector3 GetSupportMappingCapsule(const nPhysics::SHAPE& shape, const nPhysics::Math::Vector3& direction);
        static nPhysics::Math::Vector3 GetSupportMappingCylinder(const nPhysics::SHAPE& shape, const nPhysics::Math::Vector3& direction);
        static nPhysics::Math::Vector3 GetSupportMappingOBB(const nPhysics::SHAPE& shape, const nPhysics::Math::Vector3& direction);
        static nPhysics::Math::Vector3 GetSupportMappingTriangle(const nPhysics::SHAPE& shape, const nPhysics::Math::Vector3& direction);
        static nPhysics::Math::Vector3 GetSupportMappingLineSegment(const nPhysics::SHAPE& shape, const nPhysics::Math::Vector3& direction);
        static nPhysics::Math::Vector3 GetInternalPositionSphereOrOBB(const nPhysics::SHAPE& shape);
        static nPhysics::Math::Vector3 GetInternalPositionCapsuleOrCylinderOrLineSegment(const nPhysics::SHAPE& shape);
        static nPhysics::Math::Vector3 GetInternalPositionTriangle(const nPhysics::SHAPE& shape);
    public:
        u32 get_type() const;
        s32 get_material_no() const;
        u32 get_attribute() const;
        bool isEnable() const;
        void clear();
        void set_material_no(const s32 no);
        nPhysics::SHAPE move(const nPhysics::Math::Vector3& offset) const;
        nPhysics::SHAPE transform(nPhysics::AABB& circumscribed_aabb, const nPhysics::Math::Matrix& transform_matrix) const;
        nPhysics::AABB get_circumscribed_aabb() const;
        nPhysics::Math::Vector3 get_support_mapping(const nPhysics::Math::Vector3& direction) const;
        nPhysics::Math::Vector3 get_internal_position() const;
        nPhysics::Math::Vector3 get_internal_position_of_triangle() const;
        void set(const MtSphere& sphere);
        void set(const MtCapsule& capsule);
        void set(const MtCylinder& cylinder);
        void set(const MtOBB& obb);
        void set(const MtAABB& aabb);
        void set(const MtTriangle& triangle, const MtVector3& normal, const u32 attribute);
        void set(const MtLineSegment& line_segment);
        void get(MtSphere& sphere) const;
        void get(MtCapsule& capsule) const;
        void get(MtCylinder& cylinder) const;
        void get(MtOBB& obb) const;
        void get(MtTriangle& triangle, MtVector3& normal, u32& attribute) const;
        void get(MtLineSegment& line_segment) const;
        void operator=(const nPhysics::SHAPE& source);
    private:
        u32 Type;  // offset: 0x0
        s32 MaterialNo;  // offset: 0x4
        u32 Attribute;  // offset: 0x8
        u32 reserve[1];  // offset: 0xc
        nPhysics::Math::Vector4 Parameter[4];  // offset: 0x10
        static MOVE_SHAPE MoveFunctionTable[7];
        static TRANSFORM_SHAPE TransformFunctionTable[7];
        static GET_CIRCUMSCRIBED_AABB GetCircumscribedAABBFunctionTable[7];
        static GET_SUPPORT_MAPPING GetSupportMappingFunctionTable[7];
        static GET_INTERNAL_POSITION GetInternalPositionFunctionTable[7];
        static GET_INTERNAL_POSITION GetOriginalInternalPositionFunctionTable[7];
    };
}  // namespace nPhysics
