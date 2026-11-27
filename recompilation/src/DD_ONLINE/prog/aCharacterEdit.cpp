// Reconstructed from the game's DWARF debug information.
#include <new>
#include "aCharacterEdit.h"
#include "Protocol/PacketData/Community.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtString.h"
#include "aStage.h"
#include "cArcLoader.h"
#include "cCharacterData.h"
#include "cContextInterface.h"
#include "cEditParam.h"
#include "cEquipData.h"
#include "cNetGameServer.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "nCharacterData.h"
#include "nJobParam.h"
#include "rArchiveListArray.h"
#include "rCharacterEdit.h"
#include "../../XFramework/rSoundStreamRequest.h"
#include "sArchiveManager.h"
#include "sContextManager.h"
#include "sDialogBase.h"
#include "sFlag.h"
#include "sGame.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/sUnit.h"
#include "uCharacterEdit.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& aCharacterEditGame::getDTI() const {
    return aCharacterEditGame::DTI;
}

aCharacterEditGame::aCharacterEditGame() {
    DDON_STUB("aCharacterEditGame::aCharacterEditGame")
    /* stub */
}

__attribute__((noinline)) aCharacterEditGame::~aCharacterEditGame() {
    DDON_STUB("aCharacterEditGame::~aCharacterEditGame")
    /* stub */
}

void aCharacterEditGame::init() {
    this->aStage::init();
    mEditType = sGame::getInstance()->getCharEditType();
    mCharEditPawnSlotNo = sGame::getInstance()->getCharEditPawnSlotNo();
}

void aCharacterEditGame::move() {
    if (mpCharacterEdit != nullptr) {
        if (!mpCharacterEdit->isEnable()) {
            mpCharacterEdit = nullptr;
        }
    }
    this->aStage::move();
}

__attribute__((weak)) void aCharacterEditGame::moveMain() {
    DDON_STUB("aCharacterEditGame::moveMain")
    /* stub */
}

void aCharacterEditGame::final() {
    if (mprBgm != nullptr) {
        mprBgm->release();
        mprBgm = nullptr;
    }
    this->aStage::final();
}

inline aCharacterEditGame::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

aCharacterEditGame::MyDTI aCharacterEditGame::DTI("aCharacterEditGame", &::aStage::DTI, 7600ul, 0u, 0u);

__attribute__((weak)) MtObject* aCharacterEditGame::MyDTI::newInstance() const {
    DDON_STUB("aCharacterEditGame::MyDTI::newInstance")
    return nullptr;
}

