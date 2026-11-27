// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCharParamEnemyFly.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cCharParamEnemy.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCharParamEnemyFly::getDTI() const {
    return cCharParamEnemyFly::DTI;
}

void* cCharParamEnemyFly::operator new(size_t sz, u32 align) {
    return cCharParamEnemyFly::getAllocator()->memAlloc(sz, align, cCharParamEnemyFly::DTI.getID());
}

cCharParamEnemyFly::cCharParamEnemyFly() {
    mHoverAltitude[3] = 0.0f;
    mHoverAltitude[1] = 0.0f;
    mHoverAltitude[2] = 0.0f;
    mHoverSpeed = 0.0f;
    mHoverAltitude[0] = 0.0f;
    mHoverLevelMax = 2;
    mFlySpeed = 0.0f;
    mFlyAltitude = 0.0f;
    mHoverLevelRange = 50;
}

void cCharParamEnemyFly::createProperty(MtPropertyList& s) {
    this->cCharParamEnemy::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "ホバリング速度", &mHoverSpeed, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ホバリング高度", &mHoverAltitude[0], 32u, 4u);
    s << MtProperty(static_cast<MtObject*>(this), "ホバリング高度段階数", &mHoverLevelMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ホバリング到達判定幅", &mHoverLevelRange, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "飛行速度", &mFlySpeed, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "飛行高度", &mFlyAltitude, 0u, 0u);
}

MtUI* cCharParamEnemyFly::createUI(MtProperty& prop) {
    return this->cCharParamEnemy::createUI(prop);
}

__attribute__((weak)) void cCharParamEnemyFly::paramClassCopy(MtObject* pObject) {
    DDON_STUB("cCharParamEnemyFly::paramClassCopy")
    /* stub */
}

inline cCharParamEnemyFly::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCharParamEnemyFly::MyDTI cCharParamEnemyFly::DTI("cCharParamEnemyFly", &::cCharParamEnemy::DTI, 520ul, 0u, 0u);

MtObject* cCharParamEnemyFly::MyDTI::newInstance() const {
    return new (16u) cCharParamEnemyFly;
}

