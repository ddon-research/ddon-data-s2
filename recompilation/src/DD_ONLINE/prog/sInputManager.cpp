// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include "sInputManager.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive2D.h"
#include "../../MT/MtString.h"
#include "../../MT/MtSynchronize.h"
#include "cKeyCustom.h"
#include "cMenuBase.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cSystem.h"
#include "nDDOUtility.h"
#include "../../generated/shared/nHuman.h"
#include "../../generated/shared/nKeyCustom.h"
#include "../../generated/shared/nUnicode.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUIMessage.h"
#include "rKeyCustomParam.h"
#include "sArchiveManager.h"
#include "sFlag.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "../../XFramework/sKeyboard.h"
#include "sKeyboardExt.h"
#include "../../XFramework/sMain.h"
#include "sMenu.h"
#include "../../XFramework/sMouse.h"
#include "sMouseExt.h"
#include "../../XFramework/sPad.h"
#include "sPadExt.h"
#include "../../XFramework/sSavedata.h"
#include "sSavedataExt.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

static const MT_WCHAR DefaultUserNameFormat[8] = {
    12467,
    12531,
    12501,
    12451,
    12464,
    37,
    100,
    0,
};

const MtDTI& sInputManager::getDTI() const {
    return sInputManager::DTI;
}

void* sInputManager::operator new(size_t sz, u32 align) {
    return sInputManager::getAllocator()->memAlloc(sz, align, sInputManager::DTI.getID());
}

sInputManager::sInputManager() {
    DDON_STUB("sInputManager::sInputManager")
    /* stub */
}

sInputManager::~sInputManager() {
    releaseResource();
    sInputManager::mpInstance = nullptr;
}

void sInputManager::reset() {
    mDisableInputGame = false;
    mDisableInputGameByPauseMenu = false;
}

__attribute__((weak)) void sInputManager::move() {
    DDON_STUB("sInputManager::move")
    /* stub */
}

void sInputManager::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
}

void sInputManager::loadResource() {
    u32 tagId = rArchiveListArray::convTagId("key_custom");
    u32 searchId = rArchiveListArray::convSearchId("RES_ID_KEY_CUSTOM_KCP");
    mprCommonPresetKey = static_cast<rKeyCustomParam*>(sArchiveManager::getInstance()->createRes(tagId, searchId, 1u, false));
    mArcLoadFinish = true;
}

__attribute__((weak)) void sInputManager::releaseResource() {
    if (mprCommonPresetKey != nullptr) {
        mprCommonPresetKey->release();
        mprCommonPresetKey = nullptr;
    }
    if (mprJobPresetKey[0] != nullptr) {
        mprJobPresetKey[0]->cResource::release();
        mprJobPresetKey[0] = nullptr;
    }
    if (mprJobPresetKey[1] != nullptr) {
        mprJobPresetKey[1]->cResource::release();
        mprJobPresetKey[1] = nullptr;
    }
    if (mprJobPresetKey[2] != nullptr) {
        mprJobPresetKey[2]->cResource::release();
        mprJobPresetKey[2] = nullptr;
    }
    if (mprJobPresetKey[3] != nullptr) {
        mprJobPresetKey[3]->cResource::release();
        mprJobPresetKey[3] = nullptr;
    }
    if (mprJobPresetKey[4] != nullptr) {
        mprJobPresetKey[4]->cResource::release();
        mprJobPresetKey[4] = nullptr;
    }
    if (mprJobPresetKey[5] != nullptr) {
        mprJobPresetKey[5]->cResource::release();
        mprJobPresetKey[5] = nullptr;
    }
    if (mprJobPresetKey[6] != nullptr) {
        mprJobPresetKey[6]->cResource::release();
        mprJobPresetKey[6] = nullptr;
    }
    if (mprJobPresetKey[7] != nullptr) {
        mprJobPresetKey[7]->cResource::release();
        mprJobPresetKey[7] = nullptr;
    }
    if (mprJobPresetKey[8] != nullptr) {
        mprJobPresetKey[8]->cResource::release();
        mprJobPresetKey[8] = nullptr;
    }
    if (mprJobPresetKey[9] != nullptr) {
        mprJobPresetKey[9]->cResource::release();
        mprJobPresetKey[9] = nullptr;
    }
}

__attribute__((weak)) void sInputManager::init() {
    DDON_STUB("sInputManager::init")
    /* stub */
}

u32 sInputManager::getInputMode() {
    return static_cast<u32>(mInputMode);
}

