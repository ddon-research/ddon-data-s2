// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rAIPathBase.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataReader.h"
#include "../MT/MtDataWriter.h"
#include "../MT/MtGeomAABB.h"
#include "../MT/MtGeomOBB.h"
#include "../MT/MtGeomSphere.h"
#include "../MT/MtGeometry3D.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtString.h"
#include "cResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rAIPathBase::getDTI() const {
    return rAIPathBase::DTI;
}

inline void* rAIPathBase::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rAIPathBase::DTI)->memAlloc(sz, align, rAIPathBase::DTI.mID);
}

inline void rAIPathBase::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rAIPathBase::DTI)->memFree(p_addr);
}

rAIPathBase::rAIPathBase() {
    mAttr = 16;
    mNumberOfTotalAreaLink = 0;
    mNumberOfArea = 0;
    mNumberOfTotalAreaChild = 0;
    mpHierarchyArea = nullptr;
}

__attribute__((noinline)) rAIPathBase::~rAIPathBase() {
        if (mpHierarchyArea != nullptr) {
            for (u32 i = 0; i < mNumberOfArea; i++) {
                delete mpHierarchyArea[i];
            }
            MtMemoryAllocator::getAllocator(rAIPathBase::DTI)->memFree(mpHierarchyArea);
        }
}

MT_CTSTR rAIPathBase::getExt() const {
    return "are";
}

bool rAIPathBase::save(MtStream& out) {
    return true;
}

bool rAIPathBase::load(MtStream& in) {
    return true;
}

void rAIPathBase::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mNumberOfArea", &mNumberOfArea, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpHierarchyArea", reinterpret_cast<MT_MFUNC>(&::rAIPathBase::getArea), reinterpret_cast<MT_MFUNC>(&::rAIPathBase::setArea), 160u, reinterpret_cast<MT_MFUNC>(&::rAIPathBase::getNumberOfArea), reinterpret_cast<MT_MFUNC>(&::rAIPathBase::setNumberOfArea));
}

MtUI* rAIPathBase::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

__attribute__((weak)) void rAIPathBase::save(MtDataWriter* w) {
    u16 TotalLink;
    u16 TotalChild;
    TotalLink = 0;
    TotalChild = 0;
    w->writeU16(mNumberOfArea);
    for (u32 i = 0; i < mNumberOfArea; ++i) {
        w->writeU16(mpHierarchyArea[i]->mID);
        w->writeU32(mpHierarchyArea[i]->mName.length());
        w->writeString(mpHierarchyArea[i]->mName.ptr());
        w->writeU32(mpHierarchyArea[i]->mAttribute);
        w->writeU32(mpHierarchyArea[i]->mNumberOfGeometry);
        u32 n = mpHierarchyArea[i]->mNumberOfGeometry;
        for (u32 j = 0; j < n; ++j) {
            MtGeometry* pGeom = mpHierarchyArea[i]->getGeometry(j);
            if (pGeom->getDTI().getID() == MtGeomAABB::DTI.getID()) {
                MtGeomAABB* pAABB = static_cast<MtGeomAABB*>(pGeom);
                w->writeU8(0);
                w->writeV3(MtFloat3(pAABB->mAABB.minpos));
                w->writeV3(MtFloat3(pAABB->mAABB.maxpos));
            } else if (pGeom->getDTI().getID() == MtGeomOBB::DTI.getID()) {
                MtGeomOBB* pOBB = static_cast<MtGeomOBB*>(pGeom);
                w->writeU8(1);
                w->writeV3(MtFloat3(pOBB->mOBB.extent));
                w->writeV4(MtFloat4(pOBB->mOBB.coord.m[0]));
                w->writeV4(MtFloat4(pOBB->mOBB.coord.m[1]));
                w->writeV4(MtFloat4(pOBB->mOBB.coord.m[2]));
                w->writeV4(MtFloat4(pOBB->mOBB.coord.m[3]));
            } else if (pGeom->getDTI().getID() == MtGeomSphere::DTI.getID()) {
                MtGeomSphere* pSphere = static_cast<MtGeomSphere*>(pGeom);
                w->writeU8(2);
                w->writeF32(pSphere->mSphere.r);
                w->writeV3(MtFloat3(pSphere->mSphere.pos.x, pSphere->mSphere.pos.y, pSphere->mSphere.pos.z));
            }
        }
        w->writeU16(mpHierarchyArea[i]->mFirstIndex);
        w->writeU16(mpHierarchyArea[i]->mLastIndex);
        w->writeU16(static_cast<u16>(mpHierarchyArea[i]->mParentID));
        w->writeU8(mpHierarchyArea[i]->mNumberOfChild);
        for (u32 j = 0; j < mpHierarchyArea[i]->mNumberOfChild; ++j) w->writeU8(mpHierarchyArea[i]->mpChild[j]);
        w->writeU8(mpHierarchyArea[i]->mNumberOfLink);
        for (u32 j = 0; j < mpHierarchyArea[i]->mNumberOfLink; ++j) w->writeU8(mpHierarchyArea[i]->mpLink[j]);
        TotalChild += mpHierarchyArea[i]->mNumberOfChild;
        TotalLink += mpHierarchyArea[i]->mNumberOfLink;
    }
    w->writeU16(TotalChild);
    w->writeU16(TotalLink);
}

