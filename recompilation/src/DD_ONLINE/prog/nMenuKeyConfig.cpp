// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nMenuKeyConfig.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cKeyCustom.h"
#include "nGUIKeyConfig.h"
#include "../../generated/shared/nKeyCustom.h"
#include "rKeyConfigTextTable.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sInputManager.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

u32 nMenuKeyConfig::CategoryListItems::getItemNum() const {
    return 3;
}

MT_CTSTR nMenuKeyConfig::CategoryListItems::getName(u32 itemIndex) const {
    if (itemIndex < getItemNum()) {
        if (mBaseKeyCustomManagers != nullptr) {
            if (itemIndex <= 2u) {
                if (mBaseKeyCustomManagers->mKeyCustomManagers[itemIndex] != nullptr) {
                    return mBaseKeyCustomManagers->mKeyCustomManagers[itemIndex]->mUserName.::MtString::ptr();
                }
            }
            return "";
        } else {
            return ::sInputManager::getInstance()->mCommonKeyCustomManager[itemIndex].mUserName.ptr();
        }
    } else {
        return "";
    }
}

nGUIKeyConfig::CATEGORY_STATE nMenuKeyConfig::CategoryListItems::getState(u32 itemIndex) const {
    if (itemIndex < getItemNum()) {
        if (itemIndex <= 2u) {
            if (mKeyCustomManagers.mKeyCustomManagers[itemIndex] != nullptr) {
                if (!mKeyCustomManagers.mKeyCustomManagers[itemIndex]->::cKeyCustomManager::isExistOverlap()) {
                    if (mKeyCustomManagers.mKeyCustomManagers[itemIndex] != nullptr) {
                        return static_cast<nGUIKeyConfig::CATEGORY_STATE>(!::sInputManager::getInstance()->editCompare(*mKeyCustomManagers.mKeyCustomManagers[itemIndex], itemIndex, false));
                    } else {
                        return ::nGUIKeyConfig::CATEGORY_STATE_NONE;
                    }
                } else {
                    return ::nGUIKeyConfig::CATEGORY_STATE_OVERLAPPED;
                }
            } else {
                return ::nGUIKeyConfig::CATEGORY_STATE_NONE;
            }
        } else {
            return ::nGUIKeyConfig::CATEGORY_STATE_NONE;
        }
    } else {
        return ::nGUIKeyConfig::CATEGORY_STATE_NONE;
    }
}

nMenuKeyConfig::KeyCustomManagers::KeyCustomManagers() {
    mKeyCustomManagers[2] = nullptr;
    mKeyCustomManagers[1] = nullptr;
    mKeyCustomManagers[0] = nullptr;
}

nMenuKeyConfig::KeyCustomManagers::~KeyCustomManagers() {
    if (mKeyCustomManagers[0] != nullptr) {
        delete mKeyCustomManagers[0];
        mKeyCustomManagers[0] = nullptr;
    }
    if (mKeyCustomManagers[1] != nullptr) {
        delete mKeyCustomManagers[1];
        mKeyCustomManagers[1] = nullptr;
    }
    if (mKeyCustomManagers[2] == nullptr) {
        return;
    }
    delete mKeyCustomManagers[2];
    mKeyCustomManagers[2] = nullptr;
}

__attribute__((weak)) void nMenuKeyConfig::KeyCustomManagers::init() {
    DDON_STUB("nMenuKeyConfig::KeyCustomManagers::init")
    /* stub */
}

__attribute__((weak)) void nMenuKeyConfig::KeyCustomManagers::init(const nMenuKeyConfig::KeyCustomManagers& source) {
    DDON_STUB("nMenuKeyConfig::KeyCustomManagers::init")
    /* stub */
}

void nMenuKeyConfig::KeyCustomManagers::release() {
    if (mKeyCustomManagers[0] != nullptr) {
        delete mKeyCustomManagers[0];
        mKeyCustomManagers[0] = nullptr;
    }
    if (mKeyCustomManagers[1] != nullptr) {
        delete mKeyCustomManagers[1];
        mKeyCustomManagers[1] = nullptr;
    }
    if (mKeyCustomManagers[2] == nullptr) {
        return;
    }
    delete mKeyCustomManagers[2];
    mKeyCustomManagers[2] = nullptr;
}

__attribute__((weak)) void nMenuKeyConfig::KeyCustomManagers::apply(u32 categoryNo, const nMenuKeyConfig::KeyCustomManagers& source, u32 sourceCategoryNo) {
        cKeyCustomManager* const key_custom_manager = getManager(categoryNo);
        cKeyCustomManager* const other_key_custom_manager = source.getManager(sourceCategoryNo);
        if (other_key_custom_manager == nullptr) {
            return;
        }
        if (key_custom_manager == nullptr) {
            return;
        }
        if (key_custom_manager == other_key_custom_manager) {
            return;
        }
        *key_custom_manager = *other_key_custom_manager;
        key_custom_manager->checkOverlap();
}

