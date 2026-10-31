#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtAllocator;
class MtArray;
namespace MtCollisionUtil { class MtArrayEx; }
namespace MtCollisionUtil { class MtDtiObject; }
namespace MtCollisionUtil { class MtTreeDTI; }
class MtDataWriter;
class MtDtiSelecter;
class MtFile;
class MtFileStream;
class MtGeomAABB;
class MtGeomCapsule;
class MtGeomCylinder;
class MtGeomLine;
class MtGeomLineSegment;
class MtGeomOBB;
class MtGeomSphere;
class MtGeomTriangle;
class MtMap;
class MtMemoryStream;
namespace MtNet { namespace Utility { namespace PS4 { class BlockList; } } }
namespace MtNet { namespace Utility { namespace PS4 { class Json; } } }
class MtNetObject;
class MtNetRanking;
class MtNetServiceError;
class MtObject;
class MtStream;
class MtThread;
class cAIConditionTreeNode;
class cAIFSM;
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
class cContextInterface;
class cDynamicBVHCollision;
class cFSMUnit;
class cGUIInstAnimation;
class cGUIUtility;
class cGeneralPoint;
class cGeomConvexHull;
class cGridCollision;
class cHttpClient;
class cLayoutSetEnemy;
class cLayoutSetOm;
class cOmControl;
class cPrim;
class cPrimBuffer;
class cPrimBufferManager;
class cPrimTagList;
class cPrimTexHandleManager;
class cSetInfoCharacter;
class cSetInfoGeneralPoint;
class cSetInfoOm;
class cSetInfoOmBadStatus;
class cSetInfoOmBoard;
class cSetInfoOmBowlOfLife;
class cSetInfoOmCtrl;
class cSetInfoOmDoor;
class cSetInfoOmElfSW;
class cSetInfoOmFall;
class cSetInfoOmGather;
class cSetInfoOmHakuryuu;
class cSetInfoOmHeal;
class cSetInfoOmLadder;
class cSetInfoOmLever;
class cSetInfoOmNav;
class cSetInfoOmRange;
class cSetInfoOmText;
class cSetInfoOmTreasureBox;
class cSetInfoOmWall;
class cSetInfoOmWarp;
class cUnit;
class cWebsocketClient;
class cZoneLayout;
class cpBakeJoint;
class cpEquip;
class cpHumanWarpCtrl;
class cpIKCtrl;
class cpJob09;
class cpJobBase;
class cpSoftBody;
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
namespace nDraw { class MaterialStdEst; }
namespace nDraw { class OcclusionQuery; }
namespace nDraw { class RasterizerState; }
namespace nDraw { class Scene; }
namespace nDraw { class Texture; }
namespace nDraw { class VertexBuffer; }
namespace nNetwork { class Connect; }
namespace nNetwork { class Match; }
namespace nNetwork { class RpcNetSystem_Match; }
namespace nNetwork { class RpcNetSystem_RouteKey; }
namespace nNetwork { class SessionDatabase; }
namespace nNetwork { class Storage; }
namespace nNetwork { class TagChecker; }
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
class rAIPathBase;
class rArchive;
class rCameraList;
class rCollisionHeightField;
class rDynamicSbc;
class rEffect2D;
class rEffectAnim;
class rEffectList;
class rEffectStrip;
class rGUIIconInfo;
class rGUIMessage;
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
class rTexture;
class rVibration;
class sApp;
class sCollision;
class sControlManager;
class sEffect;
class sEffectExt;
class sEnemyManager;
class sGUIExt;
class sGpuParticle;
class sPlatformUtil;
class sPrimitive;
class sRemoteProcedure;
class sResource;
class sShadow;
class sUserManager;
class sZone;
class uBaseModel;
class uCharacter;
class uCnsJointOffset;
class uCnsTinyChain;
class uConstraint;
class uDynamicSbc;
class uEffect;
class uEffect2D;
class uFreeCamera;
class uGUIBase;
class uGUIItemBase01;
class uGUIMap;
class uGUIUseItemBase;
class uGeometry2;
class uGeometry2Collider;
class uGeometry2Group;
class uGeometry2GroupCollider;
class uLight;
class uModel;
class uMotionBlurFilter;
class uScheduler;
class uScreenSpace;
class uScrollCollisionGeometry;
class uScrollCollisionGeometryModel;
class uShadow;
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
namespace MtCollisionUtil { bool saveDTI(MtDataWriter& w, const MtDTI* pSaveDTI); }
namespace MtMemoryAllocator { MtAllocator* getAllocator(const MtDTI& dti); }

