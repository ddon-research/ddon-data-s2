// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cLayoutSetEnemy.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtString.h"
#include "../../MT/MtSynchronize.h"
#include "Protocol/PacketData/Stage.h"
#include "aStage.h"
#include "../../XFramework/cArea.h"
#include "cContextInstance.h"
#include "cContextInterface.h"
#include "cContextPlayerInfo.h"
#include "cEquipData.h"
#include "cLayoutSet.h"
#include "cNetGameServer.h"
#include "cOmControl.h"
#include "../../XFramework/cResource.h"
#include "cSetInfoCoord.h"
#include "cSetInfoEnemy.h"
#include "../../XFramework/cSystem.h"
#include "cpLayout.h"
#include "../../generated/shared/nDDOMath.h"
#include "nLayout.h"
#include "../../XFramework/rCollisionHeightField.h"
#include "rLayout.h"
#include "rLayoutGroupParam.h"
#include "rLayoutPreset.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "../../XFramework/sCollision.h"
#include "sCollisionExt.h"
#include "sContextManager.h"
#include "sControlManager.h"
#include "sEnemyManager.h"
#include "sGame.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sOmManager.h"
#include "sPlayerManager.h"
#include "sSetManager.h"
#include "sWorldOffset.h"
#include "uControl.h"
#include "uControlEnemy.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uHumanEnemy.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cLayoutSetEnemy::getDTI() const {
    return cLayoutSetEnemy::DTI;
}

inline MtAllocator* cLayoutSetEnemy::getAllocator() {
    return MtMemoryAllocator::getAllocator(cLayoutSetEnemy::DTI);
}

void* cLayoutSetEnemy::operator new(size_t sz, u32 align) {
    return cLayoutSetEnemy::getAllocator()->memAlloc(sz, align, cLayoutSetEnemy::DTI.getID());
}

inline void cLayoutSetEnemy::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cLayoutSetEnemy::DTI)->memFree(p_addr);
}

cLayoutSetEnemy::cLayoutSetEnemy() {
}

cLayoutSetEnemy::~cLayoutSetEnemy() {
    kill();
}

__attribute__((weak)) void cLayoutSetEnemy::setup() {
    DDON_STUB("cLayoutSetEnemy::setup")
    /* stub */
}

void cLayoutSetEnemy::move() {
    this->cLayoutSet::move();
}

__attribute__((weak)) void cLayoutSetEnemy::finish() {
    DDON_STUB("cLayoutSetEnemy::finish")
    /* stub */
}

__attribute__((weak)) void cLayoutSetEnemy::createProperty(MtPropertyList& s) {
}

MtObject* cLayoutSetEnemy::setLayoutUnit(rLayout* pLayout, u32 no, bool isForceSet, u32 mode) {
    if (pLayout != nullptr) {
        if (getGroupParam() != nullptr) {
            if (getGroupParam()->mKillAreaType == cGroupParam::KILL_AREA_SHAPE) {
                return setLayoutUnitSever(pLayout, no, isForceSet, mode);
            }
        }
    }
    return nullptr;
}

__attribute__((weak)) MtObject* cLayoutSetEnemy::setLayoutUnitSever(rLayout* pLayout, u32 no, bool isForceSet, u32 mode) {
    DDON_STUB("cLayoutSetEnemy::setLayoutUnitSever")
    return nullptr;
}

__attribute__((weak)) bool cLayoutSetEnemy::deleteAllUnit() {
    DDON_STUB("cLayoutSetEnemy::deleteAllUnit")
    return {};
}

