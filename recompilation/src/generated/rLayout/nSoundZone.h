#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtMatrix;
class MtVector3;
class cSoundLayoutInfo;
class cZoneLayout;
namespace nSoundZoneBase { class cSoundZoneContents; }
namespace nZone { class ShapeInfoAABB; }
namespace nZone { class ShapeInfoArea; }
namespace nZone { class ShapeInfoBase; }
namespace nZone { class ShapeInfoCapsule; }
namespace nZone { class ShapeInfoCone; }
namespace nZone { class ShapeInfoCylinder; }
namespace nZone { class ShapeInfoLine; }
namespace nZone { class ShapeInfoOBB; }
namespace nZone { class ShapeInfoPanel; }
namespace nZone { class ShapeInfoPoint; }
namespace nZone { class ShapeInfoSphere; }
namespace nZone { class cLayoutElement; }

namespace nSoundZone {
    enum FREEWORK_CATEGORY
    {
        FREEWORK_CATEGORY_NO_USE = 0,
        FREEWORK_CATEGORY_ROOM = 1,
        FREEWORK_CATEGORY_BAR_BGM = 2,
        FREEWORK_CATEGORY_BASE_BGM = 3,
        FREEWORK_CATEGORY_CYCLE_BGM = 4,
        FREEWORK_CATEGORY_NUM = 5,
    };
}  // namespace nSoundZone

// Type aliases from DWARF
using u32 = unsigned int;

namespace nSoundZone {

    nSoundZoneBase::cSoundZoneContents* getContentsFromLayout(const nZone::cLayoutElement* pLayout, u32 contentsId);
    nSoundZoneBase::cSoundZoneContents* getContentsFromZoneLayout(cZoneLayout* pZone, u32 index, u32 contentsId);
    cSoundLayoutInfo* getLayoutInfoFromZoneLayout(cZoneLayout* pZone, u32 index);
    nZone::ShapeInfoBase* getShapeFromZoneLayout(cZoneLayout* pZone, u32 index);
    void rotationShape(nZone::ShapeInfoArea* pDst, nZone::ShapeInfoArea* pSrc, const MtMatrix& baseMat, const MtVector3& rot);
    void rotationShape(nZone::ShapeInfoAABB* pDst, nZone::ShapeInfoAABB* pSrc, const MtMatrix& baseMat, const MtVector3& rot);
    void rotationShape(nZone::ShapeInfoOBB* pDst, nZone::ShapeInfoOBB* pSrc, const MtMatrix& baseMat, const MtVector3& rot);
    void rotationShape(nZone::ShapeInfoSphere* pDst, nZone::ShapeInfoSphere* pSrc, const MtMatrix& baseMat, const MtVector3& rot);
    void rotationShape(nZone::ShapeInfoCapsule* pDst, nZone::ShapeInfoCapsule* pSrc, const MtMatrix& baseMat, const MtVector3& rot);
    void rotationShape(nZone::ShapeInfoCylinder* pDst, nZone::ShapeInfoCylinder* pSrc, const MtMatrix& baseMat, const MtVector3& rot);
    void rotationShape(nZone::ShapeInfoPoint* pDst, nZone::ShapeInfoPoint* pSrc, const MtMatrix& baseMat, const MtVector3& rot);
    void rotationShape(nZone::ShapeInfoLine* pDst, nZone::ShapeInfoLine* pSrc, const MtMatrix& baseMat, const MtVector3& rot);
    void rotationShape(nZone::ShapeInfoPanel* pDst, nZone::ShapeInfoPanel* pSrc, const MtMatrix& baseMat, const MtVector3& rot);
    void rotationShape(nZone::ShapeInfoCone* pDst, nZone::ShapeInfoCone* pSrc, const MtMatrix& baseMat, const MtVector3& rot);
    MtVector3 calcNormal(const MtVector3& pos0, const MtVector3& pos1, const MtVector3& pos2);
    MtVector3 calcCenterPos(const MtVector3& pos0, const MtVector3& pos1, const MtVector3& pos2);

}  // namespace nSoundZone
