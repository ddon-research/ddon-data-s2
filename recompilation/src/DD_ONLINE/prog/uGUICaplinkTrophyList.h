#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cControl.h"
#include "uGUIBase.h"
#include "uGUICaplinkProfile.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cCaplinkProfIconLoader;
class cControl;
class cGUIInstAnimation;
class cGUIObjMessage;
class cGUIObjTexture;
class rGUI;
class uGUICaplinkTopMenu;

// Declarations
class uGUICaplinkTrophyList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUICaplinkTrophyList : public uGUIBase
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
        INPUTEVENT_CANCEL = 66,
    };
public:
    class MyDTI;
    struct stVariable;
    struct stMain;
    struct stList;
    class cListItem;
    struct stDetail;
    class cListInfo;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stVariable
    {
    public:
        stVariable();
    public:
        s32 mParam_ofst_list_y;  // offset: 0x0
        s32 mParam_ofst_star_x;  // offset: 0x4
        s32 mParam_cr_list_x;  // offset: 0x8
        s32 mParam_ofst_caption_y;  // offset: 0xc
    };
public:
    struct stMain
    {
    public:
        stMain();
    public:
        cGUIInstAnimation* mpInstAnimStamp;  // offset: 0x0
        cGUIInstAnimation* mpInstAnimLoading;  // offset: 0x8
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x10
        cGUIObjMessage* mpObjMsgSubTitle;  // offset: 0x18
        cGUIObjMessage* mpObjMsgContentName;  // offset: 0x20
        cGUIObjMessage* mpObjMsgComment;  // offset: 0x28
        cGUIObjMessage* mpObjMsgCompleteNum;  // offset: 0x30
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x38
        cCaplinkProfIconLoader mIcon;  // offset: 0x90
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
        virtual ~cListItem() {}
    public:
        cGUIInstAnimation* mpInstAnimStatus;  // offset: 0x58
        cGUIObjMessage* mpObjMsgTrophyName;  // offset: 0x60
        cGUIObjMessage* mpObjMsgStatus;  // offset: 0x68
        static MyDTI DTI;
    };
public:
    struct stDetail
    {
    public:
        stDetail();
    public:
        cGUIInstAnimation* mpInstAnimStar[10];  // offset: 0x0
        cGUIInstAnimation* mpInstAnimStamp;  // offset: 0x50
        cGUIObjMessage* mpObjMsgTrophyName;  // offset: 0x58
        cGUIObjMessage* mpObjMsgDifficulty;  // offset: 0x60
        cGUIObjMessage* mpObjMsgCaptionTitle;  // offset: 0x68
        cGUIObjMessage* mpObjMsgCaption;  // offset: 0x70
        cGUIObjMessage* mpObjMsgPeriod;  // offset: 0x78
        cGUIObjTexture* mpObjTexCaptionBG;  // offset: 0x80
        cGUIObjTexture* mpObjTexCaptionBottom;  // offset: 0x88
        f32 mCaptionBGDefaultSize;  // offset: 0x90
        f32 mCaptionBottomDefaultPos;  // offset: 0x94
        static const u32 star_num = 10;
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
        virtual ~cListInfo() {}
    public:
        s32 mId;  // offset: 0x28
        static MyDTI DTI;
    };
public:
    struct stList
    {
    public:
        stList();
    public:
        cGUIInstAnimation* mpInstAnimMask;  // offset: 0x0
        uGUIBase::cScrollList mListCtrl;  // offset: 0x10
        uGUICaplinkTrophyList::cListItem mList[20];  // offset: 0x2c0
        static const u32 item_num = 20;
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
    uGUICaplinkTrophyList();
    virtual ~uGUICaplinkTrophyList();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    void setOwner(uGUICaplinkTopMenu* pOwner);
private:
    void setFlowId(u32 flow_id);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateMove();
    void updateExit();
    void setupList();
    void setupListItem(uGUIBase::cScrollListItemBase* pListItem, uGUIBase::cScrollListInfoBase* pListInfo, u32 index);
    void hideListItem(uGUIBase::cScrollListItemBase* pListItem);
    cListInfo* getListInfo();
    cListInfo* getListInfo(u32 index);
    void setupDetail();
    void eventCancel();
    u32 evCtrlCancel(cControl::Message* msg);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    u32 mFlowId;  // offset: 0x8d0
    stVariable mVar;  // offset: 0x8d4
    stMain mMain;  // offset: 0x8e8
    stList mList;  // offset: 0x9a0
    stDetail mDetail;  // offset: 0x1520
    cControl* mpCancelCtrl;  // offset: 0x15b8
    uGUICaplinkTopMenu* mpOwner;  // offset: 0x15c0
public:
    static MyDTI DTI;
};

inline uGUICaplinkTrophyList::stVariable::stVariable() {
}

inline uGUICaplinkTrophyList::stDetail::stDetail() {
}
