#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "nDDOUtility.h"
#include "uGUIBase.h"
#include "uGUIsMenuBase.h"

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
class cGUIObjNull;
class rGUI;
class rSoundRequest;
class uGUIBase;

// Declarations
class uGUIServerSelectBase;
class uGUIServerSelectSMENU;
class uGUIServerSelectSMENUserver;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIServerSelectBase : public uGUIsMenuBase
{
public:
    enum PTN
    {
        PTN_CLAN = 0,
        PTN_FRIEND = 1,
        PTN_MAX = 2,
    };
    enum RESULT_SERVER
    {
        RESULT_SERVER_NONE = 0,
        RESULT_SERVER_WAIT = 1,
        RESULT_SERVER_SUCCESS = 2,
        RESULT_SERVER_ERROR = 3,
    };
    enum SW
    {
        SW_server_select = 0,
        SW_roby_select = 1,
        SW_sleep = 2,
    };
    enum STR_DATA
    {
        STR_DATA_NAME = 0,
        STR_DATA_INFO = 1,
        STR_DATA_NUM = 2,
        STR_DATA_MAX = 3,
    };
    enum
    {
        INPUT_EVENT_TOP_BUTTON = 66,
    };
public:
    class MyDTI;
    struct DATA;
    class cScrollDistList;
    class cGUIMember;
    class cName;
    class cScrollInfoList;
public:
    using cStr = MtString;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct DATA
    {
    public:
        cGUIObjNull* mpOBJ_window_Null;  // offset: 0x0
        cGUIObjMessage* mpOBJ_msg_btn_m_btn;  // offset: 0x8
        cGUIObjMessage* mpOBJ_msg_btn_m_guide;  // offset: 0x10
        cGUIObjMessage* mpOBJ_msg_reward_m_reward;  // offset: 0x18
        cGUIObjMessage* mpOBJ_msg_login_m_num[3];  // offset: 0x20
        cGUIObjMessage* mpOBJ_msg_login_m_player;  // offset: 0x38
        cGUIObjMessage* mpOBJ_msg_fix_player_m_title;  // offset: 0x40
        cGUIObjMessage* mpOBJ_msg_top_m_top00;  // offset: 0x48
        cGUIObjMessage* mpOBJ_msg_top_m_top01;  // offset: 0x50
        s32 mVAR_param_spacing;  // offset: 0x58
    };
public:
    class cScrollDistList : public uGUIBase::cScrollListItemBase
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
        cScrollDistList();
        virtual ~cScrollDistList() {}
    public:
        cGUIInstNull* mpInstance;  // offset: 0x58
        cGUIInstAnimation* mpAnimInst;  // offset: 0x60
        cGUIObjMessage* mpMsgTitle;  // offset: 0x68
        cGUIObjMessage* mpMsgNum;  // offset: 0x70
        cGUIObjMessage* mpMsgInfo;  // offset: 0x78
        static MyDTI DTI;
    };
public:
    class cGUIMember : public MtObject
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
        cGUIMember();
        void setPatern(uGUIServerSelectBase::PTN ptn);
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x8
        cGUIInstAnimation* mpInstAnim;  // offset: 0x30
        cGUIObjMessage* mpMesTitle;  // offset: 0x38
        uGUIServerSelectBase::PTN mPatern;  // offset: 0x40
        static MyDTI DTI;
    };
public:
    class cName : public MtObject
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
        cName();
    public:
        nDDOUtility::cArray<MtString, 3> mNames;  // offset: 0x8
        u32 mIndex;  // offset: 0x20
        static MyDTI DTI;
    };
public:
    class cScrollInfoList : public uGUIBase::cScrollListInfoBase
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
        cScrollInfoList();
        cScrollInfoList(f32 Top, f32 Bottom, MT_CTSTR Name, MT_CTSTR Info, MT_CTSTR Num, u32 Index);
        virtual ~cScrollInfoList();
    public:
        nDDOUtility::cArray<MtString, 3> mNames;  // offset: 0x28
        u32 mIndex;  // offset: 0x40
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
    uGUIServerSelectBase();
    virtual ~uGUIServerSelectBase();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual bool changeFlow(u32 sw, bool force);  // vtable slot 91
    cName* addListName(MT_CTSTR str, MT_CTSTR info, u32 index, u32 nowNum, u32 maxNum);
    void setupArray();
    void clearArray();
    void setSleep(bool b);
    bool isSleep();
    void setWaitServer();
    void resetWaitServer();
    s32 getIndex();
    bool isDecide();
    bool isCancel();
    s32 getListStartY();
    s32 getSpacingY();
    void playServerSE();
    void playLobbySE();
    static void setServerResult(uGUIBase* pBase, RESULT_SERVER result);
    void setListInfo();
protected:
    virtual void updateInit();  // vtable slot 93
    virtual void updateWait();  // vtable slot 96
    virtual void updateExit();  // vtable slot 97
    void updateSleep();
    virtual void updateWaitServer();  // vtable slot 98
    void managedMember();
    void updateScrollListDisp(uGUIBase::cScrollListItemBase* pDispItem, uGUIBase::cScrollListInfoBase* pListItem, u32 Index);
    void updateScrollListHide(uGUIBase::cScrollListItemBase* pDispItem);
    u32 getServerId();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlTop(cControl::Message* msg);
    u32 evCtrlMouseOver(cControl::Message* msg);
    u32 evCtrlMouseLclick(cControl::Message* msg);
