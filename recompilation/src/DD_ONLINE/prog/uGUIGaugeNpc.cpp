// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "uGUIGaugeNpc.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtColor.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive2D.h"
#include "../../MT/MtString.h"
#include "aStage.h"
#include "../../XFramework/cArea.h"
#include "cCharacterData.h"
#include "cComponentManager.h"
#include "cContextInstance.h"
#include "cContextInterface.h"
#include "cGUIExtNetMgr.h"
#include "cGUIFloorManager.h"
#include "../../XFramework/cGUIInstance.h"
#include "../../XFramework/cGUIObject.h"
#include "cGUIUtility.h"
#include "cOmComponent.h"
#include "../../XFramework/cResource.h"
#include "cState.h"
#include "../../XFramework/cUnit.h"
#include "cpActionManager.h"
#include "cpComponent.h"
#include "cpOcdCtrl.h"
#include "cpStateManager.h"
#include "nCharacterData.h"
#include "nDDOUtility.h"
#include "../../XFramework/nGUI.h"
#include "nGUIExt.h"
#include "nQuest.h"
#include "rArchiveListArray.h"
#include "../../XFramework/rGUI.h"
#include "../../XFramework/rGUIMessage.h"
#include "../../XFramework/sArea.h"
#include "../../XFramework/sCamera.h"
#include "sContextManager.h"
#include "../../XFramework/sGUI.h"
#include "sGUIExt.h"
#include "sGame.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sNpcManager.h"
#include "sOmManager.h"
#include "sPlayerManager.h"
#include "sQuestManagerExt.h"
#include "../../XFramework/sRender.h"
#include "sReward.h"
#include "uControl.h"
#include "uControlNpc.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "../../XFramework/uGUI.h"
#include "uGUIBase.h"
#include "uHuman.h"
#include "../../XFramework/uModel.h"
#include "uOmModel.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& uGUIGaugeNpc::getDTI() const {
    return uGUIGaugeNpc::DTI;
}

void* uGUIGaugeNpc::operator new(size_t sz, u32 align) {
    return uGUIGaugeNpc::getAllocator()->memAlloc(sz, align, uGUIGaugeNpc::DTI.getID());
}

uGUIGaugeNpc::uGUIGaugeNpc() {
    DDON_STUB("uGUIGaugeNpc::uGUIGaugeNpc")
    /* stub */
}

__attribute__((noinline)) uGUIGaugeNpc::~uGUIGaugeNpc() {
}

__attribute__((weak)) void uGUIGaugeNpc::setup() {
    DDON_STUB("uGUIGaugeNpc::setup")
    /* stub */
}

void uGUIGaugeNpc::draw(cDraw* pDraw) {
    if (sArea::getInstance()->mpArea[2] != nullptr) {
        if (!static_cast<aStage*>(sArea::getInstance()->mpArea[2])->mEventBusy) {
            this->uGUIBase::draw(pDraw);
        }
    } else {
        this->uGUIBase::draw(pDraw);
    }
}

void uGUIGaugeNpc::setMode(uGUIGaugeNpcBase::MODE mode) {
    if (static_cast<unsigned int>(mode - 1) <= 5) {
        mMode = mode;
    }
}

void uGUIGaugeNpc::resetMode(uGUIGaugeNpcBase::MODE mode) {
    mModeOld = MODE_INVALID;
    mMode = mode;
}

void uGUIGaugeNpc::setObjectName(MT_CTSTR name) {
    if (name != nullptr) {
        if (name != (&mObjectName.mStr[0])) {
            size_t t0 = strlen(name);
            mObjectName.mLength = (static_cast<int>(t0) <= 127) ? static_cast<unsigned int>(t0) : 127u;
            if (((static_cast<int>(t0) <= 127) ? static_cast<unsigned int>(t0) : 127u) != 0) {
                memcpy(static_cast<void*>(&mObjectName.mStr[0]), static_cast<const void*>(name), static_cast<size_t>((static_cast<int>(t0) <= 127) ? static_cast<unsigned int>(t0) : 127u));
                mObjectName.mStr[(static_cast<int>(t0) <= 127) ? static_cast<unsigned int>(t0) : 127u] = 0;
            } else {
                mObjectName.mStr[0] = 0;
            }
        }
    } else {
        mObjectName.mStr[0] = 0;
        mObjectName.mLength = 0;
    }
}

