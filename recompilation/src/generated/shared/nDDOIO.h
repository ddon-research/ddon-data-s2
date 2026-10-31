#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"

// Forward declarations
class MtColor;
class MtDataReader;
class MtDataWriter;
struct MtFloat2;
class MtMatrix;
class MtRect;
class MtSphere;
class MtString;
class MtVector2;
class MtVector3;
class cResPathBase;
class cResource;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using __uint64_t = long unsigned int;
using f32 = float;
using s16 = short;
using s32 = int;
using s8 = signed char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = __uint64_t;
using u8 = unsigned char;

namespace nDDOIO {

    void readData(MtDataReader& r, u8& data);
    void writeData(MtDataWriter& w, u8 data);
    void readData(MtDataReader& r, s8& data);
    void writeData(MtDataWriter& w, s8 data);
    void readData(MtDataReader& r, s16& data);
    void writeData(MtDataWriter& w, s16 data);
    void readDataArray(MtDataReader& r, s16* data, u32 bufNum);
    void readDataArray(MtDataReader& r, s32* data, u32 bufNum);
    void writeDataArray(MtDataWriter& w, s32* data, u32 num);
    void readDataArray(MtDataReader& r, f32* data, u32 bufNum);
    void writeDataArray(MtDataWriter& w, f32* data, u32 num);
    void readData(MtDataReader& r, bool& data);
    void readData(MtDataReader& r, u32& data);
    void readData(MtDataReader& r, u16& data);
    void writeData(MtDataWriter& w, bool data);
    void writeData(MtDataWriter& w, u32 data);
    void writeData(MtDataWriter& w, u16 data);
    void readData(MtDataReader& r, MtVector2& data);
    void readData(MtDataReader& r, MtVector3& data);
    void writeData(MtDataWriter& w, const MtVector3& data);
    void readData(MtDataReader& r, f32& data);
    void writeData(MtDataWriter& w, f32 data);
    void readDataArray(MtDataReader& r, u32* data, u32 bufNum);
    void writeDataArray(MtDataWriter& w, u32* data, u32 num);
    void readData(MtDataReader& r, MtFloat2& data);
    void writeData(MtDataWriter& w, const MtFloat2& data);
    void readData(MtDataReader& r, MtRect& data);
    void writeData(MtDataWriter& w, const MtRect& data);
    void readData(MtDataReader& r, MtMatrix& data);
    void writeData(MtDataWriter& w, const MtMatrix& data);
    void readData(MtDataReader& r, s32& data);
    void readData(MtDataReader& r, u64& data);
    void readData(MtDataReader& r, cResPathBase& data);
    void writeData(MtDataWriter& w, s32 data);
    void writeData(MtDataWriter& w, cResPathBase& data);
    void writeData(MtDataWriter& w, u64 data);
    void readData(MtDataReader& r, MtString& data);
    void writeData(MtDataWriter& w, const MtString& data);
    void readData(MtDataReader& r, MT_STR data, u32 buf);
    void writeData(MtDataWriter& w, MT_CTSTR data);
    void readData(MtDataReader& r, MtColor& data);
    void writeData(MtDataWriter& w, const MtColor& data);
    void readData(MtDataReader& r, MtSphere& data);
    void writeData(MtDataWriter& w, const MtSphere& data);
    void readData(MtDataReader& r, cResource* & pr);
    void writeData(MtDataWriter& w, cResource* pr);
    template <typename T> void readMtArray(MtDataReader& r, MtTypedArray<T>& ar);
    template <typename T> void writeMtArray(MtDataWriter& w, MtTypedArray<T>& ar);
    template <typename T> void readMtArrayEx(MtDataReader& r, MtTypedArray<T>& ar);

}  // namespace nDDOIO

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../DD_ONLINE/prog/cResPath.h"

inline void nDDOIO::readData(MtDataReader& r, u8& data) {
    data = r.::MtDataReader::readU8();
}

inline void nDDOIO::readData(MtDataReader& r, s16& data) {
    data = r.readS16();
}

inline void nDDOIO::readData(MtDataReader& r, bool& data) {
    data = r.::MtDataReader::readU8() != 0;
}

inline void nDDOIO::readData(MtDataReader& r, u32& data) {
    data = r.readU32();
}

inline void nDDOIO::readData(MtDataReader& r, u16& data) {
    data = r.readU16();
}

inline void nDDOIO::writeData(MtDataWriter& w, u32 data) {
    w.writeU32(data);
}

inline void nDDOIO::readData(MtDataReader& r, f32& data) {
    data = r.readF32();
}

inline void nDDOIO::writeData(MtDataWriter& w, f32 data) {
    w.writeF32(data);
}

inline void nDDOIO::readData(MtDataReader& r, s32& data) {
    data = r.readS32();
}

inline void nDDOIO::readData(MtDataReader& r, u64& data) {
    data = r.readU64();
}

inline void nDDOIO::readData(MtDataReader& r, cResPathBase& data) {
    data.mId = r.readU64();
}

inline void nDDOIO::writeData(MtDataWriter& w, s32 data) {
    w.writeS32(data);
}

inline void nDDOIO::writeData(MtDataWriter& w, u64 data) {
    w.writeU64(data);
}