void sInputManager::setInputMode(u32 mode) {
    mInputMode = static_cast<s32>(mode);
}

__attribute__((weak)) void sInputManager::setDisableInputGame(bool Disable) {
    DDON_STUB("sInputManager::setDisableInputGame")
    /* stub */
}

bool sInputManager::isDisableInputGame() const {
    return mDisableInputGame;
}

void sInputManager::setDisableInputGameByPauseMenu(bool Disable) {
    mDisableInputGameByPauseMenu = Disable;
}

bool sInputManager::isDisableInputGameByPauseMenu() const {
    if (sMenu::getInstance() != nullptr) {
        if (!sMenu::getInstance()->checkMoveMenu(static_cast<cMenuBase*>(&sMenu::getInstance()->mMenuCraftMenu), false)) {
            if (!sMenu::getInstance()->checkMoveMenu(static_cast<cMenuBase*>(&sMenu::getInstance()->mPawnManageMenu), false)) {
                if (!sMenu::getInstance()->checkMoveMenu(static_cast<cMenuBase*>(&sMenu::getInstance()->mMyPawnList), false)) {
                    if (!sMenu::getInstance()->checkMoveMenu(static_cast<cMenuBase*>(&sMenu::getInstance()->mRentalPawnList), false)) {
                        if (!sMenu::getInstance()->checkMoveMenu(static_cast<cMenuBase*>(&sMenu::getInstance()->mPartyManager), false)) {
                            if (!sMenu::getInstance()->checkMoveMenu(static_cast<cMenuBase*>(&sMenu::getInstance()->mMenuAreaMaster), false)) {
                                return mDisableInputGameByPauseMenu;
                            }
                        }
                    }
                }
            }
        }
        return true;
    } else {
        return mDisableInputGameByPauseMenu;
    }
}

__attribute__((weak)) void sInputManager::setJobId(nHuman::JOB_ENUM job) {
    DDON_STUB("sInputManager::setJobId")
    /* stub */
}

__attribute__((weak)) bool sInputManager::checkModifierKeyKbm(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode) {
    DDON_STUB("sInputManager::checkModifierKeyKbm")
    return {};
}

__attribute__((weak)) bool sInputManager::checkModifierKeyPad(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode, u32 padId) {
    DDON_STUB("sInputManager::checkModifierKeyPad")
    return {};
}

__attribute__((weak)) bool sInputManager::checkModifierKeyPad2(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode, u32 padId) {
    DDON_STUB("sInputManager::checkModifierKeyPad2")
    return {};
}

__attribute__((weak)) bool sInputManager::getCustomKeySetting(nKeyCustom::KB_CUSTOM kb, u32& key, u32& modifier) {
    DDON_STUB("sInputManager::getCustomKeySetting")
    return {};
}

__attribute__((weak)) void sInputManager::getCustomPadSetting(nKeyCustom::KB_CUSTOM kb, u32& pad, u32& modifier) {
    DDON_STUB("sInputManager::getCustomPadSetting")
    /* stub */
}

__attribute__((weak)) nKeyCustom::KB_CUSTOM sInputManager::getCustomKeyIdFromTagParam(MT_CTSTR tagParam) const {
    DDON_STUB("sInputManager::getCustomKeyIdFromTagParam")
    return {};
}

__attribute__((weak)) u32 sInputManager::getCustomKeySkillTrigger(nKeyCustom::KB_CUSTOM kb) {
    DDON_STUB("sInputManager::getCustomKeySkillTrigger")
    return {};
}

__attribute__((weak)) u32 sInputManager::getCustomKeySkillOn(nKeyCustom::KB_CUSTOM kb) {
    DDON_STUB("sInputManager::getCustomKeySkillOn")
    return {};
}

__attribute__((weak)) u32 sInputManager::getCustomKeySkillDerive(nKeyCustom::KB_CUSTOM kb, nKeyCustom::GET_TYPE type, u32 padId) {
    DDON_STUB("sInputManager::getCustomKeySkillDerive")
    return {};
}

