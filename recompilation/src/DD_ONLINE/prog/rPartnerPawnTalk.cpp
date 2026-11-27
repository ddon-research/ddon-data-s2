// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rPartnerPawnTalk.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtRandom.h"
#include "../../XFramework/cResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rPartnerPawnTalk::getDTI() const {
    return rPartnerPawnTalk::DTI;
}

rPartnerPawnTalk::~rPartnerPawnTalk() {
    unsigned int i3 = 0;
    if (mArrayNum != 0) {
        do {
            mpArray[i3].~InfoBinary();
            i3 += 1u;
        } while (i3 < mArrayNum);
    }
    MtMemoryAllocator::getAllocator(rPartnerPawnTalk::DTI)->memFree(static_cast<void*>(mpArray));
    mpArray = nullptr;
    mArrayNum = 0;
}

__attribute__((weak)) void rPartnerPawnTalk::clear() {
}

__attribute__((weak)) bool rPartnerPawnTalk::load(MtStream& in) {
    MtDataReader r(in, 4096);
    if (r.readU32() != 0x747070) {
        return false;
    }
    if (r.readU32() != DATA_VERSION) {
        return false;
    }
    const u32 nInfoNum = r.readU32();
    const u32 nSizeBinary = r.readU32();
    void* pBinaryInfo = MtMemoryAllocator::getAllocator(rPartnerPawnTalk::DTI)->memAlloc(nSizeBinary, 16);
    u8* pBinaryCursor = static_cast<u8*>(pBinaryInfo) + nInfoNum * sizeof(InfoBinary);
    pBinaryCursor = reinterpret_cast<u8*>((reinterpret_cast<size_t>(pBinaryCursor) + 15) & ~15ul);
    for (u32 i = 0; i < nInfoNum; ++i) {
        InfoBinary* pBinary = new (&static_cast<InfoBinary*>(pBinaryInfo)[i]) InfoBinary;
        const u32 nTalkDataNum = r.readU32();
        void* pTalkData = pBinaryCursor;
        pBinaryCursor += nTalkDataNum * sizeof(InfoBinary::TalkDataBinary);
        pBinaryCursor = reinterpret_cast<u8*>((reinterpret_cast<size_t>(pBinaryCursor) + 15) & ~15ul);
        for (u32 e = 0; e < nTalkDataNum; ++e) {
            InfoBinary::TalkDataBinary* pBinary = new (&static_cast<InfoBinary::TalkDataBinary*>(pTalkData)[e]) InfoBinary::TalkDataBinary;
            pBinary->mTalk = r.readU16();
            pBinary->mType = r.readU16();
        }
        pBinary->mpTalkList = static_cast<InfoBinary::TalkDataBinary*>(pTalkData);
        pBinary->mTalkListNum = nTalkDataNum;
    }
    mpArray = static_cast<InfoBinary*>(pBinaryInfo);
    mArrayNum = nInfoNum;
    return true;
}

__attribute__((weak)) bool rPartnerPawnTalk::save(MtStream& out) {
    MtDataWriter w(out, 4096, 4096);
    w.writeU32(0x747070);
    w.writeU32(DATA_VERSION);
    const u32 nInfoNum = rPartnerPawnTalk::getInfoNum();
    w.writeU32(nInfoNum);
    u32 nSizeBinary = nInfoNum * sizeof(InfoBinary);
    nSizeBinary = (nSizeBinary + 15) & ~15;
    for (u32 i = 0; i < nInfoNum; ++i) {
        InfoBinary* pBinary = rPartnerPawnTalk::getInfo(i);
        nSizeBinary += pBinary->getTalkListNum() * sizeof(InfoBinary::TalkDataBinary);
        nSizeBinary = (nSizeBinary + 15) & ~15;
    }
    w.writeU32(nSizeBinary);
    for (u32 i = 0; i < nInfoNum; ++i) {
        InfoBinary* pBinary = rPartnerPawnTalk::getInfo(i);
        const u32 nInfoNum = pBinary->getTalkListNum();
        w.writeU32(nInfoNum);
        for (u32 e = 0; e < nInfoNum; ++e) {
            InfoBinary::TalkDataBinary* pParts = pBinary->getTalkList(e);
            w.writeU16(pParts->mTalk);
            w.writeU16(pParts->mType);
        }
    }
    return true;
}

MT_CTSTR rPartnerPawnTalk::getExt() const {
    return "ppt";
}

u32 rPartnerPawnTalk::getInfoNum() const {
    return mArrayNum;
}

rPartnerPawnTalk::InfoBinary* rPartnerPawnTalk::getInfo(u32 index) const {
    if (index < getInfoNum()) {
        return &mpArray[index];
    } else {
        return nullptr;
    }
}

inline rPartnerPawnTalk::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rPartnerPawnTalk::MyDTI rPartnerPawnTalk::DTI("rPartnerPawnTalk", &::cResource::DTI, 128ul, 0u, 0u);

MtObject* rPartnerPawnTalk::MyDTI::newInstance() const {
    return new (16u) rPartnerPawnTalk;
}

const MtDTI& rPartnerPawnTalk::InfoBinary::getDTI() const {
    return rPartnerPawnTalk::InfoBinary::DTI;
}

rPartnerPawnTalk::InfoBinary::~InfoBinary() {
    for (u32 i = 0; i < mTalkListNum; ++i) {
        mpTalkList[i].~TalkDataBinary();
    }
    mpTalkList = nullptr;
    mTalkListNum = 0;
}

__attribute__((weak)) u16 rPartnerPawnTalk::InfoBinary::getMessage(u16 type) {
    DDON_STUB("rPartnerPawnTalk::InfoBinary::getMessage")
    return {};
}

u16 rPartnerPawnTalk::InfoBinary::getGreetingMessage() {
    return getMessage(static_cast<u16>(0));
}

u16 rPartnerPawnTalk::InfoBinary::getTalkMessage() {
    return getMessage(static_cast<u16>(1));
}

rPartnerPawnTalk::InfoBinary::TalkDataBinary* rPartnerPawnTalk::InfoBinary::getTalkList(u32 index) {
    return &mpTalkList[index];
}

u32 rPartnerPawnTalk::InfoBinary::getTalkListNum() {
    return mTalkListNum;
}

inline rPartnerPawnTalk::InfoBinary::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rPartnerPawnTalk::InfoBinary::MyDTI rPartnerPawnTalk::InfoBinary::DTI("rPartnerPawnTalk::InfoBinary", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* rPartnerPawnTalk::InfoBinary::MyDTI::newInstance() const {
    return new (16u) rPartnerPawnTalk::InfoBinary;
}

const MtDTI& rPartnerPawnTalk::InfoBinary::TalkDataBinary::getDTI() const {
    return rPartnerPawnTalk::InfoBinary::TalkDataBinary::DTI;
}

inline rPartnerPawnTalk::InfoBinary::TalkDataBinary::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rPartnerPawnTalk::InfoBinary::TalkDataBinary::MyDTI rPartnerPawnTalk::InfoBinary::TalkDataBinary::DTI("rPartnerPawnTalk::InfoBinary::TalkDataBinary", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* rPartnerPawnTalk::InfoBinary::TalkDataBinary::MyDTI::newInstance() const {
    return new (16u) rPartnerPawnTalk::InfoBinary::TalkDataBinary;
}

