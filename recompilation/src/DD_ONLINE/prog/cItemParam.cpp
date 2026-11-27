// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cItemParam.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "cNetGameServer.h"
#include "nCharacterData.h"
#include "rItemList.h"
#include "sItemManager.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cCraftParam::getDTI() const {
    return cCraftParam::DTI;
}

cCraftParam::cCraftParam() {
    init();
}

cCraftParam::~cCraftParam() {
}

void cCraftParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "エレメントID", &mCraftElementItemNo[0], 32u, 4u);
    s << MtProperty(static_cast<MtObject*>(this), "強化素材", &mCraftPlusParam, 0u, 0u);
}

void cCraftParam::init() {
    mCraftPlusParam = 0;
    mCraftElementItemNo[2] = 0;
    mCraftElementItemNo[3] = 0;
    mCraftElementItemNo[0] = 0;
    mCraftElementItemNo[1] = 0;
    mpElementParam[3] = nullptr;
    mpElementParam[2] = nullptr;
    mpElementParam[1] = nullptr;
    mpElementParam[0] = nullptr;
}

void cCraftParam::copyParam(const cCraftParam* pSrc, rItemList::rItemParam* pItemParam) {
    if (pSrc == nullptr) {
        return;
    }
    if (pItemParam == nullptr) {
        return;
    }
    const unsigned int t0 = pSrc->mCraftElementItemNo[0];
    mCraftElementItemNo[0] = t0;
    mpElementParam[0] = sItemManager::getInstance()->getItemParam(t0);
    const unsigned int t1 = pSrc->mCraftElementItemNo[1];
    mCraftElementItemNo[1] = t1;
    mpElementParam[1] = sItemManager::getInstance()->getItemParam(t1);
    const unsigned int t2 = pSrc->mCraftElementItemNo[2];
    mCraftElementItemNo[2] = t2;
    mpElementParam[2] = sItemManager::getInstance()->getItemParam(t2);
    const unsigned int t3 = pSrc->mCraftElementItemNo[3];
    mCraftElementItemNo[3] = t3;
    mpElementParam[3] = sItemManager::getInstance()->getItemParam(t3);
    mCraftPlusParam = pSrc->mCraftPlusParam;
}

void cCraftParam::setElementItemNo(u32 no, u32 itemNo) {
    if (no <= 3u) {
        mCraftElementItemNo[no] = itemNo;
        mpElementParam[no] = sItemManager::getInstance()->getItemParam(itemNo);
    }
}

u32 cCraftParam::getElementItemNo(u32 no) const {
    if (no <= 3u) {
        return mCraftElementItemNo[no];
    } else {
        return 0;
    }
}

void cCraftParam::setElementItemParam(u32 no, u32 itemNo) {
    if (no <= 3u) {
        mpElementParam[no] = sItemManager::getInstance()->getItemParam(itemNo);
    }
}

rItemList::rItemParam* cCraftParam::getElementParam(u32 no) {
    if (no <= 3u) {
        return mpElementParam[no];
    } else {
        return nullptr;
    }
}

void cCraftParam::setPlusParam(u8 plus, rItemList::rItemParam* pItemParam) {
    if (pItemParam == nullptr) {
        return;
    }
    mCraftPlusParam = plus;
}

u32 cCraftParam::getElementEquipNum() const {
    return static_cast<u32>(((((mCraftElementItemNo[0] != 0) - (mCraftElementItemNo[1] <= 0u)) - (mCraftElementItemNo[2] <= 0u)) - (mCraftElementItemNo[3] <= 0u)) + 3);
}

inline cCraftParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cCraftParam::MyDTI cCraftParam::DTI("cCraftParam", &::MtObject::DTI, 64ul, 0u, 0u);

MtObject* cCraftParam::MyDTI::newInstance() const {
    return new (16u) cCraftParam;
}

const MtDTI& cItemParam::getDTI() const {
    return cItemParam::DTI;
}

void* cItemParam::operator new(size_t sz, u32 align) {
    return cItemParam::getAllocator()->memAlloc(sz, align, cItemParam::DTI.getID());
}

cItemParam::cItemParam() {
    DDON_STUB("cItemParam::cItemParam")
    /* stub */
}

__attribute__((weak)) void cItemParam::init(u32 key) {
    DDON_STUB("cItemParam::init")
    /* stub */
}

__attribute__((weak)) void cItemParam::copyParam(const cItemParam* pSrc) {
    DDON_STUB("cItemParam::copyParam")
    /* stub */
}

void cItemParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "アイテムID", &mItemParam.mItemNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CSTRING, "アイテム名", reinterpret_cast<MT_MFUNC>(&::cItemParam::getItemName), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "個数", reinterpret_cast<MT_MFUNC>(&::cItemParam::getItemNum), reinterpret_cast<MT_MFUNC>(&::cItemParam::setItemNum), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mWstrUID", &mWstrUID, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "カラー", &mColorNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "強化度", &mEquipPoint, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "装備枠", &mSlotType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "アイテムパラメータ", reinterpret_cast<MtObject* *>(&mpItemResParam), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "クラフト", static_cast<MtObject*>(&mCraftParam), 0u, 0u);
}

static auto ddon_emit_0x0196fd50 __attribute__((used)) = &cItemParam::getItemNum;

static auto ddon_emit_0x0196fd60 __attribute__((used)) = &cItemParam::setItemNum;

u8 cItemParam::getColorSortNo() const {
    static const u8 color_sort_tbl[9] = {
        0,
        7,
        7,
        1,
        5,
        4,
        3,
        2,
        6,
    };
    if (mColorNo <= 8) {
        return color_sort_tbl[mColorNo];
    } else {
        return 7;
    }
}

bool cItemParam::isPlayerEquip() const {
    if (mEquipCharID != 0) {
        if ((mEquipCharType == 1) && (mEquipCharID == static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mLobbyCharacterId)) {
            return true;
        }
    }
    return false;
}

bool cItemParam::isPawnEquip() const {
    if (mEquipCharID != 0) {
        if ((mEquipCharType == 2) && (mEquipCharID != static_cast<sNetworkExt*>(sNetwork::getInstance())->getGameServer()->mLobbyCharacterId)) {
            return true;
        }
    }
    return false;
}

__attribute__((weak)) rItemList::ITEM_CATEGORY cItemParam::getItemCategory() {
    DDON_STUB("cItemParam::getItemCategory")
    return {};
}

__attribute__((weak)) u64 cItemParam::getItemPrice() {
    DDON_STUB("cItemParam::getItemPrice")
    return {};
}

MT_CTSTR cItemParam::getItemName() {
    if ((mpItemResParam == nullptr) && ((mpItemResParam = sItemManager::getInstance()->getItemParam(mItemParam.mItemNo)) == nullptr)) {
        return "";
    }
    return mpItemResParam->getItemName();
}

__attribute__((weak)) u8 cItemParam::getElementSlot() {
    DDON_STUB("cItemParam::getElementSlot")
    return {};
}

inline cItemParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cItemParam::MyDTI cItemParam::DTI("cItemParam", &::MtObject::DTI, 120ul, 0u, 0u);

__attribute__((weak)) MtObject* cItemParam::MyDTI::newInstance() const {
    DDON_STUB("cItemParam::MyDTI::newInstance")
    return nullptr;
}

