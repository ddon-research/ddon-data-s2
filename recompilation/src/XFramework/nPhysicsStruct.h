#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtEaseCurve.h"
#include "../MT/MtMath.h"
#include "nPhysicsMathMatrix3.h"
#include "nPhysicsMathQuaternion.h"
#include "nPhysicsMathVector3.h"
#include "nPhysicsMathVector4.h"

// Forward declarations
class MtAABB;
struct MtFloat3;
struct MtFloat3A;
struct MtFloat4A;
class MtHermiteCurve;
namespace nPhysics { namespace Math { class Matrix3; } }
namespace nPhysics { namespace Math { class Quaternion; } }
namespace nPhysics { namespace Math { class Vector3; } }
namespace nPhysics { namespace Math { class Vector4; } }
namespace nPhysics { class QUANTIZATION_AABB; }

namespace nPhysics {
    enum CUBE_MAP_ID
    {
        CUBE_MAP_ID_INVALID = 0,
        CUBE_MAP_ID_LEFT = 1,
        CUBE_MAP_ID_RIGHT = 2,
        CUBE_MAP_ID_TOP = 3,
        CUBE_MAP_ID_BOTTOM = 4,
        CUBE_MAP_ID_FRONT = 5,
        CUBE_MAP_ID_BACK = 6,
        CUBE_MAP_ID_MAX = 7,
    };
}  // namespace nPhysics

// Declarations
namespace nPhysics { struct AABB; }
namespace nPhysics { struct COLLISION_INFORMATION; }
namespace nPhysics { struct CONSTRAINT; }
namespace nPhysics { struct CONSTRAINT_CACHE2; }
namespace nPhysics { struct CONSTRAINT_HEADER; }
namespace nPhysics { struct CONTACT_INFO; }
namespace nPhysics { struct CONTACT_UPDATE_PARAMETER; }
namespace nPhysics { struct CURRENT_RIGID_BODY_DATA; }
namespace nPhysics { struct DELTA_VELOCITY; }
namespace nPhysics { struct INITIALIZE_PARAMETER; }
namespace nPhysics { struct RIGID_BODY_DATA; }
namespace nPhysics { struct RIGID_BODY_INFORMATION; }
namespace nPhysics { struct RIGID_BODY_STATUS; }
namespace nPhysics { struct SOLVER_CONFIG; }
namespace nPhysics { class SORTED_PAIR; }
namespace nPhysics { class SORT_DATA; }
namespace nPhysics { struct UPDATE_RIGID_BODY_CONFIG; }

// Type aliases from DWARF
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
using s16 = short;
using s32 = int;
using u16 = unsigned short;
using u32 = unsigned int;
using uintptr = __uintptr_t;

namespace nPhysics {
    struct AABB
    {
    public:
        AABB();
        AABB(const nPhysics::AABB&);
        AABB(const MtAABB&);
        ~AABB();
        u32 get_id() const;
        void set_id(const u32 id);
        u32 get_status() const;
        void set_status(const u32 status);
        uintptr get_address() const;
        void set_address(const uintptr address);
        nPhysics::Math::Vector3 get_center() const;
        const nPhysics::AABB& operator=(const nPhysics::AABB& aabb);
        void inflate(const nPhysics::AABB& aabb);
        void inflate(const nPhysics::Math::Vector3& margin);
        operator MtAABB() const;
    public:
        nPhysics::Math::Vector3 Maximum;  // offset: 0x0
        nPhysics::Math::Vector3 Minimum;  // offset: 0x10
        uintptr mpAddress;  // offset: 0x20
    };
}  // namespace nPhysics

namespace nPhysics {
    struct COLLISION_INFORMATION
    {
    public:
        void operator=(const nPhysics::COLLISION_INFORMATION& source);
        bool isHit(const nPhysics::COLLISION_INFORMATION& target) const;
    public:
        u32 Group;  // offset: 0x0
        u32 ID;  // offset: 0x4
        u32 PrimaryFilter;  // offset: 0x8
        u32 SecondaryFilter;  // offset: 0xc
        u32 reserve;  // offset: 0x10
        u32 Bit;  // offset: 0x14
        u32 PrimaryAttribute;  // offset: 0x18
        u32 SecondaryAttribute;  // offset: 0x1c
    };
}  // namespace nPhysics

