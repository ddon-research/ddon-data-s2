// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sResource.h"
#include "../MT/MtCRC.h"
#include "../MT/MtDTI.h"
#include "../MT/MtFile.h"
#include "../MT/MtFilePath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtStream.h"
#include "../MT/MtString.h"
#include "../MT/MtSynchronize.h"
#include "cResource.h"
#include "cSystem.h"
#include "rArchive.h"
#include "../ZLIB/1.2.8/zlib.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& sResource::getDTI() const {
    return sResource::DTI;
}

sResource::sResource(u32 ringbufsize) {
    DDON_STUB("sResource::sResource")
    /* stub */
}

__attribute__((noinline)) sResource::~sResource() {
    DDON_STUB("sResource::~sResource")
    /* stub */
}

void sResource::reset() {
    unsigned int i3 = 64;
    do {
        setup();
        i3 += 0xFFFFFFFFu;
    } while (i3 != 0);
}

__attribute__((weak)) void sResource::setup() {
}

__attribute__((weak)) void sResource::move() {
}

void sResource::createProperty(MtPropertyList& s) {
    this->cSystem::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mAutoUpdate", &mAutoUpdate, 256u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mOptimizeEnable", &mOptimizeEnable, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mForceHDDCache", &mForceHDDCache, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mForceBackGround", &mForceBackGround, 2u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "Build Archive", static_cast<MT_MFUNC>(&::sResource::buildArchive), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "mBuildComplete", &mBuildComplete, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRootDirectory", &mRootDirectory, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mResourceFolder", &mResourceFolder, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNativeFolder", &mNativeFolder, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mResourcePath", &mResourcePath, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mNativePath", &mNativePath, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRemoteConvert", &mRemoteConvert, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mTypeInfo", static_cast<MtObject*>(&mTypeInfo[0]), 35u, mTypeInfoNum);
    s << MtProperty(static_cast<MtObject*>(this), "mResourceNum", &mResourceNum, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRModelDataReaderBufferSizeKB", &mRModelDataReaderBufferSizeKB, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRTextureDataReaderBufferSizeKB", &mRTextureDataReaderBufferSizeKB, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRGrassDataReaderBufferSizeKB", &mRGrassDataReaderBufferSizeKB, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRCollisionDataReaderBufferSizeKB", &mRCollisionDataReaderBufferSizeKB, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRNavigationMeshDataReaderBufferSizeKB", &mRNavigationMeshDataReaderBufferSizeKB, 0u, 0u);
}

__attribute__((weak)) void sResource::buildArchive() {
    DDON_STUB("sResource::buildArchive")
    /* stub */
}

__attribute__((weak)) void sResource::terminateAsync() {
    DDON_STUB("sResource::terminateAsync")
    /* stub */
}

__attribute__((weak)) cResource* sResource::create(MT_CTSTR fullpath, const MtDTI* pbase, u32 mode) {
    DDON_STUB("sResource::create")
    return nullptr;
}

__attribute__((weak)) cResource* sResource::create(const MtDTI& dti, MT_CTSTR path, u32 mode) {
    DDON_STUB("sResource::create")
    return nullptr;
}

__attribute__((weak)) cResource* sResource::create(MtStream& in, const MtDTI& dti, MT_CTSTR path, cResource::QUALITY quality) {
    DDON_STUB("sResource::create")
    return nullptr;
}

__attribute__((weak)) cResource* sResource::create(u64 id) {
    DDON_STUB("sResource::create")
    return nullptr;
}

__attribute__((weak)) cResource* sResource::createNative(cResource* psrc, u32 mode) {
        if (psrc == nullptr || !(psrc->mAttr & 8)) {
            return nullptr;
        }
        const MtDTI* pdti = &psrc->getDTI();
        do {
            pdti = pdti->mpParent;
        } while (pdti != nullptr && (pdti->mAttr & 1));
        if (pdti != nullptr) {
            TypeInfo* pi = nullptr;
            for (u32 i = 0; i < mTypeInfoNum; i++) {
                if (mTypeInfo[i].mpDTI == pdti) {
                    pi = &mTypeInfo[i];
                    break;
                }
            }
            if (pi != nullptr && (pi->mAttr & 16)) {
                cResource* pdst = create(*pdti, psrc->mPath, mode);
                if (pdst != nullptr) {
                    return pdst;
                }
            }
        }
        return nullptr;
}

__attribute__((weak)) u64 sResource::makeID(const MtDTI& dti, MT_CTSTR path) {
    DDON_STUB("sResource::makeID")
    return {};
}

__attribute__((weak)) void sResource::setupDecode(MtStream& in) {
        mDecodeWork.pin = &in;
        mDecodeWork.parc = nullptr;
        memset(mDecodeWork.rwork, 0, sizeof(mDecodeWork.rwork));
        mDecodeWork.rcomplete = 0;
        mDecodeWork.cancel = 0;
        mDecodeWork.rnum = 0;
        mDecodeWork.rrequest = 0;
        mDecodeWork.readpt = 0;
        mDecodeWork.writept = 0;
}

__attribute__((weak)) cResource* sResource::entryDecode(MT_CTSTR path, const MtDTI& dti, u32 offset, u32 datasize, u32 orgsize, cResource::QUALITY quality) {
        RESOURCEWORK* prwk = &mDecodeWork.rwork[mDecodeWork.rnum++];
        prwk->presource = precreate(dti, path, orgsize, quality);
        prwk->datasize = datasize;
        prwk->offset = offset;
        prwk->readsize = 0;
        prwk->complete = 0;
        prwk->loaded = 0;
        prwk->orgsize = orgsize;
        return prwk->presource;
}

__attribute__((weak)) bool sResource::executeDecode(rArchive* parc) {
    DDON_STUB("sResource::executeDecode")
    return {};
}

__attribute__((weak)) void sResource::getFullPath(MT_STR dst, cResource* pr) {
        if (dst != nullptr) {
            if (pr != nullptr) {
                MT_CTSTR root;
                if (pr->mAttr & cResource::ATTR_NATIVE) {
                    root = mNativePath.value != nullptr ? reinterpret_cast<MT_CTSTR>(mNativePath.value->str) : "";
                } else {
                    root = mResourcePath.value != nullptr ? reinterpret_cast<MT_CTSTR>(mResourcePath.value->str) : "";
                }
                sprintf(dst, "%s\\%s.%s", root, pr->mPath, pr->getExt());
                if (mpPathFilter != nullptr) {
                    mpPathFilter(dst, mpPathFilterAdr);
                }
            } else {
                *dst = 0;
            }
        }
}

__attribute__((weak)) void sResource::getFullPath(MT_STR dst, const MtDTI& dti, MT_CTSTR path) {
        if (dst != nullptr && !(dti.mAttr & 1)) {
            TypeInfo* pi = nullptr;
            for (u32 i = 0; i < mTypeInfoNum; i++) {
                if (mTypeInfo[i].mpDTI == &dti) {
                    pi = &mTypeInfo[i];
                    break;
                }
            }
            if (pi != nullptr) {
                MT_CTSTR root;
                if (pi->mAttr & cResource::ATTR_NATIVE) {
                    root = mNativePath.value != nullptr ? reinterpret_cast<MT_CTSTR>(mNativePath.value->str) : "";
                } else {
                    root = mResourcePath.value != nullptr ? reinterpret_cast<MT_CTSTR>(mResourcePath.value->str) : "";
                }
                sprintf(dst, "%s\\%s.%s", root, path, pi->mExt);
                if (mpPathFilter != nullptr) {
                    mpPathFilter(dst, mpPathFilterAdr);
                }
            }
        }
}

__attribute__((weak)) void sResource::setRootDirectory(MT_CTSTR root_directory) {
    DDON_STUB("sResource::setRootDirectory")
    /* stub */
}

bool sResource::isLoading() {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        int t0 = scePthreadMutexLock(&mCS.mCSection);
        if (t0 != 0) {
            abort();
        }
        if (!mLoadingInfo.active) {
            u32 t1 = mLoadNum;
            if (mThreadSafe || (cSystem::mJobSafe)) {
                int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                if (t2 != 0) {
                    abort();
                }
                return t1 != 0;
            } else {
                return t1 != 0;
            }
        } else {
            if (mThreadSafe || (cSystem::mJobSafe)) {
                int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                if (t2 != 0) {
                    abort();
                }
                return true;
            } else {
                return true;
            }
        }
    } else {
        if (!mLoadingInfo.active) {
            u32 t1 = mLoadNum;
            if (mThreadSafe || (cSystem::mJobSafe)) {
                int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                if (t2 != 0) {
                    abort();
                }
                return t1 != 0;
            } else {
                return t1 != 0;
            }
        } else {
            if (mThreadSafe || (cSystem::mJobSafe)) {
                int t2 = scePthreadMutexUnlock(&mCS.mCSection);
                if (t2 != 0) {
                    abort();
                }
                return true;
            } else {
                return true;
            }
        }
    }
}

