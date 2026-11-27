// Reconstructed from the game's DWARF debug information.
#include <new>
#include <_fs.h>
#include <string.h>
#include "MtFile.h"
#include "MtAllocator.h"
#include "MtDTI.h"
#include "MtFilePath.h"
#include "MtMemory.h"
#include "MtMemoryAllocator.h"
#include "MtObject.h"
#include "MtPropertyList.h"
#include "MtString.h"
#include "MtSynchronize.h"
#include "MtTime.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& MtFile::getDTI() const {
    return MtFile::DTI;
}

void* MtFile::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(MtFile::DTI)->memAlloc(sz, align, MtFile::DTI.mID);
}

void* MtFile::operator new[](size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(MtFile::DTI)->memAlloc(sz, align, MtFile::DTI.mID);
}

void MtFile::operator delete[](void* p_addr) {
    MtMemoryAllocator::getAllocator(MtFile::DTI)->memFree(p_addr);
}

__attribute__((weak)) bool MtFile::findFile(MtFile::FileInfo& info, MT_CTSTR start) {
    DDON_STUB("MtFile::findFile")
    return {};
}

__attribute__((weak)) bool MtFile::createDirectory(MT_CTSTR path) {
    DDON_STUB("MtFile::createDirectory")
    return {};
}

__attribute__((weak)) bool MtFile::createDirectoryEx(MT_CTSTR dpath) {
    DDON_STUB("MtFile::createDirectoryEx")
    return {};
}

__attribute__((weak)) bool MtFile::removeDirectory(MT_CTSTR path) {
    DDON_STUB("MtFile::removeDirectory")
    return {};
}

__attribute__((weak)) bool MtFile::removeDirectoryEx(MT_CTSTR path) {
    DDON_STUB("MtFile::removeDirectoryEx")
    return {};
}

__attribute__((weak)) bool MtFile::move(MT_CTSTR srcpath, MT_CTSTR dstpath) {
    DDON_STUB("MtFile::move")
    return {};
}

__attribute__((weak)) bool MtFile::copy(MT_CTSTR src, MT_CTSTR dst) {
    DDON_STUB("MtFile::copy")
    return {};
}

__attribute__((weak)) bool MtFile::remove(MT_CTSTR path) {
    DDON_STUB("MtFile::remove")
    return {};
}

__attribute__((weak)) bool MtFile::isExist(MT_CTSTR path) {
    DDON_STUB("MtFile::isExist")
    return {};
}

MT_CTSTR MtFile::getCurrentPath() {
    return MtFile::mCurrentPath;
}

void MtFile::setCurrentPath(MT_CTSTR path) {
    strcpy(MtFile::mCurrentPath, path);
}

void MtFile::setCachePath(MT_CTSTR path) {
    strcpy(MtFile::mCachePath, path);
}

MtFile::MtFile(MT_CTSTR path, MtFile::MODE mode) {
    mHandle = -1;
    mMode = MODE_UNDEFINED;
    mPath[0] = 0;
    mSeekPt = 0;
    mSize = 0;
    mDLCHandle = 0xFFFFFFFF;
    mAsyncExec = false;
    if (path != nullptr) {
        this->MtFile::open(path, mode, false);
    }
    mLastErrorCode = 0;
}

MtFile::~MtFile() {
    DDON_STUB("MtFile::~MtFile")
    /* stub */
}

__attribute__((weak)) bool MtFile::open(MT_CTSTR path, MtFile::MODE mode, bool interrupt) {
    DDON_STUB("MtFile::open")
    return {};
}

__attribute__((weak)) void MtFile::close() {
    DDON_STUB("MtFile::close")
    /* stub */
}

__attribute__((weak)) u32 MtFile::read(void* out, u32 bytes) {
    DDON_STUB("MtFile::read")
    return {};
}

__attribute__((weak)) u32 MtFile::readAsync(void* out, u32 bytes) {
    DDON_STUB("MtFile::readAsync")
    return {};
}

__attribute__((weak)) void MtFile::readWait() {
    DDON_STUB("MtFile::readWait")
    /* stub */
}

bool MtFile::isAsyncReading() const {
    return mAsyncExec;
}

u32 MtFile::write(const void* in, u32 bytes) {
    if (mDLCHandle == 0xFFFFFFFFu) {
        ssize_t writebytes = sceKernelWrite(mHandle, in, bytes);
        MtFile::mLastError = static_cast<FileError>(static_cast<unsigned int>(writebytes & (writebytes >> 63)));
        u32 t0 = mSeekPt;
        mSeekPt = t0 + ((writebytes <= -1l) ? 0u : static_cast<unsigned int>(writebytes));
        if (mSize < mSeekPt) {
            mSize = mSeekPt;
        }
        return static_cast<unsigned int>((writebytes <= -1l) ? 0l : writebytes);
    } else {
        return 0;
    }
}

