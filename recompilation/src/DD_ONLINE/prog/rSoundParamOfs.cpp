// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rSoundParamOfs.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cSoundParamOfs::getDTI() const {
    return cSoundParamOfs::DTI;
}

inline void* cSoundParamOfs::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cSoundParamOfs::DTI)->memAlloc(sz, align, cSoundParamOfs::DTI.getID());
}

inline void cSoundParamOfs::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cSoundParamOfs::DTI)->memFree(p_addr);
}

void cSoundParamOfs::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "Vol", &mVolume, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Pitch", &mPitchShift, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ProgNo", &mProgramNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Prio", &mPriority, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "GID", &mGlobal, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ID1", &mID1, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ID2", &mID2, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ID3", &mID3, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Lmt", &mLimit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "CVol", &mCenterVol, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "VolCrvID", &mVolCurveId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "EfcCrvID", &mEffectCurveId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "LfeCrvID", &mLfeCurveId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "DrcCrvID", &mDirectionalCurveId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Submixer", &mSubmixer, 0u, 0u);
}

inline cSoundParamOfs::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cSoundParamOfs::MyDTI cSoundParamOfs::DTI("cSoundParamOfs", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* cSoundParamOfs::MyDTI::newInstance() const {
    return new (16u) cSoundParamOfs;
}

const MtDTI& rSoundParamOfs::getDTI() const {
    return rSoundParamOfs::DTI;
}

inline void* rSoundParamOfs::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rSoundParamOfs::DTI)->memAlloc(sz, align, rSoundParamOfs::DTI.getID());
}

inline void rSoundParamOfs::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rSoundParamOfs::DTI)->memFree(p_addr);
}

__attribute__((weak)) bool rSoundParamOfs::loadData(MtDataReader& in, cSoundParamOfs* pData) {
        nDDOIO::readData(in, pData->mVolume);
        nDDOIO::readData(in, pData->mPitchShift);
        nDDOIO::readData(in, pData->mProgramNo);
        {
            s8& data = pData->mPriority;
            data = in.readS8();
        }
        {
            s8& data = pData->mGlobal;
            data = in.readS8();
        }
        {
            s8& data = pData->mID1;
            data = in.readS8();
        }
        {
            s8& data = pData->mID2;
            data = in.readS8();
        }
        {
            s8& data = pData->mID3;
            data = in.readS8();
        }
        {
            s8& data = pData->mLimit;
            data = in.readS8();
        }
        {
            s8& data = pData->mCenterVol;
            data = in.readS8();
        }
        nDDOIO::readData(in, pData->mVolCurveId);
        nDDOIO::readData(in, pData->mEffectCurveId);
        nDDOIO::readData(in, pData->mLfeCurveId);
        nDDOIO::readData(in, pData->mDirectionalCurveId);
        {
            s8& data = pData->mSubmixer;
            data = in.readS8();
        }
        return true;
}

MT_CTSTR rSoundParamOfs::getExt() const {
    return "spo";
}

u32 rSoundParamOfs::getDataVersion() const {
    return 2;
}

inline rSoundParamOfs::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundParamOfs::MyDTI rSoundParamOfs::DTI("rSoundParamOfs", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rSoundParamOfs::MyDTI::newInstance() const {
    return new (16u) rSoundParamOfs;
}

template cSoundParamOfs* rTbl2<cSoundParamOfs>::getData(unsigned int);

template bool rTbl2<cSoundParamOfs>::load(MtStream&);

template bool rTbl2<cSoundParamOfs>::loadCore(MtDataReader&);

template const cSoundParamOfs* rTbl2<cSoundParamOfs>::getData(unsigned int) const;

template unsigned int rTbl2<cSoundParamOfs>::getDataNum() const;

template rTbl2<cSoundParamOfs>::~rTbl2();