MtUI* sResource::createUI(MtProperty& prop) {
    return this->cSystem::createUI(prop);
}

__attribute__((weak)) cResource* sResource::loadBlocking(const MtDTI& dti, MT_CTSTR path, u64 id, u32 mode) {
    DDON_STUB("sResource::loadBlocking")
    return nullptr;
}

__attribute__((weak)) cResource* sResource::loadAsync(const MtDTI& dti, MT_CTSTR path, u64 id, u32 mode) {
    DDON_STUB("sResource::loadAsync")
    return nullptr;
}

__attribute__((weak)) cResource* sResource::findTable(u64 id, u32 shift) {
        cResource** ptbl = &mpTable[((id >> shift) & 0x7ff) * 8];
        for (s32 i = 0; i < 8; i++) {
            cResource* pr = ptbl[i];
            if (pr != nullptr && pr->mID == id) {
                return pr;
            }
        }
        if (shift < 16) {
            return findTable(id, shift + 1);
        }
        return nullptr;
}

__attribute__((weak)) void sResource::createTypeInfo(const MtDTI& dti) {
    DDON_STUB("sResource::createTypeInfo")
    /* stub */
}

__attribute__((weak)) void* sResource::loaderHandler(void* pArg) {
    DDON_STUB("sResource::loaderHandler")
    return nullptr;
}

