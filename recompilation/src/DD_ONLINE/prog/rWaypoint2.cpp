// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rWaypoint2.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rWaypoint.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rWaypoint2::getDTI() const {
    return rWaypoint2::DTI;
}

inline void* rWaypoint2::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rWaypoint2::DTI)->memAlloc(sz, align, rWaypoint2::DTI.getID());
}

inline void rWaypoint2::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rWaypoint2::DTI)->memFree(p_addr);
}

MT_CTSTR rWaypoint2::getExt() const {
    return "wp2";
}

rWaypoint2::~rWaypoint2() {
    if (mRouteList2.mLength != 0) {
        u32 v0_0 = mRouteList2.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mRouteList2.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mRouteList2.mpArray[i0_3];
                v1_0 = mRouteList2.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mRouteList2.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mRouteList2.mpArray));
    }
    mRouteList2.mpArray = nullptr;
    mRouteList2.mBufsiz = 0;
    mRouteList2.mLength = 0;
}

void rWaypoint2::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mPointList", static_cast<MtObject*>(&mPointList), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRouteList2", static_cast<MtObject*>(&mRouteList2), 0u, 0u);
}

bool rWaypoint2::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if ((&r)->readU32() == 0x325057) {
        if ((&r)->readU32() == 1) {
            nDDOIO::readMtArray(r, mPointList);
            nDDOIO::readMtArray(r, mRouteList2);
            return true;
        }
    }
    return false;
}

__attribute__((weak)) bool rWaypoint2::save(MtStream& out) {
        MtDataWriter w(out, 0x1000, 0x1000);
        MtDataWriter& t1 = w;
        t1.writeU32(0x325057);
        t1.writeU32(1);
        t1.writeU32(mPointList.mLength);
        for (u32 t2 = 0; t2 < mPointList.mLength; ++t2) {
            static_cast<rWaypoint::cPoint*>(mPointList.mpArray[(s32)t2])->save(w);
        }
        t1.writeU32(mRouteList2.mLength);
        for (u32 t3 = 0; t3 < mRouteList2.mLength; ++t3) {
            cRoute2* t4 = static_cast<cRoute2*>(mRouteList2.mpArray[(s32)t3]);
            const s32* t5 = t4->mPointIdx;
            t1.writeU32(8);
            t1.write(t5, sizeof(t4->mPointIdx));
            const f32* t6 = t4->mWeight;
            t1.writeU32(8);
            t1.write(t6, sizeof(t4->mWeight));
        }
        return true;
}

inline rWaypoint2::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rWaypoint2::MyDTI rWaypoint2::DTI("rWaypoint2", &::rWaypoint::DTI, 208ul, 0u, 0u);

MtObject* rWaypoint2::MyDTI::newInstance() const {
    return new (16u) rWaypoint2;
}

const MtDTI& rWaypoint2::cRoute2::getDTI() const {
    return rWaypoint2::cRoute2::DTI;
}

void* rWaypoint2::cRoute2::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rWaypoint2::cRoute2::DTI)->memAlloc(sz, align, rWaypoint2::cRoute2::DTI.getID());
}

inline void rWaypoint2::cRoute2::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rWaypoint2::cRoute2::DTI)->memFree(p_addr);
}

rWaypoint2::cRoute2::~cRoute2() {
}

void rWaypoint2::cRoute2::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mPointIdx", &mPointIdx[0], 32u, 8u);
    s << MtProperty(static_cast<MtObject*>(this), "mWeight", &mWeight[0], 32u, 8u);
}

MtUI* rWaypoint2::cRoute2::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline rWaypoint2::cRoute2::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rWaypoint2::cRoute2::MyDTI rWaypoint2::cRoute2::DTI("rWaypoint2::cRoute2", &::MtObject::DTI, 72ul, 0u, 0u);

MtObject* rWaypoint2::cRoute2::MyDTI::newInstance() const {
    return new (16u) rWaypoint2::cRoute2;
}

template MtTypedArray<rWaypoint2::cRoute2>::~MtTypedArray();

template void nDDOIO::readMtArray(MtDataReader&, MtTypedArray<rWaypoint2::cRoute2>&);

