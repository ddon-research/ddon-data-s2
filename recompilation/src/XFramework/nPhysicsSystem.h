#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtEaseCurve.h"
#include "../MT/MtMath.h"
#include "../MT/MtSynchronize.h"
#include "cSystem.h"
#include "nPhysicsBarrier.h"
#include "nPhysicsCallback.h"
#include "nPhysicsConstraintObject.h"
#include "nPhysicsIDArray.h"
#include "nPhysicsIsland.h"
#include "nPhysicsList.h"
#include "nPhysicsLockFreePipe.h"
#include "nPhysicsPhantom.h"
#include "nPhysicsRigidBody.h"
#include "nPhysicsSPU.h"
#include "nPhysicsStackMemory.h"
#include "sCollision.h"

// Forward declarations
class MtAllocator;
class MtArray;
struct MtContact;
class MtCriticalSection;
class MtDTI;
class MtHermiteCurve;
class MtLineSegment;
class MtObject;
class MtSphere;
class MtVector3;
struct _SceKernelEventFlag;
class csSoundPhysicsRigidBody;
namespace nPhysics { class Barrier; }
namespace nPhysics { struct COLLISION_INFORMATION; }
namespace nPhysics { struct CONSTRAINT; }
namespace nPhysics { struct CONSTRAINT_HEADER; }
namespace nPhysics { struct CONTACT_INFO; }
namespace nPhysics { class CONTACT_PAIR; }
namespace nPhysics { struct CURRENT_RIGID_BODY_DATA; }
namespace nPhysics { class Callback; }
namespace nPhysics { namespace Constraint { class Object; } }
namespace nPhysics { class ID_ARRAY; }
namespace nPhysics { struct INITIALIZE_PARAMETER; }
namespace nPhysics { class ISLAND; }
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
namespace nPhysics { struct MATERIAL; }
namespace nPhysics { class Material; }
namespace nPhysics { namespace Math { class Vector3; } }
namespace nPhysics { class POWER; }
namespace nPhysics { class Phantom; }
namespace nPhysics { struct RIGID_BODY_DATA; }
namespace nPhysics { struct RIGID_BODY_INFORMATION; }
namespace nPhysics { struct RIGID_BODY_LINK; }
namespace nPhysics { struct RIGID_BODY_STATUS; }
namespace nPhysics { class RigidBody; }
namespace nPhysics { class SHAPES; }
namespace nPhysics { class SORTED_PAIR; }
namespace nPhysics { class SORT_DATA; }
namespace nPhysics { class StackMemory; }
struct pthread;
class rSoundPhysicsList;
class uCoord;

// Declarations
namespace nPhysics { class System; }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_MFUNC = void(MtObject::*)();
using u32 = unsigned int;
using MT_MFUNC32 = void(MtObject::*)(u32);
using SceKernelEventFlag = _SceKernelEventFlag*;
using pthread_t = pthread*;
using ScePthread = pthread_t;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using __uintptr_t = __uint64_t;
using f32 = float;
namespace nPhysics { using GET_MATERIAL_ID = u32(*)(const sCollision::SbcInfo&); }
using s32 = int;
namespace nPhysics { using IS_VALID_MATERIAL_ID = bool(*)(const s32); }
using s8 = signed char;
using size_t = _Sizet;
using u8 = unsigned char;
using uintptr = __uintptr_t;

