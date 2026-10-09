#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cSystem.h"
#include "nDDOUtility.h"
#include "rAIPawnOrder.h"
#include "rAIPawnSkillParam.h"
#include "rEffectProvider.h"
#include "rFreeF32Tbl.h"
#include "res_ptr.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class MtVector4;
class cAIPawnOrderParam;
class cAIPawnSkillParamNode;
class rAIPawnOrder;
class rAIPawnSkillParamTbl;
class rEffectProvider;
class rFreeF32Tbl;
class uCharacter;
class uDDOModel;
class uHuman;

// Declarations
class sAIPawnSys;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using cAIPawnOrderGroupArray = nDDOUtility::cArray<unsigned int, 3>;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sAIPawnSys : public cSystem
{
public:
    enum
    {
        ROTATE_NO_NUM = 4,
    };
public:
    class MyDTI;
public:
    using cAIRotateTbl = nDDOUtility::cArray<unsigned int, 4>;
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
    sAIPawnSys();
    virtual ~sAIPawnSys();
    static sAIPawnSys* getInstance();
    virtual void move();  // vtable slot 7
    virtual void reset();  // vtable slot 6
    void initGame();
    void clear();
    void updateAIPawnRotateNo();
    void getAIPawnRotateNo(u32* pDst);
    bool isAIPawnRotateEnable(u32 no) const;
    void releaseAIPawnRotateNo(u32* pDst);
    void updatePawnOrder();
    u32 getPawnOrderNum() const;
    cAIPawnOrderParam* getPawnOrderFormId(u32 id);
    cAIPawnOrderParam* getPawnOrderFormIdx(u32 idx);
    uDDOModel* getPawnOrderTarget();
    void reqPawnOrder(u32 order);
    void clearPawnOrder();
    bool getIsDispPawnTargetUi();
private:
    uDDOModel* calcPawnOrderTarget();
public:
    void receivePawnOrder(u32 party_index, u32 order);
private:
    void sendPawnOrder(u32 order);
    void clearNetMsgPawnOrder(bool set_ng_time);
public:
    void setPawnOwnerTarget(uDDOModel* pOwner, uDDOModel* pTarget);
    uDDOModel* getPawnOwnerTarget();
    uDDOModel* getPawnOwnerTargetOld();
    void clearPawnOwnerTarget();
    bool isPawnGroupThinkEnableAct(uCharacter& chara, u32 groupThinkID);
    void createPawnWarpEpv(uHuman* pModel, const MtVector3& ofsPos);
    cAIPawnSkillParamNode* findAIPawnSkillParamNode(s32 job, s32 actNo);
    void reqPartyInDeploy();
    bool isPartyInDeploy() const;
    void resetPartyInDeploy();
    f32 getPawnPrmF32(MT_CTSTR tag, f32 def);
    MtVector3 getPawnPrmVec3(MT_CTSTR tag, const MtVector3& def);
    MtVector4 getPawnPrmVec4(MT_CTSTR tag, const MtVector4& def);
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
private:
    res_ptr<rEffectProvider> mpPawnWarpEpv;  // offset: 0x18
    res_ptr<rFreeF32Tbl> mpAIPawnParam;  // offset: 0x20
    res_ptr<rAIPawnSkillParamTbl> mpAIPawnSkillParamTbl;  // offset: 0x28
    cAIPawnOrderGroupArray mReqPawnOrder;  // offset: 0x30
    res_ptr<rAIPawnOrder> mpAIPawnOrderRes;  // offset: 0x40
    f32 mAIPawnOrderTargetTime;  // offset: 0x48
    f32 mAIPawnReqPartyInDeployLimit;  // offset: 0x4c
    u32 mAIPawnRotateNo;  // offset: 0x50
    cAIRotateTbl mAIPawnRotateTbl;  // offset: 0x54
    bool mAIPawnRotateDisable;  // offset: 0x64
    bool mAIPawnRotateFourceUpdate;  // offset: 0x65
    bool mIsDispPawnTargetUi;  // offset: 0x66
    uDDOModel* mpPawnOwnerTarget;  // offset: 0x68
    uDDOModel* mpPawnOwnerTargetOld;  // offset: 0x70
    uDDOModel* mpPawnOrderTarget;  // offset: 0x78
public:
    u32 mNetMsgPawnPartyIndex;  // offset: 0x80
    u32 mNetMsgPawnOrder;  // offset: 0x84
private:
    f32 mNetMsgNgTimer;  // offset: 0x88
public:
    static MyDTI DTI;
private:
    static sAIPawnSys* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sAIPawnSys* sAIPawnSys::getInstance() {
    return ::sAIPawnSys::mpInstance;
}

// Inline, no code of its own: checked where it is inlined.
inline void sAIPawnSys::clearPawnOrder() {
    this->mReqPawnOrder.elems[0] = static_cast<unsigned int>(0);
    this->mReqPawnOrder.elems[1] = static_cast<unsigned int>(0);
    this->mReqPawnOrder.elems[2] = static_cast<unsigned int>(0);
    this->mAIPawnOrderTargetTime = 0.0f;
    this->mAIPawnReqPartyInDeployLimit = 0.0f;
    this->mpPawnOrderTarget = static_cast<uDDOModel*>(nullptr);
    this->mpPawnOwnerTargetOld = static_cast<uDDOModel*>(nullptr);
    this->mpPawnOwnerTarget = static_cast<uDDOModel*>(nullptr);
}
