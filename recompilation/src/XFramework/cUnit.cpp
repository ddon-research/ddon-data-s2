// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cUnit.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "sRender.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cUnit::getDTI() const {
    return cUnit::DTI;
}

cUnit::cUnit() {
    mDrawMode = 0;
    mBeFlag = 1;
    mMoveLine = 127;
    mUnitAttr = 19;
    mDrawView = 15;
    this->mRno = 0;
    mpPrevUnit = nullptr;
    mpNextUnit = nullptr;
    mDeltaTime = 1.0f;
    mUnitParam = 0;
    mUnitGroup = 0;
    mpHardwareDispCtrl = nullptr;
}

cUnit::~cUnit() {
    if (mpHardwareDispCtrl == nullptr) {
        return;
    }
    delete mpHardwareDispCtrl;
    mpHardwareDispCtrl = nullptr;
}

void cUnit::setup() {
    mpHardwareDispCtrl = createHardwareDispCtrl();
}

static auto ddon_emit_0x01b5bc80 __attribute__((used)) = &cUnit::getMoveLine;

bool cUnit::checkUnitGroup(u32 group) const {
    return ((static_cast<unsigned long>(mUnitGroup) >> static_cast<unsigned long>(group & 63u)) & 1ul) != 0;
}

u64 cUnit::getDefaultUnitGroup() const {
    return 0;
}

u64 cUnit::getSystemUnitGroup() const {
    return 0;
}

bool cUnit::getBoundary(MtSphere* pdst) {
    return false;
}

MtUI* cUnit::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

MT_CTSTR cUnit::getName() {
    return getDTI().mName;
}

void cUnit::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Move", reinterpret_cast<MT_MFUNC>(&::cUnit::isMove), reinterpret_cast<MT_MFUNC>(&::cUnit::setMove), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Draw", reinterpret_cast<MT_MFUNC>(&::cUnit::getTrans), reinterpret_cast<MT_MFUNC>(&::cUnit::setDraw), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Fix", reinterpret_cast<MT_MFUNC>(&::cUnit::isFix), reinterpret_cast<MT_MFUNC>(&::cUnit::setFix), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mDrawMode", reinterpret_cast<MT_MFUNC>(&::cUnit::getDrawMode), reinterpret_cast<MT_MFUNC>(&::cUnit::setDrawMode), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mDrawView", reinterpret_cast<MT_MFUNC>(&::cUnit::getDrawView), reinterpret_cast<MT_MFUNC>(&::cUnit::setDrawView), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_STRING, "Name", reinterpret_cast<MT_MFUNC>(&::cUnit::getName), reinterpret_cast<MT_MFUNC>(&::cUnit::setName), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mMoveLine", reinterpret_cast<MT_MFUNC>(&::cUnit::getMoveLine), reinterpret_cast<MT_MFUNC>(&::cUnit::setMoveLine), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mBeFlag", reinterpret_cast<MT_MFUNC>(&::cUnit::getBeFlag), reinterpret_cast<MT_MFUNC>(&::cUnit::setBeFlag), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "mRno", &this->mRno, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUnitParam", &mUnitParam, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mDeltaTime", &mDeltaTime, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mUnitGroup", &mUnitGroup, 3u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Trans", reinterpret_cast<MT_MFUNC>(&::cUnit::getTrans), reinterpret_cast<MT_MFUNC>(&::cUnit::setDraw), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mTransMode", reinterpret_cast<MT_MFUNC>(&::cUnit::getDrawMode), reinterpret_cast<MT_MFUNC>(&::cUnit::setDrawMode), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "mTransView", reinterpret_cast<MT_MFUNC>(&::cUnit::getDrawView), reinterpret_cast<MT_MFUNC>(&::cUnit::setDrawView), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_CLASS, "mpHardwareDispCtrl", reinterpret_cast<MT_MFUNC>(&::cUnit::getHardwareDispCtrl), reinterpret_cast<MT_MFUNC>(&::cUnit::setHardwareDispCtrl), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

void cUnit::kill() {
    if ((((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 16)) >> 8) & 32u) != 0) {
        return;
    }
    if ((mBeFlag - 1u) <= 1u) {
        mBeFlag = 3;
    }
}

static auto ddon_emit_0x01b5bc00 __attribute__((used)) = &cUnit::setFix;

