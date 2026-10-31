#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
struct internal_state;

// Declarations
struct z_stream_s;

// Type aliases from DWARF
using Byte = unsigned char;
using Bytef = Byte;
using voidpf = void*;
using uInt = unsigned int;
using alloc_func = voidpf(*)(voidpf, uInt, uInt);
using free_func = void(*)(voidpf, voidpf);
using uLong = long unsigned int;

struct z_stream_s
{
public:
    Bytef* next_in;  // offset: 0x0
    uInt avail_in;  // offset: 0x8
    uLong total_in;  // offset: 0x10
    Bytef* next_out;  // offset: 0x18
    uInt avail_out;  // offset: 0x20
    uLong total_out;  // offset: 0x28
    char* msg;  // offset: 0x30
    internal_state* state;  // offset: 0x38
    alloc_func zalloc;  // offset: 0x40
    free_func zfree;  // offset: 0x48
    voidpf opaque;  // offset: 0x50
    int data_type;  // offset: 0x58
    uLong adler;  // offset: 0x60
    uLong reserved;  // offset: 0x68
};
