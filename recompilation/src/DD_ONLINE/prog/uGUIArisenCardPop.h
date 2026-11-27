#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "../../MT/MtMath.h"
#include "cControl.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector2;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class rAchievementHeader;
class rGUI;
class rGUIMessage;
class uGUIArisenCard;

// Declarations
class uGUIArisenCardPop;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIArisenCardPop : public uGUIBase
{
public:
    enum
    {
        MODE_IMAGE = 0,
        MODE_ACHIEVE = 1,
        MODE_EMOTION = 2,
        MODE_NUM = 3,
    };
    enum
    {
        INPUTEVENT_END = 66,
        INPUTEVENT_BG_CURSORMOVE = 67,
        INPUTEVENT_BG_CHANGE = 68,
        INPUTEVENT_BG_EXIT = 69,
        INPUTEVENT_ACHIEVE_CATEGORYMOVE = 70,
        INPUTEVENT_ACHIEVE_LISTMOVE = 71,
        INPUTEVENT_ACHIEVE_CHANGECATEGORY = 72,
        INPUTEVENT_ACHIEVE_CHANGELIST = 73,
        INPUTEVENT_ACHIEVE_CHANGE = 74,
        INPUTEVENT_EMOTION_CATEGORYMOVE = 75,
        INPUTEVENT_EMOTION_LISTMOVE = 76,
        INPUTEVENT_EMOTION_CHANGECATEGORY = 77,
        INPUTEVENT_EMOTION_CHANGELIST = 78,
        INPUTEVENT_EMOTION_STARTSLIDER = 79,
        INPUTEVENT_EMOTION_ENDSLIDER_CANCEL = 80,
        INPUTEVENT_EMOTION_ENDSLIDER_DECIDE = 81,
        INPUTEVENT_EMOTION_MOVESLIDER = 82,
        INPUTEVENT_EMOTION_SLIDERMOVECURSOR = 83,
    };
    enum
    {
        BG_DISP_MAX = 20,
        BG_MAX = 22,
        MENU_DISP_MAX = 16,
        MENU_MAX = 18,
        LIST_DISP_MAX = 19,
        LIST_MAX = 21,
        BG_NUM = 9,
    };
    enum
    {
        SLIDER_DIVIDE_NUM = 20,
    };
    enum
    {
        SLIDER_VLIST_SLIDER = 0,
        SLIDER_VLIST_BUTTON = 1,
        SLIDER_VLIST_NUM = 2,
    };
public:
    class MyDTI;
    class cScrollDispList;
    class cScrollListInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cScrollDispList : public uGUIBase::cScrollListItemBase
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
        cScrollDispList();
        virtual ~cScrollDispList() {}
    public:
        cGUIObjMessage* mpText;  // offset: 0x58
        static MyDTI DTI;
    };
public:
    class cScrollListInfo : public uGUIBase::cScrollListInfoBase
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
        cScrollListInfo();
    public:
        cScrollListInfo(f32 Top, f32 Bottom, u32 Index, u32 MsgId);
        virtual ~cScrollListInfo() {}
    public:
        u32 mIndex;  // offset: 0x28
        u32 mMsgId;  // offset: 0x2c
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
    uGUIArisenCardPop();
    virtual ~uGUIArisenCardPop();
    virtual bool loadResource();  // vtable slot 76
    virtual void updatePtr();  // vtable slot 17
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void setFocusForActiveBar(bool IsActive);  // vtable slot 82
    void setMode(u32 Mode);
    u32 getMode();
    s32 getResultNo();
    void setArisenCard(uGUIArisenCard* pCard);
    u32 getMotionNo();
    u32 getFrameNo();
    void setSVMotionInfo(u32 MotNo, u32 FrameNo, bool IsMan);
    u32 getAchieveUid();
    u32 getAchieveIndex();
private:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    bool moveInputSlider();
    void updateWaitInit();
    void updateWait();
    void updateExit();
    u32 evCtrlCancel(cControl::Message* pMsg);
    u32 evCtrlDecide(cControl::Message* pMsg);
    u32 evCtrlMoveUD(cControl::Message* pMsg);
    u32 evCtrlCancelSub(cControl::Message* pMsg);
    u32 evCtrlDecideSub(cControl::Message* pMsg);
    u32 evCtrlMoveUDSub(cControl::Message* pMsg);
    u32 evCtrlEmotionFrameCancel(cControl::Message* pMsg);
    u32 evCtrlEmotionFrameDecide(cControl::Message* pMsg);
    u32 evCtrlEmotionFrameMoveUD(cControl::Message* pMsg);
    u32 evCtrlEmotionFrameMouseClick(cControl::Message* pMsg);
    void initImage();
    void initAchieve();
    void initAchieveList();
    void initEmotion();
    void initEmotionFrame();
    void initEmotionList();
    void initAchieveCategory(cGUIInstAnimation* pInst, u32 Index);
    void initEmotionCategory(cGUIInstAnimation* pInst, u32 Index);
    void updateBGDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateBGHide(uGUIBase::cScrollListItemBase* pDispItem);
    void updateAchieveMenuDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateAchieveMenuHide(uGUIBase::cScrollListItemBase* pDispItem);
    void updateAchieveDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateAchieveHide(uGUIBase::cScrollListItemBase* pDispItem);
    void updateEmotionMenuDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateEmotionMenuHide(uGUIBase::cScrollListItemBase* pDispItem);
    void updateEmotionDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateEmotionHide(uGUIBase::cScrollListItemBase* pDispItem);
    void setCategoryFocus(bool IsFocus);
    void initListFocus();
    void setListSelected();
    void setBGFocus();
    void wakeupSlider();
    void sleepSlider();
    void updateSlider();
    void updateEmotion();
    void selectEmotion();
    void setEnd();
    u32 getBgNo(u32 CursorPos);
    bool requestBGServer();
    void callbackBGServer();
    bool requestAchieveServer();
    void callbackAchieveServer();
    void updateBG();
    void updateBGCursor();
    void updateAchieveCategoryCursor();
    void updateEmotionCategoryCursor();
    void updateSubListCursor();
    void decideBG();
    void decideAchieve();
    void decideAchieveMenu();
    void decideAchieveList();
    void decideEmotion();
    void decideEmotionMenu();
    void decideEmotionList();
    s32 getSelectBGNo();
    void resetEmotionDisp();
    void setSliderPos(u32 FrameNo, bool IsInit);
    u32 getFrameNoFromSliderPos();
    void setSliderActive(bool IsActive);
    void updateSliderCursor();
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDRes;  // offset: 0x8d0
    rGUIMessage* mpBGGMDRes;  // offset: 0x8d8
    rAchievementHeader* mpAchieveRes;  // offset: 0x8e0
    rGUIMessage* mpCategoryGMDRes;  // offset: 0x8e8
    rGUIMessage* mpArisenCardGMDRes;  // offset: 0x8f0
    uGUIArisenCard* mpCard;  // offset: 0x8f8
    uGUIBase::cVerticalList* mpSliderCtrl;  // offset: 0x900
    u32 mMode;  // offset: 0x908
    bool mIsSliderMode;  // offset: 0x90c
    bool mIsMan;  // offset: 0x90d
    uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x910
    uGUIBase::cReferenceUICloseBtn mCloseFrame;  // offset: 0x968
    uGUIBase::cScrollList mScrollBG;  // offset: 0x9c0
    cScrollDispList mDispBG[22];  // offset: 0xc70
    uGUIBase::cScrollList mScrollMenu;  // offset: 0x14b0
    uGUIBase::cScrollList mScrollList;  // offset: 0x1760
    cScrollDispList mDispMenu[18];  // offset: 0x1a10
    cScrollDispList mDispList[21];  // offset: 0x20d0
    u32 mMenuNum;  // offset: 0x28b0
    f32 mMenuBasePosY;  // offset: 0x28b4
    f32 mMenuOfsY;  // offset: 0x28b8
    u32 mListNum;  // offset: 0x28bc
    u32 mCategoryNo;  // offset: 0x28c0
    f32 mListBasePosY;  // offset: 0x28c4
    f32 mListOfsY;  // offset: 0x28c8
    s32 mResultNo;  // offset: 0x28cc
    cGUIInstAnimation* mpCategoryInst[21];  // offset: 0x28d0
    uGUIBase::cReferenceUIVlCursor mMainCursor;  // offset: 0x2980
    uGUIBase::cReferenceUIVlCursor mSubCursor;  // offset: 0x2a30
    uGUIBase::cReferenceUIIconJob mEmotionJobIcon;  // offset: 0x2ae0
    uGUIBase::cReferenceUIEditSlider mSlider;  // offset: 0x2b38
    uGUIBase::cReferenceUIButton mSliderButton;  // offset: 0x2c68
    u32 mMotionNo;  // offset: 0x2df8
    u32 mFrameNo;  // offset: 0x2dfc
    u32 mInitMotionNo;  // offset: 0x2e00
    u32 mInitFrameNo;  // offset: 0x2e04
    bool mIsMainListPointerDisp;  // offset: 0x2e08
    MtVector2 mBasePointerPos;  // offset: 0x2e10
    bool mIsChangeBG;  // offset: 0x2e18
    u32 mSelectBGNo;  // offset: 0x2e1c
    u32 mAchieveUid;  // offset: 0x2e20
    u32 mAchieveIndex;  // offset: 0x2e24
    cGUIInstNull* mpEmotion;  // offset: 0x2e28
    cGUIObjMessage* mpEmotionName;  // offset: 0x2e30
    cGUIInstAnimation* mpOtherActiveBar;  // offset: 0x2e38
    cGUIInstAnimation* mpEmotionFrameActiveBar;  // offset: 0x2e40
