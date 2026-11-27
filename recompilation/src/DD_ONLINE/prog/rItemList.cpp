// Reconstructed from the game's DWARF debug information.
#include <new>
#include <sce_atomic.h>
#include <string.h>
#include "rItemList.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtString.h"
#include "../../XFramework/cResource.h"
#include "nCharacterData.h"
#include "../../generated/shared/nDDOIO.h"
#include "../../generated/shared/nWeapon.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sGUI.h"
#include "sItemManager.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rItemList::getDTI() const {
    return rItemList::DTI;
}

rItemList::~rItemList() {
    releaseWork();
    MtMemoryAllocator::getAllocator(rItemList::DTI)->memFree(static_cast<void*>(mpIndexTbl));
    mpIndexTbl = nullptr;
}

__attribute__((weak)) bool rItemList::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if (r.readU32() != 0x617069u) {
        return false;
    }
    if (r.readU32() != DATA_VERSION) {
        return false;
    }
    const u32 nArrayNum = r.readU32();
    void* pListData = nullptr;
    if (nArrayNum != 0) {
        pListData = MtMemoryAllocator::getAllocator(rItemList::DTI)->memAlloc(sizeof(rItemParam) * nArrayNum, 16u);
    }
    const u32 nArrayParamNum = r.readU32();
    void* pParamListData = nullptr;
    if (nArrayParamNum != 0) {
        pParamListData = MtMemoryAllocator::getAllocator(rItemList::DTI)->memAlloc(sizeof(rParam) * nArrayParamNum, 16u);
    }
    const u32 nArrayVsNum = r.readU32();
    void* pVsListData = nullptr;
    if (nArrayVsNum != 0) {
        pVsListData = MtMemoryAllocator::getAllocator(rItemList::DTI)->memAlloc(sizeof(rVsEnemyParam) * nArrayVsNum, 16u);
    }
    const u32 nArrayWeaponNum = r.readU32();
    void* pWeaponListData = nullptr;
    if (nArrayWeaponNum != 0) {
        pWeaponListData = MtMemoryAllocator::getAllocator(rItemList::DTI)->memAlloc(sizeof(rWeaponParam) * nArrayWeaponNum, 16u);
    }
    const u32 nArrayProtectNum = r.readU32();
    void* pProtectorListData = nullptr;
    if (nArrayProtectNum != 0) {
        pProtectorListData = MtMemoryAllocator::getAllocator(rItemList::DTI)->memAlloc(sizeof(rProtectorParam) * nArrayProtectNum, 16u);
    }
    const u32 nArrayKindParamNum = r.readU32();
    void* pEquipParamS8List = nullptr;
    if (nArrayKindParamNum != 0) {
        pEquipParamS8List = MtMemoryAllocator::getAllocator(rItemList::DTI)->memAlloc(sizeof(rEquipParamS8) * nArrayKindParamNum, 16u);
    }
    u32 weaponNowNum = 0;
    u32 protectorNowNum = 0;
    u32 vsParamNowNum = 0;
    u32 kindParamNowNum = 0;
    u32 paramNowNum = 0;
    for (u32 i = 0; i < nArrayNum; ++i) {
        rItemParam* pData = new (&static_cast<rItemParam*>(pListData)[i]) rItemParam();
        pData->load(r, pWeaponListData, &weaponNowNum, pProtectorListData, &protectorNowNum, pVsListData, &vsParamNowNum, pParamListData, &paramNowNum, pEquipParamS8List, &kindParamNowNum);
    }
    mpItemList = static_cast<rItemParam*>(pListData);
    mArrayDataNum = nArrayNum;
    mpParamList = static_cast<rParam*>(pParamListData);
    mArrayParamDataNum = nArrayParamNum;
    mpVsParamList = static_cast<rVsEnemyParam*>(pVsListData);
    mArrayVsParamDataNum = nArrayVsNum;
    mpWeaponParamList = static_cast<rWeaponParam*>(pWeaponListData);
    mArrayWeaponParamDataNum = nArrayWeaponNum;
    mpProtectParamList = static_cast<rProtectorParam*>(pProtectorListData);
    mArrayProtectParamDataNum = nArrayProtectNum;
    mpEquipParamS8List = static_cast<rEquipParamS8*>(pEquipParamS8List);
    mArrayEquipParamS8DataNum = nArrayKindParamNum;
    return true;
}

bool rItemList::save(MtStream& out) {
    MtDataWriter w(out, 4096u, 4096u);
    w.MtDataWriter::writeU32(0x617069u);
    w.MtDataWriter::writeU32(58u);
    w.MtDataWriter::writeU32(mArrayDataNum);
    w.MtDataWriter::writeU32(mArrayParamDataNum);
    w.MtDataWriter::writeU32(mArrayVsParamDataNum);
    w.MtDataWriter::writeU32(mArrayWeaponParamDataNum);
    w.MtDataWriter::writeU32(mArrayProtectParamDataNum);
    w.MtDataWriter::writeU32(mArrayEquipParamS8DataNum);
    u32 i = 0;
    if (mArrayDataNum != 0) {
        do {
            mpItemList[i].save(w);
            i += 1u;
        } while (i < mArrayDataNum);
    }
    return true;
}

void rItemList::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mpItemList", reinterpret_cast<MtObject* *>(&mpItemList), 0u, 0u);
}

MT_CTSTR rItemList::getExt() const {
    return "ipa";
}

u32 rItemList::getListNum() const {
    return mArrayDataNum;
}

