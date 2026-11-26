// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rNPCEmoMyRoom.h"
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

const MtDTI& rNPCEmoMyRoom::getDTI() const {
    return rNPCEmoMyRoom::DTI;
}

inline void* rNPCEmoMyRoom::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rNPCEmoMyRoom::DTI)->memAlloc(sz, align, rNPCEmoMyRoom::DTI.getID());
}

inline void rNPCEmoMyRoom::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rNPCEmoMyRoom::DTI)->memFree(p_addr);
}

inline rNPCEmoMyRoom::rNPCEmoMyRoom() {
    setAttribute(18u);
    mpArray = nullptr;
    mArrayNum = 0;
}

rNPCEmoMyRoom::~rNPCEmoMyRoom() {
    unsigned int i3 = 0;
    if (mArrayNum != 0) {
        do {
            mpArray[i3].~InfoBinary();
            i3 += 1u;
        } while (i3 < mArrayNum);
    }
    MtMemoryAllocator::getAllocator(rNPCEmoMyRoom::DTI)->memFree(static_cast<void*>(mpArray));
    mpArray = nullptr;
    mArrayNum = 0;
}

__attribute__((weak)) void rNPCEmoMyRoom::clear() {
}

__attribute__((weak)) bool rNPCEmoMyRoom::load(MtStream& in) {
    MtDataReader r(in, 4096);
    if (r.readU32() != 0x6d656e) {
        return false;
    }
    if (r.readU32() != DATA_VERSION) {
        return false;
    }
    const u32 nInfoNum = r.readU32();
    const u32 nSizeBinary = r.readU32();
    void* pBinaryInfo = MtMemoryAllocator::getAllocator(rNPCEmoMyRoom::DTI)->memAlloc(nSizeBinary, 16);
    u8* pBinaryCursor = static_cast<u8*>(pBinaryInfo) + nInfoNum * sizeof(InfoBinary);
    pBinaryCursor = reinterpret_cast<u8*>((reinterpret_cast<size_t>(pBinaryCursor) + 15) & ~15ul);
    for (u32 i = 0; i < nInfoNum; ++i) {
        InfoBinary* pBinary = new (&static_cast<InfoBinary*>(pBinaryInfo)[i]) InfoBinary;
        pBinary->mTransOff = r.readU8() == 1;
        pBinary->mUID = r.readU32();
        const u32 nMotDataNum = r.readU32();
        void* pMotData = pBinaryCursor;
        pBinaryCursor += nMotDataNum * sizeof(InfoBinary::MotDataBinary);
        pBinaryCursor = reinterpret_cast<u8*>((reinterpret_cast<size_t>(pBinaryCursor) + 15) & ~15ul);
        for (u32 e = 0; e < nMotDataNum; ++e) {
            InfoBinary::MotDataBinary* pBinary = new (&static_cast<InfoBinary::MotDataBinary*>(pMotData)[e]) InfoBinary::MotDataBinary;
            pBinary->mMotNoM = r.readS16();
            pBinary->mMotNoW = r.readS16();
            pBinary->mFinger = r.readS16();
            pBinary->mLoop = r.readS16();
        }
        pBinary->mpMotList = static_cast<InfoBinary::MotDataBinary*>(pMotData);
        pBinary->mMotListNum = nMotDataNum;
    }
    mpArray = static_cast<InfoBinary*>(pBinaryInfo);
    mArrayNum = nInfoNum;
    return true;
}

__attribute__((weak)) bool rNPCEmoMyRoom::save(MtStream& out) {
    MtDataWriter w(out, 4096, 4096);
    w.writeU32(0x6d656e);
    w.writeU32(DATA_VERSION);
    const u32 nInfoNum = rNPCEmoMyRoom::getInfoNum();
    w.writeU32(nInfoNum);
    u32 nSizeBinary = nInfoNum * sizeof(InfoBinary);
    nSizeBinary = (nSizeBinary + 15) & ~15;
    for (u32 i = 0; i < nInfoNum; ++i) {
        InfoBinary* pBinary = rNPCEmoMyRoom::getInfo(i);
        nSizeBinary += pBinary->getMotListNum() * sizeof(InfoBinary::MotDataBinary);
        nSizeBinary = (nSizeBinary + 15) & ~15;
    }
    w.writeU32(nSizeBinary);
    for (u32 i = 0; i < nInfoNum; ++i) {
        InfoBinary* pBinary = rNPCEmoMyRoom::getInfo(i);
        w.writeU8(pBinary->mTransOff);
        w.writeU32(pBinary->mUID);
        const u32 nInfoNum = pBinary->getMotListNum();
        w.writeU32(nInfoNum);
        for (u32 e = 0; e < nInfoNum; ++e) {
            InfoBinary::MotDataBinary* pParts = pBinary->getMotList(e);
            w.writeS16(pParts->mMotNoM);
            w.writeS16(pParts->mMotNoW);
            w.writeS16(pParts->mFinger);
            w.writeS16(pParts->mLoop);
        }
    }
    return true;
}

