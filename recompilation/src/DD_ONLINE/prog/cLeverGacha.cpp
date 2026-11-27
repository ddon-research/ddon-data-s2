// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cLeverGacha.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cContextPlayerInfo.h"
#include "cpInput.h"
#include "cpPawnThink.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sInputManager.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sMouse.h"
#include "sMouseExt.h"
#include "sPlayerManager.h"
#include "sQuestManagerExt.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cLeverGacha::getDTI() const {
    return cLeverGacha::DTI;
}

cLeverGacha::cLeverGacha() {
    mCntMax = 0;
    mResult = false;
    mOldMouseZ = 0;
    mOldMouseX = 0;
    mOldMouseY = 0;
    mOldLvLx = 0.0f;
    mOldLvLy = 0.0f;
    mCnt = 0.0f;
    mOldAngleType = 0;
}

void cLeverGacha::createProperty(MtPropertyList& proplist) {
    proplist << MtProperty(static_cast<MtObject*>(this), "mCnt", &mCnt, 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mCntMax", &mCntMax, 0u, 0u);
}

void cLeverGacha::initLeverGacha(s32 count) {
    mCntMax = count;
    mResult = false;
    mOldMouseZ = 0;
    mOldMouseX = 0;
    mOldMouseY = 0;
    mOldLvLx = 0.0f;
    mOldLvLy = 0.0f;
    mCnt = 0.0f;
    mOldAngleType = 0;
}

__attribute__((weak)) bool cLeverGacha::checkLeverGacha(const cpInput& Input, const uDDOModel* pModel) {
    DDON_STUB("cLeverGacha::checkLeverGacha")
    return {};
}

inline cLeverGacha::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cLeverGacha::MyDTI cLeverGacha::DTI("cLeverGacha", &::MtObject::DTI, 48ul, 0u, 0u);

MtObject* cLeverGacha::MyDTI::newInstance() const {
    return new (16u) cLeverGacha;
}