__attribute__((weak)) void rItemList::releaseWork() {
    u32 i = 0;
    if (mArrayDataNum != 0) {
        do {
            mpItemList[i].~rItemParam();
            i += 1u;
        } while (i < mArrayDataNum);
    }
    MtMemoryAllocator::getAllocator(rItemList::DTI)->memFree(static_cast<void*>(mpItemList));
    mpItemList = nullptr;
    mArrayDataNum = 0;
    MtMemoryAllocator::getAllocator(rItemList::DTI)->memFree(static_cast<void*>(mpParamList));
    mpParamList = nullptr;
    mArrayParamDataNum = 0;
    MtMemoryAllocator::getAllocator(rItemList::DTI)->memFree(static_cast<void*>(mpVsParamList));
    mpVsParamList = nullptr;
    mArrayVsParamDataNum = 0;
    MtMemoryAllocator::getAllocator(rItemList::DTI)->memFree(static_cast<void*>(mpWeaponParamList));
    mpWeaponParamList = nullptr;
    mArrayWeaponParamDataNum = 0;
    MtMemoryAllocator::getAllocator(rItemList::DTI)->memFree(static_cast<void*>(mpProtectParamList));
    mpProtectParamList = nullptr;
    mArrayProtectParamDataNum = 0;
    MtMemoryAllocator::getAllocator(rItemList::DTI)->memFree(static_cast<void*>(mpEquipParamS8List));
    mpEquipParamS8List = nullptr;
    mArrayEquipParamS8DataNum = 0;
}

rItemList::rItemParam* rItemList::getItemList(u32 no) const {
    if (mpIndexTbl != nullptr) {
        if (mMaxId >= no) {
            u16 t0 = mpIndexTbl[no];
            if (t0 < getListNum()) {
                return &mpItemList[t0];
            } else {
                return nullptr;
            }
        } else {
            return nullptr;
        }
    } else {
        return nullptr;
    }
}

rItemList::rItemParam* rItemList::getItemListByIndex(u32 index) const {
    if (index < getListNum()) {
        return &mpItemList[index];
    } else {
        return nullptr;
    }
}

rItemList::rItemParam* rItemList::getItemListByArcTagNo(u32 arcTagNo) const {
    rItemParam* v2_0;
    if (getListNum() == 0) {
        v2_0 = nullptr;
    } else {
        for (unsigned int i0_2 = 0;;) {
            if ((&mpItemList[i0_2]) != nullptr) {
                if (mpItemList[i0_2].mpWeaponParam != nullptr) {
                    if (mpItemList[i0_2].mpWeaponParam->mModelTagId == arcTagNo) {
                        v2_0 = &mpItemList[i0_2];
                        break;
                    }
                } else {
                    if (mpItemList[i0_2].mpProtectorParam != nullptr) {
                        if (mpItemList[i0_2].mpProtectorParam->mModelTagId == arcTagNo) {
                            v2_0 = &mpItemList[i0_2];
                            break;
                        }
                    } else {
                        if (arcTagNo == 0) {
                            v2_0 = &mpItemList[i0_2];
                            break;
                        }
                    }
                }
            }
            if ((i0_2 + 1u) < getListNum()) {
                i0_2 += 1u;
            } else {
                v2_0 = nullptr;
                break;
            }
        }
    }
    return v2_0;
}

__attribute__((weak)) void rItemList::createIndexTable() {
    u32 listNum = getListNum();
    u32 maxId = 0;
    for (u32 i = 0; i < listNum; ++i) {
        rItemParam* pParam = &mpItemList[i];
        if (pParam != nullptr) {
            u32 itemId = pParam->getItemId();
            if (maxId < itemId) {
                maxId = itemId;
            }
        }
    }
    mMaxId = maxId;
    mpIndexTbl = static_cast<u16*>(MtMemoryAllocator::getAllocator(rItemList::DTI)->memAlloc(sizeof(u16) * (maxId + 1u), 16u));
    memset(mpIndexTbl, 0xff, sizeof(u16) * (maxId + 1u));
    for (u32 i = 0; i < listNum; ++i) {
        rItemParam* pParam = &mpItemList[i];
        if (pParam != nullptr) {
            u32 index = pParam->getItemId();
            mpIndexTbl[index] = static_cast<u16>(i);
        }
    }
}

inline rItemList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rItemList::MyDTI rItemList::DTI("rItemList", &::cResource::DTI, 224ul, 0u, 0u);

MtObject* rItemList::MyDTI::newInstance() const {
    return new (16u) rItemList;
}

const MtDTI& rItemList::rItemParam::getDTI() const {
    return rItemList::rItemParam::DTI;
}

__attribute__((noinline)) rItemList::rItemParam::~rItemParam() {
    releaseWork();
}

__attribute__((weak)) void rItemList::rItemParam::createProperty(MtPropertyList& s) {
    DDON_STUB("rItemList::rItemParam::createProperty")
    /* stub */
}

