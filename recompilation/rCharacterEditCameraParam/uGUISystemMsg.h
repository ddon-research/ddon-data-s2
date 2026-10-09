#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/nDDOUtility.h"
#include "../shared/nGUIExt.h"
#include "../shared/nHuman.h"
#include "../shared/sGUIExt.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class cGUIObjTexture;
class rGUI;
class rSoundRequest;
class uGUIItemBase01;

// Declarations
class uGUISystemMsg;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUISystemMsg : public uGUIBase
{
    // inferred: uGUIItemBase01::evOnlineShop names uGUISystemMsg::mMode
    friend class uGUIItemBase01;
public:
    enum EXIT_FUNC_TYPE
    {
        EXIT_FUNC_END = 0,
        EXIT_FUNC_STOP = 1,
    };
    enum
    {
        ERRTYPE_NONE = 0,
        ERRTYPE_WARNING = 1,
        ERRTYPE_ERROR = 2,
    };
    enum
    {
        MODE_DEFAULT = 0,
        MODE_LIST = 1,
        MODE_YON = 2,
        MODE_MAX = 3,
    };
    enum
    {
        SKIPTYPE_BUTTON = 0,
        SKIPTYPE_COUNT = 1,
        SKIPTYPE_COUNT_BUTTON = 2,
    };
    enum
    {
        CHOICEPOS_ERROR = -3,
        CHOICEPOS_CANCEL = -2,
        CHOICEPOS_NONE = -1,
    };
    enum
    {
        INSTYON_YES = 0,
        INSTYON_NO = 1,
        INSTYON_NUM = 2,
    };
    enum
    {
        INPUTEVENT_CANCEL = 66,
        INPUTEVENT_DECIDE = 67,
        INPUTEVENT_LIST_MOVE = 68,
    };
public:
    class MyDTI;
    class cPageInfo;
    class cChoiceInfo;
    struct stReserveSE;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cChoiceInfo : public MtObject
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
        cChoiceInfo();
        virtual ~cChoiceInfo();
        void setMsg(MT_CTSTR msg);
        MT_CTSTR getMsg();
        void setErrorMsg(MT_CTSTR msg);
        MT_CTSTR getErrorMsg();
    public:
        u32 mSdlId;  // offset: 0x8
        u32 mJobId;  // offset: 0xc
        bool mIsEnable;  // offset: 0x10
        bool mIsDispLv;  // offset: 0x11
        uGUIBase::cMsgAnalyzer mMAWMsg;  // offset: 0x18
    private:
        MT_CHAR mMsg[256];  // offset: 0xc0
        MtStringEx<128> mErrorMsg;  // offset: 0x1c0
    public:
        static MyDTI DTI;
    };
public:
    struct stReserveSE
    {
    public:
        stReserveSE();
    public:
        u32 seID;  // offset: 0x0
        sGUIExt::cSEPlayer sound;  // offset: 0x8
    };
