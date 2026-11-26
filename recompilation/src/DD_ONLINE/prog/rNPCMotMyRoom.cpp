// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rNPCMotMyRoom.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rNPCMotMyRoom::getDTI() const {
    return rNPCMotMyRoom::DTI;
}

inline void* rNPCMotMyRoom::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rNPCMotMyRoom::DTI)->memAlloc(sz, align, rNPCMotMyRoom::DTI.getID());
}

inline void rNPCMotMyRoom::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rNPCMotMyRoom::DTI)->memFree(p_addr);
}

inline rNPCMotMyRoom::rNPCMotMyRoom() {
    setAttribute(18u);
    mpArray = nullptr;
    mArrayNum = 0;
}

rNPCMotMyRoom::~rNPCMotMyRoom() {
    unsigned int i3 = 0;
    if (mArrayNum != 0) {
        do {
            mpArray[i3].~InfoBinary();
            i3 += 1u;
        } while (i3 < mArrayNum);
    }
    MtMemoryAllocator::getAllocator(rNPCMotMyRoom::DTI)->memFree(static_cast<void*>(mpArray));
    mpArray = nullptr;
    mArrayNum = 0;
}

__attribute__((weak)) void rNPCMotMyRoom::clear() {
}

__attribute__((weak)) bool rNPCMotMyRoom::load(MtStream& in) {
    MtDataReader r(in, 4096);
    if (r.readU32() != 0x6d6d6e) {
        return false;
    }
    if (r.readU32() != DATA_VERSION) {
        return false;
    }
    const u32 nInfoNum = r.readU32();
    const u32 nSizeBinary = r.readU32();
    void* pBinaryInfo = MtMemoryAllocator::getAllocator(rNPCMotMyRoom::DTI)->memAlloc(nSizeBinary, 16);
    u8* pBinaryCursor = static_cast<u8*>(pBinaryInfo) + nInfoNum * sizeof(InfoBinary);
    pBinaryCursor = reinterpret_cast<u8*>((reinterpret_cast<size_t>(pBinaryCursor) + 15) & ~15ul);
    for (u32 i = 0; i < nInfoNum; ++i) {
        InfoBinary* pBinary = new (&static_cast<InfoBinary*>(pBinaryInfo)[i]) InfoBinary;
        pBinary->mTransOff = r.readU8() == 1;
        const u32 nMotDataNum = r.readU32();
        void* pMotData = pBinaryCursor;
        pBinaryCursor += nMotDataNum * sizeof(InfoBinary::MotDataBinary);
        pBinaryCursor = reinterpret_cast<u8*>((reinterpret_cast<size_t>(pBinaryCursor) + 15) & ~15ul);
        for (u32 e = 0; e < nMotDataNum; ++e) {
            InfoBinary::MotDataBinary* pBinary = new (&static_cast<InfoBinary::MotDataBinary*>(pMotData)[e]) InfoBinary::MotDataBinary;
            pBinary->mBankNo = r.readU8();
            pBinary->mMotNoM = r.readS16();
            pBinary->mMotNoW = r.readS16();
            pBinary->mWait = r.readS16();
            pBinary->mRandWait = r.readS16();
            pBinary->mProbability = r.readU8();
            pBinary->mNext = r.readS8();
            pBinary->mCancel = r.readS8();
            pBinary->mFrame = r.readS8();
            pBinary->mHaveItem = r.readU16();
            pBinary->mItemMotNo = r.readS16();
            pBinary->mMessage = r.readS16();
        }
        pBinary->mpMotList = static_cast<InfoBinary::MotDataBinary*>(pMotData);
        pBinary->mMotListNum = nMotDataNum;
    }
    mpArray = static_cast<InfoBinary*>(pBinaryInfo);
    mArrayNum = nInfoNum;
    return true;
}

__attribute__((weak)) bool rNPCMotMyRoom::save(MtStream& out) {
    MtDataWriter w(out, 4096, 4096);
    w.writeU32(0x6d6d6e);
    w.writeU32(DATA_VERSION);
    const u32 nInfoNum = rNPCMotMyRoom::getInfoNum();
    w.writeU32(nInfoNum);
    u32 nSizeBinary = nInfoNum * sizeof(InfoBinary);
    nSizeBinary = (nSizeBinary + 15) & ~15;
    for (u32 i = 0; i < nInfoNum; ++i) {
        InfoBinary* pBinary = rNPCMotMyRoom::getInfo(i);
        nSizeBinary += pBinary->getMotListNum() * sizeof(InfoBinary::MotDataBinary);
        nSizeBinary = (nSizeBinary + 15) & ~15;
    }
    w.writeU32(nSizeBinary);
    for (u32 i = 0; i < nInfoNum; ++i) {
        InfoBinary* pBinary = rNPCMotMyRoom::getInfo(i);
        w.writeU8(pBinary->mTransOff);
        const u32 nInfoNum = pBinary->getMotListNum();
        w.writeU32(nInfoNum);
        for (u32 e = 0; e < nInfoNum; ++e) {
            InfoBinary::MotDataBinary* pParts = pBinary->getMotList(e);
            w.writeU8(pParts->mBankNo);
            w.writeS16(pParts->mMotNoM);
            w.writeS16(pParts->mMotNoW);
            w.writeS16(pParts->mWait);
            w.writeS16(pParts->mRandWait);
            w.writeU8(pParts->mProbability);
            w.writeS8(pParts->mNext);
            w.writeS8(pParts->mCancel);
            w.writeS8(pParts->mFrame);
            w.writeU16(pParts->mHaveItem);
            w.writeS16(pParts->mItemMotNo);
            w.writeS16(pParts->mMessage);
        }
    }
    return true;
}

MT_CTSTR rNPCMotMyRoom::getExt() const {
    return "nmm";
}