MtUI* rItemList::rItemParam::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) bool rItemList::rItemParam::load(MtDataReader& in, void* pWeaponListData, u32* pWeaponNum, void* pProtectorListData, u32* pProtectorNum, void* pVsListData, u32* pVsNum, void* pParamListData, u32* pParamNum, void* pEquipParamS8List, u32* pEquipParamS8Num) {
    mItemId = in.readU32();
    mNameId = in.readU32();
    mCategory2.mCategory = in.readU32();
    mPrice = in.readU32();
    mSortNo = in.readU32();
    mNameSortNo = in.readU32();
    mAttackStatus = in.readU32();
    mIsUseJob = in.readU32();
    mFlag = in.readU16();
    mIconNo = in.readU16();
    mIsUseLv = in.readU16();
    mCategory = in.readU8();
    mStackMax = in.readU8();
    mRank = in.readU8();
    mGrade = in.readU8();
    mIconColNo = in.readU8();
    mParamNum = in.readU32();
    if (mParamNum != 0) {
        rParam* pBase = static_cast<rParam*>(pParamListData);
        u32 num = *pParamNum;
        for (u32 i = 0; i < mParamNum; ++i) {
            rParam* pData = new (&pBase[num + i]) rParam(0, 0, 0, 0);
            pData->load(in);
            (*pParamNum)++;
        }
        mpItemParamList = &pBase[num];
    }
    mVsEmNum = in.readU32();
    if (mVsEmNum != 0) {
        rVsEnemyParam* pVsBase = static_cast<rVsEnemyParam*>(pVsListData);
        u32 num = *pVsNum;
        for (u32 i = 0; i < mVsEmNum; ++i) {
            rVsEnemyParam* pData = new (&pVsBase[num + i]) rVsEnemyParam(rVsEnemyParam::EM_PHYLOGENY_KIND_NONE, 0);
            pData->load(in);
            (*pVsNum)++;
        }
        mpVsEmList = &pVsBase[num];
    }
    if (isWeaponElement()) {
        rWeaponParam* pData = new (&static_cast<rWeaponParam*>(pWeaponListData)[*pWeaponNum]) rWeaponParam();
        u32 abnormalParamNum = 0;
        u32 num = *pEquipParamS8Num;
        rEquipParamS8* pEquipParamS8Data = &static_cast<rEquipParamS8*>(pEquipParamS8List)[num];
        pData->load(in, pEquipParamS8Data, &abnormalParamNum);
        (*pWeaponNum)++;
        mpWeaponParam = pData;
        *pEquipParamS8Num += abnormalParamNum;
        pData->mpEquipParamS8List = (abnormalParamNum != 0) ? pEquipParamS8Data : nullptr;
    }
    if (isProtectorElement()) {
        rProtectorParam* pData = new (&static_cast<rProtectorParam*>(pProtectorListData)[*pProtectorNum]) rProtectorParam();
        u32 abnormalParamNum = 0;
        u32 num = *pEquipParamS8Num;
        rEquipParamS8* pEquipParamS8Data = &static_cast<rEquipParamS8*>(pEquipParamS8List)[num];
        pData->load(in, pEquipParamS8Data, &abnormalParamNum);
        (*pProtectorNum)++;
        mpProtectorParam = pData;
        *pEquipParamS8Num += abnormalParamNum;
        pData->mpEquipParamS8List = (abnormalParamNum != 0) ? pEquipParamS8Data : nullptr;
    }
    return true;
}

__attribute__((weak)) bool rItemList::rItemParam::save(MtDataWriter& out) {
    out.writeU32(mItemId);
    out.writeU32(mNameId);
    out.writeU32(mCategory2.mCategory);
    out.writeU32(mPrice);
    out.writeU32(mSortNo);
    out.writeU32(mNameSortNo);
    out.writeU32(mAttackStatus);
    out.writeU32(mIsUseJob);
    out.writeU16(mFlag);
    out.writeU16(mIconNo);
    out.writeU16(mIsUseLv);
    out.writeU8(mCategory);
    out.writeU8(mStackMax);
    out.writeU8(mRank);
    out.writeU8(mGrade);
    out.writeU8(mIconColNo);
    out.writeU32(mParamNum);
    for (u32 i = 0; i < mParamNum; ++i) {
        rParam* pParam = &mpItemParamList[i];
        pParam->save(out);
    }
    out.writeU32(mVsEmNum);
    for (u32 i = 0; i < mVsEmNum; ++i) {
        rVsEnemyParam* pParam = &mpVsEmList[i];
        pParam->save(out);
    }
    if (mpWeaponParam != nullptr) {
        mpWeaponParam->save(out);
    }
    if (mpProtectorParam != nullptr) {
        mpProtectorParam->save(out);
    }
    return true;
}

MT_CTSTR rItemList::rItemParam::getItemName() const {
    if ((sGUI::mpInstance) != nullptr) {
        if (sItemManager::getInstance() != nullptr) {
            if (sItemManager::getInstance()->getItemNameGmd() != nullptr) {
                return sItemManager::getInstance()->getItemNameGmd()->getMessage(mNameId);
            }
        }
    }
    return nullptr;
}

void rItemList::rItemParam::getItemInfo(MtString& retStr) const {
    if ((sGUI::mpInstance) == nullptr) {
        return;
    }
    if (sItemManager::getInstance() == nullptr) {
        return;
    }
    if (mCategory == 3) {
        return;
    }
    rGUIMessage* prRes = sItemManager::getInstance()->getItemInfoGmd();
    if (prRes == nullptr) {
        return;
    }
    if (prRes->isUsage()) {
        MT_CTSTR t0 = prRes->getMessage(mNameId);
        if (t0 != retStr.ptr()) {
            if (retStr.value != nullptr) {
                if (sceAtomicAdd32Relaxed(&retStr.value->ref, -1) == 1) {
                    (MtString::mpAllocator)->memFree(static_cast<void*>(retStr.value));
                }
                retStr.value = nullptr;
            }
            if (t0 != nullptr) {
                size_t t1 = strlen(t0);
                if (static_cast<unsigned int>(t1) != 0) {
                    void* t2 = (MtString::mpAllocator)->memAlloc(static_cast<size_t>(static_cast<unsigned int>(t1)) + 12, 16u);
                    retStr.value = static_cast<MtString::STRING*>(t2);
                    retStr.value->ref = 1;
                    retStr.value->length = static_cast<unsigned int>(t1);
                    strcpy(reinterpret_cast<char*>(retStr.value->str), t0);
                    prRes->release();
                } else {
                    retStr.value = nullptr;
                    prRes->release();
                }
            } else {
                retStr.value = nullptr;
                prRes->release();
            }
        } else {
            prRes->release();
        }
    } else {
        prRes->release();
    }
}

__attribute__((weak)) u32 rItemList::rItemParam::getStackMax(nCharacterData::ITEM_BAG_TYPE bagType) const {
    DDON_STUB("rItemList::rItemParam::getStackMax")
    return {};
}

