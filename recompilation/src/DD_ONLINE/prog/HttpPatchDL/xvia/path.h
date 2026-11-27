#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtString;

namespace via {
namespace path {
    enum DriveType
    {
        DriveType_Download = 0,
        DriveType_Temp = 1,
        DriveType_MaxType = 2,
    };
}  // namespace path
}  // namespace via

// Declarations
namespace via { namespace path { struct DrivePathInfo; } }

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using __uint64_t = long unsigned int;
using u32 = unsigned int;
using u64 = __uint64_t;

namespace via {
    namespace path {

        // Forward declarations
        struct DrivePathInfo;

        struct DrivePathInfo
        {
        public:
            MT_CHAR path8[1024];  // offset: 0x0
            u32 len;  // offset: 0x400
            bool no_enable;  // offset: 0x404
            via::path::DriveType type;  // offset: 0x408
        };

        MtString getMtFitPath(MT_CTSTR path);
        MtString getMtFitDirectory(MT_CTSTR path);
        MtString getDirectoryName(MT_CTSTR path);
        u64 getMountPointAvailableSpace(DriveType mount_type, u32 mount_no);
        MtString getDrivePath(DriveType type, u32 driveNo);
        void setDrivePath(DriveType type, MT_CTSTR path, bool no_enable);
        bool formatMountPoint(MT_CTSTR path_str);
        bool formatMountPoint(const DriveType mount_type, MT_CTSTR path_str, u32 mount_no);

    }  // namespace path
}  // namespace via