void sResource::addRef(cResource* pr) {
    if (mThreadSafe || (cSystem::mJobSafe)) {
        if (scePthreadMutexLock(&mCS.mCSection) != 0) {
            abort();
        }
    }
    pr->mRefCount = pr->mRefCount + 1;
    if (!(mThreadSafe || (cSystem::mJobSafe))) {
        return;
    }
    if (scePthreadMutexUnlock(&mCS.mCSection) != 0) {
        abort();
    }
}

__attribute__((weak)) void sResource::release(cResource* pr) {
    DDON_STUB("sResource::release")
    /* stub */
}

__attribute__((weak)) cResource* sResource::precreate(const MtDTI& dti, MT_CTSTR path, u32 size, cResource::QUALITY quality) {
    DDON_STUB("sResource::precreate")
    return nullptr;
}

__attribute__((weak)) sResource::ResourceInfo* sResource::createResourceInfo(MT_CTSTR fullpath) {
    DDON_STUB("sResource::createResourceInfo")
    return nullptr;
}

const MtDTI* sResource::getResourceDTI(MT_CTSTR ext, bool isNative, const MtDTI* pbase) {
    u32 v0_9 = mTypeInfoNum;
    const MtDTI* v9_2;
    if (v0_9 == 0) {
        v9_2 = nullptr;
    } else {
        const MtDTI* pdti;
        if (!isNative) {
            const MtDTI* v5_4 = nullptr;
            unsigned int i5_8 = 0;
            const MtDTI* v6_0;
            const MtDTI* v8_4;
            for (;;) {
                u32 v6_3 = mTypeInfo[i5_8].mAttr;
                if ((mTypeInfo[i5_8].mAttr & 16u) != 0) {
                    v8_4 = v5_4;
                } else {
                    MT_CTSTR v6_2 = pbase->mName;
                    if (v6_2 == mTypeInfo[i5_8].mpDTI->mName) {
                        pdti = mTypeInfo[i5_8].mpDTI;
                    } else {
                        v6_0 = mTypeInfo[i5_8].mpDTI;
                        pdti = mTypeInfo[i5_8].mpDTI;
                        for (;;) {
                            if (v6_0->mpParent == nullptr) {
                                v8_4 = v5_4;
                                goto region_126d430;
                            } else {
                                if (v6_2 != v6_0->mpParent->mName) {
                                    v6_0 = v6_0->mpParent;
                                } else {
                                    break;
                                }
                            }
                        }
                    }
                    if (mTypeInfo[i5_8].mExt != nullptr) {
                        if (strcasecmp(mTypeInfo[i5_8].mExt, ext) != 0) {
                            v8_4 = v5_4;
                        } else {
                            if ((v6_3 & 32u) != 0) {
                                v8_4 = pdti;
                            } else {
                                v9_2 = pdti;
                                break;
                            }
                        }
                    } else {
                        v8_4 = v5_4;
                    }
                }
                region_126d430:;
                if ((i5_8 + 1u) < v0_9) {
                    v5_4 = v8_4;
                    i5_8 += 1u;
                } else {
                    v9_2 = v8_4;
                    break;
                }
            }
        } else {
            const MtDTI* v0_4 = nullptr;
            unsigned int i0_8 = 0;
            const MtDTI* v1_0;
            const MtDTI* v3_4;
            for (;;) {
                u32 v1_3 = mTypeInfo[i0_8].mAttr;
                if ((mTypeInfo[i0_8].mAttr & 16u) == 0) {
                    v3_4 = v0_4;
                } else {
                    pdti = mTypeInfo[i0_8].mpDTI;
                    MT_CTSTR v1_2 = pbase->mName;
                    if (v1_2 != pdti->mName) {
                        v1_0 = pdti;
                        for (;;) {
                            if (v1_0->mpParent == nullptr) {
                                v3_4 = v0_4;
                                goto region_126d390;
                            } else {
                                if (v1_2 != v1_0->mpParent->mName) {
                                    v1_0 = v1_0->mpParent;
                                } else {
                                    break;
                                }
                            }
                        }
                    }
                    if (mTypeInfo[i0_8].mExt != nullptr) {
                        if (strcasecmp(mTypeInfo[i0_8].mExt, ext) != 0) {
                            v3_4 = v0_4;
                        } else {
                            if ((v1_3 & 32u) != 0) {
                                v3_4 = pdti;
                            } else {
                                v9_2 = pdti;
                                return v9_2;
                            }
                        }
                    } else {
                        v3_4 = v0_4;
                    }
                }
                region_126d390:;
                if ((i0_8 + 1u) < v0_9) {
                    v0_4 = v3_4;
                    i0_8 += 1u;
                } else {
                    break;
                }
            }
            v9_2 = v3_4;
        }
    }
    return v9_2;
}

