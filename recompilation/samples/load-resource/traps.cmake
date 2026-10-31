# Writes traps.cpp: a definition for every symbol the sample's link leaves
# undefined. The reconstruction declares functions whose bodies it does not
# have (and objects it does not define); a load that reaches one stops there
# and names it (`ddon_trap`), instead of the program failing to link.
#
# Run by CMakeLists.txt as `cmake -P`, with:
#   CXX       the C++ compiler, which links
#   ARGS      a file with the link's arguments, one per line (the sample's
#             objects, the library, the link options)
#   CXXFILT   llvm-cxxfilt or c++filt, to read the names
#   TRAPS_FILE  traps.cpp
#   WORK      a directory for the trial link's files
#
# A function becomes a function that traps; a class's vtable, a table of
# such functions; an object (a class's MtDTI, a static member), zeroed
# storage.

file(STRINGS "${ARGS}" link_args)
execute_process(
  COMMAND "${CXX}" ${link_args} -o "${WORK}/trial-link${CMAKE_EXECUTABLE_SUFFIX}"
  RESULT_VARIABLE linked
  OUTPUT_VARIABLE out
  ERROR_VARIABLE err)
set(log "${out}${err}")
file(WRITE "${WORK}/trial-link.log" "${log}")

# lld: `undefined symbol: NAME`; GNU ld: "undefined reference to `NAME'".
string(REGEX MATCHALL "undefined symbol: [^ \t\r\n]+" lld_lines "${log}")
string(REGEX MATCHALL "undefined reference to `[^']+'" bfd_lines "${log}")
set(symbols)
foreach(line IN LISTS lld_lines bfd_lines)
  string(REGEX REPLACE "^undefined (symbol: |reference to `)" "" name "${line}")
  string(REGEX REPLACE "'$" "" name "${name}")
  list(APPEND symbols "${name}")
endforeach()
list(REMOVE_DUPLICATES symbols)
list(SORT symbols)
if(NOT linked EQUAL 0 AND NOT symbols)
  message(FATAL_ERROR "traps: the trial link failed with no undefined symbol; see ${WORK}/trial-link.log")
endif()

set(text "// Generated at build time by traps.cmake: what the sample's link lacks.\n")
string(APPEND text "extern \"C\" [[noreturn]] void ddon_trap(const char*);\n")
list(LENGTH symbols count)
if(count GREATER 0)
  string(REPLACE ";" "\n" listed "${symbols}")
  file(WRITE "${WORK}/undefined.txt" "${listed}\n")
  execute_process(
    COMMAND "${CXXFILT}"
    INPUT_FILE "${WORK}/undefined.txt"
    OUTPUT_FILE "${WORK}/demangled.txt"
    RESULT_VARIABLE demangled_ok)
  if(NOT demangled_ok EQUAL 0)
    message(FATAL_ERROR "traps: ${CXXFILT} failed")
  endif()
  file(STRINGS "${WORK}/demangled.txt" names)
  list(LENGTH names name_count)
  if(NOT name_count EQUAL count)
    message(FATAL_ERROR "traps: ${count} symbols but ${name_count} demangled names")
  endif()
  math(EXPR last "${count} - 1")
  foreach(index RANGE ${last})
    list(GET symbols ${index} symbol)
    list(GET names ${index} name)
    string(REPLACE "\\" "\\\\" quoted "${name}")
    string(REPLACE "\"" "\\\"" quoted "${quoted}")
    if(name MATCHES "^vtable for ")
      string(APPEND text
        "extern \"C\" void ddon_v${index}() { ddon_trap(\"${quoted}\"); }\n"
        "alignas(64) __attribute__((used)) void* ddon_d${index}[512] __asm__(\"${symbol}\");\n"
        "__attribute__((constructor)) static void ddon_fill${index}() {\n"
        "    for (auto& slot : ddon_d${index}) slot = reinterpret_cast<void*>(&ddon_v${index});\n}\n")
    elseif(name MATCHES "^(guard variable for |typeinfo|VTT for )" OR NOT name MATCHES "\\)( const)?$")
      string(APPEND text
        "alignas(64) __attribute__((used)) unsigned char ddon_d${index}[4096] __asm__(\"${symbol}\");\n")
    else()
      string(APPEND text
        "extern \"C\" __attribute__((used)) void ddon_t${index}() __asm__(\"${symbol}\");\n"
        "extern \"C\" void ddon_t${index}() { ddon_trap(\"${quoted}\"); }\n")
    endif()
  endforeach()
endif()
file(WRITE "${TRAPS_FILE}" "${text}")
message(STATUS "traps: ${count} symbols the reconstruction lacks on the sample's path")
