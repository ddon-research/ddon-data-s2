// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "sHttpClient.h"
#include "../../MT/MtAllocator.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtJsonReader.h"
#include "../../MT/MtMemoryAllocator.h"
#include "../../MT/MtNetDevice.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtProperty.h"
#include "../../MT/MtPropertyList.h"
#include "../../MT/MtStream.h"
#include "../../MT/MtString.h"
#include "../../MT/MtSynchronize.h"
#include "../../XFramework/cHttpClient.h"
#include "../../XFramework/cResource.h"
#include "../../XFramework/cSystem.h"
#include "../../XFramework/sMain.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cGameHttpClient::getDTI() const {
    return cGameHttpClient::DTI;
}

__attribute__((noinline)) cGameHttpClient::~cGameHttpClient() {
    DDON_STUB("cGameHttpClient::~cGameHttpClient")
    /* stub */
}

__attribute__((weak)) void cGameHttpClient::createProperty(MtPropertyList& s) {
}

MtUI* cGameHttpClient::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void cGameHttpClient::init() {
    DDON_STUB("cGameHttpClient::init")
    /* stub */
}

void cGameHttpClient::abort() {
    mRno = 5;
}

__attribute__((weak)) void cGameHttpClient::sendReq() {
    DDON_STUB("cGameHttpClient::sendReq")
    /* stub */
}

__attribute__((weak)) void cGameHttpClient::separateURI(MT_CTSTR uri, MtString& urn, MtString& url) {
    DDON_STUB("cGameHttpClient::separateURI")
    /* stub */
}

__attribute__((weak)) void cGameHttpClient::openingServerFlow() {
    DDON_STUB("cGameHttpClient::openingServerFlow")
    /* stub */
}

__attribute__((weak)) void cGameHttpClient::setDownloadPic(MT_CTSTR addr, void* * ptr, u32* size) {
    DDON_STUB("cGameHttpClient::setDownloadPic")
    /* stub */
}

s32 cGameHttpClient::analyzeDownloadPic() {
    if (mStream.MtMemoryStream::getPosition() <= 1u) {
        if (mHandle <= 8u) {
            sHttpClient::getInstance()->mClientList[mHandle].mErrorCode = 268435506;
        }
        return 4;
    } else {
        *mpOutputSize = mStream.mLength;
        void* t0 = MtMemoryAllocator::getAllocator(cResource::DTI)->memAlloc(mStream.mLength, 16u);
        *mpOutputPtr = t0;
        if ((*mpOutputPtr) != nullptr) {
            memcpy(*mpOutputPtr, static_cast<const void*>(mStream.mBuffer), mStream.mLength);
        }
        return 2;
    }
}

inline cGameHttpClient::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGameHttpClient::MyDTI cGameHttpClient::DTI("cGameHttpClient", &::cHttpClient::DTI, 33232ul, 0u, 0u);

