// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "rLayoutGroupParam.h"
#include "Protocol/PacketData/Enemy.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtDataWriter.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtPrimitive3D.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtRandom.h"
#include "../../MT/MtString.h"
#include "Protocol/PacketData/Stage.h"
#include "cAreaHit.h"
#include "cComponentManager.h"
#include "cLayoutSetEnemy.h"
#include "cNetGameServer.h"
#include "cOmComponent.h"
#include "cOmControl.h"
#include "../../XFramework/cResource.h"
#include "cpComponent.h"
#include "cpOmGather.h"
#include "../../generated/shared/nDDOIO.h"
#include "nDDOUtility.h"
#include "nLayout.h"
#include "nQuest.h"
#include "../../XFramework/nZone.h"
#include "rLayout.h"
#include "../../XFramework/sArea.h"
#include "sAreaExt.h"
#include "sAreaHit.h"
#include "sContextManager.h"
#include "sControlManager.h"
#include "sFlag.h"
#include "sGame.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sNetwork.h"
#include "sNetworkExt.h"
#include "sOmManager.h"
#include "sPlayerManager.h"
#include "sQuestManagerExt.h"
#include "sSetManager.h"
#include "sWorldOffset.h"
#include "../../XFramework/uBaseModel.h"
#include "../../XFramework/uCoord.h"
#include "uDDOModel.h"
#include "uOmModel.h"
#include "uPlayer.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cGroupParam::getDTI() const {
    return cGroupParam::DTI;
}

void* cGroupParam::operator new(size_t sz, u32 align) {
    return cGroupParam::getAllocator()->memAlloc(sz, align, cGroupParam::DTI.getID());
}

__attribute__((noinline)) cGroupParam::cGroupParam() : mGroup(0), mPriority(0), mIsDisableSplit(0), mIsParts(0), mHasMarkerPos(0), mDataLotFlag(mDataLotFlag & 0xffff0000u), mLoadStageNo(0), mLoadVersionNo(0), mMarkerPos(MtVector3::Zero), mPartsOffset(MtVector3::Zero), mLayer(0), mIsKillAreaInside(false), mKillAreaType(KILL_AREA_ALL), mInvalidFlag(INVALID_KILL_AREA), mAlivePriority(0), mAlivePriorityCnt(0), mAreaHitUseCount(0), mIsDieStageBoss(false), mRandomSeed(0), mIsRequestList(false), mIsSetupList(false), mIsResetList(false), mDriftType(0), mSubGroupRequestBit(0), mSubGroupSetupBit(0), mIsRequestDrop(false), mIsSetupDrop(false) {
    mResetTimer = 0.0f;
    mIsDestroy = false;
    mGuardData.mQuestNo = 0;
    mGuardData.mLayoutFlagNo = 0;
    mLotType = rLayout::TYPE_PLAN;
    mDataCommon = 0;
    mIsLoadLotRes = false;
    mLoadArea.r = 0.0f;
    mLoadArea.pos.x = MtVector3::Zero.x;
    mLoadArea.pos.y = MtVector3::Zero.y;
    mLoadArea.pos.z = MtVector3::Zero.z;
    mLayoutIDArray.setAutoDelete(true);
    mAreaHitShapeList.setAutoDelete(true);
    mSetInfoList.setAutoDelete(true);
    mDropItemList.setAutoDelete(true);
    mLifeAreaArray.setAutoDelete(true);
    mKillAreaList.setAutoDelete(true);
    mResetContextList.setAutoDelete(false);
    mGroupQuestId = nQuest::INVALID_QUEST_ID.toU32();
}

__attribute__((noinline)) cGroupParam::~cGroupParam() {
    final();
}

void cGroupParam::createProperty(MtPropertyList& s) {
    createPropertyCmn(s);
    createPropertySet(s);
    createPropertyLife(s);
    createPropertyKill(s);
}

void cGroupParam::createPropertyCmn(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mGroup", reinterpret_cast<MT_MFUNC>(&::cGroupParam::getGroup), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setGroup), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mPriority", reinterpret_cast<MT_MFUNC>(&::cGroupParam::getPriority), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setPriority), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "\345\210\206\345\211\262\343\202\222\347\204\241\345\212\271\343\201\253\343\201\231\343\202\213", reinterpret_cast<MT_MFUNC>(&::cGroupParam::isDisableSplit), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setIsDisableSplit), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "Num", reinterpret_cast<MT_MFUNC>(&::cGroupParam::getDataNum), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setDummy), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "\343\203\236\343\203\274\343\202\253\343\203\274\345\272\247\346\250\231\343\202\222\350\250\255\345\256\232\343\201\231\343\202\213", reinterpret_cast<MT_MFUNC>(&::cGroupParam::hasMarkerPos), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setHasMarkerPos), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_VECTOR3, "\343\203\236\343\203\274\343\202\253\343\203\274\345\272\247\346\250\231", reinterpret_cast<MT_MFUNC>(&::cGroupParam::getMarkerPos), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setMarkerPos), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mLayoutIDArray", static_cast<MtObject*>(&mLayoutIDArray), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mLayoutDataList", static_cast<MtObject*>(&mLayoutDataList), 2u, 0u);
}

void cGroupParam::createPropertySet(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "LOT\343\203\225\343\203\251\343\202\260", reinterpret_cast<MT_MFUNC>(&::cGroupParam::isLoadLotFlag), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setLoadLotFlag), 2176u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "\343\203\225\343\203\251\343\202\260No.", reinterpret_cast<MT_MFUNC>(&::cGroupParam::getLotFlagNo), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setLotFlagNo), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "\343\202\257\343\202\250\343\202\271\343\203\210\343\203\254\343\202\244\343\202\242\343\202\246\343\203\210\343\203\225\343\203\251\343\202\260", reinterpret_cast<MT_MFUNC>(&::cGroupParam::isLoadLayoutFlag), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setLoadLayoutFlag), 2176u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "\343\202\257\343\202\250\343\202\271\343\203\210No.", reinterpret_cast<MT_MFUNC>(&::cGroupParam::getQuestNo), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setQuestNo), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "\343\203\254\343\202\244\343\202\242\343\202\246\343\203\210\343\203\225\343\203\251\343\202\260No.", reinterpret_cast<MT_MFUNC>(&::cGroupParam::getLayoutFlagNo), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setLayoutFlagNo), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "\343\202\271\343\203\206\343\203\274\343\202\270\346\214\207\345\256\232", reinterpret_cast<MT_MFUNC>(&::cGroupParam::isLoadStage), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setLoadStage), 2176u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "\343\202\271\343\203\206\343\203\274\343\202\270No.", reinterpret_cast<MT_MFUNC>(&::cGroupParam::getLoadStageNo), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setLoadStageNo), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "\343\203\220\343\203\274\343\202\270\343\203\247\343\203\263\346\214\207\345\256\232", reinterpret_cast<MT_MFUNC>(&::cGroupParam::isLoadVersion), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setLoadVersion), 2176u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "\343\203\220\343\203\274\343\202\270\343\203\247\343\203\263No.", reinterpret_cast<MT_MFUNC>(&::cGroupParam::getLoadVersionNo), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setLoadVersionNo), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "\343\202\252\343\203\237\343\203\203\343\203\210", reinterpret_cast<MT_MFUNC>(&::cGroupParam::isLoadOmit), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setLoadOmit), 2176u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "\343\202\267\343\203\263\343\203\227\343\203\253\343\202\244\343\203\231\343\203\263\343\203\210\344\270\255\346\234\200\345\274\267", reinterpret_cast<MT_MFUNC>(&::cGroupParam::isSetSimpleEv), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setSetSimpleEv), 2176u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "\343\203\251\343\203\263\343\203\200\343\203\240\343\203\200\343\203\263\343\202\270\343\203\247\343\203\263\343\201\256\343\201\277", reinterpret_cast<MT_MFUNC>(&::cGroupParam::isLoadRandomOnly), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setLoadRandomOnly), 2177u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "\346\234\200\345\244\247\346\225\260", reinterpret_cast<MT_MFUNC>(&::cGroupParam::getSetMax), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setSetMax), 2176u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "\343\202\250\343\203\252\343\202\242\343\203\222\343\203\203\343\203\210", reinterpret_cast<MT_MFUNC>(&::cGroupParam::isSetAreaHit), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setSetAreaHit), 2176u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mAreaHitShapeList", static_cast<MtObject*>(&mAreaHitShapeList), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "LOT\343\203\225\343\203\251\343\202\260\343\201\214\346\266\210\343\201\210\343\201\237", reinterpret_cast<MT_MFUNC>(&::cGroupParam::isDeleteLotFlag), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setDeleteLotFlag), 2176u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "\343\203\254\343\202\244\343\202\242\343\202\246\343\203\210\343\203\225\343\203\251\343\202\260\343\201\214\346\266\210\343\201\210\343\201\237", reinterpret_cast<MT_MFUNC>(&::cGroupParam::isDeleteLayoutFlag), reinterpret_cast<MT_MFUNC>(&::cGroupParam::setDeleteLayoutFlag), 2176u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

