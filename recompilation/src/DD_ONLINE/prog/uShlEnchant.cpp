// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uShlEnchant.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "cContextPlayerInfo.h"
#include "../../generated/shared/nDDOGame.h"
#include "nHumanMsg.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uHuman.h"
#include "uShlBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cShlParamEnchant::getDTI() const {
    return cShlParamEnchant::DTI;
}

inline void cShlParamEnchant::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(cShlParamEnchant::DTI)->memFree(p_addr);
}

MtDTI& cShlParamEnchant::getShlDTI() const {
    return uShlEnchant::DTI;
}

void cShlParamEnchant::createProperty(MtPropertyList& proplist) {
    this->cShlParamBase::createProperty(proplist);
    proplist << MtProperty(static_cast<MtObject*>(this), "mElementType", reinterpret_cast<s32*>(&mElementType), 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mEnchantTime", &mEnchantTime, 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mEnchantRate", &mEnchantRate, 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mAilmentDamage", &mAilmentDamage, 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mEnchantIntervalTime", &mEnchantIntervalTime, 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mCustomSkillNo", &mCustomSkillNo, 0u, 0u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mEnchantExtendTime", &mEnchantExtendTime[0], 32u, 10u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mEnchantExtendRate", &mEnchantExtendRate[0], 32u, 10u);
    proplist << MtProperty(static_cast<MtObject*>(this), "mKillDistance", &mKillDistance, 0u, 0u);
}

__attribute__((weak)) void cShlParamEnchant::copy(const cShlParamBase* pParamBase) {
    DDON_STUB("cShlParamEnchant::copy")
    /* stub */
}

inline cShlParamEnchant::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cShlParamEnchant::MyDTI cShlParamEnchant::DTI("cShlParamEnchant", &::cShlParamBase::DTI, 464ul, 0u, 0u);

MtObject* cShlParamEnchant::MyDTI::newInstance() const {
    return new (16u) cShlParamEnchant;
}

const MtDTI& uShlEnchant::getDTI() const {
    return uShlEnchant::DTI;
}

__attribute__((weak)) void uShlEnchant::setup() {
    DDON_STUB("uShlEnchant::setup")
    /* stub */
}

__attribute__((weak)) void uShlEnchant::update() {
    DDON_STUB("uShlEnchant::update")
    /* stub */
}

nDDOGame::ELEMENT_TYPE uShlEnchant::getElementType() const {
    return static_cast<const cShlParamEnchant*>(getShlParamBase())->getElementType();
}

__attribute__((weak)) f32 uShlEnchant::getEnchantTime() const {
    DDON_STUB("uShlEnchant::getEnchantTime")
    return {};
}

__attribute__((weak)) f32 uShlEnchant::getEnchantRate() const {
    DDON_STUB("uShlEnchant::getEnchantRate")
    return {};
}

f32 uShlEnchant::getAilmentDamage() const {
    return static_cast<const cShlParamEnchant*>(getShlParamBase())->getAilmentDamage();
}

f32 uShlEnchant::getEnchantIntervalTime() const {
    return static_cast<const cShlParamEnchant*>(getShlParamBase())->getEnchantIntervalTime();
}

inline uShlEnchant::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uShlEnchant::MyDTI uShlEnchant::DTI("uShlEnchant", &::uShlBase::DTI, 10944ul, 0u, 0u);

MtObject* uShlEnchant::MyDTI::newInstance() const {
    return new (16u) uShlEnchant;
}

