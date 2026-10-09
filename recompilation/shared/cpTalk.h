#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtString.h"
#include "cTalkMsgData.h"
#include "cpComponent.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtString;
class MtVector3;
class cTalkMsgData;
class rSituationMsgCtrl;
class rSoundStreamRequest;
class uDDOModel;

// Declarations
class cpTalk;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cpTalk : public cpComponent
{
public:
    enum
    {
        STATUS_WAIT = 0,
        STATUS_TALKNOW = 1,
    };
    enum
    {
        RNO_FACE_NONE = 0,
        RNO_FACE_TALK = 1,
        RNO_FACE_EVENT_WAIT = 2,
        RNO_FACE_EYE_CLOSE = 3,
        RNO_FACE_NUM = 4,
    };
    enum
    {
        RNO_FACE_TALK_INIT = 0,
        RNO_FACE_TALK_MOVE = 1,
        RNO_FACE_TALK_NUM = 2,
    };
    enum
    {
        RNO_FACE_EVENT_WAIT_INIT = 0,
        RNO_FACE_EVENT_WAIT_MOVE = 1,
        RNO_FACE_EVENT_WAIT_NUM = 2,
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
    MT_CTSTR getName() const;
    void setName(MT_CTSTR name);
    u32 getMessageNo() const;
    void setMessageNo(u32);
    s32 getNpcId() const;
    void setNpcId(s32 npcId);
    s32 getShopId() const;
    u32 getShopListId() const;
    void setShopId(s32);
    void setShopListId(u32);
    bool hasCallFunction(u32) const;
    void addCallFunction(u32);
    virtual cTalkMsgData& getTalkMsgData();  // vtable slot 15
    bool isTalkNow();
    bool isEnableTalkMotion();
    bool isDisableCancel();
    virtual void loadMsgData();  // vtable slot 16
    void setVoiceData(u8 voiceType);
    virtual void callGreetingVoice();  // vtable slot 17
    void callVoice(u32 reqNo);
    void startFaceMot(u32 MotType, f32 SetFrame, u32 handle);
    s16 getTalkMotNo();
    void moveFace_none();
    void moveFace_talk();
    void moveFace_eventWait();
    void moveFace_eyeClose();
    void setTalkMot(s16 setMotNo);
    void setDefMot();
    void setDefMotForce();
protected:
    void initTalk();
    void checkDistance();
    void finishTalk();
public:
    cpTalk();
    virtual ~cpTalk();
    virtual void move();  // vtable slot 7
    s32 getSituationTalkIdx();
    u32 getOwnerUnitQuestId();
    bool isForceListTalk();
    virtual void setTouch(uDDOModel* pUnit);  // vtable slot 18
    // Address: 0x0197fd10 - 0x0197fd11 (1 bytes)
    virtual void sync() {}  // vtable slot 19
    // Address: 0x0197fd20 - 0x0197fd21 (1 bytes)
    virtual void moveAfter() {}  // vtable slot 20
    // Address: 0x0197fcd0 - 0x0197fcd1 (1 bytes)
    virtual void kill() {}  // vtable slot 8
    // Address: 0x0197fce0 - 0x0197fce1 (1 bytes)
    virtual void updateEfcHandle() {}  // vtable slot 10
    // Address: 0x0197fcf0 - 0x0197fcf1 (1 bytes)
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {}  // vtable slot 11
    void initTurnTarget();
    void returnTurn();
    bool isTalkedSituationTalk();
    void onTalkedSituationTalk();
protected:
    MtString mName;  // offset: 0x50
    u32 mMessageNo;  // offset: 0x58
    s32 mNpcId;  // offset: 0x5c
    u32 mFunction;  // offset: 0x60
    u32 mStatus;  // offset: 0x64
    f32 mFaceMotFrame;  // offset: 0x68
    uDDOModel* mpTalkUnit;  // offset: 0x70
    s32 mShopId;  // offset: 0x78
    u32 mShopListId;  // offset: 0x7c
    cTalkMsgData mTalkMsgData;  // offset: 0x80
    rSoundStreamRequest* mpVoice;  // offset: 0xd0
    rSituationMsgCtrl* mpSituation;  // offset: 0xd8
    s32 mVoicePitch;  // offset: 0xe0
    u32 mRno0;  // offset: 0xe4
    u32 mRno1;  // offset: 0xe8
    bool mPrivateVoice;  // offset: 0xec
    u8 mReqNoBase;  // offset: 0xed
    s16 mSetTalkMotNo;  // offset: 0xee
    u32 mOwnerUnitQuestId;  // offset: 0xf0
    bool mIsTalkedSituationTalk;  // offset: 0xf4
    f32 mDisableTimer;  // offset: 0xf8
    bool mIsWaitMotion;  // offset: 0xfc
    u32 mVoiceHandle;  // offset: 0x100
public:
    static MyDTI DTI;
    static const f32 DISABLE_TALK_FRAME;
};

// Inline, no code of its own: checked where it is inlined.
inline s32 cpTalk::getNpcId() const {
    return this->mNpcId;
}
