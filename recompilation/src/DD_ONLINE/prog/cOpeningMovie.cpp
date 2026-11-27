// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cOpeningMovie.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/rScheduler.h"
#include "sArchiveManager.h"
#include "../../XFramework/sCamera.h"
#include "sCameraExt.h"
#include "sFlag.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sInputManager.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sSound.h"
#include "sSoundExt.h"
#include "../../XFramework/sUnit.h"
#include "sUnitExt.h"
#include "uGUIEventSkip.h"
#include "uGUISystemMsg.h"
#include "../../XFramework/uMovie.h"
#include "../../XFramework/uScheduler.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cOpeningMovie::getDTI() const {
    return cOpeningMovie::DTI;
}

void* cOpeningMovie::operator new(size_t sz, u32 align) {
    return cOpeningMovie::getAllocator()->memAlloc(sz, align, cOpeningMovie::DTI.getID());
}

cOpeningMovie::cOpeningMovie() {
    mRno0 = 0;
    mRno1 = 0;
    mEndFadeType = 1;
    mMovieState = 0;
    mpMovie = nullptr;
    mpScheduler = nullptr;
    mMovieSyncTimer = 0.0f;
    mEventStreamReadyTimer = 0.0f;
    mpGUIDialog = nullptr;
    mpGUIEventSkip = nullptr;
}

cOpeningMovie::~cOpeningMovie() {
    sFlag::getInstance()->setFlag(4u, 13u, false, true, false);
    if (mpScheduler != nullptr) {
        mpScheduler->kill();
        mpScheduler = nullptr;
    }
    if (mpGUIEventSkip != nullptr) {
        mpGUIEventSkip->kill();
        mpGUIEventSkip = nullptr;
    }
    if (mpGUIDialog != nullptr) {
        mpGUIDialog->kill();
        mpGUIDialog = nullptr;
    }
    mpMovie = nullptr;
    static_cast<sCameraExt*>(sCamera::getInstance())->mRateFix = false;
}

__attribute__((weak)) void cOpeningMovie::initMovie(u32 type) {
    DDON_STUB("cOpeningMovie::initMovie")
    /* stub */
}

__attribute__((weak)) bool cOpeningMovie::moveMovie() {
    DDON_STUB("cOpeningMovie::moveMovie")
    return {};
}

inline cOpeningMovie::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cOpeningMovie::MyDTI cOpeningMovie::DTI("cOpeningMovie", &::MtObject::DTI, 64ul, 0u, 0u);

MtObject* cOpeningMovie::MyDTI::newInstance() const {
    return new (16u) cOpeningMovie;
}

