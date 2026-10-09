#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class MtVector2;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjTexture;
class rGUI;
class rSoundRequest;
class uGUIPopDetail01;

// Declarations
class uGUILoginBonus;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUILoginBonus : public uGUIBase
{
public:
    enum LOGINBONUS_IDX
    {
        LOGINBONUS_CUMULATIVE = 0,
        LOGINBONUS_SEQUENCIAL = 1,
        LOGINBONUS_CUMULATIVE_MENU = 2,
        LOGINBONUS_SEQUENCIAL_MENU = 3,
    };
    enum LOGINBONUS_CTRL_STAT
    {
        LOGINBONUS_MAT_CTRL = 0,
        LOGINBONUS_BTN_CTRL = 1,
    };
    enum LOGINBONUS_DEF
    {
        INVALID_IDX = -1,
        LB_GMD_IDX_0 = 0,
        CUM_H_MAX = 5,
        SEQ_H_MAX = 4,
        LIST_V_MAX = 2,
        BTN_MAX = 1,
    };
    enum LOGINBONUS_FIX_FRAME
    {
        FIX_SEQ = 0,
        FIX_CUM = 1,
    };
    enum LOGINBONUS_INPUTEVENT
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_ADJUST_BUTTON = 68,
        INPUTEVENT_SHORTCUT = 69,
        INPUTEVENT_ADJUST_CURSOR = 70,
        INPUTEVENT_ADJUST_TAB = 71,
        INPUTEVENT_END = 72,
    };
public:
    class MyDTI;
    struct stGUILoginBonusInst;
    struct stGUILoginBonusObj;
    struct stIconInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stGUILoginBonusInst
    {
    public:
        cGUIInstNull* null;  // offset: 0x0
        cGUIInstNull* null_all;  // offset: 0x8
        cGUIInstNull* null_scr;  // offset: 0x10
        cGUIInstNull* null_detail;  // offset: 0x18
        cGUIInstAnimation* msg_title;  // offset: 0x20
        cGUIInstAnimation* msg_name;  // offset: 0x28
        cGUIInstAnimation* msg_date;  // offset: 0x30
        cGUIInstAnimation* msg_tab;  // offset: 0x38
        cGUIInstAnimation* msg_btn;  // offset: 0x40
        cGUIInstAnimation* scrbar;  // offset: 0x48
        cGUIInstAnimation* close;  // offset: 0x50
    };
public:
    struct stGUILoginBonusObj
    {
    public:
        cGUIObjMessage* title_eng;  // offset: 0x0
        cGUIObjMessage* title_jap;  // offset: 0x8
        cGUIObjMessage* name;  // offset: 0x10
        cGUIObjMessage* date;  // offset: 0x18
    };
public:
    struct stIconInfo
    {
    public:
        stIconInfo();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstNull* mpInstNullEf;  // offset: 0x8
        cGUIInstAnimation* mpInstEffect;  // offset: 0x10
        cGUIInstAnimation* mpInstStamp;  // offset: 0x18
        cGUIInstAnimation* mpInstIcon;  // offset: 0x20
        cGUIObjMessage* mpObjnum;  // offset: 0x28
        cGUIObjTexture* mpTexEf;  // offset: 0x30
        cGUIObjTexture* mpTexSt;  // offset: 0x38
        cGUIObjTexture* mpTexMsk;  // offset: 0x40
        s32 mItemIdx;  // offset: 0x48
        s32 mItemVal;  // offset: 0x4c
        s32 mDate;  // offset: 0x50
        s32 mStat;  // offset: 0x54
        uGUIBase::cReferenceUIIconItem mIcon;  // offset: 0x60
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
    uGUILoginBonus();
    virtual ~uGUILoginBonus();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    u32 getFlow(u32 stat);
    u32 getHWidth(u32 stat);
    u32 getSum(u32 stat);
    void getOfs(u32 stat, u32& outX, u32& outY);
    void setState(u32 stat);
    void setCallState(bool bMenu);
    stIconInfo& getListIcon(u32 idx, u32 cnt);
protected:
    virtual void adjustScale();  // vtable slot 84
private:
    void setAnmIdx(u32 idx);
    void setStampEffect(u32 idx);
    void callStampEffect();
    void reset();
    void resetDispAndExecute(stIconInfo* pInfo, const u32 num, bool bDispAndExecute);
    u32 convItemId(u32 idx);
    stIconInfo* getIcon(u32 idx);
    MT_CTSTR getUnit(u32 idx);
    void makeItemName(MtString& rStr, MT_CTSTR name, u32 plus_value, u32 idx);
    void setInstPosX(cGUIInstNull* pInst, cGUIInstNull* pInstOrg, f32 val);
    void setInstPosY(cGUIInstNull* pInst, cGUIInstNull* pInstOrg, f32 val);
    void setupCtrl();
    void setupMenu();
    void setupList();
    void setupListData(u32 idx);
    void setupServer();
    void setupServerData();
    bool waitServerChk();
    bool initServerData();
    void initCumulative();
    void initSequencial();
    void updateDupliInstPos(u32 stat);
    void updateInit();
    void updateWait();
    void updateExit();
    void updateDisp();
    void setupFocus();
    void hideItemDetail();
    void setupItemDetail(u32 item_id);
    void updateItemDetail();
    virtual void moveInput();  // vtable slot 87
    void moveCtrl();
    virtual void moveEvent();  // vtable slot 88
    virtual void evEnd();  // vtable slot 48
    void evAdjustTab();
    void evAdjustCursor();
    void evDecide();
    u32 evCtrlEnd(cControl::Message* msg);
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlAdjTab(cControl::Message* msg);
    u32 evCtrlAdjCursor(cControl::Message* msg);
    u32 evCtrlLClick(cControl::Message* msg);
private:
    stGUILoginBonusInst mInst;  // offset: 0x8c8
    stGUILoginBonusObj mObj;  // offset: 0x920
    u32 mStat;  // offset: 0x940
    u32 mCtrlStat;  // offset: 0x944
    rGUI* mpGUIRes;  // offset: 0x948
    rSoundRequest* mpSeRes;  // offset: 0x950
    cControl* mpCtrl;  // offset: 0x958
    uGUIPopDetail01* mpPopDetail;  // offset: 0x960
    uGUIBase::cHorizontalList* mpTabCtrl;  // offset: 0x968
    uGUIBase::cHorizontalList* mpBtnCtrl;  // offset: 0x970
    uGUIBase::cMatrix* mpMatCtrl;  // offset: 0x978
    uGUIBase::cReferenceUITab mTab;  // offset: 0x980
    uGUIBase::cReferenceUIButton mBtn;  // offset: 0xa30
    uGUIBase::cReferenceUICloseBtn mCloseBtn;  // offset: 0xbc0
    stIconInfo mListSeqIcon[8];  // offset: 0xc20
    stIconInfo mListCumIcon[10];  // offset: 0x1b20
    s32 mOldLocateCum;  // offset: 0x2de0
    s32 mOldLocateSeq;  // offset: 0x2de4
    s32 mAnmIdx[10];  // offset: 0x2de8
    MtVector2 mPointerPos;  // offset: 0x2e10
    bool mIsCallFromMenu;  // offset: 0x2e18
    bool mIsPushUpBtn;  // offset: 0x2e19
    bool mIsMatrixClick;  // offset: 0x2e1a
    u32 mDrawItemId;  // offset: 0x2e1c
    u32 mSelectItemId;  // offset: 0x2e20
public:
    static MyDTI DTI;
    static const s32 CUM_LIST_NUM = 10;
    static const s32 SEQ_LIST_NUM = 8;
};
