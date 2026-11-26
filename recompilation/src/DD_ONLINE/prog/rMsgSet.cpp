// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rMsgSet.h"
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

const MtDTI& rMsgSet::getDTI() const {
    return rMsgSet::DTI;
}

inline void* rMsgSet::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rMsgSet::DTI)->memAlloc(sz, align, rMsgSet::DTI.getID());
}

inline void rMsgSet::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rMsgSet::DTI)->memFree(p_addr);
}

MT_CTSTR rMsgSet::getExt() const {
    return "mss";
}

inline rMsgSet::rMsgSet() {
    setAttribute(22u);
    mArray.mAutoDelete = true;
    mpNativeMsgGroupArray = nullptr;
    mNativeMsgGroupArrayNum = 0;
    mpNativeMsgDataArray = nullptr;
    mNativeMsgDataArrayNum = 0;
}

rMsgSet::~rMsgSet() {
    deleteAllocateMemory();
}

void rMsgSet::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mArray", static_cast<MtObject*>(&mArray), 0u, 0u);
}

__attribute__((weak)) bool rMsgSet::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if (!r.isReadable()) {
        return false;
    }
    const u32 LoadMagic = r.readU32();
    const u32 LoadVersion = r.readU16();
    if (LoadMagic != MAGIC || LoadVersion != DATA_VERSION) {
        return false;
    }
    mArray.setAutoDelete(false);
    const u32 LoadMsgGroupTotalNum = r.readU32();
    const u32 LoadMsgDataTotalNum = r.readU32();
    const u32 AllocateSize = LoadMsgGroupTotalNum * sizeof(cMsgGroup) + LoadMsgDataTotalNum * sizeof(cMsgData);
    void* pAllocateBuffer = MtMemoryAllocator::getAllocator(DTI)->memAlloc(AllocateSize, 16u, DTI.getID());
    if (pAllocateBuffer == nullptr) {
        deleteAllocateMemory();
        return false;
    }
    mpNativeMsgGroupArray = static_cast<cMsgGroup*>(pAllocateBuffer);
    for (u32 i = 0; i < LoadMsgGroupTotalNum; i++) {
        new (&static_cast<cMsgGroup*>(pAllocateBuffer)[i]) cMsgGroup(0u, 0u, 0u, 0u, false);
    }
    mNativeMsgGroupArrayNum = LoadMsgGroupTotalNum;
    mpNativeMsgDataArray = reinterpret_cast<cMsgData*>(&static_cast<cMsgGroup*>(pAllocateBuffer)[LoadMsgGroupTotalNum]);
    for (u32 i = 0; i < LoadMsgDataTotalNum; i++) {
        new (&reinterpret_cast<cMsgData*>(&static_cast<cMsgGroup*>(pAllocateBuffer)[LoadMsgGroupTotalNum])[i]) cMsgData(0u, 0u, 0u, 0u, 0u, 0u, -1, 1u);
    }
    mNativeMsgDataArrayNum = LoadMsgDataTotalNum;
    u32 MsgGroupUseCount = 0;
    u32 MsgDataUseCount = 0;
    mArray.resize(LoadMsgGroupTotalNum);
    for (u32 i = 0; i < LoadMsgGroupTotalNum; i++) {
        const u8 GroupEnable = r.readU8();
        if (GroupEnable == 0) {
            mArray.mpArray[static_cast<s32>(i)] = nullptr;
            continue;
        }
        if (MsgGroupUseCount > LoadMsgGroupTotalNum) {
            deleteAllocateMemory();
            return false;
        }
        mArray.mpArray[static_cast<s32>(i)] = &mpNativeMsgGroupArray[MsgGroupUseCount++];
        if (!static_cast<cMsgGroup*>(mArray.mpArray[static_cast<s32>(i)])->load(r, mpNativeMsgDataArray, MsgDataUseCount, LoadMsgDataTotalNum)) {
            deleteAllocateMemory();
            return false;
        }
    }
    return true;
}

__attribute__((weak)) bool rMsgSet::save(MtStream& out) {
    MtDataWriter w(out, 4096u, 4096u);
    if (!w.isWritable()) {
        return false;
    }
    w.writeU32(MAGIC);
    w.writeU16(DATA_VERSION);
    u32 MsgGroupTotalNum = 0;
    u32 MsgDataTotalNum = 0;
    for (u32 i = 0; i < getMsgGroupNum(); i++) {
        cMsgGroup* pNowGroup = getGroupData(i);
        if (pNowGroup == nullptr) {
            continue;
        }
        const u32 MsgDataNum = pNowGroup->getMsgDataNum();
        for (u32 j = 0; j < MsgDataNum; j++) {
            if (pNowGroup->getMsgData(j) != nullptr) {
                MsgDataTotalNum++;
            }
        }
        MsgGroupTotalNum++;
    }
    w.writeU32(MsgGroupTotalNum);
    w.writeU32(MsgDataTotalNum);
    for (u32 i = 0; i < mArray.mLength; i++) {
        cMsgGroup* pNowGroup = getGroupData(i);
        if (pNowGroup == nullptr) {
            w.writeU8(0u);
            continue;
        }
        w.writeU8(1u);
        pNowGroup->save(w);
    }
    return true;
}

