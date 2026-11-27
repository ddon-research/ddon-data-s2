// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rMapSpotStageList.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rMapSpotStageList::getDTI() const {
    return rMapSpotStageList::DTI;
}

rMapSpotStageList::~rMapSpotStageList() {
    unsigned int i3 = 0;
    if (mArrayNum != 0) {
        do {
            mpArray[i3].~Data();
            i3 += 1u;
        } while (i3 < mArrayNum);
    }
    MtMemoryAllocator::getAllocator(rMapSpotStageList::DTI)->memFree(static_cast<void*>(mpArray));
    mpArray = nullptr;
    mArrayNum = 0;
}

MT_CTSTR rMapSpotStageList::getExt() const {
    return "msl";
}

MT_CTSTR rMapSpotStageList::getName() const {
    return "rMapSpotStageList";
}

__attribute__((weak)) bool rMapSpotStageList::load(MtStream& in) {
    MtDataReader r(in, MtDataReader::DEFAULT_BUFFERSIZE);
    if (r.readU32() != 0x6c736d) {
        return false;
    }
    u32 ver = r.readU32();
    if (ver != DATA_VERSION) {
        return false;
    }
    const u32 nArray = r.readU32();
    void* pArray = MtMemoryAllocator::getAllocator(rMapSpotStageList::DTI)->memAlloc(sizeof(Data) * nArray, 16u);
    for (u32 i = 0; i < nArray; ++i) {
        Data* pData = new (static_cast<Data*>(pArray) + i) Data();
        pData->load(r);
    }
    mpArray = static_cast<Data*>(pArray);
    mArrayNum = nArray;
    return true;
}

rMapSpotStageList::Data* rMapSpotStageList::getData(u32 index) const {
    return &mpArray[index];
}

u32 rMapSpotStageList::getDataNum() const {
    return mArrayNum;
}

inline rMapSpotStageList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rMapSpotStageList::MyDTI rMapSpotStageList::DTI("rMapSpotStageList", &::cResource::DTI, 128ul, 0u, 0u);

MtObject* rMapSpotStageList::MyDTI::newInstance() const {
    return new (16u) rMapSpotStageList;
}

const MtDTI& rMapSpotStageList::Data::getDTI() const {
    return rMapSpotStageList::Data::DTI;
}

void rMapSpotStageList::Data::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mStageNo", &mStageNo, 0u, 0u);
}

MtUI* rMapSpotStageList::Data::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline rMapSpotStageList::Data::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rMapSpotStageList::Data::MyDTI rMapSpotStageList::Data::DTI("rMapSpotStageList::Data", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* rMapSpotStageList::Data::MyDTI::newInstance() const {
    return new (16u) rMapSpotStageList::Data;
}

