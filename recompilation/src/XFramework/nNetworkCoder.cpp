// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nNetworkCoder.h"
#include "../MT/MtNetDevice.h"
#include "../MT/MtStream.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

nNetwork::Coder::Coder(MtStream& stream) : mMemory(static_cast<void*>(nullptr), 0u, 2u), mStream(stream) {
    mBitOffset = 0;
    mTempBuffer = 0;
    mIsOverflow = false;
}

nNetwork::Coder::~Coder() {
    DDON_STUB("nNetwork::Coder::~Coder")
    /* stub */
}

__attribute__((weak)) void nNetwork::Coder::writeU16(u16 n) {
    DDON_STUB("nNetwork::Coder::writeU16")
    /* stub */
}

__attribute__((weak)) void nNetwork::Coder::writeU32(u32 n) {
    DDON_STUB("nNetwork::Coder::writeU32")
    /* stub */
}

__attribute__((weak)) void nNetwork::Coder::writeU64(u64 n) {
    DDON_STUB("nNetwork::Coder::writeU64")
    /* stub */
}

__attribute__((weak)) void nNetwork::Coder::writeF32(f32 n) {
    DDON_STUB("nNetwork::Coder::writeF32")
    /* stub */
}

__attribute__((weak)) void nNetwork::Coder::writeF64(f64 n) {
    DDON_STUB("nNetwork::Coder::writeF64")
    /* stub */
}

__attribute__((weak)) void nNetwork::Coder::writeU32V(u32 val) {
    DDON_STUB("nNetwork::Coder::writeU32V")
    /* stub */
}

__attribute__((weak)) void nNetwork::Coder::writeBit32(u32 bit, u32 width) {
    DDON_STUB("nNetwork::Coder::writeBit32")
    /* stub */
}

__attribute__((weak)) void nNetwork::Coder::writeBit64(u64 bit, u32 width) {
    DDON_STUB("nNetwork::Coder::writeBit64")
    /* stub */
}

nNetwork::Decoder::Decoder(MtStream& stream) : mMemory(static_cast<void*>(nullptr), 0u, 1u), mStream(stream) {
    mBitOffset = 8;
    mTempBuffer = 0;
    mIsDrain = false;
}

nNetwork::Decoder::~Decoder() {
}

__attribute__((weak)) u16 nNetwork::Decoder::readU16() {
    u16 val = 0;
    if (mStream.read(&val, sizeof(val)) != sizeof(val)) {
        mIsDrain = true;
    }
    return MtNetByteOrder::netToHost16(val);
}

__attribute__((weak)) u32 nNetwork::Decoder::readU32() {
    DDON_STUB("nNetwork::Decoder::readU32")
    return {};
}

__attribute__((weak)) u64 nNetwork::Decoder::readU64() {
    DDON_STUB("nNetwork::Decoder::readU64")
    return {};
}

__attribute__((weak)) f32 nNetwork::Decoder::readF32() {
    DDON_STUB("nNetwork::Decoder::readF32")
    return {};
}

__attribute__((weak)) f64 nNetwork::Decoder::readF64() {
    DDON_STUB("nNetwork::Decoder::readF64")
    return {};
}

__attribute__((weak)) u32 nNetwork::Decoder::readU32V() {
    DDON_STUB("nNetwork::Decoder::readU32V")
    return {};
}

__attribute__((weak)) u32 nNetwork::Decoder::readBit32(u32 width) {
    DDON_STUB("nNetwork::Decoder::readBit32")
    return {};
}

__attribute__((weak)) u64 nNetwork::Decoder::readBit64(u32 width) {
    DDON_STUB("nNetwork::Decoder::readBit64")
    return {};
}

