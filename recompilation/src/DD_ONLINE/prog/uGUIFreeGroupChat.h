#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "cControl.h"
#include "nDDOUtility.h"
#include "uGUIBase.h"
#include "uGUIsMenuBase.h"

// Forward declarations
class CDataCharacterListElement;
class MtAllocator;
class MtColor;
class MtDTI;
class MtObject;
class MtPropertyList;
class cControl;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjPolygon;
class cGUIObjTexture;
class rGUI;
class uGUICommunityList;

// Declarations
class uGUIFreeGroupChat;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIFreeGroupChat : public uGUIsMenuBase
{
public:
    enum FG_DM
    {
        DM_DEFAULT = 0,
        DM_COMMENT = 1,
        DM_MAX = 2,
    };
    enum FGC_DEF
    {
        FGC_GMD_IDX_0 = 0,
    };
    enum
    {
        BTN_INVITE = 0,
        BTN_LEAVE = 1,
        BTN_MAX = 2,
    };
    enum INPUTEVENT_FGC
    {
        INPUTEVENT_VMOVE = 66,
        INPUTEVENT_PAGEMOVE = 67,
        INPUTEVENT_HMOVE = 68,
        INPUTEVENT_SWITCH = 69,
        INPUTEVENT_LIST_UPDATE = 70,
    };
public:
    class MyDTI;
    class cPlInfo;
    struct stFreeGrpChatInst;
    struct stFreeGrpChatObj;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cPlInfo : public MtObject
    {
        friend class uGUIFreeGroupChat;
    public:
        class MyDTI;
    public:
        using cStr = uGUIBase::cExGUIMessageObj<64>;
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
        cPlInfo();
        void setAttr(u32 attr);
        void setStringColorAll(const MtColor& color);
        void setStringColor(cGUIObjMessage* p, const MtColor& color);
    private:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x8
        u32 mAttr;  // offset: 0x30
        cStr mName;  // offset: 0x38
        cStr mLv;  // offset: 0xa0
        cStr mLobbyName;  // offset: 0x108
        cStr mUnionName;  // offset: 0x170
        cStr mLocationName;  // offset: 0x1d8
        cStr mCommentName;  // offset: 0x240
        cGUIInstAnimation* mpINST_msg_list;  // offset: 0x2a8
        cGUIInstAnimation* mpINST_fix_job;  // offset: 0x2b0
        cGUIObjMessage* mpOBJ_msg_list_m_name;  // offset: 0x2b8
        cGUIObjMessage* mpOBJ_msg_list_m_lv;  // offset: 0x2c0
        cGUIObjMessage* mpOBJ_msg_list_m_loby;  // offset: 0x2c8
        cGUIObjMessage* mpOBJ_msg_list_m_location;  // offset: 0x2d0
        cGUIObjMessage* mpOBJ_msg_list_m_union;  // offset: 0x2d8
        cGUIObjMessage* mpOBJ_msg_list_m_comment;  // offset: 0x2e0
        cGUIObjMessage* mpObj_msg_list_m_party;  // offset: 0x2e8
        cGUIObjTexture* mpObj_msg_list_m_party_icon;  // offset: 0x2f0
        cGUIObjPolygon* mpObj_msg_list_mouseover;  // offset: 0x2f8
        uGUIBase::cReferenceUIIconOnlineStatus mOnlineStatusIcon;  // offset: 0x300
    public:
        static MyDTI DTI;
    };
public:
    struct stFreeGrpChatInst
    {
    public:
        cGUIInstNull* Null;  // offset: 0x0
        cGUIInstNull* Null_all;  // offset: 0x8
        cGUIInstNull* Null_list;  // offset: 0x10
        cGUIInstAnimation* msg_list;  // offset: 0x18
        cGUIInstAnimation* msg_num;  // offset: 0x20
        cGUIInstAnimation* msg_select;  // offset: 0x28
        cGUIInstAnimation* msg_btn00;  // offset: 0x30
        cGUIInstAnimation* msg_btn01;  // offset: 0x38
        cGUIInstAnimation* msg_numpager;  // offset: 0x40
        cGUIInstAnimation* msg_guide;  // offset: 0x48
        cGUIInstAnimation* job;  // offset: 0x50
        cGUIInstAnimation* cursor;  // offset: 0x58
        cGUIInstAnimation* msg_info;  // offset: 0x60
    };
public:
    struct stFreeGrpChatObj
    {
    public:
        cGUIObjMessage* msg_slct_name;  // offset: 0x0
        cGUIObjMessage* msg_slct_joblv;  // offset: 0x8
        cGUIObjMessage* msg_slct_lobby;  // offset: 0x10
        cGUIObjMessage* msg_slct_union;  // offset: 0x18
        cGUIObjMessage* msg_slct_party;  // offset: 0x20
        cGUIObjMessage* msg_num_m_num;  // offset: 0x28
        cGUIObjMessage* msg_num_txt;  // offset: 0x30
        cGUIObjMessage* msg_list_name;  // offset: 0x38
        cGUIObjMessage* msg_list_joblv;  // offset: 0x40
        cGUIObjMessage* msg_list_lobby;  // offset: 0x48
        cGUIObjMessage* msg_list_union;  // offset: 0x50
        cGUIObjMessage* msg_list_party;  // offset: 0x58
        cGUIObjMessage* msg_list_cmnt;  // offset: 0x60
        cGUIObjMessage* msg_nump_pager;  // offset: 0x68
        cGUIObjMessage* msg_btn_00;  // offset: 0x70
        cGUIObjMessage* msg_btn_01;  // offset: 0x78
        cGUIObjMessage* msg_guide_btn0;  // offset: 0x80
        cGUIObjMessage* msg_guide;  // offset: 0x88
        cGUIObjMessage* msg_info;  // offset: 0x90
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
    uGUIFreeGroupChat();
    virtual ~uGUIFreeGroupChat();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual s32 getSMenuCursorX();  // vtable slot 70
    virtual s32 getSMenuCursorY();  // vtable slot 72
    void setCurrentPos(s32);
    virtual void updatePtr();  // vtable slot 17
    void reqListUpdate();
private:
    void setupListInfo();
    void updateList();
    void setMemberInfo(const CDataCharacterListElement* pData, u32 dispIndex);
    virtual void updateInit();  // vtable slot 93
    void updateWait();
    void updateExit();
    void updateDisp();
    void changeDisp();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void evSMenuCancel();
    void evVMove();
    void evPageMove();
    void evHMove();
    void evSwitch();
    u32 evCtrlEnd(cControl::Message* msg);
    u32 evCtrlLClick(cControl::Message* msg);
    u32 evCtrlVMove(cControl::Message* msg);
    u32 evCtrlPageMove(cControl::Message* msg);
    u32 evCtrlHMove(cControl::Message* msg);
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlSwitch(cControl::Message* msg);
    u32 evCtrlBtnClick(cControl::Message* msg);
    u32 getDispMemberNum();
private:
    MtTypedArray<cPlInfo> mPlInfoArray;  // offset: 0x958
    u32 mProc;  // offset: 0x978
    rGUI* mpGUIRes;  // offset: 0x980
    cControl* mpCtrl;  // offset: 0x988
    uGUIBase::cVerticalList* mpVCtrl;  // offset: 0x990
    uGUIBase::cHorizontalList* mpHCtrl;  // offset: 0x998
    uGUIBase::cHorizontalList* mpPageCtrl;  // offset: 0x9a0
    stFreeGrpChatInst mGUIFreeGrpChatInst;  // offset: 0x9a8
    stFreeGrpChatObj mGUIFreeGrpChatObj;  // offset: 0xa10
    uGUIBase::cReferenceUIBtnGuide mBtnGuide;  // offset: 0xaa8
    uGUIBase::cReferenceUICloseBtn mCloseBtn;  // offset: 0xb40
    uGUIBase::cReferenceUINumPager mNumPager;  // offset: 0xb98
    uGUIBase::cReferenceUIIconJob mJobIcon;  // offset: 0xc40
    nDDOUtility::cArray<uGUIBase::cReferenceUIButton, 2> mBtn;  // offset: 0xc98
    uGUIBase::cReferenceUIVlCursor mSlctCursor;  // offset: 0xfc0
    s32 mCurrentPos;  // offset: 0x1070
    uGUICommunityList* mpCommList;  // offset: 0x1078
    bool mIsListComplete;  // offset: 0x1080
    u32 mDispMode;  // offset: 0x1084
public:
    static MyDTI DTI;
};

inline void* uGUIFreeGroupChat::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void uGUIFreeGroupChat::evSMenuCancel() {
    this->::uGUIBase::mpCurrentFunc = static_cast<void(uGUIBase::*)()>(&::uGUIFreeGroupChat::updateExit);
}

inline void* uGUIFreeGroupChat::cPlInfo::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void uGUIFreeGroupChat::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIFreeGroupChat::DTI)->memFree(p_addr);
}

inline void uGUIFreeGroupChat::cPlInfo::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIFreeGroupChat::cPlInfo::DTI)->memFree(p_addr);
}
