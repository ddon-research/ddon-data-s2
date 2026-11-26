// Reconstructed from the game's DWARF debug information.
#include <new>
#include "cGUIObject.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtColor.h"
#include "../MT/MtDTI.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive2D.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "cDraw.h"
#include "cGUIInstance.h"
#include "cGUIMessageAnalyzer.h"
#include "nDrawResource.h"
#include "nGUI.h"
#include "nGUIDraw.h"
#include "rGUI.h"
#include "rGUIMessage.h"
#include "sGUI.h"
#include "uGUI.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

const MtDTI& cGUIObj2D::getDTI() const {
    return cGUIObj2D::DTI;
}

inline void cGUIObj2D::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cGUIObj2D::DTI)->memFree(p_addr);
}

cGUIObj2D::cGUIObj2D() {
    DDON_STUB("cGUIObj2D::cGUIObj2D")
    /* stub */
}

cGUIObj2D::~cGUIObj2D() {
    DDON_STUB("cGUIObj2D::~cGUIObj2D")
    /* stub */
}

MtUI* cGUIObj2D::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void cGUIObj2D::createProperty(MtPropertyList& s) {
    this->cGUIObject::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "ControlPoint", reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::getControlPoint), reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::setControlPoint), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "ReferencePosition", reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::isReferencePosition), reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::setReferencePosition), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "ReferenceRotation", reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::isReferenceRotation), reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::setReferenceRotation), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "ReferenceScaleX", reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::getReferenceScaleX), reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::setReferenceScaleX), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "ReferenceScaleY", reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::getReferenceScaleY), reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::setReferenceScaleY), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "ReferenceScaleZ", reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::getReferenceScaleZ), reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::setReferenceScaleZ), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "PosX", reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::getPositionX), reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::setPositionX), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "PosY", reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::getPositionY), reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::setPositionY), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "PosZ", reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::getPositionZ), reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::setPositionZ), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "RotationX", reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::getRotationX), reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::setRotationX), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "RotationY", reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::getRotationY), reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::setRotationY), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "RotationZ", reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::getRotationZ), reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::setRotationZ), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "Rotation", reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::getRotationZ), reinterpret_cast<MT_MFUNC>(&::cGUIObj2D::setRotationZ), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

__attribute__((weak)) void cGUIObj2D::setPosition(const MtVector4& pos) {
    DDON_STUB("cGUIObj2D::setPosition")
    /* stub */
}

void cGUIObj2D::setPositionX(f32 v) {
    if (mPosition.x == v) {
        return;
    }
    mPosition.x = v;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86)) | 2;
}

static auto ddon_emit_0x01b72740 __attribute__((used)) = &cGUIObj2D::getPositionX;

void cGUIObj2D::setPositionY(f32 v) {
    if (mPosition.y == v) {
        return;
    }
    mPosition.y = v;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86)) | 2;
}

static auto ddon_emit_0x01b72750 __attribute__((used)) = &cGUIObj2D::getPositionY;

void cGUIObj2D::setPositionZ(f32 v) {
    if (mPosition.z == v) {
        return;
    }
    mPosition.z = v;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86)) | 2;
}

static auto ddon_emit_0x01b72760 __attribute__((used)) = &cGUIObj2D::getPositionZ;

void cGUIObj2D::setRotationX(f32 v) {
    if (mRotation.x == (0.017453294f * v)) {
        return;
    }
    mRotation.x = 0.017453294f * v;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86)) | 2;
}

__attribute__((weak)) f32 cGUIObj2D::getRotationX() const {
    DDON_STUB("cGUIObj2D::getRotationX")
    return {};
}

void cGUIObj2D::setRotationY(f32 v) {
    if (mRotation.y == (0.017453294f * v)) {
        return;
    }
    mRotation.y = 0.017453294f * v;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86)) | 2;
}

__attribute__((weak)) f32 cGUIObj2D::getRotationY() const {
    DDON_STUB("cGUIObj2D::getRotationY")
    return {};
}

void cGUIObj2D::setRotationZ(f32 v) {
    if (mRotation.z == (0.017453294f * v)) {
        return;
    }
    mRotation.z = 0.017453294f * v;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86)) | 2;
}

__attribute__((weak)) f32 cGUIObj2D::getRotationZ() const {
    DDON_STUB("cGUIObj2D::getRotationZ")
    return {};
}

void cGUIObj2D::setControlPoint(u32 cp) {
    if (mControlPoint != cp) {
        mControlPoint = cp;
        setUpdateDraw();
    }
}

static auto ddon_emit_0x01b726e0 __attribute__((used)) = &cGUIObj2D::getControlPoint;

__attribute__((weak)) void cGUIObj2D::setReferencePosition(bool v) {
    DDON_STUB("cGUIObj2D::setReferencePosition")
    /* stub */
}

static auto ddon_emit_0x01b726f0 __attribute__((used)) = &cGUIObj2D::isReferencePosition;

__attribute__((weak)) void cGUIObj2D::setReferenceRotation(bool v) {
    DDON_STUB("cGUIObj2D::setReferenceRotation")
    /* stub */
}

static auto ddon_emit_0x01b72700 __attribute__((used)) = &cGUIObj2D::isReferenceRotation;

void cGUIObj2D::setReferenceScaleX(u32 type) {
    if (mReferenceScaleX == type) {
        return;
    }
    mReferenceScaleX = type;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86)) | 2;
}

static auto ddon_emit_0x01b72710 __attribute__((used)) = &cGUIObj2D::getReferenceScaleX;

void cGUIObj2D::setReferenceScaleY(u32 type) {
    if (mReferenceScaleY == type) {
        return;
    }
    mReferenceScaleY = type;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86)) | 2;
}

static auto ddon_emit_0x01b72720 __attribute__((used)) = &cGUIObj2D::getReferenceScaleY;

void cGUIObj2D::setReferenceScaleZ(u32 type) {
    if (mReferenceScaleZ == type) {
        return;
    }
    mReferenceScaleZ = type;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86)) | 2;
}

static auto ddon_emit_0x01b72730 __attribute__((used)) = &cGUIObj2D::getReferenceScaleZ;

__attribute__((weak)) void cGUIObj2D::getRectFromSize(MtRectF& rect, const MtFloat2& size) const {
    DDON_STUB("cGUIObj2D::getRectFromSize")
    /* stub */
}

__attribute__((weak)) void cGUIObj2D::calcMatrix(const MtMatrix& wmat) {
    DDON_STUB("cGUIObj2D::calcMatrix")
    /* stub */
}

__attribute__((weak)) void cGUIObj2D::calcBoundingPosition(MtVector3* pPosition, const MtFloat2& size, f32 ratio) const {
    DDON_STUB("cGUIObj2D::calcBoundingPosition")
    /* stub */
}

inline cGUIObj2D::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGUIObj2D::MyDTI cGUIObj2D::DTI("cGUIObj2D", &::cGUIObject::DTI, 208ul, 0u, 1u);

MtObject* cGUIObj2D::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& cGUIObjChildAnimationRoot::getDTI() const {
    return cGUIObjChildAnimationRoot::DTI;
}

void* cGUIObjChildAnimationRoot::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

cGUIObjChildAnimationRoot::cGUIObjChildAnimationRoot() {
    DDON_STUB("cGUIObjChildAnimationRoot::cGUIObjChildAnimationRoot")
    /* stub */
}

cGUIObjChildAnimationRoot::~cGUIObjChildAnimationRoot() {
    DDON_STUB("cGUIObjChildAnimationRoot::~cGUIObjChildAnimationRoot")
    /* stub */
}

MtUI* cGUIObjChildAnimationRoot::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void cGUIObjChildAnimationRoot::createProperty(MtPropertyList& s) {
    this->cGUIObjNull::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "ChildAnimPlay", reinterpret_cast<MT_MFUNC>(&::cGUIObjChildAnimationRoot::isChildAnimationPlay), reinterpret_cast<MT_MFUNC>(&::cGUIObjChildAnimationRoot::setChildAnimationPlay), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), "ChildAnimFrame", reinterpret_cast<MT_MFUNC32>(&::cGUIObjChildAnimationRoot::setChildAnimationCurrentFrameForProperty), 0u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "ChildSequenceId", reinterpret_cast<MT_MFUNC>(&::cGUIObjChildAnimationRoot::getChildSequenceId), reinterpret_cast<MT_MFUNC>(&::cGUIObjChildAnimationRoot::setChildSequenceId), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

bool cGUIObjChildAnimationRoot::isDrawableStatic() const {
    return true;
}

void cGUIObjChildAnimationRoot::setChildSequenceId(u32 id) {
    mSequenceId = id;
    if (mpChildRoot == nullptr) {
        return;
    }
    if (mpChildRoot->mpPlayingSequence != nullptr) {
        if (mpChildRoot->mpPlayingSequence->id != id) {
            mChildAnimCurrentFrame = 0.0f;
            mpChildRoot->setSequenceId(id);
        }
    } else {
        if (id != 0xFFFFFFFFu) {
            mChildAnimCurrentFrame = 0.0f;
            mpChildRoot->setSequenceId(id);
        }
    }
}

u32 cGUIObjChildAnimationRoot::getChildSequenceId() const {
    if (mpChildRoot != nullptr) {
        if (mpChildRoot->mpPlayingSequence != nullptr) {
            return mpChildRoot->mpPlayingSequence->id;
        } else {
            return 0xFFFFFFFF;
        }
    } else {
        return mSequenceId;
    }
}

void cGUIObjChildAnimationRoot::setChildAnimationCurrentFrameForProperty(s32 frame) {
    if (mpChildRoot == nullptr) {
        return;
    }
    mChildAnimCurrentFrame = static_cast<float>(frame);
    setChildAnimationCurrentFrame2(static_cast<cGUIObject*>(mpChildRoot), static_cast<float>(frame));
}

