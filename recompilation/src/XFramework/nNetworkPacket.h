#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtStream.h"

// Forward declarations
class MtMemoryStream;
class MtStream;

// Declarations
namespace nNetwork { class PacketBase; }
namespace nNetwork { class PacketReader; }

// Type aliases from DWARF
using s32 = int;
using u32 = unsigned int;
using u8 = unsigned char;

namespace nNetwork {
    class PacketBase
    {
    public:
        enum
        {
            HASH_TYPE_NONE = 0,
            HASH_TYPE_CRC32 = 1,
            HASH_TYPE_SHA_1 = 2,
        };
    public:
        PacketBase();
        virtual ~PacketBase() {}
        u32 head() const;
    protected:
        void hmac(const u8* pbuf, u32 length, const u8* pass);
        bool check(const u8* pbuf, u32 length, const u8* pass);
        void reserve(MtStream& stream);
        void write(MtStream& stream);
        void read(MtStream& stream);
    private:
        void hash(const u8* pbuf, u32 length);
    private:
        u32 mHash[5];  // offset: 0x8
        u32 mHashLength;  // offset: 0x1c
        s32 mHashType;  // offset: 0x20
        s32 mReservePos;  // offset: 0x24
    public:
        static const u32 MAX_HASH_LENGTH = 5;
    };
}  // namespace nNetwork

namespace nNetwork {
    class PacketReader : public nNetwork::PacketBase
    {
    public:
        PacketReader(const void* data_ptr, u32 data_size);
        virtual ~PacketReader();
        MtMemoryStream& getGameStream();
        MtMemoryStream& getVoiceStream();
        s32 remain();
        bool check(const u8* pass);
    private:
        u32 mGameData;  // offset: 0x28
        MtMemoryStream mGameStream;  // offset: 0x30
        MtMemoryStream mVoiceStream;  // offset: 0x58
    };
}  // namespace nNetwork
