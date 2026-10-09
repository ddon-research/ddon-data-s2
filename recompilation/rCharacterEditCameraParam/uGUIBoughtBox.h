#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/MtMath.h"
#include "../shared/cControl.h"
#include "../shared/sItemManager.h"
#include "../shared/uGUIBase.h"
#include "uGUIItem01.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtVector3;

// Declarations
class uGUIBoughtBox;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIBoughtBox : public uGUIItemBase01
{
public:
    enum ITM_GUIDE_BIT
    {
        ITM_CHECK = 1,
        ITM_CHECK_ALL = 2,
        ITM_CHECK_ALL_CLEAR = 4,
        ITM_BIT_MAX = 3,
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
    uGUIBoughtBox();
    virtual ~uGUIBoughtBox();
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void updateDetail();  // vtable slot 151
    virtual void updateExit();  // vtable slot 113
    virtual sItemManager::cItemBag::ITEM_CATEGORY getTab2Category();  // vtable slot 164
    void setDetailPos(const MtVector3& pos);
    virtual void setFlowId(u32 flowId);  // vtable slot 124
    virtual u32 evCtrlSubWindow(cControl::Message* msg);  // vtable slot 176
protected:
    virtual u32 getItemDrawNum();  // vtable slot 166
    virtual bool isExecuteDecide();  // vtable slot 153
    virtual void loadItem();  // vtable slot 139
    void updateItemList();
    virtual void setTitle();  // vtable slot 141
    virtual void setupGuideBtn();  // vtable slot 169
    virtual void setGuideBtn();  // vtable slot 170
    u32 evSendsBagFromPost(MtObject* pCaller, MtObject* pData);
    u32 evSendsBoxFromPost(MtObject* pCaller, MtObject* pData);
    u32 evSendsExFromPost(MtObject* pCaller, MtObject* pData);
    virtual u32 evCtrlDecide(cControl::Message* msg);  // vtable slot 179
    bool getBoughtBoxListRequestServer();
    void getBoughtBoxListCallBack();
    bool getBoughtBoxSortDataRequestServer();
    void getBoughtBoxSortDataCallBack();
    virtual bool subMenuItemSetting(MtObject* p);  // vtable slot 155
    virtual bool subMenuItemsSetting(MtObject* p);  // vtable slot 156
protected:
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[3];  // offset: 0xf98
private:
    bool mIsBoughtBoxListOk;  // offset: 0x1010
    bool mIsSetDetailPos;  // offset: 0x1011
    MtVector3 mDetailPos;  // offset: 0x1020
public:
    static MyDTI DTI;
};
