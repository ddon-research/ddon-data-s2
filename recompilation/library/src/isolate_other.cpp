// An inner load's isolation where the host cannot fork (`isolate.h`): none.
// The library answers `unsupported_option` for `InnerLoads::isolate` before
// any load (`resource.cpp`), so a trial here only ever meets a caller that
// asked for nothing else: it is a wall, and a rerun runs as it is.
#if defined(_WIN32)

#include <algorithm>
#include <cstring>

#include "isolate.h"

namespace ddon {
namespace isolate {

bool supported() { return false; }

DdonInnerTrial trial(const DdonInnerKey&, int (*)(void*), void*, char* wall, std::size_t size,
                     Host&) {
    static const char why[] = "not isolated (unsupported option)";
    if (size != 0) {
        std::size_t n = std::min(size - 1, sizeof why - 1);
        std::memcpy(wall, why, n);
        wall[n] = 0;
    }
    return DdonInnerTrial::wall;
}

int rerun(int (*rerun)(void* context), void* context) { return rerun(context); }

bool in_child() { return false; }

void wall(const char*) {}

}  // namespace isolate
}  // namespace ddon

#endif  // defined(_WIN32)
