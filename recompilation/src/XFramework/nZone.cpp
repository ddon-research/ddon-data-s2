// Reconstructed from the game's DWARF debug information.
#include <new>
#include "nZone.h"
#include "../MT/MtAllocator.h"
#include "../MT/MtCollection.h"
#include "../MT/MtCollision.h"
#include "../MT/MtCollisionGjk.h"
#include "../MT/MtDTI.h"
#include "../MT/MtDataReader.h"
#include "../MT/MtDataWriter.h"
#include "../MT/MtGeometry3D.h"
#include "../MT/MtMath.h"
#include "../MT/MtMemoryAllocator.h"
#include "../MT/MtObject.h"
#include "../MT/MtPrimitive3D.h"
#include "../MT/MtProperty.h"
#include "../MT/MtPropertyList.h"
#include "../MT/MtSerializer.h"
#include "cDynamicBVHCollision.h"
#include "cZoneContents.h"
#include "cZoneExtendObject.h"
#include "cZoneLayout.h"
#include "rZone.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

inline void* nZone::ShapeInfoLine::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoLine::DTI)->memAlloc(sz, align, ::nZone::ShapeInfoLine::DTI.getID());
}
inline nZone::ShapeInfoLine::ShapeInfoLine() {
    mLineSegment.p0 = MtVector3(-50.0f, 0.0f, 0.0f);
    mLineSegment.p1 = MtVector3(50.0f, 0.0f, 0.0f);
}

inline void* nZone::ShapeInfoPoint::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoPoint::DTI)->memAlloc(sz, align, ::nZone::ShapeInfoPoint::DTI.getID());
}
inline nZone::ShapeInfoPoint::ShapeInfoPoint() {
    mPos = MtVector3::Zero;
}

inline void* nZone::cContentsPool::cContentsList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nZone::cContentsPool::cContentsList::DTI)->memAlloc(sz, align, ::nZone::cContentsPool::cContentsList::DTI.getID());
}

const MtDTI& nZone::ShapeInfoAABB::getDTI() const {
    return nZone::ShapeInfoAABB::DTI;
}

void* nZone::ShapeInfoAABB::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoAABB::DTI)->memAlloc(sz, align, ::nZone::ShapeInfoAABB::DTI.mID);
}

void* nZone::ShapeInfoAABB::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void nZone::ShapeInfoAABB::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoAABB::DTI)->memFree(p_addr);
}

nZone::ShapeInfoAABB::ShapeInfoAABB() {
    mAABB.minpos = MtVector3(-50.0f, 0.0f, -50.0f);
    mAABB.maxpos = MtVector3(50.0f, 100.0f, 50.0f);
    mDecayY = 1.0f;
    mDecayZ = 1.0f;
    mIsEnableExtendedDecay = false;
}

nZone::ShapeInfoAABB::~ShapeInfoAABB() {
}

void nZone::ShapeInfoAABB::createProperty(MtPropertyList& s) {
    this->::nZone::ShapeInfoBase::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "mIsEnableExtendedDecay", &mIsEnableExtendedDecay, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mDecayX", &mDecay, 2u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mDecayY", &mDecayY, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mDecayZ", &mDecayZ, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_VECTOR3, "std::minpos", reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoAABB::getVertex000), reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoAABB::setVertex000), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_VECTOR3, "std::maxpos", reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoAABB::getVertex111), reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoAABB::setVertex111), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_VECTOR3, "v000", reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoAABB::getVertex000), reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoAABB::setVertex000), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_VECTOR3, "v100", reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoAABB::getVertex100), reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoAABB::setVertex100), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_VECTOR3, "v010", reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoAABB::getVertex010), reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoAABB::setVertex010), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_VECTOR3, "v110", reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoAABB::getVertex110), reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoAABB::setVertex110), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_VECTOR3, "v001", reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoAABB::getVertex001), reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoAABB::setVertex001), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_VECTOR3, "v101", reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoAABB::getVertex101), reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoAABB::setVertex101), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_VECTOR3, "v011", reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoAABB::getVertex011), reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoAABB::setVertex011), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_VECTOR3, "v111", reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoAABB::getVertex111), reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoAABB::setVertex111), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), "mAABB", &mAABB, 0u, 0u);
}

__attribute__((weak)) bool nZone::ShapeInfoAABB::copy(const nZone::ShapeInfoBase& copyShape) {
    DDON_STUB("nZone::ShapeInfoAABB::copy")
    return {};
}

__attribute__((weak)) void nZone::ShapeInfoAABB::applyWorldOffset(const MtVector3& offset) {
    DDON_STUB("nZone::ShapeInfoAABB::applyWorldOffset")
    /* stub */
}

nZone::ShapeInfoBase::SHAPE_TYPE nZone::ShapeInfoAABB::getShapeType() const {
    return SHAPE_TYPE_AABB;
}

__attribute__((weak)) bool nZone::ShapeInfoAABB::isHit(const MtVector3& pos) const {
    DDON_STUB("nZone::ShapeInfoAABB::isHit")
    return {};
}

bool nZone::ShapeInfoAABB::isHitLineSegment(const MtLineSegment& ls) const {
    return ::MtCollision::intersect(mAABB, ls);
}

bool nZone::ShapeInfoAABB::isHitConvex(const MtGeomConvex& convex) const {
    return convex.isIntersect(mAABB);
}

__attribute__((weak)) bool nZone::ShapeInfoAABB::isIntersectAABB(const MtAABB& aabb) const {
    DDON_STUB("nZone::ShapeInfoAABB::isIntersectAABB")
    return {};
}

__attribute__((weak)) bool nZone::ShapeInfoAABB::getClosest(const MtVector3& pos, MtContact& contact) const {
    DDON_STUB("nZone::ShapeInfoAABB::getClosest")
    return {};
}

void nZone::ShapeInfoAABB::loadBinary(MtDataReader& r) {
    f32 t0 = r.readF32();
    mDecay = t0;
    u32 t1 = r.mSeekPt;
    u32 t2 = r.mBufsiz;
    if (t1 >= t2) {
        if (r.refill()) {
            u32 t4 = r.mSeekPt;
            u8* t5 = r.mBuffer;
            u8 t6 = t5[r.mSeekPt];
            r.mSeekPt = t4 + 1u;
            mIsNativeData = t6 == 1;
            r.read(static_cast<void*>(&mAABB), 32u);
            f32 t8 = r.readF32();
            mDecayY = t8;
            f32 t9 = r.readF32();
            mDecayZ = t9;
            u32 t10 = r.mSeekPt;
            u32 t11 = r.mBufsiz;
            if (t10 >= t11) {
                if (r.refill()) {
                    u32 t13 = r.mSeekPt;
                    u8* t14 = r.mBuffer;
                    u8 t15 = t14[r.mSeekPt];
                    r.mSeekPt = t13 + 1u;
                    mIsEnableExtendedDecay = t15 == 1;
                } else {
                    mIsEnableExtendedDecay = false;
                }
            } else {
                u8* t14 = r.mBuffer;
                u8 t15 = t14[r.mSeekPt];
                r.mSeekPt = t10 + 1u;
                mIsEnableExtendedDecay = t15 == 1;
            }
        } else {
            mIsNativeData = false;
            r.read(static_cast<void*>(&mAABB), 32u);
            f32 t8 = r.readF32();
            mDecayY = t8;
            f32 t9 = r.readF32();
            mDecayZ = t9;
            u32 t10 = r.mSeekPt;
            u32 t11 = r.mBufsiz;
            if (t10 >= t11) {
                if (r.refill()) {
                    u32 t13 = r.mSeekPt;
                    u8* t14 = r.mBuffer;
                    u8 t15 = t14[r.mSeekPt];
                    r.mSeekPt = t13 + 1u;
                    mIsEnableExtendedDecay = t15 == 1;
                } else {
                    mIsEnableExtendedDecay = false;
                }
            } else {
                u8* t14 = r.mBuffer;
                u8 t15 = t14[r.mSeekPt];
                r.mSeekPt = t10 + 1u;
                mIsEnableExtendedDecay = t15 == 1;
            }
        }
    } else {
        u8* t5 = r.mBuffer;
        u8 t6 = t5[r.mSeekPt];
        r.mSeekPt = t1 + 1u;
        mIsNativeData = t6 == 1;
        r.read(static_cast<void*>(&mAABB), 32u);
        f32 t8 = r.readF32();
        mDecayY = t8;
        f32 t9 = r.readF32();
        mDecayZ = t9;
        u32 t10 = r.mSeekPt;
        u32 t11 = r.mBufsiz;
        if (t10 >= t11) {
            if (r.refill()) {
                u32 t13 = r.mSeekPt;
                u8* t14 = r.mBuffer;
                u8 t15 = t14[r.mSeekPt];
                r.mSeekPt = t13 + 1u;
                mIsEnableExtendedDecay = t15 == 1;
            } else {
                mIsEnableExtendedDecay = false;
            }
        } else {
            u8* t14 = r.mBuffer;
            u8 t15 = t14[r.mSeekPt];
            r.mSeekPt = t10 + 1u;
            mIsEnableExtendedDecay = t15 == 1;
        }
    }
}

void nZone::ShapeInfoAABB::saveBinary(MtDataWriter& w) {
    w.writeF32(mDecay);
    bool t0 = mIsNativeData;
    if (w.mSeekPt >= w.mBufsiz) {
        w.flush();
        w.mBuffer[w.mSeekPt] = static_cast<u8>(t0);
        w.mSeekPt = w.mSeekPt + 1u;
        w.write(static_cast<const void*>(&mAABB), 32u);
        w.writeF32(mDecayY);
        w.writeF32(mDecayZ);
        bool t1 = mIsEnableExtendedDecay;
        if (w.mSeekPt >= w.mBufsiz) {
            w.flush();
        }
        w.mBuffer[w.mSeekPt] = static_cast<u8>(t1);
        w.mSeekPt = w.mSeekPt + 1u;
    } else {
        w.mBuffer[w.mSeekPt] = static_cast<u8>(t0);
        w.mSeekPt = w.mSeekPt + 1u;
        w.write(static_cast<const void*>(&mAABB), 32u);
        w.writeF32(mDecayY);
        w.writeF32(mDecayZ);
        bool t1 = mIsEnableExtendedDecay;
        if (w.mSeekPt >= w.mBufsiz) {
            w.flush();
        }
        w.mBuffer[w.mSeekPt] = static_cast<u8>(t1);
        w.mSeekPt = w.mSeekPt + 1u;
    }
}

bool nZone::ShapeInfoAABB::isGetAABB() const {
    return true;
}

MtAABB nZone::ShapeInfoAABB::getAABB() const {
    return mAABB;
}

bool nZone::ShapeInfoAABB::isGetBoundingSphere() const {
    return true;
}

