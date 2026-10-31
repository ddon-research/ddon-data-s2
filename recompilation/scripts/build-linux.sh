#!/usr/bin/env bash
# Builds the reconstruction as a static library on Linux and runs the layout
# tests, from a Linux shell (on Windows, scripts/build-wsl.sh runs it in
# WSL). Needs cmake (3.25 or newer), ninja and clang (DDON_CXX, default the
# newest clang++ found).
set -euo pipefail
root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
for tool in cmake ninja; do
  command -v "$tool" >/dev/null || { echo "build-linux: $tool not found" >&2; exit 2; }
done
if [ -z "${DDON_CXX:-}" ]; then
  for candidate in clang++-22 clang++-21 clang++-20 clang++; do
    if command -v "$candidate" >/dev/null; then DDON_CXX="$(command -v "$candidate")"; break; fi
  done
fi
[ -n "${DDON_CXX:-}" ] || { echo "build-linux: no clang++ found; set DDON_CXX" >&2; exit 2; }
export DDON_CXX
# DDON_BUILD_DIR moves the build directory (build-wsl.sh puts it on WSL's
# own file system); the default is the preset's build/linux-clang.
build="${DDON_BUILD_DIR:-$root/build/linux-clang}"
cd "$root"
cmake --preset linux-clang -B "$build"
cmake --build "$build" -- -k 0
ctest --test-dir "$build" --output-on-failure
