#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "nPhysicsBase.h"
#include "nPhysicsInertiaTensor.h"
#include "nPhysicsList.h"
#include "nPhysicsMass.h"
#include "nPhysicsShapes.h"

// Forward declarations
class MtAllocator;
class MtCapsule;
struct MtContact;
class MtCylinder;
class MtDTI;
struct MtFloat3x3;
class MtLineSegment;
class MtMatrix;
class MtOBB;
class MtObject;
class MtQuaternion;
class MtSphere;
class MtVector3;
class MtVector4;
namespace nPhysics { struct COLLISION_INFORMATION; }
namespace nPhysics { struct CURRENT_RIGID_BODY_DATA; }
namespace nPhysics { namespace Event { class Collide; } }
namespace nPhysics { namespace Event { class Contact; } }
namespace nPhysics { namespace Event { class Separate; } }
namespace nPhysics { class InertiaTensor; }
namespace nPhysics { namespace Listener { class Collision; } }
namespace nPhysics { namespace Listener { class Status; } }
namespace nPhysics { class Mass; }
namespace nPhysics { class POWER; }
namespace nPhysics { struct RIGID_BODY_DATA; }
namespace nPhysics { struct RIGID_BODY_INFORMATION; }
namespace nPhysics { struct RIGID_BODY_STATUS; }
namespace nPhysics { class SHAPES; }
namespace nPhysics { class System; }