protected:
    DATA mData;  // offset: 0x958
    uGUIBase::cScrollList mList;  // offset: 0x9c0
    cScrollDistList mDispList[13];  // offset: 0xc70
    MtTypedArray<cGUIMember> mGUIMemberArray;  // offset: 0x12f0
    rGUI* mpGUIRes;  // offset: 0x1310
    cGUIInstNull* mpINST_Null;  // offset: 0x1318
    cGUIInstNull* mpINST_Null_info;  // offset: 0x1320
    cControl* mpCtrl;  // offset: 0x1328
    rSoundRequest* mpSE;  // offset: 0x1330
    uGUIBase::cReferenceUINumPager mRefNumPager;  // offset: 0x1338
    uGUIBase::cReferenceUIBtnGuide mRefBtnGuideMain;  // offset: 0x13e0
    uGUIBase::cReferenceUIBtnGuide mRefBtnGuideSub;  // offset: 0x1478
    uGUIBase::cReferenceUICloseBtn mCloseButton;  // offset: 0x1510
    MtTypedArray<cName> mNameArray;  // offset: 0x1568
    u32 mSelectServerNo;  // offset: 0x1588
    bool mSleep;  // offset: 0x158c
    bool mIsDecide;  // offset: 0x158d
    bool mIsCancel;  // offset: 0x158e
    bool mIsUpdate;  // offset: 0x158f
    MtString mServerName;  // offset: 0x1590
    f32 mTimer;  // offset: 0x1598
    RESULT_SERVER mServerResult;  // offset: 0x159c
    s32 mListPos;  // offset: 0x15a0
    bool mIsChangeWait;  // offset: 0x15a4
public:
    static MyDTI DTI;
protected:
    static const u32 DISP_LIST_NUM = 11;
    static const u32 LIST_MAX = 13;
};

class uGUIServerSelectSMENU : public uGUIServerSelectBase
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
    virtual void setup();  // vtable slot 6
    virtual s32 getSMenuCursorX();  // vtable slot 70
    virtual s32 getSMenuCursorY();  // vtable slot 72
public:
    static MyDTI DTI;
};

class uGUIServerSelectSMENUserver : public uGUIServerSelectSMENU
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
    uGUIServerSelectSMENUserver();
    virtual void updateInit();  // vtable slot 93
    virtual void updateWait();  // vtable slot 96
public:
    static MyDTI DTI;
};

inline void* uGUIServerSelectBase::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIServerSelectBase::cScrollDistList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIServerSelectBase::cScrollDistList::cScrollDistList() {
    this->mpMsgInfo = nullptr;
    this->mpMsgNum = nullptr;
    this->mpMsgTitle = nullptr;
    this->mpAnimInst = nullptr;
    this->mpInstance = nullptr;
}

inline void* uGUIServerSelectBase::cGUIMember::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIServerSelectBase::cName::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUIServerSelectBase::cName::cName() {
    this->mIndex = 0;
}

inline void* uGUIServerSelectBase::cScrollInfoList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIServerSelectSMENU::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUIServerSelectSMENUserver::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

// Included after the classes: the generic bodies below need these complete.
#include "../../MT/MtAllocator.h"
#include "../../MT/MtMemoryAllocator.h"

inline void uGUIServerSelectBase::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIServerSelectBase::DTI)->memFree(p_addr);
}

inline s32 uGUIServerSelectBase::getIndex() {
    if (this->mList.mpVCtrl != nullptr) {
        return this->mList.mpVCtrl->::cControl::mCurrentPos;
    } else {
        return 0;
    }
}

inline void* uGUIServerSelectBase::cScrollDistList::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIServerSelectBase::cScrollDistList::DTI)->memAlloc(sz, align, ::uGUIServerSelectBase::cScrollDistList::DTI.::MtDTI::getID());
}

inline void uGUIServerSelectBase::cScrollDistList::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIServerSelectBase::cScrollDistList::DTI)->memFree(p_addr);
}

inline void uGUIServerSelectBase::cGUIMember::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIServerSelectBase::cGUIMember::DTI)->memFree(p_addr);
}

inline void* uGUIServerSelectBase::cName::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIServerSelectBase::cName::DTI)->memAlloc(sz, align, ::uGUIServerSelectBase::cName::DTI.::MtDTI::getID());
}

inline void* uGUIServerSelectSMENU::operator new(size_t sz, u32 align) {
    return ::MtMemoryAllocator::getAllocator(::uGUIServerSelectSMENU::DTI)->memAlloc(sz, align, ::uGUIServerSelectSMENU::DTI.::MtDTI::getID());
}

inline void uGUIServerSelectSMENU::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIServerSelectSMENU::DTI)->memFree(p_addr);
}

inline void uGUIServerSelectSMENUserver::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::uGUIServerSelectSMENUserver::DTI)->memFree(p_addr);
}
