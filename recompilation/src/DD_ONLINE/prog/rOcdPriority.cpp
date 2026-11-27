// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rOcdPriority.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtDataReader.h"
#include "../../MT/MtObject.h"
#include "cOcdPriority.h"
#include "../../generated/shared/nDDOIO.h"
#include "rTbl2.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& rOcdPriorityParam::getDTI() const {
    return rOcdPriorityParam::DTI;
}

__attribute__((weak)) bool rOcdPriorityParam::loadData(MtDataReader& in, cOcdPriorityParam* pData) {
    nDDOIO::readData(in, pData->mOcdUID);
    nDDOIO::readData(in, pData->mIsMultiApply);
    nDDOIO::readData(in, pData->mIsMultiNumLimit);
    nDDOIO::readData(in, pData->mMultiApplyNum);
    nDDOIO::readData(in, pData->mOcdClass);
    nDDOIO::readData(in, pData->mOcdLank);
    for (u32 i = 0; i < 27u; ++i) {
        nDDOIO::readData(in, pData->mIsAnnihilateGoodOcd[i]);
    }
    for (u32 i = 0; i < 31u; ++i) {
        nDDOIO::readData(in, pData->mIsAnnihilateBadOcd[i]);
    }
    for (u32 i = 0; i < 5u; ++i) {
        nDDOIO::readData(in, pData->mIsAnnihilateEnchantOcd[i]);
    }
    for (u32 i = 0; i < 9u; ++i) {
        nDDOIO::readData(in, pData->mIsAnnihilateHumanOcd[i]);
    }
    for (u32 i = 0; i < 3u; ++i) {
        nDDOIO::readData(in, pData->mIsAnnihilateEnemyOcd[i]);
    }
    return true;
}

MT_CTSTR rOcdPriorityParam::getExt() const {
    return "opp";
}

u32 rOcdPriorityParam::getDataVersion() const {
    return 23;
}

inline rOcdPriorityParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rOcdPriorityParam::MyDTI rOcdPriorityParam::DTI("rOcdPriorityParam", &::rTbl2Base::DTI, 128ul, 0u, 0u);

MtObject* rOcdPriorityParam::MyDTI::newInstance() const {
    return new (16u) rOcdPriorityParam;
}

template cOcdPriorityParam* rTbl2<cOcdPriorityParam>::getData(unsigned int);

template bool rTbl2<cOcdPriorityParam>::load(MtStream&);

template bool rTbl2<cOcdPriorityParam>::loadCore(MtDataReader&);

template const cOcdPriorityParam* rTbl2<cOcdPriorityParam>::getData(unsigned int) const;

template unsigned int rTbl2<cOcdPriorityParam>::getDataNum() const;

template rTbl2<cOcdPriorityParam>::~rTbl2();

