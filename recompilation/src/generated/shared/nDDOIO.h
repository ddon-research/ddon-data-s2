#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../DD_ONLINE/prog/nDDOUtility.h"
#include "../../DD_ONLINE/prog/res_ptr.h"

#include "../../MT/MtMath.h"
#include "../../MT/MtPrimitive2D.h"
#include "../../MT/MtString.h"

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
    inline void writeData(MtDataWriter& w, const MtVector3& data);
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
    inline void writeData(MtDataWriter& w, MT_CTSTR data);
    void readData(MtDataReader& r, MtColor& data);
    void writeData(MtDataWriter& w, const MtColor& data);
    void readData(MtDataReader& r, MtSphere& data);
    void writeData(MtDataWriter& w, const MtSphere& data);
    inline void readData(MtDataReader& r, cResource* & pr);
    inline void writeData(MtDataWriter& w, cResource* pr);
    template <typename T> inline void readData(MtDataReader& r, res_ptr<T>& pr);
    template <typename T> void readData(MtDataReader& r, nDDOUtility::cScopedPtr<T>& ptr);
    template <typename T> inline void writeData(MtDataWriter& w, res_ptr<T>& pr);
    template <unsigned int N> void readData(MtDataReader& r, nDDOUtility::cBitSet<N>& data);
    template <unsigned int N> void writeData(MtDataWriter& w, nDDOUtility::cBitSet<N>& data);
    template <typename T> void readMtArray(MtDataReader& r, MtTypedArray<T>& ar);
    template <typename T> void readClass(MtDataReader& r, T* & ptr);
    template <typename T> void readClass(MtDataReader& r, T& obj);
    template <typename T> void writeMtArray(MtDataWriter& w, MtTypedArray<T>& ar);
    template <typename T> void writeClass(MtDataWriter& w, T* ptr);
    template <typename T> void readFunc(MtDataReader& r, T* pClass, void(T::*pFunc)(u32));
    template <typename T> void readFunc(MtDataReader& r, T* pClass, void(T::*pFunc)(bool));
    template <typename T> void readFunc(MtDataReader& r, T* pClass, void(T::*pFunc)(s32));
    template <typename T> void writeFunc(MtDataWriter& w, const T* pClass, u32(T::*pFunc)());
    template <typename T> void writeFunc(MtDataWriter& w, const T* pClass, s32(T::*pFunc)());
    template <typename T> void readMtArrayEx(MtDataReader& r, MtTypedArray<T>& ar);
    template <typename T, unsigned int N> void readData(MtDataReader& r, nDDOUtility::cArray<T, N>& val);

}  // namespace nDDOIO

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtColor.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../DD_ONLINE/prog/cResPath.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/sResource.h"

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

inline void nDDOIO::writeData(MtDataWriter& w, cResPathBase& data) {
    w.writeU64(data.mId);
}

inline void nDDOIO::writeData(MtDataWriter& w, u64 data) {
    w.writeU64(data);
}

inline void nDDOIO::writeData(MtDataWriter& w, const MtMatrix& data) {
    w.writeV4(MtFloat4(data.m[0].x, data.m[0].y, data.m[0].z, data.m[0].w));
    w.writeV4(MtFloat4(data.m[1].x, data.m[1].y, data.m[1].z, data.m[1].w));
    w.writeV4(MtFloat4(data.m[2].x, data.m[2].y, data.m[2].z, data.m[2].w));
    w.writeV4(MtFloat4(data.m[3].x, data.m[3].y, data.m[3].z, data.m[3].w));
}

template <typename T>
inline void nDDOIO::readClass(MtDataReader& r, T& obj) {
    obj.load(r);
}
template <unsigned int N>
void nDDOIO::readData(MtDataReader& r, nDDOUtility::cBitSet<N>& data) {
    readDataArray(r, data.toArrayPtr(), data.AR_NUM);
}

template <typename T>
void nDDOIO::readMtArray(MtDataReader& r, MtTypedArray<T>& ar) {
    ar.deleteAll(true);
    u32 num = r.readU32();
    if (num > 0) {
        ar.reserve(num);
    }
    for (u32 i = 0; i < num; i++) {
        T* pElement = static_cast<T*>(T::DTI.newInstance());
        pElement->load(r);
        ar.add(pElement);
    }
}

template <typename T>
void nDDOIO::readMtArrayEx(MtDataReader& r, MtTypedArray<T>& ar) {
    ar.deleteAll(true);
    u32 num = r.readU32();
    if (num > 0) {
        ar.reserve(num);
    }
    for (u32 i = 0; i < num; i++) {
        T* pElement = static_cast<T*>(MtDTI::from(r.readU32())->newInstance());
        pElement->load(r);
        ar.add(pElement);
    }
}

