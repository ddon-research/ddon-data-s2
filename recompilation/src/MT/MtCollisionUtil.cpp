// Reconstructed from the game's DWARF debug information.
#include <new>
#include <string.h>
#include "MtCollisionUtil.h"
#include "../DD_ONLINE/prog/HttpPatchDL/modules/httpPatch/HttpPatchManager.h"
#include "MtAllocator.h"
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtDtiSelecter.h"
#include "MtMemory.h"
#include "MtMemoryAllocator.h"
#include "MtObject.h"
#include "MtProperty.h"
#include "MtPropertyList.h"
#include "MtString.h"
#include "../XFramework/cDynamicBVHCollision.h"
#include "../DD_ONLINE/prog/HttpPatchDL/modules/httpPatch/httpPatchTypes.h"
#include "../DD_ONLINE/prog/HttpPatchDL/modules/network/networkHttpDownloadManager.h"
#include "../XFramework/sCollision.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& MtCollisionUtil::MtArrayEx::getDTI() const {
    return MtCollisionUtil::MtArrayEx::DTI;
}

void* MtCollisionUtil::MtArrayEx::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::MtCollisionUtil::MtArrayEx::DTI)->memAlloc(sz, align, ::MtCollisionUtil::MtArrayEx::DTI.mID);
}

MtCollisionUtil::MtArrayEx::~MtArrayEx() {
    DDON_STUB("MtCollisionUtil::MtArrayEx::~MtArrayEx")
    /* stub */
}

MtUI* MtCollisionUtil::MtArrayEx::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void MtCollisionUtil::MtArrayEx::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_BOOL, "mAutoDelete", reinterpret_cast<MT_MFUNC>(&::MtArray::isAutoDelete), reinterpret_cast<MT_MFUNC>(&::MtArray::setAutoDelete), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_U32, "mLength", reinterpret_cast<MT_MFUNC>(&::MtArray::length), reinterpret_cast<MT_MFUNC>(&::MtCollisionUtil::MtArrayEx::resize), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_STRING, "ArrayDTI", reinterpret_cast<MT_MFUNC>(&::MtCollisionUtil::MtArrayEx::getElementDtiName), reinterpret_cast<MT_MFUNC>(&::MtCollisionUtil::MtArrayEx::setDummyString), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_CLASSREF, "mpArray", reinterpret_cast<MT_MFUNC>(&::MtCollisionUtil::MtArrayEx::getClass), reinterpret_cast<MT_MFUNC>(&::MtCollisionUtil::MtArrayEx::setClass), 160u, reinterpret_cast<MT_MFUNC>(&::MtArray::length), reinterpret_cast<MT_MFUNC>(&::MtCollisionUtil::MtArrayEx::resize));
}

