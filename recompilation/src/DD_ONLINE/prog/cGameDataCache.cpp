// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "cGameDataCache.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "nDDOUtility.h"
#include "sFlag.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nLayout::cGameDataCache::getDTI() const {
    return nLayout::cGameDataCache::DTI;
}

nLayout::cGameDataCache::cGameDataCache() {
    ::memset(static_cast<void*>(&mBuff), 0, 260ul);
}

void nLayout::cGameDataCache::setGameData(u32 data, bool isSend) {
    if ((data & 15u) != 1) {
        return;
    }
    if ((data & 16u) != 0) {
        ::sFlag::getInstance()->setFlag(2u, (data & 0x1FFE0u) + ((data >> 17) & 4095u), true, isSend, true);
    } else {
        ::sFlag::getInstance()->setFlag(2u, (data & 0x1FFE0u) + ((data >> 17) & 4095u), false, isSend, true);
    }
}

inline nLayout::cGameDataCache::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nLayout::cGameDataCache::MyDTI nLayout::cGameDataCache::DTI("cGameDataCache", &::MtObject::DTI, 272ul, 0u, 0u);

MtObject* nLayout::cGameDataCache::MyDTI::newInstance() const {
    return new (16u) ::nLayout::cGameDataCache;
}

