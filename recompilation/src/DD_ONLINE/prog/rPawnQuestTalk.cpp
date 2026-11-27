// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rPawnQuestTalk.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtRandom.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rPawnQuestTalk::getDTI() const {
    return rPawnQuestTalk::DTI;
}

__attribute__((weak)) bool rPawnQuestTalk::getTalkData(rPawnQuestTalk::MSGTYPE msgType, u32 personality, u32& groupSerial, rPawnQuestTalk::RESTYPE& resType) const {
    DDON_STUB("rPawnQuestTalk::getTalkData")
    return {};
}

MT_CTSTR rPawnQuestTalk::getExt() const {
    return "pqt";
}

rPawnQuestTalk::~rPawnQuestTalk() {
    if (mTalkDataList.mLength != 0) {
        u32 v0_0 = mTalkDataList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mTalkDataList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mTalkDataList.mpArray[i0_3];
                v1_0 = mTalkDataList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mTalkDataList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mTalkDataList.mpArray));
    }
    mTalkDataList.mpArray = nullptr;
    mTalkDataList.mBufsiz = 0;
    mTalkDataList.mLength = 0;
}

void rPawnQuestTalk::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mTalkDataList", static_cast<MtObject*>(&mTalkDataList), 0u, 0u);
}

MtUI* rPawnQuestTalk::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

bool rPawnQuestTalk::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if ((&r)->readU32() == 0x545150) {
        if ((&r)->readU32() == 1) {
            nDDOIO::readMtArray(r, mTalkDataList);
            return true;
        }
    }
    return false;
}

__attribute__((weak)) bool rPawnQuestTalk::save(MtStream& out) {
    MtDataWriter w(out, 4096u, 4096u);
    w.writeU32(0x545150u);
    w.writeU32(1u);
    w.writeU32(mTalkDataList.mLength);
    for (u32 i = 0; i < mTalkDataList.mLength; ++i) {
        static_cast<rPawnQuestTalk::cTalkData*>(mTalkDataList.mpArray[i])->save(w);
        }
    return true;
}

inline rPawnQuestTalk::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rPawnQuestTalk::MyDTI rPawnQuestTalk::DTI("rPawnQuestTalk", &::cResource::DTI, 144ul, 0u, 0u);

MtObject* rPawnQuestTalk::MyDTI::newInstance() const {
    return new (16u) rPawnQuestTalk;
}

const MtDTI& rPawnQuestTalk::cTalkData::getDTI() const {
    return rPawnQuestTalk::cTalkData::DTI;
}

rPawnQuestTalk::MSGTYPE rPawnQuestTalk::cTalkData::getMsgType() const {
    return static_cast<MSGTYPE>(mMsgType);
}

__attribute__((weak)) void rPawnQuestTalk::cTalkData::setMsgType(u8 msgType) {
    DDON_STUB("rPawnQuestTalk::cTalkData::setMsgType")
    /* stub */
}

void rPawnQuestTalk::cTalkData::load(MtDataReader& r) {
    nDDOIO::readData(r, mGroupSerial);
    nDDOIO::readData(r, mMsgType);
    mResType = r.readU8();
    mParsonality = r.readU8();
}

rPawnQuestTalk::cTalkData::~cTalkData() {
}

void rPawnQuestTalk::cTalkData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U8, "mMsgType", reinterpret_cast<MT_MFUNC>(&::rPawnQuestTalk::cTalkData::getMsgType), reinterpret_cast<MT_MFUNC>(&::rPawnQuestTalk::cTalkData::setMsgType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mResType", &mResType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParsonality", &mParsonality, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroupSerial", &mGroupSerial, 0u, 0u);
}

MtUI* rPawnQuestTalk::cTalkData::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline rPawnQuestTalk::cTalkData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rPawnQuestTalk::cTalkData::MyDTI rPawnQuestTalk::cTalkData::DTI("rPawnQuestTalk::cTalkData", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* rPawnQuestTalk::cTalkData::MyDTI::newInstance() const {
    return new (16u) rPawnQuestTalk::cTalkData;
}

template MtTypedArray<rPawnQuestTalk::cTalkData>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rPawnQuestTalk::cTalkData>&);

