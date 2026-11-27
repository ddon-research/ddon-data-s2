// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sMyRoom.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "aStage.h"
#include "../../XFramework/cArea.h"
#include "cContextInstance.h"
#include "cContextInterface.h"
#include "cEquipData.h"
#include "cPlayerLoadManager.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cSystem.h"
#include "rRoomWearParam.h"
#include "sArchiveManager.h"
#include "../../XFramework/sArea.h"
#include "sContextManager.h"
#include "sNpcManager.h"
#include "uControl.h"
#include "uDDOModel.h"
#include "uNpc.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sMyRoom::getDTI() const {
    return sMyRoom::DTI;
}

void* sMyRoom::operator new(size_t sz, u32 align) {
    return sMyRoom::getAllocator()->memAlloc(sz, align, sMyRoom::DTI.getID());
}

sMyRoom::sMyRoom() {
    mThreadSafe = true;
    mPawnBathWear = -1;
    mPawnRoomWear = -1;
    mPawnSleepWear = -1;
    mPawnWear = -1;
    mPawnWearType = -1;
    mPlayerRoomWear = -1;
    mReqPlayerRoomWear = -1;
    mprRoomWear = nullptr;
    sMyRoom::mpInstance = this;
}

sMyRoom::~sMyRoom() {
    sMyRoom::mpInstance = nullptr;
}

void sMyRoom::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
}

MtUI* sMyRoom::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

void sMyRoom::init() {
    mPawnBathWear = -1;
    mPawnRoomWear = -1;
    mPawnSleepWear = -1;
    mPawnWear = -1;
    mPawnWearType = -1;
    mPlayerRoomWear = -1;
    mReqPlayerRoomWear = -1;
}

__attribute__((weak)) void sMyRoom::move() {
}

bool sMyRoom::isReqPlayerChangeWear(const cContextInstance* pContext) {
    if (sArea::getInstance()->mpArea[2] != nullptr) {
        if (static_cast<aStage*>(sArea::getInstance()->mpArea[2])->isMyRoomStage() && (pContext == sContextManager::getInstance()->getContextMyPlayer())) {
            return mPlayerRoomWear != mReqPlayerRoomWear;
        }
    }
    return false;
}

