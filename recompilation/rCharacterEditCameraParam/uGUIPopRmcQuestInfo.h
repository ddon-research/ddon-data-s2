#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/nQuest.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjPolygon;
namespace nQuest { class SCHEDULE_ID; }
namespace nQuest { class cGUIInfoData; }
class rGUI;
class rGUIMessage;

// Declarations
class uGUIPopRmcQuestInfo;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIPopRmcQuestInfo : public uGUIBase
{
public:
    enum
    {
        TYPE_UNKNOWN = 0,
        TYPE_REPEAT = 1,
        TYPE_AREA = 2,
        TYPE_PARTY = 3,
        TYPE_RAID = 4,
        TYPE_DAILY = 5,
        TYPE_OPTION_COURSE = 6,
        TYPE_PROGRESS_BONUS = 7,
        TYPE_NUM = 8,
    };
public:
    class MyDTI;
    struct stMain;
    struct stBonusItem;
    struct stVar;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stBonusItem
    {
    public:
        stBonusItem();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnim;  // offset: 0x8
        cGUIObjMessage* mpObjMsgBonus;  // offset: 0x10
        cGUIObjMessage* mpObjMsgExp;  // offset: 0x18
        cGUIObjPolygon* mpObjPolyLine;  // offset: 0x20
        uGUIBase::cReferenceUIChargesInfo mCharge;  // offset: 0x28
    };
public:
    struct stVar
    {
    public:
        stVar();
    public:
        s32 mBaseSize;  // offset: 0x0
        s32 mOneLineOffset;  // offset: 0x4
        s32 mChargeSize;  // offset: 0x8
    };
public:
    struct stMain
    {
    public:
        stMain();
    public:
        uGUIPopRmcQuestInfo::stBonusItem mItem[6];  // offset: 0x0
        u32 mType[8];  // offset: 0x900
        u32 mCurrent;  // offset: 0x920
        u32 mTotalNum;  // offset: 0x924
        s32 mHeight;  // offset: 0x928
        s32 mHeightMax;  // offset: 0x92c
        f32 mTimer;  // offset: 0x930
        f32 mLineBasePos;  // offset: 0x934
        bool mIsChangePage;  // offset: 0x938
        static const u32 item_num = 6;
        static const s32 disp_frame = 150;
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
    uGUIPopRmcQuestInfo();
    virtual ~uGUIPopRmcQuestInfo();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    void setScheduleId(nQuest::SCHEDULE_ID schedule_id, nQuest::QUEST_TYPE quest_type);
private:
    void updateInit();
    void updateWait();
    void updateExit();
    void setupItem();
    bool setupUnknown(stBonusItem& bonus);
    bool setupRepeat(stBonusItem& bonus);
    bool setupArea(stBonusItem& bonus);
    bool setupParty(stBonusItem& bonus);
    bool setupRaid(stBonusItem& bonus);
    bool setupDaily(stBonusItem& bonus);
    bool setupOptionCourse(stBonusItem& bonus);
    bool setupProgressBonus(stBonusItem& bonus);
    bool setupBonusPos(stBonusItem& bonus);
    MT_CTSTR getMsg(u32 index);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    cGUIInstNull* mpInstNull;  // offset: 0x8d8
    stMain mMain;  // offset: 0x8e0
    stVar mVar;  // offset: 0x1220
    nQuest::cGUIInfoData mData;  // offset: 0x1230
    bool mIsRequest;  // offset: 0x1250
    nQuest::QUEST_TYPE mQuestType;  // offset: 0x1254
public:
    static MyDTI DTI;
};
