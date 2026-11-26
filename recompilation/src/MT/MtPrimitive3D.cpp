// Reconstructed from the game's DWARF debug information.
#include <new>
#include "MtPrimitive3D.h"
#include "MtCollision.h"
#include "MtCollisionMath.h"
#include "MtCollisionPrimitive3D.h"
#include "MtColor.h"
#include "MtMath.h"
#ifndef DDON_STUB
#define DDON_STUB(name)
#endif

bool MtAABB::getSurfaceVertex(MtVector3& p0, MtVector3& p1, MtVector3& p2, MtVector3& p3, u32 VoronoiID) const {
    if (static_cast<int>(VoronoiID) <= 31) {
        if (static_cast<int>(VoronoiID) <= 15) {
            switch (VoronoiID - 1u) {
                case 0:
                {
                    p0.x = minpos.x;
                    p0.y = minpos.y;
                    p0.z = minpos.z;
                    p0.pad_ = 0.0f;
                    const f32 t0 = minpos.y;
                    const f32 t1 = maxpos.z;
                    p1.x = minpos.x;
                    p1.y = t0;
                    p1.z = t1;
                    p1.pad_ = 0.0f;
                    const f32 t2 = maxpos.y;
                    const f32 t3 = maxpos.z;
                    p2.x = minpos.x;
                    p2.y = t2;
                    p2.z = t3;
                    p2.pad_ = 0.0f;
                    const f32 t14 = maxpos.y;
                    const f32 t15 = minpos.z;
                    p3.x = minpos.x;
                    p3.y = t14;
                    p3.z = t15;
                    p3.pad_ = 0.0f;
                    return true;
                }
                case 1:
                {
                    const f32 t16 = minpos.y;
                    const f32 t17 = minpos.z;
                    p0.x = maxpos.x;
                    p0.y = t16;
                    p0.z = t17;
                    p0.pad_ = 0.0f;
                    const f32 t18 = minpos.y;
                    const f32 t19 = maxpos.z;
                    p1.x = maxpos.x;
                    p1.y = t18;
                    p1.z = t19;
                    p1.pad_ = 0.0f;
                    p2.x = maxpos.x;
                    p2.y = maxpos.y;
                    p2.z = maxpos.z;
                    p2.pad_ = 0.0f;
                    const f32 t30 = minpos.z;
                    const f32 t31 = maxpos.y;
                    p3.x = maxpos.x;
                    p3.y = t31;
                    p3.z = t30;
                    p3.pad_ = 0.0f;
                    return true;
                }
                case 3:
                {
                    p0.x = minpos.x;
                    p0.y = minpos.y;
                    p0.z = minpos.z;
                    p0.pad_ = 0.0f;
                    const f32 t20 = minpos.y;
                    const f32 t21 = maxpos.z;
                    p1.x = minpos.x;
                    p1.y = t20;
                    p1.z = t21;
                    p1.pad_ = 0.0f;
                    const f32 t22 = minpos.y;
                    const f32 t23 = maxpos.z;
                    p2.x = maxpos.x;
                    p2.y = t22;
                    p2.z = t23;
                    p2.pad_ = 0.0f;
                    const f32 t24 = minpos.y;
                    const f32 t25 = minpos.z;
                    p3.x = maxpos.x;
                    p3.y = t24;
                    p3.z = t25;
                    p3.pad_ = 0.0f;
                    return true;
                }
                case 7:
                {
                    const f32 t26 = maxpos.y;
                    const f32 t27 = minpos.z;
                    p0.x = minpos.x;
                    p0.y = t26;
                    p0.z = t27;
                    p0.pad_ = 0.0f;
                    const f32 t28 = maxpos.y;
                    const f32 t29 = maxpos.z;
                    p1.x = minpos.x;
                    p1.y = t28;
                    p1.z = t29;
                    p1.pad_ = 0.0f;
                    p2.x = maxpos.x;
                    p2.y = maxpos.y;
                    p2.z = maxpos.z;
                    p2.pad_ = 0.0f;
                    const f32 t30 = minpos.z;
                    const f32 t31 = maxpos.y;
                    p3.x = maxpos.x;
                    p3.y = t31;
                    p3.z = t30;
                    p3.pad_ = 0.0f;
                    return true;
                }
                default:
                {
                    return false;
                }
            }
        } else {
            if (VoronoiID == 16) {
                p0.x = minpos.x;
                p0.y = minpos.y;
                p0.z = minpos.z;
                p0.pad_ = 0.0f;
                const f32 t10 = minpos.y;
                const f32 t11 = minpos.z;
                p1.x = maxpos.x;
                p1.y = t10;
                p1.z = t11;
                p1.pad_ = 0.0f;
                const f32 t12 = minpos.z;
                const f32 t13 = maxpos.y;
                p2.x = maxpos.x;
                p2.y = t13;
                p2.z = t12;
                p2.pad_ = 0.0f;
                const f32 t14 = maxpos.y;
                const f32 t15 = minpos.z;
                p3.x = minpos.x;
                p3.y = t14;
                p3.z = t15;
                p3.pad_ = 0.0f;
                return true;
            } else {
                return false;
            }
        }
    } else {
        if (VoronoiID == 32) {
            const f32 t4 = maxpos.y;
            const f32 t5 = maxpos.z;
            p0.x = minpos.x;
            p0.y = t4;
            p0.z = t5;
            p0.pad_ = 0.0f;
            p1.x = maxpos.x;
            p1.y = maxpos.y;
            p1.z = maxpos.z;
            p1.pad_ = 0.0f;
            const f32 t6 = minpos.y;
            const f32 t7 = maxpos.z;
            p2.x = maxpos.x;
            p2.y = t6;
            p2.z = t7;
            p2.pad_ = 0.0f;
            const f32 t8 = minpos.y;
            const f32 t9 = maxpos.z;
            p3.x = minpos.x;
            p3.y = t8;
            p3.z = t9;
            p3.pad_ = 0.0f;
            return true;
        } else {
            return false;
        }
    }
}