bool rItemList::rItemParam::getUseJob(u32 jobType) const {
    return ((static_cast<unsigned long>(mIsUseJob) >> static_cast<unsigned long>(jobType & 31u)) & 1ul) != 0;
}

__attribute__((weak)) rItemList::USE_CATEGORY rItemList::rItemParam::getUseType() const {
    DDON_STUB("rItemList::rItemParam::getUseType")
    return {};
}

u32 rItemList::rItemParam::getWepCategory() const {
    if (mpWeaponParam != nullptr) {
        return mpWeaponParam->mWepCategory;
    } else {
        return 15;
    }
}

u32 rItemList::rItemParam::getEquipCategory() const {
    if (mCategory == 3) {
        if ((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 16)) <= 12) {
            return static_cast<u32>(((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 16)) == 12) ? static_cast<unsigned char>(4) : (*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 16)));
        }
    }
    return 13;
}

rItemList::rItemParam::EQUIP_SUB_CATEGORY rItemList::rItemParam::getEquipSubCategory() const {
    if (mCategory == 3) {
        return static_cast<EQUIP_SUB_CATEGORY>(*reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(this) + 18));
    } else {
        return EQUIP_SUB_CATEGORY_NONE;
    }
}

__attribute__((weak)) bool rItemList::rItemParam::isCanEquip(u32 slotType) {
    DDON_STUB("rItemList::rItemParam::isCanEquip")
    return {};
}

bool rItemList::rItemParam::isWeapon() const {
    if (mCategory == 3) {
        if ((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 16)) <= 12) {
            return sItemManager::getInstance()->isWeaponCategory(static_cast<nCharacterData::EQUIP_CATEGORY>(((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 16)) == 12) ? static_cast<unsigned char>(4) : (*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 16))));
        }
    }
    return sItemManager::getInstance()->isWeaponCategory(nCharacterData::EQUIP_CATEGORY_END);
}

bool rItemList::rItemParam::isArmor() const {
    if (mCategory == 3) {
        if ((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 16)) <= 12) {
            return sItemManager::getInstance()->isArmorCategory(static_cast<nCharacterData::EQUIP_CATEGORY>(((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 16)) == 12) ? static_cast<unsigned char>(4) : (*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 16))));
        }
    }
    return sItemManager::getInstance()->isArmorCategory(nCharacterData::EQUIP_CATEGORY_END);
}

bool rItemList::rItemParam::isCostume() const {
    if ((mCategory == 3) && ((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 16)) == 12)) {
        return true;
    }
    return false;
}

u8 rItemList::rItemParam::getPhysicalType() const {
    static const u8 type[4] = {
        3,
        0,
        1,
        2,
    };
    if (mpWeaponParam != nullptr) {
        if (mpWeaponParam->mPhysicalType <= 3) {
            return type[mpWeaponParam->mPhysicalType];
        }
    }
    return 3;
}

u8 rItemList::rItemParam::getElementType() const {
    if (mpWeaponParam != nullptr) {
        return mpWeaponParam->mElementType;
    } else {
        return 3;
    }
}

u32 rItemList::rItemParam::getUseJob() const {
    return mIsUseJob;
}

u32 rItemList::rItemParam::getUseLv() const {
    return mIsUseLv;
}

u16 rItemList::rItemParam::getWight() const {
    if (mpWeaponParam != nullptr) {
        return mpWeaponParam->mWeight;
    } else {
        if (mpProtectorParam != nullptr) {
            return mpProtectorParam->mWeight;
        } else {
            return 0xFFFF;
        }
    }
}

u8 rItemList::rItemParam::getEleSlot() const {
    if (mpWeaponParam != nullptr) {
        return mpWeaponParam->mEleSlot;
    } else {
        if (mpProtectorParam != nullptr) {
            return mpProtectorParam->mEleSlot;
        } else {
            return 0;
        }
    }
}

s8 rItemList::rItemParam::getMaterialColNo() const {
    if (mpWeaponParam != nullptr) {
        return static_cast<s8>(mpWeaponParam->mColorNo);
    } else {
        if (mpProtectorParam != nullptr) {
            return static_cast<s8>(mpProtectorParam->mColorNo);
        } else {
            return 0;
        }
    }
}

u8 rItemList::rItemParam::getSex() const {
    if (mpWeaponParam != nullptr) {
        return mpWeaponParam->mSex;
    } else {
        if (mpProtectorParam != nullptr) {
            return mpProtectorParam->mSex;
        } else {
            return 0;
        }
    }
}

u32 rItemList::rItemParam::getModelTagId() const {
    if (mpWeaponParam != nullptr) {
        return mpWeaponParam->mModelTagId;
    } else {
        if (mpProtectorParam != nullptr) {
            return mpProtectorParam->mModelTagId;
        } else {
            return 0;
        }
    }
}

u8 rItemList::rItemParam::getModelParts() const {
    if (mpWeaponParam != nullptr) {
        return mpWeaponParam->mModelParts;
    } else {
        if (mpProtectorParam != nullptr) {
            return mpProtectorParam->mModelParts;
        } else {
            return 0;
        }
    }
}

u32 rItemList::rItemParam::getAttack() const {
    if (mpWeaponParam != nullptr) {
        return mpWeaponParam->mAttack;
    } else {
        if (mpProtectorParam != nullptr) {
            return mpProtectorParam->mAttack;
        } else {
            return 0;
        }
    }
}

u32 rItemList::rItemParam::getMagicAttack() const {
    if (mpWeaponParam != nullptr) {
        return mpWeaponParam->mMagicAttack;
    } else {
        if (mpProtectorParam != nullptr) {
            return mpProtectorParam->mMagicAttack;
        } else {
            return 0;
        }
    }
}

u32 rItemList::rItemParam::getPowerRev() const {
    if (mpWeaponParam != nullptr) {
        return mpWeaponParam->mPowerRev;
    } else {
        if (mpProtectorParam != nullptr) {
            return mpProtectorParam->mPowerRev;
        } else {
            return 0;
        }
    }
}