namespace nPhysics {
    struct CONSTRAINT_CACHE2
    {
    public:
        nPhysics::Math::Vector3 Axis;  // offset: 0x0
        f32 InitialValue;  // offset: 0x10
        f32 InverseConstant;  // offset: 0x14
        f32 Minimum;  // offset: 0x18
        f32 Maximum;  // offset: 0x1c
    };
}  // namespace nPhysics

namespace nPhysics {
    struct CONSTRAINT_HEADER
    {
    public:
        void enable();
        void disable();
        u32 getStatus() const;
        void setStatus(const u32 status);
        u32 get_constraint_id() const;
        u32 get_rigid_body_id1() const;
        u32 get_rigid_body_id2() const;
    public:
        u32 RigidBodyID1;  // offset: 0x0
        u32 RigidBodyID2;  // offset: 0x4
        u32 NumConstraint : 4;  // offset: 0x8
        u32 Type : 4;  // offset: 0x8
        u32 FunctionID : 8;  // offset: 0x8
        u32 Status : 16;  // offset: 0x8
        u32 ID;  // offset: 0xc
    };
}  // namespace nPhysics

namespace nPhysics {
    struct CONTACT_INFO
    {
    public:
        void operator=(const nPhysics::CONTACT_INFO& source);
    public:
        MtFloat3A Position1;  // offset: 0x0
        f32 Distance;  // offset: 0xc
        MtFloat3A Position2;  // offset: 0x10
        u32 MaterialNo1 : 16;  // offset: 0x1c
        u32 MaterialNo2 : 16;  // offset: 0x1c
        MtFloat3A Normal;  // offset: 0x20
        nPhysics::CUBE_MAP_ID CubeMapID;  // offset: 0x2c
    };
}  // namespace nPhysics

namespace nPhysics {
    struct alignas(16) CONTACT_UPDATE_PARAMETER
    {
    public:
        CONTACT_UPDATE_PARAMETER();
    public:
        f32 NormalSeparateLimit;  // offset: 0x0
        f32 TangentSeparateLimit;  // offset: 0x4
        f32 DistanceLimit;  // offset: 0x8
    private:
        f32 reserve;  // offset: 0xc
    };
}  // namespace nPhysics

namespace nPhysics {
    struct DELTA_VELOCITY
    {
    public:
        nPhysics::Math::Vector3 Linear;  // offset: 0x0
        nPhysics::Math::Vector3 Angular;  // offset: 0x10
    };
}  // namespace nPhysics

namespace nPhysics {
    struct INITIALIZE_PARAMETER
    {
    public:
        INITIALIZE_PARAMETER();
    public:
        MtFloat3 WorldCenter;  // offset: 0x0
        u32 MaxRigidBody;  // offset: 0xc
        MtFloat3 WorldExtent;  // offset: 0x10
        u32 MaxContactPair;  // offset: 0x1c
        u32 MaxGeometry;  // offset: 0x20
        u32 MaxConstraint;  // offset: 0x24
        u32 MaxMaterial;  // offset: 0x28
    };
}  // namespace nPhysics

namespace nPhysics {
    struct RIGID_BODY_DATA
    {
    public:
        void clear();
        void update();
        void lerp(const nPhysics::RIGID_BODY_DATA& start, const nPhysics::RIGID_BODY_DATA& end, const f32 t);
        void operator=(const nPhysics::RIGID_BODY_DATA& source);
        s32 get_layer() const;
        void set_layer(const s32 layer);
        u32 is_static() const;
        u32 get_status() const;
        void set_status(const u32 status);
        void update(const nPhysics::DELTA_VELOCITY& delta_velocity, nPhysics::RIGID_BODY_INFORMATION& information, nPhysics::RIGID_BODY_STATUS& status, const nPhysics::UPDATE_RIGID_BODY_CONFIG& config);
        void dampingVelocity(nPhysics::RIGID_BODY_INFORMATION& information, nPhysics::RIGID_BODY_STATUS& status, const nPhysics::UPDATE_RIGID_BODY_CONFIG& config);
    public:
        nPhysics::Math::Vector3 Position;  // offset: 0x0
        nPhysics::Math::Quaternion Rotation;  // offset: 0x10
        nPhysics::Math::Vector3 LinearVelocity;  // offset: 0x20
        nPhysics::Math::Vector3 AngularVelocity;  // offset: 0x30
    };
}  // namespace nPhysics

