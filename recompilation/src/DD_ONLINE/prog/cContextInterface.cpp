// Reconstructed from the game's DWARF debug information.
#include <new>
#include <stdio.h>
#include "cContextInterface.h"
#include "Protocol/PacketData/Lobby.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "cContext.h"
#include "cContextInstance.h"
#include "cContextPlayerInfo.h"
#include "cEditParam.h"
#include "cEquipData.h"
#include "cNetGameServer.h"
#include "cPlayerLoadManager.h"
#include "nCharacterData.h"
#include "../../generated/shared/nDDOGame.h"
#include "nDDOUtility.h"
#include "nJobParam.h"
#include "nNetMsgData.h"
#include "rCharacterEdit.h"
#include "sContextManager.h"
#include "sGame.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

static const nNetMsgData::stNetPos NetPosZero = {
    0x0p+0,
    0x0p+0f,
    0x0p+0,
};

static CHAR_NAME dummyCharName;

const MtDTI& cContextInterface::getDTI() const {
    return cContextInterface::DTI;
}

inline void* cContextInterface::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cContextInterface::DTI)->memAlloc(sz, align, cContextInterface::DTI.getID());
}

inline void cContextInterface::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cContextInterface::DTI)->memFree(p_addr);
}

cContextInterface::cContextInterface() {
    mpContextCharacter = nullptr;
    mpContextInstance = nullptr;
}

cContextInterface::~cContextInterface() {
}

__attribute__((weak)) void cContextInterface::createProperty(MtPropertyList& s) {
}

MtUI* cContextInterface::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

cContextInstHm* cContextInterface::getContextInstHm() {
    cContextInstance* v2_0;
    if (mpContextInstance == nullptr) {
        v2_0 = nullptr;
    } else {
        const MtDTI& t0 = mpContextInstance->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_0 = nullptr;
                    return static_cast<cContextInstHm*>(v2_0);
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        v2_0 = mpContextInstance;
    }
    return static_cast<cContextInstHm*>(v2_0);
}

u64 cContextInterface::getPosReceiveTime(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return static_cast<u64>(pChara->getPosReceiveTime());
    } else {
        return 0;
    }
}

void cContextInterface::setPosReceiveTime(cContextInstance* pInst, cContextCharacter* pChara, u64 time) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mPosReceiveTime = static_cast<t64>(time);
}

s32 cContextInterface::getPosReceiveInterval(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getPosReceiveInterval();
    } else {
        return -1;
    }
}

void cContextInterface::setPosReceiveInterval(cContextInstance* pInst, cContextCharacter* pChara, s32 interval) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mPosReceiveInterval = interval;
}

__attribute__((weak)) MtVector3 cContextInterface::getNetPos(const cContextInstance* pInst, const cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::getNetPos")
    __builtin_unreachable();
}

void cContextInterface::setNetPos(cContextInstance* pInst, cContextCharacter* pChara, const MtVector3& pos) {
    if (pInst == nullptr) {
        return;
    }
    pInst->setNetPos(pos);
}

const nNetMsgData::stNetPos& cContextInterface::getNetRealPos(const cContextInstance* pInst, const cContextCharacter* pChara) {
    return *((pInst == nullptr) ? (&NetPosZero) : (&pInst->mNetPos));
}

__attribute__((weak)) void cContextInterface::setNetRealPos(cContextInstance* pInst, const nNetMsgData::stNetPos& pos) {
    DDON_STUB("cContextInterface::setNetRealPos")
    /* stub */
}

f32 cContextInterface::getNetDir(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pInst != nullptr) {
        return pInst->getNetDir();
    } else {
        return 0.0f;
    }
}

void cContextInterface::setNetDir(cContextInstance* pInst, cContextCharacter* pChara, f32 dir) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mNetDir = dir;
}

s32 cContextInterface::getStageNo(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pInst != nullptr) {
        return pInst->getStageNo();
    } else {
        return 0;
    }
}

void cContextInterface::setStageNo(cContextInstance* pInst, cContextCharacter* pChara, s32 StageNo) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mStageNo = StageNo;
}

u32 cContextInterface::getUniqueId(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pInst != nullptr) {
        return pInst->getUniqueId();
    } else {
        return 0;
    }
}

void cContextInterface::setUniqueId(cContextInstance* pInst, cContextCharacter* pChara, u32 UniqueId) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mUniqueId = UniqueId;
}

u32 cContextInterface::getQuestId(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pInst != nullptr) {
        return pInst->getQuestId();
    } else {
        return 0;
    }
}

void cContextInterface::setQuestId(cContextInstance* pInst, cContextCharacter* pChara, u32 QuestId) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mQuestId = QuestId;
}

bool cContextInterface::getIsReqAction(const cContextInstance* pInst, const cContextCharacter* pChara, u32 idx) {
    if (pChara != nullptr) {
        return ((static_cast<unsigned long>(pChara->mIsReqAction) >> static_cast<unsigned long>(idx & 31u)) & 1ul) != 0;
    } else {
        return false;
    }
}

__attribute__((weak)) void cContextInterface::clrIsReqAction(cContextInstance* pInst, cContextCharacter* pChara, u32 idx) {
    DDON_STUB("cContextInterface::clrIsReqAction")
    /* stub */
}

u32 cContextInterface::getActNo(const cContextInstance* pInst, const cContextCharacter* pChara, u32 idx) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstChar::DTI)) {
        return static_cast<const cContextInstChar*>(pInst)->getActNo(idx);
    }
    return 0xFFFFFFFF;
}

__attribute__((weak)) void cContextInterface::setActNo(cContextInstance* pInst, cContextCharacter* pChara, u32 idx, u32 no) {
    DDON_STUB("cContextInterface::setActNo")
    /* stub */
}

u8 cContextInterface::getActReqPrio(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstChar::DTI)) {
        return static_cast<const cContextInstChar*>(pInst)->getActReqPrio();
    }
    return 1;
}

void cContextInterface::setActReqPrio(cContextInstance* pInst, cContextCharacter* pChara, u8 prio) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mActReqPrio = prio;
                return;
            }
        }
    }
}

u32 cContextInterface::getActFreeWork(const cContextInstance* pInst, const cContextCharacter* pChara) {
    u32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                const cContextInstChar* pInstChar = static_cast<const cContextInstChar*>(pInst);
                v2_7 = static_cast<const cContextInstChar*>(pInst)->getActFreeWork();
                return v2_7;
            }
        }
        v2_7 = 0;
    }
    return v2_7;
}

void cContextInterface::setActFreeWork(cContextInstance* pInst, cContextCharacter* pChara, u32 work) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mActFreeWork = work;
                return;
            }
        }
    }
}

u64 cContextInterface::getAttackParamUIDForDmVec(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getAttackParamUIDForDmVec();
    } else {
        return 0;
    }
}

void cContextInterface::setAttackParamUIDForDmVec(cContextInstance* pInst, cContextCharacter* pChara, u64 uID) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mAttackParamUIDForDmVec = uID;
}

f32 cContextInterface::getMoveSpeed(const cContextInstance* pInst, const cContextCharacter* pChara) {
    f32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0.0f;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_7 = 0.0f;
                    return v2_7;
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        const cContextInstChar* pInstChar = static_cast<const cContextInstChar*>(pInst);
        v2_7 = static_cast<const cContextInstChar*>(pInst)->getMoveSpeed();
    }
    return v2_7;
}

void cContextInterface::setMoveSpeed(cContextInstance* pInst, cContextCharacter* pChara, f32 speed) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mMoveSpeed = speed;
                return;
            }
        }
    }
}

f32 cContextInterface::getMoveAngle(const cContextInstance* pInst, const cContextCharacter* pChara) {
    f32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0.0f;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_7 = 0.0f;
                    return v2_7;
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        v2_7 = static_cast<const cContextInstChar*>(pInst)->getMoveAngle();
    }
    return v2_7;
}

void cContextInterface::setMoveAngle(cContextInstance* pInst, cContextCharacter* pChara, f32 angle) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mMoveAngle = angle;
                return;
            }
        }
    }
}

__attribute__((weak)) MtVector3 cContextInterface::getCliffPos(const cContextInstance* pInst, const cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::getCliffPos")
    __builtin_unreachable();
}

void cContextInterface::setCliffPos(cContextInstance* pInst, cContextCharacter* pChara, const MtVector3& pos) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cContextInstChar*>(pInst)->setCliffPos(pos);
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
}

const nNetMsgData::stNetPos& cContextInterface::getCliffRealPos(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                return static_cast<const cContextInstChar*>(pInst)->mCliffPos;
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
    return NetPosZero;
}

const MtVector3& cContextInterface::getCliffNormal(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                return static_cast<const cContextInstChar*>(pInst)->mCliffNormal;
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
    return MtVector3::AxisZ;
}

void cContextInterface::setCliffNormal(cContextInstance* pInst, cContextCharacter* pChara, const MtVector3& vec) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                cContextInstChar* pInstChar = static_cast<cContextInstChar*>(pInst);
                pInstChar->mCliffNormal.x = vec.x;
                pInstChar->mCliffNormal.y = vec.y;
                pInstChar->mCliffNormal.z = vec.z;
                static_cast<cContextInstChar*>(pInst)->mCliffNormal.pad_ = 0.0f;
                return;
            }
        }
    }
}

__attribute__((weak)) MtVector3 cContextInterface::getCliffStartPos(const cContextInstance* pInst, const cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::getCliffStartPos")
    __builtin_unreachable();
}

void cContextInterface::setCliffStartPos(cContextInstance* pInst, cContextCharacter* pChara, const MtVector3& pos) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cContextInstChar*>(pInst)->setCliffStartPos(pos);
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
}

const nNetMsgData::stNetPos& cContextInterface::getCliffStartRealPos(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                return static_cast<const cContextInstChar*>(pInst)->mCliffStartPos;
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
    return NetPosZero;
}

__attribute__((weak)) MtVector3 cContextInterface::getCliffStartOldPos(const cContextInstance* pInst, const cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::getCliffStartOldPos")
    __builtin_unreachable();
}

void cContextInterface::setCliffStartOldPos(cContextInstance* pInst, cContextCharacter* pChara, const MtVector3& pos) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cContextInstChar*>(pInst)->setCliffStartOldPos(pos);
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
}

const nNetMsgData::stNetPos& cContextInterface::getCliffStartOldRealPos(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                return static_cast<const cContextInstChar*>(pInst)->mCliffStartOldPos;
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
    return NetPosZero;
}

__attribute__((weak)) MtVector3 cContextInterface::getWallClimbPos(const cContextInstance* pInst, const cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::getWallClimbPos")
    __builtin_unreachable();
}

void cContextInterface::setWallClimbPos(cContextInstance* pInst, cContextCharacter* pChara, const MtVector3& pos) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cContextInstChar*>(pInst)->setWallClimbPos(pos);
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
}

const nNetMsgData::stNetPos& cContextInterface::getWallClimbRealPos(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                return static_cast<const cContextInstChar*>(pInst)->mWallClimbPos;
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
    return NetPosZero;
}

const MtVector3& cContextInterface::getWallClimbNormal(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                return static_cast<const cContextInstChar*>(pInst)->mWallClimbNormal;
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
    return MtVector3::Zero;
}

void cContextInterface::setWallClimbNormal(cContextInstance* pInst, cContextCharacter* pChara, const MtVector3& pos) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                cContextInstChar* pInstChar = static_cast<cContextInstChar*>(pInst);
                pInstChar->mWallClimbNormal.x = pos.x;
                pInstChar->mWallClimbNormal.y = pos.y;
                pInstChar->mWallClimbNormal.z = pos.z;
                static_cast<cContextInstChar*>(pInst)->mWallClimbNormal.pad_ = 0.0f;
                return;
            }
        }
    }
}

__attribute__((weak)) MtVector3 cContextInterface::getWallClimbLandPos(const cContextInstance* pInst, const cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::getWallClimbLandPos")
    __builtin_unreachable();
}

void cContextInterface::setWallClimbLandPos(cContextInstance* pInst, cContextCharacter* pChara, const MtVector3& pos) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cContextInstChar*>(pInst)->setWallClimbLandPos(pos);
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
}

const nNetMsgData::stNetPos& cContextInterface::getWallClimbLandRealPos(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                return static_cast<const cContextInstChar*>(pInst)->mWallClimbLandPos;
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
    return NetPosZero;
}

u32 cContextInterface::getTargetUid(const cContextInstance* pInst, const cContextCharacter* pChara) {
    u32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                v2_7 = static_cast<const cContextInstChar*>(pInst)->getTargetUid();
                return v2_7;
            }
        }
        v2_7 = 0;
    }
    return v2_7;
}

void cContextInterface::setTargetUid(cContextInstance* pInst, cContextCharacter* pChara, const u32 uid) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mTargetUid = uid;
                return;
            }
        }
    }
}

__attribute__((weak)) MtVector3 cContextInterface::getTargetPos(const cContextInstance* pInst, const cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::getTargetPos")
    __builtin_unreachable();
}

void cContextInterface::setTargetPos(cContextInstance* pInst, cContextCharacter* pChara, const MtVector3& pos) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cContextInstChar*>(pInst)->setTargetPos(pos);
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
}

const nNetMsgData::stNetPos& cContextInterface::getTargetRealPos(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                return static_cast<const cContextInstChar*>(pInst)->mTargetPos;
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
    return NetPosZero;
}

__attribute__((weak)) void cContextInterface::setActExParam(cContextInstance* pInst, cContextCharacter* pChara, u32 idx, const nActionManager::stActExParam* pSrc) {
    DDON_STUB("cContextInterface::setActExParam")
    /* stub */
}

u32 cContextInterface::getClimbEnemyUId(const cContextInstance* pInst, const cContextCharacter* pChara) {
    u32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                v2_7 = static_cast<const cContextInstChar*>(pInst)->getClimbEnemyUId();
                return v2_7;
            }
        }
        v2_7 = 0;
    }
    return v2_7;
}

void cContextInterface::setClimbEnemyUId(cContextInstance* pInst, cContextCharacter* pChara, u32 no) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mClimbEnemyUId = no;
                return;
            }
        }
    }
}

