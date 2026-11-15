# The load-resource sample: a program that loads one resource file with the
# load/save library (library/, README.md "Load a resource file"). Built on
# the Linux and Windows hosts; a PS4 build has no host to run it on.

add_library(load_resource_objects OBJECT main.cpp)
target_link_libraries(load_resource_objects PRIVATE ddon_resource)

# The link. The library's src/engine.cpp replaces the reconstruction's stub
# of the class registry's constructor, MtDTI::MtDTI (its body did not
# reconstruct; the export checked that the fixture replaces no reconstructed
# body): the program's objects come before the reconstruction, and the
# linker keeps their definition. Windows's linker warns of the duplicate;
# the fixture's runs. Every function the reconstruction lacks becomes one
# that stops the load and names it (cmake/traps.cmake).
ddon_add_trap_linked_executable(load-resource
  OBJECTS load_resource_objects ddon_resource WHOLE_ARCHIVE
  LIBRARIES ${DDON_RESOURCE_LIBRARIES}
  LINK_OPTIONS -Wl,--allow-multiple-definition ${DDON_RESOURCE_LINK_OPTIONS})
get_filename_component(ddon_compiler_dir "${CMAKE_CXX_COMPILER}" DIRECTORY)

# CTest: with no file, the program prints its usage and exits 2. With
# DDON_SAMPLE_ROOT and DDON_SAMPLE_FILE set (game data never ships), it
# loads that file and must read it whole; load_resource_round_trip saves it
# too and must give the file's bytes back.
add_test(NAME load_resource_usage
  COMMAND ${CMAKE_COMMAND} -DPROGRAM=$<TARGET_FILE:load-resource> -P ${CMAKE_CURRENT_SOURCE_DIR}/expect.cmake)
add_test(NAME load_resource_file
  COMMAND ${CMAKE_COMMAND} -DPROGRAM=$<TARGET_FILE:load-resource> -DFILE_TEST=ON -P ${CMAKE_CURRENT_SOURCE_DIR}/expect.cmake)
add_test(NAME load_resource_round_trip
  COMMAND ${CMAKE_COMMAND} -DPROGRAM=$<TARGET_FILE:load-resource> -DFILE_TEST=ON -DSAVE_TO=${CMAKE_CURRENT_BINARY_DIR}/round-trip.out
    -P ${CMAKE_CURRENT_SOURCE_DIR}/expect.cmake)
set_tests_properties(load_resource_file load_resource_round_trip PROPERTIES
  SKIP_REGULAR_EXPRESSION "skipped: set DDON_SAMPLE_ROOT and DDON_SAMPLE_FILE")
if(DDON_PLATFORM STREQUAL "windows")
  # libc++'s DLL sits beside MSYS2's clang++.
  set_tests_properties(load_resource_usage load_resource_file load_resource_round_trip PROPERTIES
    ENVIRONMENT_MODIFICATION "PATH=path_list_prepend:${ddon_compiler_dir}")
endif()
