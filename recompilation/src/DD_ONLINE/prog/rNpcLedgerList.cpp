// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rNpcLedgerList.h"
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
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rNpcLedgerList::getDTI() const {
    return rNpcLedgerList::DTI;
}

u32 rNpcLedgerList::getLedgerSize() const {
    return mArray.mLength;
}

const rNpcLedgerList::cItem* rNpcLedgerList::getNpcInfo(u32 index) const {
    return static_cast<const cItem*>(mArray.mpArray[index]);
}

const rNpcLedgerList::cItem* rNpcLedgerList::searchNpcInfo(u32 npcId) const {
    if (mArray.mLength != 0) {
        u32 i = 0;
        do {
            if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mArray.mpArray[i]) + 40)) == npcId) {
                return static_cast<const cItem*>(mArray.mpArray[i]);
            }
            i += 1u;
        } while (i < mArray.mLength);
    }
    return nullptr;
}

MT_CTSTR rNpcLedgerList::getExt() const {
    return "nll";
}

__attribute__((noinline)) rNpcLedgerList::~rNpcLedgerList() {
    if (mArray.isAutoDelete()) {
        mArray.deleteAll(true);
    } else {
        if (mArray.length() != 0) {
            cItem* pRoot = mArray[0];
            if (pRoot != nullptr) {
                delete[] pRoot;
            }
            mArray.clear(true);
        }
    }
}

void rNpcLedgerList::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mArray", static_cast<MtObject*>(&mArray), 0u, 0u);
}

bool rNpcLedgerList::save(MtStream& out) {
    MtDataWriter w(out, 4096u, 4096u);
    (&w)->writeU32(0x6C6C6Eu);
    (&w)->writeU32(6u);
    (&w)->writeU32(mArray.mLength);
    if (mArray.mLength == 0) {
        return true;
    }
    unsigned int i3 = 0;
    do {
        static_cast<rNpcLedgerList::cItem*>(mArray.getBuffer()[static_cast<int>(i3)])->save(w);
        i3 += 1u;
    } while (i3 < mArray.mLength);
    return true;
}

__attribute__((weak)) bool rNpcLedgerList::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    u32 header = r.readU32();
    if (header != 0x6c6c6eu) {
        return false;
    }
    u32 dataVersion = r.readU32();
    if (dataVersion != 6u) {
        return false;
    }
    if (mArray.isAutoDelete()) {
        mArray.deleteAll(true);
    } else {
        if (mArray.length() != 0) {
            cItem* pRoot = mArray[0];
            if (pRoot != nullptr) {
                delete[] pRoot;
            }
            mArray.clear(true);
        }
    }
    const u32 num = r.readU32();
    if (num == 0) {
        return true;
    }
    cItem* pElements = new (16u) cItem[num];
    mArray.reserve(num);
    for (u32 i = 0; i < num; i++) {
        pElements[i].load(r);
        mArray.add(&pElements[i]);
    }
    return true;
}

inline rNpcLedgerList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rNpcLedgerList::MyDTI rNpcLedgerList::DTI("rNpcLedgerList", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rNpcLedgerList::MyDTI::newInstance() const {
    return new (16u) rNpcLedgerList;
}

const MtDTI& rNpcLedgerList::cItem::getDTI() const {
    return rNpcLedgerList::cItem::DTI;
}

u32 rNpcLedgerList::cItem::getNpcId() const {
    return mNpcId;
}

u8 rNpcLedgerList::cItem::getSex() const {
    return mSex;
}

u32 rNpcLedgerList::cItem::getNameId() const {
    return mNameId;
}

u32 rNpcLedgerList::cItem::getClassNameId() const {
    return mClassNameId;
}

u8 rNpcLedgerList::cItem::getJobId() const {
    return mJobId;
}

u8 rNpcLedgerList::cItem::getFinger() const {
    return mFinger;
}

u8 rNpcLedgerList::cItem::getVoiceType() const {
    return mVoiceType;
}

u8 rNpcLedgerList::cItem::getUnitType() const {
    return mUnitType;
}

u32 rNpcLedgerList::cItem::getUnitTypeParam() const {
    return mUnitTypeParam;
}

const MtTypedArray<rNpcLedgerList::cItem::cInstitution>& rNpcLedgerList::cItem::getInstitutionList() const {
    return mInstitutionList;
}

rNpcLedgerList::cItem::~cItem() {
    if (mInstitutionList.mLength != 0) {
        u32 v0_0 = mInstitutionList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mInstitutionList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mInstitutionList.mpArray[i0_3];
                v1_0 = mInstitutionList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mInstitutionList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mInstitutionList.mpArray));
    }
    mInstitutionList.mpArray = nullptr;
    mInstitutionList.mBufsiz = 0;
    mInstitutionList.mLength = 0;
}

