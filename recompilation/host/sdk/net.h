// The host stand-in for the PS4 SDK's `<net.h>`: only
// what the units call, spelled as the SDK does (`libnet/socket.h`, C
// linkage), with `SceNetId` written out as the `int` it names
// (`libnet/nettypes.h`). The definitions are the runtime's (`runtime.cpp`).
#pragma once

extern "C" {
int sceNetSocketClose(int s);
}
