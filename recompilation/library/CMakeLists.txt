# The load/save library (ddon_resource): loads a root's resource file through
# the game's own `load`, saves it through its own `save`, and destroys it,
# outside any test runner. Its interface is include/ddon/resource.h (standard
# headers only); src/ holds its implementation, the engine services the
# loads need (src/engine.cpp, src/host.cpp; src/isolate_posix.cpp forks an
# inner load, src/isolate_other.cpp is Windows', where it cannot) and the SDK stand-ins
# (src/sdk.cpp); roots/ holds the roots it offers, generated from the harness
# report the export was made from. Built on the Linux and Windows hosts.
#
# A program links it with ddon_add_trap_linked_executable(<name> OBJECTS
# <its objects> ddon_resource WHOLE_ARCHIVE LIBRARIES ${DDON_RESOURCE_LIBRARIES}
# ...): the reconstruction goes in whole, so every unit's static constructors
# run and the class registry holds every class a file may name only by a
# string, as in the game.

include(${CMAKE_CURRENT_SOURCE_DIR}/Includes.cmake)  # the folders of the engine headers src/ includes

# zlib: the game linked it with no debug information, so the reconstruction
# declares its API (rArchive's streams call inflate) and the host supplies
# it. Inflate's output is fixed by the format, whatever zlib's version.
find_package(ZLIB REQUIRED GLOBAL)
set(DDON_RESOURCE_LIBRARIES ZLIB::ZLIB PARENT_SCOPE)
# Windows' zlib has a 4-byte uLong where DWARF's stream has 8 bytes: the
# link wraps the three calls the reconstruction makes, and src/zlib-lp64.cpp
# copies the stream between the two layouts around each.
set(ddon_zlib_adapter)
set(ddon_link_options)
if(DDON_PLATFORM STREQUAL "windows")
  set(ddon_zlib_adapter src/zlib-lp64.cpp)
  set(ddon_link_options -Wl,--wrap=inflateInit_ -Wl,--wrap=inflate -Wl,--wrap=inflateEnd)
endif()
set(DDON_RESOURCE_LINK_OPTIONS ${ddon_link_options} PARENT_SCOPE)

file(GLOB ddon_library_roots CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/roots/*.cpp)
add_library(ddon_resource OBJECT
  src/resource.cpp src/host.cpp src/isolate_posix.cpp src/isolate_other.cpp src/engine.cpp src/sdk.cpp
  ${ddon_zlib_adapter} ${ddon_library_roots})
target_include_directories(ddon_resource
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR}/include/ddon
    ${PROJECT_SOURCE_DIR}/src ${DDON_LIBRARY_INCLUDES})
target_link_libraries(ddon_resource PUBLIC ddon_reconstruction ZLIB::ZLIB)
# A root's field dump reads its records' private members, as a debugger
# would.
set_source_files_properties(${ddon_library_roots} PROPERTIES COMPILE_OPTIONS -fno-access-control)