void rNpcLedgerList::cItem::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mNpcId", &mNpcId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSex", &mSex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNameId", &mNameId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mClassNameId", &mClassNameId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJobId", &mJobId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFinger", &mFinger, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVoiceType", &mVoiceType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUnitType", &mUnitType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUnitTypeParam", &mUnitTypeParam, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInstitutionList", static_cast<MtObject*>(&mInstitutionList), 0u, 0u);
}

__attribute__((weak)) bool rNpcLedgerList::cItem::load(MtDataReader& r) {
    nDDOIO::readData(r, mNpcId);
    nDDOIO::readData(r, mSex);
    nDDOIO::readData(r, mNameId);
    nDDOIO::readData(r, mClassNameId);
    nDDOIO::readData(r, mJobId);
    nDDOIO::readData(r, mFinger);
    nDDOIO::readData(r, mVoiceType);
    nDDOIO::readData(r, mUnitType);
    nDDOIO::readData(r, mUnitTypeParam);
    nDDOIO::readMtArray(r, mInstitutionList);
    return true;
}

__attribute__((weak)) bool rNpcLedgerList::cItem::save(MtDataWriter& w) {
    nDDOIO::writeData(w, mNpcId);
    nDDOIO::writeData(w, mSex);
    nDDOIO::writeData(w, mNameId);
    nDDOIO::writeData(w, mClassNameId);
    nDDOIO::writeData(w, mJobId);
    nDDOIO::writeData(w, mFinger);
    nDDOIO::writeData(w, mVoiceType);
    nDDOIO::writeData(w, mUnitType);
    nDDOIO::writeData(w, mUnitTypeParam);
    nDDOIO::writeMtArray(w, mInstitutionList);
    return true;
}

inline rNpcLedgerList::cItem::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rNpcLedgerList::cItem::MyDTI rNpcLedgerList::cItem::DTI("rNpcLedgerList::cItem", &::MtObject::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* rNpcLedgerList::cItem::MyDTI::newInstance() const {
    return new (16u) rNpcLedgerList::cItem;
}

const MtDTI& rNpcLedgerList::cItem::cInstitution::getDTI() const {
    return rNpcLedgerList::cItem::cInstitution::DTI;
}

rNpcLedgerList::cItem::cInstitution::~cInstitution() {
    if (mInstitutionOpenList.mLength != 0) {
        u32 v0_0 = mInstitutionOpenList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mInstitutionOpenList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mInstitutionOpenList.mpArray[i0_3];
                v1_0 = mInstitutionOpenList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mInstitutionOpenList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mInstitutionOpenList.mpArray));
    }
    mInstitutionOpenList.mpArray = nullptr;
    mInstitutionOpenList.mBufsiz = 0;
    mInstitutionOpenList.mLength = 0;
}

void rNpcLedgerList::cItem::cInstitution::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mInstitutionId", &mInstitutionId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInstitutionParam", &mInstitutionParam, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mInstitutionOpenList", static_cast<MtObject*>(&mInstitutionOpenList), 0u, 0u);
}

inline rNpcLedgerList::cItem::cInstitution::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rNpcLedgerList::cItem::cInstitution::MyDTI rNpcLedgerList::cItem::cInstitution::DTI("rNpcLedgerList::cItem::cInstitution", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* rNpcLedgerList::cItem::cInstitution::MyDTI::newInstance() const {
    return new (16u) rNpcLedgerList::cItem::cInstitution;
}

const MtDTI& rNpcLedgerList::cItem::cInstitutionOpenData::getDTI() const {
    return rNpcLedgerList::cItem::cInstitutionOpenData::DTI;
}

void rNpcLedgerList::cItem::cInstitutionOpenData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mType", &mType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlagNo", &mFlagNo, 0u, 0u);
}

inline rNpcLedgerList::cItem::cInstitutionOpenData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rNpcLedgerList::cItem::cInstitutionOpenData::MyDTI rNpcLedgerList::cItem::cInstitutionOpenData::DTI("rNpcLedgerList::cItem::cInstitutionOpenData", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* rNpcLedgerList::cItem::cInstitutionOpenData::MyDTI::newInstance() const {
    return new (16u) rNpcLedgerList::cItem::cInstitutionOpenData;
}

template MtTypedArray<rNpcLedgerList::cItem::cInstitution>::~MtTypedArray();

template MtTypedArray<rNpcLedgerList::cItem::cInstitutionOpenData>::~MtTypedArray();

template MtTypedArray<rNpcLedgerList::cItem>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rNpcLedgerList::cItem::cInstitution>&);

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rNpcLedgerList::cItem::cInstitutionOpenData>&);

