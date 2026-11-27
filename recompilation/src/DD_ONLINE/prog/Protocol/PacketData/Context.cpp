// Reconstructed from the game's DWARF debug information.
#include <new>
#include "Context.h"
#include "CharacterCommon.h"
#include "CharacterEdit.h"
#include "Common.h"
#include "../../../../MT/MtAllocator.h"
#include "../../../../MT/MtCollection.h"
#include "../../../../MT/MtDTI.h"
#include "../../../../MT/MtMemoryAllocator.h"
#include "../../../../MT/MtObject.h"
#include "../../../../MT/MtString.h"
#include "Pawn.h"
#include "../../cPacket.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& CDataAllContextPlayer::getDTI() const {
    return CDataAllContextPlayer::DTI;
}

__attribute__((weak)) void CDataAllContextPlayer::operator delete(void* p_addr) {
    CDataAllContextPlayer::getAllocator()->memFree(p_addr);
}

CDataAllContextPlayer::CDataAllContextPlayer() {
    DDON_STUB("CDataAllContextPlayer::CDataAllContextPlayer")
    /* stub */
}

inline CDataAllContextPlayer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataAllContextPlayer::MyDTI CDataAllContextPlayer::DTI("CDataAllContextPlayer", &::CPacketDataBase::DTI, 840ul, 0u, 0u);

