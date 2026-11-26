// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "nNetworkUtil.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtNetDevice.h"
#include "../MT/MtNetSession.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& nNetwork::SearchFilterListPtr::getDTI() const {
    return nNetwork::SearchFilterListPtr::DTI;
}

inline void nNetwork::SearchFilterListPtr::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nNetwork::SearchFilterListPtr::DTI)->memFree(p_addr);
}

void nNetwork::SearchFilterListPtr::createProperty(MtPropertyList& s) {
    if (mpList == nullptr) {
        return;
    }
    s << ::MtProperty(static_cast<MtObject*>(this), "Trace", static_cast<MT_MFUNC>(&::nNetwork::SearchFilterListPtr::trace), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "Attribute", &mpList->mAttribute, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "GameType", &mpList->mGameType, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "GameMode", &mpList->mGameMode, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "ProcIndex", &mpList->mProcedureIndex, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "NumUsers", &mpList->mNumUsers, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "Num", &mpList->mNum, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mList", static_cast<MtObject*>(&mList[0]), 32u, 8u);
}

MtUI* nNetwork::SearchFilterListPtr::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

__attribute__((weak)) void nNetwork::SearchFilterListPtr::init(MtNetSession::SearchKeyFilterList& list) {
    DDON_STUB("nNetwork::SearchFilterListPtr::init")
    /* stub */
}

__attribute__((weak)) void nNetwork::SearchFilterListPtr::trace() {
}

inline nNetwork::SearchFilterListPtr::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::SearchFilterListPtr::MyDTI nNetwork::SearchFilterListPtr::DTI("nNetwork::SearchFilterListPtr", &::MtObject::DTI, 272ul, 0u, 2u);

__attribute__((weak)) MtObject* nNetwork::SearchFilterListPtr::MyDTI::newInstance() const {
    DDON_STUB("nNetwork::SearchFilterListPtr::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nNetwork::SearchFilterPtr::getDTI() const {
    return nNetwork::SearchFilterPtr::DTI;
}

inline void nNetwork::SearchFilterPtr::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nNetwork::SearchFilterPtr::DTI)->memFree(p_addr);
}

__attribute__((weak)) void nNetwork::SearchFilterPtr::createProperty(MtPropertyList& s) {
    DDON_STUB("nNetwork::SearchFilterPtr::createProperty")
    /* stub */
}

inline nNetwork::SearchFilterPtr::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::SearchFilterPtr::MyDTI nNetwork::SearchFilterPtr::DTI("nNetwork::SearchFilterPtr", &::MtObject::DTI, 32ul, 0u, 2u);

__attribute__((weak)) MtObject* nNetwork::SearchFilterPtr::MyDTI::newInstance() const {
    DDON_STUB("nNetwork::SearchFilterPtr::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nNetwork::SearchKeyListPtr::getDTI() const {
    return nNetwork::SearchKeyListPtr::DTI;
}

inline void nNetwork::SearchKeyListPtr::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nNetwork::SearchKeyListPtr::DTI)->memFree(p_addr);
}

void nNetwork::SearchKeyListPtr::createProperty(MtPropertyList& s) {
    if (mpSearchKeyList == nullptr) {
        return;
    }
    s << ::MtProperty(static_cast<MtObject*>(this), "Trace", static_cast<MT_MFUNC>(&::nNetwork::SearchKeyListPtr::trace), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "Attribute", &mpSearchKeyList->mAttribute, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "GameType", &mpSearchKeyList->mGameType, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "GameMode", &mpSearchKeyList->mGameMode, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "Num", &mpSearchKeyList->mNum, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mList", static_cast<MtObject*>(&mList[0]), 32u, 8u);
}

MtUI* nNetwork::SearchKeyListPtr::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

__attribute__((weak)) void nNetwork::SearchKeyListPtr::init(MtNetSessionInfo::SearchKeyList& list) {
    DDON_STUB("nNetwork::SearchKeyListPtr::init")
    /* stub */
}

__attribute__((weak)) void nNetwork::SearchKeyListPtr::trace() {
}

inline nNetwork::SearchKeyListPtr::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::SearchKeyListPtr::MyDTI nNetwork::SearchKeyListPtr::DTI("nNetwork::SearchKeyListPtr", &::MtObject::DTI, 144ul, 0u, 2u);

__attribute__((weak)) MtObject* nNetwork::SearchKeyListPtr::MyDTI::newInstance() const {
    DDON_STUB("nNetwork::SearchKeyListPtr::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nNetwork::SearchKeyPtr::getDTI() const {
    return nNetwork::SearchKeyPtr::DTI;
}

inline void nNetwork::SearchKeyPtr::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nNetwork::SearchKeyPtr::DTI)->memFree(p_addr);
}

void nNetwork::SearchKeyPtr::createProperty(MtPropertyList& s) {
    if (mpKey == nullptr) {
        return;
    }
    s << ::MtProperty(static_cast<MtObject*>(this), "Type", &mpKey->mType, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "Value", &mpKey->mInt32, 0u, 0u);
}

