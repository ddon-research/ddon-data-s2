#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtColor.h"
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtPropertyList;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjPolygon;
class cGUIObjTexture;
class rGUI;
class rGUIMessage;

// Declarations
class uGUIQuestBoardBase;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIQuestBoardBase : public uGUIBase
{
public:
    enum
    {
        TAB_ALL = 0,
        TAB_BATTLE = 1,
        TAB_DELIVERY = 2,
        TAB_NUM = 3,
    };
    enum
    {
        SL_ITEM_TYPE_HEADER = 0,
        SL_ITEM_TYPE_ITEM = 1,
        SL_ITEM_TYPE_NONE = 2,
    };
    enum
    {
        INPUTEVENT_CLOSE = 86,
    };
public:
    class MyDTI;
    struct stVar;
    struct stMain;
    struct stList;
    class cListHeader;
    class cListItem;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stVar
    {
    public:
        stVar();
    public:
        s32 param_spacing;  // offset: 0x0
        s32 sw;  // offset: 0x4
        s32 change_flow;  // offset: 0x8
        s32 param_cr_list_x;  // offset: 0xc
        s32 param_cr_list_y;  // offset: 0x10
        s32 param_header_base_y;  // offset: 0x14
    };
public:
    struct stMain
    {
    public:
        stMain();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIInstNull* mpInstNullInfoPos;  // offset: 0x8
        cGUIInstAnimation* mpInstAnimWindowFrame;  // offset: 0x10
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x18
        cGUIObjMessage* mpObjMsgTitleSub;  // offset: 0x20
        cGUIObjMessage* mpObjMsgOrder;  // offset: 0x28
        cGUIObjMessage* mpObjMsgOrderVal;  // offset: 0x30
        cGUIObjMessage* mpObjMsgNothing;  // offset: 0x38
        uGUIBase::cReferenceUITab mTab;  // offset: 0x40
        uGUIBase::cReferenceUIBtnGuide mGuide;  // offset: 0xf0
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x188
        MtColor mMaxDefColor;  // offset: 0x1e0
        uGUIBase::cReferenceUIButton mButton;  // offset: 0x1e8
    };
public:
    class cListHeader : public uGUIBase::cScrollListItemBase
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
        cListHeader();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x58
        cGUIInstNull* mpInstNullBase;  // offset: 0x60
        cGUIInstNull* mpInstNullCursorPos;  // offset: 0x68
        cGUIInstAnimation* mpInstAnim;  // offset: 0x70
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x78
        cGUIObjTexture* mpObjTexQuestIcon;  // offset: 0x80
        static MyDTI DTI;
    };
public:
    class cListItem : public uGUIBase::cScrollListItemBase
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
        cGUIInstNull* mpInstNull;  // offset: 0x58
        cGUIInstAnimation* mpInstAnimTitle;  // offset: 0x60
        cGUIInstAnimation* mpInstAnimLv;  // offset: 0x68
        cGUIInstAnimation* mpInstAnimIconClear;  // offset: 0x70
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x78
        cGUIObjMessage* mpObjMsgLv;  // offset: 0x80
        cGUIObjMessage* mpObjMsgLvVal;  // offset: 0x88
        static MyDTI DTI;
    };
public:
    struct stList
    {
    public:
        stList();
    public:
        cGUIObjPolygon* mpObjPolyMaskTop;  // offset: 0x0
        cGUIObjPolygon* mpObjPolyMaskCenter;  // offset: 0x8
        cGUIObjPolygon* mpObjPolyMaskBottom;  // offset: 0x10
        uGUIQuestBoardBase::cListHeader mHeader[9];  // offset: 0x18
        uGUIQuestBoardBase::cListItem mList[18];  // offset: 0x4e0
        uGUIBase::cScrollList mListCtrl;  // offset: 0xf00
        uGUIBase::cReferenceUIVlCursor mCursor;  // offset: 0x11b0
        f32 mHeaderBasePos;  // offset: 0x1260
        f32 mHeaderBaseBasePos;  // offset: 0x1264
        f32 mItemBasePos;  // offset: 0x1268
        f32 mCursorBasePos;  // offset: 0x126c
        static const u32 list_num = 18;
        static const u32 header_num = 9;
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
    uGUIQuestBoardBase(u32 initFlags);
    virtual ~uGUIQuestBoardBase();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    // Address: 0x01aeefc0 - 0x01aeefc1 (1 bytes)
    virtual void setInfoFlow() {}  // vtable slot 91
protected:
    virtual void updateExit();  // vtable slot 92
    MT_CTSTR getQuestMsg(u32 index);
    void clearItem();
    virtual void hideHeader(uGUIBase::cScrollListItemBase* pItemBase);  // vtable slot 93
    virtual void hideItem(uGUIBase::cScrollListItemBase* pItemBase);  // vtable slot 94
    void hideListItem(uGUIBase::cScrollListItemBase* pItemBase);
    void setupQuestOrderNum();
    u32 evCtrlClose(cControl::Message* msg);
protected:
    rGUI* mpGUIRes;  // offset: 0x8c8
    rGUIMessage* mpGMDQuest;  // offset: 0x8d0
    cGUIInstNull* mpInstNull;  // offset: 0x8d8
    stVar mVar;  // offset: 0x8e0
    stMain mMain;  // offset: 0x900
    stList mList;  // offset: 0xc80
    MtStringEx<128> mTempStr;  // offset: 0x1ef0
public:
    static MyDTI DTI;
};
