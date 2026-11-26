// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rEmoteGroup.h"
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

const MtDTI& rEmoteGroup::getDTI() const {
    return rEmoteGroup::DTI;
}

inline void* rEmoteGroup::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rEmoteGroup::DTI)->memAlloc(sz, align, rEmoteGroup::DTI.getID());
}

inline void rEmoteGroup::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rEmoteGroup::DTI)->memFree(p_addr);
}

inline rEmoteGroup::rEmoteGroup() {
    setAttribute(18u);
    mpArray = nullptr;
    mArrayNum = 0;
}

rEmoteGroup::~rEmoteGroup() {
    unsigned int i3 = 0;
    if (mArrayNum != 0) {
        do {
            mpArray[i3].~InfoBinary();
            i3 += 1u;
        } while (i3 < mArrayNum);
    }
    MtMemoryAllocator::getAllocator(rEmoteGroup::DTI)->memFree(static_cast<void*>(mpArray));
    mpArray = nullptr;
    mArrayNum = 0;
}

__attribute__((weak)) void rEmoteGroup::clear() {
}

__attribute__((weak)) bool rEmoteGroup::load(MtStream& in) {
    MtDataReader r(in, 4096);
    if (r.readU32() != 0x676570) {
        return false;
    }
    if (r.readU32() != DATA_VERSION) {
        return false;
    }
    const u32 nInfoNum = r.readU32();
    const u32 nSizeBinary = r.readU32();
    void* pBinaryInfo = MtMemoryAllocator::getAllocator(rEmoteGroup::DTI)->memAlloc(nSizeBinary, 16);
    u8* pBinaryCursor = static_cast<u8*>(pBinaryInfo) + nInfoNum * sizeof(InfoBinary);
    pBinaryCursor = reinterpret_cast<u8*>((reinterpret_cast<size_t>(pBinaryCursor) + 15) & ~15ul);
    for (u32 i = 0; i < nInfoNum; ++i) {
        InfoBinary* pBinary = new (&static_cast<InfoBinary*>(pBinaryInfo)[i]) InfoBinary;
        const u32 nMotDataNum = r.readU32();
        void* pMotData = pBinaryCursor;
        pBinaryCursor += nMotDataNum * sizeof(InfoBinary::MotDataBinary);
        pBinaryCursor = reinterpret_cast<u8*>((reinterpret_cast<size_t>(pBinaryCursor) + 15) & ~15ul);
        for (u32 e = 0; e < nMotDataNum; ++e) {
            InfoBinary::MotDataBinary* pBinary = new (&static_cast<InfoBinary::MotDataBinary*>(pMotData)[e]) InfoBinary::MotDataBinary;
            pBinary->mEmo = r.readS16();
        }
        pBinary->mpMotList = static_cast<InfoBinary::MotDataBinary*>(pMotData);
        pBinary->mMotListNum = nMotDataNum;
    }
    mpArray = static_cast<InfoBinary*>(pBinaryInfo);
    mArrayNum = nInfoNum;
    return true;
}

__attribute__((weak)) bool rEmoteGroup::save(MtStream& out) {
    MtDataWriter w(out, 4096, 4096);
    w.writeU32(0x676570);
    w.writeU32(DATA_VERSION);
    const u32 nInfoNum = rEmoteGroup::getInfoNum();
    w.writeU32(nInfoNum);
    u32 nSizeBinary = nInfoNum * sizeof(InfoBinary);
    nSizeBinary = (nSizeBinary + 15) & ~15;
    for (u32 i = 0; i < nInfoNum; ++i) {
        InfoBinary* pBinary = rEmoteGroup::getInfo(i);
        nSizeBinary += pBinary->getMotListNum() * sizeof(InfoBinary::MotDataBinary);
        nSizeBinary = (nSizeBinary + 15) & ~15;
    }
    w.writeU32(nSizeBinary);
    for (u32 i = 0; i < nInfoNum; ++i) {
        InfoBinary* pBinary = rEmoteGroup::getInfo(i);
        const u32 nInfoNum = pBinary->getMotListNum();
        w.writeU32(nInfoNum);
        for (u32 e = 0; e < nInfoNum; ++e) {
            InfoBinary::MotDataBinary* pParts = pBinary->getMotList(e);
            w.writeS16(pParts->mEmo);
        }
    }
    return true;
}

MT_CTSTR rEmoteGroup::getExt() const {
    return "peg";
}

u32 rEmoteGroup::getInfoNum() const {
    return mArrayNum;
}

rEmoteGroup::InfoBinary* rEmoteGroup::getInfo(u32 index) const {
    if (index < getInfoNum()) {
        return &mpArray[index];
    } else {
        return nullptr;
    }
}

inline rEmoteGroup::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEmoteGroup::MyDTI rEmoteGroup::DTI("rEmoteGroup", &::cResource::DTI, 128ul, 0u, 0u);

MtObject* rEmoteGroup::MyDTI::newInstance() const {
    return new (16u) rEmoteGroup;
}

const MtDTI& rEmoteGroup::InfoBinary::getDTI() const {
    return rEmoteGroup::InfoBinary::DTI;
}

inline void* rEmoteGroup::InfoBinary::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rEmoteGroup::InfoBinary::DTI)->memAlloc(sz, align, rEmoteGroup::InfoBinary::DTI.getID());
}

inline void rEmoteGroup::InfoBinary::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rEmoteGroup::InfoBinary::DTI)->memFree(p_addr);
}

rEmoteGroup::InfoBinary::~InfoBinary() {
    for (u32 i = 0; i < mMotListNum; ++i) {
        mpMotList[i].~MotDataBinary();
    }
    mpMotList = nullptr;
    mMotListNum = 0;
}

s16 rEmoteGroup::InfoBinary::getEmotionNo(u32 idx) {
    if (idx < getMotListNum()) {
        MotDataBinary* data = getMotList(idx);
        if (data != nullptr) {
            return data->mEmo;
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

rEmoteGroup::InfoBinary::MotDataBinary* rEmoteGroup::InfoBinary::getMotList(u32 index) {
    return &mpMotList[index];
}

u32 rEmoteGroup::InfoBinary::getMotListNum() {
    return mMotListNum;
}

inline rEmoteGroup::InfoBinary::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEmoteGroup::InfoBinary::MyDTI rEmoteGroup::InfoBinary::DTI("rEmoteGroup::InfoBinary", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* rEmoteGroup::InfoBinary::MyDTI::newInstance() const {
    return new (16u) rEmoteGroup::InfoBinary;
}

const MtDTI& rEmoteGroup::InfoBinary::MotDataBinary::getDTI() const {
    return rEmoteGroup::InfoBinary::MotDataBinary::DTI;
}

inline void* rEmoteGroup::InfoBinary::MotDataBinary::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rEmoteGroup::InfoBinary::MotDataBinary::DTI)->memAlloc(sz, align, rEmoteGroup::InfoBinary::MotDataBinary::DTI.getID());
}

inline void rEmoteGroup::InfoBinary::MotDataBinary::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rEmoteGroup::InfoBinary::MotDataBinary::DTI)->memFree(p_addr);
}

inline rEmoteGroup::InfoBinary::MotDataBinary::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEmoteGroup::InfoBinary::MotDataBinary::MyDTI rEmoteGroup::InfoBinary::MotDataBinary::DTI("rEmoteGroup::InfoBinary::MotDataBinary", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* rEmoteGroup::InfoBinary::MotDataBinary::MyDTI::newInstance() const {
    return new (16u) rEmoteGroup::InfoBinary::MotDataBinary;
}

