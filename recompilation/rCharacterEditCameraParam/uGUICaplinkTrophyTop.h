#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"
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
class rGUI;
class uGUICaplinkTopMenu;

// Declarations
class uGUICaplinkTrophyTop;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUICaplinkTrophyTop : public uGUIBase
{
public:
    enum
    {
        FLOW_NONE = 0,
        FLOW_GET_ACHIEVE_LIST = 1,
        FLOW_GET_ACHIEVE_RELATION = 2,
        FLOW_GET_ACHIEVE = 3,
        FLOW_LOAD_ICON = 4,
        FLOW_LIST = 5,
        FLOW_END = 6,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
    };
public:
    class MyDTI;
    struct stVariable;
    struct stMain;
    struct stList;
    class cListItem;
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
        s32 mParam_spacing_trophylist;  // offset: 0x0
    };
public:
    struct stMain
    {
    public:
        stMain();
    public:
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x0
        cGUIObjMessage* mpObjMsgSubTitle;  // offset: 0x8
        uGUIBase::cReferenceUICloseBtn mClose;  // offset: 0x10
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
        virtual ~cListItem();
    public:
        cGUIInstAnimation* mpInstAnimStamp;  // offset: 0x58
        cGUIInstAnimation* mpInstAnimLoading;  // offset: 0x60
        cGUIObjMessage* mpObjMsgTitle;  // offset: 0x68
        cGUIObjMessage* mpObjMsgComment;  // offset: 0x70
        cGUIObjMessage* mpObjMsgNum;  // offset: 0x78
        cCaplinkProfIconLoader mIcon;  // offset: 0x80
        static MyDTI DTI;
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
        // Address: 0x01ae6bc0 - 0x01ae6bc1 (1 bytes)
        virtual ~cListInfo() {}
    public:
        MtStringEx<33> mContentId;  // offset: 0x28
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
        uGUICaplinkTrophyTop::cListItem mList[9];  // offset: 0x2c0
        static const u32 list_num = 9;
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
    uGUICaplinkTrophyTop();
    virtual ~uGUICaplinkTrophyTop();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    void setOwner(uGUICaplinkTopMenu* pOwner);
private:
    void setFlowId(u32 flow_id);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateMove();
    void updateExit();
    void setupGetAchieveList();
    void updateGetAchieveList();
    void setupGetAchieveRelation();
    void updateGetAchieveRelation();
    void setupGetAchieve();
    void updateGetAchieve();
    void setupLoadIcon();
    void updateLoadIcon();
    void setupList();
    void setupListItem(uGUIBase::cScrollListItemBase* pListItem, uGUIBase::cScrollListInfoBase* pListInfo, u32 index);
    void hideListItem(uGUIBase::cScrollListItemBase* pListItem);
    cListInfo* getListInfo();
    cListInfo* getListInfo(u32 index);
    void eventDecide();
    void eventCancel();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    bool evCtrlScrl(cControl::Message* msg);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    u32 mFlowId;  // offset: 0x8d0
    stVariable mVar;  // offset: 0x8d4
    stMain mMain;  // offset: 0x8d8
    stList mList;  // offset: 0x940
    cControl* mpDecideCtrl;  // offset: 0x11a0
    cControl* mpCancelCtrl;  // offset: 0x11a8
    uGUICaplinkTopMenu* mpOwner;  // offset: 0x11b0
    s32 mRequestOffset;  // offset: 0x11b8
    s32 mRequestCount;  // offset: 0x11bc
public:
    static MyDTI DTI;
};
