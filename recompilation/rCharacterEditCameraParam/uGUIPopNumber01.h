#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../shared/MtDTI.h"
#include "../shared/cControl.h"
#include "../shared/nDDOUtility.h"
#include "../shared/uGUIBase.h"
#include "uGUIPopBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class cGUIObjMessage;
class rGUI;
class uGUIBase;

// Declarations
class uGUIPopNumber01;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUIPopNumber01 : public uGUIPopBase
{
public:
    enum END
    {
        END_NONE = 0,
        END_DECIDE = 1,
        END_CANCEL = 2,
    };
    enum FLOW_ID
    {
        FLOW_ID_INIT = 0,
        FLOW_ID_WAIT = 1,
        FLOW_ID_NUM_EDIT = 2,
        FLOW_ID_POP_DIALOG_WAIT = 3,
        FLOW_ID_EXIT = 4,
    };
    enum PN01_GUIDE_BIT
    {
        PN01_INP_NUM = 1,
        PN01_BIT_MAX = 1,
    };
    enum BUTTON_ID
    {
        BUTTON_DECIDE = 0,
        BUTTON_CANCEL = 1,
        BUTTON_NUM = 2,
    };
    enum V_POS
    {
        V_POS_NUMBOX = 0,
        V_POS_BUTTON = 1,
        V_POS_NUM = 2,
    };
    enum
    {
        INPUT_EVENT_MOVE = 66,
        INPUT_EVENT_DECIDE = 67,
        INPUT_EVENT_CANCEL = 68,
        INPUT_EVENT_DIRECT_NUM = 69,
        INPUT_EVENT_NUMDECIDE_LEFT = 70,
        INPUT_EVENT_NUMDECIDE_RIGHT = 71,
    };
public:
    class MyDTI;
    class cData;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cData
    {
    public:
        cGUIObjMessage* mpOBJ_msg_title_m_title;  // offset: 0x0
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
    uGUIPopNumber01();
    virtual ~uGUIPopNumber01();
    virtual bool loadResource();  // vtable slot 76
    virtual void updatePtr();  // vtable slot 17
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void reboot();  // vtable slot 98
    void setTitle(u32 str);
    bool isDecideEnd();
    void setMaxNum(s32 n);
    s32 getMaxNum();
    void setNum(s32 n);
    void setDefaultDecide(bool flag);
    s32 getNum();
    void setUnit(uGUIBase* pUnit);
    void setFlowId(FLOW_ID flowId);
protected:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
private:
    virtual void updateInit();  // vtable slot 93
    void updateWait();
    void updateNumEdit();
    void updatePopListDialog();
    void updateExit();
    void updateReferenceUI();
    void executeWindow();
    void _setFunc(uGUIBase* pUnit, uGUIPopBase::DATA_FUNC pFunc, MtObject* pParam);
    void setKeyControl();
    bool isDialog();
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlNumStartMenu(cControl::Message* msg);
    u32 evCtrlMove(cControl::Message* msg);
    u32 evCtrlNumDecide(cControl::Message* msg);
private:
    rGUI* mpGUIRes;  // offset: 0x988
    END mFlowEndType;  // offset: 0x990
    u32 mTitle;  // offset: 0x994
    nDDOUtility::cArray<uGUIBase::cReferenceUIButton, 2> mRefButtons;  // offset: 0x998
    uGUIBase::cReferenceUINumBox mRefNumBox;  // offset: 0xcb8
    uGUIBase::cReferenceUIBtnGuide mRefBtnGuide;  // offset: 0xdd0
    cData mData;  // offset: 0xe68
    s32 mNum;  // offset: 0xe70
    s32 mMaxNum;  // offset: 0xe74
    bool mIsDefaultDecide;  // offset: 0xe78
    uGUIBase::cVerticalList* mpCtrlV;  // offset: 0xe80
    uGUIBase::cHorizontalList* mpCtrlH;  // offset: 0xe88
    uGUIBase::cHorizontalList* mpCtrlHnumbox;  // offset: 0xe90
    uGUIPopBase::DATA_FUNC mpFunc;  // offset: 0xe98
    uGUIBase* mpFuncUnit;  // offset: 0xea8
    MtObject* mpFuncParam;  // offset: 0xeb0
    uGUIBase::cReferenceUIBtnGuide::stGuideBtnData mTblGuide[1];  // offset: 0xeb8
    uGUIBase* mpDialog;  // offset: 0xee0
public:
    static MyDTI DTI;
};