void uGUIGaugeNpc::setTitleName(MT_CTSTR name) {
    if (name != nullptr) {
        if (name != (&mTitleName.mStr[0])) {
            size_t t0 = strlen(name);
            mTitleName.mLength = (static_cast<int>(t0) <= 127) ? static_cast<unsigned int>(t0) : 127u;
            if (((static_cast<int>(t0) <= 127) ? static_cast<unsigned int>(t0) : 127u) != 0) {
                memcpy(static_cast<void*>(&mTitleName.mStr[0]), static_cast<const void*>(name), static_cast<size_t>((static_cast<int>(t0) <= 127) ? static_cast<unsigned int>(t0) : 127u));
                mTitleName.mStr[(static_cast<int>(t0) <= 127) ? static_cast<unsigned int>(t0) : 127u] = 0;
            } else {
                mTitleName.mStr[0] = 0;
            }
        }
    } else {
        mTitleName.mStr[0] = 0;
        mTitleName.mLength = 0;
    }
}

void uGUIGaugeNpc::updateInit() {
    updateMode();
    updateDisp();
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIGaugeNpc::updateWait);
}

__attribute__((weak)) void uGUIGaugeNpc::updateWait() {
    DDON_STUB("uGUIGaugeNpc::updateWait")
    /* stub */
}

__attribute__((weak)) void uGUIGaugeNpc::updateDisp() {
    DDON_STUB("uGUIGaugeNpc::updateDisp")
    /* stub */
}

__attribute__((weak)) void uGUIGaugeNpc::updateMode() {
    DDON_STUB("uGUIGaugeNpc::updateMode")
    /* stub */
}

__attribute__((weak)) void uGUIGaugeNpc::updateName() {
    DDON_STUB("uGUIGaugeNpc::updateName")
    /* stub */
}

__attribute__((weak)) void uGUIGaugeNpc::updateHpGauge(cContextInstHm* context) {
    DDON_STUB("uGUIGaugeNpc::updateHpGauge")
    /* stub */
}

__attribute__((weak)) void uGUIGaugeNpc::updateOmInfo() {
    DDON_STUB("uGUIGaugeNpc::updateOmInfo")
    /* stub */
}

__attribute__((weak)) void uGUIGaugeNpc::updateOmWarpNames() {
    DDON_STUB("uGUIGaugeNpc::updateOmWarpNames")
    /* stub */
}

