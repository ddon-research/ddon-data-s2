// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "sUnitExt.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../XFramework/cSystem.h"
#include "../../XFramework/cUnit.h"
#include "sBakingJointOrder.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sUnit.h"
#include "uDDOModel.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sUnitExt::getDTI() const {
    return sUnitExt::DTI;
}

void* sUnitExt::operator new(size_t sz, u32 align) {
    return sUnitExt::getAllocator()->memAlloc(sz, align, sUnitExt::DTI.getID());
}

sUnitExt::~sUnitExt() {
}

__attribute__((weak)) void sUnitExt::move() {
    DDON_STUB("sUnitExt::move")
    /* stub */
}

void sUnitExt::move(MOVE_LINE n) {
    this->sUnit::move(n);
}

MT_CTSTR sUnitExt::getLineName(MOVE_LINE n) {
    static MT_CTSTR name[29] = {
        "Pre Process",
        "Scheduler",
        "Scheduler Sub",
        "Filter",
        "Scr",
        "Scr Sub",
        "Control",
        "Obj",
        "Obj Sub1",
        "Player",
        "Npc Ai",
        "Enemy",
        "Enemy2",
        "Sub All1",
        "Sub All2",
        "Camera",
        "Effect Ctrl",
        "UI_PMNT",
        "UI_AREA1",
        "UI_AREA2",
        "UI_AREA3",
        "Effect",
        "Effect Sub",
        "Light",
        "Fade",
        "Fade Scheduler",
        "Fade Filter",
        "Post Process",
        "UI_AREA4",
    };
    if (n <= 28) {
        return name[n];
    } else {
        return "Undefined";
    }
}

MT_CTSTR sUnitExt::getGroupName(u32 group) {
    static MT_CTSTR name[61] = {
        "SystemGroup0",
        "SystemGroup1",
        "SystemGroup2",
        "SystemGroup3",
        "SystemGroup4",
        "SystemGroup5",
        "SystemGroup6",
        "SystemGroup7",
        "SystemGroup8",
        "SystemGroup9",
        "SystemGroup10",
        "SystemGroup11",
        "SystemGroup12",
        "SystemGroup13",
        "SystemGroup14",
        "SystemGroup15",
        "UG_PREPROCESS\t\t\t",
        "UG_SCHEDULER",
        "UG_SCHEDULER_SUB\t\t",
        "UG_FILTER",
        "UG_SCR",
        "UG_SCR_SUB",
        "UG_OBJ",
        "UG_OBJ_SUB1",
        "UG_OBJ_SUB2",
        "UG_PLAYER",
        "UG_PLAYER_SUB1\t",
        "UG_PLAYER_SUB2",
        "UG_CMC",
        "UG_CMC_SUB1",
        "UG_NPC",
        "UG_ENEMY",
        "UG_ENEMY_SUB1",
        "UG_ENEMY_SUB2",
        "UG_OBJ2",
        "UG_OBJ2_SUB1",
        "UG_OBJ2_SUB2",
        "UG_CAMERA",
        "UG_EFFECT_CTRL",
        "UG_EFFECT",
        "UG_EFFECT_SUB",
        "UG_LIGHT",
        "UG_UI_MAIN",
        "UG_UI_SUB",
        "UG_UNUSED1",
        "UG_UNUSED2",
        "UG_UNUSED3",
        "UG_UNUSED4",
        "UG_UNUSED5",
        "UG_FADE\t\t",
        "UG_FADE_SCHEDULER\t\t",
        "UG_FADE_FILTER",
        "UG_POSTPROCESS",
        "UG_SHELL1",
        "UG_SHELL2",
        "UG_STOP_EVENT",
        "UG_EFFECT_UNIT",
        "UG_PAUSE",
        "UG_STAGE_SETUP_WAIT",
        "UG_STOP_FSM_EVENT",
        "UG_PAUSE_SYSTEM",
    };
    if (group > 60u) {
        return "undefined";
    } else {
        if (group <= 15u) {
            return this->sUnit::getGroupName(group);
        } else {
            return name[group];
        }
    }
}

void sUnitExt::createProperty(MtPropertyList& s) {
    this->sUnit::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "IsUseCommandCache", reinterpret_cast<MT_MFUNC>(&::sUnitExt::getCommandCacheFlag), reinterpret_cast<MT_MFUNC>(&::sUnitExt::setCommandCacheFlag), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mIsEffectHandleFastMode", &mIsEffectHandleFastMode, 0u, 0u);
}

