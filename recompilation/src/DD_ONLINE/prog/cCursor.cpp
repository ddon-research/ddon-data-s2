// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cCursor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "sInputManager.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCursor::getDTI() const {
    return cCursor::DTI;
}

cCursor::cCursor() {
    mIsClamp = false;
    mIsStop = false;
    mIsLoop = false;
    mIsTrg = false;
    mIsArrowOnly = false;
    mMaxY = 0;
    mMinY = 0;
    mMaxX = 0;
    mMinX = 0;
}

cCursor::~cCursor() {
}

void cCursor::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mIsStop", &mIsStop, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsLoop", &mIsLoop, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsTrg", &mIsTrg, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsArrowOnly", &mIsArrowOnly, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaxX", &mMaxX, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMinX", &mMinX, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaxY", &mMaxY, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMinY", &mMinY, 0u, 0u);
}

void cCursor::setupX(s32 min, s32 max, bool loop, bool trg, bool arrowOnly, bool clamp) {
    mMinX = min;
    mMaxX = max;
    mIsLoop = loop;
    mIsTrg = trg;
    mIsArrowOnly = arrowOnly;
    mIsClamp = clamp;
}

void cCursor::setupY(s32 min, s32 max, bool loop, bool trg, bool arrowOnly, bool clamp) {
    mMinY = min;
    mMaxY = max;
    mIsLoop = loop;
    mIsTrg = trg;
    mIsArrowOnly = arrowOnly;
    mIsClamp = clamp;
}

__attribute__((weak)) s32 cCursor::updateX(s32& cursor) {
    DDON_STUB("cCursor::updateX")
    return {};
}

__attribute__((weak)) s32 cCursor::updateY(s32& cursor) {
    DDON_STUB("cCursor::updateY")
    return {};
}

inline cCursor::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCursor::MyDTI cCursor::DTI("cCursor", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cCursor::MyDTI::newInstance() const {
    return new (16u) cCursor;
}

