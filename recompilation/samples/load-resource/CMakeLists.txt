# The load-resource sample: a program that loads one resource file with the
# reconstructed library (README.md, "Load a resource file"). Built on the
# Linux and Windows hosts; a PS4 build has no host to run it on.

include(${CMAKE_CURRENT_SOURCE_DIR}/Includes.cmake)  # the folders of the engine headers the host files include

# The sample's own files, the roots it offers (roots.cpp, roots/), and the
# engine services from the harness that tested these loads (host/).
file(GLOB ddon_sample_roots CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/roots/*.cpp)
add_library(load_resource_objects OBJECT
  main.cpp host.cpp roots.cpp host/fixtures.cpp ${ddon_sample_roots})
target_include_directories(load_resource_objects PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/host ${PROJECT_SOURCE_DIR}/src ${DDON_SAMPLE_INCLUDES})
target_link_libraries(load_resource_objects PRIVATE ddon_reconstruction)
# A root's field dump reads its records' private members, as a debugger
# would.
set_source_files_properties(${ddon_sample_roots} PROPERTIES COMPILE_OPTIONS -fno-access-control)

# The link. host/fixtures.cpp replaces the library's stub of the class
# registry's constructor, MtDTI::MtDTI (its body did not reconstruct; the
# export checked that the fixture replaces no reconstructed body): the
# sample's objects come before the library, and the linker keeps their
# definition. Windows's linker warns of the duplicate; the fixture's runs.
# Every function the reconstruction lacks becomes one that stops the load and
# names it (cmake/traps.cmake).
ddon_add_trap_linked_executable(load-resource load_resource_objects -Wl,--allow-multiple-definition)
get_filename_component(ddon_compiler_dir "${CMAKE_CXX_COMPILER}" DIRECTORY)

# CTest: with no file, the program prints its usage and exits 2. With
# DDON_SAMPLE_ROOT and DDON_SAMPLE_FILE set (game data never ships), it
# loads that file and must read it whole.
add_test(NAME load_resource_usage
  COMMAND ${CMAKE_COMMAND} -DPROGRAM=$<TARGET_FILE:load-resource> -P ${CMAKE_CURRENT_SOURCE_DIR}/expect.cmake)
add_test(NAME load_resource_file
  COMMAND ${CMAKE_COMMAND} -DPROGRAM=$<TARGET_FILE:load-resource> -DFILE_TEST=ON -P ${CMAKE_CURRENT_SOURCE_DIR}/expect.cmake)
set_tests_properties(load_resource_file PROPERTIES SKIP_REGULAR_EXPRESSION "skipped: set DDON_SAMPLE_ROOT and DDON_SAMPLE_FILE")
if(DDON_PLATFORM STREQUAL "windows")
  # libc++'s DLL sits beside MSYS2's clang++.
  set_tests_properties(load_resource_usage load_resource_file PROPERTIES
    ENVIRONMENT_MODIFICATION "PATH=path_list_prepend:${ddon_compiler_dir}")
endif()