bool MtAABB::getEdge(MtVector3& p0, MtVector3& p1, u32 VoronoiID) const {
    if (static_cast<int>(VoronoiID) <= 16) {
        switch (VoronoiID - 5u) {
            case 0:
            {
                const f32 t0 = minpos.y;
                const f32 t1 = minpos.z;
                p0.x = minpos.x;
                p0.y = t0;
                p0.z = t1;
                p0.pad_ = 0.0f;
                const f32 t2 = minpos.y;
                const f32 t34 = maxpos.z;
                p1.x = minpos.x;
                p1.y = t2;
                p1.z = t34;
                p1.pad_ = 0.0f;
                return true;
            }
            case 1:
            {
                const f32 t9 = minpos.y;
                const f32 t10 = minpos.z;
                p0.x = maxpos.x;
                p0.y = t9;
                p0.z = t10;
                p0.pad_ = 0.0f;
                const f32 t29 = minpos.y;
                const f32 t30 = maxpos.z;
                p1.x = maxpos.x;
                p1.y = t29;
                p1.z = t30;
                p1.pad_ = 0.0f;
                return true;
            }
            case 4:
            {
                const f32 t11 = maxpos.y;
                const f32 t12 = minpos.z;
                p0.x = minpos.x;
                p0.y = t11;
                p0.z = t12;
                p0.pad_ = 0.0f;
                const f32 t33 = maxpos.y;
                const f32 t34 = maxpos.z;
                p1.x = minpos.x;
                p1.y = t33;
                p1.z = t34;
                p1.pad_ = 0.0f;
                return true;
            }
            case 5:
            {
                const f32 t13 = minpos.z;
                const f32 t14 = maxpos.y;
                p0.x = maxpos.x;
                p0.y = t14;
                p0.z = t13;
                p0.pad_ = 0.0f;
                const f32 t33 = maxpos.y;
                const f32 t34 = maxpos.z;
                p1.x = maxpos.x;
                p1.y = t33;
                p1.z = t34;
                p1.pad_ = 0.0f;
                return true;
            }
            default:
            {
                return false;
            }
        }
    } else {
        if (static_cast<int>(VoronoiID) <= 32) {
            switch (VoronoiID - 17u) {
                case 0:
                {
                    const f32 t3 = minpos.y;
                    const f32 t4 = minpos.z;
                    p0.x = minpos.x;
                    p0.y = t3;
                    p0.z = t4;
                    p0.pad_ = 0.0f;
                    const f32 t5 = maxpos.y;
                    const f32 t6 = minpos.z;
                    p1.x = minpos.x;
                    p1.y = t5;
                    p1.z = t6;
                    p1.pad_ = 0.0f;
                    return true;
                }
                case 1:
                {
                    const f32 t15 = minpos.y;
                    const f32 t16 = minpos.z;
                    p0.x = maxpos.x;
                    p0.y = t15;
                    p0.z = t16;
                    p0.pad_ = 0.0f;
                    const f32 t23 = minpos.z;
                    const f32 t24 = maxpos.y;
                    p1.x = maxpos.x;
                    p1.y = t24;
                    p1.z = t23;
                    p1.pad_ = 0.0f;
                    return true;
                }
                case 3:
                {
                    const f32 t17 = minpos.y;
                    const f32 t18 = minpos.z;
                    p0.x = minpos.x;
                    p0.y = t17;
                    p0.z = t18;
                    p0.pad_ = 0.0f;
                    const f32 t19 = minpos.y;
                    const f32 t20 = minpos.z;
                    p1.x = maxpos.x;
                    p1.y = t19;
                    p1.z = t20;
                    p1.pad_ = 0.0f;
                    return true;
                }
                case 7:
                {
                    const f32 t21 = maxpos.y;
                    const f32 t22 = minpos.z;
                    p0.x = minpos.x;
                    p0.y = t21;
                    p0.z = t22;
                    p0.pad_ = 0.0f;
                    const f32 t23 = minpos.z;
                    const f32 t24 = maxpos.y;
                    p1.x = maxpos.x;
                    p1.y = t24;
                    p1.z = t23;
                    p1.pad_ = 0.0f;
                    return true;
                }
                default:
                {
                    return false;
                }
            }
        } else {
            switch (VoronoiID - 33u) {
                case 0:
                {
                    const f32 t7 = minpos.y;
                    const f32 t8 = maxpos.z;
                    p0.x = minpos.x;
                    p0.y = t7;
                    p0.z = t8;
                    p0.pad_ = 0.0f;
                    const f32 t33 = maxpos.y;
                    const f32 t34 = maxpos.z;
                    p1.x = minpos.x;
                    p1.y = t33;
                    p1.z = t34;
                    p1.pad_ = 0.0f;
                    return true;
                }
                case 1:
                {
                    const f32 t25 = minpos.y;
                    const f32 t26 = maxpos.z;
                    p0.x = maxpos.x;
                    p0.y = t25;
                    p0.z = t26;
                    p0.pad_ = 0.0f;
                    const f32 t33 = maxpos.y;
                    const f32 t34 = maxpos.z;
                    p1.x = maxpos.x;
                    p1.y = t33;
                    p1.z = t34;
                    p1.pad_ = 0.0f;
                    return true;
                }
                case 3:
                {
                    const f32 t27 = minpos.y;
                    const f32 t28 = maxpos.z;
                    p0.x = minpos.x;
                    p0.y = t27;
                    p0.z = t28;
                    p0.pad_ = 0.0f;
                    const f32 t29 = minpos.y;
                    const f32 t30 = maxpos.z;
                    p1.x = maxpos.x;
                    p1.y = t29;
                    p1.z = t30;
                    p1.pad_ = 0.0f;
                    return true;
                }
                case 7:
                {
                    const f32 t31 = maxpos.y;
                    const f32 t32 = maxpos.z;
                    p0.x = minpos.x;
                    p0.y = t31;
                    p0.z = t32;
                    p0.pad_ = 0.0f;
                    const f32 t33 = maxpos.y;
                    const f32 t34 = maxpos.z;
                    p1.x = maxpos.x;
                    p1.y = t33;
                    p1.z = t34;
                    p1.pad_ = 0.0f;
                    return true;
                }
                default:
                {
                    return false;
                }
            }
        }
    }
}

