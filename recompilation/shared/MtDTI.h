#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtAllocator;
class MtArray;
namespace MtCollisionUtil { class MtArrayEx; }
namespace MtCollisionUtil { class MtDtiObject; }
class MtDtiSelecter;
class MtFile;
class MtFileStream;
class MtGeomAABB;
class MtGeomCapsule;
class MtGeomCylinder;
class MtGeomLineSegment;
class MtGeomOBB;
class MtGeomSphere;
class MtGeomTriangle;
class MtMemoryStream;
namespace MtNet { namespace Utility { namespace PS4 { class Json; } } }
class MtNetObject;
class MtNetRanking;
class MtNetServiceError;
class MtObject;
class MtStream;
class MtThread;
class cAIConditionTreeNode;
class cAIFSMCluster;
class cAIFSMData;
class cAIGraph;
class cAIQuadTree;
class cAIService;
class cAITaskJobPrim;
class cAITaskJobPrimList;
class cAITreeBase;
class cAIUserProcess;
class cAIUserProcessCallback;
class cBVHCollision;
class cDynamicBVHCollision;
class cGeomConvexHull;
class cGridCollision;
class cHttpClient;
class cPrim;
class cPrimBuffer;
class cPrimTagList;
class cUnit;
class cWebsocketClient;
class cZoneLayout;
namespace nCaplink { class Object; }
namespace nCaplink { class cAchievementExtendedInfo; }
namespace nCaplink { class cAchievementListInfo; }
namespace nCaplink { class cAchievementRelationInfo; }
namespace nCaplink { class cAchievementRewardInfo; }
namespace nCaplink { class cUserBaseInfo; }
namespace nCaplink { class cWebsocketServerInfo; }
namespace nCollision { class cCollisionNode; }
namespace nDraw { class Animation; }
namespace nDraw { class IndexBuffer; }
namespace nDraw { class OcclusionQuery; }
namespace nDraw { class RasterizerState; }
namespace nDraw { class Scene; }
namespace nDraw { class Texture; }
namespace nDraw { class VertexBuffer; }
namespace nNetwork { class Connect; }
namespace nNetwork { class Match; }
namespace nNetwork { class SessionDatabase; }
namespace nNetwork { class Storage; }
namespace nNetwork { class Transport; }
namespace nNetwork { class VoiceChat; }
namespace nNetwork { namespace nAchievement { class Object; } }
namespace nNetwork { namespace nRanking { class Object; } }
namespace nNetwork { namespace nSharedMemory2 { class Object; } }
namespace nZone { class ShapeInfoOBB; }
namespace nZone { class ShapeInfoPanel; }
namespace nZone { class cContentsPool; }
namespace nZone { class cLayoutElement; }
class rAIConditionTree;
class rArchive;
class rCameraList;
class rCollisionHeightField;
class rEffect2D;
class rEffectList;
class rEffectStrip;
class rGUIIconInfo;
class rGeometry2;
class rMotionList;
class rOccluder;
class rRenderTargetTexture;
class rScheduler;
class rSoundBank;
class rSoundCurveSet;
class rSoundDirectionalSet;
class rSoundStreamSourcePackage;
class rStarCatalog;
class rSwingModel;
class rVibration;
class sApp;
class sGpuParticle;
class sPrimitive;
class sShadow;
class sUserManager;
class sZone;
class uBaseModel;
class uCnsJointOffset;
class uCnsTinyChain;
class uDynamicSbc;
class uEffect;
class uEffect2D;
class uFreeCamera;
class uGeometry2;
class uGeometry2Group;
class uGeometry2GroupCollider;
class uModel;
class uMotionBlurFilter;
class uScheduler;
class uScreenSpace;
class uScrollCollisionGeometry;
class uScrollCollisionGeometryModel;
class uSimSoftBody;
class uSimpleEffect;

// Declarations
class MtDTI;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

// Functions the classes below befriend, declared first
namespace MtMemoryAllocator { MtAllocator* getAllocator(const MtDTI& dti); }

