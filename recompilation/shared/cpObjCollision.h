#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtCollection.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "cBitCtrl.h"
#include "cObjHitCache.h"
#include "cOcdDamageInfo.h"
#include "cpComponent.h"
#include "nObjCollision.h"
#include "sCollision.h"
#include "uDDOModel.h"

// Forward declarations
class MtAllocator;
class MtArray;
class MtCapsule;
struct MtContact;
class MtDTI;
class MtLineSegment;
class MtObject;
class MtSphere;
class MtVector3;
class cAttackParam;
class cBitCtrl;
class cChildRegionStatus;
class cCollGeom;
class cCollIndex;
class cCollNode;
class cGuardInfo;
class cHitGeom;
class cHitInfoAfter;
class cHitNode;
class cObjHitCache;
class cOcdDamageInfo;
class cpSequenceCtrl;
class rAttackParam;
class rBitTable;
class rObjCollision;
class uDDOModel;

// Declarations
class cHitInfo;
class cModelList;
class cpObjCollisionBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using u32 = unsigned int;
namespace nObjCollision { using HIT_CACHE_HANDLE = u32; }
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u64 = __uint64_t;

class cHitInfo : public MtObject
{
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    static MtDTI* getMyDTIPtr();
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    cHitInfo();
    virtual ~cHitInfo();
    cAttackParam* getAttackParam();
    const cAttackParam* getAttackParamNode();
    const cAttackParam* getDefendParam();
    const cAttackParam* getAttackParam(u32 index);
    const cAttackParam* getDefendParam(u32 index);
    void setAttackParam(const cAttackParam* pAttackParam);
    void setDefendParam(const cAttackParam* pAttackParam);
    const cChildRegionStatus* getDefendRegion();
    uDDOModel* getAttackerUnitPtr() const;
    bool isAttackerShl() const;
    u16 getAtkCollNodID() const;
public:
    f32 mDamage;  // offset: 0x8
    uDDOModel* mpAtkModel;  // offset: 0x10
    uDDOModel* mpDfdModel;  // offset: 0x18
    cHitNode* mpAtkNode;  // offset: 0x20
    cHitNode* mpDfdNode;  // offset: 0x28
    const cHitGeom* mpAtkGeom;  // offset: 0x30
    const cHitGeom* mpDfdGeom;  // offset: 0x38
    MtVector3 mHitPos;  // offset: 0x40
    MtVector3 mHitNormal;  // offset: 0x50
    cGuardInfo* mpGuardInfo;  // offset: 0x60
    u32 mHitStopSlowResultType;  // offset: 0x68
    u32 mAttackReactionType;  // offset: 0x6c
    const cCollNode* mpDfdCollNode;  // offset: 0x70
    const cCollGeom* mpDfdCollGeom;  // offset: 0x78
    u16 mAtkAdjustUniqueId;  // offset: 0x80
    cOcdDamageInfo mOcdDamageInfo;  // offset: 0x88
    cAttackParam* mpAttackParam;  // offset: 0x6f8
    static MyDTI DTI;
};

class cModelList : public MtObject
{
public:
    class MyDTI;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    static MtDTI* getMyDTIPtr();
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    void add(uDDOModel* pModel);
    void remove(uDDOModel* pModel);
    bool find(uDDOModel* pModel);
    bool isEmpty();
    void clear();
    void add_unsafe(uDDOModel* pModel);
    void remove_unsafe(uDDOModel* pModel);
    bool find_unsafe(uDDOModel* pModel);
    bool isEmpty_unsafe();
    void clear_unsafe();
    void updatePtr();
public:
    MtTypedArray<uDDOModel> mModelList;  // offset: 0x8
    static MyDTI DTI;
};