extern const unsigned char MtAABB_Empty_bytes[32] __asm__("_ZN6MtAABB5EmptyE");
alignas(16) const unsigned char MtAABB_Empty_bytes[32] __asm__("_ZN6MtAABB5EmptyE") = {
    0xff, 0xff, 0x7f, 0x7f, 0xff, 0xff, 0x7f, 0x7f, 0xff, 0xff, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00,
    0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0x7f, 0xff, 0x00, 0x00, 0x00, 0x00,
};

__attribute__((weak)) f32 MtCapsule::getCapSurfaceAxisPos(const MtVector3& SurfacePos) const {
    DDON_STUB("MtCapsule::getCapSurfaceAxisPos")
    return {};
}

__attribute__((weak)) MtCapsule MtCapsule::transform(const MtMatrix& mat) const {
    DDON_STUB("MtCapsule::transform")
    __builtin_unreachable();
}

__attribute__((weak)) void MtCylinder::getBoundingAABB(MtAABB& aabb) const {
    MtVector3 PosV0(
        (p0.x < p1.x) ? p0.x : p1.x,
        (p0.y < p1.y) ? p0.y : p1.y,
        (p0.z < p1.z) ? p0.z : p1.z
    );
    MtVector3 PosV1(
        (p0.x > p1.x) ? p0.x : p1.x,
        (p0.y > p1.y) ? p0.y : p1.y,
        (p0.z > p1.z) ? p0.z : p1.z
    );
    aabb.minpos = MtVector3(PosV0.x - r, PosV0.y - r, PosV0.z - r);
    aabb.maxpos = MtVector3(PosV1.x + r, PosV1.y + r, PosV1.z + r);
}

