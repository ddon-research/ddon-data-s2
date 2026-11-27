// Reconstructed from the game's DWARF debug information.
#include <new>
#include "sIME.h"
#include "../../MT/MtDTI.h"
#include "../../XFramework/cSystem.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

nIME::CandidateDispInfo::CandidateDispInfo() {
    mListNum = 0;
    mListSelectIndex = 0;
}

nIME::CandidateDispInfo::~CandidateDispInfo() {
}

void nIME::CandidateDispInfo::clear() {
    mListNum = 0;
    mListSelectIndex = 0;
}

__attribute__((weak)) u32 nIME::CandidateDispInfo::getDispStartIndex() const {
    DDON_STUB("nIME::CandidateDispInfo::getDispStartIndex")
    return {};
}

__attribute__((weak)) u32 nIME::CandidateDispInfo::getDispNum() const {
    DDON_STUB("nIME::CandidateDispInfo::getDispNum")
    return {};
}

void nIME::InputEvent::clear() {
    mId = ::nIME::INPUT_EVENT_ID_NONE;
    mFlags = 0;
}

nIME::InputInfo::InputInfo() {
}

nIME::InputInfo::~InputInfo() {
}

const MtDTI& sIME::getDTI() const {
    return sIME::DTI;
}

sIME::sIME() {
    DDON_STUB("sIME::sIME")
    /* stub */
}

sIME::~sIME() {
    sIME::mpInstance = nullptr;
}

void sIME::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
}

MtUI* sIME::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

__attribute__((weak)) void sIME::move() {
}

bool sIME::start(MT_CWSTR initialString, cInputTextKeyboardHook* keyboardHook) {
    mInputEvent.mId = nIME::INPUT_EVENT_ID_NONE;
    mInputEvent.mFlags = 0;
    mActive = true;
    mKeyboardHook = keyboardHook;
    return true;
}

void sIME::end() {
    mKeyboardHook = nullptr;
    mActive = false;
}

bool sIME::confirm() {
    return true;
}

bool sIME::cancel() {
    return true;
}

MT_CWSTR sIME::getInputString() const {
    return nullptr;
}

MT_CWSTR sIME::getConfirmString() const {
    return nullptr;
}

__attribute__((weak)) void sIME::clearConfirmString() {
}

inline sIME::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sIME::MyDTI sIME::DTI("sIME", &::cSystem::DTI, 40ul, 0u, 1u);

sIME* sIME::mpInstance;

MtObject* sIME::MyDTI::newInstance() const {
    return nullptr;
}

