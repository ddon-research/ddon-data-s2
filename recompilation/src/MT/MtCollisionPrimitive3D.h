#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtMath.h"
#include "MtPrimitive3D.h"

// Forward declarations
class MtColor;
class MtPlane;
class MtTriangle;
class MtVector2;
class MtVector3;

// Declarations
namespace MtCollisionUtil { class MtRect3DC; }

// Type aliases from DWARF
using f32 = float;

namespace MtCollisionUtil {
    class MtRect3DC
    {
    public:
        void initialize(const MtVector3& _normal, const MtVector3& center, const MtVector2& size);
        void initialize(const MtVector3&, const MtVector3&, const MtVector3&, const MtVector3&);
        void initialize(const MtVector3& _lt, const MtVector3& _lb, const MtVector3& _rt, const MtVector3& _rb, const MtVector3& _normal);
        void updateEdgeInfo();
        MtVector3 getSupport(const MtVector3& v) const;
        MtVector3 getSupportConst(const MtVector3& v) const;
        MtVector3 getInternalPos() const;
        operator MtVector3 *();
        operator const MtVector3 *() const;
        const MtVector3& getVertexLT() const;
        const MtVector3& getVertexLB() const;
        const MtVector3& getVertexRT() const;
        const MtVector3& getVertexRB() const;
        const MtVector3& getEdgeDirectionLR() const;
        const MtVector3& getEdgeDirectionTB() const;
        f32 getEdgeLengthLR() const;
        f32 getEdgeLengthTB() const;
        const MtVector3& getEdgeNormalizedDirectionLR() const;
        const MtVector3& getEdgeNormalizedDirectionTB() const;
        const MtVector3& getNormal() const;
        MtPlane getPlane() const;
        MtTriangle getTriangle0() const;
        MtTriangle getTriangle1() const;
        MtVector3 getCenter() const;
        MtVector2 getSize() const;
        void trace() const;
        void traceByWarning() const;
        void traceByError() const;
        void debugDraw(MtColor color, bool ztest, f32 NormalLength) const;
    protected:
        MtVector3 lt;  // offset: 0x0
        MtVector3 lb;  // offset: 0x10
        MtVector3 rt;  // offset: 0x20
        MtVector3 rb;  // offset: 0x30
        MtPlane plane;  // offset: 0x40
        MtVector3 DirLR;  // offset: 0x50
        MtVector3 DirTB;  // offset: 0x60
        f32 DirLRLen;  // offset: 0x70
        f32 DirTBLen;  // offset: 0x74
        MtVector3 DirLR_Normalize;  // offset: 0x80
        MtVector3 DirTB_Normalize;  // offset: 0x90
    };
}  // namespace MtCollisionUtil
