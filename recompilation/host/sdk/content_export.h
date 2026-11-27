// The host stand-in for the PS4 SDK's `<content_export.h>`: only what the
// units call (sRender's teardown), spelled as the SDK does (C linkage). The
// definition is the runtime's.
#pragma once

#include <cstdint>

extern "C" {
int32_t sceContentExportTerm();
}
