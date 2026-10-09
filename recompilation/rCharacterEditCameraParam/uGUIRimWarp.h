#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class CDataFavoriteWarpPoint;
class MtAllocator;
class MtDTI;
struct MtFloat2;
class MtObject;
class MtPropertyList;
class MtVector2;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObjMessage;
class cGUIObjPolygon;
class cWarpLocation;
class rGUI;
class rGUIMessage;
class rWarpLocation;
class uGUISystemMsg;

// Declarations
class uGUIRimWarp;

// Type aliases from DWARF
using CFavoriteWarpPoint = CDataFavoriteWarpPoint;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIRimWarp : public uGUIBase
{
public:
    enum
    {
        MENU_TYPE_GAMEMENU = 0,
        MENU_TYPE_OUTPOST = 1,
        MENU_TYPE_HOME = 2,
        MENU_TYPE_DUNGEON = 3,
    };
    enum
    {
        FLOW_NONE = 0,
        FLOW_SERVER_WAIT = 1,
        FLOW_INIT = 2,
        FLOW_OUTPOST_TOP = 3,
        FLOW_FAVORITE_LIST = 4,
        FLOW_FAVORITE_WARP_CONFIRM = 5,
        FLOW_PARTY_WARP_CONFIRM = 6,
        FLOW_WARP_LIST = 7,
        FLOW_WARP_CONFIRM = 8,
        FLOW_REGIST_LIST = 9,
        FLOW_REGIST_CONFIRM = 10,
        FLOW_OVERWRITE_CONFIRM = 11,
        FLOW_WARP = 12,
        FLOW_END = 13,
    };
    enum
    {
        WARP_RESULT_DECIDE = 0,
        WARP_RESULT_CANCEL = 1,
    };
    enum
    {
        TAB_MAIN = 0,
        TAB_SUB = 1,
        TAB_FAVORITE = 2,
        TAB_ALL = 3,
        TAB_LOBBY = 4,
        TAB_NUM = 5,
    };
    enum
    {
        REQ_FLAG_GET_WARP_POINT_LIST = 0,
        REQ_FLAG_GET_FAVORITE_WARP_POINT_LIST = 1,
        REQ_FLAG_REGISTER_FAVORITE_WARP = 2,
        REQ_FLAG_WARP = 3,
        REQ_FLAG_AREA_WARP = 4,
        REQ_FLAG_PARTY_WARP = 5,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_ADJUST_CURSOR = 68,
        INPUTEVENT_ADJUST_TAB = 69,
        INPUTEVENT_START_BTN = 70,
    };
    enum
    {
        ITEMTYPE_HEADER = 0,
        ITEMTYPE_LIST = 1,
    };
public:
    class MyDTI;
    struct stMain;
    struct stTop;
    struct stPlace;
    struct stList;
    struct cHeaderItem;
    struct cListItem;
    struct stDialog;
    struct stDialogItem;
    struct stMap;
    class cListInfo;
    class cHeaderInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stTop
    {
    public:
        stTop();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x8
        cGUIObjMessage* mpObjMsgTitleSub;  // offset: 0x10
    };
public:
    struct stPlace
    {
    public:
        stPlace();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsgPlace;  // offset: 0x8
        cGUIObjMessage* mpObjMsgRim;  // offset: 0x10
        cGUIObjMessage* mpObjMsgRimVal;  // offset: 0x18
    };
public:
    struct cHeaderItem : public uGUIBase::cScrollListItemBase
    {
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
        cHeaderItem();
    public:
        cGUIObjMessage* mpObjMsg;  // offset: 0x58
        static MyDTI DTI;
    };
public:
    struct cListItem : public uGUIBase::cScrollListItemBase
    {
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
        cListItem();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x58
        cGUIInstAnimation* mpInstAnimIcon;  // offset: 0x60
        cGUIObjMessage* mpObjMsgPlace;  // offset: 0x68
        cGUIObjMessage* mpObjMsgArea;  // offset: 0x70
        cGUIObjMessage* mpObjMsgRim;  // offset: 0x78
        cGUIObjMessage* mpObjMsgRimVal;  // offset: 0x80
        static MyDTI DTI;
    };
public:
    struct stDialogItem
    {
    public:
        stDialogItem();
    public:
        cGUIInstAnimation* mpInstAnim;  // offset: 0x0
        cGUIObjMessage* mpObjMsg;  // offset: 0x8
    };
public:
    struct stMap
    {
    public:
        stMap();
    public:
        cGUIInstNull* mpInstNullIcon;  // offset: 0x0
        cGUIInstAnimation* mpInstAnim;  // offset: 0x8
        cGUIInstAnimation* mpInstAnimNowPlace;  // offset: 0x10
        cGUIInstAnimation* mpInstAnimPin;  // offset: 0x18
        cGUIInstAnimation* mpInstAnimLoadIcon;  // offset: 0x20
        u32 mDispIndex;  // offset: 0x28
    };
public:
    class cListInfo : public uGUIBase::cScrollListInfoBase
    {
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
        cListInfo();
    public:
        u32 mId;  // offset: 0x28
        u32 mIndex;  // offset: 0x2c
        u32 mLandId;  // offset: 0x30
        u32 mSortId;  // offset: 0x34
        u32 mPrice;  // offset: 0x38
        u32 mSlot;  // offset: 0x3c
        s32 mPos;  // offset: 0x40
        bool mIsLobby;  // offset: 0x44
        bool mIsPartyWarp;  // offset: 0x45
        bool mIsRegist;  // offset: 0x46
        bool mIsDisableClanBase;  // offset: 0x47
        static MyDTI DTI;
    };
public:
    class cHeaderInfo : public uGUIBase::cScrollListInfoBase
    {
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
        cHeaderInfo();
    public:
        u32 mLandId;  // offset: 0x28
        static MyDTI DTI;
    };
public:
    struct stMain
    {
    public:
        stMain();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimWindow;  // offset: 0x8
        cGUIInstAnimation* mpInstAnimWindowFrame;  // offset: 0x10
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x18
        uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0x70
        uGUIBase::cReferenceUITab mTab;  // offset: 0x110
        uGUIBase::cAdjustableWindow mWindowSizeCtrl;  // offset: 0x1c0
        uGUIRimWarp::stTop mTop;  // offset: 0x260
        uGUIRimWarp::stPlace mPlace;  // offset: 0x278
    };
public:
    struct stList
    {
    public:
        stList();
    public:
        cGUIInstAnimation* mpInstAnimMask;  // offset: 0x0
        cGUIObjPolygon* mpObjPolyMaskCenter;  // offset: 0x8
        cGUIObjPolygon* mpObjPolyMaskBottom;  // offset: 0x10
        cGUIObjMessage* mpObjMsgNotice;  // offset: 0x18
        uGUIRimWarp::cHeaderItem mHeaderItem[3];  // offset: 0x20
        uGUIRimWarp::cListItem mListItem[18];  // offset: 0x140
        uGUIBase::cScrollList mListCtrl;  // offset: 0xad0
        MtFloat2 mListBasePos;  // offset: 0xd80
        s32 mListOffset;  // offset: 0xd88
        f32 mCursorOffset;  // offset: 0xd8c
        static const u32 header_num = 3;
        static const u32 item_num = 18;
    };
public:
    struct stDialog
    {
    public:
        enum
        {
            LIST_UP = 0,
            LIST_DOWN = 1,
            LIST_NUM = 2,
        };
    public:
        stDialog();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimWindowFrame;  // offset: 0x8
        uGUIRimWarp::stTop mTop;  // offset: 0x10
        uGUIRimWarp::stPlace mPlace;  // offset: 0x28
        uGUIRimWarp::stDialogItem mList[2];  // offset: 0x48
        uGUIBase::cReferenceUIVlCursor mCursor;  // offset: 0x70
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x120
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
    uGUIRimWarp();
    virtual ~uGUIRimWarp();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    void setType(u32 menu_type, u32 place_id);
    s32 getStageNo();
    u32 getPosNo();
    u32 getWarpResult();
private:
    void setupTop(stTop& top, cGUIInstance* pInst);
    void setupPlace(stPlace& place, cGUIInstance* pInst);
    void setupDialogItem(stDialogItem& item, cGUIInstance* pInst);
    void setFlowId(u32 flow_id, bool isInit);
    void setPlayFlow(u32 flow_id);
    void setupWindowActive();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateMove();
    void updateExit();
    void setupInit();
    void setupEnd();
    void setupDialog();
    bool isAnyEnableWarpPoint();
    void setupList();
    bool isWarpPointFilter(u32 index, u32 slot);
    void addPartyWarp(MtTypedArray<cListInfo>& sort_list);
    void updateFavoriteList();
    void adjustMapPin(bool isUseCtrlPos);
    void adjustListCursor(bool isImmediate);
    void setupRegistList();
    void setupSystemMsg();
    void setup2WayDialog(MT_CTSTR msg, MT_CTSTR ok, MT_CTSTR cancel, MT_CTSTR error_msg, s32 def_pos);
    void updateSystemMsg();
    void setupSystemMsgEnable();
    void setupWarp();
    void setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideListItem(uGUIBase::cScrollListItemBase* pItemBase);
    cListInfo* getListInfo(u32 index);
    cListInfo* getListInfo();
    const CFavoriteWarpPoint* getFavoriteWarpPoint(u32 point_id);
    u32 getFavoriteSlotNo(u32 point_id);
    bool isAlreadyRegisted();
    u32 getRegistNum();
    u32 getRegistMax();
    const cWarpLocation* getLocData(u32 index);
    u32 getDataNum();
    u32 getLobbyDataNum();
    u32 getSortNo(u32 index);
    u32 getAreaId(u32 index);
    u32 getLandId(u32 index);
    u32 getSpotId(u32 index);
    s32 getStageNo(u32 index);
    u32 getPosNo(u32 index);
    u32 getIndexFromId(u32 id);
    u32 getIconType(u32 index);
    f32 getIconFrame(u32 index, u32 slot);
    MT_CTSTR getPlaceName(u32 index);
    MtVector2 getMapPos(u32 index);
    bool isRequest(u32 flag);
    void setRequest(u32 flag);
    void clearRequest(u32 flag);
    void requestServer(u32 next_flow_id);
    bool requestGetWarpPointList();
    void callbackGetWarpPointList();
    bool requestGetFavoriteWarpPointList();
    void callbackGetFavoriteWarpPointList();
    bool requestRegisterFavoriteWarpList();
    void callbackRegisterFavoriteWarpList();
    bool requestWarp();
    void callbackWarp();
    bool requestAreaWarp();
    void callbackAreaWarp();
    bool requestPartyWarp();
    void callbackPartyWarp();
    void eventDecide();
    void eventCancel();
    void eventStart();
    void eventAdjustCursor();
    void eventAdjustTab();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlStart(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message* msg);
    u32 evCtrlAdjustTab(cControl::Message* msg);
    u32 evCtrlMouseClick(cControl::Message* msg);
    MT_CTSTR getMsg(u32 index);
    MT_CTSTR getDlgMsg(u32 index);
    MT_CTSTR getCmnMsg(u32 index);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    rWarpLocation* mpWarpLoc;  // offset: 0x8d8
    rWarpLocation* mpLobbyWarpLoc;  // offset: 0x8e0
    cGUIInstNull* mpInstNull;  // offset: 0x8e8
    u32 mMenuType;  // offset: 0x8f0
    u32 mFlowId;  // offset: 0x8f4
    u32 mNextFlowId;  // offset: 0x8f8
    u32 mWarpResult;  // offset: 0x8fc
    u32 mNowPlaceIndex;  // offset: 0x900
    u32 mWarpPlaceId;  // offset: 0x904
    u32 mWarpPrice;  // offset: 0x908
    u32 mNowPlaceId;  // offset: 0x90c
    u32 mFavoriteSlot;  // offset: 0x910
    u32 mRequestFlag;  // offset: 0x914
    stMain mMain;  // offset: 0x920
    stList mList;  // offset: 0xbc0
    stDialog mDialog;  // offset: 0x1950
    stMap mMap;  // offset: 0x1ad0
    cControl* mpDecideCtrl;  // offset: 0x1b00
    cControl* mpCancelCtrl;  // offset: 0x1b08
    uGUIBase::cVerticalList* mpDialogCtrl;  // offset: 0x1b10
    uGUIBase::cHorizontalList* mpTabCtrl;  // offset: 0x1b18
    uGUISystemMsg* mpSystemMsg;  // offset: 0x1b20
    MtStringEx<256> mTempStr;  // offset: 0x1b28
    u32 mPartyWarpSec;  // offset: 0x1c2c
    u32 mPartyWarpId;  // offset: 0x1c30
    bool mIsPartyWarp;  // offset: 0x1c34
    bool mIsFavoriteFree;  // offset: 0x1c35
    bool mIsPaid;  // offset: 0x1c36
    bool mIsCallOpenSE;  // offset: 0x1c37
public:
    static MyDTI DTI;
};
