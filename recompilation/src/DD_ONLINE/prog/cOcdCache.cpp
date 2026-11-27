// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cOcdCache.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "nObjCondition.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cOcdCache::getDTI() const {
    return cOcdCache::DTI;
}

cOcdCache::cOcdCache() {
    mIsActive = false;
    mReason = nObjCondition::OCD_REASON_NONE;
    mTimer = 0.0f;
}

cOcdCache::~cOcdCache() {
}

__attribute__((weak)) void cOcdCache::createProperty(MtPropertyList& s) {
}

void cOcdCache::clear() {
    mIsActive = false;
    mReason = nObjCondition::OCD_REASON_NONE;
    mTimer = 0.0f;
}

void cOcdCache::update(f32 deltaTime) {
    mTimer = mTimer - deltaTime;
    if (0.0f > mTimer) {
        mTimer = 0.0f;
        mIsActive = false;
        mReason = nObjCondition::OCD_REASON_NONE;
    }
}

void cOcdCache::copy(const cOcdCache& src) {
    mIsActive = src.mIsActive;
    mReason = src.mReason;
    mTimer = src.mTimer;
}

inline cOcdCache::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cOcdCache::MyDTI cOcdCache::DTI("cOcdCache", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cOcdCache::MyDTI::newInstance() const {
    return new (16u) cOcdCache;
}