rMsgSet::cMsgGroup* rMsgSet::getGroupData(u32 Idx) {
    if (Idx < mArray.mLength) {
        return static_cast<cMsgGroup*>(mArray.getBuffer()[static_cast<int>(Idx)]);
    } else {
        return nullptr;
    }
}

__attribute__((weak)) void rMsgSet::deleteAllocateMemory() {
    if (mArray.mAutoDelete) {
        if (mArray.mLength != 0) {
            u32 v0_0 = mArray.mLength;
            unsigned int i0_3 = 0;
            u32 v1_0;
            for (;;) {
                if (mArray.mpArray[i0_3] == nullptr) {
                    v1_0 = v0_0;
                } else {
                    delete mArray.mpArray[i0_3];
                    v1_0 = mArray.mLength;
                }
                if ((i0_3 + 1u) < v1_0) {
                    v0_0 = v1_0;
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
        if (mArray.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mArray.mpArray));
        }
        mArray.mpArray = nullptr;
        mArray.mBufsiz = 0;
        mArray.mLength = 0;
    } else {
        if (mpNativeMsgGroupArray != nullptr) {
            if (mNativeMsgGroupArrayNum != 0) {
                cMsgGroup* v3_0 = mpNativeMsgGroupArray;
                for (unsigned int i3_3 = 0;;) {
                    v3_0[i3_3].~cMsgGroup();
                    if ((i3_3 + 1u) >= mNativeMsgGroupArrayNum) {
                        break;
                    } else {
                        v3_0 = mpNativeMsgGroupArray;
                        i3_3 += 1u;
                    }
                }
            }
            if (mNativeMsgDataArrayNum != 0) {
                for (unsigned int i5_3 = 0;;) {
                    mpNativeMsgDataArray[i5_3].~cMsgData();
                    if ((i5_3 + 1u) < mNativeMsgDataArrayNum) {
                        i5_3 += 1u;
                    } else {
                        break;
                    }
                }
            }
            MtMemoryAllocator::getAllocator(rMsgSet::DTI)->memFree(static_cast<void*>(mpNativeMsgGroupArray));
        }
        if (mArray.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mArray.mpArray));
        }
        mArray.mpArray = nullptr;
        mArray.mBufsiz = 0;
        mArray.mLength = 0;
        mArray.mAutoDelete = true;
    }
}

inline rMsgSet::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rMsgSet::MyDTI rMsgSet::DTI("rMsgSet", &::cResource::DTI, 176ul, 0u, 0u);

MtObject* rMsgSet::MyDTI::newInstance() const {
    return new (16u) rMsgSet;
}

const MtDTI& rMsgSet::cMsgGroup::getDTI() const {
    return rMsgSet::cMsgGroup::DTI;
}

inline void rMsgSet::cMsgGroup::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rMsgSet::cMsgGroup::DTI)->memFree(p_addr);
}

rMsgSet::cMsgGroup::~cMsgGroup() {
    if (mMsgData.mAutoDelete) {
        u32 v3_0;
        if (mMsgData.mLength != 0) {
            u32 v0_0 = mMsgData.mLength;
            unsigned int i0_3 = 0;
            u32 v1_0;
            for (;;) {
                if (mMsgData.mpArray[i0_3] == nullptr) {
                    v1_0 = v0_0;
                } else {
                    delete mMsgData.mpArray[i0_3];
                    v1_0 = mMsgData.mLength;
                }
                if ((i0_3 + 1u) < v1_0) {
                    v0_0 = v1_0;
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
            v3_0 = v1_0;
        } else {
            v3_0 = 0;
        }
        memset(static_cast<void*>(mMsgData.mpArray), 0, static_cast<size_t>(v3_0) * 8);
    }
    mMsgData.mLength = 0;
}

void rMsgSet::cMsgGroup::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mGroupSerial", &mGroupSerial, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNpcId", &mNpcId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroupNameSerial", &mGroupNameSerial, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroupType", &mGroupType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNameDispOff", &mNameDispOff, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMsgData", static_cast<MtObject*>(&mMsgData), 0u, 0u);
}