void sInputManager::writeData(MtDataWriter& w, u32 SaveVersion) {
    if (SaveVersion > 0x1000004u) {
        if (mThreadSafe || (cSystem::mJobSafe)) {
            if (scePthreadMutexLock(&mCS.mCSection) != 0) {
                abort();
                return;
            }
        }
        mHeader.magic = 0x4D434B;
        mHeader.version = 21;
        mHeader.settingNum = 3;
        if (w.mSeekPt >= w.mBufsiz) {
            w.flush();
        }
        w.mBuffer[w.mSeekPt] = 12;
        w.mSeekPt = w.mSeekPt + 1u;
        w.write(static_cast<const void*>(&mHeader), 12u);
        if (mHeader.settingNum == 0) {
            if (mThreadSafe || (cSystem::mJobSafe)) {
                if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
                    abort();
                    return;
                }
            }
            return;
        }
    } else {
        return;
    }
    u32 i = 0;
    do {
        mCommonKeyCustomManager[i].dataWrite(static_cast<u8>(0xFF), w);
        i += 1u;
    } while (i < mHeader.settingNum);
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
        }
    }
}

__attribute__((weak)) void sInputManager::readData(MtDataReader& r, u32 CurrentVersion, u32 LoadVersion) {
    DDON_STUB("sInputManager::readData")
    /* stub */
}

void sInputManager::editApply(cKeyCustomManager& cmn, u32 categoryNo) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    mCommonKeyCustomManager[categoryNo] = cmn;
    static_cast<sGUIExt*>(sGUI::getInstance())->updateFKeyPaletteGuide();
    static_cast<sGUIExt*>(sGUI::getInstance())->noticeUpdateButtonGuide();
    mCommonKeyCustomManager[categoryNo].setSoloExcludeModifierKey();
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

void sInputManager::editCancel(cKeyCustomManager& cmn, u32 categoryNo) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    cmn = mCommonKeyCustomManager[categoryNo];
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

bool sInputManager::editCompare(cKeyCustomManager& cmn, u32 categoryNo, bool isCheckName) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
        bool t0 = cmn.isEqual(mCommonKeyCustomManager[categoryNo], isCheckName);
        if (mThreadSafe || (cSystem::mJobSafe)) {
            int t1 = scePthreadMutexUnlock(&mCS.mCSection);
            if (t1 != 0) {
                abort();
            }
            return t0;
        } else {
            return t0;
        }
    } else {
        bool t0 = cmn.isEqual(mCommonKeyCustomManager[categoryNo], isCheckName);
        if (mThreadSafe || (cSystem::mJobSafe)) {
            int t1 = scePthreadMutexUnlock(&mCS.mCSection);
            if (t1 != 0) {
                abort();
            }
            return t0;
        } else {
            return t0;
        }
    }
}

__attribute__((weak)) void sInputManager::editDefault(cKeyCustomManager& cmn) {
    DDON_STUB("sInputManager::editDefault")
    /* stub */
}

__attribute__((weak)) void sInputManager::editCancel(cKeyCustomManager& cmn, u32 categoryNo, nKeyCustom::KB_CUSTOM kb) {
    DDON_STUB("sInputManager::editCancel")
    /* stub */
}

__attribute__((weak)) void sInputManager::editDefault(cKeyCustomManager& cmn, nKeyCustom::KB_CUSTOM kb) {
    DDON_STUB("sInputManager::editDefault")
    /* stub */
}

