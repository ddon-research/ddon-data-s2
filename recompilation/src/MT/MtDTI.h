#pragma once

#include <cstdint>
#include <cstddef>

// Forward declarations
class MtAllocator;
class MtArray;
namespace MtCollisionUtil { class MtArrayEx; }
namespace MtCollisionUtil { class MtDataBuffer; }
namespace MtCollisionUtil { class MtDtiObject; }
namespace MtCollisionUtil { class MtFuncBase; }
namespace MtCollisionUtil { class MtLinerTree; }
namespace MtCollisionUtil { class MtList; }
namespace MtCollisionUtil { class MtListElement; }
namespace MtCollisionUtil { class MtTreeDTI; }
class MtDataWriter;
class MtDtiSelecter;
class MtFile;
class MtFileStream;
class MtGeomAABB;
class MtGeomAABB4;
class MtGeomCapsule;
class MtGeomCylinder;
class MtGeomLine;
class MtGeomLineSegment;
class MtGeomLineSegment4;
class MtGeomLineSweptSphere;
class MtGeomOBB;
class MtGeomPlane;
class MtGeomRay;
class MtGeomSphere;
class MtGeomTriangle;
class MtMap;
namespace MtMemoryAllocator { class Initializer; }
class MtMemoryStream;
namespace MtNet { namespace Utility { namespace PS4 { class BlockList; } } }
namespace MtNet { namespace Utility { namespace PS4 { class Json; } } }
class MtNetObject;
class MtNetRanking;
class MtNetServiceError;
class MtObject;
class MtPerformance;
class MtPerformanceCounter;
class MtScalableAllocator;
class MtStream;
class MtThread;
class MtTree;
class cAIConditionTreeNode;
class cAIDEnum;
class cAIFSM;
class cAIFSMCluster;
class cAIFSMData;
class cAIFSMLink;
class cAIFSMNode;
class cAIFSMProcessContainer;
class cAIGraph;
class cAINavPathTrace;
class cAIObject;
class cAIPathTrace;
class cAIQuadTree;
class cAIResource;
class cAIService;
class cAISvNavPathFinding;
class cAISvPathFinding;
class cAISvUserProcess;
class cAITaskJobPrim;
class cAITaskJobPrimList;
class cAITreeBase;
class cAIUserProcess;
class cAIUserProcessCallback;
class cAIUserProcessReference;
class cBVHCollision;
class cColliderNodeParam;
class cContextInterface;
class cDDMaterialCtrl;
class cDynamicBVHCollision;
class cFSMBase;
class cFSMUnit;
class cGUIInstAnimation;
class cGUIInstRoot;
class cGUIUtility;
class cGeneralPoint;
class cGeomConvexHull;
class cGridCollision;
class cHttpClient;
class cLayoutSetEnemy;
class cLayoutSetOm;
class cMenuBase;
class cOmControl;
class cPlActWpnBow;
class cPrim;
class cPrimBuffer;
class cPrimBufferManager;
class cPrimObj;
class cPrimTagList;
class cPrimTexHandle;
class cPrimTexHandleManager;
class cQuestSvNoticeCallback;
class cQuestSvReqQuestCancel;
class cQuestSvReqQuestProgress;
class cQuestSvRequestManager;
class cSetInfoCharacter;
class cSetInfoEnemy;
class cSetInfoGeneralPoint;
class cSetInfoOm;
class cSetInfoOmBadStatus;
class cSetInfoOmBlock;
class cSetInfoOmBoard;
class cSetInfoOmBowlOfLife;
class cSetInfoOmBreakTarget;
class cSetInfoOmCtrl;
class cSetInfoOmDoor;
class cSetInfoOmElfSW;
class cSetInfoOmEx;
class cSetInfoOmFall;
class cSetInfoOmGather;
class cSetInfoOmHakuryuu;
class cSetInfoOmHeal;
class cSetInfoOmLadder;
class cSetInfoOmLever;
class cSetInfoOmNav;
class cSetInfoOmOldDoor;
class cSetInfoOmOneWay;
class cSetInfoOmRange;
class cSetInfoOmText;
class cSetInfoOmTreasureBox;
class cSetInfoOmWall;
class cSetInfoOmWarp;
class cSoundGeneratorListener;
class cSoundTriggerListener;
class cStateMachineBase;
class cSwing;
class cUnit;
class cWebsocketClient;
class cZoneContents;
class cZoneLayout;
class cpBakeJoint;
class cpCharacterEdit;
class cpEquip;
class cpHmHeadCtrl;
class cpHumanWarpCtrl;
class cpIKCtrl;
class cpJob09;
class cpJobBase;
class cpShlSelectorJob10Cs08;
class cpSoftBody;
namespace nAI { class EnumProp; }

