// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rNPCMotionSet.h"
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

const MtDTI& rNPCMotionSet::getDTI() const {
    return rNPCMotionSet::DTI;
}

inline void* rNPCMotionSet::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rNPCMotionSet::DTI)->memAlloc(sz, align, rNPCMotionSet::DTI.getID());
}

inline void rNPCMotionSet::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rNPCMotionSet::DTI)->memFree(p_addr);
}

inline rNPCMotionSet::rNPCMotionSet() {
    setAttribute(18u);
    mArrayNum[6] = 0;
    mArrayNum[7] = 0;
    mArrayNum[4] = 0;
    mArrayNum[5] = 0;
    mArrayNum[2] = 0;
    mArrayNum[3] = 0;
    mArrayNum[0] = 0;
    mArrayNum[1] = 0;
    mpArray[7] = nullptr;
    mpArray[6] = nullptr;
    mpArray[5] = nullptr;
    mpArray[4] = nullptr;
    mpArray[3] = nullptr;
    mpArray[2] = nullptr;
    mpArray[1] = nullptr;
    mpArray[0] = nullptr;
}

rNPCMotionSet::~rNPCMotionSet() {
    unsigned int i0_8 = 0;
    unsigned int i1_3;
    for (;;) {
        if (mArrayNum[i0_8] != 0) {
            i1_3 = 0;
            for (;;) {
                mpArray[i0_8][i1_3].~InfoBinary();
                if ((i1_3 + 1u) < mArrayNum[i0_8]) {
                    i1_3 += 1u;
                } else {
                    break;
                }
            }
        }
        MtMemoryAllocator::getAllocator(rNPCMotionSet::DTI)->memFree(static_cast<void*>(mpArray[i0_8]));
        mpArray[i0_8] = nullptr;
        mArrayNum[i0_8] = 0;
        if ((i0_8 + 1u) != 8) {
            i0_8 = i0_8 + 1u;
        } else {
            break;
        }
    }
}

__attribute__((weak)) void rNPCMotionSet::clear() {
}

__attribute__((weak)) bool rNPCMotionSet::load(MtStream& in) {
    MtDataReader r(in, 4096);
    if (r.readU32() != 0x736d6e) {
        return false;
    }
    if (r.readU32() != DATA_VERSION) {
        return false;
    }
    for (u32 type = 0; type < 8; ++type) {
        const u32 nInfoNum = r.readU32();
        const u32 nSizeBinary = r.readU32();
        void* pBinaryInfo = MtMemoryAllocator::getAllocator(rNPCMotionSet::DTI)->memAlloc(nSizeBinary, 16);
        u8* pBinaryCursor = static_cast<u8*>(pBinaryInfo) + nInfoNum * sizeof(InfoBinary);
        pBinaryCursor = reinterpret_cast<u8*>((reinterpret_cast<size_t>(pBinaryCursor) + 15) & ~15ul);
        for (u32 i = 0; i < nInfoNum; ++i) {
            InfoBinary* pBinary = new (&static_cast<InfoBinary*>(pBinaryInfo)[i]) InfoBinary;
            pBinary->mTransOff = r.readU8() == 1;
            pBinary->mRandomOn = r.readU8() == 1;
            pBinary->mTalkMot = r.readS16();
            pBinary->mHeadCtrl = r.readS16();
            pBinary->mTurnType = r.readU8();
            const u32 nMotDataNum = r.readU32();
            void* pMotData = pBinaryCursor;
            for (u32 e = 0; e < nMotDataNum; ++e) {
                InfoBinary::MotDataBinary* pBinary = new (&static_cast<InfoBinary::MotDataBinary*>(pMotData)[e]) InfoBinary::MotDataBinary;
                pBinary->mBankNo = r.readU8();
                pBinary->mMotionNo = r.readS16();
                pBinary->mWait = r.readS16();
                pBinary->mRandWait = r.readS16();
                pBinary->mStartFrame = r.readS16();
                pBinary->mProbability = r.readU8();
                pBinary->mNext = r.readS8();
                pBinary->mFrame = r.readS8();
                pBinary->mDispItem = r.readU8() != 0;
                pBinary->mPlayMusic = r.readU8() != 0;
                pBinary->mDisableCancel = r.readU8() != 0;
            }
            pBinaryCursor += nMotDataNum * sizeof(InfoBinary::MotDataBinary);
            pBinaryCursor = reinterpret_cast<u8*>((reinterpret_cast<size_t>(pBinaryCursor) + 15) & ~15ul);
            pBinary->mpMotList = static_cast<InfoBinary::MotDataBinary*>(pMotData);
            pBinary->mMotListNum = nMotDataNum;
        }
        mpArray[type] = static_cast<InfoBinary*>(pBinaryInfo);
        mArrayNum[type] = nInfoNum;
    }
    return true;
}

