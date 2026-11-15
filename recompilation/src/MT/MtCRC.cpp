// Reconstructed from the game's DWARF debug information.
#include <new>
#include "MtCRC.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) u32 MtCRC::getCRC(MT_CTSTR str, u32 crc32) {
    u32 n = 0;
    while (str[n] != '\0') {
        crc32 = mCRCtable[(crc32 & 0xffu) ^ static_cast<unsigned char>(str[n])] ^ (crc32 >> 8);
        n++;
    }
    return crc32;
}