void uGUIGaugeNpc::setOmWarpName(u32 warpIndex) {
    if (mOmWarpNum != 0) {
        if (warpIndex < mOmWarpNum) {
            MtString::STRING* t0 = mOmWarpNames.elems[(warpIndex <= 2u) ? warpIndex : 0u].value;
            if ((&mTitleName.mStr[0]) != mOmWarpNames.elems[(warpIndex <= 2u) ? warpIndex : 0u].ptr()) {
                size_t t1 = strlen(mOmWarpNames.elems[(warpIndex <= 2u) ? warpIndex : 0u].ptr());
                mTitleName.mLength = (static_cast<int>(t1) <= 127) ? static_cast<unsigned int>(t1) : 127u;
                if (((static_cast<int>(t1) <= 127) ? static_cast<unsigned int>(t1) : 127u) == 0) {
                    mTitleName.mStr[0] = 0;
                } else {
                    memcpy(static_cast<void*>(&mTitleName.mStr[0]), static_cast<const void*>(mOmWarpNames.elems[(warpIndex <= 2u) ? warpIndex : 0u].ptr()), static_cast<size_t>((static_cast<int>(t1) <= 127) ? static_cast<unsigned int>(t1) : 127u));
                    mTitleName.mStr[(static_cast<int>(t1) <= 127) ? static_cast<unsigned int>(t1) : 127u] = 0;
                }
            }
        } else {
            MtString::STRING* t2 = mOmWarpNames.elems[0].value;
            if ((&mTitleName.mStr[0]) != mOmWarpNames.elems[0].ptr()) {
                size_t t3 = strlen(mOmWarpNames.elems[0].ptr());
                mTitleName.mLength = (static_cast<int>(t3) <= 127) ? static_cast<unsigned int>(t3) : 127u;
                if (((static_cast<int>(t3) <= 127) ? static_cast<unsigned int>(t3) : 127u) != 0) {
                    memcpy(static_cast<void*>(&mTitleName.mStr[0]), static_cast<const void*>(mOmWarpNames.elems[0].ptr()), static_cast<size_t>((static_cast<int>(t3) <= 127) ? static_cast<unsigned int>(t3) : 127u));
                    mTitleName.mStr[(static_cast<int>(t3) <= 127) ? static_cast<unsigned int>(t3) : 127u] = 0;
                } else {
                    mTitleName.mStr[0] = 0;
                }
            }
        }
    } else {
        if ("" != (&mTitleName.mStr[0])) {
            mTitleName.mLength = 0;
            mTitleName.mStr[0] = 0;
        }
    }
}

void uGUIGaugeNpc::setNameColor() {
    switch (static_cast<unsigned int>(mMode - 1)) {
        case 0:
        {
            if (mData.mpOBJ_fix_gaugepc_ColorAdjust != nullptr) {
                mData.mpOBJ_fix_gaugepc_ColorAdjust->mAmbientColor.rgba = mNameAmbientColor.rgba;
                setMessageColor(static_cast<cGUIObject*>(mData.mpOBJ_fix_gaugepc_m_name), mNameColor);
            } else {
                setMessageColor(static_cast<cGUIObject*>(mData.mpOBJ_fix_gaugepc_m_name), mNameColor);
            }
            break;
        }
        case 1:
        {
            if (mData.mpOBJ_fix_gaugepc_ColorAdjust != nullptr) {
                mData.mpOBJ_fix_gaugepc_ColorAdjust->mAmbientColor.rgba = mNameAmbientColor.rgba;
                setMessageColor(static_cast<cGUIObject*>(mData.mpOBJ_fix_gaugepc_m_name), mNameColor);
            } else {
                setMessageColor(static_cast<cGUIObject*>(mData.mpOBJ_fix_gaugepc_m_name), mNameColor);
            }
            break;
        }
        case 2:
        {
            if (mpINST_msg_name != nullptr) {
                mpINST_msg_name->mAmbientColor.rgba = mNameAmbientColor.rgba;
                setMessageColor(static_cast<cGUIObject*>(mData.mpOBJ_msg_name_m_name), mNameColor);
            } else {
                setMessageColor(static_cast<cGUIObject*>(mData.mpOBJ_msg_name_m_name), mNameColor);
            }
            break;
        }
        case 3:
        {
            if (mpINST_msg_name != nullptr) {
                mpINST_msg_name->mAmbientColor.rgba = mNameAmbientColor.rgba;
                setMessageColor(static_cast<cGUIObject*>(mData.mpOBJ_msg_name_m_name), mNameColor);
                if (mpINST_msg_npcname != nullptr) {
                    mpINST_msg_npcname->mAmbientColor.rgba = mNameAmbientColor.rgba;
                    setMessageColor(static_cast<cGUIObject*>(mData.mpOBJ_msg_npcname_m_npcname), mNameColor);
                } else {
                    setMessageColor(static_cast<cGUIObject*>(mData.mpOBJ_msg_npcname_m_npcname), mNameColor);
                }
            } else {
                setMessageColor(static_cast<cGUIObject*>(mData.mpOBJ_msg_name_m_name), mNameColor);
                if (mpINST_msg_npcname != nullptr) {
                    mpINST_msg_npcname->mAmbientColor.rgba = mNameAmbientColor.rgba;
                    setMessageColor(static_cast<cGUIObject*>(mData.mpOBJ_msg_npcname_m_npcname), mNameColor);
                } else {
                    setMessageColor(static_cast<cGUIObject*>(mData.mpOBJ_msg_npcname_m_npcname), mNameColor);
                }
            }
            break;
        }
        case 4:
        {
            if (mpINST_msg_npcname != nullptr) {
                mpINST_msg_npcname->mAmbientColor.rgba = mNameAmbientColor.rgba;
                setMessageColor(static_cast<cGUIObject*>(mData.mpOBJ_msg_npcname_m_npcname), mNameColor);
            } else {
                setMessageColor(static_cast<cGUIObject*>(mData.mpOBJ_msg_npcname_m_npcname), mNameColor);
            }
            break;
        }
        default:
        {
            break;
        }
    }
}

