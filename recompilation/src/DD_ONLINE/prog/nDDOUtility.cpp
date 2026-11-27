// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nDDOUtility.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtRandom.h"
#include "../../XFramework/cArea.h"
#include "../../XFramework/cGUIInstance.h"
#include "cStaminaCtrl.h"
#include "cpHumanWarpCtrl.h"
#include "cpInput.h"
#include "../../XFramework/sArea.h"
#include "sFlag.h"
#include "uEnemy.h"
#include "uGUIBase.h"
#include "uGUICharacterEdit.h"
#include "uGUIChat.h"
#include "uGUIGauge.h"
#include "uGUIGaugeArts.h"
#include "uGUIGaugeArtsV01_03.h"
#include "uGUIKeyConfig.h"
#include "uGUIPawnReview.h"
#include "uGUIPopTopSel.h"
#include "uGUIQuestActive.h"
#include "uHuman.h"

inline void* nDDOUtility::cKeyFrameValue<MtVector4, MtObject>::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(nDDOUtility::cKeyFrameValue<MtVector4, MtObject>::DTI)->memAlloc(sz, align, nDDOUtility::cKeyFrameValue<MtVector4, MtObject>::DTI.getID());
}

inline void nDDOUtility::cKeyFrameValue<MtVector4, MtObject>::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(nDDOUtility::cKeyFrameValue<MtVector4, MtObject>::DTI)->memFree(p_addr);
}

const ::MtDTI& nDDOUtility::cKeyFrameValue<MtVector4, MtObject>::getDTI() const {
    return nDDOUtility::cKeyFrameValue<MtVector4, MtObject>::DTI;
}

void nDDOUtility::cKeyFrameValue<MtVector4, MtObject>::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "keyNum", &keyNum, MtProperty::ATTR_UI_SEPARATE, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[0].key", &value[0].key, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[0].value", &value[0].value, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[1].key", &value[1].key, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[1].value", &value[1].value, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[2].key", &value[2].key, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[2].value", &value[2].value, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[3].key", &value[3].key, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[3].value", &value[3].value, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[4].key", &value[4].key, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[4].value", &value[4].value, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[5].key", &value[5].key, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[5].value", &value[5].value, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[6].key", &value[6].key, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[6].value", &value[6].value, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[7].key", &value[7].key, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[7].value", &value[7].value, 0, 0);
}

inline nDDOUtility::cKeyFrameValue<MtVector4, MtObject>::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nDDOUtility::cKeyFrameValue<MtVector4, MtObject>::MyDTI nDDOUtility::cKeyFrameValue<MtVector4, MtObject>::DTI("cKeyFrameValueColor", &::MtObject::DTI, 272ul, 0u, 0u);

MtObject* nDDOUtility::cKeyFrameValue<MtVector4, MtObject>::MyDTI::newInstance() const {
    return new (16u) nDDOUtility::cKeyFrameValue<MtVector4, MtObject>;
}

inline void* nDDOUtility::cKeyFrameValue<float, MtObject>::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(nDDOUtility::cKeyFrameValue<float, MtObject>::DTI)->memAlloc(sz, align, nDDOUtility::cKeyFrameValue<float, MtObject>::DTI.getID());
}

void nDDOUtility::cKeyFrameValue<float, MtObject>::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(nDDOUtility::cKeyFrameValue<float, MtObject>::DTI)->memFree(p_addr);
}

const ::MtDTI& nDDOUtility::cKeyFrameValue<float, MtObject>::getDTI() const {
    return nDDOUtility::cKeyFrameValue<float, MtObject>::DTI;
}

void nDDOUtility::cKeyFrameValue<float, MtObject>::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "keyNum", &keyNum, MtProperty::ATTR_UI_SEPARATE, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[0].key", &value[0].key, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[0].value", &value[0].value, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[1].key", &value[1].key, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[1].value", &value[1].value, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[2].key", &value[2].key, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[2].value", &value[2].value, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[3].key", &value[3].key, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[3].value", &value[3].value, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[4].key", &value[4].key, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[4].value", &value[4].value, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[5].key", &value[5].key, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[5].value", &value[5].value, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[6].key", &value[6].key, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[6].value", &value[6].value, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[7].key", &value[7].key, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "value[7].value", &value[7].value, 0, 0);
}

inline nDDOUtility::cKeyFrameValue<float, MtObject>::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nDDOUtility::cKeyFrameValue<float, MtObject>::MyDTI nDDOUtility::cKeyFrameValue<float, MtObject>::DTI("cKeyFrameValueF32", &::MtObject::DTI, 80ul, 0u, 0u);

MtObject* nDDOUtility::cKeyFrameValue<float, MtObject>::MyDTI::newInstance() const {
    return new (16u) nDDOUtility::cKeyFrameValue<float, MtObject>;
}
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

void nDDOUtility::requestOnTutorialFlg(s32 questTarget) {
    if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(sArea::getInstance()->mpArea[2]) + 176)) != 550) {
        return;
    }
    sFlag::getInstance()->setFlag(10u, static_cast<u32>(questTarget), true, true, false);
}

__attribute__((weak)) void nDDOUtility::arraySuffle(MtArray& dst, s32 begin, s32 end) {
    DDON_STUB("nDDOUtility::arraySuffle")
    /* stub */
}

nDDOUtility::cRNSplineBase::cRNSplineBase() {
    mMaxDistance = 0.0f;
    mMaxNodeNum = 0;
    mNodeCount = 0;
}

nDDOUtility::cRNSplineBase::~cRNSplineBase() {
}

void nDDOUtility::cRNSplineBase::init() {
    mMaxDistance = 0.0f;
    mNodeCount = 0;
}

__attribute__((weak)) void nDDOUtility::cRNSplineBase::addNode(const MtVector3& pos) {
    DDON_STUB("nDDOUtility::cRNSplineBase::addNode")
    /* stub */
}

__attribute__((weak)) void nDDOUtility::cRNSplineBase::buildSpline() {
    DDON_STUB("nDDOUtility::cRNSplineBase::buildSpline")
    /* stub */
}

__attribute__((weak)) MtVector3 nDDOUtility::cRNSplineBase::getPosition(f32 time) {
    DDON_STUB("nDDOUtility::cRNSplineBase::getPosition")
    __builtin_unreachable();
}