u32 rItemList::rItemParam::getShieldStagger() const {
    if (mpWeaponParam != nullptr) {
        return mpWeaponParam->mShieldStagger;
    } else {
        return 0;
    }
}

u32 rItemList::rItemParam::getDefense() const {
    if (mpWeaponParam != nullptr) {
        return mpWeaponParam->mDefense;
    } else {
        if (mpProtectorParam != nullptr) {
            return mpProtectorParam->mDefense;
        } else {
            return 0;
        }
    }
}

u32 rItemList::rItemParam::getMagicDefense() const {
    if (mpWeaponParam != nullptr) {
        return mpWeaponParam->mMagicDefense;
    } else {
        if (mpProtectorParam != nullptr) {
            return mpProtectorParam->mMagicDefense;
        } else {
            return 0;
        }
    }
}

u32 rItemList::rItemParam::getDurability() const {
    if (mpWeaponParam != nullptr) {
        return mpWeaponParam->mDurability;
    } else {
        if (mpProtectorParam != nullptr) {
            return mpProtectorParam->mDurability;
        } else {
            return 0;
        }
    }
}

u16 rItemList::rItemParam::getMaxHpRev() const {
    if (mpWeaponParam != nullptr) {
        return mpWeaponParam->mMaxHpRev;
    } else {
        if (mpProtectorParam != nullptr) {
            return mpProtectorParam->mMaxHpRev;
        } else {
            return 0;
        }
    }
}

u16 rItemList::rItemParam::getMaxStRev() const {
    if (mpWeaponParam != nullptr) {
        return mpWeaponParam->mMaxStRev;
    } else {
        if (mpProtectorParam != nullptr) {
            return mpProtectorParam->mMaxStRev;
        } else {
            return 0;
        }
    }
}

__attribute__((weak)) void rItemList::rItemParam::getKindParamList(MtTypedArray<rItemList::rEquipParamS8>& list) {
    DDON_STUB("rItemList::rItemParam::getKindParamList")
    /* stub */
}

u32 rItemList::rItemParam::getChanceNum() const {
    if (mpWeaponParam != nullptr) {
        return mpWeaponParam->mChance;
    } else {
        if (mpProtectorParam != nullptr) {
            return mpProtectorParam->mChance;
        } else {
            return 0;
        }
    }
}

rItemList::rVsEnemyParam* rItemList::rItemParam::getVsEmParam(u32 index) {
    if (index < mVsEmNum) {
        return &mpVsEmList[index];
    } else {
        return nullptr;
    }
}

rItemList::rParam* rItemList::rItemParam::getItemParam(u32 no) {
    if (no < mParamNum) {
        return &mpItemParamList[no];
    } else {
        return nullptr;
    }
}

rItemList::rParam* rItemList::rItemParam::getItemParam(rItemList::rParam::PARAM_KIND kind) {
    rParam* v0_3 = mpItemParamList;
    rParam* v2_0;
    if (v0_3 == nullptr) {
        v2_0 = nullptr;
    } else {
        u32 v0_4 = mParamNum;
        if (v0_4 == 0) {
            v2_0 = nullptr;
        } else {
            rParam* p0_0 = v0_3;
            for (unsigned int i0_2 = 0;;) {
                if (static_cast<unsigned int>(kind) != static_cast<unsigned int>(p0_0->mKindType)) {
                    if ((i0_2 + 1u) < v0_4) {
                        p0_0 += 1;
                        i0_2 = i0_2 + 1u;
                    } else {
                        break;
                    }
                } else {
                    v2_0 = &v0_3[i0_2];
                    return v2_0;
                }
            }
            v2_0 = nullptr;
        }
    }
    return v2_0;
}

inline rItemList::rItemParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rItemList::rItemParam::MyDTI rItemList::rItemParam::DTI("rItemList::rItemParam", &::MtObject::DTI, 104ul, 0u, 0u);

__attribute__((weak)) MtObject* rItemList::rItemParam::MyDTI::newInstance() const {
    DDON_STUB("rItemList::rItemParam::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& rItemList::rParam::getDTI() const {
    return rItemList::rParam::DTI;
}

__attribute__((weak)) void rItemList::rParam::createProperty(MtPropertyList& s) {
    DDON_STUB("rItemList::rParam::createProperty")
    /* stub */
}

MtUI* rItemList::rParam::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

bool rItemList::rParam::load(MtDataReader& in) {
    mKindType = static_cast<s16>(in.readU16());
    mParam.mParam1 = in.readU16();
    mParam.mParam2 = in.readU16();
    mParam.mParam3 = in.readU16();
    return true;
}

bool rItemList::rParam::save(MtDataWriter& out) {
    out.writeU16(static_cast<u16>(mKindType));
    out.writeU16(*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 10));
    out.writeU16(*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 12));
    out.writeU16(*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 14));
    return true;
}

inline rItemList::rParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rItemList::rParam::MyDTI rItemList::rParam::DTI("rItemList::rParam", &::MtObject::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* rItemList::rParam::MyDTI::newInstance() const {
    DDON_STUB("rItemList::rParam::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& rItemList::rVsEnemyParam::getDTI() const {
    return rItemList::rVsEnemyParam::DTI;
}

void rItemList::rVsEnemyParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mKindType", &mKindType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParam", &mParam, 0u, 0u);
}

MtUI* rItemList::rVsEnemyParam::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

bool rItemList::rVsEnemyParam::load(MtDataReader& in) {
    nDDOIO::readData(in, mKindType);
    nDDOIO::readData(in, mParam);
    return true;
}