inline void nDDOIO::readData(MtDataReader& r, MtVector3& data) {
    data = r.readV3();
}

inline void nDDOIO::readData(MtDataReader& r, MT_STR data, u32 buf) {
    r.readString(data, buf);
}

inline void nDDOIO::readDataArray(MtDataReader& r, u32* data, u32 bufNum) {
    u32 num;
    nDDOIO::readData(r, num);
    r.read(data, num * sizeof(u32));
}

inline void nDDOIO::readDataArray(MtDataReader& r, f32* data, u32 bufNum) {
    u32 num = r.readU32();
    r.read(data, num * sizeof(f32));
}

inline void nDDOIO::readDataArray(MtDataReader& r, s32* data, u32 bufNum) {
    u32 num = r.readU32();
    r.read(data, num * sizeof(s32));
}

inline void nDDOIO::writeData(MtDataWriter& w, u8 data) {
    w.writeU8(data);
}

inline void nDDOIO::writeData(MtDataWriter& w, bool data) {
    w.writeU8(data);
}

inline void nDDOIO::writeData(MtDataWriter& w, u16 data) {
    w.writeU16(data);
}

inline void nDDOIO::writeData(MtDataWriter& w, const MtColor& data) {
    w.writeU32(data.rgba);
}

inline void nDDOIO::writeDataArray(MtDataWriter& w, f32* data, u32 num) {
    w.writeU32(num);
    w.write(data, num * sizeof(f32));
}

inline void nDDOIO::readData(MtDataReader& r, cResource* & pr) {
    MT_CHAR buf[64];
    r.readString(buf, 64);
    if (buf[0] != '\0') {
        const MtDTI* pdti = MtDTI::from(buf, cResource::DTI);
        r.readString(buf, 64);
        pr = sResource::getInstance()->create(*pdti, buf, sResource::MODE_BLOCKING);
    }
}

inline void nDDOIO::writeData(MtDataWriter& w, cResource* pr) {
    if (pr != nullptr) {
        w.writeString(pr->getDTI().getName());
        w.writeString(pr->getPath());
    } else {
        w.writeString("");
    }
}

template <typename T>
inline void nDDOIO::readData(MtDataReader& r, res_ptr<T>& pr) {
    nDDOIO::readData(r, reinterpret_cast<cResource*&>(pr.mpPtr));
}

template <typename T>
inline void nDDOIO::writeData(MtDataWriter& w, res_ptr<T>& pr) {
    nDDOIO::writeData(w, static_cast<cResource*>(pr.mpPtr));
}

inline void nDDOIO::writeData(MtDataWriter& w, const MtVector3& data) {
    MtFloat3 ft3;
    ft3.x = data.x;
    ft3.y = data.y;
    ft3.z = data.z;
    w.writeV3(ft3);
}

inline void nDDOIO::writeData(MtDataWriter& w, MT_CTSTR data) {
    w.writeString(data);
}

inline void nDDOIO::readData(MtDataReader& r, MtMatrix& data) {
    data.m[0] = r.readV4();
    data.m[1] = r.readV4();
    data.m[2] = r.readV4();
    data.m[3] = r.readV4();
}

inline void nDDOIO::readData(MtDataReader& r, MtFloat2& data) {
    data.x = r.readF32();
    data.y = r.readF32();
}

inline void nDDOIO::writeData(MtDataWriter& w, const MtFloat2& data) {
    w.writeF32(data.x);
    w.writeF32(data.y);
}

inline void nDDOIO::readData(MtDataReader& r, MtRect& data) {
    data.l = r.readS32();
    data.t = r.readS32();
    data.r = r.readS32();
    data.b = r.readS32();
}

inline void nDDOIO::writeData(MtDataWriter& w, const MtRect& data) {
    w.writeS32(data.l);
    w.writeS32(data.t);
    w.writeS32(data.r);
    w.writeS32(data.b);
}

inline void nDDOIO::readData(MtDataReader& r, MtString& data) {
    MT_CHAR t1[256];
    r.readString(t1, sizeof(t1));
    data = t1;
}

inline void nDDOIO::writeData(MtDataWriter& w, const MtString& data) {
    w.writeString(data.ptr());
}

inline void nDDOIO::writeDataArray(MtDataWriter& w, u32* data, u32 num) {
    w.writeU32(num);
    w.write(data, num * sizeof(u32));
}

template <unsigned int N>
void nDDOIO::writeData(MtDataWriter& w, nDDOUtility::cBitSet<N>& data) {
    writeDataArray(w, data.toArrayPtr(), data.AR_NUM);
}
