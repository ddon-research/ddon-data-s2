// The Windows build's forced include. The reconstruction
// follows DWARF, where `long` and `unsigned long` are 8 bytes (the PS4 is
// LP64); Windows is LLP64, where they are 4. MinGW's clang keeps the Itanium
// C++ ABI the PS4 uses (a derived class's members go in its base's tail
// padding, which MSVC's ABI never does), so the 64-bit `long` is the one
// difference left.
//
// The C and C++ library headers the sources include are parsed here first,
// with the platform's own `long`; their include guards make the sources'
// later includes no-ops. Only then does `long` name the 8-byte type, for the
// reconstruction's own declarations: every `long` they spell is DWARF's
// 8-byte `long int` or `long unsigned int` (they spell no `long long` and no
// `long double`). A literal's suffix (`0ul`) keeps the platform's 4-byte
// type: no directive reaches it.
//
// The load/save library (library/) and its sample add <algorithm>, <chrono>,
// <cmath>, <cstdio>, <cstdlib>, <cstring>, <filesystem>, <fstream>,
// <iterator>, <string>, <system_error>, <type_traits> and <unordered_set>.
//
// A library header first included after this point would be parsed with the
// wider `long` and fails loudly (its `long` and `long long` overloads
// collide): add it to the list.
#pragma once

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <list>
#include <map>
#include <math.h>
#include <memory>
#include <new>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <system_error>
#include <type_traits>
#include <unordered_set>
#include <utility>
#include <vector>

#define long long long
