// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uCnsTurnUpper.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../generated/shared/nDDOMath.h"
#include "../../XFramework/uConstraint.h"
#include "../../XFramework/uCoord.h"
#include "../../XFramework/uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uCnsTurnUpper::getDTI() const {
    return uCnsTurnUpper::DTI;
}

inline void* uCnsTurnUpper::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(uCnsTurnUpper::DTI)->memAlloc(sz, align, uCnsTurnUpper::DTI.getID());
}

inline void uCnsTurnUpper::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uCnsTurnUpper::DTI)->memFree(p_addr);
}

uCnsTurnUpper::uCnsTurnUpper() {
    mJoint = 0;
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 244) = 0;
    mScl.x = 1.0f;
    mScl.y = 1.0f;
    mScl.z = 1.0f;
    mScl.pad_ = 0.0f;
    mRot = MtVector3::Zero;
    mTrans = MtVector3::Zero;
    mDir = MtVector3::AxisZ;
    mTurnSpeed = -1.0f;
    mTargetRot = MtVector3::Zero;
}

uCnsTurnUpper::~uCnsTurnUpper() {
    removeConstraint();
}

cResource* uCnsTurnUpper::getResource() {
    return nullptr;
}

__attribute__((weak)) void uCnsTurnUpper::adjust(uModel::Joint* pJnt, uModel* pModel) {
    DDON_STUB("uCnsTurnUpper::adjust")
    /* stub */
}

void uCnsTurnUpper::remove() {
    removeConstraint();
}

void uCnsTurnUpper::update() {
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

void uCnsTurnUpper::evSetJoints(uModel::Joint* * pJnts, u32 Num) {
    if (Num == 0) {
        return;
    }
    mJoint = (*pJnts)->mNo;
    if (getModel() == nullptr) {
        return;
    }
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

void uCnsTurnUpper::createProperty(MtPropertyList& s) {
    this->uConstraint::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mpCnsTurnUpperRes", "resource", reinterpret_cast<MT_MFUNC>(&::uCnsTurnUpper::getResource), reinterpret_cast<MT_MFUNC>(&::uConstraint::setResource), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mScl", &mScl, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOrder", &(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 244)), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRot", &mRot, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTargetRot", &mTargetRot, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTrans", &mTrans, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTurnSpeed", &mTurnSpeed, 0u, 0u);
}

MtUI* uCnsTurnUpper::createUI(MtProperty& prop) {
    return this->uConstraint::createUI(prop);
}

__attribute__((weak)) void uCnsTurnUpper::draw(cDraw* pDraw) {
}

void uCnsTurnUpper::set(uModel* pModel, u32 JntNo, u32 Pri) {
    setModel(pModel);
    setPri(Pri);
    mJoint = JntNo;
    if (getModel() == nullptr) {
        return;
    }
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

inline uCnsTurnUpper::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCnsTurnUpper::MyDTI uCnsTurnUpper::DTI("uCnsTurnUpper", &::uConstraint::DTI, 256ul, 0u, 0u);

MtObject* uCnsTurnUpper::MyDTI::newInstance() const {
    return new (16u) uCnsTurnUpper;
}

