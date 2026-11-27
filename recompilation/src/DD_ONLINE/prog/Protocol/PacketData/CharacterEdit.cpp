// Reconstructed from the game's DWARF debug information.
#include <new>
#include "CharacterEdit.h"
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtDTI.h"
#include "../../../../MT/MtObject.h"
#include "../../cPacket.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& CDataEditInfo::getDTI() const {
    return CDataEditInfo::DTI;
}

__attribute__((weak)) void CDataEditInfo::operator delete(void* p_addr) {
    CDataEditInfo::getAllocator()->memFree(p_addr);
}

inline CDataEditInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataEditInfo::MyDTI CDataEditInfo::DTI("CDataEditInfo", &::CPacketDataBase::DTI, 136ul, 0u, 0u);

MtObject* CDataEditInfo::MyDTI::newInstance() const {
    return new (16u) CDataEditInfo;
}

const MtDTI& CDataEditParam::getDTI() const {
    return CDataEditParam::DTI;
}

void* CDataEditParam::operator new(size_t sz, u32 align) {
    return CDataEditParam::getAllocator()->memAlloc(sz, align, CDataEditParam::DTI.getID());
}

__attribute__((weak)) void CDataEditParam::operator delete(void* p_addr) {
    CDataEditParam::getAllocator()->memFree(p_addr);
}

inline CDataEditParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataEditParam::MyDTI CDataEditParam::DTI("CDataEditParam", &::CPacketDataBase::DTI, 32ul, 0u, 0u);

MtObject* CDataEditParam::MyDTI::newInstance() const {
    return new (16u) CDataEditParam;
}

const MtDTI& CDataEditParamPalette::getDTI() const {
    return CDataEditParamPalette::DTI;
}

__attribute__((weak)) void CDataEditParamPalette::operator delete(void* p_addr) {
    CDataEditParamPalette::getAllocator()->memFree(p_addr);
}

inline CDataEditParamPalette::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataEditParamPalette::MyDTI CDataEditParamPalette::DTI("CDataEditParamPalette", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataEditParamPalette::MyDTI::newInstance() const {
    return new (16u) CDataEditParamPalette;
}

const MtDTI& CDataUnlockEditParam::getDTI() const {
    return CDataUnlockEditParam::DTI;
}

void* CDataUnlockEditParam::operator new(size_t sz, u32 align) {
    return CDataUnlockEditParam::getAllocator()->memAlloc(sz, align, CDataUnlockEditParam::DTI.getID());
}

__attribute__((weak)) void CDataUnlockEditParam::operator delete(void* p_addr) {
    CDataUnlockEditParam::getAllocator()->memFree(p_addr);
}

inline CDataUnlockEditParam::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataUnlockEditParam::MyDTI CDataUnlockEditParam::DTI("CDataUnlockEditParam", &::CPacketDataBase::DTI, 32ul, 0u, 0u);

MtObject* CDataUnlockEditParam::MyDTI::newInstance() const {
    return new (16u) CDataUnlockEditParam;
}