bool rItemList::rVsEnemyParam::save(MtDataWriter& out) {
    u8 t0 = mKindType;
    if (out.mSeekPt >= out.mBufsiz) {
        out.flush();
    }
    out.mBuffer[out.mSeekPt] = t0;
    out.mSeekPt = out.mSeekPt + 1u;
    out.writeU16(mParam);
    return true;
}

inline rItemList::rVsEnemyParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rItemList::rVsEnemyParam::MyDTI rItemList::rVsEnemyParam::DTI("rItemList::rVsEnemyParam", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* rItemList::rVsEnemyParam::MyDTI::newInstance() const {
    return new (16u) rItemList::rVsEnemyParam(rItemList::rVsEnemyParam::EM_PHYLOGENY_KIND_NONE, static_cast<u16>(0));
}

const MtDTI& rItemList::rWeaponParam::getDTI() const {
    return rItemList::rWeaponParam::DTI;
}

rItemList::rWeaponParam::~rWeaponParam() {
    if (mpEquipParamS8List != nullptr) {
        for (u8 i = 0; i < mEquipParamS8Num; ++i) {
            mpEquipParamS8List[i].~rEquipParamS8();
        }
    }
    mpEquipParamS8List = nullptr;
    mEquipParamS8Num = 0;
}

__attribute__((weak)) void rItemList::rWeaponParam::createProperty(MtPropertyList& s) {
    DDON_STUB("rItemList::rWeaponParam::createProperty")
    /* stub */
}

MtUI* rItemList::rWeaponParam::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) bool rItemList::rWeaponParam::load(MtDataReader& in, rItemList::rEquipParamS8* pArray, u32* pUseNum) {
    mModelTagId = in.readU32();
    mPowerRev = in.readU32();
    mChance = in.readU32();
    mDefense = in.readU32();
    mMagicDefense = in.readU32();
    mDurability = in.readU32();
    mWepCategory = in.readU8();
    mAttack = in.readU32();
    mMagicAttack = in.readU32();
    mShieldStagger = in.readU32();
    mWeight = in.readU16();
    mMaxHpRev = in.readU16();
    mMaxStRev = in.readU16();
    mColorNo = in.readU8();
    mSex = in.readU8();
    mModelParts = in.readU8();
    mEleSlot = in.readU8();
    mPhysicalType = in.readU8();
    mElementType = in.readU8();
    mEquipParamS8Num = in.readU8();
    *pUseNum = mEquipParamS8Num;
    for (u32 i = 0; i < mEquipParamS8Num; ++i) {
        rEquipParamS8* pData = new (&pArray[i]) rEquipParamS8();
        pData->load(in);
    }
    return true;
}

__attribute__((weak)) bool rItemList::rWeaponParam::save(MtDataWriter& out) {
    out.writeU32(mModelTagId);
    out.writeU32(mPowerRev);
    out.writeU32(mChance);
    out.writeU32(mDefense);
    out.writeU32(mMagicDefense);
    out.writeU32(mDurability);
    out.writeU8(mWepCategory);
    out.writeU32(mAttack);
    out.writeU32(mMagicAttack);
    out.writeU32(mShieldStagger);
    out.writeU16(mWeight);
    out.writeU16(mMaxHpRev);
    out.writeU16(mMaxStRev);
    out.writeU8(mColorNo);
    out.writeU8(mSex);
    out.writeU8(mModelParts);
    out.writeU8(mEleSlot);
    out.writeU8(mPhysicalType);
    out.writeU8(mElementType);
    out.writeU8(mEquipParamS8Num);
    for (u32 i = 0; i < mEquipParamS8Num; ++i) {
        rEquipParamS8* pEquipParamS8 = &mpEquipParamS8List[i];
        pEquipParamS8->save(out);
    }
    return true;
}

inline rItemList::rWeaponParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rItemList::rWeaponParam::MyDTI rItemList::rWeaponParam::DTI("rItemList::rWeaponParam", &::MtObject::DTI, 72ul, 0u, 0u);

MtObject* rItemList::rWeaponParam::MyDTI::newInstance() const {
    return new (16u) rItemList::rWeaponParam;
}

const MtDTI& rItemList::rEquipParamS8::getDTI() const {
    return rItemList::rEquipParamS8::DTI;
}

__attribute__((weak)) void rItemList::rEquipParamS8::createProperty(MtPropertyList& s) {
    DDON_STUB("rItemList::rEquipParamS8::createProperty")
    /* stub */
}

MtUI* rItemList::rEquipParamS8::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) bool rItemList::rEquipParamS8::load(MtDataReader& in) {
    mKindType = in.readU8();
    mForm = in.readU8();
    switch (mForm) {
    case FORM_TYPE_S8:
        mValue.mValueS8 = in.readS8();
        break;
    case FORM_TYPE_U8:
        mValue.mValueU8 = in.readU8();
        break;
    case FORM_TYPE_S16:
        mValue.mValueS16 = in.readS16();
        break;
    case FORM_TYPE_U16:
        mValue.mValueU16 = in.readU16();
        break;
    }
    return true;
}

__attribute__((weak)) bool rItemList::rEquipParamS8::save(MtDataWriter& out) {
    out.writeU8(mKindType);
    out.writeU8(mForm);
    switch (mForm) {
    case FORM_TYPE_S8:
        out.writeS8(mValue.mValueS8);
        break;
    case FORM_TYPE_U8:
        out.writeU8(mValue.mValueU8);
        break;
    case FORM_TYPE_S16:
        out.writeS16(mValue.mValueS16);
        break;
    case FORM_TYPE_U16:
        out.writeU16(mValue.mValueU16);
        break;
    }
    return true;
}

