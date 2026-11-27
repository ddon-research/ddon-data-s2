// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <kernel.h>
#include <stdlib.h>
#include "nPhysicsSystem.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDebug.h"
#include "../MT/MtEaseCurve.h"
#include "../MT/MtGeometry3D.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtSynchronize.h"
#include "cResource.h"
#include "cSystem.h"
#include "nPhysicsBarrier.h"
#include "nPhysicsCallback.h"
#include "nPhysicsConstraintObject.h"
#include "nPhysicsIDArray.h"
#include "nPhysicsIsland.h"
#include "nPhysicsList.h"
#include "nPhysicsLockFreePipe.h"
#include "nPhysicsMaterial.h"
#include "nPhysicsPhantom.h"
#include "nPhysicsPower.h"
#include "nPhysicsRigidBody.h"
#include "nPhysicsSPU.h"
#include "nPhysicsShape.h"
#include "nPhysicsShapes.h"
#include "nPhysicsStackMemory.h"
#include "nPhysicsStruct.h"
#include "nPhysicsThread.h"
#include "rCollisionHeightField.h"
#include "sCollision.h"
#include "sMain.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nPhysics::System::getDTI() const {
    return nPhysics::System::DTI;
}

nPhysics::System::System(const nPhysics::INITIALIZE_PARAMETER& parameter) {
    DDON_STUB("nPhysics::System::System")
    /* stub */
}

__attribute__((noinline)) nPhysics::System::~System() {
    DDON_STUB("nPhysics::System::~System")
    /* stub */
}

