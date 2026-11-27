#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
namespace nPhysics { class ISLAND; }

// Type aliases from DWARF
using u32 = unsigned int;

namespace nPhysics {
    class ISLAND
    {
    public:
        enum STATE
        {
            STATE_ACTIVE = 1,
            STATE_SLEEP = 2,
            STATE_STATIONARY = 4,
            STATE_WAKEUP = 8,
            STATE_MAX = 9,
        };
    public:
        ISLAND();
        ~ISLAND();
        void clear();
        u32 get_hash() const;
        void set_hash(const u32);
        bool is_sleep() const;
        void sleep();
        void wakeup();
        bool is_stationary() const;
        void clear_stationary_count();
        void increment_stationary_count();
    private:
        u32 mAggressiveSleepCount;  // offset: 0x0
        u32 mStatus;  // offset: 0x4
        u32 mStationaryCount;  // offset: 0x8
        u32 mHash;  // offset: 0xc
    };
}  // namespace nPhysics