inline rItemList::rEquipParamS8::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rItemList::rEquipParamS8::MyDTI rItemList::rEquipParamS8::DTI("rItemList::rEquipParamS8", &::MtObject::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* rItemList::rEquipParamS8::MyDTI::newInstance() const {
    DDON_STUB("rItemList::rEquipParamS8::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& rItemList::rItemParamXml::getDTI() const {
    return rItemList::rItemParamXml::DTI;
}

void rItemList::rItemParamXml::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mItemId", &mItemId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNameId", &mNameId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStackMax", &mStackMax, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIconNo", &mIconNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIconColNo", &mIconColNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCategory", reinterpret_cast<s32*>(&mCategory), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaterialCategory", reinterpret_cast<s32*>(&mMaterialCategory), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPrice", &mPrice, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsSell", &mIsSell, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsBazaar", &mIsBazaar, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRank", &mRank, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGrade", &mGrade, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSortNo", &mSortNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNameSortNo", &mNameSortNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUseType", reinterpret_cast<s32*>(&mUseType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAttackStatus", &mAttackStatus, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsUnUseLobby", &mIsUnUseLobby, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWepCategory", reinterpret_cast<s32*>(&mWepCategory), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEquip", &mEquip, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPhysicalType", &mPhysicalType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mElementType", &mElementType, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsJob01", &mIsJob01, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsJob02", &mIsJob02, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsJob03", &mIsJob03, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsJob04", &mIsJob04, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsJob05", &mIsJob05, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsJob06", &mIsJob06, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsJob07", &mIsJob07, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsJob08", &mIsJob08, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsJob09", &mIsJob09, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsJob10", &mIsJob10, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsUseLv", &mIsUseLv, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWeight", &mWeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIsUseNpc", &mIsUseNpc, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEleSlot", &mEleSlot, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColorNo", &mColorNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSex", &mSex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mModelTagId", &mModelTagId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mModelParts", &mModelParts, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAttack", &mAttack, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMagicAttack", &mMagicAttack, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPowerRev", &mPowerRev, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShieldStagger", &mShieldStagger, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShieldStamina", &mShieldStamina, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTShieldStorage", &mTShieldStorage, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mArrowNum", &mArrowNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVsEm00", &mVsEm00, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVsEm01", &mVsEm01, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVsEm02", &mVsEm02, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVsEm03", &mVsEm03, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVsEm04", &mVsEm04, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVsEm05", &mVsEm05, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVsEm06", &mVsEm06, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVsEm07", &mVsEm07, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVsEm08", &mVsEm08, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVsEm09", &mVsEm09, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVsEm0a", &mVsEm0a, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVsEm0b", &mVsEm0b, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVsEm0c", &mVsEm0c, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVsEm0d", &mVsEm0d, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVsEm0e", &mVsEm0e, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVsEm0f", &mVsEm0f, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPoisonSav", &mPoisonSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSlowSav", &mSlowSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOilSav", &mOilSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBlindSav", &mBlindSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSleepSav", &mSleepSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWaterSav", &mWaterSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSealSav", &mSealSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSoftBodySav", &mSoftBodySav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStoneSav", &mStoneSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGoldSav", &mGoldSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpredSav", &mSpredSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFreezeSav", &mFreezeSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShockSav", &mShockSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCrossSav", &mCrossSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStanSav", &mStanSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFallFireSav", &mFallFireSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFallIceSav", &mFallIceSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFallThunderSav", &mFallThunderSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFallSaintSav", &mFallSaintSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFallBlindSav", &mFallBlindSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFallAttackSav", &mFallAttackSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFallDefSav", &mFallDefSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFallMagicSav", &mFallMagicSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFallMagicDefSav", &mFallMagicDefSav, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mChance", &mChance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDefense", &mDefense, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMagicDefense", &mMagicDefense, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDurability", &mDurability, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpirit", &mSpirit, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaxHpRev", &mMaxHpRev, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaxStRev", &mMaxStRev, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFireEleDef", &mFireEleDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mIceEleDef", &mIceEleDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mThunderEleDef", &mThunderEleDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSaintEleDef", &mSaintEleDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDarkEleDef", &mDarkEleDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPoisonDef", &mPoisonDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSlowDef", &mSlowDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOilDef", &mOilDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mBlindDef", &mBlindDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSleepDef", &mSleepDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWaterDef", &mWaterDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSealDef", &mSealDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSoftBodyDef", &mSoftBodyDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStoneDef", &mStoneDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mGoldDef", &mGoldDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSpredDef", &mSpredDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFreezeDef", &mFreezeDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mShockDef", &mShockDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCrossDef", &mCrossDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mStanDef", &mStanDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mCurseDef", &mCurseDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFallFireDef", &mFallFireDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFallIceDef", &mFallIceDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFallThunderDef", &mFallThunderDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFallSaintDef", &mFallSaintDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFallBlindDef", &mFallBlindDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFallAttackDef", &mFallAttackDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFallDefenceDef", &mFallDefenceDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFallMagicAttackDef", &mFallMagicAttackDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mFallMagicDefenceDef", &mFallMagicDefenceDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mErosionDef", &mErosionDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mItemSealDef", &mItemSealDef, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEquipSubCategory", &mEquipSubCategory, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mParamNum", &mParamNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mItemParamList", static_cast<MtObject*>(&mItemParamList), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVsEmNum", &mVsEmNum, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mVsEmList", static_cast<MtObject*>(&mVsEmList), 0u, 0u);
}

MtUI* rItemList::rItemParamXml::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline rItemList::rItemParamXml::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rItemList::rItemParamXml::MyDTI rItemList::rItemParamXml::DTI("rItemList::rItemParamXml", &::MtObject::DTI, 352ul, 0u, 0u);

MtObject* rItemList::rItemParamXml::MyDTI::newInstance() const {
    return new (16u) rItemList::rItemParamXml;
}

const MtDTI& rItemList::rProtectorParam::getDTI() const {
    return rItemList::rProtectorParam::DTI;
}