__attribute__((weak)) MtObject* CDataAllContextPlayer::MyDTI::newInstance() const {
    DDON_STUB("CDataAllContextPlayer::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& CDataContextBase::getDTI() const {
    return CDataContextBase::DTI;
}

__attribute__((weak)) void CDataContextBase::operator delete(void* p_addr) {
    CDataContextBase::getAllocator()->memFree(p_addr);
}

inline CDataContextBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataContextBase::MyDTI CDataContextBase::DTI("CDataContextBase", &::CPacketDataBase::DTI, 296ul, 0u, 0u);

__attribute__((weak)) MtObject* CDataContextBase::MyDTI::newInstance() const {
    DDON_STUB("CDataContextBase::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& CDataContextCrestData::getDTI() const {
    return CDataContextCrestData::DTI;
}

void* CDataContextCrestData::operator new(size_t sz, u32 align) {
    return CDataContextCrestData::getAllocator()->memAlloc(sz, align, CDataContextCrestData::DTI.getID());
}

__attribute__((weak)) void CDataContextCrestData::operator delete(void* p_addr) {
    CDataContextCrestData::getAllocator()->memFree(p_addr);
}

inline CDataContextCrestData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataContextCrestData::MyDTI CDataContextCrestData::DTI("CDataContextCrestData", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataContextCrestData::MyDTI::newInstance() const {
    return new (16u) CDataContextCrestData;
}

const MtDTI& CDataContextEquipData::getDTI() const {
    return CDataContextEquipData::DTI;
}

void* CDataContextEquipData::operator new(size_t sz, u32 align) {
    return CDataContextEquipData::getAllocator()->memAlloc(sz, align, CDataContextEquipData::DTI.getID());
}

__attribute__((weak)) void CDataContextEquipData::operator delete(void* p_addr) {
    CDataContextEquipData::getAllocator()->memFree(p_addr);
}

inline CDataContextEquipData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataContextEquipData::MyDTI CDataContextEquipData::DTI("CDataContextEquipData", &::CPacketDataBase::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* CDataContextEquipData::MyDTI::newInstance() const {
    DDON_STUB("CDataContextEquipData::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& CDataContextEquipJobItemData::getDTI() const {
    return CDataContextEquipJobItemData::DTI;
}

void* CDataContextEquipJobItemData::operator new(size_t sz, u32 align) {
    return CDataContextEquipJobItemData::getAllocator()->memAlloc(sz, align, CDataContextEquipJobItemData::DTI.getID());
}

__attribute__((weak)) void CDataContextEquipJobItemData::operator delete(void* p_addr) {
    CDataContextEquipJobItemData::getAllocator()->memFree(p_addr);
}

inline CDataContextEquipJobItemData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataContextEquipJobItemData::MyDTI CDataContextEquipJobItemData::DTI("CDataContextEquipJobItemData", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataContextEquipJobItemData::MyDTI::newInstance() const {
    return new (16u) CDataContextEquipJobItemData;
}

const MtDTI& CDataContextJobData::getDTI() const {
    return CDataContextJobData::DTI;
}

void* CDataContextJobData::operator new(size_t sz, u32 align) {
    return CDataContextJobData::getAllocator()->memAlloc(sz, align, CDataContextJobData::DTI.getID());
}

__attribute__((weak)) void CDataContextJobData::operator delete(void* p_addr) {
    CDataContextJobData::getAllocator()->memFree(p_addr);
}

inline CDataContextJobData::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataContextJobData::MyDTI CDataContextJobData::DTI("CDataContextJobData", &::CPacketDataBase::DTI, 32ul, 0u, 0u);

MtObject* CDataContextJobData::MyDTI::newInstance() const {
    return new (16u) CDataContextJobData;
}

const MtDTI& CDataContextPawnInfo::getDTI() const {
    return CDataContextPawnInfo::DTI;
}

__attribute__((weak)) void CDataContextPawnInfo::operator delete(void* p_addr) {
    CDataContextPawnInfo::getAllocator()->memFree(p_addr);
}

inline CDataContextPawnInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataContextPawnInfo::MyDTI CDataContextPawnInfo::DTI("CDataContextPawnInfo", &::CPacketDataBase::DTI, 40ul, 0u, 0u);

MtObject* CDataContextPawnInfo::MyDTI::newInstance() const {
    return new (16u) CDataContextPawnInfo;
}

const MtDTI& CDataContextPlayerInfo::getDTI() const {
    return CDataContextPlayerInfo::DTI;
}

__attribute__((weak)) void CDataContextPlayerInfo::operator delete(void* p_addr) {
    CDataContextPlayerInfo::getAllocator()->memFree(p_addr);
}

inline CDataContextPlayerInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataContextPlayerInfo::MyDTI CDataContextPlayerInfo::DTI("CDataContextPlayerInfo", &::CPacketDataBase::DTI, 360ul, 0u, 0u);

__attribute__((weak)) MtObject* CDataContextPlayerInfo::MyDTI::newInstance() const {
    DDON_STUB("CDataContextPlayerInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& CDataContextResist::getDTI() const {
    return CDataContextResist::DTI;
}

__attribute__((weak)) void CDataContextResist::operator delete(void* p_addr) {
    CDataContextResist::getAllocator()->memFree(p_addr);
}

inline CDataContextResist::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataContextResist::MyDTI CDataContextResist::DTI("CDataContextResist", &::CPacketDataBase::DTI, 40ul, 0u, 0u);

MtObject* CDataContextResist::MyDTI::newInstance() const {
    return new (16u) CDataContextResist;
}

const MtDTI& CDataContextSetAdditional::getDTI() const {
    return CDataContextSetAdditional::DTI;
}

__attribute__((weak)) void CDataContextSetAdditional::operator delete(void* p_addr) {
    CDataContextSetAdditional::getAllocator()->memFree(p_addr);
}

inline CDataContextSetAdditional::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataContextSetAdditional::MyDTI CDataContextSetAdditional::DTI("CDataContextSetAdditional", &::CPacketDataBase::DTI, 752ul, 0u, 0u);

__attribute__((weak)) MtObject* CDataContextSetAdditional::MyDTI::newInstance() const {
    DDON_STUB("CDataContextSetAdditional::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& CDataContextSetBase::getDTI() const {
    return CDataContextSetBase::DTI;
}

__attribute__((weak)) void CDataContextSetBase::operator delete(void* p_addr) {
    CDataContextSetBase::getAllocator()->memFree(p_addr);
}

inline CDataContextSetBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataContextSetBase::MyDTI CDataContextSetBase::DTI("CDataContextSetBase", &::CPacketDataBase::DTI, 32ul, 0u, 0u);

MtObject* CDataContextSetBase::MyDTI::newInstance() const {
    return new (16u) CDataContextSetBase;
}

const MtDTI& CDataContextSetInfo::getDTI() const {
    return CDataContextSetInfo::DTI;
}

__attribute__((weak)) void CDataContextSetInfo::operator delete(void* p_addr) {
    CDataContextSetInfo::getAllocator()->memFree(p_addr);
}

inline CDataContextSetInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataContextSetInfo::MyDTI CDataContextSetInfo::DTI("CDataContextSetInfo", &::CPacketDataBase::DTI, 792ul, 0u, 0u);

__attribute__((weak)) MtObject* CDataContextSetInfo::MyDTI::newInstance() const {
    DDON_STUB("CDataContextSetInfo::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& CDataLobbyContextPlayer::getDTI() const {
    return CDataLobbyContextPlayer::DTI;
}

__attribute__((weak)) void CDataLobbyContextPlayer::operator delete(void* p_addr) {
    CDataLobbyContextPlayer::getAllocator()->memFree(p_addr);
}

inline CDataLobbyContextPlayer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataLobbyContextPlayer::MyDTI CDataLobbyContextPlayer::DTI("CDataLobbyContextPlayer", &::CPacketDataBase::DTI, 800ul, 0u, 0u);

__attribute__((weak)) MtObject* CDataLobbyContextPlayer::MyDTI::newInstance() const {
    DDON_STUB("CDataLobbyContextPlayer::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& CDataNetPos::getDTI() const {
    return CDataNetPos::DTI;
}

__attribute__((weak)) void CDataNetPos::operator delete(void* p_addr) {
    CDataNetPos::getAllocator()->memFree(p_addr);
}

inline CDataNetPos::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataNetPos::MyDTI CDataNetPos::DTI("CDataNetPos", &::CPacketDataBase::DTI, 32ul, 0u, 0u);

MtObject* CDataNetPos::MyDTI::newInstance() const {
    return new (16u) CDataNetPos;
}

const MtDTI& CDataOcdActive::getDTI() const {
    return CDataOcdActive::DTI;
}

void* CDataOcdActive::operator new(size_t sz, u32 align) {
    return CDataOcdActive::getAllocator()->memAlloc(sz, align, CDataOcdActive::DTI.getID());
}

__attribute__((weak)) void CDataOcdActive::operator delete(void* p_addr) {
    CDataOcdActive::getAllocator()->memFree(p_addr);
}

inline CDataOcdActive::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataOcdActive::MyDTI CDataOcdActive::DTI("CDataOcdActive", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataOcdActive::MyDTI::newInstance() const {
    return new (16u) CDataOcdActive;
}

const MtDTI& CDataOcdImmuneLv::getDTI() const {
    return CDataOcdImmuneLv::DTI;
}

void* CDataOcdImmuneLv::operator new(size_t sz, u32 align) {
    return CDataOcdImmuneLv::getAllocator()->memAlloc(sz, align, CDataOcdImmuneLv::DTI.getID());
}

__attribute__((weak)) void CDataOcdImmuneLv::operator delete(void* p_addr) {
    CDataOcdImmuneLv::getAllocator()->memFree(p_addr);
}

inline CDataOcdImmuneLv::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataOcdImmuneLv::MyDTI CDataOcdImmuneLv::DTI("CDataOcdImmuneLv", &::CPacketDataBase::DTI, 16ul, 0u, 0u);

MtObject* CDataOcdImmuneLv::MyDTI::newInstance() const {
    return new (16u) CDataOcdImmuneLv;
}

const MtDTI& CDataPartyContextPawn::getDTI() const {
    return CDataPartyContextPawn::DTI;
}

__attribute__((weak)) void CDataPartyContextPawn::operator delete(void* p_addr) {
    CDataPartyContextPawn::getAllocator()->memFree(p_addr);
}

CDataPartyContextPawn::CDataPartyContextPawn() {
    DDON_STUB("CDataPartyContextPawn::CDataPartyContextPawn")
    /* stub */
}

inline CDataPartyContextPawn::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataPartyContextPawn::MyDTI CDataPartyContextPawn::DTI("CDataPartyContextPawn", &::CPacketDataBase::DTI, 880ul, 0u, 0u);

__attribute__((weak)) MtObject* CDataPartyContextPawn::MyDTI::newInstance() const {
    DDON_STUB("CDataPartyContextPawn::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& CDataPartyContextPlayer::getDTI() const {
    return CDataPartyContextPlayer::DTI;
}

__attribute__((weak)) void CDataPartyContextPlayer::operator delete(void* p_addr) {
    CDataPartyContextPlayer::getAllocator()->memFree(p_addr);
}

CDataPartyContextPlayer::CDataPartyContextPlayer() {
    DDON_STUB("CDataPartyContextPlayer::CDataPartyContextPlayer")
    /* stub */
}

inline CDataPartyContextPlayer::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataPartyContextPlayer::MyDTI CDataPartyContextPlayer::DTI("CDataPartyContextPlayer", &::CPacketDataBase::DTI, 840ul, 0u, 0u);

__attribute__((weak)) MtObject* CDataPartyContextPlayer::MyDTI::newInstance() const {
    DDON_STUB("CDataPartyContextPlayer::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& CDataVector3::getDTI() const {
    return CDataVector3::DTI;
}

__attribute__((weak)) void CDataVector3::operator delete(void* p_addr) {
    CDataVector3::getAllocator()->memFree(p_addr);
}

inline CDataVector3::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

CDataVector3::MyDTI CDataVector3::DTI("CDataVector3", &::CPacketDataBase::DTI, 24ul, 0u, 0u);

MtObject* CDataVector3::MyDTI::newInstance() const {
    return new (16u) CDataVector3;
}

