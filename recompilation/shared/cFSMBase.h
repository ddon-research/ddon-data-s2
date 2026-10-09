#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cAIUserProcess.h"
#include "cFSMCore.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class cAIFSM;
class uCameraGame;

// Declarations
class cFSMBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class cFSMBase : public cFSMCore
{
public:
    enum
    {
        FSMORDER_FREE_NUM = 32,
    };
public:
    class MyDTI;
    class cParamCallMessage;
    class cParamCallMessageFortDef_Common;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cParamCallMessage : public cAICopiableParameter
    {
    public:
        enum
        {
            MSG_TYPE_EVENT = 0,
            MSG_TYPE_QUEST = 1,
            MSG_TYPE_STAGE = 2,
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
        cParamCallMessage();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        u32 mMsgType;  // offset: 0x8
        u32 mQstNo;  // offset: 0xc
        u32 mMsgNo;  // offset: 0x10
        f32 mMsgDispTime;  // offset: 0x14
        f32 mMsgWaitTime;  // offset: 0x18
        bool mIsUseSerial;  // offset: 0x1c
        bool mIsHideMessage;  // offset: 0x1d
        static MyDTI DTI;
    };
public:
    class cParamCallMessageFortDef_Common : public cFSMBase::cParamCallMessage
    {
    public:
        enum
        {
            MSG_RAND_NUM = 3,
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
        cParamCallMessageFortDef_Common();
        virtual void createProperty(MtPropertyList& s);  // vtable slot 4
        virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    public:
        u32 mMsgNo1;  // offset: 0x20
        u32 mMsgNo2;  // offset: 0x24
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
    virtual void callbackUpdate();  // vtable slot 7
    u32 stateCallMessage(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateCallMessage(MtObject* pParam, MtObject* pCaller);
    u32 stateCallMessageFortDef_Common(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateCallMessageFortDef_Common(MtObject* pParam, MtObject* pCaller);
    u32 stateCallMessageFortDef_BattleStart(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateCallMessageFortDef_BattleStart(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateFreeFlagOn(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateFreeFlagOff(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateGameGlobalFlagOn(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateGameGlobalFlagOff(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateMainQuestFlagOn(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateMainQuestFlagOff(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSceFlagOn(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateSceFlagOff(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateEvtFlagOn(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateEvtFlagOff(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateQuestInfo(MtObject* pParam, MtObject* pCaller);
    u32 stateIsMyQuestFlag(MtObject* pParam, MtObject* pCaller);
    u32 stateUpdateCallAnnounce(MtObject* pParam, MtObject* pCaller);
    bool isEndCameraCut(u32 cutNo) const;
    u32 getCameraCutNum() const;
    bool isEndCameraSdr(u32 idx) const;
    u32 getCameraSdrNum() const;
    bool isNowCameraSdr(u32 idx) const;
    uCameraGame* getTargetCamera() const;
protected:
    bool getFreeFlag(u32 flagNo) const;
    u32 getFreeFlagNum() const;
    bool getGGFlag(u32 flagNo) const;
    u32 getGGFlagNum() const;
    bool getMyQuestFlag(u32 flagNo) const;
    u32 getMyQuestFlagNum();
    bool getMainQuestFlag(u32 flagNo) const;
    u32 getMainQuestFlagNum() const;
    bool getSceFlag(u32 flagNo) const;
    u32 getSceFlagNum() const;
    bool getEvtFlag(u32 flagNo) const;
    u32 getEvtFlagNum() const;
    bool isMyQuestFlag() const;
    u32 getMyQuestFlagArrayNum() const;
    bool isMyQuestFlagArray(u32 idx) const;
    bool isFadeEnded() const;
    bool isFadeOut() const;
    bool isMessageEnded() const;
public:
    void setOwner(MtObject* pOwner);
    MtObject* getOwner() const;
    cAIFSM& getFSM();
    MT_CTSTR getFSMName();
    MT_CTSTR getFSMPath();
    cFSMBase();
    virtual ~cFSMBase();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 6
protected:
    virtual void createPropertyFSM(MtPropertyList& s);  // vtable slot 9
protected:
    u32 mRno;  // offset: 0x90
    f32 mFsmMesWaitTime;  // offset: 0x94
    u32 mNowCamSdrIdx;  // offset: 0x98
    u32 mOldCamCutNo;  // offset: 0x9c
    bool mIsMyQuestFlag;  // offset: 0xa0
    bool mIsMyQuestFlagArray[4];  // offset: 0xa1
    bool mIsDispMsg;  // offset: 0xa5
    u8 mFreeB[4];  // offset: 0xa6
    u32 mQuestType;  // offset: 0xac
    u32 mQuestId;  // offset: 0xb0
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cFSMBase::cParamCallMessage::cParamCallMessage() {
    this->mMsgType = static_cast<u32>(0);
    this->mQstNo = static_cast<u32>(0);
    this->mMsgNo = static_cast<u32>(0);
    this->mMsgDispTime = 5.0f;
    this->mMsgWaitTime = 0.0f;
    this->mIsUseSerial = false;
    this->mIsHideMessage = false;
}
