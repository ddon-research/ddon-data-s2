// The forced include of the runtime's stubs. A body the
// reconstruction refused starts with DDON_STUB("Q::f") (no semicolon: the
// bundle defines the macro as nothing, so the Orbis compiles see the same
// body). Here it records that a load reached that body.
#pragma once
extern "C" void ddon_stub_hit(const char* name);
#define DDON_STUB(name) ddon_stub_hit(name);
