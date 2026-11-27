// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlNotifyCatch.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cShlNotifyInfo.h"
#include "../../XFramework/cUnit.h"
#include "cpShlShotCtrl.h"
#include "uDDOModel.h"
#include "uEnemy.h"
#include "uShlBase.h"
#include "uShlSpeed.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamNotifyCatch::getDTI() const {
    return cShlParamNotifyCatch::DTI;
}

inline void cShlParamNotifyCatch::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamNotifyCatch::DTI)->memFree(p_addr);
}

MtDTI& cShlParamNotifyCatch::getShlDTI() const {
    return uShlNotifyCatch::DTI;
}

void cShlParamNotifyCatch::createProperty(MtPropertyList& s) {
    this->cShlParamSpeed::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mNotifyAttrFlag", &mNotifyAttrFlag, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShlReqInfo.mShotGroup", &mShlReqInfo.mShotGroup, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShlReqInfo.mShotIndex", &mShlReqInfo.mShotIndex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShlReqInfo.mShotTimer", &mShlReqInfo.mShotTimer, 0u, 0u);
}

__attribute__((weak)) void cShlParamNotifyCatch::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamNotifyCatch::copy")
    /* stub */
}

inline cShlParamNotifyCatch::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamNotifyCatch::MyDTI cShlParamNotifyCatch::DTI("cShlParamNotifyCatch", &::cShlParamSpeed::DTI, 720ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamNotifyCatch::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamNotifyCatch::DTI)->memAlloc(sizeof(cShlParamNotifyCatch), 16u, cShlParamNotifyCatch::DTI.getID())) cShlParamNotifyCatch;
}

const MtDTI& uShlNotifyCatch::getDTI() const {
    return uShlNotifyCatch::DTI;
}

void uShlNotifyCatch::setup() {
    this->uShlSpeed::setup();
}

__attribute__((weak)) void uShlNotifyCatch::update() {
    DDON_STUB("uShlNotifyCatch::update")
    /* stub */
}

__attribute__((weak)) void uShlNotifyCatch::callbackCatch(cHitInfo* pHitInfo) {
    DDON_STUB("uShlNotifyCatch::callbackCatch")
    /* stub */
}

bool uShlNotifyCatch::isOwnerCatch() const {
    return static_cast<const cShlParamNotifyCatch*>(getShlParamBase())->isOwnerCatch();
}

inline uShlNotifyCatch::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlNotifyCatch::MyDTI uShlNotifyCatch::DTI("uShlNotifyCatch", &::uShlSpeed::DTI, 11152ul, 0u, 0u);

MtObject* uShlNotifyCatch::MyDTI::newInstance() const {
    return new (16u) uShlNotifyCatch;
}

