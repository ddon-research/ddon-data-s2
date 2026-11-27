// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rStageCustom.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtFilePath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "rStageCustomParts.h"
#include "../../XFramework/sResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rStageCustom::getDTI() const {
    return rStageCustom::DTI;
}

rStageCustom::~rStageCustom() {
    if (mprParts != nullptr) {
        mprParts->release();
        mprParts = nullptr;
    }
    if (mArrayAreaNum != 0) {
        for (unsigned int i0_3 = 0;;) {
            mpArrayArea[i0_3].~Area();
            if ((i0_3 + 1u) < mArrayAreaNum) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    MtMemoryAllocator::getAllocator(rStageCustom::DTI)->memFree(static_cast<void*>(mpArrayArea));
    mpArrayArea = nullptr;
    mArrayAreaNum = 0;
}

MT_CTSTR rStageCustom::getExt() const {
    return "sca";
}

__attribute__((weak)) bool rStageCustom::load(MtStream& in) {
    MtDataReader r(in, MtDataReader::DEFAULT_BUFFERSIZE);
    if (r.readU32() != 0x00616373u) {
        return false;
    }
    u32 ver = r.readU32();
    if (ver != DATA_VERSION) {
        return false;
    }
    {
        MT_CHAR t1[64];
        r.readString(t1, 64u);
        if (t1[0] != '\0') {
            const MtDTI* t2 = MtDTI::from(t1, cResource::DTI);
            r.readString(t1, 64u);
            this->mprParts = static_cast<rStageCustomParts*>(sResource::getInstance()->create(*t2, t1, sResource::MODE_BLOCKING));
        }
    }
    const u32 nArrayArea = r.readU32();
    void* pArrayArea = nullptr;
    if (nArrayArea != 0) {
        pArrayArea = MtMemoryAllocator::getAllocator(rStageCustom::DTI)->memAlloc(sizeof(Area) * nArrayArea, 16u);
        for (u32 i = 0; i < nArrayArea; i++) {
            Area* pArea = new (&static_cast<Area*>(pArrayArea)[i]) Area;
            pArea->load(r);
        }
    }
    this->mpArrayArea = static_cast<Area*>(pArrayArea);
    this->mArrayAreaNum = nArrayArea;
    this->setPartsResNumber();
    return true;
}

__attribute__((weak)) bool rStageCustom::save(MtStream& out) {
    MtDataWriter w(out, MtDataWriter::DEFAULT_BUFFERSIZE, MtDataWriter::DEFAULT_LABELSIZE);
    w.writeU32(0x00616373u);
    w.writeU32(DATA_VERSION);
    if (this->mprParts != nullptr) {
        w.writeString(this->mprParts->getDTI().getName());
        w.writeString(this->mprParts->getPath());
    } else {
        w.writeString("");
    }
    w.writeU32(this->mArrayAreaNum);
    for (u32 i = 0; i < this->mArrayAreaNum; i++) {
        Area* pArea = &this->mpArrayArea[i];
        pArea->save(w);
    }
    return true;
}

rStageCustom::Area* rStageCustom::getArea(u32 index) const {
    if (index < getAreaNum()) {
        return &mpArrayArea[index];
    } else {
        return nullptr;
    }
}

u32 rStageCustom::getAreaNum() const {
    return mArrayAreaNum;
}

rStageCustomParts::Info* rStageCustom::getAreaInfo(s32 areaNo) const {
    if (mprParts != nullptr) {
        return mprParts->searchInfo(static_cast<u32>(areaNo));
    } else {
        return nullptr;
    }
}

s32 rStageCustom::getAreaNo(s32 index) const {
    Area* area = getArea(static_cast<u32>(index));
    if (area != nullptr) {
        return area->mAreaNo;
    } else {
        return -1;
    }
}

__attribute__((weak)) void rStageCustom::getPartsName(MtString& fname) const {
    DDON_STUB("rStageCustom::getPartsName")
    /* stub */
}

inline rStageCustom::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStageCustom::MyDTI rStageCustom::DTI("rStageCustom", &::cResource::DTI, 136ul, 0u, 0u);

MtObject* rStageCustom::MyDTI::newInstance() const {
    return new (16u) rStageCustom;
}

const MtDTI& rStageCustom::Area::getDTI() const {
    return rStageCustom::Area::DTI;
}

void rStageCustom::Area::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mAreaNo", &mAreaNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFilterNo", &mFilterNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroupNo", &mGroupNo, 0u, 0u);
}

inline rStageCustom::Area::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rStageCustom::Area::MyDTI rStageCustom::Area::DTI("rStageCustom::Area", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* rStageCustom::Area::MyDTI::newInstance() const {
    return new (16u) rStageCustom::Area;
}

