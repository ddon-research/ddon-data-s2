// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sClanKyoten.h"
#include "Protocol/PacketData/Common.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cSystem.h"
#include "cTalkMsgData.h"
#include "sArchiveManager.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sOmManager.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "uGUIClanEmblem.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sClanKyoten::getDTI() const {
    return sClanKyoten::DTI;
}

void* sClanKyoten::operator new(size_t sz, u32 align) {
    return sClanKyoten::getAllocator()->memAlloc(sz, align, sClanKyoten::DTI.getID());
}

sClanKyoten::sClanKyoten() {
    sClanKyoten::mpInstance = this;
    mbOpenLot[5] = false;
    mbOpenLot[3] = false;
    mbOpenLot[4] = false;
    mbClanK = false;
    mbOpenLot[0] = false;
    mbOpenLot[1] = false;
    mbOpenLot[2] = false;
    initPawn();
    initShop();
}

sClanKyoten::~sClanKyoten() {
}

void sClanKyoten::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mbClanK", &mbClanK, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "１Ｆ解放", &mbOpenLot[1], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "１Ｆ踊り場解放", &mbOpenLot[2], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "２Ｆ解放", &mbOpenLot[3], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "クランフラッグ解放", &mbOpenLot[4], 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "ポーン隊解放", &mbOpenLot[5], 0u, 0u);
    createPawnProperty(s);
    createShopProperty(s);
}

__attribute__((weak)) void sClanKyoten::reset() {
}

void sClanKyoten::final() {
    finalPawn();
    finalShop();
}

void sClanKyoten::move() {
    if (!mbClanK) {
        return;
    }
    movePawn();
    moveShop();
}

__attribute__((weak)) void sClanKyoten::initLobby() {
}

__attribute__((weak)) void sClanKyoten::finalLobby() {
}

__attribute__((weak)) void sClanKyoten::initKyoten(bool isClanK) {
    DDON_STUB("sClanKyoten::initKyoten")
    /* stub */
}

void sClanKyoten::finalKyoten() {
    sOmManager::getInstance()->mCETC.release();
    finalPawnKyoten();
    finalShopKyoten();
}

bool sClanKyoten::isEnableReleaseTalk() {
    if (!static_cast<sNetworkExt*>(sNetwork::getInstance())->mIsClanBaseRelease) {
        if (static_cast<sNetworkExt*>(sNetwork::getInstance())->isClanMember(static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->getCharacterId())) {
            if (static_cast<sNetworkExt*>(sNetwork::getInstance())->isClanLeader()) {
                return static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mMyClanParam.m_ClanServerParam.m_bCanClanBaseRelease;
            }
        }
    }
    return false;
}

void sClanKyoten::clrOpenLot() {
    mbOpenLot[4] = false;
    mbOpenLot[5] = false;
    mbOpenLot[0] = false;
    mbOpenLot[1] = false;
    mbOpenLot[2] = false;
    mbOpenLot[3] = false;
}

__attribute__((weak)) void sClanKyoten::initPawn() {
}

__attribute__((weak)) void sClanKyoten::finalPawn() {
}

__attribute__((weak)) void sClanKyoten::movePawn() {
}

__attribute__((weak)) void sClanKyoten::initPawnExpeditionTalkMsgDataCore(cTalkMsgData* pTalkData, u32 Personality) {
    DDON_STUB("sClanKyoten::initPawnExpeditionTalkMsgDataCore")
    /* stub */
}

cTalkMsgData* sClanKyoten::getPawnExpeditionTalkMsgData(u32 Personality) {
    return &mPawnExpeditionTalkData[Personality];
}

__attribute__((weak)) void sClanKyoten::initPawnClanBaseTalkMsgDataCore(cTalkMsgData* pTalkData, u32 Personality) {
    DDON_STUB("sClanKyoten::initPawnClanBaseTalkMsgDataCore")
    /* stub */
}

cTalkMsgData* sClanKyoten::getPawnClanBaseTalkMsgData(u32 Personality) {
    return &mPawnClanBaseTalkData[Personality];
}

__attribute__((weak)) bool sClanKyoten::isReleasePawnExpedition() const {
    DDON_STUB("sClanKyoten::isReleasePawnExpedition")
    return {};
}

__attribute__((weak)) void sClanKyoten::initPawnKyoten() {
    DDON_STUB("sClanKyoten::initPawnKyoten")
    /* stub */
}

__attribute__((weak)) void sClanKyoten::finalPawnKyoten() {
    mPawnExpeditionTalkData[0].reset();
    mPawnClanBaseTalkData[0].reset();
    mPawnExpeditionTalkData[1].reset();
    mPawnClanBaseTalkData[1].reset();
    mPawnExpeditionTalkData[2].reset();
    mPawnClanBaseTalkData[2].reset();
    mPawnExpeditionTalkData[3].reset();
    mPawnClanBaseTalkData[3].reset();
    mPawnExpeditionTalkData[4].reset();
    mPawnClanBaseTalkData[4].reset();
    mPawnExpeditionTalkData[5].reset();
    mPawnClanBaseTalkData[5].reset();
    mPawnExpeditionTalkData[6].reset();
    mPawnClanBaseTalkData[6].reset();
    mPawnExpeditionTalkData[7].reset();
    mPawnClanBaseTalkData[7].reset();
    mPawnExpeditionTalkData[8].reset();
    mPawnClanBaseTalkData[8].reset();
}

__attribute__((weak)) void sClanKyoten::createPawnProperty(MtPropertyList& s) {
}

__attribute__((weak)) void sClanKyoten::initShop() {
}

__attribute__((weak)) void sClanKyoten::finalShop() {
}

__attribute__((weak)) void sClanKyoten::moveShop() {
}

__attribute__((weak)) void sClanKyoten::initShopKyoten() {
}

__attribute__((weak)) void sClanKyoten::finalShopKyoten() {
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->clearClanShopGetFunctionItemListPacket();
    static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->clearClanShopGetBuffItemListPacket();
}

__attribute__((weak)) void sClanKyoten::createShopProperty(MtPropertyList& s) {
}

inline sClanKyoten::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sClanKyoten::MyDTI sClanKyoten::DTI("sClanKyoten", &::cSystem::DTI, 1464ul, 0u, 0u);

sClanKyoten* sClanKyoten::mpInstance;

MtObject* sClanKyoten::MyDTI::newInstance() const {
    return new (16u) sClanKyoten;
}