class cpObjCollisionBase : public cpComponent
{
    // inferred: uDDOModel::isAttackTestHit calls cpObjCollisionBase::isAttackHitSub
    friend class uDDOModel;
public:
    class MyDTI;
    class cHitFlag;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cHitFlag : public MtObject
    {
    public:
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        static MtDTI* getMyDTIPtr();
        static void usage();
        virtual const MtDTI& getDTI() const;  // vtable slot 5
        static MtAllocator* getAllocator();
        static void setAllocator(u32);
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void* operator new(size_t sz, void* p_addr);
        static void* operator new[](size_t sz, void* p_addr);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
        cHitFlag();
        // Address: 0x01a5c380 - 0x01a5c381 (1 bytes)
        virtual ~cHitFlag() {}
        void clear();
    public:
        u32 mAttackHit;  // offset: 0x8
        u32 mDamageHit;  // offset: 0xc
        u32 mCheckHit;  // offset: 0x10
        u32 mCheckedHit;  // offset: 0x14
        u32 mCatchHit;  // offset: 0x18
        u32 mCaughtHit;  // offset: 0x1c
        u32 mPushHit;  // offset: 0x20
        u32 mGuardHit;  // offset: 0x24
        u32 mGuardedHit;  // offset: 0x28
        u32 mHealHit;  // offset: 0x2c
        u32 mHealedHit;  // offset: 0x30
        static MyDTI DTI;
    };
public:
    static MtDTI* getMyDTIPtr();
    static void usage();
    virtual const MtDTI& getDTI() const;  // vtable slot 5
    static MtAllocator* getAllocator();
    static void setAllocator(u32);
    static void* operator new(size_t sz, u32 align);
    static void* operator new[](size_t sz, u32 align);
    static void* operator new(size_t sz, void* p_addr);
    static void* operator new[](size_t sz, void* p_addr);
    static void operator delete(void* p_addr);
    static void operator delete[](void* p_addr);
    static void operator delete(void* p_addr, u32 align);
    static void operator delete[](void* p_addr, u32 align);
    void setResource(rObjCollision* pRes, u32 bank);
    rObjCollision* getResource(u32 bank) const;
    void setAttackParam(rAttackParam* pRes, u32 bank);
    rAttackParam* getAttackParam(u32) const;
    void setHitGroup(u32 id);
    u32 getHitGroup();
    void setPushGroup(u32 id);
    u32 getPushGroup();
    u32 objAdjust(MtVector3& NewPos, MtVector3& OldPos);
    const cHitGeom* findClosest(const MtVector3& pos, u32 attr, MtVector3& ResultHitPos, MtVector3& ResultHitNormal);
    const cHitGeom* findIntersect(const MtLineSegment& sg, u32 attr, MtVector3& ResultHitPos, MtVector3& ResultHitNormal);
    bool findIntersect(const MtSphere& sphere, u32 attr, MtTypedArray<cHitGeom>& result);
    bool findIntersect(const MtCapsule& capsule, u32 attr, MtTypedArray<cHitGeom>& result);
    const cHitGeom* getGeom(u16 NodeIndex, u16 GeomIndex);
    void calcHitPos(cObjHitCache* pCache, MtVector3& HitPos, MtVector3& HitNormal);
    static bool isFriendHitAttr(u32 AtkHitGroup, u32 DfdHitGroup);
    static bool isAttackHitAttr(u32 AtkHitGroup, u32 DfdHitGroup);
    static bool isPushHitAttr(u32 AtkHitGroup, u32 DfdHitGroup);
    void allHangedRemove();
    void setLayerOn(u32 no, bool on);
    bool isLayerOn(u32 no);
    void setLayerBit(u64 bit);
    u64 getLayerBit();
    void doBitCommand(u32 index, u32 commandSet);
    void setBitTableRes(rBitTable* pRes);
    rBitTable* getBitTableRes() const;
    void setFlag(u32);
    void addFlag(u32 flag);
    void removeFlag(u32 flag);
    u32 getFlag();
    void makeSharedUID();
    void copySharedUID(cpObjCollisionBase* pSrc);
    void setSharedUID(u32 index, u32 uid);
    u32 getSharedUID(u32 index);
    bool isAttackHit(u32 filter);
    bool isDamageHit(u32 filter);
    bool isCheckHit(u32 filter);
    bool isCheckedHit(u32 filter);
    bool isCatchHit(u32 filter);
    bool isCaughtHit(u32 filter);
    bool isPushHit(u32 filter);
    bool isGuardHit(u32 filter);
    bool isGuardedHit(u32 filter);
    bool isHealHit(u32 filter);
    bool isHealedHit(u32 filter);
    bool isAttackTestHit(u32 filter);
    bool isDamageTestHit(u32 filter);
    bool isCheckTestHit(u32 filter);
    bool isCheckedTestHit(u32 filter);
    bool isCatchTestHit(u32 filter);
    bool isCaughtTestHit(u32 filter);
    bool isGuardTestHit(u32 filter);
    bool isGuardedTestHit(u32);
    bool isHealTestHit(u32 filter);
    bool isHealedTestHit(u32 filter);
protected:
    bool isAttackHitSub(u32 filter, bool test);
    bool isDamageHitSub(u32 filter, bool test);
    bool isCheckHitSub(u32 filter, bool test);
    bool isCheckedHitSub(u32 filter, bool test);
    bool isCatchHitSub(u32 filter, bool test);
    bool isCaughtHitSub(u32 filter, bool test);
    bool isPushHitSub(u32 filter, bool test);
    bool isGuardHitSub(u32 filter, bool test);
    bool isGuardedHitSub(u32 filter, bool test);
    bool isHealHitSub(u32 filter, bool test);
    bool isHealedHitSub(u32 filter, bool test);
public:
    u32 getResourceNum() const;
    void setResourceNum(u32) const;
    u32 getAttackParamNum() const;
    void setAttackParamNum(u32) const;
    bool isActiveNode(u32 attr);
    bool isPassiveNode(u32 attr);
    bool isPushNode(u32 attr);
    bool isLargePushNode(u32 attr);
    u32 makeOpponentHitGroupMask(u32 filter);
    nObjCollision::HIT_GROUP_BIT getHitGroupAtk(cHitInfo* pHitInfo);
    nObjCollision::HIT_GROUP_BIT getHitGroupDfd(cHitInfo* pHitInfo);
    nObjCollision::HIT_GROUP_BIT getHitGroupAtk(cHitInfoAfter* pHitInfoAfter);
    nObjCollision::HIT_GROUP_BIT getHitGroupDfd(cHitInfoAfter* pHitInfoAfter);
    cpObjCollisionBase();
    virtual ~cpObjCollisionBase();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void kill();  // vtable slot 8
    virtual void updatePtr();  // vtable slot 9
    void compSync();
    void compMoveAfter();
    void update();
    cHitNode* createNodeFromIndex(u32 bank, s32 index, bool MotionSync, u32 ExplicitUID);
    cHitNode* createNode(u32 bank, s32 NodeNo, s32 AttackNo, u32 ExplicitUID);
    cHitNode* createNodeCore(rObjCollision* pRes, rAttackParam* pAttackParamRes, cCollNode* pCollNode, cAttackParam* pAttackParam, cCollIndex* pSrcIndex, bool MotionSync, u32 ExplicitUID);
    void killNode(u32 bank, u32 index);
    void killNode(cHitNode* pNode);
    void killNodeAll();
    void killNodeMotionSync();
    void callbackSequenceTrigger(cpSequenceCtrl* pSeqCtrl, u32 page, u32 bit, u16 work);
    void callbackSequenceRelease(cpSequenceCtrl* pSeqCtrl, u32 page, u32 bit, u16 work);
    void callbackSetMotion(u32 blend, u32 mot_no, f32 hokan, f32 frame, f32 speed, u32 attr);
    void callbackMoveEnd();
    cBitCtrl* getBitCtrl();
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset);  // vtable slot 11
    void addColNodeProgFlag(u32 flag);
    void clearColNodeProgFlag();
    bool isColNodeProgFlag(u32 flag) const;
