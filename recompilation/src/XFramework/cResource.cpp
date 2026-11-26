// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cResource.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtFile.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtTime.h"
#include "../MT/MtXmlReader.h"
#include "sResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cResource::getDTI() const {
    return cResource::DTI;
}

inline void cResource::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cResource::DTI)->memFree(p_addr);
}

static auto ddon_emit_0x01b5bad0 __attribute__((used)) = &cResource::getQuality;

static auto ddon_emit_0x01b5ba80 __attribute__((used)) = &cResource::getTag;

static auto ddon_emit_0x01b5ba60 __attribute__((used)) = &cResource::getPath;

void cResource::addRef() {
    (sResource::mpInstance)->addRef(this);
}

void cResource::release() {
    (sResource::mpInstance)->release(this);
}

MtUI* cResource::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void cResource::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CSTRING, "mPath", reinterpret_cast<MT_MFUNC>(&::cResource::getPath), reinterpret_cast<MT_MFUNC>(&::cResource::setPath), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mID", &mID, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mRefCount", &mRefCount, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mSize", &mSize, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mAttr", &mAttr, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mTag", reinterpret_cast<MT_MFUNC>(&::cResource::getTag), reinterpret_cast<MT_MFUNC>(&::cResource::setTag), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mState", reinterpret_cast<MT_MFUNC>(&::cResource::getState), reinterpret_cast<MT_MFUNC>(&::cResource::setState), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mQuality", reinterpret_cast<MT_MFUNC>(&::cResource::getQuality), reinterpret_cast<MT_MFUNC>(&::cResource::setQuality), 145u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

__attribute__((weak)) MtTime cResource::getUpdateTime(MT_CTSTR fullpath) {
    DDON_STUB("cResource::getUpdateTime")
    __builtin_unreachable();
}

MT_CTSTR cResource::getExt() const {
    return "";
}

bool cResource::compact(MtStream& out) {
    return false;
}

cResource::cResource() {
    mMagicID = 21075;
    mMagicTag = 0;
    mRefCount = 1;
    mAttr = 0;
    mSize = 0;
    mID = 0;
    mPath[0] = 0;
    mState = 0;
    mQuality = 2;
    mTag = 0;
}

cResource::~cResource() {
    mMagicID = 0;
    mMagicTag = 0;
}

bool cResource::create() {
    return false;
}

bool cResource::loadEnd() {
    return true;
}

bool cResource::load(MtStream&) {
    return false;
}

bool cResource::save(MtStream&) {
    return false;
}

bool cResource::convert(MtStream& out) {
    return convertEx(out, CONVERT_DEFAULT);
}

bool cResource::convertEx(MtStream&, cResource::CONVERT_TYPE type) {
    return false;
}

__attribute__((weak)) void cResource::clear() {
}

u32 cResource::getState() {
    return mState;
}

void cResource::setState(u32 v) {
    mState = v;
}

void cResource::setQuality(u32 q) {
    mQuality = q;
}

void cResource::setTag(u32 tag) {
    mTag = tag;
}

__attribute__((weak)) void cResource::setPath(const MtString& s) {
}

inline cResource::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cResource::MyDTI cResource::DTI("cResource", &::MtObject::DTI, 112ul, 0u, 1u);

MtObject* cResource::MyDTI::newInstance() const {
    return nullptr;
}

