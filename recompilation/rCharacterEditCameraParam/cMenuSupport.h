#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtObject.h"
#include "../shared/nGUIExt.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cMenuBase;
class cMenuCharacterList;
class cMenuQuickMatchCancel;
class cMenuQuickMatchRetry;
namespace nMenu { struct MENU_PARTS; }
class rSoundRequest;
class uGUISystemMsg;

// Declarations
class cMenuDialogFlow;
class cMenuSupport;
class cMenuSupportList;
class cMenuSupportMenu;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cMenuSupport : public MtObject
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
    cMenuSupport();
    // Address: 0x0197b310 - 0x0197b311 (1 bytes)
    virtual ~cMenuSupport() {}
    // Address: 0x0197b270 - 0x0197b271 (1 bytes)
    virtual void updatePtr() {}  // vtable slot 6
    void setParent(cMenuBase* pParentMenu);
protected:
    cMenuBase* mpParentMenu;  // offset: 0x8
public:
    static MyDTI DTI;
};

class cMenuSupportMenu : public cMenuSupport
{
    // inferred: cMenuBase::setListCursor names cMenuSupportMenu::mListCursor
    friend class cMenuBase;
    // inferred: cMenuQuickMatchCancel::moveQuickMatchCancel names cMenuSupportMenu::mMenuNum
    friend class cMenuQuickMatchCancel;
    // inferred: cMenuQuickMatchRetry::moveQuickMatchRetry names cMenuSupportMenu::mMenuNum
    friend class cMenuQuickMatchRetry;
    // inferred: cMenuSupportList::releaseList names cMenuSupportMenu::mpMenuParts
    friend class cMenuSupportList;
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
    cMenuSupportMenu();
    virtual ~cMenuSupportMenu();
    void initialize(u32 menuMax);
    void updateMenu();
    void moveMenu(s32 cursorOrderId);
    u32 getMenuNum();
    s32 getCursor();
    void setCursor(s32 cursor);
    void clearMenuList();
    void createMenuList();
    void createMenuListSimple();
    void createMenuListTbl(const s32* pTbl, u32 menuNum);
    void addMenuList(s32 menuId);
    void convertMenuId(s32 from, s32 to);
    bool isAutoUpdate();
    void setAutoUpdate(bool isUpdate);
    s32 getIndexFromMenuId(s32 menuId);
    const nMenu::MENU_PARTS& getMenuParts(s32 index);
    s32 getMenuId(s32 index);
private:
    void checkMenuPartsParam();
protected:
    void releaseList();
private:
    nMenu::MENU_PARTS* mpMenuParts;  // offset: 0x10
    bool mAutoUpdateMenu;  // offset: 0x18
protected:
    u32 mMenuMax;  // offset: 0x1c
    s32* mpMenuList;  // offset: 0x20
    u32 mMenuNum;  // offset: 0x28
    s32 mListCursor;  // offset: 0x2c
public:
    static MyDTI DTI;
};

