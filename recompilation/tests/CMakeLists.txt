# The layout test: every root class's size is DWARF's (static_asserts, so the
# test is its compile), and the program links against the library.
if(DDON_PLATFORM STREQUAL "ps4" OR DDON_PLATFORM STREQUAL "openorbis")
  # A PS4 build has no host to run on: compiling the asserts is the test.
  add_library(ddon_layout_test OBJECT layout.cpp)
  target_link_libraries(ddon_layout_test PRIVATE ddon_reconstruction)
else()
  add_executable(ddon_layout_test layout.cpp)
  target_link_libraries(ddon_layout_test PRIVATE ddon_reconstruction)
  add_test(NAME layout COMMAND ddon_layout_test)
  if(DDON_PLATFORM STREQUAL "windows")
    # libc++'s DLL sits beside MSYS2's clang++; an IDE's CTest run may not
    # have that folder on PATH.
    get_filename_component(ddon_compiler_dir "${CMAKE_CXX_COMPILER}" DIRECTORY)
    set_tests_properties(layout PROPERTIES
      ENVIRONMENT_MODIFICATION "PATH=path_list_prepend:${ddon_compiler_dir}")
  endif()
endif()
