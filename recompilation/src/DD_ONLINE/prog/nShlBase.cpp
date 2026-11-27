// Reconstructed from the game's DWARF debug information.
#include <new>
#include <ymath.h>
#include "nShlBase.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../generated/shared/nDDOMath.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

nShlBase::cShlFuwaMove::~cShlFuwaMove() {
}

void nShlBase::cShlFuwaMove::update(f32 deltaTime) {
    f32 t0 = mInitPeriod.x;
    f32 t1 = mInitScale.x;
    f32 t2 = mInitRandom.x;
    f32 t3 = mTimer.x;
    mTimer.x = t3 + deltaTime;
    f32 t4 = mPeriod.x;
    if (mTimer.x >= t4) {
        mTimer.x = (t3 + deltaTime) - t4;
        mPeriod.x = t0 * ::nDDOMath::random(1.0f - t2, t2 + 1.0f);
        mScale.x = t1 * ::nDDOMath::random(1.0f - t2, t2 + 1.0f);
        float t5 = ::_FSin(6.2831855f * (((t3 + deltaTime) - t4) / t4), 0u, 0);
        f32 t6 = mScale.x;
        f32 t7 = mInitPeriod.y;
        f32 t8 = mInitScale.y;
        f32 t9 = mInitRandom.y;
        f32 t10 = mTimer.y;
        mTimer.y = t10 + deltaTime;
        f32 t11 = mPeriod.y;
        if (mTimer.y >= t11) {
            mTimer.y = (t10 + deltaTime) - t11;
            mPeriod.y = t7 * ::nDDOMath::random(1.0f - t9, t9 + 1.0f);
            mScale.y = t8 * ::nDDOMath::random(1.0f - t9, t9 + 1.0f);
            float t12 = ::_FSin(6.2831855f * (((t10 + deltaTime) - t11) / t11), 0u, 0);
            f32 t13 = mScale.y;
            f32 t14 = mInitPeriod.z;
            f32 t15 = mInitScale.z;
            f32 t16 = mInitRandom.z;
            f32 t17 = mTimer.z;
            mTimer.z = t17 + deltaTime;
            f32 t18 = mPeriod.z;
            if (mTimer.z >= t18) {
                mTimer.z = (t17 + deltaTime) - t18;
                mPeriod.z = t14 * ::nDDOMath::random(1.0f - t16, t16 + 1.0f);
                mScale.z = t15 * ::nDDOMath::random(1.0f - t16, t16 + 1.0f);
                float t19 = ::_FSin(6.2831855f * (((t17 + deltaTime) - t18) / t18), 0u, 0);
                mDisplace.x = (t6 * t5) - mPos.x;
                mDisplace.y = (t13 * t12) - mPos.y;
                mDisplace.z = (mScale.z * t19) - mPos.z;
                mDisplace.pad_ = 0.0f;
                mPos.x = t6 * t5;
                mPos.y = t13 * t12;
                mPos.z = mScale.z * t19;
            } else {
                float t19 = ::_FSin(6.2831855f * ((t17 + deltaTime) / t18), 0u, 0);
                mDisplace.x = (t6 * t5) - mPos.x;
                mDisplace.y = (t13 * t12) - mPos.y;
                mDisplace.z = (mScale.z * t19) - mPos.z;
                mDisplace.pad_ = 0.0f;
                mPos.x = t6 * t5;
                mPos.y = t13 * t12;
                mPos.z = mScale.z * t19;
            }
        } else {
            float t12 = ::_FSin(6.2831855f * ((t10 + deltaTime) / t11), 0u, 0);
            f32 t13 = mScale.y;
            f32 t14 = mInitPeriod.z;
            f32 t15 = mInitScale.z;
            f32 t16 = mInitRandom.z;
            f32 t17 = mTimer.z;
            mTimer.z = t17 + deltaTime;
            f32 t18 = mPeriod.z;
            if (mTimer.z >= t18) {
                mTimer.z = (t17 + deltaTime) - t18;
                mPeriod.z = t14 * ::nDDOMath::random(1.0f - t16, t16 + 1.0f);
                mScale.z = t15 * ::nDDOMath::random(1.0f - t16, t16 + 1.0f);
                float t19 = ::_FSin(6.2831855f * (((t17 + deltaTime) - t18) / t18), 0u, 0);
                mDisplace.x = (t6 * t5) - mPos.x;
                mDisplace.y = (t13 * t12) - mPos.y;
                mDisplace.z = (mScale.z * t19) - mPos.z;
                mDisplace.pad_ = 0.0f;
                mPos.x = t6 * t5;
                mPos.y = t13 * t12;
                mPos.z = mScale.z * t19;
            } else {
                float t19 = ::_FSin(6.2831855f * ((t17 + deltaTime) / t18), 0u, 0);
                mDisplace.x = (t6 * t5) - mPos.x;
                mDisplace.y = (t13 * t12) - mPos.y;
                mDisplace.z = (mScale.z * t19) - mPos.z;
                mDisplace.pad_ = 0.0f;
                mPos.x = t6 * t5;
                mPos.y = t13 * t12;
                mPos.z = mScale.z * t19;
            }
        }
    } else {
        float t5 = ::_FSin(6.2831855f * ((t3 + deltaTime) / t4), 0u, 0);
        f32 t6 = mScale.x;
        f32 t7 = mInitPeriod.y;
        f32 t8 = mInitScale.y;
        f32 t9 = mInitRandom.y;
        f32 t10 = mTimer.y;
        mTimer.y = t10 + deltaTime;
        f32 t11 = mPeriod.y;
        if (mTimer.y >= t11) {
            mTimer.y = (t10 + deltaTime) - t11;
            mPeriod.y = t7 * ::nDDOMath::random(1.0f - t9, t9 + 1.0f);
            mScale.y = t8 * ::nDDOMath::random(1.0f - t9, t9 + 1.0f);
            float t12 = ::_FSin(6.2831855f * (((t10 + deltaTime) - t11) / t11), 0u, 0);
            f32 t13 = mScale.y;
            f32 t14 = mInitPeriod.z;
            f32 t15 = mInitScale.z;
            f32 t16 = mInitRandom.z;
            f32 t17 = mTimer.z;
            mTimer.z = t17 + deltaTime;
            f32 t18 = mPeriod.z;
            if (mTimer.z >= t18) {
                mTimer.z = (t17 + deltaTime) - t18;
                mPeriod.z = t14 * ::nDDOMath::random(1.0f - t16, t16 + 1.0f);
                mScale.z = t15 * ::nDDOMath::random(1.0f - t16, t16 + 1.0f);
                float t19 = ::_FSin(6.2831855f * (((t17 + deltaTime) - t18) / t18), 0u, 0);
                mDisplace.x = (t6 * t5) - mPos.x;
                mDisplace.y = (t13 * t12) - mPos.y;
                mDisplace.z = (mScale.z * t19) - mPos.z;
                mDisplace.pad_ = 0.0f;
                mPos.x = t6 * t5;
                mPos.y = t13 * t12;
                mPos.z = mScale.z * t19;
            } else {
                float t19 = ::_FSin(6.2831855f * ((t17 + deltaTime) / t18), 0u, 0);
                mDisplace.x = (t6 * t5) - mPos.x;
                mDisplace.y = (t13 * t12) - mPos.y;
                mDisplace.z = (mScale.z * t19) - mPos.z;
                mDisplace.pad_ = 0.0f;
                mPos.x = t6 * t5;
                mPos.y = t13 * t12;
                mPos.z = mScale.z * t19;
            }
        } else {
            float t12 = ::_FSin(6.2831855f * ((t10 + deltaTime) / t11), 0u, 0);
            f32 t13 = mScale.y;
            f32 t14 = mInitPeriod.z;
            f32 t15 = mInitScale.z;
            f32 t16 = mInitRandom.z;
            f32 t17 = mTimer.z;
            mTimer.z = t17 + deltaTime;
            f32 t18 = mPeriod.z;
            if (mTimer.z >= t18) {
                mTimer.z = (t17 + deltaTime) - t18;
                mPeriod.z = t14 * ::nDDOMath::random(1.0f - t16, t16 + 1.0f);
                mScale.z = t15 * ::nDDOMath::random(1.0f - t16, t16 + 1.0f);
                float t19 = ::_FSin(6.2831855f * (((t17 + deltaTime) - t18) / t18), 0u, 0);
                mDisplace.x = (t6 * t5) - mPos.x;
                mDisplace.y = (t13 * t12) - mPos.y;
                mDisplace.z = (mScale.z * t19) - mPos.z;
                mDisplace.pad_ = 0.0f;
                mPos.x = t6 * t5;
                mPos.y = t13 * t12;
                mPos.z = mScale.z * t19;
            } else {
                float t19 = ::_FSin(6.2831855f * ((t17 + deltaTime) / t18), 0u, 0);
                mDisplace.x = (t6 * t5) - mPos.x;
                mDisplace.y = (t13 * t12) - mPos.y;
                mDisplace.z = (mScale.z * t19) - mPos.z;
                mDisplace.pad_ = 0.0f;
                mPos.x = t6 * t5;
                mPos.y = t13 * t12;
                mPos.z = mScale.z * t19;
            }
        }
    }
    mPos.pad_ = 0.0f;
}

const MtDTI& nShlBase::cShlStickContextInfo::getDTI() const {
    return nShlBase::cShlStickContextInfo::DTI;
}

void* nShlBase::cShlStickContextInfo::operator new(size_t sz, u32 align) {
    return ::nShlBase::cShlStickContextInfo::getAllocator()->memAlloc(sz, align, ::nShlBase::cShlStickContextInfo::DTI.getID());
}

__attribute__((weak)) void nShlBase::cShlStickContextInfo::operator delete(void* p_addr) {
    ::nShlBase::cShlStickContextInfo::getAllocator()->memFree(p_addr);
}

inline nShlBase::cShlStickContextInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nShlBase::cShlStickContextInfo::MyDTI nShlBase::cShlStickContextInfo::DTI("nShlBase::cShlStickContextInfo", &::MtObject::DTI, 64ul, 0u, 0u);

MtObject* nShlBase::cShlStickContextInfo::MyDTI::newInstance() const {
    return new (16u) ::nShlBase::cShlStickContextInfo;
}