void MtCollisionUtil::MtArrayEx::resize(u32 siz) {
    u32 t0 = mLength;
    u32 v3_11;
    if (mAutoDelete) {
        if (siz < t0) {
            if (t0 != siz) {
                MtObject* * ppBuffer = mpArray;
                for (u32 v0_3 = t0;;) {
                    if (ppBuffer[v0_3 - 1u] != nullptr) {
                        delete ppBuffer[v0_3 - 1u];
                        ppBuffer[v0_3 - 1u] = nullptr;
                    }
                    if (siz != (v0_3 - 1u)) {
                        v0_3 += 0xFFFFFFFFu;
                    } else {
                        break;
                    }
                }
                this->::MtArray::resize(siz);
                return;
            } else {
                this->::MtArray::resize(siz);
                return;
            }
        } else {
            if (t0 >= siz) {
                this->::MtArray::resize(siz);
                return;
            } else {
                if (mAutoCreate) {
                    if (mAutoCreateDTI.getRegistDTI() != nullptr) {
                        if (t0 != siz) {
                            v3_11 = siz - t0;
                        } else {
                            this->::MtArray::resize(siz);
                            return;
                        }
                    } else {
                        this->::MtArray::resize(siz);
                        return;
                    }
                } else {
                    this->::MtArray::resize(siz);
                    return;
                }
            }
        }
    } else {
        if (t0 >= siz) {
            this->::MtArray::resize(siz);
            return;
        } else {
            if (mAutoCreate) {
                if (mAutoCreateDTI.getRegistDTI() != nullptr) {
                    if (t0 != siz) {
                        v3_11 = siz - t0;
                    } else {
                        this->::MtArray::resize(siz);
                        return;
                    }
                } else {
                    this->::MtArray::resize(siz);
                    return;
                }
            } else {
                this->::MtArray::resize(siz);
                return;
            }
        }
    }
    for (;;) {
        MtObject* t1 = mAutoCreateDTI.getRegistDTI()->newInstance();
        u32 t2 = mLength;
        u32 t3 = mBufsiz;
        if (t2 < t3) {
            mLength = t2 + 1u;
            mpArray[t2] = t1;
        } else {
            void* t4 = ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memAlloc(static_cast<size_t>(t3 + 32u) * 8, 16u);
            ::memset(t4, 0, static_cast<size_t>(t3 + 32u) * 8);
            ::memcpy(t4, static_cast<const void*>(mpArray), static_cast<size_t>(mLength) * 8);
            ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mpArray));
            mpArray = static_cast<MtObject* *>(t4);
            mBufsiz = t3 + 32u;
            u32 t5 = mLength;
            mLength = t5 + 1u;
            mpArray[t5] = t1;
        }
        if ((v3_11 - 1u) != 0) {
            v3_11 += 0xFFFFFFFFu;
        } else {
            break;
        }
    }
    this->::MtArray::resize(siz);
}

void MtCollisionUtil::MtArrayEx::setClass(MtObject* pObj, u32 index) {
    if (index < mBufsiz) {
        mpArray[index] = pObj;
    }
}

MtObject* MtCollisionUtil::MtArrayEx::getClass(u32 index) {
    if (index < mBufsiz) {
        return mpArray[index];
    } else {
        return nullptr;
    }
}

MT_CTSTR MtCollisionUtil::MtArrayEx::getElementDtiName() {
    if (mLength != 0) {
        if ((*mpArray) != nullptr) {
            return (*mpArray)->getDTI().mName;
        }
    }
    return "";
}

__attribute__((weak)) void MtCollisionUtil::MtArrayEx::setDummyString(MtString) {
}

