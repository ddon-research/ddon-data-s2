// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nRegionStatus.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

bool nRegionStatus::isCorePointErosion(nRegionStatus::CORE_POINT_TYPE type) {
    return static_cast<unsigned int>(type - 2) <= 3;
}

bool nRegionStatus::isCorePointErosionTentacle(nRegionStatus::CORE_POINT_TYPE type) {
    return static_cast<unsigned int>(type - 6) <= 3;
}