bool uGUIGaugeNpc::isVisibleAreaMasterIcon(u32 npcId) {
    if (sNpcManager::getInstance()->isHaveEnableFunction(npcId, 21u)) {
        if (mpUnit != nullptr) {
            uControlNpc* t0 = mpUnit->getCtrlNpc();
            if (t0 != nullptr) {
                if (t0->isDispClassName()) {
                    const u32 area_id = sGame::getInstance()->getArea(static_cast<MtVector3*>(nullptr));
                    u32 v0_1 = static_cast<sGUIExt*>(sGUI::getInstance())->mAreaPointList.size();
                    if (v0_1 == 0) {
                        return false;
                    } else {
                        MtObject* * v0_2 = static_cast<sGUIExt*>(sGUI::getInstance())->mAreaPointList.getBuffer();
                        for (unsigned int i0_3 = 0;;) {
                            if (v0_2[static_cast<int>(i0_3)] != nullptr) {
                                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_2[static_cast<int>(i0_3)]) + 8)) == area_id) {
                                    return (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(v0_2[static_cast<int>(i0_3)]) + 28)) != 0;
                                }
                            }
                            if ((i0_3 + 1u) < v0_1) {
                                i0_3 += 1u;
                            } else {
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

__attribute__((weak)) bool uGUIGaugeNpc::checkFloorGroup() const {
    DDON_STUB("uGUIGaugeNpc::checkFloorGroup")
    return {};
}

inline uGUIGaugeNpc::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIGaugeNpc::MyDTI uGUIGaugeNpc::DTI("uGUIGaugeNpc", &::uGUIGaugeNpcBase::DTI, 4064ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIGaugeNpc::MyDTI::newInstance() const {
    DDON_STUB("uGUIGaugeNpc::MyDTI::newInstance")
    return nullptr;
}

u32 uGUIGaugeNpc::IOcdIcon::getOcdIconParamNum() const {
    return 2;
}

nGUIExt::OCD_ICON_CATEGORY uGUIGaugeNpc::IOcdIcon::getOcdIconCategory(u32 paramIndex) const {
    static const nGUIExt::OCD_ICON_CATEGORY categorys[2] = {
        static_cast<const nGUIExt::OCD_ICON_CATEGORY>(0),
        static_cast<const nGUIExt::OCD_ICON_CATEGORY>(1),
    };
    if (paramIndex <= 1u) {
        return categorys[paramIndex];
    } else {
        return nGUIExt::OCD_ICON_CATEGORY_NUM;
    }
}

nGUIExt::OcdIconParam& uGUIGaugeNpc::IOcdIcon::refOcdIconParam(u32 paramIndex) {
    return mOwner.mStatusInfos.elems[(paramIndex <= 1u) ? paramIndex : 0u].mParam;
}

bool uGUIGaugeNpc::IOcdIcon::isOcdActive(u32 ocdId) const {
    return mHuman.isAbnormalConditionActive(ocdId);
}

bool uGUIGaugeNpc::IOcdIcon::isOcdAccumulating(u32 ocdId) const {
    return false;
}

__attribute__((weak)) void uGUIGaugeNpc::IOcdIcon::setOcdIcon(u32 iconIndex, u32 ocdId, nGUIExt::OCD_ICON_ANIM iconAnim, f32 animFrame) {
    DDON_STUB("uGUIGaugeNpc::IOcdIcon::setOcdIcon")
    /* stub */
}

const MtDTI& uGUIGaugeNpcBase::getDTI() const {
    return uGUIGaugeNpcBase::DTI;
}

__attribute__((weak)) uGUIGaugeNpcBase::MODE uGUIGaugeNpcBase::GetMode(uDDOModel* unit) {
    DDON_STUB("uGUIGaugeNpcBase::GetMode")
    return {};
}

uGUIGaugeNpcBase::~uGUIGaugeNpcBase() {
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

bool uGUIGaugeNpcBase::loadResource() {
    if ((mpGUIRes == nullptr) && ((mpGUIRes = static_cast<rGUI*>(uiCreateResource(getArcTag(0u), rArchiveListArray::convSearchId("RES_ID_GAUGE_NPC_GUI"), 129u, 1456742344l))) == nullptr)) {
        return false;
    }
    return true;
}

void uGUIGaugeNpcBase::kill() {
    this->uGUIBase::kill();
    if (mpGUIRes == nullptr) {
        return;
    }
    mpGUIRes->release();
    mpGUIRes = nullptr;
}

void uGUIGaugeNpcBase::move() {
    this->uGUIBase::move();
    mWorldOffset = MtVector3::Zero;
}

__attribute__((weak)) void uGUIGaugeNpcBase::moveAfter() {
    DDON_STUB("uGUIGaugeNpcBase::moveAfter")
    /* stub */
}

void uGUIGaugeNpcBase::draw(cDraw* pDraw) {
    if (sArea::getInstance()->mpArea[2] != nullptr) {
        if (!static_cast<aStage*>(sArea::getInstance()->mpArea[2])->mEventBusy) {
            this->uGUIBase::draw(pDraw);
        }
    } else {
        this->uGUIBase::draw(pDraw);
    }
}

void uGUIGaugeNpcBase::updatePtr() {
    if (mpUnit != nullptr) {
        if (!mpUnit->isEnable()) {
            mpUnit = nullptr;
            mpHuman = nullptr;
        }
    } else {
        mpHuman = nullptr;
    }
}

void uGUIGaugeNpcBase::applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {
    mWorldOffset = offset;
}

void uGUIGaugeNpcBase::setUnit(uDDOModel* pUnit) {
    mpUnit = pUnit;
    if (pUnit != nullptr) {
        if ((pUnit->mUnitId & 16u) != 0) {
            mpHuman = static_cast<uHuman*>(pUnit);
        } else {
            mpHuman = nullptr;
        }
    } else {
        mpHuman = nullptr;
    }
}

__attribute__((weak)) void uGUIGaugeNpcBase::setupInstances() {
    mpINST_Null = static_cast<cGUIInstNull*>(getInstance(467u, false));
    mpINST_Null_all = static_cast<cGUIInstNull*>(getInstance(370u, false));
    mpINST_target = static_cast<cGUIInstAnimation*>(getInstance(508u, false));
    mpINST_msg_name = static_cast<cGUIInstAnimation*>(getInstance(356u, false));
    mpINST_msg_npcname = static_cast<cGUIInstAnimation*>(getInstance(492u, false));
    mpINST_fix_gaugepc = static_cast<cGUIInstAnimation*>(getInstance(476u, false));
    mpINST_fix_icon00 = static_cast<cGUIInstAnimation*>(getInstance(445u, false));
    mpINST_fix_icon_quest = static_cast<cGUIInstAnimation*>(getInstance(509u, false));
    mpINST_autorun_icon = static_cast<cGUIInstAnimation*>(getInstance(0x1FEu, false));
    mpINST_fix_classicon = static_cast<cGUIInstAnimation*>(getInstance(485u, false));
    mpINST_areamaster_icon = static_cast<cGUIInstAnimation*>(getInstance(514u, false));
    mpINST_sos_icon = static_cast<cGUIInstAnimation*>(getInstance(516u, false));
    cGUIInstance* t0 = getInstance(511u, false);
    if ((mpINST_Null_charges = static_cast<cGUIInstNull*>(t0)) != nullptr) {
        t0->setVisible(false);
        if (mpINST_Null_charges != nullptr) {
            mpINST_Null_charges->setExecute(false);
        }
    }
    mpINST_fix_jyoutais.elems[0] = static_cast<cGUIInstAnimation*>(getInstance(506u, false));
    mpINST_fix_jyoutais.elems[1] = static_cast<cGUIInstAnimation*>(getInstance(507u, false));
}

__attribute__((weak)) bool uGUIGaugeNpcBase::updatePos(const uDDOModel* unit) {
    DDON_STUB("uGUIGaugeNpcBase::updatePos")
    return {};
}

inline uGUIGaugeNpcBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUIGaugeNpcBase::MyDTI uGUIGaugeNpcBase::DTI("uGUIGaugeNpcBase", &::uGUIBase::DTI, 2432ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUIGaugeNpcBase::MyDTI::newInstance() const {
    DDON_STUB("uGUIGaugeNpcBase::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& uGUITouchTargetSelector::getDTI() const {
    return uGUITouchTargetSelector::DTI;
}

void* uGUITouchTargetSelector::operator new(size_t sz, u32 align) {
    return uGUITouchTargetSelector::getAllocator()->memAlloc(sz, align, uGUITouchTargetSelector::DTI.getID());
}

uGUITouchTargetSelector::uGUITouchTargetSelector() {
    DDON_STUB("uGUITouchTargetSelector::uGUITouchTargetSelector")
    /* stub */
}

uGUITouchTargetSelector::~uGUITouchTargetSelector() {
}

void uGUITouchTargetSelector::setup() {
    this->uGUIBase::setup();
    if (!mIsEndLoadResource) {
        return;
    }
    setPlay(true);
    setFlowAndInit(16u, false);
    setupInstances();
    mpOBJ_target_m_key = static_cast<cGUIObjMessage*>(getObjectFromId(static_cast<cGUIInstance*>(mpINST_target), 3u));
    mpOBJ_target_left = static_cast<cGUIObjTexture*>(getObjectFromId(static_cast<cGUIInstance*>(mpINST_target), 4u));
    mpOBJ_target_right = static_cast<cGUIObjTexture*>(getObjectFromId(static_cast<cGUIInstance*>(mpINST_target), 5u));
    mpOBJ_target_center = static_cast<cGUIObjTexture*>(getObjectFromId(static_cast<cGUIInstance*>(mpINST_target), 6u));
    if (mpINST_Null_all != nullptr) {
        mpINST_Null_all->setVisible(false);
        if (mpINST_Null_all != nullptr) {
            mpINST_Null_all->setExecute(false);
        }
    }
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUITouchTargetSelector::updateInit);
}

void uGUITouchTargetSelector::updateInit() {
    mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUITouchTargetSelector::updateWait);
}

__attribute__((weak)) void uGUITouchTargetSelector::updateWait() {
    DDON_STUB("uGUITouchTargetSelector::updateWait")
    /* stub */
}

inline uGUITouchTargetSelector::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

uGUITouchTargetSelector::MyDTI uGUITouchTargetSelector::DTI("uGUITouchTargetSelector", &::uGUIGaugeNpcBase::DTI, 2480ul, 0u, 0u);

__attribute__((weak)) MtObject* uGUITouchTargetSelector::MyDTI::newInstance() const {
    DDON_STUB("uGUITouchTargetSelector::MyDTI::newInstance")
    return nullptr;
}

