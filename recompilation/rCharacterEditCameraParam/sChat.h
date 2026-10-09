#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/Community.h"
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/MtTime.h"
#include "../shared/cSystem.h"
#include "../shared/nGUIExt.h"

// Forward declarations
class CDataCommunityCharacterBaseInfo;
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtTime;
class MtUI;
namespace nCharacterData { struct stMessageSet; }

// Declarations
class sChat;

// Type aliases from DWARF
using CCommunityCharacterBaseInfo = CDataCommunityCharacterBaseInfo;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u8 = unsigned char;

class sChat : public cSystem
{
public:
    enum INPUT_RNO
    {
        INPUT_RNO_IDLE = 0,
        INPUT_RNO_MOVE = 1,
    };
    enum
    {
        CHAT_AREA_SHOUT = 0,
        CHAT_AREA_SAY = 1,
        CHAT_AREA_PARTY = 2,
        CHAT_AREA_PARTY_L = 3,
        CHAT_AREA_CLAN = 4,
        CHAT_AREA_GROUP_00 = 5,
        CHAT_AREA_TELL = 6,
        CHAT_AREA_ENTRYBOARD = 7,
        CHAT_AREA_MAX = 8,
        CHAT_AREA_NONE = -1,
    };
    enum
    {
        DISP_TYPE_ANONYMOUS = 0,
        DISP_TYPE_NAME = 1,
        DISP_TYPE_ID = 2,
        DISP_TYPE_NUM = 3,
    };
    enum
    {
        CHATSTATE_NONE = 0,
        CHATSTATE_INPUT = 1,
        CHATSTATE_ENTERED = 2,
        CHATSTATE_CANCELED = 3,
        CHATSTATE_MAX = 4,
    };
    enum
    {
        CHAT_FILTER_GROUP_ALL = 0,
        CHAT_FILTER_GROUP_SHOUT = 1,
        CHAT_FILTER_GROUP_SAY = 2,
        CHAT_FILTER_GROUP_PARTY = 3,
        CHAT_FILTER_GROUP_PARTY_L = 4,
        CHAT_FILTER_GROUP_CLAN = 5,
        CHAT_FILTER_GROUP_CLAN_NTC = 6,
        CHAT_FILTER_GROUP_GROUP_01 = 7,
        CHAT_FILTER_GROUP_GROUP_02 = 8,
        CHAT_FILTER_GROUP_GROUP_03 = 9,
        CHAT_FILTER_GROUP_GROUP_04 = 10,
        CHAT_FILTER_GROUP_GROUP_05 = 11,
        CHAT_FILTER_GROUP_GROUP_06 = 12,
        CHAT_FILTER_GROUP_GROUP_07 = 13,
        CHAT_FILTER_GROUP_GROUP_08 = 14,
        CHAT_FILTER_GROUP_TELL = 15,
        CHAT_FILTER_GROUP_ENTRYBOARD = 16,
        CHAT_FILTER_GROUP_PAWN = 17,
        CHAT_FILTER_GROUP_SERVER_SYSTEM = 18,
        CHAT_FILTER_GROUP_SERVER_ALERT = 19,
        CHAT_FILTER_GROUP_LOCAL_SYSTEM = 20,
        CHAT_FILTER_GROUP_QUEST = 21,
        CHAT_FILTER_GROUP_OHTER = 22,
        CHAT_FILTER_GROUP_NONE = 23,
        CHAT_FILTER_GROUP_MAX = 24,
    };
    enum
    {
        MSG_ATTR_NONE = 0,
        MSG_ATTR_ERROR = 1,
        MSG_ATTR_MY_TELL = 2,
    };
public:
    class MyDTI;
    struct stMsgQueue;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stMsgQueue
    {
    public:
        s32 logId;  // offset: 0x0
        u32 characterId;  // offset: 0x4
        s32 filterGroup;  // offset: 0x8
        u32 attr;  // offset: 0xc
        MtString mFirstName;  // offset: 0x10
        MtString mLastName;  // offset: 0x18
        MtString mClanName;  // offset: 0x20
        MT_CHAR onlineID[32];  // offset: 0x28
        MT_CHAR msg[256];  // offset: 0x48
        MtString mAnalyzerMsg[3];  // offset: 0x148
        s32 mAnalyzerNum[3];  // offset: 0x160
        MtTime mTime;  // offset: 0x170
        sChat::stMsgQueue* pFilterGroupNext;  // offset: 0x178
        sChat::stMsgQueue* pFilterGroupPrev;  // offset: 0x180
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
    sChat();
    virtual ~sChat();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void move();  // vtable slot 7
    virtual void reset();  // vtable slot 6
    static sChat* getInstance();
    void init();
    void final();
    void resetLog();
    void clearMsgQueue(stMsgQueue& MsgQue);
    bool checkChatOk();
    void setKeyboardSetting(MT_CTSTR pMsgDefault);
    void requestSoftKeyboardChat();
    u32 getChatState();
    MT_CHAR* getOutputText_utf8();
    u32 getOutputTextLength();
    void setOutputTextLength(u32);
    void setOutputText_utf8(MT_CTSTR msg, u32 size);
    MT_CTSTR getOutputTextDefault();
    void setOutputTextDefault(MT_CTSTR);
    void setChatArea(s32 chatArea);
    s32 getChatArea();
    void setDispFilterGroup(s32);
    MT_CTSTR getFixedPhrase(u32 fixedPhrase);
    bool sendMessage(MT_CTSTR message);
    void sendFixedMessage(u32 fixedPhrase);
    void sendPawnMessage(s32 pawnIndex, u32 msgNo);
    bool sendClanNtcMessage(MT_CTSTR message);
    bool analyzeMessage(MT_CHAR* dstMsg, MT_CTSTR srcMsg, u32 size, s32 memberIndex, s32 type);
    void addMessage(const MT_CHAR* msg, s32 filterGroup, MT_CTSTR name, bool isUTF8, MT_CTSTR pAnalizerMsg0, MT_CTSTR pAnalizerMsg1, s32 pAnalizerNum0, s32 pAnalizerNum1, u32 msgAttr, u32 characterId, MT_CTSTR pLastName, MT_CTSTR pClanName, MT_CTSTR pAnalizerMsg2, s32 pAnalizerNum2);
    void addMsgQueue(stMsgQueue& queue);
    u32 getMsgQueue(stMsgQueue* * queueArray, u32 filterBit, s32 msgNum, s32 msgStart);
    u32 getMsgQueueNum(stMsgQueue* * queueArray);
    bool checkFilter(s32 filterGroup, s32 filterBit);
    void addMsgFilterGroup(stMsgQueue& msg);
    void removeMsgFilterGroup(stMsgQueue& msg);
    void clearTellChat();
    void setTellChat(u32 characterId, MT_CTSTR firstName, MT_CTSTR lastName, MT_CTSTR clanName);
    u32 getTellCharacterId();
    void makeTellCharacterName(MtString& rStr, nGUIExt::NAME_TYPE type);
private:
    void clearTellCharacterHistory();
    void addTellCharacterHistory(u32 characterId, MT_CTSTR firstName, MT_CTSTR lastName, MT_CTSTR clanName, bool isLock);
public:
    s32 getTellCharacterHistoryNum() const;
    bool setLastTellCharacterHistory(bool isLock);
    bool setNextTellCharacterHistory(bool isLock);
    void setChatView();
    MT_CTSTR getChatAreaStr(s32);
    MT_CTSTR getChatFilterGroupStr(s32);
    s32 getChatAreaFromFilterGroup(s32);
    u32 getShoutIntervalTime() const;
    void setShoutIntervalTime(u32 time);
    f32 getShoutWaitTime() const;
    void setStrMessageSet(nCharacterData::stMessageSet& msgSet, MT_CTSTR str, s32 index);
    MT_CTSTR getStrMessageSet(nCharacterData::stMessageSet& msgSet, s32 index);
    void setNameMessageSet(nCharacterData::stMessageSet& msgSet, MT_CTSTR str);
    MT_CTSTR getNameMessageSet(nCharacterData::stMessageSet& msgSet);
    void putMessageSet(nCharacterData::stMessageSet& msgSet, s32 index);
    void setMessageSetKeyboardSetting(MT_CTSTR defStr);
private:
    stMsgQueue mMsgArray[300];  // offset: 0x18
    s32 mQueueIndex;  // offset: 0x1cb78
    s32 mQueueHead;  // offset: 0x1cb7c
    s32 mNextLogId;  // offset: 0x1cb80
    stMsgQueue* mpFilterGroupTop[24];  // offset: 0x1cb88
    stMsgQueue* mpFilterGroupBottom[24];  // offset: 0x1cc48
    s32 mFilterGroupMsgNum[24];  // offset: 0x1cd08
    MT_CHAR mOutputText_utf8[6144];  // offset: 0x1cd68
    u32 mOutputTextLength;  // offset: 0x1e568
    MtString mOutputTextDefault;  // offset: 0x1e570
    f32 mNoSendSecond;  // offset: 0x1e578
    MtString mSendMsgOld;  // offset: 0x1e580
    s32 mChatArea;  // offset: 0x1e588
    s32 mDispFilterGroup;  // offset: 0x1e58c
    bool mIsChatEnable;  // offset: 0x1e590
    f32 mTimer;  // offset: 0x1e594
    f32 mDispWaitTimer;  // offset: 0x1e598
    u32 mSpeakerDispType;  // offset: 0x1e59c
    u32 mShoutIntervalTime;  // offset: 0x1e5a0
    f32 mShoutWaitTime;  // offset: 0x1e5a4
    CCommunityCharacterBaseInfo mTellCharacter;  // offset: 0x1e5a8
    CCommunityCharacterBaseInfo mTellCharacterPool[8];  // offset: 0x1e5d8
    CCommunityCharacterBaseInfo* mTellCharacterEmptyList[8];  // offset: 0x1e758
    CCommunityCharacterBaseInfo* mTellCharacterHistory[8];  // offset: 0x1e798
    s32 mTellCharacterHistoryNum;  // offset: 0x1e7d8
    s32 mTellCharacterHistoryIndex;  // offset: 0x1e7dc
    s32 mInputRno;  // offset: 0x1e7e0
public:
    static const u32 QUEUE_SIZE_MAX = 300;
    static const s32 LOG_ID_INVALID = -1;
    static const s32 LOG_ID_MAX = 2147483647;
    static const u32 CHAT_FILTER_BIT_SHOUT = 2;
    static const u32 CHAT_FILTER_BIT_SAY = 4;
    static const u32 CHAT_FILTER_BIT_PARTY = 8;
    static const u32 CHAT_FILTER_BIT_PARTY_L = 16;
    static const u32 CHAT_FILTER_BIT_CLAN = 32;
    static const u32 CHAT_FILTER_BIT_CLAN_NTC = 64;
    static const u32 CHAT_FILTER_BIT_GROUP_01 = 128;
    static const u32 CHAT_FILTER_BIT_GROUP_02 = 256;
    static const u32 CHAT_FILTER_BIT_GROUP_03 = 512;
    static const u32 CHAT_FILTER_BIT_GROUP_04 = 1024;
    static const u32 CHAT_FILTER_BIT_GROUP_05 = 2048;
    static const u32 CHAT_FILTER_BIT_GROUP_06 = 4096;
    static const u32 CHAT_FILTER_BIT_GROUP_07 = 8192;
    static const u32 CHAT_FILTER_BIT_GROUP_08 = 16384;
    static const u32 CHAT_FILTER_BIT_TELL = 32768;
    static const u32 CHAT_FILTER_BIT_ENTRYBOARD = 65536;
    static const u32 CHAT_FILTER_BIT_PAWN = 131072;
    static const u32 CHAT_FILTER_BIT_SERVER_SYSTEM = 262144;
    static const u32 CHAT_FILTER_BIT_SERVER_ALERT = 524288;
    static const u32 CHAT_FILTER_BIT_LOCAL_SYSTEM = 1048576;
    static const u32 CHAT_FILTER_BIT_QUEST = 2097152;
    static const u32 CHAT_FILTER_BIT_OHTER = 4194304;
    static const u32 CHAT_FILTER_LOBBY = 4;
    static const u32 CHAT_FILTER_LOBBY_ALL = 2;
    static const u32 CHAT_FILTER_PARTY = 24;
    static const u32 CHAT_FILTER_TELL = 32768;
    static const u32 CHAT_FILTER_SYSTEM = 1048576;
    static const u32 CHAT_FILTER_CLAN = 96;
    static const u32 CHAT_FILTER_GROUP = 32640;
    static const u32 CHAT_FILTER_INFORMATION = 262144;
    static const u32 CHAT_FILTER_ALERT = 524288;
    static const u32 CHAT_FILTER_QUEST = 2097152;
    static const u32 CHAT_FILTER_PAWN = 131072;
    static const u32 CHAT_FILTER_ENTRYBOARD = 65536;
    static const u32 CHAT_FILTER_ALL = 4294967295;
    static const u32 MSG_QUEUE_NAME_SIZE = 32;
    static const u32 MSG_QUEUE_ONLINE_ID_SIZE = 32;
    static const u32 MSG_QUEUE_MESSAGE_SIZE = 256;
    static const u32 CHAT_ANALYZER_MAX = 3;
    static const u32 CHATLOG_DISP_WAIT_TIME = 30;
    static const u8 FIXED_MESSAGE_TAG = 7;
    static const u8 PAWN_MESSAGE_TAG = 8;
    static const s32 MIN_DOUBLE_SEND_INTERVAL_SECONDS = 10;
    static const s32 MIN_SEND_INTERVAL_SECONDS = 1;
    static const s32 TELL_HISTORY_MAX = 8;
    static MyDTI DTI;
private:
    static sChat* mpInstance;
    static const MtColor mFontColor[5];
    static const MT_CTSTR mChatAreaStr[8];
    static const MT_CTSTR mChatGroupStr[24];
    static const s32 mGroupToChatArea[24];
};
