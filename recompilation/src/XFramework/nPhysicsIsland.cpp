// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nPhysicsIsland.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

nPhysics::ISLAND::ISLAND() {
    mAggressiveSleepCount = 0;
    mStatus = 1;
    mStationaryCount = 0;
    mHash = 0;
}

nPhysics::ISLAND::~ISLAND() {
}

void nPhysics::ISLAND::clear() {
    mAggressiveSleepCount = 0;
    mStatus = 1;
    mStationaryCount = 0;
    mHash = 0;
}

void nPhysics::ISLAND::increment_stationary_count() {
    mStationaryCount = mStationaryCount + 1u;
    mStatus = mStatus | 4u;
}