namespace nPhysics {
    class System : public ::cSystem
    {
        friend class nPhysics::Constraint::Object;
        friend class nPhysics::RigidBody;
    public:
        class MyDTI;
        struct THREAD_INFO;
    public:
        class MyDTI : public ::MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct THREAD_INFO
        {
        public:
            u32 Index;  // offset: 0x0
            MT_MFUNC32 Function;  // offset: 0x8
            ScePthread ID;  // offset: 0x18
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
        System(const nPhysics::INITIALIZE_PARAMETER& parameter);
        virtual ~System();
        virtual void reset();  // vtable slot 6
        void setup();
        void synchronize();
        void begin();
        void end();
        virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 9
        void setCollisionType(const u32);
        u32 getCollisionType();
        nPhysics::RigidBody* createRigidBody();
        void removeRigidBody(nPhysics::RigidBody* rigid_body);
        nPhysics::Constraint::Object* createConstraint(const MtDTI& dti);
        void removeConstraint(nPhysics::Constraint::Object* constraint);
        nPhysics::RigidBody* getRigidBodyFromIndex(const u32 index);
        nPhysics::RigidBody* getRigidBodyFromID(const u32 id);
        void addPhantom(nPhysics::Phantom* phantom);
        void removePhantom(nPhysics::Phantom* phantom);
    private:
        void simulation(f32 delta_time);
        void step();
        void disable_rigid_body(nPhysics::RigidBody* rigid_body);
        void enable_rigid_body(nPhysics::RigidBody* rigid_body);
        nPhysics::CONSTRAINT* create_constraint_instance();
        void remove_constraint_instance(nPhysics::CONSTRAINT* constraint);
        void create_thread();
        void destroy_thread();
        void sync_rigid_body();
        void setup_rigid_body();
        void calculate_variance();
        void quantize_aabb();
        void detect_phantom_pair();
        void detect_pair();
        void detect_collision_with_scroll();
        void merge_pair();
        void detect_collision_pair();
        void split_constraint();
        void calculate_island();
        void solve_constraint();
        void update_rigid_body();
    public:
        s32 getRigidBodyLayer(const u32 id);
    private:
        void resetRigidBodyNoLock();
        void resetConstraintNoLock();
    public:
        void resetRigidBody();
        void resetConstraint();
        static nPhysics::System* getInstance();
        void setGravity(const MtVector3& gravity);
        void setStepGravity(const MtVector3&);
        void setStepPerSecond(const s32);
        void setIntegrationEpsilon(const f32);
        void setInertiaTensorScale(const f32);
        void setLinearExtraDampingRange(const f32);
        void setLinearExtraDampingRange2(const f32);
        void setAngularExtraDampingRange(const f32);
        void setAngularExtraDampingRange2(const f32);
        void setLinearExtraDamping(const f32 damping);
        void setAngularExtraDamping(const f32 damping);
        void setLinearSleepRange(const f32 range);
        void setLinearSleepRange2(const f32);
        void setAngularSleepRange(const f32 range);
        void setAngularSleepRange2(const f32);
        void setSleepStartCount(const s32);
        void setWakeupVelocity(const f32);
        void setWakeupVelocity2(const f32);
        void setStaticlimit(const f32);
        void setStaticlimit2(const f32);
        void setAmplifyCoefficient(const f32 coefficient);
        void setCollisionMargin(const f32 margin);
        f32 getCollisionMargin() const;
        void setWorldCenter(const MtVector3& center);
        MtVector3 getWorldCenter() const;
        void setWorldExtent(const MtVector3& extent);
        MtVector3 getWorldExtent() const;
        void setNumUseTask(const u32 num);
    private:
        void sortSPU(nPhysics::SORT_DATA* data, const u32 num_data, MT_CTSTR name);
        void sync_rigid_body_function(const u32 index);
        void setup_rigid_body_function(const u32 index);
        void calculate_variance_function(const u32 index);
        void quantize_aabb_function(const u32 index);
        void detect_phantom_pair_function(const u32 index);
        void detect_pair_function(const u32 index);
        void detect_collision_with_scroll_function(const u32 index);
        void merge_pair_function(const u32 index);
        void detect_collision_pair_function(const u32 index);
        void split_constraint_function(const u32 index);
        void calculate_island_function(const u32);
        void solve_constraint_function(const u32 index);
        void update_rigid_body_function(const u32 index);
        void callback_collision(const u32);
        void callback_step_end(const u32);
    public:
        void setPause(const bool pause);
        bool isPause();
        void resetTime();
        MtVector3 getGravity();
        MtVector3 getStepGravity();
        s32 getStepPerSecond();
        f32 getRealStepPerSecond();
        f32 getStepTime();
        f32 getInterpolationTime();
        f32 getIntegrationEpsilon();
        f32 getInertiaTensorScale();
        f32 getContactLimit();
        f32 getContactPower();
        f32 getAmplifyCoefficient();
        const MtVector3& getInverseAmplifyCoefficient();
        const MtVector3& getQuantizationOffset();
        const MtVector3& getQuantizationScale();
        u32 getMaxRigidBody() const;
        u32 getMaxContactPair() const;
        u32 getMaxGeometry() const;
        u32 getMaxConstraint() const;
        f32 getBallJointPower() const;
        f32 getBallJointDamper() const;
        f32 getSwingLimitPower() const;
        f32 getTwistLimitPower() const;
        f32 getDistancePower() const;
        f32 getHingePower() const;
        f32 getAxisPower() const;
        f32 getMotorPower() const;
        f32 getSpringPower() const;
        f32 getGyroPower() const;
        f32 getMotionPower() const;
        f32 getLimitTorque() const;
        f32 getEpsilon() const;
        f32 getOmega() const;
        u32 getMaxLoop() const;
        f32 getLinearExtraDampingRange() const;
        f32 getLinearExtraDampingRange2() const;
        f32 getAngularExtraDampingRange() const;
        f32 getAngularExtraDampingRange2() const;
        f32 getLinearExtraDamping() const;
        f32 getAngularExtraDamping() const;
        f32 getLinearSleepRange() const;
        f32 getLinearSleepRange2() const;
        f32 getAngularSleepRange() const;
        f32 getAngularSleepRange2() const;
        s32 getSleepStartCount() const;
        f32 getWakeupVelocity() const;
        f32 getWakeupVelocity2() const;
        f32 getStaticLimit() const;
        f32 getStaticLimit2() const;
        f32 getWakeupPosition() const;
        f32 getWakeupRotation() const;
        f32 getNormalSeparateLimit() const;
        f32 getTangentSeparateLimit() const;
        f32 getDistanceSeparateLimit() const;
        f32 getContactTolerance() const;
        u32 getSystemTimer();
        u32 getElapsedTime(const u32);
        void setMaterial(const u32 index, const nPhysics::Material& material);
        const nPhysics::Material& getMaterial(const u32 index) const;
        bool findNearestRigidBody(const MtLineSegment& line, nPhysics::RigidBody* & output_rigid_body, MtContact& output_contact);
        u32 findRigidBody(const MtLineSegment& line, const u32 array_count, nPhysics::RigidBody* * output_rigid_body, MtContact* output_contact);
        bool findNearestRigidBody(const MtSphere& sphere, nPhysics::RigidBody* & output_rigid_body, MtContact& output_contact);
        u32 findRigidBody(const MtSphere& sphere, const u32 array_count, nPhysics::RigidBody* * output_rigid_body, MtContact* output_contact);
        void lockSystem();
        void unlockSystem();
        void lockCreateEntity();
        void unlockCreateEntity();
        u32 getMaterialID(const sCollision::SbcInfo& sbc_info);
        void setFunctionGetMaterialID(nPhysics::GET_MATERIAL_ID get_material_id);
        void addStepEndCallback(MtObject* object, MT_MFUNC function);
        void removeStepEndCallback(MtObject* object, MT_MFUNC function);
        nPhysics::CURRENT_RIGID_BODY_DATA* getCurrentRigidBodyData(const u32 id);
        nPhysics::RIGID_BODY_DATA* getPreviousRigidBodyData(const u32 id);
        nPhysics::RIGID_BODY_DATA* getNextRigidBodyData(const u32 id);
        nPhysics::RIGID_BODY_DATA* getInterpolationRigidBodyData(const u32 id);
        nPhysics::SHAPES* getRigidBodyShapes(const u32 id);
        nPhysics::SHAPES* getTransformedRigidBodyShapes(const u32 id);
        nPhysics::POWER* getRigidBodyPower(const u32 id);
        nPhysics::RIGID_BODY_INFORMATION* getRigidBodyInformation(const u32 id);
        nPhysics::RIGID_BODY_STATUS* getRigidBodyStatus(const u32 id);
        nPhysics::COLLISION_INFORMATION* getCollisionInformation(const u32 id);
        nPhysics::CONSTRAINT_HEADER* getConstraintHeader(const u32 id);
        u32 getConstraintID(nPhysics::CONSTRAINT* constraint);
        const nPhysics::RIGID_BODY_LINK& getRigidBodyLink(const u32);
        u32 getNumRigidBodyLink(const u32);
        const nPhysics::RIGID_BODY_LINK& getNextRigidBodyLink(const u32 id);
        u32 getNumNextRigidBodyLink(const u32 id);
        const nPhysics::CONTACT_PAIR& getContactPair(const u32 id);
    private:
        static void* MainThreadFunction(void* parameter);
        static void* JobThreadFunction(void* parameter);
        void main_thread_function();
        void job_thread_function(THREAD_INFO& thread_info);
        void execute_same_job(MT_MFUNC32 function, u32 num_job);
        void execute_different_job(MT_MFUNC32* function, u32 num_job);
        void send_command(const void* command, const u32 size);
        void receive_command(const u32 thread_id);
        void setNumRigidBody(const u32);
        void setNumConstraint(const u32);
        u32 collide_vs_scroll(const sCollision::SbcInfo& sbc_info, uintptr parameter, u32 hit_convex_index);
        nPhysics::CONTACT_INFO* get_scroll_contact_info(const u32 rigid_body_id);
    public:
        u32 getNumRigidBody();
        u32 getNumConstraint();
    private:
        rSoundPhysicsList* get_ground_sound_resource();
    public:
        void clearGroundSoundResource();
        void setGroundSoundResource(rSoundPhysicsList* resource);
        void requestGroundSound(s32 self_material_no, s32 target_material_no, const u32 contact_keep_count, f32 normal_force, f32 slide_speed, f32 roll_speed, uCoord* coord, s32 joint_no, u32 id);
        void setCheckMaterialIDFunction(nPhysics::IS_VALID_MATERIAL_ID);
        void update_max_linear_velocity_of_rigid_body(const nPhysics::Math::Vector3& velocity);
        void update_max_angular_velocity_of_rigid_body(const nPhysics::Math::Vector3& velocity);
    private:
        static void* memAlloc(size_t size, u32 alignment);
        static void memFree(void* address);
    protected:
        nPhysics::RigidBody* mRigidBodyInstance;  // offset: 0x18
        nPhysics::CURRENT_RIGID_BODY_DATA* mCurrentRigidBodyData;  // offset: 0x20
        nPhysics::RIGID_BODY_DATA* mPreservedRigidBodyData;  // offset: 0x28
        nPhysics::RIGID_BODY_DATA* mInterpolationRigidBodyData;  // offset: 0x30
        nPhysics::SHAPES* mRigidBodyShapes;  // offset: 0x38
        nPhysics::SHAPES* mTransformedRigidBodyShapes;  // offset: 0x40
        nPhysics::POWER* mRigidBodyPower;  // offset: 0x48
        nPhysics::RIGID_BODY_INFORMATION* mRigidBodyInformation;  // offset: 0x50
        nPhysics::RIGID_BODY_STATUS* mRigidBodyStatus;  // offset: 0x58
        nPhysics::COLLISION_INFORMATION* mCollisionInformation;  // offset: 0x60
        nPhysics::RIGID_BODY_LINK* mRigidBodyLink;  // offset: 0x68
        u8* mNumRigidBodyLink;  // offset: 0x70
        nPhysics::RIGID_BODY_LINK* mCurrentRigidBodyLink;  // offset: 0x78
        nPhysics::RIGID_BODY_LINK* mNextRigidBodyLink;  // offset: 0x80
        u8* mNumCurrentRigidBodyLink;  // offset: 0x88
        u8* mNumNextRigidBodyLink;  // offset: 0x90
        nPhysics::CONSTRAINT_HEADER* mConstraintHeader;  // offset: 0x98
        nPhysics::CONSTRAINT* mConstraint;  // offset: 0xa0
        nPhysics::SORTED_PAIR* mSortedContactPair;  // offset: 0xa8
        nPhysics::SORTED_PAIR* mTemporaryContactPair;  // offset: 0xb0
        nPhysics::SORTED_PAIR* mDisableContactPair;  // offset: 0xb8
        u32* mIslandIndexOfRigidBody;  // offset: 0xc0
        u32 mNumIsland;  // offset: 0xc8
        alignas(8) nPhysics::ISLAND mIsland[256];  // offset: 0xd0
        nPhysics::ISLAND* mTemporaryIsland;  // offset: 0x10d0
        u32* mMergeIslandTable;  // offset: 0x10d8
        u32* mIslandIndexTable;  // offset: 0x10e0
        u32* mCurrentIslandHash;  // offset: 0x10e8
        u32 mIslandStatus[3][256];  // offset: 0x10f0
        nPhysics::StackMemory mStackMemory;  // offset: 0x1cf0
        nPhysics::ID_ARRAY mRigidBodyID;  // offset: 0x1d18
        nPhysics::ID_ARRAY mConstraintID;  // offset: 0x1d48
        u32 mNumProcessRigidBody;  // offset: 0x1d78
        u32* mProcessRigidBodyID;  // offset: 0x1d80
        u32 mNumProcessPhantom;  // offset: 0x1d88
        u32* mNumBlockPerPhase;  // offset: 0x1d90
        u32* mGroundLayerRigidBodyID;  // offset: 0x1d98
        u32 mNumGroundLayerRigidBody;  // offset: 0x1da0
        s8* mRigidBodyLayer;  // offset: 0x1da8
        nPhysics::CONTACT_PAIR* mContactPair;  // offset: 0x1db0
        u32 mNumContactPair;  // offset: 0x1db8
        u32 mMaxRigidBody;  // offset: 0x1dbc
        u32 mMaxContactPair;  // offset: 0x1dc0
        u32 mMaxGeometry;  // offset: 0x1dc4
        u32 mMaxConstraint;  // offset: 0x1dc8
        u32 mMaxMaterial;  // offset: 0x1dcc
        nPhysics::List<nPhysics::RigidBody, 1> mRigidBodyEnableList[6];  // offset: 0x1dd0
        nPhysics::List<nPhysics::RigidBody, 2> mRigidBodyDisableList[6];  // offset: 0x1e90
        nPhysics::List<nPhysics::RigidBody, 3> mRigidBodyDeleteList[6];  // offset: 0x1f50
        nPhysics::List<nPhysics::Constraint::Object, 3> mConstraintDeleteList[6];  // offset: 0x2010
        nPhysics::List<nPhysics::RigidBody, 0> mRigidBodyList;  // offset: 0x20d0
        nPhysics::List<nPhysics::Constraint::Object, 0> mConstraintList;  // offset: 0x20f0
        nPhysics::List<nPhysics::Phantom, 0> mPhantomList;  // offset: 0x2110
        nPhysics::List<nPhysics::Phantom, 0> mPhantomAddList[6];  // offset: 0x2130
        nPhysics::List<nPhysics::Phantom, 1> mPhantomRemoveList[6];  // offset: 0x21f0
        f32 mInertiaTensorScale;  // offset: 0x22b0
        f32 mAmplifyCoefficient;  // offset: 0x22b4
        f32 mCollisionMargin;  // offset: 0x22b8
        MtVector3 mGravity;  // offset: 0x22c0
        MtVector3 mStepGravity;  // offset: 0x22d0
        MtVector3 mInverseAmplifyCoefficient;  // offset: 0x22e0
        MtVector3 mQuantizationOffset;  // offset: 0x22f0
        MtVector3 mQuantizationScale;  // offset: 0x2300
        MtHermiteCurve mElasticFrictionCurve;  // offset: 0x2310
        f32 mContactLimit;  // offset: 0x2350
        f32 mContactPower;  // offset: 0x2354
        f32 mBallJointPower;  // offset: 0x2358
        f32 mBallJointDamper;  // offset: 0x235c
        f32 mSwingLimitPower;  // offset: 0x2360
        f32 mTwistLimitPower;  // offset: 0x2364
        f32 mDistancePower;  // offset: 0x2368
        f32 mHingePower;  // offset: 0x236c
        f32 mAxisPower;  // offset: 0x2370
        f32 mMotorPower;  // offset: 0x2374
        f32 mSpringPower;  // offset: 0x2378
        f32 mGyroPower;  // offset: 0x237c
        f32 mMotionPower;  // offset: 0x2380
        f32 mNormalSeparateLimit;  // offset: 0x2384
        f32 mTangentSeparateLimit;  // offset: 0x2388
        f32 mDistanceSeparateLimit;  // offset: 0x238c
        f32 mContactTolerance;  // offset: 0x2390
        f32 mLimitTorque;  // offset: 0x2394
        f32 mOmega;  // offset: 0x2398
        f32 mEpsilon;  // offset: 0x239c
        u32 mMaxLoop;  // offset: 0x23a0
        bool mPause;  // offset: 0x23a4
        bool mRunningThread;  // offset: 0x23a5
        u32 mSystemTimer;  // offset: 0x23a8
        f32 mCurrentTime;  // offset: 0x23ac
        f32 mNextTime;  // offset: 0x23b0
        f32 mPreviousTime;  // offset: 0x23b4
        f32 mInterpolationTime;  // offset: 0x23b8
        f32 mStepTime;  // offset: 0x23bc
        s32 mStepPerSecond;  // offset: 0x23c0
        f32 mRealStepPerSecond;  // offset: 0x23c4
        f32 mLinearExtraDampingRange2;  // offset: 0x23c8
        f32 mAngularExtraDampingRange2;  // offset: 0x23cc
        f32 mLinearExtraDamping;  // offset: 0x23d0
        f32 mAngularExtraDamping;  // offset: 0x23d4
        f32 mLinearSleepRange2;  // offset: 0x23d8
        f32 mAngularSleepRange2;  // offset: 0x23dc
        u32 mSleepStartCount;  // offset: 0x23e0
        f32 mWakeupPosition;  // offset: 0x23e4
        f32 mWakeupRotation;  // offset: 0x23e8
        f32 mWakeupVelocity2;  // offset: 0x23ec
        f32 mStaticLimit2;  // offset: 0x23f0
        f32 mIntegrationEpsilon;  // offset: 0x23f4
        MtArray mMaterialList;  // offset: 0x23f8
        nPhysics::MATERIAL* mMaterial;  // offset: 0x2418
        nPhysics::GET_MATERIAL_ID mFunctionGetMaterialID;  // offset: 0x2420
    private:
        nPhysics::Callback mStepEnd;  // offset: 0x2428
        u32 mNumUseTask;  // offset: 0x2440
        u32 mNumUseTaskGame;  // offset: 0x2444
        u32 mNumRunTask;  // offset: 0x2448
        SceKernelEventFlag mSyncThreadEventFlag;  // offset: 0x2450
        THREAD_INFO mMainThreadInfo;  // offset: 0x2458
        THREAD_INFO mJobThreadInfo[3];  // offset: 0x2478
        u32 mMaxJobThread;  // offset: 0x24d8
        s32 mJobIndex[3];  // offset: 0x24dc
        bool mExitThread;  // offset: 0x24e8
        nPhysics::LockFreePipe<12> mCommand[6];  // offset: 0x24f0
        MtCriticalSection mCriticalSectionCreateEntity;  // offset: 0x8550
        MtCriticalSection mCriticalSectionCallback;  // offset: 0x8558
        bool mUserLock;  // offset: 0x8560
        u32 mNumRigidBody;  // offset: 0x8564
        u32 mNumConstraint;  // offset: 0x8568
        u32 mMaxVariance;  // offset: 0x856c
        u32 mNumNewPair;  // offset: 0x8570
        u32 mNumDisablePair;  // offset: 0x8574
        nPhysics::Barrier mSyncBarrier;  // offset: 0x8578
        u32 mNumRigidBodyPerTask[3];  // offset: 0x857c
        alignas(16) nPhysics::IoSPU::SYNC_RIGID_BODY mSyncRigidBody[3];  // offset: 0x8590
        nPhysics::IoSPU::SETUP_RIGID_BODY mSetupRigidBody[3];  // offset: 0x86b0
        nPhysics::IoSPU::CALCULATE_VARIANCE mCalculateVariance[3];  // offset: 0x8800
        nPhysics::IoSPU::QUANTIZE_AABB mQuantizeAABB[3];  // offset: 0x8860
        nPhysics::IoSPU::SORT mSort[3];  // offset: 0x8980
        nPhysics::IoSPU::DETECT_PHANTOM_PAIR mDetectPhantomPair[3];  // offset: 0x8aa0
        nPhysics::IoSPU::DETECT_PAIR mDetectPair[3];  // offset: 0x8b90
        nPhysics::IoSPU::DETECT_COLLISION_WITH_SCROLL mDetectCollisionWithScroll[3];  // offset: 0x8c50
        nPhysics::IoSPU::MERGE_PAIR mMergePair[3];  // offset: 0x8dd0
        nPhysics::IoSPU::DETECT_COLLISION_PAIR mDetectCollisionPair[3];  // offset: 0x8ec0
        nPhysics::IoSPU::SPLIT_CONSTRAINT mSplitConstraint;  // offset: 0x9010
        nPhysics::IoSPU::CALCULATE_ISLAND mCalculateIsland;  // offset: 0x90d0
        nPhysics::IoSPU::SOLVE_CONSTRAINT mSolveConstraint[3];  // offset: 0x9120
        nPhysics::IoSPU::UPDATE_RIGID_BODY mUpdateRigidBody[3];  // offset: 0x9480
        rSoundPhysicsList* mGroundSoundResource;  // offset: 0x9600
        csSoundPhysicsRigidBody* mGroundSound;  // offset: 0x9608
        nPhysics::IS_VALID_MATERIAL_ID mCheckMaterialIDFunction;  // offset: 0x9610
    public:
        static MyDTI DTI;
        static const u32 MAX_TRIANGLE_INFO = 100;
        static const u32 MAX_CONTACT_INFO = 100;
        static const u32 HALF_MAX_CONTACT_INFO = 50;
        static const u32 MAX_SYSTEM_TIMER_COUNT = 1048575;
    private:
        static nPhysics::System* mInstance;
    };
}  // namespace nPhysics

inline void* nPhysics::System::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void nPhysics::System::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nPhysics::System::DTI)->memFree(p_addr);
}
