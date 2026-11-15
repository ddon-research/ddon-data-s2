# A host program linked against the reconstruction, with a definition for
# every symbol its link leaves undefined (traps.cmake). The headers' inline
# bodies, the reconstruction and the program's own files can all reach a
# function or a static member the reconstruction has no definition for.

set(DDON_TRAPS_SCRIPT ${CMAKE_CURRENT_LIST_DIR}/traps.cmake)
# The game's function and data symbols, which `export` writes beside it.
set(DDON_SYMBOL_KINDS ${CMAKE_CURRENT_LIST_DIR}/symbol-kinds.txt CACHE FILEPATH
  "The game's `function <name>` and `data <name>` lines (traps.cmake)")

# ddon_add_trap_linked_executable(<name> OBJECTS <object library>...
#                                 [WHOLE_ARCHIVE] [LIBRARIES <imported library>...]
#                                 [LINK_OPTIONS <option>...]):
# the program <name> from the object libraries' objects, the reconstruction
# and <name>-traps.cpp, which a trial link of the same objects writes at
# build time. The objects need an extern "C" ddon_trap(const char*) (the
# load/save library's src/host.cpp has one). WHOLE_ARCHIVE links the
# reconstruction whole, as the game is linked: every unit's static
# constructors run, so the class registry holds every class (the load/save
# library needs it). LIBRARIES are imported targets linked after it (the
# load/save library's zlib, which the game linked with no debug information).
# A symbol named ddon_... left undefined fails the build:
# it belongs to the host, never to the reconstruction.
function(ddon_add_trap_linked_executable name)
  cmake_parse_arguments(PARSE_ARGV 1 arg "WHOLE_ARCHIVE" "" "OBJECTS;LIBRARIES;LINK_OPTIONS")
  if(NOT arg_OBJECTS)
    message(FATAL_ERROR "ddon_add_trap_linked_executable(${name}): no OBJECTS")
  endif()
  include(CheckLinkerFlag)
  set(link_options ${arg_LINK_OPTIONS})
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
  # The objects' relocations say which missing symbols are called (traps.cmake).
  find_program(DDON_OBJDUMP NAMES llvm-objdump llvm-objdump-22 llvm-objdump-21 llvm-objdump-20 objdump
    HINTS ${compiler_dir} REQUIRED)
  set(trial_options ${link_options} -Wl,--no-demangle)
  if(DDON_TRAP_LLD)
    list(APPEND trial_options -Wl,--error-limit=0)
  endif()
  set(work ${CMAKE_CURRENT_BINARY_DIR}/${name}-trial)
  set(traps ${CMAKE_CURRENT_BINARY_DIR}/${name}-traps.cpp)
  list(JOIN trial_options "\n" trial_lines)
  set(object_lines)
  set(object_files)
  foreach(objects IN LISTS arg_OBJECTS)
    string(APPEND object_lines "$<JOIN:$<TARGET_OBJECTS:${objects}>,\n>\n")
    list(APPEND object_files $<TARGET_OBJECTS:${objects}>)
  endforeach()
  set(library "$<TARGET_FILE:ddon_reconstruction>\n")
  if(arg_WHOLE_ARCHIVE)
    set(library "-Wl,--whole-archive\n${library}-Wl,--no-whole-archive\n")
  endif()
  foreach(imported IN LISTS arg_LIBRARIES)
    string(APPEND library "$<TARGET_LINKER_FILE:${imported}>\n")
  endforeach()
  file(GENERATE OUTPUT ${work}/link-args.txt CONTENT "${object_lines}${library}${trial_lines}\n")
  add_custom_command(
    OUTPUT ${traps}
    COMMAND ${CMAKE_COMMAND}
      -DCXX=${CMAKE_CXX_COMPILER} -DARGS=${work}/link-args.txt -DCXXFILT=${DDON_CXXFILT}
      -DOBJDUMP=${DDON_OBJDUMP} -DSYMBOL_KINDS=${DDON_SYMBOL_KINDS}
      -DTRAPS_FILE=${traps} -DWORK=${work} -DPROGRAM_NAME=${name}
      -P ${DDON_TRAPS_SCRIPT}
    DEPENDS ${arg_OBJECTS} ${object_files} ddon_reconstruction
      $<TARGET_FILE:ddon_reconstruction> ${DDON_TRAPS_SCRIPT} ${DDON_SYMBOL_KINDS}
    COMMENT "Finding what the reconstruction lacks on ${name}'s path")

  add_executable(${name} ${object_files} ${traps})
  if(arg_WHOLE_ARCHIVE)
    target_link_libraries(${name} PRIVATE "$<LINK_LIBRARY:WHOLE_ARCHIVE,ddon_reconstruction>")
  else()
    target_link_libraries(${name} PRIVATE ddon_reconstruction)
  endif()
  target_link_libraries(${name} PRIVATE ${arg_LIBRARIES})
  target_link_options(${name} PRIVATE ${link_options})
endfunction()
