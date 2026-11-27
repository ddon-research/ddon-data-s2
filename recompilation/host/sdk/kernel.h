// The host stand-in for the PS4 SDK's `<kernel.h>`: as the SDK's, it
// includes `_kernel.h`, `_pthread.h` and `_fs.h`, and declares what the units
// call of `kernel/semaphore.h` and `kernel/eventflag.h` (C linkage), with the
// handles' types as the SDK names them, and the two creations, which a test
// of the services calls; their option structures stay incomplete, as no
// caller passes one. The definitions are the runtime's.
#pragma once

#include <cstdint>

#include "_fs.h"
#include "_kernel.h"
#include "_pthread.h"

typedef struct _SceKernelSema* SceKernelSema;
typedef struct _SceKernelEventFlag* SceKernelEventFlag;
struct SceKernelSemaOptParam;
struct SceKernelEventFlagOptParam;

extern "C" {
int sceKernelCreateSema(SceKernelSema* sem, const char* name, uint32_t attr, int init, int max,
                        const SceKernelSemaOptParam* opt);
int sceKernelDeleteSema(SceKernelSema sem);
int sceKernelWaitSema(SceKernelSema sem, int need, SceKernelUseconds* timo);
int sceKernelSignalSema(SceKernelSema sem, int count);
int sceKernelCancelSema(SceKernelSema sem, int count, int* threads);
int sceKernelCreateEventFlag(SceKernelEventFlag* ef, const char* pName, uint32_t attr,
                             uint64_t initPattern, const SceKernelEventFlagOptParam* pOptParam);
int sceKernelDeleteEventFlag(SceKernelEventFlag ef);
int sceKernelWaitEventFlag(SceKernelEventFlag ef, uint64_t bitPattern, uint32_t waitMode,
                           uint64_t* pResultPat, SceKernelUseconds* pTimeout);
int sceKernelSetEventFlag(SceKernelEventFlag ef, uint64_t bitPattern);
}