inline MtCollisionUtil::MtArrayEx::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtCollisionUtil::MtArrayEx::MyDTI MtCollisionUtil::MtArrayEx::DTI("MtCollisionUtil::MtArrayEx", &::MtArray::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* MtCollisionUtil::MtArrayEx::MyDTI::newInstance() const {
    DDON_STUB("MtCollisionUtil::MtArrayEx::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& MtCollisionUtil::MtDtiObject::getDTI() const {
    return MtCollisionUtil::MtDtiObject::DTI;
}

MtCollisionUtil::MtDtiObject::MtDtiObject(const MtDTI* pDTI) {
    mpRegistDTI = pDTI;
}

MtCollisionUtil::MtDtiObject::~MtDtiObject() {
}

MtUI* MtCollisionUtil::MtDtiObject::createUI(MtProperty& prop) {
    return this->::MtObject::createUI(prop);
}

void MtCollisionUtil::MtDtiObject::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_STRING, "DtiName", reinterpret_cast<MT_MFUNC>(&::MtCollisionUtil::MtDtiObject::getRegistDTIName), reinterpret_cast<MT_MFUNC>(&::MtCollisionUtil::MtDtiObject::registDTIName), 1409u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_U32, "DtiID", reinterpret_cast<MT_MFUNC>(&::MtCollisionUtil::MtDtiObject::getRegistDTI_ID), reinterpret_cast<MT_MFUNC>(&::MtCollisionUtil::MtDtiObject::registDTI_ID), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

__attribute__((weak)) const MtDTI* MtCollisionUtil::MtDtiObject::getRegistDTI() const {
    return mpRegistDTI;
}

void MtCollisionUtil::MtDtiObject::registDTI(const MtDTI* pRegistDTI) {
    mpRegistDTI = pRegistDTI;
}

MT_CTSTR MtCollisionUtil::MtDtiObject::getRegistDTIName() const {
    if (mpRegistDTI != nullptr) {
        return mpRegistDTI->mName;
    } else {
        return "";
    }
}

__attribute__((weak)) void MtCollisionUtil::MtDtiObject::registDTIName(MtString& NewDTIName) {
    DDON_STUB("MtCollisionUtil::MtDtiObject::registDTIName")
    /* stub */
}

u32 MtCollisionUtil::MtDtiObject::getRegistDTI_ID() const {
    if (mpRegistDTI != nullptr) {
        return mpRegistDTI->mID;
    } else {
        return 0;
    }
}

void MtCollisionUtil::MtDtiObject::registDTI_ID(u32 NewDTI_ID) {
    mpRegistDTI = ::MtDTI::from(NewDTI_ID);
}

inline MtCollisionUtil::MtDtiObject::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtCollisionUtil::MtDtiObject::MyDTI MtCollisionUtil::MtDtiObject::DTI("MtCollisionUtil::MtDtiObject", &::MtObject::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* MtCollisionUtil::MtDtiObject::MyDTI::newInstance() const {
    DDON_STUB("MtCollisionUtil::MtDtiObject::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& MtCollisionUtil::MtDtiSelecter::getDTI() const {
    return MtCollisionUtil::MtDtiSelecter::DTI;
}

__attribute__((weak)) void MtCollisionUtil::MtDtiSelecter::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::MtCollisionUtil::MtDtiSelecter::DTI)->memFree(p_addr);
}

inline MtCollisionUtil::MtDtiSelecter::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtCollisionUtil::MtDtiSelecter::MyDTI MtCollisionUtil::MtDtiSelecter::DTI("MtCollisionUtil::MtDtiSelecter", &::MtCollisionUtil::MtDtiSelecterIntermediate::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* MtCollisionUtil::MtDtiSelecter::MyDTI::newInstance() const {
    DDON_STUB("MtCollisionUtil::MtDtiSelecter::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& MtCollisionUtil::MtDtiSelecterIntermediate::getDTI() const {
    return MtCollisionUtil::MtDtiSelecterIntermediate::DTI;
}

inline MtCollisionUtil::MtDtiSelecterIntermediate::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtCollisionUtil::MtDtiSelecterIntermediate::MyDTI MtCollisionUtil::MtDtiSelecterIntermediate::DTI("MtCollisionUtil::MtDtiSelecterIntermediate", &::MtDtiSelecter::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* MtCollisionUtil::MtDtiSelecterIntermediate::MyDTI::newInstance() const {
    DDON_STUB("MtCollisionUtil::MtDtiSelecterIntermediate::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& MtCollisionUtil::MtFuncBase::getDTI() const {
    return MtCollisionUtil::MtFuncBase::DTI;
}

MtCollisionUtil::MtFuncBase::~MtFuncBase() {
    DDON_STUB("MtCollisionUtil::MtFuncBase::~MtFuncBase")
    /* stub */
}

void MtCollisionUtil::MtFuncBase::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_STRING, "name", reinterpret_cast<MT_MFUNC>(&::MtCollisionUtil::MtFuncBase::getName), reinterpret_cast<MT_MFUNC>(&::MtCollisionUtil::MtFuncBase::setNameForIO), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), "mpOwner", &mpOwner, 16u, 0u);
}

MT_CTSTR MtCollisionUtil::MtFuncBase::getName() {
    return mpName;
}

__attribute__((weak)) void MtCollisionUtil::MtFuncBase::setNameForIO(MtString& str) {
    DDON_STUB("MtCollisionUtil::MtFuncBase::setNameForIO")
    /* stub */
}

inline MtCollisionUtil::MtFuncBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

MtCollisionUtil::MtFuncBase::MyDTI MtCollisionUtil::MtFuncBase::DTI("MtCollisionUtil::MtFuncBase", &::MtObject::DTI, 24ul, 0u, 0u);

MtObject* MtCollisionUtil::MtFuncBase::MyDTI::newInstance() const {
    return new (16u) ::MtCollisionUtil::MtFuncBase;
}

