// The field dump's helpers (harness-dump.h, from the harness that tested
// these loads). On Windows, the forced include host/windows-lp64.h spells
// `long` as `long long` for the reconstruction's own declarations; the
// helpers spell the platform's own types (`long long` among them), so they
// are read without it.
#pragma once

#if defined(long)
#undef long
#include "harness-dump.h"
#define long long long
#else
#include "harness-dump.h"
#endif
