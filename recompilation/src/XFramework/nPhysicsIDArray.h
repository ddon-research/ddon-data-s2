#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
namespace nPhysics { class System; }

// Declarations
namespace nPhysics { class ID_ARRAY; }

// Type aliases from DWARF
using u32 = unsigned int;

namespace nPhysics {
    class ID_ARRAY
    {
        friend class nPhysics::System;
    public:
        ID_ARRAY();
        ~ID_ARRAY();
        void initialize(const u32 num, void* buffer, const u32 buffer_size);
        u32 create();
        void remove(const u32 id);
        void migrate(const u32 id);
        void restore(const u32 id);
        void clear();
        u32 get_max_id() const;
        u32 get_num_valid_id() const;
        u32* get_valid_id_top() const;
        u32 get_valid_id(const u32 index);
        u32 get_num_migrated_id() const;
        u32 get_migrated_id(const u32 index) const;
        u32 get_index_from_id(const u32 id);
        static u32 GetNecessaryMemorySize(const u32 num);
    private:
        u32* mValidID;  // offset: 0x0
        u32* mValidIDIndex;  // offset: 0x8
        u32* mInvalidID;  // offset: 0x10
        u32 mNumValidID;  // offset: 0x18
        u32 mNumMigratedID;  // offset: 0x1c
        u32 mMaxID;  // offset: 0x20
        u32 mCreatePosition;  // offset: 0x24
        u32 mRemovePosition;  // offset: 0x28
    };
}  // namespace nPhysics
