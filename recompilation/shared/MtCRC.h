#pragma once

#include <cstdint>
#include <cstddef>

// Declarations
class MtCRC;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using u32 = unsigned int;

class MtCRC
{
public:
    static u32 getCRC(MT_CTSTR str, u32 crc32);
    static u32 getCRC32C(MT_CTSTR str, u32 crc32);
    static u32 getCRC32K(MT_CTSTR str, u32 crc32);
    static u32 getCRC(const void* pbuf, u32 bytes, u32 crc32);
    static u32 getCRC32C(const void* pbuf, u32 bytes, u32 crc32);
    static u32 getCRC32K(const void* pbuf, u32 bytes, u32 crc32);
    static u32 getHashBlock32(const u32* pbuf, u32 bytes, u32 crc32);
    static u32 getCRCwithCheck(MT_CTSTR str, u32 crc32);
    static u32 getCRC32CwithCheck(MT_CTSTR str, u32 crc32);
    static u32 getCRC32KwithCheck(MT_CTSTR str, u32 crc32);
    static u32 getCRCwithCheck(const void* pbuf, u32 bytes, u32 crc32);
    static u32 getCRC32CwithCheck(const void* pbuf, u32 bytes, u32 crc32);
    static u32 getCRC32KwithCheck(const void* pbuf, u32 bytes, u32 crc32);
private:
    MtCRC();
    virtual ~MtCRC() {}
private:
    static const u32 mCRCtable[256];
    static const u32 mCRC32Ctable[256];
    static const u32 mCRC32Ktable[256];
};
