// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdlib.h>
#include <string.h>
#include "sSceneExt.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtString.h"
#include "../../MT/MtSynchronize.h"
#include "../../MT/MtType.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cSystem.h"
#include "rTexDetailEdit.h"
#include "sArchiveManager.h"
#include "sEnemyManager.h"
#include "sFlag.h"
#include "../../XFramework/sMain.h"
#include "../../XFramework/sScene.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sSceneExt::getDTI() const {
    return sSceneExt::DTI;
}

void* sSceneExt::operator new(size_t sz, u32 align) {
    return sSceneExt::getAllocator()->memAlloc(sz, align, sSceneExt::DTI.getID());
}

sSceneExt::~sSceneExt() {
}

const MT_ENUM* sSceneExt::getLightGroupType() {
    static const MT_ENUM type[21] = {
        {"GROUP_SCR", 1},
        {"GROUP_WATER", 2},
        {"GROUP_EVENT", 4},
        {"GROUP_EFFECT", 8},
        {"GROUP_PL", 16},
        {"GROUP_EM", 32},
        {"GROUP_SCR_DEVIDE", 64},
        {"無効", 128},
        {"GROUP_ID", 256},
        {"無効", 0},
        {"GROUP_EVENT_SH1", 1024},
        {"GROUP_EVENT_SH2", 2048},
        {"無効", 0},
        {"GROUP_EFF_SH", 8192},
        {"GROUP_EFF_PL", 16384},
        {"無効", 0},
        {"無効", 0},
        {"無効", 0},
        {"無効", 0},
        {"無効", 0},
        {nullptr, 0},
    };
    return type;
}

const MT_CTSTR* sSceneExt::getLightGroupTips() {
    static const MT_CTSTR tips[32] = {
        "背景",
        "水",
        "イベント",
        "エフェクト(動的)",
        "プレイヤー",
        "敵",
        "背景分割用",
        "未使用",
        "ＩＤ",
        "未使用",
        "イベント(静的1)",
        "イベント(静的2)",
        "未使用",
        "効果(静的)",
        "効果(PL静的)",
        "未使用",
        "未使用",
        "未使用",
        "未使用",
        "未使用",
        "未使用",
        "未使用",
        "未使用",
        "未使用",
        "未使用",
        "未使用",
        "未使用",
        "未使用",
        "未使用",
        "未使用",
        "未使用",
        "未使用",
    };
    return tips;
}

u32 sSceneExt::getTextureDetail(MT_CTSTR path) {
    return getTextureDetailMain(path);
}

void sSceneExt::createProperty(MtPropertyList& s) {
    this->sScene::createProperty(s);
}

__attribute__((weak)) void sSceneExt::move() {
    DDON_STUB("sSceneExt::move")
    /* stub */
}

u32 sSceneExt::getTextureDetailMain(MT_CTSTR path) {
    return mTextureDetail;
}

bool sSceneExt::isTextureMipEnable(MT_CTSTR path) {
    return true;
}

void sSceneExt::loadTxd() {
    rTexDetailEdit* pRes = static_cast<rTexDetailEdit*>(sArchiveManager::getInstance()->createRes("base", "RES_ID_DDO_TEXTURE_DETAIL_TDE", 1u, false));
    if (pRes == nullptr) {
        return;
    }
    loadTxd(pRes, TEXDETAIL_FILE);
    pRes->release();
}