void cGroupParam::createPropertyLife(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mLifeAreaArray", static_cast<MtObject*>(&mLifeAreaArray), 0u, 0u);
}

void cGroupParam::createPropertyKill(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "KILL\343\202\250\343\203\252\343\202\242\343\202\277\343\202\244\343\203\227", reinterpret_cast<s32*>(&mKillAreaType), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mKillAreaList", static_cast<MtObject*>(&mKillAreaList), 0u, 0u);
}

__attribute__((weak)) void cGroupParam::final() {
    mLayoutDataList.MtArray::erase();
    mAreaHitShapeList.MtArray::erase();
    for (u32 i = 0; i < mAreaHitList.mLength; i++) {
        cAreaHit* pAreaHit = static_cast<cAreaHit*>(mAreaHitList.mpArray[static_cast<s32>(i)]);
        pAreaHit->final();
    }
    mAreaHitList.clear(true);
    mLifeAreaArray.MtArray::erase();
    mKillAreaList.MtArray::erase();
    for (u32 t1 = 0; t1 < mSetInfoList.mLength; t1++) {
        if (mSetInfoList.mpArray[t1] != nullptr) {
            delete mSetInfoList.mpArray[t1];
        }
    }
    mSetInfoList.clear(true);
    clearDropItem();
    mResetContextList.clear(true);
}

__attribute__((weak)) bool cGroupParam::load(MtDataReader& r, nLayoutGroupParam::NativeAllocInfo& buffer) {
    mDataCommon = r.readU32();
    mLayoutIDArray.MtArray::erase();
    u32 IdNum = r.readU32();
    if (IdNum != 0) {
        if (buffer.IdUseNum + IdNum > buffer.IdMaxNum) {
            return false;
        }
        mLayoutIDArray.reserve(IdNum);
        cID* pIdTable = &buffer.pIdArray[buffer.IdUseNum];
        for (u32 i = 0; i < IdNum; i++) {
            pIdTable[i].load(r);
            mLayoutIDArray.MtArray::add(&pIdTable[i]);
        }
        buffer.IdUseNum += IdNum;
        mLayoutIDArray.setAutoDelete(false);
    }
    mLoadCondition.mLoadCondition = static_cast<u32>(r.readU32() != 0) | (mLoadCondition.mLoadCondition & 0xfffffffeu);
    mDataLotFlag = r.readU32();
    mLoadCondition.mLoadCondition = (static_cast<u32>(r.readU32() != 0) << 1) | (mLoadCondition.mLoadCondition & 0xfffffffdu);
    mGuardData.mQuestNo = r.readU32();
    mGuardData.mLayoutFlagNo = r.readU32();
    mLoadCondition.mLoadCondition = (static_cast<u32>(r.readU32() != 0) << 2) | (mLoadCondition.mLoadCondition & 0xfffffffbu);
    mLoadCondition.mLoadCondition = (static_cast<u32>(r.readU32() != 0) << 3) | (mLoadCondition.mLoadCondition & 0xfffffff7u);
    mLoadStageNo = r.readU32();
    mSetCondition.mSetCondition = static_cast<u32>(r.readU32() != 0) | (mSetCondition.mSetCondition & 0xfffffffeu);
    mAreaHitShapeList.MtArray::erase();
    u32 AreaHitShapeNum = r.readU32();
    if (AreaHitShapeNum != 0) {
        if (buffer.AreaHitShapeUseNum + AreaHitShapeNum > buffer.AreaHitShapeMaxNum) {
            return false;
        }
        mAreaHitShapeList.reserve(AreaHitShapeNum);
        AreaHitShape* pAreaHitTable = &buffer.pAreaHitShapeArray[buffer.AreaHitShapeUseNum];
        for (u32 i = 0; i < AreaHitShapeNum; i++) {
            pAreaHitTable[i].load(r, &buffer.ShapeAllocInfo);
            mAreaHitShapeList.MtArray::add(&pAreaHitTable[i]);
        }
        buffer.AreaHitShapeUseNum += AreaHitShapeNum;
        mAreaHitShapeList.setAutoDelete(false);
    }
    mSetCondition.mSetCondition = (static_cast<u32>(r.readU32() != 0) << 1) | (mSetCondition.mSetCondition & 0xfffffffdu);
    mSetCondition.mSetCondition = ((static_cast<u32>(r.readS32()) << 2) & 0x3fcu) | (mSetCondition.mSetCondition & 0xfffffc03u);
    mDeleteCondition.mDeleteCondition = static_cast<u32>(r.readU32() != 0) | (mDeleteCondition.mDeleteCondition & 0xfffffffeu);
    mDeleteCondition.mDeleteCondition = (static_cast<u32>(r.readU32() != 0) << 1) | (mDeleteCondition.mDeleteCondition & 0xfffffffdu);
    mLifeAreaArray.MtArray::erase();
    u32 LifeAreaNum = r.readU32();
    if (LifeAreaNum != 0) {
        mLifeAreaArray.reserve(LifeAreaNum);
        if (buffer.LifeAreaUseNum + LifeAreaNum > buffer.LifeAreaMaxNum) {
            return false;
        }
        mLifeAreaArray.reserve(LifeAreaNum);
        cLifeArea* pLifeTable = &buffer.pLifeAreaArray[buffer.LifeAreaUseNum];
        for (u32 i = 0; i < LifeAreaNum; i++) {
            pLifeTable[i].load(r, buffer);
            mLifeAreaArray.MtArray::add(&pLifeTable[i]);
        }
        buffer.LifeAreaUseNum += LifeAreaNum;
        mLifeAreaArray.setAutoDelete(false);
    }
    mKillAreaType = static_cast<KILL_AREA_TYPE>(r.readS32());
    u32 KillAreaNum = r.readU32();
    if (KillAreaNum == 0) {
        return true;
    }
    if (buffer.AreaHitShapeUseNum + KillAreaNum > buffer.AreaHitShapeMaxNum) {
        return false;
    }
    mKillAreaList.reserve(KillAreaNum);
    AreaHitShape* pKillTable = &buffer.pAreaHitShapeArray[buffer.AreaHitShapeUseNum];
    for (u32 i = 0; i < KillAreaNum; i++) {
        pKillTable[i].load(r, &buffer.ShapeAllocInfo);
        mKillAreaList.MtArray::add(&pKillTable[i]);
    }
    buffer.AreaHitShapeUseNum += KillAreaNum;
    mKillAreaList.setAutoDelete(false);
    return true;
}