__attribute__((weak)) bool rNPCMotionSet::save(MtStream& out) {
    MtDataWriter w(out, 4096, 4096);
    w.writeU32(0x736d6e);
    w.writeU32(DATA_VERSION);
    for (u32 type = 0; type < 8; ++type) {
        const u32 nInfoNum = rNPCMotionSet::getInfoNum(type);
        w.writeU32(nInfoNum);
        u32 nSizeBinary = nInfoNum * sizeof(InfoBinary);
        nSizeBinary = (nSizeBinary + 15) & ~15;
        for (u32 i = 0; i < nInfoNum; ++i) {
            InfoBinary* pBinary = rNPCMotionSet::getInfo(type, i);
            nSizeBinary += pBinary->getMotListNum() * sizeof(InfoBinary::MotDataBinary);
            nSizeBinary = (nSizeBinary + 15) & ~15;
        }
        w.writeU32(nSizeBinary);
        for (u32 i = 0; i < nInfoNum; ++i) {
            InfoBinary* pBinary = rNPCMotionSet::getInfo(type, i);
            w.writeU8(pBinary->mTransOff);
            w.writeU8(pBinary->mRandomOn);
            w.writeS16(pBinary->mTalkMot);
            w.writeS16(pBinary->mHeadCtrl);
            w.writeU8(pBinary->mTurnType);
            const u32 nInfoNum = pBinary->getMotListNum();
            w.writeU32(nInfoNum);
            for (u32 e = 0; e < nInfoNum; ++e) {
                InfoBinary::MotDataBinary* pParts = pBinary->getMotList(e);
                w.writeU8(pParts->mBankNo);
                w.writeS16(pParts->mMotionNo);
                w.writeS16(pParts->mWait);
                w.writeS16(pParts->mRandWait);
                w.writeS16(pParts->mStartFrame);
                w.writeU8(pParts->mProbability);
                w.writeS8(pParts->mNext);
                w.writeS8(pParts->mFrame);
                if (pParts->mDispItem) {
                    w.writeU8(1);
                } else {
                    w.writeU8(0);
                }
                if (pParts->mPlayMusic) {
                    w.writeU8(1);
                } else {
                    w.writeU8(0);
                }
                if (pParts->mDisableCancel) {
                    w.writeU8(1);
                } else {
                    w.writeU8(0);
                }
            }
        }
    }
    return true;
}

MT_CTSTR rNPCMotionSet::getExt() const {
    return "nms";
}

u32 rNPCMotionSet::getInfoNum(s32 type) const {
    if (static_cast<unsigned int>(type) <= 7) {
        return mArrayNum[type];
    } else {
        return 0;
    }
}

rNPCMotionSet::InfoBinary* rNPCMotionSet::getInfo(s32 type, u32 index) const {
    if (static_cast<unsigned int>(type) <= 7) {
        if (index < getInfoNum(type)) {
            return &mpArray[type][index];
        }
    }
    return nullptr;
}

inline rNPCMotionSet::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rNPCMotionSet::MyDTI rNPCMotionSet::DTI("rNPCMotionSet", &::cResource::DTI, 208ul, 0u, 0u);

