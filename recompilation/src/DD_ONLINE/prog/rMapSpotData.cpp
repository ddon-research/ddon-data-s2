// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rMapSpotData.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rMapSpotData::getDTI() const {
    return rMapSpotData::DTI;
}

inline void* rMapSpotData::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rMapSpotData::DTI)->memAlloc(sz, align, rMapSpotData::DTI.getID());
}

inline void rMapSpotData::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rMapSpotData::DTI)->memFree(p_addr);
}

inline rMapSpotData::rMapSpotData() {
    setAttribute(22u);
    mpArray = nullptr;
    mArrayNum = 0;
}

rMapSpotData::~rMapSpotData() {
    unsigned int i3 = 0;
    if (mArrayNum != 0) {
        do {
            mpArray[i3].~Data();
            i3 += 1u;
        } while (i3 < mArrayNum);
    }
    MtMemoryAllocator::getAllocator(rMapSpotData::DTI)->memFree(static_cast<void*>(mpArray));
    mpArray = nullptr;
    mArrayNum = 0;
}

MT_CTSTR rMapSpotData::getExt() const {
    return "msd";
}

MT_CTSTR rMapSpotData::getName() const {
    return "rMapSpotData";
}

__attribute__((weak)) bool rMapSpotData::load(MtStream& in) {
    MtDataReader r(in, MtDataReader::DEFAULT_BUFFERSIZE);
    if (r.readU32() != 0x64736d) {
        return false;
    }
    u32 ver = r.readU32();
    if (ver != DATA_VERSION) {
        return false;
    }
    const u32 nArray = r.readU32();
    void* pArray = getAllocator()->memAlloc(sizeof(Data) * nArray, 16u);
    for (u32 i = 0; i < nArray; ++i) {
        rMapSpotData::Data* pData = new (&static_cast<Data*>(pArray)[i]) Data();
        pData->load(r);
    }
    mpArray = static_cast<Data*>(pArray);
    mArrayNum = nArray;
    return true;
}

rMapSpotData::Data* rMapSpotData::getData(u32 index) const {
    return &mpArray[index];
}

u32 rMapSpotData::getDataNum() const {
    return mArrayNum;
}

__attribute__((weak)) void rMapSpotData::setupSpotMsgId() {
    DDON_STUB("rMapSpotData::setupSpotMsgId")
    /* stub */
}

inline rMapSpotData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rMapSpotData::MyDTI rMapSpotData::DTI("rMapSpotData", &::cResource::DTI, 128ul, 0u, 0u);

MtObject* rMapSpotData::MyDTI::newInstance() const {
    return new (16u) rMapSpotData;
}

const MtDTI& rMapSpotData::Data::getDTI() const {
    return rMapSpotData::Data::DTI;
}

inline void* rMapSpotData::Data::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rMapSpotData::Data::DTI)->memAlloc(sz, align, rMapSpotData::Data::DTI.getID());
}

inline void rMapSpotData::Data::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rMapSpotData::Data::DTI)->memFree(p_addr);
}

inline rMapSpotData::Data::Data() {
    mPos.x = MtVector3::Zero.x;
    mPos.y = MtVector3::Zero.y;
    mPos.z = MtVector3::Zero.z;
    mPos.pad_ = 0.0f;
    mMessId = 0;
    mFloorNo = -9999;
    mGroupNo = -9999;
    mFloorCheck = true;
}

void rMapSpotData::Data::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMessId", &mMessId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFloorNo", &mFloorNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroupNo", &mGroupNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFloorCheck", &mFloorCheck, 0u, 0u);
}

MtUI* rMapSpotData::Data::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline rMapSpotData::Data::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rMapSpotData::Data::MyDTI rMapSpotData::Data::DTI("rMapSpotData::Data", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* rMapSpotData::Data::MyDTI::newInstance() const {
    return new (16u) rMapSpotData::Data;
}

