// Reconstructed from the game's DWARF debug information.
#include <new>
#include "rSoundDirectionalCurve.h"
#include "../MT/MtCollection.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtSerializer.h"
#include "cResource.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

__attribute__((weak)) void rSoundDirectionalCurveXml::usage() {
}

const MtDTI& rSoundDirectionalCurveXml::getDTI() const {
    return rSoundDirectionalCurveXml::DTI;
}

rSoundDirectionalCurveXml::rSoundDirectionalCurveXml() {
    DDON_STUB("rSoundDirectionalCurveXml::rSoundDirectionalCurveXml")
    /* stub */
}

rSoundDirectionalCurveXml::~rSoundDirectionalCurveXml() {
    DDON_STUB("rSoundDirectionalCurveXml::~rSoundDirectionalCurveXml")
    /* stub */
}

void rSoundDirectionalCurveXml::createProperty(MtPropertyList& s) {
    this->cResource::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), "mCurves", static_cast<MtObject*>(&mCurves), 0u, 0u);
}

MtUI* rSoundDirectionalCurveXml::createUI(MtProperty& prop) {
    return this->cResource::createUI(prop);
}

bool rSoundDirectionalCurveXml::load(MtStream& in) {
    MtSerializer sz(65536);
    return sz.deserializeXML(in, "SoundDirectionalCurve", static_cast<MtObject*>(this), MtSerializer::MODE_STATE, MtSerializer::ENCODING_AUTO) != nullptr;
}

bool rSoundDirectionalCurveXml::save(MtStream& out) {
    MtSerializer sz(65536);
    return sz.serializeXML(out, "SoundDirectionalCurve", static_cast<MtObject*>(this), MtSerializer::MODE_STATE, MtSerializer::ENCODING_AUTO);
}

MT_CTSTR rSoundDirectionalCurveXml::getExt() const {
    return "sdcr.xml";
}

__attribute__((weak)) void rSoundDirectionalCurveXml::clear() {
    DDON_STUB("rSoundDirectionalCurveXml::clear")
    /* stub */
}

inline rSoundDirectionalCurveXml::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundDirectionalCurveXml::MyDTI rSoundDirectionalCurveXml::DTI("rSoundDirectionalCurveXml", &::cResource::DTI, 152ul, 0u, 0u);

__attribute__((weak)) MtObject* rSoundDirectionalCurveXml::MyDTI::newInstance() const {
    DDON_STUB("rSoundDirectionalCurveXml::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& rSoundDirectionalCurveXml::Curve::getDTI() const {
    return rSoundDirectionalCurveXml::Curve::DTI;
}

rSoundDirectionalCurveXml::Curve::~Curve() {
    DDON_STUB("rSoundDirectionalCurveXml::Curve::~Curve")
    /* stub */
}

void rSoundDirectionalCurveXml::Curve::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mEnable", &mEnable, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mZeroRadianValue", &mZeroRadianValue, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mPiRadianValue", &mPiRadianValue, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mElements", static_cast<MtObject*>(&mElements), 0u, 0u);
}

inline rSoundDirectionalCurveXml::Curve::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundDirectionalCurveXml::Curve::MyDTI rSoundDirectionalCurveXml::Curve::DTI("rSoundDirectionalCurveXml::Curve", &::MtObject::DTI, 56ul, 0u, 0u);

__attribute__((weak)) MtObject* rSoundDirectionalCurveXml::Curve::MyDTI::newInstance() const {
    DDON_STUB("rSoundDirectionalCurveXml::Curve::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& rSoundDirectionalCurveXml::Element::getDTI() const {
    return rSoundDirectionalCurveXml::Element::DTI;
}

rSoundDirectionalCurveXml::Element::~Element() {
}

void rSoundDirectionalCurveXml::Element::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mAngle", &mAngle, 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), "mValue", &mValue, 0u, 0u);
}

inline rSoundDirectionalCurveXml::Element::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

rSoundDirectionalCurveXml::Element::MyDTI rSoundDirectionalCurveXml::Element::DTI("rSoundDirectionalCurveXml::Element", &::MtObject::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* rSoundDirectionalCurveXml::Element::MyDTI::newInstance() const {
    DDON_STUB("rSoundDirectionalCurveXml::Element::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<rSoundDirectionalCurveXml::Curve>::~MtTypedArray();

template MtTypedArray<rSoundDirectionalCurveXml::Element>::~MtTypedArray();

