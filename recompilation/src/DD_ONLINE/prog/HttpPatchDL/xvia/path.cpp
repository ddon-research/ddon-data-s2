// Reconstructed from the game's DWARF debug information.
#include <new>
#include "path.h"
#include "../../../../MT/MtFile.h"
#include "../../../../MT/MtFilePath.h"
#include "../../../../MT/MtString.h"
#include "../../../../generated/shared/directory.h"
#include "../../../../generated/shared/str.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) MtString via::path::getMtFitDirectory(MT_CTSTR path) {
    DDON_STUB("via::path::getMtFitDirectory")
    __builtin_unreachable();
}

__attribute__((weak)) MtString via::path::getDirectoryName(MT_CTSTR path) {
    DDON_STUB("via::path::getDirectoryName")
    __builtin_unreachable();
}

__attribute__((weak)) u64 via::path::getMountPointAvailableSpace(via::path::DriveType mount_type, u32 mount_no) {
    DDON_STUB("via::path::getMountPointAvailableSpace")
    return {};
}

__attribute__((weak)) MtString via::path::getDrivePath(via::path::DriveType type, u32 driveNo) {
    DDON_STUB("via::path::getDrivePath")
    __builtin_unreachable();
}

__attribute__((weak)) void via::path::setDrivePath(via::path::DriveType type, MT_CTSTR path, bool no_enable) {
    DDON_STUB("via::path::setDrivePath")
    /* stub */
}

__attribute__((weak)) bool via::path::formatMountPoint(const via::path::DriveType mount_type, MT_CTSTR path_str, u32 mount_no) {
    DDON_STUB("via::path::formatMountPoint")
    return {};
}