s32 cContextInterface::getClimbEnemyJointNo(const cContextInstance* pInst, const cContextCharacter* pChara) {
    s32 v2_7;
    if (pInst == nullptr) {
        v2_7 = -1;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                const cContextInstChar* pInstChar = static_cast<const cContextInstChar*>(pInst);
                v2_7 = static_cast<const cContextInstChar*>(pInst)->getClimbEnemyJointNo();
                return v2_7;
            }
        }
        v2_7 = -1;
    }
    return v2_7;
}

void cContextInterface::setClimbEnemyJointNo(cContextInstance* pInst, cContextCharacter* pChara, s32 no) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mClimbEnemyJointNo = no;
                return;
            }
        }
    }
}

const MtVector3& cContextInterface::getClimbEnemyJointOffset(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                return static_cast<const cContextInstChar*>(pInst)->mClimbEnemyJointOffset;
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
    return MtVector3::Zero;
}

void cContextInterface::setClimbEnemyJointOffset(cContextInstance* pInst, cContextCharacter* pChara, const MtVector3& offset) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                cContextInstChar* pInstChar = static_cast<cContextInstChar*>(pInst);
                pInstChar->mClimbEnemyJointOffset.x = offset.x;
                pInstChar->mClimbEnemyJointOffset.y = offset.y;
                pInstChar->mClimbEnemyJointOffset.z = offset.z;
                static_cast<cContextInstChar*>(pInst)->mClimbEnemyJointOffset.pad_ = 0.0f;
                return;
            }
        }
    }
}

u16 cContextInterface::getClimbNodeIndex(const cContextInstance* pInst, const cContextCharacter* pChara) {
    u16 v2_0;
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                v2_0 = static_cast<const cContextInstChar*>(pInst)->getClimbNodeIndex();
                return v2_0;
            }
        }
        v2_0 = 0;
    } else {
        v2_0 = 0;
    }
    return v2_0;
}

void cContextInterface::setClimbNodeIndex(cContextInstance* pInst, cContextCharacter* pChara, u16 NodeIndex) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mClimbEnemyNodeIndex = NodeIndex;
                return;
            }
        }
    }
}

u16 cContextInterface::getClimbGeomIndex(const cContextInstance* pInst, const cContextCharacter* pChara) {
    u16 v2_0;
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                const cContextInstChar* pInstChar = static_cast<const cContextInstChar*>(pInst);
                v2_0 = static_cast<const cContextInstChar*>(pInst)->getClimbGeomIndex();
                return v2_0;
            }
        }
        v2_0 = 0;
    } else {
        v2_0 = 0;
    }
    return v2_0;
}

void cContextInterface::setClimbGeomIndex(cContextInstance* pInst, cContextCharacter* pChara, u16 GeomIndex) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mClimbEnemyGeomIndex = GeomIndex;
                return;
            }
        }
    }
}

__attribute__((weak)) bool cContextInterface::isDead(const cContextInstance* pInst, const cContextCharacter* pChara, u32 i) {
    DDON_STUB("cContextInterface::isDead")
    return {};
}

void cContextInterface::setIsDead(cContextInstance* pInst, cContextCharacter* pChara, bool isDead, u32 i) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cContextInstChar*>(pInst)->setIsDead(isDead, i);
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
}

bool cContextInterface::isInjured(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstChar::DTI)) {
        return static_cast<const cContextInstChar*>(pInst)->isInjured();
    }
    return false;
}

void cContextInterface::setIsInjured(cContextInstance* pInst, cContextCharacter* pChara, const bool flg) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                cContextInstChar* pInstChar = static_cast<cContextInstChar*>(pInst);
                pInstChar->mIsInjured = flg;
                return;
            }
        }
    }
}

void cContextInterface::setIsLost(cContextInstance* pInst, cContextCharacter* pChara, const bool flg) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                cContextInstChar* pInstChar = static_cast<cContextInstChar*>(pInst);
                pInstChar->mIsLost = flg;
                return;
            }
        }
    }
}

bool cContextInterface::isRescue(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstChar::DTI)) {
        return static_cast<const cContextInstChar*>(pInst)->isRescue();
    }
    return false;
}

void cContextInterface::setIsRescue(cContextInstance* pInst, cContextCharacter* pChara, const bool flg) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                cContextInstChar* pInstChar = static_cast<cContextInstChar*>(pInst);
                pInstChar->mIsRescue = flg;
                return;
            }
        }
    }
}

__attribute__((weak)) HP_DATATYPE cContextInterface::getHp(const cContextInstance* pInst, const cContextCharacter* pChara, u32 i) {
    DDON_STUB("cContextInterface::getHp")
    return {};
}

__attribute__((weak)) void cContextInterface::setHp(cContextInstance* pInst, cContextCharacter* pChara, HP_DATATYPE hp, u32 i) {
    DDON_STUB("cContextInterface::setHp")
    /* stub */
}

__attribute__((weak)) HP_DATATYPE cContextInterface::getHpMax(const cContextInstance* pInst, const cContextCharacter* pChara, u32 i) {
    DDON_STUB("cContextInterface::getHpMax")
    return {};
}

void cContextInterface::setHpMax(cContextInstance* pInst, cContextCharacter* pChara, HP_DATATYPE hp, u32 i) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cContextInstChar*>(pInst)->setHpMax(hp, i);
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
}

bool cContextInterface::getIsDeadCheatCheck(const cContextInstance* pInst, const cContextCharacter* pChara, u32 i) {
    bool v2_0;
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                v2_0 = static_cast<const cContextInstChar*>(pInst)->getIsDeadCheatCheck(i);
                return v2_0;
            }
        }
        v2_0 = false;
    } else {
        v2_0 = false;
    }
    return v2_0;
}

HP_DATATYPE cContextInterface::getHpCheatCheck(const cContextInstance* pInst, const cContextCharacter* pChara, u32 i) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                return static_cast<const cContextInstChar*>(pInst)->getHpCheatCheck(i);
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
    return 0;
}

__attribute__((weak)) HP_DATATYPE cContextInterface::getHpMaxCheatCheck(const cContextInstance* pInst, const cContextCharacter* pChara, u32 i) {
    DDON_STUB("cContextInterface::getHpMaxCheatCheck")
    return {};
}

bool cContextInterface::isHpMax_calc(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstChar::DTI)) {
        return static_cast<const cContextInstChar*>(pInst)->isHpMax_calc();
    }
    return false;
}

void cContextInterface::setHpMax_calc(cContextInstance* pInst, cContextCharacter* pChara, bool flag) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                cContextInstChar* pInstChar = static_cast<cContextInstChar*>(pInst);
                pInstChar->mIsHpMax_calc_pri = flag;
                return;
            }
        }
    }
}

HP_DATATYPE cContextInterface::getHpWhite(const cContextInstance* pInst, const cContextCharacter* pChara) {
    HP_DATATYPE v2_0;
    if (pInst == nullptr) {
        v2_0 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_0 = 0;
                    return v2_0;
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        v2_0 = static_cast<const cContextInstChar*>(pInst)->getHpWhite();
    }
    return v2_0;
}

void cContextInterface::setHpWhite(cContextInstance* pInst, cContextCharacter* pChara, HP_DATATYPE hp) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mHpWhite_pri = hp;
                return;
            }
        }
    }
}

void cContextInterface::setStamina(cContextInstance* pInst, cContextCharacter* pChara, f32 stamina) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mPlayerInfo.mBaseInfo.mStamina_pri = stamina;
                if (stamina > static_cast<cContextInstHm*>(pInst)->mPlayerInfo.getFinalMaxStamina()) {
                    static_cast<cContextInstHm*>(pInst)->mPlayerInfo.mBaseInfo.mStamina_pri = static_cast<cContextInstHm*>(pInst)->mPlayerInfo.getFinalMaxStamina();
                    if (0.0f > static_cast<cContextInstHm*>(pInst)->mPlayerInfo.mBaseInfo.mStamina_pri) {
                        static_cast<cContextInstHm*>(pInst)->mPlayerInfo.mBaseInfo.mStamina_pri = 0.0f;
                    }
                } else {
                    if (0.0f > stamina) {
                        static_cast<cContextInstHm*>(pInst)->mPlayerInfo.mBaseInfo.mStamina_pri = 0.0f;
                    }
                }
                return;
            }
        }
    }
}

u16 cContextInterface::getUseRegionBit(const cContextInstance* pInst, const cContextCharacter* pChara) {
    u16 v2_0;
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                const cContextInstChar* pInstChar = static_cast<const cContextInstChar*>(pInst);
                v2_0 = static_cast<const cContextInstChar*>(pInst)->getUseRegionBit();
                return v2_0;
            }
        }
        v2_0 = 0;
    } else {
        v2_0 = 0;
    }
    return v2_0;
}

void cContextInterface::setUseRegionBit(cContextInstance* pInst, cContextCharacter* pChara, u16 useRegionBit) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mUseRegionBit_pri = useRegionBit;
                return;
            }
        }
    }
}

__attribute__((weak)) s32 cContextInterface::getLv(const cContextInstance* pInst, const cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::getLv")
    return {};
}

void cContextInterface::setLv(cContextInstance* pInst, cContextCharacter* pChara, s32 lv) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mLv_pri = lv;
                return;
            }
        }
    }
}

f32 cContextInterface::getShakeEndurance(const cContextInstance* pInst, const cContextCharacter* pChara) {
    f32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0.0f;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_7 = 0.0f;
                    return v2_7;
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        const cContextInstChar* pInstChar = static_cast<const cContextInstChar*>(pInst);
        v2_7 = static_cast<const cContextInstChar*>(pInst)->getShakeEndurance();
    }
    return v2_7;
}

void cContextInterface::setShakeEndurance(cContextInstance* pInst, cContextCharacter* pChara, f32 endurance) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mShakeEndurance = endurance;
                return;
            }
        }
    }
}

f32 cContextInterface::getRageShrinkEndurance(const cContextInstance* pInst, const cContextCharacter* pChara) {
    f32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0.0f;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_7 = 0.0f;
                    return v2_7;
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        v2_7 = static_cast<const cContextInstChar*>(pInst)->getRageShrinkEndurance();
    }
    return v2_7;
}

void cContextInterface::setRageShrinkEndurance(cContextInstance* pInst, cContextCharacter* pChara, f32 endurance) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mRageShrinkEndurance = endurance;
                return;
            }
        }
    }
}

u32 cContextInterface::getOcdActiveMsgNum(const cContextInstance* pInst, const cContextCharacter* pChara) {
    u32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                v2_7 = static_cast<const cContextInstChar*>(pInst)->getOcdActiveMsgNum();
                return v2_7;
            }
        }
        v2_7 = 0;
    }
    return v2_7;
}

__attribute__((weak)) const nObjCondition::stOcdActiveMsg& cContextInterface::getOcdActiveMsg(const cContextInstance* pInst, const cContextCharacter* pChara, u32 index) {
    DDON_STUB("cContextInterface::getOcdActiveMsg")
    __builtin_unreachable();
}

void cContextInterface::makeOcdMsgArray(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cContextInstChar*>(pInst)->makeOcdMsgArray();
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
}

__attribute__((weak)) const nObjCondition::stOcdActiveData& cContextInterface::getOcdActiveData(const cContextInstance* pInst, const cContextCharacter* pChara, u32 OcdUID) {
    DDON_STUB("cContextInterface::getOcdActiveData")
    __builtin_unreachable();
}

__attribute__((weak)) const nObjCondition::stOcdActiveData& cContextInterface::getOcdActiveData(const cContextInstance* pInst, const cContextCharacter* pChara, u32 bank, u32 index) {
    DDON_STUB("cContextInterface::getOcdActiveData")
    __builtin_unreachable();
}

void cContextInterface::setOcdActiveData(cContextInstance* pInst, cContextCharacter* pChara, u32 OcdUID, const nObjCondition::stOcdActiveData& data, bool isTimerReset) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cContextInstChar*>(pInst)->setOcdActiveData(OcdUID, data, isTimerReset);
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
}

void cContextInterface::setOcdActiveData(cContextInstance* pInst, cContextCharacter* pChara, u32 bank, u32 index, const nObjCondition::stOcdActiveData& data, bool isTimerReset) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cContextInstChar*>(pInst)->setOcdActiveData(bank, index, data, isTimerReset);
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
}

void cContextInterface::setOcdActiveTimer(cContextInstance* pInst, cContextCharacter* pChara, u32 OcdUID, f32 timer) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cContextInstChar*>(pInst)->setOcdActiveTimer(OcdUID, timer);
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
}

void cContextInterface::setOcdActiveTimer(cContextInstance* pInst, cContextCharacter* pChara, u32 bank, u32 index, f32 timer) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cContextInstChar*>(pInst)->setOcdActiveTimer(bank, index, timer);
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
}

f32 cContextInterface::getOcdActiveTimer(const cContextInstance* pInst, const cContextCharacter* pChara, u32 OcdUID) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                return static_cast<const cContextInstChar*>(pInst)->getOcdActiveTimer(OcdUID);
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
    return 0.0f;
}

void cContextInterface::setOcdAllTimerResetFlag(cContextInstance* pInst, cContextCharacter* pChara, bool flag) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cContextInstChar*>(pInst)->setOcdAllTimerResetFlag(flag);
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
}

bool cContextInterface::isOcdAllTimerReset(const cContextInstance* pInst, const cContextCharacter* pChara) {
    bool v2_0;
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                v2_0 = static_cast<const cContextInstChar*>(pInst)->isOcdAllTimerReset();
                return v2_0;
            }
        }
        v2_0 = false;
    } else {
        v2_0 = false;
    }
    return v2_0;
}

bool cContextInterface::isOcdTimerReset(const cContextInstance* pInst, const cContextCharacter* pChara, u32 OcdUID) {
    bool v2_0;
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                v2_0 = static_cast<const cContextInstChar*>(pInst)->isOcdTimerReset(OcdUID);
                return v2_0;
            }
        }
        v2_0 = false;
    } else {
        v2_0 = false;
    }
    return v2_0;
}