namespace nPhysics {
    struct RIGID_BODY_INFORMATION
    {
    public:
        void clear_aggressive_sleep_count();
        void increment_aggressive_sleep_count();
        u32 get_aggressive_sleep_count() const;
        nPhysics::Math::Vector3 getSleepPosition() const;
        nPhysics::Math::Quaternion getSleepRotation() const;
        void setSleepPosition(const nPhysics::Math::Vector3& position);
        void setSleepRotation(const nPhysics::Math::Quaternion& rotation);
        nPhysics::Math::Matrix3 getInverseInertiaTensor() const;
        void setInverseInertiaTensor(const nPhysics::Math::Matrix3& inertia_tensor);
        void set_max_linear_velocity(const f32 velocity);
        void set_max_angular_velocity(const f32 velocity);
        void set_linear_damping_scale(const f32 damping);
        void set_angular_damping_scale(const f32 damping);
        void setRestitution(const f32 restitution);
        void setStaticFriction(const f32 friction);
        void setKineticFriction(const f32 friction);
        void set_inverse_mass(const f32 mass);
        f32 getRestitution() const;
        f32 getStaticFriction() const;
        f32 getKineticFriction() const;
        f32 get_inverse_mass() const;
        f32 get_max_linear_velocity() const;
        f32 get_max_angular_velocity() const;
        f32 get_linear_damping_scale() const;
        f32 get_angular_damping_scale() const;
    public:
        nPhysics::Math::Matrix3 InverseInertiaTensor;  // offset: 0x0
        nPhysics::Math::Vector4 Parameter;  // offset: 0x30
        nPhysics::Math::Vector4 VelocityParameter;  // offset: 0x40
        MtFloat3A SleepPosition;  // offset: 0x50
        u32 AggressiveSleepCount;  // offset: 0x5c
        MtFloat4A SleepRotation;  // offset: 0x60
    };
}  // namespace nPhysics

namespace nPhysics {
    struct RIGID_BODY_STATUS
    {
    public:
        enum STATE
        {
            STATE_ELASTIC = 4,
            STATE_SLEEP = 16,
            STATE_OUTSIDE_AREA = 32,
            STATE_GROUND = 64,
            STATE_INVALID_GRAVITY = 128,
            STATE_INVALID_DAMPING = 256,
            STATE_INVALID_SLEEP = 512,
            STATE_INVALID_FRICTION = 1024,
            STATE_INVALID_PHYSICS = 2048,
            STATE_INVALID_ROTATION = 4096,
            STATE_ACTIVE_CONSTRAINT = 8192,
            STATE_FREEZE = 16384,
            STATE_FIXED = 32768,
            STATE_KEY_FRAME = 65536,
            STATE_DESTROY = 1048576,
            STATE_RESET = 2097152,
            STATE_CONTACT_CACHE = 4194304,
            STATE_DISABLE = 8388608,
            STATE_AGGRESSIVE_SLEEP = 16777216,
            STATE_CCD = 67108864,
            STATE_SCROLL = 134217728,
            STATE_PARTICULAR = 268435456,
            STATE_STATIC = 114704,
        };
    public:
        void clear();
        void update();
        u32 get_status() const;
        void set_status(const u32 status);
        void add_state(const u32 state);
        void remove_state(const u32 state);
        bool check_state(const u32 state) const;
        u32 get_current_status() const;
        void set_current_status(const u32);
        void add_current_state(const u32 state = 32768);
        void remove_current_state(const u32 state);
        bool check_current_state(const u32 state) const;
    public:
        u32 Status;  // offset: 0x0
        u32 CurrentStatus;  // offset: 0x4
        u32 AddState;  // offset: 0x8
        u32 RemoveState;  // offset: 0xc
    };
}  // namespace nPhysics