__attribute__((weak)) MtSphere nZone::ShapeInfoAABB::getBoundingSphere() const {
    DDON_STUB("nZone::ShapeInfoAABB::getBoundingSphere")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector3 nZone::ShapeInfoAABB::getCenterPos() const {
    DDON_STUB("nZone::ShapeInfoAABB::getCenterPos")
    __builtin_unreachable();
}

__attribute__((weak)) void nZone::ShapeInfoAABB::setCenterPos(const MtVector3& pos) {
    DDON_STUB("nZone::ShapeInfoAABB::setCenterPos")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoAABB::movePosition(const MtVector3& AddPos) {
    DDON_STUB("nZone::ShapeInfoAABB::movePosition")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoAABB::movePosition(nZone::ShapeInfoBase& OutputShape, const MtVector3& AddPos) const {
    DDON_STUB("nZone::ShapeInfoAABB::movePosition")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoAABB::mulMatrix(const MtMatrix& MulMatrix) {
    DDON_STUB("nZone::ShapeInfoAABB::mulMatrix")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoAABB::mulMatrix(nZone::ShapeInfoBase& OutputShape, const MtMatrix& MulMatrix) const {
    DDON_STUB("nZone::ShapeInfoAABB::mulMatrix")
    /* stub */
}

__attribute__((weak)) f32 nZone::ShapeInfoAABB::calcWeight(const MtVector3& pos) const {
    DDON_STUB("nZone::ShapeInfoAABB::calcWeight")
    return {};
}

static auto ddon_emit_0x01b88890 __attribute__((used)) = &nZone::ShapeInfoAABB::getVertex000;

void nZone::ShapeInfoAABB::setVertex000(const MtVector3& v) {
    if (v.x > mAABB.maxpos.x) {
        mAABB.minpos.x = mAABB.maxpos.x + -0.001f;
    } else {
        mAABB.minpos.x = v.x;
    }
    if (v.y > mAABB.maxpos.y) {
        mAABB.minpos.y = mAABB.maxpos.y + -0.001f;
    } else {
        mAABB.minpos.y = v.y;
    }
    if (v.z > mAABB.maxpos.z) {
        mAABB.minpos.z = mAABB.maxpos.z + -0.001f;
    } else {
        mAABB.minpos.z = v.z;
    }
}

MtVector3 nZone::ShapeInfoAABB::getVertex001() const {
    MtVector3 result;
    const f32 t0 = mAABB.minpos.y;
    const f32 t1 = mAABB.maxpos.z;
    result.x = mAABB.minpos.x;
    result.y = t0;
    result.z = t1;
    result.pad_ = 0.0f;
    return result;
}

void nZone::ShapeInfoAABB::setVertex001(const MtVector3& v) {
    if (v.x > mAABB.maxpos.x) {
        mAABB.minpos.x = mAABB.maxpos.x + -0.001f;
    } else {
        mAABB.minpos.x = v.x;
    }
    if (v.y > mAABB.maxpos.y) {
        mAABB.minpos.y = mAABB.maxpos.y + -0.001f;
    } else {
        mAABB.minpos.y = v.y;
    }
    if (mAABB.minpos.z > v.z) {
        mAABB.maxpos.z = mAABB.minpos.z + 0.001f;
    } else {
        mAABB.maxpos.z = v.z;
    }
}

MtVector3 nZone::ShapeInfoAABB::getVertex010() const {
    MtVector3 result;
    const f32 t0 = mAABB.maxpos.y;
    const f32 t1 = mAABB.minpos.z;
    result.x = mAABB.minpos.x;
    result.y = t0;
    result.z = t1;
    result.pad_ = 0.0f;
    return result;
}

void nZone::ShapeInfoAABB::setVertex010(const MtVector3& v) {
    if (v.x > mAABB.maxpos.x) {
        mAABB.minpos.x = mAABB.maxpos.x + -0.001f;
    } else {
        mAABB.minpos.x = v.x;
    }
    if (mAABB.minpos.y > v.y) {
        mAABB.maxpos.y = mAABB.minpos.y + 0.001f;
    } else {
        mAABB.maxpos.y = v.y;
    }
    if (v.z > mAABB.maxpos.z) {
        mAABB.minpos.z = mAABB.maxpos.z + -0.001f;
    } else {
        mAABB.minpos.z = v.z;
    }
}

MtVector3 nZone::ShapeInfoAABB::getVertex011() const {
    MtVector3 result;
    const f32 t0 = mAABB.maxpos.y;
    const f32 t1 = mAABB.maxpos.z;
    result.x = mAABB.minpos.x;
    result.y = t0;
    result.z = t1;
    result.pad_ = 0.0f;
    return result;
}

void nZone::ShapeInfoAABB::setVertex011(const MtVector3& v) {
    if (v.x > mAABB.maxpos.x) {
        mAABB.minpos.x = mAABB.maxpos.x + -0.001f;
    } else {
        mAABB.minpos.x = v.x;
    }
    if (mAABB.minpos.y > v.y) {
        mAABB.maxpos.y = mAABB.minpos.y + 0.001f;
    } else {
        mAABB.maxpos.y = v.y;
    }
    if (mAABB.minpos.z > v.z) {
        mAABB.maxpos.z = mAABB.minpos.z + 0.001f;
    } else {
        mAABB.maxpos.z = v.z;
    }
}

MtVector3 nZone::ShapeInfoAABB::getVertex100() const {
    MtVector3 result;
    const f32 t0 = mAABB.minpos.y;
    const f32 t1 = mAABB.minpos.z;
    result.x = mAABB.maxpos.x;
    result.y = t0;
    result.z = t1;
    result.pad_ = 0.0f;
    return result;
}

void nZone::ShapeInfoAABB::setVertex100(const MtVector3& v) {
    if (mAABB.minpos.x > v.x) {
        mAABB.maxpos.x = mAABB.minpos.x + 0.001f;
    } else {
        mAABB.maxpos.x = v.x;
    }
    if (v.y > mAABB.maxpos.y) {
        mAABB.minpos.y = mAABB.maxpos.y + -0.001f;
    } else {
        mAABB.minpos.y = v.y;
    }
    if (v.z > mAABB.maxpos.z) {
        mAABB.minpos.z = mAABB.maxpos.z + -0.001f;
    } else {
        mAABB.minpos.z = v.z;
    }
}

MtVector3 nZone::ShapeInfoAABB::getVertex101() const {
    MtVector3 result;
    const f32 t0 = mAABB.minpos.y;
    const f32 t1 = mAABB.maxpos.z;
    result.x = mAABB.maxpos.x;
    result.y = t0;
    result.z = t1;
    result.pad_ = 0.0f;
    return result;
}

void nZone::ShapeInfoAABB::setVertex101(const MtVector3& v) {
    if (mAABB.minpos.x > v.x) {
        mAABB.maxpos.x = mAABB.minpos.x + 0.001f;
    } else {
        mAABB.maxpos.x = v.x;
    }
    if (v.y > mAABB.maxpos.y) {
        mAABB.minpos.y = mAABB.maxpos.y + -0.001f;
    } else {
        mAABB.minpos.y = v.y;
    }
    if (mAABB.minpos.z > v.z) {
        mAABB.maxpos.z = mAABB.minpos.z + 0.001f;
    } else {
        mAABB.maxpos.z = v.z;
    }
}

MtVector3 nZone::ShapeInfoAABB::getVertex110() const {
    MtVector3 result;
    const f32 t0 = mAABB.minpos.z;
    const f32 t1 = mAABB.maxpos.y;
    result.x = mAABB.maxpos.x;
    result.y = t1;
    result.z = t0;
    result.pad_ = 0.0f;
    return result;
}

void nZone::ShapeInfoAABB::setVertex110(const MtVector3& v) {
    if (mAABB.minpos.x > v.x) {
        mAABB.maxpos.x = mAABB.minpos.x + 0.001f;
    } else {
        mAABB.maxpos.x = v.x;
    }
    if (mAABB.minpos.y > v.y) {
        mAABB.maxpos.y = mAABB.minpos.y + 0.001f;
    } else {
        mAABB.maxpos.y = v.y;
    }
    if (v.z > mAABB.maxpos.z) {
        mAABB.minpos.z = mAABB.maxpos.z + -0.001f;
    } else {
        mAABB.minpos.z = v.z;
    }
}

static auto ddon_emit_0x01b88920 __attribute__((used)) = &nZone::ShapeInfoAABB::getVertex111;

void nZone::ShapeInfoAABB::setVertex111(const MtVector3& v) {
    if (mAABB.minpos.x > v.x) {
        mAABB.maxpos.x = mAABB.minpos.x + 0.001f;
    } else {
        mAABB.maxpos.x = v.x;
    }
    if (mAABB.minpos.y > v.y) {
        mAABB.maxpos.y = mAABB.minpos.y + 0.001f;
    } else {
        mAABB.maxpos.y = v.y;
    }
    if (mAABB.minpos.z > v.z) {
        mAABB.maxpos.z = mAABB.minpos.z + 0.001f;
    } else {
        mAABB.maxpos.z = v.z;
    }
}

inline nZone::ShapeInfoAABB::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nZone::ShapeInfoAABB::MyDTI nZone::ShapeInfoAABB::DTI("nZone::ShapeInfoAABB", &::nZone::ShapeInfoBase::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* nZone::ShapeInfoAABB::MyDTI::newInstance() const {
    return new (16u) ::nZone::ShapeInfoAABB;
}

const MtDTI& nZone::ShapeInfoArea::getDTI() const {
    return nZone::ShapeInfoArea::DTI;
}

void* nZone::ShapeInfoArea::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoArea::DTI)->memAlloc(sz, align, ::nZone::ShapeInfoArea::DTI.mID);
}

void* nZone::ShapeInfoArea::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void nZone::ShapeInfoArea::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoArea::DTI)->memFree(p_addr);
}

__attribute__((noinline)) nZone::ShapeInfoArea::ShapeInfoArea() {
    mHeight = 100.0f;
    mBottom = 0.0f;
    mConcaveStatus = 0;
    mFlgConvex = true;
    mVertex[0] = MtVector3(50.0f, 0.0f, 50.0f);
    mVertex[1] = MtVector3(50.0f, 0.0f, -50.0f);
    mVertex[2] = MtVector3(-50.0f, 0.0f, -50.0f);
    mVertex[3] = MtVector3(-50.0f, 0.0f, 50.0f);
    mConcaveCrossPos = MtVector3::Zero;
}

nZone::ShapeInfoArea::~ShapeInfoArea() {
}

void nZone::ShapeInfoArea::createProperty(MtPropertyList& s) {
    this->::nZone::ShapeInfoBase::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_VECTOR3, "mVertex", reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoArea::getVertex), reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoArea::setVertex), 160u, reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoArea::getVertexNumForProperty), reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoArea::setDummyU32));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_F32, "mBottom", reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoArea::getBottom), reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoArea::setBottom), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_F32, "mHeight", reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoArea::getHeight), reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoArea::setHeight), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), "mConcaveCrossPos", &mConcaveCrossPos, 1u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mFlgConvex", &mFlgConvex, 1u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mConcaveStatus", &mConcaveStatus, 1u, 0u);
}

__attribute__((weak)) bool nZone::ShapeInfoArea::copy(const nZone::ShapeInfoBase& copyShape) {
    DDON_STUB("nZone::ShapeInfoArea::copy")
    return {};
}

__attribute__((weak)) void nZone::ShapeInfoArea::applyWorldOffset(const MtVector3& offset) {
    DDON_STUB("nZone::ShapeInfoArea::applyWorldOffset")
    /* stub */
}

nZone::ShapeInfoBase::SHAPE_TYPE nZone::ShapeInfoArea::getShapeType() const {
    return SHAPE_TYPE_AREA;
}

__attribute__((weak)) bool nZone::ShapeInfoArea::isHit(const MtVector3& pos) const {
    DDON_STUB("nZone::ShapeInfoArea::isHit")
    return {};
}

__attribute__((weak)) bool nZone::ShapeInfoArea::isHitLineSegment(const MtLineSegment& ls) const {
    DDON_STUB("nZone::ShapeInfoArea::isHitLineSegment")
    return {};
}

__attribute__((weak)) bool nZone::ShapeInfoArea::isHitConvex(const MtGeomConvex& convex) const {
    DDON_STUB("nZone::ShapeInfoArea::isHitConvex")
    return {};
}

__attribute__((weak)) bool nZone::ShapeInfoArea::isIntersectAABB(const MtAABB& aabb) const {
    DDON_STUB("nZone::ShapeInfoArea::isIntersectAABB")
    return {};
}

__attribute__((weak)) bool nZone::ShapeInfoArea::getClosest(const MtVector3& pos, MtContact& contact) const {
    DDON_STUB("nZone::ShapeInfoArea::getClosest")
    return {};
}

__attribute__((weak)) void nZone::ShapeInfoArea::loadBinary(MtDataReader& r) {
    mDecay = r.readF32();
    mIsNativeData = (r.readU8() == 1);
    mHeight = r.readF32();
    mBottom = r.readF32();
    r.read(mVertex, sizeof(mVertex));
    r.read(&mConcaveCrossPos, sizeof(mConcaveCrossPos));
    mFlgConvex = (r.readU8() != 0);
    mConcaveStatus = r.readU32();
    repairHeightAndBottom();
}

__attribute__((weak)) void nZone::ShapeInfoArea::saveBinary(MtDataWriter& w) {
    repairHeightAndBottom();
    w.writeF32(mDecay);
    w.writeU8(static_cast<u8>(mIsNativeData));
    w.writeF32(mHeight);
    w.writeF32(mBottom);
    w.write(mVertex, sizeof(mVertex));
    w.write(&mConcaveCrossPos, sizeof(mConcaveCrossPos));
    w.writeU8(static_cast<u8>(mFlgConvex));
    w.writeU32(mConcaveStatus);
}

bool nZone::ShapeInfoArea::isGetAABB() const {
    return true;
}

__attribute__((weak)) MtAABB nZone::ShapeInfoArea::getAABB() const {
    MtAABB aabb = MtAABB::Empty;
    for (u32 i = 0; i < VERTEX_NUM; ++i) {
        aabb.inflate(mVertex[i]);
    }
    aabb.maxpos.y += mHeight;
    return aabb;
}

bool nZone::ShapeInfoArea::isGetBoundingSphere() const {
    return true;
}

