// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cEditChargeInfoUpdator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cNetGameServer.h"
#include "sItemManager.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cEditChargeInfoUpdator::getDTI() const {
    return cEditChargeInfoUpdator::DTI;
}

cEditChargeInfoUpdator::cEditChargeInfoUpdator() {
    mRno = ROUTINE_BUY_INIT;
    mResultType = RESULT_NONE;
}

void cEditChargeInfoUpdator::init() {
    mRno = ROUTINE_BUY_INIT;
    mResultType = RESULT_NONE;
}

void cEditChargeInfoUpdator::move() {
    switch (mRno) {
        case ROUTINE_BUY_INIT:
        {
            mRno = ROUTINE_BUY_REQ;
            break;
        }
        case ROUTINE_BUY_REQ:
        {
            static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getPawnVoiceListReq();
            mRno = ROUTINE_BUY_WAIT;
            break;
        }
        case ROUTINE_BUY_WAIT:
        {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[230] != sNetworkExt::NET_STAT_ERROR) {
                if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[230] == sNetworkExt::NET_STAT_CANCEL) {
                    mRno = ROUTINE_BUY_ERROR;
                } else {
                    if (static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[230] == sNetworkExt::NET_STAT_SUCCESS) {
                        mRno = ROUTINE_GET_GP_INIT;
                    }
                }
            } else {
                mRno = ROUTINE_BUY_ERROR;
                mResultType = RESULT_ERROR;
            }
            break;
        }
        case ROUTINE_BUY_ERROR:
        {
            if (!static_cast<sNetworkExt*>(sNetwork::getInstance())->isDispErrorDialog()) {
                mRno = ROUTINE_END;
                mResultType = RESULT_ERROR;
            }
            break;
        }
        case ROUTINE_GET_GP_INIT:
        {
            mRno = ROUTINE_GET_GP_REQ;
            break;
        }
        case ROUTINE_GET_GP_REQ:
        {
            sItemManager::getInstance()->reqGetGP();
            mRno = ROUTINE_GET_GP_REQ_WAIT;
            break;
        }
        case ROUTINE_GET_GP_REQ_WAIT:
        {
            switch (static_cast<unsigned int>(static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mStatus[204] - 1)) {
                case 0:
                {
                    break;
                }
                case 1:
                {
                    mRno = ROUTINE_END;
                    mResultType = RESULT_OK;
                    break;
                }
                case 2:
                {
                    mRno = ROUTINE_END;
                    break;
                }
                case 3:
                {
                    mRno = ROUTINE_GET_GP_ERROR;
                    break;
                }
                default:
                {
                    mRno = ROUTINE_GET_GP_ERROR;
                    break;
                }
            }
            break;
        }
        case ROUTINE_GET_GP_ERROR:
        {
            if (!static_cast<sNetworkExt*>(sNetwork::getInstance())->isDispErrorDialog()) {
                mRno = ROUTINE_END;
                mResultType = RESULT_ERROR;
            }
            break;
        }
        default:
        {
            break;
        }
    }
}

__attribute__((weak)) void cEditChargeInfoUpdator::final() {
}

bool cEditChargeInfoUpdator::isEnd() const {
    return mResultType != RESULT_NONE;
}

inline cEditChargeInfoUpdator::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cEditChargeInfoUpdator::MyDTI cEditChargeInfoUpdator::DTI("cEditChargeInfoUpdator", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cEditChargeInfoUpdator::MyDTI::newInstance() const {
    return new (16u) cEditChargeInfoUpdator;
}