MtObject* rNPCMotionSet::MyDTI::newInstance() const {
    return new (16u) rNPCMotionSet;
}

const MtDTI& rNPCMotionSet::InfoBinary::getDTI() const {
    return rNPCMotionSet::InfoBinary::DTI;
}

inline void* rNPCMotionSet::InfoBinary::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rNPCMotionSet::InfoBinary::DTI)->memAlloc(sz, align, rNPCMotionSet::InfoBinary::DTI.getID());
}

inline void rNPCMotionSet::InfoBinary::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rNPCMotionSet::InfoBinary::DTI)->memFree(p_addr);
}

rNPCMotionSet::InfoBinary::~InfoBinary() {
    for (u32 i = 0; i < mMotListNum; ++i) {
        mpMotList[i].~MotDataBinary();
    }
    mpMotList = nullptr;
    mMotListNum = 0;
}

__attribute__((weak)) u32 rNPCMotionSet::InfoBinary::getMotionNo(u32 idx) {
    DDON_STUB("rNPCMotionSet::InfoBinary::getMotionNo")
    return {};
}

u8 rNPCMotionSet::InfoBinary::getProbability(u32 idx) {
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

s8 rNPCMotionSet::InfoBinary::getNext(u32 idx) {
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

bool rNPCMotionSet::InfoBinary::getDispItem(u32 idx) {
    if (idx < getMotListNum()) {
        MotDataBinary* data = getMotList(idx);
        if (data != nullptr) {
            return data->mDispItem;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool rNPCMotionSet::InfoBinary::getDisableCancel(u32 idx) {
    if (idx < getMotListNum()) {
        MotDataBinary* data = getMotList(idx);
        if (data != nullptr) {
            return data->mDisableCancel;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

s16 rNPCMotionSet::InfoBinary::getWait(u32 idx) {
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

s16 rNPCMotionSet::InfoBinary::getStartFrame(u32 idx) {
    if (idx < getMotListNum()) {
        MotDataBinary* data = getMotList(idx);
        if (data != nullptr) {
            return data->mStartFrame;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

s16 rNPCMotionSet::InfoBinary::getRandomWait(u32 idx) {
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

s8 rNPCMotionSet::InfoBinary::getFrame(u32 idx) {
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

rNPCMotionSet::InfoBinary::MotDataBinary* rNPCMotionSet::InfoBinary::getMotList(u32 index) {
    return &mpMotList[index];
}

u32 rNPCMotionSet::InfoBinary::getMotListNum() {
    return mMotListNum;
}

inline rNPCMotionSet::InfoBinary::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rNPCMotionSet::InfoBinary::MyDTI rNPCMotionSet::InfoBinary::DTI("rNPCMotionSet::InfoBinary", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* rNPCMotionSet::InfoBinary::MyDTI::newInstance() const {
    return new (16u) rNPCMotionSet::InfoBinary;
}

const MtDTI& rNPCMotionSet::InfoBinary::MotDataBinary::getDTI() const {
    return rNPCMotionSet::InfoBinary::MotDataBinary::DTI;
}

inline void* rNPCMotionSet::InfoBinary::MotDataBinary::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rNPCMotionSet::InfoBinary::MotDataBinary::DTI)->memAlloc(sz, align, rNPCMotionSet::InfoBinary::MotDataBinary::DTI.getID());
}

inline void rNPCMotionSet::InfoBinary::MotDataBinary::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rNPCMotionSet::InfoBinary::MotDataBinary::DTI)->memFree(p_addr);
}

inline rNPCMotionSet::InfoBinary::MotDataBinary::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rNPCMotionSet::InfoBinary::MotDataBinary::MyDTI rNPCMotionSet::InfoBinary::MotDataBinary::DTI("rNPCMotionSet::InfoBinary::MotDataBinary", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* rNPCMotionSet::InfoBinary::MotDataBinary::MyDTI::newInstance() const {
    return new (16u) rNPCMotionSet::InfoBinary::MotDataBinary;
}

