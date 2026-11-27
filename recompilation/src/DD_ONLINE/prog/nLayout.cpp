// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nLayout.h"
#include "../../MT/MtDTI.h"
#include "Protocol/PacketData/Stage.h"
#include "cNetGameServer.h"
#include "cSetInfoEnemy.h"
#include "cSetInfoGeneralPoint.h"
#include "cSetInfoNpc.h"
#include "cSetInfoOm.h"
#include "nQuest.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sQuestManagerExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

namespace nLayout {
static const MtDTI* SetInfoDtiTable[28] = {
    &cSetInfoOm::DTI,
    &cSetInfoEnemy::DTI,
    &cSetInfoNpc::DTI,
    &cSetInfoGeneralPoint::DTI,
    &cSetInfoOmGather::DTI,
    &cSetInfoOmLadder::DTI,
    &cSetInfoOmWarp::DTI,
    &cSetInfoOmTreasureBox::DTI,
    &cSetInfoOmBoard::DTI,
    &cSetInfoOmCtrl::DTI,
    &cSetInfoOmElfSW::DTI,
    &cSetInfoOmFall::DTI,
    &cSetInfoOmLever::DTI,
    &cSetInfoOmRange::DTI,
    &cSetInfoOmText::DTI,
    &cSetInfoOmWall::DTI,
    &cSetInfoOmHakuryuu::DTI,
    &cSetInfoOmDoor::DTI,
    &cSetInfoOmBowlOfLife::DTI,
    &cSetInfoOmNav::DTI,
    &cSetInfoOmHeal::DTI,
    &cSetInfoOmBadStatus::DTI,
    &cSetInfoOmBlock::DTI,
    &cSetInfoOmEx::DTI,
    &cSetInfoOmOldDoor::DTI,
    &cSetInfoOmOneWay::DTI,
    &cSetInfoOmBreakTarget::DTI,
    nullptr,
};
}

__attribute__((weak)) u32 nLayout::createUniqueID(nLayout::U_KIND kind, u32 layoutGroup, u32 layoutId, s32 stageNo) {
    s32 stageId = static_cast<sAreaExt*>(sArea::getInstance())->convertStageId(stageNo);
    return (static_cast<u32>(kind) & 7u) | ((static_cast<u32>(stageId) & 0x1ffu) << 3) | ((layoutGroup & 0x1ffu) << 12) | ((layoutId & 0x1fu) << 21) | 0x80000000u;
}

__attribute__((weak)) u32 nLayout::createUniqueID(nLayout::U_KIND kind, u32 layoutGroup, u32 layoutId, u32 innerId, s32 stageNo) {
    s32 stageId = static_cast<const sAreaExt*>(sAreaExt::getInstance())->convertStageId(stageNo);
    
    u32 uniqueid = ((static_cast<u32>(kind) & 0x7u) + ((layoutGroup << 12) & 0x1ff000u))
        | ((layoutId & 0x1fu) << 21)
        | (innerId << 26)
        | ((static_cast<u32>(stageId) << 3) & 0xff8u)
        | 0x80000000u;
    return uniqueid;
}

__attribute__((weak)) u32 nLayout::createUniqueIDQuestProcess(u32 q_no, u32 blockNo, s32 stageNo, u8 processNo) {
    DDON_STUB("nLayout::createUniqueIDQuestProcess")
    return {};
}

__attribute__((weak)) u32 nLayout::createUniqueIDQuestSet(u32 QuestNo, s32 StageNo, u32 LayoutGroup, u32 LayoutId) {
    DDON_STUB("nLayout::createUniqueIDQuestSet")
    return {};
}

u32 nLayout::createUniqueIDQuestSetSeq(u32 QuestSeq, s32 StageNo, u32 LayoutGroup, u32 LayoutId) {
    return static_cast<unsigned int>(((static_cast<unsigned long>(((LayoutGroup & 15u) * 0x800000u) + ((QuestSeq * 4096u) & 0x7FF000u)) | static_cast<unsigned long>(LayoutId * 0x8000000u)) | static_cast<unsigned long>((static_cast<sAreaExt*>(sArea::getInstance())->convertStageId(StageNo) * 8) & 0xFF8)) | 0x80000007ul);
}

u32 nLayout::getUniqueIDStageId(u32 uniqueId) {
    return (uniqueId >> 3) & 511u;
}

u32 nLayout::getUniqueIDLayoutGroup(u32 uniqueId) {
    return (uniqueId >> 12) & 511u;
}

u32 nLayout::getUniqueIDLayoutID(u32 uniqueId) {
    return (uniqueId >> 21) & 31u;
}

u32 nLayout::getUniqueIDInnerID(u32 uniqueId) {
    return (uniqueId >> 26) & 31u;
}

u32 nLayout::delInnerIDToUniqueID(u32 uniqueId) {
    return (uniqueId & 0x3FFFFFFu) - 0x80000000u;
}

u32 nLayout::getUniqueIdQstSeq(u32 uniqueId) {
    return (uniqueId >> 12) & 2047u;
}

__attribute__((weak)) CDataStageLayoutID nLayout::createStageLayoutId(u32 stageNo, u32 layerNo, u32 groupNo) {
    DDON_STUB("nLayout::createStageLayoutId")
    __builtin_unreachable();
}

__attribute__((weak)) const MtDTI* nLayout::getSetInfoDtiFromTable(s32 index) {
        if (index >= 0 && static_cast<u32>(index) < 28u) {
            return SetInfoDtiTable[index];
        }
        return nullptr;
}

