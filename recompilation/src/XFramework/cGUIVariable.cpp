// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cGUIVariable.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cGUIVarFloat::getDTI() const {
    return cGUIVarFloat::DTI;
}

void* cGUIVarFloat::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

cGUIVarFloat::cGUIVarFloat() {
    DDON_STUB("cGUIVarFloat::cGUIVarFloat")
    /* stub */
}

cGUIVarFloat::~cGUIVarFloat() {
}

MtUI* cGUIVarFloat::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void cGUIVarFloat::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "Id", &mId, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "LoopValue", reinterpret_cast<MT_MFUNC>(&::cGUIVariable::isLoopValue), reinterpret_cast<MT_MFUNC>(&::cGUIVariable::setLoopValue), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "MinValue", reinterpret_cast<MT_MFUNC>(&::cGUIVarFloat::getMin), reinterpret_cast<MT_MFUNC>(&::cGUIVarFloat::setMin), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "MaxValue", reinterpret_cast<MT_MFUNC>(&::cGUIVarFloat::getMax), reinterpret_cast<MT_MFUNC>(&::cGUIVarFloat::setMax), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "Value", reinterpret_cast<MT_MFUNC>(&::cGUIVarFloat::get), reinterpret_cast<MT_MFUNC>(&::cGUIVarFloat::setValue), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "OldValue", reinterpret_cast<MT_MFUNC>(&::cGUIVarFloat::getOld), reinterpret_cast<MT_MFUNC>(&::cGUIVarFloat::setOld), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "InitValue", reinterpret_cast<MT_MFUNC>(&::cGUIVarFloat::getInit), reinterpret_cast<MT_MFUNC>(&::cGUIVarFloat::setInit), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

s32 cGUIVarFloat::getS32() const {
    return static_cast<int>(mValue);
}

__attribute__((weak)) void cGUIVarFloat::set(f32 value, bool forceUpdate) {
    DDON_STUB("cGUIVarFloat::set")
    /* stub */
}

static auto ddon_emit_0x01b73940 __attribute__((used)) = &cGUIVarFloat::get;

__attribute__((weak)) void cGUIVarFloat::setOld(f32 value) {
}

static auto ddon_emit_0x01b73950 __attribute__((used)) = &cGUIVarFloat::getOld;

static auto ddon_emit_0x01b73980 __attribute__((used)) = &cGUIVarFloat::setInit;

static auto ddon_emit_0x01b73970 __attribute__((used)) = &cGUIVarFloat::getInit;

static auto ddon_emit_0x01b73930 __attribute__((used)) = &cGUIVarFloat::setMax;

static auto ddon_emit_0x01b73920 __attribute__((used)) = &cGUIVarFloat::getMax;

static auto ddon_emit_0x01b73910 __attribute__((used)) = &cGUIVarFloat::setMin;

static auto ddon_emit_0x01b73900 __attribute__((used)) = &cGUIVarFloat::getMin;

__attribute__((weak)) void cGUIVarFloat::setValue(f32 value) {
    DDON_STUB("cGUIVarFloat::setValue")
    /* stub */
}