namespace nAI { class TaskPerformanceInfo; }
namespace nCaplink { class ContextListener; }
namespace nCaplink { class Object; }
namespace nCaplink { class cAchievementExtendedInfo; }
namespace nCaplink { class cAchievementListInfo; }
namespace nCaplink { class cAchievementRelationInfo; }
namespace nCaplink { class cAchievementRewardInfo; }
namespace nCaplink { class cChatGroupInfo; }
namespace nCaplink { class cChatUserInfo; }
namespace nCaplink { class cContentInfo; }
namespace nCaplink { class cContentInviteAvailableUserInfo; }
namespace nCaplink { class cContentInviteUserInfo; }
namespace nCaplink { class cContentTagInfo; }
namespace nCaplink { class cFreeTagInfo; }
namespace nCaplink { class cFriendEntryInfo; }
namespace nCaplink { class cFriendInfo; }
namespace nCaplink { class cIgnoreUserInfo; }
namespace nCaplink { class cNotifyAppInfo; }
namespace nCaplink { class cResourceInfo; }
namespace nCaplink { class cTagInfo; }
namespace nCaplink { class cUserBaseInfo; }
namespace nCaplink { class cUserContentInfo; }
namespace nCaplink { class cWebsocketServerInfo; }
namespace nCollision { class cCollisionNode; }
namespace nCollision { class cCollisionNodeGroup; }
namespace nCollision { class cMotionSequenceSupport; }
namespace nCollision { class cScrCommonFilter; }
namespace nCollisionUtil { class cOwnerSystem; }
namespace nDraw { class Animation; }
namespace nDraw { class IndexBuffer; }
namespace nDraw { class InputLayout; }
namespace nDraw { class MaterialNull; }
namespace nDraw { class MaterialStd; }
namespace nDraw { class MaterialStdDM; }
namespace nDraw { class MaterialStdEst; }
namespace nDraw { class MaterialStdPN; }
namespace nDraw { class OcclusionQuery; }
namespace nDraw { class RasterizerState; }
namespace nDraw { class SamplerState; }
namespace nDraw { class Scene; }
namespace nDraw { class Texture; }
namespace nDraw { class VertexBuffer; }
namespace nNetwork { class BlockBuffer; }
namespace nNetwork { class Callback; }
namespace nNetwork { class Connect; }
namespace nNetwork { class Match; }
namespace nNetwork { class ProtocolStandard; }
namespace nNetwork { class RpcNetSystem_LinkState; }
namespace nNetwork { class RpcNetSystem_Match; }
namespace nNetwork { class RpcNetSystem_RouteKey; }
namespace nNetwork { class SessionDatabase; }
namespace nNetwork { class SessionListener; }
namespace nNetwork { class Storage; }
namespace nNetwork { class TagChecker; }
namespace nNetwork { class Transport; }
namespace nNetwork { class VoiceChat; }
namespace nNetwork { namespace nAchievement { class Object; } }
namespace nNetwork { namespace nRanking { class Object; } }
namespace nNetwork { namespace nSharedMemory2 { class CProtocol; } }
namespace nNetwork { namespace nSharedMemory2 { class CRecord; } }
namespace nNetwork { namespace nSharedMemory2 { class Object; } }
namespace nZone { class ShapeInfoAABB; }
namespace nZone { class ShapeInfoArea; }
namespace nZone { class ShapeInfoCapsule; }
namespace nZone { class ShapeInfoCone; }
namespace nZone { class ShapeInfoCylinder; }
namespace nZone { class ShapeInfoOBB; }
namespace nZone { class ShapeInfoPanel; }
namespace nZone { class ShapeInfoSphere; }
namespace nZone { class cContentsPool; }
namespace nZone { class cLayoutElement; }
class rAIConditionTree;
class rAIFSM;
class rAIPathBase;
class rArchive;
class rCameraList;
class rCollisionHeightField;
class rDeformWeightMap;
class rDynamicSbc;
class rEffect2D;
class rEffectAnim;
class rEffectList;
class rEffectStrip;
class rFullbodyIKHuman2;
class rGUI;
class rGUIIconInfo;
class rGUIMessage;
class rGeometry2;
class rMaterial;
class rModel;
class rMotionList;
class rNavigationMesh;
class rOccluder;
class rRenderTargetTexture;
class rScheduler;
class rShaderPackage;
class rSoundBank;
class rSoundCurveSet;
class rSoundDirectionalSet;
class rSoundSourceStreamAT9;
class rSoundStreamSourcePackage;
class rStarCatalog;
class rSwingModel;
class rTexture;
class rTextureMemory;
class rVertices;
class rVibration;
class rZone;
class sAI;
class sApp;
class sCollision;
class sControlManager;
class sEffect;
class sEffectExt;
class sEnemyManager;
class sGUI;
class sGUIExt;
class sGpuParticle;
class sPlatformUtil;
class sPrimitive;
class sRemoteProcedure;
class sResource;
class sScene;
class sShader2;
class sShadow;
class sSound;
class sTalkManager;
class sUnit;
class sUserManager;
class sWeatherManager;
class sZone;
class uBaseModel;
class uCharacter;
class uCnsJointOffset;
class uCnsTinyChain;
class uConstraint;
class uDOFFilter;
class uDynamicSbc;
class uEffect;
class uEffect2D;
class uEffectExt;
class uFSMTask;
class uFreeCamera;
class uFullbodyIKHuman2;
class uGUI;
class uGUIBase;
class uGUICaplinkMenuBase;
class uGUICharacterEdit;
class uGUIItem01;
class uGUIItemBase01;
class uGUIMap;
class uGUIStorage;
class uGUIUseItemBase;
class uGeometry2;
class uGeometry2Collider;
class uGeometry2Group;
class uGeometry2GroupCollider;
class uLight;
class uModel;
class uMotionBlurFilter;
class uMotionCamera;
class uMovie;
class uMultiBloomFilter;
class uMultiBlurFilter;
class uMultiColorCorrectFilter;
class uMultiGodRaysFilter;
class uScheduler;
class uScreenSpace;
class uScrollCollisionGeometry;
class uScrollCollisionGeometryGroupModel;
class uScrollCollisionGeometryModel;
class uShadow;
class uShlComponentCtrl;
class uSimSoftBody;
class uSimpleEffect;
class uSoundMotionSe;

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
namespace MtMemoryAllocator { void setMtMemoryAllocator(const Initializer& init); }

