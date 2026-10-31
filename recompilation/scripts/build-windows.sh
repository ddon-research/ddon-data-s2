#!/usr/bin/env bash
# Builds the reconstruction as a static library on Windows and runs the
# layout tests, from Git Bash or an MSYS2 shell. Needs cmake (3.25 or newer),
# ninja and MSYS2's clang64 environment (clang++, lld and libc++; DDON_MSYS2
# names the MSYS2 root, default C:/msys64), which keeps the PS4's Itanium C++
# ABI on Windows.
set -euo pipefail
root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
msys="${DDON_MSYS2:-C:/msys64}"
clang64="$msys/clang64/bin"
DDON_CXX="${DDON_CXX:-$clang64/clang++.exe}"
[ -x "$DDON_CXX" ] || { echo "build-windows: no clang++ at $DDON_CXX; install MSYS2's mingw-w64-clang-x86_64-clang or set DDON_CXX" >&2; exit 2; }
# The linker and libc++'s DLL (for the test) come from clang64's bin, put
# first on PATH in its POSIX spelling (a drive's colon would split it).
bin="$(dirname "$DDON_CXX")"
command -v cygpath >/dev/null && bin="$(cygpath -u "$bin")"
PATH="$bin:$PATH"
for tool in cmake ninja; do
  command -v "$tool" >/dev/null || { echo "build-windows: $tool not found" >&2; exit 2; }
done
export DDON_CXX PATH
cd "$root"
cmake --preset windows-clang
cmake --build --preset windows-clang -- -k 0
ctest --preset windows-clang