void cContextInterface::resetOcdTimerReset(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cContextInstChar*>(pInst)->resetOcdTimerReset();
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
}

void cContextInterface::resetOcdActiveDataAll(cContextInstance* pInst, cContextCharacter* pChara, bool isImmuneReset) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cContextInstChar*>(pInst)->resetOcdActiveDataAll(isImmuneReset);
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
}

void cContextInterface::resetOcdActiveDataGoodStatus(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cContextInstChar*>(pInst)->resetOcdActiveDataGoodStatus();
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
}

bool cContextInterface::isOcdActive(const cContextInstance* pInst, const cContextCharacter* pChara, u32 OcdUID) {
    bool v2_0;
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                v2_0 = static_cast<const cContextInstChar*>(pInst)->isOcdActive(OcdUID);
                return v2_0;
            }
        }
        v2_0 = false;
    } else {
        v2_0 = false;
    }
    return v2_0;
}

bool cContextInterface::isPlayer(const cContextInstHm* pInst) {
    return (pInst != nullptr) && (pInst->mHumanType == 0);
}

bool cContextInterface::isPawn(const cContextInstance* pInst) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                if (static_cast<const cContextInstHm*>(pInst)->mHumanType == 1) {
                    return true;
                } else {
                    break;
                }
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
    return false;
}

bool cContextInterface::isPawn(const cContextInstHm* pInst) {
    return (pInst != nullptr) && (pInst->mHumanType == 1);
}

bool cContextInterface::isNpc(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstNpc::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                return true;
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
    return false;
}

f32 cContextInterface::getEnchantRate(const cContextInstance* pInst, const cContextCharacter* pChara) {
    f32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0.0f;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_7 = 0.0f;
                    return v2_7;
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        const cContextInstChar* pInstChar = static_cast<const cContextInstChar*>(pInst);
        v2_7 = static_cast<const cContextInstChar*>(pInst)->getEnchantRate();
    }
    return v2_7;
}

void cContextInterface::setEnchantRate(cContextInstance* pInst, cContextCharacter* pChara, f32 rate) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mEnchantRate = rate;
                return;
            }
        }
    }
}

f32 cContextInterface::getAilmentDamage(const cContextInstance* pInst, const cContextCharacter* pChara) {
    f32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0.0f;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_7 = 0.0f;
                    return v2_7;
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        v2_7 = static_cast<const cContextInstChar*>(pInst)->getAilmentDamage();
    }
    return v2_7;
}

void cContextInterface::setAilmentDamage(cContextInstance* pInst, cContextCharacter* pChara, f32 ailment) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mAilmentDamage = ailment;
                return;
            }
        }
    }
}

f32 cContextInterface::getAttackBasePhys(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getAttackBasePhys();
    } else {
        return 0.0f;
    }
}

void cContextInterface::setAttackBasePhys(cContextInstance* pInst, cContextCharacter* pChara, f32 attack) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mAttackBasePhys = attack;
}

f32 cContextInterface::getAttackBaseMagic(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getAttackBaseMagic();
    } else {
        return 0.0f;
    }
}

void cContextInterface::setAttackBaseMagic(cContextInstance* pInst, cContextCharacter* pChara, f32 attack) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mAttackBaseMagic = attack;
}

f32 cContextInterface::getAttackWepPhys(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getAttackWepPhys();
    } else {
        return 0.0f;
    }
}

void cContextInterface::setAttackWepPhys(cContextInstance* pInst, cContextCharacter* pChara, f32 attack) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mAttackWepPhys = attack;
}

f32 cContextInterface::getAttackWepMagic(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getAttackWepMagic();
    } else {
        return 0.0f;
    }
}

void cContextInterface::setAttackWepMagic(cContextInstance* pInst, cContextCharacter* pChara, f32 attack) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mAttackWepMagic = attack;
}

f32 cContextInterface::getDefenceBasePhys(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getDefenceBasePhys();
    } else {
        return 0.0f;
    }
}

void cContextInterface::setDefenceBasePhys(cContextInstance* pInst, cContextCharacter* pChara, f32 deffence) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mDefenceBasePhys = deffence;
}

f32 cContextInterface::getDefenceBaseMagic(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getDefenceBaseMagic();
    } else {
        return 0.0f;
    }
}

void cContextInterface::setDefenceBaseMagic(cContextInstance* pInst, cContextCharacter* pChara, f32 deffence) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mDefenceBaseMagic = deffence;
}

f32 cContextInterface::getDefenceWepPhys(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getDefenceWepPhys();
    } else {
        return 0.0f;
    }
}

void cContextInterface::setDefenceWepPhys(cContextInstance* pInst, cContextCharacter* pChara, f32 deffence) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mDefenceWepPhys = deffence;
}

f32 cContextInterface::getDefenceWepMagic(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getDefenceWepMagic();
    } else {
        return 0.0f;
    }
}

void cContextInterface::setDefenceWepMagic(cContextInstance* pInst, cContextCharacter* pChara, f32 deffence) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mDefenceWepMagic = deffence;
}

f32 cContextInterface::getPower(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getPower();
    } else {
        return 0.0f;
    }
}

void cContextInterface::setPower(cContextInstance* pInst, cContextCharacter* pChara, f32 power) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mPower = power;
}

f32 cContextInterface::getWeight(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getWeight();
    } else {
        return 0.0f;
    }
}

void cContextInterface::setWeight(cContextInstance* pInst, cContextCharacter* pChara, f32 weight) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mWeight = weight;
}

f32 cContextInterface::getShrinkWep(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getShrinkWep();
    } else {
        return 0.0f;
    }
}

void cContextInterface::setShrinkWep(cContextInstance* pInst, cContextCharacter* pChara, f32 shrink) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mShrinkWep = shrink;
}

f32 cContextInterface::getBlowWep(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getBlowWep();
    } else {
        return 0.0f;
    }
}

void cContextInterface::setBlowWep(cContextInstance* pInst, cContextCharacter* pChara, f32 blow) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mBlowWep = blow;
}

f32 cContextInterface::getDownBase(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getDownBase();
    } else {
        return 0.0f;
    }
}

void cContextInterface::setDownBase(cContextInstance* pInst, cContextCharacter* pChara, f32 down) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mDownBase = down;
}

f32 cContextInterface::getDownWep(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getDownWep();
    } else {
        return 0.0f;
    }
}

void cContextInterface::setDownWep(cContextInstance* pInst, cContextCharacter* pChara, f32 down) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mDownWep = down;
}

f32 cContextInterface::getShakeBase(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getShakeBase();
    } else {
        return 0.0f;
    }
}

void cContextInterface::setShakeBase(cContextInstance* pInst, cContextCharacter* pChara, f32 shake) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mShakeBase = shake;
}

void cContextInterface::setGuardAttackBase(cContextInstance* pInst, cContextCharacter* pChara, f32 guard) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mGuardAttackBase = guard;
}

f32 cContextInterface::getGuardDefenceBase(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getGuardDefenceBase();
    } else {
        return 0.0f;
    }
}

void cContextInterface::setGuardDefenceBase(cContextInstance* pInst, cContextCharacter* pChara, f32 guard) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mGuardDefenceBase = guard;
}

f32 cContextInterface::getGuardDefenceWep(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getGuardDefenceWep();
    } else {
        return 0.0f;
    }
}

void cContextInterface::setGuardDefenceWep(cContextInstance* pInst, cContextCharacter* pChara, f32 guard) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mGuardDefenceWep = guard;
}

u32 cContextInterface::getWeaponTypeSe(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getWeaponTypeSe();
    } else {
        return 0xFFFFFFFF;
    }
}

void cContextInterface::setWeaponTypeSe(cContextInstance* pInst, cContextCharacter* pChara, u32 type) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mWeaponTypeSe = type;
}

u32 cContextInterface::getBodySize(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getBodySize();
    } else {
        return 1;
    }
}

void cContextInterface::setBodySize(cContextInstance* pInst, cContextCharacter* pChara, u32 size) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mBodySize = size;
}

bool cContextInterface::isServerDamage(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->isServerDamage();
    } else {
        return false;
    }
}

void cContextInterface::setIsServerDamage(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mIsServerDamaged = true;
}

void cContextInterface::clrIsServerDamage(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mIsServerDamaged = false;
}

const cDamageMsg* cContextInterface::getServerDamageMsgTop(const cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getServerDamageMsgTop();
    } else {
        return nullptr;
    }
}

void cContextInterface::eraseServerDamageMsgTop(const cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->eraseServerDamageMsgTop();
}

__attribute__((weak)) u32 cContextInterface::getServerDamageMsgNum(cContextInstance* pInst, cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::getServerDamageMsgNum")
    return {};
}

void cContextInterface::addServerDamageMsg(cContextInstance* pInst, cContextCharacter* pChara, const cDamageMsg* pMsg) {
    if (pChara == nullptr) {
        return;
    }
    pChara->addServerDamageMsg(pMsg);
}

bool cContextInterface::isSlaveDamage(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->isSlaveDamage();
    } else {
        return false;
    }
}

void cContextInterface::setIsSlaveDamage(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mIsSlaveDamaged = true;
}

void cContextInterface::clrIsSlaveDamage(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mIsSlaveDamaged = false;
}

const cDamageMsg* cContextInterface::getDamageMsgTop(const cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getDamageMsgTop();
    } else {
        return nullptr;
    }
}

void cContextInterface::eraseDamageMsgTop(const cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->eraseDamageMsgTop();
}

__attribute__((weak)) u32 cContextInterface::getDamageMsgNum(cContextInstance* pInst, cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::getDamageMsgNum")
    return {};
}

void cContextInterface::addDamageMsg(cContextInstance* pInst, cContextCharacter* pChara, const cDamageMsg* pMsg) {
    if (pChara == nullptr) {
        return;
    }
    pChara->addDamageMsg(pMsg);
}

u16 cContextInterface::getActAtkAdjustUniqueId(const cContextInstance* pInst, const cContextCharacter* pChara) {
    u16 v2_0;
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                v2_0 = static_cast<const cContextInstChar*>(pInst)->getActAtkAdjustUniqueId();
                return v2_0;
            }
        }
        v2_0 = 0;
    } else {
        v2_0 = 0;
    }
    return v2_0;
}

void cContextInterface::setActAtkAdjustUniqueId(cContextInstance* pInst, cContextCharacter* pChara, u16 uid) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mActAtkAdjustUniqueId = uid;
                return;
            }
        }
    }
}

bool cContextInterface::isCatchHit(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->isCatchHit();
    } else {
        return false;
    }
}

void cContextInterface::setIsCatchHit(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mIsCatchHit = true;
}

void cContextInterface::clrIsCatchHit(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mIsCatchHit = false;
}

bool cContextInterface::isCaughtResult(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->isCaughtResult();
    } else {
        return false;
    }
}

void cContextInterface::setIsCaughtResult(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mIsCaughtResult = true;
}

void cContextInterface::clrIsCaughtResult(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mIsCaughtResult = false;
}

u8 cContextInterface::getCatchType(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pInst != nullptr) {
        return pInst->getCatchType();
    } else {
        return 0;
    }
}

void cContextInterface::setCatchType(cContextInstance* pInst, cContextCharacter* pChara, u8 type) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mCatchType = type;
}

u8 cContextInterface::getCatchJointNo(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pInst != nullptr) {
        return pInst->mCatchJointNo;
    } else {
        return 0;
    }
}

void cContextInterface::setCatchJointNo(cContextInstance* pInst, cContextCharacter* pChara, u8 no) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mCatchJointNo = no;
}

u32 cContextInterface::getCatchTargetUID(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pInst != nullptr) {
        return pInst->getCatchTargetUID();
    } else {
        return 0;
    }
}

void cContextInterface::setCatchTargetUID(cContextInstance* pInst, cContextCharacter* pChara, u32 uid) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mCatchTargetUid = uid;
}

__attribute__((weak)) MtVector3 cContextInterface::getCatchHitPos(const cContextInstance* pInst, const cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::getCatchHitPos")
    __builtin_unreachable();
}

void cContextInterface::setCatchHitPos(cContextInstance* pInst, cContextCharacter* pChara, MtVector3& vec) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mCatchHitPos.x = vec.x;
    pChara->mCatchHitPos.y = vec.y;
    pChara->mCatchHitPos.z = vec.z;
    pChara->mCatchHitPos.pad_ = 0.0f;
}

bool cContextInterface::getIsOmReleaseThrow(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getIsOmReleaseThrow();
    } else {
        return false;
    }
}

void cContextInterface::setIsOmReleaseThrow(cContextInstance* pInst, cContextCharacter* pChara, bool isOmReleaseThrow) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mIsOmReleaseThrow = isOmReleaseThrow;
}

bool cContextInterface::getIsOmReleasePut(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getIsOmReleasePut();
    } else {
        return false;
    }
}

void cContextInterface::setIsOmReleasePut(cContextInstance* pInst, cContextCharacter* pChara, bool isOmReleasePut) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mIsOmReleasePut = isOmReleasePut;
}

const nNetMsgData::stNetPos& cContextInterface::getOmReleaseRealPos(const cContextInstance* pInst, const cContextCharacter* pChara) {
    return *((pChara == nullptr) ? (&NetPosZero) : (&pChara->mOmReleasePos));
}

__attribute__((weak)) MtVector3 cContextInterface::getOmReleasePos(const cContextInstance* pInst, const cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::getOmReleasePos")
    __builtin_unreachable();
}

void cContextInterface::setOmReleasePos(cContextInstance* pInst, cContextCharacter* pChara, const MtVector3& pos) {
    if (pChara == nullptr) {
        return;
    }
    pChara->setOmReleasePos(pos);
}

f32 cContextInterface::getOmReleaseAngle(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getOmReleaseAngle();
    } else {
        return 0.0f;
    }
}

void cContextInterface::setOmReleaseAngle(cContextInstance* pInst, cContextCharacter* pChara, f32 angle) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mOmReleaseAngle = angle;
}

__attribute__((weak)) MtQuaternion cContextInterface::getOmReleaseQuat(const cContextInstance* pInst, const cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::getOmReleaseQuat")
    __builtin_unreachable();
}

