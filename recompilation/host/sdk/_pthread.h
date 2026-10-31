// The harness's host stand-in for the PS4 SDK's `<_pthread.h>` (026 P11j3).
// The bundle's import probe includes the SDK header a unit's imports come
// from; the host has no such header, so the units that lock a mutex did not
// compile there. This declares only what the units call, spelled as the SDK
// does (`int scePthreadMutexLock(ScePthreadMutex *)`, C linkage), with
// `ScePthreadMutex` written out as the type it names: the bundle declares
// `ScePthreadMutex` and `pthread_mutex_t` itself from DWARF (`MtSynchronize.h`:
// `pthread_mutex_t = pthread_mutex*`), and those names are left to it. The
// definitions are the runtime's (`runtime.cpp`).
#pragma once

struct pthread_mutex;

extern "C" {
int scePthreadMutexLock(pthread_mutex** mutex);
int scePthreadMutexUnlock(pthread_mutex** mutex);
}