__attribute__((weak)) void rAIPathBase::load(MtDataReader* r) {
    setNumberOfArea(r->readU16());
    for (u32 i = 0; i < mNumberOfArea; ++i) {
        HierarchyArea* pArea = new (16) HierarchyArea();
        pArea->setID(r->readU16());
        MT_CHAR c[256];
        u32 s = r->readU32();
        r->readString(c, s + 1);
        pArea->setName(c);
        pArea->setAttribute(r->readU32());
        u32 n = r->readU32();
        pArea->setNumberOfGeometry(n);
        for (u32 j = 0; j < pArea->getNumberOfGeometry(); ++j) {
            u8 gIndex = r->readU8();
            if (gIndex == 0) {
                MtGeomAABB* pAABB = new (16) MtGeomAABB();
                pAABB->mAABB.minpos = r->readV3();
                pAABB->mAABB.maxpos = r->readV3();
                pArea->setGeometry(pAABB, j);
            } else if (gIndex == 1) {
                MtGeomOBB* pOBB = new (16) MtGeomOBB();
                pOBB->mOBB.extent = r->readV3();
                for (u32 t1 = 0; t1 < 4; ++t1) pOBB->mOBB.coord.m[t1] = r->readV4();
                pArea->setGeometry(pOBB, j);
            } else if (gIndex == 2) {
                MtGeomSphere* pSphere = new (16) MtGeomSphere();
                pSphere->mSphere.r = r->readF32();
                MtFloat3 t1 = r->readV3();
                pSphere->mSphere.pos.x = t1.x;
                pSphere->mSphere.pos.y = t1.y;
                pSphere->mSphere.pos.z = t1.z;
                pArea->setGeometry(pSphere, j);
            }
        }
        u16 first = r->readU16();
        u16 last = r->readU16();
        pArea->setElement(first, last);
        pArea->setParent(r->readU16());
        n = r->readU8();
        pArea->setNumberOfChild(n);
        for (u32 j = 0; j < pArea->getNumberOfChild(); ++j) pArea->setChild(r->readU8(), j);
        n = r->readU8();
        pArea->setNumberOfLink(n);
        for (u32 j = 0; j < pArea->getNumberOfLink(); ++j) pArea->setLink(r->readU8(), j);
        mpHierarchyArea[i] = pArea;
    }
    mNumberOfTotalAreaChild = r->readU16();
    mNumberOfTotalAreaLink = r->readU16();
}

