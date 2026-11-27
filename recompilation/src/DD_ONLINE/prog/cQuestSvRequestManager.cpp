// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cQuestSvRequestManager.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cContextInstance.h"
#include "cNetGameServer.h"
#include "cQuestFunctionManagerBAse.h"
#include "cQuestResourceLoadManager.h"
#include "cQuestSvRequest.h"
#include "nQuest.h"
#include "sContextManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sQuestManagerExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cQuestSvRequestManager::getDTI() const {
    return cQuestSvRequestManager::DTI;
}

void* cQuestSvRequestManager::operator new(size_t sz, u32 align) {
    return cQuestSvRequestManager::getAllocator()->memAlloc(sz, align, cQuestSvRequestManager::DTI.getID());
}

cQuestSvRequest* cQuestSvRequestManager::pushRequest(const MtDTI& requestClassDti) {
    sQuestManagerExt::getInstance()->csLock();
    cQuestSvRequest* pRequestClass = static_cast<cQuestSvRequest*>(requestClassDti.newInstance());
    sQuestManagerExt::getInstance()->getQuestSvRequestMgr()->pushRequest(pRequestClass);
    sQuestManagerExt::getInstance()->csUnlock();
    return pRequestClass;
}

void cQuestSvRequestManager::popRequest(const MtObject* pFromClass) {
    sQuestManagerExt::getInstance()->csLock();
    sQuestManagerExt::getInstance()->getQuestSvRequestMgr()->removeRequest(pFromClass);
    sQuestManagerExt::getInstance()->getQuestResourceLoadMgr()->removeTask(pFromClass);
    sQuestManagerExt::getInstance()->csUnlock();
}

__attribute__((weak)) bool cQuestSvRequestManager::hasRequest(const MtObject* pFromClass) {
    DDON_STUB("cQuestSvRequestManager::hasRequest")
    return {};
}

bool cQuestSvRequestManager::canRequest(bool isDispAnnounce) {
    sNetwork* t0 = sNetwork::getInstance();
    cNetGameServer* t1 = static_cast<sNetworkExt*>(t0)->getGameServer();
    sNetworkExt::NET_STAT t2 = t1->mStatus[43];
    if (t2 != sNetworkExt::NET_STAT_REQ) {
        sGame* t3 = sGame::getInstance();
        s32 t4 = t3->getSelfMemberIndex();
        bool t6 = t3->mIsParty[t4];
        if (!t6) {
            if (!isDispAnnounce) {
                return false;
            } else {
                sGUI* t11 = sGUI::getInstance();
                rGUIMessage* t12 = static_cast<sGUIExt*>(t11)->getMsgCommonDialog();
                MT_CTSTR t13 = static_cast<sGUIExt*>(t11)->getMsgFromIdxInfo(t12, 385u);
                static_cast<sGUIExt*>(t11)->requestAnnounce(t13, 1u, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), 0u, 0u, true);
                return false;
            }
        }
    } else {
        return false;
    }
    u32 i = 0;
    do {
        sContextManager* t7 = sContextManager::getInstance();
        cContextInstHm* t8 = t7->getContextPartyPlayerIndex(i, true);
        if (t8 != nullptr) {
            if ((t8->mIsValid & 1) != 0) {
                if ((t8->mIsValid & 11) != 11) {
                    if (isDispAnnounce) {
                        sGUI* t11 = sGUI::getInstance();
                        rGUIMessage* t12 = static_cast<sGUIExt*>(t11)->getMsgCommonDialog();
                        MT_CTSTR t13 = static_cast<sGUIExt*>(t11)->getMsgFromIdxInfo(t12, 385u);
                        static_cast<sGUIExt*>(t11)->requestAnnounce(t13, 1u, static_cast<MT_CTSTR>(nullptr), static_cast<MT_CTSTR>(nullptr), 0u, 0u, true);
                        return false;
                    } else {
                        return false;
                    }
                }
            }
        }
        i += 1u;
    } while (i <= 7u);
    return true;
}

bool cQuestSvRequestManager::isEmpty() const {
    return mQuestSvRequestQueue.mLength == 0;
}

bool cQuestSvRequestManager::canReqQuestProgres() const {
    return (mpQuestProgressReq == nullptr) && (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[43] != sNetworkExt::NET_STAT_REQ);
}

__attribute__((weak)) cQuestSvRequestManager& cQuestSvRequestManager::pushRequest(cQuestSvRequest* pSvReq) {
    if (pSvReq != nullptr) {
        const MtDTI& t0 = pSvReq->getDTI();
        MT_CTSTR v0_1 = cQuestSvReqQuestProgress::DTI.mName;
        const MtDTI* v0_0 = &t0;
        const MtDTI* v1_0;
        cQuestSvRequest* v2_2;
        for (;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                const MtDTI& t1 = pSvReq->getDTI();
                MT_CTSTR v1_1 = cQuestSvReqQuestProgress::DTI.mName;
                v1_0 = &t1;
                for (;;) {
                    if (v1_1 == v1_0->mName) {
                        v2_2 = pSvReq;
                        break;
                    } else {
                        if (v1_0->mpParent != nullptr) {
                            v1_0 = v1_0->mpParent;
                        } else {
                            v2_2 = nullptr;
                            break;
                        }
                    }
                }
                mpQuestProgressReq = static_cast<cQuestSvReqQuestProgress*>(v2_2);
                break;
            }
        }
        u32 t2 = mQuestSvRequestQueue.mLength;
        u32 t3 = mQuestSvRequestQueue.mBufsiz;
        if (t2 < t3) {
            mQuestSvRequestQueue.mLength = t2 + 1u;
            mQuestSvRequestQueue.mpArray[t2] = static_cast<MtObject*>(pSvReq);
        } else {
            void* t4 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t3 + 32u) * 8, 16u);
            memset(t4, 0, static_cast<size_t>(t3 + 32u) * 8);
            memcpy(t4, static_cast<const void*>(mQuestSvRequestQueue.mpArray), static_cast<size_t>(mQuestSvRequestQueue.mLength) * 8);
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mQuestSvRequestQueue.mpArray));
            mQuestSvRequestQueue.mpArray = static_cast<MtObject* *>(t4);
            mQuestSvRequestQueue.mBufsiz = t3 + 32u;
            u32 t5 = mQuestSvRequestQueue.mLength;
            mQuestSvRequestQueue.mLength = t5 + 1u;
            mQuestSvRequestQueue.mpArray[t5] = static_cast<MtObject*>(pSvReq);
        }
    }
    return *this;
}

