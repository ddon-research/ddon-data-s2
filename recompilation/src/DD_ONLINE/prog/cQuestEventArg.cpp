// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cQuestEventArg.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtObject.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cQuestEventArg::getDTI() const {
    return cQuestEventArg::DTI;
}

cQuestEventArg::cQuestEventArg() {
}

cQuestEventArg::~cQuestEventArg() {
}

inline cQuestEventArg::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestEventArg::MyDTI cQuestEventArg::DTI("cQuestEventArg", &::MtObject::DTI, 8ul, 0u, 0u);

MtObject* cQuestEventArg::MyDTI::newInstance() const {
    return new (16u) cQuestEventArg;
}

const MtDTI& cQuestEventArgEntryParty::getDTI() const {
    return cQuestEventArgEntryParty::DTI;
}

u32 cQuestEventArgEntryParty::getCharacterId() const {
    return mCharacterId;
}

bool cQuestEventArgEntryParty::isPawn() const {
    return mIsPawn;
}

cQuestEventArgEntryParty::cQuestEventArgEntryParty(u32 characterId, bool isPawn) {
    DDON_STUB("cQuestEventArgEntryParty::cQuestEventArgEntryParty")
    /* stub */
}

cQuestEventArgEntryParty::~cQuestEventArgEntryParty() {
}

inline cQuestEventArgEntryParty::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestEventArgEntryParty::MyDTI cQuestEventArgEntryParty::DTI("cQuestEventArgEntryParty", &::cQuestEventArg::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* cQuestEventArgEntryParty::MyDTI::newInstance() const {
    DDON_STUB("cQuestEventArgEntryParty::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cQuestEventArgLeaveParty::getDTI() const {
    return cQuestEventArgLeaveParty::DTI;
}

u32 cQuestEventArgLeaveParty::getCharacterId() const {
    return mCharacterId;
}

bool cQuestEventArgLeaveParty::isPawn() const {
    return mIsPawn;
}

cQuestEventArgLeaveParty::cQuestEventArgLeaveParty(u32 characterId, bool isPawn) {
    DDON_STUB("cQuestEventArgLeaveParty::cQuestEventArgLeaveParty")
    /* stub */
}

cQuestEventArgLeaveParty::~cQuestEventArgLeaveParty() {
}

inline cQuestEventArgLeaveParty::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cQuestEventArgLeaveParty::MyDTI cQuestEventArgLeaveParty::DTI("cQuestEventArgLeaveParty", &::cQuestEventArg::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* cQuestEventArgLeaveParty::MyDTI::newInstance() const {
    DDON_STUB("cQuestEventArgLeaveParty::MyDTI::newInstance")
    return nullptr;
}

