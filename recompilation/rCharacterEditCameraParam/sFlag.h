#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cSystem.h"
#include "../shared/nDDOUtility.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
class aStage;
namespace nLayout { class cGameDataCache; }
namespace nSessionManager { class cNetSessionManager; }

// Declarations
class sFlag;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class sFlag : public cSystem
{
    // inferred: aStage::requestWarp calls sFlag::setFlag
    friend class aStage;
    // inferred: nLayout::cGameDataCache::setGameData calls sFlag::setFlag
    friend class nLayout::cGameDataCache;
    // inferred: nSessionManager::cNetSessionManager::setReadyAction calls sFlag::setFlag
    friend class nSessionManager::cNetSessionManager;
public:
    enum
    {
        MAIN_QUEST_FLAG_NUM = 64,
        SET_QUEST_FLAG_NUM = 32,
        GAME_GLOBAL_FLAG_NUM = 512,
        LOT_FLAG_NUM = 128,
        SCENARIO_CTRL_FLAG_NUM = 256,
        DEMO_CTRL_FLAG_NUM = 64,
        TUTORIAL_TARGET_FLAG_NUM = 128,
        DEMO_LAYOUT_FLAG_NUM = 256,
        SET_QUEST_DISTRIBUTION_NUM = 128,
    };
    enum
    {
        FLAG_TYPE_NONE = 0,
        FLAG_TYPE_MAIN_QUEST = 1,
        FLAG_TYPE_SET_QUEST = 2,
        FLAG_TYPE_GAME_GLOBAL = 3,
        FLAG_TYPE_SYSTEM_FIX = 4,
        FLAG_TYPE_SYSTEM = 5,
        FLAG_TYPE_STATUS = 6,
        FLAG_TYPE_LOT = 7,
        FLAG_TYPE_SCE_CTRL = 8,
        FLAG_TYPE_DEMO_CTRL = 9,
        FLAG_TYPE_TUTORIAL_TARGET = 10,
        FLAG_TYPE_DEMO_LAYOUT = 11,
        FLAG_TYPE_NUM = 12,
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
    sFlag();
    virtual ~sFlag();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void init();  // vtable slot 10
    virtual void reset();  // vtable slot 6
    virtual void move();  // vtable slot 7
    virtual void clear();  // vtable slot 11
    virtual bool update();  // vtable slot 12
    static sFlag* getInstance();
    void resetSetQuestFlag();
    void setFlagOn_SystemFix(s32 FlagNo);
    void setFlagOff_SystemFix(s32 FlagNo);
    bool chkFlag_SystemFix(s32 FlagNo);
    void setFlagOn_System(s32);
    void setFlagOff_System(s32);
    bool chkFlag_System(s32);
    void setFlagOn_Status(s32 FlagNo);
    void setFlagOff_Status(s32);
    bool chkFlag_Status(s32 FlagNo);
    void setFlagOn_GameGlobal(s32 FlagNo);
    void setFlagOff_GameGlobal(s32 FlagNo);
    bool chkFlag_GameGlobal(s32 FlagNo);
    void setFlagOn_MainQuest(s32 QuestNo, s32 FlagNo);
    void setFlagOff_MainQuest(s32 QuestNo, s32 FlagNo);
    bool chkFlag_MainQuest(s32 QuestNo, s32 FlagNo);
    void resetMainQuestFlag();
    void setFlagOn_SetQuest(s32, s32);
    void setFlagOff_SetQuest(s32, s32);
    bool chkFlag_SetQuest(s32, s32);
    void setFlagOn_SetQuest_Recv(s32 QuestNo, s32 FlagNo, bool IsHost);
    void setFlagOff_SetQuest_Recv(s32 QuestNo, s32 FlagNo, bool IsHost);
    void resetSetQuestFlag(s32);
    void setFlagOn_SceCtrl(s32 FlagNo);
    void setFlagOff_SceCtrl(s32 FlagNo);
    bool chkFlag_SceCtrl(s32 FlagNo);
    void setFlagOn_DemoCtrl(s32 FlagNo);
    void setFlagOff_DemoCtrl(s32 FlagNo);
    bool chkFlag_DemoCtrl(s32 FlagNo);
    void resetDemoCtrlFlag();
    void setFlagOn_TutoTarget(s32 FlagNo);
    void setFlagOff_TutoTarget(s32);
    bool chkFlag_TutoTarget(s32 FlagNo);
    void resetTutoTargetFlag();
    void setFlagOn_DemoLayout(s32 FlagNo);
    void setFlagOff_DemoLayout(s32 FlagNo);
    bool chkFlag_DemoLayout(s32 FlagNo);
    void resetDemoLayoutFlag();
    void setFlagOn_SetQuestNoSync(s32 QuestNo, s32 FlagNo, bool Set);
    void resetSystemFlagStage();
    bool isHumanEventBusy() const;
private:
    void setFlag(u32 Type, u32 FlagNo, bool Set, bool IsHost, bool IsRecv);
    void resetFlag(u32 Type, u32 StartFlagNo);
private:
    nDDOUtility::cBitSet<32> mSystemFixFlag;  // offset: 0x14
    nDDOUtility::cBitSet<32> mSystemFlag;  // offset: 0x18
    nDDOUtility::cBitSet<64> mStatusFlag;  // offset: 0x1c
    nDDOUtility::cBitSet<512> mGameGlobalFlag;  // offset: 0x24
    nDDOUtility::cBitSet<1664> mMainQuestFlag;  // offset: 0x64
    nDDOUtility::cBitSet<4096> mSetQuestFlag;  // offset: 0x134
    nDDOUtility::cBitSet<256> mSceCtrlFlag;  // offset: 0x334
    nDDOUtility::cBitSet<64> mDemoCtrlFlag;  // offset: 0x354
    nDDOUtility::cBitSet<128> mTutoTargetFlag;  // offset: 0x35c
    nDDOUtility::cBitSet<256> mDemoLayoutFlag;  // offset: 0x36c
    static sFlag* mpInstance;
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline sFlag* sFlag::getInstance() {
    return ::sFlag::mpInstance;
}