rItemList::rProtectorParam::~rProtectorParam() {
    if (mpEquipParamS8List != nullptr) {
        for (u8 i = 0; i < mEquipParamS8Num; ++i) {
            mpEquipParamS8List[i].~rEquipParamS8();
        }
    }
    mpEquipParamS8List = nullptr;
    mEquipParamS8Num = 0;
}

void rItemList::rProtectorParam::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mModelTagId", &mModelTagId, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPowerRev", &mPowerRev, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mChance", &mChance, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDefense", &mDefense, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMagicDefense", &mMagicDefense, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDurability", &mDurability, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAttack", &mAttack, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMagicAttack", &mMagicAttack, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mWeight", &mWeight, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaxHpRev", &mMaxHpRev, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mMaxStRev", &mMaxStRev, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mColorNo", &mColorNo, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSex", &mSex, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mModelParts", &mModelParts, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEleSlot", &mEleSlot, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mEquipParamS8Num", &mEquipParamS8Num, 0u, 0u);
}

MtUI* rItemList::rProtectorParam::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) bool rItemList::rProtectorParam::load(MtDataReader& in, rItemList::rEquipParamS8* pArray, u32* pUseNum) {
    mModelTagId = in.readU32();
    mPowerRev = in.readU32();
    mChance = in.readU32();
    mDefense = in.readU32();
    mMagicDefense = in.readU32();
    mDurability = in.readU32();
    mAttack = in.readU32();
    mMagicAttack = in.readU32();
    mWeight = in.readU16();
    mMaxHpRev = in.readU16();
    mMaxStRev = in.readU16();
    mColorNo = in.readU8();
    mSex = in.readU8();
    mModelParts = in.readU8();
    mEleSlot = in.readU8();
    mEquipParamS8Num = in.readU8();
    *pUseNum = mEquipParamS8Num;
    for (u32 i = 0; i < mEquipParamS8Num; ++i) {
        rEquipParamS8* pData = new (&pArray[i]) rEquipParamS8();
        pData->load(in);
    }
    return true;
}

bool rItemList::rProtectorParam::save(MtDataWriter& out) {
    out.writeU32(mModelTagId);
    out.writeU32(mPowerRev);
    out.writeU32(mChance);
    out.writeU32(mDefense);
    out.writeU32(mMagicDefense);
    out.writeU32(mDurability);
    out.writeU32(mAttack);
    out.writeU32(mMagicAttack);
    out.writeU16(mWeight);
    out.writeU16(mMaxHpRev);
    out.writeU16(mMaxStRev);
    u8 t1 = mColorNo;
    if (out.mSeekPt >= out.mBufsiz) {
        out.flush();
    }
    out.mBuffer[out.mSeekPt] = t1;
    u32 t2 = out.mSeekPt;
    out.mSeekPt = t2 + 1u;
    u8 t3 = mSex;
    if (out.mSeekPt >= out.mBufsiz) {
        out.flush();
        out.mBuffer[out.mSeekPt] = t3;
    } else {
        out.mBuffer[t2 + 1u] = t3;
    }
    u32 t4 = out.mSeekPt;
    out.mSeekPt = t4 + 1u;
    u8 t5 = mModelParts;
    if (out.mSeekPt >= out.mBufsiz) {
        out.flush();
        out.mBuffer[out.mSeekPt] = t5;
    } else {
        out.mBuffer[t4 + 1u] = t5;
    }
    u32 t6 = out.mSeekPt;
    out.mSeekPt = t6 + 1u;
    u8 t7 = mEleSlot;
    if (out.mSeekPt >= out.mBufsiz) {
        out.flush();
        out.mBuffer[out.mSeekPt] = t7;
    } else {
        out.mBuffer[t6 + 1u] = t7;
    }
    u32 t8 = out.mSeekPt;
    out.mSeekPt = t8 + 1u;
    u8 t9 = mEquipParamS8Num;
    if (out.mSeekPt >= out.mBufsiz) {
        out.flush();
        out.mBuffer[out.mSeekPt] = t9;
    } else {
        out.mBuffer[t8 + 1u] = t9;
    }
    out.mSeekPt = out.mSeekPt + 1u;
    if (mEquipParamS8Num != 0) {
        for (unsigned int i0_3 = 0;;) {
            mpEquipParamS8List[i0_3].save(out);
            if ((i0_3 + 1u) < mEquipParamS8Num) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    return true;
}

inline rItemList::rProtectorParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rItemList::rProtectorParam::MyDTI rItemList::rProtectorParam::DTI("rItemList::rProtectorParam", &::MtObject::DTI, 64ul, 0u, 0u);

MtObject* rItemList::rProtectorParam::MyDTI::newInstance() const {
    return new (16u) rItemList::rProtectorParam;
}

const MtDTI& rItemList::rEquipParamS32::getDTI() const {
    return rItemList::rEquipParamS32::DTI;
}

__attribute__((weak)) void rItemList::rEquipParamS32::createProperty(MtPropertyList& s) {
    DDON_STUB("rItemList::rEquipParamS32::createProperty")
    /* stub */
}

MtUI* rItemList::rEquipParamS32::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) bool rItemList::rEquipParamS32::load(MtDataReader& in) {
    DDON_STUB("rItemList::rEquipParamS32::load")
    return {};
}

__attribute__((weak)) bool rItemList::rEquipParamS32::save(MtDataWriter& out) {
    DDON_STUB("rItemList::rEquipParamS32::save")
    return {};
}

inline rItemList::rEquipParamS32::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rItemList::rEquipParamS32::MyDTI rItemList::rEquipParamS32::DTI("rItemList::rEquipParamS32", &::MtObject::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* rItemList::rEquipParamS32::MyDTI::newInstance() const {
    DDON_STUB("rItemList::rEquipParamS32::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<rItemList::rParam>::~MtTypedArray();

template MtTypedArray<rItemList::rVsEnemyParam>::~MtTypedArray();

