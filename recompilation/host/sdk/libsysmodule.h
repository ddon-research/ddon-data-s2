// The harness's host stand-in for the PS4 SDK's `<libsysmodule.h>` (026
// plan-P114b): only what the units call, spelled as SDK 2.500's header does
// (C linkage, the module id a `uint16_t`). `~sApp` unloads its modules; the
// definition is the runtime's (`runtime.cpp`).
#pragma once

#include <stdint.h>

extern "C" {
int sceSysmoduleUnloadModule(uint16_t id);
}
