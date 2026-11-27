// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nHumanMsg.h"
#include "../../generated/shared/nHuman.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

u32 nHuman::getJobArrayIndex(nHuman::JOB_ENUM jobId) {
    return (((jobId == nHuman::JOB_ID_ERROR) || (static_cast<int>(jobId) > 10)) == false) ? static_cast<unsigned int>(jobId - 1) : 0u;
}

u32 nHuman::getRoleArrayIndex(nHuman::ROLE_ENUM roleId) {
    return (static_cast<unsigned int>(roleId - 1) <= 2) ? static_cast<unsigned int>(roleId - 1) : 0u;
}

u32 nHuman::getCustomSkillIdArrayIndex(nHuman::CUSTOM_SKILL_ENUM id) {
    return (((id == nHuman::CUSTOM_SKILL_ID_ERROR) || (static_cast<int>(id) > 20)) == false) ? static_cast<unsigned int>(id - 1) : 0u;
}

bool nHuman::isEnableCustomSkillId(nHuman::CUSTOM_SKILL_ENUM id) {
    return static_cast<unsigned int>(id - 1) <= 19;
}

bool nHuman::CSGroupConvertCSMsg2Info(const u8 csSlotMsg, nHuman::CUSTOM_SKILL_GROUP& group, u8& slot) {
    slot = csSlotMsg & 15;
    if (csSlotMsg > 31) {
        return false;
    } else {
        group = static_cast<nHuman::CUSTOM_SKILL_GROUP>(static_cast<unsigned long>(csSlotMsg) >> 4);
        return true;
    }
}

__attribute__((weak)) bool nHuman::CSGroupConvertInfo2CSMsg(const u8 group, const u8 slot, u8& csSlotMsg) {
    DDON_STUB("nHuman::CSGroupConvertInfo2CSMsg")
    return {};
}

u32 nHuman::getNormalSkillIdArrayIndex(nHuman::GROW_NORMAL_SKILL_ENUM id) {
    return (static_cast<int>(id) <= 10) ? static_cast<unsigned int>(id - 1) : 0u;
}

