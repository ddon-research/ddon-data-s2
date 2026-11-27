// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nSyncPoint.h"
#include "sSyncPoint.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

nSyncPoint::cSyncPointDefinition::cSyncPointDefinition(nSyncPoint::eSyncPoint bsp) {
    mEsp = ::nSyncPoint::SP_INVALID;
    if ((::sSyncPoint::mpInstance) == nullptr) {
        return;
    }
    (::sSyncPoint::mpInstance)->::sSyncPoint::updateStatus(bsp);
}

nSyncPoint::cSyncPointDefinition::~cSyncPointDefinition() {
    DDON_STUB("nSyncPoint::cSyncPointDefinition::~cSyncPointDefinition")
    /* stub */
}