u32 MtFile::seek(s32 offset, MtFile::SEEKBASE base) {
    if (base != SEEKBASE_END) {
        if (base == SEEKBASE_CUR) {
            u32 t0 = mSeekPt;
            mSeekPt = (mSize < (offset + t0)) ? mSize : (offset + t0);
            if (mMode == MODE_READ_ASYNC) {
                readWait();
                ssize_t pos = sceKernelLseek(mHandle, mSeekPt, 0);
                if (pos > -1l) {
                    MtFile::mLastError = 0;
                    return static_cast<unsigned int>(pos);
                } else {
                    MtFile::mLastError = static_cast<FileError>(static_cast<unsigned int>(pos));
                    return 0;
                }
            } else {
                ssize_t pos = sceKernelLseek(mHandle, (mSize < (offset + t0)) ? mSize : (offset + t0), 0);
                if (pos > -1l) {
                    MtFile::mLastError = 0;
                    return static_cast<unsigned int>(pos);
                } else {
                    MtFile::mLastError = static_cast<FileError>(static_cast<unsigned int>(pos));
                    return 0;
                }
            }
        } else {
            if (base == SEEKBASE_SET) {
                if (offset > -1) {
                    if (mSize >= static_cast<unsigned int>(offset)) {
                        mSeekPt = static_cast<u32>(offset);
                        if (mMode == MODE_READ_ASYNC) {
                            readWait();
                            ssize_t pos = sceKernelLseek(mHandle, mSeekPt, 0);
                            if (pos > -1l) {
                                MtFile::mLastError = 0;
                                return static_cast<unsigned int>(pos);
                            } else {
                                MtFile::mLastError = static_cast<FileError>(static_cast<unsigned int>(pos));
                                return 0;
                            }
                        } else {
                            ssize_t pos = sceKernelLseek(mHandle, static_cast<unsigned int>(offset), 0);
                            if (pos > -1l) {
                                MtFile::mLastError = 0;
                                return static_cast<unsigned int>(pos);
                            } else {
                                MtFile::mLastError = static_cast<FileError>(static_cast<unsigned int>(pos));
                                return 0;
                            }
                        }
                    } else {
                        mSeekPt = mSize;
                        if (mMode == MODE_READ_ASYNC) {
                            readWait();
                            ssize_t pos = sceKernelLseek(mHandle, mSeekPt, 0);
                            if (pos > -1l) {
                                MtFile::mLastError = 0;
                                return static_cast<unsigned int>(pos);
                            } else {
                                MtFile::mLastError = static_cast<FileError>(static_cast<unsigned int>(pos));
                                return 0;
                            }
                        } else {
                            ssize_t pos = sceKernelLseek(mHandle, mSize, 0);
                            if (pos > -1l) {
                                MtFile::mLastError = 0;
                                return static_cast<unsigned int>(pos);
                            } else {
                                MtFile::mLastError = static_cast<FileError>(static_cast<unsigned int>(pos));
                                return 0;
                            }
                        }
                    }
                } else {
                    mSeekPt = 0;
                    if (mMode == MODE_READ_ASYNC) {
                        readWait();
                        ssize_t pos = sceKernelLseek(mHandle, mSeekPt, 0);
                        if (pos > -1l) {
                            MtFile::mLastError = 0;
                            return static_cast<unsigned int>(pos);
                        } else {
                            MtFile::mLastError = static_cast<FileError>(static_cast<unsigned int>(pos));
                            return 0;
                        }
                    } else {
                        ssize_t pos = sceKernelLseek(mHandle, 0l, 0);
                        if (pos > -1l) {
                            MtFile::mLastError = 0;
                            return static_cast<unsigned int>(pos);
                        } else {
                            MtFile::mLastError = static_cast<FileError>(static_cast<unsigned int>(pos));
                            return 0;
                        }
                    }
                }
            } else {
                return 0;
            }
        }
    } else {
        mSeekPt = (static_cast<unsigned int>(offset) < mSize) ? (mSize - offset) : 0u;
        if (mMode == MODE_READ_ASYNC) {
            readWait();
            ssize_t pos = sceKernelLseek(mHandle, mSeekPt, 0);
            if (pos > -1l) {
                MtFile::mLastError = 0;
                return static_cast<unsigned int>(pos);
            } else {
                MtFile::mLastError = static_cast<FileError>(static_cast<unsigned int>(pos));
                return 0;
            }
        } else {
            ssize_t pos = sceKernelLseek(mHandle, static_cast<off_t>((static_cast<unsigned int>(offset) < mSize) ? (mSize - offset) : 0u), 0);
            if (pos > -1l) {
                MtFile::mLastError = 0;
                return static_cast<unsigned int>(pos);
            } else {
                MtFile::mLastError = static_cast<FileError>(static_cast<unsigned int>(pos));
                return 0;
            }
        }
    }
}

