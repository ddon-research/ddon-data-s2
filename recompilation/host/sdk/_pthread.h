// The host stand-in for the PS4 SDK's `<_pthread.h>`.
// The bundle's import probe includes the SDK header a unit's imports come
// from; the host has no such header, so the units that lock a mutex did not
// compile there. This declares only what the units call, spelled as the SDK
// does (`int scePthreadMutexLock(ScePthreadMutex *)`, C linkage), with
// `ScePthreadMutex` written out as the type it names: the bundle declares
// `ScePthreadMutex` and `pthread_mutex_t` itself from DWARF (`MtSynchronize.h`:
// `pthread_mutex_t = pthread_mutex*`), and those names are left to it. The
// definitions are the runtime's (`runtime.cpp`). `ScePthreadMutexattr` is the
// SDK's own alias.
#pragma once

struct pthread_mutex;
struct pthread_mutexattr;
using ScePthreadMutexattr = pthread_mutexattr*;

extern "C" {
int scePthreadMutexLock(pthread_mutex** mutex);
int scePthreadMutexUnlock(pthread_mutex** mutex);
int scePthreadMutexInit(pthread_mutex** mutex, const ScePthreadMutexattr* attr, const char* name);
int scePthreadMutexDestroy(pthread_mutex** mutex);
int scePthreadMutexattrInit(ScePthreadMutexattr* attr);
int scePthreadMutexattrSettype(ScePthreadMutexattr* attr, int type);
int scePthreadMutexattrDestroy(ScePthreadMutexattr* attr);
}