MtFrustum::MtFrustum(f32 fov, f32 aspect_ratio, f32 nearz, f32 farz) {
    infinite = false;
    init(fov, aspect_ratio, nearz, farz);
}

MtFrustum::MtFrustum(f32 fov, f32 aspect_ratio, f32 nearz) {
    infinite = true;
    init(fov, aspect_ratio, nearz, nearz);
}

MtFrustum::MtFrustum(MtPlane* plane) {
    DDON_STUB("MtFrustum::MtFrustum")
    /* stub */
}

__attribute__((weak)) void MtFrustum::transform(const MtMatrix& mat) {
    DDON_STUB("MtFrustum::transform")
    /* stub */
}

__attribute__((weak)) MtFrustum::HIT_TYPE MtFrustum::isIntersect(const MtSphere& sphere) const {
    DDON_STUB("MtFrustum::isIntersect")
    return {};
}

__attribute__((weak)) MtFrustum::HIT_TYPE MtFrustum::isIntersect(const MtOBB& obb) const {
    DDON_STUB("MtFrustum::isIntersect")
    return {};
}

__attribute__((weak)) void MtFrustum::init(f32 fov, f32 aspect_ratio, f32 nearz, f32 farz) {
    DDON_STUB("MtFrustum::init")
    /* stub */
}

__attribute__((weak)) void MtOBB::getBoundingAABB(MtAABB& aabb) const {
    MtVector3 v[8];
    const MtVector3 minExtent(-extent.x, -extent.y, -extent.z);
    const MtVector3 maxExtent = extent;
    
    v[0] = MtVector3(minExtent.x, minExtent.y, minExtent.z);
    v[1] = MtVector3(minExtent.x, minExtent.y, maxExtent.z);
    v[2] = MtVector3(maxExtent.x, minExtent.y, maxExtent.z);
    v[3] = MtVector3(maxExtent.x, minExtent.y, minExtent.z);
    v[4] = MtVector3(minExtent.x, maxExtent.y, minExtent.z);
    v[5] = MtVector3(minExtent.x, maxExtent.y, maxExtent.z);
    v[6] = MtVector3(maxExtent.x, maxExtent.y, maxExtent.z);
    v[7] = MtVector3(maxExtent.x, maxExtent.y, minExtent.z);
    
    for (u32 t1 = 0; t1 < 8; ++t1) {
        v[t1] = MtVector3(
            v[t1].x * coord.m[0].x + v[t1].y * coord.m[1].x + v[t1].z * coord.m[2].x + coord.m[3].x,
            v[t1].x * coord.m[0].y + v[t1].y * coord.m[1].y + v[t1].z * coord.m[2].y + coord.m[3].y,
            v[t1].x * coord.m[0].z + v[t1].y * coord.m[1].z + v[t1].z * coord.m[2].z + coord.m[3].z
        );
    }
    
    aabb.minpos = v[0];
    aabb.maxpos = v[0];
    aabb.inflate(v[1]);
    aabb.inflate(v[2]);
    aabb.inflate(v[3]);
    aabb.inflate(v[4]);
    aabb.inflate(v[5]);
    aabb.inflate(v[6]);
    aabb.inflate(v[7]);
}