void cGroupParam::clearWork() {
    if (mAreaHitList.mLength != 0) {
        for (unsigned int i0_3 = 0;;) {
            static_cast<cAreaHit*>(mAreaHitList.getBuffer()[static_cast<int>(i0_3)])->final();
            if ((i0_3 + 1u) < mAreaHitList.mLength) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mAreaHitList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mAreaHitList.mpArray));
    }
    mAreaHitList.mpArray = nullptr;
    mAreaHitList.mBufsiz = 0;
    mAreaHitList.mLength = 0;
    this->mDataPriority = (this->mDataPriority & 0xFF000000u) | 2u;
    mAlivePriorityCnt = 0;
    mAreaHitUseCount = 0;
    mIsDieStageBoss = false;
    if (mSetInfoList.mLength != 0) {
        u32 v2_0 = mSetInfoList.mLength;
        unsigned int i2_3 = 0;
        u32 v3_0;
        for (;;) {
            if (mSetInfoList.mpArray[i2_3] == nullptr) {
                v3_0 = v2_0;
            } else {
                delete mSetInfoList.mpArray[i2_3];
                v3_0 = mSetInfoList.mLength;
            }
            if ((i2_3 + 1u) < v3_0) {
                v2_0 = v3_0;
                i2_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mSetInfoList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSetInfoList.mpArray));
    }
    mSetInfoList.mpArray = nullptr;
    mSetInfoList.mBufsiz = 0;
    mSetInfoList.mLength = 0;
    clearDropItem();
    if (mResetContextList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mResetContextList.mpArray));
    }
    mResetContextList.mpArray = nullptr;
    mResetContextList.mBufsiz = 0;
    mResetContextList.mLength = 0;
    mIsLoadLotRes = false;
    mIsKillAreaInside = false;
    mIsRequestList = false;
    mIsSetupList = false;
    mIsResetList = false;
    mDriftType = 0;
    mSubGroupRequestBit = 0;
    mSubGroupSetupBit = 0;
    mIsRequestDrop = false;
    mIsSetupDrop = false;
    mIsDestroy = false;
    mResetTimer = 0.0f;
}

__attribute__((weak)) void cGroupParam::setAreaOffset(MtVector3& ofs) {
    DDON_STUB("cGroupParam::setAreaOffset")
    /* stub */
}

__attribute__((weak)) void cGroupParam::copy(const cGroupParam& r) {
    DDON_STUB("cGroupParam::copy")
    /* stub */
}

static auto ddon_emit_0x01a99b20 __attribute__((used)) = &cGroupParam::getGroup;

static auto ddon_emit_0x01a99b50 __attribute__((used)) = &cGroupParam::getPriority;

bool cGroupParam::isDisableSplit() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 47)) & 8) >> 3);
}

bool cGroupParam::hasMarkerPos() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 47)) & 32) >> 5);
}

bool cGroupParam::isLoadLotFlag() const {
    return static_cast<bool>(mLoadCondition.mLoadCondition & 1u);
}

bool cGroupParam::isLoadLayoutFlag() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 48)) & 2) >> 1);
}

bool cGroupParam::isLoadRandomOnly() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 48)) & 4) >> 2);
}

u32 cGroupParam::getLotFlagNo() const {
    return *reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(this) + 52);
}

static auto ddon_emit_0x01a99cd0 __attribute__((used)) = &cGroupParam::getQuestNo;

static auto ddon_emit_0x01a99cf0 __attribute__((used)) = &cGroupParam::getLayoutFlagNo;

bool cGroupParam::isLoadStage() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 48)) & 8) >> 3);
}

static auto ddon_emit_0x01a99d40 __attribute__((used)) = &cGroupParam::getLoadStageNo;

bool cGroupParam::isLoadVersion() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 48)) & 16) >> 4);
}

static auto ddon_emit_0x01a99d90 __attribute__((used)) = &cGroupParam::getLoadVersionNo;

bool cGroupParam::isLoadOmit() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 48)) & 32) >> 5);
}

bool cGroupParam::isSetAreaHit() const {
    return static_cast<bool>(mSetCondition.mSetCondition & 1u);
}

bool cGroupParam::isSetSimpleEv() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 72)) & 2) >> 1);
}

static auto ddon_emit_0x01a99e40 __attribute__((used)) = &cGroupParam::getSetMax;

bool cGroupParam::isDeleteLotFlag() const {
    return static_cast<bool>(mDeleteCondition.mDeleteCondition & 1u);
}

bool cGroupParam::isDeleteLayoutFlag() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 180)) & 2) >> 1);
}

static auto ddon_emit_0x01a99bb0 __attribute__((used)) = &cGroupParam::getDataNum;

static auto ddon_emit_0x01a99b30 __attribute__((used)) = &cGroupParam::setGroup;

__attribute__((weak)) void cGroupParam::setDummy(u32 d) {
}

void cGroupParam::setIsDisableSplit(bool b) {
    this->mDataCommon = static_cast<unsigned int>(static_cast<unsigned long>(static_cast<long>(b) * 134217728) | static_cast<unsigned long>(this->mDataCommon & 0xF7FFFFFFu));
}

void cGroupParam::setSetMax(s32 no) {
    mSetCondition.mSetCondition = static_cast<u32>(static_cast<unsigned long>(mSetCondition.mSetCondition & 0xFFFFFC03u) | static_cast<unsigned long>((no * 4) & 0x3FC));
}

void cGroupParam::setHasMarkerPos(bool b) {
    this->mDataCommon = static_cast<unsigned int>(static_cast<unsigned long>(static_cast<long>(b) * 536870912) | static_cast<unsigned long>(this->mDataCommon & 0xDFFFFFFFu));
}

__attribute__((weak)) void cGroupParam::initAreaHit() {
    DDON_STUB("cGroupParam::initAreaHit")
    /* stub */
}

__attribute__((weak)) u32 cGroupParam::getDetectedAreaHit() {
    DDON_STUB("cGroupParam::getDetectedAreaHit")
    return {};
}

static auto ddon_emit_0x01a99c00 __attribute__((used)) = &cGroupParam::getMarkerPos;

void cGroupParam::setMarkerPos(MtVector3& pos) {
    mMarkerPos = pos;
}

bool cGroupParam::isKillAreaInside(const MtVector3& pos) const {
    if (mKillAreaType == KILL_AREA_ALL) {
        return true;
    }
    if (mKillAreaList.mLength == 0) {
        return false;
    }
    u32 i = 0;
    do {
        if (static_cast<AreaHitShape*>(mKillAreaList.mpArray[i])->hitCheck(pos)) {
            return true;
        }
        i += 1u;
    } while (i < mKillAreaList.mLength);
    return false;
}

__attribute__((weak)) bool cGroupParam::isLifeAreaInside(const MtVector3& pos) const {
    DDON_STUB("cGroupParam::isLifeAreaInside")
    return {};
}

__attribute__((weak)) f32 cGroupParam::distNearLifeAreaCenter(const MtVector3& pos) const {
    DDON_STUB("cGroupParam::distNearLifeAreaCenter")
    return {};
}

__attribute__((weak)) bool cGroupParam::isLoadAreaInside(const MtVector3& pos) {
    DDON_STUB("cGroupParam::isLoadAreaInside")
    return {};
}

__attribute__((weak)) const nLayout::stLayoutID* cGroupParam::searchLayoutID(u32 splitX, u32 splitZ) const {
    DDON_STUB("cGroupParam::searchLayoutID")
    return nullptr;
}

__attribute__((weak)) u32 cGroupParam::update(bool isCheckKillArea) {
    DDON_STUB("cGroupParam::update")
    return {};
}

