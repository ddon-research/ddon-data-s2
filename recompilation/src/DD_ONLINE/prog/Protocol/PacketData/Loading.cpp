// Reconstructed from the game's DWARF debug information.
#include <new>
#include "Loading.h"
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtCollection.h"
#include "../../../../MT/MtDTI.h"
#include "../../../../MT/MtObject.h"
#include "../../../../MT/MtString.h"
#include "../../cPacket.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& CDataLoadingInfoSchedule::getDTI() const {
    return CDataLoadingInfoSchedule::DTI;
}

void* CDataLoadingInfoSchedule::operator new(size_t sz, u32 align) {
    return CDataLoadingInfoSchedule::getAllocator()->memAlloc(sz, align, CDataLoadingInfoSchedule::DTI.getID());
}

__attribute__((weak)) void CDataLoadingInfoSchedule::operator delete(void* p_addr) {
    CDataLoadingInfoSchedule::getAllocator()->memFree(p_addr);
}

inline CDataLoadingInfoSchedule::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataLoadingInfoSchedule::MyDTI CDataLoadingInfoSchedule::DTI("CDataLoadingInfoSchedule", &::CPacketDataBase::DTI, 40ul, 0u, 0u);

MtObject* CDataLoadingInfoSchedule::MyDTI::newInstance() const {
    return new (16u) CDataLoadingInfoSchedule;
}

const MtDTI& CDataLoadingInfoSchedules::getDTI() const {
    return CDataLoadingInfoSchedules::DTI;
}

__attribute__((weak)) void CDataLoadingInfoSchedules::operator delete(void* p_addr) {
    CDataLoadingInfoSchedules::getAllocator()->memFree(p_addr);
}

inline CDataLoadingInfoSchedules::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataLoadingInfoSchedules::MyDTI CDataLoadingInfoSchedules::DTI("CDataLoadingInfoSchedules", &::CPacketDataBase::DTI, 40ul, 0u, 0u);

MtObject* CDataLoadingInfoSchedules::MyDTI::newInstance() const {
    return new (16u) CDataLoadingInfoSchedules;
}