void cGUIObjChildAnimationRoot::setChildAnimationCurrentFrame(f32 frame) {
    if (mpChildRoot == nullptr) {
        return;
    }
    mChildAnimCurrentFrame = frame;
    setChildAnimationCurrentFrame2(static_cast<cGUIObject*>(mpChildRoot), frame);
}

static auto ddon_emit_0x01b72880 __attribute__((used)) = &cGUIObjChildAnimationRoot::setChildAnimationPlay;

static auto ddon_emit_0x01b72870 __attribute__((used)) = &cGUIObjChildAnimationRoot::isChildAnimationPlay;

MtAABB cGUIObjChildAnimationRoot::calcBoundingBox() const {
    if (mpChildRoot != nullptr) {
        return mpChildRoot->getBoundingBox3D();
    } else {
        return MtAABB::Zero;
    }
}

bool cGUIObjChildAnimationRoot::isChildAnimationEnd() const {
    if (mpChildRoot != nullptr) {
        if (mpChildRoot->mpPlayingSequence != nullptr) {
            return mChildAnimCurrentFrame >= static_cast<float>(mpChildRoot->mpPlayingSequence->frameCount);
        } else {
            return mChildAnimCurrentFrame >= 0.0f;
        }
    } else {
        return true;
    }
}

void cGUIObjChildAnimationRoot::init() {
    if (mpChildRoot != nullptr) {
        mChildAnimCurrentFrame = 0.0f;
        mpChildRoot->msgInit();
    }
    mCurrentFrame = -1.0f;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86)) | 2;
}

void cGUIObjChildAnimationRoot::initProperty() {
    if (mpChildRoot != nullptr) {
        mpChildRoot->initProperty();
    }
    if (mpObjectInfo->initParamNum == 0) {
        if (mpParent != nullptr) {
            mpParent->mAttr = mpParent->mAttr | 0x80000u;
        }
        return;
    }
    unsigned int i3 = 0;
    nGUI::INIT_PARAM* p8 = mpObjectInfo->pInitParam;
    do {
        nGUI::initProperty(static_cast<MtObject*>(this), p8);
        i3 += 1u;
        p8 += static_cast<int>(1);
    } while (i3 < mpObjectInfo->initParamNum);
    if (mpParent != nullptr) {
        mpParent->mAttr = mpParent->mAttr | 0x80000u;
    }
}

void cGUIObjChildAnimationRoot::play(f32 delta) {
    cGUIObjRoot* j0;
    cGUIObjRoot* t0 = mpChildRoot;
    if (t0 == nullptr) {
        return;
    }
    if ((mChildAnimPlay & 1u) != 0) {
        mChildAnimCurrentFrame = mChildAnimCurrentFrame + delta;
        t0->msgPlay(delta, false);
        j0 = mpChildRoot;
    } else {
        j0 = t0;
    }
    mAttr = (((j0->mRootAttr & 2u) | (mAttr & 0x20000u)) == 0) ? (mAttr & 0xFFFDFFFFu) : (mAttr | 0x20000u);
}

void cGUIObjChildAnimationRoot::draw(nGUI::Draw& drawObj) {
    if (mpChildRoot == nullptr) {
        return;
    }
    mpChildRoot->msgDraw(drawObj);
}

void cGUIObjChildAnimationRoot::calcMatrix(const MtMatrix& wmat) {
    this->cGUIObjNull::calcMatrix(wmat);
    if (mpChildRoot == nullptr) {
        return;
    }
    mpChildRoot->msgCalcMatrix(mMat, static_cast<bool>((mAttr & 0x20000u) >> 17));
}

bool cGUIObjChildAnimationRoot::checkHit(const MtVector3& pt, f32 ratio, const MtRay* const pRay) const {
    if (mpChildRoot != nullptr) {
        return mpChildRoot->msgCheckHit(pt, ratio, pRay) != 0xFFFFFFFFu;
    } else {
        return false;
    }
}

__attribute__((weak)) void cGUIObjChildAnimationRoot::setParentResolutionAdjust(u32 type) {
    DDON_STUB("cGUIObjChildAnimationRoot::setParentResolutionAdjust")
    /* stub */
}

__attribute__((weak)) void cGUIObjChildAnimationRoot::setChildAnimationCurrentFrame2(cGUIObject* pObject, f32 frame) {
    pObject->setCurrentFrame(frame, true);
    for (cGUIObject* pChild = pObject->mpChild;;) {
        if (pChild == nullptr) {
            break;
        } else {
            setChildAnimationCurrentFrame2(pChild, frame);
            pChild = pChild->mpNext;
        }
    }
}

__attribute__((weak)) void cGUIObjChildAnimationRoot::setExtendData(void* pData) {
    DDON_STUB("cGUIObjChildAnimationRoot::setExtendData")
    /* stub */
}

inline cGUIObjChildAnimationRoot::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGUIObjChildAnimationRoot::MyDTI cGUIObjChildAnimationRoot::DTI("cGUIObjChildAnimationRoot", &::cGUIObjNull::DTI, 256ul, 0u, 2u);

__attribute__((weak)) MtObject* cGUIObjChildAnimationRoot::MyDTI::newInstance() const {
    DDON_STUB("cGUIObjChildAnimationRoot::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cGUIObjColorAdjust::getDTI() const {
    return cGUIObjColorAdjust::DTI;
}

void* cGUIObjColorAdjust::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void cGUIObjColorAdjust::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cGUIObjColorAdjust::DTI)->memFree(p_addr);
}

cGUIObjColorAdjust::cGUIObjColorAdjust() {
    DDON_STUB("cGUIObjColorAdjust::cGUIObjColorAdjust")
    /* stub */
}

cGUIObjColorAdjust::~cGUIObjColorAdjust() {
}

MtUI* cGUIObjColorAdjust::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void cGUIObjColorAdjust::createProperty(MtPropertyList& s) {
    this->cGUIObject::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "ColorControl", reinterpret_cast<MT_MFUNC>(&::cGUIObjColorAdjust::getColorControl), reinterpret_cast<MT_MFUNC>(&::cGUIObjColorAdjust::setColorControl), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_VECTOR4, "ColorScale", reinterpret_cast<MT_MFUNC>(&::cGUIObjColorAdjust::getColorScale), reinterpret_cast<MT_MFUNC>(&::cGUIObjColorAdjust::setColorScale), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_COLOR, "AmbientColor", reinterpret_cast<MT_MFUNC>(&::cGUIObjColorAdjust::getAmbientColor), reinterpret_cast<MT_MFUNC>(&::cGUIObjColorAdjust::setAmbientColor), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "Saturation", reinterpret_cast<MT_MFUNC>(&::cGUIObjColorAdjust::getSaturation), reinterpret_cast<MT_MFUNC>(&::cGUIObjColorAdjust::setSaturation), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

bool cGUIObjColorAdjust::isDrawableStatic() const {
    return true;
}

void cGUIObjColorAdjust::setColorControl(u32 type) {
    if (mColorControl == type) {
        return;
    }
    mColorControl = type;
}

static auto ddon_emit_0x01b72670 __attribute__((used)) = &cGUIObjColorAdjust::getColorControl;

__attribute__((weak)) void cGUIObjColorAdjust::setColorScale(const MtVector4& color) {
    DDON_STUB("cGUIObjColorAdjust::setColorScale")
    /* stub */
}

static auto ddon_emit_0x01b72680 __attribute__((used)) = &cGUIObjColorAdjust::getColorScale;

void cGUIObjColorAdjust::setAmbientColor(const MtColor& color) {
    mAmbientColor.rgba = color.rgba;
}

MtColor cGUIObjColorAdjust::getAmbientColor() const {
    MtColor result;
    result.rgba = mAmbientColor.rgba;
    return result;
}

static auto ddon_emit_0x01b726c0 __attribute__((used)) = &cGUIObjColorAdjust::setSaturation;

static auto ddon_emit_0x01b726b0 __attribute__((used)) = &cGUIObjColorAdjust::getSaturation;

__attribute__((weak)) void cGUIObjColorAdjust::beginDraw(nGUI::Draw& drawObj) {
    DDON_STUB("cGUIObjColorAdjust::beginDraw")
    /* stub */
}

void cGUIObjColorAdjust::endDraw(nGUI::Draw& drawObj) {
    if ((mColorControl & 15u) == 1) {
        drawObj.setColorAttribute(false, 0.0f);
    } else {
        if ((mColorControl & 15u) == 0) {
            drawObj.popColorConstantBuffer();
        }
    }
}

inline cGUIObjColorAdjust::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGUIObjColorAdjust::MyDTI cGUIObjColorAdjust::DTI("cGUIObjColorAdjust", &::cGUIObject::DTI, 192ul, 0u, 0u);

__attribute__((weak)) MtObject* cGUIObjColorAdjust::MyDTI::newInstance() const {
    DDON_STUB("cGUIObjColorAdjust::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cGUIObjMessage::getDTI() const {
    return cGUIObjMessage::DTI;
}

void* cGUIObjMessage::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void cGUIObjMessage::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cGUIObjMessage::DTI)->memFree(p_addr);
}

cGUIObjMessage::cGUIObjMessage() {
    DDON_STUB("cGUIObjMessage::cGUIObjMessage")
    /* stub */
}

__attribute__((noinline)) cGUIObjMessage::~cGUIObjMessage() {
    DDON_STUB("cGUIObjMessage::~cGUIObjMessage")
    /* stub */
}

MtUI* cGUIObjMessage::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void cGUIObjMessage::createProperty(MtPropertyList& s) {
    DDON_STUB("cGUIObjMessage::createProperty")
    /* stub */
}

bool cGUIObjMessage::isDrawableStatic() const {
    return true;
}

__attribute__((weak)) void cGUIObjMessage::setAutoWrap(u32 wrapMode) {
    DDON_STUB("cGUIObjMessage::setAutoWrap")
    /* stub */
}

static auto ddon_emit_0x01b72f00 __attribute__((used)) = &cGUIObjMessage::getAutoWrap;

void cGUIObjMessage::setAutoScale(bool e) {
    mMsgAttr = !e ? (mMsgAttr & 0xFFFFFFFEu) : (mMsgAttr | 1u);
}