inline cGUIVarFloat::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGUIVarFloat::MyDTI cGUIVarFloat::DTI("cGUIVarFloat", &::cGUIVariable::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* cGUIVarFloat::MyDTI::newInstance() const {
    DDON_STUB("cGUIVarFloat::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cGUIVarInt::getDTI() const {
    return cGUIVarInt::DTI;
}

void* cGUIVarInt::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

cGUIVarInt::cGUIVarInt() {
    DDON_STUB("cGUIVarInt::cGUIVarInt")
    /* stub */
}

cGUIVarInt::~cGUIVarInt() {
}

MtUI* cGUIVarInt::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void cGUIVarInt::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "Id", &mId, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "LoopValue", reinterpret_cast<MT_MFUNC>(&::cGUIVariable::isLoopValue), reinterpret_cast<MT_MFUNC>(&::cGUIVariable::setLoopValue), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "MinValue", reinterpret_cast<MT_MFUNC>(&::cGUIVarInt::getMin), reinterpret_cast<MT_MFUNC>(&::cGUIVarInt::setMin), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "MaxValue", reinterpret_cast<MT_MFUNC>(&::cGUIVarInt::getMax), reinterpret_cast<MT_MFUNC>(&::cGUIVarInt::setMax), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "Value", reinterpret_cast<MT_MFUNC>(&::cGUIVarInt::get), reinterpret_cast<MT_MFUNC>(&::cGUIVarInt::setValue), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "OldValue", reinterpret_cast<MT_MFUNC>(&::cGUIVarInt::getOld), reinterpret_cast<MT_MFUNC>(&::cGUIVarInt::setOld), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_S32, "InitValue", reinterpret_cast<MT_MFUNC>(&::cGUIVarInt::getInit), reinterpret_cast<MT_MFUNC>(&::cGUIVarInt::setInit), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

void cGUIVarInt::createEventProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "increment", static_cast<MT_MFUNC>(&::cGUIVarInt::incrementForProperty), 10u);
    s << MtProperty(static_cast<MtObject*>(this), "decrement", static_cast<MT_MFUNC>(&::cGUIVarInt::decrementForProperty), 10u);
}

const MT_CTSTR* cGUIVarInt::getEventPropertyTooltip() {
    static const MT_CTSTR tooltip[2] = {
        "現在の値を＋１する",
        "現在の値を－１する",
    };
    return tooltip;
}

s32 cGUIVarInt::getS32() const {
    return mValue;
}

__attribute__((weak)) void cGUIVarInt::set(s32 value, bool forceUpdate) {
    DDON_STUB("cGUIVarInt::set")
    /* stub */
}

static auto ddon_emit_0x01b73800 __attribute__((used)) = &cGUIVarInt::get;

__attribute__((weak)) void cGUIVarInt::setOld(s32 value) {
}

static auto ddon_emit_0x01b73810 __attribute__((used)) = &cGUIVarInt::getOld;

static auto ddon_emit_0x01b73840 __attribute__((used)) = &cGUIVarInt::setInit;

static auto ddon_emit_0x01b73830 __attribute__((used)) = &cGUIVarInt::getInit;

static auto ddon_emit_0x01b737f0 __attribute__((used)) = &cGUIVarInt::setMax;

static auto ddon_emit_0x01b737e0 __attribute__((used)) = &cGUIVarInt::getMax;

static auto ddon_emit_0x01b737d0 __attribute__((used)) = &cGUIVarInt::setMin;

static auto ddon_emit_0x01b737c0 __attribute__((used)) = &cGUIVarInt::getMin;

__attribute__((weak)) void cGUIVarInt::setValue(s32 value) {
    DDON_STUB("cGUIVarInt::setValue")
    /* stub */
}

__attribute__((weak)) void cGUIVarInt::incrementForProperty() {
    DDON_STUB("cGUIVarInt::incrementForProperty")
    /* stub */
}

__attribute__((weak)) void cGUIVarInt::decrementForProperty() {
    DDON_STUB("cGUIVarInt::decrementForProperty")
    /* stub */
}

inline cGUIVarInt::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGUIVarInt::MyDTI cGUIVarInt::DTI("cGUIVarInt", &::cGUIVariable::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* cGUIVarInt::MyDTI::newInstance() const {
    DDON_STUB("cGUIVarInt::MyDTI::newInstance")
    return nullptr;
}

cGUIVariable::~cGUIVariable() {
}

__attribute__((weak)) void cGUIVariable::createEventProperty(MtPropertyList& s) {
}

const MT_CTSTR* cGUIVariable::getEventPropertyTooltip() {
    return nullptr;
}

static auto ddon_emit_0x01b73790 __attribute__((used)) = &cGUIVariable::setLoopValue;

bool cGUIVariable::isLoopValue() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 12)) & 2) >> 1);
}

inline cGUIVariable::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGUIVariable::MyDTI cGUIVariable::DTI("cGUIVariable", &::MtObject::DTI, 24ul, 0u, 1u);

MtObject* cGUIVariable::MyDTI::newInstance() const {
    return nullptr;
}