protected:
    void entryNode();
    void updateNode();
    void deleteNodeAll();
    void updateNodeActive(cHitNode* pNode);
    void updateGeomActive(cHitGeom* pGeom);
    void callbackNodeHit(sCollision::CALLBACK_MODE mode, sCollision::Node* pThisNode, sCollision::Node* pNode, MtContact* pContact, u32 param, sCollision::TriangleInfo* pTriInfo, u32 HitGeomThisID, u32 HitGeomID, bool IsHit);
    u32 makeUID();
    void initCache();
    void initTmpCache();
    void updateCache();
    bool isThrough_Hit(uDDOModel* pAtkModel, uDDOModel* pDfdModel, cHitInfo& hitInfo) const;
    bool isThrough(uDDOModel* pAtkModel, uDDOModel* pDfdModel) const;
    bool checkHitCache(u32 uid) const;
    bool isCacheFull() const;
    void addHitCache(cObjHitCache* pCache);
    void addHitCacheByThread(uDDOModel* pAtkModel, uDDOModel* pDfdModel, cHitNode* pAtkNode, cHitNode* pDfdNode, cHitGeom* pAtkGeom, cHitGeom* pDfdGeom, f32 keep_frame);
    bool registHitCache(cObjHitCache* pDstCache, uDDOModel* pAtkModel, uDDOModel* pDfdModel, cHitNode* pAtkNode, cHitNode* pDfdNode, cHitGeom* pAtkGeom, cHitGeom* pDfdGeom, f32 keep_frame);
    void initLinkCache();
    void updateLinkCache();
    bool checkRange(cObjHitCache* pCache);
    void executeCallback(cObjHitCache* pCache);
    bool checkList(cHitInfo* pHitInfo);
    u32 createNodeUID(cCollIndex* pSrcIndex);
    void calcPush(cpObjCollisionBase* pObjCollAtk, cpObjCollisionBase* pObjCollDfd, u32 AtkAttr, u32 DfdAttr, MtContact* pContact, cHitNode* pAtkNode, cHitNode* pDfdNode);
    bool checkWallHit(cHitInfo* pHitInfo);
    bool checkExclusionErea(cHitInfo* pHitInfo);
    void syncCache();