__attribute__((weak)) bool cGroupParam::isValidGroup() const {
    DDON_STUB("cGroupParam::isValidGroup")
    return {};
}

__attribute__((weak)) bool cGroupParam::isWaitRepop(u32 posId) const {
    DDON_STUB("cGroupParam::isWaitRepop")
    return {};
}

__attribute__((weak)) bool cGroupParam::isQuestLayoutFlag() const {
    DDON_STUB("cGroupParam::isQuestLayoutFlag")
    return {};
}

void cGroupParam::setLoadLotFlag(bool b) {
    mLoadCondition.mLoadCondition = static_cast<u32>(static_cast<unsigned long>(mLoadCondition.mLoadCondition & 0xFFFFFFFEu) | static_cast<unsigned long>(b));
}

void cGroupParam::setLoadLayoutFlag(bool b) {
    mLoadCondition.mLoadCondition = static_cast<unsigned int>(static_cast<unsigned long>(static_cast<long>(b) * 2) | static_cast<unsigned long>(mLoadCondition.mLoadCondition & 0xFFFFFFFDu));
}

void cGroupParam::setLoadRandomOnly(bool b) {
    mLoadCondition.mLoadCondition = static_cast<unsigned int>(static_cast<unsigned long>(static_cast<long>(b) * 4) | static_cast<unsigned long>(mLoadCondition.mLoadCondition & 0xFFFFFFFBu));
}

void cGroupParam::setLoadStage(bool b) {
    mLoadCondition.mLoadCondition = static_cast<unsigned int>(static_cast<unsigned long>(static_cast<long>(b) * 8) | static_cast<unsigned long>(mLoadCondition.mLoadCondition & 0xFFFFFFF7u));
}

void cGroupParam::setLoadVersion(bool b) {
    mLoadCondition.mLoadCondition = static_cast<unsigned int>(static_cast<unsigned long>(static_cast<long>(b) * 16) | static_cast<unsigned long>(mLoadCondition.mLoadCondition & 0xFFFFFFEFu));
}

void cGroupParam::setLoadOmit(bool b) {
    mLoadCondition.mLoadCondition = static_cast<unsigned int>(static_cast<unsigned long>(static_cast<long>(b) * 32) | static_cast<unsigned long>(mLoadCondition.mLoadCondition & 0xFFFFFFDFu));
}

__attribute__((weak)) void cGroupParam::setLotFlagNo(u32 no) {
    DDON_STUB("cGroupParam::setLotFlagNo")
    /* stub */
}

void cGroupParam::setQuestNo(u32 no) {
    mGuardData.mQuestNo = no;
}

void cGroupParam::setLayoutFlagNo(u32 no) {
    mGuardData.mLayoutFlagNo = no;
}

void cGroupParam::setLoadStageNo(u32 no) {
    mLoadStageNo = no;
}

void cGroupParam::setLoadVersionNo(u32 no) {
    mLoadVersionNo = no;
}

void cGroupParam::setPriority(u32 prio) {
    this->mDataCommon = (this->mDataCommon & 0xF80001FFu) | ((prio * 512u) & 0x7FFFE00u);
}

void cGroupParam::setSetAreaHit(bool b) {
    mSetCondition.mSetCondition = static_cast<u32>(static_cast<unsigned long>(mSetCondition.mSetCondition & 0xFFFFFFFEu) | static_cast<unsigned long>(b));
}

void cGroupParam::setSetSimpleEv(bool b) {
    mSetCondition.mSetCondition = static_cast<unsigned int>(static_cast<unsigned long>(static_cast<long>(b) * 2) | static_cast<unsigned long>(mSetCondition.mSetCondition & 0xFFFFFFFDu));
}

void cGroupParam::setDeleteLotFlag(bool b) {
    mDeleteCondition.mDeleteCondition = static_cast<u32>(static_cast<unsigned long>(mDeleteCondition.mDeleteCondition & 0xFFFFFFFEu) | static_cast<unsigned long>(b));
}

void cGroupParam::setDeleteLayoutFlag(bool b) {
    mDeleteCondition.mDeleteCondition = static_cast<unsigned int>(static_cast<unsigned long>(static_cast<long>(b) * 2) | static_cast<unsigned long>(mDeleteCondition.mDeleteCondition & 0xFFFFFFFDu));
}

cGroupParam::EmSetInfo* cGroupParam::getEmSetInfo(u32 posId) {
    MtObject* v3_0;
    if (static_cast<int>(mSetInfoList.mLength - 1u) <= -1) {
        v3_0 = nullptr;
    } else {
        MtObject* * v0_1 = mSetInfoList.mpArray;
        for (u32 v0_0 = mSetInfoList.mLength - 1u;;) {
            if (v0_1[v0_0] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(v0_1[v0_0]) + 8)) == posId) {
                    v3_0 = v0_1[v0_0];
                    return static_cast<EmSetInfo*>(v3_0);
                }
            }
            if (static_cast<int>(v0_0 - 1u) > -1) {
                v0_0 += 0xFFFFFFFFu;
            } else {
                break;
            }
        }
        v3_0 = nullptr;
    }
    return static_cast<EmSetInfo*>(v3_0);
}

__attribute__((weak)) cGroupParam::EmSetInfo* cGroupParam::addEmSetInfo(u32 posID, CDataStageLayoutEnemyPresetEnemyInfoClient data) {
    DDON_STUB("cGroupParam::addEmSetInfo")
    return nullptr;
}

__attribute__((weak)) void cGroupParam::setEnemySetList(const u32 subGroupId, const u32 layerNo, u32 seed, u32 questId, const LayoutEnemyDataVec& list) {
    DDON_STUB("cGroupParam::setEnemySetList")
    /* stub */
}

__attribute__((weak)) void cGroupParam::repopEnemySet(const CLayoutEnemyData data, u32 wait_sec) {
    DDON_STUB("cGroupParam::repopEnemySet")
    /* stub */
}

__attribute__((weak)) void cGroupParam::setGatherEnemyList(const u32 posId, CDataStageLayoutID GatheringLayoutId, const u32 GatheringPosId) {
    DDON_STUB("cGroupParam::setGatherEnemyList")
    /* stub */
}

cGroupParam::OmSetInfo* cGroupParam::getOmSetInfo(u32 id) {
    if (mSetInfoList.mLength != 0) {
        u32 i = 0;
        do {
            if (mSetInfoList.mpArray[i] != nullptr) {
                if ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(mSetInfoList.mpArray[i]) + 8)) == id) {
                    return static_cast<OmSetInfo*>(mSetInfoList.mpArray[i]);
                }
            }
            i += 1u;
        } while (i < mSetInfoList.mLength);
    }
    return nullptr;
}

__attribute__((weak)) cGroupParam::OmSetInfo* cGroupParam::addOmSetInfo(u32 id, u32 stat) {
    DDON_STUB("cGroupParam::addOmSetInfo")
    return nullptr;
}

