// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rShopGoods.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTable.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShopGoods::getDTI() const {
    return cShopGoods::DTI;
}

inline MtAllocator* cShopGoods::getAllocator() {
    return MtMemoryAllocator::getAllocator(cShopGoods::DTI);
}

void* cShopGoods::operator new(size_t sz, u32 align) {
    return cShopGoods::getAllocator()->memAlloc(sz, align, cShopGoods::DTI.getID());
}

inline void cShopGoods::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShopGoods::DTI)->memFree(p_addr);
}

__attribute__((weak)) void cShopGoods::createProperty(MtPropertyList& s) {
    DDON_STUB("cShopGoods::createProperty")
    /* stub */
}

inline cShopGoods::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShopGoods::MyDTI cShopGoods::DTI("cShopGoods", &::MtObject::DTI, 96ul, 0u, 0u);

__attribute__((weak)) MtObject* cShopGoods::MyDTI::newInstance() const {
    return new (16u) cShopGoods;
}

const MtDTI& cShopGoods::rDate::getDTI() const {
    return cShopGoods::rDate::DTI;
}

inline void* cShopGoods::rDate::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cShopGoods::rDate::DTI)->memAlloc(sz, align, cShopGoods::rDate::DTI.getID());
}

inline void cShopGoods::rDate::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cShopGoods::rDate::DTI)->memFree(p_addr);
}

__attribute__((weak)) void cShopGoods::rDate::createProperty(MtPropertyList& s) {
    DDON_STUB("cShopGoods::rDate::createProperty")
    /* stub */
}

bool cShopGoods::rDate::load(MtDataReader& in) {
    nDDOIO::readData(in, mYear);
    nDDOIO::readData(in, mMonth);
    mDay = in.readU8();
    return true;
}

bool cShopGoods::rDate::save(MtDataWriter& out) {
    out.writeU16(mYear);
    u8 t0 = mMonth;
    if (out.mSeekPt >= out.mBufsiz) {
        out.flush();
        out.mBuffer[out.mSeekPt] = t0;
        u32 t1 = out.mSeekPt;
        out.mSeekPt = t1 + 1u;
        u8 t2 = mDay;
        if (out.mSeekPt >= out.mBufsiz) {
            out.flush();
            out.mBuffer[out.mSeekPt] = t2;
        } else {
            out.mBuffer[t1 + 1u] = t2;
        }
        out.mSeekPt = out.mSeekPt + 1u;
        return true;
    } else {
        out.mBuffer[out.mSeekPt] = t0;
        u32 t1 = out.mSeekPt;
        out.mSeekPt = t1 + 1u;
        u8 t2 = mDay;
        if (out.mSeekPt >= out.mBufsiz) {
            out.flush();
            out.mBuffer[out.mSeekPt] = t2;
        } else {
            out.mBuffer[t1 + 1u] = t2;
        }
        out.mSeekPt = out.mSeekPt + 1u;
        return true;
    }
}

inline cShopGoods::rDate::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShopGoods::rDate::MyDTI cShopGoods::rDate::DTI("cShopGoods::rDate", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cShopGoods::rDate::MyDTI::newInstance() const {
    return new (16u) cShopGoods::rDate;
}

const MtDTI& rShopGoods::getDTI() const {
    return rShopGoods::DTI;
}

inline void* rShopGoods::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rShopGoods::DTI)->memAlloc(sz, align, rShopGoods::DTI.getID());
}

inline void rShopGoods::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rShopGoods::DTI)->memFree(p_addr);
}

inline rShopGoods::rShopGoods() {
    setAttribute(16u);
}

__attribute__((weak)) const MtDTI& rShopGoods::getDataDTI() {
    return cShopGoods::DTI;
}

MT_CTSTR rShopGoods::getExt() const {
    return "spg_tbl";
}

u16 rShopGoods::getDataVersion() {
    return 259;
}

bool rShopGoods::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    return loadData(r);
}