public:
    uDDOModel* getModel() const;
    void setIsMotSeqColNoEntry(bool flg);
    bool isMotSeqColNoEntry() const;
    bool isCollisionGeomActive(u32 regionNo) const;
public:
    cHitFlag mHitFlag;  // offset: 0x50
    cHitFlag mHitTestFlag;  // offset: 0x88
    cModelList mIgnorePush;  // offset: 0xc0
    cModelList mGripAttackOnly;  // offset: 0xe8
    cModelList mHangedList;  // offset: 0x110
    cModelList mIgnoreList;  // offset: 0x138
protected:
    rObjCollision* mpResource[16];  // offset: 0x160
    rAttackParam* mpAttackParam[16];  // offset: 0x1e0
public:
    MtArray mNodeArray;  // offset: 0x260
    MtArray mPushNodeArray;  // offset: 0x280
protected:
    u32 mFlag;  // offset: 0x2a0
    u32 mInnerFlag;  // offset: 0x2a4
    u16 mUID;  // offset: 0x2a8
    u16 mNodeUID;  // offset: 0x2aa
    uDDOModel* mpModel;  // offset: 0x2b0
    u64 mLayer;  // offset: 0x2b8
    u32 mHitGroup;  // offset: 0x2c0
    u32 mPushGroup;  // offset: 0x2c4
    MtVector3 mPushTmp[6];  // offset: 0x2d0
    f32 mDistance[6];  // offset: 0x330
    uDDOModel* mpPushModelTmp[6];  // offset: 0x348
    MtVector3 mPush;  // offset: 0x380
    bool mIsMotSeqColNoEntry;  // offset: 0x390
    cBitCtrl mBitCtrl;  // offset: 0x398
    cObjHitCache mLinkCache[4];  // offset: 0x3b8
    u32 mSharedUID[8];  // offset: 0x518
    u32 mColNodeProgFlag;  // offset: 0x538
    cObjHitCache* mpHitCache;  // offset: 0x540
    u32 mHitCacheSize;  // offset: 0x548
    nObjCollision::HIT_CACHE_HANDLE* mpHitCacheHandleTmp[6];  // offset: 0x550
    u32 mHitCacheHandleTmpSize;  // offset: 0x580
    u16 mHitCacheHandleNum[6];  // offset: 0x584
    cObjHitCache* mpHitCacheMerge;  // offset: 0x590
    u32 mHitCacheMergeSize;  // offset: 0x598
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cAttackParam* cHitInfo::getAttackParam() {
    return this->mpAttackParam;
}

// Inline, no code of its own: checked where it is inlined.
inline uDDOModel* cpObjCollisionBase::getModel() const {
    return this->mpModel;
}

// Inline, no code of its own: checked where it is inlined.
inline cpObjCollisionBase::cHitFlag::cHitFlag() {
    this->mHealedHit = static_cast<u32>(0);
    this->mGuardedHit = static_cast<u32>(0);
    this->mHealHit = static_cast<u32>(0);
    this->mPushHit = static_cast<u32>(0);
    this->mGuardHit = static_cast<u32>(0);
    this->mCatchHit = static_cast<u32>(0);
    this->mCaughtHit = static_cast<u32>(0);
    this->mCheckHit = static_cast<u32>(0);
    this->mCheckedHit = static_cast<u32>(0);
    this->mAttackHit = static_cast<u32>(0);
    this->mDamageHit = static_cast<u32>(0);
}