__attribute__((weak)) void cContextInterface::setOmReleaseQuat(cContextInstance* pInst, cContextCharacter* pChara, const MtQuaternion& quat) {
    DDON_STUB("cContextInterface::setOmReleaseQuat")
    /* stub */
}

f32 cContextInterface::getLostTimer(const cContextInstance* pInst, const cContextCharacter* pChara) {
    f32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0.0f;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_7 = 0.0f;
                    return v2_7;
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        const cContextInstHm* pInstHm = static_cast<const cContextInstHm*>(pInst);
        v2_7 = static_cast<const cContextInstHm*>(pInst)->getLostTime();
    }
    return v2_7;
}

void cContextInterface::setLostTimer(cContextInstance* pInst, cContextCharacter* pChara, f32 time) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mLostTime = time;
                return;
            }
        }
    }
}

void cContextInterface::subLostTimer(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cContextInstHm*>(pInst)->subLostTime();
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
}

bool cContextInterface::isIsInstantDead(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->isIsInstantDead();
    } else {
        return false;
    }
}

void cContextInterface::setIsInstantDead(cContextInstance* pInst, cContextCharacter* pChara, bool b) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mIsInstantDead = b;
}

u32 cContextInterface::getShlDelte(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getShlDelte();
    } else {
        return 0;
    }
}

void cContextInterface::setShlDelte(cContextInstance* pInst, cContextCharacter* pChara, u32 bit) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mShlDelete = bit;
}

u32 cContextInterface::getShlNetSts(const cContextInstance* pInst, const cContextCharacter* pChara, u32 index) {
    if (pChara != nullptr) {
        return pChara->getShlNetSts(index);
    } else {
        return 0;
    }
}

__attribute__((weak)) bool cContextInterface::isShlNetSts(const cContextInstance* pInst, const cContextCharacter* pChara, u32 sts, u32 index) {
    DDON_STUB("cContextInterface::isShlNetSts")
    return {};
}

__attribute__((weak)) void cContextInterface::setShlNetSts(cContextInstance* pInst, cContextCharacter* pChara, u32 sts, u32 index) {
    DDON_STUB("cContextInterface::setShlNetSts")
    /* stub */
}

u32 cContextInterface::getShlUniqueId(const cContextInstance* pInst, const cContextCharacter* pChara, u32 index) {
    if (pChara != nullptr) {
        return pChara->getShlUniqueId(index);
    } else {
        return 0;
    }
}

__attribute__((weak)) void cContextInterface::setShlUniqueId(cContextInstance* pInst, cContextCharacter* pChara, u32 uid, u32 index) {
    DDON_STUB("cContextInterface::setShlUniqueId")
    /* stub */
}

u32 cContextInterface::getShlTargetUId(const cContextInstance* pInst, const cContextCharacter* pChara, u32 index) {
    if (pChara != nullptr) {
        return pChara->getShlTargetUId(index);
    } else {
        return 0;
    }
}

__attribute__((weak)) void cContextInterface::setShlTargetUId(cContextInstance* pInst, cContextCharacter* pChara, u32 uid, u32 index) {
    DDON_STUB("cContextInterface::setShlTargetUId")
    /* stub */
}

s32 cContextInterface::getShlGroup(const cContextInstance* pInst, const cContextCharacter* pChara, u32 index) {
    if (pChara != nullptr) {
        return pChara->getShlGroup(index);
    } else {
        return -1;
    }
}

__attribute__((weak)) void cContextInterface::setShlGroup(cContextInstance* pInst, cContextCharacter* pChara, s32 group, u32 index) {
    DDON_STUB("cContextInterface::setShlGroup")
    /* stub */
}

s32 cContextInterface::getShlIndex(const cContextInstance* pInst, const cContextCharacter* pChara, u32 index) {
    if (pChara != nullptr) {
        return pChara->getShlIndex(index);
    } else {
        return -1;
    }
}

__attribute__((weak)) void cContextInterface::setShlIndex(cContextInstance* pInst, cContextCharacter* pChara, s32 shl_index, u32 index) {
    DDON_STUB("cContextInterface::setShlIndex")
    /* stub */
}

bool cContextInterface::isShlReqSlave(const cContextInstance* pInst, const cContextCharacter* pChara, u32 index) {
    if (pChara != nullptr) {
        return pChara->isShlReqSlave(index);
    } else {
        return false;
    }
}

void cContextInterface::setIsShlReqSlave(cContextInstance* pInst, cContextCharacter* pChara, bool flg, u32 index) {
    if (pChara == nullptr) {
        return;
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(reinterpret_cast<char*>(pChara) + index) + 1065) = static_cast<unsigned char>(flg);
}

bool cContextInterface::isShotReqNoAct(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->isShotReqNoAct();
    } else {
        return false;
    }
}

void cContextInterface::setIsShotReqNoAct(cContextInstance* pInst, cContextCharacter* pChara, bool flg) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mIsShotReqNoAct = flg;
}

__attribute__((weak)) MtVector3 cContextInterface::getShlPos(const cContextInstance* pInst, const cContextCharacter* pChara, u32 index) {
    DDON_STUB("cContextInterface::getShlPos")
    __builtin_unreachable();
}

void cContextInterface::setShlPos(cContextInstance* pInst, cContextCharacter* pChara, const MtVector3& pos, u32 index) {
    if (pChara == nullptr) {
        return;
    }
    pChara->setShlPos(pos, index);
}

__attribute__((weak)) const nNetMsgData::stNetPos& cContextInterface::getShlRealPos(const cContextInstance* pInst, const cContextCharacter* pChara, u32 index) {
    DDON_STUB("cContextInterface::getShlRealPos")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector3 cContextInterface::getShlTarget(const cContextInstance* pInst, const cContextCharacter* pChara, u32 index) {
    DDON_STUB("cContextInterface::getShlTarget")
    __builtin_unreachable();
}

void cContextInterface::setShlTarget(cContextInstance* pInst, cContextCharacter* pChara, const MtVector3& pos, u32 index) {
    if (pChara == nullptr) {
        return;
    }
    pChara->setShlTarget(pos, index);
}

__attribute__((weak)) const nNetMsgData::stNetPos& cContextInterface::getShlTargetRealPos(const cContextInstance* pInst, const cContextCharacter* pChara, u32 index) {
    DDON_STUB("cContextInterface::getShlTargetRealPos")
    __builtin_unreachable();
}

__attribute__((weak)) const MtVector3 cContextInterface::getShlDir(const cContextInstance* pInst, const cContextCharacter* pChara, u32 index) {
    DDON_STUB("cContextInterface::getShlDir")
    __builtin_unreachable();
}

__attribute__((weak)) void cContextInterface::setShlDir(cContextInstance* pInst, cContextCharacter* pChara, const MtVector3& dir, u32 index) {
    DDON_STUB("cContextInterface::setShlDir")
    /* stub */
}

__attribute__((weak)) u8 cContextInterface::getShlLockOnId(const cContextInstance* pInst, const cContextCharacter* pChara, u32 index) {
    DDON_STUB("cContextInterface::getShlLockOnId")
    return {};
}

void cContextInterface::setShlLockOnId(cContextInstance* pInst, cContextCharacter* pChara, u8 id, u32 index) {
    if (pChara == nullptr) {
        return;
    }
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(reinterpret_cast<char*>(pChara) + index) + 1056) = id;
}

void cContextInterface::setShlShotReceiveNum(cContextInstance* pInst, cContextCharacter* pChara, u8 num) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mShlShotReceiveNum = num;
}

bool cContextInterface::isReqStickShl(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->isReqStickShl();
    } else {
        return false;
    }
}

void cContextInterface::addShlStickInfo(cContextInstance* pInst, cContextCharacter* pChara, nShlBase::cShlStickContextInfo* pinfo) {
    if (pChara == nullptr) {
        return;
    }
    pChara->addShlStickInfo(pinfo);
}

void cContextInterface::requestShlStickInfoContext(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->requestShlStickInfoContext();
}

bool cContextInterface::isStickCreateControl(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->isStickCreateControl();
    } else {
        return false;
    }
}

void cContextInterface::setIsStickCreateControl(cContextInstance* pInst, cContextCharacter* pChara, bool flg) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mIsStickCreateControl = flg;
}

u32 cContextInterface::getStickShlUniqueId(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getStickShlUniqueId();
    } else {
        return 0;
    }
}

u32 cContextInterface::getStickUniqueId(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getStickUniqueId();
    } else {
        return 0;
    }
}

u8 cContextInterface::getStickJointNo(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getStickJointNo();
    } else {
        return 0;
    }
}

u8 cContextInterface::getStickShlGroup(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getStickShlGroup();
    } else {
        return 0;
    }
}

u8 cContextInterface::getStickShlIndex(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getStickShlIndex();
    } else {
        return 0;
    }
}

__attribute__((weak)) const MtVector3 cContextInterface::getStickJointOffset(const cContextInstance* pInst, const cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::getStickJointOffset")
    __builtin_unreachable();
}

__attribute__((weak)) const MtVector3 cContextInterface::getStickDirection(const cContextInstance* pInst, const cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::getStickDirection")
    __builtin_unreachable();
}

bool cContextInterface::isShlKillSync(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->isShlKillSync();
    } else {
        return false;
    }
}

void cContextInterface::setIsShlKillSync(cContextInstance* pInst, cContextCharacter* pChara, bool flg) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mIsShlKillSync = flg;
}

bool cContextInterface::isShlSlaveKill(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->isShlSlaveKill();
    } else {
        return false;
    }
}

void cContextInterface::setIsShlSlaveKill(cContextInstance* pInst, cContextCharacter* pChara, bool flg) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mIsShlSlaveKill = flg;
}

u8 cContextInterface::getSlaveKillSyncSts(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getSlaveKillSyncSts();
    } else {
        return 0;
    }
}

void cContextInterface::setSlaveKillSyncSts(cContextInstance* pInst, cContextCharacter* pChara, u8 bit) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mShlSlaveKillSyncSts = bit;
}

u32 cContextInterface::getEnemyStatusGroupNum(const cContextInstance* pInst, const cContextCharacter* pChara) {
    u32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                const cContextInstChar* pInstChar = static_cast<const cContextInstChar*>(pInst);
                v2_7 = static_cast<const cContextInstChar*>(pInst)->getEnemyStatusGroupNum();
                return v2_7;
            }
        }
        v2_7 = 0;
    }
    return v2_7;
}

void cContextInterface::setEnemyStatusGroupNum(cContextInstance* pInst, cContextCharacter* pChara, u32 groupNum) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mEnemyStatusGroupNoNum = groupNum;
                return;
            }
        }
    }
}

__attribute__((weak)) bool cContextInterface::addEnemyStatusGroup(cContextInstance* pInst, cContextCharacter* pChara, u32 group, u32 subGroup) {
    DDON_STUB("cContextInterface::addEnemyStatusGroup")
    return {};
}

u32 cContextInterface::getEnemyStatusGroup(const cContextInstance* pInst, const cContextCharacter* pChara, u32 idx) {
    if (pInst != nullptr) {
        if (pInst->getDTI().MtDTI::operator==(cContextInstChar::DTI)) {
            if (idx <= 15u) {
                return static_cast<const cContextInstChar*>(pInst)->getEnemyStatusGroup(idx);
            }
        }
    }
    return 0;
}

__attribute__((weak)) void cContextInterface::setEnemyStatusGroup(cContextInstance* pInst, cContextCharacter* pChara, u32 idx, u32 group) {
    DDON_STUB("cContextInterface::setEnemyStatusGroup")
    /* stub */
}

u32 cContextInterface::getEnemyStatusSubGroup(const cContextInstance* pInst, const cContextCharacter* pChara, u32 idx) {
    if (pInst != nullptr) {
        if (pInst->getDTI().MtDTI::operator==(cContextInstChar::DTI)) {
            if (idx <= 15u) {
                return static_cast<const cContextInstChar*>(pInst)->getEnemyStatusSubGroup(idx);
            }
        }
    }
    return 0;
}

__attribute__((weak)) void cContextInterface::setEnemyStatusSubGroup(cContextInstance* pInst, cContextCharacter* pChara, u32 idx, u32 subGroup) {
    DDON_STUB("cContextInterface::setEnemyStatusSubGroup")
    /* stub */
}

void cContextInterface::setEnemyBitReceive(cContextInstance* pInst, cContextCharacter* pChara, bool enable) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mIsEnemyBitReceive = enable;
                return;
            }
        }
    }
}

u64 cContextInterface::getEnemyBitCtrlCollision(const cContextInstance* pInst, const cContextCharacter* pChara) {
    u64 v2_0;
    if (pInst == nullptr) {
        v2_0 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_0 = 0;
                    return v2_0;
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        v2_0 = static_cast<const cContextInstChar*>(pInst)->getEnemyBitCtrlCollision();
    }
    return v2_0;
}

void cContextInterface::setEnemyBitCtrlCollision(cContextInstance* pInst, cContextCharacter* pChara, u64 bit) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mEnemyBitCtrlCollision = bit;
                return;
            }
        }
    }
}

u8 cContextInterface::getEnemyCtrRegionSelectNo(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstChar::DTI)) {
        return static_cast<const cContextInstChar*>(pInst)->getEnemyCtrRegionSelectNo();
    }
    return 0;
}

void cContextInterface::setEnemyCtrRegionSelectNo(cContextInstance* pInst, cContextCharacter* pChara, u8 selectNo) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mEnemyCtrlRegionSelectNo = selectNo;
                return;
            }
        }
    }
}

u64 cContextInterface::getEnemyBitCtrParts(const cContextInstance* pInst, const cContextCharacter* pChara) {
    u64 v2_0;
    if (pInst == nullptr) {
        v2_0 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_0 = 0;
                    return v2_0;
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        v2_0 = static_cast<const cContextInstChar*>(pInst)->getEnemyBitCtrParts();
    }
    return v2_0;
}

void cContextInterface::setEnemyBitCtrParts(cContextInstance* pInst, cContextCharacter* pChara, u64 bit) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mEnemyBitCtrlParts = bit;
                return;
            }
        }
    }
}

