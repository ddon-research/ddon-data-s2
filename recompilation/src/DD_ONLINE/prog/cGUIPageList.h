#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cControl.h"
#include "cUIObject.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cGUIControlMgr;
class cGUIInstance;
class cGUIObject;
class uGUIBase;

// Declarations
class cGUIPageList;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class cGUIPageList : public cUIObject
{
public:
    enum FLAG
    {
        FLAG_INPUT_EVENT = 0,
        FLAG_VISIBLE = 1,
        FLAG_SMENU = 2,
    };
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
    cGUIPageList();
    virtual ~cGUIPageList();
    void setup(uGUIBase* owner, cGUIControlMgr* controlMgr, uGUIBase::cReferenceUIVlCursor* cursor, uGUIBase::cReferenceUINumPager* numPager);
    void setupControlList(u32 listControlMgrId, u32 categoryId, u32 listItemNum);
    void setupControlList(u32 listControlMgrId, u32 categoryId, u32 parentControlMgrId, s32 moveParentPos, u32 parentItemNum, u32 listItemNum);
    void setupControlPage(u32 pageControlMgrId, u32 categoryId, u32 pageNum);
    void setupControlPage(u32 pageControlMgrId, u32 categoryId, u32 parentControlMgrId, s32 moveParentPos, u32 parentItemNum, u32 listItemNum);
    virtual void update();  // vtable slot 6
    void setFlag(FLAG flag, bool isOn);
    bool isFlag(FLAG flag) const;
    virtual s32 getItemNum() const = 0;  // vtable slot 7
    virtual s32 getPageItemNum() const = 0;  // vtable slot 8
    s32 getItemIndex() const;
    s32 getPageNum() const;
    s32 getPageIndex() const;
    s32 getDispItemNum(s32 pageIndex) const;
    s32 getDispItemNum() const;
    s32 getDispItemIndex() const;
    virtual f32 getCursorPosY(s32 dispItemIndex) const;  // vtable slot 9
    virtual void getMouseCollision(cGUIInstance* & instance, cGUIObject* & object, s32 dispItemIndex) const;  // vtable slot 10
    void clearMouseTouchList();
    void updateMouseTouchList();
    bool moveEvent(u32 eventId);
    virtual u32 evCtrlMoveParent(cControl::Message* msg);  // vtable slot 11
    virtual u32 evCtrlMoveCursor(cControl::Message* msg);  // vtable slot 12
    virtual u32 evCtrlMovePage(cControl::Message* msg);  // vtable slot 13
    virtual u32 evCtrlMouseSelect(cControl::Message* msg);  // vtable slot 14
    virtual u32 evCtrlMouseDecide(cControl::Message* msg);  // vtable slot 15
    virtual bool evMoveParent(u32 eventId);  // vtable slot 16
    virtual bool evMoveCursor();  // vtable slot 17
    virtual bool evMoveCursorLoop();  // vtable slot 18
    virtual bool evMovePage();  // vtable slot 19
    s32 setItemIndex(s32 itemIndex);
    s32 setDispItemIndex(s32 dispItemIndex);
protected:
    virtual void callbackShowItem(s32, s32) = 0;  // vtable slot 20
    virtual void callbackHideItem(s32) = 0;  // vtable slot 21
protected:
    uGUIBase* mOwner;  // offset: 0x8
    cGUIControlMgr* mControlMgr;  // offset: 0x10
    uGUIBase::cReferenceUIVlCursor* mCursor;  // offset: 0x18
    uGUIBase::cReferenceUINumPager* mNumPager;  // offset: 0x20
    u32 mListControlMgrId;  // offset: 0x28
    u32 mParentControlMgrId;  // offset: 0x2c
    s32 mMoveParentPos;  // offset: 0x30
    u32 mPageControlMgrId;  // offset: 0x34
    s32 mItemIndex;  // offset: 0x38
    u32 mFlags;  // offset: 0x3c
    f32 mCursorDefaultY;  // offset: 0x40
public:
    static MyDTI DTI;
};
