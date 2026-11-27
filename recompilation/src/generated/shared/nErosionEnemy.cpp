// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nErosionEnemy.h"
#include "../../DD_ONLINE/prog/nRegionStatus.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

bool nErosionEnemy::isErosionRegion(nRegionStatus::P_REGION_CATEGORY category) {
    return static_cast<unsigned int>(category - 1) <= 3;
}

