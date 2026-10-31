// The deserialization harness's first forced include (024 T872). The bundle
// declares the PS4 libc's thread handles from DWARF at global scope
// (`using pthread_t = pthread*;` in `MtThread.h`, `using pthread_mutex_t =
// pthread_mutex*;` in `MtSynchronize.h`). glibc's `<pthread.h>` defines the
// same two names as `unsigned long` and a union, and libstdc++ includes it
// (`<memory>` → `<bits/gthr.h>` → `<pthread.h>`) in every unit that uses a
// std container, so 107 of merge2b's units did not compile on the host.
//
// So every header that names them is parsed here, first, while the two names
// are spelled differently: glibc and libstdc++ keep their own types, layouts
// and extern "C" symbols, and the global names are left to the bundle. Later
// includes of these headers are no-ops (their include guards), so nothing
// the bundle declares changes, and no bundle file is edited.
#pragma once

#define pthread_t ddon_host_pthread_t
#define pthread_mutex_t ddon_host_pthread_mutex_t
#include <cstddef>  // libstdc++'s configuration, before its thread layer
#include <pthread.h>
#include <signal.h>  // `pthread_kill(pthread_t, int)`
#include <bits/gthr.h>
#undef pthread_t
#undef pthread_mutex_t

// The PS4's `wchar_t` is 2 bytes (026 plan-P118): the harness compiles with
// `-fshort-wchar`, so `nInputText::cUnicodeString`, `sKeyboardInterface` and
// `nIMEPS4::CandidateDispInfo` have DWARF's layout. glibc's wide-character
// functions still count 4-byte units, so each one the bundle calls is
// replaced here by a 16-bit one under its name. The census (of
// every `wcs*`, `wmem*`, `*wprintf`, `isw*`, `tow*` and conversion function
// in the units, the runtime and the fixtures): `wcslen` alone, in
// `nUnicode::GetLength`. `<cwchar>` (and through it `<wchar.h>`) is parsed
// first, under glibc's names: it `#undef`s `wcslen`, so the macro must follow
// it, and a later include of either is a no-op (their include guards).
#include <cwchar>
#if __SIZEOF_WCHAR_T__ == 2
static inline size_t ddon_wcslen16(const wchar_t* s) {
    const wchar_t* end = s;
    while (*end != 0) {
        ++end;
    }
    return static_cast<size_t>(end - s);
}
#define wcslen ddon_wcslen16
#endif