bool sMyRoom::isChangePlayerWear(u32 category, const cContextInstance* pContext) {
    if (sArea::getInstance()->mpArea[2] != nullptr) {
        if (static_cast<aStage*>(sArea::getInstance()->mpArea[2])->isMyRoomStage()) {
            if (pContext == sContextManager::getInstance()->getContextMyPlayer()) {
                if ((category - 3u) <= 6u) {
                    if (mPlayerRoomWear == mReqPlayerRoomWear) {
                        return false;
                    } else {
                        u32 sex = cContextInterface::getSex(pContext);
                        if (mPlayerRoomWear > -1) {
                            u16 t0 = getResRoomWear(static_cast<u32>(mPlayerRoomWear), category, sex);
                            if (mReqPlayerRoomWear > -1) {
                                u16 itemIdNew = getResRoomWear(static_cast<u32>(mReqPlayerRoomWear), category, sex);
                                return t0 != itemIdNew;
                            } else {
                                u16 t2 = cContextInterface::getContextEquip(const_cast<cContextInstance*>(pContext)).getEquip(static_cast<unsigned char>(category), static_cast<u8>(1), true);
                                return t0 != t2;
                            }
                        } else {
                            u16 t1 = cContextInterface::getContextEquip(const_cast<cContextInstance*>(pContext)).getEquip(static_cast<unsigned char>(category), static_cast<u8>(1), true);
                            if (mReqPlayerRoomWear > -1) {
                                u16 itemIdNew = getResRoomWear(static_cast<u32>(mReqPlayerRoomWear), category, sex);
                                return t1 != itemIdNew;
                            } else {
                                u16 t2 = cContextInterface::getContextEquip(const_cast<cContextInstance*>(pContext)).getEquip(static_cast<unsigned char>(category), static_cast<u8>(1), true);
                                return t1 != t2;
                            }
                        }
                    }
                } else {
                    return false;
                }
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

u16 sMyRoom::getItemIdPlayerWearNew(u32 category, const cContextInstance* pContext) {
    return getItemIdPlayerWearSub(category, pContext, false);
}

u16 sMyRoom::getItemIdPlayerWearNow(u32 category, const cContextInstance* pContext) {
    return getItemIdPlayerWearSub(category, pContext, true);
}

__attribute__((weak)) u16 sMyRoom::getItemIdPlayerWearSub(u32 category, const cContextInstance* pContext, bool isNow) {
    if (sArea::getInstance()->mpArea[2] != nullptr) {
        if (static_cast<aStage*>(sArea::getInstance()->mpArea[2])->isMyRoomStage()) {
            if ((category - 3u) <= 6u) {
                if (pContext == sContextManager::getInstance()->getContextMyPlayer()) {
                    u32 sex = cContextInterface::getSex(pContext);
                    if (mReqPlayerRoomWear > -1) {
                        if (isNow) {
                            return getResRoomWear(static_cast<u32>(mPlayerRoomWear), category, sex);
                        } else {
                            return getResRoomWear(static_cast<u32>(mReqPlayerRoomWear), category, sex);
                        }
                    } else {
                        if (pContext != nullptr) {
                            return cContextInterface::getContextEquip(const_cast<cContextInstance*>(pContext)).getEquip(static_cast<unsigned char>(category), static_cast<u8>(1), true);
                        } else {
                            return 0;
                        }
                    }
                } else {
                    if (pContext != nullptr) {
                        return cContextInterface::getContextEquip(const_cast<cContextInstance*>(pContext)).getEquip(static_cast<unsigned char>(category), static_cast<u8>(1), true);
                    } else {
                        return 0;
                    }
                }
            } else {
                if (pContext != nullptr) {
                    return cContextInterface::getContextEquip(const_cast<cContextInstance*>(pContext)).getEquip(static_cast<unsigned char>(category), static_cast<u8>(1), true);
                } else {
                    return 0;
                }
            }
        } else {
            if (pContext != nullptr) {
                return cContextInterface::getContextEquip(const_cast<cContextInstance*>(pContext)).getEquip(static_cast<unsigned char>(category), static_cast<u8>(1), true);
            } else {
                return 0;
            }
        }
    } else {
        if (pContext != nullptr) {
            return cContextInterface::getContextEquip(const_cast<cContextInstance*>(pContext)).getEquip(static_cast<unsigned char>(category), static_cast<u8>(1), true);
        } else {
            return 0;
        }
    }
}

bool sMyRoom::isReqPlayerRoomWear(const cContextInstance* pContext) {
    if (sArea::getInstance()->mpArea[2] != nullptr) {
        if (static_cast<aStage*>(sArea::getInstance()->mpArea[2])->isMyRoomStage() && (pContext == sContextManager::getInstance()->getContextMyPlayer())) {
            return mReqPlayerRoomWear > -1;
        }
    }
    return false;
}

bool sMyRoom::isPlayerRoomWear(const cContextInstance* pContext) {
    if (sArea::getInstance()->mpArea[2] != nullptr) {
        if (static_cast<aStage*>(sArea::getInstance()->mpArea[2])->isMyRoomStage() && (pContext == sContextManager::getInstance()->getContextMyPlayer())) {
            return mPlayerRoomWear > -1;
        }
    }
    return false;
}

void sMyRoom::setChangePlayerWear(const cContextInstance* pContext) {
    if (sArea::getInstance()->mpArea[2] == nullptr) {
        return;
    }
    if (!static_cast<aStage*>(sArea::getInstance()->mpArea[2])->isMyRoomStage()) {
        return;
    }
    if (pContext != sContextManager::getInstance()->getContextMyPlayer()) {
        return;
    }
    mPlayerRoomWear = mReqPlayerRoomWear;
}

void sMyRoom::setRoomWearResource() {
    if (mprRoomWear != nullptr) {
        mprRoomWear->release();
        mprRoomWear = nullptr;
    }
    mprRoomWear = static_cast<rRoomWearParam*>(sArchiveManager::getInstance()->createRes("MyRoom", "RES_ID_ROOMWEAR", 1u, false));
}

void sMyRoom::releaseRoomWearResource() {
    if (mprRoomWear == nullptr) {
        return;
    }
    mprRoomWear->release();
    mprRoomWear = nullptr;
}

__attribute__((weak)) u16 sMyRoom::getResRoomWear(u32 index, u32 category, u32 sex) {
    if (mprRoomWear != nullptr) {
        if (index < mprRoomWear->getDataNum()) {
            switch (category - 3u) {
                case 0:
                {
                    return mprRoomWear->getData(index)->getAH(sex);
                }
                case 1:
                {
                    return mprRoomWear->getData(index)->getAB(sex);
                }
                case 2:
                {
                    return mprRoomWear->getData(index)->getWB(sex);
                }
                case 3:
                {
                    return mprRoomWear->getData(index)->getAA(sex);
                }
                case 4:
                {
                    return mprRoomWear->getData(index)->getAL(sex);
                }
                case 5:
                {
                    return mprRoomWear->getData(index)->getWL(sex);
                }
                case 6:
                {
                    return mprRoomWear->getData(index)->getAC(sex);
                }
                default:
                {
                    return 0;
                }
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

void sMyRoom::checkRoomWear(u32 itemId) {
    if (mprRoomWear != nullptr) {
        u32 num = mprRoomWear->getDataNum();
        if (num != 0) {
            for (unsigned int i0_3 = 0;;) {
                if (mprRoomWear->getData(i0_3)->mItem == itemId) {
                    switch (mprRoomWear->getData(i0_3)->mType) {
                        case 0:
                        {
                            mReqPlayerRoomWear = static_cast<s32>(i0_3);
                            break;
                        }
                        case 1:
                        {
                            mPawnRoomWear = static_cast<s32>(i0_3);
                            break;
                        }
                        case 2:
                        {
                            mPawnBathWear = static_cast<s32>(i0_3);
                            break;
                        }
                        case 3:
                        {
                            mPawnSleepWear = static_cast<s32>(i0_3);
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }
                }
                if (num != (i0_3 + 1u)) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
}

void sMyRoom::clearWearInfo() {
    mReqPlayerRoomWear = -1;
    mPawnRoomWear = -1;
    mPawnBathWear = -1;
    mPawnSleepWear = -1;
}

void sMyRoom::setPawnWear(s32 type) {
    mPawnWearType = type;
    if (type != 1) {
        if (type == 0) {
            mPawnWear = (mPawnBathWear <= -1) ? 0 : mPawnBathWear;
        } else {
            if (type == -1) {
                mPawnWear = mPawnRoomWear;
            } else {
                mPawnWear = -1;
            }
        }
    } else {
        mPawnWear = (mPawnSleepWear <= -1) ? 1 : mPawnSleepWear;
    }
}

s32 sMyRoom::getPawnWear() {
    if (mPawnWearType != 1) {
        if (mPawnWearType == 0) {
            return (mPawnBathWear <= -1) ? 0 : mPawnBathWear;
        } else {
            if (mPawnWearType == -1) {
                return mPawnRoomWear;
            } else {
                return -1;
            }
        }
    } else {
        return (mPawnSleepWear <= -1) ? 1 : mPawnSleepWear;
    }
}

bool sMyRoom::isPawnChanging() {
    if (!sNpcManager::getInstance()->isReqChangeEquipMyRoom()) {
        uNpc* pNpc = sNpcManager::getInstance()->getNpcUnit(7100u);
        if (pNpc != nullptr) {
            cContextInstHm* pContext = static_cast<cContextInstHm*>(pNpc->getCtrl()->getContextInst());
            if ((pContext != nullptr) && !cContextInterface::getPlayerLoadMgr(pContext).isLoadFinish()) {
                return true;
            }
            return false;
        } else {
            return false;
        }
    } else {
        return true;
    }
}

inline sMyRoom::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sMyRoom::MyDTI sMyRoom::DTI("sMyRoom", &::cSystem::DTI, 64ul, 0u, 0u);

sMyRoom* sMyRoom::mpInstance;

__attribute__((weak)) MtObject* sMyRoom::MyDTI::newInstance() const {
    DDON_STUB("sMyRoom::MyDTI::newInstance")
    return nullptr;
}

