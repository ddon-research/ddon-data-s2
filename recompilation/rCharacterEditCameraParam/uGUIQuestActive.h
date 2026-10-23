#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/nDDOUtility.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjChildAnimationRoot;
class cGUIObjColorAdjust;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjTexture;
class cGUIObject;
class rGUI;
class rSoundRequest;

// Declarations
class uGUIQuestActive;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIQuestActive : public uGUIBase
{
public:
    enum STEP
    {
        STEP_DEFAULT = 0,
        STEP_DELETE = 1,
        STEP_MOVE = 2,
        STEP_ADD = 3,
    };
    enum MODE
    {
        MODE_QUEST = 0,
        MODE_CYCLE_CONTENT = 1,
        MODE_END_CONTENT = 2,
        MODE_CLAN_DUNGEON = 3,
    };
public:
    class MyDTI;
    struct ActiveQuestInfo;
    struct Quest;
    struct InstTitle;
    struct Content;
public:
    using ActiveQuestInfos = nDDOUtility::cArray<uGUIQuestActive::ActiveQuestInfo, 3>;
    using Quests = nDDOUtility::cArray<uGUIQuestActive::Quest, 3>;
    using Purposes = nDDOUtility::cArray<uGUIQuestActive::InstTitle, 3>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct ActiveQuestInfo
    {
    public:
        void reset();
        void set(u32 scheduleId, u32 activeQuestIndex, u32 dispIndex);
    public:
        u32 mScheduleId;  // offset: 0x0
        u32 mActiveQuestIndex;  // offset: 0x4
        u32 mDispIndex;  // offset: 0x8
    };
public:
    struct InstTitle
    {
    public:
        InstTitle();
        void clearMessage();
    public:
        cGUIInstAnimation* mpINST_anim;  // offset: 0x0
        cGUIObjMessage* mpOBJ_msg;  // offset: 0x8
        cGUIObjNull* mpOBJ_null_base;  // offset: 0x10
        cGUIObjTexture* mpOBJ_left;  // offset: 0x18
        cGUIObjTexture* mpOBJ_center;  // offset: 0x20
    };
public:
    struct Content
    {
    public:
        Content();
        void clearAllMessages();
    public:
        cGUIInstNull* mpINST_Null_quest00;  // offset: 0x0
        cGUIInstAnimation* mpINST_partyquest00;  // offset: 0x8
        cGUIObjTexture* mpOBJ_partyquest00_questtext00;  // offset: 0x10
        cGUIInstAnimation* mpINST_msg_time;  // offset: 0x18
        cGUIObjMessage* mpOBJ_msg_time_m_ctgry;  // offset: 0x20
        cGUIObjMessage* mpOBJ_msg_time_m_time01;  // offset: 0x28
        cGUIObjMessage* mpOBJ_msg_time_m_time02;  // offset: 0x30
        cGUIObjChildAnimationRoot* mpOBJ_msg_time_msg_childtime;  // offset: 0x38
        cGUIObjChildAnimationRoot* mpOBJ_msg_time_msg_childtime01;  // offset: 0x40
        cGUIObjMessage* mpOBJ_msg_childtime_m_time;  // offset: 0x48
        cGUIObjMessage* mpOBJ_msg_childtime_m_time00;  // offset: 0x50
        cGUIObjMessage* mpOBJ_msg_childtime01_m_time;  // offset: 0x58
        cGUIObjMessage* mpOBJ_msg_childtime01_m_time00;  // offset: 0x60
        cGUIInstAnimation* mpINST_msg_point;  // offset: 0x68
        cGUIObjMessage* mpOBJ_msg_point_m_ctgry;  // offset: 0x70
        cGUIObjMessage* mpOBJ_msg_point_m_point;  // offset: 0x78
        cGUIObjMessage* mpOBJ_msg_point_m_point01;  // offset: 0x80
        cGUIObjMessage* mpOBJ_msg_point_m_unit;  // offset: 0x88
        cGUIObjMessage* mpOBJ_msg_point_m_point00;  // offset: 0x90
        cGUIObjMessage* mpOBJ_msg_point_m_unit00;  // offset: 0x98
        uGUIQuestActive::InstTitle mInstTitle;  // offset: 0xa0
        cGUIInstAnimation* mpINST_fix_icon_quest;  // offset: 0xc8
        uGUIBase::cReferenceUIIconQuest mIconQuest;  // offset: 0xd0
        uGUIQuestActive::Purposes mPurposes;  // offset: 0x1b0
        f32 mAddTime;  // offset: 0x228
        u32 mAddPoint;  // offset: 0x22c
        f32 mLastTime;  // offset: 0x230
    };
public:
    struct Quest
    {
    public:
        Quest();
        void setup(uGUIQuestActive* uGui, cGUIInstNull* pINST_Null_quest, bool isDuplicate);
        void setTitle(uGUIQuestActive* uGui, MT_CTSTR title);
        void setScheduleId(uGUIQuestActive* uGui, const uGUIQuestActive::ActiveQuestInfo& activeQuestInfo);
        void clearAllMessages();
    public:
        cGUIInstNull* mpINST_Null_quest;  // offset: 0x0
        uGUIQuestActive::InstTitle mInstTitle;  // offset: 0x8
        cGUIInstAnimation* mpINST_fix_icon_quest;  // offset: 0x30
        cGUIObjColorAdjust* mpOBJ_msg_fix_title_ColorAdjust;  // offset: 0x38
        uGUIBase::cReferenceUIIconQuest mIconQuest;  // offset: 0x40
        uGUIQuestActive::Purposes mPurposes;  // offset: 0x120
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
private:
    void instTitleSetupAsQuestName(InstTitle& instTitle, cGUIInstNull* pINST_Null_quest, u32 instanceId);
    void instTitleSetupAsQuestPurpose(InstTitle& instTitle, cGUIInstNull* pINST_Null_quest, u32 instanceId);
    void instTitleSetMessage(InstTitle& instTitle, MT_CTSTR msg);
    void contentSetup(Content& content);
    void contentSetPoint(Content& content, u32 point);
    void contentSetTime(Content& content, f32 time);
    void contentEventAddPoint(Content& content, u32 point);
    void contentEventAddTime(Content& content, f32 time);
    void contentCheckAnimationAddPoint(Content& content);
    void contentCheckAnimationAddTime(Content& content);
    void contentSetTimeSeqId(Content& content, u32 seqId);
    void checkMode();
    void setMode(MODE mode);
    void clearAllMessages();
public:
    uGUIQuestActive();
    virtual ~uGUIQuestActive();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    void setObjectMessage(cGUIObject* object, MT_CTSTR msg);
    void evAddPoint(u32 point);
    void evAddTime(f32 time);
private:
    void updateInit();
    void updateWait();
    void updateExit();
    bool updateQuest();
    bool updateContent();
    void updateDisp(const ActiveQuestInfos& activeQuestInfos, u32 activeQuestNum);
    void returnDefaultMode();
    u32 getActiveQuestDispType() const;
    u32 getActiveQuestInfos(ActiveQuestInfos& activeQuestInfos);
    bool isCycleContentsPlayNow() const;
    bool isEndContentsPlayNow() const;
    bool isClanDungeonPlayNow() const;
    bool isContentLoadResource() const;
    bool isReceiveContentTimer() const;
    u32 getContentPoint() const;
    f32 getContentTime() const;
    bool isDispContentTimer() const;
    bool isDispContentPoint() const;
    bool isDispContentInfo() const;
    u32 getContentPurposeNum() const;
    MT_CTSTR getContentPurpose(u32 idx) const;
    MT_CTSTR getContentName() const;
    void requestMissionSe(u32 reqNo);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rSoundRequest* mpSeRes;  // offset: 0x8d0
    cGUIInstNull* mpINST_Null;  // offset: 0x8d8
    cGUIInstNull* mpINST_Null_all;  // offset: 0x8e0
    cGUIInstNull* mpINST_Null_quest;  // offset: 0x8e8
    cGUIInstAnimation* mpINST_move_color;  // offset: 0x8f0
    cGUIObjNull* mpOBJ_move_color_Null;  // offset: 0x8f8
    cGUIObjColorAdjust* mpOBJ_move_color_ColorAdjust;  // offset: 0x900
    cGUIInstAnimation* mpINST_partyquest;  // offset: 0x908
    cGUIObjMessage* mpOBJ_partyquest_m_partyquest;  // offset: 0x910
    cGUIObjMessage* mpOBJ_partyquest_m_name;  // offset: 0x918
    f32 mNullX;  // offset: 0x920
    nDDOUtility::cArray<float, 3> mNullYs;  // offset: 0x924
    ActiveQuestInfos mActiveQuestInfos;  // offset: 0x930
    u32 mActiveQuestNum;  // offset: 0x954
    Quests mQuests;  // offset: 0x958
    STEP mStep;  // offset: 0xe20
    ActiveQuestInfos mNextActiveQuestInfos;  // offset: 0xe24
    u32 mNextActiveQuestNum;  // offset: 0xe48
    u32 mNextLostBitmap;  // offset: 0xe4c
    u32 mNextMoveBitmap;  // offset: 0xe50
    u32 mNextAddBitmap;  // offset: 0xe54
    nDDOUtility::cArray<unsigned int, 3> mNextDispIndexs;  // offset: 0xe58
    f32 mCnt;  // offset: 0xe64
    Content mContent;  // offset: 0xe68
    MODE mMode;  // offset: 0x10a0
public:
    static MyDTI DTI;
private:
    static const u32 MAX_QUEST_NUM = 3;
    static const u32 MAX_PURPOSE_NUM = 3;
    static const u32 MAX_CONTENT_PURPOSE_NUM = 3;
};
