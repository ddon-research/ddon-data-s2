// The harness's host stand-in for the PS4 SDK's `<ymath.h>` (026 P11j3), the
// Dinkumware library's math primitives: only what the units call, spelled as
// the SDK does (C linkage). The definitions are the runtime's
// (`runtime.cpp`).
#pragma once

extern "C" {
float _FLog(float x, int base);
float _FSin(float x, unsigned int qoff, int quads);
}