__attribute__((weak)) bool rMsgSet::cMsgGroup::load(MtDataReader& r, rMsgSet::cMsgData* PreAllocMsgDataArray, u32& PreAllocMsgDataUseCount, const u32 PreAllocMsgDataMaxCount) {
    nDDOIO::readData(r, mGroupSerial);
    nDDOIO::readData(r, mNpcId);
    nDDOIO::readData(r, mGroupNameSerial);
    nDDOIO::readData(r, mGroupType);
    nDDOIO::readData(r, mNameDispOff);
    mMsgData.setAutoDelete(false);
    const u32 MsgDataNum = r.readU32();
    mMsgData.resize(MsgDataNum);
    for (u32 i = 0; i < MsgDataNum; i++) {
        const u8 DataEnable = r.readU8();
        if (DataEnable == 0) {
            mMsgData.mpArray[static_cast<s32>(i)] = nullptr;
            continue;
        }
        if (PreAllocMsgDataUseCount > PreAllocMsgDataMaxCount) {
            if (mMsgData.mpArray != nullptr) {
                MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(mMsgData.mpArray);
            }
            mMsgData.mpArray = nullptr;
            mMsgData.mBufsiz = 0;
            mMsgData.mLength = 0;
            mMsgData.setAutoDelete(true);
            return false;
        }
        mMsgData.mpArray[static_cast<s32>(i)] = &PreAllocMsgDataArray[PreAllocMsgDataUseCount++];
        static_cast<rMsgSet::cMsgData*>(mMsgData.mpArray[static_cast<s32>(i)])->load(r);
    }
    return true;
}

__attribute__((weak)) bool rMsgSet::cMsgGroup::save(MtDataWriter& w) {
    nDDOIO::writeData(w, mGroupSerial);
    nDDOIO::writeData(w, mNpcId);
    nDDOIO::writeData(w, mGroupNameSerial);
    nDDOIO::writeData(w, mGroupType);
    nDDOIO::writeData(w, mNameDispOff);
    const u32 MsgDataNum = getMsgDataNum();
    w.writeU32(MsgDataNum);
    for (u32 i = 0; i < MsgDataNum; i++) {
        cMsgData* pNowData = getMsgData(i);
        if (pNowData == nullptr) {
            w.writeU8(0u);
            continue;
        }
        w.writeU8(1u);
        pNowData->save(w);
    }
    return true;
}

rMsgSet::cMsgData* rMsgSet::cMsgGroup::getMsgData(u32 Idx) {
    if (Idx < mMsgData.mLength) {
        return static_cast<cMsgData*>(mMsgData.getBuffer()[static_cast<int>(Idx)]);
    } else {
        return nullptr;
    }
}

inline rMsgSet::cMsgGroup::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rMsgSet::cMsgGroup::MyDTI rMsgSet::cMsgGroup::DTI("rMsgSet::cMsgGroup", &::MtObject::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* rMsgSet::cMsgGroup::MyDTI::newInstance() const {
    DDON_STUB("rMsgSet::cMsgGroup::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& rMsgSet::cMsgData::getDTI() const {
    return rMsgSet::cMsgData::DTI;
}

inline void rMsgSet::cMsgData::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rMsgSet::cMsgData::DTI)->memFree(p_addr);
}

rMsgSet::cMsgData::~cMsgData() {
}

void rMsgSet::cMsgData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mMsgSerial", &mMsgSerial, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGmdIndex", &mGmdIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMsgType", &mMsgType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mJumpGroupSerial", &mJumpGroupSerial, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDispType", &mDispType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDispTime", &mDispTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSetMotion", &mSetMotion, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVoiceReqNo", &mVoiceReqNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTalkFaceType", &mTalkFaceType, 0u, 0u);
}

bool rMsgSet::cMsgData::load(MtDataReader& r) {
    nDDOIO::readData(r, mMsgSerial);
    nDDOIO::readData(r, mGmdIndex);
    nDDOIO::readData(r, mMsgType);
    nDDOIO::readData(r, mJumpGroupSerial);
    nDDOIO::readData(r, mDispType);
    nDDOIO::readData(r, mDispTime);
    nDDOIO::readData(r, mSetMotion);
    nDDOIO::readData(r, mVoiceReqNo);
    nDDOIO::readData(r, mTalkFaceType);
    return true;
}

bool rMsgSet::cMsgData::save(MtDataWriter& w) {
    w.writeU32(mMsgSerial);
    w.writeU32(mGmdIndex);
    w.writeU32(mMsgType);
    w.writeU32(mJumpGroupSerial);
    w.writeU32(mDispType);
    w.writeU32(mDispTime);
    w.writeU32(mSetMotion);
    w.writeS32(mVoiceReqNo);
    u8 t0 = mTalkFaceType;
    if (w.mSeekPt >= w.mBufsiz) {
        w.flush();
    }
    w.mBuffer[w.mSeekPt] = t0;
    w.mSeekPt = w.mSeekPt + 1u;
    return true;
}

inline rMsgSet::cMsgData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rMsgSet::cMsgData::MyDTI rMsgSet::cMsgData::DTI("rMsgSet::cMsgData", &::MtObject::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* rMsgSet::cMsgData::MyDTI::newInstance() const {
    DDON_STUB("rMsgSet::cMsgData::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<rMsgSet::cMsgData>::~MtTypedArray();

template MtTypedArray<rMsgSet::cMsgGroup>::~MtTypedArray();

