#!/usr/bin/env bash
# Builds the reconstruction on Linux inside WSL, from Git Bash or an MSYS2
# shell on Windows: runs scripts/build-linux.sh in a WSL distribution
# (DDON_WSL_DISTRO, default WSL's default one), which needs cmake (3.25 or
# newer), ninja and clang there. The sources stay where they are; the build
# directory goes on WSL's own file system
# (~/.cache/ddon-recompilation/<hash of this folder>/linux-clang), since every
# write under /mnt/<drive> crosses to Windows.
set -euo pipefail
root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
command -v wsl.exe >/dev/null || { echo "build-wsl: wsl.exe not found; install WSL and a distribution (wsl --install -d Ubuntu)" >&2; exit 2; }
command -v cygpath >/dev/null || { echo "build-wsl: run this from Git Bash or an MSYS2 shell (no cygpath)" >&2; exit 2; }
windows_root="$(cygpath -m "$root")"
wsl=(wsl.exe)
[ -z "${DDON_WSL_DISTRO:-}" ] || wsl+=(-d "$DDON_WSL_DISTRO")
# Inside WSL: the root's Linux path, the tools, then build-linux.sh with the
# build directory on WSL's file system.
inside='set -euo pipefail
root="$(wslpath -u "$1")"
missing=0
need() {
  command -v "$1" >/dev/null || { echo "build-wsl: $1 not found in WSL; install it with: sudo apt install $2" >&2; missing=1; }
}
need cmake cmake
need ninja ninja-build
clang=""
for candidate in clang++-22 clang++-21 clang++-20 clang++; do
  if command -v "$candidate" >/dev/null; then clang="$candidate"; break; fi
done
[ -n "$clang" ] || { echo "build-wsl: no clang++ in WSL; install it with: sudo apt install clang" >&2; missing=1; }
[ "$missing" -eq 0 ] || exit 2
hash="$(printf %s "$root" | sha256sum | cut -c1-16)"
export DDON_BUILD_DIR="${XDG_CACHE_HOME:-$HOME/.cache}/ddon-recompilation/$hash/linux-clang"
echo "build-wsl: building $root in $DDON_BUILD_DIR"
exec bash "$root/scripts/build-linux.sh"'
# MSYS would rewrite the arguments that look like paths.
MSYS_NO_PATHCONV=1 MSYS2_ARG_CONV_EXCL='*' "${wsl[@]}" -e bash -c "$inside" build-wsl "$windows_root"