__attribute__((weak)) void sSceneExt::loadTxd(rTexDetailEdit* pRes, sSceneExt::TEX_DETAIL_TYPE mode) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
    if (mDetail[mode].mTable != nullptr) {
        MtMemoryAllocator::getAllocator(sSceneExt::DTI)->memFree(static_cast<void*>(mDetail[mode].mTable));
        mDetail[mode].mTable = nullptr;
    }
    if (pRes != nullptr) {
        mDetail[mode].num = pRes->mEditList.size();
        void* t0 = MtMemoryAllocator::getAllocator(sSceneExt::DTI)->memAlloc(static_cast<size_t>(mDetail[mode].num) * 76, 16u);
        mDetail[mode].mTable = static_cast<TexDetail*>(t0);
        memset(t0, 0, static_cast<size_t>(mDetail[mode].num) * 76);
        if (mDetail[mode].num != 0) {
            for (unsigned int i0_2 = 0;;) {
                rTexDetailEdit::DetailParam* t1 = pRes->getEditWork(i0_2);
                if (t1 != nullptr) {
                    TexDetail* t2 = mDetail[mode].mTable;
                    MtString::STRING* t3 = t1->mPath.value;
                    u32 t4 = t1->mForm;
                    u32 t5 = t1->mType;
                    u32 t6 = t1->getIgnoreLimit();
                    if (strlen(t1->mPath.ptr()) > 63ul) {
                        t2[i0_2].mIgnoreLimit = false;
                        *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(&t2[i0_2]) + 73) = 0;
                        *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(&t2[i0_2]) + 75) = 0;
                        t2[i0_2].mForm = 0;
                        t2[i0_2].mType = 0;
                        t2[i0_2].mPath[56] = '\0';
                        t2[i0_2].mPath[57] = '\0';
                        t2[i0_2].mPath[58] = '\0';
                        t2[i0_2].mPath[59] = '\0';
                        t2[i0_2].mPath[60] = '\0';
                        t2[i0_2].mPath[61] = '\0';
                        t2[i0_2].mPath[62] = '\0';
                        t2[i0_2].mPath[63] = '\0';
                        t2[i0_2].mPath[48] = '\0';
                        t2[i0_2].mPath[49] = '\0';
                        t2[i0_2].mPath[50] = '\0';
                        t2[i0_2].mPath[51] = '\0';
                        t2[i0_2].mPath[52] = '\0';
                        t2[i0_2].mPath[53] = '\0';
                        t2[i0_2].mPath[54] = '\0';
                        t2[i0_2].mPath[55] = '\0';
                        t2[i0_2].mPath[40] = '\0';
                        t2[i0_2].mPath[41] = '\0';
                        t2[i0_2].mPath[42] = '\0';
                        t2[i0_2].mPath[43] = '\0';
                        t2[i0_2].mPath[44] = '\0';
                        t2[i0_2].mPath[45] = '\0';
                        t2[i0_2].mPath[46] = '\0';
                        t2[i0_2].mPath[47] = '\0';
                        t2[i0_2].mPath[32] = '\0';
                        t2[i0_2].mPath[33] = '\0';
                        t2[i0_2].mPath[34] = '\0';
                        t2[i0_2].mPath[35] = '\0';
                        t2[i0_2].mPath[36] = '\0';
                        t2[i0_2].mPath[37] = '\0';
                        t2[i0_2].mPath[38] = '\0';
                        t2[i0_2].mPath[39] = '\0';
                        t2[i0_2].mPath[24] = '\0';
                        t2[i0_2].mPath[25] = '\0';
                        t2[i0_2].mPath[26] = '\0';
                        t2[i0_2].mPath[27] = '\0';
                        t2[i0_2].mPath[28] = '\0';
                        t2[i0_2].mPath[29] = '\0';
                        t2[i0_2].mPath[30] = '\0';
                        t2[i0_2].mPath[31] = '\0';
                        t2[i0_2].mPath[16] = '\0';
                        t2[i0_2].mPath[17] = '\0';
                        t2[i0_2].mPath[18] = '\0';
                        t2[i0_2].mPath[19] = '\0';
                        t2[i0_2].mPath[20] = '\0';
                        t2[i0_2].mPath[21] = '\0';
                        t2[i0_2].mPath[22] = '\0';
                        t2[i0_2].mPath[23] = '\0';
                        t2[i0_2].mPath[8] = '\0';
                        t2[i0_2].mPath[9] = '\0';
                        t2[i0_2].mPath[10] = '\0';
                        t2[i0_2].mPath[11] = '\0';
                        t2[i0_2].mPath[12] = '\0';
                        t2[i0_2].mPath[13] = '\0';
                        t2[i0_2].mPath[14] = '\0';
                        t2[i0_2].mPath[15] = '\0';
                        t2[i0_2].mPath[0] = '\0';
                        t2[i0_2].mPath[1] = '\0';
                        t2[i0_2].mPath[2] = '\0';
                        t2[i0_2].mPath[3] = '\0';
                        t2[i0_2].mPath[4] = '\0';
                        t2[i0_2].mPath[5] = '\0';
                        t2[i0_2].mPath[6] = '\0';
                        t2[i0_2].mPath[7] = '\0';
                    }
                    strncpy(&t2[i0_2].mPath[0], t1->mPath.ptr(), 63ul);
                    t2[i0_2].mForm = t4;
                    t2[i0_2].mType = static_cast<signed char>(t5);
                    t2[i0_2].mIgnoreLimit = t6 != 0;
                }
                if ((i0_2 + 1u) < mDetail[mode].num) {
                    i0_2 += 1u;
                } else {
                    break;
                }
            }
        }
    }
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
            abort();
            return;
        }
    }
}

void sSceneExt::releaseTxd(sSceneExt::TEX_DETAIL_TYPE mode) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    if (mDetail[mode].mTable != nullptr) {
        MtMemoryAllocator::getAllocator(sSceneExt::DTI)->memFree(static_cast<void*>(mDetail[mode].mTable));
        mDetail[mode].mTable = nullptr;
    }
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

inline sSceneExt::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sSceneExt::MyDTI sSceneExt::DTI("sSceneExt", &::sScene::DTI, 5232ul, 0u, 0u);

__attribute__((weak)) MtObject* sSceneExt::MyDTI::newInstance() const {
    DDON_STUB("sSceneExt::MyDTI::newInstance")
    return nullptr;
}

