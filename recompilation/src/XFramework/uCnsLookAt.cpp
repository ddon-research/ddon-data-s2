// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uCnsLookAt.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cResource.h"
#include "cUnit.h"
#include "uConstraint.h"
#include "uModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void uCnsLookAt::usage() {
}

const MtDTI& uCnsLookAt::getDTI() const {
    return uCnsLookAt::DTI;
}

inline void uCnsLookAt::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(uCnsLookAt::DTI)->memFree(p_addr);
}

uCnsLookAt::uCnsLookAt() {
    DDON_STUB("uCnsLookAt::uCnsLookAt")
    /* stub */
}

uCnsLookAt::~uCnsLookAt() {
    DDON_STUB("uCnsLookAt::~uCnsLookAt")
    /* stub */
}

void uCnsLookAt::createProperty(MtPropertyList& s) {
    this->uConstraint::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mpCnsLookAtRes", "resource", reinterpret_cast<MT_MFUNC>(&::uCnsLookAt::getResource), reinterpret_cast<MT_MFUNC>(&::uCnsLookAt::setResource), 0u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "Joint", reinterpret_cast<MT_MFUNC>(&::uCnsLookAt::getJoint), reinterpret_cast<MT_MFUNC>(&::uCnsLookAt::setJointForProperty), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U8, "mDir", reinterpret_cast<MT_MFUNC>(&::uCnsLookAt::getDirection), reinterpret_cast<MT_MFUNC>(&::uCnsLookAt::setDirection), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U8, "mUp", reinterpret_cast<MT_MFUNC>(&::uCnsLookAt::getUpvector), reinterpret_cast<MT_MFUNC>(&::uCnsLookAt::setUpvector), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASSREF, "mpTargetModel", reinterpret_cast<MT_MFUNC>(&::uCnsLookAt::getTargetModel), reinterpret_cast<MT_MFUNC>(&::uCnsLookAt::setTargetModel), 144u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "mpTargetJoint", reinterpret_cast<MT_MFUNC>(&::uCnsLookAt::getTargetJoint), reinterpret_cast<MT_MFUNC>(&::uCnsLookAt::setTargetJoint), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mTargetPos", &mTargetPos, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_VECTOR3, "TargetWPos", reinterpret_cast<MT_MFUNC>(&::uCnsLookAt::getTargetWPos), reinterpret_cast<MT_MFUNC>(&::uCnsLookAt::setTargetWPos), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

MtUI* uCnsLookAt::createUI(MtProperty& prop) {
    return this->uConstraint::createUI(prop);
}

void uCnsLookAt::move() {
    if (mpTargetModel != nullptr) {
        if ((mpTargetModel->mBeFlag - 1u) > 1u) {
            mpTargetModel = nullptr;
        }
    }
    this->uConstraint::move();
}

__attribute__((weak)) void uCnsLookAt::draw(cDraw* pDraw) {
}

__attribute__((weak)) void uCnsLookAt::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    DDON_STUB("uCnsLookAt::applyWorldOffset")
    /* stub */
}

__attribute__((weak)) void uCnsLookAt::adjust(uModel::Joint* pJnt, uModel* pModel) {
    DDON_STUB("uCnsLookAt::adjust")
    /* stub */
}

__attribute__((weak)) void uCnsLookAt::setResource(cResource* pRes) {
    DDON_STUB("uCnsLookAt::setResource")
    /* stub */
}

__attribute__((weak)) cResource* uCnsLookAt::getResource() {
    DDON_STUB("uCnsLookAt::getResource")
    return nullptr;
}

void uCnsLookAt::remove() {
    removeConstraint();
}

void uCnsLookAt::update() {
    setConstraint(getModel(), static_cast<s32>(mJoint));
}

u32 uCnsLookAt::getDependentJointNum() {
    return mpTargetModel != nullptr;
}

uModel::Joint* uCnsLookAt::getDependentJoint(u32 Idx) {
    if (mpTargetModel != nullptr) {
        if ((mpTargetModel->mJointTable[mTargetJointNo] != 0xFF) && ((&mpTargetModel->mJoint[mpTargetModel->mJointTable[mTargetJointNo]]) != nullptr)) {
            return &mpTargetModel->mJoint[mpTargetModel->mJointTable[mTargetJointNo]];
        }
    }
    return nullptr;
}

void uCnsLookAt::evSetJoints(uModel::Joint* * pJnts, u32 Num) {
    if (Num == 0) {
        return;
    }
    unsigned int t0 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*pJnts) + 160);
    if (!uConstraint::checkJointNo(getModel(), static_cast<s32>(t0 >> 24))) {
        return;
    }
    mJoint = t0 >> 24;
    update();
}

