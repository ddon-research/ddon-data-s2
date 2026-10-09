#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtTime.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class CDataGPDetail;
class MtAllocator;
class MtDTI;
class MtObject;
class MtTime;
class cControl;
class cGUIInstAnimation;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjTexture;
namespace nInputTextKeyboardHook { struct Keycode; }
class rGUI;
class rGUIMessage;
class uGUIGPShop;

// Declarations
class uGUIGPShopDialog;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class uGUIGPShopDialog : public uGUIBase
{
public:
    enum
    {
        TYPE_EVENTCODE = 0,
        TYPE_GOLDSTONE = 1,
        TYPE_LIMIT = 2,
        TYPE_HISTORY = 3,
        TYPE_NONE = 4,
        TYPE_NUM = 5,
    };
    enum
    {
        LIMIT_LIST_DISP_MAX = 3,
        LIMIT_LIST_MAX = 6,
        HISTORY_LIST_DISP_MAX = 8,
        HISTORY_LIST_MAX = 10,
        CODE_BOX_NUM = 4,
        CODE_STRINGS_NUM = 4,
    };
    enum
    {
        INPUTEVENT_END = 66,
        INPUTEVENT_CHANGETAB = 67,
        INPUTEVENT_STARTLIMITBROWSER = 68,
        INPUTEVENT_CHANGELIMITCURSOR = 69,
        INPUTEVENT_CHANGEHISTORYCURSOR = 70,
        INPUTEVENT_STARTGPSHOP = 71,
        INPUTEVENT_GSBUYEND = 72,
        INPUTEVENT_CHANGESELECT = 73,
        INPUTEVENT_WAKEUPTEXTBOX = 74,
        INPUTEVENT_SENDCODE = 75,
        INPUTEVENT_CAUTIONMOVE = 76,
        INPUTEVENT_ATTENTIONCODE = 77,
        INPUTEVENT_EVENTCODENEXT = 78,
    };
    enum
    {
        TAB_GOLDSTONE = 0,
        TAB_LIMIT = 1,
        TAB_HISTORY = 2,
        TAB_NUM = 3,
    };
public:
    class MyDTI;
    class cScrollLimitDispList;
    class cScrollHistoryDispList;
    class cScrollLimitItemList;
    class cScrollHistoryItemList;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cScrollLimitDispList : public uGUIBase::cScrollListItemBase
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
        cScrollLimitDispList();
        // Address: 0x01af24a0 - 0x01af24a1 (1 bytes)
        virtual ~cScrollLimitDispList() {}
    public:
        cGUIInstAnimation* mpInst;  // offset: 0x58
        cGUIObjMessage* mpTime;  // offset: 0x60
        cGUIObjMessage* mpBuyGoldStone;  // offset: 0x68
        cGUIObjMessage* mpFreeGoldStone;  // offset: 0x70
        static MyDTI DTI;
    };
public:
    class cScrollHistoryDispList : public uGUIBase::cScrollListItemBase
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
        cScrollHistoryDispList();
        // Address: 0x01af2490 - 0x01af2491 (1 bytes)
        virtual ~cScrollHistoryDispList() {}
    public:
        cGUIInstAnimation* mpInst;  // offset: 0x58
        cGUIObjMessage* mpTime;  // offset: 0x60
        cGUIObjMessage* mpName;  // offset: 0x68
        cGUIObjMessage* mpKind;  // offset: 0x70
        cGUIObjMessage* mpGoldStone;  // offset: 0x78
        static MyDTI DTI;
    };
public:
    class cScrollLimitItemList : public uGUIBase::cScrollListInfoBase
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
    private:
        cScrollLimitItemList();
    public:
        cScrollLimitItemList(f32 Top, f32 Bottom, u32 FreeNum, u32 ChargedNum, u64 Time);
        // Address: 0x01af2560 - 0x01af2561 (1 bytes)
        virtual ~cScrollLimitItemList() {}
    public:
        u32 mFreeNum;  // offset: 0x28
        u32 mChargedNum;  // offset: 0x2c
        MtTime mTime;  // offset: 0x30
        static MyDTI DTI;
    };
