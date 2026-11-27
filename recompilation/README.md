# DDON reconstruction

C++ source reconstructed from the DWARF debug information of Dragon's Dogma
Online's PS4 build 02020005 (season 2): the
resource classes' load and save graph, with the types they reach.

- `src/`: the sources, in the original source tree's folders as DWARF
  records them (`DD_ONLINE/`, `MT/`, `XFramework/`, `Middleware/`);
  `src/generated/` holds the files DWARF gives no folder.
- `docs/README.md`: what is reconstructed and what is a stub, the
  prerequisites, and how to build.
- `scripts/`: one build script per platform.
- `tests/`: the layout test.
- `library/`: the load/save library, which loads and saves the game's
  resource files with the reconstruction (below, "The load/save library").
- `samples/load-resource/`: a program that loads a resource file with it
  (below, "Load a resource file").
- `host/`: the stand-ins a Linux, Windows or OpenOrbis build needs in place of
  the PS4 SDK. Its `windows-lp64.h` is the Windows preset's host adapter, as
  `host-libc.h` is Linux's and `openorbis-libc.h` OpenOrbis's: the sources
  spell DWARF's 8-byte base types `long` and `unsigned long`, as the original
  source did (`using _Sizet = long unsigned int;`), and Windows' `long` is 4
  bytes. The forced include gives the sources' own `long` 8 bytes after the
  library headers are parsed, and only the MinGW preset uses it.

## Progress

How much of the binary this reconstruction holds, counted when the export was made.

- **Methods:** 54,558 of the 72,425 methods the sources define are rendered, with a body (75%); the binary has 81,692 functions with code. Rendered is the sum of the first five counts:
  - proven: 26,907, equal to the binary by recompiling them with the game's own compiler release;
  - approximate: 6,376, rendered from the binary but not proven equal to it;
  - recorded: 1,098, written by hand and checked against the binary or by loading their resources' files;
  - empty: 2,415, where the binary's is a single return;
  - no code in the binary: 17,762 (inline bodies checked where they are inlined, and saves derived from a load);
  - without a body: 17,867, of them 17,312 stubs and 555 not written.
- **Classes:** of the 10,697 classes with methods in the sources, 5,851 are complete (every method has a body, 54%), 2,902 partial and 1,944 left; the binary defines 19,734 classes.
- **Resources:** 92 of the 93 resource classes tested load every file of theirs (98%), of the 291 the sources hold; 60,626 of their 60,638 files load whole (99%). 20,551 files save back byte for byte through their class's own save, and 41,847 through a save derived from its load.

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

## The load/save library

`library/` is a static set of objects, the CMake target `ddon_resource`, that
loads one of the game's resource files the way the engine does: it opens the
file as an `MtStream`, creates the resource class through its `MtDTI`, sets
its game path, and calls the class's own `load`; it saves through the class's
own `save`. Every byte is read and written by the reconstructed code. Its
interface is `library/include/ddon/resource.h` (C++17, standard headers
only, no exceptions): `ddon::load_file`, `ddon::save`, `ddon::destroy`, and a
`Status` for each result (`ok` is a whole load: `load` returned true, every
byte read, no stub reached).

A program links it with the reconstruction whole, so every unit's static
constructors run and the class registry holds every class, as in the game:

```cmake
add_library(my_objects OBJECT main.cpp)
target_link_libraries(my_objects PRIVATE ddon_resource)
ddon_add_trap_linked_executable(my-program
  OBJECTS my_objects ddon_resource WHOLE_ARCHIVE
  LIBRARIES ${DDON_RESOURCE_LIBRARIES}
  LINK_OPTIONS -Wl,--allow-multiple-definition ${DDON_RESOURCE_LINK_OPTIONS})
```

A load that reaches a function the reconstruction does not have stops there
and names it: the build writes such a function for each one the library
lacks (`cmake/traps.cmake`). A missing symbol the program calls is a
function; one it only takes the address of is a function or an object as
the game's symbol table says (`cmake/symbol-kinds.txt`), and one in neither
is a function, which the build's output names. A missing object is zeroed
storage. A function of the library's own host (a name
starting `ddon_`) is never trapped: the build fails and names it. The
library links zlib (`zlib1g-dev` on Ubuntu; MSYS2's clang64 has it), which
the game linked with no debug information.

An inner resource the file names (a texture, an archive's entry) is loaded
by the library's resource manager under `--data`'s folder. `LoadOptions::inner`
chooses how: `in_place` runs its class's own `load` in the same process (a
stub reached inside it fails the root, `stub reached`); `placeholder` loads
none; `isolate`, the library's default, runs each inner load in a child
process first, so a stub or a trap inside it stays there and the root gets
the placeholder. It needs `fork`: the Windows build
answers `unsupported option`.

## Load a resource file

`samples/load-resource/` is a small program over the library. The Linux and
Windows builds above build it as
`build/<preset>/samples/load-resource/load-resource` (`.exe` on Windows); the
PS4 builds leave both out, having no host to run them on.

```sh
build/linux-clang/samples/load-resource/load-resource rStageList <rom>/base/scr/stage_list.slt --save stage_list.out.slt
```

```text
set-up reached: MtCriticalSection::MtCriticalSection
rStageList: ok, read 6319 of 6319 bytes
save (own): ok, 6319 bytes to stage_list.out.slt: round trip ok
```

Run with no arguments, it prints its usage and the root classes it offers,
`rGUIMessage` first: those that loaded files whole when this export was
made. The line gives the load's status and how many of the file's bytes it
consumed, then each stub reached and each inner request; the exit code is 0
for a whole load (and a round trip with `--save`), 1 otherwise, and 3 when
the load reached a function the reconstruction lacks.

- `--data <rom>`: the game's `rom` folder. The file's game path and its
  inner files come from it.
- `--inner in-place|placeholder|isolate`: how inner resources load
  (default `isolate`, the library's own, on Linux; `in-place` on Windows,
  which cannot isolate).
- `--save <out>`: saves the loaded resource through its own `save`, writes
  the bytes to `<out>`, and compares them with the file (`round trip ok`, or
  the first difference).
- `--list <file>`: loads each path the file lists, one line each.

The game's files never ship with this project. `ctest` runs the program
with no file (its usage, exit 2), and loads (`load_resource_file`) and
round-trips (`load_resource_round_trip`) a file of yours when
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