static auto ddon_emit_0x01b5bb80 __attribute__((used)) = &cUnit::setMove;

__attribute__((weak)) void cUnit::setDraw(bool draw) {
    DDON_STUB("cUnit::setDraw")
    /* stub */
}

static auto ddon_emit_0x01b5bc30 __attribute__((used)) = &cUnit::setDrawMode;

static auto ddon_emit_0x01b5bc20 __attribute__((used)) = &cUnit::getDrawMode;

static auto ddon_emit_0x01b5bc50 __attribute__((used)) = &cUnit::setDrawView;

static auto ddon_emit_0x01b5bc40 __attribute__((used)) = &cUnit::getDrawView;

static auto ddon_emit_0x01b5bcb0 __attribute__((used)) = &cUnit::getBeFlag;

bool cUnit::isFix() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 17)) & 32) >> 5);
}

__attribute__((weak)) bool cUnit::isMove() const {
    DDON_STUB("cUnit::isMove")
    return {};
}

void cUnit::getDrawUnitState(u32& type, u32& priority) const {
    type = 9;
    priority = 0;
}

u32 cUnit::getUseCommandCacheNum() {
    return 0;
}

u32 cUnit::getUseMaxCommandCacheNum() {
    return 0;
}

bool cUnit::isPossibleDrawFromDrawBuffer() {
    return (sRender::mpInstance)->isPossibleDrawFromDrawBuffer();
}

bool cUnit::isEnableInstance() const {
    return (mBeFlag - 1u) <= 1u;
}

void cUnit::setBeFlag(u32 bf) {
    mBeFlag = bf;
}

bool cUnit::getTrans() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 17)) & 8) >> 3);
}

void cUnit::setMoveLine(u32 line) {
    mMoveLine = line;
}

__attribute__((weak)) void cUnit::setName(MT_CTSTR) {
}

__attribute__((weak)) cUnit::cHardwareDispCtrl* cUnit::createHardwareDispCtrl() {
    DDON_STUB("cUnit::createHardwareDispCtrl")
    return nullptr;
}

static auto ddon_emit_0x01b5bcd0 __attribute__((used)) = &cUnit::getHardwareDispCtrl;

__attribute__((weak)) void cUnit::setHardwareDispCtrl(cUnit::cHardwareDispCtrl* set) {
}

inline cUnit::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cUnit::MyDTI cUnit::DTI("cUnit", &::MtObject::DTI, 72ul, 0u, 1u);

MtObject* cUnit::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& cUnit::cHardwareDispCtrl::getDTI() const {
    return cUnit::cHardwareDispCtrl::DTI;
}

void* cUnit::cHardwareDispCtrl::operator new(size_t sz, u32 align) {
    return MtMemoryAllocator::getAllocator(cUnit::cHardwareDispCtrl::DTI)->memAlloc(sz, align, cUnit::cHardwareDispCtrl::DTI.mID);
}

inline void cUnit::cHardwareDispCtrl::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cUnit::cHardwareDispCtrl::DTI)->memFree(p_addr);
}

void cUnit::cHardwareDispCtrl::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mFlag", &mFlag, 0u, 0u);
}

void cUnit::cHardwareDispCtrl::init() {
    mHard = 1;
    mFlag = 0;
    mOldFlag = 0;
    mpOwner = nullptr;
}

__attribute__((weak)) void cUnit::cHardwareDispCtrl::update() {
    DDON_STUB("cUnit::cHardwareDispCtrl::update")
    /* stub */
}

bool cUnit::cHardwareDispCtrl::isDispOperateHard() {
    return ((static_cast<unsigned long>(mFlag) >> static_cast<unsigned long>(mHard & 31u)) & 1ul) == 0;
}

bool cUnit::cHardwareDispCtrl::isDispOperateHardOld() {
    return ((static_cast<unsigned long>(mOldFlag) >> static_cast<unsigned long>(mHard & 31u)) & 1ul) == 0;
}

inline cUnit::cHardwareDispCtrl::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cUnit::cHardwareDispCtrl::MyDTI cUnit::cHardwareDispCtrl::DTI("cUnit::cHardwareDispCtrl", &::MtObject::DTI, 32ul, 0u, 0u);

MtObject* cUnit::cHardwareDispCtrl::MyDTI::newInstance() const {
    return new (16u) cUnit::cHardwareDispCtrl;
}

