// The host stand-in for the PS4 SDK's `<libsysmodule.h>`: only
// what the units call, spelled as SDK 2.500's header does (C linkage, the module id a `uint16_t`). `~sApp` unloads its modules and
// sMovie loads one; the definitions are the runtime's (`runtime.cpp`).
#pragma once

#include <stdint.h>

extern "C" {
int sceSysmoduleLoadModule(uint16_t id);
int sceSysmoduleUnloadModule(uint16_t id);
}
