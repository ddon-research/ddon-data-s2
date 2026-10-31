cmake_minimum_required(VERSION 3.25)

# The clang presets take the compiler from DDON_CXX, which the build scripts
# set. An IDE that opens the folder without them (VSCode's CMake Tools) leaves
# it empty: then the host's default clang, MSYS2 clang64's on Windows
# (DDON_MSYS2 names its root).
if(NOT CMAKE_CXX_COMPILER)
  if(CMAKE_HOST_WIN32)
    set(ddon_msys2 "C:/msys64")
    if(DEFINED ENV{DDON_MSYS2})
      file(TO_CMAKE_PATH "$ENV{DDON_MSYS2}" ddon_msys2)
    endif()
    set(CMAKE_CXX_COMPILER "${ddon_msys2}/clang64/bin/clang++.exe")
  else()
    set(CMAKE_CXX_COMPILER clang++)
  endif()
endif()

project(ddon_reconstruction LANGUAGES CXX)

# The platform is a setting (the presets set it), never a fork of the sources.
set(DDON_PLATFORM "linux" CACHE STRING "Target platform: linux (clang, LP64 host), windows (MSYS2 clang64), ps4 (orbis-clang++) or openorbis (clang and the OpenOrbis toolchain)")
set_property(CACHE DDON_PLATFORM PROPERTY STRINGS linux windows ps4 openorbis)
option(DDON_BUILD_TESTS "Build the layout tests" ON)

include(cmake/Sources.cmake)
include(cmake/Platform.cmake)

add_library(ddon_reconstruction STATIC ${DDON_SOURCES})
target_compile_features(ddon_reconstruction PUBLIC cxx_std_17)
set_target_properties(ddon_reconstruction PROPERTIES CXX_EXTENSIONS OFF)
ddon_apply_platform(ddon_reconstruction)

if(DDON_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

# The load-resource sample (samples/load-resource): loads a resource file
# with the library. It runs on the build's own host, so the PS4 presets
# leave it out.
option(DDON_BUILD_SAMPLES "Build the load-resource sample (Linux and Windows)" ON)
if(DDON_BUILD_SAMPLES AND (DDON_PLATFORM STREQUAL "linux" OR DDON_PLATFORM STREQUAL "windows"))
  add_subdirectory(samples/load-resource)
endif()