__attribute__((weak)) cQuestSvRequestManager& cQuestSvRequestManager::removeRequest(const MtObject* pFromClass) {
    DDON_STUB("cQuestSvRequestManager::removeRequest")
    __builtin_unreachable();
}

__attribute__((weak)) void cQuestSvRequestManager::updateRequest() {
    DDON_STUB("cQuestSvRequestManager::updateRequest")
    /* stub */
}

__attribute__((weak)) void cQuestSvRequestManager::deleteRequestQueue(nQuest::SCHEDULE_ID scheduleId) {
    DDON_STUB("cQuestSvRequestManager::deleteRequestQueue")
    /* stub */
}

void cQuestSvRequestManager::release() {
    mpQuestProgressReq = nullptr;
    if (mQuestSvRequestQueue.mLength != 0) {
        u32 v0_0 = mQuestSvRequestQueue.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mQuestSvRequestQueue.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mQuestSvRequestQueue.mpArray[i0_3];
                v1_0 = mQuestSvRequestQueue.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mQuestSvRequestQueue.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mQuestSvRequestQueue.mpArray));
    }
    mQuestSvRequestQueue.mpArray = nullptr;
    mQuestSvRequestQueue.mBufsiz = 0;
    mQuestSvRequestQueue.mLength = 0;
}

void cQuestSvRequestManager::cancelQuestProgress() {
    if (mpQuestProgressReq != nullptr) {
        if (!mpQuestProgressReq->waitsResult()) {
            mpQuestProgressReq->resetParam();
            u32 v0_0 = mQuestSvRequestQueue.mLength;
            if (v0_0 != 0) {
                cQuestSvReqQuestProgress* v0_5 = mpQuestProgressReq;
                MtObject* * v0_1 = mQuestSvRequestQueue.mpArray;
                unsigned int i0_3 = 0;
                u32 v3_0;
                unsigned int v4_1;
                u32 v4_2;
                unsigned int v4_3;
                for (;;) {
                    if (v0_5 == v0_1[i0_3]) {
                        if (!mQuestSvRequestQueue.mAutoDelete) {
                            v3_0 = v0_0;
                        } else {
                            if (v0_5 == nullptr) {
                                v3_0 = v0_0;
                            } else {
                                delete v0_5;
                                v3_0 = mQuestSvRequestQueue.mLength;
                            }
                        }
                        if ((i0_3 + 1u) < v3_0) {
                            v4_1 = i0_3 + 1u;
                            v4_2 = v3_0;
                            v4_3 = i0_3;
                            for (;;) {
                                mQuestSvRequestQueue.mpArray[v4_3] = mQuestSvRequestQueue.mpArray[v4_1];
                                if (v4_2 != (v4_1 + 1u)) {
                                    v4_3 = v4_1;
                                    v4_1 = v4_1 + 1u;
                                } else {
                                    break;
                                }
                            }
                        }
                        mQuestSvRequestQueue.mLength = v3_0 - 1u;
                        break;
                    } else {
                        if ((i0_3 + 1u) < v0_0) {
                            i0_3 = i0_3 + 1u;
                        } else {
                            break;
                        }
                    }
                }
            }
            mpQuestProgressReq = nullptr;
        }
    }
}

cQuestSvRequestManager::cQuestSvRequestManager() {
    DDON_STUB("cQuestSvRequestManager::cQuestSvRequestManager")
    /* stub */
}

cQuestSvRequestManager::~cQuestSvRequestManager() {
    mpQuestProgressReq = nullptr;
    if (mQuestSvRequestQueue.mLength != 0) {
        u32 v0_0 = mQuestSvRequestQueue.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mQuestSvRequestQueue.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mQuestSvRequestQueue.mpArray[i0_3];
                v1_0 = mQuestSvRequestQueue.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mQuestSvRequestQueue.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mQuestSvRequestQueue.mpArray));
    }
    mQuestSvRequestQueue.mpArray = nullptr;
    mQuestSvRequestQueue.mBufsiz = 0;
    mQuestSvRequestQueue.mLength = 0;
}

__attribute__((weak)) void cQuestSvRequestManager::createProperty(MtPropertyList& s) {
}

MtUI* cQuestSvRequestManager::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline cQuestSvRequestManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestSvRequestManager::MyDTI cQuestSvRequestManager::DTI("cQuestSvRequestManager", &::cQuestFunctionManagerBase::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* cQuestSvRequestManager::MyDTI::newInstance() const {
    DDON_STUB("cQuestSvRequestManager::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<cQuestSvRequest>::~MtTypedArray();

