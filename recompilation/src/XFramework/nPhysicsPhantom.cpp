// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nPhysicsPhantom.h"
#include "../MT/MtObject.h"
#include "nPhysicsList.h"
#include "nPhysicsMathVector4.h"
#include "nPhysicsShape.h"
#include "nPhysicsStruct.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) nPhysics::AABB nPhysics::Phantom::get_circumscribed_aabb() const {
    DDON_STUB("nPhysics::Phantom::get_circumscribed_aabb")
    __builtin_unreachable();
}

void nPhysics::Phantom::update() {
    if (!mUpdate) {
        return;
    }
    mShape.Type = mUpdateShape.Type;
    mShape.MaterialNo = mUpdateShape.MaterialNo;
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 48) = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 128);
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 56) = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 136);
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 64) = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 144);
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 72) = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 152);
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 80) = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 160);
    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 88) = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 168);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 96) = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 176);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 100) = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 180);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 104) = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 184);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 108) = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 188);
    mUpdate = false;
}

__attribute__((weak)) nPhysics::CONTACT_INFO nPhysics::Phantom::closest(const nPhysics::SHAPES& shapes) const {
    DDON_STUB("nPhysics::Phantom::closest")
    __builtin_unreachable();
}

bool nPhysics::Phantom::is_enable_collide_callback() const {
    if (mSelfObject != nullptr) {
        if (mCollideCallbackFunction != static_cast<const nPhysics::Phantom::COLLIDE_CALLBACK>(0)) {
            return mShape.Type != 0;
        }
    }
    return false;
}

void nPhysics::Phantom::execute_begin_callback() const {
    if (mSelfObject == nullptr) {
        return;
    }
    if (mBeginCallbackFunction == static_cast<const nPhysics::Phantom::EVENT_CALLBACK>(0)) {
        return;
    }
    (mSelfObject->*mBeginCallbackFunction)();
}

void nPhysics::Phantom::execute_collide_callback(nPhysics::RigidBody& rigid_body, const nPhysics::CONTACT_INFO& contact_info) const {
    (mSelfObject->*mCollideCallbackFunction)(rigid_body, contact_info);
}

void nPhysics::Phantom::end() {
    if ((mStatus & 1u) != 0) {
        if (mKeepAliveTime != 0) {
            mKeepAliveTime = mKeepAliveTime - 1u;
        } else {
            mEnable = false;
        }
    }
    if (mSelfObject == nullptr) {
        return;
    }
    if (mEndCallbackFunction == static_cast<nPhysics::Phantom::EVENT_CALLBACK>(0)) {
        return;
    }
    (mSelfObject->*mEndCallbackFunction)();
}