public:
    class cPageInfo : public MtObject
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
        cPageInfo();
        virtual ~cPageInfo();
        void initChoicePos();
    public:
        MT_CHAR mText[2048];  // offset: 0x8
        MT_CHAR mChoiceTitle[256];  // offset: 0x808
        MtTypedArray<uGUISystemMsg::cChoiceInfo> mArrayChoiceInfo;  // offset: 0x908
        s32 mChoicePos;  // offset: 0x928
        s32 mCancelChoicePos;  // offset: 0x92c
        s32 mDefaultChoicePos;  // offset: 0x930
        uGUIBase::cMsgAnalyzer mMAWText;  // offset: 0x938
        uGUIBase::cMsgAnalyzer mMAWCTitle;  // offset: 0x9e0
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
    uGUISystemMsg(u32 errType, u32 baseInitFlags, bool isChatSubMenu);
    virtual ~uGUISystemMsg();
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void setSE(nGUIExt::MSG_REASON reason, u32 seId, rSoundRequest* pRes);
    void setSerialNo(u32 uSerialNo);
    u32 getSerialNo();
    void setMode(u32 uMode);
    u32 getMode();
    void setSkipType(u32 uSkipType);
    u32 getSkipType();
    void setCntSkipChk(f32 fCnt);
    f32 getCntSkipChk();
    void setCntSkipRevChk(f32 fCnt);
    f32 getCntSkipRevChk();
    void setText(MT_CTSTR pText, s32 sPage);
    void setTextReal(MT_CTSTR pText, s32 sPage);
    void addText(MT_CTSTR pText, s32 sPage);
    MT_CTSTR getText(s32 sPage);
    void addPageInfo(MT_CTSTR msg);
    bool isFinalPage();
    u32 getFinalPageIdx();
    void setChoiceTitle(MT_CTSTR msg, s32 sPage);
    void addChoiceInfo(MT_CTSTR msg, u32 uScheduleId, nHuman::JOB_ENUM job, s32 sPage, bool isDispLv);
    void setChoiceEnable(u32 idx, bool isEnable, s32 sPage);
    void setChoiceErrorMsg(u32 idx, MT_CTSTR pErrorMsg, s32 sPage);
    s32 getChoicePos(s32 sPage);
    void setCancelChoicePos(s32 sCancelChoicePos, s32 sPage);
    void setCancelChoiceOff(bool isOff);
    void setDefaultChoicePos(s32 sDefaultChoicePos, s32 sPage);
    u32 getErrType();
    u32 getCurrentPage();
    void setEnableCloseBtn(bool);
    bool isEnableCloseBtn();
    void setPointerPosPrio(u32 uPrio);
    u32 getPointerPosPrio();
    void setMsgAnalyzeWorkText(u32 uIdx, MT_CTSTR pMsg, s32 sPage);
    void setMsgAnalyzeWorkText(u32 uIdx, s32 sNum, s32 sPage);
    void setMsgAnalyzeWorkChoiceTitle(u32 uIdx, MT_CTSTR pMsg, s32 sPage);
    void setMsgAnalyzeWorkChoiceTitle(u32 uIdx, s32 sNum, s32 sPage);
    void setMsgAnalyzeWorkChoiceMsg(u32 uIdx, MT_CTSTR pMsg, s32 sChoicePos, s32 sPage);
    void setMsgAnalyzeWorkChoiceMsg(u32 uIdx, s32 sNum, s32 sChoicePos, s32 sPage);
    void setAnalyzeMsg(bool isAnalyze);
    void exit();
    void setExitFunc(EXIT_FUNC_TYPE exitFuncType);
    bool isStop() const;
    void restart();
    void updateWindowActiveBar();
    void setMoveAsMenu(bool is_menu);
    bool isMoveAsMenu();
    virtual void updateDisp(bool bInit);  // vtable slot 91
private:
    void updateInit();
    void updateExit();
    void updateStop();
protected:
    virtual void updateWait();  // vtable slot 92
    virtual void createListCtrl();  // vtable slot 93
    virtual u32 evCtrlListMove(cControl::Message* msg);  // vtable slot 94
    virtual u32 evCtrlListDecide(cControl::Message* msg);  // vtable slot 95
    virtual u32 evCtrlListCancel(cControl::Message* msg);  // vtable slot 96
    void evListMove();
    void evListDecide();
    void evListCancel();
    cControl* getListCtrl();
    s32 getEnablePage(s32 sPage);
    virtual void setPointerPriority(u32 uPrio);  // vtable slot 97
    void callSe(nGUIExt::MSG_REASON Key);
    void callDecideSe();
    virtual void setFocusForActiveBar(bool IsActive);  // vtable slot 82
