# The reconstruction

## What it is

1220 headers and 1157 units reconstructed from DWARF and the ELF: every class's declaration, layout and virtual table as DWARF records them, and each method's body where the generator could render it.

- **Reconstructed:** 18163 bodies rendered from the ELF and proven equal to it by recompiling with the game's own compiler release (SDK 2.500), and 3903 rendered bodies the generator marks approximate.
- **Stubs:** 18730 bodies are stubs: they start with `DDON_STUB("Q::f")`, a macro that is empty unless a build defines it (a test host can record which stubs a run reached).

The generator's notes (its inferences, rulings, addresses, refusals and oracle verdicts) are stripped; only comments a reader of the source needs stay (file sections, member offsets, vtable slots, namespace ends, stub markers).

## The source tree

`src/` follows the original folders as DWARF records them. A header keeps its own name under its classes' original folder; several of our headers may come from one original file. A header with the name of another in the same folder carries its bundle folder in its name. These files have no original folder, so they live under `src/generated/`:

- `src/generated/rCharacterEditCameraParam/cPCGraphicOption.h`: no class with a decl_file
- `src/generated/rCharacterEditCameraParam/mouse.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include/mouse.h
- `src/generated/rCharacterEditCameraParam/nEnemyAction.h`: no class with a decl_file
- `src/generated/rCharacterEditCameraParam/nErosionEnemySmall.h`: no class with a decl_file
- `src/generated/rCharacterEditCameraParam/nStatusEnemy.h`: no class with a decl_file
- `src/generated/rCharacterEditCameraParam/user_service_api.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include/user_service/user_service_api.h
- `src/generated/shared/ChatMsgType.h`: no class with a decl_file
- `src/generated/shared/DDOAllocator.h`: no class with a decl_file
- `src/generated/shared/Error.h`: no class with a decl_file
- `src/generated/shared/FrameworkAllocator.h`: no class with a decl_file
- `src/generated/shared/GpCourse.h`: no class with a decl_file
- `src/generated/shared/GpCourseEffect.h`: no class with a decl_file
- `src/generated/shared/Job.h`: no class with a decl_file
- `src/generated/shared/_rtc.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include/_rtc.h
- `src/generated/shared/audioout.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include/audioout.h
- `src/generated/shared/basegfxcontext.cpp`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnmx/basegfxcontext.h
- `src/generated/shared/basegfxcontext.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnmx/basegfxcontext.h
- `src/generated/shared/boolInVec.cpp`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/vectormath/cpp/boolInVec.h
- `src/generated/shared/boolInVec.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/vectormath/cpp/boolInVec.h
- `src/generated/shared/buffer.cpp`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnm/buffer.h
- `src/generated/shared/buffer.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnm/buffer.h
- `src/generated/shared/commandbuffer.cpp`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnm/commandbuffer.h
- `src/generated/shared/commandbuffer.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnm/commandbuffer.h
- `src/generated/shared/constantcommandbuffer.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnm/constantcommandbuffer.h
- `src/generated/shared/constants.h`: no class with a decl_file
- `src/generated/shared/dataformats.cpp`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnm/dataformats.h
- `src/generated/shared/dataformats.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnm/dataformats.h
- `src/generated/shared/dispatchcommandbuffer.cpp`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnm/dispatchcommandbuffer.h
- `src/generated/shared/dispatchcommandbuffer.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnm/dispatchcommandbuffer.h
- `src/generated/shared/dispatchdraw.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnmx/dispatchdraw.h
- `src/generated/shared/drawcommandbuffer.cpp`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnm/drawcommandbuffer.h
- `src/generated/shared/drawcommandbuffer.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnm/drawcommandbuffer.h
- `src/generated/shared/floatInVec.cpp`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/vectormath/cpp/floatInVec.h
- `src/generated/shared/floatInVec.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/vectormath/cpp/floatInVec.h
- `src/generated/shared/gpumem.cpp`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnm/gpumem.h
- `src/generated/shared/gpumem.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnm/gpumem.h
- `src/generated/shared/ime_dialog.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include/ime_dialog.h
- `src/generated/shared/ime_types.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include/libime/ime_types.h
- `src/generated/shared/json2.cpp`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include/json2.h
- `src/generated/shared/json2.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include/json2.h
- `src/generated/shared/lwcue_base.cpp`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnmx/lwcue_base.h
- `src/generated/shared/lwcue_base.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnmx/lwcue_base.h
- `src/generated/shared/lwcue_graphics.cpp`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnmx/lwcue_graphics.h
- `src/generated/shared/lwcue_graphics.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnmx/lwcue_graphics.h
- `src/generated/shared/lwgfxcontext.cpp`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnmx/lwgfxcontext.h
- `src/generated/shared/lwgfxcontext.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnmx/lwgfxcontext.h
- `src/generated/shared/nAbility.h`: no class with a decl_file
- `src/generated/shared/nAction.h`: no class with a decl_file
- `src/generated/shared/nCameraGame.h`: no class with a decl_file
- `src/generated/shared/nCatch.h`: no class with a decl_file
- `src/generated/shared/nCharacterEdit.h`: no class with a decl_file
- `src/generated/shared/nCollisionDefine.h`: no class with a decl_file
- `src/generated/shared/nDDOGame.h`: no class with a decl_file
- `src/generated/shared/nDDOIO.cpp`: no class with a decl_file
- `src/generated/shared/nDDOIO.h`: no class with a decl_file
- `src/generated/shared/nDDOMath.cpp`: no class with a decl_file
- `src/generated/shared/nDDOMath.h`: no class with a decl_file
- `src/generated/shared/nDDOModel.h`: no class with a decl_file
- `src/generated/shared/nDDOShader.h`: no class with a decl_file
- `src/generated/shared/nEnemy.h`: no class with a decl_file
- `src/generated/shared/nEnemyID.h`: no class with a decl_file
- `src/generated/shared/nErosionEnemy.cpp`: no class with a decl_file
- `src/generated/shared/nErosionEnemy.h`: no class with a decl_file
- `src/generated/shared/nErosionEnemyBase.cpp`: no class with a decl_file
- `src/generated/shared/nErosionEnemyBase.h`: no class with a decl_file
- `src/generated/shared/nGUIAim.h`: no class with a decl_file
- `src/generated/shared/nGUIHudJob10.h`: no class with a decl_file
- `src/generated/shared/nGroup.h`: no class with a decl_file
- `src/generated/shared/nHuman.h`: no class with a decl_file
- `src/generated/shared/nKeyCustom.h`: no class with a decl_file
- `src/generated/shared/nSequence.h`: no class with a decl_file
- `src/generated/shared/nSoundZone.cpp`: no class with a decl_file
- `src/generated/shared/nSoundZone.h`: no class with a decl_file
- `src/generated/shared/nStamina.h`: no class with a decl_file
- `src/generated/shared/nUnicode.cpp`: no class with a decl_file
- `src/generated/shared/nUnicode.h`: no class with a decl_file
- `src/generated/shared/nWeapon.h`: no class with a decl_file
- `src/generated/shared/nZoneUnitCtrl.h`: no class with a decl_file
- `src/generated/shared/ngs2_sce_mastering.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/ngs2/ngs2_sce_mastering.h
- `src/generated/shared/ngs2_sce_reverb.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/ngs2/ngs2_sce_reverb.h
- `src/generated/shared/ngs2_system.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/ngs2/ngs2_system.h
- `src/generated/shared/np_auth.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include/np/np_auth.h
- `src/generated/shared/np_common.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include/np/np_common.h
- `src/generated/shared/np_npid.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include/np/np_npid.h
- `src/generated/shared/np_party.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include/np/np_party.h
- `src/generated/shared/np_ranking.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include/np/np_ranking.h
- `src/generated/shared/np_trophy.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include/np/np_trophy.h
- `src/generated/shared/regs.cpp`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnm/regs.h
- `src/generated/shared/regs.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnm/regs.h
- `src/generated/shared/rendertarget.cpp`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnm/rendertarget.h
- `src/generated/shared/rendertarget.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnm/rendertarget.h
- `src/generated/shared/save_data.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include/save_data.h
- `src/generated/shared/texture.cpp`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnm/texture.h
- `src/generated/shared/texture.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/gnm/texture.h
- `src/generated/shared/vecidx_aos.cpp`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/vectormath/cpp/vecidx_aos.h
- `src/generated/shared/vecidx_aos.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/vectormath/cpp/vecidx_aos.h
- `src/generated/shared/vectormath_aos.cpp`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/vectormath/cpp/vectormath_aos.h
- `src/generated/shared/vectormath_aos.h`: declared outside the sources: C:/Program Files (x86)/SCE/ORBIS SDKs/2.500/target/include_common/vectormath/cpp/vectormath_aos.h

`export.json` records every file's original path.

## Prerequisites

- **Linux:** cmake 3.25 or newer, ninja, clang (17 or newer; 22 tested) and
  libstdc++, on x86_64: the reconstruction assumes the PS4's LP64 data model,
  and the build gives `wchar_t` the PS4's 2 bytes (`-fshort-wchar`).
- **PS4:** the Orbis SDK, its directory in `SCE_ORBIS_SDK_DIR`, run from Git
  Bash. The SDK and its headers are not part of this project.
- **PS4 without the Orbis SDK:** the open OpenOrbis PS4 toolchain (v0.5.4
  tested; GPL-3.0; its headers are musl's and libc++'s) from its release
  archive `toolchain-llvm-18.tar.gz`, not a git clone (a clone has no libc or
  libc++ headers), with `OO_PS4_TOOLCHAIN` set to the extracted
  `OpenOrbis/PS4Toolchain` directory, and cmake 3.25 or newer, ninja and a clang 18 or newer
  (MSYS2 clang64's on Windows): OpenOrbis ships no compiler. The build uses
  the PS4's own triple, `x86_64-scei-ps4`, not its samples'
  `x86_64-pc-freebsd12-elf`, whose 4-byte `wchar_t` moves the members after an
  `MT_WCHAR` array; `host/openorbis-libc.h` keeps musl's thread handles apart
  from the reconstruction's. The toolchain is not part of this project.
- **Windows:** cmake 3.25 or newer, ninja, and MSYS2 with its clang64
  environment (`pacman -S mingw-w64-clang-x86_64-clang`: clang, lld and libc++;
  `DDON_MSYS2` names the MSYS2 root, default `C:/msys64`), run from Git Bash.
  The MinGW target keeps the PS4's Itanium C++ ABI; MSVC's ABI lays out
  derived classes differently. Windows is LLP64, so `host/windows-lp64.h`, a
  forced include, gives the reconstruction's `long` DWARF's 64 bits after the
  library headers are parsed.

## Building

```sh
scripts/build-linux.sh               # static library build/linux-clang/libddon_reconstruction.a, then the layout test
scripts/build-windows.sh             # build/windows-clang/libddon_reconstruction.a with MSYS2 clang64, then the layout test
scripts/build-wsl.sh                 # from Git Bash or MSYS2: build-linux.sh inside WSL, building under ~/.cache/ddon-recompilation/ there
scripts/build-ps4.sh                 # build/ps4/libddon_reconstruction.a with orbis-clang++ and orbis-ar
scripts/build-ps4.sh --syntax-only   # each unit checked only
scripts/build-ps4-openorbis.sh       # build/ps4-openorbis/libddon_reconstruction.a with clang and OpenOrbis
```

The platform is a CMake setting (`DDON_PLATFORM`, from the presets); the
sources are the same on every platform. `host/` holds what a Linux, Windows
or OpenOrbis build uses in place of the SDK: two forced includes that let
glibc and libstdc++ live beside the reconstruction's own declarations, the
Windows and OpenOrbis forced includes, and stand-ins that declare the few SDK
functions the units call. A PS4 build has nothing to run the layout test on:
the `ps4-orbis` and `ps4-openorbis` presets compile its static asserts, which
is the test.

## VSCode

Open the project's folder with the recommended extensions (CMake Tools and
clangd, `.vscode/extensions.json`). CMake Tools lists the four presets
(`linux-clang`, `windows-clang`, `ps4-orbis`, `ps4-openorbis`): select one,
then Configure, Build, and Run Tests (CTest, on Linux and Windows). Without
`DDON_CXX` the clang presets use MSYS2 clang64's compiler on Windows and
`clang++` elsewhere; `ps4-orbis` reads `SCE_ORBIS_SDK_DIR` and
`ps4-openorbis` `OO_PS4_TOOLCHAIN` from VSCode's environment. CMake Tools
copies the active preset's `compile_commands.json` to `build/`, where clangd
finds every unit's flags.
