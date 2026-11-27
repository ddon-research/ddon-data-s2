// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uCnsLookAt.h"
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

void uCnsLookAt::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    if (mpTargetModel != nullptr) {
        return;
    }
    mTargetPos.x = offset.x + mTargetPos.x;
    mTargetPos.y = offset.y + mTargetPos.y;
    mTargetPos.z = offset.z + mTargetPos.z;
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

void uCnsLookAt::setTargetWPos(const MtVector3& pos) {
    const f32 t0 = pos.x;
    const f32 t1 = pos.y;
    const f32 t2 = pos.z;
    uModel* t3 = mpTargetModel;
    if (t3 != nullptr) {
        u32 t4 = mTargetJointNo;
        const u8* t5 = t3->mJointTable;
        const u8 t6 = t5[t4];
        if (t6 != 0xFF) {
            uModel::Joint* t7 = t3->mJoint;
            if ((&t7[t6]) != nullptr) {
                f32 t8 = t7[t6].mWmat.m[0].x;
                f32 t9 = t7[t6].mWmat.m[0].y;
                f32 t10 = t7[t6].mWmat.m[0].z;
                f32 t11 = t7[t6].mWmat.m[1].x;
                f32 t12 = t7[t6].mWmat.m[1].y;
                f32 t13 = t7[t6].mWmat.m[1].z;
                f32 t14 = t7[t6].mWmat.m[2].x;
                f32 t15 = t7[t6].mWmat.m[3].x;
                f32 t16 = t7[t6].mWmat.m[3].y;
                f32 t17 = t7[t6].mWmat.m[3].z;
                f32 t18 = t7[t6].mWmat.m[2].y;
                f32 t19 = t7[t6].mWmat.m[2].z;
                float t33 = -0.0f;
                float t34 = 1.0f;
                mTargetPos.x = (-(((t8 * t15) + (t9 * t16)) + (t10 * t17))) + (((t0 * t8) + (t1 * t9)) + (t2 * t10));
                mTargetPos.y = (-(((t11 * t15) + (t12 * t16)) + (t13 * t17))) + (((t0 * t11) + (t1 * t12)) + (t2 * t13));
                mTargetPos.z = (-(((t14 * t15) + (t16 * t18)) + (t17 * t19))) + (((t0 * t14) + (t1 * t18)) + (t2 * t19));
                mTargetPos.pad_ = 0.0f;
            } else {
                const MtMatrix& t20 = t3->getWorldMatrix(-1);
                const f32 t21 = t20.m[0].x;
                const f32 t22 = t20.m[0].y;
                const f32 t23 = t20.m[0].z;
                const f32 t24 = t20.m[1].x;
                const f32 t25 = t20.m[1].y;
                const f32 t26 = t20.m[1].z;
                const f32 t27 = t20.m[2].x;
                const f32 t28 = t20.m[3].x;
                const f32 t29 = t20.m[3].y;
                const f32 t30 = t20.m[3].z;
                const f32 t31 = t20.m[2].y;
                const f32 t32 = t20.m[2].z;
                float t33 = -0.0f;
                float t34 = 1.0f;
                mTargetPos.x = (-(((t21 * t28) + (t22 * t29)) + (t23 * t30))) + (((t0 * t21) + (t1 * t22)) + (t2 * t23));
                mTargetPos.y = (-(((t24 * t28) + (t25 * t29)) + (t26 * t30))) + (((t0 * t24) + (t1 * t25)) + (t2 * t26));
                mTargetPos.z = (-(((t27 * t28) + (t29 * t31)) + (t30 * t32))) + (((t0 * t27) + (t1 * t31)) + (t2 * t32));
                mTargetPos.pad_ = 0.0f;
            }
        } else {
            const MtMatrix& t20 = t3->getWorldMatrix(-1);
            const f32 t21 = t20.m[0].x;
            const f32 t22 = t20.m[0].y;
            const f32 t23 = t20.m[0].z;
            const f32 t24 = t20.m[1].x;
            const f32 t25 = t20.m[1].y;
            const f32 t26 = t20.m[1].z;
            const f32 t27 = t20.m[2].x;
            const f32 t28 = t20.m[3].x;
            const f32 t29 = t20.m[3].y;
            const f32 t30 = t20.m[3].z;
            const f32 t31 = t20.m[2].y;
            const f32 t32 = t20.m[2].z;
            float t33 = -0.0f;
            float t34 = 1.0f;
            mTargetPos.x = (-(((t21 * t28) + (t22 * t29)) + (t23 * t30))) + (((t0 * t21) + (t1 * t22)) + (t2 * t23));
            mTargetPos.y = (-(((t24 * t28) + (t25 * t29)) + (t26 * t30))) + (((t0 * t24) + (t1 * t25)) + (t2 * t26));
            mTargetPos.z = (-(((t27 * t28) + (t29 * t31)) + (t30 * t32))) + (((t0 * t27) + (t1 * t31)) + (t2 * t32));
            mTargetPos.pad_ = 0.0f;
        }
    } else {
        mTargetPos.x = t0;
        mTargetPos.y = t1;
        mTargetPos.z = t2;
        mTargetPos.pad_ = 0.0f;
    }
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

