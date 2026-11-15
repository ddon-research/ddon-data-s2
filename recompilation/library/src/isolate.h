// An inner load's isolation: each inner load
// first runs in a child of its own, so whatever it reaches (a stub, a trap,
// a crash) stays there, and only a clean one reruns in the caller's process.
// One implementation for the harness (`runtime.cpp`) and the load/save
// library (`host.cpp`): `isolate_posix.cpp` forks; `isolate_other.cpp`, for
// a host without `fork`, isolates nothing (`supported()` is false).
//
// The rerun of a clean trial replays it: the same code from the same state,
// so it asks the same inner requests in the same order. The child sends back
// each request's verdict with its key, and the requests of the rerun that
// follows take them in order instead of a trial of their own; the first
// whose key differs, and every one after it, runs its own trial.
#pragma once

#include <cstddef>

#include "runtime.h"

namespace ddon {
namespace isolate {

// The caller's part of a trial: what its own process keeps beside it.
class Host {
public:
    // In the parent, before the fork and after the child ended (the harness
    // pauses its file's alarm meanwhile).
    virtual void before_fork() {}
    virtual void after_child() {}
    // In the child, before the attempt: `out` is the pipe to the parent,
    // where a record the caller writes there must go.
    virtual void enter_child(int out) = 0;
    // In the child, after the attempt: the first stub it reached, or null.
    virtual const char* first_stub() = 0;

protected:
    ~Host() = default;
};

// Whether this build isolates: false where the host cannot fork.
bool supported();
// `attempt(context)` in a child of its own, or the verdict the rerun under
// way replays for `key`. `attempt` returns 0 (loaded), 1 (refused) or 2 (no
// file); a wall's text goes into `wall` (`size` bytes, ended by a zero).
DdonInnerTrial trial(const DdonInnerKey& key, int (*attempt)(void* context), void* context,
                     char* wall, std::size_t size, Host& host);
// A clean trial's rerun, `rerun(context)`; the verdicts its trial sent back
// last no longer than it does.
int rerun(int (*rerun)(void* context), void* context);
// Whether this process is a trial's child.
bool in_child();
// In a trial's child: ends its answer as a wall with `text` (a trap, a
// sanitizer's death). The caller then ends the process.
void wall(const char* text);

}  // namespace isolate
}  // namespace ddon