__attribute__((weak)) void sResource::buildFolder(MtString path, MtString* folder_list, s32& folder_num, MtString* archive_list, s32& archive_num) {
    DDON_STUB("sResource::buildFolder")
    /* stub */
}

__attribute__((weak)) void* sResource::decodeProc(void* context) {
    DDON_STUB("sResource::decodeProc")
    return nullptr;
}

inline sResource::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sResource::MyDTI sResource::DTI("sResource", &::cSystem::DTI, 0x4A1D0ul, 0u, 0u);

sResource* sResource::mpInstance;

__attribute__((weak)) MtObject* sResource::MyDTI::newInstance() const {
    DDON_STUB("sResource::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& sResource::TypeInfo::getDTI() const {
    return sResource::TypeInfo::DTI;
}

sResource::TypeInfo::~TypeInfo() {
}

MT_CTSTR sResource::TypeInfo::getName() const {
    return mpDTI->mName;
}

MT_CTSTR sResource::TypeInfo::getSuper() const {
    return mpDTI->mpParent->mName;
}

u32 sResource::TypeInfo::getSize() const {
    return ((*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(mpDTI) + 48)) * 4u) & 0x1FFFFFCu;
}

MtUI* sResource::TypeInfo::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void sResource::TypeInfo::createProperty(MtPropertyList& s) {
    DDON_STUB("sResource::TypeInfo::createProperty")
    /* stub */
}

__attribute__((weak)) void sResource::TypeInfo::setSize(u32) {
}

__attribute__((weak)) void sResource::TypeInfo::setName(MT_CTSTR) {
}

__attribute__((weak)) void sResource::TypeInfo::setSuper(MT_CTSTR) {
}