MtUI* sUnitExt::createUI(MtProperty& prop) {
    return this->sUnit::createUI(prop);
}

__attribute__((weak)) void sUnitExt::unitAllUpdatePtrSingle() {
    DDON_STUB("sUnitExt::unitAllUpdatePtrSingle")
    /* stub */
}

void sUnitExt::evAddUnit(cUnit& unit) {
    const MtDTI& t0 = unit.getDTI();
    MT_CTSTR v0_1 = uDDOModel::DTI.mName;
    for (const MtDTI* v0_0 = &t0;;) {
        if (v0_1 == v0_0->mName) {
            u32 t1 = mDDOModelArray.mLength;
            u32 t2 = mDDOModelArray.mBufsiz;
            if (t1 < t2) {
                mDDOModelArray.mLength = t1 + 1u;
                mDDOModelArray.mpArray[t1] = static_cast<MtObject*>(&unit);
            } else {
                void* t3 = MtMemoryAllocator::getAllocator(MtArray::DTI)->memAlloc(static_cast<size_t>(t2 + 32u) * 8, 16u);
                memset(t3, 0, static_cast<size_t>(t2 + 32u) * 8);
                memcpy(t3, static_cast<const void*>(mDDOModelArray.mpArray), static_cast<size_t>(mDDOModelArray.mLength) * 8);
                MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mDDOModelArray.mpArray));
                mDDOModelArray.mpArray = static_cast<MtObject* *>(t3);
                mDDOModelArray.mBufsiz = t2 + 32u;
                u32 t4 = mDDOModelArray.mLength;
                mDDOModelArray.mLength = t4 + 1u;
                mDDOModelArray.mpArray[t4] = static_cast<MtObject*>(&unit);
            }
            return;
        } else {
            if (v0_0->mpParent != nullptr) {
                v0_0 = v0_0->mpParent;
            } else {
                break;
            }
        }
    }
}

__attribute__((weak)) void sUnitExt::evRemoveUnit(cUnit& unit) {
    DDON_STUB("sUnitExt::evRemoveUnit")
    /* stub */
}

static auto ddon_emit_0x01acfb30 __attribute__((used)) = &sUnitExt::getCommandCacheFlag;

static auto ddon_emit_0x01acfb20 __attribute__((used)) = &sUnitExt::setCommandCacheFlag;

void sUnitExt::forceFlushDrawCommandCache() {
    this->sUnit::forceFlushDrawCommandCache();
    sBakingJointOrder::getInstance()->flushAllCache();
}

void sUnitExt::setForceFlushDrawCommandCacheCount(u32 set) {
    mForceFlushDrawCommandCacheCountDown = static_cast<s32>(set);
}

u32 sUnitExt::getMoveLineId(u32 index) {
    return sUnitExt::mMoveLineOrderTbl[index];
}

__attribute__((weak)) u32 sUnitExt::getNextMoveLineId(u32 lineId) {
    DDON_STUB("sUnitExt::getNextMoveLineId")
    return {};
}

u32 sUnitExt::getPrevMoveLineId(u32 lineId) {
    u32 order = getMoveLineOrder(lineId);
    return sUnitExt::mMoveLineOrderTbl[(order + (order == 0)) - 1u];
}

u32 sUnitExt::getLastMoveLineId() {
    return 27;
}

u32 sUnitExt::getMoveLineOrder(u32 lineId) {
    if (lineId <= 28u) {
        return mMoveLineOrderSearchTbl[lineId];
    } else {
        return 127;
    }
}

inline sUnitExt::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sUnitExt::MyDTI sUnitExt::DTI("sUnitExt", &::sUnit::DTI, 0x372E40ul, 0u, 0u);

alignas(4) unsigned char sUnitExt_mMoveLineOrderTbl_bytes[116] __asm__("_ZN8sUnitExt17mMoveLineOrderTblE") = {0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x1a, 0x00, 0x00, 0x00, 0x1b, 0x00, 0x00, 0x00};

__attribute__((weak)) MtObject* sUnitExt::MyDTI::newInstance() const {
    DDON_STUB("sUnitExt::MyDTI::newInstance")
    return nullptr;
}