void nMenuKeyConfig::KeyCustomManagers::apply(u32 categoryNo, const nMenuKeyConfig::KeyCustomManagers& source) {
    if (categoryNo <= 2u) {
        cKeyCustomManager* const other_key_custom_manager = source.mKeyCustomManagers[categoryNo];
        if (other_key_custom_manager != nullptr) {
            cKeyCustomManager* const key_custom_manager = mKeyCustomManagers[categoryNo];
            if (key_custom_manager != nullptr) {
                if (other_key_custom_manager != key_custom_manager) {
                    *key_custom_manager = *other_key_custom_manager;
                    key_custom_manager->checkOverlap();
                }
            }
        }
    }
}

bool nMenuKeyConfig::KeyCustomManagers::isExistChange(bool isCheckName) const {
    u32 category_no = 0;
    do {
        if (mKeyCustomManagers[category_no] != nullptr) {
            if (!::sInputManager::getInstance()->editCompare(*mKeyCustomManagers[category_no], category_no, isCheckName)) {
                return true;
            }
        }
        category_no += 1u;
    } while (category_no <= 2u);
    return false;
}

bool nMenuKeyConfig::KeyCustomManagers::isExistChange(u32 categoryNo, bool isCheckName) const {
    if (categoryNo <= 2u) {
        if (mKeyCustomManagers[categoryNo] != nullptr) {
            return !::sInputManager::getInstance()->editCompare(*mKeyCustomManagers[categoryNo], categoryNo, isCheckName);
        }
    }
    return false;
}

bool nMenuKeyConfig::KeyCustomManagers::isExistChange(u32 categoryNo, const nMenuKeyConfig::KeyCustomManagers* source, bool isCheckName) const {
    if (source != nullptr) {
        if (categoryNo <= 2u) {
            if (source->mKeyCustomManagers[categoryNo] != nullptr) {
                if (mKeyCustomManagers[categoryNo] != nullptr) {
                    if (source->mKeyCustomManagers[categoryNo] != mKeyCustomManagers[categoryNo]) {
                        return !mKeyCustomManagers[categoryNo]->::cKeyCustomManager::isEqual(*source->mKeyCustomManagers[categoryNo], isCheckName);
                    }
                }
            }
        }
    } else {
        if (categoryNo <= 2u) {
            if (mKeyCustomManagers[categoryNo] != nullptr) {
                return !::sInputManager::getInstance()->editCompare(*mKeyCustomManagers[categoryNo], categoryNo, isCheckName);
            }
        }
    }
    return false;
}

bool nMenuKeyConfig::KeyCustomManagers::isExistOverlap() const {
    u32 category_no = 0;
    do {
        if (mKeyCustomManagers[category_no] != nullptr) {
            if (mKeyCustomManagers[category_no]->::cKeyCustomManager::isExistOverlap()) {
                return true;
            }
        }
        category_no += 1u;
    } while (category_no <= 2u);
    return false;
}

bool nMenuKeyConfig::KeyCustomManagers::isExistOverlap(u32 categoryNo) const {
    if (categoryNo <= 2u) {
        if (mKeyCustomManagers[categoryNo] != nullptr) {
            return mKeyCustomManagers[categoryNo]->::cKeyCustomManager::isExistOverlap();
        }
    }
    return false;
}

__attribute__((weak)) void nMenuKeyConfig::KeyCustomManagers::setBlank(u32 categoryNo, nKeyCustom::KB_CUSTOM keyCustom) {
    DDON_STUB("nMenuKeyConfig::KeyCustomManagers::setBlank")
    /* stub */
}

void nMenuKeyConfig::KeyCustomManagers::restore(u32 categoryNo, nKeyCustom::KB_CUSTOM keyCustom) {
    if (categoryNo <= 2u) {
        cKeyCustomManager* const key_custom_manager = mKeyCustomManagers[categoryNo];
        if (key_custom_manager != nullptr) {
            ::sInputManager::getInstance()->editCancel(*key_custom_manager, categoryNo, keyCustom);
            key_custom_manager->checkOverlap();
        }
    }
}

void nMenuKeyConfig::KeyCustomManagers::setDefault(u32 categoryNo, nKeyCustom::KB_CUSTOM keyCustom) {
    if (categoryNo <= 2u) {
        cKeyCustomManager* const key_custom_manager = mKeyCustomManagers[categoryNo];
        if (key_custom_manager != nullptr) {
            ::sInputManager::getInstance()->editDefault(*key_custom_manager, keyCustom);
            key_custom_manager->checkOverlap();
        }
    }
}

cKeyCustomManager* nMenuKeyConfig::KeyCustomManagers::getManager(u32 categoryNo) const {
    if (categoryNo <= 2u) {
        return mKeyCustomManagers[categoryNo];
    } else {
        return nullptr;
    }
}

MT_CTSTR nMenuKeyConfig::KeyCustomManagers::getName(u32 categoryNo) const {
    if (categoryNo <= 2u) {
        if (mKeyCustomManagers[categoryNo] != nullptr) {
            return mKeyCustomManagers[categoryNo]->mUserName.::MtString::ptr();
        }
    }
    return "";
}

