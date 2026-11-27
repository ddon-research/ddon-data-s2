// Reconstructed from the game's DWARF debug information.
#include <new>
#include "uGUIPopCraftDetail.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtString.h"
#include "cCraftRecipe.h"
#include "cCraftSkill.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "cItemParam.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cUnit.h"
#include "rArchiveListArray.h"
#include "rCraftElementExp.h"
#include "rCraftRecipe.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "rItemList.h"
#include "sCraftManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "sItemManager.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIPopCraftDetail::getDTI() const {
    return uGUIPopCraftDetail::DTI;
}

void* uGUIPopCraftDetail::operator new(size_t sz, u32 align) {
    return uGUIPopCraftDetail::getAllocator()->memAlloc(sz, align, uGUIPopCraftDetail::DTI.getID());
}

__attribute__((noinline)) uGUIPopCraftDetail::~uGUIPopCraftDetail() {
    if (mpGUIRes != nullptr) {
        mpGUIRes->release();
        mpGUIRes = nullptr;
    }
    if (mpGMDRes != nullptr) {
        mpGMDRes->release();
        mpGMDRes = nullptr;
    }
    if (mpGMDParamRes != nullptr) {
        mpGMDParamRes->release();
        mpGMDParamRes = nullptr;
    }
    if (mpGMDJewelryCtgr == nullptr) {
        return;
    }
    mpGMDJewelryCtgr->release();
    mpGMDJewelryCtgr = nullptr;
}

void uGUIPopCraftDetail::createProperty(MtPropertyList& s) {
    this->uGUI::createProperty(s);
}

bool uGUIPopCraftDetail::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_POP_CRAFT_DETAIL_GUI"), 129u, 1477041087l))) == nullptr)) {
        return false;
    }
    if ((mpGMDRes == nullptr) && ((mpGMDRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_GMD"), 129u, 0l))) == nullptr)) {
        return false;
    }
    if ((mpGMDParamRes == nullptr) && ((mpGMDParamRes = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_PARAMETER_GMD"), 129u, 0l))) == nullptr)) {
        return false;
    }
    if ((mpGMDJewelryCtgr == nullptr) && ((mpGMDJewelryCtgr = static_cast<rGUIMessage*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_JEWELRY_CTGR_GMD"), 129u, 0l))) == nullptr)) {
        return false;
    }
    return true;
}

__attribute__((weak)) void uGUIPopCraftDetail::setup() {
    DDON_STUB("uGUIPopCraftDetail::setup")
    /* stub */
}

void uGUIPopCraftDetail::kill() {
    this->uGUIBase::kill();
}

void uGUIPopCraftDetail::move() {
    this->uGUIBase::move();
}

__attribute__((weak)) void uGUIPopCraftDetail::setupInfo(cItemParam* pParam, u32 type, u32 category, u32 recipe_index, u32 recipe_id) {
    DDON_STUB("uGUIPopCraftDetail::setupInfo")
    /* stub */
}

__attribute__((weak)) void uGUIPopCraftDetail::setupCrestInfo(cItemParam* pParam) {
    DDON_STUB("uGUIPopCraftDetail::setupCrestInfo")
    /* stub */
}

__attribute__((weak)) void uGUIPopCraftDetail::setupColorInfo(cItemParam* pParam) {
    DDON_STUB("uGUIPopCraftDetail::setupColorInfo")
    /* stub */
}

void uGUIPopCraftDetail::updateInit() {
    mTop.mIcon.uGUIBase::cReferenceUIIconItem::update();
}

void uGUIPopCraftDetail::setupCrestResult(uGUIPopCraftDetail::stCrestResult& crest, cGUIInstance* pInstNull, cGUIInstance* pInstHeader, cGUIInstance* pInstResult) {
    crest.mpInstNull = static_cast<cGUIInstNull*>(pInstNull);
    crest.mpObjMsgName = static_cast<cGUIObjMessage*>(getObjectFromId(pInstHeader, 2u));
    crest.mpObjMsgExp = static_cast<cGUIObjMessage*>(getObjectFromId(pInstResult, 11u));
    crest.mpObjMsgExpVal = static_cast<cGUIObjMessage*>(getObjectFromId(pInstResult, 15u));
    crest.mpObjMsgExpUnit = static_cast<cGUIObjMessage*>(getObjectFromId(pInstResult, 14u));
    crest.mpObjNullCost = static_cast<cGUIObjNull*>(getObjectFromId(pInstResult, 19u));
    crest.mpObjMsgCost = static_cast<cGUIObjMessage*>(getObjectFromId(pInstResult, 20u));
    crest.mpObjMsgCostVal = static_cast<cGUIObjMessage*>(getObjectFromId(pInstResult, 34u));
    crest.mpObjNullCostRise = static_cast<cGUIObjNull*>(getObjectFromId(pInstResult, 47u));
    crest.mpObjMsgCostRiseVal = static_cast<cGUIObjMessage*>(getObjectFromId(pInstResult, 23u));
    crest.mpObjMsgCostUnit = static_cast<cGUIObjMessage*>(getObjectFromId(pInstResult, 22u));
}

__attribute__((weak)) void uGUIPopCraftDetail::setupBasicInfo(cItemParam* pParam, rItemList::rItemParam* pItemParam) {
    DDON_STUB("uGUIPopCraftDetail::setupBasicInfo")
    /* stub */
}

__attribute__((weak)) void uGUIPopCraftDetail::setExpVal(cGUIObjMessage* pObj, const u32 val) {
    DDON_STUB("uGUIPopCraftDetail::setExpVal")
    /* stub */
}

inline uGUIPopCraftDetail::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIPopCraftDetail::MyDTI uGUIPopCraftDetail::DTI("uGUIPopCraftDetail", &::uGUIBase::DTI, 5216ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIPopCraftDetail::MyDTI::newInstance() const {
    DDON_STUB("uGUIPopCraftDetail::MyDTI::newInstance")
    return nullptr;
}