void cGroupParam::setOmSetList(const LayoutItemDataVec& list) {
    if (mSetInfoList.mLength != 0) {
        u32 v0_0 = mSetInfoList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            if (mSetInfoList.mpArray[i0_3] == nullptr) {
                v1_0 = v0_0;
            } else {
                delete mSetInfoList.mpArray[i0_3];
                v1_0 = mSetInfoList.mLength;
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mSetInfoList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSetInfoList.mpArray));
    }
    mSetInfoList.mpArray = nullptr;
    mSetInfoList.mBufsiz = 0;
    mSetInfoList.mLength = 0;
    if (list.mLength != 0) {
        for (unsigned int i3_3 = 0;;) {
            if (!static_cast<CDataLayoutItemData*>(list.mpArray[i3_3])->m_bIsEmpty) {
                if (!static_cast<CDataLayoutItemData*>(list.mpArray[i3_3])->m_bIsAppearEnemy) {
                    if (static_cast<CDataLayoutItemData*>(list.mpArray[i3_3])->m_bIsGathered) {
                        if (addOmSetInfo(static_cast<CDataLayoutItemData*>(list.mpArray[i3_3])->m_ucPosID, 2u) == nullptr) {
                            return;
                        }
                    } else {
                        if (addOmSetInfo(static_cast<CDataLayoutItemData*>(list.mpArray[i3_3])->m_ucPosID, 1u) == nullptr) {
                            return;
                        }
                    }
                } else {
                    if (addOmSetInfo(static_cast<CDataLayoutItemData*>(list.mpArray[i3_3])->m_ucPosID, 3u) == nullptr) {
                        return;
                    }
                }
            } else {
                if (addOmSetInfo(static_cast<CDataLayoutItemData*>(list.mpArray[i3_3])->m_ucPosID, 255u) == nullptr) {
                    return;
                }
            }
            if ((i3_3 + 1u) < list.mLength) {
                i3_3 += 1u;
            } else {
                break;
            }
        }
    }
    mIsSetupList = true;
}

cGroupParam::DropItemInfo* cGroupParam::getDropItemSetInfo(u32 id) {
    if (mDropItemList.mLength != 0) {
        u32 i = 0;
        do {
            if (mDropItemList.mpArray[i] != nullptr) {
                if ((*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(mDropItemList.mpArray[i]) + 10)) == id) {
                    return static_cast<DropItemInfo*>(mDropItemList.mpArray[i]);
                }
            }
            i += 1u;
        } while (i < mDropItemList.mLength);
    }
    return nullptr;
}

__attribute__((weak)) cGroupParam::DropItemInfo* cGroupParam::addDropItemSetInfo(u32 id, u8 mdlType, MtVector3& pos, u32 setType) {
    DDON_STUB("cGroupParam::addDropItemSetInfo")
    return nullptr;
}

__attribute__((weak)) void cGroupParam::setDropItemSetList(const DropItemSetInfoVec& list) {
    DDON_STUB("cGroupParam::setDropItemSetList")
    /* stub */
}

__attribute__((weak)) void cGroupParam::clearDropItem() {
    if (mDropItemList.mLength == 0) {
        if (mDropItemList.mpArray != nullptr) {
            MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mDropItemList.mpArray));
        }
        mDropItemList.mpArray = nullptr;
        mDropItemList.mBufsiz = 0;
        mDropItemList.mLength = 0;
        return;
    } else {
        u32 v0_0 = mDropItemList.mLength;
        unsigned int i0_3 = 0;
        u32 v1_0;
        for (;;) {
            MtObject* t0 = mDropItemList.mpArray[i0_3];
            if (t0 == nullptr) {
                v1_0 = v0_0;
            } else {
                if ((*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 48)) == 0) {
                    v1_0 = v0_0;
                } else {
                    sOmManager::getInstance()->releaseOmCtrl(reinterpret_cast<cOmControl*>(*reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 48)));
                    *reinterpret_cast<unsigned long*>(reinterpret_cast<char*>(t0) + 48) = 0;
                    v1_0 = mDropItemList.mLength;
                }
            }
            if ((i0_3 + 1u) < v1_0) {
                v0_0 = v1_0;
                i0_3 += 1u;
            } else {
                break;
            }
        }
        if (v1_0 == 0) {
            if (mDropItemList.mpArray != nullptr) {
                MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mDropItemList.mpArray));
            }
            mDropItemList.mpArray = nullptr;
            mDropItemList.mBufsiz = 0;
            mDropItemList.mLength = 0;
            return;
        } else {
            u32 v3_0 = v1_0;
            unsigned int i3_3 = 0;
            u32 v4_0;
            for (;;) {
                if (mDropItemList.mpArray[i3_3] == nullptr) {
                    v4_0 = v3_0;
                } else {
                    delete mDropItemList.mpArray[i3_3];
                    v4_0 = mDropItemList.mLength;
                }
                if ((i3_3 + 1u) < v4_0) {
                    v3_0 = v4_0;
                    i3_3 += 1u;
                } else {
                    break;
                }
            }
            if (mDropItemList.mpArray != nullptr) {
                MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mDropItemList.mpArray));
            }
            mDropItemList.mpArray = nullptr;
            mDropItemList.mBufsiz = 0;
            mDropItemList.mLength = 0;
            return;
        }
    }
}