void nPhysics::System::reset() {
    if (mThreadSafe || (::cSystem::mJobSafe)) {
        if (::scePthreadMutexLock(&mCS.mCSection) != 0) {
            ::abort();
            return;
        }
    }
    mRigidBodyList.mNum = 0;
    mRigidBodyList.mBottom = nullptr;
    mRigidBodyList.mTop = nullptr;
    if (mConstraintList.mTop != nullptr) {
        for (nPhysics::Constraint::Object* v0_5 = mConstraintList.mTop;;) {
            nPhysics::Constraint::Object* t0 = v0_5->mListComponent.mNext[0];
            delete v0_5;
            if (t0 != nullptr) {
                v0_5 = t0;
            } else {
                break;
            }
        }
    }
    mConstraintList.mNum = 0;
    mConstraintList.mBottom = nullptr;
    mConstraintList.mTop = nullptr;
    mRigidBodyDeleteList[0].mNum = 0;
    mRigidBodyDeleteList[0].mBottom = nullptr;
    mRigidBodyDeleteList[0].mTop = nullptr;
    mRigidBodyDisableList[0].mNum = 0;
    mRigidBodyDisableList[0].mBottom = nullptr;
    mRigidBodyDisableList[0].mTop = nullptr;
    mRigidBodyEnableList[0].mNum = 0;
    mRigidBodyEnableList[0].mBottom = nullptr;
    mRigidBodyEnableList[0].mTop = nullptr;
    mConstraintDeleteList[0].mNum = 0;
    mConstraintDeleteList[0].mBottom = nullptr;
    mConstraintDeleteList[0].mTop = nullptr;
    mRigidBodyDeleteList[1].mNum = 0;
    mRigidBodyDeleteList[1].mBottom = nullptr;
    mRigidBodyDeleteList[1].mTop = nullptr;
    mRigidBodyDisableList[1].mNum = 0;
    mRigidBodyDisableList[1].mBottom = nullptr;
    mRigidBodyDisableList[1].mTop = nullptr;
    mRigidBodyEnableList[1].mNum = 0;
    mRigidBodyEnableList[1].mBottom = nullptr;
    mRigidBodyEnableList[1].mTop = nullptr;
    mConstraintDeleteList[1].mNum = 0;
    mConstraintDeleteList[1].mBottom = nullptr;
    mConstraintDeleteList[1].mTop = nullptr;
    mRigidBodyDeleteList[2].mNum = 0;
    mRigidBodyDeleteList[2].mBottom = nullptr;
    mRigidBodyDeleteList[2].mTop = nullptr;
    mRigidBodyDisableList[2].mNum = 0;
    mRigidBodyDisableList[2].mBottom = nullptr;
    mRigidBodyDisableList[2].mTop = nullptr;
    mRigidBodyEnableList[2].mNum = 0;
    mRigidBodyEnableList[2].mBottom = nullptr;
    mRigidBodyEnableList[2].mTop = nullptr;
    mConstraintDeleteList[2].mNum = 0;
    mConstraintDeleteList[2].mBottom = nullptr;
    mConstraintDeleteList[2].mTop = nullptr;
    mRigidBodyDeleteList[3].mNum = 0;
    mRigidBodyDeleteList[3].mBottom = nullptr;
    mRigidBodyDeleteList[3].mTop = nullptr;
    mRigidBodyDisableList[3].mNum = 0;
    mRigidBodyDisableList[3].mBottom = nullptr;
    mRigidBodyDisableList[3].mTop = nullptr;
    mRigidBodyEnableList[3].mNum = 0;
    mRigidBodyEnableList[3].mBottom = nullptr;
    mRigidBodyEnableList[3].mTop = nullptr;
    mConstraintDeleteList[3].mNum = 0;
    mConstraintDeleteList[3].mBottom = nullptr;
    mConstraintDeleteList[3].mTop = nullptr;
    mRigidBodyDeleteList[4].mNum = 0;
    mRigidBodyDeleteList[4].mBottom = nullptr;
    mRigidBodyDeleteList[4].mTop = nullptr;
    mRigidBodyDisableList[4].mNum = 0;
    mRigidBodyDisableList[4].mBottom = nullptr;
    mRigidBodyDisableList[4].mTop = nullptr;
    mRigidBodyEnableList[4].mNum = 0;
    mRigidBodyEnableList[4].mBottom = nullptr;
    mRigidBodyEnableList[4].mTop = nullptr;
    mConstraintDeleteList[4].mNum = 0;
    mConstraintDeleteList[4].mBottom = nullptr;
    mConstraintDeleteList[4].mTop = nullptr;
    mRigidBodyDeleteList[5].mNum = 0;
    mRigidBodyDeleteList[5].mBottom = nullptr;
    mRigidBodyDeleteList[5].mTop = nullptr;
    mRigidBodyDisableList[5].mNum = 0;
    mRigidBodyDisableList[5].mBottom = nullptr;
    mRigidBodyDisableList[5].mTop = nullptr;
    mRigidBodyEnableList[5].mNum = 0;
    mRigidBodyEnableList[5].mBottom = nullptr;
    mRigidBodyEnableList[5].mTop = nullptr;
    mConstraintDeleteList[5].mNum = 0;
    mConstraintDeleteList[5].mBottom = nullptr;
    mConstraintDeleteList[5].mTop = nullptr;
    mRigidBodyID.clear();
    mConstraintID.clear();
    if (mMaxContactPair != 0) {
        nPhysics::SORTED_PAIR* v2_0 = mSortedContactPair;
        nPhysics::SORTED_PAIR* v2_1 = mTemporaryContactPair;
        for (unsigned int i2_2 = 0;;) {
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&v2_0[i2_2]) + 20) = i2_2;
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&v2_1[i2_2]) + 20) = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&v2_0[i2_2]) + 20);
            if ((i2_2 + 1u) < mMaxContactPair) {
                i2_2 += 1u;
            } else {
                break;
            }
        }
    }
    mNumRunTask = 0;
    if (mThreadSafe || (::cSystem::mJobSafe)) {
        if (::scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            ::abort();
            return;
        }
    }
}

__attribute__((weak)) void nPhysics::System::setup() {
    DDON_STUB("nPhysics::System::setup")
    /* stub */
}

void nPhysics::System::begin() {
    if (!mRunningThread) {
        return;
    }
    ::sceKernelSetEventFlag(mSyncThreadEventFlag, 1ul);
}

