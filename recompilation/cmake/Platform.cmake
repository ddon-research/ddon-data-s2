# Platform settings, one function per target: compile options and include
# directories only. The sources are the same on every platform.

function(ddon_apply_platform target)
  if(DDON_PLATFORM STREQUAL "linux")
    # The reconstruction assumes the PS4's data model (LP64, SysV, Itanium),
    # which x86_64 Linux shares. The host forced includes rename glibc's
    # thread handles while its headers are parsed and keep libstdc++'s
    # allocator rebinding to C++20's rule; host/sdk stands in for the few SDK
    # headers the units include. -fshort-wchar gives wchar_t the PS4's 2
    # bytes (DWARF's base type), which Linux makes 4: every member after an
    # MT_WCHAR array would move. The sources call no wide-character function
    # of glibc's, whose 4-byte ABI the flag would mismatch.
    target_compile_options(${target} PUBLIC
      --target=x86_64-linux-gnu
      -fshort-wchar
      -fno-rtti -fno-exceptions -w
      "SHELL:-include ${PROJECT_SOURCE_DIR}/host/host-libc.h"
      "SHELL:-include ${PROJECT_SOURCE_DIR}/host/host-stl.h")
    target_include_directories(${target} SYSTEM PUBLIC ${PROJECT_SOURCE_DIR}/host/sdk)
  elseif(DDON_PLATFORM STREQUAL "ps4")
    # orbis-clang++ from SCE_ORBIS_SDK_DIR (the ps4-orbis preset sets it);
    # the SDK's own headers.
    target_compile_options(${target} PUBLIC -fno-rtti -fno-exceptions -w)
  elseif(DDON_PLATFORM STREQUAL "openorbis")
    # Any clang against the open OpenOrbis toolchain (OO_PS4_TOOLCHAIN, the
    # variable its samples use), for builders without the Orbis SDK. Its
    # headers are musl's and libc++'s, as its samples include them. The
    # triple is the PS4's own, which upstream clang knows: OpenOrbis's
    # samples use x86_64-pc-freebsd12-elf, whose 4-byte wchar_t moves every
    # member after an MT_WCHAR array (DWARF's wchar_t is 2 bytes). musl's
    # thread handles meet the reconstruction's as glibc's do on Linux, so
    # host/openorbis-libc.h renames them while libc++ is parsed;
    # _DEFAULT_SOURCE keeps the POSIX calls libc++ makes visible at -std=c++17
    # (musl hides them under __STRICT_ANSI__). host/sdk stands in for the SDK
    # headers OpenOrbis does not ship. host/host-containers.h gives libc++
    # the SDK containers' layout over MtStlAllocator (DWARF's sizes), as
    # host-stl.h does for libstdc++ on Linux.
    if(NOT DEFINED ENV{OO_PS4_TOOLCHAIN})
      message(FATAL_ERROR "openorbis: set OO_PS4_TOOLCHAIN to the OpenOrbis PS4 toolchain")
    endif()
    file(TO_CMAKE_PATH "$ENV{OO_PS4_TOOLCHAIN}" ddon_openorbis)
    if(NOT EXISTS "${ddon_openorbis}/include/c++/v1")
      message(FATAL_ERROR "openorbis: no include/c++/v1 under OO_PS4_TOOLCHAIN (${ddon_openorbis})")
    endif()
    target_compile_options(${target} PUBLIC
      --target=x86_64-scei-ps4
      -fPIC -funwind-tables -fno-rtti -fno-exceptions -w
      -D_DEFAULT_SOURCE
      "SHELL:-isysroot ${ddon_openorbis}"
      "SHELL:-include ${PROJECT_SOURCE_DIR}/host/openorbis-libc.h"
      "SHELL:-include ${PROJECT_SOURCE_DIR}/host/host-containers.h")
    target_include_directories(${target} SYSTEM PUBLIC
      ${ddon_openorbis}/include
      ${ddon_openorbis}/include/c++/v1
      ${PROJECT_SOURCE_DIR}/host/sdk)
  elseif(DDON_PLATFORM STREQUAL "windows")
    # MSYS2's clang64 clang (MinGW target, libc++): the Itanium C++ ABI the
    # PS4 uses, on Windows' LLP64 data model. The forced include gives the
    # reconstruction's own `long` DWARF's 8 bytes after the library headers
    # are parsed; host/sdk stands in for the SDK headers, as on Linux.
    # host/host-containers.h, first, gives libc++ the SDK containers' layout
    # over MtStlAllocator (DWARF's sizes), as host-stl.h does on Linux; its
    # library headers are parsed with the platform's own `long`.
    target_compile_options(${target} PUBLIC
      --target=x86_64-w64-windows-gnu
      -fno-rtti -fno-exceptions -w
      "SHELL:-include ${PROJECT_SOURCE_DIR}/host/host-containers.h"
      "SHELL:-include ${PROJECT_SOURCE_DIR}/host/windows-lp64.h")
    target_include_directories(${target} SYSTEM PUBLIC ${PROJECT_SOURCE_DIR}/host/sdk)
  else()
    message(FATAL_ERROR "DDON_PLATFORM must be linux, windows, ps4 or openorbis, not '${DDON_PLATFORM}'")
  endif()
endfunction()