namespace nPhysics {
    struct SOLVER_CONFIG
    {
    public:
        f32 get_contact_tolerance() const;
    public:
        f32 InverseWeightAmplifyCoefficient;  // offset: 0x0
        f32 ContactTolerance;  // offset: 0x4
        u32 reserve[2];  // offset: 0x8
        MtHermiteCurve ElasticFrictionCurve;  // offset: 0x10
    };
}  // namespace nPhysics

namespace nPhysics {
    class SORT_DATA
    {
    public:
        u32 getSearchKey() const;
        void setSearchKey(const u32 key);
        void operator=(const nPhysics::SORT_DATA& input);
    protected:
        union
        {
        public:
            f32 mF32[8];  // offset: 0x0
            u32 mU32[8];  // offset: 0x0
            s32 mS32[8];  // offset: 0x0
            u16 mU16[16];  // offset: 0x0
            s16 mS16[16];  // offset: 0x0
        };  // offset: 0x0
    };
}  // namespace nPhysics

namespace nPhysics {
    struct alignas(16) UPDATE_RIGID_BODY_CONFIG
    {
    public:
        f32 getLinearExtraDamping() const;
        f32 getLinearExtraDampingRange2() const;
        f32 getAngularExtraDamping() const;
        f32 getAngularExtraDampingRange2() const;
        f32 getLinearSleepRange2() const;
        f32 getAngularSleepRange2() const;
        f32 getWakeupPosition() const;
        f32 getWakeupRotation() const;
        void setLinearExtraDamping(const f32 damping);
        void setLinearExtraDampingRange2(const f32 range);
        void setAngularExtraDamping(const f32 damping);
        void setAngularExtraDampingRange2(const f32 range);
        void setLinearSleepRange2(const f32 range);
        void setAngularSleepRange2(const f32 range);
        void setWakeupPosition(const f32 range);
        void setWakeupRotation(const f32 range);
    private:
        f32 LinearExtraDamping;  // offset: 0x0
        f32 LinearExtraDampingRange2;  // offset: 0x4
        f32 AngularExtraDamping;  // offset: 0x8
        f32 AngularExtraDampingRange2;  // offset: 0xc
        f32 LinearSleepRange2;  // offset: 0x10
        f32 AngularSleepRange2;  // offset: 0x14
        f32 WakeupPosition;  // offset: 0x18
        f32 WakeupRotation;  // offset: 0x1c
    };
}  // namespace nPhysics