MT_CTSTR rNPCEmoMyRoom::getExt() const {
    return "nem";
}

u32 rNPCEmoMyRoom::getInfoNum() const {
    return mArrayNum;
}

rNPCEmoMyRoom::InfoBinary* rNPCEmoMyRoom::getInfo(u32 index) const {
    if (index < getInfoNum()) {
        return &mpArray[index];
    } else {
        return nullptr;
    }
}

inline rNPCEmoMyRoom::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rNPCEmoMyRoom::MyDTI rNPCEmoMyRoom::DTI("rNPCEmoMyRoom", &::cResource::DTI, 128ul, 0u, 0u);

MtObject* rNPCEmoMyRoom::MyDTI::newInstance() const {
    return new (16u) rNPCEmoMyRoom;
}

const MtDTI& rNPCEmoMyRoom::InfoBinary::getDTI() const {
    return rNPCEmoMyRoom::InfoBinary::DTI;
}

inline void* rNPCEmoMyRoom::InfoBinary::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rNPCEmoMyRoom::InfoBinary::DTI)->memAlloc(sz, align, rNPCEmoMyRoom::InfoBinary::DTI.getID());
}

inline void rNPCEmoMyRoom::InfoBinary::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rNPCEmoMyRoom::InfoBinary::DTI)->memFree(p_addr);
}

rNPCEmoMyRoom::InfoBinary::~InfoBinary() {
    for (u32 i = 0; i < mMotListNum; ++i) {
        mpMotList[i].~MotDataBinary();
    }
    mpMotList = nullptr;
    mMotListNum = 0;
}

__attribute__((weak)) u32 rNPCEmoMyRoom::InfoBinary::getMotionNo(u32 idx, u8 sex) {
    DDON_STUB("rNPCEmoMyRoom::InfoBinary::getMotionNo")
    return {};
}

s16 rNPCEmoMyRoom::InfoBinary::getFinger(u32 idx) {
    if (idx < getMotListNum()) {
        MotDataBinary* data = getMotList(idx);
        if (data != nullptr) {
            return data->mFinger;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

s16 rNPCEmoMyRoom::InfoBinary::getLoop(u32 idx) {
    if (idx < getMotListNum()) {
        MotDataBinary* data = getMotList(idx);
        if (data != nullptr) {
            return data->mLoop;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

rNPCEmoMyRoom::InfoBinary::MotDataBinary* rNPCEmoMyRoom::InfoBinary::getMotList(u32 index) {
    return &mpMotList[index];
}

u32 rNPCEmoMyRoom::InfoBinary::getMotListNum() {
    return mMotListNum;
}

inline rNPCEmoMyRoom::InfoBinary::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rNPCEmoMyRoom::InfoBinary::MyDTI rNPCEmoMyRoom::InfoBinary::DTI("rNPCEmoMyRoom::InfoBinary", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* rNPCEmoMyRoom::InfoBinary::MyDTI::newInstance() const {
    return new (16u) rNPCEmoMyRoom::InfoBinary;
}

const MtDTI& rNPCEmoMyRoom::InfoBinary::MotDataBinary::getDTI() const {
    return rNPCEmoMyRoom::InfoBinary::MotDataBinary::DTI;
}

inline void* rNPCEmoMyRoom::InfoBinary::MotDataBinary::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rNPCEmoMyRoom::InfoBinary::MotDataBinary::DTI)->memAlloc(sz, align, rNPCEmoMyRoom::InfoBinary::MotDataBinary::DTI.getID());
}

inline void rNPCEmoMyRoom::InfoBinary::MotDataBinary::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rNPCEmoMyRoom::InfoBinary::MotDataBinary::DTI)->memFree(p_addr);
}

inline rNPCEmoMyRoom::InfoBinary::MotDataBinary::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rNPCEmoMyRoom::InfoBinary::MotDataBinary::MyDTI rNPCEmoMyRoom::InfoBinary::MotDataBinary::DTI("rNPCEmoMyRoom::InfoBinary::MotDataBinary", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* rNPCEmoMyRoom::InfoBinary::MotDataBinary::MyDTI::newInstance() const {
    return new (16u) rNPCEmoMyRoom::InfoBinary::MotDataBinary;
}