bool cGUIObjMessage::isAutoScale() const {
    return static_cast<bool>(mMsgAttr & 1u);
}

void cGUIObjMessage::setMonospace(bool e) {
    mMsgAttr = !e ? (mMsgAttr & 0xFFFFFFFDu) : (mMsgAttr | 2u);
}

bool cGUIObjMessage::isMonospace() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 296)) & 2) >> 1);
}

void cGUIObjMessage::setUseRuby(bool e) {
    mMsgAttr = !e ? (mMsgAttr & 0xFFFFFFFBu) : (mMsgAttr | 4u);
}

bool cGUIObjMessage::isUseRuby() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 296)) & 4) >> 2);
}

void cGUIObjMessage::setFontSlot(u32 slot) {
    mFontSlot = slot;
}

static auto ddon_emit_0x01b72e80 __attribute__((used)) = &cGUIObjMessage::getFontSlot;

static auto ddon_emit_0x01b72ea0 __attribute__((used)) = &cGUIObjMessage::setFontFilter0;

static auto ddon_emit_0x01b72e90 __attribute__((used)) = &cGUIObjMessage::getFontFilter0;

static auto ddon_emit_0x01b72ed0 __attribute__((used)) = &cGUIObjMessage::setFontFilter1;

static auto ddon_emit_0x01b72ec0 __attribute__((used)) = &cGUIObjMessage::getFontFilter1;

void cGUIObjMessage::setLayout(u32 layout) {
    mLayout = layout;
}

static auto ddon_emit_0x01b72f60 __attribute__((used)) = &cGUIObjMessage::getLayout;

__attribute__((weak)) void cGUIObjMessage::setLetterHAlign(u32 letterHAlign) {
    DDON_STUB("cGUIObjMessage::setLetterHAlign")
    /* stub */
}

static auto ddon_emit_0x01b72f70 __attribute__((used)) = &cGUIObjMessage::getLetterHAlign;

__attribute__((weak)) void cGUIObjMessage::setLetterVAlign(u32 letterVAlign) {
    DDON_STUB("cGUIObjMessage::setLetterVAlign")
    /* stub */
}

static auto ddon_emit_0x01b72f80 __attribute__((used)) = &cGUIObjMessage::getLetterVAlign;

void cGUIObjMessage::setLineSpace(s32 space) {
    mLineSpace = space;
}

s32 cGUIObjMessage::getLineSpace() const {
    return static_cast<short>(*reinterpret_cast<const unsigned short*>(reinterpret_cast<const char*>(this) + 308));
}

void cGUIObjMessage::setLetterSpace(s32 space) {
    mLetterSpace = space;
}

s32 cGUIObjMessage::getLetterSpace() const {
    return static_cast<s32>(static_cast<unsigned int>(static_cast<long>(*reinterpret_cast<const unsigned long*>(reinterpret_cast<const char*>(this) + 304)) >> 48));
}

__attribute__((weak)) void cGUIObjMessage::setMessageId(u32 id) {
    DDON_STUB("cGUIObjMessage::setMessageId")
    /* stub */
}

static auto ddon_emit_0x01b72ff0 __attribute__((used)) = &cGUIObjMessage::getMessageId;

__attribute__((weak)) void cGUIObjMessage::setMessageIndexName(const MtString& name) {
    DDON_STUB("cGUIObjMessage::setMessageIndexName")
    /* stub */
}

static auto ddon_emit_0x01b73000 __attribute__((used)) = &cGUIObjMessage::getMessageIndexName;

void cGUIObjMessage::setFontSize(const MtSize& size) {
    if (size.wh == mFontSize.wh) {
        return;
    }
    mFontSize.w = static_cast<s32>(static_cast<unsigned int>(size.wh));
    mFontSize.h = size.h;
    mMsgAttr = mMsgAttr | 0x10000u;
}

MtSize cGUIObjMessage::getFontSize() const {
    MtSize result;
    result.wh = mFontSize.wh;
    return result;
}

__attribute__((weak)) void cGUIObjMessage::setSize(const MtFloat2& size) {
    DDON_STUB("cGUIObjMessage::setSize")
    /* stub */
}

static auto ddon_emit_0x01b72fe0 __attribute__((used)) = &cGUIObjMessage::getSize;

void cGUIObjMessage::setColor(const MtColor& color) {
    if (color.rgba != mColor.rgba) {
        mColor.rgba = color.rgba;
        setUpdateDraw();
    }
}

MtColor cGUIObjMessage::getColor() const {
    MtColor result;
    result.rgba = mColor.rgba;
    return result;
}

__attribute__((weak)) void cGUIObjMessage::setAlpha(u8 alpha) {
    DDON_STUB("cGUIObjMessage::setAlpha")
    /* stub */
}

u8 cGUIObjMessage::getAlpha() const {
    return *reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 231);
}

void cGUIObjMessage::setRGB(const MtColor& rgb) {
    u32 t0 = mColor.rgba;
    const u32 t1 = rgb.rgba;
    if (((t0 ^ t1) & 0xFFFFFFu) == 0) {
        return;
    }
    mColor.rgba = static_cast<u32>(static_cast<unsigned long>(t0 & 0xFFFFFF00u) | static_cast<unsigned long>(static_cast<unsigned char>(t1)));
    const u32 t2 = rgb.rgba;
    mColor.rgba = static_cast<u32>(static_cast<unsigned long>(t2 & 0xFF00u) | ((static_cast<unsigned long>(t0 & 0xFFFFFF00u) | static_cast<unsigned long>(static_cast<unsigned char>(t1))) & 0xFFFF00FFul));
    mColor.rgba = static_cast<u32>(static_cast<unsigned long>(rgb.rgba & 0xFF0000u) | ((static_cast<unsigned long>(t2 & 0xFF00u) | ((static_cast<unsigned long>(t0 & 0xFFFFFF00u) | static_cast<unsigned long>(static_cast<unsigned char>(t1))) & 0xFFFF00FFul)) & 0xFF00FFFFul));
    setUpdateDraw();
}

MtColor cGUIObjMessage::getRGB() const {
    MtColor result;
    result.rgba = mColor.rgba;
    return result;
}

__attribute__((weak)) void cGUIObjMessage::setSamplerState(u32 state) {
    DDON_STUB("cGUIObjMessage::setSamplerState")
    /* stub */
}

static auto ddon_emit_0x01b72ef0 __attribute__((used)) = &cGUIObjMessage::getSamplerState;

__attribute__((weak)) void cGUIObjMessage::setIconColorType(u32 type) {
    DDON_STUB("cGUIObjMessage::setIconColorType")
    /* stub */
}

__attribute__((weak)) u32 cGUIObjMessage::getIconColorType() const {
    DDON_STUB("cGUIObjMessage::getIconColorType")
    return {};
}

__attribute__((weak)) void cGUIObjMessage::setResolutionAdjust(u32 type) {
    DDON_STUB("cGUIObjMessage::setResolutionAdjust")
    /* stub */
}

static auto ddon_emit_0x01b72e40 __attribute__((used)) = &cGUIObjMessage::getResolutionAdjust;

u32 cGUIObjMessage::getValidResolutionAdjust() const {
    if (mResolutionAdjust == 0) {
        return mParentResolutionAdjust;
    } else {
        return mResolutionAdjust;
    }
}

void cGUIObjMessage::setMessage(MT_CTSTR msg, u32 length) {
    analyzeMessage(msg, length, -1);
}

void cGUIObjMessage::setGenderMessage(MT_CTSTR msg, nGUI::GENDER speakerGender, nGUI::GENDER listenerGender, u32 length) {
    analyzeGenderMessage(msg, speakerGender, listenerGender, length);
}

void cGUIObjMessage::setDrawChar(bool v, u32 start, u32 end) {
    setUpdateDraw();
    nGUI::MTAG* pMTagTop = getDrawStartMTag();
    nGUI::MTAG* pMTag = cGUIMessageAnalyzer::getCharMTAG(pMTagTop, start, true);
    for (u32 v0_3 = start;;) {
        if (pMTag == nullptr) {
            break;
        } else {
            if (static_cast<unsigned char>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pMTag) + 0)) != 11) {
                if (static_cast<unsigned int>(static_cast<unsigned char>(*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pMTag) + 0)) - 4) <= 1) {
                    if (v0_3 >= ((start < end) ? end : 0xFFFFFFFFu)) {
                        break;
                    } else {
                        *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pMTag) + 0) = !v ? ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pMTag) + 0)) & 0xFFFFFDFFu) : ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(pMTag) + 0)) | 512u);
                        pMTag = pMTag->pNext;
                        v0_3 += 1u;
                    }
                } else {
                    pMTag = pMTag->pNext;
                }
            } else {
                if (pMTag != pMTagTop) {
                    break;
                } else {
                    pMTag = pMTag->pNext;
                }
            }
        }
    }
}

rGUIFont* cGUIObjMessage::getFont(u32 index) const {
    rGUI* pResource = mpResource;
    if (pResource != nullptr) {
        if (((sGUI::mpInstance)->mAttr & 2u) != 0) {
            return (sGUI::mpInstance)->sGUI::getFont(index);
        } else {
            nGUI::FONT* pFONT = pResource->getFontFromId(index);
            if (pFONT != nullptr) {
                return pFONT->pFont;
            } else {
                return nullptr;
            }
        }
    } else {
        return (sGUI::mpInstance)->sGUI::getFont(index);
    }
}

u32 cGUIObjMessage::getLineNum(u32 pageIndex) const {
    nGUI::MTAG* pMTag = cGUIMessageAnalyzer::getPage(mpMTag, pageIndex);
    unsigned int v1_0;
    if (pMTag != nullptr) {
        unsigned int i0_0 = 0;
        for (nGUI::MTAG* v0_1 = pMTag;;) {
            if (v0_1->pNext == nullptr) {
                v1_0 = i0_0;
                break;
            } else {
                if (v0_1->pNext->type == 11) {
                    v1_0 = i0_0;
                    break;
                } else {
                    if (v0_1->pNext->type == 21) {
                        i0_0 += 1u;
                    }
                    v0_1 = v0_1->pNext;
                }
            }
        }
    } else {
        v1_0 = 0;
    }
    return v1_0;
}