private:
    bool evCtrlScrollList(cControl::Message* msg);
    void initScrollList();
    u32 updateScrollList();
    void showScrollListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideScrollListItem(uGUIBase::cScrollListItemBase* pItemBase);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    cGUIInstAnimation* mpInstLine;  // offset: 0x8d0
    u32 mErrType;  // offset: 0x8d8
    f32 mDistMsgToLine;  // offset: 0x8dc
    f32 mDistLineToList;  // offset: 0x8e0
    uGUIBase::cReferenceUICloseBtn mCloseBtn;  // offset: 0x8e8
    bool mReqUpdateDisp;  // offset: 0x940
protected:
    cGUIInstAnimation* mpInstSkip;  // offset: 0x948
    cGUIObjTexture* mpObjSkip;  // offset: 0x950
    cGUIObjMessage* mpObjText;  // offset: 0x958
    cGUIObjPolygon* mpObjWndwBgC;  // offset: 0x960
    cGUIObjPolygon* mpObjWndwBgB;  // offset: 0x968
    cGUIObjPolygon* mpObjMask;  // offset: 0x970
    cGUIInstNull* mpInstNullListRoot;  // offset: 0x978
    cGUIInstNull* mpInstNullChoice[12];  // offset: 0x980
    cGUIInstAnimation* mpInstAnimChoice[12];  // offset: 0x9e0
    cGUIObjMessage* mpObjMsgChoiceInfo[12];  // offset: 0xa40
    cGUIObjPolygon* mpObjPolyChoiceInfoMO[12];  // offset: 0xaa0
    uGUIBase::cReferenceUIIconQuest mIconQuest[12];  // offset: 0xb00
    uGUIBase::cReferenceUIIconJob mIconJob[12];  // offset: 0x1580
    uGUIBase::cReferenceUIButton mBtnY;  // offset: 0x19a0
    uGUIBase::cReferenceUIButton mBtnN;  // offset: 0x1b30
    uGUIBase::cAdjustableWindow mWindow;  // offset: 0x1cc0
    u32 mSerialNo;  // offset: 0x1d60
    u32 mMode;  // offset: 0x1d64
    MtTypedArray<cPageInfo> mArrayPageInfo;  // offset: 0x1d68
    u32 mCurrentPage;  // offset: 0x1d88
    cControl* mpCtrl;  // offset: 0x1d90
    uGUIBase::cHorizontalList* mpCtrlYoN;  // offset: 0x1d98
    u32 mSkipType;  // offset: 0x1da0
    u32 mPointerPosPrio;  // offset: 0x1da4
    f32 mCntSkip;  // offset: 0x1da8
    f32 mCntSkipChk;  // offset: 0x1dac
    f32 mCntSkipRevChk;  // offset: 0x1db0
    f32 mDistList;  // offset: 0x1db4
    nDDOUtility::cArray<stReserveSE, 50> mReserveSEList;  // offset: 0x1db8
    bool mIsReserveSEUpdate;  // offset: 0x2268
    bool mIsUserSE;  // offset: 0x2269
    bool mIsCancelChoiseOff;  // offset: 0x226a
    bool mIsAnalyzeMsg;  // offset: 0x226b
    bool mIsMoveAsMenu;  // offset: 0x226c
    void(uGUIBase::*mpExitFunc)();  // offset: 0x2270
    uGUIBase::cScrollList mScrollList;  // offset: 0x2280
    uGUIBase::cScrollListItemBase mScrollDispList[12];  // offset: 0x2530
    nDDOUtility::cArray<cGUIObjNull*, 3> mActiveBarObjects;  // offset: 0x2950
public:
    static MyDTI DTI;
    static const u32 PAGEINFO_MAX = 32;
    static const u32 CHOICEINFODISP_MAX = 12;
    static const u32 DISABLE_SE = 4294967295;
protected:
    static const u32 CHOICEINFO_MAX = 64;
    static const s32 DIST_LIST = 20;
};

// Inline, no code of its own: checked where it is inlined.
inline u32 uGUISystemMsg::getCurrentPage() {
    return this->mCurrentPage;
}
