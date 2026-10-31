#!/usr/bin/env bash
# Builds the reconstruction for the PS4 as a static library with the open
# OpenOrbis toolchain, for builders without the Orbis SDK, and compiles the
# layout test (its static_asserts are the test; nothing runs). Needs cmake
# (3.25 or newer), ninja, a clang (DDON_CXX; default MSYS2 clang64's on
# Windows, DDON_MSYS2 naming the MSYS2 root, else the newest clang++ found)
# and OpenOrbis-PS4-Toolchain, its directory in OO_PS4_TOOLCHAIN. Runs in Git
# Bash on Windows or a Linux shell.
set -euo pipefail
root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
[ -n "${OO_PS4_TOOLCHAIN:-}" ] || { echo "build-ps4-openorbis: set OO_PS4_TOOLCHAIN to the OpenOrbis PS4 toolchain" >&2; exit 2; }
# libc and libc++'s headers come from the toolchain's build, which only the
# release archive holds: a git clone's include/ has the PS4 headers alone.
if [ ! -d "$OO_PS4_TOOLCHAIN/include/c++/v1" ]; then
  echo "build-ps4-openorbis: no include/c++/v1 under $OO_PS4_TOOLCHAIN" >&2
  if [ -d "$OO_PS4_TOOLCHAIN/.git" ] || [ -d "$OO_PS4_TOOLCHAIN/src" ]; then
    echo "build-ps4-openorbis: that looks like a source checkout, which holds no libc or libc++ headers" >&2
  fi
  echo "build-ps4-openorbis: download toolchain-llvm-18.tar.gz from the OpenOrbis-PS4-Toolchain v0.5.4 release (https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain/releases/tag/v0.5.4), extract it, and set OO_PS4_TOOLCHAIN to the OpenOrbis/PS4Toolchain directory inside it" >&2
  exit 2
fi
if [ -z "${DDON_CXX:-}" ]; then
  msys="${DDON_MSYS2:-C:/msys64}"
  for candidate in "$msys/clang64/bin/clang++.exe" clang++-22 clang++-21 clang++-20 clang++; do
    if [ -x "$candidate" ] || command -v "$candidate" >/dev/null; then
      DDON_CXX="$(command -v "$candidate" || echo "$candidate")"
      break
    fi
  done
fi
[ -n "${DDON_CXX:-}" ] || { echo "build-ps4-openorbis: no clang++ found; set DDON_CXX" >&2; exit 2; }
# The archiver and ninja's tools come first from the compiler's folder, in its
# POSIX spelling (a drive's colon would split PATH).
bin="$(dirname "$DDON_CXX")"
command -v cygpath >/dev/null && bin="$(cygpath -u "$bin")"
PATH="$bin:$PATH"
for tool in cmake ninja; do
  command -v "$tool" >/dev/null || { echo "build-ps4-openorbis: $tool not found" >&2; exit 2; }
done
export DDON_CXX OO_PS4_TOOLCHAIN PATH
cd "$root"
cmake --preset ps4-openorbis
cmake --build --preset ps4-openorbis -- -k 0
echo "build-ps4-openorbis: $root/build/ps4-openorbis/libddon_reconstruction.a"