class cMenuDialogFlow : public cMenuSupport
{
public:
    enum RET
    {
        RET_DLG_SET_DLG = 0,
        RET_DLG_CHOICE = 1,
        RET_DLG_SET_RESULT = 2,
        RET_DLG_EXIT = 3,
        RET_DLG_ERROR = 4,
        RET_DLG_CONTINUE = 5,
        RET_DLG_NULL = 6,
    };
    enum
    {
        ATTR_NONE = 0,
        ATTR_COM_WAIT = 1,
        ATTR_RESULT = 2,
        ATTR_ERROR_RET = 4,
        ATTR_TAG_OFF = 8,
    };
    enum
    {
        RNO_INIT = 0,
        RNO_SELECT = 1,
        RNO_WAIT = 2,
        RNO_RESULT = 3,
        RNO_ERROR = 4,
        RNO_END = 5,
    };
public:
    class MyDTI;
public:
    using CloseCallBack = bool(cMenuBase::*)();
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
    cMenuDialogFlow();
    virtual ~cMenuDialogFlow();
    virtual void updatePtr();  // vtable slot 6
    void initialize(u32 attr);
    void setDialog(nGUIExt::REQ_DIALOG_TYPE dialogType, MT_CTSTR mainMsg, s32 defPos, MT_CTSTR choice1, MT_CTSTR choice2, MT_CTSTR choice3, MT_CTSTR choice4, bool isCancelOff);
    void setDialogNoCancel(nGUIExt::REQ_DIALOG_TYPE dialogType, MT_CTSTR mainMsg, s32 defPos, MT_CTSTR choice1, MT_CTSTR choice2, MT_CTSTR choice3, MT_CTSTR choice4);
    void setMsgAnalyzerWork(u32 uIdx, MT_CTSTR pAnalyzeMsg);
    void setMsgAnalyzerWork(u32 uIdx, s32 sAnalyzeNum);
    void setChoiceEnable(u32 idx, bool isEnable, s32 sPage);
    void setChoiceErrorMsg(u32 idx, MT_CTSTR pErrorMsg, s32 sPage);
    void setComWait(s32 comId);
    RET moveFlow();
    void pushFlow();
    void retryFlow(s32 dialogId);
    s32 getDialogId();
    s32 getChoicePos();
    void setCloseCallback(CloseCallBack pFunc);
    void setDialogId(s32 id);
    void setDialogSE(u32 reason, u32 seId, rSoundRequest* pRes);
    u32 getNextBasePointerPriority();
private:
    bool isComWait();
    bool isResult();
    bool isErrorRet();
    void setEnd();
private:
    CloseCallBack mpCloseCallBack;  // offset: 0x10
    u32 mRno;  // offset: 0x20
    u32 mAttr;  // offset: 0x24
    s32 mDialogId;  // offset: 0x28
    s32 mChoice;  // offset: 0x2c
    s32 mComId;  // offset: 0x30
    u32 mNextPointerPriority;  // offset: 0x34
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0x38
public:
    static MyDTI DTI;
};

class cMenuSupportList : public cMenuSupportMenu
{
    // inferred: cMenuCharacterList::initCharacterList names cMenuSupportList::mMenuTopId
    friend class cMenuCharacterList;
public:
    enum ADD_TYPE
    {
        ADD_TYPE_NONE = 0,
        ADD_TYPE_ABOVE = 1,
        ADD_TYPE_BELOW = 2,
    };
public:
    class MyDTI;
    struct stAddMenu;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    struct stAddMenu
    {
    public:
        s32 mMenuId;  // offset: 0x0
        cMenuSupportList::ADD_TYPE mAddType;  // offset: 0x4
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
    cMenuSupportList();
    virtual ~cMenuSupportList();
    void initialize(u32 listMax, u32 pageElemMax, u32 pageMenuMax);
    void moveList(u32 listNum);
    void createList(u32 listNum);
    void createMenuList();
    bool isCursorInList(s32 cursor);
    u32 getListIdInPage(s32 cursor);
    u32 getSortListIndex(u32 menuNo, u32 pageNo);
    s32 getBaseListIndex(u32 sortListIndex);
    s32 getBaseListIndexFromCursor(s32 cursor);
    s32 getBaseListIndexFromMenuId(s32 menuId);
    s32 getBaseListIndexNow();
    u32 getSortListCount();
    u32 getPageNum();
    u32 getDispMax();
    s32 getPageNo();
    bool getRemakeListFlag();
    void resetRemakeListFlag();
    void reqRemake();
    void setMenuTopId(s32 menuId);
    void addAboveMenu(s32 menuId);
    void addBelowMenu(s32 menuId);
    void clearAddMenu();
private:
    void releaseList();
    stAddMenu* getEmptyAddMenu();
    void addMenu(ADD_TYPE addType, s32 menuId);
    void setAddMenu(ADD_TYPE addType);
private:
    s32* mpSortList;  // offset: 0x30
    stAddMenu* mpAddMenu;  // offset: 0x38
    u32 mListMax;  // offset: 0x40
    u32 mPageElemMax;  // offset: 0x44
    u32 mAddMenuNum;  // offset: 0x48
    s32 mMenuTopId;  // offset: 0x4c
    u32 mListNum;  // offset: 0x50
    u32 mSortListCount;  // offset: 0x54
    s32 mPageNo;  // offset: 0x58
    bool mIsRemakeList;  // offset: 0x5c
    bool mReqRemake;  // offset: 0x5d
public:
    static MyDTI DTI;
};

// Inline, no code of its own: checked where it is inlined.
inline cMenuSupport::cMenuSupport() {
    this->mpParentMenu = static_cast<cMenuBase*>(nullptr);
}

// Inline, no code of its own: checked where it is inlined.
inline s32 cMenuSupportMenu::getCursor() {
    return this->mListCursor;
}
