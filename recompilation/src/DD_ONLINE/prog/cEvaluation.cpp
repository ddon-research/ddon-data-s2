// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include "cEvaluation.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtSynchronize.h"
#include "cCharParamEnemy.h"
#include "cContextInterface.h"
#include "cContextPlayerInfo.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "cpStateManager.h"
#include "nHumanMsg.h"
#include "rCharParamEnemy.h"
#include "rEvaluationTable.h"
#include "../../XFramework/sMain.h"
#include "uCharacter.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uEnemy.h"
#include "uHuman.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cEvaluationName::cEvaluation::getDTI() const {
    return cEvaluationName::cEvaluation::DTI;
}

inline void cEvaluationName::cEvaluation::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cEvaluationName::cEvaluation::DTI)->memFree(p_addr);
}

cEvaluationName::cEvaluation::cEvaluation() {
    DDON_STUB("cEvaluationName::cEvaluation::cEvaluation")
    /* stub */
}

cEvaluationName::cEvaluation::~cEvaluation() {
    DDON_STUB("cEvaluationName::cEvaluation::~cEvaluation")
    /* stub */
}

__attribute__((weak)) void cEvaluationName::cEvaluation::createProperty(MtPropertyList& s) {
}

MtUI* cEvaluationName::cEvaluation::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

__attribute__((weak)) uDDOModel* cEvaluationName::cEvaluation::getEvaHigh(u32 excludeFlag) {
    DDON_STUB("cEvaluationName::cEvaluation::getEvaHigh")
    return nullptr;
}

__attribute__((weak)) f32 cEvaluationName::cEvaluation::getUnitEvaPoint(uDDOModel* pMod, u32 categoryNo) {
    DDON_STUB("cEvaluationName::cEvaluation::getUnitEvaPoint")
    return {};
}

__attribute__((weak)) void cEvaluationName::cEvaluation::deleteCategory(uDDOModel* pObjModel, u32 category) {
    DDON_STUB("cEvaluationName::cEvaluation::deleteCategory")
    /* stub */
}

void cEvaluationName::cEvaluation::deleteCategory(u32 category) {
    if (category > 17u) {
        return;
    } else {
        if (::scePthreadMutexLock(&mCS.mCSection) == 0) {
            bool* v0_1 = &mEvaList[0].mEvaPointList[0].mEnable;
            unsigned int i0_2 = 0;
            cEvaluationName::cEvaluationPoint* p1_0;
            unsigned int i1_1;
            bool* v4_0;
            unsigned int i4_2;
            for (;;) {
                p1_0 = &mEvaList[i0_2].mEvaPointList[0];
                i1_1 = 0;
                for (;;) {
                    if (p1_0->mEnable) {
                        if (p1_0->mCategory == category) {
                            p1_0->mCategory = 0;
                            p1_0->mAddValue = 0.0f;
                            p1_0->mDecValue = 0.0f;
                            p1_0->mEnable = false;
                        }
                    }
                    if (i1_1 != 31) {
                        p1_0 += 1;
                        i1_1 = i1_1 + 1u;
                    } else {
                        break;
                    }
                }
                v4_0 = v0_1;
                i4_2 = 0;
                for (;;) {
                    if (*v4_0) {
                        break;
                    } else {
                        if ((i4_2 + 1u) <= 31u) {
                            v4_0 += 24;
                            i4_2 += 1u;
                        } else {
                            mEvaList[i0_2].mNeverAddValue = 0.0f;
                            break;
                        }
                    }
                }
                if ((i0_2 + 1u) != 16) {
                    v0_1 += 808;
                    i0_2 = i0_2 + 1u;
                } else {
                    break;
                }
            }
            if (::scePthreadMutexUnlock(&mCS.mCSection) == 0) {
                return;
            }
        }
    }
    ::abort();
}