f32 cGUIObjMessage::getLineHeight(u32 lineIndex, u32 pageIndex) const {
    nGUI::MTAG* pMTag = cGUIMessageAnalyzer::getPage(mpMTag, pageIndex);
    f32 v1_9;
    if (pMTag == nullptr) {
        v1_9 = 0.0f;
    } else {
        float v0_9 = -1.0f;
        nGUI::MTAG* v0_0 = pMTag;
        for (unsigned int i0_1 = 0;;) {
            if (v0_0->pNext == nullptr) {
                v1_9 = v0_9;
                break;
            } else {
                if (v0_0->pNext->type == 11) {
                    v1_9 = v0_9;
                    break;
                } else {
                    if (v0_0->pNext->type != 21) {
                        v0_0 = v0_0->pNext;
                    } else {
                        if (lineIndex != i0_1) {
                            v0_0 = v0_0->pNext;
                            i0_1 += 1u;
                        } else {
                            v1_9 = v0_0->pNext->height;
                            break;
                        }
                    }
                }
            }
        }
    }
    return v1_9;
}

u32 cGUIObjMessage::getLineCharCount(u32 lineIndex, u32 pageIndex, bool countIcon) const {
    return cGUIMessageAnalyzer::getLineCharCount(mpMTag, lineIndex, pageIndex, countIcon);
}

__attribute__((weak)) MtFloat2 cGUIObjMessage::getCharPos(u32 charIndex, u32 lineIndex, u32 pageIndex, bool countIcon) const {
    DDON_STUB("cGUIObjMessage::getCharPos")
    __builtin_unreachable();
}

MtSizeF cGUIObjMessage::getCharSize(u32 charIndex, u32 lineIndex, u32 pageIndex, bool countIcon) const {
    return cGUIMessageAnalyzer::getCharSize(mpMTag, charIndex, lineIndex, pageIndex, countIcon);
}

__attribute__((weak)) MtAABB cGUIObjMessage::calcBoundingBox() const {
    DDON_STUB("cGUIObjMessage::calcBoundingBox")
    __builtin_unreachable();
}

void cGUIObjMessage::play(f32 delta) {
    if ((mMsgAttr & 0x10000u) == 0) {
        return;
    }
    recalcFontSize();
    mMsgAttr = mMsgAttr & 0xFFFEFFFFu;
}

__attribute__((weak)) void cGUIObjMessage::draw(nGUI::Draw& drawObj) {
    DDON_STUB("cGUIObjMessage::draw")
    /* stub */
}

__attribute__((weak)) bool cGUIObjMessage::checkHit(const MtVector3& pt, f32 ratio, const MtRay* const pRay) const {
    DDON_STUB("cGUIObjMessage::checkHit")
    return {};
}

void cGUIObjMessage::invisible() {
    if ((mAttr & 32u) == 0) {
        return;
    }
    clearMessage();
}

__attribute__((weak)) void cGUIObjMessage::analyzeMessage(MT_CTSTR msg, u32 length, s32 pageIndex) {
    DDON_STUB("cGUIObjMessage::analyzeMessage")
    /* stub */
}

__attribute__((weak)) void cGUIObjMessage::analyzeGenderMessage(MT_CTSTR msg, nGUI::GENDER speakerGender, nGUI::GENDER listenerGender, u32 length) {
    DDON_STUB("cGUIObjMessage::analyzeGenderMessage")
    /* stub */
}

__attribute__((weak)) void cGUIObjMessage::clearMessage() {
    DDON_STUB("cGUIObjMessage::clearMessage")
    /* stub */
}

void cGUIObjMessage::clearDrawMTag() {
    (sGUI::mpInstance)->sGUI::freeVertexBuffer(mVertexObject);
    (sGUI::mpInstance)->sGUI::freeIndexBuffer(mIndexObject);
    (sGUI::mpInstance)->sGUI::freeMTAGList(mpDrawMTag);
    (sGUI::mpInstance)->sGUI::freeVertexBuffer(mFFVertexObject[0]);
    (sGUI::mpInstance)->sGUI::freeIndexBuffer(mFFIndexObject[0]);
    (sGUI::mpInstance)->sGUI::freeMTAGList(mpFFDrawMTag[0]);
    (sGUI::mpInstance)->sGUI::freeVertexBuffer(mFFVertexObject[1]);
    (sGUI::mpInstance)->sGUI::freeIndexBuffer(mFFIndexObject[1]);
    (sGUI::mpInstance)->sGUI::freeMTAGList(mpFFDrawMTag[1]);
    mMsgAttr = mMsgAttr & 0xFFFDFFFFu;
}

void cGUIObjMessage::recalcFontSize() {
    if (mpMTag == nullptr) {
        return;
    }
    cGUIMessageAnalyzer analyzer(this, -1);
    analyzer.recalcFontSize(mpMTag);
    setUpdateDraw();
}

__attribute__((weak)) void cGUIObjMessage::setUpdateDraw() {
    DDON_STUB("cGUIObjMessage::setUpdateDraw")
    /* stub */
}

__attribute__((weak)) void cGUIObjMessage::checkFontFilter() {
    DDON_STUB("cGUIObjMessage::checkFontFilter")
    /* stub */
}

nGUI::MTAG* cGUIObjMessage::getDrawStartMTag() const {
    return mpMTag;
}

nGUI::MTAG* cGUIObjMessage::getDrawEndMTag() const {
    return nullptr;
}

bool cGUIObjMessage::isPageEnd() const {
    return false;
}

__attribute__((weak)) void cGUIObjMessage::createDrawMTagList(nGUI::MessageDrawState& state) {
    DDON_STUB("cGUIObjMessage::createDrawMTagList")
    /* stub */
}

__attribute__((weak)) void cGUIObjMessage::allocBuffer(nGUI::MessageDrawState& state) {
    DDON_STUB("cGUIObjMessage::allocBuffer")
    /* stub */
}

__attribute__((weak)) void cGUIObjMessage::updateDraw(nGUI::MessageDrawState& state) {
    DDON_STUB("cGUIObjMessage::updateDraw")
    /* stub */
}

__attribute__((weak)) void cGUIObjMessage::updateDrawMTagChar(nGUI::MessageDrawState& state, nGUI::MTAG* pMTag) {
    DDON_STUB("cGUIObjMessage::updateDrawMTagChar")
    /* stub */
}

__attribute__((weak)) void cGUIObjMessage::updateDrawMTagExtend(nGUI::MessageDrawState& state, nGUI::MTAG* pMTag) {
}

__attribute__((weak)) void cGUIObjMessage::executeDraw(nGUI::MessageDrawState& state, nGUI::Draw& drawObj) {
    DDON_STUB("cGUIObjMessage::executeDraw")
    /* stub */
}

__attribute__((weak)) void cGUIObjMessage::drawMTagExtend(nGUI::Draw& drawObj, nGUI::MTAG* pMTag) {
}

inline cGUIObjMessage::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGUIObjMessage::MyDTI cGUIObjMessage::DTI("cGUIObjMessage", &::cGUIObj2D::DTI, 464ul, 0u, 0u);

__attribute__((weak)) MtObject* cGUIObjMessage::MyDTI::newInstance() const {
    DDON_STUB("cGUIObjMessage::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cGUIObjNull::getDTI() const {
    return cGUIObjNull::DTI;
}

void* cGUIObjNull::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void cGUIObjNull::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cGUIObjNull::DTI)->memFree(p_addr);
}

cGUIObjNull::cGUIObjNull() {
    DDON_STUB("cGUIObjNull::cGUIObjNull")
    /* stub */
}

cGUIObjNull::~cGUIObjNull() {
    DDON_STUB("cGUIObjNull::~cGUIObjNull")
    /* stub */
}

MtUI* cGUIObjNull::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void cGUIObjNull::createProperty(MtPropertyList& s) {
    this->cGUIObj2D::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "SclX", reinterpret_cast<MT_MFUNC>(&::cGUIObjNull::getScaleX), reinterpret_cast<MT_MFUNC>(&::cGUIObjNull::setScaleX), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "SclY", reinterpret_cast<MT_MFUNC>(&::cGUIObjNull::getScaleY), reinterpret_cast<MT_MFUNC>(&::cGUIObjNull::setScaleY), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "SclZ", reinterpret_cast<MT_MFUNC>(&::cGUIObjNull::getScaleZ), reinterpret_cast<MT_MFUNC>(&::cGUIObjNull::setScaleZ), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

void cGUIObjNull::setScaleX(f32 v) {
    if (mScale.x == v) {
        return;
    }
    mScale.x = v;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86)) | 2;
}

static auto ddon_emit_0x01b72830 __attribute__((used)) = &cGUIObjNull::getScaleX;

void cGUIObjNull::setScaleY(f32 v) {
    if (mScale.y == v) {
        return;
    }
    mScale.y = v;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86)) | 2;
}

static auto ddon_emit_0x01b72840 __attribute__((used)) = &cGUIObjNull::getScaleY;

void cGUIObjNull::setScaleZ(f32 v) {
    if (mScale.z == v) {
        return;
    }
    mScale.z = v;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86)) | 2;
}

static auto ddon_emit_0x01b72850 __attribute__((used)) = &cGUIObjNull::getScaleZ;

__attribute__((weak)) void cGUIObjNull::calcMatrix(const MtMatrix& wmat) {
    DDON_STUB("cGUIObjNull::calcMatrix")
    /* stub */
}

inline cGUIObjNull::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGUIObjNull::MyDTI cGUIObjNull::DTI("cGUIObjNull", &::cGUIObj2D::DTI, 224ul, 0u, 0u);

