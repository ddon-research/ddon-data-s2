// The PS4 SDK's functions the units call, on a Linux or Windows host (the
// stand-ins' declarations are under host/sdk). One thread runs, so a mutex
// never waits. None of them reads a byte of a file.

#include <chrono>
#include <cmath>
#include <cstdint>

#include "runtime.h"

#include <_kernel.h>
#include <_pthread.h>
#include <net.h>
#include <ymath.h>

extern "C" int scePthreadMutexLock(pthread_mutex**) { return 0; }
extern "C" int scePthreadMutexUnlock(pthread_mutex**) { return 0; }

// The time-stamp counter as a monotonic clock in nanoseconds.
extern "C" uint64_t sceKernelReadTsc(void) {
    auto now = std::chrono::steady_clock::now().time_since_epoch();
    return static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::nanoseconds>(now).count());
}
extern "C" uint64_t sceKernelGetTscFrequency(void) { return 1000000000u; }

extern "C" int sceNetSocketClose(int) { return 0; }

// The SDK's math primitives, for the arguments the units pass: `_FLog(x, 0)`
// is the natural log and `_FLog(x, 1)` log10; `_FSin(x, 0, 0)` is sin and
// `_FSin(x, 1, 0)` cos.
extern "C" float _FLog(float x, int base) {
    if (base == 0) {
        return std::log(x);
    }
    if (base == 1) {
        return std::log10(x);
    }
    ddon_trap("_FLog(float, int) with a base other than 0 or 1");
}
extern "C" float _FSin(float x, unsigned int qoff, int quads) {
    if (qoff == 0 && quads == 0) {
        return std::sin(x);
    }
    if (qoff == 1 && quads == 0) {
        return std::cos(x);
    }
    ddon_trap("_FSin(float, unsigned int, int) with other than (x, 0, 0) or (x, 1, 0)");
}
