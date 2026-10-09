#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
class cUserManagerListener;

// Type aliases from DWARF
using s32 = int;

class cUserManagerListener
{
public:
    cUserManagerListener();
    virtual ~cUserManagerListener() {}
    virtual void addUser(s32 user_index, s32 user_id);  // vtable slot 2
    virtual void removeUser(s32 user_index, s32 user_id);  // vtable slot 3
};
