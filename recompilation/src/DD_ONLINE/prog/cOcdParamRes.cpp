// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cOcdParamRes.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cOcdImmuneParamRes::getDTI() const {
    return cOcdImmuneParamRes::DTI;
}

inline MtAllocator* cOcdImmuneParamRes::getAllocator() {
    return MtMemoryAllocator::getAllocator(cOcdImmuneParamRes::DTI);
}

inline void* cOcdImmuneParamRes::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cOcdImmuneParamRes::DTI)->memAlloc(sz, align, cOcdImmuneParamRes::DTI.getID());
}

void* cOcdImmuneParamRes::operator new[](size_t sz, u32 align) {
    return cOcdImmuneParamRes::getAllocator()->memAlloc(sz, align, cOcdImmuneParamRes::DTI.getID());
}

inline void cOcdImmuneParamRes::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cOcdImmuneParamRes::DTI)->memFree(p_addr);
}

void cOcdImmuneParamRes::operator delete[](void* p_addr) {
    cOcdImmuneParamRes::getAllocator()->memFree(p_addr);
}

cOcdImmuneParamRes::cOcdImmuneParamRes() {
    mOcdUID = 0;
    mImmuneRate = 1.1f;
    mImmuneNum = 5;
}

void cOcdImmuneParamRes::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "\347\225\260\345\270\270\345\220\215\347\247\260", &mOcdUID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\345\205\215\347\226\253\345\212\233\350\243\234\346\255\243\345\200\244", &mImmuneRate, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\350\243\234\346\255\243\345\233\236\346\225\260", &mImmuneNum, 0u, 0u);
}

inline cOcdImmuneParamRes::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cOcdImmuneParamRes::MyDTI cOcdImmuneParamRes::DTI("cOcdImmuneParamRes", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cOcdImmuneParamRes::MyDTI::newInstance() const {
    return new (16u) cOcdImmuneParamRes;
}

const MtDTI& cOcdStatusParamRes::getDTI() const {
    return cOcdStatusParamRes::DTI;
}

inline MtAllocator* cOcdStatusParamRes::getAllocator() {
    return MtMemoryAllocator::getAllocator(cOcdStatusParamRes::DTI);
}

inline void* cOcdStatusParamRes::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cOcdStatusParamRes::DTI)->memAlloc(sz, align, cOcdStatusParamRes::DTI.getID());
}

void* cOcdStatusParamRes::operator new[](size_t sz, u32 align) {
    return cOcdStatusParamRes::getAllocator()->memAlloc(sz, align, cOcdStatusParamRes::DTI.getID());
}

inline void cOcdStatusParamRes::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cOcdStatusParamRes::DTI)->memFree(p_addr);
}

void cOcdStatusParamRes::operator delete[](void* p_addr) {
    cOcdStatusParamRes::getAllocator()->memFree(p_addr);
}

cOcdStatusParamRes::cOcdStatusParamRes() {
    mOcdUID = 0;
    mIsEffective = true;
    mEndurance = 1000.0f;
    mEnduranceCheatCheck = 1000.0f;
    mIsTimeRecover = true;
    mActiveTime = 120.0f;
    mCureWaitTime = 5.0f;
    mActiveTimeCheatCheck = 120.0f;
    mCureValue = 0.5f;
    mFreeParam0 = 0.0f;
    mCureValueCheatCheck = 0.5f;
    mFreeParam0CheatCheck = 0.0f;
    mFreeParam1 = 0.0f;
    mFreeParam1CheatCheck = 0.0f;
}

void cOcdStatusParamRes::copyParam(const cOcdStatusParamRes& param) {
    mIsEffective = param.mIsEffective;
    mEndurance = param.getEndurancePrivate();
    mEnduranceCheatCheck = mEndurance;
    mIsTimeRecover = param.mIsTimeRecover;
    mActiveTime = param.getActiveTimePrivate();
    mActiveTimeCheatCheck = mActiveTime;
    mCureWaitTime = param.mCureWaitTime;
    mCureValue = param.getCureValuePrivate();
    mCureValueCheatCheck = mCureValue;
    mFreeParam0 = param.getFreeParam0Private();
    mFreeParam0CheatCheck = mFreeParam0;
    mFreeParam1 = param.getFreeParam1Private();
    mFreeParam1CheatCheck = mFreeParam1;
}