namespace nPhysics {
    struct CONSTRAINT
    {
    public:
        enum TYPE
        {
            TYPE_BALL_JOINT = 0,
            TYPE_AXIS = 1,
            TYPE_CONE_TWIST = 2,
            TYPE_HINGE = 3,
            TYPE_UNIVERSAL = 4,
            TYPE_MUSCLE = 5,
            TYPE_MOTOR = 6,
            TYPE_ERROR = 7,
            TYPE_MAX = 8,
        };
        enum STATE
        {
            STATE_ENABLE = 0,
            STATE_BREAK = 1,
            STATE_OUTSIDE_AREA = 2,
            STATE_MAX = 3,
        };
    public:
        void setLocalPosition1(const nPhysics::Math::Vector3& position);
        void setLocalPosition2(const nPhysics::Math::Vector3& position);
        void setWorldRelativePosition1(const nPhysics::Math::Vector3& position);
        void setWorldRelativePosition2(const nPhysics::Math::Vector3& position);
        void setAdditionalRelativeVelocity(const nPhysics::Math::Vector3& velocity);
        void setLocalRotation1(const nPhysics::Math::Quaternion& rotation);
        void setLocalRotation2(const nPhysics::Math::Quaternion& rotation);
        void setSwingLimit(const f32 limit);
        void setTwistLimit(const f32 min_limit, const f32 max_limit);
        void setMaxForce(const nPhysics::Math::Vector3& force);
        void setHingeAxis1(const nPhysics::Math::Vector3& axis);
        void setHingeAxis2(const nPhysics::Math::Vector3& axis);
        void setHingeLimit(const f32 min_limit, const f32 max_limit);
        void setStiffness(const f32 stiffness);
        void setDesireRotation(const nPhysics::Math::Quaternion& rotation);
        void setDesireVelocity(const nPhysics::Math::Vector3& velocity);
        void setAdditionalRotation(const nPhysics::Math::Quaternion& rotation);
        void setMaxSwingTorque(const f32 torque);
        void setMaxCorrectTorque(const f32 torque);
        void setMaxTwistTorque(const f32 torque);
        void setSpringConstant(const f32 constant);
        void setDistanceOnAxis(const f32 constant);
        void setMaximumLength(const f32 length);
        void setMinimumLength(const f32 length);
        void setConstraintAxis1(const nPhysics::Math::Vector3& axis);
        void setConstraintAxis2(const nPhysics::Math::Vector3& axis);
        void setFastReboundDamping(const f32 damping);
        void setFastBumpDamping(const f32 damping);
        void setSlowReboundDamping(const f32 damping);
        void setSlowBumpDamping(const f32 damping);
        void setAdditionalSpringPower(const f32 power);
        void setMotorAxis1(const nPhysics::Math::Vector3& axis);
        void setMotorAxis2(const nPhysics::Math::Vector3& axis);
        void setMaximumMotorTorque(const f32 torque);
        void setMinimumMotorTorque(const f32 torque);
        void setMotorSpeed(const f32 speed);
        void setWorldMotorAxis1(const nPhysics::Math::Vector3& axis);
        void setWorldMotorAxis2(const nPhysics::Math::Vector3& axis);
        nPhysics::Math::Vector3 getLocalPosition1() const;
        nPhysics::Math::Vector3 getLocalPosition2() const;
        nPhysics::Math::Vector3 getWorldRelativePosition1() const;
        nPhysics::Math::Vector3 getWorldRelativePosition2() const;
        nPhysics::Math::Vector3 getAdditionalRelativeVelocity() const;
        nPhysics::Math::Quaternion getLocalRotation1() const;
        nPhysics::Math::Quaternion getLocalRotation2() const;
        f32 getSwingLimit() const;
        f32 getMinTwistLimit() const;
        f32 getMaxTwistLimit() const;
        nPhysics::Math::Vector3 getConeTwistLimit() const;
        nPhysics::Math::Vector3 getMaxForce() const;
        nPhysics::Math::Vector3 getHingeAxis1() const;
        nPhysics::Math::Vector3 getHingeAxis2() const;
        f32 getMinHingeLimit() const;
        f32 getMaxHingeLimit() const;
        nPhysics::Math::Vector4 getHingeLimit() const;
        f32 getStiffness() const;
        nPhysics::Math::Quaternion getDesireRotation() const;
        nPhysics::Math::Vector3 getDesireVelocity() const;
        nPhysics::Math::Quaternion getAdditionalRotation() const;
        f32 getMaxSwingTorque() const;
        f32 getMaxCorrectTorque() const;
        f32 getMaxTwistTorque() const;
        nPhysics::Math::Vector3 getMaxTorque();
        f32 getSpringConstant() const;
        f32 getDistanceOnAxis() const;
        f32 getMaximumLength() const;
        f32 getMinimumLength() const;
        nPhysics::Math::Vector3 getConstraintAxis1() const;
        nPhysics::Math::Vector3 getConstraintAxis2() const;
        f32 getFastReboundDamping() const;
        f32 getFastBumpDamping() const;
        f32 getSlowReboundDamping() const;
        f32 getSlowBumpDamping() const;
        f32 getAdditionalSpringPower() const;
        nPhysics::Math::Vector3 getMotorAxis1() const;
        nPhysics::Math::Vector3 getMotorAxis2() const;
        f32 getMaximumMotorTorque() const;
        f32 getMinimumMotorTorque() const;
        f32 getMotorSpeed() const;
        nPhysics::Math::Vector3 getWorldMotorAxis1() const;
        nPhysics::Math::Vector3 getWorldMotorAxis2() const;
        u32 getStatus() const;
        u32 getType() const;
        void setStatus(const u32 status);
        void enable();
        void disable();
        u32 get_num_constraint() const;
        const nPhysics::Math::Matrix3& get_inverse_inertia_tensor1() const;
        const nPhysics::Math::Matrix3& get_inverse_inertia_tensor2() const;
        void set_inverse_inertia_tensor1(const nPhysics::Math::Matrix3& inverse_inertia_tensor);
        void set_inverse_inertia_tensor2(const nPhysics::Math::Matrix3& inverse_inertia_tensor);
        f32 get_inverse_mass1() const;
        f32 get_inverse_mass2() const;
        void set_inverse_mass1(const f32 inverse_mass);
        void set_inverse_mass2(const f32 inverse_mass);
        void operator=(const nPhysics::CONSTRAINT_HEADER& header);
    public:
        nPhysics::CONSTRAINT_HEADER Header;  // offset: 0x0
        nPhysics::CONSTRAINT_CACHE2 ConstraintCache[4];  // offset: 0x10
        nPhysics::Math::Matrix3 InverseInertiaTensor1;  // offset: 0x90
        nPhysics::Math::Matrix3 InverseInertiaTensor2;  // offset: 0xc0
        nPhysics::Math::Vector4 Parameter[8];  // offset: 0xf0
        f32 SpringPower;  // offset: 0x170
        f32 DampingPower;  // offset: 0x174
        u32 Attribute;  // offset: 0x178
        f32 reserve[1];  // offset: 0x17c
    };
}  // namespace nPhysics

