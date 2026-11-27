#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../../../../../generated/shared/libsha256.h"

// Forward declarations
struct SceSha256Context;

namespace via {
    enum HashType
    {
        HashType_SHA256 = 0,
    };
}  // namespace via

// Declarations
namespace via { template <via::HashType Hash> class hash; }
namespace via { template <via::HashType Hash> struct hash_algorithm_selector; }

// Type aliases from DWARF
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u8 = unsigned char;

namespace via {
    template <via::HashType Hash>
    struct hash_algorithm_selector
    {
    public:
        using value_type = u8[32];
    public:
        hash_algorithm_selector();
        ~hash_algorithm_selector();
        s32 initialize();
        s32 update(const void* buffer_ptr, const size_t buffer_size);
        s32 getDigest(u8* digest_ptr);
        s32 getDigest(const void* buffer_ptr, const size_t buffer_size, u8* digest_ptr);
    public:
        SceSha256Context mContext;  // offset: 0x0
    };
}  // namespace via

namespace via {
    template <via::HashType Hash>
    class hash
    {
    public:
        using hash_type = via::hash_algorithm_selector<Hash>;
        using value_type = typename via::hash_algorithm_selector<Hash>::value_type;
    public:
        hash();
        s32 initialize();
        s32 update(const void* buffer_ptr, const size_t buffer_size);
        s32 getDigest(value_type& digest);
    private:
        hash_type mHash;  // offset: 0x0
    public:
        static const via::HashType hash_type_value = static_cast<via::HashType>(0);
    };
}  // namespace via
