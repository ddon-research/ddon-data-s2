#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"
#include "uGUICaplinkProfile.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtVector2;
class cCaplinkProfIconLoader;
class cControl;
class cDraw;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class rGUI;

// Declarations
class uGUICaplinkImageSelect;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUICaplinkImageSelect : public uGUIBase
{
public:
    enum
    {
        FLOW_NONE = 0,
        FLOW_LIST = 1,
        FLOW_END = 2,
    };
    enum
    {
        IMAGE_SELECT_NONE = 0,
        IMAGE_SELECT_DECIDE = 1,
        IMAGE_SELECT_CANCEL = 2,
    };
    enum
    {
        BUTTON_YES = 0,
        BUTTON_NO = 1,
        BUTTON_NUM = 2,
    };
    enum
    {
        INPUTEVENT_DECIDE_LIST = 66,
        INPUTEVENT_DECIDE_BUTTON = 67,
        INPUTEVENT_CANCEL = 68,
        INPUTEVENT_ADJUST_CURSOR = 69,
        INPUTEVENT_ADJUST_TAB = 70,
    };
public:
    class MyDTI;
    struct stMain;
    struct stIcon;
    struct stVariable;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stIcon
    {
    public:
        stIcon();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimMask;  // offset: 0x8
        cGUIInstAnimation* mpInstAnimIcon;  // offset: 0x10
        cGUIObjNull* mpObjNullPointer;  // offset: 0x18
        cGUIObjPolygon* mpObjPolyMouseCollision;  // offset: 0x20
        cCaplinkProfIconLoader mProfIcon;  // offset: 0x28
    };
public:
    struct stVariable
    {
    public:
        stVariable();
    public:
        s32 mParam_tab_x;  // offset: 0x0
        s32 mParam_spacing00;  // offset: 0x4
        s32 mParam_tabsize_x;  // offset: 0x8
        s32 mParam_mouse_collision;  // offset: 0xc
    };
public:
    struct stMain
    {
    public:
        stMain();
    public:
        cGUIInstNull* mpInstAnimPreview;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimCursor;  // offset: 0x8
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x10
        cGUIObjMessage* mpObjMsgTitleSub;  // offset: 0x18
        cGUIObjMessage* mpObjMsgPreview;  // offset: 0x20
        uGUICaplinkImageSelect::stIcon mIcon[9];  // offset: 0x28
        cCaplinkProfIconLoader mPreviewIcon;  // offset: 0x2b0
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x2d0
        uGUIBase::cReferenceUITab mTab;  // offset: 0x330
        uGUIBase::cReferenceUIButton mButton[2];  // offset: 0x3e0
        u32 mTabNum;  // offset: 0x700
        bool mIsSelectList;  // offset: 0x704
        static const u32 icon_num_x = 3;
        static const u32 icon_num_y = 3;
        static const u32 icon_num = 9;
        static const u32 tab_max = 8;
        static const u32 icon_max = 24;
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
    uGUICaplinkImageSelect();
    virtual ~uGUICaplinkImageSelect();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    void setDefaultIndex(u32 index);
    u32 getSelectResult();
    u32 getSelectIndex();
private:
    void setFlowId(u32 flow_id);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateMove();
    void updateExit();
    void setupTab();
    void setupList();
    void setupPreviewIcon();
    u32 getListIndex();
    void eventDecide();
    void eventCancel();
    void eventAdjustCursor();
    void eventAdjustTab();
    void decideList();
    void decideButton();
    void cancel();
    void adjustCursor();
    void adjustTab();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlClose(cControl::Message* msg);
    u32 evCtrlAdjustCursor(cControl::Message* msg);
    u32 evCtrlAdjustTab(cControl::Message* msg);
    u32 evCtrlMouseClick(cControl::Message* msg);
    void callPointer();
private:
    MtVector2 mPointerPos;  // offset: 0x8c8
    rGUI* mpGUIRes;  // offset: 0x8d0
    u32 mFlowId;  // offset: 0x8d8
    u32 mSelectIndex;  // offset: 0x8dc
    u32 mSelectResult;  // offset: 0x8e0
    stMain mMain;  // offset: 0x8f0
    stVariable mVar;  // offset: 0x1000
    cControl* mpDecideCtrl;  // offset: 0x1010
    cControl* mpCancelCtrl;  // offset: 0x1018
    uGUIBase::cMatrix* mpListCtrl;  // offset: 0x1020
    uGUIBase::cHorizontalList* mpTabCtrl;  // offset: 0x1028
    uGUIBase::cHorizontalList* mpButtonCtrl;  // offset: 0x1030
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
// inferred: a single inlined copy's body: the copy inlined in uGUICaplinkImageSelect::moveEvent at 0x9c1552-0x9c155c; it may reflect that caller's specialization (constants folded in, dead stores dropped), so read it with caution (026 plan-P76, ruling D-C2); approximate: no recompile checks it
inline void uGUICaplinkImageSelect::cancel() {
    this->mSelectResult = 2;
}