void cEvaluationName::cEvaluation::deleteCategoryAll(uDDOModel* pObjModel) {
    deleteCategory(pObjModel, 0u);
    deleteCategory(pObjModel, 1u);
    deleteCategory(pObjModel, 2u);
    deleteCategory(pObjModel, 3u);
    deleteCategory(pObjModel, 4u);
    deleteCategory(pObjModel, 5u);
    deleteCategory(pObjModel, 6u);
    deleteCategory(pObjModel, 7u);
    deleteCategory(pObjModel, 8u);
    deleteCategory(pObjModel, 9u);
    deleteCategory(pObjModel, 10u);
    deleteCategory(pObjModel, 11u);
    deleteCategory(pObjModel, 12u);
    deleteCategory(pObjModel, 13u);
    deleteCategory(pObjModel, 14u);
    deleteCategory(pObjModel, 15u);
    deleteCategory(pObjModel, 16u);
    deleteCategory(pObjModel, 17u);
}

__attribute__((weak)) bool cEvaluationName::cEvaluation::addEvaluation(uDDOModel* pObjModel, u32 category, f32 addValue, f32 decValue, bool scription, bool isPlHosei, f32 neverAdd, bool ignoreAbility) {
    DDON_STUB("cEvaluationName::cEvaluation::addEvaluation")
    return {};
}

__attribute__((weak)) bool cEvaluationName::cEvaluation::addEvaluationLimitHeight(uDDOModel* pObjModel, u32 category, f32 addValue, f32 decValue, bool scription, bool isPlHosei, f32 neverAdd, bool ignoreAbility, f32 height) {
    DDON_STUB("cEvaluationName::cEvaluation::addEvaluationLimitHeight")
    return {};
}

void cEvaluationName::cEvaluation::updatePtr() {
    if (mpMyObj != nullptr) {
        if (!mpMyObj->isEnable()) {
            mpMyObj = nullptr;
        }
    }
    u32 i = 0;
    unsigned int i1_0;
    cEvaluationName::cEvaluationPoint* p1_1;
    for (;;) {
        if (mEvaList[i].mpObject != nullptr) {
            if (mEvaList[i].mpObject->isEnable()) {
                goto region_1dfa41;
            } else {
                mEvaList[i].mpObject = nullptr;
                mEvaList[i].mEnable = true;
                mEvaList[i].mpObject = nullptr;
                mEvaList[i].mNeverAddValue = 0.0f;
                mEvaList[i].mIsSessionLost = true;
                mEvaList[i].mSessionStateUpdateTimer = 0.0f;
                i1_0 = 0;
                p1_1 = &mEvaList[i].mEvaPointList[0];
            }
        } else {
            mEvaList[i].mEnable = true;
            mEvaList[i].mpObject = nullptr;
            mEvaList[i].mNeverAddValue = 0.0f;
            mEvaList[i].mIsSessionLost = true;
            mEvaList[i].mSessionStateUpdateTimer = 0.0f;
            i1_0 = 0;
            p1_1 = &mEvaList[i].mEvaPointList[0];
        }
        for (;;) {
            p1_1->mCategory = 0;
            p1_1->mAddValue = 0.0f;
            p1_1->mDecValue = 0.0f;
            p1_1->mEnable = false;
            if (i1_0 != 31) {
                i1_0 = i1_0 + 1u;
                p1_1 += 1;
            } else {
                break;
            }
        }
        region_1dfa41:;
        if ((i + 1u) != 16) {
            i = i + 1u;
        } else {
            break;
        }
    }
    if (mpEvaTopObj != nullptr) {
        if (!mpEvaTopObj->isEnable()) {
            mpEvaTopObj = nullptr;
        }
    }
}

__attribute__((weak)) void cEvaluationName::cEvaluation::calcAllEvaValue() {
    DDON_STUB("cEvaluationName::cEvaluation::calcAllEvaValue")
    /* stub */
}

void cEvaluationName::cEvaluation::perNeverEvaValue(MtObject* pSrcObject, f32 perData) {
    if (::scePthreadMutexLock(&mCS.mCSection) == 0) {
        for (u32 i = 0;;) {
            if (pSrcObject == mEvaList[i].mpObject) {
                mEvaList[i].mNeverAddValue = mEvaList[i].mNeverAddValue * perData;
                if (0.0f >= mEvaList[i].mNeverAddValue) {
                    mEvaList[i].mNeverAddValue = 0.0f;
                }
            }
            if (i != 15) {
                i = i + 1u;
            } else {
                break;
            }
        }
        if (::scePthreadMutexUnlock(&mCS.mCSection) == 0) {
            return;
        }
    }
    ::abort();
}

