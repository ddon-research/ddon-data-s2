// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uCnsMotFilter.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cpComponent.h"
#include "cpMotionFilter.h"
#include "../../XFramework/uConstraint.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uCnsMotFilter::getDTI() const {
    return uCnsMotFilter::DTI;
}

void* uCnsMotFilter::operator new(size_t sz, u32 align) {
    return uCnsMotFilter::getAllocator()->memAlloc(sz, align, uCnsMotFilter::DTI.getID());
}

uCnsMotFilter::uCnsMotFilter() {
    mJoint = 0;
    mMulMode = 0;
    mpMotFlt = nullptr;
    mSleep = false;
}

uCnsMotFilter::~uCnsMotFilter() {
    removeConstraint();
}

cResource* uCnsMotFilter::getResource() {
    return nullptr;
}

__attribute__((weak)) void uCnsMotFilter::adjust(uModel::Joint* pJnt, uModel* pModel) {
    DDON_STUB("uCnsMotFilter::adjust")
    /* stub */
}

void uCnsMotFilter::remove() {
    removeConstraint();
}

void uCnsMotFilter::update() {
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

__attribute__((weak)) void uCnsMotFilter::draw(cDraw* pDraw) {
}

void uCnsMotFilter::createProperty(MtPropertyList& s) {
    this->uConstraint::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "Joint", reinterpret_cast<MT_MFUNC>(&::uCnsMotFilter::getJoint), reinterpret_cast<MT_MFUNC>(&::uCnsMotFilter::setJoint), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mMulMode", &mMulMode, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mpMotFlt", reinterpret_cast<MtObject* *>(&mpMotFlt), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSleep", &mSleep, 0u, 0u);
}

MtUI* uCnsMotFilter::createUI(MtProperty& prop) {
    return this->uConstraint::createUI(prop);
}

void uCnsMotFilter::setJoint(u32 JntNo) {
    mJoint = JntNo;
    if (getModel() == nullptr) {
        return;
    }
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

static auto ddon_emit_0x01ad3ad0 __attribute__((used)) = &uCnsMotFilter::getJoint;

void uCnsMotFilter::set(uModel* pModel, u32 JntNo, cpMotionFilter* pMotFilter, u32 Pri) {
    setModel(pModel);
    setPri(Pri);
    mJoint = JntNo;
    if (getModel() != nullptr) {
        setConstraint(getModel(), static_cast<s32>(mJoint));
    }
    mpMotFlt = pMotFilter;
}

inline uCnsMotFilter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCnsMotFilter::MyDTI uCnsMotFilter::DTI("uCnsMotFilter", &::uConstraint::DTI, 176ul, 0u, 0u);

MtObject* uCnsMotFilter::MyDTI::newInstance() const {
    return new (16u) uCnsMotFilter;
}

