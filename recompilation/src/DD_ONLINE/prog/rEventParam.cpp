// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rEventParam.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

#ifndef DDON_SIGNATURE_PROBE
extern template __attribute__((noinline)) void rTbl2<cEventParam>::allocData(unsigned int);
#endif

const MtDTI& cEventParam::getDTI() const {
    return cEventParam::DTI;
}

inline void cEventParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cEventParam::DTI)->memFree(p_addr);
}

__attribute__((noinline)) cEventParam::~cEventParam() {
    this->mOmList.deleteAll(true);
}

void cEventParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mType", &mType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStage", &mStage, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEvNo", &mEvNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFlag", &mFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "mFname", reinterpret_cast<MT_MFUNC>(&::cEventParam::getFileName), reinterpret_cast<MT_MFUNC>(&::cEventParam::setFileName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mQuestId", &mQuestId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLightCtrl", &mLightCtrl, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStartFadeType", &mStartFadeType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEndFadeType", &mEndFadeType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSubMixerBefore", &mSubMixerBefore, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSubMixerAfter", &mSubMixerAfter, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOmAQCScale", &mOmAQCScale, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVersion", &mVersion, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOmList", static_cast<MtObject*>(&mOmList), 0u, 0u);
}

__attribute__((weak)) void cEventParam::setFileName(const MtString& name) {
    this->mFname = name;
}

MT_CTSTR cEventParam::getFileName() const {
    return mFname.ptr();
}

inline cEventParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEventParam::MyDTI cEventParam::DTI("cEventParam", &::MtObject::DTI, 80ul, 0u, 0u);

__attribute__((weak)) MtObject* cEventParam::MyDTI::newInstance() const {
    return new (16u) cEventParam;
}

const MtDTI& cEventParam::cOmList::getDTI() const {
    return cEventParam::cOmList::DTI;
}

inline void* cEventParam::cOmList::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cEventParam::cOmList::DTI)->memAlloc(sz, align, cEventParam::cOmList::DTI.getID());
}

inline void cEventParam::cOmList::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cEventParam::cOmList::DTI)->memFree(p_addr);
}

void cEventParam::cOmList::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mOmId", &mOmId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCtrlType", &mCtrlType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLotType", &mLotType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGroupNo", &mGroupNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSetId", &mSetId, 0u, 0u);
}

inline cEventParam::cOmList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEventParam::cOmList::MyDTI cEventParam::cOmList::DTI("cEventParam::cOmList", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cEventParam::cOmList::MyDTI::newInstance() const {
    return new (16u) cEventParam::cOmList;
}

const MtDTI& rEventParam::getDTI() const {
    return rEventParam::DTI;
}

inline void* rEventParam::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(rEventParam::DTI)->memAlloc(sz, align, rEventParam::DTI.getID());
}

inline void rEventParam::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(rEventParam::DTI)->memFree(p_addr);
}

__attribute__((weak)) bool rEventParam::loadData(MtDataReader& in, cEventParam* pData) {
    if (pData == nullptr) {
        return false;
    }
    nDDOIO::readData(in, pData->mType);
    nDDOIO::readData(in, pData->mStage);
    nDDOIO::readData(in, pData->mEvNo);
    nDDOIO::readData(in, pData->mFlag);
    nDDOIO::readData(in, pData->mFname);
    nDDOIO::readData(in, pData->mQuestId);
    nDDOIO::readData(in, pData->mLightCtrl);
    nDDOIO::readData(in, pData->mStartFadeType);
    nDDOIO::readData(in, pData->mEndFadeType);
    nDDOIO::readData(in, pData->mSubMixerBefore);
    nDDOIO::readData(in, pData->mSubMixerAfter);
    nDDOIO::readData(in, pData->mOmAQCScale);
    const u32 nArray = in.readU32();
    for (u32 i = 0; i < nArray; i++) {
        cEventParam::cOmList* p = new (16u) cEventParam::cOmList;
        if (p != nullptr) {
            p->load(in);
            pData->addOmList(p);
        }
    }
    return true;
}

MT_CTSTR rEventParam::getExt() const {
    return "evp";
}

u32 rEventParam::getDataVersion() const {
    return 18;
}

__attribute__((weak)) bool rEventParam::load(MtStream& in) {
        MtDataReader r(in, 4096);
        u32 ver;
        this->readDataValue(r, ver);
        if (ver != this->getDataVersion()) {
            return false;
        }
        u32 dat_num;
        this->readDataValue(r, dat_num);
        this->allocData(dat_num);
        u32 num = this->mDataNum;
        if (num != 0) {
            u32 i = 0;
            cEventParam* p_dat = this->mpData;
            do {
                if (!this->loadData(r, &p_dat[i])) {
                    return false;
                }
                i += 1u;
            } while (i < num);
        }
        return true;
}

inline rEventParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rEventParam::MyDTI rEventParam::DTI("rEventParam", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rEventParam::MyDTI::newInstance() const {
    return new (16u) rEventParam;
}

template MtTypedArray<cEventParam::cOmList>::~MtTypedArray();

template cEventParam* rTbl2<cEventParam>::getData(unsigned int);

template bool rTbl2<cEventParam>::load(MtStream&);

template bool rTbl2<cEventParam>::loadCore(MtDataReader&);

template const cEventParam* rTbl2<cEventParam>::getData(unsigned int) const;

template unsigned int rTbl2<cEventParam>::getDataNum() const;

template rTbl2<cEventParam>::~rTbl2();