void nPhysics::System::end() {
    bool t0 = mRunningThread;
    if (!t0) {
        return;
    }
    SceKernelEventFlag t1 = mSyncThreadEventFlag;
    ::sceKernelWaitEventFlag(t1, 0x100000000ul, 33u, static_cast<uint64_t*>(nullptr), static_cast<SceKernelUseconds*>(nullptr));
    u8* t3 = mNumCurrentRigidBodyLink;
    u8* t4 = mNumNextRigidBodyLink;
    mNumNextRigidBodyLink = t3;
    mNumCurrentRigidBodyLink = t4;
    nPhysics::RIGID_BODY_LINK* t5 = mCurrentRigidBodyLink;
    nPhysics::RIGID_BODY_LINK* t6 = mNextRigidBodyLink;
    mNextRigidBodyLink = t5;
    mCurrentRigidBodyLink = t6;
}

__attribute__((weak)) void nPhysics::System::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("nPhysics::System::applyWorldOffset")
    /* stub */
}

nPhysics::RigidBody* nPhysics::System::createRigidBody() {
    const u32 instance_index = mRigidBodyID.create();
    if (instance_index != 0xFFFFFFFFu) {
        nPhysics::RigidBody* t0 = mRigidBodyInstance;
        mRigidBodyList.mNum = mRigidBodyList.mNum + 1;
        if (mRigidBodyList.mTop != nullptr) {
            mRigidBodyList.mBottom->mListComponent.mNext[0] = &t0[instance_index];
            t0[instance_index].mListComponent.mPrevious[0] = mRigidBodyList.mBottom;
            t0[instance_index].mListComponent.mNext[0] = nullptr;
            mRigidBodyList.mBottom = &t0[instance_index];
        } else {
            mRigidBodyList.mTop = &t0[instance_index];
            mRigidBodyList.mBottom = mRigidBodyList.mTop;
            t0[instance_index].mListComponent.mNext[0] = nullptr;
            mRigidBodyList.mTop->mListComponent.mPrevious[0] = nullptr;
        }
        t0[instance_index].clear();
        return &t0[instance_index];
    } else {
        return nullptr;
    }
}

void nPhysics::System::removeRigidBody(nPhysics::RigidBody* rigid_body) {
    if (rigid_body == nullptr) {
        return;
    }
    u32 t0 = (::sMain::mpInstance)->::sMain::getJobThreadIndex();
    mRigidBodyDeleteList[t0].mNum = mRigidBodyDeleteList[t0].mNum + 1;
    if (mRigidBodyDeleteList[t0].mTop != nullptr) {
        mRigidBodyDeleteList[t0].mBottom->mListComponent.mNext[3] = rigid_body;
        rigid_body->mListComponent.mPrevious[3] = mRigidBodyDeleteList[t0].mBottom;
        rigid_body->mListComponent.mNext[3] = nullptr;
        mRigidBodyDeleteList[t0].mBottom = rigid_body;
    } else {
        mRigidBodyDeleteList[t0].mTop = rigid_body;
        mRigidBodyDeleteList[t0].mBottom = rigid_body;
        rigid_body->mListComponent.mNext[3] = nullptr;
        mRigidBodyDeleteList[t0].mTop->mListComponent.mPrevious[3] = nullptr;
    }
}

nPhysics::Constraint::Object* nPhysics::System::createConstraint(const MtDTI& dti) {
    nPhysics::Constraint::Object* output = static_cast<nPhysics::Constraint::Object*>(dti.newInstance());
    if (output != nullptr) {
        mConstraintList.mNum = mConstraintList.mNum + 1;
        if (mConstraintList.mTop != nullptr) {
            mConstraintList.mBottom->mListComponent.mNext[0] = output;
            output->mListComponent.mPrevious[0] = mConstraintList.mBottom;
            output->mListComponent.mNext[0] = nullptr;
            mConstraintList.mBottom = output;
            return mConstraintList.mBottom;
        } else {
            mConstraintList.mTop = output;
            mConstraintList.mBottom = mConstraintList.mTop;
            output->mListComponent.mNext[0] = nullptr;
            mConstraintList.mTop->mListComponent.mPrevious[0] = nullptr;
            return output;
        }
    } else {
        return nullptr;
    }
}