__attribute__((weak)) MtObject* cGUIObjNull::MyDTI::newInstance() const {
    DDON_STUB("cGUIObjNull::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cGUIObjPolygon::getDTI() const {
    return cGUIObjPolygon::DTI;
}

void* cGUIObjPolygon::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

cGUIObjPolygon::cGUIObjPolygon() {
    DDON_STUB("cGUIObjPolygon::cGUIObjPolygon")
    /* stub */
}

cGUIObjPolygon::~cGUIObjPolygon() {
    DDON_STUB("cGUIObjPolygon::~cGUIObjPolygon")
    /* stub */
}

MtUI* cGUIObjPolygon::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void cGUIObjPolygon::createProperty(MtPropertyList& s) {
    this->cGUIObj2D::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "BlendState", reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::getBlendState), reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::setBlendState), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_FLOAT2, "Size", reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::getSize), reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::setSize), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Reverse", reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::isReverseClockwise), reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::setReverseClockwise), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "Mask", reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::getMaskType), reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::setMaskType), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_COLOR, "VertexColorLT", reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::getVertexColorLT), reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::setVertexColorLT), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_COLOR, "VertexColorRT", reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::getVertexColorRT), reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::setVertexColorRT), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_COLOR, "VertexColorLB", reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::getVertexColorLB), reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::setVertexColorLB), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_COLOR, "VertexColorRB", reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::getVertexColorRB), reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::setVertexColorRB), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_COLOR, "VertexColorUp", reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::getVertexColorUp), reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::setVertexColorUp), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_COLOR, "VertexColorDown", reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::getVertexColorDown), reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::setVertexColorDown), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_COLOR, "VertexColorLeft", reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::getVertexColorLeft), reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::setVertexColorLeft), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_COLOR, "VertexColorRight", reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::getVertexColorRight), reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::setVertexColorRight), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_COLOR, "VertexColor", reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::getVertexColor), reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::setVertexColor), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U8, "VertexAlpha", reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::getVertexAlpha), reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::setVertexAlpha), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_COLOR, "VertexRGB", reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::getVertexRGB), reinterpret_cast<MT_MFUNC>(&::cGUIObjPolygon::setVertexRGB), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

bool cGUIObjPolygon::isDrawableStatic() const {
    return true;
}

static auto ddon_emit_0x01b72970 __attribute__((used)) = &cGUIObjPolygon::setMaskType;

static auto ddon_emit_0x01b72960 __attribute__((used)) = &cGUIObjPolygon::getMaskType;

void cGUIObjPolygon::setVertexColorLT(const MtColor& color) {
    if (color.rgba != mColor[0].rgba) {
        mColor[0].rgba = color.rgba;
        updateColorState();
        setUpdateDraw();
    }
}

MtColor cGUIObjPolygon::getVertexColorLT() const {
    MtColor result;
    result.rgba = mColor[0].rgba;
    return result;
}

void cGUIObjPolygon::setVertexColorRT(const MtColor& color) {
    if (color.rgba != mColor[1].rgba) {
        mColor[1].rgba = color.rgba;
        updateColorState();
        setUpdateDraw();
    }
}

MtColor cGUIObjPolygon::getVertexColorRT() const {
    MtColor result;
    result.rgba = mColor[1].rgba;
    return result;
}

void cGUIObjPolygon::setVertexColorLB(const MtColor& color) {
    if (color.rgba != mColor[2].rgba) {
        mColor[2].rgba = color.rgba;
        updateColorState();
        setUpdateDraw();
    }
}

MtColor cGUIObjPolygon::getVertexColorLB() const {
    MtColor result;
    result.rgba = mColor[2].rgba;
    return result;
}

void cGUIObjPolygon::setVertexColorRB(const MtColor& color) {
    if (color.rgba != mColor[3].rgba) {
        mColor[3].rgba = color.rgba;
        updateColorState();
        setUpdateDraw();
    }
}

MtColor cGUIObjPolygon::getVertexColorRB() const {
    MtColor result;
    result.rgba = mColor[3].rgba;
    return result;
}

void cGUIObjPolygon::setVertexColorUp(const MtColor& color) {
    const u32 t0 = color.rgba;
    if (t0 != mColor[0].rgba) {
        mColor[1].rgba = t0;
        mColor[0].rgba = t0;
        updateColorState();
        setUpdateDraw();
    }
}

MtColor cGUIObjPolygon::getVertexColorUp() const {
    MtColor result;
    result.rgba = mColor[0].rgba;
    return result;
}

void cGUIObjPolygon::setVertexColorDown(const MtColor& color) {
    const u32 t0 = color.rgba;
    if (t0 != mColor[2].rgba) {
        mColor[3].rgba = t0;
        mColor[2].rgba = t0;
        updateColorState();
        setUpdateDraw();
    }
}

MtColor cGUIObjPolygon::getVertexColorDown() const {
    MtColor result;
    result.rgba = mColor[2].rgba;
    return result;
}

void cGUIObjPolygon::setVertexColorLeft(const MtColor& color) {
    const u32 t0 = color.rgba;
    if (t0 != mColor[0].rgba) {
        mColor[2].rgba = t0;
        mColor[0].rgba = t0;
        updateColorState();
        setUpdateDraw();
    }
}

MtColor cGUIObjPolygon::getVertexColorLeft() const {
    MtColor result;
    result.rgba = mColor[0].rgba;
    return result;
}

void cGUIObjPolygon::setVertexColorRight(const MtColor& color) {
    const u32 t0 = color.rgba;
    if (t0 != mColor[1].rgba) {
        mColor[3].rgba = t0;
        mColor[1].rgba = t0;
        updateColorState();
        setUpdateDraw();
    }
}

MtColor cGUIObjPolygon::getVertexColorRight() const {
    MtColor result;
    result.rgba = mColor[1].rgba;
    return result;
}

__attribute__((weak)) void cGUIObjPolygon::setVertexColor(const MtColor& color) {
    DDON_STUB("cGUIObjPolygon::setVertexColor")
    /* stub */
}

MtColor cGUIObjPolygon::getVertexColor() const {
    MtColor result;
    result.rgba = mColor[0].rgba;
    return result;
}

void cGUIObjPolygon::setColor(const MtColor& color, u32 index) {
    if (index <= 3u) {
        if (color.rgba != mColor[index].rgba) {
            mColor[index].rgba = color.rgba;
            updateColorState();
            setUpdateDraw();
        }
    }
}

__attribute__((weak)) MtColor cGUIObjPolygon::getColor(u32 index) const {
    DDON_STUB("cGUIObjPolygon::getColor")
    __builtin_unreachable();
}

__attribute__((weak)) void cGUIObjPolygon::setVertexAlpha(u8 alpha) {
    DDON_STUB("cGUIObjPolygon::setVertexAlpha")
    /* stub */
}

u8 cGUIObjPolygon::getVertexAlpha() const {
    return *reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 199);
}

void cGUIObjPolygon::setAlpha(u8 alpha, u32 index) {
    if (index <= 3u) {
        if ((mColor[index].rgba >> 24) != alpha) {
            mColor[index].rgba = static_cast<unsigned int>(static_cast<unsigned long>(alpha * 16777216) | static_cast<unsigned long>(mColor[index].rgba & 0xFFFFFFu));
            updateColorState();
            setUpdateDraw();
        }
    }
}

__attribute__((weak)) void cGUIObjPolygon::setVertexRGB(const MtColor& rgb) {
    DDON_STUB("cGUIObjPolygon::setVertexRGB")
    /* stub */
}

MtColor cGUIObjPolygon::getVertexRGB() const {
    MtColor result;
    result.rgba = mColor[0].rgba;
    return result;
}

static auto ddon_emit_0x01b728e0 __attribute__((used)) = &cGUIObjPolygon::setBlendState;

static auto ddon_emit_0x01b728d0 __attribute__((used)) = &cGUIObjPolygon::getBlendState;

__attribute__((weak)) void cGUIObjPolygon::setReverseClockwise(bool v) {
    DDON_STUB("cGUIObjPolygon::setReverseClockwise")
    /* stub */
}

bool cGUIObjPolygon::isReverseClockwise() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 249)) & 16) >> 4);
}

__attribute__((weak)) void cGUIObjPolygon::setSize(const MtFloat2& size) {
    DDON_STUB("cGUIObjPolygon::setSize")
    /* stub */
}

static auto ddon_emit_0x01b72900 __attribute__((used)) = &cGUIObjPolygon::getSize;

__attribute__((weak)) MtAABB cGUIObjPolygon::calcBoundingBox() const {
    DDON_STUB("cGUIObjPolygon::calcBoundingBox")
    __builtin_unreachable();
}

void cGUIObjPolygon::beginDraw(nGUI::Draw& drawObj) {
    if (mMaskType <= 6u) {
        if (((54ul >> static_cast<unsigned long>(mMaskType)) & 1ul) != 0) {
            if ((drawObj.mAttr & 4u) == 0) {
                drawObj.beginStencilMask(mMaskType);
            }
        } else {
            if (((72ul >> static_cast<unsigned long>(mMaskType)) & 1ul) != 0) {
                drawObj.beginAlphaMask(mMaskType);
            }
        }
    }
}

__attribute__((weak)) void cGUIObjPolygon::draw(nGUI::Draw& drawObj) {
    DDON_STUB("cGUIObjPolygon::draw")
    /* stub */
}

void cGUIObjPolygon::endDraw(nGUI::Draw& drawObj) {
    if (mMaskType <= 6u) {
        if (((54ul >> static_cast<unsigned long>(mMaskType)) & 1ul) != 0) {
            if ((drawObj.mAttr & 4u) == 0) {
                drawObj.endStencilMask();
            }
        } else {
            if (((72ul >> static_cast<unsigned long>(mMaskType)) & 1ul) != 0) {
                drawObj.endAlphaMask();
            }
        }
    }
}

__attribute__((weak)) bool cGUIObjPolygon::checkHit(const MtVector3& pt, f32 ratio, const MtRay* const pRay) const {
    DDON_STUB("cGUIObjPolygon::checkHit")
    return {};
}

