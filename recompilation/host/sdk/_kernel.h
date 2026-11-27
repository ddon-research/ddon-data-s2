// The host stand-in for the PS4 SDK's `<_kernel.h>`: only
// what the units call, spelled as the SDK does (C linkage). The
// definitions are the runtime's (`runtime.cpp`). `SceKernelUseconds` is the
// SDK's `_types.h` alias: the imports name it from the SDK's header, and the
// bundle does not.
#pragma once

#include <cstdint>

typedef unsigned int SceKernelUseconds;

extern "C" {
uint64_t sceKernelGetTscFrequency(void);
uint64_t sceKernelReadTsc(void);
int sceKernelUsleep(SceKernelUseconds microseconds);
}
