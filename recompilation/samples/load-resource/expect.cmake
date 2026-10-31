# The sample's tests (CMakeLists.txt): run PROGRAM and check its exit code.
# Without FILE_TEST: no arguments, so the usage and exit 2. With FILE_TEST:
# DDON_SAMPLE_ROOT's load of DDON_SAMPLE_FILE, which must read the file
# whole (exit 0); skipped when either is unset.
if(FILE_TEST)
  if(NOT DEFINED ENV{DDON_SAMPLE_ROOT} OR NOT DEFINED ENV{DDON_SAMPLE_FILE})
    message("skipped: set DDON_SAMPLE_ROOT and DDON_SAMPLE_FILE to load a file")
    return()
  endif()
  execute_process(COMMAND "${PROGRAM}" "$ENV{DDON_SAMPLE_ROOT}" "$ENV{DDON_SAMPLE_FILE}"
    RESULT_VARIABLE code OUTPUT_VARIABLE out ERROR_VARIABLE err)
  set(expected 0)
else()
  execute_process(COMMAND "${PROGRAM}" RESULT_VARIABLE code OUTPUT_VARIABLE out ERROR_VARIABLE err)
  set(expected 2)
endif()
message("${out}${err}")
if(NOT code STREQUAL "${expected}")
  message(FATAL_ERROR "load-resource exited ${code}, not ${expected}")
endif()