__attribute__((weak)) bool rShopGoods::loadData(MtDataReader& in) {
    bool ret = false;
    u32 magic = in.readU32();
    u32 version = in.readU16();
    if (magic == mMagic && version == cShopGoods::DATA_VERSION) {
        u32 dmy = in.readU16();
        u32 Num = in.readU32();
        for (u32 i = 0; i < Num; ++i) {
            cShopGoods* pObj = new (16u) cShopGoods;
            if (pObj != nullptr) {
                loadData(in, pObj);
                mArray.add(pObj);
            }
        }
        ret = true;
    }
    return ret;
}

__attribute__((weak)) bool rShopGoods::save(MtStream& out) {
    MtDataWriter w(out, MtDataWriter::DEFAULT_BUFFERSIZE, MtDataWriter::DEFAULT_LABELSIZE);
    return saveData(w);
}

bool rShopGoods::loadData(MtDataReader& in, cShopGoods* pData) {
    unsigned int v1_0;
    unsigned long v2_1;
    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 24)) < (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 28))) {
        v1_0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 24);
    } else {
        if (in.refill()) {
            v1_0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 24);
        } else {
            v2_1 = 0;
            goto region_6e6bb6;
        }
    }
    unsigned long t0;
    t0 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&in) + 16);
    unsigned char t1;
    t1 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t0 + v1_0) + 0);
    in.mSeekPt = v1_0 + 1u;
    v2_1 = static_cast<unsigned long>(t1) | (t0 & 0xFFFFFFFFFFFFFF00ul);
    region_6e6bb6:;
    pData->mCategory = static_cast<unsigned char>(v2_1);
    pData->mID = in.readU32();
    pData->mPrice = in.readU64();
    unsigned int v4_0;
    unsigned long v5_1;
    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 24)) < (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 28))) {
        v4_0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 24);
    } else {
        if (in.refill()) {
            v4_0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 24);
        } else {
            v5_1 = 0;
            goto region_6e6bfd;
        }
    }
    unsigned long t2;
    t2 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&in) + 16);
    unsigned char t3;
    t3 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t2 + v4_0) + 0);
    in.mSeekPt = v4_0 + 1u;
    v5_1 = static_cast<unsigned long>(t3) | (t2 & 0xFFFFFFFFFFFFFF00ul);
    region_6e6bfd:;
    pData->mGoldType = static_cast<unsigned char>(v5_1);
    unsigned int v7_0;
    unsigned long v8_1;
    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 24)) < (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 28))) {
        v7_0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 24);
    } else {
        if (in.refill()) {
            v7_0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 24);
        } else {
            v8_1 = 0;
            goto region_6e6c2a;
        }
    }
    unsigned long t4;
    t4 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&in) + 16);
    unsigned char t5;
    t5 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t4 + v7_0) + 0);
    in.mSeekPt = v7_0 + 1u;
    v8_1 = static_cast<unsigned long>(t5) | (t4 & 0xFFFFFFFFFFFFFF00ul);
    region_6e6c2a:;
    pData->mSaleType = static_cast<unsigned char>(v8_1);
    pData->mRequiedFavorite = in.readU16();
    pData->mStartDate.mYear = in.readU16();
    pData->mStartDate.mMonth = in.readU8();
    pData->mStartDate.mDay = in.readU8();
    pData->mEndDate.mYear = in.readU16();
    pData->mEndDate.mMonth = in.readU8();
    pData->mEndDate.mDay = in.readU8();
    unsigned int v10_0;
    unsigned long v11_1;
    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 24)) < (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 28))) {
        v10_0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 24);
    } else {
        if (in.refill()) {
            v10_0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 24);
        } else {
            v11_1 = 0;
            goto region_6e6d35;
        }
    }
    unsigned long t6;
    t6 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&in) + 16);
    unsigned char t7;
    t7 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t6 + v10_0) + 0);
    in.mSeekPt = v10_0 + 1u;
    v11_1 = static_cast<unsigned long>(t7) | (t6 & 0xFFFFFFFFFFFFFF00ul);
    region_6e6d35:;
    pData->mStockNum = static_cast<unsigned char>(v11_1);
    unsigned int v13_0;
    unsigned long v14_1;
    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 24)) < (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 28))) {
        v13_0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 24);
    } else {
        if (in.refill()) {
            v13_0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 24);
        } else {
            v14_1 = 0;
            goto region_6e6d62;
        }
    }
    unsigned long t8;
    t8 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&in) + 16);
    unsigned char t9;
    t9 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t8 + v13_0) + 0);
    in.mSeekPt = v13_0 + 1u;
    v14_1 = static_cast<unsigned long>(t9) | (t8 & 0xFFFFFFFFFFFFFF00ul);
    region_6e6d62:;
    pData->mMaxStockNum = static_cast<unsigned char>(v14_1);
    unsigned int v16_0;
    unsigned long v17_1;
    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 24)) < (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 28))) {
        v16_0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 24);
    } else {
        if (in.refill()) {
            v16_0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 24);
        } else {
            v17_1 = 0;
            goto region_6e6d8f;
        }
    }
    unsigned long t10;
    t10 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&in) + 16);
    unsigned char t11;
    t11 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t10 + v16_0) + 0);
    in.mSeekPt = v16_0 + 1u;
    v17_1 = static_cast<unsigned long>(t11) | (t10 & 0xFFFFFFFFFFFFFF00ul);
    region_6e6d8f:;
    pData->mReplenishRate = static_cast<unsigned char>(v17_1);
    unsigned int v19_0;
    unsigned long v20_1;
    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 24)) < (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 28))) {
        v19_0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 24);
    } else {
        if (in.refill()) {
            v19_0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(&in) + 24);
        } else {
            v20_1 = 0;
            pData->mReplenishType = static_cast<unsigned char>(v20_1);
            pData->mInGameDays = in.readU16();
            pData->mRealDate.mYear = in.readU16();
            pData->mRealDate.mMonth = in.readU8();
            pData->mRealDate.mDay = in.readU8();
            return true;
        }
    }
    unsigned long t12 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(&in) + 16);
    unsigned char t13 = *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(t12 + v19_0) + 0);
    in.mSeekPt = v19_0 + 1u;
    v20_1 = static_cast<unsigned long>(t13) | (t12 & 0xFFFFFFFFFFFFFF00ul);
    pData->mReplenishType = static_cast<unsigned char>(v20_1);
    pData->mInGameDays = in.readU16();
    pData->mRealDate.mYear = in.readU16();
    pData->mRealDate.mMonth = in.readU8();
    pData->mRealDate.mDay = in.readU8();
    return true;
}

