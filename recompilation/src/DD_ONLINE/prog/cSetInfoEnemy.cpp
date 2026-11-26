// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cSetInfoEnemy.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cSetInfo.h"
#include "cSetInfoCharacter.h"
#include "sWorldOffset.h"
#include "uCharacter.h"
#include "uControl.h"
#include "uControlEnemy.h"
#include "uDDOModel.h"
#include "uEnemy.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cSetInfoEnemy::getDTI() const {
    return cSetInfoEnemy::DTI;
}

inline void* cSetInfoEnemy::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cSetInfoEnemy::DTI)->memAlloc(sz, align, cSetInfoEnemy::DTI.getID());
}

void* cSetInfoEnemy::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void cSetInfoEnemy::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cSetInfoEnemy::DTI)->memFree(p_addr);
}

cSetInfoEnemy::cSetInfoEnemy() {
    mPresetKind = 0;
    mGroup = -1;
    mEmReactNo = 2;
    mSubGroupNo = -1;
    mReturnPoint2nd = false;
}

cSetInfoEnemy::~cSetInfoEnemy() {
}

void cSetInfoEnemy::createProperty(MtPropertyList& s) {
    this->cSetInfoCharacter::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mGroup", &mGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEmReactNo", &mEmReactNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPresetKind", &mPresetKind, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSubGroupNo", &mSubGroupNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mReturnPoint2nd", &mReturnPoint2nd, 0u, 0u);
}

bool cSetInfoEnemy::load(MtDataReader& r) {
    s32 t0 = r.readS32();
    mGroup = t0;
    s32 t2 = r.readS32();
    mPresetKind = t2;
    u32 t4 = r.readU32();
    mEmReactNo = t4;
    s32 t6 = r.readS32();
    mSubGroupNo = t6;
    u32 t8 = r.mSeekPt;
    u32 t9 = r.mBufsiz;
    if (t8 >= t9) {
        if (r.refill()) {
            u32 t11 = r.mSeekPt;
            u8* t12 = r.mBuffer;
            u8 t13 = t12[r.mSeekPt];
            r.mSeekPt = t11 + 1u;
            mReturnPoint2nd = t13 != 0;
            return this->cSetInfoCharacter::load(r);
        } else {
            mReturnPoint2nd = false;
            return this->cSetInfoCharacter::load(r);
        }
    } else {
        u8* t12 = r.mBuffer;
        u8 t13 = t12[r.mSeekPt];
        r.mSeekPt = t8 + 1u;
        mReturnPoint2nd = t13 != 0;
        return this->cSetInfoCharacter::load(r);
    }
}

bool cSetInfoEnemy::save(MtDataWriter& w) {
    w.writeS32(mGroup);
    w.writeS32(mPresetKind);
    w.writeU32(mEmReactNo);
    w.writeS32(mSubGroupNo);
    bool t0 = mReturnPoint2nd;
    if (w.mSeekPt >= w.mBufsiz) {
        w.flush();
    }
    w.mBuffer[w.mSeekPt] = static_cast<u8>(t0);
    w.mSeekPt = w.mSeekPt + 1u;
    return this->cSetInfoCharacter::save(w);
}

__attribute__((weak)) bool cSetInfoEnemy::applyInfo(cUnit* pu) const {
    DDON_STUB("cSetInfoEnemy::applyInfo")
    return {};
}

void cSetInfoEnemy::copy(cSetInfo* p) {
    this->cSetInfoCharacter::copy(p);
    const MtDTI& t0 = p->getDTI();
    MT_CTSTR v0_1 = cSetInfoEnemy::DTI.mName;
    for (const MtDTI* v0_0 = &t0;;) {
        if (v0_1 == v0_0->mName) {
            cSetInfoEnemy* pSie = static_cast<cSetInfoEnemy*>(p);
            mPresetKind = pSie->mPresetKind;
            mGroup = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(p) + 72);
            mEmReactNo = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(p) + 76);
            mSubGroupNo = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(p) + 80);
            mReturnPoint2nd = pSie->mReturnPoint2nd;
            return;
        } else {
            if (v0_0->mpParent != nullptr) {
                v0_0 = v0_0->mpParent;
            } else {
                break;
            }
        }
    }
}

inline cSetInfoEnemy::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cSetInfoEnemy::MyDTI cSetInfoEnemy::DTI("cSetInfoEnemy", &::cSetInfoCharacter::DTI, 88ul, 0u, 0u);

MtObject* cSetInfoEnemy::MyDTI::newInstance() const {
    return new (16u) cSetInfoEnemy;
}

