// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlKeyFrame.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtEaseCurve.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "nDDOUtility.h"
#include "../../XFramework/sEffect.h"
#include "sEffectExt.h"
#include "../../XFramework/uCoord.h"
#include "uShlBase.h"
#include "uShlSpeed.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

inline void* cShlParamKeyFrame<uShlKeyFrame<uShlBase>, cShlParamBase>::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(cShlParamKeyFrame<uShlKeyFrame<uShlBase>, cShlParamBase>::DTI)->memAlloc(sz, align, cShlParamKeyFrame<uShlKeyFrame<uShlBase>, cShlParamBase>::DTI.getID());
}

inline void cShlParamKeyFrame<uShlKeyFrame<uShlBase>, cShlParamBase>::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamKeyFrame<uShlKeyFrame<uShlBase>, cShlParamBase>::DTI)->memFree(p_addr);
}

cShlParamKeyFrame<uShlKeyFrame<uShlBase>, cShlParamBase>::~cShlParamKeyFrame() {
}

const MtDTI& cShlParamKeyFrame<uShlKeyFrame<uShlBase>, cShlParamBase>::getDTI() const {
    return cShlParamKeyFrame<uShlKeyFrame<uShlBase>, cShlParamBase>::DTI;
}

void cShlParamKeyFrame<uShlKeyFrame<uShlBase>, cShlParamBase>::createProperty(MtPropertyList& s) {
    this->::cShlParamBase::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "type", reinterpret_cast<s32*>(&type), 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "curve", reinterpret_cast<s32*>(&curve), 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "valueScale", &valueScale, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "keyFrame", static_cast<MtObject*>(&keyFrame), 0, 0);
}

inline cShlParamKeyFrame<uShlKeyFrame<uShlBase>, cShlParamBase>::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamKeyFrame<uShlKeyFrame<uShlBase>, cShlParamBase>::MyDTI cShlParamKeyFrame<uShlKeyFrame<uShlBase>, cShlParamBase>::DTI("cShlParamKeyFrameBase", &::cShlParamBase::DTI, 448ul, 0u, 0u);

MtObject* cShlParamKeyFrame<uShlKeyFrame<uShlBase>, cShlParamBase>::MyDTI::newInstance() const {
    return new (16u) cShlParamKeyFrame<uShlKeyFrame<uShlBase>, cShlParamBase>;
}

inline void* cShlParamKeyFrame<uShlKeyFrame<uShlSpeed>, cShlParamSpeed>::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(cShlParamKeyFrame<uShlKeyFrame<uShlSpeed>, cShlParamSpeed>::DTI)->memAlloc(sz, align, cShlParamKeyFrame<uShlKeyFrame<uShlSpeed>, cShlParamSpeed>::DTI.getID());
}

inline void cShlParamKeyFrame<uShlKeyFrame<uShlSpeed>, cShlParamSpeed>::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamKeyFrame<uShlKeyFrame<uShlSpeed>, cShlParamSpeed>::DTI)->memFree(p_addr);
}

cShlParamKeyFrame<uShlKeyFrame<uShlSpeed>, cShlParamSpeed>::~cShlParamKeyFrame() {
}

const MtDTI& cShlParamKeyFrame<uShlKeyFrame<uShlSpeed>, cShlParamSpeed>::getDTI() const {
    return cShlParamKeyFrame<uShlKeyFrame<uShlSpeed>, cShlParamSpeed>::DTI;
}

void cShlParamKeyFrame<uShlKeyFrame<uShlSpeed>, cShlParamSpeed>::createProperty(MtPropertyList& s) {
    this->::cShlParamSpeed::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "type", reinterpret_cast<s32*>(&type), 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "curve", reinterpret_cast<s32*>(&curve), 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "valueScale", &valueScale, 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "keyFrame", static_cast<MtObject*>(&keyFrame), 0, 0);
}

inline cShlParamKeyFrame<uShlKeyFrame<uShlSpeed>, cShlParamSpeed>::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamKeyFrame<uShlKeyFrame<uShlSpeed>, cShlParamSpeed>::MyDTI cShlParamKeyFrame<uShlKeyFrame<uShlSpeed>, cShlParamSpeed>::DTI("cShlParamKeyFrameSpeed", &::cShlParamSpeed::DTI, 592ul, 0u, 0u);

MtObject* cShlParamKeyFrame<uShlKeyFrame<uShlSpeed>, cShlParamSpeed>::MyDTI::newInstance() const {
    return new (16u) cShlParamKeyFrame<uShlKeyFrame<uShlSpeed>, cShlParamSpeed>;
}

