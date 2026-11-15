// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rEmEffectTable.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cResource.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTable.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cEmEffectTable::getDTI() const {
    return cEmEffectTable::DTI;
}

inline void* cEmEffectTable::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cEmEffectTable::DTI)->memAlloc(sz, align, cEmEffectTable::DTI.getID());
}

inline void cEmEffectTable::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cEmEffectTable::DTI)->memFree(p_addr);
}

__attribute__((weak)) void cEmEffectTable::createProperty(MtPropertyList& s) {
    DDON_STUB("cEmEffectTable::createProperty")
    /* stub */
}

inline cEmEffectTable::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEmEffectTable::MyDTI cEmEffectTable::DTI("cEmEffectTable", &::MtObject::DTI, 64ul, 0u, 0u);

MtObject* cEmEffectTable::MyDTI::newInstance() const {
    return new (16u) cEmEffectTable;
}

const MtDTI& rEmEffectTable::getDTI() const {
    return rEmEffectTable::DTI;
}

inline void* rEmEffectTable::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rEmEffectTable::DTI)->memAlloc(sz, align, rEmEffectTable::DTI.getID());
}

inline void rEmEffectTable::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rEmEffectTable::DTI)->memFree(p_addr);
}

inline rEmEffectTable::rEmEffectTable() {
    setAttribute(16u);
}

__attribute__((weak)) const MtDTI& rEmEffectTable::getDataDTI() {
    DDON_STUB("rEmEffectTable::getDataDTI")
    __builtin_unreachable();
}

MT_CTSTR rEmEffectTable::getExt() const {
    return "eef";
}

u16 rEmEffectTable::getDataVersion() {
    return 258;
}

bool rEmEffectTable::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    return loadData(r);
}

__attribute__((weak)) bool rEmEffectTable::loadData(MtDataReader& in) {
    bool ret = false;
    u32 magic = in.readU32();
    u32 version = in.readU16();
    if (magic == rTable::mMagic && version == cEmEffectTable::DATA_VERSION) {
        u32 dmy = in.readU16();
        (void)dmy;
        u32 Num = in.readU32();
        for (u32 i = 0; i < Num; i++) {
            cEmEffectTable* pObj = new (16u) cEmEffectTable;
            if (pObj != nullptr) {
                loadData(in, pObj);
                mArray.add(pObj);
            }
        }
        ret = true;
    }
    return ret;
}

__attribute__((weak)) bool rEmEffectTable::save(MtStream& out) {
    MtDataWriter w(out, MtDataWriter::DEFAULT_BUFFERSIZE, MtDataWriter::DEFAULT_LABELSIZE);
    return saveData(w);
}

bool rEmEffectTable::loadData(MtDataReader& in, cEmEffectTable* pData) {
    pData->mIdx = in.readU32();
    pData->mEffectSyncBitNo = in.readU32();
    pData->mEffectResNo = in.readU32();
    pData->mEffectEndType = in.readS32();
    pData->mEffectIndexNo = in.readS32();
    pData->mEffectElementNo = in.readS32();
    pData->mBoneNo = in.readU32();
    pData->mOffsetPos = in.readV3();
    nDDOIO::readData(in, pData->mDieNoCall);
    return true;
}

bool rEmEffectTable::saveData(MtDataWriter& out, cEmEffectTable* pData) {
    out.writeU32(pData->mIdx);
    out.writeU32(pData->mEffectSyncBitNo);
    out.writeU32(pData->mEffectResNo);
    out.writeS32(pData->mEffectEndType);
    out.writeS32(pData->mEffectIndexNo);
    out.writeS32(pData->mEffectElementNo);
    out.writeU32(pData->mBoneNo);
    MtFloat3 frame56;
    frame56.x = pData->mOffsetPos.x;
    frame56.y = pData->mOffsetPos.y;
    frame56.z = pData->mOffsetPos.z;
    out.writeV3(frame56);
    bool t0 = pData->mDieNoCall;
    if (out.mSeekPt >= out.mBufsiz) {
        out.flush();
    }
    out.mBuffer[out.mSeekPt] = static_cast<u8>(t0);
    out.mSeekPt = out.mSeekPt + 1u;
    return true;
}

inline rEmEffectTable::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEmEffectTable::MyDTI rEmEffectTable::DTI("rEmEffectTable", &::rTable::DTI, 176ul, 0u, 0u);

MtObject* rEmEffectTable::MyDTI::newInstance() const {
    return new (16u) rEmEffectTable;
}