bool sInputManager::editCompare(cKeyCustomManager& cmn, u32 categoryNo, nKeyCustom::KB_CUSTOM kb) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    if (mCommonKeyCustomManager[categoryNo].mCustomArray.mpArray[kb] != nullptr) {
        if (cmn.mCustomArray.mpArray[kb] != nullptr) {
            if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(mCommonKeyCustomManager[categoryNo].mCustomArray.mpArray[kb]) + 8)) == static_cast<cKeyCustom*>(cmn.mCustomArray.mpArray[kb])->mSt.mJobId) {
                if ((*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(mCommonKeyCustomManager[categoryNo].mCustomArray.mpArray[kb]) + 9)) == static_cast<cKeyCustom*>(cmn.mCustomArray.mpArray[kb])->mSt.mKbcIndex) {
                    if ((*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(mCommonKeyCustomManager[categoryNo].mCustomArray.mpArray[kb]) + 10)) == static_cast<cKeyCustom*>(cmn.mCustomArray.mpArray[kb])->mSt.mKbmFlag) {
                        if ((*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(mCommonKeyCustomManager[categoryNo].mCustomArray.mpArray[kb]) + 12)) == static_cast<cKeyCustom*>(cmn.mCustomArray.mpArray[kb])->mSt.mKey) {
                            if ((*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(mCommonKeyCustomManager[categoryNo].mCustomArray.mpArray[kb]) + 14)) == static_cast<cKeyCustom*>(cmn.mCustomArray.mpArray[kb])->mSt.mBtn) {
                                if ((*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(mCommonKeyCustomManager[categoryNo].mCustomArray.mpArray[kb]) + 16)) == static_cast<cKeyCustom*>(cmn.mCustomArray.mpArray[kb])->mSt.mPadFlag) {
                                    if (static_cast<cKeyCustom*>(cmn.mCustomArray.mpArray[kb])->mSt.mPad == (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mCommonKeyCustomManager[categoryNo].mCustomArray.mpArray[kb]) + 20))) {
                                        u32 t0 = static_cast<cKeyCustom*>(cmn.mCustomArray.mpArray[kb])->mSt.mPad2;
                                        unsigned int t1 = *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mCommonKeyCustomManager[categoryNo].mCustomArray.mpArray[kb]) + 24);
                                        if (mThreadSafe || (cSystem::mJobSafe)) {
                                            int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                                            if (t2 != 0) {
                                                abort();
                                            }
                                            return t0 == t1;
                                        } else {
                                            return t0 == t1;
                                        }
                                    } else {
                                        if (mThreadSafe || (cSystem::mJobSafe)) {
                                            int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                                            if (t2 != 0) {
                                                abort();
                                            }
                                            return false;
                                        } else {
                                            return false;
                                        }
                                    }
                                } else {
                                    if (mThreadSafe || (cSystem::mJobSafe)) {
                                        int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                                        if (t2 != 0) {
                                            abort();
                                        }
                                        return false;
                                    } else {
                                        return false;
                                    }
                                }
                            } else {
                                if (mThreadSafe || (cSystem::mJobSafe)) {
                                    int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                                    if (t2 != 0) {
                                        abort();
                                    }
                                    return false;
                                } else {
                                    return false;
                                }
                            }
                        } else {
                            if (mThreadSafe || (cSystem::mJobSafe)) {
                                int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                                if (t2 != 0) {
                                    abort();
                                }
                                return false;
                            } else {
                                return false;
                            }
                        }
                    } else {
                        if (mThreadSafe || (cSystem::mJobSafe)) {
                            int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                            if (t2 != 0) {
                                abort();
                            }
                            return false;
                        } else {
                            return false;
                        }
                    }
                } else {
                    if (mThreadSafe || (cSystem::mJobSafe)) {
                        int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                        if (t2 != 0) {
                            abort();
                        }
                        return false;
                    } else {
                        return false;
                    }
                }
            } else {
                if (mThreadSafe || (cSystem::mJobSafe)) {
                    int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                    if (t2 != 0) {
                        abort();
                    }
                    return false;
                } else {
                    return false;
                }
            }
        } else {
            if (mThreadSafe || (cSystem::mJobSafe)) {
                int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                if (t2 != 0) {
                    abort();
                }
                return false;
            } else {
                return false;
            }
        }
    } else {
        if (mThreadSafe || (cSystem::mJobSafe)) {
            int t2 = scePthreadMutexUnlock(&mCS.mCSection);
            if (t2 != 0) {
                abort();
            }
            return false;
        } else {
            return false;
        }
    }
}