public:
    class cScrollHistoryItemList : public uGUIBase::cScrollListInfoBase
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
    private:
        cScrollHistoryItemList();
    public:
        cScrollHistoryItemList(f32 Top, f32 Bottom, const CDataGPDetail& Data);
        // Address: 0x01af2510 - 0x01af2511 (1 bytes)
        virtual ~cScrollHistoryItemList() {}
    public:
        u32 mNum;  // offset: 0x28
        u32 mType;  // offset: 0x2c
        bool mIsFree;  // offset: 0x30
        MtTime mTime;  // offset: 0x38
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
    void setStartType(u32 Type);
    void setOnlineShopOpen();
    bool isSelectedGSBuy();
    uGUIGPShopDialog();
    virtual ~uGUIGPShopDialog();
    virtual bool loadResource();  // vtable slot 76
    virtual void updatePtr();  // vtable slot 17
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void adjustScale();  // vtable slot 84
private:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateWait();
    void updateLimit();
    void updateHistory();
    void updateGoldStone();
    void updateEventCode();
    u32 evCtrlCancel(cControl::Message* pMsg);
    u32 evCtrlTabLR(cControl::Message* pMsg);
    u32 evCtrlGSDecide(cControl::Message* pMsg);
    u32 evCtrlLimitDecide(cControl::Message* pMsg);
    u32 evCtrlLimitCursorUD(cControl::Message* pMsg);
    u32 evCtrlHistoryCursorUD(cControl::Message* pMsg);
    u32 evCtrlEventCodeCancel(cControl::Message* pMsg);
    u32 evCtrlEventCodeDecide(cControl::Message* pMsg);
    u32 evCtrlEventCodeCursorLR(cControl::Message* pMsg);
    u32 evCtrlEventCodeCursorUD(cControl::Message* pMsg);
    u32 evCtrlEventCodeMouseClick(cControl::Message* pMsg);
    u32 evCtrlEventCodeNext(cControl::Message* pMsg);
    void initType();
    void initConfirmCommon();
    void initGoldStone();
    void initLimit();
    void initHistory();
    void initEventCode();
    bool initConfirmRequestServer();
    bool limitRequestServer();
    bool historyRequestServer();
    void initConfirmCallBack();
    void limitCallBack();
    void historyCallBack();
    void setupGoldStone();
    void setupLimit();
    void setupHistory();
    void updateTab();
    void updateLimitCursor();
    void updateHistoryCursor();
    void updateTextBox(bool mIsOperate);
    void updateEventCodeLine();
    void updateEventCodeButton(bool mIsOperate);
    void updateConfirmCaution(bool IsDisp);
    void updateScrollLimitListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateScrollLimitListHide(uGUIBase::cScrollListItemBase* pDispItem);
    void updateScrollHistoryListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateScrollHistoryListHide(uGUIBase::cScrollListItemBase* pDispItem);
    void setType(u32 Type);
    void startLimitBrowser();
    bool isDispLimitCatution();
    void startGPShop();
    bool moveGPShop();
    bool isEnableEventCodeButton();
    void startSendEventCode();
    bool initEventCodeSend();
    void initEventCodeSendCallBack();
    virtual bool onKeyEvent(const nInputTextKeyboardHook::Keycode& keycode);  // vtable slot 90
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    uGUIBase::cHorizontalList* mpCtrl;  // offset: 0x8d8
    uGUIGPShop* mpGPShop;  // offset: 0x8e0
    bool mIsOnlineShopOpen;  // offset: 0x8e8
    bool mIsGSBuyClose;  // offset: 0x8e9
    uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x8f0
    uGUIBase::cReferenceUIBtnGuide mGuideCode;  // offset: 0x948
    uGUIBase::cReferenceUIBtnGuide mGuideDialog;  // offset: 0x9e0
    u32 mInitType;  // offset: 0xa78
    u32 mType;  // offset: 0xa7c
    uGUIBase::cReferenceUITab mTab;  // offset: 0xa80
    s32 mScrollDir;  // offset: 0xb30
    bool mIsGoldStoneRequest;  // offset: 0xb34
    uGUIBase::cVerticalList* mpGSCtrl;  // offset: 0xb38
    bool mIsLimitRequest;  // offset: 0xb40
    uGUIBase::cVerticalList* mpLimitCtrl;  // offset: 0xb48
    s32 mLimitListNum;  // offset: 0xb50
    cScrollLimitDispList mLimitList[6];  // offset: 0xb58
    uGUIBase::cScrollList mLimitScrollbar;  // offset: 0xe30
    f32 mLimitBaseY;  // offset: 0x10e0
    f32 mLimitListOfsH;  // offset: 0x10e4
    bool mIsHistoryRequest;  // offset: 0x10e8
    uGUIBase::cVerticalList* mpHistoryCtrl;  // offset: 0x10f0
    s32 mHistoryListNum;  // offset: 0x10f8
    cScrollHistoryDispList mHistoryList[10];  // offset: 0x1100
    uGUIBase::cScrollList mHistoryScrollbar;  // offset: 0x1600
    f32 mHistoryBaseY;  // offset: 0x18b0
    f32 mHistoryListOfsH;  // offset: 0x18b4
    s32 mSelectEventCodeTextBoxNo;  // offset: 0x18b8
    bool mIsMoveKeyboard;  // offset: 0x18bc
    uGUIBase::cReferenceUITextBox mTextBox[4];  // offset: 0x18c0
    uGUIBase::cReferenceUIButton mCodeButton;  // offset: 0x1e60
    uGUIBase::cScrollCtrl mCautionScrollbar;  // offset: 0x1ff0
    cControl* mpSpecialKeyCtrl;  // offset: 0x20d8
    cGUIInstAnimation* mpCaution;  // offset: 0x20e0
    cGUIInstAnimation* mpGSConfirm;  // offset: 0x20e8
    cGUIObjMessage* mpMyGoldStone;  // offset: 0x20f0
    cGUIObjMessage* mpBuyGoldStone;  // offset: 0x20f8
    cGUIObjMessage* mpFreeGoldStone;  // offset: 0x2100
    cGUIObjTexture* mpGSCaution;  // offset: 0x2108
    cGUIObjMessage* mpGSCautionTxt;  // offset: 0x2110
    cGUIObjNull* mpGSBuyButtonCursorObj;  // offset: 0x2118
    cGUIInstAnimation* mpLimitExplain;  // offset: 0x2120
    cGUIObjNull* mpLimitExplainCursorObj;  // offset: 0x2128
    cGUIObjTexture* mpCodeCheck;  // offset: 0x2130
    cGUIObjMessage* mpLimitNoList;  // offset: 0x2138
    cGUIObjMessage* mpHistoryNoList;  // offset: 0x2140
public:
    static MyDTI DTI;
private:
    static const u32 mCTType2TabTable[5];
};