void cGroupParam::resetEnemySetList(f32 frame) {
    if (mIsResetList) {
        return;
    } else {
        if (mIsSetupList) {
            mResetTimer = frame;
        }
        mIsResetList = true;
        if (mSetInfoList.mLength != 0) {
            u32 v0_0 = mSetInfoList.mLength;
            unsigned int i0_3 = 0;
            u32 v1_0;
            for (;;) {
                if (mSetInfoList.mpArray[i0_3] == nullptr) {
                    v1_0 = v0_0;
                } else {
                    delete mSetInfoList.mpArray[i0_3];
                    v1_0 = mSetInfoList.mLength;
                }
                if ((i0_3 + 1u) < v1_0) {
                    v0_0 = v1_0;
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
    if (mSetInfoList.mpArray != nullptr) {
        MtMemoryAllocator::getAllocator(MtArray::DTI)->memFree(static_cast<void*>(mSetInfoList.mpArray));
    }
    mSetInfoList.mpArray = nullptr;
    mSetInfoList.mBufsiz = 0;
    mSetInfoList.mLength = 0;
    mIsRequestList = false;
    mIsSetupList = false;
    mIsDestroy = false;
    sContextManager::getInstance()->getContextEnemytList(static_cast<u32>(sGame::getInstance()->getStageNo()), this->mDataCommon & 511u, mResetContextList);
    clearDropItem();
}

void cGroupParam::destroyEnemySetList() {
    mIsDestroy = true;
}

inline cGroupParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGroupParam::MyDTI cGroupParam::DTI("cGroupParam", &::MtObject::DTI, 800ul, 0u, 0u);

__attribute__((weak)) MtObject* cGroupParam::MyDTI::newInstance() const {
    DDON_STUB("cGroupParam::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cGroupParam::cLifeArea::getDTI() const {
    return cGroupParam::cLifeArea::DTI;
}

void* cGroupParam::cLifeArea::operator new(size_t sz, u32 align) {
    return cGroupParam::cLifeArea::getAllocator()->memAlloc(sz, align, cGroupParam::cLifeArea::DTI.getID());
}

__attribute__((weak)) void cGroupParam::cLifeArea::copy(const cGroupParam::cLifeArea* pParam) {
    DDON_STUB("cGroupParam::cLifeArea::copy")
    /* stub */
}

cGroupParam::cLifeArea::~cLifeArea() {
    if (mShapeList.mAutoDelete) {
        u32 v3_0;
        if (mShapeList.mLength != 0) {
            u32 v0_0 = mShapeList.mLength;
            unsigned int i0_3 = 0;
            u32 v1_0;
            for (;;) {
                if (mShapeList.mpArray[i0_3] == nullptr) {
                    v1_0 = v0_0;
                } else {
                    delete mShapeList.mpArray[i0_3];
                    v1_0 = mShapeList.mLength;
                }
                if ((i0_3 + 1u) < v1_0) {
                    v0_0 = v1_0;
                    i0_3 += 1u;
                } else {
                    break;
                }
            }
            v3_0 = v1_0;
        } else {
            v3_0 = 0;
        }
        memset(static_cast<void*>(mShapeList.mpArray), 0, static_cast<size_t>(v3_0) * 8);
    }
    mShapeList.mLength = 0;
}

void cGroupParam::cLifeArea::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mShapeList", static_cast<MtObject*>(&mShapeList), 0u, 0u);
}

__attribute__((weak)) bool cGroupParam::cLifeArea::load(MtDataReader& r, nLayoutGroupParam::NativeAllocInfo& buffer) {
    mShapeList.MtArray::erase();
    u32 ShapeNum = r.readU32();
    if (ShapeNum == 0) {
        return true;
    }
    if (buffer.AreaHitShapeUseNum + ShapeNum > buffer.AreaHitShapeMaxNum) {
        return false;
    }
    mShapeList.reserve(ShapeNum);
    AreaHitShape* pShapeTable = &buffer.pAreaHitShapeArray[buffer.AreaHitShapeUseNum];
    for (u32 i = 0; i < ShapeNum; i++) {
        pShapeTable[i].load(r, &buffer.ShapeAllocInfo);
        mShapeList.MtArray::add(&pShapeTable[i]);
    }
    buffer.AreaHitShapeUseNum += ShapeNum;
    mShapeList.setAutoDelete(false);
    return true;
}

bool cGroupParam::cLifeArea::save(MtDataWriter& w) {
    w.writeU32(mShapeList.mLength);
    unsigned int i3 = 0;
    if (mShapeList.mLength != 0) {
        do {
            static_cast<AreaHitShape*>(mShapeList.getBuffer()[static_cast<int>(i3)])->save(w);
            i3 += 1u;
        } while (i3 < mShapeList.mLength);
    }
    return true;
}

inline cGroupParam::cLifeArea::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGroupParam::cLifeArea::MyDTI cGroupParam::cLifeArea::DTI("cGroupParam::cLifeArea", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* cGroupParam::cLifeArea::MyDTI::newInstance() const {
    return new (16u) cGroupParam::cLifeArea;
}

const MtDTI& cGroupParam::cID::getDTI() const {
    return cGroupParam::cID::DTI;
}

void* cGroupParam::cID::operator new(size_t sz, u32 align) {
    return cGroupParam::cID::getAllocator()->memAlloc(sz, align, cGroupParam::cID::DTI.getID());
}

void cGroupParam::cID::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "Area", reinterpret_cast<MT_MFUNC>(&::cGroupParam::cID::getArea), reinterpret_cast<MT_MFUNC>(&::cGroupParam::cID::setArea), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "Group", reinterpret_cast<MT_MFUNC>(&::cGroupParam::cID::getGroup), reinterpret_cast<MT_MFUNC>(&::cGroupParam::cID::setGroup), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "SplitX", reinterpret_cast<MT_MFUNC>(&::cGroupParam::cID::getSplitX), reinterpret_cast<MT_MFUNC>(&::cGroupParam::cID::setSplitX), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "SplitZ", reinterpret_cast<MT_MFUNC>(&::cGroupParam::cID::getSplitZ), reinterpret_cast<MT_MFUNC>(&::cGroupParam::cID::setSplitZ), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

__attribute__((weak)) bool cGroupParam::cID::load(MtDataReader& r) {
    mLayoutID.mArea = r.readU32();
    mLayoutID.mGroup = r.readU32();
    mSplitID.mSplitX = r.readU32();
    mSplitID.mSplitZ = r.readU32();
    return true;
}

bool cGroupParam::cID::save(MtDataWriter& w) {
    w.writeU32(mLayoutID.mLayoutID & 1023u);
    w.writeU32(mLayoutID.mLayoutID >> 10);
    w.writeS32(*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 12));
    w.writeS32(*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 14));
    return true;
}

u32 cGroupParam::cID::getArea() const {
    return mLayoutID.mLayoutID & 1023u;
}

u32 cGroupParam::cID::getGroup() const {
    return mLayoutID.mLayoutID >> 10;
}

void cGroupParam::cID::setArea(u32 area) {
    mLayoutID.mLayoutID = (area & 1023u) | (mLayoutID.mLayoutID & 0xFFFFFC00u);
}

void cGroupParam::cID::setGroup(u32 group) {
    mLayoutID.mLayoutID = (group * 1024u) | (mLayoutID.mLayoutID & 1023u);
}

s32 cGroupParam::cID::getSplitX() const {
    return *reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(this) + 12);
}

s32 cGroupParam::cID::getSplitZ() const {
    return *reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(this) + 14);
}

__attribute__((weak)) void cGroupParam::cID::setSplitX(u32 x) {
    DDON_STUB("cGroupParam::cID::setSplitX")
    /* stub */
}

__attribute__((weak)) void cGroupParam::cID::setSplitZ(u32 z) {
    DDON_STUB("cGroupParam::cID::setSplitZ")
    /* stub */
}

inline cGroupParam::cID::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGroupParam::cID::MyDTI cGroupParam::cID::DTI("cGroupParam::cID", &::MtObject::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* cGroupParam::cID::MyDTI::newInstance() const {
    DDON_STUB("cGroupParam::cID::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cGroupParam::EmSetInfo::getDTI() const {
    return cGroupParam::EmSetInfo::DTI;
}

inline cGroupParam::EmSetInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGroupParam::EmSetInfo::MyDTI cGroupParam::EmSetInfo::DTI("cGroupParam::EmSetInfo", &::MtObject::DTI, 88ul, 0u, 0u);

MtObject* cGroupParam::EmSetInfo::MyDTI::newInstance() const {
    return new (16u) cGroupParam::EmSetInfo;
}

const MtDTI& cGroupParam::OmSetInfo::getDTI() const {
    return cGroupParam::OmSetInfo::DTI;
}

inline cGroupParam::OmSetInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGroupParam::OmSetInfo::MyDTI cGroupParam::OmSetInfo::DTI("cGroupParam::OmSetInfo", &::MtObject::DTI, 16ul, 0u, 0u);

MtObject* cGroupParam::OmSetInfo::MyDTI::newInstance() const {
    return new (16u) cGroupParam::OmSetInfo;
}

const MtDTI& cGroupParam::DropItemInfo::getDTI() const {
    return cGroupParam::DropItemInfo::DTI;
}

cGroupParam::DropItemInfo::~DropItemInfo() {
    sOmManager::getInstance()->releaseOmCtrl(mpOmControl);
}

inline cGroupParam::DropItemInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGroupParam::DropItemInfo::MyDTI cGroupParam::DropItemInfo::DTI("cGroupParam::DropItemInfo", &::MtObject::DTI, 64ul, 0u, 0u);

MtObject* cGroupParam::DropItemInfo::MyDTI::newInstance() const {
    return new (16u) cGroupParam::DropItemInfo;
}

const MtDTI& cGroupParam::cUnitData::getDTI() const {
    return cGroupParam::cUnitData::DTI;
}

cGroupParam::cUnitData::~cUnitData() {
}

void cGroupParam::cUnitData::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "name", &name, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "isBelong", &isBelong, 1u, 0u);
}

__attribute__((weak)) bool cGroupParam::cUnitData::load(MtDataReader& r) {
    DDON_STUB("cGroupParam::cUnitData::load")
    return {};
}

bool cGroupParam::cUnitData::save(MtDataWriter& w) {
    w.writeString(name.ptr());
    bool t0 = isBelong;
    if (w.mSeekPt >= w.mBufsiz) {
        w.flush();
    }
    w.mBuffer[w.mSeekPt] = static_cast<u8>(t0);
    w.mSeekPt = w.mSeekPt + 1u;
    return true;
}

inline cGroupParam::cUnitData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGroupParam::cUnitData::MyDTI cGroupParam::cUnitData::DTI("cGroupParam::cUnitData", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cGroupParam::cUnitData::MyDTI::newInstance() const {
    return new (16u) cGroupParam::cUnitData;
}

const MtDTI& rLayoutGroupParamList::getDTI() const {
    return rLayoutGroupParamList::DTI;
}

inline rLayoutGroupParamList::rLayoutGroupParamList() {
    setAttribute(16u);
    memset(static_cast<void*>(&mGroupList[0]), 0, 2052ul);
    memset(static_cast<void*>(&mpGroupParamBuff), 0, 152ul);
}

rLayoutGroupParamList::~rLayoutGroupParamList() {
    destruct();
}

void rLayoutGroupParamList::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mGroupList", &mGroupList[0], 32u, 512u);
}

__attribute__((weak)) void rLayoutGroupParamList::destruct() {
    if (mGroupNum != 0) {
        for (unsigned int i0_3 = 0;;) {
            mpGroupParamBuff[i0_3].~cGroupParam();
            if ((i0_3 + 1u) < mGroupNum) {
                i0_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mAllocInfo.IdMaxNum != 0) {
        for (unsigned int i2_3 = 0;;) {
            mAllocInfo.pIdArray[i2_3].~cID();
            if ((i2_3 + 1u) < mAllocInfo.IdMaxNum) {
                i2_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mAllocInfo.LifeAreaMaxNum != 0) {
        for (unsigned int i4_3 = 0;;) {
            mAllocInfo.pLifeAreaArray[i4_3].~cLifeArea();
            if ((i4_3 + 1u) < mAllocInfo.LifeAreaMaxNum) {
                i4_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mAllocInfo.AreaHitShapeMaxNum != 0) {
        for (unsigned int i6_3 = 0;;) {
            mAllocInfo.pAreaHitShapeArray[i6_3].~AreaHitShape();
            if ((i6_3 + 1u) < mAllocInfo.AreaHitShapeMaxNum) {
                i6_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mAllocInfo.ShapeAllocInfo.ShapeBoxMaxNum != 0) {
        for (unsigned int i8_3 = 0;;) {
            mAllocInfo.ShapeAllocInfo.pShapeBoxArray[i8_3].~ShapeInfoArea();
            if ((i8_3 + 1u) < mAllocInfo.ShapeAllocInfo.ShapeBoxMaxNum) {
                i8_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mAllocInfo.ShapeAllocInfo.ShapeSphereMaxNum != 0) {
        for (unsigned int i10_3 = 0;;) {
            mAllocInfo.ShapeAllocInfo.pShapeSphereArray[i10_3].~ShapeInfoSphere();
            if ((i10_3 + 1u) < mAllocInfo.ShapeAllocInfo.ShapeSphereMaxNum) {
                i10_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mAllocInfo.ShapeAllocInfo.ShapeCylinderMaxNum != 0) {
        unsigned int i12_3 = 0;
        u32 v13_0;
        for (;;) {
            mAllocInfo.ShapeAllocInfo.pShapeCylinderArray[i12_3].~ShapeInfoCylinder();
            v13_0 = mAllocInfo.ShapeAllocInfo.ShapeCylinderMaxNum;
            if ((i12_3 + 1u) < v13_0) {
                i12_3 += 1u;
            } else {
                break;
            }
        }
        if (v13_0 != 0) {
            for (unsigned int i14_3 = 0;;) {
                mAllocInfo.ShapeAllocInfo.pShapeCylinderArray[i14_3].~ShapeInfoCylinder();
                if ((i14_3 + 1u) < mAllocInfo.ShapeAllocInfo.ShapeCylinderMaxNum) {
                    i14_3 += 1u;
                } else {
                    break;
                }
            }
        }
    }
    if (mAllocInfo.ShapeAllocInfo.ShapeConeMaxNum != 0) {
        for (unsigned int i16_3 = 0;;) {
            mAllocInfo.ShapeAllocInfo.pShapeConeArray[i16_3].~ShapeInfoCone();
            if ((i16_3 + 1u) < mAllocInfo.ShapeAllocInfo.ShapeConeMaxNum) {
                i16_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mAllocInfo.ShapeAllocInfo.ShapeAABBMaxNum != 0) {
        for (unsigned int i18_3 = 0;;) {
            mAllocInfo.ShapeAllocInfo.pShapeAABBArray[i18_3].~ShapeInfoAABB();
            if ((i18_3 + 1u) < mAllocInfo.ShapeAllocInfo.ShapeAABBMaxNum) {
                i18_3 += 1u;
            } else {
                break;
            }
        }
    }
    if (mAllocInfo.ShapeAllocInfo.ShapeOBBMaxNum != 0) {
        for (unsigned int i20_3 = 0;;) {
            mAllocInfo.ShapeAllocInfo.pShapeOBBArray[i20_3].~ShapeInfoOBB();
            if ((i20_3 + 1u) < mAllocInfo.ShapeAllocInfo.ShapeOBBMaxNum) {
                i20_3 += 1u;
            } else {
                break;
            }
        }
    }
    MtMemoryAllocator::getAllocator(rLayoutGroupParamList::DTI)->memFree(static_cast<void*>(mpGroupParamBuff));
    clear();
}

void rLayoutGroupParamList::clear() {
    mGroupNum = 0;
    memset(static_cast<void*>(&mpGroupParamBuff), 0, 152ul);
}

__attribute__((weak)) bool rLayoutGroupParamList::load(MtStream& in) {
    MtDataReader r(in, 4096u);
    if (r.readU32() != 0x6c7067u) {
        return false;
    }
    u32 ver = r.readU32();
    if (ver != 64u) {
        return false;
    }
    clear();
    MtDataReader& t1 = r;
    u32* t0 = mGroupList;
    u32 num = t1.readU32();
    t1.read(t0, num * 4u);
    const u32 groupNum = r.readU32();
    if (groupNum == 0) {
        mGroupNum = 0;
        mpGroupParamBuff = nullptr;
        return true;
    }
    nLayoutGroupParam::NeedAllocCountInfo info;
    r.read(&info, sizeof(info));
    u32 TotalAllocSize = groupNum * sizeof(cGroupParam) + info.AreaHitShapeTotalNum * sizeof(AreaHitShape) + info.ShapeInfoSphereTotalNum * sizeof(nZone::ShapeInfoSphere) + info.IdTotalNum * sizeof(cGroupParam::cID) + info.ShapeInfoConeTotalNum * sizeof(nZone::ShapeInfoCone) + info.ShapeInfoOBBTotalNum * sizeof(nZone::ShapeInfoOBB) + info.LifeAreaTotalNum * sizeof(cGroupParam::cLifeArea) + info.ShapeInfoCylinderTotalNum * sizeof(nZone::ShapeInfoCylinder) + info.ShapeInfoAABBTotalNum * sizeof(nZone::ShapeInfoAABB) + info.ShapeInfoAreaTotalNum * sizeof(nZone::ShapeInfoArea);
    nCollisionUtil::LoadBuffer MemBuffer;
    MemBuffer.pBuffer = static_cast<u8*>(MtMemoryAllocator::getAllocator(rLayoutGroupParamList::DTI)->memAlloc(TotalAllocSize, 16u, rLayoutGroupParamList::DTI.getID()));
    if (MemBuffer.pBuffer == nullptr) {
        return false;
    }
    MemBuffer.Position = 0;
    memset(&mAllocInfo, 0, sizeof(mAllocInfo));
    u8* t2 = MemBuffer.pBuffer;
    for (u32 t3 = 0; t3 < groupNum; t3++) {
        new (t2 + MemBuffer.Position) cGroupParam();
        MemBuffer.Position += sizeof(cGroupParam);
    }
    mpGroupParamBuff = reinterpret_cast<cGroupParam*>(t2);
    
    AreaHitShape* t4 = nullptr;
    u32 t21 = info.AreaHitShapeTotalNum;
    if (t21 != 0) {
        t4 = reinterpret_cast<AreaHitShape*>(t2 + MemBuffer.Position);
        for (u32 t3 = 0; t3 < t21; t3++) {
            new (t2 + MemBuffer.Position) AreaHitShape();
            MemBuffer.Position += sizeof(AreaHitShape);
        }
    }
    mAllocInfo.pAreaHitShapeArray = t4;
    mAllocInfo.AreaHitShapeUseNum = 0;
    mAllocInfo.AreaHitShapeMaxNum = info.AreaHitShapeTotalNum;
    
    nZone::ShapeInfoArea* t5 = nullptr;
    u32 t22 = info.ShapeInfoAreaTotalNum;
    if (t22 != 0) {
        t5 = reinterpret_cast<nZone::ShapeInfoArea*>(t2 + MemBuffer.Position);
        for (u32 t3 = 0; t3 < t22; t3++) {
            new (t2 + MemBuffer.Position) nZone::ShapeInfoArea();
            MemBuffer.Position += sizeof(nZone::ShapeInfoArea);
        }
    }
    mAllocInfo.ShapeAllocInfo.pShapeBoxArray = t5;
    mAllocInfo.ShapeAllocInfo.ShapeBoxUseNum = 0;
    mAllocInfo.ShapeAllocInfo.ShapeBoxMaxNum = info.ShapeInfoAreaTotalNum;
    
    nZone::ShapeInfoSphere* t6 = nullptr;
    u32 t23 = info.ShapeInfoSphereTotalNum;
    if (t23 != 0) {
        t6 = reinterpret_cast<nZone::ShapeInfoSphere*>(t2 + MemBuffer.Position);
        for (u32 t3 = 0; t3 < t23; t3++) {
            new (t2 + MemBuffer.Position) nZone::ShapeInfoSphere();
            MemBuffer.Position += sizeof(nZone::ShapeInfoSphere);
        }
    }
    mAllocInfo.ShapeAllocInfo.pShapeSphereArray = t6;
    mAllocInfo.ShapeAllocInfo.ShapeSphereUseNum = 0;
    mAllocInfo.ShapeAllocInfo.ShapeSphereMaxNum = info.ShapeInfoSphereTotalNum;
    
    nZone::ShapeInfoCylinder* t7 = nullptr;
    u32 t24 = info.ShapeInfoCylinderTotalNum;
    if (t24 != 0) {
        t7 = reinterpret_cast<nZone::ShapeInfoCylinder*>(t2 + MemBuffer.Position);
        for (u32 t3 = 0; t3 < t24; t3++) {
            new (t2 + MemBuffer.Position) nZone::ShapeInfoCylinder();
            MemBuffer.Position += sizeof(nZone::ShapeInfoCylinder);
        }
    }
    mAllocInfo.ShapeAllocInfo.pShapeCylinderArray = t7;
    mAllocInfo.ShapeAllocInfo.ShapeCylinderUseNum = 0;
    mAllocInfo.ShapeAllocInfo.ShapeCylinderMaxNum = info.ShapeInfoCylinderTotalNum;
    
    nZone::ShapeInfoCone* t8 = nullptr;
    u32 t25 = info.ShapeInfoConeTotalNum;
    if (t25 != 0) {
        t8 = reinterpret_cast<nZone::ShapeInfoCone*>(t2 + MemBuffer.Position);
        for (u32 t3 = 0; t3 < t25; t3++) {
            new (t2 + MemBuffer.Position) nZone::ShapeInfoCone();
            MemBuffer.Position += sizeof(nZone::ShapeInfoCone);
        }
    }
    mAllocInfo.ShapeAllocInfo.pShapeConeArray = t8;
    mAllocInfo.ShapeAllocInfo.ShapeConeUseNum = 0;
    mAllocInfo.ShapeAllocInfo.ShapeConeMaxNum = info.ShapeInfoConeTotalNum;
    
    nZone::ShapeInfoAABB* t9 = nullptr;
    u32 t26 = info.ShapeInfoAABBTotalNum;
    if (t26 != 0) {
        t9 = reinterpret_cast<nZone::ShapeInfoAABB*>(t2 + MemBuffer.Position);
        for (u32 t3 = 0; t3 < t26; t3++) {
            new (t2 + MemBuffer.Position) nZone::ShapeInfoAABB();
            MemBuffer.Position += sizeof(nZone::ShapeInfoAABB);
        }
    }
    mAllocInfo.ShapeAllocInfo.pShapeAABBArray = t9;
    mAllocInfo.ShapeAllocInfo.ShapeAABBUseNum = 0;
    mAllocInfo.ShapeAllocInfo.ShapeAABBMaxNum = info.ShapeInfoAABBTotalNum;
    
    nZone::ShapeInfoOBB* t10 = nullptr;
    u32 t27 = info.ShapeInfoOBBTotalNum;
    if (t27 != 0) {
        t10 = reinterpret_cast<nZone::ShapeInfoOBB*>(t2 + MemBuffer.Position);
        for (u32 t3 = 0; t3 < t27; t3++) {
            new (t2 + MemBuffer.Position) nZone::ShapeInfoOBB();
            MemBuffer.Position += sizeof(nZone::ShapeInfoOBB);
        }
    }
    mAllocInfo.ShapeAllocInfo.pShapeOBBArray = t10;
    mAllocInfo.ShapeAllocInfo.ShapeOBBUseNum = 0;
    mAllocInfo.ShapeAllocInfo.ShapeOBBMaxNum = info.ShapeInfoOBBTotalNum;
    
    cGroupParam::cLifeArea* t11 = nullptr;
    u32 t28 = info.LifeAreaTotalNum;
    if (t28 != 0) {
        t11 = reinterpret_cast<cGroupParam::cLifeArea*>(t2 + MemBuffer.Position);
        for (u32 t3 = 0; t3 < t28; t3++) {
            new (t2 + MemBuffer.Position) cGroupParam::cLifeArea();
            MemBuffer.Position += sizeof(cGroupParam::cLifeArea);
        }
    }
    mAllocInfo.pLifeAreaArray = t11;
    mAllocInfo.LifeAreaUseNum = 0;
    mAllocInfo.LifeAreaMaxNum = info.LifeAreaTotalNum;
    
    cGroupParam::cID* t12 = nullptr;
    u32 t29 = info.IdTotalNum;
    if (t29 != 0) {
        t12 = reinterpret_cast<cGroupParam::cID*>(t2 + MemBuffer.Position);
        for (u32 t3 = 0; t3 < t29; t3++) {
            new (t2 + MemBuffer.Position) cGroupParam::cID();
            MemBuffer.Position += sizeof(cGroupParam::cID);
        }
    }
    mAllocInfo.pIdArray = t12;
    mAllocInfo.IdUseNum = 0;
    mAllocInfo.IdMaxNum = info.IdTotalNum;
    
    u32 t13 = 0;
    for (u32 i = 0; i < GROUP_NUM; i++) {
        if (static_cast<s32>(mGroupList[i]) < 0) {
            if (t13 == groupNum) {
                return false;
            }
            mpGroupParamBuff[t13].load(r, mAllocInfo);
            t13++;
        }
    }
    mGroupNum = groupNum;
    return true;
}

bool rLayoutGroupParamList::save(MtStream& out) {
    return false;
}

MT_CTSTR rLayoutGroupParamList::getExt() const {
    return "gpl";
}

inline rLayoutGroupParamList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rLayoutGroupParamList::MyDTI rLayoutGroupParamList::DTI("rLayoutGroupParamList", &::cResource::DTI, 2320ul, 0u, 0u);

MtObject* rLayoutGroupParamList::MyDTI::newInstance() const {
    return new (16u) rLayoutGroupParamList;
}

template MtTypedArray<cAreaHit>::~MtTypedArray();

template MtTypedArray<cGroupParam::cID>::~MtTypedArray();

template MtTypedArray<cGroupParam::cLifeArea>::~MtTypedArray();

