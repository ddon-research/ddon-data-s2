#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector3;
class cGUIInstance;
class rGUI;
class rGUIMessage;
class rSoundRequest;
class uGUIAnnounce;
class uGUIBazaarDealSheet;
class uGUIBazaarHistory;
class uGUIBazaarItem;
class uGUIBazaarItemSearch;
class uGUIBazaarPopBuy;
class uGUIBazaarPopInfo;
class uGUIBazaarPopItemList;
class uGUIBazaarPopPriceSetting;
class uGUIPopCmd01;
class uGUIPopTopSel;
class uGUISystemMsg;

// Declarations
class uGUIBazaar;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIBazaar : public uGUIBase
{
public:
    enum
    {
        FLOW_NONE = 0,
        FLOW_TOP = 1,
        FLOW_ITEM_SEARCH = 2,
        FLOW_ITEM_SEARCH_LIST = 3,
        FLOW_ITEM_LIST = 4,
        FLOW_ITEM_BUY_DISTRIBUTION = 5,
        FLOW_ITEM_BUY_CONFIRM = 6,
        FLOW_ITEM_CAUTION = 7,
        FLOW_ITEM_BUY_SUCCESS = 8,
        FLOW_ITEM_BUY_ERROR = 9,
        FLOW_SELECT_STORAGE = 10,
        FLOW_ITEM_SELECT = 11,
        FLOW_PRICE_SETTING = 12,
        FLOW_RE_PRICE_SETTING = 13,
        FLOW_PRICE_SET_CONFIRM = 14,
        FLOW_RE_PRICE_SET_CONFIRM = 15,
        FLOW_EXHIBIT_SUCCESS = 16,
        FLOW_EXHIBIT_ERROR = 17,
        FLOW_EXHIBIT_AFTER_LIST_REQ = 18,
        FLOW_EXHIBIT_AFTER_LIST_END = 19,
        FLOW_EXHIBIT_CANNOT_SELECT = 20,
        FLOW_DEAL_SHEET = 21,
        FLOW_GET_PRICEEDS = 22,
        FLOW_EXHIBIT_COMMAND_SELECT = 23,
        FLOW_EXHIBIT_CANCEL = 24,
        FLOW_EXHIBIT_CANCEL_FAIL = 25,
        FLOW_RE_EXHIBIT = 26,
        FLOW_DEAL_SHEET_TO_SELECT_STORAGE = 27,
        FLOW_GET_PRICEEDS_SUCCESS = 28,
        FLOW_GET_PRICEEDS_ERROR = 29,
        FLOW_CANCEL_EXHIBIT_WAIT = 30,
        FLOW_CANCEL_EXHIBIT_SUCCESS = 31,
        FLOW_CANCEL_EXHIBIT_ERROR = 32,
        FLOW_RE_EXHIBIT_SUCCESS = 33,
        FLOW_RE_EXHIBIT_ERROR = 34,
        FLOW_INVISIBLE = 35,
    };
    enum
    {
        INPUT_EVENT_DECIDE = 66,
        INPUT_EVENT_CANCEL = 67,
        INPUT_EVENT_SHORTCUT = 68,
    };
    enum
    {
        COMMAND_NONE = 0,
        COMMAND_00 = 1,
        COMMAND_01 = 2,
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
    void testCallBack(void* param);
    uGUIBazaar();
    virtual ~uGUIBazaar();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void move();  // vtable slot 9
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    void setFlowId(u32 flowId);
    u32 getFlowId();
    u32 getTopMenuPos();
    u32 getSearchMenuPos();
    u32 getSelectItemNo();
    u32 getDealSheetSelectNo();
    u32 getDealSheetSelectTag();
    f32 getDealSheetHSize();
    u32 callbackCmd00(MtObject* pCaller, MtObject* pDummy);
    u32 callbackCmd01(MtObject* pCaller, MtObject* pDummy);
    void callbackCmdCancel(u32 endType);
    u32 getDealSheetCommandSelNo();
    bool isSMENUShortCut();
    virtual s32 getSMenuCursorY();  // vtable slot 72
protected:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    virtual void adjustScale();  // vtable slot 84
private:
    void updateInit();
    void updateMove();
    void updateDisp();
    void eventDecide();
    void eventCancel();
    void eventShortCut();
    void dispCheckBazaarIcon(bool isUpdate);
    void movePriceSetConfirm();
    void moveCaution();
    void moveMessage();
    void moveAnnounce(bool cancel);
    void updateSelectCommnad();
    void createItemBox();
    void createPriceSetConfirm();
    void cretateExhibitAnnounce(bool isSuccess);
    void cretateExhibitCannotSelectAnnounce();
    void createBuyConfirm();
    void createBuyAnnounce(bool isSuccess);
    void createGetPriceedsAnnounce(bool isSuccess);
    void createExhibitCancelConfirm();
    void createExhibitCancelAnnounce(bool isSuccess);
    void createExhibitCancelFailAnnounce(bool isSuccess);
    void createReExhibitConfirm();
    void createReExhibitAnnounce(bool isSuccess);
    void createCaution();
    MT_CTSTR getMsg(u32 index);
    MT_CTSTR getCmnMsg(u32);
    void setBazaar2TopSel();
    bool isBoxFull(u32 itemNo, u32 Num);
    bool isCautionTime();
    void updateTime();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    cGUIInstance* mpInstDealSheet;  // offset: 0x8d8
    cGUIInstance* mpInstItemSearch;  // offset: 0x8e0
    cGUIInstance* mpInstHistory;  // offset: 0x8e8
    cGUIInstance* mpInstItemList;  // offset: 0x8f0
    cGUIInstance* mpInstPriceSetting;  // offset: 0x8f8
    cGUIInstance* mpInstItemDetail;  // offset: 0x900
    cGUIInstance* mpInstItemBox;  // offset: 0x908
    cGUIInstance* mpInstSystemMsg;  // offset: 0x910
    cGUIInstance* mpInstAnnounce;  // offset: 0x918
    cGUIInstance* mpInstBuy;  // offset: 0x920
    uGUIPopTopSel* mpTopSel;  // offset: 0x928
    uGUIBazaarItemSearch* mpItemSearch;  // offset: 0x930
    uGUIBazaarDealSheet* mpDealSheet;  // offset: 0x938
    uGUIBazaarPopInfo* mpInfo;  // offset: 0x940
    uGUIBazaarPopItemList* mpPopItemList;  // offset: 0x948
    uGUIBazaarPopPriceSetting* mpPopPriceSetting;  // offset: 0x950
    uGUIBazaarItem* mpPopItemBox;  // offset: 0x958
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0x960
    uGUIBazaarPopBuy* mpPopBuy;  // offset: 0x968
    uGUIPopCmd01* mpPopCmd;  // offset: 0x970
    uGUIAnnounce* mpAnnounce;  // offset: 0x978
    uGUIBazaarHistory* mpHistory;  // offset: 0x980
    rSoundRequest* mpSeRes;  // offset: 0x988
    u32 mFlowNow;  // offset: 0x990
    u32 mSelectItemNo;  // offset: 0x994
    u32 mCommandResult;  // offset: 0x998
    u32 mCommandEndType;  // offset: 0x99c
    bool mIsShortCut;  // offset: 0x9a0
    MtVector3 mCmdOfs;  // offset: 0x9b0
    f32 mTimer;  // offset: 0x9c0
    f32 mDetectionMasterTimer;  // offset: 0x9c4
    f32 mInvocationMasterTimer;  // offset: 0x9c8
    f32 mDetectionTimer;  // offset: 0x9cc
    u32 mDetectionCountLimit;  // offset: 0x9d0
    u32 mDetectionCount;  // offset: 0x9d4
    f32 mInvocationTimer;  // offset: 0x9d8
public:
    static MyDTI DTI;
    static const u32 mBazaarRebate;
    static const u32 mExhibitCannotSelectTimer;
};

inline void* uGUIBazaar::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u32 uGUIBazaar::callbackCmd00(MtObject* pCaller, MtObject* pDummy) {
    this->mCommandResult = 1;
    return 0;
}

inline u32 uGUIBazaar::callbackCmd01(MtObject* pCaller, MtObject* pDummy) {
    this->mCommandResult = 2;
    return 0;
}

inline void uGUIBazaar::callbackCmdCancel(u32 endType) {
    this->mCommandEndType = endType;
}

inline void uGUIBazaar::updateTime() {
    if (this->mInvocationTimer > 0.0f) {
        this->mInvocationTimer = this->mInvocationTimer - this->::cUnit::mDeltaTime;
        if (0.0f >= this->mInvocationTimer) {
            this->mInvocationTimer = 0.0f;
            this->mDetectionTimer = 0.0f;
            this->mDetectionCount = 0;
        }
    } else {
        if (this->mDetectionTimer > 0.0f) {
            this->mDetectionTimer = this->mDetectionTimer - this->::cUnit::mDeltaTime;
            if (0.0f >= this->mDetectionTimer) {
                this->mDetectionTimer = 0.0f;
                this->mDetectionCount = 0;
            }
        }
    }
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void uGUIBazaar::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIBazaar::DTI)->memFree(p_addr);
}