void nPhysics::System::removeConstraint(nPhysics::Constraint::Object* constraint) {
    if (constraint == nullptr) {
        return;
    }
    u32 t0 = (::sMain::mpInstance)->::sMain::getJobThreadIndex();
    mConstraintDeleteList[t0].mNum = mConstraintDeleteList[t0].mNum + 1;
    if (mConstraintDeleteList[t0].mTop != nullptr) {
        mConstraintDeleteList[t0].mBottom->mListComponent.mNext[3] = constraint;
        constraint->mListComponent.mPrevious[3] = mConstraintDeleteList[t0].mBottom;
        constraint->mListComponent.mNext[3] = nullptr;
        mConstraintDeleteList[t0].mBottom = constraint;
    } else {
        mConstraintDeleteList[t0].mTop = constraint;
        mConstraintDeleteList[t0].mBottom = constraint;
        constraint->mListComponent.mNext[3] = nullptr;
        mConstraintDeleteList[t0].mTop->mListComponent.mPrevious[3] = nullptr;
    }
}

nPhysics::RigidBody* nPhysics::System::getRigidBodyFromID(const u32 id) {
    return &mRigidBodyInstance[id];
}

__attribute__((weak)) void nPhysics::System::simulation(f32 delta_time) {
    DDON_STUB("nPhysics::System::simulation")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::step() {
    DDON_STUB("nPhysics::System::step")
    /* stub */
}

void nPhysics::System::disable_rigid_body(nPhysics::RigidBody* rigid_body) {
    u32 t0 = (::sMain::mpInstance)->::sMain::getJobThreadIndex();
    mRigidBodyDisableList[t0].mNum = mRigidBodyDisableList[t0].mNum + 1;
    if (mRigidBodyDisableList[t0].mTop != nullptr) {
        mRigidBodyDisableList[t0].mBottom->mListComponent.mNext[2] = rigid_body;
        rigid_body->mListComponent.mPrevious[2] = mRigidBodyDisableList[t0].mBottom;
        rigid_body->mListComponent.mNext[2] = nullptr;
        mRigidBodyDisableList[t0].mBottom = rigid_body;
    } else {
        mRigidBodyDisableList[t0].mTop = rigid_body;
        mRigidBodyDisableList[t0].mBottom = rigid_body;
        rigid_body->mListComponent.mNext[2] = nullptr;
        mRigidBodyDisableList[t0].mTop->mListComponent.mPrevious[2] = nullptr;
    }
}

void nPhysics::System::enable_rigid_body(nPhysics::RigidBody* rigid_body) {
    u32 t0 = (::sMain::mpInstance)->::sMain::getJobThreadIndex();
    mRigidBodyEnableList[t0].mNum = mRigidBodyEnableList[t0].mNum + 1;
    if (mRigidBodyEnableList[t0].mTop != nullptr) {
        mRigidBodyEnableList[t0].mBottom->mListComponent.mNext[1] = rigid_body;
        rigid_body->mListComponent.mPrevious[1] = mRigidBodyEnableList[t0].mBottom;
        rigid_body->mListComponent.mNext[1] = nullptr;
        mRigidBodyEnableList[t0].mBottom = rigid_body;
    } else {
        mRigidBodyEnableList[t0].mTop = rigid_body;
        mRigidBodyEnableList[t0].mBottom = rigid_body;
        rigid_body->mListComponent.mNext[1] = nullptr;
        mRigidBodyEnableList[t0].mTop->mListComponent.mPrevious[1] = nullptr;
    }
}

nPhysics::CONSTRAINT* nPhysics::System::create_constraint_instance() {
    nPhysics::CONSTRAINT_HEADER* t0 = mConstraintHeader;
    u32 t1 = mConstraintID.mNumValidID;
    const u32 id = mConstraintID.create();
    if (id != 0xFFFFFFFFu) {
        t0[t1].RigidBodyID1 = 0;
        t0[t1].RigidBodyID2 = 0;
        t0[t1].NumConstraint = 0;
        t0[t1].Type = 0;
        t0[t1].Status = 0;
        t0[t1].ID = id;
        return &mConstraint[id];
    } else {
        return nullptr;
    }
}

__attribute__((weak)) void nPhysics::System::remove_constraint_instance(nPhysics::CONSTRAINT* constraint) {
    DDON_STUB("nPhysics::System::remove_constraint_instance")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::create_thread() {
    DDON_STUB("nPhysics::System::create_thread")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::destroy_thread() {
    DDON_STUB("nPhysics::System::destroy_thread")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::sync_rigid_body() {
    DDON_STUB("nPhysics::System::sync_rigid_body")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::setup_rigid_body() {
    DDON_STUB("nPhysics::System::setup_rigid_body")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::calculate_variance() {
    DDON_STUB("nPhysics::System::calculate_variance")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::quantize_aabb() {
    DDON_STUB("nPhysics::System::quantize_aabb")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::detect_phantom_pair() {
    DDON_STUB("nPhysics::System::detect_phantom_pair")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::detect_pair() {
    DDON_STUB("nPhysics::System::detect_pair")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::detect_collision_with_scroll() {
    DDON_STUB("nPhysics::System::detect_collision_with_scroll")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::merge_pair() {
    DDON_STUB("nPhysics::System::merge_pair")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::detect_collision_pair() {
    DDON_STUB("nPhysics::System::detect_collision_pair")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::split_constraint() {
    DDON_STUB("nPhysics::System::split_constraint")
    /* stub */
}

void nPhysics::System::calculate_island() {
    mCalculateIsland.AddressPair = mSortedContactPair;
    mCalculateIsland.NumPair = mNumContactPair;
    mCalculateIsland.AddressConstraintHeader = mConstraintHeader;
    mCalculateIsland.NumConstraint = mNumConstraint;
    mCalculateIsland.MaxRigidBody = mMaxRigidBody;
    mCalculateIsland.MaxMaterial = mMaxMaterial;
    mCalculateIsland.NumRigidBody = mNumProcessRigidBody;
    mCalculateIsland.AddressRigidBodyID = mProcessRigidBodyID;
    mCalculateIsland.AddressIslandIndexOfRigidBody = mIslandIndexOfRigidBody;
    mCalculateIsland.AddressIsland = &mIsland[0];
    mCalculateIsland.NumIsland = mNumIsland;
    mCalculateIsland.OutputNumIsland = 0;
}

__attribute__((weak)) void nPhysics::System::solve_constraint() {
    DDON_STUB("nPhysics::System::solve_constraint")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::update_rigid_body() {
    DDON_STUB("nPhysics::System::update_rigid_body")
    /* stub */
}

void nPhysics::System::setWorldCenter(const MtVector3& center) {
    mQuantizationOffset.x = center.x;
    mQuantizationOffset.y = center.y;
    mQuantizationOffset.z = center.z;
    mQuantizationOffset.pad_ = 0.0f;
}

__attribute__((weak)) void nPhysics::System::sortSPU(nPhysics::SORT_DATA* data, const u32 num_data, MT_CTSTR name) {
    DDON_STUB("nPhysics::System::sortSPU")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::sync_rigid_body_function(const u32 index) {
    DDON_STUB("nPhysics::System::sync_rigid_body_function")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::setup_rigid_body_function(const u32 index) {
    DDON_STUB("nPhysics::System::setup_rigid_body_function")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::calculate_variance_function(const u32 index) {
    DDON_STUB("nPhysics::System::calculate_variance_function")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::quantize_aabb_function(const u32 index) {
    DDON_STUB("nPhysics::System::quantize_aabb_function")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::detect_phantom_pair_function(const u32 index) {
    DDON_STUB("nPhysics::System::detect_phantom_pair_function")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::detect_pair_function(const u32 index) {
    DDON_STUB("nPhysics::System::detect_pair_function")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::detect_collision_with_scroll_function(const u32 index) {
    DDON_STUB("nPhysics::System::detect_collision_with_scroll_function")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::merge_pair_function(const u32 index) {
    DDON_STUB("nPhysics::System::merge_pair_function")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::detect_collision_pair_function(const u32 index) {
    DDON_STUB("nPhysics::System::detect_collision_pair_function")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::split_constraint_function(const u32 index) {
    DDON_STUB("nPhysics::System::split_constraint_function")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::calculate_island_function(const u32) {
    DDON_STUB("nPhysics::System::calculate_island_function")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::solve_constraint_function(const u32 index) {
    DDON_STUB("nPhysics::System::solve_constraint_function")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::update_rigid_body_function(const u32 index) {
    DDON_STUB("nPhysics::System::update_rigid_body_function")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::callback_collision(const u32) {
    DDON_STUB("nPhysics::System::callback_collision")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::callback_step_end(const u32) {
    DDON_STUB("nPhysics::System::callback_step_end")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::setMaterial(const u32 index, const nPhysics::Material& material) {
    DDON_STUB("nPhysics::System::setMaterial")
    /* stub */
}

void nPhysics::System::addStepEndCallback(MtObject* object, MT_MFUNC function) {
    if (::scePthreadMutexLock(&mCriticalSectionCallback.mCSection) != 0) {
        ::abort();
    }
    mStepEnd.add(object, function);
    if (::scePthreadMutexUnlock(&mCriticalSectionCallback.mCSection) != 0) {
        ::abort();
    }
}

void nPhysics::System::removeStepEndCallback(MtObject* object, MT_MFUNC function) {
    if (::scePthreadMutexLock(&mCriticalSectionCallback.mCSection) != 0) {
        ::abort();
    }
    mStepEnd.remove(object, function);
    if (::scePthreadMutexUnlock(&mCriticalSectionCallback.mCSection) != 0) {
        ::abort();
    }
}

__attribute__((weak)) void* nPhysics::System::MainThreadFunction(void* parameter) {
    DDON_STUB("nPhysics::System::MainThreadFunction")
    return nullptr;
}

__attribute__((weak)) void* nPhysics::System::JobThreadFunction(void* parameter) {
    DDON_STUB("nPhysics::System::JobThreadFunction")
    return nullptr;
}

__attribute__((weak)) void nPhysics::System::job_thread_function(nPhysics::System::THREAD_INFO& thread_info) {
    DDON_STUB("nPhysics::System::job_thread_function")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::execute_same_job(MT_MFUNC32 function, u32 num_job) {
    DDON_STUB("nPhysics::System::execute_same_job")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::execute_different_job(MT_MFUNC32* function, u32 num_job) {
    DDON_STUB("nPhysics::System::execute_different_job")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::send_command(const void* command, const u32 size) {
    DDON_STUB("nPhysics::System::send_command")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::receive_command(const u32 thread_id) {
    DDON_STUB("nPhysics::System::receive_command")
    /* stub */
}

__attribute__((weak)) u32 nPhysics::System::collide_vs_scroll(const sCollision::SbcInfo& sbc_info, uintptr parameter, u32 hit_convex_index) {
    DDON_STUB("nPhysics::System::collide_vs_scroll")
    return {};
}

__attribute__((weak)) void nPhysics::System::clearGroundSoundResource() {
    DDON_STUB("nPhysics::System::clearGroundSoundResource")
    /* stub */
}

__attribute__((weak)) void nPhysics::System::requestGroundSound(s32 self_material_no, s32 target_material_no, const u32 contact_keep_count, f32 normal_force, f32 slide_speed, f32 roll_speed, uCoord* coord, s32 joint_no, u32 id) {
    DDON_STUB("nPhysics::System::requestGroundSound")
    /* stub */
}

inline nPhysics::System::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nPhysics::System::MyDTI nPhysics::System::DTI("nPhysics::System", &::cSystem::DTI, 38432ul, 0u, 0u);

nPhysics::System* nPhysics::System::mInstance;

__attribute__((weak)) MtObject* nPhysics::System::MyDTI::newInstance() const {
    DDON_STUB("nPhysics::System::MyDTI::newInstance")
    return nullptr;
}