u64 cContextInterface::getEnemyWorkRate(const cContextInstance* pInst, const cContextCharacter* pChara) {
    u64 v2_0;
    if (pInst == nullptr) {
        v2_0 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_0 = 0;
                    return v2_0;
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        v2_0 = static_cast<const cContextInstChar*>(pInst)->getEnemyWorkRate();
    }
    return v2_0;
}

void cContextInterface::setEnemyWorkRate(cContextInstance* pInst, cContextCharacter* pChara, u64 bit) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mEnemyBitCtrlWorkRate = bit;
                return;
            }
        }
    }
}

u64 cContextInterface::getEnemyScale(const cContextInstance* pInst, const cContextCharacter* pChara) {
    u64 v2_0;
    if (pInst == nullptr) {
        v2_0 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_0 = 0;
                    return v2_0;
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        v2_0 = static_cast<const cContextInstChar*>(pInst)->getEnemyScale();
    }
    return v2_0;
}

void cContextInterface::setEnemyScale(cContextInstance* pInst, cContextCharacter* pChara, u64 bit) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mEnemyBitCtrlScale = bit;
                return;
            }
        }
    }
}

u64 cContextInterface::getEnemyBitCtrlMontage(const cContextInstance* pInst, const cContextCharacter* pChara) {
    u64 v2_0;
    if (pInst == nullptr) {
        v2_0 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_0 = 0;
                    return v2_0;
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        v2_0 = static_cast<const cContextInstChar*>(pInst)->getEnemyBitCtrlMontage();
    }
    return v2_0;
}

void cContextInterface::setEnemyBitCtrlMontage(cContextInstance* pInst, cContextCharacter* pChara, u64 bit) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mEnemyBitCtrlMontage = bit;
                return;
            }
        }
    }
}

u32 cContextInterface::getEnemyBitCtrlSyncBit(const cContextInstance* pInst, const cContextCharacter* pChara) {
    u32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                v2_7 = static_cast<const cContextInstChar*>(pInst)->getEnemyBitCtrlSyncBit();
                return v2_7;
            }
        }
        v2_7 = 0;
    }
    return v2_7;
}

void cContextInterface::setEnemyBitCtrlSyncBit(cContextInstance* pInst, cContextCharacter* pChara, u32 bit) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mEnemyBitCtrlSyncBit = bit;
                return;
            }
        }
    }
}

bool cContextInterface::isEnemyStatusChange(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstChar::DTI)) {
        return static_cast<const cContextInstChar*>(pInst)->isEnemyStatusChange();
    }
    return false;
}

void cContextInterface::setEnemyStatusChange(cContextInstance* pInst, cContextCharacter* pChara, bool enable) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mIsEnemyStatusChange = enable;
                return;
            }
        }
    }
}

bool cContextInterface::getEnemyWaitting(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstChar::DTI)) {
        return static_cast<const cContextInstChar*>(pInst)->getEnemyWaitting();
    }
    return false;
}

void cContextInterface::setEnemyWaitting(cContextInstance* pInst, cContextCharacter* pChara, bool enable) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                cContextInstChar* pInstChar = static_cast<cContextInstChar*>(pInst);
                pInstChar->mIsEnemyWaitting = enable;
                return;
            }
        }
    }
}

bool cContextInterface::isEnemyWaittingChange(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstChar::DTI)) {
        return static_cast<const cContextInstChar*>(pInst)->isEnemyWaittingChange();
    }
    return false;
}

void cContextInterface::setEnemyWaittingChange(cContextInstance* pInst, cContextCharacter* pChara, bool enable) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                cContextInstChar* pInstChar = static_cast<cContextInstChar*>(pInst);
                pInstChar->mIsEnemyWaittingChange = enable;
                return;
            }
        }
    }
}

bool cContextInterface::getEnemyStartWait(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstChar::DTI)) {
        return static_cast<const cContextInstChar*>(pInst)->getEnemyStartWait();
    }
    return false;
}

void cContextInterface::setEnemyStartWait(cContextInstance* pInst, cContextCharacter* pChara, bool enable) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                cContextInstChar* pInstChar = static_cast<cContextInstChar*>(pInst);
                pInstChar->mIsEnemyStartWait = enable;
                return;
            }
        }
    }
}

bool cContextInterface::isEnemyStartWaitChange(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstChar::DTI)) {
        return static_cast<const cContextInstChar*>(pInst)->isEnemyStartWaitChange();
    }
    return false;
}

void cContextInterface::setEnemyStartWaitChange(cContextInstance* pInst, cContextCharacter* pChara, bool enable) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                cContextInstChar* pInstChar = static_cast<cContextInstChar*>(pInst);
                pInstChar->mIsEnemyStartWaitChange = enable;
                return;
            }
        }
    }
}

void cContextInterface::addCorePointMsg(cContextInstance* pInst, cContextCharacter* pChara, const cCorePointMsg* pMsg) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cContextInstChar*>(pInst)->addCorePointMsg(pMsg);
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
}

u32 cContextInterface::getUnSendedCorePointMsgNum(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                return static_cast<const cContextInstChar*>(pInst)->getUnSendedCorePointMsgNum();
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
    return 0;
}

cCorePointMsg* cContextInterface::getUnSendedTopCorePointMsg(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                return static_cast<const cContextInstChar*>(pInst)->getUnSendedTopCorePointMsg();
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
    return nullptr;
}

u32 cContextInterface::getCorePointMsgNum(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                return static_cast<const cContextInstChar*>(pInst)->getCorePointMsgNum();
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
    return 0;
}

cCorePointMsg* cContextInterface::getCorePointMsg(const cContextInstance* pInst, const cContextCharacter* pChara, u32 index) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                return static_cast<const cContextInstChar*>(pInst)->getCorePointMsg(index);
            } else {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            }
        }
    }
    return nullptr;
}

void cContextInterface::eraseCorePointMsg(cContextInstance* pInst, cContextCharacter* pChara, u32 index) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cContextInstChar*>(pInst)->eraseCorePointMsg(index);
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
}

u32 cContextInterface::getMontageFixNo(const cContextInstance* pInst) {
    u32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                v2_7 = static_cast<const cContextInstChar*>(pInst)->getMontageFixNo();
                return v2_7;
            }
        }
        v2_7 = 0;
    }
    return v2_7;
}

void cContextInterface::setMontageFixNo(cContextInstance* pInst, u32 fixNo) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mMontageFixNo = fixNo;
                return;
            }
        }
    }
}

u32 cContextInterface::getMontageRandom(const cContextInstance* pInst) {
    u32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                const cContextInstChar* pInstChar = static_cast<const cContextInstChar*>(pInst);
                v2_7 = static_cast<const cContextInstChar*>(pInst)->getMontageRandom();
                return v2_7;
            }
        }
        v2_7 = 0;
    }
    return v2_7;
}

void cContextInterface::setMontageRandom(cContextInstance* pInst, u32 rand) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstChar*>(pInst)->mMontageRandom = rand;
                return;
            }
        }
    }
}

u32 cContextInterface::getCorePointSlaveMsgNum(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getCorePointSlaveMsgNum();
    } else {
        return 0;
    }
}

bool cContextInterface::isSendCorePointSlaveFlag_On(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->isSendCorePointSlaveFlag_On();
    } else {
        return false;
    }
}

void cContextInterface::sendCorePointSlaveFlag_On(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->sendCorePointSlaveFlag_On();
}

void cContextInterface::sendCorePointSlaveFlag_Off(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->sendCorePointSlaveFlag_Off();
}

void cContextInterface::addCorePointSlaveMsg(cContextInstance* pInst, cContextCharacter* pChara, const nRegionStatus::stCorePointSlaveMsg& src) {
    if (pChara == nullptr) {
        return;
    }
    pChara->addCorePointSlaveMsg(src);
}

void cContextInterface::clearCorePointSlaveMsgAll(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->clearCorePointSlaveMsgAll();
}

__attribute__((weak)) const nRegionStatus::stCorePointSlaveMsg& cContextInterface::getCorePointSlaveMsgTop(cContextInstance* pInst, cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::getCorePointSlaveMsgTop")
    __builtin_unreachable();
}

void cContextInterface::clearCorePointSlaveMsgTop(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->clearCorePointSlaveMsgTop();
}

u16 cContextInterface::getCommonWork(const cContextInstance* pInst, const cContextCharacter* pChara) {
    u16 v2_0;
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                const cContextInstChar* pInstChar = static_cast<const cContextInstChar*>(pInst);
                v2_0 = static_cast<const cContextInstChar*>(pInst)->getCommonWork();
                return v2_0;
            }
        }
        v2_0 = 0;
    } else {
        v2_0 = 0;
    }
    return v2_0;
}

void cContextInterface::setCommonWork(cContextInstance* pInst, cContextCharacter* pChara, u16 work) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                cContextInstChar* pInstChar = static_cast<cContextInstChar*>(pInst);
                pInstChar->mCommonWork = work;
                if (pChara != nullptr) {
                    pChara->mSendDataBuff.mCommonWork = pInstChar->mCommonWork;
                }
                return;
            }
        }
    }
}

void cContextInterface::addCommonWork(cContextInstance* pInst, cContextCharacter* pChara, u16 work) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                cContextInstChar* pInstChar = static_cast<cContextInstChar*>(pInst);
                pInstChar->mCommonWork = work | pInstChar->mCommonWork;
                if (pChara != nullptr) {
                    pChara->mSendDataBuff.mCommonWork = work | pChara->mSendDataBuff.mCommonWork;
                }
                return;
            }
        }
    }
}

__attribute__((weak)) void cContextInterface::subCommonWork(cContextInstance* pInst, cContextCharacter* pChara, u16 work) {
    DDON_STUB("cContextInterface::subCommonWork")
    /* stub */
}

__attribute__((weak)) bool cContextInterface::isCommonWork(const cContextInstance* pInst, const cContextCharacter* pChara, u16 work) {
    DDON_STUB("cContextInterface::isCommonWork")
    return {};
}

u16 cContextInterface::getCustomWork(const cContextInstance* pInst, const cContextCharacter* pChara) {
    u16 v2_0;
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                const cContextInstChar* pInstChar = static_cast<const cContextInstChar*>(pInst);
                v2_0 = static_cast<const cContextInstChar*>(pInst)->getCustomWork();
                return v2_0;
            }
        }
        v2_0 = 0;
    } else {
        v2_0 = 0;
    }
    return v2_0;
}

void cContextInterface::setCustomWork(cContextInstance* pInst, cContextCharacter* pChara, u16 work) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                cContextInstChar* pInstChar = static_cast<cContextInstChar*>(pInst);
                pInstChar->mCustomWork = work;
                if (pChara != nullptr) {
                    pChara->mSendDataBuff.mCustomWork = pInstChar->mCustomWork;
                }
                return;
            }
        }
    }
}

void cContextInterface::addCustomWork(cContextInstance* pInst, cContextCharacter* pChara, u16 work) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                cContextInstChar* pInstChar = static_cast<cContextInstChar*>(pInst);
                pInstChar->mCustomWork = work | pInstChar->mCustomWork;
                if (pChara != nullptr) {
                    pChara->mSendDataBuff.mCustomWork = work | pChara->mSendDataBuff.mCustomWork;
                }
                return;
            }
        }
    }
}

__attribute__((weak)) void cContextInterface::subCustomWork(cContextInstance* pInst, cContextCharacter* pChara, u16 work) {
    DDON_STUB("cContextInterface::subCustomWork")
    /* stub */
}

__attribute__((weak)) bool cContextInterface::isCustomWork(const cContextInstance* pInst, const cContextCharacter* pChara, u16 work) {
    DDON_STUB("cContextInterface::isCustomWork")
    return {};
}

u32 cContextInterface::getStateLive(const cContextInstance* pInst, const cContextCharacter* pChara) {
    u32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                v2_7 = static_cast<const cContextInstChar*>(pInst)->getStateLive();
                return v2_7;
            }
        }
        v2_7 = 0;
    }
    return v2_7;
}

void cContextInterface::setStateLive(cContextInstance* pInst, cContextCharacter* pChara, u32 state) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                if (static_cast<cContextInstChar*>(pInst)->mStateLive != state) {
                    cContextInstChar* pInstChar = static_cast<cContextInstChar*>(pInst);
                    static_cast<cContextInstChar*>(pInst)->mStateLive = state;
                    pInstChar->mIsStateLiveChange = true;
                }
                return;
            }
        }
    }
}

bool cContextInterface::isStateLiveChange(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstChar::DTI)) {
        return static_cast<const cContextInstChar*>(pInst)->isStateLiveChange();
    }
    return false;
}

void cContextInterface::setStateLiveChange(cContextInstance* pInst, cContextCharacter* pChara, bool flg) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstChar::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                cContextInstChar* pInstChar = static_cast<cContextInstChar*>(pInst);
                pInstChar->mIsStateLiveChange = flg;
                return;
            }
        }
    }
}

__attribute__((weak)) const nHumanBow::stNetData& cContextInterface::popBowUpNetData(const cContextInstance* pInst, cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::popBowUpNetData")
    __builtin_unreachable();
}

void cContextInterface::pushBowUpNetData(cContextInstance* pInst, cContextCharacter* pChara, const nHumanBow::stNetData& d) {
    if (pChara == nullptr) {
        return;
    }
    pChara->pushBowUpNetData(d);
}

void cContextInterface::pushBowLockOnInfo(u32 index, u32 uid, u32 lockId) {
    if (mpContextCharacter == nullptr) {
        return;
    }
    mpContextCharacter->pushBowLockOnInfo(index, uid, lockId);
}

void cContextInterface::popBowLockOnInfo(u32 index, u32& uid, u32& lockId) {
    if (mpContextCharacter == nullptr) {
        return;
    }
    mpContextCharacter->popBowLockOnInfo(index, uid, lockId);
}

__attribute__((weak)) const nHumanBow::stNetData& cContextInterface::popBowLowNetData(const cContextInstance* pInst, cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::popBowLowNetData")
    __builtin_unreachable();
}