__attribute__((weak)) void rAIPathBase::setNumberOfArea(u32 size) {
        if (mpHierarchyArea) {
            for (u32 i = 0; i < mNumberOfArea; ++i) {
                delete mpHierarchyArea[i];
            }
            MtMemoryAllocator::getAllocator(DTI)->memFree(mpHierarchyArea);
        }
        if (size) {
            mpHierarchyArea = static_cast<HierarchyArea**>(MtMemoryAllocator::getAllocator(DTI)->memAlloc(sizeof(HierarchyArea*) * size, 16));
            for (u32 i = 0; i < size; ++i) mpHierarchyArea[i] = nullptr;
            mNumberOfArea = static_cast<u16>(size);
        }
}

static auto ddon_emit_0x01b94260 __attribute__((used)) = &rAIPathBase::getNumberOfArea;

void rAIPathBase::setArea(rAIPathBase::HierarchyArea* area, u32 index) {
    if (mpHierarchyArea == nullptr) {
        return;
    }
    if (index < mNumberOfArea) {
        mpHierarchyArea[index] = area;
    }
}

rAIPathBase::HierarchyArea* rAIPathBase::getArea(u32 index) {
    if (index < mNumberOfArea) {
        return mpHierarchyArea[index];
    } else {
        return nullptr;
    }
}

inline rAIPathBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAIPathBase::MyDTI rAIPathBase::DTI("rAIPathBase", &::cResource::DTI, 128ul, 0u, 0u);

MtObject* rAIPathBase::MyDTI::newInstance() const {
    return new (16u) rAIPathBase;
}

const MtDTI& rAIPathBase::HierarchyArea::getDTI() const {
    return rAIPathBase::HierarchyArea::DTI;
}

inline void rAIPathBase::HierarchyArea::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rAIPathBase::HierarchyArea::DTI)->memFree(p_addr);
}

__attribute__((noinline)) rAIPathBase::HierarchyArea::~HierarchyArea() {
        if (mpChild) MtMemoryAllocator::getAllocator(DTI)->memFree(mpChild);
        if (mpLink) MtMemoryAllocator::getAllocator(DTI)->memFree(mpLink);
        if (mpGeometryList) {
            for (u32 i = 0; i < mNumberOfGeometry; ++i) delete mpGeometryList[i];
            MtMemoryAllocator::getAllocator(DTI)->memFree(mpGeometryList);
        }
}

void rAIPathBase::HierarchyArea::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mName", &mName, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNumberOfGeometry", &mNumberOfGeometry, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpGeometryList", reinterpret_cast<MT_MFUNC>(&::rAIPathBase::HierarchyArea::getGeometry), reinterpret_cast<MT_MFUNC>(&::rAIPathBase::HierarchyArea::setGeometry), 160u, reinterpret_cast<MT_MFUNC>(&::rAIPathBase::HierarchyArea::getNumberOfGeometry), reinterpret_cast<MT_MFUNC>(&::rAIPathBase::HierarchyArea::setNumberOfGeometry));
    s << MtProperty(static_cast<MtObject*>(this), "mID", &mID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFirstIndex", &mFirstIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLastIndex", &mLastIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAttribute", &mAttribute, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParentID", &mParentID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNumberOfChild", &mNumberOfChild, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U8, "mpChild", reinterpret_cast<MT_MFUNC>(&::rAIPathBase::HierarchyArea::getChild), reinterpret_cast<MT_MFUNC>(&::rAIPathBase::HierarchyArea::setChild), 160u, reinterpret_cast<MT_MFUNC>(&::rAIPathBase::HierarchyArea::getNumberOfChild), reinterpret_cast<MT_MFUNC>(&::rAIPathBase::HierarchyArea::setNumberOfChild));
    s << MtProperty(static_cast<MtObject*>(this), "mNumberOfLink", &mNumberOfLink, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U8, "mpLink", reinterpret_cast<MT_MFUNC>(&::rAIPathBase::HierarchyArea::getLink), reinterpret_cast<MT_MFUNC>(&::rAIPathBase::HierarchyArea::setLink), 160u, reinterpret_cast<MT_MFUNC>(&::rAIPathBase::HierarchyArea::getNumberOfLink), reinterpret_cast<MT_MFUNC>(&::rAIPathBase::HierarchyArea::setNumberOfLink));
}

