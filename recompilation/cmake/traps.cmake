# Writes a program's traps file: a definition for every symbol its link leaves
# undefined. The reconstruction declares functions whose bodies it does not
# have (and objects it does not define); a run that reaches one stops there
# and names it (`ddon_trap`), instead of the program failing to link.
#
# Run by TrapLink.cmake as `cmake -P`, with:
#   CXX       the C++ compiler, which links
#   ARGS      a file with the link's arguments, one per line (the program's
#             objects, the library, the link options)
#   CXXFILT   llvm-cxxfilt or c++filt, to read the names
#   OBJDUMP   llvm-objdump or objdump, to read the inputs' relocations
#   SYMBOL_KINDS  the game's `function <name>` and `data <name>` lines
#             (cmake/symbol-kinds.txt, which `export` writes)
#   TRAPS_FILE  the file to write
#   WORK      a directory for the trial link's files
#   PROGRAM_NAME  the program, for the messages
#
# A function becomes a function that traps; a class's vtable, a table of
# such functions; an object (a class's MtDTI, a static member), zeroed
# storage. An undefined symbol's entry in an object has no type (ELF's
# NOTYPE, COFF's null type), so a symbol is a function when an input calls
# it: a branch relocation against it (ELF's R_X86_64_PLT32, which clang
# writes for every call and tail call; on COFF a REL32 against the symbol
# itself, since MinGW reaches undefined data through a `.refptr` pointer).
# A symbol the inputs only take the address of (a vtable slot, a function
# pointer, an object) takes its kind from the game's symbol table, where the
# game defines or imports it (STT_FUNC or STT_OBJECT; SYMBOL_KINDS). One in
# neither is a function that traps, and the build's output names it.

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

set(text "// Generated at build time by traps.cmake: what ${PROGRAM_NAME}'s link lacks.\n")
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
  # The host's seam (ddon_host_alloc, ddon_trap, ddon::load_file, ...) is
  # never trapped: a program without one has a host that lacks it, and a
  # trap would hide that until a load reached it.
  set(host_lacks)
  foreach(index RANGE ${last})
    list(GET symbols ${index} symbol)
    list(GET names ${index} name)
    if(symbol MATCHES "^_?ddon_" OR name MATCHES "^(ddon_|ddon::)")
      list(APPEND host_lacks "${name}")
    endif()
  endforeach()
  if(host_lacks)
    list(JOIN host_lacks "\n  " listed)
    message(FATAL_ERROR "traps: ${PROGRAM_NAME}'s host lacks:\n  ${listed}\n"
      "Link the load/save library (library/) or define them in the program.")
  endif()
  # The symbols the link's inputs call: each argument that names a file (an
  # object, an archive) is read; a shared library's calls don't reach here.
  set(relocations "${WORK}/relocations.txt")
  file(WRITE "${relocations}" "")
  foreach(arg IN LISTS link_args)
    if(arg MATCHES "^-" OR NOT EXISTS "${arg}" OR IS_DIRECTORY "${arg}"
        OR arg MATCHES "\\.(so(\\.[0-9]+)*|dll|dylib)$")
      continue()
    endif()
    execute_process(
      COMMAND "${OBJDUMP}" -r "${arg}"
      OUTPUT_FILE "${WORK}/relocations-one.txt"
      ERROR_VARIABLE objdump_err
      RESULT_VARIABLE objdump_ok)
    if(NOT objdump_ok EQUAL 0)
      message(FATAL_ERROR "traps: ${OBJDUMP} -r ${arg} failed: ${objdump_err}")
    endif()
    file(READ "${WORK}/relocations-one.txt" one)
    file(APPEND "${relocations}" "${one}")
  endforeach()
  file(STRINGS "${relocations}" calls
    REGEX "^[0-9a-fA-F]+ +(R_X86_64_PLT32|IMAGE_REL_AMD64_REL32) +[^ ]")
  list(TRANSFORM calls REPLACE "^[0-9a-fA-F]+ +[A-Z0-9_]+ +([^ +-]+).*$" "\\1")
  list(REMOVE_DUPLICATES calls)
  list(JOIN calls "\n" called)
  set(called "\n${called}\n")
  # The game's own kinds (`export` wrote them from its symbol table).
  file(READ "${SYMBOL_KINDS}" game_kinds)
  set(game_kinds "\n${game_kinds}")
  set(functions 0)
  set(called_functions 0)
  set(game_functions 0)
  set(data 0)
  set(vtables 0)
  set(unknown)
  foreach(index RANGE ${last})
    list(GET symbols ${index} symbol)
    list(GET names ${index} name)
    string(REPLACE "\\" "\\\\" quoted "${name}")
    string(REPLACE "\"" "\\\"" quoted "${quoted}")
    string(FIND "${called}" "\n${symbol}\n" call_at)
    set(kind function)
    if(call_at GREATER -1)
      math(EXPR called_functions "${called_functions} + 1")
    else()
      string(FIND "${game_kinds}" "\nfunction ${symbol}\n" game_function_at)
      string(FIND "${game_kinds}" "\ndata ${symbol}\n" game_data_at)
      if(game_data_at GREATER -1)
        # The game's object; a class's vtable (which the demangler names)
        # gets a trap in every slot.
        set(kind data)
        if(name MATCHES "^vtable for ")
          set(kind vtable)
        endif()
      elseif(game_function_at GREATER -1)
        math(EXPR game_functions "${game_functions} + 1")
      else()
        # Neither called nor in the game's table: a trap, named below.
        list(APPEND unknown "${name}")
      endif()
    endif()
    if(kind STREQUAL "vtable")
      math(EXPR vtables "${vtables} + 1")
      string(APPEND text
        "extern \"C\" void ddon_v${index}() { ddon_trap(\"${quoted}\"); }\n"
        "alignas(64) __attribute__((used)) void* ddon_d${index}[512] __asm__(\"${symbol}\");\n"
        "__attribute__((constructor)) static void ddon_fill${index}() {\n"
        "    for (auto& slot : ddon_d${index}) slot = reinterpret_cast<void*>(&ddon_v${index});\n}\n")
    elseif(kind STREQUAL "data")
      math(EXPR data "${data} + 1")
      string(APPEND text
        "alignas(64) __attribute__((used)) unsigned char ddon_d${index}[4096] __asm__(\"${symbol}\");\n")
    else()
      math(EXPR functions "${functions} + 1")
      string(APPEND text
        "extern \"C\" __attribute__((used)) void ddon_t${index}() __asm__(\"${symbol}\");\n"
        "extern \"C\" void ddon_t${index}() { ddon_trap(\"${quoted}\"); }\n")
    endif()
  endforeach()
  list(LENGTH unknown unknown_count)
  message(STATUS "traps: ${functions} functions (${called_functions} called by an input, "
    "${game_functions} by the game's table, ${unknown_count} by neither), "
    "${data} data, ${vtables} vtables")
  if(unknown)
    list(JOIN unknown "\n  " listed)
    message(STATUS "traps: neither called nor in the game's table, so trapped as functions:\n  ${listed}")
  endif()
endif()
file(WRITE "${TRAPS_FILE}" "${text}")
message(STATUS "traps: ${count} symbols the reconstruction lacks on ${PROGRAM_NAME}'s path")