__attribute__((weak)) void MtOBB::getVertex(MtVector3* out) const {
    DDON_STUB("MtOBB::getVertex")
    /* stub */
}

__attribute__((weak)) MtVector3 MtOBB::getSupport(const MtVector3& v) const {
    DDON_STUB("MtOBB::getSupport")
    __builtin_unreachable();
}

__attribute__((weak)) MtOBB MtOBB::transform(const MtMatrix& matrix) const {
    DDON_STUB("MtOBB::transform")
    __builtin_unreachable();
}

__attribute__((weak)) MtVector2 MtRect3D_XZ::getCenter() const {
    DDON_STUB("MtRect3D_XZ::getCenter")
    __builtin_unreachable();
}

MtVector2 MtRect3D_XZ::getSize() const {
    MtVector2 result;
    const f32 t0 = rb.y;
    const f32 t1 = lt.y;
    result.x = rt.x - lt.x;
    result.y = t0 - t1;
    return result;
}

__attribute__((weak)) void MtTriangle::getBoundingSphere(MtSphere& sphere) const {
    DDON_STUB("MtTriangle::getBoundingSphere")
    /* stub */
}

bool MtTriangle::getNearestEdgeFromUVW(MtLineSegment& edge_out, MtVector3& NoEdgeVtxOut, u32 vid, f32 u, f32 v, f32 w) const {
    if (vid != 0) {
        return false;
    } else {
        if (u > v) {
            edge_out.p0.x = p0.x;
            edge_out.p0.y = p0.y;
            edge_out.p0.z = p0.z;
            edge_out.p0.pad_ = 0.0f;
            if (v > w) {
                edge_out.p1.x = p1.x;
                edge_out.p1.y = p1.y;
                edge_out.p1.z = p1.z;
                edge_out.p1.pad_ = 0.0f;
                NoEdgeVtxOut.x = p2.x;
                NoEdgeVtxOut.y = p2.y;
                NoEdgeVtxOut.z = p2.z;
            } else {
                edge_out.p1.x = p2.x;
                edge_out.p1.y = p2.y;
                edge_out.p1.z = p2.z;
                edge_out.p1.pad_ = 0.0f;
                NoEdgeVtxOut.x = p1.x;
                NoEdgeVtxOut.y = p1.y;
                NoEdgeVtxOut.z = p1.z;
            }
        } else {
            edge_out.p0.x = p1.x;
            edge_out.p0.y = p1.y;
            edge_out.p0.z = p1.z;
            edge_out.p0.pad_ = 0.0f;
            if (u > w) {
                edge_out.p1.x = p0.x;
                edge_out.p1.y = p0.y;
                edge_out.p1.z = p0.z;
                edge_out.p1.pad_ = 0.0f;
                NoEdgeVtxOut.x = p2.x;
                NoEdgeVtxOut.y = p2.y;
                NoEdgeVtxOut.z = p2.z;
            } else {
                edge_out.p1.x = p2.x;
                edge_out.p1.y = p2.y;
                edge_out.p1.z = p2.z;
                edge_out.p1.pad_ = 0.0f;
                NoEdgeVtxOut.x = p0.x;
                NoEdgeVtxOut.y = p0.y;
                NoEdgeVtxOut.z = p0.z;
            }
        }
        NoEdgeVtxOut.pad_ = 0.0f;
        return true;
    }
}

__attribute__((weak)) bool MtTriangle::isDegeneracy() const {
    DDON_STUB("MtTriangle::isDegeneracy")
    return {};
}

__attribute__((weak)) u32 MtTriangle::getDegeneracyType(bool FlgDegenerateFoundEnd) const {
    DDON_STUB("MtTriangle::getDegeneracyType")
    return {};
}

__attribute__((weak)) MtVector3 MtTriangle::getInternalPos() const {
    DDON_STUB("MtTriangle::getInternalPos")
    __builtin_unreachable();
}