class MtDTI
{
    friend class MtArray;
    friend class MtCollisionUtil::MtArrayEx;
    friend class MtCollisionUtil::MtDataBuffer;
    friend class MtCollisionUtil::MtDtiObject;
    friend class MtCollisionUtil::MtFuncBase;
    friend class MtCollisionUtil::MtLinerTree;
    friend class MtCollisionUtil::MtList;
    friend class MtCollisionUtil::MtListElement;
    friend class MtCollisionUtil::MtTreeDTI;
    friend bool MtCollisionUtil::saveDTI(MtDataWriter& w, const MtDTI* pSaveDTI);
    friend class MtDtiSelecter;
    friend class MtFile;
    friend class MtFileStream;
    friend class MtGeomAABB;
    friend class MtGeomAABB4;
    friend class MtGeomCapsule;
    friend class MtGeomCylinder;
    friend class MtGeomLine;
    friend class MtGeomLineSegment;
    friend class MtGeomLineSegment4;
    friend class MtGeomLineSweptSphere;
    friend class MtGeomOBB;
    friend class MtGeomPlane;
    friend class MtGeomRay;
    friend class MtGeomSphere;
    friend class MtGeomTriangle;
    friend class MtMap;
    friend MtAllocator* MtMemoryAllocator::getAllocator(const MtDTI& dti);
    friend void MtMemoryAllocator::setMtMemoryAllocator(const MtMemoryAllocator::Initializer& init);
    friend class MtMemoryStream;
    friend class MtNet::Utility::PS4::BlockList;
    friend class MtNet::Utility::PS4::Json;
    friend class MtNetObject;
    friend class MtNetRanking;
    friend class MtNetServiceError;
    friend class MtPerformance;
    friend class MtPerformanceCounter;
    friend class MtScalableAllocator;
    friend class MtStream;
    friend class MtThread;
    friend class MtTree;
    friend class cAIConditionTreeNode;
    friend class cAIDEnum;
    friend class cAIFSM;
    friend class cAIFSMCluster;
    friend class cAIFSMData;
    friend class cAIFSMLink;
    friend class cAIFSMNode;
    friend class cAIFSMProcessContainer;
    friend class cAIGraph;
    friend class cAINavPathTrace;
    friend class cAIObject;
    friend class cAIPathTrace;
    friend class cAIQuadTree;
    friend class cAIResource;
    friend class cAIService;
    friend class cAISvNavPathFinding;
    friend class cAISvPathFinding;
    friend class cAISvUserProcess;
    friend class cAITaskJobPrim;
    friend class cAITaskJobPrimList;
    friend class cAITreeBase;
    friend class cAIUserProcess;
    friend class cAIUserProcessCallback;
    friend class cAIUserProcessReference;
    friend class cBVHCollision;
    friend class cColliderNodeParam;
    friend class cContextInterface;
    friend class cDDMaterialCtrl;
    friend class cDynamicBVHCollision;
    friend class cFSMBase;
    friend class cFSMUnit;
    friend class cGUIInstAnimation;
    friend class cGUIInstRoot;
    friend class cGUIUtility;
    friend class cGeneralPoint;
    friend class cGeomConvexHull;
    friend class cGridCollision;
    friend class cHttpClient;
    friend class cLayoutSetEnemy;
    friend class cLayoutSetOm;
    friend class cMenuBase;
    friend class cOmControl;
    friend class cPlActWpnBow;
    friend class cPrim;
    friend class cPrimBuffer;
    friend class cPrimBufferManager;
    friend class cPrimObj;
    friend class cPrimTagList;
    friend class cPrimTexHandle;
    friend class cPrimTexHandleManager;
    friend class cQuestSvNoticeCallback;
    friend class cQuestSvReqQuestCancel;
    friend class cQuestSvReqQuestProgress;
    friend class cQuestSvRequestManager;
    friend class cSetInfoCharacter;
    friend class cSetInfoEnemy;
    friend class cSetInfoGeneralPoint;
    friend class cSetInfoOm;
    friend class cSetInfoOmBadStatus;
    friend class cSetInfoOmBlock;
    friend class cSetInfoOmBoard;
    friend class cSetInfoOmBowlOfLife;
    friend class cSetInfoOmBreakTarget;
    friend class cSetInfoOmCtrl;
    friend class cSetInfoOmDoor;
    friend class cSetInfoOmElfSW;
    friend class cSetInfoOmEx;
    friend class cSetInfoOmFall;
    friend class cSetInfoOmGather;
    friend class cSetInfoOmHakuryuu;
    friend class cSetInfoOmHeal;
    friend class cSetInfoOmLadder;
    friend class cSetInfoOmLever;
    friend class cSetInfoOmNav;
    friend class cSetInfoOmOldDoor;
    friend class cSetInfoOmOneWay;
    friend class cSetInfoOmRange;
    friend class cSetInfoOmText;
    friend class cSetInfoOmTreasureBox;
    friend class cSetInfoOmWall;
    friend class cSetInfoOmWarp;
    friend class cSoundGeneratorListener;
    friend class cSoundTriggerListener;
    friend class cStateMachineBase;
    friend class cSwing;
    friend class cUnit;
    friend class cWebsocketClient;
    friend class cZoneContents;
    friend class cZoneLayout;
    friend class cpBakeJoint;
    friend class cpCharacterEdit;
    friend class cpEquip;
    friend class cpHmHeadCtrl;
    friend class cpHumanWarpCtrl;
    friend class cpIKCtrl;
    friend class cpJob09;
    friend class cpJobBase;
    friend class cpShlSelectorJob10Cs08;
    friend class cpSoftBody;
    friend class nAI::EnumProp;