void cGUIObjPolygon::setUpdateDraw() {
    mVertexObject.update = (sGUI::mpInstance)->mBufferBit;
}

__attribute__((weak)) void cGUIObjPolygon::updateColorState() {
    DDON_STUB("cGUIObjPolygon::updateColorState")
    /* stub */
}

inline cGUIObjPolygon::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGUIObjPolygon::MyDTI cGUIObjPolygon::DTI("cGUIObjPolygon", &::cGUIObj2D::DTI, 256ul, 0u, 0u);

__attribute__((weak)) MtObject* cGUIObjPolygon::MyDTI::newInstance() const {
    DDON_STUB("cGUIObjPolygon::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cGUIObjRoot::getDTI() const {
    return cGUIObjRoot::DTI;
}

void* cGUIObjRoot::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

cGUIObjRoot::cGUIObjRoot() {
    DDON_STUB("cGUIObjRoot::cGUIObjRoot")
    /* stub */
}

cGUIObjRoot::~cGUIObjRoot() {
    DDON_STUB("cGUIObjRoot::~cGUIObjRoot")
    /* stub */
}

MtUI* cGUIObjRoot::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void cGUIObjRoot::createProperty(MtPropertyList& s) {
    DDON_STUB("cGUIObjRoot::createProperty")
    /* stub */
}

void cGUIObjRoot::msgInit() {
    u32 i = 0;
    if (mpAnimation->objectNum != 0) {
        do {
            mpObject[i]->init();
            i += 1u;
        } while (i < mpAnimation->objectNum);
    }
}

__attribute__((weak)) void cGUIObjRoot::msgPlay(f32 delta, bool force) {
    DDON_STUB("cGUIObjRoot::msgPlay")
    /* stub */
}

__attribute__((weak)) void cGUIObjRoot::msgDraw(nGUI::Draw& drawObj) {
    DDON_STUB("cGUIObjRoot::msgDraw")
    /* stub */
}

__attribute__((weak)) void cGUIObjRoot::msgCalcMatrix(const MtMatrix& wmat, bool update) {
    DDON_STUB("cGUIObjRoot::msgCalcMatrix")
    /* stub */
}

__attribute__((weak)) void cGUIObjRoot::setSequenceId(u32 id) {
    DDON_STUB("cGUIObjRoot::setSequenceId")
    /* stub */
}

__attribute__((weak)) cGUIObject* cGUIObjRoot::getObjectFromName(MT_CTSTR name) const {
    DDON_STUB("cGUIObjRoot::getObjectFromName")
    return nullptr;
}

__attribute__((weak)) void cGUIObjRoot::setParentResolutionAdjust(u32 type) {
    DDON_STUB("cGUIObjRoot::setParentResolutionAdjust")
    /* stub */
}

void cGUIObjRoot::init() {
    mCurrentFrame = -1.0f;
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86) = (*reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 86)) | 2;
    if (mpDrawList == nullptr) {
        return;
    }
    mpDrawList->type = 2;
    mRootAttr = mRootAttr | 1u;
}

void cGUIObjRoot::triggerEvent(u32 eventNo) {
    if (mpUnit == nullptr) {
        return;
    }
    mpUnit->callbackAnimationEvent(mInstanceId, mAnimationId, eventNo);
}

__attribute__((weak)) void cGUIObjRoot::setObject(nGUI::ANIMATION* pAnimation, cGUIObject* * pObject) {
    DDON_STUB("cGUIObjRoot::setObject")
    /* stub */
}

void cGUIObjRoot::setSequence(u32 sequenceNum, nGUI::SEQUENCE* pSequence) {
    mSequenceNum = sequenceNum;
    mpSequence = pSequence;
}

__attribute__((weak)) void cGUIObjRoot::setInstanceId(u32 id) {
    DDON_STUB("cGUIObjRoot::setInstanceId")
    /* stub */
}

inline cGUIObjRoot::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGUIObjRoot::MyDTI cGUIObjRoot::DTI("cGUIObjRoot", &::cGUIObject::DTI, 240ul, 0u, 2u);

__attribute__((weak)) MtObject* cGUIObjRoot::MyDTI::newInstance() const {
    DDON_STUB("cGUIObjRoot::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cGUIObjScissorMask::getDTI() const {
    return cGUIObjScissorMask::DTI;
}

void* cGUIObjScissorMask::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void cGUIObjScissorMask::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cGUIObjScissorMask::DTI)->memFree(p_addr);
}

cGUIObjScissorMask::cGUIObjScissorMask() {
    DDON_STUB("cGUIObjScissorMask::cGUIObjScissorMask")
    /* stub */
}

cGUIObjScissorMask::~cGUIObjScissorMask() {
    DDON_STUB("cGUIObjScissorMask::~cGUIObjScissorMask")
    /* stub */
}

MtUI* cGUIObjScissorMask::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void cGUIObjScissorMask::createProperty(MtPropertyList& s) {
    this->cGUIObj2D::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Enable", reinterpret_cast<MT_MFUNC>(&::cGUIObjScissorMask::isEnableScissor), reinterpret_cast<MT_MFUNC>(&::cGUIObjScissorMask::setEnableScissor), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_SIZE, "Size", reinterpret_cast<MT_MFUNC>(&::cGUIObjScissorMask::getSize), reinterpret_cast<MT_MFUNC>(&::cGUIObjScissorMask::setSize), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

bool cGUIObjScissorMask::isDrawableStatic() const {
    return true;
}

void cGUIObjScissorMask::setEnableScissor(bool v) {
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 196) = static_cast<unsigned int>(static_cast<unsigned long>((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 196)) & 0xFFFFFFFEu) | static_cast<unsigned long>(v));
}

bool cGUIObjScissorMask::isEnableScissor() const {
    return static_cast<bool>((*reinterpret_cast<const unsigned int*>(reinterpret_cast<const char*>(this) + 196)) & 1u);
}

void cGUIObjScissorMask::setSize(const MtSize& size) {
    if (size.wh == mSize.wh) {
        return;
    }
    mSize.w = static_cast<s32>(static_cast<unsigned int>(size.wh));
    mSize.h = size.h;
    mUpdateSize = 1;
}

MtSize cGUIObjScissorMask::getSize() const {
    MtSize result;
    result.wh = mSize.wh;
    return result;
}

void cGUIObjScissorMask::calcMatrix(const MtMatrix& wmat) {
    this->cGUIObj2D::calcMatrix(wmat);
    mUpdateSize = 1;
}

__attribute__((weak)) void cGUIObjScissorMask::beginDraw(nGUI::Draw& drawObj) {
    DDON_STUB("cGUIObjScissorMask::beginDraw")
    /* stub */
}

__attribute__((weak)) void cGUIObjScissorMask::endDraw(nGUI::Draw& drawObj) {
    DDON_STUB("cGUIObjScissorMask::endDraw")
    /* stub */
}

__attribute__((weak)) bool cGUIObjScissorMask::checkHit(const MtVector3& pt, f32 ratio, const MtRay* const pRay) const {
    DDON_STUB("cGUIObjScissorMask::checkHit")
    return {};
}

inline cGUIObjScissorMask::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGUIObjScissorMask::MyDTI cGUIObjScissorMask::DTI("cGUIObjScissorMask", &::cGUIObj2D::DTI, 240ul, 0u, 0u);

__attribute__((weak)) MtObject* cGUIObjScissorMask::MyDTI::newInstance() const {
    DDON_STUB("cGUIObjScissorMask::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cGUIObjText::getDTI() const {
    return cGUIObjText::DTI;
}

void* cGUIObjText::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void cGUIObjText::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cGUIObjText::DTI)->memFree(p_addr);
}

cGUIObjText::cGUIObjText() {
    DDON_STUB("cGUIObjText::cGUIObjText")
    /* stub */
}

cGUIObjText::~cGUIObjText() {
}

