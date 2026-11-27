// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rSoundMotionSe.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtSerializer.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rSoundMotionSe::getDTI() const {
    return rSoundMotionSe::DTI;
}

__attribute__((noinline)) rSoundMotionSe::~rSoundMotionSe() {
    if (mpIDToIndexTbl != nullptr) {
        MtMemoryAllocator::getAllocator(rSoundMotionSe::DTI)->memFree(static_cast<void*>(mpIDToIndexTbl));
        mpIDToIndexTbl = nullptr;
    }
    if (mMotionSe.mLength != 0) {
        u32 v0_0 = mMotionSe.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mMotionSe.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mMotionSe.mpArray[i0_3];
                v1_0 = mMotionSe.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mMotionSe.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mMotionSe.mpArray));
    }
    mMotionSe.mpArray = nullptr;
    mMotionSe.mBufsiz = 0;
    mMotionSe.mLength = 0;
}

MT_CTSTR rSoundMotionSe::getExt() const {
    return "mser";
}

void rSoundMotionSe::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mMotionSe", static_cast<MtObject*>(&mMotionSe), 0u, 0u);
    this->cResource::createProperty(s);
}

MtUI* rSoundMotionSe::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

bool rSoundMotionSe::load(MtStream& in) {
    MtSerializer sz(65536);
    if (sz.deserializeBinary(in, static_cast<u16>(9), static_cast<MtObject*>(&mMotionSe), MtSerializer::MODE_STATE) != nullptr) {
        createIDToIndexTbl();
        return true;
    } else {
        return false;
    }
}

bool rSoundMotionSe::save(MtStream& in) {
    MtSerializer sz(65536);
    return sz.serializeBinary(in, static_cast<u16>(9), static_cast<MtObject*>(&mMotionSe), MtSerializer::MODE_STATE, static_cast<const MtDTI*>(nullptr));
}

rSoundMotionSe::cSoundMotionSeData* rSoundMotionSe::getMotionSeDataFromUniqueID(u16 uniqueID) {
    if (uniqueID < mIDToIndexTblNum) {
        if (mpIDToIndexTbl != nullptr) {
            if (mpIDToIndexTbl[uniqueID] != 0xFFFF) {
                if (mMotionSe.mLength != 0) {
                    if (mpIDToIndexTbl[uniqueID] < mMotionSe.mLength) {
                        return static_cast<cSoundMotionSeData*>(mMotionSe.getBuffer()[mpIDToIndexTbl[uniqueID]]);
                    }
                }
            }
        }
    }
    return nullptr;
}

__attribute__((weak)) void rSoundMotionSe::createIDToIndexTbl() {
    u32 dataNum = mMotionSe.size();
    u16 maxUniqueID = 0;
    for (u32 i = 0; i < dataNum; ++i) {
        cSoundMotionSeData* pData = static_cast<cSoundMotionSeData*>(mMotionSe.getBuffer()[static_cast<s32>(i)]);
        if (pData != nullptr) {
            u16 uniqueID = static_cast<u16>(pData->getData()->mUniqueID);
            if (uniqueID > maxUniqueID) {
                maxUniqueID = uniqueID;
            }
        }
    }
    
    if (mpIDToIndexTbl != nullptr) {
        getAllocator()->memFree(mpIDToIndexTbl);
        mpIDToIndexTbl = nullptr;
    }
    if (static_cast<s16>(maxUniqueID) < 0) {
        return;
    }
    
    mIDToIndexTblNum = maxUniqueID + 1;
    mpIDToIndexTbl = static_cast<u16*>(getAllocator()->memAlloc(sizeof(*mpIDToIndexTbl) * mIDToIndexTblNum, 16));
    memset(mpIDToIndexTbl, 0xff, sizeof(*mpIDToIndexTbl) * mIDToIndexTblNum);
    for (u32 i = 0; i < dataNum; ++i) {
        cSoundMotionSeData* pData = static_cast<cSoundMotionSeData*>(mMotionSe.getBuffer()[static_cast<s32>(i)]);
        if (pData != nullptr) {
            mpIDToIndexTbl[pData->getData()->mUniqueID] = static_cast<u16>(i);
        }
    }
}

inline rSoundMotionSe::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundMotionSe::MyDTI rSoundMotionSe::DTI("rSoundMotionSe", &::cResource::DTI, 168ul, 0u, 0u);

MtObject* rSoundMotionSe::MyDTI::newInstance() const {
    return new (16u) rSoundMotionSe;
}

const MtDTI& rSoundMotionSe::cSoundMotionSeData::getDTI() const {
    return rSoundMotionSe::cSoundMotionSeData::DTI;
}

rSoundMotionSe::cSoundMotionSeData::~cSoundMotionSeData() {
}

void rSoundMotionSe::cSoundMotionSeData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "UniqueID", &mData.mUniqueID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ReqType", &mData.mRequestType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqNo_1", &mData.mSeReqNo_1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqNo_2", &mData.mSeReqNo_2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeReqNo_3", &mData.mSeReqNo_3, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeJointID", &mData.mSeJointID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "SeJointAttachFlag", &mData.mSeJointAttachFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Offset", &mData.mOffset, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "UpMarginY", &mData.mUpMarginY, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "DownMarginY", &mData.mDownMarginY, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "AttributeSeFlag", &mData.mAttributeSeFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "FreeArea", &mData.mFreeArea[0], 32u, 2u);
}

MtUI* rSoundMotionSe::cSoundMotionSeData::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline rSoundMotionSe::cSoundMotionSeData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundMotionSe::cSoundMotionSeData::MyDTI rSoundMotionSe::cSoundMotionSeData::DTI("rSoundMotionSe::cSoundMotionSeData", &::MtObject::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* rSoundMotionSe::cSoundMotionSeData::MyDTI::newInstance() const {
    return new (16u) cSoundMotionSeData;
}

template MtTypedArray<rSoundMotionSe::cSoundMotionSeData>::~MtTypedArray();

