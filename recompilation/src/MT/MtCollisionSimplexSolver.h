#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtMath.h"

// Forward declarations
class MtVector3;

// Declarations
namespace MtCollisionUtil { class MtSimplexSolver; }

// Type aliases from DWARF
using f32 = float;
using u32 = unsigned int;

namespace MtCollisionUtil {
    class MtSimplexSolver
    {
    public:
        enum SIMPLEX_TYPE
        {
            TYPE_ID_NONE = 0,
            TYPE_ID_POINT = 1,
            TYPE_ID_LINESEGMENT = 2,
            TYPE_ID_TRIANGLE = 3,
            TYPE_ID_TETRAHEDRON = 4,
            TYPE_ID_NUM = 5,
        };
    public:
        MtSimplexSolver(f32 AddVertexEpsilon);
        ~MtSimplexSolver();
        void init();
        bool addVertex(const MtVector3& w, const MtVector3& a, const MtVector3& b);
        bool update(MtVector3& v, u32 LoopIndex);
        f32 getMaxSqDist();
        bool isFull() const;
        bool isEmpty() const;
        bool isExist(const MtVector3&);
        MtVector3* getVertex(u32 id);
        MtVector3* getVertexA(u32 id);
        MtVector3* getVertexB(u32 id);
        u32 getSimplexType();
        void getClosestPosRegistedSimplex(MtVector3& posA, MtVector3& posB, MtVector3& normalA, MtVector3& normalB, const MtVector3& OffsetA, const MtVector3& OffsetB);
    protected:
        void setSimplexType(u32 type);
        void copyData(u32 DestID, u32 SrcID);
        void closestPoint(MtVector3& NextSeparateAxis);
        void closestLineSegment(MtVector3& NextSeparateAxis);
        u32 closestTriangleForTest(bool FlgRegisterDelete, MtVector3& NextSeparateAxis, const MtVector3& p0, const MtVector3& p1, const MtVector3& p2);
        bool closestTetrahedron(MtVector3& NextSeparateAxis, const MtVector3& p0, const MtVector3& p1, const MtVector3& p2, const MtVector3& p3);
        bool isOutsideOriginTriangularPyramid(const MtVector3& p0, const MtVector3& p1, const MtVector3& p2, const MtVector3& p3);
    protected:
        u32 mSimplexType;  // offset: 0x0
        MtVector3 mSimplexVec[6];  // offset: 0x10
        MtVector3 mSimplexPosA[6];  // offset: 0x70
        MtVector3 mSimplexPosB[6];  // offset: 0xd0
        MtVector3 mPos1;  // offset: 0x130
        MtVector3 mPos2;  // offset: 0x140
        MtVector3 mVec;  // offset: 0x150
        MtVector3 mLastVec;  // offset: 0x160
        bool mValidClosest;  // offset: 0x170
        bool mUpdate;  // offset: 0x171
        f32 mAddVertexEpsilon;  // offset: 0x174
    public:
        static const u32 MAX_VERTEX = 6;
    };
}  // namespace MtCollisionUtil
