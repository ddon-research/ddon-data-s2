#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cControl;
class cGUIInstAnimation;
class cGUIInstance;
class cGUIObject;
class rGUI;
class rGUIMessage;
class uGUITutorialPop;

// Declarations
class uGUIMenuTutorial;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIMenuTutorial : public uGUIBase
{
public:
    enum
    {
        INPUTEVENT_CANCEL = 66,
        INPUTEVENT_DECIDE = 67,
        INPUTEVENT_END = 68,
        INPUTEVENT_START = 69,
    };
public:
    class MyDTI;
    class cCaption;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cCaption : public MtObject
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
        cCaption();
        // Address: 0x01af8170 - 0x01af8171 (1 bytes)
        virtual ~cCaption() {}
    public:
        u32 mGuideNo;  // offset: 0x8
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
    uGUIMenuTutorial();
    virtual ~uGUIMenuTutorial();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    bool isDirectOpenMode();
    void setDirectOpenMode(bool bIsDirectOpenMode);
private:
    void updateInit();
    void updateWaitCtgr();
    void updateWaitCaption();
    void updateWaitDirectOpen();
    void updateExit();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    virtual void evEnd();  // vtable slot 48
    void evDecide();
    void evCancel();
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlStart(cControl::Message* msg);
    u32 evCtrlEnd(cControl::Message* msg);
    void updateCaptionList();
    void updateDisp();
    void initScrollListCtgr();
    void initScrollListCaption();
    void updateScrollListCtgr();
    void updateScrollListCaption();
    void updateScrollListDispCtgr(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateScrollListDispCaption(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateScrollListHide(uGUIBase::cScrollListItemBase* pDispItem);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGUIMsgCtgr;  // offset: 0x8d0
    rGUIMessage* mpGUIMsg;  // offset: 0x8d8
    uGUIBase::cReferenceUICloseBtn mCloseBtn;  // offset: 0x8e0
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0x938
    cControl* mpCtgrCtrl;  // offset: 0x9d0
    cControl* mpCaptionCtrl;  // offset: 0x9d8
    uGUIBase::cScrollList mScrollListCtgr;  // offset: 0x9e0
    uGUIBase::cScrollList mScrollListCaption;  // offset: 0xc90
    uGUIBase::cScrollListItemBase mScrollDispListCtgr[11];  // offset: 0xf40
    uGUIBase::cScrollListItemBase mScrollDispListCaption[12];  // offset: 0x1308
    cGUIInstAnimation* mpInstListCtgr[11];  // offset: 0x1728
    cGUIObject* mpObjListCtgr[11];  // offset: 0x1780
    cGUIInstAnimation* mpInstListCptn[12];  // offset: 0x17d8
    cGUIObject* mpObjListCptn[12];  // offset: 0x1838
    cGUIInstance* mpInstListCaption;  // offset: 0x1898
    MtTypedArray<cCaption> mCaptionList;  // offset: 0x18a0
    uGUITutorialPop* mpGUITutorialPop;  // offset: 0x18c0
    bool mIsDirectOpenMode;  // offset: 0x18c8
public:
    static MyDTI DTI;
    static const u32 CTGRVISIBLE_NUM = 11;
    static const u32 CPTNVISIBLE_NUM = 12;
};

// Inline, no code of its own: checked where it is inlined.
inline uGUIMenuTutorial::cCaption::cCaption() {
    this->mGuideNo = static_cast<u32>(0);
}
