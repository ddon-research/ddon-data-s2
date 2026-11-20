// The field dump's helpers (field-dump.h, from the test runner that ran
// these loads). On Windows, the forced include host/windows-lp64.h spells
// `long` as `long long` for the reconstruction's own declarations; the
// helpers spell the platform's own types (`long long` among them), so they
// are read without it.
#pragma once

#if defined(long)
#undef long
#include "field-dump.h"
#define long long long
#else
#include "field-dump.h"
#endif
