// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cpShlSelectorJob10.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cpComponent.h"
#include "cpShlBase.h"
#include "cpShlSelector.h"
#include "cpjob10.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "uShlBase.h"
#include "uShlComponentCtrl.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamCompSelectorJob10Cs08::getDTI() const {
    return cShlParamCompSelectorJob10Cs08::DTI;
}

const MtDTI& cShlParamCompSelectorJob10Cs08::getComponentDTI() const {
    return cpShlSelectorJob10Cs08::DTI;
}

__attribute__((noinline)) cShlParamCompSelectorJob10Cs08::~cShlParamCompSelectorJob10Cs08() {
    for (u32 i = 0; i < mShlList.mLength; i++) {
        delete mShlList.mpArray[i];
    }
    if (mShlList.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mShlList.mpArray));
    }
    mShlList.mpArray = nullptr;
    mShlList.mBufsiz = 0;
    mShlList.mLength = 0;
}

__attribute__((weak)) void cShlParamCompSelectorJob10Cs08::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mShlComponent", static_cast<MtObject*>(&mShlComponent), 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "mShlList", static_cast<MtObject*>(&mShlList), 0, 0);
    s << MtProperty(static_cast<MtObject*>(this), "mIsReqSe", &mIsReqSe, 0, 0);
}

__attribute__((weak)) void cShlParamCompSelectorJob10Cs08::copy(const cShlParamComponent* pParamBase) {
    DDON_STUB("cShlParamCompSelectorJob10Cs08::copy")
    /* stub */
}

inline cShlParamCompSelectorJob10Cs08::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamCompSelectorJob10Cs08::MyDTI cShlParamCompSelectorJob10Cs08::DTI("cShlParamCompSelectorJob10Cs08", &::cShlParamCompSelector::DTI, 80ul, 0u, 0u);

__attribute__((weak)) MtObject* cShlParamCompSelectorJob10Cs08::MyDTI::newInstance() const {
    return new (MtMemoryAllocator::getAllocator(cShlParamCompSelectorJob10Cs08::DTI)->memAlloc(sizeof(cShlParamCompSelectorJob10Cs08), 16u, cShlParamCompSelectorJob10Cs08::DTI.getID())) cShlParamCompSelectorJob10Cs08;
}

const MtDTI& cpShlSelectorJob10Cs08::getDTI() const {
    return cpShlSelectorJob10Cs08::DTI;
}

__attribute__((weak)) void cpShlSelectorJob10Cs08::initSub() {
    DDON_STUB("cpShlSelectorJob10Cs08::initSub")
    /* stub */
}

__attribute__((weak)) void cpShlSelectorJob10Cs08::kill() {
    DDON_STUB("cpShlSelectorJob10Cs08::kill")
    /* stub */
}

void cpShlSelectorJob10Cs08::callbackReplaceHitInfo_Atk(cHitInfo* pHitInfo) {
    MtObject* v0_3 = mpOwner;
    const MtDTI& t0 = v0_3->getDTI();
    MT_CTSTR v0_1 = uShlComponentCtrl::DTI.mName;
    for (const MtDTI* v0_0 = &t0;;) {
        if (v0_1 == v0_0->mName) {
            if (v0_3 != nullptr) {
                uShlComponentCtrl* pShl = static_cast<uShlComponentCtrl*>(v0_3);
                if (static_cast<unsigned int>(static_cast<uShlBase*>(v0_3)->getShlId() - 79) <= 1) {
                    if (static_cast<uShlBase*>(v0_3)->getOwner() != nullptr) {
                        if ((static_cast<uShlBase*>(v0_3)->getOwner()->mUnitId & 16u) != 0) {
                            if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(static_cast<uShlBase*>(v0_3)->getOwner()) + 13376)) != 0) {
                                if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(static_cast<uShlBase*>(v0_3)->getOwner()) + 13376)) + 40)) == 10) {
                                    if (!mIsChargeMax) {
                                        static_cast<uShlBase*>(v0_3)->getOwner()->attackParamReplace(pHitInfo, 1);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            return;
        } else {
            if (v0_0->mpParent != nullptr) {
                v0_0 = v0_0->mpParent;
            } else {
                break;
            }
        }
    }
}

u32 cpShlSelectorJob10Cs08::getSelectedIndex() const {
    MtObject* v0_3 = mpOwner;
    const MtDTI& t0 = v0_3->getDTI();
    MT_CTSTR v0_1 = uShlComponentCtrl::DTI.mName;
    const MtDTI* v0_0 = &t0;
    const MtDTI* v2_0;
    MT_CTSTR v2_1;
    uDDOModel* pModel;
    for (;;) {
        if (v0_1 == v0_0->mName) {
            if (v0_3 != nullptr) {
                uShlComponentCtrl* pShl = static_cast<uShlComponentCtrl*>(v0_3);
                pModel = static_cast<uShlBase*>(v0_3)->getOwner();
                if (pModel == nullptr) {
                    return 0;
                } else {
                    const MtDTI& t2 = pModel->getDTI();
                    v2_1 = uHuman::DTI.mName;
                    v2_0 = &t2;
                    break;
                }
            } else {
                return 0;
            }
        } else {
            if (v0_0->mpParent != nullptr) {
                v0_0 = v0_0->mpParent;
            } else {
                return 0;
            }
        }
    }
    for (;;) {
        if (v2_1 == v2_0->mName) {
            if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(pModel) + 13376)) != 0) {
                if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(pModel) + 13376)) + 40)) == 10) {
                    uHuman* pHuman = static_cast<uHuman*>(pModel);
                    return static_cast<u32>(pHuman->mpJob10->getCs08ShlSizeCache());
                }
            }
            return 0;
        } else {
            if (v2_0->mpParent != nullptr) {
                v2_0 = v2_0->mpParent;
            } else {
                break;
            }
        }
    }
    return 0;
}

inline cpShlSelectorJob10Cs08::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cpShlSelectorJob10Cs08::MyDTI cpShlSelectorJob10Cs08::DTI("cpShlSelectorJob10Cs08", &::cpShlSelector::DTI, 96ul, 0u, 0u);

__attribute__((weak)) MtObject* cpShlSelectorJob10Cs08::MyDTI::newInstance() const {
    DDON_STUB("cpShlSelectorJob10Cs08::MyDTI::newInstance")
    return nullptr;
}