MtUI* rAIPathBase::HierarchyArea::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void rAIPathBase::HierarchyArea::setNumberOfGeometry(u32 n) {
        if (mpGeometryList) {
            for (u32 i = 0; i < mNumberOfGeometry; ++i) delete mpGeometryList[i];
            MtMemoryAllocator::getAllocator(DTI)->memFree(mpGeometryList);
            mpGeometryList = nullptr;
        }
        mpGeometryList = static_cast<MtGeometry**>(MtMemoryAllocator::getAllocator(DTI)->memAlloc(sizeof(MtGeometry*) * n, 16));
        for (u32 i = 0; i < n; ++i) mpGeometryList[i] = nullptr;
        mNumberOfGeometry = static_cast<u8>(n);
}

static auto ddon_emit_0x01b94140 __attribute__((used)) = &rAIPathBase::HierarchyArea::getNumberOfGeometry;

static auto ddon_emit_0x01b94120 __attribute__((used)) = &rAIPathBase::HierarchyArea::setGeometry;

static auto ddon_emit_0x01b94100 __attribute__((used)) = &rAIPathBase::HierarchyArea::getGeometry;

void rAIPathBase::HierarchyArea::setChild(u32 id, u32 index) {
    if (index < mNumberOfChild) {
        mpChild[index] = static_cast<unsigned char>(id);
    }
}

s32 rAIPathBase::HierarchyArea::getChild(u32 id) {
    if (id < mNumberOfChild) {
        return mpChild[id];
    } else {
        return -1;
    }
}

void rAIPathBase::HierarchyArea::setNumberOfChild(u32 size) {
    if (mpChild != nullptr) {
        MtMemoryAllocator::getAllocator(rAIPathBase::HierarchyArea::DTI)->memFree(static_cast<void*>(mpChild));
    }
    if (size == 0) {
        return;
    }
    void* t0 = MtMemoryAllocator::getAllocator(rAIPathBase::HierarchyArea::DTI)->memAlloc(size, 16u);
    mpChild = static_cast<u8*>(t0);
    memset(t0, 0, size);
    mNumberOfChild = static_cast<unsigned char>(size);
}

static auto ddon_emit_0x01b94230 __attribute__((used)) = &rAIPathBase::HierarchyArea::getNumberOfChild;

void rAIPathBase::HierarchyArea::setLink(u32 id, u32 index) {
    if (index < mNumberOfLink) {
        mpLink[index] = static_cast<unsigned char>(id);
    }
}

s32 rAIPathBase::HierarchyArea::getLink(u32 id) {
    if (id < mNumberOfLink) {
        return mpLink[id];
    } else {
        return -1;
    }
}

void rAIPathBase::HierarchyArea::setNumberOfLink(u32 size) {
    if (mpLink != nullptr) {
        MtMemoryAllocator::getAllocator(rAIPathBase::HierarchyArea::DTI)->memFree(static_cast<void*>(mpLink));
    }
    if (size == 0) {
        return;
    }
    void* t0 = MtMemoryAllocator::getAllocator(rAIPathBase::HierarchyArea::DTI)->memAlloc(size, 16u);
    mpLink = static_cast<u8*>(t0);
    memset(t0, 0, size);
    mNumberOfLink = static_cast<unsigned char>(size);
}

static auto ddon_emit_0x01b94240 __attribute__((used)) = &rAIPathBase::HierarchyArea::getNumberOfLink;

inline rAIPathBase::HierarchyArea::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rAIPathBase::HierarchyArea::MyDTI rAIPathBase::HierarchyArea::DTI("rAIPathBase::HierarchyArea", &::MtObject::DTI, 80ul, 0u, 0u);

__attribute__((weak)) MtObject* rAIPathBase::HierarchyArea::MyDTI::newInstance() const {
    DDON_STUB("rAIPathBase::HierarchyArea::MyDTI::newInstance")
    return nullptr;
}

