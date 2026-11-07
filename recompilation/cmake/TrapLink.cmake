# A host program linked against the library, with a definition for every symbol
# its link leaves undefined (traps.cmake). The headers' inline bodies, the
# library and the program's own files can all reach a function or a static
# member the reconstruction has no definition for.

set(DDON_TRAPS_SCRIPT ${CMAKE_CURRENT_LIST_DIR}/traps.cmake)

# ddon_add_trap_linked_executable(<name> <object library> [<link option>...]):
# the program <name> from the object library's objects, the library and
# <name>-traps.cpp, which a trial link of the same objects writes at build time.
# The object library's folder needs an extern "C" ddon_trap(const char*).
function(ddon_add_trap_linked_executable name objects)
  include(CheckLinkerFlag)
  set(link_options ${ARGN})
  if(DDON_PLATFORM STREQUAL "linux")
    list(PREPEND link_options --target=x86_64-linux-gnu)
  elseif(DDON_PLATFORM STREQUAL "windows")
    list(PREPEND link_options --target=x86_64-w64-windows-gnu)
  endif()
  check_linker_flag(CXX -fuse-ld=lld DDON_TRAP_LLD)
  if(DDON_TRAP_LLD)
    list(APPEND link_options -fuse-ld=lld)
  endif()

  get_filename_component(compiler_dir "${CMAKE_CXX_COMPILER}" DIRECTORY)
  find_program(DDON_CXXFILT NAMES llvm-cxxfilt llvm-cxxfilt-22 llvm-cxxfilt-21 llvm-cxxfilt-20 c++filt
    HINTS ${compiler_dir} REQUIRED)
  set(trial_options ${link_options} -Wl,--no-demangle)
  if(DDON_TRAP_LLD)
    list(APPEND trial_options -Wl,--error-limit=0)
  endif()
  set(work ${CMAKE_CURRENT_BINARY_DIR}/${name}-trial)
  set(traps ${CMAKE_CURRENT_BINARY_DIR}/${name}-traps.cpp)
  list(JOIN trial_options "\n" trial_lines)
  file(GENERATE OUTPUT ${work}/link-args.txt CONTENT
    "$<JOIN:$<TARGET_OBJECTS:${objects}>,\n>\n$<TARGET_FILE:ddon_reconstruction>\n${trial_lines}\n")
  add_custom_command(
    OUTPUT ${traps}
    COMMAND ${CMAKE_COMMAND}
      -DCXX=${CMAKE_CXX_COMPILER} -DARGS=${work}/link-args.txt -DCXXFILT=${DDON_CXXFILT}
      -DTRAPS_FILE=${traps} -DWORK=${work} -DPROGRAM_NAME=${name}
      -P ${DDON_TRAPS_SCRIPT}
    DEPENDS ${objects} $<TARGET_OBJECTS:${objects}> ddon_reconstruction
      $<TARGET_FILE:ddon_reconstruction> ${DDON_TRAPS_SCRIPT}
    COMMENT "Finding what the reconstruction lacks on ${name}'s path")

  add_executable(${name} $<TARGET_OBJECTS:${objects}> ${traps})
  target_link_libraries(${name} PRIVATE ddon_reconstruction)
  target_link_options(${name} PRIVATE ${link_options})
endfunction()
