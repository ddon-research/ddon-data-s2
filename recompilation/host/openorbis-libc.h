// The OpenOrbis build's forced include (026 plan-P79e), as host-libc.h is
// Linux's. The reconstruction declares the PS4 libc's thread handles from
// DWARF at global scope (`using pthread_t = pthread*;` in `MtThread.h`,
// `using pthread_mutex_t = pthread_mutex*;` in `MtSynchronize.h`). OpenOrbis's
// libc is musl, whose `<pthread.h>` defines the same two names as other
// types, and its libc++ includes it (`<memory>` -> `<atomic>` ->
// `<__threading_support>`): 151 of t180's 1,153 units did not compile.
//
// So the headers that name them are parsed here, first, while the two names
// are spelled differently: musl and libc++ keep their own types, and the
// global names are left to the reconstruction. Later includes of these
// headers are no-ops (their include guards), and no source file is edited.
#pragma once

#define pthread_t ddon_host_pthread_t
#define pthread_mutex_t ddon_host_pthread_mutex_t
#include <cstddef>
#include <pthread.h>
#include <signal.h>  // `pthread_kill(pthread_t, int)`
#include <__threading_support>
#undef pthread_t
#undef pthread_mutex_t
