#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtCollection.h"
#include "../shared/MtDTI.h"
#include "../shared/MtString.h"
#include "../shared/cControl.h"
#include "../shared/uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjPolygon;
class cGUIObjTexture;
class cItemParam;
class rGUI;

// Declarations
class uGUIPopListDialog;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIPopListDialog : public uGUIBase
{
public:
    enum SELECT_ID
    {
        SELECT_ID_NONE = 0,
        SELECT_ID_DECIDE = 1,
        SELECT_ID_CANCEL = 2,
    };
    enum
    {
        FLOW_NONE = 0,
        FLOW_LIST = 1,
        FLOW_DECIDE = 2,
        FLOW_END = 3,
    };
    enum
    {
        MODE_DECIDE_CANCEL = 0,
        MODE_OK = 1,
    };
    enum
    {
        BUTTON_YES = 0,
        BUTTON_NO = 1,
        BUTTON_NUM = 2,
    };
    enum
    {
        INPUTEVENT_DECIDE = 66,
        INPUTEVENT_CANCEL = 67,
        INPUTEVENT_ADJUST_BUTTON_CURSOR = 68,
    };
public:
    class MyDTI;
    struct stVariable;
    struct stMain;
    struct stList;
    class cListItem;
    class cListInfo;
public:
    using DATA_FUNC = u32(MtObject::*)(MtObject*, MtObject*);
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
        s32 mParam_list_y;  // offset: 0x0
        s32 mParam_size_h;  // offset: 0x4
    };
public:
    struct stMain
    {
    public:
        stMain();
    public:
        cGUIInstAnimation* mpInstAnimText;  // offset: 0x0
        cGUIObjMessage* mpObjMsgText;  // offset: 0x8
        cGUIObjTexture* mpObjTexTopLeft;  // offset: 0x10
        cGUIObjTexture* mpObjTexTopCenter;  // offset: 0x18
        cGUIObjTexture* mpObjTexTopRight;  // offset: 0x20
        cGUIObjTexture* mpObjTexCenterLeft;  // offset: 0x28
        cGUIObjTexture* mpObjTexCenterCenter;  // offset: 0x30
        cGUIObjTexture* mpObjTexCenterRight;  // offset: 0x38
        cGUIObjTexture* mpObjTexBottomLeft;  // offset: 0x40
        cGUIObjTexture* mpObjTexBottomCenter;  // offset: 0x48
        cGUIObjTexture* mpObjTexBottomRight;  // offset: 0x50
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
        cGUIObjMessage* mpObjMsg;  // offset: 0x58
        cGUIObjMessage* mpObjMsgSub;  // offset: 0x60
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
    public:
        u32 mId;  // offset: 0x28
        u32 mQuality;  // offset: 0x2c
        u32 mNum;  // offset: 0x30
        static MyDTI DTI;
    };
public:
    struct stList
    {
    public:
        stList();
    public:
        cGUIInstNull* mpInstNull;  // offset: 0x0
        cGUIObjPolygon* mpObjPolyMask;  // offset: 0x8
        uGUIPopListDialog::cListItem mList[7];  // offset: 0x10
        uGUIBase::cScrollList mListCtrl;  // offset: 0x2f0
        uGUIBase::cReferenceUIButton mButton[2];  // offset: 0x5a0
        static const u32 item_num = 7;
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
    uGUIPopListDialog();
    virtual ~uGUIPopListDialog();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    void setMode(u32 mode);
    void setText(MT_CTSTR pText, MT_CTSTR pAnalyze0, s32 val0, MT_CTSTR pAnalyze1, s32 val1);
    void setDefaultPos(u32 pos);
    void setItemList(const MtTypedArray<cItemParam>& item_list);
    bool isDecide();
    SELECT_ID getSelect();
private:
    void setFlowId(u32 flow_id);
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void updateMove();
    void updateExit();
    void updateDecide();
    void setupText();
    void addSize(cGUIObjTexture* pObj, f32 add);
    void addPos(cGUIObjTexture* pObj, f32 add);
    void setupList();
    void adjustListCursor();
    void adjustButtonCursor();
    void setupListItem(uGUIBase::cScrollListItemBase* pItemBase, uGUIBase::cScrollListInfoBase* pInfoBase, u32 index);
    void hideListItem(uGUIBase::cScrollListItemBase* pItemBase);
    void eventDecide();
    void eventCancel();
    void eventAdjustListCursor();
    void eventAdjustButtonCursor();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlAdjustButtonCursor(cControl::Message* msg);
    u32 evCtrlMouseClick(cControl::Message* msg);
    void _setFunc(uGUIBase* pUnit, DATA_FUNC pFunc, MtObject* pParam);
private:
    rGUI* mpGUIRes;  // offset: 0x8c8
    u32 mFlowId;  // offset: 0x8d0
    bool mIsDecide;  // offset: 0x8d4
    u32 mDefaultPos;  // offset: 0x8d8
    u32 mMode;  // offset: 0x8dc
    MtString mText;  // offset: 0x8e0
    MtString mAnalyze0;  // offset: 0x8e8
    MtString mAnalyze1;  // offset: 0x8f0
    s32 mVal0;  // offset: 0x8f8
    s32 mVal1;  // offset: 0x8fc
    stVariable mVar;  // offset: 0x900
    stMain mMain;  // offset: 0x908
    stList mList;  // offset: 0x960
    cControl* mpDecideCtrl;  // offset: 0x1220
    cControl* mpCancelCtrl;  // offset: 0x1228
    cControl* mpButtonCtrl;  // offset: 0x1230
    MtTypedArray<cListInfo> mTempInfo;  // offset: 0x1238
    DATA_FUNC mpFunc;  // offset: 0x1258
    uGUIBase* mpFuncUnit;  // offset: 0x1268
    MtObject* mpFuncParam;  // offset: 0x1270
    SELECT_ID mSelect;  // offset: 0x1278
public:
    static MyDTI DTI;
};