inline sResource::TypeInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sResource::TypeInfo::MyDTI sResource::TypeInfo::DTI("sResource::TypeInfo", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* sResource::TypeInfo::MyDTI::newInstance() const {
    return new (16u) sResource::TypeInfo;
}

MT_CTSTR sResource::Property::getName() {
    return "resource";
}

__attribute__((weak)) u32 sResource::Property::getParam(MtProperty* pp, MtProperty::Custom::PARAM* params) {
    cResource* pr = static_cast<cResource*>(pp->getClass());
    params[0].name = "rtype";
    params[1].name = "path";
    if (pr != nullptr) {
        params[0].value = pr->getDTI().mName;
        params[1].value = pr->mPath;
    } else {
        params[0].value = "null";
        params[1].value = "";
    }
    return 2u;
}

__attribute__((weak)) void sResource::Property::setParam(MtProperty* pp, const MtProperty::Custom::PARAM* params, u32 num) {
    const MtDTI* pdti = MtDTI::from(params[0].value, cResource::DTI);
    cResource* pr = nullptr;
    if (pdti != nullptr) {
        u32 t1 = sResource::MODE_BLOCKING | ((pp->getAttr() & MtProperty::ATTR_AUTO_CREATE) ? sResource::MODE_CREATE : 0);
        pr = sResource::getInstance()->create(*pdti, params[1].value, t1);
    }
    if (pp->isDynamic()) {
        pp->setClass(pr);
        if (pr != nullptr) {
            pr->release();
        }
    } else {
        cResource* ppr = static_cast<cResource*>(pp->getClass());
        if (ppr != nullptr) {
            ppr->release();
        }
        pp->setClass(pr);
    }
}

const MtDTI& sResource::RemoteInfo::getDTI() const {
    return sResource::RemoteInfo::DTI;
}

inline sResource::RemoteInfo::RemoteInfo() {
    mEnable = false;
    mConfigName[0] = 'r';
    mConfigName[1] = 'e';
    mConfigName[2] = 'm';
    mConfigName[3] = 'o';
    mConfigName[4] = 't';
    mConfigName[5] = 'e';
    mConfigName[6] = '.';
    mConfigName[7] = 'x';
    mConfigName[10] = '\0';
    mConfigName[8] = 'm';
    mConfigName[9] = 'l';
    mPCName[0] = 0;
    mFolderName[0] = 0;
    mConfigNameLen = static_cast<unsigned int>(strlen(&mConfigName[0]));
    mPCNameLen = 0;
    mFolderNameLen = 0;
}

void sResource::RemoteInfo::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mEnable", &mEnable, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CSTRING, "mPCName", reinterpret_cast<MT_MFUNC>(&::sResource::RemoteInfo::getPCName), reinterpret_cast<MT_MFUNC>(&::sResource::RemoteInfo::setPCName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CSTRING, "mFolderName", reinterpret_cast<MT_MFUNC>(&::sResource::RemoteInfo::getFolderName), reinterpret_cast<MT_MFUNC>(&::sResource::RemoteInfo::setFolderName), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

static auto ddon_emit_0x01ba6c20 __attribute__((used)) = &sResource::RemoteInfo::getPCName;

void sResource::RemoteInfo::setPCName(MT_CTSTR pc_name) {
    snprintf(&mPCName[0], 64ul, "%s", pc_name);
    mPCName[63] = '\0';
    mPCNameLen = static_cast<unsigned int>(strlen(&mPCName[0]));
}

static auto ddon_emit_0x01ba6c80 __attribute__((used)) = &sResource::RemoteInfo::getFolderName;

void sResource::RemoteInfo::setFolderName(MT_CTSTR folder_name) {
    snprintf(&mFolderName[0], 64ul, "%s", folder_name);
    mFolderName[63] = '\0';
    mFolderNameLen = static_cast<unsigned int>(strlen(&mFolderName[0]));
}

inline sResource::RemoteInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sResource::RemoteInfo::MyDTI sResource::RemoteInfo::DTI("sResource::RemoteInfo", &::MtObject::DTI, 216ul, 0u, 0u);

MtObject* sResource::RemoteInfo::MyDTI::newInstance() const {
    return new (16u) sResource::RemoteInfo;
}

const MtDTI& sResource::DecompressStream::getDTI() const {
    return sResource::DecompressStream::DTI;
}

sResource::DecompressStream::~DecompressStream() {
    DDON_STUB("sResource::DecompressStream::~DecompressStream")
    /* stub */
}

bool sResource::DecompressStream::isReadable() {
    return true;
}

__attribute__((weak)) u32 sResource::DecompressStream::read(void* pbuf, u32 bufsize) {
    DDON_STUB("sResource::DecompressStream::read")
    return {};
}

u32 sResource::DecompressStream::getPosition() {
    return mCurOut;
}

u32 sResource::DecompressStream::getLength() {
    return mpResourceWork->orgsize;
}

inline sResource::DecompressStream::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

sResource::DecompressStream::MyDTI sResource::DecompressStream::DTI("sResource::DecompressStream", &::MtStream::DTI, 144ul, 0u, 0u);

__attribute__((weak)) MtObject* sResource::DecompressStream::MyDTI::newInstance() const {
    DDON_STUB("sResource::DecompressStream::MyDTI::newInstance")
    return nullptr;
}

