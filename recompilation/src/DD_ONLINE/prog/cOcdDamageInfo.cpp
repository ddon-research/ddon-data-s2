// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cOcdDamageInfo.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../generated/shared/nDDOGame.h"
#include "nObjCollision.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cOcdDamageInfo::getDTI() const {
    return cOcdDamageInfo::DTI;
}

cOcdDamageInfo::cOcdDamageInfo() {
    DDON_STUB("cOcdDamageInfo::cOcdDamageInfo")
    /* stub */
}

__attribute__((weak)) cOcdDamageInfo::stDamageData* cOcdDamageInfo::getOcdDataFromUID(u32 OcdUID) {
    DDON_STUB("cOcdDamageInfo::getOcdDataFromUID")
    return nullptr;
}

cOcdDamageInfo::stDamageData* cOcdDamageInfo::getOcdDataFromIndex(u32 index) {
    return &mOcdBadData[index];
}

cOcdDamageInfo::stDamageData* cOcdDamageInfo::getOcdDataEnchantTarget(nDDOGame::ELEMENT_TYPE type) {
    switch (static_cast<unsigned int>(type - 2)) {
        case 0:
        {
            return &mOcdBadData[11];
        }
        case 1:
        {
            return &mOcdBadData[12];
        }
        case 2:
        {
            return &mOcdBadData[13];
        }
        case 3:
        {
            return &mOcdBadData[14];
        }
        case 4:
        {
            return &mOcdBadData[15];
        }
        default:
        {
            return nullptr;
        }
    }
}

__attribute__((weak)) void cOcdDamageInfo::getInfoFromCM(const cHitInfoAfterCommon& info) {
}

inline cOcdDamageInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cOcdDamageInfo::MyDTI cOcdDamageInfo::DTI("cOcdDamageInfo", &::MtObject::DTI, 1648ul, 0u, 0u);

__attribute__((weak)) MtObject* cOcdDamageInfo::MyDTI::newInstance() const {
    DDON_STUB("cOcdDamageInfo::MyDTI::newInstance")
    return nullptr;
}

