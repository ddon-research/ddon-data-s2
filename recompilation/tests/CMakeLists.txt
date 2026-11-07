# The layout test: every root class's size is DWARF's (static_asserts, so the
# test is its compile). main() calls nothing, but an inline body marked `used`
# in a header is emitted here and may reach what the library doesn't define:
# the host programs link it as the sample links, with traps for what's missing.
add_library(ddon_layout_objects OBJECT layout.cpp)
target_link_libraries(ddon_layout_objects PRIVATE ddon_reconstruction)
# A PS4 build has no host to run on: compiling the asserts is the test.
if(NOT DDON_PLATFORM STREQUAL "ps4" AND NOT DDON_PLATFORM STREQUAL "openorbis")
  ddon_add_trap_linked_executable(ddon_layout_test ddon_layout_objects)
  add_test(NAME layout COMMAND ddon_layout_test)
  if(DDON_PLATFORM STREQUAL "windows")
    # libc++'s DLL sits beside MSYS2's clang++; an IDE's CTest run may not
    # have that folder on PATH.
    get_filename_component(ddon_compiler_dir "${CMAKE_CXX_COMPILER}" DIRECTORY)
    set_tests_properties(layout PROPERTIES
      ENVIRONMENT_MODIFICATION "PATH=path_list_prepend:${ddon_compiler_dir}")
  endif()
endif()
