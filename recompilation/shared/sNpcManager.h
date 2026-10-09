#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "MtString.h"
#include "cTalkMsgData.h"
#include "nCastUtility.h"
#include "rNpcLedgerList.h"
#include "sUnitManager.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtString;
class MtUI;
class cArcLoaderBase;
class cContextInstNpc;
class cNpcConstItem;
class cNpcCustomSkill;
class cNpcMeetingPlace;
class cTalkMsgData;
namespace nJobParam { class cJobInfo; }
class rGUIMessage;
class rHumanEnemyParam;
class rNPCEmoMyRoom;
class rNPCMotMyRoom;
class rNPCMotionSet;
class rNpcConstItem;
class rNpcCustomSkill;
class rNpcIsNoSetPS3;
class rNpcIsUseJobParamEx;
class rNpcLedgerList;
class rNpcMeetingPlace;
class rkThinkData;
class uControlNpc;
class uDDOModel;
class uHuman;
class uNpc;

// Declarations
class sNpcManager;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using f32 = float;
using s16 = short;
using s32 = int;
using size_t = _Sizet;
using u16 = unsigned short;
using u32 = unsigned int;
using u8 = unsigned char;

class sNpcManager : public sUnitManager
{
public:
    enum
    {
        NPC_LOAD_STATUS_NONE = 0,
        NPC_LOAD_STATUS_INIT = 1,
        NPC_LOAD_STATUS_BAKE_RELEASE_WAIT = 2,
        NPC_LOAD_STATUS_LOAD_WAIT = 3,
        NPC_LOAD_STATUS_LOAD_DONE = 4,
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
    sNpcManager();
    virtual ~sNpcManager();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void move();  // vtable slot 7
    static sNpcManager* getInstance();
    estUnitType<uDDOModel, void> createUnit(u32 unique_id, u32 unitID, bool IsCreateLightComp, bool IsPartnerPawn);
    rNpcLedgerList* getLedgerList();
    MT_CTSTR getNpcName(u32 NpcId);
    MT_CTSTR getNpcClassName(u32 NpcId);
    u32 getNpcVoiceType(u32 NpcId);
    u32 getNpcUnitType(u32 NpcId);
    u8 getNpcSex(u32 NpcId);
    void setUTF8Msg(MtString& dst, MT_CTSTR src_format, ...);
    uNpc* getNpcUnit(u32 npcId);
    void createResource();
    void releaseResource();
    void createNpcLedgerList();
    void releaseNpcLedgerList();
    void applyNpcInfo(u32 NpcId, cContextInstNpc* pNpc, uControlNpc* pCtrl);
    void setNPCMotionSetRes(rNPCMotionSet* pRes);
    u32 getNPCMotion(u8 category, u8 no, s32& index, f32& timer, f32& frame, f32& start, bool& dispItem);
    bool isTransOff(u8 category, u8 no);
    bool isRandomOn(u8 category, u8 no);
    s16 getTalkMot(u8 category, u8 no);
    s16 getHeadCtrl(u8 category, u8 no);
    u8 getTurnType(u8 category, u8 no);
    bool isPlayMusic(u8 category, u8 no, s32 index);
    bool isDisableCancel(u8 category, u8 no, s32 index);
    u32 getMotionListNum(u8 category, u8 no);
    void setNPCMotMyRoomRes();
    void releaseNPCMotMyRoomRes();
    bool isTransOffMyRoom(u8 no);
    bool isMotionCancelMyRoom(u8 no, s32 index);
    bool isMotionFinishMyRoom(u8 no, s32 index);
    u32 getNPCMotMyRoom(u8 no, s32& index, s32& cancel, f32& timer, f32& frame, u16& haveItem, s16& itemMotNo, s16& message, u8 sex, bool isCancel);
    void setNPCEmoMyRoomRes();
    void releaseNPCEmoMyRoomRes();
    bool isTransOffEmoMyRoom(u8 no);
    u32 getIndexFromUIDEmoMyRoom(u32 uid);
    bool isMotionCancelEmoMyRoom(u8 no, s32 index);
    bool isMotionFinishEmoMyRoom(u8 no, s32 index);
    u32 getNPCEmoMyRoom(u8 no, s32& index, s32& cancel, s16& fingerMotNo, s16& loop, u8 sex);
    void npcSyncLoad();
    bool isDispNpcId() const;
    void setDispNpcId(bool);
    void onDispNpcId();
    s32 getDispLineNpcId();
    void setDispLineNpcId(u32);
    void setThinkData(u32 job, rkThinkData* pRes);
    rkThinkData* getThinkData(u32 job) const;
    void setJobParam(u32 job, rHumanEnemyParam* pRes);
    void setJobParamEx(u32 job, rHumanEnemyParam* pRes);
    u32 getJobId(u32 NpcId);
    rHumanEnemyParam* getJobParam(u32 job, bool isUseEx) const;
    void calcJobParam(u32 job, u32 lv, nJobParam::cJobInfo& info, u32& hp, uControlNpc* pCtrlNpc, bool isUseEx);
    const uControlNpc* checkPlayNpcMusic(uHuman* pPl);
    void setNpcCustomSkill(rNpcCustomSkill* pRes);
    cNpcCustomSkill* getNpcCustomSkill(u16 thinkIndex) const;
    void setNpcConstItem(rNpcConstItem* pRes);
    cNpcConstItem* getNpcConstItem(u32 index) const;
    bool isHaveFunction(u32 NpcId, u32 FunctionId);
    bool isHaveFunction(u32 NpcId);
    bool isHaveEnableFunction(u32 NpcId, u32 FunctionId);
    bool isHaveEnableFunction(u32 NpcId);
    u32 getFunctionId(u32 NpcId, u32 Idx);
    u32 getFunctionParam(u32 NpcId, u32 FunctionId);
    rNpcLedgerList::cItem::cInstitutionOpenData* getFunctionOpenData(u32 NpcId, u32 FunctionId, u32 Idx);
    u32 getFunctionOpenDataNum(u32 NpcId, u32 FunctionId);
    bool isEnableFunction(u32 NpcId, u32 FunctionId);
    u32 getJobMasterState(u32 JobId);
    void initNoraPawnIdList();
    u32 getNoraPawnId(u32 Idx);
    bool isRegisterdNoraPawnList();
    void clearNoraPawnList();
    cTalkMsgData* getPawnTalkMsgData(u32 Personality);
    cTalkMsgData* getPawnTalkMsgData(const uDDOModel* pModel);
    void initPawnTalkMsgData();
    void initPawnTalkMsgDataCore(cTalkMsgData* pTalkData, u32 Personality);
    void startExMotArcLoad();
    bool isFinishExMotArcLoad();
    void releaseExMotArc();
    cNpcMeetingPlace* getMeetingPlace(u32 NpcId);
    void initStage();
    void loadCoMotionArc();
    void loadCoFullMotionArc();
    bool isFinishLoadCoFullMotionArc();
    void releaseCoFullMotionArc();
    bool isFinishLoadCoMotionArc();
    bool isUseLiteMotionStage(u32 StageNo);
    bool isUseLiteMotion();
    void loadFsmMotionArc();
    void releaseFsmMotionArc();
    bool isFinishLoadFsmMotionArc();
    void releaseCoMotionArc();
    bool isExistNpc(u32 NpcId);
    void checkCheckCollision();
    void reqChangeEquipMyRoom(uNpc* pNpc, s32 req);
    void setChangeEquipMyRoom();
    void clearChangeEquipMyRoom();
    bool isReqChangeEquipMyRoom();
    bool isNpcUseJobParamEx(u16 stageNo, u16 groupNo, u8 unitNo, u32 questId);
    bool isNpcNoSetPS3(u16 stageNo, u16 groupNo, u8 unitNo, u32 questId);
    bool isCommonVoiceCategory(u32 voiceType);
    u32 getCommonVoiceCategory(u32 voiceType);
    MT_CTSTR getCommonVoiceArcName(u32 voiceCategory);
    bool isInvalidCommonVoiceArc(u32 voiceCategory);
    void loadCommonVoiceArc(u32 voiceType);
    bool isFinishLoadCommonVoiceArc(u32 voiceType);
    void releaseCommonVoiceArc();
    bool isUseCommonVoiceArc(u32 voiceCategory);
protected:
    rNpcLedgerList* mpLedgerList;  // offset: 0xa0
    rGUIMessage* mpNpcNameMsg;  // offset: 0xa8
    rGUIMessage* mpNpcClassNameMsg;  // offset: 0xb0
    rNPCMotionSet* mpNPCMotionSet;  // offset: 0xb8
    rkThinkData* mpThinkData[10];  // offset: 0xc0
    rHumanEnemyParam* mpJobParam[10];  // offset: 0x110
    rHumanEnemyParam* mpJobParamEx[10];  // offset: 0x160
    rNpcCustomSkill* mpNpcCustomSkill;  // offset: 0x1b0
    rNpcConstItem* mpNpcConstItem;  // offset: 0x1b8
    rNpcMeetingPlace* mpNpcMeetingPlace;  // offset: 0x1c0
    MtString mNameError;  // offset: 0x1c8
    bool mIsDispNpcId;  // offset: 0x1d0
    s32 mDispLineNpcId;  // offset: 0x1d4
    u32* mpNoraPawnIdList;  // offset: 0x1d8
    u32 mNoraPawnIdNum;  // offset: 0x1e0
    bool mIsRegisterdNoraPawnList;  // offset: 0x1e4
    cTalkMsgData mPawnTalkData[9];  // offset: 0x1e8
    TICKET mExMotTicket;  // offset: 0x4b8
    TICKET mLiteTicket;  // offset: 0x4c0
    TICKET mFsmTicket;  // offset: 0x4c8
    TICKET mFullTicket;  // offset: 0x4d0
    TICKET mCommonVoiceTicket[12];  // offset: 0x4d8
    rNPCMotMyRoom* mpNPCMotMyRoom;  // offset: 0x538
    rNPCEmoMyRoom* mpNPCEmoMyRoom;  // offset: 0x540
    s32 mReqChangeEquipMyRoom;  // offset: 0x548
    uNpc* mpChangeEquipNpc;  // offset: 0x550
    rNpcIsUseJobParamEx* mpNpcIsUseJobParamEx;  // offset: 0x558
    rNpcIsNoSetPS3* mpNpcIsNoSetPS3;  // offset: 0x560
private:
    static sNpcManager* mpInstance;
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline sNpcManager* sNpcManager::getInstance() {
    return ::sNpcManager::mpInstance;
}