    friend class nAI::TaskPerformanceInfo;
    friend class nCaplink::ContextListener;
    friend class nCaplink::Object;
    friend class nCaplink::cAchievementExtendedInfo;
    friend class nCaplink::cAchievementListInfo;
    friend class nCaplink::cAchievementRelationInfo;
    friend class nCaplink::cAchievementRewardInfo;
    friend class nCaplink::cChatGroupInfo;
    friend class nCaplink::cChatUserInfo;
    friend class nCaplink::cContentInfo;
    friend class nCaplink::cContentInviteAvailableUserInfo;
    friend class nCaplink::cContentInviteUserInfo;
    friend class nCaplink::cContentTagInfo;
    friend class nCaplink::cFreeTagInfo;
    friend class nCaplink::cFriendEntryInfo;
    friend class nCaplink::cFriendInfo;
    friend class nCaplink::cIgnoreUserInfo;
    friend class nCaplink::cNotifyAppInfo;
    friend class nCaplink::cResourceInfo;
    friend class nCaplink::cTagInfo;
    friend class nCaplink::cUserBaseInfo;
    friend class nCaplink::cUserContentInfo;
    friend class nCaplink::cWebsocketServerInfo;
    friend class nCollision::cCollisionNode;
    friend class nCollision::cCollisionNodeGroup;
    friend class nCollision::cMotionSequenceSupport;
    friend class nCollision::cScrCommonFilter;
    friend class nCollisionUtil::cOwnerSystem;
    friend class nDraw::Animation;
    friend class nDraw::IndexBuffer;
    friend class nDraw::InputLayout;
    friend class nDraw::MaterialNull;
    friend class nDraw::MaterialStd;
    friend class nDraw::MaterialStdDM;
    friend class nDraw::MaterialStdEst;
    friend class nDraw::MaterialStdPN;
    friend class nDraw::OcclusionQuery;
    friend class nDraw::RasterizerState;
    friend class nDraw::SamplerState;
    friend class nDraw::Scene;
    friend class nDraw::Texture;
    friend class nDraw::VertexBuffer;
    friend class nNetwork::BlockBuffer;
    friend class nNetwork::Callback;
    friend class nNetwork::Connect;
    friend class nNetwork::Match;
    friend class nNetwork::ProtocolStandard;
    friend class nNetwork::RpcNetSystem_LinkState;
    friend class nNetwork::RpcNetSystem_Match;
    friend class nNetwork::RpcNetSystem_RouteKey;
    friend class nNetwork::SessionDatabase;
    friend class nNetwork::SessionListener;
    friend class nNetwork::Storage;
    friend class nNetwork::TagChecker;
    friend class nNetwork::Transport;
    friend class nNetwork::VoiceChat;
    friend class nNetwork::nAchievement::Object;
    friend class nNetwork::nRanking::Object;
    friend class nNetwork::nSharedMemory2::CProtocol;
    friend class nNetwork::nSharedMemory2::CRecord;
    friend class nNetwork::nSharedMemory2::Object;
    friend class nZone::ShapeInfoAABB;
    friend class nZone::ShapeInfoArea;
    friend class nZone::ShapeInfoCapsule;
    friend class nZone::ShapeInfoCone;
    friend class nZone::ShapeInfoCylinder;
    friend class nZone::ShapeInfoOBB;
    friend class nZone::ShapeInfoPanel;
    friend class nZone::ShapeInfoSphere;
    friend class nZone::cContentsPool;
    friend class nZone::cLayoutElement;
    friend class rAIConditionTree;
    friend class rAIFSM;
    friend class rAIPathBase;
    friend class rArchive;
    friend class rCameraList;
    friend class rCollisionHeightField;
    friend class rDeformWeightMap;
    friend class rDynamicSbc;
    friend class rEffect2D;
    friend class rEffectAnim;
    friend class rEffectList;
    friend class rEffectStrip;
    friend class rFullbodyIKHuman2;
    friend class rGUI;
    friend class rGUIIconInfo;
    friend class rGUIMessage;
    friend class rGeometry2;
    friend class rMaterial;
    friend class rModel;
    friend class rMotionList;
    friend class rNavigationMesh;
    friend class rOccluder;
    friend class rRenderTargetTexture;
    friend class rScheduler;
    friend class rShaderPackage;
    friend class rSoundBank;
    friend class rSoundCurveSet;
    friend class rSoundDirectionalSet;