void cContextInterface::pushBowLowNetData(cContextInstance* pInst, cContextCharacter* pChara, const nHumanBow::stNetData& d) {
    if (pChara == nullptr) {
        return;
    }
    pChara->pushBowLowNetData(d);
}

__attribute__((weak)) const nHumanBow::stNetData& cContextInterface::popBowPeriodNetData(const cContextInstance* pInst, cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::popBowPeriodNetData")
    __builtin_unreachable();
}

void cContextInterface::pushBowPeriodNetData(cContextInstance* pInst, cContextCharacter* pChara, const nHumanBow::stNetData& d) {
    if (pChara == nullptr) {
        return;
    }
    pChara->pushBowPeriodNetData(d);
}

const MtVector3& cContextInterface::getBowNetAimPos(const cContextInstance* pInst, const cContextCharacter* pChara) {
    return *((pChara == nullptr) ? (&MtVector3::Zero) : (&pChara->mBowNetAimPos));
}

void cContextInterface::setBowNetAimPos(cContextInstance* pInst, cContextCharacter* pChara, const MtVector3& pos) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mBowNetAimPos.x = pos.x;
    pChara->mBowNetAimPos.y = pos.y;
    pChara->mBowNetAimPos.z = pos.z;
    pChara->mBowNetAimPos.pad_ = 0.0f;
}

u32 cContextInterface::getBowNetUpdateFlag(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getBowNetUpdateFlag();
    } else {
        return 0;
    }
}

void cContextInterface::setBowNetUpdateFlag(cContextInstance* pInst, cContextCharacter* pChara, u32 flag) {
    if (pChara == nullptr) {
        return;
    }
    pChara->mBowNetUpdateFlag = flag;
}

bool cContextInterface::getMasterChangeFlag(const cContextInstance* pInst) {
    if (pInst != nullptr) {
        return pInst->getMasterChangeFlag();
    } else {
        return false;
    }
}

void cContextInterface::setMasterChangeFlag(cContextInstance* pInst, bool flg) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mMasterChangeFlag = flg;
}

s32 cContextInterface::getMasterIndex(const cContextInstance* pInst) {
    if (pInst != nullptr) {
        return pInst->getMasterIndex();
    } else {
        return -1;
    }
}

void cContextInterface::setMasterIndex(cContextInstance* pInst, s32 masterIndex) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mMasterIndex = masterIndex;
}

s32 cContextInterface::getMainEncountArea(const cContextInstance* pInst) {
    if (pInst != nullptr) {
        return pInst->getMainEncountArea();
    } else {
        return -1;
    }
}

void cContextInterface::setMainEncountArea(cContextInstance* pInst, s32 encountArea) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mMainEncountArea = encountArea;
}

bool cContextInterface::getSetWaitFlag(const cContextInstance* pInst) {
    if (pInst != nullptr) {
        return pInst->getSetWaitFlag();
    } else {
        return false;
    }
}

void cContextInterface::setSetWaitFlag(cContextInstance* pInst, bool flg) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mSetWaitFlag = flg;
}

__attribute__((weak)) bool cContextInterface::isSessionLost(const cContextInstance* pInst) {
    DDON_STUB("cContextInterface::isSessionLost")
    return {};
}

__attribute__((weak)) bool cContextInterface::isSessionLost(const cContextInstHm* pInst) {
    DDON_STUB("cContextInterface::isSessionLost")
    return {};
}

__attribute__((weak)) bool cContextInterface::isPartyLeader(const cContextInstance* pInst) {
    DDON_STUB("cContextInterface::isPartyLeader")
    return {};
}

bool cContextInterface::isPartyLeader(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        if (pInst->mHumanType == 0) {
            if ((pInst->getCharId() != 0) && (pInst->getCharId() == static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mLeaderCharacterId)) {
                return true;
            }
        }
    }
    return false;
}

__attribute__((weak)) bool cContextInterface::isPawnOwner(const cContextInstance* pInst) {
    DDON_STUB("cContextInterface::isPawnOwner")
    return {};
}

__attribute__((weak)) bool cContextInterface::isPawnOwner(const cContextInstHm* pInst) {
    DDON_STUB("cContextInterface::isPawnOwner")
    return {};
}

__attribute__((weak)) s32 cContextInterface::getPawnOwnerIndex(const cContextInstHm* pInst) {
    DDON_STUB("cContextInterface::getPawnOwnerIndex")
    return {};
}

void cContextInterface::setIndex(cContextInstHm* pInst, u8 index) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mIndex = index;
}

u32 cContextInterface::getRPCID(const cContextInstance* pInst) {
    unsigned int v2_7;
    if (pInst == nullptr) {
        v2_7 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                if (static_cast<const cContextInstHm*>(pInst)->mHumanType > 1) {
                    v2_7 = 0;
                } else {
                    v2_7 = static_cast<const cContextInstHm*>(pInst)->mIndex + 2000;
                }
                return v2_7;
            }
        }
        v2_7 = 0;
    }
    return v2_7;
}

u32 cContextInterface::getRPCID(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        if (pInst->mHumanType <= 1) {
            return static_cast<u32>(pInst->mIndex + 2000);
        }
    }
    return 0;
}

u32 cContextInterface::getSex(const cContextInstance* pInst) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstHm::DTI)) {
        return static_cast<const cContextInstHm*>(pInst)->mSex;
    }
    return 0;
}

u32 cContextInterface::getSex(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        return pInst->mSex;
    } else {
        return 0;
    }
}

void cContextInterface::setSex(cContextInstance* pInst, u32 sex) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mSex = static_cast<unsigned char>(sex);
                return;
            }
        }
    }
}

void cContextInterface::setSex(cContextInstHm* pInst, u32 sex) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mSex = static_cast<unsigned char>(sex);
}

rCharacterEdit* cContextInterface::getCharacterEdit(const cContextInstance* pInst) {
    rCharacterEdit* v2_0;
    if (pInst == nullptr) {
        v2_0 = nullptr;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_0 = nullptr;
                    return v2_0;
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        v2_0 = static_cast<const cContextInstHm*>(pInst)->getCharacterEdit();
    }
    return v2_0;
}

rCharacterEdit* cContextInterface::getCharacterEdit(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        return pInst->getCharacterEdit();
    } else {
        return nullptr;
    }
}

s32 cContextInterface::getFloorGroupNo(const cContextInstance* pInst) {
    s32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                v2_7 = static_cast<const cContextInstHm*>(pInst)->getFloorGroupNo();
                return v2_7;
            }
        }
        v2_7 = 0;
    }
    return v2_7;
}

void cContextInterface::setFloorGroupNo(cContextInstance* pInst, const s32 no) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mFloorGroupNo = no;
                return;
            }
        }
    }
}

void cContextInterface::setFloorGroupNo(cContextInstHm* pInst, const s32 no) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mFloorGroupNo = no;
}

s32 cContextInterface::getStartPosNo(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        return pInst->getStartPosNo();
    } else {
        return 0;
    }
}

void cContextInterface::setStartPosNo(cContextInstHm* pInst, const s32 no) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mStartPosNo = no;
}

__attribute__((weak)) const CHAR_NAME& cContextInterface::getName(const cContextInstance* pInst) {
    DDON_STUB("cContextInterface::getName")
    __builtin_unreachable();
}

__attribute__((weak)) const CHAR_NAME& cContextInterface::getName(const cContextInstHm* pInst) {
    DDON_STUB("cContextInterface::getName")
    __builtin_unreachable();
}

__attribute__((weak)) void cContextInterface::setName(cContextInstance* pInst, const CHAR_NAME& name) {
    DDON_STUB("cContextInterface::setName")
    /* stub */
}

__attribute__((weak)) void cContextInterface::setName(cContextInstHm* pInst, const CHAR_NAME& name) {
    DDON_STUB("cContextInterface::setName")
    /* stub */
}

__attribute__((weak)) MT_CTSTR cContextInterface::getFirstName(const cContextInstance* pInst) {
    DDON_STUB("cContextInterface::getFirstName")
    return {};
}

MT_CTSTR cContextInterface::getFirstName(const cContextInstHm* pInst) {
    return (pInst == nullptr) ? "" : (&pInst->mName.mFirstName[0]);
}

void cContextInterface::setFirstName(cContextInstHm* pInst, MT_CTSTR name) {
    if (pInst == nullptr) {
        return;
    }
    if (name == nullptr) {
        return;
    }
    snprintf(&pInst->mName.mFirstName[0], 13ul, "%s", name);
}

__attribute__((weak)) MT_CTSTR cContextInterface::getLastName(const cContextInstance* pInst) {
    DDON_STUB("cContextInterface::getLastName")
    return {};
}

MT_CTSTR cContextInterface::getLastName(const cContextInstHm* pInst) {
    return (pInst == nullptr) ? "" : (&pInst->mName.mLastName[0]);
}

void cContextInterface::setLastName(cContextInstHm* pInst, MT_CTSTR name) {
    if (pInst == nullptr) {
        return;
    }
    if (name == nullptr) {
        return;
    }
    snprintf(&pInst->mName.mLastName[0], 9ul, "%s", name);
}

MT_CTSTR cContextInterface::getClanNickName(const cContextInstHm* pInst) {
    return (pInst == nullptr) ? "" : (&pInst->mClanNickName[0]);
}

void cContextInterface::setClanNickName(cContextInstHm* pInst, MT_CTSTR name) {
    if (pInst == nullptr) {
        return;
    }
    snprintf(&pInst->mClanNickName[0], 4ul, "%s", name);
}

__attribute__((weak)) bool cContextInterface::isFriend(const cContextInstance* pInst) {
    DDON_STUB("cContextInterface::isFriend")
    return {};
}

__attribute__((weak)) bool cContextInterface::isClanMember(const cContextInstance* pInst) {
    DDON_STUB("cContextInterface::isClanMember")
    return {};
}

void cContextInterface::setOnlineStatus(cContextInstHm* pInst, const u8 status) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mOnlineStatus = status;
}

u8 cContextInterface::getOnlineStatus(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        return pInst->getOnlineStatus();
    } else {
        return 0;
    }
}

u8 cContextInterface::getJob(const cContextInstance* pInst) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstHm::DTI)) {
        return static_cast<const cContextInstHm*>(pInst)->mPlayerInfo.getJob();
    }
    return 0xFF;
}

u8 cContextInterface::getJob(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        return pInst->mPlayerInfo.getJob();
    } else {
        return 0xFF;
    }
}

void cContextInterface::setJob(cContextInstance* pInst, u8 Job) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mPlayerInfo.mCurrentJob_pri = Job;
                return;
            }
        }
    }
}

void cContextInterface::setJob(cContextInstHm* pInst, u8 Job) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mPlayerInfo.mCurrentJob_pri = Job;
}

__attribute__((weak)) const cEquipData& cContextInterface::getContextEquipConst(const cContextInstance* pInst) {
    DDON_STUB("cContextInterface::getContextEquipConst")
    __builtin_unreachable();
}

__attribute__((weak)) const cEquipData& cContextInterface::getContextEquipConst(const cContextInstHm* pInst) {
    DDON_STUB("cContextInterface::getContextEquipConst")
    __builtin_unreachable();
}

__attribute__((weak)) cEquipData& cContextInterface::getContextEquip(cContextInstance* pInst) {
    DDON_STUB("cContextInterface::getContextEquip")
    __builtin_unreachable();
}

__attribute__((weak)) cEquipData& cContextInterface::getContextEquip(cContextInstHm* pInst) {
    DDON_STUB("cContextInterface::getContextEquip")
    __builtin_unreachable();
}

__attribute__((weak)) u16 cContextInterface::getEquipData(const cContextInstance* pInst, u8 category, u8 type) {
    DDON_STUB("cContextInterface::getEquipData")
    return {};
}

u16 cContextInterface::getEquipData(const cContextInstHm* pInst, u8 category, u8 type) {
    if (pInst != nullptr) {
        return pInst->mEquip.getEquip(category, type, true);
    } else {
        return 0;
    }
}

__attribute__((weak)) void cContextInterface::setEquipData(cContextInstance* pInst, u8 category, cItemParam* pItem, u8 type) {
    DDON_STUB("cContextInterface::setEquipData")
    /* stub */
}

void cContextInterface::setEquipData(cContextInstHm* pInst, u8 category, cItemParam* pItem, u8 type) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mEquip.setEquip(category, type, pItem);
}

void cContextInterface::setEquipFromCharData(cContextInstHm* pInst, const nCharacterData::stEquipData& Data) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mEquip.setEquipFromCharacterData(Data);
}

void cContextInterface::setPlayerLoadStatus(cContextInstance* pInst, s32 status) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mPlayerLoadStatus = status;
                return;
            }
        }
    }
}

__attribute__((weak)) cPlayerLoadManager& cContextInterface::getPlayerLoadMgr(cContextInstance* pInst) {
    DDON_STUB("cContextInterface::getPlayerLoadMgr")
    __builtin_unreachable();
}

__attribute__((weak)) cPlayerLoadManager& cContextInterface::getPlayerLoadMgr(cContextInstHm* pInst) {
    DDON_STUB("cContextInterface::getPlayerLoadMgr")
    __builtin_unreachable();
}

u8 cContextInterface::getVoice(const cContextInstance* pInst) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstHm::DTI)) {
        return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(static_cast<const cContextInstHm*>(pInst)->getCharacterEdit()->mpEditParam) + 48);
    }
    return 0;
}

u8 cContextInterface::getVoice(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        return *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(pInst->getCharacterEdit()->mpEditParam) + 48);
    } else {
        return 0;
    }
}

void cContextInterface::setVoice(cContextInstHm* pInst, u8 Voice) {
    if (pInst == nullptr) {
        return;
    }
    pInst->getCharacterEdit()->mpEditParam->mVoice = Voice;
}

s32 cContextInterface::getVoicePitch(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        return pInst->getCharacterEdit()->mpEditParam->mVoicePitch;
    } else {
        return 0;
    }
}

void cContextInterface::setVoicePitch(cContextInstHm* pInst, s32 pitch) {
    if (pInst == nullptr) {
        return;
    }
    pInst->getCharacterEdit()->mpEditParam->mVoicePitch = pitch;
}

