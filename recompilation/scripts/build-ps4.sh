#!/usr/bin/env bash
# Compiles every unit with the Orbis SDK's clang (SCE_ORBIS_SDK_DIR) for the
# PS4, and archives the objects into a static library when the SDK's
# archiver is found; with --syntax-only it only checks each unit. Runs in
# Git Bash on Windows, where the SDK lives. JOBS sets the parallel compiles.
set -uo pipefail
root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
[ -n "${SCE_ORBIS_SDK_DIR:-}" ] || { echo "build-ps4: set SCE_ORBIS_SDK_DIR to the Orbis SDK" >&2; exit 2; }
bin="$SCE_ORBIS_SDK_DIR/host_tools/bin"
cxx="$bin/orbis-clang++.exe"
[ -x "$cxx" ] || cxx="$bin/orbis-clang++"
[ -x "$cxx" ] || { echo "build-ps4: no orbis-clang++ under $bin" >&2; exit 2; }
ar="$bin/orbis-ar.exe"
[ -x "$ar" ] || ar="$bin/orbis-ar"
mode=library
[ "${1:-}" = "--syntax-only" ] && mode=syntax
[ -x "$ar" ] || { [ "$mode" = library ] && echo "build-ps4: no orbis-ar under $bin: checking syntax only" >&2; mode=syntax; }
out="$root/build/ps4"
rm -rf "$out/obj"
mkdir -p "$out/obj"
flags=(-std=c++17 -O2 -fno-rtti -fno-exceptions -w)

compile() {
  local unit="$1" object="$out/obj/${1//\//__}.o"
  if [ "$mode" = syntax ]; then
    "$cxx" "${flags[@]}" -fsyntax-only "$root/src/$unit" 2> "$object.err"
  else
    "$cxx" "${flags[@]}" -c "$root/src/$unit" -o "$object" 2> "$object.err"
  fi && rm -f "$object.err"
}

running=0
while IFS= read -r unit; do
  compile "$unit" &
  running=$((running + 1))
  if [ "$running" -ge "${JOBS:-8}" ]; then
    wait -n
    running=$((running - 1))
  fi
done < "$root/cmake/units.txt"
wait

units="$(wc -l < "$root/cmake/units.txt")"
failed="$(find "$out/obj" -name '*.err' | wc -l)"
echo "build-ps4: $((units - failed)) of $units units compiled ($mode); errors in $out/obj/*.err"
[ "$failed" -eq 0 ] || exit 1
# The layout test: its static asserts are DWARF's sizes, so compiling it is
# the test (a PS4 build has no host to run it on).
"$cxx" "${flags[@]}" -fsyntax-only -I "$root/tests" "$root/tests/layout.cpp" || { echo "build-ps4: the layout test failed" >&2; exit 1; }
echo "build-ps4: the layout test compiled"
if [ "$mode" = library ]; then
  rm -f "$out/libddon_reconstruction.a"
  (cd "$out/obj" && find . -name '*.o' | sort | xargs "$ar" rcs "$out/libddon_reconstruction.a")
  echo "build-ps4: $out/libddon_reconstruction.a"
fi
