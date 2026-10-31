# DDON reconstruction

C++ source reconstructed from the DWARF debug information of Dragon's Dogma
Online's PS4 build 02020005 (season 2) by ddon-dwarf-reconstructor: the
resource classes' load and save graph, with the types they reach.

- `src/`: the sources, in the original source tree's folders as DWARF
  records them (`DD_ONLINE/`, `MT/`, `XFramework/`, `Middleware/`);
  `src/generated/` holds the files DWARF gives no folder.
- `docs/README.md`: what is reconstructed and what is a stub, the
  prerequisites, and how to build.
- `scripts/`: one build script per platform.
- `tests/`: the layout test.
- `samples/load-resource/`: a program that loads a resource file with the
  library (below, "Load a resource file").
- `host/`: the stand-ins a Linux, Windows or OpenOrbis build needs in place of
  the PS4 SDK. Its `windows-lp64.h` is the Windows preset's host adapter, as
  `host-libc.h` is Linux's and `openorbis-libc.h` OpenOrbis's: the sources
  spell DWARF's 8-byte base types `long` and `unsigned long`, as the original
  source did (`using _Sizet = long unsigned int;`), and Windows' `long` is 4
  bytes. The forced include gives the sources' own `long` 8 bytes after the
  library headers are parsed, and only the MinGW preset uses it.

## Building

Each script runs from a POSIX shell in this folder (`cd` to it first), and
writes a static library and, on Linux and Windows, runs the layout test.

- **Linux**, from a Linux shell. Needs cmake 3.25 or newer, ninja and clang
  17 or newer (`sudo apt install cmake ninja-build clang` on Ubuntu).

  ```sh
  cd <export root> && scripts/build-linux.sh
  ```

- **Windows, native**, from MSYS2's CLANG64 shell, or Git Bash with MSYS2
  installed. Needs cmake 3.25 or newer, ninja and MSYS2's clang64
  (`pacman -S mingw-w64-clang-x86_64-clang mingw-w64-clang-x86_64-cmake mingw-w64-clang-x86_64-ninja`).

  ```sh
  cd <export root> && scripts/build-windows.sh
  ```

- **Windows, through WSL**, from Git Bash or an MSYS2 shell: runs
  `build-linux.sh` in WSL (`DDON_WSL_DISTRO` picks the distribution, default
  WSL's default), with the build directory on WSL's own file system
  (`~/.cache/ddon-recompilation/`). Needs WSL with cmake, ninja and clang in
  the distribution; the script names each one missing and its `apt` line.

  ```sh
  cd <export root> && scripts/build-wsl.sh
  ```

- **PS4**, from Git Bash, with the Orbis SDK's directory in
  `SCE_ORBIS_SDK_DIR` (`--syntax-only` checks each unit only).

  ```sh
  cd <export root> && SCE_ORBIS_SDK_DIR='<Orbis SDK directory>' scripts/build-ps4.sh
  ```

- **PS4 with OpenOrbis**, from MSYS2's CLANG64 shell or Git Bash: any clang 18
  or newer, cmake 3.25 or newer, ninja and the OpenOrbis toolchain (below) in
  `OO_PS4_TOOLCHAIN`.

  ```sh
  cd <export root> && OO_PS4_TOOLCHAIN=<extracted archive>/OpenOrbis/PS4Toolchain scripts/build-ps4-openorbis.sh
  ```

**Without the Orbis SDK**, the PS4 build uses the open
[OpenOrbis PS4 toolchain](https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain)
(v0.5.4 tested). It needs the release archive, not a git clone: download
`toolchain-llvm-18.tar.gz` from the
[v0.5.4 release](https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain/releases/tag/v0.5.4),
extract it, and set `OO_PS4_TOOLCHAIN` to the `OpenOrbis/PS4Toolchain`
directory inside it. A clone's `include/` has only the PS4-specific headers;
libc and libc++ come from the toolchain's build, which only the archive
holds. Then run `scripts/build-ps4-openorbis.sh` with any clang 18 or newer
(MSYS2 clang64's on Windows). Neither toolchain is part of this project.

## Load a resource file

`samples/load-resource/` is a small program that loads one of the game's
resource files with the library, the way the engine does: it opens the file
as an `MtStream`, creates the resource class through its `MtDTI`, and calls
the class's own `load`. Every byte is read by the reconstructed code. The
Linux and Windows builds above build it as
`build/<preset>/samples/load-resource/load-resource` (`.exe` on Windows);
the PS4 builds leave it out, having no host to run it on.

```sh
build/linux-clang/samples/load-resource/load-resource rGUIMessage <rom>/quest/q60000012/ui/00_message/quest/q60000012.gmd
```

```text
rGUIMessage: load returned true, read 8425 of 8425 bytes
```

Run with no arguments, it prints its usage and the root classes it offers,
`rGUIMessage` first: those that loaded files whole when this export was
made. The line says whether `load` returned true and how many of the file's
bytes it consumed; the exit code is 0 for a whole load and 1 otherwise. A
load that reaches a function the reconstruction does not have stops there
and names it (exit 3): the build writes such a function for each one the
library lacks (`traps.cmake`). A sub-resource the file names (a texture, a
model) is another file: the program hands the load an empty placeholder and
says so.

- `--dump` prints the loaded records' fields as JSON, for a table class
  (one with `getDataNum` and `getData`).
- `--save <out>` writes the class's own `save` output, for a class that has
  one. Compare it with the file for a round trip:

  ```sh
  load-resource rGUIMessage q60000012.gmd --save q60000012.out.gmd && cmp q60000012.gmd q60000012.out.gmd
  ```

The game's files never ship with this project. `ctest` runs the program
with no file (its usage, exit 2), and loads a file of yours when
`DDON_SAMPLE_ROOT` and `DDON_SAMPLE_FILE` name one.

## VSCode

Open this folder in VSCode with the recommended extensions (CMake Tools and
clangd, `.vscode/extensions.json`). CMake Tools lists the presets
`linux-clang`, `windows-clang`, `ps4-orbis` and `ps4-openorbis`; pick one,
then Build, and run the layout test with CTest (Linux and Windows; a PS4
build compiles the test's static asserts, with nothing to run). The presets
take the compiler from `DDON_CXX`, else MSYS2 clang64's on Windows and
`clang++` elsewhere; `ps4-orbis` needs `SCE_ORBIS_SDK_DIR` and
`ps4-openorbis` `OO_PS4_TOOLCHAIN` in VSCode's environment. Each configure
writes `build/<preset>/compile_commands.json`, and CMake Tools copies the
active one to `build/compile_commands.json`, where clangd reads it.