namespace nPhysics {
    struct CURRENT_RIGID_BODY_DATA : public nPhysics::RIGID_BODY_DATA
    {
    public:
        void clear();
        nPhysics::Math::Matrix3 get_inverse_inertia_tensor() const;
        f32 get_inverse_mass() const;
    public:
        nPhysics::Math::Matrix3 InverseInertiaTensor;  // offset: 0x40
        nPhysics::Math::Vector4 Parameter;  // offset: 0x70
    };
}  // namespace nPhysics

namespace nPhysics {
    class SORTED_PAIR : public nPhysics::SORT_DATA
    {
    public:
        u32 get_rigid_body_id1() const;
        void set_rigid_body_id1(const u32 id);
        u32 get_rigid_body_id2() const;
        void set_rigid_body_id2(const u32 id);
        u32 get_rigid_body_status1() const;
        void set_rigid_body_status1(const u32 status);
        u32 get_rigid_body_status2() const;
        void set_rigid_body_status2(const u32 status);
        void set_rigid_body(const nPhysics::QUANTIZATION_AABB& rigid_body1, const nPhysics::QUANTIZATION_AABB& rigid_body2);
        void clear_keep_count();
        void increment_keep_count();
        u32 get_keep_count();
        bool is_new_pair() const;
        u32 get_contact_pair() const;
        void set_contact_pair(const u32 index);
        u32 get_num_contact() const;
        void set_num_contact(const u32 num);
        void merge_old_pair(const nPhysics::SORTED_PAIR& old_pair);
    };
}  // namespace nPhysics

inline nPhysics::AABB::AABB() {
}

inline nPhysics::INITIALIZE_PARAMETER::INITIALIZE_PARAMETER() {
    this->MaxRigidBody = 100;
    this->MaxGeometry = 200;
    this->MaxConstraint = 100;
    this->MaxContactPair = 2000;
    this->MaxMaterial = 32;
    this->WorldCenter.x = 0.0f;
    this->WorldCenter.y = 0.0f;
    this->WorldCenter.z = 0.0f;
    this->WorldExtent.x = 40000.0f;
    this->WorldExtent.y = 20000.0f;
    this->WorldExtent.z = 40000.0f;
}

inline void nPhysics::RIGID_BODY_STATUS::add_current_state(const u32 state) {
    this->AddState = this->AddState | 32768u;
    this->RemoveState = this->RemoveState & 0xFFFF7FFFu;
    this->CurrentStatus = this->CurrentStatus | 32768u;
}