void cOcdStatusParamRes::copyEffectiveParam(const cOcdStatusParamRes& param) {
    mIsEffective = param.mIsEffective;
    mIsTimeRecover = param.mIsTimeRecover;
    if (param.getEndurancePrivate() > 1.1920929e-7f) {
        mEndurance = param.getEndurancePrivate();
        mEnduranceCheatCheck = mEndurance;
    }
    if (param.getActiveTimePrivate() > 1.1920929e-7f) {
        mActiveTime = param.getActiveTimePrivate();
        mActiveTimeCheatCheck = mActiveTime;
    }
    if (param.getCureWaitTime() > 1.1920929e-7f) {
        mCureWaitTime = param.getCureWaitTime();
    }
    if (param.getCureValuePrivate() > 1.1920929e-7f) {
        mCureValue = param.getCureValuePrivate();
        mCureValueCheatCheck = mCureValue;
    }
    if (param.getFreeParam0Private() > -999.0f) {
        if (999.0f > param.getFreeParam0Private()) {
            mFreeParam0 = param.getFreeParam0Private();
            mFreeParam0CheatCheck = mFreeParam0;
        }
    }
    if (param.getFreeParam1Private() > -999.0f) {
        if (999.0f > param.getFreeParam1Private()) {
            mFreeParam1 = param.getFreeParam1Private();
            mFreeParam1CheatCheck = mFreeParam1;
        }
    }
}

void cOcdStatusParamRes::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "\347\225\260\345\270\270\345\220\215\347\247\260", &mOcdUID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "\347\225\260\345\270\270\346\234\211\347\204\241", &mIsEffective, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "\350\200\220\346\200\247\345\200\244", reinterpret_cast<MT_MFUNC>(&::cOcdStatusParamRes::getEndurance), reinterpret_cast<MT_MFUNC>(&::cOcdStatusParamRes::setEndurance), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "\346\231\202\351\226\223\347\265\214\351\201\216\343\201\247\346\262\273\343\202\213", &mIsTimeRecover, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "\346\234\211\345\212\271\346\231\202\351\226\223", reinterpret_cast<MT_MFUNC>(&::cOcdStatusParamRes::getActiveTime), reinterpret_cast<MT_MFUNC>(&::cOcdStatusParamRes::setActiveTime), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "\345\233\236\345\276\251\345\276\205\346\251\237\346\231\202\351\226\223", &mCureWaitTime, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "\345\233\236\345\276\251\351\207\217", reinterpret_cast<MT_MFUNC>(&::cOcdStatusParamRes::getCureValue), reinterpret_cast<MT_MFUNC>(&::cOcdStatusParamRes::setCureValue), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "\346\261\216\347\224\250\343\203\221\343\203\251\343\203\241\343\203\274\343\202\2770", reinterpret_cast<MT_MFUNC>(&::cOcdStatusParamRes::getFreeParam0), reinterpret_cast<MT_MFUNC>(&::cOcdStatusParamRes::setFreeParam0), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "\346\261\216\347\224\250\343\203\221\343\203\251\343\203\241\343\203\274\343\202\2771", reinterpret_cast<MT_MFUNC>(&::cOcdStatusParamRes::getFreeParam1), reinterpret_cast<MT_MFUNC>(&::cOcdStatusParamRes::setFreeParam1), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

f32 cOcdStatusParamRes::getEndurance() const {
    return mEndurance;
}

f32 cOcdStatusParamRes::getActiveTime() const {
    return mActiveTime;
}

f32 cOcdStatusParamRes::getCureValue() const {
    return mCureValue;
}

f32 cOcdStatusParamRes::getFreeParam0() const {
    return mFreeParam0;
}

f32 cOcdStatusParamRes::getFreeParam1() const {
    return mFreeParam1;
}

void cOcdStatusParamRes::setEndurance(f32 endurance) {
    mEndurance = endurance;
    mEnduranceCheatCheck = endurance;
}

void cOcdStatusParamRes::setActiveTime(f32 ActiveTime) {
    mActiveTime = ActiveTime;
    mActiveTimeCheatCheck = ActiveTime;
}

void cOcdStatusParamRes::setCureValue(f32 CureValue) {
    mCureValue = CureValue;
    mCureValueCheatCheck = CureValue;
}

void cOcdStatusParamRes::setFreeParam0(f32 FreeParam0) {
    mFreeParam0 = FreeParam0;
    mFreeParam0CheatCheck = FreeParam0;
}

void cOcdStatusParamRes::setFreeParam1(f32 FreeParam1) {
    mFreeParam1 = FreeParam1;
    mFreeParam1CheatCheck = FreeParam1;
}

f32 cOcdStatusParamRes::getEnduranceCheatCheck() const {
    return mEnduranceCheatCheck;
}

f32 cOcdStatusParamRes::getActiveTimeCheatCheck() const {
    return mActiveTimeCheatCheck;
}

f32 cOcdStatusParamRes::getCureValueCheatCheck() const {
    return mCureValueCheatCheck;
}

f32 cOcdStatusParamRes::getFreeParam0CheatCheck() const {
    return mFreeParam0CheatCheck;
}

f32 cOcdStatusParamRes::getFreeParam1CheatCheck() const {
    return mFreeParam1CheatCheck;
}

inline cOcdStatusParamRes::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cOcdStatusParamRes::MyDTI cOcdStatusParamRes::DTI("cOcdStatusParamRes", &::MtObject::DTI, 64ul, 0u, 0u);

MtObject* cOcdStatusParamRes::MyDTI::newInstance() const {
    return new (16u) cOcdStatusParamRes;
}