u32 MtFile::getPosition() {
    return mSeekPt;
}

__attribute__((weak)) u32 MtFile::length() {
    DDON_STUB("MtFile::length")
    return {};
}

void MtFile::setLength(u32 len) {
    if (mDLCHandle != 0xFFFFFFFFu) {
        return;
    }
    mLastErrorCode = sceKernelFtruncate(mHandle, len);
}

bool MtFile::isReadable() {
    return isReadableMode(mMode);
}

bool MtFile::isWritable() {
    return isWritableMode(mMode);
}

bool MtFile::isAsyncReadable() {
    return isAsyncReadableMode(mMode);
}

__attribute__((weak)) u32 MtFile::getDriveType(MT_CTSTR path) {
        MtFile::DRIVETYPE type = DRIVETYPE_HOME;
        u32 offset = 0;
        u32 src_offset = 0;
        do {
            mpPathDriveTypeFunc(path + offset, type, src_offset, nullptr);
            offset += src_offset;
        } while (type == DRIVETYPE_ABS);
        return type;
}

__attribute__((weak)) bool MtFile::checkAcceptableName(MT_CTSTR filename, MT_CTSTR findName) {
    DDON_STUB("MtFile::checkAcceptableName")
    return {};
}

u32 MtFile::getAsyncTransferredSize() const {
    return mAsyncTransferredSize;
}

bool MtFile::isReadableMode(MtFile::MODE mode) {
    if (static_cast<unsigned int>(mode - 17) <= 5) {
        return static_cast<bool>((51ul >> static_cast<unsigned long>(static_cast<unsigned char>(mode + 239) & 31)) & 1ul);
    } else {
        return false;
    }
}

bool MtFile::isWritableMode(MtFile::MODE mode) {
    return static_cast<unsigned int>(mode - 19) <= 3;
}

bool MtFile::isAsyncReadableMode(MtFile::MODE mode) {
    return mode == MODE_READ_ASYNC;
}

inline MtFile::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtFile::MyDTI MtFile::DTI("MtFile", &::MtObject::DTI, 1096ul, 0u, 0u);

MT_CHAR MtFile::mCurrentPath[1024];

MtFile::FileError MtFile::mLastError;

MT_CHAR MtFile::mCachePath[1024];

MtFile::DLC_CLOSE_FUNC MtFile::mpDLCcloseFunc;

__attribute__((weak)) MtObject* MtFile::MyDTI::newInstance() const {
    DDON_STUB("MtFile::MyDTI::newInstance")
    return nullptr;
}

MtFile::AsyncThreadPool::AsyncThreadPool() {
    DDON_STUB("MtFile::AsyncThreadPool::AsyncThreadPool")
    /* stub */
}

MtFile::AsyncThreadPool::~AsyncThreadPool() {
    DDON_STUB("MtFile::AsyncThreadPool::~AsyncThreadPool")
    /* stub */
}

__attribute__((weak)) void* MtFile::AsyncThreadPool::readAsyncProc(void* pArg) {
    DDON_STUB("MtFile::AsyncThreadPool::readAsyncProc")
    return nullptr;
}

const MtDTI& MtFile::FileInfo::getDTI() const {
    return MtFile::FileInfo::DTI;
}

MtFile::FileInfo::FileInfo() {
    DDON_STUB("MtFile::FileInfo::FileInfo")
    /* stub */
}

__attribute__((noinline)) MtFile::FileInfo::~FileInfo() {
    DDON_STUB("MtFile::FileInfo::~FileInfo")
    /* stub */
}

__attribute__((weak)) MT_CTSTR MtFile::FileInfo::getFileType() const {
    DDON_STUB("MtFile::FileInfo::getFileType")
    return {};
}

__attribute__((weak)) void MtFile::FileInfo::setFileType(MT_CTSTR) {
}

__attribute__((weak)) void MtFile::FileInfo::createProperty(MtPropertyList& s) {
    DDON_STUB("MtFile::FileInfo::createProperty")
    /* stub */
}

MtUI* MtFile::FileInfo::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

inline MtFile::FileInfo::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtFile::FileInfo::MyDTI MtFile::FileInfo::DTI("MtFile::FileInfo", &::MtObject::DTI, 2144ul, 0u, 0u);

__attribute__((weak)) MtObject* MtFile::FileInfo::MyDTI::newInstance() const {
    DDON_STUB("MtFile::FileInfo::MyDTI::newInstance")
    return nullptr;
}

MtFile::RealPath::RealPath(MT_CTSTR path) {
    DDON_STUB("MtFile::RealPath::RealPath")
    /* stub */
}