MtUI* cGUIObjText::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void cGUIObjText::createProperty(MtPropertyList& s) {
    this->cGUIObjMessage::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_F32, "TypingSpeed", reinterpret_cast<MT_MFUNC>(&::cGUIObjText::getTypingSpeed), reinterpret_cast<MT_MFUNC>(&::cGUIObjText::setTypingSpeed), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "TypingEvent", reinterpret_cast<MT_MFUNC>(&::cGUIObjText::isTypingEvent), reinterpret_cast<MT_MFUNC>(&::cGUIObjText::setTypingEvent), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

void cGUIObjText::setTypingSpeed(f32 speed) {
    mTypingSpeed = speed;
    mNowTypingSpeed = speed;
}

static auto ddon_emit_0x01b73020 __attribute__((used)) = &cGUIObjText::getTypingSpeed;

static auto ddon_emit_0x01b73040 __attribute__((used)) = &cGUIObjText::setTypingEvent;

bool cGUIObjText::isTypingEvent() const {
    return static_cast<bool>(mTextAttr & 1u);
}

__attribute__((weak)) void cGUIObjText::play(f32 delta) {
    DDON_STUB("cGUIObjText::play")
    /* stub */
}

__attribute__((weak)) void cGUIObjText::analyzeMessage(MT_CTSTR msg, u32 length, s32 pageIndex) {
    DDON_STUB("cGUIObjText::analyzeMessage")
    /* stub */
}

__attribute__((weak)) void cGUIObjText::analyzeGenderMessage(MT_CTSTR msg, nGUI::GENDER speakerGender, nGUI::GENDER listenerGender, u32 length) {
    DDON_STUB("cGUIObjText::analyzeGenderMessage")
    /* stub */
}

__attribute__((weak)) void cGUIObjText::clearMessage() {
    DDON_STUB("cGUIObjText::clearMessage")
    /* stub */
}

__attribute__((weak)) void cGUIObjText::executeMTag() {
    DDON_STUB("cGUIObjText::executeMTag")
    /* stub */
}

__attribute__((weak)) void cGUIObjText::executeMTagExtend(void* pData) {
}

nGUI::MTAG* cGUIObjText::getDrawStartMTag() const {
    return mpStartMTag;
}

nGUI::MTAG* cGUIObjText::getDrawEndMTag() const {
    return mpNowMTag;
}

bool cGUIObjText::isPageEnd() const {
    return true;
}

inline cGUIObjText::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGUIObjText::MyDTI cGUIObjText::DTI("cGUIObjText", &::cGUIObjMessage::DTI, 496ul, 0u, 0u);

__attribute__((weak)) MtObject* cGUIObjText::MyDTI::newInstance() const {
    DDON_STUB("cGUIObjText::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cGUIObjTexture::getDTI() const {
    return cGUIObjTexture::DTI;
}

void* cGUIObjTexture::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

cGUIObjTexture::cGUIObjTexture() {
    DDON_STUB("cGUIObjTexture::cGUIObjTexture")
    /* stub */
}

cGUIObjTexture::~cGUIObjTexture() {
    DDON_STUB("cGUIObjTexture::~cGUIObjTexture")
    /* stub */
}

MtUI* cGUIObjTexture::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void cGUIObjTexture::createProperty(MtPropertyList& s) {
    this->cGUIObjPolygon::createProperty(s);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "SamplerState", reinterpret_cast<MT_MFUNC>(&::cGUIObjTexture::getSamplerState), reinterpret_cast<MT_MFUNC>(&::cGUIObjTexture::setSamplerState), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "Tiling", reinterpret_cast<MT_MFUNC>(&::cGUIObjTexture::getTiling), reinterpret_cast<MT_MFUNC>(&::cGUIObjTexture::setTiling), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "Texture", reinterpret_cast<MT_MFUNC>(&::cGUIObjTexture::getTextureId), reinterpret_cast<MT_MFUNC>(&::cGUIObjTexture::setTextureId), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_FLOAT4, "mTextureRect", reinterpret_cast<MT_MFUNC>(&::cGUIObjTexture::getTextureRect), reinterpret_cast<MT_MFUNC>(&::cGUIObjTexture::setTextureRect), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

void cGUIObjTexture::setSamplerState(u32 state) {
    if (mSamplerState != state) {
        mSamplerState = state;
        setUpdateDraw();
    }
}

static auto ddon_emit_0x01b72a50 __attribute__((used)) = &cGUIObjTexture::getSamplerState;

__attribute__((weak)) void cGUIObjTexture::setSize(const MtFloat2& size) {
    DDON_STUB("cGUIObjTexture::setSize")
    /* stub */
}

void cGUIObjTexture::setTiling(u32 mode) {
    if (mode <= 2u) {
        if (mTiling != mode) {
            *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 264) = ((*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this) + 264)) & 0xFFFFFFCFu) | ((mode * 16u) & 48u);
            if (((mode * 16u) & 48u) != 0) {
                (sGUI::mpInstance)->sGUI::freeVertexBuffer(mVertexObject);
                (sGUI::mpInstance)->sGUI::freeIndexBuffer(mIndexObject);
            }
            setUpdateDraw();
        }
    }
}

static auto ddon_emit_0x01b72a60 __attribute__((used)) = &cGUIObjTexture::getTiling;

void cGUIObjTexture::setTextureId(u32 id) {
    if (mpResource != nullptr) {
        if (mTextureId != id) {
            mTextureId = id;
            nGUI::TEXTURE* t0 = mpResource->getTextureFromId(id);
            if ((mpTexture = t0) != nullptr) {
                if (t0->pTexture == nullptr) {
                    mpTexture = nullptr;
                }
            }
        }
    } else {
        mTextureId = 0xFFFFFFFF;
        mpTexture = nullptr;
    }
}

static auto ddon_emit_0x01b72a70 __attribute__((used)) = &cGUIObjTexture::getTextureId;

__attribute__((weak)) void cGUIObjTexture::setTextureRect(const MtFloat4& rect) {
    DDON_STUB("cGUIObjTexture::setTextureRect")
    /* stub */
}

static auto ddon_emit_0x01b72a80 __attribute__((used)) = &cGUIObjTexture::getTextureRect;

__attribute__((weak)) void cGUIObjTexture::setUpdateDraw() {
    DDON_STUB("cGUIObjTexture::setUpdateDraw")
    /* stub */
}

__attribute__((weak)) void cGUIObjTexture::draw(nGUI::Draw& drawObj) {
    DDON_STUB("cGUIObjTexture::draw")
    /* stub */
}

__attribute__((weak)) bool cGUIObjTexture::drawWithTiling(nGUI::Draw& drawObj, nGUI::SamplerState::SAMPLER_MODE& sampler) {
    DDON_STUB("cGUIObjTexture::drawWithTiling")
    return {};
}

__attribute__((weak)) bool cGUIObjTexture::drawWithoutTiling(nGUI::Draw& drawObj, nGUI::SamplerState::SAMPLER_MODE& sampler) {
    DDON_STUB("cGUIObjTexture::drawWithoutTiling")
    return {};
}

inline cGUIObjTexture::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGUIObjTexture::MyDTI cGUIObjTexture::DTI("cGUIObjTexture", &::cGUIObjPolygon::DTI, 320ul, 0u, 0u);