u32 rNPCMotMyRoom::getInfoNum() const {
    return mArrayNum;
}

rNPCMotMyRoom::InfoBinary* rNPCMotMyRoom::getInfo(u32 index) const {
    if (index < getInfoNum()) {
        return &mpArray[index];
    } else {
        return nullptr;
    }
}

inline rNPCMotMyRoom::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rNPCMotMyRoom::MyDTI rNPCMotMyRoom::DTI("rNPCMotMyRoom", &::cResource::DTI, 128ul, 0u, 0u);

MtObject* rNPCMotMyRoom::MyDTI::newInstance() const {
    return new (16u) rNPCMotMyRoom;
}

const MtDTI& rNPCMotMyRoom::InfoBinary::getDTI() const {
    return rNPCMotMyRoom::InfoBinary::DTI;
}

inline void* rNPCMotMyRoom::InfoBinary::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rNPCMotMyRoom::InfoBinary::DTI)->memAlloc(sz, align, rNPCMotMyRoom::InfoBinary::DTI.getID());
}

inline void rNPCMotMyRoom::InfoBinary::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rNPCMotMyRoom::InfoBinary::DTI)->memFree(p_addr);
}

rNPCMotMyRoom::InfoBinary::~InfoBinary() {
    for (u32 i = 0; i < mMotListNum; ++i) {
        mpMotList[i].~MotDataBinary();
    }
    mpMotList = nullptr;
    mMotListNum = 0;
}

__attribute__((weak)) u32 rNPCMotMyRoom::InfoBinary::getMotionNo(u32 idx, u8 sex) {
    DDON_STUB("rNPCMotMyRoom::InfoBinary::getMotionNo")
    return {};
}

u8 rNPCMotMyRoom::InfoBinary::getProbability(u32 idx) {
    if (idx < getMotListNum()) {
        MotDataBinary* data = getMotList(idx);
        if (data != nullptr) {
            return data->mProbability;
        } else {
            return 100;
        }
    } else {
        return 100;
    }
}

s8 rNPCMotMyRoom::InfoBinary::getNext(u32 idx) {
    if (idx < getMotListNum()) {
        MotDataBinary* data = getMotList(idx);
        if (data != nullptr) {
            return data->mNext;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

s8 rNPCMotMyRoom::InfoBinary::getCancel(u32 idx) {
    if (idx < getMotListNum()) {
        MotDataBinary* data = getMotList(idx);
        if (data != nullptr) {
            return data->mCancel;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

u16 rNPCMotMyRoom::InfoBinary::getHaveItem(u32 idx) {
    if (idx < getMotListNum()) {
        MotDataBinary* data = getMotList(idx);
        if (data != nullptr) {
            return data->mHaveItem;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

s16 rNPCMotMyRoom::InfoBinary::getItemMotNo(u32 idx) {
    if (idx < getMotListNum()) {
        MotDataBinary* data = getMotList(idx);
        if (data != nullptr) {
            return data->mItemMotNo;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

s16 rNPCMotMyRoom::InfoBinary::getWait(u32 idx) {
    if (idx < getMotListNum()) {
        MotDataBinary* data = getMotList(idx);
        if (data != nullptr) {
            return data->mWait;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

s16 rNPCMotMyRoom::InfoBinary::getRandomWait(u32 idx) {
    if (idx < getMotListNum()) {
        MotDataBinary* data = getMotList(idx);
        if (data != nullptr) {
            return data->mRandWait;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

s8 rNPCMotMyRoom::InfoBinary::getFrame(u32 idx) {
    if (idx < getMotListNum()) {
        MotDataBinary* data = getMotList(idx);
        if (data != nullptr) {
            return data->mFrame;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

s16 rNPCMotMyRoom::InfoBinary::getMessage(u32 idx) {
    if (idx < getMotListNum()) {
        MotDataBinary* data = getMotList(idx);
        if (data != nullptr) {
            return data->mMessage;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

rNPCMotMyRoom::InfoBinary::MotDataBinary* rNPCMotMyRoom::InfoBinary::getMotList(u32 index) {
    return &mpMotList[index];
}

u32 rNPCMotMyRoom::InfoBinary::getMotListNum() {
    return mMotListNum;
}

inline rNPCMotMyRoom::InfoBinary::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rNPCMotMyRoom::InfoBinary::MyDTI rNPCMotMyRoom::InfoBinary::DTI("rNPCMotMyRoom::InfoBinary", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* rNPCMotMyRoom::InfoBinary::MyDTI::newInstance() const {
    return new (16u) rNPCMotMyRoom::InfoBinary;
}

const MtDTI& rNPCMotMyRoom::InfoBinary::MotDataBinary::getDTI() const {
    return rNPCMotMyRoom::InfoBinary::MotDataBinary::DTI;
}

inline void* rNPCMotMyRoom::InfoBinary::MotDataBinary::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rNPCMotMyRoom::InfoBinary::MotDataBinary::DTI)->memAlloc(sz, align, rNPCMotMyRoom::InfoBinary::MotDataBinary::DTI.getID());
}

inline void rNPCMotMyRoom::InfoBinary::MotDataBinary::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rNPCMotMyRoom::InfoBinary::MotDataBinary::DTI)->memFree(p_addr);
}

inline rNPCMotMyRoom::InfoBinary::MotDataBinary::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rNPCMotMyRoom::InfoBinary::MotDataBinary::MyDTI rNPCMotMyRoom::InfoBinary::MotDataBinary::DTI("rNPCMotMyRoom::InfoBinary::MotDataBinary", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* rNPCMotMyRoom::InfoBinary::MotDataBinary::MyDTI::newInstance() const {
    return new (16u) rNPCMotMyRoom::InfoBinary::MotDataBinary;
}

