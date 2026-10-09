#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cAction;
class cHumanActBase;
namespace nSessionManager { class cNetSessionManager; }
class uCharacter;
class uDDOModel;
class uEnemy;
class uHuman;

// Declarations
class cpActionRequest;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class cpActionRequest : public cpComponent
{
    // inferred: cAction::requestAction names cpActionRequest::mRequestActionReq
    friend class cAction;
    // inferred: cHumanActBase::setEndActNoSendOcdBadStatus names cpActionRequest::mEndAction
    friend class cHumanActBase;
    // inferred: nSessionManager::cNetSessionManager::endReadyAction names cpActionRequest::mRequestActionReq
    friend class nSessionManager::cNetSessionManager;
    // inferred: uCharacter::setupContextAction names cpActionRequest::mRequestActionReq
    friend class uCharacter;
    // inferred: uDDOModel::callbackShrink names cpActionRequest::mShrinkActionReq
    friend class uDDOModel;
    // inferred: uEnemy::hitInstantDeath names cpActionRequest::mDamageAction
    friend class uEnemy;
    // inferred: uHuman::startBlowUKEMIAcsept names cpActionRequest::mLandAction
    friend class uHuman;
public:
    enum SET_ACT_TYPE
    {
        RESULT_NONE = -1,
        RESULT_ACTION_REQ = 0,
        RESULT_FALL = 1,
        RESULT_END = 2,
        RESULT_LAND = 3,
        RESULT_DAMAGE = 4,
        RESULT_TOUCH = 5,
        RESULT_SHRINK = 6,
        RESULT_BLOW = 7,
        RESULT_GUARD = 8,
        RESULT_HIGH = 9,
        RESULT_NUM = 10,
    };
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
    cpActionRequest();
    virtual ~cpActionRequest();
    virtual void setOwner(MtObject* pOwner);  // vtable slot 14
    virtual void setup();  // vtable slot 6
    virtual void updatePtr();  // vtable slot 9
    u32 callbackGetAutoAction();
    u32 callbackGetDamageAction();
    u32 callbackGetTouchAction();
    u32 callbackGetEndAction();
    u32 callbackGetRequestAction();
    u32 callbackGetHighPriorityAction();
    u32 getDamageAction();
    u32 getLandAction() const;
    void setEndAction(u32 ActNo);
    void setLandAction(u32 ActNo);
    void setFallAction(u32 ActNo);
    void setTouchAction(u32 ActNo);
    void setDamageAction(u32 ActNo);
    void setShrinkAction(u32 ActNo);
    void setBlowAction(u32 ActNo);
    void requestHighPriorityAction(u32 ActNo);
    void requestAction(u32 ActNo);
    void reqEndAction();
    void reqLandAction();
    void reqFallAction();
    void reqDamageAction();
    void reqTouchAction();
    void reqShrinkAction();
    void reqBlowAction();
    void requestArgAction(u32 ActNo, u32 uparam0, u32 uparam1, u32 uparam2, u32 uparam3, f32 fparam0, f32 fparam1, f32 fparam2, f32 fparam3);
    void setRequestActionNoSend(bool isSend);
    void reqEndActionNoSend(bool isSend);
    void reqLandActionNoSend(bool isSend);
    void reqFallActionNoSend(bool isSend);
    void reqDamageActionNoSend(bool);
    void reqTouchActionNoSend(bool);
    void reqShrinkActionNoSend(bool);
    void reqBlowActionNoSend(bool);
    SET_ACT_TYPE getSetActionType();
    bool isArgument();
    u32 getUparam(u32 no);
    f32 getFparam(u32 no);
    void clearReqestActionAll();
    void resetNoSendFlag();
    bool checkNoSendFlag();
public:
    uDDOModel* mpModel;  // offset: 0x50
private:
    u32 mFallAction;  // offset: 0x58
    u32 mEndAction;  // offset: 0x5c
    u32 mLandAction;  // offset: 0x60
    u32 mDamageAction;  // offset: 0x64
    u32 mTouchAction;  // offset: 0x68
    u32 mShrinkAction;  // offset: 0x6c
    u32 mBlowAction;  // offset: 0x70
    u32 mRequestActionReq;  // offset: 0x74
    u32 mFallActionReq;  // offset: 0x78
    u32 mEndActionReq;  // offset: 0x7c
    u32 mLandActionReq;  // offset: 0x80
    u32 mDamageActionReq;  // offset: 0x84
    u32 mTouchActionReq;  // offset: 0x88
    u32 mShrinkActionReq;  // offset: 0x8c
    u32 mBlowActionReq;  // offset: 0x90
    u32 mHighPriorityActionReq;  // offset: 0x94
    u32 mUparam0;  // offset: 0x98
    u32 mUparam1;  // offset: 0x9c
    u32 mUparam2;  // offset: 0xa0
    u32 mUparam3;  // offset: 0xa4
    f32 mFparam0;  // offset: 0xa8
    f32 mFparam1;  // offset: 0xac
    f32 mFparam2;  // offset: 0xb0
    f32 mFparam3;  // offset: 0xb4
    SET_ACT_TYPE mSetActionType;  // offset: 0xb8
    bool mRequestActionNoSend;  // offset: 0xbc
    bool mFallActionNoSend;  // offset: 0xbd
    bool mEndActionNoSend;  // offset: 0xbe
    bool mLandActionNoSend;  // offset: 0xbf
    bool mDamageActionNoSend;  // offset: 0xc0
    bool mTouchActionNoSend;  // offset: 0xc1
    bool mShrinkActionNoSend;  // offset: 0xc2
    bool mBlowActionNoSend;  // offset: 0xc3
    bool mIsArgument;  // offset: 0xc4
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline void cpActionRequest::reqDamageAction() {
    this->mDamageActionReq = static_cast<u32>(169);
}