__attribute__((weak)) MtObject* cGUIObjTexture::MyDTI::newInstance() const {
    DDON_STUB("cGUIObjTexture::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cGUIObjTextureSet::getDTI() const {
    return cGUIObjTextureSet::DTI;
}

void* cGUIObjTextureSet::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

cGUIObjTextureSet::cGUIObjTextureSet() {
    DDON_STUB("cGUIObjTextureSet::cGUIObjTextureSet")
    /* stub */
}

cGUIObjTextureSet::~cGUIObjTextureSet() {
}

MtUI* cGUIObjTextureSet::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

void cGUIObjTextureSet::createProperty(MtPropertyList& s) {
    this->cGUIObjTexture::createProperty(s);
    MtProperty* t0 = s.find("ControlPoint");
    if (t0 != nullptr) {
        t0->mAttr = t0->mAttr | 1u;
        MtProperty* t1 = s.find("Size");
        if (t1 != nullptr) {
            t1->mAttr = t1->mAttr | 1u;
            MtProperty* t2 = s.find("Reverse");
            if (t2 != nullptr) {
                t2->mAttr = t2->mAttr | 1u;
                MtProperty* t3 = s.find("mTextureRect");
                if (t3 != nullptr) {
                    t3->mAttr = t3->mAttr | 1u;
                    MtProperty* t4 = s.find("Tiling");
                    if (t4 != nullptr) {
                        t4->mAttr = t4->mAttr | 1u;
                    }
                } else {
                    MtProperty* t4 = s.find("Tiling");
                    if (t4 != nullptr) {
                        t4->mAttr = t4->mAttr | 1u;
                    }
                }
            } else {
                MtProperty* t3 = s.find("mTextureRect");
                if (t3 != nullptr) {
                    t3->mAttr = t3->mAttr | 1u;
                    MtProperty* t4 = s.find("Tiling");
                    if (t4 != nullptr) {
                        t4->mAttr = t4->mAttr | 1u;
                    }
                } else {
                    MtProperty* t4 = s.find("Tiling");
                    if (t4 != nullptr) {
                        t4->mAttr = t4->mAttr | 1u;
                    }
                }
            }
        } else {
            MtProperty* t2 = s.find("Reverse");
            if (t2 != nullptr) {
                t2->mAttr = t2->mAttr | 1u;
                MtProperty* t3 = s.find("mTextureRect");
                if (t3 != nullptr) {
                    t3->mAttr = t3->mAttr | 1u;
                    MtProperty* t4 = s.find("Tiling");
                    if (t4 != nullptr) {
                        t4->mAttr = t4->mAttr | 1u;
                    }
                } else {
                    MtProperty* t4 = s.find("Tiling");
                    if (t4 != nullptr) {
                        t4->mAttr = t4->mAttr | 1u;
                    }
                }
            } else {
                MtProperty* t3 = s.find("mTextureRect");
                if (t3 != nullptr) {
                    t3->mAttr = t3->mAttr | 1u;
                    MtProperty* t4 = s.find("Tiling");
                    if (t4 != nullptr) {
                        t4->mAttr = t4->mAttr | 1u;
                    }
                } else {
                    MtProperty* t4 = s.find("Tiling");
                    if (t4 != nullptr) {
                        t4->mAttr = t4->mAttr | 1u;
                    }
                }
            }
        }
    } else {
        MtProperty* t1 = s.find("Size");
        if (t1 != nullptr) {
            t1->mAttr = t1->mAttr | 1u;
            MtProperty* t2 = s.find("Reverse");
            if (t2 != nullptr) {
                t2->mAttr = t2->mAttr | 1u;
                MtProperty* t3 = s.find("mTextureRect");
                if (t3 != nullptr) {
                    t3->mAttr = t3->mAttr | 1u;
                    MtProperty* t4 = s.find("Tiling");
                    if (t4 != nullptr) {
                        t4->mAttr = t4->mAttr | 1u;
                    }
                } else {
                    MtProperty* t4 = s.find("Tiling");
                    if (t4 != nullptr) {
                        t4->mAttr = t4->mAttr | 1u;
                    }
                }
            } else {
                MtProperty* t3 = s.find("mTextureRect");
                if (t3 != nullptr) {
                    t3->mAttr = t3->mAttr | 1u;
                    MtProperty* t4 = s.find("Tiling");
                    if (t4 != nullptr) {
                        t4->mAttr = t4->mAttr | 1u;
                    }
                } else {
                    MtProperty* t4 = s.find("Tiling");
                    if (t4 != nullptr) {
                        t4->mAttr = t4->mAttr | 1u;
                    }
                }
            }
        } else {
            MtProperty* t2 = s.find("Reverse");
            if (t2 != nullptr) {
                t2->mAttr = t2->mAttr | 1u;
                MtProperty* t3 = s.find("mTextureRect");
                if (t3 != nullptr) {
                    t3->mAttr = t3->mAttr | 1u;
                    MtProperty* t4 = s.find("Tiling");
                    if (t4 != nullptr) {
                        t4->mAttr = t4->mAttr | 1u;
                    }
                } else {
                    MtProperty* t4 = s.find("Tiling");
                    if (t4 != nullptr) {
                        t4->mAttr = t4->mAttr | 1u;
                    }
                }
            } else {
                MtProperty* t3 = s.find("mTextureRect");
                if (t3 != nullptr) {
                    t3->mAttr = t3->mAttr | 1u;
                    MtProperty* t4 = s.find("Tiling");
                    if (t4 != nullptr) {
                        t4->mAttr = t4->mAttr | 1u;
                    }
                } else {
                    MtProperty* t4 = s.find("Tiling");
                    if (t4 != nullptr) {
                        t4->mAttr = t4->mAttr | 1u;
                    }
                }
            }
        }
    }
}

void cGUIObjTextureSet::setVertexColor(const MtColor& color) {
    mColor[0].rgba = color.rgba;
}

__attribute__((weak)) MtAABB cGUIObjTextureSet::calcBoundingBox() const {
    DDON_STUB("cGUIObjTextureSet::calcBoundingBox")
    __builtin_unreachable();
}

__attribute__((weak)) void cGUIObjTextureSet::draw(nGUI::Draw& drawObj) {
    DDON_STUB("cGUIObjTextureSet::draw")
    /* stub */
}

__attribute__((weak)) bool cGUIObjTextureSet::checkHit(const MtVector3& pt, f32 ratio, const MtRay* const pRay) const {
    DDON_STUB("cGUIObjTextureSet::checkHit")
    return {};
}

__attribute__((weak)) void cGUIObjTextureSet::setExtendData(void* pData) {
    DDON_STUB("cGUIObjTextureSet::setExtendData")
    /* stub */
}

inline cGUIObjTextureSet::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGUIObjTextureSet::MyDTI cGUIObjTextureSet::DTI("cGUIObjTextureSet", &::cGUIObjTexture::DTI, 352ul, 0u, 0u);

__attribute__((weak)) MtObject* cGUIObjTextureSet::MyDTI::newInstance() const {
    DDON_STUB("cGUIObjTextureSet::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& cGUIObject::getDTI() const {
    return cGUIObject::DTI;
}

MtAllocator* cGUIObject::getAllocator() {
    return MtMemoryAllocator::getAllocator(cGUIObject::DTI);
}

inline void cGUIObject::operator delete(void* p_addr) {
    MtMemoryAllocator::getAllocator(cGUIObject::DTI)->memFree(p_addr);
}

cGUIObject::~cGUIObject() {
    if ((mDeleteChild & 1u) != 0) {
        if (mpChild != nullptr) {
            for (cGUIObject* v0_5 = mpChild;;) {
                cGUIObject* t0 = v0_5->mpNext;
                delete v0_5;
                if (t0 != nullptr) {
                    v0_5 = t0;
                } else {
                    break;
                }
            }
        }
    }
}

MtUI* cGUIObject::createUI(MtProperty& prop) {
    return this->MtObject::createUI(prop);
}

__attribute__((weak)) void cGUIObject::createProperty(MtPropertyList& s) {
    s << MtProperty(static_cast<MtObject*>(this), "mId", &mId, 1u, 0u);
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Visible", reinterpret_cast<MT_MFUNC>(&::cGUIObject::isVisible), reinterpret_cast<MT_MFUNC>(&::cGUIObject::setVisible), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "Priority", reinterpret_cast<MT_MFUNC>(&::cGUIObject::getPriority), reinterpret_cast<MT_MFUNC>(&::cGUIObject::setPriority), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "Loop", reinterpret_cast<MT_MFUNC>(&::cGUIObject::isLoop), reinterpret_cast<MT_MFUNC>(&::cGUIObject::setLoop), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_U32, "LoopStartFrame", reinterpret_cast<MT_MFUNC>(&::cGUIObject::getLoopStartFrame), reinterpret_cast<MT_MFUNC>(&::cGUIObject::setLoopStartFrame), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << MtProperty(static_cast<MtObject*>(this), MtProperty::TYPE_BOOL, "FixFrame", reinterpret_cast<MT_MFUNC>(&::cGUIObject::isFixFrame), reinterpret_cast<MT_MFUNC>(&::cGUIObject::setFixFrame), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
}

bool cGUIObject::isDrawableStatic() const {
    return false;
}

__attribute__((weak)) u32 cGUIObject::msgCheckHit(const MtVector3& pt, f32 ratio, const MtRay* const pRay) {
    DDON_STUB("cGUIObject::msgCheckHit")
    return {};
}

__attribute__((weak)) void cGUIObject::setPriority(u32 prio) {
    DDON_STUB("cGUIObject::setPriority")
    /* stub */
}

static auto ddon_emit_0x01b725c0 __attribute__((used)) = &cGUIObject::getPriority;

__attribute__((weak)) void cGUIObject::setVisible(bool v) {
    DDON_STUB("cGUIObject::setVisible")
    /* stub */
}

bool cGUIObject::isVisible() const {
    return static_cast<bool>(mAttr & 1u);
}

static auto ddon_emit_0x01b725e0 __attribute__((used)) = &cGUIObject::setLoop;

bool cGUIObject::isLoop() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 84)) & 4) >> 2);
}

static auto ddon_emit_0x01b72630 __attribute__((used)) = &cGUIObject::setFixFrame;

bool cGUIObject::isFixFrame() const {
    return static_cast<bool>(static_cast<unsigned long>((*reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 84)) & 8) >> 3);
}

static auto ddon_emit_0x01b72610 __attribute__((used)) = &cGUIObject::setLoopStartFrame;

static auto ddon_emit_0x01b72600 __attribute__((used)) = &cGUIObject::getLoopStartFrame;

__attribute__((weak)) void cGUIObject::setCurrentFrame(f32 frame, bool changeFixFrame) {
    DDON_STUB("cGUIObject::setCurrentFrame")
    /* stub */
}

__attribute__((weak)) cGUIObject* cGUIObject::getObjectFromId(u32 id) const {
    DDON_STUB("cGUIObject::getObjectFromId")
    return nullptr;
}

__attribute__((weak)) MtRect cGUIObject::getBoundingBox2D() const {
    DDON_STUB("cGUIObject::getBoundingBox2D")
    __builtin_unreachable();
}

__attribute__((weak)) MtAABB cGUIObject::getBoundingBox3D() const {
    DDON_STUB("cGUIObject::getBoundingBox3D")
    __builtin_unreachable();
}

__attribute__((weak)) MtAABB cGUIObject::calcBoundingBox() const {
    DDON_STUB("cGUIObject::calcBoundingBox")
    __builtin_unreachable();
}

u32 cGUIObject::getValidResolutionAdjust() const {
    return mParentResolutionAdjust;
}

void cGUIObject::init() {
    mCurrentFrame = -1.0f;
    mAttr = mAttr | 0x20000u;
}

void cGUIObject::initProperty() {
    if (mpObjectInfo->initParamNum == 0) {
        if (mpParent != nullptr) {
            mpParent->mAttr = mpParent->mAttr | 0x80000u;
        }
        return;
    }
    u32 i = 0;
    nGUI::INIT_PARAM* p8 = mpObjectInfo->pInitParam;
    do {
        nGUI::initProperty(static_cast<MtObject*>(this), p8);
        i += 1u;
        p8 += static_cast<int>(1);
    } while (i < mpObjectInfo->initParamNum);
    if (mpParent != nullptr) {
        mpParent->mAttr = mpParent->mAttr | 0x80000u;
    }
}

__attribute__((weak)) void cGUIObject::calcMatrix(const MtMatrix& wmat) {
    DDON_STUB("cGUIObject::calcMatrix")
    /* stub */
}

bool cGUIObject::checkHit(const MtVector3& pt, f32 ratio, const MtRay* const pRay) const {
    return false;
}

__attribute__((weak)) void cGUIObject::msgInvisible() {
}

void cGUIObject::setParentResolutionAdjust(u32 type) {
    mParentResolutionAdjust = type;
    for (cGUIObject* pChild = mpChild;;) {
        if (pChild == nullptr) {
            break;
        } else {
            pChild->setParentResolutionAdjust(type);
            pChild = pChild->mpNext;
        }
    }
}

__attribute__((weak)) void cGUIObject::setDrawable(bool v) {
    DDON_STUB("cGUIObject::setDrawable")
    /* stub */
}

void* cGUIObject::memAlloc(u32 size) {
    return cGUIObject::getAllocator()->memAlloc(size, 16u);
}

void cGUIObject::memFree(void* p_addr) {
    cGUIObject::getAllocator()->memFree(p_addr);
}

void cGUIObject::setChild(cGUIObject* pObject) {
    mpChild = pObject;
    if (pObject == nullptr) {
        return;
    }
    pObject->mpParent = this;
}

void cGUIObject::setNext(cGUIObject* pObject) {
    mpNext = pObject;
    if (pObject == nullptr) {
        return;
    }
    pObject->mpParent = mpParent;
}

void cGUIObject::setObjectInfo(nGUI::OBJECT* pObjectInfo, nGUI::PARAM_WORK* pParamWork) {
    mpObjectInfo = pObjectInfo;
    mpParamWork = pParamWork;
    if ((mAnimateParamNum & 255u) != 0) {
        unsigned int i0_0 = 0;
        for (nGUI::PARAM_WORK* p0_2 = pParamWork;;) {
            p0_2->pOwner = static_cast<MtObject*>(this);
            if ((i0_0 + 1u) < mAnimateParamNum) {
                i0_0 += 1u;
                p0_2 += 1;
            } else {
                break;
            }
        }
    }
}

inline cGUIObject::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

cGUIObject::MyDTI cGUIObject::DTI("cGUIObject", &::MtObject::DTI, 160ul, 0u, 1u);

MtObject* cGUIObject::MyDTI::newInstance() const {
    return nullptr;
}