    friend class rSoundAreaInfo;
    friend class rSoundRequest;
    friend class rSoundStreamRequest;
    friend class rZone;

    friend class rSoundReverb;
    friend class rSoundSourceStreamAT9;
    friend class rSoundStreamSourcePackage;
    friend class rStarCatalog;
    friend class rSwingModel;
    friend class rTexture;
    friend class rTextureMemory;
    friend class rVertices;
    friend class rVibration;
    friend class rZone;
    friend class sAI;
    friend class sApp;
    friend class sCollision;
    friend class sControlManager;
    friend class sEffect;
    friend class sEffectExt;
    friend class sEnemyManager;
    friend class sGUI;
    friend class sGUIExt;
    friend class sGpuParticle;
    friend class sPlatformUtil;
    friend class sPrimitive;
    friend class sRemoteProcedure;
    friend class sResource;
    friend class sScene;
    friend class sShader2;
    friend class sShadow;
    friend class sSound;
    friend class sTalkManager;
    friend class sUnit;
    friend class sUserManager;
    friend class sWeatherManager;
    friend class sZone;
    friend class uBaseModel;
    friend class uCharacter;
    friend class uCnsJointOffset;
    friend class uCnsTinyChain;
    friend class uConstraint;
    friend class uDOFFilter;
    friend class uDynamicSbc;
    friend class uEffect;
    friend class uEffect2D;
    friend class uEffectExt;
    friend class uFSMTask;
    friend class uFreeCamera;
    friend class uFullbodyIKHuman2;
    friend class uGUI;
    friend class uGUIBase;
    friend class uGUICaplinkMenuBase;
    friend class uGUICharacterEdit;
    friend class uGUIItem01;
    friend class uGUIItemBase01;
    friend class uGUIMap;
    friend class uGUIStorage;
    friend class uGUIUseItemBase;
    friend class uGeometry2;
    friend class uGeometry2Collider;
    friend class uGeometry2Group;
    friend class uGeometry2GroupCollider;
    friend class uLight;
    friend class uModel;
    friend class uMotionBlurFilter;
    friend class uMotionCamera;
    friend class uMovie;
    friend class uMultiBloomFilter;
    friend class uMultiBlurFilter;
    friend class uMultiColorCorrectFilter;
    friend class uMultiGodRaysFilter;
    friend class uScheduler;
    friend class uScreenSpace;
    friend class uScrollCollisionGeometry;
    friend class uScrollCollisionGeometryGroupModel;
    friend class uScrollCollisionGeometryModel;
    friend class uShadow;
    friend class uShlComponentCtrl;
    friend class uSimSoftBody;
    friend class uSimpleEffect;
    friend class uSoundMotionSe;
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

inline MtDTI::operator const char *() const {
    return this->mName;
}

inline u32 MtDTI::getID() const {
    return this->mID;
}

inline u32 MtDTI::getSize() const {
    return mSize << MTDTI_CLASSSIZE_BITSHIFT;
}

inline bool MtDTI::compare(const MtDTI& s, const MtDTI& d) const {
    for (MtDTI* pt = const_cast<MtDTI*>(&s); pt != nullptr; pt = pt->mpParent) {
        if (pt->mName == d.mName) {
            return true;
        }
    }
    return false;
}

inline bool MtDTI::operator==(const MtDTI& type) const {
    return compare(*this, type);
}
