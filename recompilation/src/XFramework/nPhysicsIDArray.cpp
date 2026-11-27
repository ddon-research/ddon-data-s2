// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nPhysicsIDArray.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

nPhysics::ID_ARRAY::ID_ARRAY() {
    mRemovePosition = 0;
    mMaxID = 0;
    mCreatePosition = 0;
    mNumValidID = 0;
    mNumMigratedID = 0;
    mInvalidID = nullptr;
    mValidIDIndex = nullptr;
    mValidID = nullptr;
}

nPhysics::ID_ARRAY::~ID_ARRAY() {
}

__attribute__((weak)) void nPhysics::ID_ARRAY::initialize(const u32 num, void* buffer, const u32 buffer_size) {
    DDON_STUB("nPhysics::ID_ARRAY::initialize")
    /* stub */
}

u32 nPhysics::ID_ARRAY::create() {
    if (mCreatePosition == mRemovePosition) {
        if (mNumValidID == 0) {
            u32 t0 = mInvalidID[mCreatePosition];
            *mValidID = t0;
            mValidIDIndex[t0] = mNumValidID;
            mNumValidID = mNumValidID + 1u;
            if (mMaxID != (mCreatePosition + 1u)) {
                mCreatePosition = mCreatePosition + 1u;
            } else {
                mCreatePosition = 0;
            }
            return t0;
        } else {
            return 0xFFFFFFFF;
        }
    } else {
        u32 t0 = mInvalidID[mCreatePosition];
        mValidID[mNumValidID] = t0;
        mValidIDIndex[t0] = mNumValidID;
        mNumValidID = mNumValidID + 1u;
        if (mMaxID != (mCreatePosition + 1u)) {
            mCreatePosition = mCreatePosition + 1u;
        } else {
            mCreatePosition = 0;
        }
        return t0;
    }
}

void nPhysics::ID_ARRAY::remove(const u32 id) {
    u32 j0;
    u32 j1;
    u32 j2;
    u32 t0 = mNumValidID;
    u32 migrated_index = mValidIDIndex[id];
    if (migrated_index < t0) {
        mNumValidID = t0 - 1u;
        u32 t1 = mValidID[t0 - 1u];
        u32 t2 = mValidIDIndex[id];
        mValidID[t2] = t1;
        j0 = t1;
        j1 = t2;
    } else {
        u32 t3 = mNumMigratedID;
        mNumMigratedID = t3 - 1u;
        u32 t4 = mValidID[mMaxID - t3];
        mValidID[migrated_index] = t4;
        j0 = t4;
        j1 = migrated_index;
    }
    mValidIDIndex[j0] = j1;
    mInvalidID[mRemovePosition] = id;
    u32 t5 = mRemovePosition;
    mRemovePosition = t5 + 1u;
    if (mMaxID != mRemovePosition) {
        j2 = t5 + 1u;
    } else {
        j2 = 0;
    }
    mRemovePosition = j2;
}

void nPhysics::ID_ARRAY::migrate(const u32 id) {
    u32* j0;
    u32* j1;
    u32 t0 = mNumValidID;
    mNumValidID = t0 - 1u;
    if (mNumValidID != 0) {
        u32 t1 = mValidID[t0 - 1u];
        u32 t2 = mValidIDIndex[id];
        mValidID[t2] = t1;
        mValidIDIndex[t1] = t2;
        j0 = mValidID;
        j1 = mValidIDIndex;
    } else {
        u32* t3 = mValidIDIndex;
        j0 = mValidID;
        j1 = t3;
    }
    u32 t4 = mMaxID;
    u32 t5 = mNumMigratedID;
    j0[(t4 - t5) - 1u] = id;
    j1[id] = (t4 - t5) - 1u;
    mNumMigratedID = mNumMigratedID + 1u;
}

void nPhysics::ID_ARRAY::restore(const u32 id) {
    if (mNumMigratedID > 1u) {
        u32 t0 = mValidIDIndex[id];
        u32 t1 = mValidID[mMaxID - mNumMigratedID];
        mValidID[t0] = t1;
        mValidIDIndex[t1] = t0;
        mNumMigratedID = mNumMigratedID - 1u;
        mValidID[mNumValidID] = id;
        mValidIDIndex[id] = mNumValidID;
        mNumValidID = mNumValidID + 1u;
    } else {
        u32* t2 = mValidIDIndex;
        mNumMigratedID = mNumMigratedID - 1u;
        mValidID[mNumValidID] = id;
        t2[id] = mNumValidID;
        mNumValidID = mNumValidID + 1u;
    }
}

void nPhysics::ID_ARRAY::clear() {
    mNumValidID = 0;
    mNumMigratedID = 0;
    mCreatePosition = 0;
    mRemovePosition = 0;
    if (mMaxID != 0) {
        u32* v0_0 = mInvalidID;
        for (unsigned int i0_1 = 0;;) {
            v0_0[i0_1] = i0_1;
            if ((i0_1 + 1u) < mMaxID) {
                i0_1 += 1u;
            } else {
                break;
            }
        }
    }
}

