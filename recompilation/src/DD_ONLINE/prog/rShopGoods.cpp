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
    s << MtProperty(static_cast<MtObject*>(this), "商品カテゴリ", &mCategory, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "商品ID", &mID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "価格", &mPrice, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ポイント種別", &mGoldType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "販売種別", &mSaleType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "必要好感度", &mRequiedFavorite, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "販売開始日", static_cast<MtObject*>(&mStartDate), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "販売終了日", static_cast<MtObject*>(&mEndDate), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "在庫数", &mStockNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "最大在庫数", &mMaxStockNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "在庫補充単位", &mReplenishRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "在庫補充条件", &mReplenishType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ゲーム内日数", &mInGameDays, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "現実の日付", static_cast<MtObject*>(&mRealDate), 0u, 0u);
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
    s << MtProperty(static_cast<MtObject*>(this), "年", &mYear, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "月", &mMonth, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "日", &mDay, 0u, 0u);
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

