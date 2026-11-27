// Reconstructed from the game's DWARF debug information.
#include <new>
#include "Message.h"
#include "Common.h"
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtCollection.h"
#include "../../../../MT/MtDTI.h"
#include "../../../../MT/MtObject.h"
#include "../../../../MT/MtString.h"
#include "../../cPacket.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& CDataErrorMessage::getDTI() const {
    return CDataErrorMessage::DTI;
}

void* CDataErrorMessage::operator new(size_t sz, u32 align) {
    return CDataErrorMessage::getAllocator()->memAlloc(sz, align, CDataErrorMessage::DTI.getID());
}

__attribute__((weak)) void CDataErrorMessage::operator delete(void* p_addr) {
    CDataErrorMessage::getAllocator()->memFree(p_addr);
}

inline CDataErrorMessage::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataErrorMessage::MyDTI CDataErrorMessage::DTI("CDataErrorMessage", &::CPacketDataBase::DTI, 32ul, 0u, 0u);

MtObject* CDataErrorMessage::MyDTI::newInstance() const {
    return new (16u) CDataErrorMessage;
}

const MtDTI& CDataNGWordInfo::getDTI() const {
    return CDataNGWordInfo::DTI;
}

void* CDataNGWordInfo::operator new(size_t sz, u32 align) {
    return CDataNGWordInfo::getAllocator()->memAlloc(sz, align, CDataNGWordInfo::DTI.getID());
}

__attribute__((weak)) void CDataNGWordInfo::operator delete(void* p_addr) {
    CDataNGWordInfo::getAllocator()->memFree(p_addr);
}

inline CDataNGWordInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataNGWordInfo::MyDTI CDataNGWordInfo::DTI("CDataNGWordInfo", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataNGWordInfo::MyDTI::newInstance() const {
    return new (16u) CDataNGWordInfo;
}

const MtDTI& CDataSameLetterInfo::getDTI() const {
    return CDataSameLetterInfo::DTI;
}

void* CDataSameLetterInfo::operator new(size_t sz, u32 align) {
    return CDataSameLetterInfo::getAllocator()->memAlloc(sz, align, CDataSameLetterInfo::DTI.getID());
}

__attribute__((weak)) void CDataSameLetterInfo::operator delete(void* p_addr) {
    CDataSameLetterInfo::getAllocator()->memFree(p_addr);
}

inline CDataSameLetterInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataSameLetterInfo::MyDTI CDataSameLetterInfo::DTI("CDataSameLetterInfo", &::CPacketDataBase::DTI, 40ul, 0u, 0u);

MtObject* CDataSameLetterInfo::MyDTI::newInstance() const {
    return new (16u) CDataSameLetterInfo;
}