u8 cContextInterface::getHumanType(const cContextInstance* pInst) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstHm::DTI)) {
        return static_cast<const cContextInstHm*>(pInst)->getHumanType();
    }
    return 0;
}

u8 cContextInterface::getHumanType(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        return pInst->getHumanType();
    } else {
        return 0;
    }
}

void cContextInterface::setHumanType(cContextInstance* pInst, u8 type) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mHumanType = type;
                return;
            }
        }
    }
}

void cContextInterface::setHumanType(cContextInstHm* pInst, u8 type) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mHumanType = type;
}

u8 cContextInterface::getPawnType(const cContextInstance* pInst) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstHm::DTI)) {
        return static_cast<const cContextInstHm*>(pInst)->getPawnType();
    }
    return 0;
}

u8 cContextInterface::getPawnType(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        return pInst->getPawnType();
    } else {
        return 0;
    }
}

void cContextInterface::setPawnType(cContextInstHm* pInst, u8 type) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mPawnType = type;
}

u32 cContextInterface::getRawCharacterId(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        return pInst->getCharId();
    } else {
        return 0;
    }
}

void cContextInterface::setCharacterId(cContextInstHm* pInst, u32 charId) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mCharId = charId;
}

u32 cContextInterface::getPlCharacterId(const cContextInstance* pInst) {
    u32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                if (static_cast<const cContextInstHm*>(pInst)->mHumanType != 0) {
                    v2_7 = 0;
                } else {
                    v2_7 = static_cast<const cContextInstHm*>(pInst)->getCharId();
                }
                return v2_7;
            }
        }
        v2_7 = 0;
    }
    return v2_7;
}

u32 cContextInterface::getPlCharacterId(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        if (pInst->mHumanType == 0) {
            return pInst->getCharId();
        }
    }
    return 0;
}

__attribute__((weak)) u32 cContextInterface::getPawnOwnerCharacterId(const cContextInstance* pInst) {
    DDON_STUB("cContextInterface::getPawnOwnerCharacterId")
    return {};
}

u32 cContextInterface::getPawnOwnerCharacterId(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        if (pInst->mHumanType == 1) {
            return pInst->getCharId();
        }
    }
    return 0;
}

u32 cContextInterface::getPawnId(const cContextInstance* pInst) {
    u32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                if (static_cast<const cContextInstHm*>(pInst)->mHumanType != 1) {
                    v2_7 = 0;
                } else {
                    v2_7 = static_cast<const cContextInstHm*>(pInst)->getPawnId();
                }
                return v2_7;
            }
        }
        v2_7 = 0;
    }
    return v2_7;
}

u32 cContextInterface::getPawnId(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        if (pInst->mHumanType == 1) {
            return pInst->getPawnId();
        }
    }
    return 0;
}

void cContextInterface::setPawnId(cContextInstHm* pInst, u32 pawnId) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mPawnId = pawnId;
}

bool cContextInterface::checkId(const cContextInstHm* pInst, u32 characterId, u32 pawnId) {
    if (pInst != nullptr) {
        if (pInst->mCharId == characterId) {
            if (pInst->mHumanType == 1) {
                if (pInst->getPawnId() != pawnId) {
                    return false;
                }
            } else {
                if (pawnId != 0) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

__attribute__((weak)) bool cContextInterface::checkId(const cContextInstance* pInst, const cContextInstHm* pCheckInst) {
    DDON_STUB("cContextInterface::checkId")
    return {};
}

s32 cContextInterface::getMemberIndex(const cContextInstance* pInst) {
    s32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                v2_7 = static_cast<const cContextInstHm*>(pInst)->getMemberIndex();
                return v2_7;
            }
        }
        v2_7 = 0;
    }
    return v2_7;
}

s32 cContextInterface::getMemberIndex(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        return pInst->getMemberIndex();
    } else {
        return 0;
    }
}

void cContextInterface::setMemberIndex(cContextInstHm* pInst, s32 memberIndex) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mMemberIndex = memberIndex;
}

__attribute__((weak)) s32 cContextInterface::getEncountArea(const cContextInstance* pInst, u32 index) {
    DDON_STUB("cContextInterface::getEncountArea")
    return {};
}

s32 cContextInterface::getEncountArea(const cContextInstHm* pInst, u32 index) {
    if (pInst != nullptr) {
        return pInst->getEncountArea(index);
    } else {
        return -1;
    }
}

__attribute__((weak)) void cContextInterface::setEncountArea(cContextInstance* pInst, s32* areaArray, s32 num) {
    DDON_STUB("cContextInterface::setEncountArea")
    /* stub */
}

__attribute__((weak)) void cContextInterface::setEncountArea(cContextInstHm* pInst, s32* areaArray, s32 num) {
    DDON_STUB("cContextInterface::setEncountArea")
    /* stub */
}

__attribute__((weak)) MtVector3 cContextInterface::getLastSafePos(const cContextInstance* pInst) {
    DDON_STUB("cContextInterface::getLastSafePos")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector3 cContextInterface::getLastSafePos(const cContextInstHm* pInst) {
    DDON_STUB("cContextInterface::getLastSafePos")
    __builtin_unreachable();
}

void cContextInterface::setLastSafePos(cContextInstance* pInst, const MtVector3& pos) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 == v0_0->mName) {
                static_cast<cContextInstHm*>(pInst)->setLastSafePos(pos);
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
}

void cContextInterface::setLastSafePos(cContextInstHm* pInst, const MtVector3& pos) {
    if (pInst == nullptr) {
        return;
    }
    pInst->setLastSafePos(pos);
}

__attribute__((weak)) const nNetMsgData::stNetPos& cContextInterface::getLastSafeRealPos(const cContextInstance* pInst) {
    DDON_STUB("cContextInterface::getLastSafeRealPos")
    __builtin_unreachable();
}

__attribute__((weak)) void cContextInterface::setLastSafeRealPos(cContextInstHm* pInst, const nNetMsgData::stNetPos& pos) {
    DDON_STUB("cContextInterface::setLastSafeRealPos")
    /* stub */
}

__attribute__((weak)) u16 cContextInterface::getPawnAutoMotion(const cContextInstance* pInst, u32 situation) {
    DDON_STUB("cContextInterface::getPawnAutoMotion")
    return {};
}

__attribute__((weak)) void cContextInterface::setPawnAutoMotion(cContextInstHm* pInst, u32 situation, u16 val) {
    DDON_STUB("cContextInterface::setPawnAutoMotion")
    /* stub */
}

u16 cContextInterface::getPawnPersonality(const cContextInstance* pInst) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstHm::DTI)) {
        if (static_cast<const cContextInstHm*>(pInst)->mpCharacterEdit != nullptr) {
            if (static_cast<const cContextInstHm*>(pInst)->mpCharacterEdit->mpEditParam != nullptr) {
                return *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(static_cast<const cContextInstHm*>(pInst)->mpCharacterEdit->mpEditParam) + 60);
            }
        }
        return 1;
    }
    return 0;
}

u16 cContextInterface::getPawnPersonality(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        if (pInst->mpCharacterEdit != nullptr) {
            if (pInst->mpCharacterEdit->mpEditParam != nullptr) {
                return *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(pInst->mpCharacterEdit->mpEditParam) + 60);
            }
        }
        return 1;
    } else {
        return 0;
    }
}

u16 cContextInterface::getPawnTalkLv(const cContextInstance* pInst) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstHm::DTI)) {
        if (static_cast<const cContextInstHm*>(pInst)->mpCharacterEdit != nullptr) {
            if (static_cast<const cContextInstHm*>(pInst)->mpCharacterEdit->mpEditParam != nullptr) {
                return *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(static_cast<const cContextInstHm*>(pInst)->mpCharacterEdit->mpEditParam) + 64);
            }
        }
        return 1;
    }
    return 0;
}

__attribute__((weak)) u32 cContextInterface::getPawnTalkCharId(const cContextInstance* pInst, u32 idx) {
    DDON_STUB("cContextInterface::getPawnTalkCharId")
    return {};
}

__attribute__((weak)) void cContextInterface::setPawnTalkCharId(cContextInstance* pInst, u32 idx, u32 charId) {
    DDON_STUB("cContextInterface::setPawnTalkCharId")
    /* stub */
}

__attribute__((weak)) bool cContextInterface::getPawnTalkSituationFlag(const cContextInstance* pInst, u32 flag) {
    DDON_STUB("cContextInterface::getPawnTalkSituationFlag")
    return {};
}

__attribute__((weak)) void cContextInterface::setPawnTalkSituationFlag(cContextInstance* pInst, u32 flag, bool on) {
    DDON_STUB("cContextInterface::setPawnTalkSituationFlag")
    /* stub */
}

__attribute__((weak)) cContextPlayerInfo* cContextInterface::getContextPlayerInfo(cContextInstance* pInst) {
    DDON_STUB("cContextInterface::getContextPlayerInfo")
    return nullptr;
}

cContextPlayerInfo* cContextInterface::getContextPlayerInfo(cContextInstHm* pInst) {
    return (pInst == nullptr) ? static_cast<cContextPlayerInfo*>(nullptr) : (&pInst->mPlayerInfo);
}

const cContextPlayerInfo* cContextInterface::getContextPlayerInfo(const cContextInstHm* pInst) {
    return (pInst == nullptr) ? static_cast<const cContextPlayerInfo*>(nullptr) : (&pInst->mPlayerInfo);
}

u8 cContextInterface::getReviveStock(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        return pInst->getReviveStock();
    } else {
        return 0;
    }
}

void cContextInterface::setReviveStock(cContextInstHm* pInst, u8 num) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mReviveStock = num;
}

s32 cContextInterface::getReviveType(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        return pInst->getReviveType();
    } else {
        return 0;
    }
}

void cContextInterface::setReviveType(cContextInstance* pInst, s32 type) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mReviveType = type;
                return;
            }
        }
    }
}

void cContextInterface::setReviveType(cContextInstHm* pInst, s32 type) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mReviveType = type;
}

__attribute__((weak)) MtVector3 cContextInterface::getPosFreeMarker(const cContextInstHm* pInst, u32 idx) {
    DDON_STUB("cContextInterface::getPosFreeMarker")
    __builtin_unreachable();
}

__attribute__((weak)) void cContextInterface::setPosFreeMarker(cContextInstHm* pInst, const MtVector3& vPos, u32 idx) {
    DDON_STUB("cContextInterface::setPosFreeMarker")
    /* stub */
}

s32 cContextInterface::getStageNoFreeMarker(const cContextInstHm* pInst, u32 idx) {
    if (pInst != nullptr) {
        return pInst->getStageNoFreeMarker(idx);
    } else {
        return 0;
    }
}

__attribute__((weak)) void cContextInterface::setStageNoFreeMarker(cContextInstHm* pInst, s32 sStageNo, u32 idx) {
    DDON_STUB("cContextInterface::setStageNoFreeMarker")
    /* stub */
}

s32 cContextInterface::getGroupNoFreeMarker(const cContextInstHm* pInst, u32 idx) {
    if (pInst != nullptr) {
        return pInst->getGroupNoFreeMarker(idx);
    } else {
        return 0;
    }
}

__attribute__((weak)) void cContextInterface::setGroupNoFreeMarker(cContextInstHm* pInst, s32 sStageNo, u32 idx) {
    DDON_STUB("cContextInterface::setGroupNoFreeMarker")
    /* stub */
}

f32 cContextInterface::getElementGuardTime(const cContextInstance* pInst) {
    f32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0.0f;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_7 = 0.0f;
                    return v2_7;
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        v2_7 = static_cast<const cContextInstHm*>(pInst)->getElementGuardTime();
    }
    return v2_7;
}

inline f32 cContextInterface::getElementGuardTime(const cContextInstHm* pInst) {
    return pInst->mElementGuardTime;
}

void cContextInterface::setElementGuardTime(cContextInstance* pInst, f32 time) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mElementGuardTime = time;
                return;
            }
        }
    }
}

f32 cContextInterface::getElementCoverRate(const cContextInstance* pInst) {
    f32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0.0f;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_7 = 0.0f;
                    return v2_7;
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        v2_7 = static_cast<const cContextInstHm*>(pInst)->getElementCoverRate();
    }
    return v2_7;
}

void cContextInterface::setElementCoverRate(cContextInstance* pInst, f32 rate) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mElementCoverRate = rate;
                return;
            }
        }
    }
}

nDDOGame::ELEMENT_TYPE cContextInterface::getElementCoverType(const cContextInstance* pInst) {
    nDDOGame::ELEMENT_TYPE v2_7;
    if (pInst == nullptr) {
        v2_7 = nDDOGame::ELEMENT_TYPE_START_ELEMENT;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                v2_7 = static_cast<const cContextInstHm*>(pInst)->getElementCoverType();
                return v2_7;
            }
        }
        v2_7 = nDDOGame::ELEMENT_TYPE_START_ELEMENT;
    }
    return v2_7;
}

void cContextInterface::setElementCoverType(cContextInstance* pInst, nDDOGame::ELEMENT_TYPE type) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mElementCoverType = type;
                return;
            }
        }
    }
}

f32 cContextInterface::getElementCoverDamageRate(const cContextInstance* pInst) {
    f32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0.0f;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_7 = 0.0f;
                    return v2_7;
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        v2_7 = static_cast<const cContextInstHm*>(pInst)->getElementCoverDamageRate();
    }
    return v2_7;
}

inline f32 cContextInterface::getElementCoverDamageRate(const cContextInstHm* pInst) {
    return pInst->mElementCoverDamageRate;
}

void cContextInterface::setElementCoverDamageRate(cContextInstance* pInst, f32 rate) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mElementCoverDamageRate = rate;
                return;
            }
        }
    }
}

f32 cContextInterface::getFJobWork0(const cContextInstance* pInst) {
    f32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0.0f;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_7 = 0.0f;
                    return v2_7;
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        v2_7 = static_cast<const cContextInstHm*>(pInst)->getFJobWork0();
    }
    return v2_7;
}

