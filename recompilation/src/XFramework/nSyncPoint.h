#pragma once

#include <cstdint>
#include <cstddef>

namespace nSyncPoint {
    enum eSyncPoint
    {
        SP_INVALID = -1,
        SP_FRAME_ENTRY = 0,
        SP_BEFORE_MOVE = 1,
        SP_BEFORE_SYNC = 2,
        SP_BEFORE_MOVEAFTER = 3,
        SP_BEFORE_DRAW = 4,
        SP_BEFORE_RENDERING = 5,
        SP_NUM = 6,
    };
}  // namespace nSyncPoint

// Declarations
namespace nSyncPoint { class cSyncPointDefinition; }

namespace nSyncPoint {
    class cSyncPointDefinition
    {
    public:
        cSyncPointDefinition(nSyncPoint::eSyncPoint bsp);
        cSyncPointDefinition(nSyncPoint::eSyncPoint bsp, nSyncPoint::eSyncPoint esp);
        ~cSyncPointDefinition();
    private:
        nSyncPoint::eSyncPoint mEsp;  // offset: 0x0
    };
}  // namespace nSyncPoint