__attribute__((weak)) MtObject* cGameHttpClient::MyDTI::newInstance() const {
    DDON_STUB("cGameHttpClient::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cGameHttpClient::cLoginBackDoorInfo::getDTI() const {
    return cGameHttpClient::cLoginBackDoorInfo::DTI;
}

cGameHttpClient::cLoginBackDoorInfo::~cLoginBackDoorInfo() {
    DDON_STUB("cGameHttpClient::cLoginBackDoorInfo::~cLoginBackDoorInfo")
    /* stub */
}

inline cGameHttpClient::cLoginBackDoorInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGameHttpClient::cLoginBackDoorInfo::MyDTI cGameHttpClient::cLoginBackDoorInfo::DTI("cGameHttpClient::cLoginBackDoorInfo", &::MtObject::DTI, 40ul, 0u, 0u);

__attribute__((weak)) MtObject* cGameHttpClient::cLoginBackDoorInfo::MyDTI::newInstance() const {
    DDON_STUB("cGameHttpClient::cLoginBackDoorInfo::MyDTI::newInstance")
    return nullptr;
}

void cGameHttpClient::MyListener::onReceiveHeader(const cHttpClient::ResponseHeader* pHeader) {
    getOwner()->mStatusCode = static_cast<u32>(pHeader->mStatusCode);
    getOwner()->mContentLength = pHeader->mContentLength;
    (&getOwner()->mStream)->seek(0, MtStream::ORG_BEGIN);
    if (pHeader->mStatusCode > 399) {
        if (getOwner()->mHandle <= 8u) {
            (sHttpClient::mpInstance)->mClientList[getOwner()->mHandle].mErrorCode = pHeader->mStatusCode | 268435456;
        }
    }
}

__attribute__((weak)) void cGameHttpClient::MyListener::onReceiveData(void* pData, s32 cData) {
    DDON_STUB("cGameHttpClient::MyListener::onReceiveData")
    /* stub */
}

void cGameHttpClient::MyListener::onErrorEncounterd(s32 error) {
    if (error != -1) {
        if (error != 0) {
            if (getOwner()->mHandle <= 8u) {
                sHttpClient::getInstance()->mClientList[getOwner()->mHandle].mErrorCode = static_cast<s32>((error <= -1) ? static_cast<unsigned int>(error) : static_cast<unsigned int>(error | 268435456));
            }
        }
    } else {
        if (getOwner()->mHandle <= 8u) {
            sHttpClient::getInstance()->mClientList[getOwner()->mHandle].mErrorCode = 268435508;
        }
    }
}

const MtDTI& cGameHttpClient::cServerEnvironmentInfo::getDTI() const {
    return cGameHttpClient::cServerEnvironmentInfo::DTI;
}

cGameHttpClient::cServerEnvironmentInfo::~cServerEnvironmentInfo() {
}

inline cGameHttpClient::cServerEnvironmentInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGameHttpClient::cServerEnvironmentInfo::MyDTI cGameHttpClient::cServerEnvironmentInfo::DTI("cGameHttpClient::cServerEnvironmentInfo", &::MtObject::DTI, 40ul, 0u, 0u);

MtObject* cGameHttpClient::cServerEnvironmentInfo::MyDTI::newInstance() const {
    return new (16u) cGameHttpClient::cServerEnvironmentInfo;
}

const MtDTI& sHttpClient::getDTI() const {
    return sHttpClient::DTI;
}

void* sHttpClient::operator new(size_t sz, u32 align) {
    return sHttpClient::getAllocator()->memAlloc(sz, align, sHttpClient::DTI.getID());
}

sHttpClient::sHttpClient() {
    DDON_STUB("sHttpClient::sHttpClient")
    /* stub */
}

__attribute__((noinline)) sHttpClient::~sHttpClient() {
    DDON_STUB("sHttpClient::~sHttpClient")
    /* stub */
}

void sHttpClient::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mServerEnvironmentIndex", &mServerEnvironmentIndex, 0u, 0u);
}

MtUI* sHttpClient::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

__attribute__((weak)) void sHttpClient::reset() {
}

__attribute__((weak)) void sHttpClient::move() {
    DDON_STUB("sHttpClient::move")
    /* stub */
}

u32 sHttpClient::getConnectServerNo() {
    return 1;
}

__attribute__((weak)) u32 sHttpClient::reqDownloadPic(MT_CTSTR addr, void* * ptr, u32* size) {
    DDON_STUB("sHttpClient::reqDownloadPic")
    return {};
}

__attribute__((weak)) u32 sHttpClient::createClient() {
    DDON_STUB("sHttpClient::createClient")
    return {};
}

inline sHttpClient::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sHttpClient::MyDTI sHttpClient::DTI("sHttpClient", &::cSystem::DTI, 248ul, 0u, 0u);

sHttpClient* sHttpClient::mpInstance;

__attribute__((weak)) MtObject* sHttpClient::MyDTI::newInstance() const {
    DDON_STUB("sHttpClient::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<cGameHttpClient::cServerEnvironmentInfo>::~MtTypedArray();

