// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nNetworkPacket.h"
#include "../MT/MtCRC.h"
#include "../MT/MtStream.h"
#include "nNetworkCoder.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void nNetwork::PacketBase::hmac(const u8* pbuf, u32 length, const u8* pass) {
    DDON_STUB("nNetwork::PacketBase::hmac")
    /* stub */
}

__attribute__((weak)) void nNetwork::PacketBase::hash(const u8* pbuf, u32 length) {
    DDON_STUB("nNetwork::PacketBase::hash")
    /* stub */
}

nNetwork::PacketReader::~PacketReader() {
}

MtMemoryStream& nNetwork::PacketReader::getGameStream() {
    return mGameStream;
}

MtMemoryStream& nNetwork::PacketReader::getVoiceStream() {
    return mGameStream;
}

s32 nNetwork::PacketReader::remain() {
    u32 t0 = mGameData;
    return static_cast<s32>(t0 - mGameStream.::MtMemoryStream::getPosition());
}

__attribute__((weak)) bool nNetwork::PacketReader::check(const u8* pass) {
    DDON_STUB("nNetwork::PacketReader::check")
    return {};
}

