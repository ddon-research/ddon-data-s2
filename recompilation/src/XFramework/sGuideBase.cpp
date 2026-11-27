// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sGuideBase.h"
#include "../MT/MtNetCore.h"
#include "../MT/MtNetMediator.h"
#include "cPlatformUtilCommon.h"
#include "cSystem.h"
#include "cUserManagerListener.h"
#include "sPlatformUtil.h"
#include "sUserManager.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

sGuideBase::sGuideBase() {
    DDON_STUB("sGuideBase::sGuideBase")
    /* stub */
}

sGuideBase::~sGuideBase() {
    DDON_STUB("sGuideBase::~sGuideBase")
    /* stub */
}

void sGuideBase::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
}

__attribute__((weak)) void sGuideBase::move() {
    DDON_STUB("sGuideBase::move")
    /* stub */
}

__attribute__((weak)) void sGuideBase::addUser(s32 user_index, s32 user_id) {
    DDON_STUB("sGuideBase::addUser")
    /* stub */
}

void sGuideBase::removeUser(s32 user_index, s32 user_id) {
    (MtNetMediator::mpInstance)->MtNetMediator::removePsnUsrInfo(user_id);
}

__attribute__((weak)) void sGuideBase::onSystemService(const char* pparam, const u32 size, const u8* parg, nPlatformUtil::nSystemService::CALL_TYPE::TYPE call_type) {
    DDON_STUB("sGuideBase::onSystemService")
    /* stub */
}

__attribute__((weak)) void sGuideBase::initUser() {
    DDON_STUB("sGuideBase::initUser")
    /* stub */
}