__attribute__((weak)) bool rShopGoods::saveData(MtDataWriter& out, cShopGoods* pData) {
    out.writeU8(pData->mCategory);
    out.writeU32(pData->mID);
    out.writeU64(pData->mPrice);
    out.writeU8(pData->mGoldType);
    out.writeU8(pData->mSaleType);
    out.writeU16(pData->mRequiedFavorite);
    out.writeU16(pData->mStartDate.mYear);
    out.writeU8(pData->mStartDate.mMonth);
    out.writeU8(pData->mStartDate.mDay);
    out.writeU16(pData->mEndDate.mYear);
    out.writeU8(pData->mEndDate.mMonth);
    out.writeU8(pData->mEndDate.mDay);
    out.writeU8(pData->mStockNum);
    out.writeU8(pData->mMaxStockNum);
    out.writeU8(pData->mReplenishRate);
    out.writeU8(pData->mReplenishType);
    out.writeU16(pData->mInGameDays);
    out.writeU16(pData->mRealDate.mYear);
    out.writeU8(pData->mRealDate.mMonth);
    out.writeU8(pData->mRealDate.mDay);
    return true;
}

inline rShopGoods::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rShopGoods::MyDTI rShopGoods::DTI("rShopGoods", &::rTable::DTI, 176ul, 0u, 0u);

MtObject* rShopGoods::MyDTI::newInstance() const {
    return new (16u) rShopGoods;
}