class MtDTI
{
    friend class MtArray;
    friend class MtCollisionUtil::MtArrayEx;
    friend class MtCollisionUtil::MtDtiObject;
    friend class MtCollisionUtil::MtTreeDTI;
    friend bool MtCollisionUtil::saveDTI(MtDataWriter& w, const MtDTI* pSaveDTI);
    friend class MtDtiSelecter;
    friend class MtFile;
    friend class MtFileStream;
    friend class MtGeomAABB;
    friend class MtGeomCapsule;
    friend class MtGeomCylinder;
    friend class MtGeomLine;
    friend class MtGeomLineSegment;
    friend class MtGeomOBB;
    friend class MtGeomSphere;
    friend class MtGeomTriangle;
    friend class MtMap;
    friend MtAllocator* MtMemoryAllocator::getAllocator(const MtDTI& dti);
    friend class MtMemoryStream;
    friend class MtNet::Utility::PS4::BlockList;
    friend class MtNet::Utility::PS4::Json;
    friend class MtNetObject;
    friend class MtNetRanking;
    friend class MtNetServiceError;
    friend class MtStream;
    friend class MtThread;
    friend class cAIConditionTreeNode;
    friend class cAIFSM;
    friend class cAIFSMCluster;
    friend class cAIFSMData;
    friend class cAIGraph;
    friend class cAIQuadTree;
    friend class cAIService;
    friend class cAITaskJobPrim;
    friend class cAITaskJobPrimList;
    friend class cAITreeBase;
    friend class cAIUserProcess;
    friend class cAIUserProcessCallback;
    friend class cBVHCollision;
    friend class cContextInterface;
    friend class cDynamicBVHCollision;
    friend class cFSMUnit;
    friend class cGUIInstAnimation;
    friend class cGUIUtility;
    friend class cGeneralPoint;
    friend class cGeomConvexHull;
    friend class cGridCollision;
    friend class cHttpClient;
    friend class cLayoutSetEnemy;
    friend class cLayoutSetOm;
    friend class cOmControl;
    friend class cPrim;
    friend class cPrimBuffer;
    friend class cPrimBufferManager;
    friend class cPrimTagList;
    friend class cPrimTexHandleManager;
    friend class cSetInfoCharacter;
    friend class cSetInfoGeneralPoint;
    friend class cSetInfoOm;
    friend class cSetInfoOmBadStatus;
    friend class cSetInfoOmBoard;
    friend class cSetInfoOmBowlOfLife;
    friend class cSetInfoOmCtrl;
    friend class cSetInfoOmDoor;
    friend class cSetInfoOmElfSW;
    friend class cSetInfoOmFall;
    friend class cSetInfoOmGather;
    friend class cSetInfoOmHakuryuu;
    friend class cSetInfoOmHeal;
    friend class cSetInfoOmLadder;
    friend class cSetInfoOmLever;
    friend class cSetInfoOmNav;
    friend class cSetInfoOmRange;
    friend class cSetInfoOmText;
    friend class cSetInfoOmTreasureBox;
    friend class cSetInfoOmWall;
    friend class cSetInfoOmWarp;
    friend class cUnit;
    friend class cWebsocketClient;
    friend class cZoneLayout;
    friend class cpBakeJoint;
    friend class cpEquip;
    friend class cpHumanWarpCtrl;
    friend class cpIKCtrl;
    friend class cpJob09;
    friend class cpJobBase;
    friend class cpSoftBody;
    friend class nCaplink::Object;
    friend class nCaplink::cAchievementExtendedInfo;
    friend class nCaplink::cAchievementListInfo;
    friend class nCaplink::cAchievementRelationInfo;
    friend class nCaplink::cAchievementRewardInfo;
    friend class nCaplink::cUserBaseInfo;
    friend class nCaplink::cWebsocketServerInfo;
    friend class nCollision::cCollisionNode;
    friend class nDraw::Animation;
    friend class nDraw::IndexBuffer;
    friend class nDraw::MaterialStdEst;
    friend class nDraw::OcclusionQuery;
    friend class nDraw::RasterizerState;
    friend class nDraw::Scene;
    friend class nDraw::Texture;
    friend class nDraw::VertexBuffer;
    friend class nNetwork::Connect;
    friend class nNetwork::Match;
    friend class nNetwork::RpcNetSystem_Match;
    friend class nNetwork::RpcNetSystem_RouteKey;
    friend class nNetwork::SessionDatabase;
    friend class nNetwork::Storage;
    friend class nNetwork::TagChecker;
    friend class nNetwork::Transport;
    friend class nNetwork::VoiceChat;
    friend class nNetwork::nAchievement::Object;
    friend class nNetwork::nRanking::Object;
    friend class nNetwork::nSharedMemory2::Object;
    friend class nZone::ShapeInfoOBB;
    friend class nZone::ShapeInfoPanel;
    friend class nZone::cContentsPool;
    friend class nZone::cLayoutElement;
    friend class rAIConditionTree;
    friend class rAIPathBase;
    friend class rArchive;
    friend class rCameraList;
    friend class rCollisionHeightField;
    friend class rDynamicSbc;
    friend class rEffect2D;
    friend class rEffectAnim;
    friend class rEffectList;
    friend class rEffectStrip;
    friend class rGUIIconInfo;
    friend class rGUIMessage;
    friend class rGeometry2;
    friend class rMotionList;
    friend class rOccluder;
    friend class rRenderTargetTexture;
    friend class rScheduler;
    friend class rSoundBank;
    friend class rSoundCurveSet;
    friend class rSoundDirectionalSet;
    friend class rSoundStreamSourcePackage;
    friend class rStarCatalog;
    friend class rSwingModel;
    friend class rTexture;
    friend class rVibration;
    friend class sApp;
    friend class sCollision;
    friend class sControlManager;
    friend class sEffect;
    friend class sEffectExt;
    friend class sEnemyManager;
    friend class sGUIExt;
    friend class sGpuParticle;
    friend class sPlatformUtil;
    friend class sPrimitive;
    friend class sRemoteProcedure;
    friend class sResource;
    friend class sShadow;
    friend class sUserManager;
    friend class sZone;
    friend class uBaseModel;
    friend class uCharacter;
    friend class uCnsJointOffset;
    friend class uCnsTinyChain;
    friend class uConstraint;
    friend class uDynamicSbc;
    friend class uEffect;
    friend class uEffect2D;
    friend class uFreeCamera;
    friend class uGUIBase;
    friend class uGUIItemBase01;
    friend class uGUIMap;
    friend class uGUIUseItemBase;
    friend class uGeometry2;
    friend class uGeometry2Collider;
    friend class uGeometry2Group;
    friend class uGeometry2GroupCollider;
    friend class uLight;
    friend class uModel;
    friend class uMotionBlurFilter;
    friend class uScheduler;
    friend class uScreenSpace;
    friend class uScrollCollisionGeometry;
    friend class uScrollCollisionGeometryModel;
    friend class uShadow;
    friend class uSimSoftBody;
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

inline MT_CTSTR MtDTI::getName() const {
    return this->mName;
}

inline u32 MtDTI::getID() const {
    return this->mID;
}
