// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uControlEnemy.h"
#include "Protocol/PacketData/Enemy.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cContext.h"
#include "cContextInstance.h"
#include "cContextInterface.h"
#include "cpLayout.h"
#include "rLayoutGroupParam.h"
#include "sContextManager.h"
#include "sControlManager.h"
#include "uControl.h"
#include "uEnemy.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uControlEnemy::getDTI() const {
    return uControlEnemy::DTI;
}

uControlEnemy::~uControlEnemy() {
}

void uControlEnemy::createProperty(MtPropertyList& s) {
    this->uControl::createProperty(s);
}

void uControlEnemy::move() {
    this->uControl::move();
    if (mpModel != nullptr) {
        return;
    }
    const cGroupParam* pGrp = mLayout.getGroupParam();
    if (pGrp == nullptr) {
        return;
    }
    if (static_cast<unsigned short>(pGrp->getInvalidFlag()) != 0) {
        sControlManager::getInstance()->releaseUnit(static_cast<uControl*>(this));
    }
    if (pGrp->isWaitRepop(static_cast<u32>(mLayout.getSetNo()))) {
        sControlManager::getInstance()->releaseUnit(static_cast<uControl*>(this));
        mIsSelfDeleteContextInst = true;
        sContextManager::getInstance()->removeContext(static_cast<cContext*>(getContextInst()));
    }
    if ((mUnitId - 337u) <= 19u) {
        if (cContextInterface::getSetWaitFlag(mContextInterface.mpContextInstance)) {
            cContextInterface::setSetWaitFlag(mContextInterface.mpContextInstance, false);
        }
    }
}

void uControlEnemy::updatePtr() {
    this->uControl::updatePtr();
}

void uControlEnemy::setup() {
    this->uControl::setup();
}

void uControlEnemy::setOwner(uDDOModel* pOwner) {
    mpModel = pOwner;
}

bool uControlEnemy::isHumanEnemy() {
    return (mUnitId - 149u) <= 56u;
}

__attribute__((weak)) MT_CTSTR uControlEnemy::getName() {
    DDON_STUB("uControlEnemy::getName")
    return {};
}

inline uControlEnemy::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uControlEnemy::MyDTI uControlEnemy::DTI("uControlEnemy", &::uControl::DTI, 776ul, 0u, 0u);

MtObject* uControlEnemy::MyDTI::newInstance() const {
    return new (16u) uControlEnemy;
}