__attribute__((weak)) void cEvaluationName::cEvaluation::setResource(rEvaluationTable* pRes) {
    DDON_STUB("cEvaluationName::cEvaluation::setResource")
    /* stub */
}

cEvaluationName::cEvaluation::EVALUATION_RESULT cEvaluationName::cEvaluation::getCategoryData(u32 categorys) {
    cEvaluationName::cEvaluation::EVALUATION_RESULT resultdata;
    resultdata.mEvalutionCategoryEizokuHosei = 0.0f;
    resultdata.mEvalutionCategoryDecPer = 0.0f;
    resultdata.mEvalutionCategoryHosei = 0.0f;
    resultdata.mEvalutionCategory = 0;
    resultdata.mEvalutionCategoryMax = 0;
    if (mpEvaluationTableRes != nullptr) {
        if (mpEvaluationTableRes->getDataNum() != 0) {
            for (unsigned int i0_3 = 0;;) {
                cEvaluationTable* t0 = mpEvaluationTableRes->getData(i0_3);
                if (t0 != nullptr) {
                    if (t0->mEvalutionCategory == categorys) {
                        resultdata.mEvalutionCategory = categorys;
                        resultdata.mEvalutionCategoryMax = t0->mEvalutionCategoryMax;
                        resultdata.mEvalutionCategoryDecPer = t0->mEvalutionCategoryDecPer;
                        resultdata.mEvalutionCategoryHosei = t0->mEvalutionCategoryHosei;
                        resultdata.mEvalutionCategoryEizokuHosei = t0->mEvalutionCategoryEizokuHosei;
                        return resultdata;
                    }
                }
                if ((i0_3 + 1u) < mpEvaluationTableRes->getDataNum()) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
    return resultdata;
}

__attribute__((weak)) f32 cEvaluationName::cEvaluation::getCategoryMax(rEvaluationTable* pRes, u32 categorys) {
    DDON_STUB("cEvaluationName::cEvaluation::getCategoryMax")
    return {};
}

inline cEvaluationName::cEvaluation::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEvaluationName::cEvaluation::MyDTI cEvaluationName::cEvaluation::DTI("cEvaluation", &::MtObject::DTI, 12976ul, 0u, 0u);

__attribute__((weak)) MtObject* cEvaluationName::cEvaluation::MyDTI::newInstance() const {
    DDON_STUB("cEvaluationName::cEvaluation::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cEvaluationName::cEvaluationData::getDTI() const {
    return cEvaluationName::cEvaluationData::DTI;
}

inline void cEvaluationName::cEvaluationData::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cEvaluationName::cEvaluationData::DTI)->memFree(p_addr);
}

cEvaluationName::cEvaluationData::~cEvaluationData() {
}

__attribute__((weak)) void cEvaluationName::cEvaluationData::createProperty(MtPropertyList& s) {
}

MtUI* cEvaluationName::cEvaluationData::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

inline cEvaluationName::cEvaluationData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEvaluationName::cEvaluationData::MyDTI cEvaluationName::cEvaluationData::DTI("cEvaluationData", &::MtObject::DTI, 808ul, 0u, 0u);

__attribute__((weak)) MtObject* cEvaluationName::cEvaluationData::MyDTI::newInstance() const {
    DDON_STUB("cEvaluationName::cEvaluationData::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cEvaluationName::cEvaluationPoint::getDTI() const {
    return cEvaluationName::cEvaluationPoint::DTI;
}

inline void* cEvaluationName::cEvaluationPoint::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::cEvaluationName::cEvaluationPoint::DTI)->memAlloc(sz, align, ::cEvaluationName::cEvaluationPoint::DTI.getID());
}

inline void cEvaluationName::cEvaluationPoint::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::cEvaluationName::cEvaluationPoint::DTI)->memFree(p_addr);
}

__attribute__((weak)) void cEvaluationName::cEvaluationPoint::createProperty(MtPropertyList& s) {
}

MtUI* cEvaluationName::cEvaluationPoint::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

inline cEvaluationName::cEvaluationPoint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEvaluationName::cEvaluationPoint::MyDTI cEvaluationName::cEvaluationPoint::DTI("cEvaluationPoint", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cEvaluationName::cEvaluationPoint::MyDTI::newInstance() const {
    return new (16u) ::cEvaluationName::cEvaluationPoint;
}