void cContextInterface::setFJobWork0(cContextInstance* pInst, f32 work) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mFJobWork0 = work;
                return;
            }
        }
    }
}

f32 cContextInterface::getFJobWork1(const cContextInstance* pInst) {
    f32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0.0f;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        if (v0_1 != t0.mName) {
            for (const MtDTI* v0_0 = &t0;;) {
                if (v0_0->mpParent == nullptr) {
                    v2_7 = 0.0f;
                    return v2_7;
                } else {
                    if (v0_1 != v0_0->mpParent->mName) {
                        v0_0 = v0_0->mpParent;
                    } else {
                        break;
                    }
                }
            }
        }
        v2_7 = static_cast<const cContextInstHm*>(pInst)->getFJobWork1();
    }
    return v2_7;
}

void cContextInterface::setFJobWork1(cContextInstance* pInst, f32 work) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mFJobWork1 = work;
                return;
            }
        }
    }
}

s32 cContextInterface::getSJobWork0(const cContextInstance* pInst) {
    s32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                v2_7 = static_cast<const cContextInstHm*>(pInst)->getSJobWork0();
                return v2_7;
            }
        }
        v2_7 = 0;
    }
    return v2_7;
}

inline s32 cContextInterface::getSJobWork0(const cContextInstHm* pInst) {
    return pInst->mSJobWork0;
}

void cContextInterface::setSJobWork0(cContextInstance* pInst, s32 work) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mSJobWork0 = work;
                return;
            }
        }
    }
}

u32 cContextInterface::getHmRandom(const cContextInstance* pInst) {
    u32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                v2_7 = static_cast<const cContextInstHm*>(pInst)->getHmRandom();
                return v2_7;
            }
        }
        v2_7 = 0;
    }
    return v2_7;
}

void cContextInterface::setHmRandom(cContextInstance* pInst, u32 random) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mHmRandom = random;
                return;
            }
        }
    }
}

u8 cContextInterface::getHmEmEditType(const cContextInstance* pInst) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstHm::DTI)) {
        return static_cast<const cContextInstHm*>(pInst)->getHmEmEditType();
    }
    return 0;
}

void cContextInterface::setHmEmEditType(cContextInstance* pInst, u8 type) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mHmEmEditType = type;
                return;
            }
        }
    }
}

__attribute__((weak)) u32 cContextInterface::getHmEmPresetId(const cContextInstance* pInst) {
    DDON_STUB("cContextInterface::getHmEmPresetId")
    return {};
}

void cContextInterface::setHmEmPresetId(cContextInstance* pInst, u32 random) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mHmEmPresetId = random;
                return;
            }
        }
    }
}

u32 cContextInterface::getHmEmId(const cContextInstance* pInst) {
    u32 v2_7;
    if (pInst == nullptr) {
        v2_7 = 0;
    } else {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                v2_7 = static_cast<const cContextInstHm*>(pInst)->getHmEmId();
                return v2_7;
            }
        }
        v2_7 = 0;
    }
    return v2_7;
}

void cContextInterface::setHmEmId(cContextInstance* pInst, u32 id) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mHmEmId = id;
                return;
            }
        }
    }
}

bool cContextInterface::isReturnPrepare(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        return pInst->isReturnPrepare();
    } else {
        return false;
    }
}

void cContextInterface::setIsReturnPrepare(cContextInstHm* pInst, bool flag) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mIsReturnPrepare = flag;
}

bool cContextInterface::isAreaChangePrepare(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        return pInst->isAreaChangePrepare();
    } else {
        return false;
    }
}

void cContextInterface::setIsAreaChangePrepare(cContextInstHm* pInst, bool flag) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mIsAreaChangePrepare = flag;
}

bool cContextInterface::isReqSetLostAction(const cContextInstance* pInst) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstHm::DTI)) {
        return static_cast<const cContextInstHm*>(pInst)->isReqSetLostAction();
    }
    return false;
}

void cContextInterface::reqSetLostAction(cContextInstance* pInst, bool flag) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mReqSetLostAction = flag;
                return;
            }
        }
    }
}

void cContextInterface::reqSetLostAction(cContextInstHm* pInst, bool flag) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mReqSetLostAction = flag;
}

s32 cContextInterface::getOldGaugeContextType(const cContextInstHm* pInst) {
    if (pInst != nullptr) {
        return pInst->getOldGaugeContextType();
    } else {
        return 0;
    }
}

void cContextInterface::setOldGaugeContextType(cContextInstHm* pInst, s32 type) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mOldGaugeContextType = type;
}

bool cContextInterface::isAbility098(const cContextInstance* pInst) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstHm::DTI)) {
        return static_cast<const cContextInstHm*>(pInst)->isAbility098();
    }
    return false;
}

void cContextInterface::setIsAbility098(cContextInstance* pInst, bool flag) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mIsAbility098 = flag;
                return;
            }
        }
    }
}

bool cContextInterface::isGutsDisable(const cContextInstance* pInst) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstHm::DTI)) {
        return static_cast<const cContextInstHm*>(pInst)->isGutsDisable();
    }
    return false;
}

void cContextInterface::setIsGutsDisable(cContextInstance* pInst, bool flag) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mIsGutsDisable = flag;
                break;
            }
        }
    }
    if (flag) {
        if (pInst != nullptr) {
            const MtDTI& t1 = pInst->getDTI();
            MT_CTSTR v2_1 = cContextInstChar::DTI.mName;
            for (const MtDTI* v2_0 = &t1;;) {
                if (v2_1 != v2_0->mName) {
                    if (v2_0->mpParent != nullptr) {
                        v2_0 = v2_0->mpParent;
                    } else {
                        break;
                    }
                } else {
                    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(pInst) + 446) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(pInst) + 446)) | 8;
                    return;
                }
            }
        }
    } else {
        if (pInst != nullptr) {
            const MtDTI& t2 = pInst->getDTI();
            MT_CTSTR v4_1 = cContextInstChar::DTI.mName;
            for (const MtDTI* v4_0 = &t2;;) {
                if (v4_1 != v4_0->mName) {
                    if (v4_0->mpParent != nullptr) {
                        v4_0 = v4_0->mpParent;
                    } else {
                        break;
                    }
                } else {
                    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(pInst) + 446) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(pInst) + 446)) & 247;
                    return;
                }
            }
        }
    }
}

void cContextInterface::setIsGutsDisable(cContextInstHm* pInst, bool flag) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mIsGutsDisable = flag;
}

bool cContextInterface::isAbility370(const cContextInstance* pInst) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstHm::DTI)) {
        return static_cast<const cContextInstHm*>(pInst)->isAbility370();
    }
    return false;
}

void cContextInterface::setIsAbility370(cContextInstance* pInst, bool flag) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mIsAbility370 = flag;
                return;
            }
        }
    }
}

bool cContextInterface::isSyncCustomSkillGroup(const cContextInstance* pInst) {
    if ((pInst != nullptr) && pInst->getDTI().MtDTI::operator==(cContextInstHm::DTI)) {
        return static_cast<const cContextInstHm*>(pInst)->isSyncCustomSkillGroup();
    }
    return false;
}

void cContextInterface::setIsSyncCustomSkillGroup(cContextInstance* pInst, bool flag) {
    if (pInst != nullptr) {
        const MtDTI& t0 = pInst->getDTI();
        MT_CTSTR v0_1 = cContextInstHm::DTI.mName;
        for (const MtDTI* v0_0 = &t0;;) {
            if (v0_1 != v0_0->mName) {
                if (v0_0->mpParent != nullptr) {
                    v0_0 = v0_0->mpParent;
                } else {
                    break;
                }
            } else {
                static_cast<cContextInstHm*>(pInst)->mIsSyncCustomSkillGroup = flag;
                return;
            }
        }
    }
}

void cContextInterface::setIsSyncCustomSkillGroup(cContextInstHm* pInst, bool flag) {
    if (pInst == nullptr) {
        return;
    }
    pInst->mIsSyncCustomSkillGroup = flag;
}

void cContextInterface::copySendData(cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->copySendData(mpContextInstance);
}

__attribute__((weak)) const nNetMsgData::stNetPos& cContextInterface::getSendBuffNetPos(const cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::getSendBuffNetPos")
    __builtin_unreachable();
}

f32 cContextInterface::getSendBuffMoveSpeed(const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->mSendDataBuff.mMoveSpeed;
    } else {
        return 0.0f;
    }
}

f32 cContextInterface::getSendBuffMoveAngle(const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->mSendDataBuff.mMoveAngle;
    } else {
        return 0.0f;
    }
}

f32 cContextInterface::getSendBuffNetDir(const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->mSendDataBuff.mNetDir;
    } else {
        return 0.0f;
    }
}

__attribute__((weak)) u32 cContextInterface::getSendBuffActNo(const cContextCharacter* pChara, u32 idx) {
    DDON_STUB("cContextInterface::getSendBuffActNo")
    return {};
}

u8 cContextInterface::getSendBuffActReqPrio(const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->mSendDataBuff.mActReqPrio;
    } else {
        return 1;
    }
}

u16 cContextInterface::getSendBuffActAtkAdjustUniqueId(const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->mSendDataBuff.mActAtkAdjustUniqueId;
    } else {
        return 0;
    }
}

u32 cContextInterface::getSendBuffActFreeWork(const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->mSendDataBuff.mActFreeWork;
    } else {
        return 0;
    }
}

__attribute__((weak)) f32 cContextInterface::getSendBuffHp(const cContextCharacter* pChara, u32 i) {
    DDON_STUB("cContextInterface::getSendBuffHp")
    return {};
}

HP_DATATYPE cContextInterface::getSendBuffHpWhite(const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->mSendDataBuff.mHpWhite;
    } else {
        return 0;
    }
}

u16 cContextInterface::getSendBuffCommonWork(const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->mSendDataBuff.mCommonWork;
    } else {
        return 0;
    }
}

u16 cContextInterface::getSendBuffCustomWork(const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->mSendDataBuff.mCustomWork;
    } else {
        return 0;
    }
}

__attribute__((weak)) const nObjCondition::stHolyAbsorpReqInfo& cContextInterface::getAbsorpReqInfoTop(const cContextInstance* pInst, const cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::getAbsorpReqInfoTop")
    __builtin_unreachable();
}

void cContextInterface::clearAbsorpReqInfoTop(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->clearAbsorpReqInfoTop();
}

void cContextInterface::registAbsorpReqMsg(cContextInstance* pInst, cContextCharacter* pChara, const nObjCondition::stHolyAbsorpReqMsg& srcMsg) {
    if (pChara == nullptr) {
        return;
    }
    pChara->registAbsorpReqMsg(srcMsg);
}

u32 cContextInterface::getAbsorpReqNum(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getAbsorpReqNum();
    } else {
        return 0;
    }
}

void cContextInterface::clearAbsorpReqArray(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->clearAbsorpReqArray();
}

bool cContextInterface::isAbsorpNetFlagOn(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->isAbsorpNetFlagOn();
    } else {
        return false;
    }
}

void cContextInterface::cancelAbsorpNetFlag(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->cancelAbsorpNetFlag();
}

void cContextInterface::absorpNetFlagOn(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->absorpNetFlagOn();
}

__attribute__((weak)) const nObjCondition::stHolyAbsorpReqInfo& cContextInterface::getSoulAbsorpReqInfoTop(const cContextInstance* pInst, const cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::getSoulAbsorpReqInfoTop")
    __builtin_unreachable();
}

void cContextInterface::clearSoulAbsorpReqInfoTop(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->clearSoulAbsorpReqInfoTop();
}

void cContextInterface::registSoulAbsorpReqMsg(cContextInstance* pInst, cContextCharacter* pChara, const nObjCondition::stHolyAbsorpReqMsg& srcMsg) {
    if (pChara == nullptr) {
        return;
    }
    pChara->registSoulAbsorpReqMsg(srcMsg);
}

u32 cContextInterface::getSoulAbsorpReqNum(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getSoulAbsorpReqNum();
    } else {
        return 0;
    }
}

void cContextInterface::clearSoulAbsorpReqArray(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->clearSoulAbsorpReqArray();
}

bool cContextInterface::isSoulAbsorpNetFlagOn(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->isSoulAbsorpNetFlagOn();
    } else {
        return false;
    }
}

void cContextInterface::cancelSoulAbsorpNetFlag(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->cancelSoulAbsorpNetFlag();
}

void cContextInterface::soulAbsorpNetFlagOn(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->soulAbsorpNetFlagOn();
}

__attribute__((weak)) const nHuman::stShellRequestInfo& cContextInterface::getShellRequestInfoTop(const cContextInstance* pInst, const cContextCharacter* pChara) {
    DDON_STUB("cContextInterface::getShellRequestInfoTop")
    __builtin_unreachable();
}

void cContextInterface::clearShellRequestInfoTop(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->clearShellRequestInfoTop();
}

void cContextInterface::registShellRequestMsg(cContextInstance* pInst, cContextCharacter* pChara, const nHuman::stShellRequestMsg& srcMsg) {
    if (pChara == nullptr) {
        return;
    }
    pChara->registShellRequestMsg(srcMsg);
}

u32 cContextInterface::getShellRequestNum(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->getShellRequestInfoNum();
    } else {
        return 0;
    }
}

void cContextInterface::clearShellRequestArray(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->clearShellRequestInfoArray();
}

bool cContextInterface::isShellRequestNetFlagOn(const cContextInstance* pInst, const cContextCharacter* pChara) {
    if (pChara != nullptr) {
        return pChara->isShellRequestNetFlagOn();
    } else {
        return false;
    }
}

void cContextInterface::cancelShellRequestNetFlag(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->cancelShellRequestNetFlag();
}

void cContextInterface::shellRequestNetFlagOn(cContextInstance* pInst, cContextCharacter* pChara) {
    if (pChara == nullptr) {
        return;
    }
    pChara->shellRequestNetFlagOn();
}

inline cContextInterface::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cContextInterface::MyDTI cContextInterface::DTI("cContextInterface", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* cContextInterface::MyDTI::newInstance() const {
    return new (16u) cContextInterface;
}