void uCnsLookAt::set(uModel* pModel, rCnsLookAt* pRes, uModel* pTargetModel) {
    setModel(pModel);
    mpTargetModel = pTargetModel;
    setCnsLookAtRes(pRes);
}

__attribute__((weak)) void uCnsLookAt::setCnsLookAtRes(rCnsLookAt* pRes) {
    DDON_STUB("uCnsLookAt::setCnsLookAtRes")
    /* stub */
}

bool uCnsLookAt::setJoint(u32 JntNo) {
    if (uConstraint::checkJointNo(getModel(), static_cast<s32>(JntNo))) {
        mJoint = JntNo;
        update();
        return true;
    } else {
        return false;
    }
}

static auto ddon_emit_0x01b67620 __attribute__((used)) = &uCnsLookAt::getJoint;

__attribute__((weak)) MtVector3 uCnsLookAt::getTargetWPos() {
    DDON_STUB("uCnsLookAt::getTargetWPos")
    __builtin_unreachable();
}

__attribute__((weak)) void uCnsLookAt::setTargetWPos(const MtVector3& pos) {
    DDON_STUB("uCnsLookAt::setTargetWPos")
    /* stub */
}

void uCnsLookAt::setTargetModel(uModel* pModel) {
    mpTargetModel = pModel;
}

uModel* uCnsLookAt::getTargetModel() {
    return mpTargetModel;
}

void uCnsLookAt::setTargetJoint(u32 JntNo) {
    mTargetJointNo = JntNo;
}

static auto ddon_emit_0x01b676a0 __attribute__((used)) = &uCnsLookAt::getTargetJoint;

void uCnsLookAt::setDirection(u32 dir) {
    unsigned long t0 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 200);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 200) = static_cast<unsigned int>((t0 & 0xFFFFFF00ul) | static_cast<unsigned long>(static_cast<unsigned char>(dir)));
    switch (static_cast<unsigned char>(dir)) {
        case 0:
        {
            mType = static_cast<u32>(((t0 >> 32) & 3855ul) | 16ul);
            break;
        }
        case 1:
        {
            mType = static_cast<u32>(((t0 >> 32) & 3855ul) | 32ul);
            break;
        }
        case 2:
        {
            mType = static_cast<u32>(((t0 >> 32) & 3855ul) | 64ul);
            break;
        }
        case 3:
        {
            mType = static_cast<u32>(((t0 >> 32) & 3855ul) | 144ul);
            break;
        }
        case 4:
        {
            mType = static_cast<u32>(((t0 >> 32) & 3855ul) | 160ul);
            break;
        }
        case 5:
        {
            mType = static_cast<u32>(((t0 >> 32) & 3855ul) | 192ul);
            break;
        }
        default:
        {
            break;
        }
    }
}

static auto ddon_emit_0x01b67680 __attribute__((used)) = &uCnsLookAt::getDirection;

void uCnsLookAt::setUpvector(u32 up) {
    unsigned long t0 = *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(this) + 200);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 200) = static_cast<unsigned int>((t0 & 0xFFFF00FFul) | static_cast<unsigned long>(static_cast<unsigned short>(up * 256u)));
    switch (static_cast<unsigned char>(up)) {
        case 0:
        {
            mType = static_cast<u32>(((t0 >> 32) & 240ul) | 1ul);
            break;
        }
        case 1:
        {
            mType = static_cast<u32>(((t0 >> 32) & 240ul) | 258ul);
            break;
        }
        case 2:
        {
            mType = static_cast<u32>(((t0 >> 32) & 240ul) | 516ul);
            break;
        }
        case 3:
        {
            mType = static_cast<u32>(((t0 >> 32) & 240ul) | 9ul);
            break;
        }
        case 4:
        {
            mType = static_cast<u32>(((t0 >> 32) & 240ul) | 266ul);
            break;
        }
        case 5:
        {
            mType = static_cast<u32>(((t0 >> 32) & 240ul) | 524ul);
            break;
        }
        default:
        {
            break;
        }
    }
}

static auto ddon_emit_0x01b67690 __attribute__((used)) = &uCnsLookAt::getUpvector;

void uCnsLookAt::setJointForProperty(u32 JntNo) {
    if (!uConstraint::checkJointNo(getModel(), static_cast<s32>(JntNo))) {
        return;
    }
    mJoint = JntNo;
    update();
}

inline uCnsLookAt::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uCnsLookAt::MyDTI uCnsLookAt::DTI("uCnsLookAt", &::uConstraint::DTI, 208ul, 0u, 0u);

__attribute__((weak)) MtObject* uCnsLookAt::MyDTI::newInstance() const {
    DDON_STUB("uCnsLookAt::MyDTI::newInstance")
    return nullptr;
}