__attribute__((weak)) MtSphere nZone::ShapeInfoArea::getBoundingSphere() const {
    DDON_STUB("nZone::ShapeInfoArea::getBoundingSphere")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector3 nZone::ShapeInfoArea::getCenterPos() const {
    DDON_STUB("nZone::ShapeInfoArea::getCenterPos")
    __builtin_unreachable();
}

__attribute__((weak)) void nZone::ShapeInfoArea::setCenterPos(const MtVector3& pos) {
    DDON_STUB("nZone::ShapeInfoArea::setCenterPos")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoArea::movePosition(const MtVector3& AddPos) {
    DDON_STUB("nZone::ShapeInfoArea::movePosition")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoArea::movePosition(nZone::ShapeInfoBase& OutputShape, const MtVector3& AddPos) const {
    DDON_STUB("nZone::ShapeInfoArea::movePosition")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoArea::rotation(const MtMatrix& RotateMatrix) {
    DDON_STUB("nZone::ShapeInfoArea::rotation")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoArea::rotation(nZone::ShapeInfoBase& OutputShape, const MtMatrix& RotateMatrix) const {
    DDON_STUB("nZone::ShapeInfoArea::rotation")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoArea::rotationAngle(const MtVector3& RotateRadian) {
    DDON_STUB("nZone::ShapeInfoArea::rotationAngle")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoArea::rotationAngle(nZone::ShapeInfoBase& OutputShape, const MtVector3& RotateRadian) const {
    DDON_STUB("nZone::ShapeInfoArea::rotationAngle")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoArea::mulMatrix(const MtMatrix& MulMatrix) {
    DDON_STUB("nZone::ShapeInfoArea::mulMatrix")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoArea::mulMatrix(nZone::ShapeInfoBase& OutputShape, const MtMatrix& MulMatrix) const {
    DDON_STUB("nZone::ShapeInfoArea::mulMatrix")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoArea::mulMatrixByRotTransXYZ(const MtVector3& RotateRadianXYZ, const MtVector3& Translate) {
    DDON_STUB("nZone::ShapeInfoArea::mulMatrixByRotTransXYZ")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoArea::mulMatrixByRotTransXYZ(nZone::ShapeInfoBase& OutputShape, const MtVector3& RotateRadianXYZ, const MtVector3& Translate) const {
    DDON_STUB("nZone::ShapeInfoArea::mulMatrixByRotTransXYZ")
    /* stub */
}

__attribute__((weak)) f32 nZone::ShapeInfoArea::calcWeight(const MtVector3& pos) const {
    DDON_STUB("nZone::ShapeInfoArea::calcWeight")
    return {};
}

MtVector3 nZone::ShapeInfoArea::getVertex(u32 index) const {
    return mVertex[index];
}

void nZone::ShapeInfoArea::setVertex(const MtVector3& v, u32 index) {
    mVertex[index].x = v.x;
    mVertex[index].y = v.y;
    mVertex[index].z = v.z;
    mVertex[index].pad_ = 0.0f;
    mVertex[index].y = mBottom;
    updateConcaveParam();
}

static auto ddon_emit_0x01b87770 __attribute__((used)) = &nZone::ShapeInfoArea::getBottom;

void nZone::ShapeInfoArea::setBottom(f32 bottom) {
    mBottom = bottom;
    mVertex[0].y = bottom;
    mVertex[1].y = bottom;
    mVertex[2].y = bottom;
    mVertex[3].y = bottom;
}

static auto ddon_emit_0x01b87780 __attribute__((used)) = &nZone::ShapeInfoArea::getHeight;

__attribute__((weak)) void nZone::ShapeInfoArea::setHeight(f32 height) {
    mHeight = height > 0.0625f ? height : 0.0625f;
    repairHeightAndBottom();
}

__attribute__((weak)) MtVector3 nZone::ShapeInfoArea::calcCenter() const {
    DDON_STUB("nZone::ShapeInfoArea::calcCenter")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector3 nZone::ShapeInfoArea::getSupport(const MtVector3& v) const {
    DDON_STUB("nZone::ShapeInfoArea::getSupport")
    __builtin_unreachable();
}

u32 nZone::ShapeInfoArea::getVertexNumForProperty() const {
    return 4;
}

__attribute__((weak)) void nZone::ShapeInfoArea::setDummyU32(u32) {
}

__attribute__((weak)) MtVector3 nZone::ShapeInfoArea::closestSub(const MtVector3& pos, const MtVector3& p0, const MtVector3& p0_, const MtVector3& p1, const MtVector3& p1_, f32& len) const {
    DDON_STUB("nZone::ShapeInfoArea::closestSub")
    __builtin_unreachable();
}

__attribute__((weak)) bool nZone::ShapeInfoArea::distanceSqSub(const MtRay& ray, const MtVector3& p0, const MtVector3& p0_, const MtVector3& p1, const MtVector3& p1_, MtVector3& pos) const {
    DDON_STUB("nZone::ShapeInfoArea::distanceSqSub")
    return {};
}

__attribute__((weak)) bool nZone::ShapeInfoArea::isConvex_Private() const {
    const MtTriangle BottomTriangle[4] = {
        MtTriangle(mVertex[1], mVertex[3], mVertex[2]),
        MtTriangle(mVertex[0], mVertex[2], mVertex[3]),
        MtTriangle(mVertex[1], mVertex[3], mVertex[0]),
        MtTriangle(mVertex[0], mVertex[2], mVertex[1]),
    };
    for (s32 i = 0; i < 4; ++i) {
        const u32 vid = MtCollision::getCoGIdFast(BottomTriangle[i], mVertex[i]);
        if (vid != MtCollisionUtil::TRI_VORONOI_EDGE01) {
            return false;
        }
    }
    return true;
}

__attribute__((weak)) void nZone::ShapeInfoArea::updateConcaveParam() {
    mFlgConvex = isConvex_Private();
    mConcaveStatus = CONCAVE_DEFAULT;
    if (mFlgConvex) {
        return;
    }
    
    const MtLineSegment ls03(mVertex[0], mVertex[3]);
    const MtLineSegment ls12(mVertex[1], mVertex[2]);
    f32 toi03_12;
    const f32 distSq03_12 = MtCollision::sqrDistance(ls03, ls12, &toi03_12, nullptr, 0.001f);
    if (distSq03_12 < 1.1920929e-7f) {
        mConcaveStatus = CONCAVE_CROSS_0312;
        mConcaveCrossPos = ls03.getPos(toi03_12);
        return;
    }
    
    const MtLineSegment ls01(mVertex[0], mVertex[1]);
    const MtLineSegment ls23(mVertex[2], mVertex[3]);
    f32 toi01_23;
    const f32 distSq01_23 = MtCollision::sqrDistance(ls01, ls23, &toi01_23, nullptr, 0.001f);
    if (distSq01_23 < 1.1920929e-7f) {
        mConcaveStatus = CONCAVE_CROSS_0123;
        mConcaveCrossPos = ls01.getPos(toi01_23);
        return;
    }
    
    static const u32 CheckVertexIndex13[2] = {1, 3};
    static const u32 CheckVertexIndex02[2] = {0, 2};
    const MtTriangle BottomTriangle[VERTEX_NUM] = {
        MtTriangle(mVertex[1], mVertex[3], mVertex[2]),
        MtTriangle(mVertex[0], mVertex[2], mVertex[3]),
        MtTriangle(mVertex[1], mVertex[3], mVertex[0]),
        MtTriangle(mVertex[0], mVertex[2], mVertex[1]),
    };
    
    for (u32 i = 0; i < sizeof(CheckVertexIndex13) / sizeof(*CheckVertexIndex13); ++i) {
        const MtTriangle& CheckTriangle = BottomTriangle[CheckVertexIndex13[i]];
        const u32 vid = MtCollision::getCoGIdFast(CheckTriangle, mVertex[CheckVertexIndex13[i]]);
        if (vid != MtCollisionUtil::TRI_VORONOI_EDGE01) {
            mConcaveStatus = CONCAVE_VERTEX_ROLL_INVERSE;
            break;
        }
    }
    if (mConcaveStatus != CONCAVE_VERTEX_ROLL_INVERSE) {
        return;
    }
    
    for (u32 i = 0; i < sizeof(CheckVertexIndex02) / sizeof(*CheckVertexIndex02); ++i) {
        const MtTriangle& CheckTriangle = BottomTriangle[CheckVertexIndex02[i]];
        const u32 vid = MtCollision::getCoGIdFast(CheckTriangle, mVertex[CheckVertexIndex02[i]]);
        if (vid == MtCollisionUtil::TRI_VORONOI_V2) {
            mConcaveStatus = CONCAVE_DEFAULT;
            return;
        }
    }
}

__attribute__((weak)) void nZone::ShapeInfoArea::updateConcaveCrossPos() {
    DDON_STUB("nZone::ShapeInfoArea::updateConcaveCrossPos")
    /* stub */
}

__attribute__((weak)) MtTriangle nZone::ShapeInfoArea::getBottomTriangle_Private(u32 TriangleIndex) const {
    DDON_STUB("nZone::ShapeInfoArea::getBottomTriangle_Private")
    __builtin_unreachable();
}

inline nZone::ShapeInfoArea::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nZone::ShapeInfoArea::MyDTI nZone::ShapeInfoArea::DTI("nZone::ShapeInfoArea", &::nZone::ShapeInfoBase::DTI, 112ul, 0u, 0u);

__attribute__((weak)) MtObject* nZone::ShapeInfoArea::MyDTI::newInstance() const {
    return new (16u) ::nZone::ShapeInfoArea;
}

const MtDTI& nZone::ShapeInfoBase::getDTI() const {
    return nZone::ShapeInfoBase::DTI;
}

inline void nZone::ShapeInfoBase::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoBase::DTI)->memFree(p_addr);
}

nZone::ShapeInfoBase::~ShapeInfoBase() {
}

__attribute__((weak)) void nZone::ShapeInfoBase::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "mIsNativeData", &mIsNativeData, 1u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_VECTOR3, "CenterPos", reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoBase::getCenterPos), reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoBase::setCenterPos), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), "mDecay", &mDecay, 0u, 0u);
}

bool nZone::ShapeInfoBase::copy(const nZone::ShapeInfoBase& copyShape) {
    mDecay = copyShape.mDecay;
    return true;
}

nZone::ShapeInfoBase::SHAPE_TYPE nZone::ShapeInfoBase::getShapeType() const {
    return SHAPE_TYPE_NONE;
}

bool nZone::ShapeInfoBase::isHit(const MtVector3& pos) const {
    return false;
}

bool nZone::ShapeInfoBase::isHitLineSegment(const MtLineSegment& ls) const {
    return false;
}

bool nZone::ShapeInfoBase::isHitConvex(const MtGeomConvex& convex) const {
    return false;
}

bool nZone::ShapeInfoBase::isIntersectAABB(const MtAABB& aabb) const {
    return false;
}

bool nZone::ShapeInfoBase::getClosest(const MtVector3& pos, MtContact& contact) const {
    return false;
}

void nZone::ShapeInfoBase::loadBinary(MtDataReader& r) {
    f32 t0 = r.readF32();
    mDecay = t0;
    u32 t1 = r.mSeekPt;
    u32 t2 = r.mBufsiz;
    if (t1 >= t2) {
        if (r.refill()) {
            u32 t4 = r.mSeekPt;
            u8* t5 = r.mBuffer;
            u8 t6 = t5[r.mSeekPt];
            r.mSeekPt = t4 + 1u;
            mIsNativeData = t6 == 1;
        } else {
            mIsNativeData = false;
        }
    } else {
        u8* t5 = r.mBuffer;
        u8 t6 = t5[r.mSeekPt];
        r.mSeekPt = t1 + 1u;
        mIsNativeData = t6 == 1;
    }
}

void nZone::ShapeInfoBase::saveBinary(MtDataWriter& w) {
    w.writeF32(mDecay);
    bool t0 = mIsNativeData;
    if (w.mSeekPt >= w.mBufsiz) {
        w.flush();
    }
    w.mBuffer[w.mSeekPt] = static_cast<u8>(t0);
    w.mSeekPt = w.mSeekPt + 1u;
}

bool nZone::ShapeInfoBase::isGetAABB() const {
    return false;
}

MtAABB nZone::ShapeInfoBase::getAABB() const {
    return ::MtAABB::Zero;
}

bool nZone::ShapeInfoBase::isGetBoundingSphere() const {
    return false;
}

__attribute__((weak)) MtSphere nZone::ShapeInfoBase::getBoundingSphere() const {
    DDON_STUB("nZone::ShapeInfoBase::getBoundingSphere")
    __builtin_unreachable();
}

MtVector3 nZone::ShapeInfoBase::getCenterPos() const {
    MtVector3 result;
    result.x = 0.0f;
    result.y = 50.0f;
    result.z = 0.0f;
    result.pad_ = 0.0f;
    return result;
}

__attribute__((weak)) void nZone::ShapeInfoBase::rotationAngle(const MtVector3& RotateRadian) {
    DDON_STUB("nZone::ShapeInfoBase::rotationAngle")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoBase::rotationAngle(nZone::ShapeInfoBase& OutputShape, const MtVector3& RotateRadian) const {
    DDON_STUB("nZone::ShapeInfoBase::rotationAngle")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoBase::mulMatrixByRotTransXYZ(const MtVector3& RotateRadianXYZ, const MtVector3& Translate) {
    DDON_STUB("nZone::ShapeInfoBase::mulMatrixByRotTransXYZ")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoBase::mulMatrixByRotTransXYZ(nZone::ShapeInfoBase& OutputShape, const MtVector3& RotateRadianXYZ, const MtVector3& Translate) const {
    DDON_STUB("nZone::ShapeInfoBase::mulMatrixByRotTransXYZ")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoBase::mulMatrixByRotTransQuaternion(const MtQuaternion& qt, const MtVector3& Translate) {
    DDON_STUB("nZone::ShapeInfoBase::mulMatrixByRotTransQuaternion")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoBase::mulMatrixByRotTransQuaternion(nZone::ShapeInfoBase& OutputShape, const MtQuaternion& qt, const MtVector3& Translate) const {
    DDON_STUB("nZone::ShapeInfoBase::mulMatrixByRotTransQuaternion")
    /* stub */
}

f32 nZone::ShapeInfoBase::calcWeight(const MtVector3& pos) const {
    return 0.0f;
}

inline nZone::ShapeInfoBase::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nZone::ShapeInfoBase::MyDTI nZone::ShapeInfoBase::DTI("nZone::ShapeInfoBase", &::MtObject::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* nZone::ShapeInfoBase::MyDTI::newInstance() const {
    DDON_STUB("nZone::ShapeInfoBase::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nZone::ShapeInfoCapsule::getDTI() const {
    return nZone::ShapeInfoCapsule::DTI;
}

void* nZone::ShapeInfoCapsule::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoCapsule::DTI)->memAlloc(sz, align, ::nZone::ShapeInfoCapsule::DTI.mID);
}

inline void nZone::ShapeInfoCapsule::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoCapsule::DTI)->memFree(p_addr);
}

nZone::ShapeInfoCapsule::ShapeInfoCapsule() {
    mCapsule.p0 = MtVector3(-50.0f, 50.0f, 0.0f);
    mCapsule.p1 = MtVector3(50.0f, 50.0f, 0.0f);
    mCapsule.r = 50.0f;
}

nZone::ShapeInfoCapsule::~ShapeInfoCapsule() {
}

__attribute__((weak)) void nZone::ShapeInfoCapsule::createProperty(MtPropertyList& s) {
    DDON_STUB("nZone::ShapeInfoCapsule::createProperty")
    /* stub */
}

__attribute__((weak)) bool nZone::ShapeInfoCapsule::copy(const nZone::ShapeInfoBase& copyShape) {
    DDON_STUB("nZone::ShapeInfoCapsule::copy")
    return {};
}

__attribute__((weak)) void nZone::ShapeInfoCapsule::applyWorldOffset(const MtVector3& offset) {
    DDON_STUB("nZone::ShapeInfoCapsule::applyWorldOffset")
    /* stub */
}

nZone::ShapeInfoBase::SHAPE_TYPE nZone::ShapeInfoCapsule::getShapeType() const {
    return SHAPE_TYPE_CAPSULE;
}

bool nZone::ShapeInfoCapsule::isHit(const MtVector3& pos) const {
    return ::MtCollision::intersect(mCapsule, pos);
}

bool nZone::ShapeInfoCapsule::isHitLineSegment(const MtLineSegment& ls) const {
    return ::MtCollision::intersect(mCapsule, ls);
}

bool nZone::ShapeInfoCapsule::isHitConvex(const MtGeomConvex& convex) const {
    return convex.isIntersect(mCapsule);
}

bool nZone::ShapeInfoCapsule::isIntersectAABB(const MtAABB& aabb) const {
    return ::MtCollision::intersect(mCapsule, aabb);
}

__attribute__((weak)) bool nZone::ShapeInfoCapsule::getClosest(const MtVector3& pos, MtContact& contact) const {
    DDON_STUB("nZone::ShapeInfoCapsule::getClosest")
    return {};
}

void nZone::ShapeInfoCapsule::loadBinary(MtDataReader& r) {
    f32 t0 = r.readF32();
    mDecay = t0;
    u32 t1 = r.mSeekPt;
    u32 t2 = r.mBufsiz;
    if (t1 >= t2) {
        if (r.refill()) {
            u32 t4 = r.mSeekPt;
            u8* t5 = r.mBuffer;
            u8 t6 = t5[r.mSeekPt];
            r.mSeekPt = t4 + 1u;
            mIsNativeData = t6 == 1;
            r.read(static_cast<void*>(&mCapsule), 48u);
        } else {
            mIsNativeData = false;
            r.read(static_cast<void*>(&mCapsule), 48u);
        }
    } else {
        u8* t5 = r.mBuffer;
        u8 t6 = t5[r.mSeekPt];
        r.mSeekPt = t1 + 1u;
        mIsNativeData = t6 == 1;
        r.read(static_cast<void*>(&mCapsule), 48u);
    }
}

void nZone::ShapeInfoCapsule::saveBinary(MtDataWriter& w) {
    w.writeF32(mDecay);
    bool t0 = mIsNativeData;
    if (w.mSeekPt >= w.mBufsiz) {
        w.flush();
    }
    w.mBuffer[w.mSeekPt] = static_cast<u8>(t0);
    w.mSeekPt = w.mSeekPt + 1u;
    w.write(static_cast<const void*>(&mCapsule), 48u);
}

bool nZone::ShapeInfoCapsule::isGetAABB() const {
    return true;
}

__attribute__((weak)) MtAABB nZone::ShapeInfoCapsule::getAABB() const {
    DDON_STUB("nZone::ShapeInfoCapsule::getAABB")
    __builtin_unreachable();
}

bool nZone::ShapeInfoCapsule::isGetBoundingSphere() const {
    return true;
}

__attribute__((weak)) MtSphere nZone::ShapeInfoCapsule::getBoundingSphere() const {
    DDON_STUB("nZone::ShapeInfoCapsule::getBoundingSphere")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector3 nZone::ShapeInfoCapsule::getCenterPos() const {
    DDON_STUB("nZone::ShapeInfoCapsule::getCenterPos")
    __builtin_unreachable();
}

__attribute__((weak)) void nZone::ShapeInfoCapsule::setCenterPos(const MtVector3& pos) {
    DDON_STUB("nZone::ShapeInfoCapsule::setCenterPos")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoCapsule::movePosition(const MtVector3& AddPos) {
    DDON_STUB("nZone::ShapeInfoCapsule::movePosition")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoCapsule::movePosition(nZone::ShapeInfoBase& OutputShape, const MtVector3& AddPos) const {
    DDON_STUB("nZone::ShapeInfoCapsule::movePosition")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoCapsule::rotation(const MtMatrix& RotateMatrix) {
    DDON_STUB("nZone::ShapeInfoCapsule::rotation")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoCapsule::rotation(nZone::ShapeInfoBase& OutputShape, const MtMatrix& RotateMatrix) const {
    DDON_STUB("nZone::ShapeInfoCapsule::rotation")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoCapsule::mulMatrix(const MtMatrix& MulMatrix) {
    DDON_STUB("nZone::ShapeInfoCapsule::mulMatrix")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoCapsule::mulMatrix(nZone::ShapeInfoBase& OutputShape, const MtMatrix& MulMatrix) const {
    DDON_STUB("nZone::ShapeInfoCapsule::mulMatrix")
    /* stub */
}

__attribute__((weak)) f32 nZone::ShapeInfoCapsule::calcWeight(const MtVector3& pos) const {
    DDON_STUB("nZone::ShapeInfoCapsule::calcWeight")
    return {};
}

inline nZone::ShapeInfoCapsule::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nZone::ShapeInfoCapsule::MyDTI nZone::ShapeInfoCapsule::DTI("nZone::ShapeInfoCapsule", &::nZone::ShapeInfoBase::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* nZone::ShapeInfoCapsule::MyDTI::newInstance() const {
    DDON_STUB("nZone::ShapeInfoCapsule::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nZone::ShapeInfoCone::getDTI() const {
    return nZone::ShapeInfoCone::DTI;
}

void* nZone::ShapeInfoCone::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoCone::DTI)->memAlloc(sz, align, ::nZone::ShapeInfoCone::DTI.mID);
}

void* nZone::ShapeInfoCone::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void nZone::ShapeInfoCone::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoCone::DTI)->memFree(p_addr);
}

__attribute__((noinline)) nZone::ShapeInfoCone::ShapeInfoCone() {
    mHeight = 100.0f;
    mTopRadius = 100.0f;
    mPos = MtVector3::Zero;
    mBottomRadius = 50.0f;
}

nZone::ShapeInfoCone::~ShapeInfoCone() {
}

void nZone::ShapeInfoCone::createProperty(MtPropertyList& s) {
    this->::nZone::ShapeInfoBase::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_F32, "mHeight", reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoCone::getHeight), reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoCone::setHeight), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), "mTopRadius", &mTopRadius, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mBottomRadius", &mBottomRadius, 0u, 0u);
}

__attribute__((weak)) bool nZone::ShapeInfoCone::copy(const nZone::ShapeInfoBase& copyShape) {
    DDON_STUB("nZone::ShapeInfoCone::copy")
    return {};
}

__attribute__((weak)) void nZone::ShapeInfoCone::applyWorldOffset(const MtVector3& offset) {
    DDON_STUB("nZone::ShapeInfoCone::applyWorldOffset")
    /* stub */
}

nZone::ShapeInfoBase::SHAPE_TYPE nZone::ShapeInfoCone::getShapeType() const {
    return SHAPE_TYPE_CONE;
}

__attribute__((weak)) bool nZone::ShapeInfoCone::isHit(const MtVector3& pos) const {
    DDON_STUB("nZone::ShapeInfoCone::isHit")
    return {};
}

bool nZone::ShapeInfoCone::isHitLineSegment(const MtLineSegment& ls) const {
    return false;
}

bool nZone::ShapeInfoCone::isHitConvex(const MtGeomConvex& convex) const {
    return false;
}

__attribute__((weak)) bool nZone::ShapeInfoCone::isIntersectAABB(const MtAABB& aabb) const {
    DDON_STUB("nZone::ShapeInfoCone::isIntersectAABB")
    return {};
}

__attribute__((weak)) bool nZone::ShapeInfoCone::getClosest(const MtVector3& pos, MtContact& contact) const {
    DDON_STUB("nZone::ShapeInfoCone::getClosest")
    return {};
}

void nZone::ShapeInfoCone::loadBinary(MtDataReader& r) {
    f32 t0 = r.readF32();
    mDecay = t0;
    u32 t1 = r.mSeekPt;
    u32 t2 = r.mBufsiz;
    if (t1 >= t2) {
        if (r.refill()) {
            u32 t4 = r.mSeekPt;
            u8* t5 = r.mBuffer;
            u8 t6 = t5[r.mSeekPt];
            r.mSeekPt = t4 + 1u;
            mIsNativeData = t6 == 1;
            f32 t7 = r.readF32();
            mHeight = t7;
            f32 t8 = r.readF32();
            mTopRadius = t8;
            r.read(static_cast<void*>(&mPos), 16u);
            f32 t11 = r.readF32();
            mBottomRadius = t11;
        } else {
            mIsNativeData = false;
            f32 t7 = r.readF32();
            mHeight = t7;
            f32 t8 = r.readF32();
            mTopRadius = t8;
            r.read(static_cast<void*>(&mPos), 16u);
            f32 t11 = r.readF32();
            mBottomRadius = t11;
        }
    } else {
        u8* t5 = r.mBuffer;
        u8 t6 = t5[r.mSeekPt];
        r.mSeekPt = t1 + 1u;
        mIsNativeData = t6 == 1;
        f32 t7 = r.readF32();
        mHeight = t7;
        f32 t8 = r.readF32();
        mTopRadius = t8;
        r.read(static_cast<void*>(&mPos), 16u);
        f32 t11 = r.readF32();
        mBottomRadius = t11;
    }
}

void nZone::ShapeInfoCone::saveBinary(MtDataWriter& w) {
    w.writeF32(mDecay);
    bool t0 = mIsNativeData;
    if (w.mSeekPt >= w.mBufsiz) {
        w.flush();
    }
    w.mBuffer[w.mSeekPt] = static_cast<u8>(t0);
    w.mSeekPt = w.mSeekPt + 1u;
    w.writeF32(mHeight);
    w.writeF32(mTopRadius);
    w.write(static_cast<const void*>(&mPos), 16u);
    w.writeF32(mBottomRadius);
}

bool nZone::ShapeInfoCone::isGetAABB() const {
    return true;
}

__attribute__((weak)) MtAABB nZone::ShapeInfoCone::getAABB() const {
    const f32 RadiusMax = (mBottomRadius > mTopRadius) ? mBottomRadius : mTopRadius;
    const MtVector3 minpos(mPos.x - RadiusMax, mPos.y, mPos.z - RadiusMax);
    const MtVector3 maxpos(mPos.x + RadiusMax, mPos.y + mHeight, mPos.z + RadiusMax);
    return MtAABB(minpos, maxpos);
}

bool nZone::ShapeInfoCone::isGetBoundingSphere() const {
    return true;
}

__attribute__((weak)) MtSphere nZone::ShapeInfoCone::getBoundingSphere() const {
    DDON_STUB("nZone::ShapeInfoCone::getBoundingSphere")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector3 nZone::ShapeInfoCone::getCenterPos() const {
    DDON_STUB("nZone::ShapeInfoCone::getCenterPos")
    __builtin_unreachable();
}

__attribute__((weak)) void nZone::ShapeInfoCone::setCenterPos(const MtVector3& pos) {
    DDON_STUB("nZone::ShapeInfoCone::setCenterPos")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoCone::movePosition(const MtVector3& AddPos) {
    DDON_STUB("nZone::ShapeInfoCone::movePosition")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoCone::movePosition(nZone::ShapeInfoBase& OutputShape, const MtVector3& AddPos) const {
    DDON_STUB("nZone::ShapeInfoCone::movePosition")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoCone::mulMatrix(const MtMatrix& MulMatrix) {
    DDON_STUB("nZone::ShapeInfoCone::mulMatrix")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoCone::mulMatrix(nZone::ShapeInfoBase& OutputShape, const MtMatrix& MulMatrix) const {
    DDON_STUB("nZone::ShapeInfoCone::mulMatrix")
    /* stub */
}

__attribute__((weak)) f32 nZone::ShapeInfoCone::calcWeight(const MtVector3& pos) const {
    DDON_STUB("nZone::ShapeInfoCone::calcWeight")
    return {};
}

static auto ddon_emit_0x01b88d70 __attribute__((used)) = &nZone::ShapeInfoCone::getHeight;

__attribute__((weak)) void nZone::ShapeInfoCone::setHeight(f32 height) {
    DDON_STUB("nZone::ShapeInfoCone::setHeight")
    /* stub */
}

inline nZone::ShapeInfoCone::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nZone::ShapeInfoCone::MyDTI nZone::ShapeInfoCone::DTI("nZone::ShapeInfoCone", &::nZone::ShapeInfoBase::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* nZone::ShapeInfoCone::MyDTI::newInstance() const {
    DDON_STUB("nZone::ShapeInfoCone::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nZone::ShapeInfoCylinder::getDTI() const {
    return nZone::ShapeInfoCylinder::DTI;
}

void* nZone::ShapeInfoCylinder::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoCylinder::DTI)->memAlloc(sz, align, ::nZone::ShapeInfoCylinder::DTI.mID);
}

void* nZone::ShapeInfoCylinder::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void nZone::ShapeInfoCylinder::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoCylinder::DTI)->memFree(p_addr);
}

__attribute__((noinline)) nZone::ShapeInfoCylinder::ShapeInfoCylinder() {
    mCylinder.p0 = MtVector3(0.0f, 100.0f, 0.0f);
    mCylinder.p1 = MtVector3::Zero;
    mCylinder.r = 50.0f;
}

nZone::ShapeInfoCylinder::~ShapeInfoCylinder() {
}

void nZone::ShapeInfoCylinder::createProperty(MtPropertyList& s) {
    this->::nZone::ShapeInfoBase::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "Position0", &mCylinder.p0, 2u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "Position1", &mCylinder.p1, 2u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "Radius", &mCylinder.r, 2u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mCylinder", &mCylinder, 0u, 0u);
}

__attribute__((weak)) bool nZone::ShapeInfoCylinder::copy(const nZone::ShapeInfoBase& copyShape) {
    DDON_STUB("nZone::ShapeInfoCylinder::copy")
    return {};
}

__attribute__((weak)) void nZone::ShapeInfoCylinder::applyWorldOffset(const MtVector3& offset) {
    DDON_STUB("nZone::ShapeInfoCylinder::applyWorldOffset")
    /* stub */
}

nZone::ShapeInfoBase::SHAPE_TYPE nZone::ShapeInfoCylinder::getShapeType() const {
    return SHAPE_TYPE_CYLINDER;
}

bool nZone::ShapeInfoCylinder::isHit(const MtVector3& pos) const {
    return ::MtCollision::intersect(mCylinder, pos);
}

bool nZone::ShapeInfoCylinder::isHitLineSegment(const MtLineSegment& ls) const {
    return ::MtCollision::intersect(mCylinder, ls);
}

bool nZone::ShapeInfoCylinder::isHitConvex(const MtGeomConvex& convex) const {
    return convex.isIntersect(mCylinder);
}

bool nZone::ShapeInfoCylinder::isIntersectAABB(const MtAABB& aabb) const {
    return ::MtCollision::intersect(mCylinder, aabb);
}

__attribute__((weak)) bool nZone::ShapeInfoCylinder::getClosest(const MtVector3& pos, MtContact& contact) const {
    DDON_STUB("nZone::ShapeInfoCylinder::getClosest")
    return {};
}

void nZone::ShapeInfoCylinder::loadBinary(MtDataReader& r) {
    f32 t0 = r.readF32();
    mDecay = t0;
    u32 t1 = r.mSeekPt;
    u32 t2 = r.mBufsiz;
    if (t1 >= t2) {
        if (r.refill()) {
            u32 t4 = r.mSeekPt;
            u8* t5 = r.mBuffer;
            u8 t6 = t5[r.mSeekPt];
            r.mSeekPt = t4 + 1u;
            mIsNativeData = t6 == 1;
            r.read(static_cast<void*>(&mCylinder), 48u);
        } else {
            mIsNativeData = false;
            r.read(static_cast<void*>(&mCylinder), 48u);
        }
    } else {
        u8* t5 = r.mBuffer;
        u8 t6 = t5[r.mSeekPt];
        r.mSeekPt = t1 + 1u;
        mIsNativeData = t6 == 1;
        r.read(static_cast<void*>(&mCylinder), 48u);
    }
}

void nZone::ShapeInfoCylinder::saveBinary(MtDataWriter& w) {
    w.writeF32(mDecay);
    bool t0 = mIsNativeData;
    if (w.mSeekPt >= w.mBufsiz) {
        w.flush();
    }
    w.mBuffer[w.mSeekPt] = static_cast<u8>(t0);
    w.mSeekPt = w.mSeekPt + 1u;
    w.write(static_cast<const void*>(&mCylinder), 48u);
}

bool nZone::ShapeInfoCylinder::isGetAABB() const {
    return true;
}

__attribute__((weak)) MtAABB nZone::ShapeInfoCylinder::getAABB() const {
    MtAABB aabb;
    mCylinder.getBoundingAABB(aabb);
    return aabb;
}

bool nZone::ShapeInfoCylinder::isGetBoundingSphere() const {
    return true;
}

__attribute__((weak)) MtSphere nZone::ShapeInfoCylinder::getBoundingSphere() const {
    DDON_STUB("nZone::ShapeInfoCylinder::getBoundingSphere")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector3 nZone::ShapeInfoCylinder::getCenterPos() const {
    DDON_STUB("nZone::ShapeInfoCylinder::getCenterPos")
    __builtin_unreachable();
}

__attribute__((weak)) void nZone::ShapeInfoCylinder::setCenterPos(const MtVector3& pos) {
    DDON_STUB("nZone::ShapeInfoCylinder::setCenterPos")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoCylinder::movePosition(const MtVector3& AddPos) {
    DDON_STUB("nZone::ShapeInfoCylinder::movePosition")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoCylinder::movePosition(nZone::ShapeInfoBase& OutputShape, const MtVector3& AddPos) const {
    DDON_STUB("nZone::ShapeInfoCylinder::movePosition")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoCylinder::rotation(const MtMatrix& RotateMatrix) {
    DDON_STUB("nZone::ShapeInfoCylinder::rotation")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoCylinder::rotation(nZone::ShapeInfoBase& OutputShape, const MtMatrix& RotateMatrix) const {
    DDON_STUB("nZone::ShapeInfoCylinder::rotation")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoCylinder::mulMatrix(const MtMatrix& MulMatrix) {
    DDON_STUB("nZone::ShapeInfoCylinder::mulMatrix")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoCylinder::mulMatrix(nZone::ShapeInfoBase& OutputShape, const MtMatrix& MulMatrix) const {
    DDON_STUB("nZone::ShapeInfoCylinder::mulMatrix")
    /* stub */
}

__attribute__((weak)) f32 nZone::ShapeInfoCylinder::calcWeight(const MtVector3& pos) const {
    DDON_STUB("nZone::ShapeInfoCylinder::calcWeight")
    return {};
}

inline nZone::ShapeInfoCylinder::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nZone::ShapeInfoCylinder::MyDTI nZone::ShapeInfoCylinder::DTI("nZone::ShapeInfoCylinder", &::nZone::ShapeInfoBase::DTI, 64ul, 0u, 0u);

__attribute__((weak)) MtObject* nZone::ShapeInfoCylinder::MyDTI::newInstance() const {
    return new (16u) ::nZone::ShapeInfoCylinder;
}

const MtDTI& nZone::ShapeInfoGlobal::getDTI() const {
    return nZone::ShapeInfoGlobal::DTI;
}

inline void nZone::ShapeInfoGlobal::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoGlobal::DTI)->memFree(p_addr);
}

nZone::ShapeInfoGlobal::~ShapeInfoGlobal() {
}

nZone::ShapeInfoBase::SHAPE_TYPE nZone::ShapeInfoGlobal::getShapeType() const {
    return SHAPE_TYPE_GLOBAL;
}

bool nZone::ShapeInfoGlobal::isHit(const MtVector3& pos) const {
    return true;
}

bool nZone::ShapeInfoGlobal::isHitLineSegment(const MtLineSegment& ls) const {
    return true;
}

bool nZone::ShapeInfoGlobal::isHitConvex(const MtGeomConvex& convex) const {
    return true;
}

bool nZone::ShapeInfoGlobal::isIntersectAABB(const MtAABB& aabb) const {
    return true;
}

bool nZone::ShapeInfoGlobal::getClosest(const MtVector3& pos, MtContact& contact) const {
    contact.pos.x = pos.x;
    contact.pos.y = pos.y;
    contact.pos.z = pos.z;
    contact.pos.pad_ = 0.0f;
    contact.normal.x = ::MtVector3::Zero.x;
    contact.normal.y = ::MtVector3::Zero.y;
    contact.normal.z = ::MtVector3::Zero.z;
    contact.normal.pad_ = 0.0f;
    contact.distance = 0.0f;
    contact.toi = 0.0f;
    contact.bFind = true;
    return true;
}

MtVector3 nZone::ShapeInfoGlobal::getCenterPos() const {
    return ::MtVector3::Zero;
}

inline nZone::ShapeInfoGlobal::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nZone::ShapeInfoGlobal::MyDTI nZone::ShapeInfoGlobal::DTI("nZone::ShapeInfoGlobal", &::nZone::ShapeInfoBase::DTI, 16ul, 0u, 0u);

__attribute__((weak)) MtObject* nZone::ShapeInfoGlobal::MyDTI::newInstance() const {
    DDON_STUB("nZone::ShapeInfoGlobal::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nZone::ShapeInfoLine::getDTI() const {
    return nZone::ShapeInfoLine::DTI;
}

inline void nZone::ShapeInfoLine::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoLine::DTI)->memFree(p_addr);
}

nZone::ShapeInfoLine::~ShapeInfoLine() {
}

void nZone::ShapeInfoLine::createProperty(MtPropertyList& s) {
    this->::nZone::ShapeInfoBase::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "Position0", &mLineSegment.p0, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "Position1", &mLineSegment.p1, 0u, 0u);
}

__attribute__((weak)) bool nZone::ShapeInfoLine::copy(const nZone::ShapeInfoBase& copyShape) {
    DDON_STUB("nZone::ShapeInfoLine::copy")
    return {};
}

__attribute__((weak)) void nZone::ShapeInfoLine::applyWorldOffset(const MtVector3& offset) {
    DDON_STUB("nZone::ShapeInfoLine::applyWorldOffset")
    /* stub */
}

nZone::ShapeInfoBase::SHAPE_TYPE nZone::ShapeInfoLine::getShapeType() const {
    return SHAPE_TYPE_LINE;
}

bool nZone::ShapeInfoLine::isHit(const MtVector3& pos) const {
    return ::MtCollision::intersect(mLineSegment, pos, 1.1920929e-7f);
}

bool nZone::ShapeInfoLine::isHitLineSegment(const MtLineSegment& ls) const {
    return ::MtCollision::intersect(mLineSegment, ls, 1.1920929e-7f);
}

bool nZone::ShapeInfoLine::isHitConvex(const MtGeomConvex& convex) const {
    return convex.isIntersect(mLineSegment);
}

bool nZone::ShapeInfoLine::isIntersectAABB(const MtAABB& aabb) const {
    return ::MtCollision::intersect(aabb, mLineSegment);
}

__attribute__((weak)) bool nZone::ShapeInfoLine::getClosest(const MtVector3& pos, MtContact& contact) const {
    DDON_STUB("nZone::ShapeInfoLine::getClosest")
    return {};
}

void nZone::ShapeInfoLine::loadBinary(MtDataReader& r) {
    f32 t0 = r.readF32();
    mDecay = t0;
    u32 t1 = r.mSeekPt;
    u32 t2 = r.mBufsiz;
    if (t1 >= t2) {
        if (r.refill()) {
            u32 t4 = r.mSeekPt;
            u8* t5 = r.mBuffer;
            u8 t6 = t5[r.mSeekPt];
            r.mSeekPt = t4 + 1u;
            mIsNativeData = t6 == 1;
            r.read(static_cast<void*>(&mLineSegment), 32u);
        } else {
            mIsNativeData = false;
            r.read(static_cast<void*>(&mLineSegment), 32u);
        }
    } else {
        u8* t5 = r.mBuffer;
        u8 t6 = t5[r.mSeekPt];
        r.mSeekPt = t1 + 1u;
        mIsNativeData = t6 == 1;
        r.read(static_cast<void*>(&mLineSegment), 32u);
    }
}

void nZone::ShapeInfoLine::saveBinary(MtDataWriter& w) {
    w.writeF32(mDecay);
    bool t0 = mIsNativeData;
    if (w.mSeekPt >= w.mBufsiz) {
        w.flush();
    }
    w.mBuffer[w.mSeekPt] = static_cast<u8>(t0);
    w.mSeekPt = w.mSeekPt + 1u;
    w.write(static_cast<const void*>(&mLineSegment), 32u);
}

bool nZone::ShapeInfoLine::isGetAABB() const {
    return true;
}

__attribute__((weak)) MtAABB nZone::ShapeInfoLine::getAABB() const {
    DDON_STUB("nZone::ShapeInfoLine::getAABB")
    __builtin_unreachable();
}

bool nZone::ShapeInfoLine::isGetBoundingSphere() const {
    return true;
}

__attribute__((weak)) MtSphere nZone::ShapeInfoLine::getBoundingSphere() const {
    DDON_STUB("nZone::ShapeInfoLine::getBoundingSphere")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector3 nZone::ShapeInfoLine::getCenterPos() const {
    DDON_STUB("nZone::ShapeInfoLine::getCenterPos")
    __builtin_unreachable();
}

__attribute__((weak)) void nZone::ShapeInfoLine::setCenterPos(const MtVector3& pos) {
    DDON_STUB("nZone::ShapeInfoLine::setCenterPos")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoLine::movePosition(const MtVector3& AddPos) {
    DDON_STUB("nZone::ShapeInfoLine::movePosition")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoLine::movePosition(nZone::ShapeInfoBase& OutputShape, const MtVector3& AddPos) const {
    DDON_STUB("nZone::ShapeInfoLine::movePosition")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoLine::rotation(const MtMatrix& RotateMatrix) {
    DDON_STUB("nZone::ShapeInfoLine::rotation")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoLine::rotation(nZone::ShapeInfoBase& OutputShape, const MtMatrix& RotateMatrix) const {
    DDON_STUB("nZone::ShapeInfoLine::rotation")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoLine::mulMatrix(const MtMatrix& MulMatrix) {
    DDON_STUB("nZone::ShapeInfoLine::mulMatrix")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoLine::mulMatrix(nZone::ShapeInfoBase& OutputShape, const MtMatrix& MulMatrix) const {
    DDON_STUB("nZone::ShapeInfoLine::mulMatrix")
    /* stub */
}

inline nZone::ShapeInfoLine::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nZone::ShapeInfoLine::MyDTI nZone::ShapeInfoLine::DTI("nZone::ShapeInfoLine", &::nZone::ShapeInfoBase::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* nZone::ShapeInfoLine::MyDTI::newInstance() const {
    return new (16u) ::nZone::ShapeInfoLine;
}

const MtDTI& nZone::ShapeInfoOBB::getDTI() const {
    return nZone::ShapeInfoOBB::DTI;
}

void* nZone::ShapeInfoOBB::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoOBB::DTI)->memAlloc(sz, align, ::nZone::ShapeInfoOBB::DTI.mID);
}

void* nZone::ShapeInfoOBB::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void nZone::ShapeInfoOBB::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoOBB::DTI)->memFree(p_addr);
}

__attribute__((noinline)) nZone::ShapeInfoOBB::ShapeInfoOBB() {
    MtMatrix mat;
    mat.identity();
    mat.setTranslate(MtVector3(0.0f, 50.0f, 0.0f));
    mOBB.coord = mat;
    mOBB.extent = MtVector3(50.0f, 50.0f, 50.0f);
    mDecayY = 1.0f;
    mDecayZ = 1.0f;
    mIsEnableExtendedDecay = false;
}

nZone::ShapeInfoOBB::~ShapeInfoOBB() {
}

void nZone::ShapeInfoOBB::createProperty(MtPropertyList& s) {
    this->::nZone::ShapeInfoBase::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "mIsEnableExtendedDecay", &mIsEnableExtendedDecay, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mDecayX", &mDecay, 2u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mDecayY", &mDecayY, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mDecayZ", &mDecayZ, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_F32, "Height", reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoOBB::getHeight), reinterpret_cast<MT_MFUNC>(&::nZone::ShapeInfoOBB::setHeight), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), "mOBB.extent", &mOBB.extent, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mOBB.coord", &mOBB.coord, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mOBB", &mOBB, 2u, 0u);
}

__attribute__((weak)) bool nZone::ShapeInfoOBB::copy(const nZone::ShapeInfoBase& copyShape) {
    DDON_STUB("nZone::ShapeInfoOBB::copy")
    return {};
}

__attribute__((weak)) void nZone::ShapeInfoOBB::applyWorldOffset(const MtVector3& offset) {
    DDON_STUB("nZone::ShapeInfoOBB::applyWorldOffset")
    /* stub */
}

nZone::ShapeInfoBase::SHAPE_TYPE nZone::ShapeInfoOBB::getShapeType() const {
    return SHAPE_TYPE_OBB;
}

bool nZone::ShapeInfoOBB::isHit(const MtVector3& pos) const {
    return ::MtCollision::intersect(mOBB, pos);
}

bool nZone::ShapeInfoOBB::isHitLineSegment(const MtLineSegment& ls) const {
    return ::MtCollision::intersect(mOBB, ls);
}

bool nZone::ShapeInfoOBB::isHitConvex(const MtGeomConvex& convex) const {
    return convex.isIntersect(mOBB);
}

bool nZone::ShapeInfoOBB::isIntersectAABB(const MtAABB& aabb) const {
    return ::MtCollision::intersect(mOBB, aabb);
}

__attribute__((weak)) bool nZone::ShapeInfoOBB::getClosest(const MtVector3& pos, MtContact& contact) const {
    DDON_STUB("nZone::ShapeInfoOBB::getClosest")
    return {};
}

void nZone::ShapeInfoOBB::loadBinary(MtDataReader& r) {
    f32 t0 = r.readF32();
    mDecay = t0;
    u32 t1 = r.mSeekPt;
    u32 t2 = r.mBufsiz;
    if (t1 >= t2) {
        if (r.refill()) {
            u32 t4 = r.mSeekPt;
            u8* t5 = r.mBuffer;
            u8 t6 = t5[r.mSeekPt];
            r.mSeekPt = t4 + 1u;
            mIsNativeData = t6 == 1;
            r.read(static_cast<void*>(&mOBB), 80u);
            f32 t8 = r.readF32();
            mDecayY = t8;
            f32 t9 = r.readF32();
            mDecayZ = t9;
            u32 t10 = r.mSeekPt;
            u32 t11 = r.mBufsiz;
            if (t10 >= t11) {
                if (r.refill()) {
                    u32 t13 = r.mSeekPt;
                    u8* t14 = r.mBuffer;
                    u8 t15 = t14[r.mSeekPt];
                    r.mSeekPt = t13 + 1u;
                    mIsEnableExtendedDecay = t15 == 1;
                } else {
                    mIsEnableExtendedDecay = false;
                }
            } else {
                u8* t14 = r.mBuffer;
                u8 t15 = t14[r.mSeekPt];
                r.mSeekPt = t10 + 1u;
                mIsEnableExtendedDecay = t15 == 1;
            }
        } else {
            mIsNativeData = false;
            r.read(static_cast<void*>(&mOBB), 80u);
            f32 t8 = r.readF32();
            mDecayY = t8;
            f32 t9 = r.readF32();
            mDecayZ = t9;
            u32 t10 = r.mSeekPt;
            u32 t11 = r.mBufsiz;
            if (t10 >= t11) {
                if (r.refill()) {
                    u32 t13 = r.mSeekPt;
                    u8* t14 = r.mBuffer;
                    u8 t15 = t14[r.mSeekPt];
                    r.mSeekPt = t13 + 1u;
                    mIsEnableExtendedDecay = t15 == 1;
                } else {
                    mIsEnableExtendedDecay = false;
                }
            } else {
                u8* t14 = r.mBuffer;
                u8 t15 = t14[r.mSeekPt];
                r.mSeekPt = t10 + 1u;
                mIsEnableExtendedDecay = t15 == 1;
            }
        }
    } else {
        u8* t5 = r.mBuffer;
        u8 t6 = t5[r.mSeekPt];
        r.mSeekPt = t1 + 1u;
        mIsNativeData = t6 == 1;
        r.read(static_cast<void*>(&mOBB), 80u);
        f32 t8 = r.readF32();
        mDecayY = t8;
        f32 t9 = r.readF32();
        mDecayZ = t9;
        u32 t10 = r.mSeekPt;
        u32 t11 = r.mBufsiz;
        if (t10 >= t11) {
            if (r.refill()) {
                u32 t13 = r.mSeekPt;
                u8* t14 = r.mBuffer;
                u8 t15 = t14[r.mSeekPt];
                r.mSeekPt = t13 + 1u;
                mIsEnableExtendedDecay = t15 == 1;
            } else {
                mIsEnableExtendedDecay = false;
            }
        } else {
            u8* t14 = r.mBuffer;
            u8 t15 = t14[r.mSeekPt];
            r.mSeekPt = t10 + 1u;
            mIsEnableExtendedDecay = t15 == 1;
        }
    }
}

void nZone::ShapeInfoOBB::saveBinary(MtDataWriter& w) {
    w.writeF32(mDecay);
    bool t0 = mIsNativeData;
    if (w.mSeekPt >= w.mBufsiz) {
        w.flush();
        w.mBuffer[w.mSeekPt] = static_cast<u8>(t0);
        w.mSeekPt = w.mSeekPt + 1u;
        w.write(static_cast<const void*>(&mOBB), 80u);
        w.writeF32(mDecayY);
        w.writeF32(mDecayZ);
        bool t1 = mIsEnableExtendedDecay;
        if (w.mSeekPt >= w.mBufsiz) {
            w.flush();
        }
        w.mBuffer[w.mSeekPt] = static_cast<u8>(t1);
        w.mSeekPt = w.mSeekPt + 1u;
    } else {
        w.mBuffer[w.mSeekPt] = static_cast<u8>(t0);
        w.mSeekPt = w.mSeekPt + 1u;
        w.write(static_cast<const void*>(&mOBB), 80u);
        w.writeF32(mDecayY);
        w.writeF32(mDecayZ);
        bool t1 = mIsEnableExtendedDecay;
        if (w.mSeekPt >= w.mBufsiz) {
            w.flush();
        }
        w.mBuffer[w.mSeekPt] = static_cast<u8>(t1);
        w.mSeekPt = w.mSeekPt + 1u;
    }
}

bool nZone::ShapeInfoOBB::isGetAABB() const {
    return true;
}

__attribute__((weak)) MtAABB nZone::ShapeInfoOBB::getAABB() const {
    MtAABB aabb;
    mOBB.getBoundingAABB(aabb);
    return aabb;
}

bool nZone::ShapeInfoOBB::isGetBoundingSphere() const {
    return true;
}

__attribute__((weak)) MtSphere nZone::ShapeInfoOBB::getBoundingSphere() const {
    DDON_STUB("nZone::ShapeInfoOBB::getBoundingSphere")
    __builtin_unreachable();
}

MtVector3 nZone::ShapeInfoOBB::getCenterPos() const {
    MtVector3 result;
    result.x = mOBB.coord.m[3].x;
    result.y = mOBB.coord.m[3].y;
    result.z = mOBB.coord.m[3].z;
    result.pad_ = 0.0f;
    return result;
}

__attribute__((weak)) void nZone::ShapeInfoOBB::setCenterPos(const MtVector3& pos) {
    DDON_STUB("nZone::ShapeInfoOBB::setCenterPos")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoOBB::movePosition(const MtVector3& AddPos) {
    DDON_STUB("nZone::ShapeInfoOBB::movePosition")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoOBB::movePosition(nZone::ShapeInfoBase& OutputShape, const MtVector3& AddPos) const {
    DDON_STUB("nZone::ShapeInfoOBB::movePosition")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoOBB::rotation(const MtMatrix& RotateMatrix) {
    DDON_STUB("nZone::ShapeInfoOBB::rotation")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoOBB::rotation(nZone::ShapeInfoBase& OutputShape, const MtMatrix& RotateMatrix) const {
    DDON_STUB("nZone::ShapeInfoOBB::rotation")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoOBB::mulMatrix(const MtMatrix& MulMatrix) {
    DDON_STUB("nZone::ShapeInfoOBB::mulMatrix")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoOBB::mulMatrix(nZone::ShapeInfoBase& OutputShape, const MtMatrix& MulMatrix) const {
    DDON_STUB("nZone::ShapeInfoOBB::mulMatrix")
    /* stub */
}

__attribute__((weak)) f32 nZone::ShapeInfoOBB::calcWeight(const MtVector3& pos) const {
    DDON_STUB("nZone::ShapeInfoOBB::calcWeight")
    return {};
}

static auto ddon_emit_0x01b88d20 __attribute__((used)) = &nZone::ShapeInfoOBB::getHeight;

__attribute__((weak)) void nZone::ShapeInfoOBB::setHeight(f32 height) {
    DDON_STUB("nZone::ShapeInfoOBB::setHeight")
    /* stub */
}

inline nZone::ShapeInfoOBB::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nZone::ShapeInfoOBB::MyDTI nZone::ShapeInfoOBB::DTI("nZone::ShapeInfoOBB", &::nZone::ShapeInfoBase::DTI, 112ul, 0u, 0u);

__attribute__((weak)) MtObject* nZone::ShapeInfoOBB::MyDTI::newInstance() const {
    return new (16u) ::nZone::ShapeInfoOBB;
}

const MtDTI& nZone::ShapeInfoPanel::getDTI() const {
    return nZone::ShapeInfoPanel::DTI;
}

void* nZone::ShapeInfoPanel::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoPanel::DTI)->memAlloc(sz, align, ::nZone::ShapeInfoPanel::DTI.mID);
}

inline void nZone::ShapeInfoPanel::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoPanel::DTI)->memFree(p_addr);
}

nZone::ShapeInfoPanel::ShapeInfoPanel() {
    mVertex[0] = MtVector3(50.0f, 0.0f, 50.0f);
    mVertex[1] = MtVector3(50.0f, 0.0f, -50.0f);
    mVertex[2] = MtVector3(-50.0f, 0.0f, -50.0f);
    mVertex[3] = MtVector3(-50.0f, 0.0f, 50.0f);
}

nZone::ShapeInfoPanel::~ShapeInfoPanel() {
}

void nZone::ShapeInfoPanel::createProperty(MtPropertyList& s) {
    this->::nZone::ShapeInfoBase::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "Direction reversal", static_cast<MT_MFUNC>(&::nZone::ShapeInfoPanel::reversePanelDirection), 10u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mVertex", &mVertex[0], 32u, 4u);
    s << ::MtProperty(static_cast<MtObject*>(this), "Shift Diagonal", static_cast<MT_MFUNC>(&::nZone::ShapeInfoPanel::shiftDiagonal), 10u);
}

__attribute__((weak)) bool nZone::ShapeInfoPanel::copy(const nZone::ShapeInfoBase& copyShape) {
    DDON_STUB("nZone::ShapeInfoPanel::copy")
    return {};
}

__attribute__((weak)) void nZone::ShapeInfoPanel::applyWorldOffset(const MtVector3& offset) {
    DDON_STUB("nZone::ShapeInfoPanel::applyWorldOffset")
    /* stub */
}

nZone::ShapeInfoBase::SHAPE_TYPE nZone::ShapeInfoPanel::getShapeType() const {
    return SHAPE_TYPE_PANEL;
}

__attribute__((weak)) bool nZone::ShapeInfoPanel::isHit(const MtVector3& pos) const {
    DDON_STUB("nZone::ShapeInfoPanel::isHit")
    return {};
}

__attribute__((weak)) bool nZone::ShapeInfoPanel::isHitLineSegment(const MtLineSegment& ls) const {
    DDON_STUB("nZone::ShapeInfoPanel::isHitLineSegment")
    return {};
}

__attribute__((weak)) bool nZone::ShapeInfoPanel::isHitConvex(const MtGeomConvex& convex) const {
    DDON_STUB("nZone::ShapeInfoPanel::isHitConvex")
    return {};
}

__attribute__((weak)) bool nZone::ShapeInfoPanel::isIntersectAABB(const MtAABB& aabb) const {
    DDON_STUB("nZone::ShapeInfoPanel::isIntersectAABB")
    return {};
}

__attribute__((weak)) bool nZone::ShapeInfoPanel::getClosest(const MtVector3& pos, MtContact& contact) const {
    DDON_STUB("nZone::ShapeInfoPanel::getClosest")
    return {};
}

void nZone::ShapeInfoPanel::loadBinary(MtDataReader& r) {
    f32 t0 = r.readF32();
    mDecay = t0;
    u32 t1 = r.mSeekPt;
    u32 t2 = r.mBufsiz;
    if (t1 >= t2) {
        if (r.refill()) {
            u32 t4 = r.mSeekPt;
            u8* t5 = r.mBuffer;
            u8 t6 = t5[r.mSeekPt];
            r.mSeekPt = t4 + 1u;
            mIsNativeData = t6 == 1;
            r.read(static_cast<void*>(&mVertex[0]), 64u);
        } else {
            mIsNativeData = false;
            r.read(static_cast<void*>(&mVertex[0]), 64u);
        }
    } else {
        u8* t5 = r.mBuffer;
        u8 t6 = t5[r.mSeekPt];
        r.mSeekPt = t1 + 1u;
        mIsNativeData = t6 == 1;
        r.read(static_cast<void*>(&mVertex[0]), 64u);
    }
}

void nZone::ShapeInfoPanel::saveBinary(MtDataWriter& w) {
    w.writeF32(mDecay);
    bool t0 = mIsNativeData;
    if (w.mSeekPt >= w.mBufsiz) {
        w.flush();
    }
    w.mBuffer[w.mSeekPt] = static_cast<u8>(t0);
    w.mSeekPt = w.mSeekPt + 1u;
    w.write(static_cast<const void*>(&mVertex[0]), 64u);
}

bool nZone::ShapeInfoPanel::isGetAABB() const {
    return true;
}

__attribute__((weak)) MtAABB nZone::ShapeInfoPanel::getAABB() const {
    DDON_STUB("nZone::ShapeInfoPanel::getAABB")
    __builtin_unreachable();
}

bool nZone::ShapeInfoPanel::isGetBoundingSphere() const {
    return true;
}

__attribute__((weak)) MtSphere nZone::ShapeInfoPanel::getBoundingSphere() const {
    DDON_STUB("nZone::ShapeInfoPanel::getBoundingSphere")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector3 nZone::ShapeInfoPanel::getCenterPos() const {
    DDON_STUB("nZone::ShapeInfoPanel::getCenterPos")
    __builtin_unreachable();
}

__attribute__((weak)) void nZone::ShapeInfoPanel::setCenterPos(const MtVector3& pos) {
    DDON_STUB("nZone::ShapeInfoPanel::setCenterPos")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoPanel::movePosition(const MtVector3& AddPos) {
    DDON_STUB("nZone::ShapeInfoPanel::movePosition")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoPanel::movePosition(nZone::ShapeInfoBase& OutputShape, const MtVector3& AddPos) const {
    DDON_STUB("nZone::ShapeInfoPanel::movePosition")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoPanel::rotation(const MtMatrix& RotateMatrix) {
    DDON_STUB("nZone::ShapeInfoPanel::rotation")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoPanel::rotation(nZone::ShapeInfoBase& OutputShape, const MtMatrix& RotateMatrix) const {
    DDON_STUB("nZone::ShapeInfoPanel::rotation")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoPanel::mulMatrix(const MtMatrix& MulMatrix) {
    DDON_STUB("nZone::ShapeInfoPanel::mulMatrix")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoPanel::mulMatrix(nZone::ShapeInfoBase& OutputShape, const MtMatrix& MulMatrix) const {
    DDON_STUB("nZone::ShapeInfoPanel::mulMatrix")
    /* stub */
}

void nZone::ShapeInfoPanel::shiftDiagonal() {
    f32 t0 = mVertex[1].x;
    f32 t1 = mVertex[1].y;
    f32 t2 = mVertex[1].z;
    mVertex[1].x = mVertex[0].x;
    mVertex[1].y = mVertex[0].y;
    mVertex[1].z = mVertex[0].z;
    mVertex[1].pad_ = 0.0f;
    f32 t3 = mVertex[2].x;
    f32 t4 = mVertex[2].y;
    f32 t5 = mVertex[2].z;
    mVertex[2].x = t0;
    mVertex[2].y = t1;
    mVertex[2].z = t2;
    mVertex[2].pad_ = 0.0f;
    f32 t6 = mVertex[3].x;
    f32 t7 = mVertex[3].y;
    f32 t8 = mVertex[3].z;
    mVertex[3].x = t3;
    mVertex[3].y = t4;
    mVertex[3].z = t5;
    mVertex[3].pad_ = 0.0f;
    mVertex[0].x = t6;
    mVertex[0].y = t7;
    mVertex[0].z = t8;
    mVertex[0].pad_ = 0.0f;
}

void nZone::ShapeInfoPanel::reversePanelDirection() {
    f32 t0 = mVertex[1].x;
    f32 t1 = mVertex[1].y;
    f32 t2 = mVertex[1].z;
    mVertex[1].x = mVertex[3].x;
    mVertex[1].y = mVertex[3].y;
    mVertex[1].z = mVertex[3].z;
    mVertex[1].pad_ = 0.0f;
    mVertex[3].x = t0;
    mVertex[3].y = t1;
    mVertex[3].z = t2;
    mVertex[3].pad_ = 0.0f;
}

__attribute__((weak)) MtTriangle nZone::ShapeInfoPanel::getTriangle(u32 index) const {
    DDON_STUB("nZone::ShapeInfoPanel::getTriangle")
    __builtin_unreachable();
}

inline nZone::ShapeInfoPanel::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nZone::ShapeInfoPanel::MyDTI nZone::ShapeInfoPanel::DTI("nZone::ShapeInfoPanel", &::nZone::ShapeInfoBase::DTI, 80ul, 0u, 0u);

__attribute__((weak)) MtObject* nZone::ShapeInfoPanel::MyDTI::newInstance() const {
    DDON_STUB("nZone::ShapeInfoPanel::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nZone::ShapeInfoPoint::getDTI() const {
    return nZone::ShapeInfoPoint::DTI;
}

inline void nZone::ShapeInfoPoint::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoPoint::DTI)->memFree(p_addr);
}

nZone::ShapeInfoPoint::~ShapeInfoPoint() {
}

void nZone::ShapeInfoPoint::createProperty(MtPropertyList& s) {
    this->::nZone::ShapeInfoBase::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "mPos", &mPos, 0u, 0u);
}

__attribute__((weak)) bool nZone::ShapeInfoPoint::copy(const nZone::ShapeInfoBase& copyShape) {
    DDON_STUB("nZone::ShapeInfoPoint::copy")
    return {};
}

__attribute__((weak)) void nZone::ShapeInfoPoint::applyWorldOffset(const MtVector3& offset) {
    DDON_STUB("nZone::ShapeInfoPoint::applyWorldOffset")
    /* stub */
}

nZone::ShapeInfoBase::SHAPE_TYPE nZone::ShapeInfoPoint::getShapeType() const {
    return SHAPE_TYPE_POINT;
}

bool nZone::ShapeInfoPoint::isHit(const MtVector3& pos) const {
    return 1.1920929e-7f > ((((mPos.x - pos.x) * (mPos.x - pos.x)) + ((mPos.y - pos.y) * (mPos.y - pos.y))) + ((mPos.z - pos.z) * (mPos.z - pos.z)));
}

bool nZone::ShapeInfoPoint::isHitLineSegment(const MtLineSegment& ls) const {
    return ::MtCollision::intersect(ls, mPos, 1.1920929e-7f);
}

bool nZone::ShapeInfoPoint::isHitConvex(const MtGeomConvex& convex) const {
    return convex.isIntersect(mPos);
}

__attribute__((weak)) bool nZone::ShapeInfoPoint::isIntersectAABB(const MtAABB& aabb) const {
    DDON_STUB("nZone::ShapeInfoPoint::isIntersectAABB")
    return {};
}

__attribute__((weak)) bool nZone::ShapeInfoPoint::getClosest(const MtVector3& pos, MtContact& contact) const {
    DDON_STUB("nZone::ShapeInfoPoint::getClosest")
    return {};
}

void nZone::ShapeInfoPoint::loadBinary(MtDataReader& r) {
    f32 t0 = r.readF32();
    mDecay = t0;
    u32 t1 = r.mSeekPt;
    u32 t2 = r.mBufsiz;
    if (t1 >= t2) {
        if (r.refill()) {
            u32 t4 = r.mSeekPt;
            u8* t5 = r.mBuffer;
            u8 t6 = t5[r.mSeekPt];
            r.mSeekPt = t4 + 1u;
            mIsNativeData = t6 == 1;
            r.read(static_cast<void*>(&mPos), 16u);
        } else {
            mIsNativeData = false;
            r.read(static_cast<void*>(&mPos), 16u);
        }
    } else {
        u8* t5 = r.mBuffer;
        u8 t6 = t5[r.mSeekPt];
        r.mSeekPt = t1 + 1u;
        mIsNativeData = t6 == 1;
        r.read(static_cast<void*>(&mPos), 16u);
    }
}

void nZone::ShapeInfoPoint::saveBinary(MtDataWriter& w) {
    w.writeF32(mDecay);
    bool t0 = mIsNativeData;
    if (w.mSeekPt >= w.mBufsiz) {
        w.flush();
    }
    w.mBuffer[w.mSeekPt] = static_cast<u8>(t0);
    w.mSeekPt = w.mSeekPt + 1u;
    w.write(static_cast<const void*>(&mPos), 16u);
}

bool nZone::ShapeInfoPoint::isGetAABB() const {
    return true;
}

__attribute__((weak)) MtAABB nZone::ShapeInfoPoint::getAABB() const {
    DDON_STUB("nZone::ShapeInfoPoint::getAABB")
    __builtin_unreachable();
}

MtVector3 nZone::ShapeInfoPoint::getCenterPos() const {
    return mPos;
}

void nZone::ShapeInfoPoint::setCenterPos(const MtVector3& pos) {
    mPos.x = pos.x;
    mPos.y = pos.y;
    mPos.z = pos.z;
    mPos.pad_ = 0.0f;
}

__attribute__((weak)) void nZone::ShapeInfoPoint::movePosition(const MtVector3& AddPos) {
    DDON_STUB("nZone::ShapeInfoPoint::movePosition")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoPoint::movePosition(nZone::ShapeInfoBase& OutputShape, const MtVector3& AddPos) const {
    DDON_STUB("nZone::ShapeInfoPoint::movePosition")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoPoint::mulMatrix(const MtMatrix& MulMatrix) {
    DDON_STUB("nZone::ShapeInfoPoint::mulMatrix")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoPoint::mulMatrix(nZone::ShapeInfoBase& OutputShape, const MtMatrix& MulMatrix) const {
    DDON_STUB("nZone::ShapeInfoPoint::mulMatrix")
    /* stub */
}

inline nZone::ShapeInfoPoint::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nZone::ShapeInfoPoint::MyDTI nZone::ShapeInfoPoint::DTI("nZone::ShapeInfoPoint", &::nZone::ShapeInfoBase::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* nZone::ShapeInfoPoint::MyDTI::newInstance() const {
    return new (16u) ::nZone::ShapeInfoPoint;
}

const MtDTI& nZone::ShapeInfoSphere::getDTI() const {
    return nZone::ShapeInfoSphere::DTI;
}

void* nZone::ShapeInfoSphere::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoSphere::DTI)->memAlloc(sz, align, ::nZone::ShapeInfoSphere::DTI.mID);
}

void* nZone::ShapeInfoSphere::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void nZone::ShapeInfoSphere::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nZone::ShapeInfoSphere::DTI)->memFree(p_addr);
}

nZone::ShapeInfoSphere::ShapeInfoSphere() {
    mSphere.pos = MtFloat3A(0.0f, 50.0f, 0.0f);
    mSphere.r = 50.0f;
}

nZone::ShapeInfoSphere::~ShapeInfoSphere() {
}

void nZone::ShapeInfoSphere::createProperty(MtPropertyList& s) {
    this->::nZone::ShapeInfoBase::createProperty(s);
    s << ::MtProperty(static_cast<MtObject*>(this), "mSphere", &mSphere, 0u, 0u);
}

__attribute__((weak)) bool nZone::ShapeInfoSphere::copy(const nZone::ShapeInfoBase& copyShape) {
    DDON_STUB("nZone::ShapeInfoSphere::copy")
    return {};
}

__attribute__((weak)) void nZone::ShapeInfoSphere::applyWorldOffset(const MtVector3& offset) {
    DDON_STUB("nZone::ShapeInfoSphere::applyWorldOffset")
    /* stub */
}

nZone::ShapeInfoBase::SHAPE_TYPE nZone::ShapeInfoSphere::getShapeType() const {
    return SHAPE_TYPE_SPHERE;
}

bool nZone::ShapeInfoSphere::isHit(const MtVector3& pos) const {
    return ::MtCollision::intersect(mSphere, pos);
}

bool nZone::ShapeInfoSphere::isHitLineSegment(const MtLineSegment& ls) const {
    return ::MtCollision::intersect(mSphere, ls);
}

bool nZone::ShapeInfoSphere::isHitConvex(const MtGeomConvex& convex) const {
    return convex.isIntersect(mSphere);
}

bool nZone::ShapeInfoSphere::isIntersectAABB(const MtAABB& aabb) const {
    return ::MtCollision::intersect(aabb, mSphere);
}

__attribute__((weak)) bool nZone::ShapeInfoSphere::getClosest(const MtVector3& pos, MtContact& contact) const {
    DDON_STUB("nZone::ShapeInfoSphere::getClosest")
    return {};
}

void nZone::ShapeInfoSphere::loadBinary(MtDataReader& r) {
    f32 t0 = r.readF32();
    mDecay = t0;
    u32 t1 = r.mSeekPt;
    u32 t2 = r.mBufsiz;
    if (t1 >= t2) {
        if (r.refill()) {
            u32 t4 = r.mSeekPt;
            u8* t5 = r.mBuffer;
            u8 t6 = t5[r.mSeekPt];
            r.mSeekPt = t4 + 1u;
            mIsNativeData = t6 == 1;
            r.read(static_cast<void*>(&mSphere), 16u);
        } else {
            mIsNativeData = false;
            r.read(static_cast<void*>(&mSphere), 16u);
        }
    } else {
        u8* t5 = r.mBuffer;
        u8 t6 = t5[r.mSeekPt];
        r.mSeekPt = t1 + 1u;
        mIsNativeData = t6 == 1;
        r.read(static_cast<void*>(&mSphere), 16u);
    }
}

void nZone::ShapeInfoSphere::saveBinary(MtDataWriter& w) {
    w.writeF32(mDecay);
    bool t0 = mIsNativeData;
    if (w.mSeekPt >= w.mBufsiz) {
        w.flush();
    }
    w.mBuffer[w.mSeekPt] = static_cast<u8>(t0);
    w.mSeekPt = w.mSeekPt + 1u;
    w.write(static_cast<const void*>(&mSphere), 16u);
}

bool nZone::ShapeInfoSphere::isGetAABB() const {
    return true;
}

__attribute__((weak)) MtAABB nZone::ShapeInfoSphere::getAABB() const {
    MtAABB aabb;
    aabb.minpos = MtVector3(mSphere.pos.x - mSphere.r, mSphere.pos.y - mSphere.r, mSphere.pos.z - mSphere.r);
    aabb.maxpos = MtVector3(mSphere.pos.x + mSphere.r, mSphere.pos.y + mSphere.r, mSphere.pos.z + mSphere.r);
    return aabb;
}

bool nZone::ShapeInfoSphere::isGetBoundingSphere() const {
    return true;
}

__attribute__((weak)) MtSphere nZone::ShapeInfoSphere::getBoundingSphere() const {
    DDON_STUB("nZone::ShapeInfoSphere::getBoundingSphere")
    __builtin_unreachable();
}

MtVector3 nZone::ShapeInfoSphere::getCenterPos() const {
    MtVector3 result;
    result.x = mSphere.pos.x;
    result.y = mSphere.pos.y;
    result.z = mSphere.pos.z;
    result.pad_ = 0.0f;
    return result;
}

void nZone::ShapeInfoSphere::setCenterPos(const MtVector3& pos) {
    mSphere.pos.x = pos.x;
    mSphere.pos.y = pos.y;
    mSphere.pos.z = pos.z;
}

__attribute__((weak)) void nZone::ShapeInfoSphere::movePosition(const MtVector3& AddPos) {
    DDON_STUB("nZone::ShapeInfoSphere::movePosition")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoSphere::movePosition(nZone::ShapeInfoBase& OutputShape, const MtVector3& AddPos) const {
    DDON_STUB("nZone::ShapeInfoSphere::movePosition")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoSphere::mulMatrix(const MtMatrix& MulMatrix) {
    DDON_STUB("nZone::ShapeInfoSphere::mulMatrix")
    /* stub */
}

__attribute__((weak)) void nZone::ShapeInfoSphere::mulMatrix(nZone::ShapeInfoBase& OutputShape, const MtMatrix& MulMatrix) const {
    DDON_STUB("nZone::ShapeInfoSphere::mulMatrix")
    /* stub */
}

__attribute__((weak)) f32 nZone::ShapeInfoSphere::calcWeight(const MtVector3& pos) const {
    DDON_STUB("nZone::ShapeInfoSphere::calcWeight")
    return {};
}

inline nZone::ShapeInfoSphere::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nZone::ShapeInfoSphere::MyDTI nZone::ShapeInfoSphere::DTI("nZone::ShapeInfoSphere", &::nZone::ShapeInfoBase::DTI, 32ul, 0u, 0u);

__attribute__((weak)) MtObject* nZone::ShapeInfoSphere::MyDTI::newInstance() const {
    return new (16u) ::nZone::ShapeInfoSphere;
}

inline nZone::cAllocaterIntermediate::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nZone::cAllocaterIntermediate::MyDTI nZone::cAllocaterIntermediate::DTI("nZone::cAllocaterIntermediate", &::MtObject::DTI, 8ul, 0u, 1u);

MtObject* nZone::cAllocaterIntermediate::MyDTI::newInstance() const {
    return nullptr;
}

const MtDTI& nZone::cContentsPool::getDTI() const {
    return nZone::cContentsPool::DTI;
}

void* nZone::cContentsPool::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nZone::cContentsPool::DTI)->memAlloc(sz, align, ::nZone::cContentsPool::DTI.mID);
}

inline void nZone::cContentsPool::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nZone::cContentsPool::DTI)->memFree(p_addr);
}

__attribute__((noinline)) nZone::cContentsPool::cContentsPool() {
    mContentsListArray.setAutoDelete(true);
    mFlgNativeData = false;
}

__attribute__((noinline)) nZone::cContentsPool::~cContentsPool() {
    clearContents();
}

void nZone::cContentsPool::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "mContentsListArray", static_cast<MtObject*>(&mContentsListArray), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mFlgNativeData", &mFlgNativeData, 0u, 0u);
}

__attribute__((weak)) const nZone::cContentsPool& nZone::cContentsPool::operator=(const nZone::cContentsPool& src) {
    DDON_STUB("nZone::cContentsPool::operator=")
    __builtin_unreachable();
}

__attribute__((weak)) bool nZone::cContentsPool::loadBeforeAllocateAlign4(nCollisionUtil::LoadBuffer& buffer, u32 ContentsListNum) {
    clearContents();
    mContentsListArray.reserve(ContentsListNum);
    for (u32 i = 0; i < ContentsListNum; i++) {
        nZone::cContentsPool::cContentsList* pNewContentsList = new (static_cast<void*>(buffer.pBuffer + buffer.Position)) nZone::cContentsPool::cContentsList(-1);
        buffer.Position += sizeof(nZone::cContentsPool::cContentsList);
        if (pNewContentsList == nullptr) {
            mContentsListArray.clear(true);
            return false;
        }
        mContentsListArray.add(pNewContentsList);
    }
    mFlgNativeData = true;
    return true;
}

bool nZone::cContentsPool::load(MtDataReader& r) {
    MtSerializer sz(65536);
    return sz.deserializeBinary(r, static_cast<u16>(0), static_cast<MtObject*>(&mContentsListArray), ::MtSerializer::MODE_STATE) != nullptr;
}

__attribute__((weak)) bool nZone::cContentsPool::save(MtDataWriter& w) {
    ::MtSerializer sz(65536);
    const bool FlgAutoDelete = mContentsListArray.mAutoDelete;
    mContentsListArray.mAutoDelete = false;
    const bool ret = sz.serializeBinary(w, static_cast<u16>(0), &mContentsListArray, ::MtSerializer::MODE_STATE, static_cast<const MtDTI*>(nullptr));
    mContentsListArray.mAutoDelete = FlgAutoDelete;
    return ret;
}

void nZone::cContentsPool::clearContents() {
    u32 v0_8 = mContentsListArray.mLength;
    if (mFlgNativeData) {
        if (v0_8 != 0) {
            for (u32 i = 0;;) {
                if (mContentsListArray.mpArray[i] != nullptr) {
                    mContentsListArray.mpArray[i]->~MtObject();
                }
                if (v0_8 != (i + 1u)) {
                    i = i + 1u;
                } else {
                    break;
                }
            }
        }
    } else {
        if (v0_8 != 0) {
            unsigned int i3_3 = 0;
            u32 v3_8 = v0_8;
            u32 v4_7;
            for (;;) {
                if (mContentsListArray.mpArray[i3_3] == nullptr) {
                    v4_7 = v3_8;
                } else {
                    delete mContentsListArray.mpArray[i3_3];
                    v4_7 = mContentsListArray.mLength;
                }
                if ((i3_3 + 1u) < v4_7) {
                    i3_3 += 1u;
                    v3_8 = v4_7;
                } else {
                    break;
                }
            }
        }
    }
    if (mContentsListArray.mpArray != nullptr) {
        ::MtMemoryAllocator::getAllocator(::MtArray::DTI)->memFree(static_cast<void*>(mContentsListArray.mpArray));
    }
    mContentsListArray.mpArray = nullptr;
    mContentsListArray.mBufsiz = 0;
    mContentsListArray.mLength = 0;
}

__attribute__((weak)) void nZone::cContentsPool::copyObjectProperty(MtObject* pDest, MtObject* pSrc) {
    DDON_STUB("nZone::cContentsPool::copyObjectProperty")
    /* stub */
}

inline nZone::cContentsPool::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nZone::cContentsPool::MyDTI nZone::cContentsPool::DTI("nZone::cContentsPool", &::MtObject::DTI, 48ul, 0u, 0u);

__attribute__((weak)) MtObject* nZone::cContentsPool::MyDTI::newInstance() const {
    DDON_STUB("nZone::cContentsPool::MyDTI::newInstance")
    return nullptr;
}

const MtDTI& nZone::cContentsPool::cContentsList::getDTI() const {
    return nZone::cContentsPool::cContentsList::DTI;
}

inline void nZone::cContentsPool::cContentsList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nZone::cContentsPool::cContentsList::DTI)->memFree(p_addr);
}

nZone::cContentsPool::cContentsList::~cContentsList() {
    mZoneContentsArray.deleteAll(true);
}

void nZone::cContentsPool::cContentsList::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "mZoneContentsArray", static_cast<MtObject*>(&mZoneContentsArray), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mGroupID", &mGroupID, 1u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_U32, "ZoneContentsNum", reinterpret_cast<MT_MFUNC>(&::nZone::cContentsPool::cContentsList::getZoneContentsNum), static_cast<MT_MFUNC>(0), 131u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), "mFlgNativeData", &mFlgNativeData, 1u, 0u);
}

static auto ddon_emit_0x01b88de0 __attribute__((used)) = &nZone::cContentsPool::cContentsList::getZoneContentsNum;

inline nZone::cContentsPool::cContentsList::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nZone::cContentsPool::cContentsList::MyDTI nZone::cContentsPool::cContentsList::DTI("nZone::cContentsPool::cContentsList", &::MtObject::DTI, 128ul, 0u, 0u);

__attribute__((weak)) MtObject* nZone::cContentsPool::cContentsList::MyDTI::newInstance() const {
    return new (16u) ::nZone::cContentsPool::cContentsList(-1);
}

const MtDTI& nZone::cLayoutElement::getDTI() const {
    return nZone::cLayoutElement::DTI;
}

void* nZone::cLayoutElement::operator new[](size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::nZone::cLayoutElement::DTI)->memAlloc(sz, align, ::nZone::cLayoutElement::DTI.mID);
}

void* nZone::cLayoutElement::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

void nZone::cLayoutElement::operator delete[](void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::nZone::cLayoutElement::DTI)->memFree(p_addr);
}

nZone::cLayoutElement::cLayoutElement() {
    mpOwner = nullptr;
    mpShapeInfo = nullptr;
    mPriority = 512;
    mContentsPoolID = -1;
    mContentsPoolGroupID = -1;
    mpContentsPool = nullptr;
    mIsEnable = true;
    mIsDynamic = false;
    mIndex = 0;
    mLayoutGroupIndex = 0;
    mIndexOfLayoutGroup = 0;
    mpExtendObj = nullptr;
    mUniqueID = 4294967295;
    mGroupID = -1;
    mFlgShallowCopyShape = false;
    mpDynamicBVHNode = nullptr;
}

nZone::cLayoutElement::~cLayoutElement() {
    deleteShape();
    if (mpExtendObj != nullptr) {
        delete mpExtendObj;
        mpExtendObj = nullptr;
    }
}

void nZone::cLayoutElement::createProperty(MtPropertyList& s) {
    s << ::MtProperty(static_cast<MtObject*>(this), "mpOwner", reinterpret_cast<MtObject* *>(&mpOwner), 2u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpContentsPool", reinterpret_cast<MtObject* *>(&mpContentsPool), 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_S32, "mContentsPoolID", reinterpret_cast<MT_MFUNC>(&::nZone::cLayoutElement::getContentsPoolID), reinterpret_cast<MT_MFUNC>(&::nZone::cLayoutElement::setContentsPoolID), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), "mIndex", &mIndex, 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mLayoutGroupIndex", &mLayoutGroupIndex, 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mIndexOfLayoutGroup", &mIndexOfLayoutGroup, 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mUniqueID", &mUniqueID, 1u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mGroupID", &mGroupID, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_S32, ::nZone::cLayoutElement::PROP_TITLE_CONTENTS_GROUP_ID, reinterpret_cast<MT_MFUNC>(&::nZone::cLayoutElement::getContentsPoolGroupIDForUI), reinterpret_cast<MT_MFUNC>(&::nZone::cLayoutElement::setContentsPoolGroupIDForUI), 128u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_S32, ::nZone::cLayoutElement::PROP_TITLE_CONTENTS_GROUP_ID_DIRECT, reinterpret_cast<MT_MFUNC>(&::nZone::cLayoutElement::getContentsPoolGroupIDForUI), reinterpret_cast<MT_MFUNC>(&::nZone::cLayoutElement::setContentsPoolGroupIDForUI), 130u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), "mIsEnable", &mIsEnable, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mIsDynamic", &mIsDynamic, 3u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), "mpExtendObj", &mpExtendObj, 0u, 0u);
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_U32, ::nZone::cLayoutElement::PROP_TITLE_SHAPE_TYPE, reinterpret_cast<MT_MFUNC>(&::nZone::cLayoutElement::getShapeTypeInterface), reinterpret_cast<MT_MFUNC>(&::nZone::cLayoutElement::setShapeTypeInterface), 129u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), ::MtProperty::TYPE_CLASSREF, "mpShapeInfo", reinterpret_cast<MT_MFUNC>(&::nZone::cLayoutElement::getShapeInfo), reinterpret_cast<MT_MFUNC>(&::nZone::cLayoutElement::setShapeInfo), 132u, static_cast<MT_MFUNC>(0), static_cast<MT_MFUNC>(0));
    s << ::MtProperty(static_cast<MtObject*>(this), "mPriority", &mPriority, 0u, 0u);
}

void nZone::cLayoutElement::copy(nZone::cLayoutElement* pE) {
    if (pE == nullptr) {
        return;
    }
    mPriority = pE->mPriority;
    mIsEnable = pE->mIsEnable;
    nZone::ShapeInfoBase* t0 = pE->mpShapeInfo;
    if (t0 != nullptr) {
        createShape(static_cast<u32>(t0->getShapeType()));
        if (mpShapeInfo != nullptr) {
            mpShapeInfo->copy(*t0);
        }
    } else {
        if (!mFlgShallowCopyShape) {
            if (mpShapeInfo != nullptr) {
                delete mpShapeInfo;
                mpShapeInfo = nullptr;
            }
        } else {
            mpShapeInfo = nullptr;
        }
    }
    mFlgShallowCopyShape = false;
    copyContents(pE);
}

u32 nZone::cLayoutElement::getShapeType() const {
    if (mpShapeInfo != nullptr) {
        return static_cast<u32>(mpShapeInfo->getShapeType());
    } else {
        return 0;
    }
}

__attribute__((weak)) void nZone::cLayoutElement::createShape(u32 NewShapeType) {
    DDON_STUB("nZone::cLayoutElement::createShape")
    /* stub */
}

s32 nZone::cLayoutElement::getContentsPoolGroupID() const {
    return mContentsPoolGroupID;
}

__attribute__((weak)) void nZone::cLayoutElement::copyFromSystem(cZoneLayout* pOwner, nZone::cLayoutElement& src, nZone::cContentsPool& ContentsPool, u32 LayoutIndex, bool FlgCopyShallow) {
    DDON_STUB("nZone::cLayoutElement::copyFromSystem")
    /* stub */
}

__attribute__((weak)) bool nZone::cLayoutElement::loadBeforeAllocateAlign16(nCollisionUtil::LoadBuffer& buffer, u32 ShapeType) {
    deleteShape();
    bool FlgAllocate = true;
    switch (ShapeType) {
    case nZone::ShapeInfoBase::SHAPE_TYPE_NONE:
        mpShapeInfo = buffer.allocateNewBy<nZone::ShapeInfoBase>(1);
        break;
    case nZone::ShapeInfoBase::SHAPE_TYPE_AREA:
        mpShapeInfo = buffer.allocateNewBy<nZone::ShapeInfoArea>(1);
        break;
    case nZone::ShapeInfoBase::SHAPE_TYPE_AABB:
        mpShapeInfo = buffer.allocateNewBy<nZone::ShapeInfoAABB>(1);
        break;
    case nZone::ShapeInfoBase::SHAPE_TYPE_OBB:
        mpShapeInfo = buffer.allocateNewBy<nZone::ShapeInfoOBB>(1);
        break;
    case nZone::ShapeInfoBase::SHAPE_TYPE_SPHERE:
        mpShapeInfo = buffer.allocateNewBy<nZone::ShapeInfoSphere>(1);
        break;
    case nZone::ShapeInfoBase::SHAPE_TYPE_CAPSULE:
        mpShapeInfo = buffer.allocateNewBy<nZone::ShapeInfoCapsule>(1);
        break;
    case nZone::ShapeInfoBase::SHAPE_TYPE_CYLINDER:
        mpShapeInfo = buffer.allocateNewBy<nZone::ShapeInfoCylinder>(1);
        break;
    case nZone::ShapeInfoBase::SHAPE_TYPE_POINT:
        mpShapeInfo = buffer.allocateNewBy<nZone::ShapeInfoPoint>(1);
        break;
    case nZone::ShapeInfoBase::SHAPE_TYPE_LINE:
        mpShapeInfo = buffer.allocateNewBy<nZone::ShapeInfoLine>(1);
        break;
    case nZone::ShapeInfoBase::SHAPE_TYPE_PANEL:
        mpShapeInfo = buffer.allocateNewBy<nZone::ShapeInfoPanel>(1);
        break;
    case nZone::ShapeInfoBase::SHAPE_TYPE_CONE:
        mpShapeInfo = buffer.allocateNewBy<nZone::ShapeInfoCone>(1);
        break;
    case nZone::ShapeInfoBase::SHAPE_TYPE_GLOBAL:
        mpShapeInfo = buffer.allocateNewBy<nZone::ShapeInfoGlobal>(1);
        break;
    default:
        FlgAllocate = false;
        break;
    }
    if (FlgAllocate && mpShapeInfo == nullptr) {
        return false;
    }
    mFlgShallowCopyShape = true;
    return true;
}

__attribute__((weak)) bool nZone::cLayoutElement::loadBinary(MtDataReader& r) {
    mPriority = r.readS32();
    if (mpShapeInfo != nullptr) {
        mpShapeInfo->loadBinary(r);
    }
    mContentsPoolID = r.readS32();
    mContentsPoolGroupID = r.readS32();
    mIsEnable = r.readU8() == 1;
    mIndex = r.readU32();
    mLayoutGroupIndex = r.readU32();
    mIndexOfLayoutGroup = r.readU32();
    mUniqueID = r.readU32();
    mGroupID = r.readS32();
    const u8 EnableExtend = r.readU8();
    if (EnableExtend == 1) {
        ::MtSerializer sz(65536);
        mpExtendObj = sz.deserializeBinary(r, static_cast<u16>(0), nullptr, ::MtSerializer::MODE_STATE);
        if (mpExtendObj == nullptr) {
            return false;
        }
        if (mpExtendObj->isKindOf(::cZoneExtendObject::DTI)) {
            static_cast< ::cZoneExtendObject*>(mpExtendObj)->registerOwner(this);
        }
    }
    return true;
}

__attribute__((weak)) bool nZone::cLayoutElement::saveBinary(MtDataWriter& w) {
        w.writeS32(mPriority);
        if (mpShapeInfo != nullptr) {
            mpShapeInfo->saveBinary(w);
        }
        w.writeS32(mContentsPoolID);
        w.writeS32(mContentsPoolGroupID);
        w.writeU8(mIsEnable);
        w.writeU32(mIndex);
        w.writeU32(mLayoutGroupIndex);
        w.writeU32(mIndexOfLayoutGroup);
        w.writeU32(mUniqueID);
        w.writeS32(mGroupID);
        if (mpExtendObj != nullptr) {
            w.writeU8(1);
            MtSerializer sz(65536);
            if (!sz.serializeBinary(w, static_cast<u16>(0), mpExtendObj, ::MtSerializer::MODE_STATE, static_cast<const MtDTI*>(nullptr))) {
                return false;
            }
        } else {
            w.writeU8(0);
        }
        return true;
}

static auto ddon_emit_0x01b88e60 __attribute__((used)) = &nZone::cLayoutElement::getShapeInfo;

const nZone::ShapeInfoBase* nZone::cLayoutElement::getShapeInfoResource() const {
    if (mpOwner != nullptr) {
        if (mpOwner->mpNativeResource != nullptr) {
            if (mIndex < mpOwner->mpNativeResource->mLayoutElementsNum) {
                if ((&mpOwner->mpNativeResource->mpLayoutElements[mIndex]) != nullptr) {
                    return mpOwner->mpNativeResource->mpLayoutElements[mIndex].mpShapeInfo;
                }
            }
        }
    }
    return nullptr;
}

static auto ddon_emit_0x01b88e20 __attribute__((used)) = &nZone::cLayoutElement::getContentsPoolID;

void nZone::cLayoutElement::setContentsPoolID(s32 id) {
    if (mpContentsPool != nullptr) {
        if (id > -1) {
            if (id < static_cast<int>(mpContentsPool->mContentsListArray.mLength)) {
                mContentsPoolID = id;
            }
        }
    } else {
        mContentsPoolID = id;
    }
}

__attribute__((weak)) cZoneContents* nZone::cLayoutElement::getContents(u32 index) const {
    DDON_STUB("nZone::cLayoutElement::getContents")
    return nullptr;
}

__attribute__((weak)) cZoneContents* nZone::cLayoutElement::getContents(const MtDTI& contentsDti, u32 SearchStartIndex) const {
    DDON_STUB("nZone::cLayoutElement::getContents")
    return nullptr;
}

__attribute__((weak)) u32 nZone::cLayoutElement::getContentsIndex(const MtDTI& contentsDti, u32 SearchStartIndex) const {
    DDON_STUB("nZone::cLayoutElement::getContentsIndex")
    return {};
}

__attribute__((weak)) u32 nZone::cLayoutElement::getContentsNum() const {
    DDON_STUB("nZone::cLayoutElement::getContentsNum")
    return {};
}

__attribute__((weak)) void nZone::cLayoutElement::setEnable(bool flag) {
    DDON_STUB("nZone::cLayoutElement::setEnable")
    /* stub */
}

bool nZone::cLayoutElement::isEnable() const {
    if (mIsEnable) {
        if (mpOwner != nullptr) {
            const cZoneLayout::cInGameGroupManager* pGroupManager = mpOwner->getGroupManagerFromLayoutConst(*this);
            if (pGroupManager != nullptr) {
                return pGroupManager->mFlgEnable;
            } else {
                return true;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

void nZone::cLayoutElement::setDynamic(bool flag) {
    if (mpShapeInfo != nullptr) {
        if (!mpShapeInfo->mIsNativeData) {
            if (!flag) {
                if (mIsDynamic) {
                    mIsDynamic = flag;
                    if (mpOwner != nullptr) {
                        mpOwner->requestUpdateDBVT(*this);
                    }
                }
            } else {
                mIsDynamic = flag;
                if (mpOwner != nullptr) {
                    mpOwner->requestUpdateDBVT(*this);
                }
            }
        }
    } else {
        if (!flag) {
            if (mIsDynamic) {
                mIsDynamic = flag;
                if (mpOwner != nullptr) {
                    mpOwner->requestUpdateDBVT(*this);
                }
            }
        } else {
            mIsDynamic = flag;
            if (mpOwner != nullptr) {
                mpOwner->requestUpdateDBVT(*this);
            }
        }
    }
}

__attribute__((weak)) void nZone::cLayoutElement::copyContents(nZone::cLayoutElement* pSrcElement) {
    DDON_STUB("nZone::cLayoutElement::copyContents")
    /* stub */
}

void nZone::cLayoutElement::setShapeInfo(nZone::ShapeInfoBase* pShape) {
    if (pShape == mpShapeInfo) {
        return;
    }
    if (mpShapeInfo != nullptr) {
        delete mpShapeInfo;
    }
    mpShapeInfo = pShape;
}

void nZone::cLayoutElement::repairShapeByResource() {
    if (mpShapeInfo == nullptr) {
        return;
    }
    if (mpOwner != nullptr) {
        if (mpOwner->mpNativeResource != nullptr) {
            if (mIndex < mpOwner->mpNativeResource->mLayoutElementsNum) {
                if ((&mpOwner->mpNativeResource->mpLayoutElements[mIndex]) != nullptr) {
                    const nZone::ShapeInfoBase* pOrignalShape = mpOwner->mpNativeResource->mpLayoutElements[mIndex].mpShapeInfo;
                    if (pOrignalShape != nullptr) {
                        createShape(static_cast<u32>(pOrignalShape->getShapeType()));
                        if (mpShapeInfo != nullptr) {
                            mpShapeInfo->copy(*pOrignalShape);
                        }
                    } else {
                        delete mpShapeInfo;
                        mpShapeInfo = nullptr;
                    }
                } else {
                    delete mpShapeInfo;
                    mpShapeInfo = nullptr;
                }
            } else {
                delete mpShapeInfo;
                mpShapeInfo = nullptr;
            }
        } else {
            delete mpShapeInfo;
            mpShapeInfo = nullptr;
        }
    } else {
        delete mpShapeInfo;
        mpShapeInfo = nullptr;
    }
}

__attribute__((weak)) nZone::cContentsPool::cContentsList* nZone::cLayoutElement::getContentsList() const {
    DDON_STUB("nZone::cLayoutElement::getContentsList")
    return nullptr;
}

u32 nZone::cLayoutElement::getShapeTypeInterface() const {
    if (mpShapeInfo != nullptr) {
        return static_cast<u32>(mpShapeInfo->getShapeType());
    } else {
        return 0;
    }
}

void nZone::cLayoutElement::setShapeTypeInterface(u32 type) {
    createShape(type);
}

__attribute__((weak)) void nZone::cLayoutElement::setContentsPoolGroupIDForUI(s32 groupID) {
    DDON_STUB("nZone::cLayoutElement::setContentsPoolGroupIDForUI")
    /* stub */
}

s32 nZone::cLayoutElement::getContentsPoolGroupIDForUI() const {
    return mContentsPoolGroupID;
}

inline nZone::cLayoutElement::MyDTI::MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr) : MtDTI(class_name, ps, size, id, attr, 0u) {}

nZone::cLayoutElement::MyDTI nZone::cLayoutElement::DTI("nZone::cLayoutElement", &::MtObject::DTI, 88ul, 0u, 0u);

MT_CTSTR nZone::cLayoutElement::PROP_TITLE_CONTENTS_GROUP_ID = "GNo";

MT_CTSTR nZone::cLayoutElement::PROP_TITLE_CONTENTS_GROUP_ID_DIRECT = "GNo(Direct)";

MT_CTSTR nZone::cLayoutElement::PROP_TITLE_SHAPE_TYPE = "mShapeType";

__attribute__((weak)) MtObject* nZone::cLayoutElement::MyDTI::newInstance() const {
    DDON_STUB("nZone::cLayoutElement::MyDTI::newInstance")
    return nullptr;
}

template MtTypedArray<nZone::cContentsPool::cContentsList>::~MtTypedArray();