// Declarations
namespace nPhysics { class RigidBody; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
namespace nPhysics { namespace Event { using COLLIDE_FUNCTION = void(MtObject::*)(const nPhysics::Event::Collide&); } }
namespace nPhysics { namespace Event { using CONTACT_FUNCTION = void(MtObject::*)(const nPhysics::Event::Contact&); } }
namespace nPhysics { namespace Event { using SEPARATE_FUNCTION = void(MtObject::*)(const nPhysics::Event::Separate&); } }
namespace nPhysics { namespace Event { using STATUS_FUNCTION = void(MtObject::*)(); } }
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using uintptr = __uintptr_t;

namespace nPhysics {
    class RigidBody : public nPhysics::Base
    {
        friend class nPhysics::System;
    public:
        enum ADD_GEOMETRY_FLAG
        {
            ADD_GEOMETRY_COLLISION = 1,
            ADD_GEOMETRY_INERTIA_TENSOR = 2,
            ADD_GEOMETRY_MASS = 4,
            ADD_GEOMETRY_ALL = 7,
        };
    public:
        class MyDTI;
        class INITIALIZER;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class INITIALIZER
        {
        public:
            INITIALIZER();
            ~INITIALIZER();
            void add_shape(const MtSphere& sphere, const f32 density, const s32 material_no, const u32 flag);
            void add_shape(const MtCapsule& capsule, const f32 density, const s32 material_no, const u32 flag);
            void add_shape(const MtCylinder& cylinder, const f32 density, const s32 material_no, const u32 flag);
            void add_shape(const MtOBB& obb, const f32 density, const s32 material_no, const u32 flag);
            void add_shape(const MtSphere& sphere, const MtMatrix& inertia_tensor, const f32 mass, const s32 material_no, const u32 flag);
            void add_shape(const MtCapsule& capsule, const MtMatrix& inertia_tensor, const f32 mass, const s32 material_no, const u32 flag);
            void add_shape(const MtCylinder& cylinder, const MtMatrix& inertia_tensor, const f32 mass, const s32 material_no, const u32 flag);
            void add_shape(const MtOBB& obb, const MtMatrix& inertia_tensor, const f32 mass, const s32 material_no, const u32 flag);
            void setMass(const f32 mass);
            void setInertiaTensor(const MtMatrix& inertia_tensor);
            void setStatus(const u32 status);
            void setMaxLinearVelocity(const f32 velocity);
            void setMaxAngularVelocity(const f32 velocity);
            void setMaxRadianPerStep(const f32);
            void setPosition(const MtVector3& position);
            void setRotation(const MtQuaternion& rotation);
            void setLinearVelocity(const MtVector3& velocity);
            void setAngularVelocity(const MtVector3& velocity);
            void setLinearDamping(const f32 damping);
            void setAngularDamping(const f32 damping);
            void setStaticFriction(const f32 friction);
            void setKineticFriction(const f32 friction);
            void setRestitution(const f32 restitution);
        private:
            nPhysics::InertiaTensor mInertiaTensor;  // offset: 0x0
            nPhysics::SHAPES mShapes;  // offset: 0x110
            MtVector3 mPosition;  // offset: 0x2a0
            MtQuaternion mRotation;  // offset: 0x2b0
            MtVector3 mLinearVelocity;  // offset: 0x2c0
            MtVector3 mAngularVelocity;  // offset: 0x2d0
            nPhysics::Mass mMass;  // offset: 0x2e0
            u32 mStatus;  // offset: 0x2f0
            f32 mMaxRadianPerStep;  // offset: 0x2f4
            f32 mMaxLinearVelocity;  // offset: 0x2f8
            f32 mMaxAngularVelocity;  // offset: 0x2fc
            f32 mLinearDamping;  // offset: 0x300
            f32 mAngularDamping;  // offset: 0x304
            f32 mStaticFriction;  // offset: 0x308
            f32 mKineticFriction;  // offset: 0x30c
            f32 mRestitution;  // offset: 0x310
        };
    public:
        static MtDTI* getMyDTIPtr();
        static void usage();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        RigidBody();
        virtual ~RigidBody();
        MtVector3 getPosition() const;
        void setPosition(const MtVector3& position);
        MtQuaternion getRotation() const;
        void setRotation(const MtQuaternion& rotation);
        MtVector3 getLinearVelocity() const;
        void setLinearVelocity(const MtVector3& velocity);
        MtVector3 getAngularVelocity() const;
        void setAngularVelocity(const MtVector3& velocity);
        void setPosture(const MtVector3& position, const MtQuaternion& rotation, const MtVector3& linear_velocity, const MtVector3& angular_velocity);
        u32 getCollisionGroup() const;
        u32 getCollisionID() const;
        u32 getCollisionBit() const;
        u32 getCollisionPrimaryFilter() const;
        u32 getCollisionPrimaryAttribute() const;
        u32 getCollisionSecondaryFilter() const;
        u32 getCollisionSecondaryAttribute() const;
        u32 getScrollType() const;
        u32 getScrollFilter() const;
        f32 getMaxLinearVelocity() const;
        f32 getMaxAngularVelocity() const;
        f32 getLinearDamping() const;
        f32 getAngularDamping() const;
        f32 getStaticFriction() const;
        f32 getKineticFriction() const;
        f32 getRestitution() const;
        f32 getMass() const;
        f32 getInverseMass() const;
        MtMatrix getInertiaTensor() const;
        s32 getLayer() const;
        u32 getID() const;
        void setCollisionGroup(const u32 group);
        void setCollisionID(const u32 id);
        void setCollisionBit(const u32 bit);
        void setCollisionPrimaryFilter(const u32 filter);
        void setCollisionPrimaryAttribute(const u32 attribute);
        void setCollisionSecondaryFilter(const u32 filter);
        void setCollisionSecondaryAttribute(const u32 attribute);
        void setScrollType(const u32 type);
        void setScrollFilter(const u32 filter);
        void setMaxLinearVelocity(const f32);
        void setMaxAngularVelocity(const f32);
        void setLinearDamping(const f32 damping);
        void setAngularDamping(const f32 damping);
        void setStaticFriction(const f32 friction);
        void setKineticFriction(const f32 friction);
        void setRestitution(const f32 restitution);
        void setMass(const f32 mass);
        void setInverseMass(const f32 inverse_mass);
        void setInertiaTensor(const MtMatrix&);
        void setLayer(const s32);
        void setStatusListener(nPhysics::Listener::Status*);
        void setCollisionListener(nPhysics::Listener::Collision* listener);
        void setStatusListener(MtObject*);
        void setSleepEvent(nPhysics::Event::STATUS_FUNCTION);
        void setWakeupEvent(nPhysics::Event::STATUS_FUNCTION);
        void setCollisionListener(MtObject*);
        void setCollideEvent(nPhysics::Event::COLLIDE_FUNCTION);
        void setContactEvent(nPhysics::Event::CONTACT_FUNCTION);
        void setSeparateEvent(nPhysics::Event::SEPARATE_FUNCTION);
    private:
        void setPositionPrivate(const MtVector3& position);
        void setRotationPrivate(const MtQuaternion& rotation);
        void setLinearVelocityPrivate(const MtVector3& velocity);
        void setAngularVelocityPrivate(const MtVector3& velocity);
        void addForcePrivate(const MtVector4& force);
        void addTorquePrivate(const MtVector4& torque);
        void sleepSystem();
        void wakeupSystem();
    public:
        void addForce(const MtVector3& force, const f32 time);
        void addForce(const MtVector3& force, const MtVector3& position, const f32 time);
        void addTorque(const MtVector3& torque, const f32 time);
        MtVector3 getVelocityOfPosition(const MtVector3& position) const;
        void initialize(const INITIALIZER& initializer);
        void calculateInertiaTensor();
    private:
        void begin();
        void move();
        void end();
        void clear();
        void clearVelocity();
        void setStatus(const u32);
    public:
        void setUserData(const uintptr);
        uintptr getUserData() const;
        u32 getStatus() const;
        void addState(const u32 state);
        void removeState(const u32 state);
        bool checkState(const u32 state) const;
        bool isSleep() const;
        bool isDisable() const;
        bool isOutsideArea() const;
        void sleep();
        void wakeup();
        void destroy();
        void enable();
        void disable();
        void fix();
        void unfix();
        bool isFixed() const;
        bool isAggressiveSleep() const;
        bool isTouchGround() const;
        bool isKeyFrame() const;
        void enableKeyFrame();
        void disableKeyFrame();
        bool find(const MtLineSegment& segment, MtContact* contact) const;
        bool find(const MtSphere& sphere, MtContact* contact) const;
    private:
        void setID(const u32 id);
    private:
        u32 mID;  // offset: 0x8
        nPhysics::CURRENT_RIGID_BODY_DATA* mCurrentData;  // offset: 0x10
        nPhysics::RIGID_BODY_DATA* mPreviousData;  // offset: 0x18
        nPhysics::RIGID_BODY_DATA* mNextData;  // offset: 0x20
        nPhysics::RIGID_BODY_DATA* mInterpolationData;  // offset: 0x28
        nPhysics::SHAPES* mShapes;  // offset: 0x30
        nPhysics::SHAPES* mTransformedShapes;  // offset: 0x38
        nPhysics::POWER* mPower;  // offset: 0x40
        nPhysics::RIGID_BODY_INFORMATION* mInformation;  // offset: 0x48
        nPhysics::RIGID_BODY_STATUS* mStatus;  // offset: 0x50
        nPhysics::COLLISION_INFORMATION* mCollisionInformation;  // offset: 0x58
        nPhysics::Listener::Status* mStatusListener2;  // offset: 0x60
        nPhysics::Listener::Collision* mCollisionListener2;  // offset: 0x68
        MtObject* mCollisionListener;  // offset: 0x70
        nPhysics::Event::COLLIDE_FUNCTION mCollideFunction;  // offset: 0x78
        nPhysics::Event::CONTACT_FUNCTION mContactFunction;  // offset: 0x88
        nPhysics::Event::SEPARATE_FUNCTION mSeparateFunction;  // offset: 0x98
        MtObject* mStatusListener;  // offset: 0xa8
        nPhysics::Event::STATUS_FUNCTION mSleepFunction;  // offset: 0xb0
        nPhysics::Event::STATUS_FUNCTION mWakeupFunction;  // offset: 0xc0
        uintptr mUserData;  // offset: 0xd0
        MtFloat3x3 mInertiaTensor;  // offset: 0xd8
        f32 mOriginalMass;  // offset: 0xfc
        f32 mMass;  // offset: 0x100
    public:
        nPhysics::ListComponent<nPhysics::RigidBody, 4> mListComponent;  // offset: 0x108
    private:
        static const u32 MAX_STATUS_STACK = 10;
        static const u32 MAX_VELOCITY_STACK = 10;
        static const u32 MAX_FORCE_STACK = 10;
        static const u32 MAX_TORQUE_STACK = 10;
        static const u32 MAX_CALLBACK_STACK = 16;
        static const u32 INVALID_LAYER_ID = 4294967295;
        static const u32 GROUND_LAYER_ID = 10000;
    public:
        static MyDTI DTI;
    };
}  // namespace nPhysics

inline void* nPhysics::RigidBody::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void nPhysics::RigidBody::setCollisionListener(nPhysics::Listener::Collision* listener) {
    this->mCollisionListener2 = listener;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nPhysics::RigidBody::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nPhysics::RigidBody::DTI)->memFree(p_addr);
}
