#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
class MtProfiler;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;

class MtProfiler
{
public:
    class Profile;
public:
    class Profile
    {
    public:
        Profile(MT_CTSTR name, u32 color, bool important);
    };
public:
    void init();
    void reset();
    void update();
    static void begin(MT_CTSTR name, u32 color, bool important);
    static void end(MT_CTSTR name);
};