public:
    static MyDTI DTI;
    static const s32 RESULT_CANCEL = -1;
private:
    static const u32 ACV_INIT_NAME = 4294967295;
};

inline void* uGUIArisenCardPop::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline u32 uGUIArisenCardPop::getMode() {
    return this->mMode;
}

inline s32 uGUIArisenCardPop::getResultNo() {
    return this->mResultNo;
}

inline void uGUIArisenCardPop::setArisenCard(uGUIArisenCard* pCard) {
    this->mpCard = pCard;
}

inline u32 uGUIArisenCardPop::getMotionNo() {
    return this->mMotionNo;
}

inline u32 uGUIArisenCardPop::getFrameNo() {
    return this->mFrameNo;
}

inline u32 uGUIArisenCardPop::getAchieveUid() {
    return this->mAchieveUid;
}

inline u32 uGUIArisenCardPop::getAchieveIndex() {
    return this->mAchieveIndex;
}

inline void* uGUIArisenCardPop::cScrollDispList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIArisenCardPop::cScrollDispList::cScrollDispList() {
    this->mpText = nullptr;
}

inline void* uGUIArisenCardPop::cScrollListInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline MtAllocator* uGUIArisenCardPop::getAllocator() {
    return ::MtMemoryAllocator::getAllocator(::uGUIArisenCardPop::DTI);
}

inline void uGUIArisenCardPop::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIArisenCardPop::DTI)->memFree(p_addr);
}

inline void* uGUIArisenCardPop::cScrollDispList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIArisenCardPop::cScrollDispList::DTI)->memAlloc(sz, align, ::uGUIArisenCardPop::cScrollDispList::DTI.::MtDTI::getID());
}

inline void uGUIArisenCardPop::cScrollDispList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIArisenCardPop::cScrollDispList::DTI)->memFree(p_addr);
}

inline void uGUIArisenCardPop::cScrollListInfo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIArisenCardPop::cScrollListInfo::DTI)->memFree(p_addr);
}
