// The host stand-in for the PS4 SDK's `<_fs.h>`: only what the units call
// (MtFile's seek, write and truncate), spelled as the SDK does (C linkage).
// The definitions are the runtime's, on the host's file descriptors.
#pragma once

#include <sys/types.h>

#include <cstddef>

extern "C" {
off_t sceKernelLseek(int fildes, off_t offset, int whence);
ssize_t sceKernelWrite(int d, const void* buf, size_t nbytes);
int sceKernelFtruncate(int fd, off_t length);
}
