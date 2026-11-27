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
#include "../../generated/shared/nDDOIO.h"
#include "rTable.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShopGoods::getDTI() const {
    return cShopGoods::DTI;
}

void* cShopGoods::operator new(size_t sz, u32 align) {
    return cShopGoods::getAllocator()->memAlloc(sz, align, cShopGoods::DTI.getID());
}

void cShopGoods::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "\345\225\206\345\223\201\343\202\253\343\203\206\343\202\264\343\203\252", &mCategory, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\225\206\345\223\201ID", &mID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\344\276\241\346\240\274", &mPrice, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\235\343\202\244\343\203\263\343\203\210\347\250\256\345\210\245", &mGoldType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\350\262\251\345\243\262\347\250\256\345\210\245", &mSaleType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\277\205\350\246\201\345\245\275\346\204\237\345\272\246", &mRequiedFavorite, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\350\262\251\345\243\262\351\226\213\345\247\213\346\227\245", static_cast<MtObject*>(&mStartDate), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\350\262\251\345\243\262\347\265\202\344\272\206\346\227\245", static_cast<MtObject*>(&mEndDate), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\234\250\345\272\253\346\225\260", &mStockNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\234\200\345\244\247\345\234\250\345\272\253\346\225\260", &mMaxStockNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\234\250\345\272\253\350\243\234\345\205\205\345\215\230\344\275\215", &mReplenishRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\234\250\345\272\253\350\243\234\345\205\205\346\235\241\344\273\266", &mReplenishType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\202\262\343\203\274\343\203\240\345\206\205\346\227\245\346\225\260", &mInGameDays, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\347\217\276\345\256\237\343\201\256\346\227\245\344\273\230", static_cast<MtObject*>(&mRealDate), 0u, 0u);
}

inline cShopGoods::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShopGoods::MyDTI cShopGoods::DTI("cShopGoods", &::MtObject::DTI, 96ul, 0u, 0u);

__attribute__((weak)) MtObject* cShopGoods::MyDTI::newInstance() const {
    return new (16u) cShopGoods;
}

const MtDTI& cShopGoods::rDate::getDTI() const {
    return cShopGoods::rDate::DTI;
}

void cShopGoods::rDate::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "\345\271\264", &mYear, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\234\210", &mMonth, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\346\227\245", &mDay, 0u, 0u);
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

const MtDTI& rShopGoods::getDataDTI() {
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
        nDDOIO::readData(in, pData->mCategory);
        nDDOIO::readData(in, pData->mID);
        nDDOIO::readData(in, pData->mPrice);
        nDDOIO::readData(in, pData->mGoldType);
        nDDOIO::readData(in, pData->mSaleType);
        nDDOIO::readData(in, pData->mRequiedFavorite);
        nDDOIO::readData(in, pData->mStartDate.mYear);
        nDDOIO::readData(in, pData->mStartDate.mMonth);
        nDDOIO::readData(in, pData->mStartDate.mDay);
        nDDOIO::readData(in, pData->mEndDate.mYear);
        nDDOIO::readData(in, pData->mEndDate.mMonth);
        nDDOIO::readData(in, pData->mEndDate.mDay);
        nDDOIO::readData(in, pData->mStockNum);
        nDDOIO::readData(in, pData->mMaxStockNum);
        nDDOIO::readData(in, pData->mReplenishRate);
        nDDOIO::readData(in, pData->mReplenishType);
        nDDOIO::readData(in, pData->mInGameDays);
        nDDOIO::readData(in, pData->mRealDate.mYear);
        nDDOIO::readData(in, pData->mRealDate.mMonth);
        nDDOIO::readData(in, pData->mRealDate.mDay);
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