bool sInputManager::editCompareDefault(cKeyCustomManager& cmn, nKeyCustom::KB_CUSTOM kb) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    if (mCommonKeyDefaultManager.mCustomArray.mpArray[kb] != nullptr) {
        if (cmn.mCustomArray.mpArray[kb] != nullptr) {
            if (static_cast<cKeyCustom*>(mCommonKeyDefaultManager.mCustomArray.mpArray[kb])->mSt.mJobId == static_cast<cKeyCustom*>(cmn.mCustomArray.mpArray[kb])->mSt.mJobId) {
                if (static_cast<cKeyCustom*>(mCommonKeyDefaultManager.mCustomArray.mpArray[kb])->mSt.mKbcIndex == static_cast<cKeyCustom*>(cmn.mCustomArray.mpArray[kb])->mSt.mKbcIndex) {
                    if (static_cast<cKeyCustom*>(mCommonKeyDefaultManager.mCustomArray.mpArray[kb])->mSt.mKbmFlag == static_cast<cKeyCustom*>(cmn.mCustomArray.mpArray[kb])->mSt.mKbmFlag) {
                        if (static_cast<cKeyCustom*>(mCommonKeyDefaultManager.mCustomArray.mpArray[kb])->mSt.mKey == static_cast<cKeyCustom*>(cmn.mCustomArray.mpArray[kb])->mSt.mKey) {
                            if (static_cast<cKeyCustom*>(mCommonKeyDefaultManager.mCustomArray.mpArray[kb])->mSt.mBtn == static_cast<cKeyCustom*>(cmn.mCustomArray.mpArray[kb])->mSt.mBtn) {
                                if (static_cast<cKeyCustom*>(mCommonKeyDefaultManager.mCustomArray.mpArray[kb])->mSt.mPadFlag == static_cast<cKeyCustom*>(cmn.mCustomArray.mpArray[kb])->mSt.mPadFlag) {
                                    if (static_cast<cKeyCustom*>(cmn.mCustomArray.mpArray[kb])->mSt.mPad == static_cast<cKeyCustom*>(mCommonKeyDefaultManager.mCustomArray.mpArray[kb])->mSt.mPad) {
                                        u32 t0 = static_cast<cKeyCustom*>(cmn.mCustomArray.mpArray[kb])->mSt.mPad2;
                                        u32 t1 = static_cast<cKeyCustom*>(mCommonKeyDefaultManager.mCustomArray.mpArray[kb])->mSt.mPad2;
                                        if (mThreadSafe || (cSystem::mJobSafe)) {
                                            int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                                            if (t2 != 0) {
                                                abort();
                                            }
                                            return t0 == t1;
                                        } else {
                                            return t0 == t1;
                                        }
                                    } else {
                                        if (mThreadSafe || (cSystem::mJobSafe)) {
                                            int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                                            if (t2 != 0) {
                                                abort();
                                            }
                                            return false;
                                        } else {
                                            return false;
                                        }
                                    }
                                } else {
                                    if (mThreadSafe || (cSystem::mJobSafe)) {
                                        int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                                        if (t2 != 0) {
                                            abort();
                                        }
                                        return false;
                                    } else {
                                        return false;
                                    }
                                }
                            } else {
                                if (mThreadSafe || (cSystem::mJobSafe)) {
                                    int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                                    if (t2 != 0) {
                                        abort();
                                    }
                                    return false;
                                } else {
                                    return false;
                                }
                            }
                        } else {
                            if (mThreadSafe || (cSystem::mJobSafe)) {
                                int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                                if (t2 != 0) {
                                    abort();
                                }
                                return false;
                            } else {
                                return false;
                            }
                        }
                    } else {
                        if (mThreadSafe || (cSystem::mJobSafe)) {
                            int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                            if (t2 != 0) {
                                abort();
                            }
                            return false;
                        } else {
                            return false;
                        }
                    }
                } else {
                    if (mThreadSafe || (cSystem::mJobSafe)) {
                        int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                        if (t2 != 0) {
                            abort();
                        }
                        return false;
                    } else {
                        return false;
                    }
                }
            } else {
                if (mThreadSafe || (cSystem::mJobSafe)) {
                    int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                    if (t2 != 0) {
                        abort();
                    }
                    return false;
                } else {
                    return false;
                }
            }
        } else {
            if (mThreadSafe || (cSystem::mJobSafe)) {
                int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                if (t2 != 0) {
                    abort();
                }
                return false;
            } else {
                return false;
            }
        }
    } else {
        if (mThreadSafe || (cSystem::mJobSafe)) {
            int t2 = scePthreadMutexUnlock(&mCS.mCSection);
            if (t2 != 0) {
                abort();
            }
            return false;
        } else {
            return false;
        }
    }
}

__attribute__((weak)) void sInputManager::checkDetectInputDevice() {
    DDON_STUB("sInputManager::checkDetectInputDevice")
    /* stub */
}

__attribute__((weak)) bool sInputManager::isSoloExcludeModifierKey(nKeyCustom::KB_CUSTOM kb, nKeyCustom::MODE_TYPE mode) {
    DDON_STUB("sInputManager::isSoloExcludeModifierKey")
    return {};
}

__attribute__((weak)) u32 sInputManager::getKeyCommon(nKeyCustom::KB_CUSTOM kb, nKeyCustom::GET_TYPE type, nKeyCustom::MODE_TYPE mode, u32 padId) {
    DDON_STUB("sInputManager::getKeyCommon")
    return {};
}

inline sInputManager::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sInputManager::MyDTI sInputManager::DTI("sInputManager", &::cSystem::DTI, 528ul, 0u, 0u);

sInputManager* sInputManager::mpInstance;

__attribute__((weak)) MtObject* sInputManager::MyDTI::newInstance() const {
    DDON_STUB("sInputManager::MyDTI::newInstance")
    return nullptr;
}

