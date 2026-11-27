// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cSystemCheck.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cResource.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUIMessage.h"
#include "sArchiveManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "../../XFramework/sSavedata.h"
#include "sSavedataExt.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "uGUIBase.h"
#include "uGUISystemMsg.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cSystemCheck::getDTI() const {
    return cSystemCheck::DTI;
}

__attribute__((weak)) bool cSystemCheck::createSystemWindow(u32 msgNo) {
    DDON_STUB("cSystemCheck::createSystemWindow")
    return {};
}

bool cSystemCheck::checkFreeSpace() {
    switch (mRno2) {
        case 0:
        {
            mRno2 = 1;
            if (!static_cast<sSavedataExt*>(sSavedata::getInstance())->beginExistCheck()) {
                mFlag = mFlag | 2u;
                return true;
            } else {
                return true;
            }
            break;
        }
        case 1:
        {
            if (!static_cast<sSavedataExt*>(sSavedata::getInstance())->isBusy()) {
                mRno2 = 2;
                if (sSavedata::getInstance()->mResult == 3) {
                    mFlag = mFlag | 1u;
                    return true;
                } else {
                    return true;
                }
            } else {
                return true;
            }
            break;
        }
        case 2:
        {
            mRno2 = 3;
            mVal = 0;
            if ((mFlag & 1u) == 0) {
                u32 t0 = static_cast<sSavedataExt*>(sSavedata::getInstance())->getSavedataSize();
                if (!static_cast<sSavedataExt*>(sSavedata::getInstance())->beginHddSpaceCheck(t0)) {
                    mFlag = mFlag | 4u;
                    return true;
                } else {
                    return true;
                }
            } else {
                if (!static_cast<sSavedataExt*>(sSavedata::getInstance())->beginHddSpaceCheck(0u)) {
                    mFlag = mFlag | 4u;
                    return true;
                } else {
                    return true;
                }
            }
            break;
        }
        case 3:
        {
            if (!static_cast<sSavedataExt*>(sSavedata::getInstance())->isHddSpaceCheckBusy()) {
                sSavedata* t1 = sSavedata::getInstance();
                if (t1->mResult == 2) {
                    mFlag = mFlag | 8u;
                    mVal = static_cast<s32>(static_cast<sSavedataExt*>(t1)->getNeedHddSizeKB());
                    return false;
                } else {
                    return false;
                }
            } else {
                return true;
            }
            break;
        }
        default:
        {
            return true;
        }
    }
}

__attribute__((weak)) void cSystemCheck::setValueParam(uGUISystemMsg* pMsg, s32 Val) {
    DDON_STUB("cSystemCheck::setValueParam")
    /* stub */
}

cSystemCheck::cSystemCheck() {
    mSelectType = 0;
    mChoiceNo = 0;
    mRno0 = 0;
    mRno1 = 0;
    mRno2 = 0;
    mRno3 = 0;
    mFlag = 0;
    mVal = 0;
    mpGUISystemMsg = nullptr;
    mpCommonRes = nullptr;
    mpSystemRes = nullptr;
    mRno0 = 3;
    mRno1 = 0;
    mRno2 = 0;
    mResult = RESULT_WAIT;
}

cSystemCheck::~cSystemCheck() {
    if (mpGUISystemMsg != nullptr) {
        mpGUISystemMsg->kill();
        mpGUISystemMsg = nullptr;
    }
    if (mpSystemRes != nullptr) {
        mpSystemRes->release();
        mpSystemRes = nullptr;
    }
    if (mpCommonRes == nullptr) {
        return;
    }
    mpCommonRes->release();
    mpCommonRes = nullptr;
}

void cSystemCheck::loadResource() {
    if (mpSystemRes == nullptr) {
        sArchiveManager* t0 = sArchiveManager::getInstance();
        ARC_TAGID t1 = rArchiveListArray::convTagId("systemFlow");
        mpSystemRes = static_cast<rGUIMessage*>(t0->createRes(t1, rArchiveListArray::convSearchId("RES_ID_SYSTEM_MESSASGE_GMD"), 1u, false));
        if (mpCommonRes == nullptr) {
            sArchiveManager* t2 = sArchiveManager::getInstance();
            ARC_TAGID t3 = rArchiveListArray::convTagId("systemFlow");
            mpCommonRes = static_cast<rGUIMessage*>(t2->createRes(t3, rArchiveListArray::convSearchId("RES_ID_COMMON_MESSAGE_GMD"), 1u, false));
        }
    } else {
        if (mpCommonRes == nullptr) {
            sArchiveManager* t2 = sArchiveManager::getInstance();
            ARC_TAGID t3 = rArchiveListArray::convTagId("systemFlow");
            mpCommonRes = static_cast<rGUIMessage*>(t2->createRes(t3, rArchiveListArray::convSearchId("RES_ID_COMMON_MESSAGE_GMD"), 1u, false));
        }
    }
}

void cSystemCheck::releaseResource() {
    if (mpSystemRes != nullptr) {
        mpSystemRes->release();
        mpSystemRes = nullptr;
    }
    if (mpCommonRes == nullptr) {
        return;
    }
    mpCommonRes->release();
    mpCommonRes = nullptr;
}

void cSystemCheck::init() {
    mRno0 = 3;
    mRno1 = 0;
    mRno2 = 0;
    mResult = RESULT_WAIT;
}

__attribute__((weak)) void cSystemCheck::move() {
    DDON_STUB("cSystemCheck::move")
    /* stub */
}

inline cSystemCheck::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cSystemCheck::MyDTI cSystemCheck::DTI("cSystemCheck", &::MtObject::DTI, 56ul, 0u, 0u);

MtObject* cSystemCheck::MyDTI::newInstance() const {
    return new (16u) cSystemCheck;
}