__attribute__((weak)) void nMenuKeyConfig::KeyCustomManagers::setName(u32 categoryNo, MT_CTSTR name) {
    DDON_STUB("nMenuKeyConfig::KeyCustomManagers::setName")
    /* stub */
}

MT_CTSTR nMenuKeyConfig::KeyListItems::getGroupName(s32 groupId) const {
    if (mResMsgGroup != nullptr) {
        if (static_cast<unsigned int>(groupId) <= 3) {
            return static_cast<sGUIExt*>(::sGUI::getInstance())->getMsgFromIdxInfo(mResMsgGroup, static_cast<u32>(groupId));
        }
    }
    return "";
}

u32 nMenuKeyConfig::KeyListItems::getItemNum(u32 categoryListIndex) const {
    if (mResTextTable != nullptr) {
        return mResTextTable->mSortedArray.mLength;
    } else {
        return 0;
    }
}

s32 nMenuKeyConfig::KeyListItems::getGroupId(u32 itemIndex, u32 categoryListIndex) const {
    if (mResTextTable != nullptr) {
        const nKeyConfigTextTable::cKeyText* const key_text = mResTextTable->getSortedData(itemIndex);
        if (key_text != nullptr) {
            return static_cast<s32>(key_text->mGroupMsgId);
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

s32 nMenuKeyConfig::KeyListItems::getSerialNumber(u32 itemIndex, u32 categoryListIndex) const {
    if (mResTextTable != nullptr) {
        const nKeyConfigTextTable::cKeyText* const key_text = mResTextTable->getSortedData(itemIndex);
        if (key_text != nullptr) {
            return static_cast<s32>(key_text->mSerialNumber);
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

__attribute__((weak)) nGUIKeyConfig::Key nMenuKeyConfig::KeyListItems::getKey(u32 itemIndex, u32 categoryListIndex) const {
    DDON_STUB("nMenuKeyConfig::KeyListItems::getKey")
    __builtin_unreachable();
}

MT_CTSTR nMenuKeyConfig::KeyListItems::getDetail(u32 itemIndex, u32 categoryListIndex) const {
    if (mResMsgDetail != nullptr) {
        if (mResTextTable != nullptr) {
            const nKeyConfigTextTable::cKeyText* const key_text = mResTextTable->getSortedData(itemIndex);
            if (key_text != nullptr) {
                const u32 detail_msg_id = key_text->mDetailMsgId;
                if (detail_msg_id != 0xFFFFFFFFu) {
                    return static_cast<sGUIExt*>(::sGUI::getInstance())->getMsgFromIdxInfo(mResMsgDetail, detail_msg_id);
                } else {
                    return "";
                }
            } else {
                return "";
            }
        } else {
            return "";
        }
    } else {
        return "";
    }
}

__attribute__((weak)) nGUIKeyConfig::KEY_STATE nMenuKeyConfig::KeyListItems::getState(u32 itemIndex, u32 categoryListIndex) const {
    DDON_STUB("nMenuKeyConfig::KeyListItems::getState")
    return {};
}

__attribute__((weak)) s32 nMenuKeyConfig::KeyListItems::getOverlapSerialNumber(u32 itemIndex, u32 categoryListIndex) const {
    DDON_STUB("nMenuKeyConfig::KeyListItems::getOverlapSerialNumber")
    return {};
}

__attribute__((weak)) u32 nMenuKeyConfig::KeyListItems::getOption(u32 itemIndex, u32 categoryListIndex) const {
    DDON_STUB("nMenuKeyConfig::KeyListItems::getOption")
    return {};
}

nKeyCustom::KB_CUSTOM nMenuKeyConfig::KeyListItems::getKeyCustom(u32 itemIndex) const {
    if (mResTextTable != nullptr) {
        const nKeyConfigTextTable::cKeyText* const key_text = mResTextTable->getSortedData(itemIndex);
        if (key_text != nullptr) {
            return static_cast<nKeyCustom::KB_CUSTOM>(key_text->mKeyCustom);
        } else {
            return ::nKeyCustom::KEY_CUSTOM_NOTHING;
        }
    } else {
        return ::nKeyCustom::KEY_CUSTOM_NOTHING;
    }
}

cKeyCustom* nMenuKeyConfig::KeyListItems::getKeyCustomData(u32 itemIndex, u32 categoryListIndex) const {
    if (mResTextTable != nullptr) {
        const nKeyConfigTextTable::cKeyText* t0 = mResTextTable->getSortedData(itemIndex);
        if (t0 != nullptr) {
            if (t0->mKeyCustom != 0) {
                if (categoryListIndex <= 2u) {
                    if (mKeyCustomManagers.mKeyCustomManagers[categoryListIndex] != nullptr) {
                        return static_cast<cKeyCustom*>(mKeyCustomManagers.mKeyCustomManagers[categoryListIndex]->mCustomArray.::MtArray::mpArray[t0->mKeyCustom]);
                    }
                }
            }
        }
        return nullptr;
    } else {
        return nullptr;
    }
}