void cLayoutSetEnemy::deleteUnit(MtObject* pObj) {
    const MtDTI& t0 = pObj->getDTI();
    MT_CTSTR v0_1 = uControl::DTI.mName;
    for (const MtDTI* v0_0 = &t0;;) {
        if (v0_1 == v0_0->mName) {
            sControlManager::getInstance()->releaseUnit(static_cast<uControl*>(pObj));
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

s32 cLayoutSetEnemy::getEnemySetTblIndex(s32 uinitID) {
    rLayoutPreset* pPri = sSetManager::getInstance()->getLotPreset();
    unsigned int v3_9;
    if (pPri == nullptr) {
        v3_9 = 0xFFFFFFFF;
    } else {
        if (pPri->getDataNum() == 0) {
            v3_9 = 0xFFFFFFFF;
        } else {
            for (unsigned int i0_3 = 0;;) {
                cLayoutPreset* t0 = pPri->getData(i0_3);
                if (t0 != nullptr) {
                    if (t0->mCtrlType == 32) {
                        if (t0->mID == static_cast<unsigned int>(uinitID)) {
                            v3_9 = i0_3;
                            return static_cast<s32>(v3_9);
                        }
                    }
                }
                if ((i0_3 + 1u) < pPri->getDataNum()) {
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
            v3_9 = 0xFFFFFFFF;
        }
    }
    return static_cast<s32>(v3_9);
}

MtObject* cLayoutSetEnemy::getUnit(u32 id) {
    if (mUnitArray.mLength != 0) {
        u32 i = 0;
        do {
            if (mUnitArray.mpArray[i] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mUnitArray.mpArray[i]) + 476)) == id) {
                    return mUnitArray.mpArray[i];
                }
            }
            i += 1u;
        } while (i < mUnitArray.mLength);
    }
    return nullptr;
}

__attribute__((weak)) uControlEnemy* cLayoutSetEnemy::createUnitEnemy(rLayout::SetInfo* psi, const cLayoutPreset* preset, cGroupParam::EmSetInfo* pesi) {
    DDON_STUB("cLayoutSetEnemy::createUnitEnemy")
    return nullptr;
}

__attribute__((weak)) uControlEnemy* cLayoutSetEnemy::createControl(u32 EmId, nLayout::stUniqueID* pUniqueId, cSetInfoEnemy* pSetInfoEm, cContextInstance* pContext) {
    DDON_STUB("cLayoutSetEnemy::createControl")
    return nullptr;
}

__attribute__((weak)) void cLayoutSetEnemy::addOmControlToDrop(cGroupParam* pGP) {
    DDON_STUB("cLayoutSetEnemy::addOmControlToDrop")
    /* stub */
}

__attribute__((weak)) bool cLayoutSetEnemy::canSetUnit() const {
    DDON_STUB("cLayoutSetEnemy::canSetUnit")
    return {};
}

void cLayoutSetEnemy::moveSetUnit() {
    if (mpRsrc == nullptr) {
        return;
    }
    if (mpRsrc->isUsage()) {
        if (canSetUnit()) {
            if (mpGroupParam != nullptr) {
                if (static_cast<sAreaExt*>(sArea::getInstance())->isField()) {
                    if (getGroupParam()->getIsLoadLotRes()) {
                        if (getGroupParam()->mKillAreaType == cGroupParam::KILL_AREA_SHAPE) {
                            moveSetUnitSever();
                        }
                    }
                } else {
                    if (getGroupParam()->mKillAreaType == cGroupParam::KILL_AREA_SHAPE) {
                        moveSetUnitSever();
                    }
                }
            }
        }
    }
}

__attribute__((weak)) void cLayoutSetEnemy::moveSetUnitSever() {
    DDON_STUB("cLayoutSetEnemy::moveSetUnitSever")
    /* stub */
}

void cLayoutSetEnemy::moveSetUnitSubGroupSever(u32 flagNo, u32 idx) {
    cGroupParam* pGP = getGroupParam();
    if (pGP == nullptr) {
        return;
    }
    if ((flagNo + 1u) <= 31u) {
        if (((static_cast<unsigned long>(pGP->mSubGroupRequestBit) >> static_cast<unsigned long>((flagNo + 1u) & 31u)) & 1ul) != 0) {
            if ((static_cast<unsigned long>(pGP->mSubGroupSetupBit) & (1ul << static_cast<unsigned long>(static_cast<unsigned char>(flagNo + 1u) & 31))) != 0) {
                MtObject* t0 = setLayoutUnitSever(mpRsrc, idx, false, 2u);
                mUnitArray.mpArray[idx] = t0;
            } else {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(sNetwork::getInstance()) + 3680)) + 712)) == 4) {
                    static_cast<sNetworkExt*>(sNetwork::getInstance())->isDispErrorDialog();
                }
            }
        } else {
            CDataStageLayoutID frame80(nLayout::createStageLayoutId(static_cast<u32>(sGame::getInstance()->getStageNo()), pGP->getLayer(), pGP->mDataCommon & 511u));
            if (!!static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getEnemySetList(frame80, flagNo + 1u)) {
                pGP->mSubGroupRequestBit = static_cast<unsigned int>(static_cast<unsigned long>(pGP->mSubGroupRequestBit) | (1ul << static_cast<unsigned long>(static_cast<unsigned char>(flagNo + 1u) & 31)));
            }
        }
    } else {
        CDataStageLayoutID frame80(nLayout::createStageLayoutId(static_cast<u32>(sGame::getInstance()->getStageNo()), pGP->getLayer(), pGP->mDataCommon & 511u));
        static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getEnemySetList(frame80, flagNo + 1u);
    }
}

inline cLayoutSetEnemy::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cLayoutSetEnemy::MyDTI cLayoutSetEnemy::DTI("cLayoutSetEnemy", &::cLayoutSet::DTI, 136ul, 0u, 0u);

MtObject* cLayoutSetEnemy::MyDTI::newInstance() const {
    return new (16u) cLayoutSetEnemy;
}