inline nNetwork::SearchKeyPtr::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nNetwork::SearchKeyPtr::MyDTI nNetwork::SearchKeyPtr::DTI("nNetwork::SearchKeyPtr", &::MtObject::DTI, 16ul, 0u, 2u);

__attribute__((weak)) MtObject* nNetwork::SearchKeyPtr::MyDTI::newInstance() const {
    DDON_STUB("nNetwork::SearchKeyPtr::MyDTI::newInstance")
    return nullptr;
}

__attribute__((weak)) void nNetwork::SearchResultListPtr::createProperty(MtPropertyList& s) {
    DDON_STUB("nNetwork::SearchResultListPtr::createProperty")
    /* stub */
}

MtUI* nNetwork::SearchResultListPtr::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

__attribute__((weak)) u32 nNetwork::SearchResultListPtr::getNum() const {
    DDON_STUB("nNetwork::SearchResultListPtr::getNum")
    return {};
}

__attribute__((weak)) void nNetwork::SearchResultListPtr::setNum(u32 num) {
    DDON_STUB("nNetwork::SearchResultListPtr::setNum")
    /* stub */
}

nNetwork::SearchResultPtr* nNetwork::SearchResultListPtr::getSearchResultPtr(u32 index) {
    return &mResult[index];
}

void nNetwork::SearchResultListPtr::setSearchResultPtr(nNetwork::SearchResultPtr* pptr, u32 index) {
    mResult[index].mpSearchResult = pptr->mpSearchResult;
    mResult[index].mInfo.mpSessionInfo = pptr->mInfo.mpSessionInfo;
    mResult[index].mInfo.mList.mpSearchKeyList = pptr->mInfo.mList.mpSearchKeyList;
    mResult[index].mInfo.mList.mList[0].mpKey = pptr->mInfo.mList.mList[0].mpKey;
    mResult[index].mInfo.mList.mList[1].mpKey = pptr->mInfo.mList.mList[1].mpKey;
    mResult[index].mInfo.mList.mList[2].mpKey = pptr->mInfo.mList.mList[2].mpKey;
    mResult[index].mInfo.mList.mList[3].mpKey = pptr->mInfo.mList.mList[3].mpKey;
    mResult[index].mInfo.mList.mList[4].mpKey = pptr->mInfo.mList.mList[4].mpKey;
    mResult[index].mInfo.mList.mList[5].mpKey = pptr->mInfo.mList.mList[5].mpKey;
    mResult[index].mInfo.mList.mList[6].mpKey = pptr->mInfo.mList.mList[6].mpKey;
    mResult[index].mInfo.mList.mList[7].mpKey = pptr->mInfo.mList.mList[7].mpKey;
    mResult[index].mInfo.mBinary.mpBinary = pptr->mInfo.mBinary.mpBinary;
    MT_CTSTR t0 = pptr->mName;
    mResult[index].mPing.mRtt = pptr->mPing.mRtt;
    mResult[index].mName = t0;
}

__attribute__((weak)) void nNetwork::SearchResultListPtr::init(MtNetSession::SearchResultList& list) {
    DDON_STUB("nNetwork::SearchResultListPtr::init")
    /* stub */
}

void nNetwork::SearchResultPtr::setBinary(MtNetSessionInfo::Binary* binary) {
    ::memset(static_cast<void*>(&mpSearchResult->mSessionInfo.mBinary.mBuffer[0]), 0, 260ul);
    if (binary == nullptr) {
        return;
    }
    mpSearchResult->mSessionInfo.mBinary.mDataLength = binary->mDataLength;
    ::memcpy(static_cast<void*>(&mpSearchResult->mSessionInfo.mBinary.mBuffer[0]), static_cast<const void*>(binary), binary->mDataLength);
}

__attribute__((weak)) void nNetwork::SearchResultPtr::createProperty(MtPropertyList& s) {
    DDON_STUB("nNetwork::SearchResultPtr::createProperty")
    /* stub */
}

MtUI* nNetwork::SearchResultPtr::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nNetwork::SessionBinaryPtr::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "mpBinary->mBuffer", &mpBinary->mBuffer[0], 32u, 256u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpBinary->mDataLength", &mpBinary->mDataLength, 0u, 0u);
}

MtUI* nNetwork::SessionBinaryPtr::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void nNetwork::SessionInfoPtr::createProperty(MtPropertyList& s) {
    if (mpSessionInfo == nullptr) {
        return;
    }
    s << ::MtProperty(static_cast<MtObject*>(this), "SEARCH KEY LIST", static_cast<MtObject*>(&mList), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "NONCE", &mpSessionInfo->mGeneral.mNonce, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "IP", &mpSessionInfo->mGeneral.mAddress.mIpAddress.mData[0], 32u, 4u);
    s << ::MtProperty(static_cast<MtObject*>(this), "PORT", &mpSessionInfo->mGeneral.mAddress.mPort.mData, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mBinary", static_cast<MtObject*>(&mBinary), 0u, 0u);
}

MtUI* nNetwork::SessionInfoPtr::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

__attribute__((weak)) void nNetwork::SessionInfoPtr::init(MtNetSessionInfo& info) {
    DDON_STUB("nNetwork::SessionInfoPtr::init")
    /* stub */
}

