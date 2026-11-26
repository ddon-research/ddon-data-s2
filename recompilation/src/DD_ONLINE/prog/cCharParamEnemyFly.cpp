// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCharParamEnemyFly.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
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

inline MtAllocator* cCharParamEnemyFly::getAllocator() {
    return MtMemoryAllocator::getAllocator(cCharParamEnemyFly::DTI);
}

void* cCharParamEnemyFly::operator new(size_t sz, u32 align) {
    return cCharParamEnemyFly::getAllocator()->memAlloc(sz, align, cCharParamEnemyFly::DTI.getID());
}

inline void cCharParamEnemyFly::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cCharParamEnemyFly::DTI)->memFree(p_addr);
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
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\233\343\203\220\343\203\252\343\203\263\343\202\260\351\200\237\345\272\246", &mHoverSpeed, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\233\343\203\220\343\203\252\343\203\263\343\202\260\351\253\230\345\272\246", &mHoverAltitude[0], 32u, 4u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\233\343\203\220\343\203\252\343\203\263\343\202\260\351\253\230\345\272\246\346\256\265\351\232\216\346\225\260", &mHoverLevelMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\343\203\233\343\203\220\343\203\252\343\203\263\343\202\260\345\210\260\351\201\224\345\210\244\345\256\232\345\271\205", &mHoverLevelRange, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\351\243\233\350\241\214\351\200\237\345\272\246", &mFlySpeed, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\351\243\233\350\241\214\351\253\230\345\272\246", &mFlyAltitude, 0u, 0u);
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

