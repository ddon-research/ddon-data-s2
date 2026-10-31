// The harness's host stand-in for the PS4 SDK's `<_kernel.h>` (026 P11j3):
// only what the units call, spelled as the SDK does (C linkage). The
// definitions are the runtime's (`runtime.cpp`).
#pragma once

#include <cstdint>

extern "C" {
uint64_t sceKernelGetTscFrequency(void);
uint64_t sceKernelReadTsc(void);
}