class MtDTI
{
    // inferred: MtArray::operator new names MtDTI::mID
    friend class MtArray;
    // inferred: MtCollisionUtil::MtArrayEx::operator new names MtDTI::mID
    friend class MtCollisionUtil::MtArrayEx;
    // inferred: MtCollisionUtil::MtDtiObject::getRegistDTIName names MtDTI::mName
    friend class MtCollisionUtil::MtDtiObject;
    // inferred: MtDtiSelecter::getSelectDtiID names MtDTI::mID
    friend class MtDtiSelecter;
    // inferred: MtFile::operator new names MtDTI::mID
    friend class MtFile;
    // inferred: MtFileStream::operator new names MtDTI::mID
    friend class MtFileStream;
    // inferred: MtGeomAABB::operator new names MtDTI::mID
    friend class MtGeomAABB;
    // inferred: MtGeomCapsule::operator new names MtDTI::mID
    friend class MtGeomCapsule;
    // inferred: MtGeomCylinder::operator new names MtDTI::mID
    friend class MtGeomCylinder;
    // inferred: MtGeomLineSegment::operator new names MtDTI::mID
    friend class MtGeomLineSegment;
    // inferred: MtGeomOBB::operator new names MtDTI::mID
    friend class MtGeomOBB;
    // inferred: MtGeomSphere::operator new names MtDTI::mID
    friend class MtGeomSphere;
    // inferred: MtGeomTriangle::operator new names MtDTI::mID
    friend class MtGeomTriangle;
    // inferred: MtMemoryAllocator::getAllocator names MtDTI::mAllocatorIndex
    friend MtAllocator* MtMemoryAllocator::getAllocator(const MtDTI& dti);
    // inferred: MtMemoryStream::operator new names MtDTI::mID
    friend class MtMemoryStream;
    // inferred: MtNet::Utility::PS4::Json::operator new names MtDTI::mID
    friend class MtNet::Utility::PS4::Json;
    // inferred: MtNetObject::operator new names MtDTI::mID
    friend class MtNetObject;
    // inferred: MtNetRanking::operator new names MtDTI::mID
    friend class MtNetRanking;
    // inferred: MtNetServiceError::operator new names MtDTI::mID
    friend class MtNetServiceError;
    // inferred: MtStream::operator new names MtDTI::mID
    friend class MtStream;
    // inferred: MtThread::operator new names MtDTI::mID
    friend class MtThread;
    // inferred: cAIConditionTreeNode::operator new names MtDTI::mID
    friend class cAIConditionTreeNode;
    // inferred: cAIFSMCluster::operator new names MtDTI::mID
    friend class cAIFSMCluster;
    // inferred: cAIFSMData::operator new names MtDTI::mID
    friend class cAIFSMData;
    // inferred: cAIGraph::operator new names MtDTI::mID
    friend class cAIGraph;
    // inferred: cAIQuadTree::operator new names MtDTI::mID
    friend class cAIQuadTree;
    // inferred: cAIService::getDTIName names MtDTI::mName
    friend class cAIService;
    // inferred: cAITaskJobPrim::operator new names MtDTI::mID
    friend class cAITaskJobPrim;
    // inferred: cAITaskJobPrimList::operator new names MtDTI::mID
    friend class cAITaskJobPrimList;
    // inferred: cAITreeBase::operator new names MtDTI::mID
    friend class cAITreeBase;
    // inferred: cAIUserProcess::examine names MtDTI::mID
    friend class cAIUserProcess;
    // inferred: cAIUserProcessCallback::operator new names MtDTI::mID
    friend class cAIUserProcessCallback;
    // inferred: cBVHCollision::operator new names MtDTI::mID
    friend class cBVHCollision;
    // inferred: cDynamicBVHCollision::operator new names MtDTI::mID
    friend class cDynamicBVHCollision;
    // inferred: cGeomConvexHull::operator new names MtDTI::mID
    friend class cGeomConvexHull;
    // inferred: cGridCollision::operator new names MtDTI::mID
    friend class cGridCollision;
    // inferred: cHttpClient::operator new names MtDTI::mID
    friend class cHttpClient;
    // inferred: cPrim::operator new names MtDTI::mID
    friend class cPrim;
    // inferred: cPrimBuffer::operator new names MtDTI::mID
    friend class cPrimBuffer;
    // inferred: cPrimTagList::operator new names MtDTI::mID
    friend class cPrimTagList;
    // inferred: cUnit::getName names MtDTI::mName
    friend class cUnit;
    // inferred: cWebsocketClient::operator new names MtDTI::mID
    friend class cWebsocketClient;
    // inferred: cZoneLayout::operator new names MtDTI::mID
    friend class cZoneLayout;
    // inferred: nCaplink::Object::operator new names MtDTI::mID
    friend class nCaplink::Object;
    // inferred: nCaplink::cAchievementExtendedInfo::operator new names MtDTI::mID
    friend class nCaplink::cAchievementExtendedInfo;
    // inferred: nCaplink::cAchievementListInfo::operator new names MtDTI::mID
    friend class nCaplink::cAchievementListInfo;
    // inferred: nCaplink::cAchievementRelationInfo::operator new names MtDTI::mID
    friend class nCaplink::cAchievementRelationInfo;
    // inferred: nCaplink::cAchievementRewardInfo::operator new names MtDTI::mID
    friend class nCaplink::cAchievementRewardInfo;
    // inferred: nCaplink::cUserBaseInfo::operator new names MtDTI::mID
    friend class nCaplink::cUserBaseInfo;
    // inferred: nCaplink::cWebsocketServerInfo::operator new names MtDTI::mID
    friend class nCaplink::cWebsocketServerInfo;
    // inferred: nCollision::cCollisionNode::getEditDTIName names MtDTI::mName
    friend class nCollision::cCollisionNode;
    // inferred: nDraw::Animation::operator new names MtDTI::mID
    friend class nDraw::Animation;
    // inferred: nDraw::IndexBuffer::operator new names MtDTI::mID
    friend class nDraw::IndexBuffer;
    // inferred: nDraw::OcclusionQuery::operator new names MtDTI::mID
    friend class nDraw::OcclusionQuery;
    // inferred: nDraw::RasterizerState::operator new names MtDTI::mID
    friend class nDraw::RasterizerState;
    // inferred: nDraw::Scene::operator new names MtDTI::mID
    friend class nDraw::Scene;
    // inferred: nDraw::Texture::operator new names MtDTI::mID
    friend class nDraw::Texture;
    // inferred: nDraw::VertexBuffer::operator new names MtDTI::mID
    friend class nDraw::VertexBuffer;
    // inferred: nNetwork::Connect::operator new names MtDTI::mID
    friend class nNetwork::Connect;
    // inferred: nNetwork::Match::operator new names MtDTI::mID
    friend class nNetwork::Match;
    // inferred: nNetwork::SessionDatabase::operator new names MtDTI::mID
    friend class nNetwork::SessionDatabase;
    // inferred: nNetwork::Storage::operator new names MtDTI::mID
    friend class nNetwork::Storage;
    // inferred: nNetwork::Transport::operator new names MtDTI::mID
    friend class nNetwork::Transport;
    // inferred: nNetwork::VoiceChat::operator new names MtDTI::mID
    friend class nNetwork::VoiceChat;
    // inferred: nNetwork::nAchievement::Object::operator new names MtDTI::mID
    friend class nNetwork::nAchievement::Object;
    // inferred: nNetwork::nRanking::Object::operator new names MtDTI::mID
    friend class nNetwork::nRanking::Object;
    // inferred: nNetwork::nSharedMemory2::Object::operator new names MtDTI::mID
    friend class nNetwork::nSharedMemory2::Object;
    // inferred: nZone::ShapeInfoOBB::operator new names MtDTI::mID
    friend class nZone::ShapeInfoOBB;
    // inferred: nZone::ShapeInfoPanel::operator new names MtDTI::mID
    friend class nZone::ShapeInfoPanel;
    // inferred: nZone::cContentsPool::operator new names MtDTI::mID
    friend class nZone::cContentsPool;
    // inferred: nZone::cLayoutElement::operator new[] names MtDTI::mID
    friend class nZone::cLayoutElement;
    // inferred: rAIConditionTree::operator new names MtDTI::mID
    friend class rAIConditionTree;
    // inferred: rArchive::operator new names MtDTI::mID
    friend class rArchive;
    // inferred: rCameraList::operator new names MtDTI::mID
    friend class rCameraList;
    // inferred: rCollisionHeightField::operator new names MtDTI::mID
    friend class rCollisionHeightField;
    // inferred: rEffect2D::operator new names MtDTI::mID
    friend class rEffect2D;
    // inferred: rEffectList::operator new names MtDTI::mID
    friend class rEffectList;
    // inferred: rEffectStrip::operator new names MtDTI::mID
    friend class rEffectStrip;
    // inferred: rGUIIconInfo::operator new names MtDTI::mID
    friend class rGUIIconInfo;
    // inferred: rGeometry2::operator new names MtDTI::mID
    friend class rGeometry2;
    // inferred: rMotionList::operator new names MtDTI::mID
    friend class rMotionList;
    // inferred: rOccluder::operator new names MtDTI::mID
    friend class rOccluder;
    // inferred: rRenderTargetTexture::operator new names MtDTI::mID
    friend class rRenderTargetTexture;
    // inferred: rScheduler::operator new names MtDTI::mID
    friend class rScheduler;
    // inferred: rSoundBank::operator new names MtDTI::mID
    friend class rSoundBank;
    // inferred: rSoundCurveSet::operator new names MtDTI::mID
    friend class rSoundCurveSet;
    // inferred: rSoundDirectionalSet::operator new names MtDTI::mID
    friend class rSoundDirectionalSet;
    // inferred: rSoundStreamSourcePackage::operator new names MtDTI::mID
    friend class rSoundStreamSourcePackage;
    // inferred: rStarCatalog::operator new names MtDTI::mID
    friend class rStarCatalog;
    // inferred: rSwingModel::operator new names MtDTI::mID
    friend class rSwingModel;
    // inferred: rVibration::operator new names MtDTI::mID
    friend class rVibration;
    // inferred: sApp::operator new names MtDTI::mID
    friend class sApp;
    // inferred: sGpuParticle::operator new names MtDTI::mID
    friend class sGpuParticle;
    // inferred: sPrimitive::operator new names MtDTI::mID
    friend class sPrimitive;
    // inferred: sShadow::operator new names MtDTI::mID
    friend class sShadow;
    // inferred: sUserManager::operator new names MtDTI::mID
    friend class sUserManager;
    // inferred: sZone::operator new names MtDTI::mID
    friend class sZone;
    // inferred: uBaseModel::operator new names MtDTI::mID
    friend class uBaseModel;
    // inferred: uCnsJointOffset::operator new names MtDTI::mID
    friend class uCnsJointOffset;
    // inferred: uCnsTinyChain::operator new names MtDTI::mID
    friend class uCnsTinyChain;
    // inferred: uDynamicSbc::getName names MtDTI::mName
    friend class uDynamicSbc;
    // inferred: uEffect::operator new names MtDTI::mID
    friend class uEffect;
    // inferred: uEffect2D::operator new names MtDTI::mID
    friend class uEffect2D;
    // inferred: uFreeCamera::operator new names MtDTI::mID
    friend class uFreeCamera;
    // inferred: uGeometry2::operator new names MtDTI::mID
    friend class uGeometry2;
    // inferred: uGeometry2Group::operator new names MtDTI::mID
    friend class uGeometry2Group;
    // inferred: uGeometry2GroupCollider::getName names MtDTI::mName
    friend class uGeometry2GroupCollider;
    // inferred: uModel::operator new names MtDTI::mID
    friend class uModel;
    // inferred: uMotionBlurFilter::operator new names MtDTI::mID
    friend class uMotionBlurFilter;
    // inferred: uScheduler::operator new names MtDTI::mID
    friend class uScheduler;
    // inferred: uScreenSpace::operator new names MtDTI::mID
    friend class uScreenSpace;
    // inferred: uScrollCollisionGeometry::operator new names MtDTI::mID
    friend class uScrollCollisionGeometry;
    // inferred: uScrollCollisionGeometryModel::operator new names MtDTI::mID
    friend class uScrollCollisionGeometryModel;
    // inferred: uSimSoftBody::operator new names MtDTI::mID
    friend class uSimSoftBody;
    // inferred: uSimpleEffect::operator new names MtDTI::mID
    friend class uSimpleEffect;
public:
    enum ATTR
    {
        ATTR_ABSTRACT = 1,
        ATTR_HIDE = 2,
    };
public:
    MtDTI();
    MtDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr, u32 alloc_id);
    // Address: 0x01b26d50 - 0x01b26d51 (1 bytes)
    virtual ~MtDTI() {}
    static const MtDTI* from(MT_CTSTR name, const MtDTI& root);
    static const MtDTI* from(u32 id);
    static void trace();
    static void init();
    static u32 makeID(MT_CTSTR name);
    bool isHide() const;
    bool isAbstract() const;
    MT_CTSTR getName() const;
    operator const char *() const;
    u32 getSize() const;
    u32 getID() const;
    bool operator==(MT_CTSTR) const;
    bool operator!=(MT_CTSTR str) const;
    bool operator==(const MtDTI& type) const;
    bool operator!=(const MtDTI& type) const;
    const MtDTI* getSuper() const;
    const MtDTI* getChild() const;
    const MtDTI* getNext() const;
    virtual MtObject* newInstance() const;  // vtable slot 2
    u32 getAllocIndex() const;
    void setAllocIndex(u32 alloc_id, bool update_child);
    bool compare(const MtDTI&) const;
private:
    void getTypeCount(u32 depth, u32* count);
    void trace(s32 depth);
    void sort();
    MtDTI* getType(MT_CTSTR name) const;
    MtDTI* getType(u32 id) const;
    bool compare(const MtDTI& s, const MtDTI& d) const;
    void updateChildAlloc();
private:
    MT_CTSTR mName;  // offset: 0x8
    MtDTI* mpNext;  // offset: 0x10
    MtDTI* mpChild;  // offset: 0x18
    MtDTI* mpParent;  // offset: 0x20
    MtDTI* mpLink;  // offset: 0x28
    u32 mSize : 23;  // offset: 0x30
    u32 mAllocatorIndex : 6;  // offset: 0x30
    u32 mAttr : 3;  // offset: 0x30
    u32 mID;  // offset: 0x34
    static MtDTI mDTI;
    static const u32 MAX_HASH = 256;
    static const u32 MTDTI_CLASSSIZE_BITSHIFT = 2;
    static MtDTI* mpHashTable[256];
};

// Inline, no code of its own: checked where it is inlined.
inline MT_CTSTR MtDTI::getName() const {
    return this->mName;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 MtDTI::getID() const {
    return this->mID;
}
