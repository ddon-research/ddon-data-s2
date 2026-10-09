#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Error.h"
#include "MtCollection.h"
#include "MtColor.h"
#include "MtDTI.h"
#include "MtMath.h"
#include "MtObject.h"
#include "MtPrimitive2D.h"
#include "MtString.h"
#include "MtSynchronize.h"
#include "cControl.h"
#include "cGUIInstance.h"
#include "cInputTextKeyboardHook.h"
#include "cUIObject.h"
#include "nDDOUtility.h"
#include "nGUIExt.h"
#include "nHuman.h"
#include "nKeyCustom.h"
#include "nQuest.h"
#include "rItemList.h"
#include "sCamera.h"
#include "sItemManager.h"
#include "uGUI.h"

// Forward declarations
class CDataClanParam;
class MtAllocator;
class MtColor;
class MtCriticalSection;
class MtDTI;
struct MtFloat2;
class MtObject;
class MtRect;
class MtSize;
class MtSizeF;
class MtString;
class MtVector2;
class MtVector3;
class MtVector4;
class aStage;
class cArcLoaderBase;
class cContextInstHm;
class cControl;
class cCycleQuestManagerBase;
class cDraw;
class cGUIInstAnimControl;
class cGUIInstAnimVariable;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIInstance;
class cGUIObj2D;
class cGUIObjChildAnimationRoot;
class cGUIObjColorAdjust;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class cGUIObjTexture;
class cGUIObjTextureRef;
class cGUIObjTextureSet;
class cGUIObject;
class cGUIVariable;
class cInputTextKeyboardHook;
class cItemParam;
class cMenuCancelClanScoutEntry;
class cMenuLeaveGroupChat;
class cResource;
namespace nGUI { struct FLOW; }
namespace nGUIExt { struct stMsgAnalyzerWork; }
namespace nGUIExt { struct stWindowActive; }
namespace nGUIItem { class cItem; }
namespace nInputTextKeyboardHook { struct Keycode; }
namespace nJobParam { class cJobInfo; }
namespace nNet { struct stClanEmblem; }
namespace nQuest { class cQuestMarker; }
class rEmblemColorTable;
class rGUI;
class rGUIFont;
class rGUIMessage;
class rSoundRequest;
class rTexture;
class sGUIExt;
class uGUIAreaMaster;
class uGUIBoughtBox;
class uGUIBoxGachaInfo;
class uGUIBrowserBG;
class uGUICaplinkFriendList;
class uGUICaplinkMenuBase;
class uGUICaplinkTalk;
class uGUIGPShop;
class uGUIGiveAndTake;
class uGUIInfo;
class uGUIItemBase01;
class uGUIKeyConfig;
class uGUIMenuAreaInfo;
class uGUIMenuComm;
class uGUIMenuTutorial;
class uGUIMyRoom;
class uGUINewspaper;
class uGUIPopCmd01;
class uGUIPopNumber01;
class uGUIQuestList;
class uGUISystemMsg;
class uUIMockUp;

// Declarations
class uGUIBase;

// Type aliases from DWARF
using u32 = unsigned int;
using ARC_SEARCHID = u32;
using ARC_TAGID = u32;
using CClanParam = CDataClanParam;
using __uint64_t = long unsigned int;
using u64 = __uint64_t;
using JOBHANDLE = u64;
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using time_t = long int;
using t64 = time_t;
using u16 = unsigned short;
using u8 = unsigned char;

class uGUIBase : public uGUI
{
    // inferred: aStage::isEndCreditGUI names uGUIBase::mResult
    friend class aStage;
    // inferred: cCycleQuestManagerBase::drawResult names uGUIBase::mResult
    friend class cCycleQuestManagerBase;
    // inferred: cMenuCancelClanScoutEntry::moveCancelClanScoutEntry names uGUIBase::mResult
    friend class cMenuCancelClanScoutEntry;
    // inferred: cMenuLeaveGroupChat::moveLeaveGroupChat names uGUIBase::mBasePointerPrio
    friend class cMenuLeaveGroupChat;
    // inferred: sGUIExt::isTelopFSMEnd names uGUIBase::mResult
    friend class sGUIExt;
    // inferred: uGUIAreaMaster::setupWindowActive names uGUIBase::mIsWindowActive
    friend class uGUIAreaMaster;
    // inferred: uGUIBoughtBox::setTitle names uGUIBase::mpGUIMsgs.elems[0]
    friend class uGUIBoughtBox;
    // inferred: uGUIBoxGachaInfo::kill names uGUIBase::mEndType
    friend class uGUIBoxGachaInfo;
    // inferred: uGUIBrowserBG::sleep names uGUIBase::mIsActiveBarForceDispOff
    friend class uGUIBrowserBG;
    // inferred: uGUICaplinkFriendList::initRequestSubMenu names uGUIBase::mpGUIMsgs.elems[0]
    friend class uGUICaplinkFriendList;
    // inferred: uGUICaplinkMenuBase::updateProf names uGUIBase::mResult
    friend class uGUICaplinkMenuBase;
    // inferred: uGUICaplinkTalk::evCtrlDecide names uGUIBase::mpGUIMsgs.elems[0]
    friend class uGUICaplinkTalk;
    // inferred: uGUIGPShop::kill names uGUIBase::mEndType
    friend class uGUIGPShop;
    // inferred: uGUIItemBase01::updateOnlineShopWait names uGUIBase::mResult
    friend class uGUIItemBase01;
    // inferred: uGUIKeyConfig::getResMsgGroup names uGUIBase::mpGUIMsgs.elems[1]
    friend class uGUIKeyConfig;
    // inferred: uGUIMenuAreaInfo::setupSectionMessage names uGUIBase::mpGUIMsgs.elems[0]
    friend class uGUIMenuAreaInfo;
    // inferred: uGUIMenuTutorial::updateWaitDirectOpen names uGUIBase::mResult
    friend class uGUIMenuTutorial;
    // inferred: uGUINewspaper::initRankingActiveControl names uGUIBase::mBasePointerPrio
    friend class uGUINewspaper;
    // inferred: uGUIPopCmd01::addItemSystemMenu names uGUIBase::mpGUIMsgs.elems[1]
    friend class uGUIPopCmd01;
    // inferred: uGUISystemMsg::updateStop names uGUIBase::mIsWindowActive
    friend class uGUISystemMsg;
public:
    enum GUI_RESULT
    {
        RESULT_NONE = 0,
        RESULT_EXIT = 1,
        RESULT_BASEEND = 2,
    };
    enum END_REASON
    {
        END_REASON_DEFAULT = 0,
        END_REASON_CANCEL_BTN = 1,
        END_REASON_START_BTN = 2,
        END_REASON_CLOSE_BTN = 3,
    };
    enum ENDTYPE
    {
        ENDTYPE_KILL = 0,
        ENDTYPE_EXIT = 1,
    };
    enum
    {
        INPUTEVENT_NONE = 0,
        INPUTEVENT_DUMMY = 1,
        INPUTEVENT_NOT_SELECT = 2,
        INPUTEVENT_CLICK_NOT_SELECT = 3,
        INPUTEVENT_SMENU_DECIDE = 4,
        INPUTEVENT_SMENU_CANCEL = 5,
        INPUTEVENT_SMENU_CHKOUT = 6,
        INPUTEVENT_SMENU_TOPBTN = 7,
        INPUTEVENT_SMENU_CANCEL_DECIDE = 8,
        INPUTEVENT_SCROLLLIST_UP = 9,
        INPUTEVENT_SCROLLLIST_DOWN = 10,
        INPUTEVENT_SCROLLLIST_LEFT = 11,
        INPUTEVENT_SCROLLLIST_RIGHT = 12,
        INPUTEVENT_SCROLLLIST_MOUSE_SELECT = 13,
        INPUTEVENT_SCROLLLIST_MOUSE_DECIDE = 14,
        INPUTEVENT_SCROLLLIST_DECIDE_OUTSIDE = 15,
        INPUTEVENT_CONTROLMGR_CANCEL = 16,
        INPUTEVENT_CONTROLMGR_START_BTN = 17,
        INPUTEVENT_CONTROLMGR_DECIDE = 18,
        INPUTEVENT_CONTROLMGR_TAB_MOVE = 19,
        INPUTEVENT_CONTROLMGR_VLIST_MOVE = 20,
        INPUTEVENT_CONTROLMGR_HLIST_MOVE = 21,
        INPUTEVENT_NUMBOX_UP = 22,
        INPUTEVENT_NUMBOX_DOWN = 23,
        INPUTEVENT_NUMBOX_LEFT = 24,
        INPUTEVENT_NUMBOX_RIGHT = 25,
        INPUTEVENT_NUMBOX_DECIDE = 26,
        INPUTEVENT_NUMBOX_CANCEL = 27,
        INPUTEVENT_NUMBOX_MOVE = 28,
        INPUTEVENT_NUMBOX_LCLICK_OOMT = 29,
        INPUTEVENT_NUMBOX_MOUSE_WHEEL_FORWARD = 30,
        INPUTEVENT_NUMBOX_MOUSE_WHEEL_BACK = 31,
        INPUTEVENT_NUMBOX_KEY_NUMBER_0 = 32,
        INPUTEVENT_NUMBOX_KEY_NUMBER_1 = 33,
        INPUTEVENT_NUMBOX_KEY_NUMBER_2 = 34,
        INPUTEVENT_NUMBOX_KEY_NUMBER_3 = 35,
        INPUTEVENT_NUMBOX_KEY_NUMBER_4 = 36,
        INPUTEVENT_NUMBOX_KEY_NUMBER_5 = 37,
        INPUTEVENT_NUMBOX_KEY_NUMBER_6 = 38,
        INPUTEVENT_NUMBOX_KEY_NUMBER_7 = 39,
        INPUTEVENT_NUMBOX_KEY_NUMBER_8 = 40,
        INPUTEVENT_NUMBOX_KEY_NUMBER_9 = 41,
        INPUTEVENT_NUMBOX_KEY_BACKSPACE = 42,
        INPUTEVENT_NUMBOX_KEY_DELETE = 43,
        INPUTEVENT_PULLDOWN_MOVE = 44,
        INPUTEVENT_PULLDOWN_CANCEL = 45,
        INPUTEVENT_PULLDOWN_DECIDE = 46,
        INPUTEVENT_PULLDOWN_MOUSE_OUT = 47,
        INPUTEVENT_PULLDOWN_MOUSE_OVER = 48,
        INPUTEVENT_PULLDOWN_MOUSE_SELECT = 49,
        INPUTEVENT_PULLDOWN_MOUSE_DECIDE = 50,
        INPUTEVENT_PULLDOWN_LCLICK_OOMT = 51,
        INPUTEVENT_NUMPAGER_CLICK_L = 52,
        INPUTEVENT_NUMPAGER_CLICK_R = 53,
        INPUTEVENT_TEXTBOX_DECIDE = 54,
        INPUTEVENT_TEXTBOX_CANCEL = 55,
        INPUTEVENT_CHECKLIST_DECIDE = 56,
        INPUTEVENT_CHECKLIST_CANCEL = 57,
        INPUTEVENT_PAGELIST_MOVE_PARENT_UP = 58,
        INPUTEVENT_PAGELIST_MOVE_PARENT_DOWN = 59,
        INPUTEVENT_PAGELIST_MOVE_PARENT_LCLICK = 60,
        INPUTEVENT_PAGELIST_MOVE_CURSOR = 61,
        INPUTEVENT_PAGELIST_MOVE_CURSOR_LOOP = 62,
        INPUTEVENT_PAGELIST_MOVE_PAGE = 63,
        INPUTEVENT_PAGELIST_MOUSE_SELECT = 64,
        INPUTEVENT_PAGELIST_MOUSE_DECIDE = 65,
        INPUTEVENT_START = 66,
    };
    enum
    {
        GUI_ARC_MAIN = 0,
        GUI_ARC_SUB_1 = 1,
        GUI_ARC_SUB_2 = 2,
        GUI_ARC_MENU_CMN = 3,
        GUI_ARC_ITEM_INFO = 4,
        GUI_ARC_MAX = 5,
    };
    enum
    {
        SERVERRNO_INIT = 0,
        SERVERRNO_WAIT = 1,
        SERVERRNO_ERROR = 2,
    };
    enum
    {
        SERVER_RESULT_NONE = 0,
        SERVER_RESULT_SUCCESS = 1,
        SERVER_RESULT_ERROR = 2,
    };
    enum
    {
        WINDOWACTIVE_INIT_NOACTIVE = 0,
        WINDOWACTIVE_INIT_FORCEON = 1,
        WINDOWACTIVE_INIT_NUM = 2,
    };
    enum BASE_FLAG
    {
        BASEF_NONE = 0,
        BASEF_PAUSE = 1,
        BASEF_NOLOAD = 2,
        BASEF_CLOSEBTNEND = 4,
        BASEF_CANCELEND = 4,
        BASEF_STARTEND = 8,
        BASEF_AAM = 16,
        BASEF_HUD = 32,
        BASEF_WINDOW = 64,
        BASEF_OFFMOVE = 128,
        BASEF_CB_ENDWAIT = 256,
        BASEF_PS4_SHARE_NG = 512,
        BASEF_USE_MENU_CMN = 1024,
        BASEF_USE_ITEM_INFO = 2048,
        BASEF_CTRL_EXECCHAT = 4096,
        BASEF_CTRL_EXECERROR = 8192,
        FORCE_DWORD = -1,
    };
    enum
    {
        NINESAL_LT = 0,
        NINESAL_LC = 1,
        NINESAL_LB = 2,
        NINESAL_CT = 3,
        NINESAL_CC = 4,
        NINESAL_CB = 5,
        NINESAL_RT = 6,
        NINESAL_RC = 7,
        NINESAL_RB = 8,
        NINESAL_NUM = 9,
    };
    enum
    {
        NINESF_NONE = 0,
        NONESF_NW = 1,
        NONESF_NH = 2,
    };
    enum
    {
        GENDERTYPE_NONE = 0,
        GENDERTYPE_MTOM = 1,
        GENDERTYPE_MTOF = 2,
        GENDERTYPE_FTOM = 3,
        GENDERTYPE_FTOF = 4,
        GENDERTYPE_PTOM = 5,
        GENDERTYPE_PTOF = 6,
        GENDERTYPE_MTOP = 7,
        GENDERTYPE_FTOP = 8,
        GENDERTYPE_MAX = 9,
    };
public:
    template <typename T> class cDupliInstance;
    template <unsigned int _size> class cExGUIMessageObj;
    class MyDTI;
    class cReferenceUIBase;
    class cSupportInstAnim;
    class cSupportBase;
    class cReferenceUITextBox;
    class cAdjustableWindow;
    class cReferenceUIWndwDrag;
    class cDuplicateData;
    class cVarData;
    class cKeepInScreen;
    class InputTextKeyboardHook;
    class cReferenceUIIconJob;
    class cScrollListItemBase;
    class cScrollListInfoBase;
    class cReferenceUIPullDown;
    class cReferenceUIVlCursor;
    class cScrollList;
    class cScrollCtrl;
    class cReferenceUIScrollBar;
    class cCalcMovePos;
    class cVerticalList;
    class cReferenceUICloseBtn;
    class cReferenceUIIconQuest;
    class cReferenceUIButton;
    class cMsgAnalyzer;
    class cHorizontalList;
    class cReferenceUITab;
    class cInputGuideMonitor;
    class cReferenceUIBtnGuide;
    class cReferenceUITooltip;
    class cMatrix;
    class cMaskScroll;
    class cValueList;
    class cInterpolationValue;
    class cUnitWatcher;
    class cTexRefJpegDownloader;
    class cImageDownloader;
    class cReferenceUISlider;
    class cReferenceUIDropIcon;
    class cReferenceUICursor;
    class cReferenceUISelector;
    class cReferenceUIGoldRim;
    class cReferenceUIChargesInfo;
    class cReferenceUIIconItem;
    class cReferenceUIIconEquip;
    class cReferenceUIIconItemCharges;
    class cReferenceUIIconSkill;
    class cReferenceUIIconStatus;
    class cReferenceUIIconCraftLv;
    class cReferenceUIIconStorage;
    class cReferenceUIIconShake;
    class cReferenceUIIconSCM;
    class cReferenceUIIconGameMenu;
    class cReferenceUIIconComm;
    class cReferenceUIIconOnlineStatus;
    class cReferenceUIIconClanTitle;
    class cReferenceUIGammaBoard;
    class cReferenceUICheckbox;
    class cReferenceUIButton2;
    class cReferenceUIToggleBtn;
    class cReferenceUIPullDownSkill;
    class cReferenceUISimpleBtn;
    class cReferenceUIEditBtn;
    class cReferenceUICheckList;
    class cReferenceUICheckListForClan;
    class cReferenceUIClanEmblem;
    class cTexRefArcLoader;
    class cArcLoader;
    class cReferenceUINumBox;
    class cReferenceUIPageDot;
    class cReferenceUIRadioButton;
    class cReferenceUINumPager;
    class cReferenceUIIconButton;
    class cReferenceUIEditSlider;
    class cReferenceUIIconFriend;
    class cScreenAdjustPos;
    class cTextSlider;
    class cTexArcLoader;
    class cQuestTexLoader;
    class cClanPolicyMessages;
public:
    using cDuplicateDataArray = nDDOUtility::cNoObjectArray<uGUIBase::cDuplicateData>;
    using cVarDataArray = nDDOUtility::cNoObjectArray<uGUIBase::cVarData>;
    using cGUIInstAnimVariableArray = nDDOUtility::cNoObjectArray<cGUIInstAnimVariable>;
    using ServerRequestFunc = bool(uGUIBase::*)();
    using ServerSuccessCallBack = void(uGUIBase::*)();
    using ServerFailedCallBack = void(uGUIBase::*)(nError::ERROR_CODE);
    using cDupliInstNull = uGUIBase::cDupliInstance<cGUIInstNull*>;
    using cExGUIMessageObj64 = uGUIBase::cExGUIMessageObj<64>;
    using cDupliInstAnim = uGUIBase::cDupliInstance<cGUIInstAnimation*>;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cSupportBase : public MtObject
    {
        // inferred: uGUIBase::moveTextBox names uGUIBase::cSupportBase::mpUnit
        friend class uGUIBase;
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
        cSupportBase();
        // Address: 0x01aded80 - 0x01aded81 (1 bytes)
        virtual ~cSupportBase() {}
        cGUIInstance* ManageDuplicateAuto(cGUIInstance* pInst);
        void setParentUnit(uGUIBase* pUnit);
        void setAutoClear(bool b);
        bool getAutoClear();
        uGUIBase* getParentUnit();
        void setObjectMessage(cGUIObject* pObj, MT_CTSTR msg, u32 uGenderType, bool bAutoWrap);
        void setObjectMessageFromId(u32 instID, u32 objID, MT_CTSTR msg, u32 uGenderType, bool bAutoWrap);
        void setObjectMessageFromId(cGUIInstance* pInst, u32 objID, MT_CTSTR msg, u32 uGenderType, bool bAutoWrap);
        void setMsgAnalyzerWork(u32, MT_CTSTR);
        void setMsgAnalyzerWork(u32, s32);
    protected:
        cGUIObject* getObjectFromId(cGUIInstance* pInst, u32 objID);
        cGUIObject* getObjectFromId(u32, u32);
        void setInstanceVisible(cGUIInstance* pInst, bool visible);
        void setObjectMessageColor(cGUIObject* pObj, MT_CTSTR msg, const MtColor color, u32 uGenderType, bool bAutoWrap);
        void setSequenceId(cGUIInstAnimation* pInstAnim, u32 uSeqId, bool bReset);
    protected:
        bool mAutoClear;  // offset: 0x8
        uGUIBase* mpUnit;  // offset: 0x10
    public:
        static MyDTI DTI;
    };
public:
    class cAdjustableWindow : public uGUIBase::cSupportBase
    {
    public:
        enum CELL
        {
            CELL_LT = 0,
            CELL_LC = 1,
            CELL_LB = 2,
            CELL_CT = 3,
            CELL_CC = 4,
            CELL_CB = 5,
            CELL_RT = 6,
            CELL_RC = 7,
            CELL_RB = 8,
            CELL_MAX = 9,
        };
    public:
        class MyDTI;
        struct stGradation;
        struct stOption;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct stGradation
        {
        public:
            stGradation();
            void applySize();
        public:
            cGUIObjPolygon* mpObj;  // offset: 0x0
            MtSizeF mSize;  // offset: 0x8
        };
    public:
        struct stOption
        {
        public:
            stOption();
        public:
            bool changeWidth;  // offset: 0x0
            bool changeHeight;  // offset: 0x1
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
        cAdjustableWindow();
        // Address: 0x01adb910 - 0x01adb911 (1 bytes)
        virtual ~cAdjustableWindow() {}
        void setup(uGUIBase* pUnit, cGUIInstance* pInst, u32 LT, u32 LC, u32 LB, u32 CT, u32 CC, u32 CB, u32 RT, u32 RC, u32 RB);
        void setupGradation(uGUIBase* pUnit, cGUIInstance* pInst, u32 topId, u32 bottomId);
        void initWindowData(CELL);
        void setWindowSize(CELL align, MtSize size, const MtFloat2& ofs, CELL ctrlpt);
        void setWindowSizeDefaultPlus(CELL align, const MtSize& size, const MtFloat2& ofs, CELL ctrlpt);
        MtSize getWindowSize() const;
        MtSize getCenterSize() const;
        MtSize getDefaultCenterSize() const;
        void setDefaultCenterSize(const MtSize& size);
        void addDefaultCenterSize(const MtSize&);
        MtSize getDefaultWindowSize() const;
        s32 getSizeY() const;
        cGUIObjPolygon* getObj(CELL cell);
        void setOption(const stOption&);
        void setFrame(f32 frame, bool changeFixFrame);
        void setVisible(bool isVisible);
        MtSizeF getSize(CELL cell) const;
        MtVector4 getPos(CELL cell) const;
        cGUIInstance* getInstance();
    private:
        void _setWindowData(CELL align, MtSize& size, MtFloat2& ofs);
        void _setup9(uGUIBase* pUnit, cGUIInstance* pInst, const u32* table, u32 arrayNum, u32 stIdx);
        void _setup8(uGUIBase* pUnit, cGUIInstance* pInst, const u32* table, u32 arrayNum, u32 stIdx);
        void setPositionX(CELL cell, f32 v);
        f32 getPositionX(CELL cell);
        void setPositionY(CELL cell, f32 v);
        f32 getPositionY(CELL cell);
        void setSize(CELL cell, const MtFloat2& v);
    private:
        cGUIInstance* mpInstance;  // offset: 0x18
        nDDOUtility::cArray<cGUIObjPolygon*, 9> mpObjWindows;  // offset: 0x20
        stGradation mGrdTop;  // offset: 0x68
        stGradation mGrdBottom;  // offset: 0x78
        stOption mOption;  // offset: 0x88
        MtSize mDefaultSize;  // offset: 0x90
        MtSize mDefaultCenterSize;  // offset: 0x98
    public:
        static MyDTI DTI;
        static const u32 INVALID_ID = 4294967295;
        static const MtSizeF tblPosMul[9][9];
    };
public:
    class cVarData
    {
    public:
        static void* operator new(size_t sz);
        static void* operator new[](size_t);
        static void* operator new(size_t, void*);
        static void* operator new[](size_t, void*);
        static void operator delete(void* padr);
        static void operator delete[](void*);
    public:
        cGUIVariable* mpVariable;  // offset: 0x0
        u32 mVariableOrgId;  // offset: 0x8
        uGUIBase::cGUIInstAnimVariableArray mAnmInsts;  // offset: 0x10
    };
public:
    class cKeepInScreen : public MtObject
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
        cKeepInScreen();
        virtual ~cKeepInScreen();
        void setup(uGUIBase* pGUI, cGUIInstance* pInst, bool bEnable);
        void update();
    public:
        bool mEnable;  // offset: 0x8
        bool mIsDrew;  // offset: 0x9
        f32 mWaitFrm;  // offset: 0xc
        f32 mRate;  // offset: 0x10
        uGUIBase* mpParentGUI;  // offset: 0x18
        cGUIInstance* mpInst;  // offset: 0x20
        static MyDTI DTI;
        static const u32 FRM_WAIT = 3;
    };
public:
    class InputTextKeyboardHook : public cInputTextKeyboardHook
    {
    public:
        InputTextKeyboardHook();
        virtual ~InputTextKeyboardHook();
        void init(uGUIBase* owner);
        virtual bool onKeyEvent(const nInputTextKeyboardHook::Keycode& keycode);  // vtable slot 2
    private:
        uGUIBase* mOwner;  // offset: 0x8
    };
public:
    class cScrollListItemBase : public cUIObject
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
        cScrollListItemBase();
        // Address: 0x01ad9540 - 0x01ad9541 (1 bytes)
        virtual ~cScrollListItemBase() {}
        s32 getUseIndex();
        void setUseIndex(s32 Index);
        void setFocusInstance(cGUIInstAnimation* pInstFocus, u32 defSeq, u32 focusSeq, u32 selectSeq, u32 desableSeq);
        u32 getDefaultSeqID();
        u32 getFocusSeqID();
        u32 getSelectSeqID();
        u32 getDisableSeqID();
        void setRefUIFocus(bool isFocus);
    public:
        cGUIInstNull* mpInstBase;  // offset: 0x8
        cGUIInstAnimation* mpInstFocus;  // offset: 0x10
        uGUIBase::cReferenceUIBase* mpRefUIFocus;  // offset: 0x18
        cGUIInstance* mpInstPointerTarget;  // offset: 0x20
        cGUIObject* mpObjPointerTarget;  // offset: 0x28
        cGUIInstance* mpInstMouseCollision;  // offset: 0x30
        cGUIObject* mpObjMouseCollision;  // offset: 0x38
        u8 mItemType;  // offset: 0x40
        bool mIsVisible;  // offset: 0x41
    private:
        s32 mUseIndex;  // offset: 0x44
        u32 mDefaultSeqID;  // offset: 0x48
        u32 mFocusSeqID;  // offset: 0x4c
        u32 mSelectSeqID;  // offset: 0x50
        u32 mDisableSeqID;  // offset: 0x54
    public:
        static MyDTI DTI;
    };
public:
    class cScrollListInfoBase : public cUIObject
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
        cScrollListInfoBase(f32 Top, f32 Bottom);
        // Address: 0x01add690 - 0x01add691 (1 bytes)
        virtual ~cScrollListInfoBase() {}
        virtual void addMouseTouchList(cControl* pCtrl, s32 pos);  // vtable slot 6
        virtual void adjustMouseCollisionSize(cGUIObject* objMouseCollision);  // vtable slot 7
    public:
        uGUIBase::cScrollListItemBase* mpItem;  // offset: 0x8
        f32 mTopPos;  // offset: 0x10
        f32 mBottomPos;  // offset: 0x14
        f32 mMouseTopPos;  // offset: 0x18
        f32 mMouseBottomPos;  // offset: 0x1c
        u8 mItemType;  // offset: 0x20
        bool mIsVisible;  // offset: 0x21
        bool mIsMouseCheck;  // offset: 0x22
        bool mIsCheckScroll;  // offset: 0x23
        bool mIsDisable;  // offset: 0x24
        static MyDTI DTI;
    };
public:
    class cCalcMovePos
    {
    public:
        cCalcMovePos();
        ~cCalcMovePos();
        void setPos(const MtVector2& pos);
        void setPos(f32 pos);
        const MtVector2& getPosVec2() const;
        f32 getPos() const;
        void start(const MtVector2& targetPos, f32 frame);
        void start(f32 targetPos, f32 frame);
        const MtVector2& getTargetPosVec2() const;
        f32 getTargetPos() const;
        f32 getMoveLength() const;
        MtVector2 getMoveLengthVec2() const;
        bool isEnd() const;
        bool isMove() const;
        bool update(const f32 delta);
        f32 getRate();
        f32 getTimer();
        f32 getNowFrame();
        f32 getMaxFrame();
    private:
        MtVector2 mPos;  // offset: 0x0
        MtVector2 mDist;  // offset: 0x8
        MtVector2 mTargetPos;  // offset: 0x10
        f32 mTimer;  // offset: 0x18
        f32 mFrame;  // offset: 0x1c
        static const s32 DEFAULT_MOVE_FRAME = 4;
    };
public:
    class cVerticalList : public cControl
    {
        // inferred: uGUIMenuComm::updateCtgrList names uGUIBase::cVerticalList::mVisibleSize
        friend class uGUIMenuComm;
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
        cVerticalList(s32 item_num, const u32* tags, s32 visible_size);
        s32 getLocate() const;
        s32 getOldLocate() const;
        void setLocate(s32);
        s32 getVisibleTopPos() const;
        s32 getVisibleBottomPos() const;
        s32 getVisibleSize() const;
        void setVisibleSize(s32 sSize);
        bool isVisibleIndex(s32 idx);
        virtual void setUsePresetSE(bool bUse);  // vtable slot 10
        virtual void setCurrentPos(s32 sPos, bool bDisableLoop);  // vtable slot 18
        virtual bool execute();  // vtable slot 14
        virtual void checkLoop(u32 uKeyOnF, s32 sMoveDir, nGUIExt::MSG_REASON Reason, s32& sAddPos);  // vtable slot 7
        void setScrollList(bool flag);
        bool isScrollList() const;
    protected:
        virtual s32 getInputDirection(nGUIExt::MSG_REASON Reason) const;  // vtable slot 9
    protected:
        bool mIsScrollList;  // offset: 0xc48
        s32 mVisibleSize;  // offset: 0xc4c
        s32 mLocate;  // offset: 0xc50
        s32 mOldLocate;  // offset: 0xc54
    public:
        static MyDTI DTI;
    };
public:
    class cMsgAnalyzer : public MtObject
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
        cMsgAnalyzer();
        virtual ~cMsgAnalyzer();
        void setMsgAnalyzerWork(u32 uIdx, MT_CTSTR pAnalyzeMsg);
        void setMsgAnalyzerWork(u32 uIdx, s32 sAnalyzeNum);
        void clearMsgAnalyzerWork();
        void setObjectMessage(uGUIBase* pUnit, cGUIObject* pObj, MT_CTSTR msg, u32 uGenderType, bool bAutoWrap);
    private:
        nGUIExt::stMsgAnalyzerWork mMAW[10];  // offset: 0x8
    public:
        static MyDTI DTI;
    };
public:
    class cHorizontalList : public cControl
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
        cHorizontalList(s32 item_num, const u32* tags, s32 visible_size);
        void setTabType(bool bTabType);
        virtual bool isTabType() const;  // vtable slot 8
        s32 getLocate() const;
        s32 getOldLocate() const;
        s32 getVisibleTopPos() const;
        s32 getVisibleBottomPos() const;
        s32 getVisibleSize() const;
        void setVisibleSize(s32);
        virtual void setUsePresetSE(bool bUse);  // vtable slot 10
        virtual void setCurrentPos(s32 sPos, bool bDisableLoop);  // vtable slot 18
        virtual bool execute();  // vtable slot 14
    protected:
        virtual s32 getInputDirection(nGUIExt::MSG_REASON Reason) const;  // vtable slot 9
    protected:
        bool mTabType;  // offset: 0xc48
        s32 mVisibleSize;  // offset: 0xc4c
        s32 mLocate;  // offset: 0xc50
        s32 mOldLocate;  // offset: 0xc54
    public:
        static MyDTI DTI;
    };
public:
    class cInputGuideMonitor
    {
    public:
        cInputGuideMonitor();
        void reset();
        bool checkUpdate();
    private:
        u32 mLastUpdateButtonGuideFrame;  // offset: 0x0
        u8 mLastActPltType;  // offset: 0x4
    };
public:
    class cMatrix : public cControl
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
        cMatrix(s32 num, s32 col, const u32* tags, s32 vw, s32 vh);
        virtual bool execute();  // vtable slot 14
        bool isUpperRow();
        bool isLastRow();
        u32 resetItemNum(s32 num, s32 col, const u32* tags, s32 pos, u32 flag);
        void resetVisibleSize(s32, s32);
        s32 getCurrentColumn() const;
        s32 getCurrentRow() const;
        s32 getLocateX() const;
        s32 getLocateY() const;
        s32 getRow() const;
        s32 getColumn() const;
        u32 getFlag() const;
        virtual void setCurrentPos(s32 sPos, bool bDisableLoop);  // vtable slot 18
        void setCurrentColumn(s32 sCol);
        void setCurrentRow(s32 sRow);
        s32 getVisibleTopPos() const;
        s32 getVisibleTopPosX() const;
        s32 getVisibleTopPosY() const;
        void addVisibleTopPos(s32 add);
        s32 getPosFromXY(s32 x, s32 y) const;
        s32 getColumnOfRow(s32 sRow) const;
        s32 getRowOfColumn(s32 sCol) const;
        virtual void setUsePresetSE(bool bUse);  // vtable slot 10
        virtual void checkLoop(u32 uKeyOnF, s32 sMoveDir, nGUIExt::MSG_REASON Reason, s32& sAddPos);  // vtable slot 7
        virtual void setLoop(bool flag);  // vtable slot 16
        void setLoopX(bool flag);
        void setLoopY(bool);
        bool isLoopX();
        bool isLoopY();
        virtual void setTrgLoop(bool flag);  // vtable slot 17
        void setTrgLoopX(bool flag);
        void setTrgLoopY(bool flag);
        bool isTrgLoopX();
        bool isTrgLoopY();
    private:
        s32 _getColRowClamp(s32 sSrcNum, s32 sChkNum, bool isTrgLoop, bool isLoop, u32 uKeyOnF, s32 sMoveDir);
    protected:
        virtual s32 getInputDirection(nGUIExt::MSG_REASON Reason) const;  // vtable slot 9
    protected:
        s32 mColumn;  // offset: 0xc48
        s32 mRow;  // offset: 0xc4c
        s32 mCurrentColumn;  // offset: 0xc50
        s32 mCurrentRow;  // offset: 0xc54
        u32 mFlag;  // offset: 0xc58
        s32 mVisibleW;  // offset: 0xc5c
        s32 mVisibleH;  // offset: 0xc60
        s32 mLocateX;  // offset: 0xc64
        s32 mLocateY;  // offset: 0xc68
        bool mEnableLoopX;  // offset: 0xc6c
        bool mEnableLoopY;  // offset: 0xc6d
        bool mEnableTrgLoopX;  // offset: 0xc6e
        bool mEnableTrgLoopY;  // offset: 0xc6f
    public:
        static MyDTI DTI;
    };
public:
    class cMaskScroll : public MtObject
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
        cMaskScroll();
        // Address: 0x01af8070 - 0x01af8071 (1 bytes)
        virtual ~cMaskScroll() {}
        void setup(cGUIObject* pObj, f32 fMaskWidth, f32 fStartFrame, f32 fEndWaitFrame, f32 fMoveX, bool bLoop);
        bool update();
    public:
        cGUIObject* mpObj;  // offset: 0x8
        f32 mCurrentFrame;  // offset: 0x10
        f32 mStartFrame;  // offset: 0x14
        f32 mEndWaitFrame;  // offset: 0x18
        f32 mMaskWidth;  // offset: 0x1c
        f32 mMoveX;  // offset: 0x20
        f32 mPosXInit;  // offset: 0x24
        f32 mScrX;  // offset: 0x28
        f32 mScrXTarget;  // offset: 0x2c
        u8 mRno;  // offset: 0x30
        u8 mDTIType;  // offset: 0x31
        bool mIsLoop;  // offset: 0x32
        static MyDTI DTI;
        static const s32 SPD_DEFAULT = -2;
        static const s32 SF_DEFAULT = 60;
        static const s32 EWF_DEFAULT = 60;
    };
public:
    class cValueList : public MtObject
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
        cValueList(MT_CTSTR v0, MT_CTSTR v1, MT_CTSTR v2, MT_CTSTR v3, MT_CTSTR v4, MT_CTSTR v5, MT_CTSTR v6, MT_CTSTR v7, MT_CTSTR v8, MT_CTSTR v9, MT_CTSTR v10, MT_CTSTR v11, MT_CTSTR v12, MT_CTSTR v13, MT_CTSTR v14, MT_CTSTR v15, MT_CTSTR v16, MT_CTSTR v17, MT_CTSTR v18, MT_CTSTR v19);
        uGUIBase::cValueList& operator=(const uGUIBase::cValueList& v);
        void setStr(u32 idx, MT_CTSTR str);
        MT_CTSTR getStr(u32 idx) const;
        u32 getRegistNum() const;
        void clearStr();
    private:
        nDDOUtility::cArray<MtStringEx<32>, 20> mValues;  // offset: 0x8
        u32 mNum;  // offset: 0x2d8
    public:
        static MyDTI DTI;
        static const u32 LIST_MAX = 20;
    };
public:
    class cInterpolationValue : public MtObject
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
        cInterpolationValue();
        // Address: 0x01ade220 - 0x01ade221 (1 bytes)
        virtual ~cInterpolationValue() {}
        void init(f32 val, f32 speed);
        void set(f32 val, f32 speed);
        void setSpeed(f32);
        void setMaxSpeed(f32 f);
        void setMinPower(f32);
        void setFixDelta(bool b);
        bool getFixDelta();
        f32 execute();
        void setInverse(bool);
        bool getInverse();
        f32 getValue();
        void setValue(f32 f);
        f32 getPow();
        f32 getMax();
        f32 getRate();
        f32 getDifference();
    private:
        f32 mSpeed;  // offset: 0x8
        f32 mMaxSpeed;  // offset: 0xc
        f32 mPow;  // offset: 0x10
        f32 mMax;  // offset: 0x14
        f32 mValue;  // offset: 0x18
        f32 mMinPower;  // offset: 0x1c
        f32 mDifference;  // offset: 0x20
        bool mInverse;  // offset: 0x24
        bool mIsFixDelta;  // offset: 0x25
    public:
        static MyDTI DTI;
    };
public:
    class cUnitWatcher : public MtObject
    {
    public:
        template <typename T> class cFunc;
        class MyDTI;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        template <typename T>
        class cFunc
        {
        public:
            cFunc();
            void clear();
        public:
            MtObject* mpUnit;  // offset: 0x0
            T mpFunc;  // offset: 0x8
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
        cUnitWatcher();
        // Address: 0x01addc00 - 0x01addc01 (1 bytes)
        virtual ~cUnitWatcher() {}
        virtual void update();  // vtable slot 6
        bool isEnd();
        void clear();
        uGUIBase* getUnit();
        void setUnit(uGUIBase*);
        void addUnit(uGUIBase* pUnit, u32 line, u64 groupbit);
        uGUIBase* addSingleton(MtDTI* pdti);
        bool isForceEnd();
        void setForceEnd(bool bForceEnd);
    protected:
        uGUIBase* mpUnit;  // offset: 0x8
        uGUIBase* mpOldUnit;  // offset: 0x10
        bool mKillReq;  // offset: 0x18
        bool mForceEnd;  // offset: 0x19
        cFunc<bool(MtObject::*)()> mEndFunc;  // offset: 0x20
    public:
        static MyDTI DTI;
    };
public:
    class cImageDownloader
    {
    public:
        cImageDownloader();
        virtual ~cImageDownloader();
        void update();
        void request(MT_CTSTR url);
        bool isFail();
        bool isLoading();
        bool isComplete();
        void setRepeat(bool);
        void release();
    protected:
        void* mpImage;  // offset: 0x8
        u32 mImageSize;  // offset: 0x10
        JOBHANDLE mJobHandle;  // offset: 0x18
        bool mIsFail;  // offset: 0x20
    private:
        MtStringEx<256> mURL;  // offset: 0x24
        u32 mHandle;  // offset: 0x128
        bool mIsLoading;  // offset: 0x12c
        bool mIsComplete;  // offset: 0x12d
        bool mIsRepeat;  // offset: 0x12e
    };
public:
    class cArcLoader : public cUIObject
    {
    public:
        cArcLoader();
        virtual ~cArcLoader();
        void update(f32 delta_time);
        void request(ARC_TAGID arc_tag, f32 wait_frame);
        bool isLoading();
        bool isComplete();
        void release();
        cResource* createRes(ARC_SEARCHID search_id);
        cResource* createRes(MT_CTSTR search_id);
        void setId(u32 id);
        u32 getId();
    private:
        void load();
    private:
        TICKET mTicket;  // offset: 0x8
        ARC_TAGID mArcTagId;  // offset: 0x10
        ARC_TAGID mArcTagIdReq;  // offset: 0x14
        f32 mTimer;  // offset: 0x18
        u32 mId;  // offset: 0x1c
        bool mIsLoading;  // offset: 0x20
        bool mIsComplete;  // offset: 0x21
    };
public:
    class cScreenAdjustPos : public MtObject
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
        cScreenAdjustPos();
        // Address: 0x01ade8c0 - 0x01ade8c1 (1 bytes)
        virtual ~cScreenAdjustPos() {}
        MtVector4 execute(const MtVector3& scale, const sCamera::VIEWPORT_NO vpNo, const MtVector3& targetPos);
        void setRect(const MtRect&);
        const MtRect& getRect();
        const MtVector3& getScale();
        bool isScreenOut();
    private:
        MtVector4 calc2DPos(const MtVector3& scale, const sCamera::VIEWPORT_NO vpNo, const MtVector3& targetPos);
        MtFloat2 calcOverSize(const MtVector4& pos, const MtVector3& scale);
        MtVector4 rivisePos(const MtVector4& pos, const MtVector3& scale);
    private:
        MtRect mRect;  // offset: 0x8
        MtVector4 mBasePos;  // offset: 0x20
        MtVector4 mEndPos;  // offset: 0x30
        MtVector4 m2DScreenDir;  // offset: 0x40
        MtVector3 mScale;  // offset: 0x50
        MtFloat2 mOverSize;  // offset: 0x60
        f32 mLenMax;  // offset: 0x68
        f32 mScaleMax;  // offset: 0x6c
        bool mIsScreenOut;  // offset: 0x70
    public:
        static MyDTI DTI;
    };
public:
    class cTextSlider
    {
    public:
        enum
        {
            RNO_NONE = 0,
            RNO_WAIT = 1,
            RNO_SCROLL = 2,
            RNO_STOP = 3,
        };
    public:
        cTextSlider();
        ~cTextSlider();
        void setup(uGUIBase* pUnit, cGUIInstance* pInstNull, cGUIObject* pObjMsg, cGUIObject* pObjMaskCenter, f32 speed, f32 begin_frame, f32 end_frame);
        void initDefaultPos();
        void setDefaultPos();
        void start(MT_CTSTR pMsg);
        bool update(f32 delta_time);
        cGUIObjMessage* getMsgObject();
    protected:
        void setPos(f32 pos);
    protected:
        uGUIBase* mpUnit;  // offset: 0x0
        cGUIInstNull* mpInstNull;  // offset: 0x8
        cGUIObjMessage* mpObjMsg;  // offset: 0x10
        cGUIObjPolygon* mpObjMask;  // offset: 0x18
        f32 mDefaultPos;  // offset: 0x20
        f32 mScrollWidth;  // offset: 0x24
        f32 mTimer;  // offset: 0x28
        f32 mSpeed;  // offset: 0x2c
        f32 mBeginFrame;  // offset: 0x30
        f32 mEndFrame;  // offset: 0x34
        u32 mRno;  // offset: 0x38
    public:
        static const s32 default_begin_frame = 180;
        static const s32 default_end_frame = 360;
        static const s32 default_speed = 3;
    };
public:
    class cTexArcLoader : public uGUIBase::cArcLoader
    {
        // inferred: uGUIBrowserBG::kill names uGUIBrowserBG::mBrowserArea.mpObjTex
        friend class uGUIBrowserBG;
    public:
        cTexArcLoader();
        virtual ~cTexArcLoader();
        void setup(uGUIBase* pGUI, cGUIObject* pObjTex, u32 tex_index);
        void update(f32 delta_time);
        void request(MT_CTSTR arc_name, MT_CTSTR search_id, f32 wait_frame);
        rTexture* replaceTex(rTexture* pTex, bool IsReleaseOldTex);
        void resizeTex(s32 SizeW, s32 SizeH);
        void setBlendState(u32 BlendState);
        rTexture* createRes();
        void setVisible(bool IsVisible);
        bool isVisible();
    private:
        uGUIBase* mpParent;  // offset: 0x28
        cGUIObjTexture* mpObjTex;  // offset: 0x30
        MtStringEx<64> mSearchId;  // offset: 0x38
        u32 mTexIndex;  // offset: 0x7c
        bool mIsAutoAttach;  // offset: 0x80
    };
public:
    class cQuestTexLoader : public uGUIBase::cTexArcLoader
    {
    public:
        cQuestTexLoader();
        virtual ~cQuestTexLoader();
        void request(u32 quest_id, bool isImmediate);
    private:
        u32 mQuestId;  // offset: 0x84
    };
public:
    class cClanPolicyMessages
    {
    public:
        struct MsgObjParam;
    public:
        struct MsgObjParam
        {
        public:
            u32 mInstId;  // offset: 0x0
            u32 mObjId;  // offset: 0x4
        };
    public:
        cClanPolicyMessages();
        ~cClanPolicyMessages();
        void setup(uGUIBase* unit, const MsgObjParam(&mottoMsgObjParams)[2], const MsgObjParam(&dayMsgObjParams)[1], const MsgObjParam(&hourMsgObjParams)[1], const MsgObjParam(&featureMsgObjParams)[4]);
        void applyPolicy(u32 motto, u32 day, u32 hour, u32 feature);
    private:
        nDDOUtility::cArray<cGUIObjMessage*, 2> mMottoMsgObjs;  // offset: 0x0
        nDDOUtility::cArray<cGUIObjMessage*, 1> mDayMsgObjs;  // offset: 0x10
        nDDOUtility::cArray<cGUIObjMessage*, 1> mHourMsgObjs;  // offset: 0x18
        nDDOUtility::cArray<cGUIObjMessage*, 4> mFeatureMsgObjs;  // offset: 0x20
        u32 mMotto;  // offset: 0x40
        u32 mDay;  // offset: 0x44
        u32 mHour;  // offset: 0x48
        u32 mFeature;  // offset: 0x4c
        uGUIBase* mpParent;  // offset: 0x50
    };
public:
    template <typename T>
    class cDupliInstance : public uGUIBase::cSupportBase
    {
    public:
        cDupliInstance();
        virtual ~cDupliInstance();
        void setup(uGUIBase* pBase, cGUIInstance* pOrgInst, cGUIInstance* pDupli);
        void clear();
        void deleteInstance();
        cGUIInstance* getInstance(u32 instId);
        T getInsDupli();
        T getInsOrg();
        bool isSafePtr();
        void setVisible(bool b);
        bool isVisible();
        void setExecute(bool b);
        void setRefExecute();
        void setExecuteTree(bool b);
        void setPosition(const MtVector4& v);
        void setRefPositionX(f32 value);
        void setRefPositionY(f32 value);
        f32 getPositionX();
        f32 getPositionY();
        MtVector2 getScreenPos();
        void setRefPriority(u32 prio);
        void setSequenceId(u32 id, bool reset);
        void setRefPosition(const MtVector4& v);
        f32 getRefPositionX();
    private:
        T mpDupli;  // offset: 0x18
        T mpOrgInst;  // offset: 0x20
    };
public:
    // Layout verified against DWARF for cExGUIMessageObj<64>
    template <unsigned int _size>
    class cExGUIMessageObj : public uGUIBase::cSupportBase
    {
    public:
        cExGUIMessageObj();
        virtual ~cExGUIMessageObj();
        void setup(uGUIBase* pUnit, cGUIObject* pMes);
        void setStr(MT_CTSTR str);
        void setColor(const MtColor& color);
        void setAnalyzeTag(bool isAnalyzeTag);
        MT_CTSTR getStr();
        cGUIObjMessage* getObjMessage();
        uGUIBase::cExGUIMessageObj<_size>& operator=(MT_CTSTR str);
        uGUIBase::cExGUIMessageObj<_size>& operator=(s32 num);
    private:
        cGUIObjMessage* mpMesObj;  // offset: 0x18
        MtStringEx<_size> mString;  // offset: 0x20
    };
public:
    class cSupportInstAnim : public uGUIBase::cSupportBase
    {
        // inferred: uGUIBrowserBG::sleep names uGUIBrowserBG::mClose.::uGUIBase::cSupportInstAnim::mpInstance
        friend class uGUIBrowserBG;
        // inferred: uGUIGPShop::shiftHistoryList names uGUIGPShop::mShopMenuCursor.::uGUIBase::cSupportInstAnim::mpInstance
        friend class uGUIGPShop;
        // inferred: uGUINewspaper::initRankingActiveControl names uGUINewspaper::mRankingScrollbar.mCursor.::uGUIBase::cSupportInstAnim::mpInstance
        friend class uGUINewspaper;
        // inferred: uGUIQuestList::clearInfo names uGUIQuestList::mInfo.mScrollCtrl.::uGUIBase::cScrollCtrl::mBar.::uGUIBase::cSupportInstAnim::mpInstance
        friend class uGUIQuestList;
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
        cSupportInstAnim();
        // Address: 0x01adc240 - 0x01adc241 (1 bytes)
        virtual ~cSupportInstAnim() {}
        cGUIInstAnimation* getInstance();
        cGUIInstance* getInstanceFromId(u32);
        void setInstance(cGUIInstance*);
        void setPosition(const MtVector4& pos);
        void setPositionX(f32 pos);
        void setPositionY(f32 pos);
        void setPositionZ(f32);
        const MtVector4& getPosition();
        f32 getPositionX();
        f32 getPositionY();
        f32 getPositionZ();
        void setExecuteTree(bool b);
        bool isAnimationEnd();
        void setVisible(bool visible);
        bool isVisible();
        virtual void setExecute(bool b);  // vtable slot 6
        virtual bool isExecute();  // vtable slot 7
        void setSequence(u32 id, bool reset);
        void setPriority(u32 n);
        u32 getPriority();
        u32 getPrioGrp();
        u32 getSequenceId();
        void setColorScale(const MtVector4& v4Col);
        void setRotationZ(f32 v);
        virtual bool setupPointerPos();  // vtable slot 8
        virtual void setPointerPos(const MtVector2& v2Pos);  // vtable slot 9
        virtual MtVector2 getPointerPos();  // vtable slot 10
        cGUIObject* getObjPointer();
        void setIsPosPointerReqAuto(bool b);
        virtual void setPosPointerReqAuto(bool bAuto);  // vtable slot 11
        virtual void setPosPointerReqAuto(bool bAuto, u32 uPrio);  // vtable slot 12
        virtual void update();  // vtable slot 13
        u32 getPrioPointer();
    protected:
        // Address: 0x01adc350 - 0x01adc351 (1 bytes)
        virtual void updatePointerPos() {}  // vtable slot 14
    protected:
        cGUIInstAnimation* mpInstance;  // offset: 0x18
        cGUIObject* mpObjNullPointer;  // offset: 0x20
        MtVector2 mPosPointer;  // offset: 0x28
        bool mIsPosPointerReqAuto;  // offset: 0x30
    private:
        u32 mPrioPointer;  // offset: 0x34
    public:
        static MyDTI DTI;
    };
public:
    class cDuplicateData
    {
    public:
        static void* operator new(size_t sz);
        static void* operator new[](size_t);
        static void* operator new(size_t, void*);
        static void* operator new[](size_t, void*);
        static void operator delete(void* padr);
        static void operator delete[](void*);
    public:
        cGUIInstance* mpInst;  // offset: 0x0
        uGUIBase::cVarDataArray mVarDatas;  // offset: 0x8
    };
public:
    class cReferenceUIVlCursor : public uGUIBase::cSupportInstAnim
    {
    public:
        enum TYPE
        {
            TYPE_01 = 0,
            TYPE_02 = 1,
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
        cReferenceUIVlCursor();
        // Address: 0x01adba30 - 0x01adba31 (1 bytes)
        virtual ~cReferenceUIVlCursor() {}
        void setup(uGUIBase* pParentGUI, cGUIInstance* pInst, const MtFloat2& size, f32 fDistY);
        void setType(TYPE type);
        virtual void update();  // vtable slot 13
        void setPosInit(const MtVector4& v4PosInit);
        MtVector4 getPosInit();
        void setPosTarget(const MtVector4& v4Pos, bool isImmediate);
        const MtVector4& getPosTarget();
        void setPosTargetY(f32 fPosYTarget, bool isImmediate);
        f32 getDistY();
        void setPointerPosOfs(const MtVector2& v2Ofs);
        virtual MtVector2 getPointerPos();  // vtable slot 10
        void setCtrlPos(s32 sPos, bool isImmediate);
        void setCtrlPos(s32 sPos, f32 dPos, bool isImmediate);
        s32 getCtrlPos();
        void resetPosition();
        void setSize(MtFloat2 size, f32 dist);
        MtFloat2 getSize();
        void applyInstPosX(cGUIInstNull*);
    protected:
        virtual void updatePointerPos();  // vtable slot 14
    private:
        cGUIObjPolygon* mpObjL;  // offset: 0x38
        cGUIObjPolygon* mpObjC;  // offset: 0x40
        cGUIObjPolygon* mpObjR;  // offset: 0x48
        cGUIObjPolygon* mpObjUL;  // offset: 0x50
        cGUIObjPolygon* mpObjUC;  // offset: 0x58
        cGUIObjPolygon* mpObjUR;  // offset: 0x60
        f32 mDistY;  // offset: 0x68
        s32 mCtrlPos;  // offset: 0x6c
        f32 mFrmMove;  // offset: 0x70
        f32 mDefaultWidthL;  // offset: 0x74
        f32 mDefaultWidthR;  // offset: 0x78
        bool mIsNoUpdatePointerPos;  // offset: 0x7c
        MtVector4 mPosInit;  // offset: 0x80
        MtVector4 mPosTarget;  // offset: 0x90
        MtVector2 mPosPointerOfs;  // offset: 0xa0
    public:
        static MyDTI DTI;
        static const u32 RATE_MOVE = 2;
    };
public:
    class cTexRefJpegDownloader : public uGUIBase::cImageDownloader
    {
    public:
        cTexRefJpegDownloader();
        virtual ~cTexRefJpegDownloader();
        void setup(cGUIObject* objTexRef);
        void request(MT_CTSTR url);
        void update(f32 delta_time);
        void abort();
        bool isReplaceTex() const;
        bool isHaveTicket();
    private:
        void clearMemberJpeg();
    private:
        cGUIObjTextureRef* mpObjTexRef;  // offset: 0x130
        rTexture* mpTex;  // offset: 0x138
        MtStringEx<256> mURL_Jpeg;  // offset: 0x140
        bool mIsCrateTex;  // offset: 0x244
        bool mIsReplaceTex;  // offset: 0x245
        bool mIsRequest;  // offset: 0x246
        bool mIsRequestBuf;  // offset: 0x247
        u32 mDlTicket;  // offset: 0x248
        f32 mWaitTime;  // offset: 0x24c
        static const u32 REQ_WAIT = 20;
    };
public:
    class cReferenceUISlider : public uGUIBase::cSupportInstAnim
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
        cReferenceUISlider();
        // Address: 0x01ade270 - 0x01ade271 (1 bytes)
        virtual ~cReferenceUISlider() {}
        void setup(cGUIInstance* pInst);
        void resize(const MtFloat2& size);
        void setSliderPos(f32 parcent);
    public:
        cGUIObjPolygon* mpOBJ_fix_selector_selctor_bar;  // offset: 0x38
        cGUIObjChildAnimationRoot* mpOBJ_fix_selector_cursor_r0;  // offset: 0x40
        cGUIObjChildAnimationRoot* mpOBJ_fix_selector_cursor_l0;  // offset: 0x48
        cGUIObjTexture* mpOBJ_fix_selector_fix_cursor;  // offset: 0x50
        static MyDTI DTI;
    };
public:
    class cReferenceUICursor : public uGUIBase::cSupportInstAnim
    {
    public:
        enum TYPE
        {
            TYPE_LEFT = 0,
            TYPE_CENTER = 1,
        };
        enum
        {
            OBJ_CURSOR_LEFT = 0,
            OBJ_CURSOR_CENTER = 1,
            OBJ_CURSOR_RIGHT = 2,
            OBJ_LINE_LEFT = 3,
            OBJ_LINE_CENTER = 4,
            OBJ_LINE_RIGHT = 5,
            OBJ_MAX = 6,
        };
    public:
        class MyDTI;
    public:
        using cObjs = nDDOUtility::cArray<cGUIObjTexture*, 6>;
        using cPositions = nDDOUtility::cArray<MtVector4, 6>;
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
        cReferenceUICursor();
        // Address: 0x01ade310 - 0x01ade311 (1 bytes)
        virtual ~cReferenceUICursor() {}
        void setup(uGUIBase* pUnit, cGUIInstance* pInst, TYPE type);
        void updateWidth(f32 size, bool rightMinus);
        void setVisible(bool visible);
        void setPosition(const MtVector4& pos, bool center);
        void setVisibleUnderLine(bool);
        f32 getWidth();
    public:
        TYPE mType;  // offset: 0x38
        cObjs mpObjs;  // offset: 0x40
        cPositions mPositions;  // offset: 0x70
        bool mVisibleUnderLine;  // offset: 0xd0
        f32 mWidth;  // offset: 0xd4
        bool mRightMinus;  // offset: 0xd8
        static MyDTI DTI;
    };
public:
    class cReferenceUIGoldRim : public uGUIBase::cSupportInstAnim
    {
    public:
        enum TYPE
        {
            TYPE_GOLD = 0,
            TYPE_RIM = 1,
            TYPE_MAX = 2,
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
        cReferenceUIGoldRim();
        // Address: 0x01ade360 - 0x01ade361 (1 bytes)
        virtual ~cReferenceUIGoldRim() {}
        void setup(cGUIInstance* pInst, TYPE type);
        void setPos(const MtVector4& pos);
        MT_CTSTR getValue(u64 val);
        cGUIObjMessage* getTextObj();
    public:
        cGUIInstAnimation* mpInstance;  // offset: 0x38
        cGUIObjMessage* mpOBJ_msg_wlth_m_amount;  // offset: 0x40
        cGUIObjTexture* mpOBJ_msg_wlth_pic;  // offset: 0x48
        cGUIObjTexture* mpOBJ_msg_wlth_left;  // offset: 0x50
        cGUIObjTexture* mpOBJ_msg_wlth_center;  // offset: 0x58
        cGUIObjTexture* mpOBJ_msg_wlth_right;  // offset: 0x60
        TYPE mType;  // offset: 0x68
        MtStringEx<32> mStr;  // offset: 0x6c
        static MyDTI DTI;
    };
public:
    class cReferenceUIIconStatus : public uGUIBase::cSupportInstAnim
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
        cReferenceUIIconStatus();
        // Address: 0x01ade520 - 0x01ade521 (1 bytes)
        virtual ~cReferenceUIIconStatus() {}
        void setup(cGUIInstance* pInst);
        u32 getOcdId() const;
        void set(u32 ocdId);
        void set(u32 ocdId, f32 ocdAccumulation, f32 ocdEnduranceMax);
        void setOccurred(u32 ocdId, f32 animFrame);
        static f32 GetIconFrameFromOcdId(u32 ocdId);
    private:
        cGUIObjNull* mpNull_gauge_up;  // offset: 0x38
        u32 mOcdId;  // offset: 0x40
    public:
        static MyDTI DTI;
    };
public:
    class cTexRefArcLoader : public uGUIBase::cArcLoader
    {
    public:
        cTexRefArcLoader();
        virtual ~cTexRefArcLoader();
        void setup(cGUIObject* objTexRef);
        void request(MT_CTSTR arcName, MT_CTSTR searchId, f32 waitFrame);
        void update(f32 deltaTime);
        void release();
    private:
        cGUIObjTextureRef* mpObjTexRef;  // offset: 0x28
        MtStringEx<64> mSearchId;  // offset: 0x30
    };
public:
    class cReferenceUIBase : public uGUIBase::cSupportInstAnim
    {
    public:
        enum
        {
            ATTR_NONE = 0,
            ATTR_MOUSEOVER = 1,
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
        cReferenceUIBase();
        // Address: 0x01adc3a0 - 0x01adc3a1 (1 bytes)
        virtual ~cReferenceUIBase() {}
        void setAttr(u32);
        void orAttr(u32 uAttr);
        void xorAttr(u32);
        void clrAttr(u32 uAttr);
        bool isAttr(u32);
        u32 getAttr();
        virtual void setFocus(bool b);  // vtable slot 15
        virtual bool isFocus();  // vtable slot 16
        bool isRegister();
        virtual s32 getVItemNum();  // vtable slot 17
        virtual cGUIObjPolygon* getMouseOverObject();  // vtable slot 18
        void addMouseTouchListDefault(cControl* pCtrl, s32 pos, s32 vol);
    protected:
        void registerThis();
        virtual void updatePointerPos();  // vtable slot 14
    protected:
        u32 mAttr;  // offset: 0x38
        cGUIObjPolygon* mpObjMouseOver;  // offset: 0x40
    private:
        bool mIsRegister;  // offset: 0x48
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUITextBox : public uGUIBase::cReferenceUIBase
    {
        // inferred: uGUIBase::moveTextBox names uGUIBase::cReferenceUITextBox::mState
        friend class uGUIBase;
    public:
        enum STATE
        {
            STATE_NONE = 0,
            STATE_WAIT = 1,
            STATE_OPEN = 2,
            STATE_IDLE = 3,
            STATE_CLOSE = 4,
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
        cReferenceUITextBox();
        virtual ~cReferenceUITextBox();
        void setup(uGUIBase* pParentGUI, cGUIInstance* pInst, const MtFloat2& size, MT_CTSTR pMsgInit, u32 uLenMaxText, bool bDispCharNum);
        cControl* getControl();
        void execute();
        virtual void update();  // vtable slot 13
        void setMessage(MT_CTSTR pMsg);
        MT_CTSTR getMessage() const;
        void resetMsgLength();
        virtual void setFocus(bool b);  // vtable slot 15
        virtual bool isFocus();  // vtable slot 16
        void setFontSize(s32 fontSize);
        void setFontSize(const MtSize& fontSize);
        void setLayout(u32 layout);
        bool isWakeupKeyboard() const;
        bool isEndKeyboard() const;
        bool wakeupKeyboard();
        bool wakeupKeyboard(s32 keyboardType);
        bool wakeupKeyboard(s32 keyboardType, MT_CTSTR initText);
    protected:
        bool updateKeyboard();
    public:
        void closeKeyboard(bool isCancel);
        void resetTextSize();
        void addMouseTouchList(cControl* pOwner, s32 pos, s32 vol, bool autoErase);
        STATE getState() const;
    protected:
        bool tryWakeupKeyboard();
        virtual void setSequence(u32 id, bool reset);  // vtable slot 19
    private:
        uGUIBase::cAdjustableWindow mForm;  // offset: 0x50
        cGUIObjNull* mpObjNull;  // offset: 0xf0
        cGUIObjMessage* mpObjMsgText;  // offset: 0xf8
        cGUIObjMessage* mpObjMsgPage;  // offset: 0x100
        cGUIObjPolygon* mpObjMouseOver;  // offset: 0x108
        MtString mMsg;  // offset: 0x110
        u32 mLenMaxText;  // offset: 0x118
        MtFloat2 mSizeTextBox;  // offset: 0x11c
        MtFloat2 mMesObjPos;  // offset: 0x124
        f32 mWindowBaseSizeY;  // offset: 0x12c
        MtFloat2 mSize;  // offset: 0x130
        bool mFocus;  // offset: 0x138
        bool mIsDispCharNum;  // offset: 0x139
        u32 mAutoWrap;  // offset: 0x13c
        MtSize mDefaultFontSize;  // offset: 0x140
        MtSize mFontSize;  // offset: 0x148
        u32 mLayout;  // offset: 0x150
        STATE mState;  // offset: 0x154
        s32 mKeyboardType;  // offset: 0x158
        cControl* mCtrlMouse;  // offset: 0x160
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIWndwDrag : public uGUIBase::cReferenceUIBase
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
        cReferenceUIWndwDrag();
        // Address: 0x01adb3d0 - 0x01adb3d1 (1 bytes)
        virtual ~cReferenceUIWndwDrag() {}
        void setup(uGUIBase* pParentGUI, cGUIInstance* pInst, MtFloat2 size, cGUIInstNull* pInstNull);
        virtual void update();  // vtable slot 13
        void setCollisionSize(MtFloat2 size);
        MtFloat2 getCollisionSize() const;
    private:
        cGUIInstNull* mpInstNull;  // offset: 0x50
        cGUIObjPolygon* mpObjPolygon;  // offset: 0x58
        bool mDragOld;  // offset: 0x60
        bool mDragEnable;  // offset: 0x61
        MtVector3 mPosClick;  // offset: 0x70
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIIconJob : public uGUIBase::cReferenceUIBase
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
        cReferenceUIIconJob();
        // Address: 0x01ade3b0 - 0x01ade3b1 (1 bytes)
        virtual ~cReferenceUIIconJob() {}
        void setup(uGUIBase* pBase, cGUIInstance* pInst);
        void set(u32 jobId);
        void set(const cContextInstHm* pContext);
        void setWithSecret(u32 jobId);
        void setRole(u32 roleId);
        void setEntryCustom();
        void noBaseSequence();
        void noBaseDisableSequence();
        void noBaseSelectSeauence();
        virtual void setFocus(bool isFocus);  // vtable slot 15
        virtual bool isFocus();  // vtable slot 16
        virtual void updatePointerPos();  // vtable slot 14
    private:
        u32 mJobId;  // offset: 0x4c
        bool mIsFocus;  // offset: 0x50
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIScrollBar : public uGUIBase::cReferenceUIBase
    {
    public:
        enum
        {
            TYPE_NORMAL = 0,
            TYPE_QUEST = 1,
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
        cReferenceUIScrollBar();
        // Address: 0x01ade2c0 - 0x01ade2c1 (1 bytes)
        virtual ~cReferenceUIScrollBar() {}
        void setup(uGUIBase* pUnit, cGUIInstance* pInstance, cGUIObject* pObjWheel);
        void setupEx(uGUIBase* pUnit, cGUIInstance* pInstance, u32 SliderTop, u32 Slider, u32 SliderBottom, u32 WakuTop, u32 WakuCenter, u32 WakuBottom, cGUIObject* pObjWheel);
        void execute(bool isCheckWheel);
        s32 getWheelMoveDir();
        void setWheelCheckInstance(cGUIInstance* pInst);
        void setSize(f32 length, f32 list_range, f32 disp_range, bool execVisible);
        void setSliderPos(f32 scroll_pos);
        void moveSliderPosByScreenDist(f32 move_dist);
        void moveSliderPosByListDist(f32 move_dist);
        f32 getSliderPos();
        f32 getMoveLength();
        bool isDrag();
        void setType(u32 type);
        f32 getDispRange() const;
        f32 getListRange() const;
        f32 getMoveRange() const;
        f32 getRate() const;
    protected:
        cGUIObjTexture* mpObjTexSliderTop;  // offset: 0x50
        cGUIObjTexture* mpObjTexSliderCenter;  // offset: 0x58
        cGUIObjTexture* mpObjTexSliderBottom;  // offset: 0x60
        cGUIObjTexture* mpObjTexWakuTop;  // offset: 0x68
        cGUIObjTexture* mpObjTexWakuCenter;  // offset: 0x70
        cGUIObjTexture* mpObjTexWakuBottom;  // offset: 0x78
        cGUIObjPolygon* mpObjPolWheel;  // offset: 0x80
        cGUIInstance* mpInstPolWheel;  // offset: 0x88
        f32 mScrollBarLength;  // offset: 0x90
        f32 mListRange;  // offset: 0x94
        f32 mDispRange;  // offset: 0x98
        f32 mScrollPos;  // offset: 0x9c
        f32 mMoveLength;  // offset: 0xa0
        bool mDragOld;  // offset: 0xa4
        bool mDragEnable;  // offset: 0xa5
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUICloseBtn : public uGUIBase::cReferenceUIBase
    {
    public:
        class MyDTI;
    public:
        using CloseFunc = u32(uGUIBase::*)(cControl::Message*);
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
        cReferenceUICloseBtn();
        // Address: 0x01addda0 - 0x01addda1 (1 bytes)
        virtual ~cReferenceUICloseBtn() {}
        void setup(uGUIBase* pParentGUI, cGUIInstance* pInst, CloseFunc pCloseFunc);
        virtual void update();  // vtable slot 13
        void execute();
        void setEnable(bool bEnable);
        bool isEnable();
        cControl* getControl();
    private:
        bool mEnable;  // offset: 0x49
        cControl* mpCtrl;  // offset: 0x50
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIIconQuest : public uGUIBase::cReferenceUIBase
    {
    public:
        enum SIZE
        {
            SIZE_NORMAL = 0,
            SIZE_SMALL = 1,
        };
        enum TYPE
        {
            TYPE_MAIN = 0,
            TYPE_SET = 1,
            TYPE_LIGHT = 2,
            TYPE_CLAN_DUNGEON = 3,
            TYPE_CYCLE_CONTENTS = 4,
            TYPE_END_CONTENTS = 5,
        };
        enum STATE
        {
            STATE_AVAILABLE = 0,
            STATE_CURRENT = 1,
            STATE_NOT_AVAILABLE = 2,
            STATE_CLEARED = 3,
            STATE_HINT = 4,
            STATE_CURRENT_SUB = 5,
        };
        enum
        {
            PRIO_NONE = 0,
            PRIO_QST_L_CLEAR = 1,
            PRIO_QST_S_CLEAR = 2,
            PRIO_QST_M_CLEAR = 3,
            PRIO_QST_L_CLEAR_SAME_AREA = 4,
            PRIO_QST_S_CLEAR_SAME_AREA = 5,
            PRIO_QST_M_CLEAR_SAME_AREA = 6,
            PRIO_QST_L = 7,
            PRIO_QST_S = 8,
            PRIO_QST_M = 9,
            PRIO_QST_L_SAME_AREA = 10,
            PRIO_QST_S_SAME_AREA = 11,
            PRIO_QST_M_SAME_AREA = 12,
            PRIO_QST_L_AC = 13,
            PRIO_QST_S_AC = 14,
            PRIO_QST_M_AC = 15,
            PRIO_QSTA_L = 16,
            PRIO_QSTA_S = 19,
            PRIO_QSTA_M = 22,
            PRIO_QSTPA_L = 25,
            PRIO_QSTPA_S = 28,
            PRIO_QSTPA_M = 31,
            PRIO_QST_ETC = 34,
            PRIO_MAX = 35,
        };
        enum
        {
            ICONTYPE_NORMAL = 0,
            ICONTYPE_S_HINT_UD = 1,
        };
        enum
        {
            FIXF_NONE = 0,
            FIXF_M_NA = 1,
            FIXF_S_NA = 2,
            FIXF_L_NA = 3,
            FIXF_CD_NA = 4,
            FIXF_CC_NA = 5,
            FIXF_EC_NA = 6,
            FIXF_M_AQ = 10,
            FIXF_S_AQ = 11,
            FIXF_L_AQ = 12,
            FIXF_CD_AQ = 13,
            FIXF_CC_AQ = 14,
            FIXF_EC_AQ = 15,
            FIXF_AQ_OK = 1,
            FIXF_AQ_NG = 2,
            FIXF_AQ_CLEARED = 4,
            FIXF_AQ_HINT = 5,
            FIXF_AQ = 10,
            FIXF_AQ_SUB = 11,
            FIXF_S_HINT_UD = 100,
        };
        enum
        {
            DISPMODE_MAP = 0,
            DISPMODE_CHOICE = 1,
            DISPMODE_QUESTLIST = 2,
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
        cReferenceUIIconQuest();
        // Address: 0x01ade570 - 0x01ade571 (1 bytes)
        virtual ~cReferenceUIIconQuest() {}
        void setup(uGUIBase* pBase, cGUIInstance* pInst);
        void setDisp(TYPE type, STATE state);
        void setDispFromQuestType(nQuest::QUEST_TYPE quest_type, STATE state);
        void setSdlId(u32 uSdlId, u32 uDispMode, nQuest::cQuestMarker* pMarker);
        bool isEnableSyncChip(u32 uSdlId);
        bool isOrder();
        u32 getQuestPrio();
        void setSize(SIZE size);
        static bool IsActiveQuest(u32 scheduleId, u32 ActiveQuestDispType, u32* activeQuestIndex);
        u32 getIconType();
    private:
        cGUIObjNull* mpObjNullNormal;  // offset: 0x50
        cGUIObjTexture* mpObjBaseL;  // offset: 0x58
        cGUIObjTexture* mpObjBaseR;  // offset: 0x60
        cGUIObjTexture* mpObjIcon;  // offset: 0x68
        cGUIObjTexture* mpObjIconSp;  // offset: 0x70
        cGUIObjNull* mpObjNullActive;  // offset: 0x78
        cGUIObjNull* mpObjNullIconSp;  // offset: 0x80
        cGUIObjColorAdjust* mpObjColorAdjust;  // offset: 0x88
        cGUIObjTexture* mpObjActiveHL;  // offset: 0x90
        cGUIObjTexture* mpObjActiveHR;  // offset: 0x98
        cGUIObjTexture* mpObjActiveML;  // offset: 0xa0
        cGUIObjTexture* mpObjActiveMR;  // offset: 0xa8
        cGUIObjTexture* mpObjActiveLL;  // offset: 0xb0
        cGUIObjTexture* mpObjActiveLR;  // offset: 0xb8
        cGUIObjNull* mpObjNullChip;  // offset: 0xc0
        cGUIObjTexture* mpObjChip;  // offset: 0xc8
        bool mIsOrder;  // offset: 0xd0
        u32 mQuestPrio;  // offset: 0xd4
        SIZE mSize;  // offset: 0xd8
        u32 mIconType;  // offset: 0xdc
    public:
        static MyDTI DTI;
        static const s32 ACTIVE_QUEST_BASE_FRAME = 1;
        static const s32 ACTIVE_PARTY_QUEST_ADDITIONAL_FRAME = 9;
    };
public:
    class cReferenceUIButton : public uGUIBase::cReferenceUIBase
    {
        // inferred: uGUICaplinkTalk::evCtrlDecide names uGUICaplinkTalk::mMain.mButton.mIsEnable
        friend class uGUICaplinkTalk;
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
        cReferenceUIButton();
        // Address: 0x01adccb0 - 0x01adccb1 (1 bytes)
        virtual ~cReferenceUIButton() {}
        virtual void setup(uGUIBase* pParentGUI, cGUIInstance* pInst, MT_CTSTR pMsgInit, f32 fSize);  // vtable slot 19
        void setMessage(MT_CTSTR pMsg);
        MT_CTSTR getMessage();
        void adjustSize(bool bFixSize);
        virtual void setFocus(bool isFocus);  // vtable slot 15
        virtual bool isFocus();  // vtable slot 16
        void setEnable(bool isEnable);
        bool isEnable();
        MtFloat2 getCenterSize();
        void setBtnSize(f32 fSize, bool changeSizeForced);
        f32 getBtnSize();
        cGUIObjMessage* getMessageObject();
        s32 getWidth();
        void adjust2Buttons(uGUIBase::cReferenceUIButton& right, s32 interval);
        u32 addMouseTouchList(cControl* pOwner, s32 pos, s32 vol, bool autoErase);
    protected:
        virtual void updatePointerPos();  // vtable slot 14
    protected:
        cGUIObjTexture* mpObjL;  // offset: 0x50
        cGUIObjTexture* mpObjC;  // offset: 0x58
        cGUIObjTexture* mpObjR;  // offset: 0x60
        cGUIObjTexture* mpObjLFcs;  // offset: 0x68
        cGUIObjTexture* mpObjCFcs;  // offset: 0x70
        cGUIObjTexture* mpObjRFcs;  // offset: 0x78
        cGUIObjMessage* mpObjMsgText;  // offset: 0x80
        MT_CHAR mMsg[256];  // offset: 0x88
        f32 mBtnSize;  // offset: 0x188
        bool mIsEnable;  // offset: 0x18c
        bool mFocus;  // offset: 0x18d
        bool mIsChangeSizeForced;  // offset: 0x18e
    public:
        static MyDTI DTI;
        static const u32 SIZEW_MIN = 90;
    };
public:
    class cReferenceUITab : public uGUIBase::cReferenceUIBase
    {
    public:
        enum SHAPE
        {
            SHAPE_DEFAULT = 0,
            SHAPE_RECTANGLE = 0,
            SHAPE_CHIPPED = 1,
        };
        enum ALIGN
        {
            ALIGN_LEFT = 0,
            ALIGN_CENTER = 1,
            ALIGN_MAX = 2,
        };
    public:
        class MyDTI;
        class cTabWork;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cTabWork : public MtObject
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
            cTabWork();
            // Address: 0x01adf6c0 - 0x01adf6c1 (1 bytes)
            virtual ~cTabWork() {}
        public:
            cGUIInstAnimation* mpInst;  // offset: 0x8
            cGUIObjPolygon* mpMouseOver;  // offset: 0x10
            cGUIObjNull* mpNullPointer;  // offset: 0x18
            cGUIObjTexture* mpObjL;  // offset: 0x20
            cGUIObjTexture* mpObjC;  // offset: 0x28
            cGUIObjTexture* mpObjR;  // offset: 0x30
            cGUIObjNull* mpObjNullL;  // offset: 0x38
            cGUIObjNull* mpObjNullR;  // offset: 0x40
            cGUIObjMessage* mpObjMsg;  // offset: 0x48
            MT_CHAR mMsg[256];  // offset: 0x50
            uGUIBase::cReferenceUITab::SHAPE mShape;  // offset: 0x150
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
        cReferenceUITab();
        virtual ~cReferenceUITab();
        void setup(uGUIBase* pParentGUI, cGUIInstance* pInst, u32 uNum, f32 fDist, ALIGN align);
        void createArrayTabWork(u32 uNum);
        void setPosBase(const MtVector4& v4Pos);
        void setAutoPos();
        MtFloat2 getTabSize();
        void setTabMessage(u32 uIdx, MT_CTSTR pMsg);
        MT_CTSTR getTabMessage(u32 uIdx);
        void setFocus(u32 uIdx, bool bFocus, bool bAutoFocus);
        // Address: 0x01addd00 - 0x01addd01 (1 bytes)
        virtual void setFocus(bool b) {}  // vtable slot 15
        s32 getFocusIdx();
        void setVisible(bool bVisible);
        void setVisibleTabMax(u32 max);
        u32 getVisibleNum();
        virtual s32 getLRWidth();  // vtable slot 19
        f32 getConvertWindowCenterX(f32 center_center_x);
        void setSpace(s32);
        s32 getSpace();
        u32 getTabNum();
        void resizeForVisible();
        cGUIObjTexture* getObjTextureCenter(u32 uIdx);
        cGUIInstAnimation* getInstance(u32 uIdx);
        cGUIObjPolygon* getMouseOverObj(u32 uIdx);
        cGUIObjNull* getNullPointerObj(u32 uIdx);
        void setCtrlable(bool bEnable);
        void setupMouseTouchList(cControl* pCtrl, s32 vol);
        void updateButtonGuide();
        SHAPE getShape(u32 index) const;
        void setShape(u32 index, SHAPE shape);
        void setAnalyzeTag(bool isAnalyzeTag);
    private:
        f32 getInstanceWidth(bool bVisibleNum);
        void _setSequenceIdPrivate(cTabWork* pWork, u32 seqId, u32 uIdx);
        void setupLRGuide();
        void _setVisibleLRGuide(cTabWork* pWork, u32 uIdx);
    private:
        MtTypedArray<cTabWork> mWork;  // offset: 0x50
        MtVector4 m4PosInstInit;  // offset: 0x70
        MtVector4 m4PosBase;  // offset: 0x80
        s32 mFocusIdx;  // offset: 0x90
        u32 mVisibleNum;  // offset: 0x94
        s32 mSpace;  // offset: 0x98
        f32 mSizeW;  // offset: 0x9c
        u32 mAlign;  // offset: 0xa0
        bool mIsCtrlable;  // offset: 0xa4
        bool mIsAnalyzeTag;  // offset: 0xa5
        uGUIBase::cInputGuideMonitor mInputGuideMonitor;  // offset: 0xa8
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIBtnGuide : public uGUIBase::cReferenceUIBase
    {
    public:
        enum GUIDE_TYPE
        {
            GUIDE_TYPE_BLANK = 0,
            GUIDE_TYPE_CHANGE_INFO_RL = 1,
            GUIDE_TYPE_CHANGE_INFO_RU = 2,
            GUIDE_TYPE_CLOSE = 3,
            GUIDE_TYPE_SUBMENU_RL = 4,
            GUIDE_TYPE_SUBMENU_RU = 5,
            GUIDE_TYPE_RETURN = 6,
            GUIDE_TYPE_DECIDE = 7,
            GUIDE_TYPE_EXECUTE = 8,
            GUIDE_TYPE_END = 9,
            GUIDE_TYPE_CHANGE_PAGE = 10,
            GUIDE_TYPE_SCM_R2 = 11,
            GUIDE_TYPE_SCM_L2 = 12,
            GUIDE_TYPE_CHANGE_TOGGLE = 13,
            GUIDE_TYPE_INPUT_NUM = 14,
            GUIDE_TYPE_MAX = 15,
            GUIDE_TYPE_ERROR = -1,
        };
    public:
        class MyDTI;
        class cWork;
        struct stGuideBtnData;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cWork : public MtObject
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
            cWork();
            // Address: 0x01adf670 - 0x01adf671 (1 bytes)
            virtual ~cWork() {}
            void clear();
            void addKeyCustom(nKeyCustom::KB_CUSTOM kbCustom);
        public:
            bool mEnable;  // offset: 0x8
            cGUIInstAnimation* mpInst;  // offset: 0x10
            cGUIObjTexture* mpObjL;  // offset: 0x18
            cGUIObjTexture* mpObjC;  // offset: 0x20
            cGUIObjTexture* mpObjR;  // offset: 0x28
            cGUIObjPolygon* mpObjMouseOver;  // offset: 0x30
            cGUIObjMessage* mpObjIcon;  // offset: 0x38
            cGUIObjMessage* mpObjMsg;  // offset: 0x40
            nKeyCustom::KB_CUSTOM mKeyCustom;  // offset: 0x48
            nGUIExt::ICONTAGKB mWayType;  // offset: 0x4c
            nDDOUtility::cArray<nKeyCustom::KB_CUSTOM, 4> mAddKeyCustoms;  // offset: 0x50
            u32 mAddKeyCustomNum;  // offset: 0x60
            bool mIsIgnoreModifier;  // offset: 0x64
            MtStringEx<128> mMsg;  // offset: 0x68
            MtStringEx<128> mKbdMsg;  // offset: 0xec
            static MyDTI DTI;
        };
    public:
        struct stGuideBtnData
        {
        public:
            stGuideBtnData();
            stGuideBtnData(uGUIBase::cReferenceUIBtnGuide::GUIDE_TYPE type);
            stGuideBtnData(nKeyCustom::KB_CUSTOM kbCustom, bool isIgnoreModifier, MT_CTSTR pMsg, MT_CTSTR pKbdMsg, nGUIExt::ICONTAGKB wayType);
            void operator=(const uGUIBase::cReferenceUIBtnGuide::stGuideBtnData& data);
            void copy(const uGUIBase::cReferenceUIBtnGuide::stGuideBtnData& data);
        public:
            uGUIBase::cReferenceUIBtnGuide::GUIDE_TYPE mType;  // offset: 0x0
            nKeyCustom::KB_CUSTOM mKeyCustom;  // offset: 0x4
            nGUIExt::ICONTAGKB mWayType;  // offset: 0x8
            MT_CTSTR mpMsg;  // offset: 0x10
            MT_CTSTR mpKbdMsg;  // offset: 0x18
            bool mIsIgnoreModifier;  // offset: 0x20
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
        cReferenceUIBtnGuide();
        virtual ~cReferenceUIBtnGuide();
        void setup(uGUIBase* pParentGUI, cGUIInstance* pInst, f32 fWidth);
        virtual void update();  // vtable slot 13
        void createArrayBtnGuideWork();
        void addGuide(GUIDE_TYPE type);
        void addGuide(nKeyCustom::KB_CUSTOM kbCustom, MT_CTSTR pMsg, nGUIExt::ICONTAGKB wayType, MT_CTSTR pKbdMsg, bool isIgnoreModifier);
        void clearGuide();
        u32 getGuideNum();
        void setVisible(bool bVisible);
        f32 getTotalWidth() const;
        f32 getCenterX() const;
        void addBtnIcon(u32 uIdx, nKeyCustom::KB_CUSTOM kbCustom);
        void adjustDisp();
        void setAutoVisibleControl(bool);
        void setFocusCtrl(bool bFocus);
        bool isFocusCtrl();
        void setWidth(f32 fWidth);
        void setRightAlignment(bool isAlignment);
        bool isRightAlignment();
        void setGuideTable(stGuideBtnData* data);
        void setDispBit(u32 bit);
        u32 getDispBit();
    private:
        void setMsg(cWork* pWork);
        void setVisibleCore(bool bVisible);
        void setObjectMessageAdjustSize(cGUIObjMessage* pObjMsg, MT_CTSTR pMsg);
    private:
        MtTypedArray<cWork> mWork;  // offset: 0x50
        cControl* mpCtrl;  // offset: 0x70
        f32 mWidth;  // offset: 0x78
        bool mIsBaseVisible;  // offset: 0x7c
        bool mIsAutoVisible;  // offset: 0x7d
        bool mIsRightAlignment;  // offset: 0x7e
        stGuideBtnData* mpGuideDataPtr;  // offset: 0x80
        u32 mDispBit;  // offset: 0x88
        f32 mLeftMargin;  // offset: 0x8c
        uGUIBase::cInputGuideMonitor mInputGuideMonitor;  // offset: 0x90
    public:
        static MyDTI DTI;
        static const u32 GUIDE_MAX = 9;
        static const u32 GUIDE_TBL_MAX = 10;
        static const u32 GUIDE_ADD_NUM_MAX = 4;
    };
public:
    class cReferenceUITooltip : public uGUIBase::cReferenceUIBase
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
        cReferenceUITooltip();
        // Address: 0x01ade820 - 0x01ade821 (1 bytes)
        virtual ~cReferenceUITooltip() {}
        void setup(uGUIBase* pParentGUI, cGUIInstance* pInst, MT_CTSTR pMsg);
        void setMessage(MT_CTSTR pMsg);
        void adjustSize();
        f32 getMessageWidth() const;
        f32 getMessageHeight() const;
    private:
        cGUIObjMessage* mpObjMsg;  // offset: 0x50
        cGUIObjTexture* mpTextL;  // offset: 0x58
        cGUIObjTexture* mpTextC;  // offset: 0x60
        cGUIObjTexture* mpTextR;  // offset: 0x68
        MT_CHAR mMsgOld[256];  // offset: 0x70
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIDropIcon : public uGUIBase::cReferenceUIBase
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
        cReferenceUIDropIcon();
        // Address: 0x01adf930 - 0x01adf931 (1 bytes)
        virtual ~cReferenceUIDropIcon() {}
        void setup(uGUIBase* pUnit, cGUIInstance* pInstance);
        void setFrame(f32);
        void setMessage(MT_CTSTR);
    private:
        cGUIObjMessage* mpObjMsg;  // offset: 0x50
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUISelector : public uGUIBase::cReferenceUIBase
    {
    public:
        enum
        {
            CLICKVOL_CENTER = 0,
            CLICKVOL_LEFT = 1,
            CLICKVOL_RIGHT = 2,
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
        cReferenceUISelector();
        // Address: 0x01adc550 - 0x01adc551 (1 bytes)
        virtual ~cReferenceUISelector() {}
        void setup(uGUIBase* pUnit, cGUIInstance* pInst);
        void setMessage(MT_CTSTR* msg_list, u32 msg_num);
        void setMessage(u32 index, MT_CTSTR msg);
        void addMessage(MT_CTSTR msg);
        void clearMessage();
        void setIndex(u32 index);
        u32 getIndex();
        u32 getNum();
        virtual void setFocus(bool isFocus);  // vtable slot 15
        virtual MtVector2 getPointerPos();  // vtable slot 10
        void addMouseTouchList(cControl* pCtrl, s32 pos);
    private:
        cGUIObjMessage* mpObjMsg;  // offset: 0x50
        cGUIObjNull* mpObjNullPointerPos;  // offset: 0x58
        cGUIObjPolygon* mpObjPolyMouseCollisionCenter;  // offset: 0x60
        cGUIObjPolygon* mpObjPolyMouseCollisionLeft;  // offset: 0x68
        cGUIObjPolygon* mpObjPolyMouseCollisionRight;  // offset: 0x70
        uGUIBase::cValueList mMsgList;  // offset: 0x78
        u32 mIndex;  // offset: 0x358
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIChargesInfo : public uGUIBase::cReferenceUIBase
    {
    public:
        enum
        {
            RNO_INIT = 0,
            RNO_IN = 1,
            RNO_IN_WAIT = 2,
            RNO_SCROLL = 3,
            RNO_OUT_WAIT = 4,
            RNO_OUT = 5,
        };
        enum
        {
            DISPF_NONE = 0,
            DISPF_ICON = 1,
            DISPF_COURSE = 2,
            DISPF_LIMIT = 4,
            DISPF_CHKCHARGES = 8,
            DISPF_CENTER = 16,
            DISPF_CHANGE_BASE = 32,
            DISPF_NO_FADE = 64,
            DISPF_HUD = 128,
            DISPF_CHKCH_ALWAYS = 256,
            DISPF_DEFAULT = 8,
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
        class cData : public MtObject
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
            cData();
            virtual ~cData();
        public:
            u64 mEndTime;  // offset: 0x8
            u32 mDispF;  // offset: 0x10
            u32 mChargesEft;  // offset: 0x14
            MtString mMsg;  // offset: 0x18
            bool mIsScroll;  // offset: 0x20
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
        cReferenceUIChargesInfo();
        virtual ~cReferenceUIChargesInfo();
        void setup(uGUIBase* pParentGUI, cGUIInstance* pInst, u32 uAttr);
        void setAttribute(u32 uAttr, u32 uDispF);
        void addAttribute(u32 uAttr, u32 uDispF);
        virtual void update();  // vtable slot 13
        void addData(u32 uCharges, u32 uDispF, MT_CTSTR pMsgEdit);
        void addDataToCharaSel(u32 uCharges, u64 uEndTime, u32 uDispF, MT_CTSTR pMsgEdit);
        void resetState();
        void deleteData();
        void setContext(cContextInstHm*);
        void setSizeWFix(f32 fSizeW);
        void setSizeWFixDefault();
        f32 getWidth();
        void setMessageEdit(MT_CTSTR pMsgEdit, u32 index);
        void setNullVisible(bool bVisible);
    private:
        void setSizeW();
        bool isDispEnable(cData* pData);
        u32 getNextIndex();
        u32 getCourseNum();
        u32 getFirstPrioCourse();
        void setObjectMessageAdjustSize(cGUIObjMessage* pObjMsg, MT_CTSTR pMsg);
        bool addDataCore(cData* pData, u32 uCharges, u32 uDispF, MT_CTSTR pMsgEdit);
    private:
        MtTypedArray<cData> mList;  // offset: 0x50
        cGUIObjNull* mpObjNull;  // offset: 0x70
        cGUIObjNull* mpObjNullCourseNum;  // offset: 0x78
        cGUIObjNull* mpObjNullText;  // offset: 0x80
        cGUIObjNull* mpObjNullMask;  // offset: 0x88
        cGUIObjNull* mpObjNullEffect;  // offset: 0x90
        cGUIObjNull* mpObjNullBase00;  // offset: 0x98
        cGUIObjNull* mpObjNullBase01;  // offset: 0xa0
        cGUIObjNull* mpObjNullLimit;  // offset: 0xa8
        cGUIObjTexture* mpObjTexCenterBase00;  // offset: 0xb0
        cGUIObjTexture* mpObjTexCenterFrame00;  // offset: 0xb8
        cGUIObjTexture* mpObjTexLeftBase00;  // offset: 0xc0
        cGUIObjTexture* mpObjTexRightBase00;  // offset: 0xc8
        cGUIObjTexture* mpObjTexCenterBase01;  // offset: 0xd0
        cGUIObjTexture* mpObjTexCenterFrame01;  // offset: 0xd8
        cGUIObjTexture* mpObjTexRightBase01;  // offset: 0xe0
        cGUIObjPolygon* mpObjPolyMaskCenter;  // offset: 0xe8
        cGUIObjPolygon* mpObjPolyMaskRight;  // offset: 0xf0
        cGUIObjMessage* mpObjMsgCourse;  // offset: 0xf8
        cGUIObjMessage* mpObjMsgCourseNum;  // offset: 0x100
        cGUIObjMessage* mpObjMsgEffect;  // offset: 0x108
        cGUIObjMessage* mpObjMsgLimit;  // offset: 0x110
        cContextInstHm* mpContext;  // offset: 0x118
        f32 mCourseTimer;  // offset: 0x120
        f32 mDispTimer;  // offset: 0x124
        f32 mScrollDist;  // offset: 0x128
        f32 mScrollPos;  // offset: 0x12c
        f32 mSizeWFix;  // offset: 0x130
        f32 mDefaultSize;  // offset: 0x134
        f32 mDefaultCenterSize;  // offset: 0x138
        f32 mBaseLRSize;  // offset: 0x13c
        u32 mCurrentIdxData;  // offset: 0x140
        u32 mRno;  // offset: 0x144
        s32 mLastUpdateTime;  // offset: 0x148
        u32 mEnableCourseNum;  // offset: 0x14c
        bool mIsHUDMode;  // offset: 0x150
        bool mIsCharaSelMode;  // offset: 0x151
    public:
        static MyDTI DTI;
        static const s32 DISP_WAIT_SEC = 2;
        static const s32 FADE_FRAME = 3;
        static const s32 SCROLL_SPEED = 1;
        static const s32 ICON_SIZE_X = 22;
        static const s32 LIMIT_SIZE_X = 63;
    };
public:
    class cReferenceUIIconItem : public uGUIBase::cReferenceUIBase
    {
    public:
        enum SIZE
        {
            SIZE_SMALL = 38,
            SIZE_MIDDLE = 64,
        };
        enum EQUIP_COLOR
        {
            EQUIP_COLOR_DEFAULT = 0,
            EQUIP_COLOR_RED = 1,
            EQUIP_COLOR_YELLOW = 2,
            EQUIP_COLOR_GREEN = 3,
            EQUIP_COLOR_PURPLE = 4,
            EQUIP_COLOR_BLUE = 5,
            EQUIP_COLOR_BLACK = 6,
            EQUIP_COLOR_ORANGE = 7,
            EQUIP_COLOR_WHITE = 8,
            EQUIP_COLOR_NUM = 9,
        };
        enum TYPE
        {
            TYPE_ICON = 0,
            TYPE_BG = 1,
            TYPE_INFO = 2,
            TYPE_MAX = 3,
        };
        enum COLOR
        {
            COLOR_EMPTY = 0,
            COLOR_RANK = 1,
            COLOR_KAKIN = 100,
            COLOR_RAND = 300,
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
        cReferenceUIIconItem();
        virtual ~cReferenceUIIconItem();
        virtual void setup(uGUIBase* pParentGUI, cGUIInstance* pInstItemIcon, cGUIInstance* pInstFixIconBase, cGUIInstance* pInstFixIconInfo);  // vtable slot 19
        virtual void update();  // vtable slot 13
        virtual void setEmpty();  // vtable slot 20
        bool isEmpty();
        bool isLoading();
        void setUnknown(bool isRare);
        void setUnknown(rItemList::rItemParam* pParam);
        void setImage(u32 img);
        void setItem(nGUIItem::cItem* pItem);
        void setSize(SIZE size);
        void setScale(f32 scale);
        void setIconFromId(u32 item_id);
        virtual void setIconFromParam(rItemList::rItemParam* pItemParam);  // vtable slot 21
        void setIconFromParam(cItemParam* pParam);
        u32 getItemId();
        void setPosition(const MtVector4& pos);
        virtual MtVector2 getPointerPos();  // vtable slot 10
        virtual void setVisible(bool b);  // vtable slot 22
        void setVisibleIcon(bool b);
        void setVisibleBG(bool b);
        void setVisibleInfo(bool b);
        cGUIInstAnimation* getInstIcon();
        cGUIInstAnimation* getInstBg();
        cGUIInstAnimation* getInstInfo();
        void setExecuteTree(bool b, u32 uIdx);
        void setNum(u32 n);
        void clearNum();
        void setQuality(u32 quality);
        void clearQuality();
        void setGrade(u32 grade);
        void setEquipColor(EQUIP_COLOR color);
        void setEquipColorFromColorNo(u32 color_no);
        void setCheck(bool b);
        bool isCheck();
        virtual void setFocus(bool b);  // vtable slot 15
        virtual bool isFocus();  // vtable slot 16
        void setDispNumZero(bool b);
        bool isDispNumZero();
        void setAutoDispName(bool b, bool apply);
        void setDispName(bool b);
        bool isDispName();
        void setDispMsg(MT_CTSTR msg, bool isForceDraw);
        void addMouseTouchList(cControl* pOwner, s32 pos, s32 vol);
        void setVisibleItemDetail(bool bVisible);
        void setPosItemDetail(const MtVector3& vPos);
        void setPriorityItemDetail(bool isIssuePrio);
        void setInstNullParent(cGUIInstNull*);
        cGUIInstNull* getInstNullParent();
        void setColorScale(const MtVector4& v4ColorScale);
    protected:
        void setColor(u32 color);
        void setupIconFrame();
        virtual void updatePointerPos();  // vtable slot 14
    private:
        void setInstVisible(cGUIInstance* pInst, bool b);
        void updateDispName();
    protected:
        cGUIInstNull* mpInstNullParent;  // offset: 0x50
        nDDOUtility::cArray<cGUIInstAnimation*, 3> mpInstances;  // offset: 0x58
        cGUIObjTextureRef* mpTex;  // offset: 0x70
        cGUIObjTexture* mpFrame;  // offset: 0x78
        cGUIObjTexture* mpFocus;  // offset: 0x80
        cGUIObjTexture* mpBase00;  // offset: 0x88
        cGUIObjTexture* mpBase01;  // offset: 0x90
        cGUIObjTexture* mpBase02;  // offset: 0x98
        cGUIObjTexture* mpBase03;  // offset: 0xa0
        cGUIObjTexture* mpBase04;  // offset: 0xa8
        cGUIObjTexture* mpBase05;  // offset: 0xb0
        cGUIObjTexture* mpCheck;  // offset: 0xb8
        cGUIObjTexture* mpColor;  // offset: 0xc0
        cGUIObjNull* mpNullGrade;  // offset: 0xc8
        cGUIObjTexture* mpGradeIcon[4];  // offset: 0xd0
        cGUIObjMessage* mpNums;  // offset: 0xf0
        cGUIObjMessage* mpQuality;  // offset: 0xf8
        MtFloat2 mGradeBasePos;  // offset: 0x100
        MtFloat2 mGradeSmallPos;  // offset: 0x108
        MtFloat2 mColorBasePos;  // offset: 0x110
        MtFloat2 mColorSmallPos;  // offset: 0x118
        u32 mTexIdx;  // offset: 0x120
        u32 mImgId;  // offset: 0x124
        SIZE mSize;  // offset: 0x128
        EQUIP_COLOR mEquipColor;  // offset: 0x12c
        u32 mItemId;  // offset: 0x130
        u16 mLocalNum;  // offset: 0x134
        u16 mMaxNum;  // offset: 0x136
        u8 mQuality;  // offset: 0x138
        bool mIsArms;  // offset: 0x139
        bool mIsEmpty;  // offset: 0x13a
        bool mIsCheck;  // offset: 0x13b
        bool mIsFocus;  // offset: 0x13c
        bool mIsDispNumZero;  // offset: 0x13d
        bool mIsAutoDispName;  // offset: 0x13e
        bool mIsDispName;  // offset: 0x13f
        bool mIsVisibleItemDetail;  // offset: 0x140
        bool mIsLoading;  // offset: 0x141
        u32 mDiameter;  // offset: 0x144
        MtVector2 mPosPointerOfs;  // offset: 0x148
        MtVector3 mPosItemDetail;  // offset: 0x150
        cItemParam* mpItemParam;  // offset: 0x160
        rItemList::rItemParam* mprItemParam;  // offset: 0x168
        bool mIsIssuePriority;  // offset: 0x170
    public:
        static MyDTI DTI;
        static const u32 INVALID_TEXIDX = 128;
    protected:
        static const u32 grade_icon_num = 4;
    };
public:
    class cReferenceUIIconEquip : public uGUIBase::cReferenceUIIconItem
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
        cReferenceUIIconEquip();
        virtual ~cReferenceUIIconEquip();
        virtual void setup(uGUIBase* pParentGUI, cGUIInstance* pInstItemIcon, cGUIInstance* pInstFixIconBase, cGUIInstance* pInstFixIconInfo);  // vtable slot 19
        void setup(uGUIBase* pParentGUI, cGUIInstance* pInstItemIcon, cGUIInstance* pInstFixIconBase, cGUIInstance* pInstFixIconInfo, cGUIInstance* pInstCategoryIcon, u32 slot_no);
        virtual void setEmpty();  // vtable slot 20
        virtual void setIconFromParam(rItemList::rItemParam* pItemParam);  // vtable slot 21
        void setIconFromParam(cItemParam* pParam);
        void setLock();
    private:
        cGUIInstAnimation* mpInstAnimCategoryIcon;  // offset: 0x178
        u32 mSlotNo;  // offset: 0x180
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIIconItemCharges : public uGUIBase::cReferenceUIIconItem
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
        cReferenceUIIconItemCharges();
        virtual ~cReferenceUIIconItemCharges();
        virtual void setup(uGUIBase* pParentGUI, cGUIInstance* pInstItemIcon, cGUIInstance* pInstFixIconBase, cGUIInstance* pInstFixIconInfo);  // vtable slot 19
        void setup(uGUIBase* pParentGUI, cGUIInstance* pInstItemIcon, cGUIInstance* pInstFixIconBase, cGUIInstance* pInstFixIconInfo, cGUIInstance* pInstChargesInfo);
        virtual void update();  // vtable slot 13
    public:
        uGUIBase::cReferenceUIChargesInfo mChargesInfo;  // offset: 0x178
        static MyDTI DTI;
    };
public:
    class cReferenceUIIconSkill : public uGUIBase::cReferenceUIBase
    {
    public:
        enum TYPE
        {
            TYPE_SKILL = 0,
            TYPE_ABILITY = 1,
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
        cReferenceUIIconSkill();
        virtual ~cReferenceUIIconSkill();
        void setup(uGUIBase* pUnit, cGUIInstance* pInstIcon, cGUIInstance* pInstBase, cGUIInstance* pInstInfo);
        virtual void update();  // vtable slot 13
        void setType(TYPE type);
        void setImage(u32 id);
        void setEmpty();
        void setPosition(const MtVector4& pos);
        void setVisible(bool isVisible);
        void setLevel(u32 lv);
        void setLevelVisible(bool isVisible);
        void setSetIcon(bool isSet);
        virtual void setFocus(bool isFocus);  // vtable slot 15
        virtual bool isFocus();  // vtable slot 16
        void setEnable(bool isEnable);
        virtual void updatePointerPos();  // vtable slot 14
    private:
        ARC_TAGID getArcTag(u32 id);
        rTexture* getTexture(u32 id);
        void setupBase();
    private:
        TYPE mType;  // offset: 0x4c
        u16 mId;  // offset: 0x50
        u16 mLevel;  // offset: 0x52
        TICKET mTicket;  // offset: 0x58
        cGUIInstAnimation* mpInstAnimIcon;  // offset: 0x60
        cGUIInstAnimation* mpInstAnimBase;  // offset: 0x68
        cGUIInstAnimation* mpInstAnimInfo;  // offset: 0x70
        cGUIObjTextureRef* mpObjTexIcon;  // offset: 0x78
        cGUIObjTexture* mpObjTexHighlight;  // offset: 0x80
        cGUIObjTexture* mpObjTexFrame;  // offset: 0x88
        cGUIObjTexture* mpObjTexBase;  // offset: 0x90
        cGUIObjTexture* mpObjTexFocus;  // offset: 0x98
        cGUIObjNull* mpObjNullLv;  // offset: 0xa0
        cGUIObjMessage* mpObjMsgLv;  // offset: 0xa8
        cGUIObjTexture* mpObjTexSetIcon;  // offset: 0xb0
        bool mIsLevelVisible;  // offset: 0xb8
        bool mIsEnable;  // offset: 0xb9
        bool mIsFocus;  // offset: 0xba
    public:
        static MyDTI DTI;
        static const u16 INVALID_ID = 65535;
    };
public:
    class cReferenceUIIconCraftLv : public uGUIBase::cReferenceUIBase
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
        cReferenceUIIconCraftLv();
        // Address: 0x01adf7b0 - 0x01adf7b1 (1 bytes)
        virtual ~cReferenceUIIconCraftLv() {}
        void setup(uGUIBase* pUnit, cGUIInstance* pInst);
        void setLevel(u32 level);
    private:
        cGUIObject* mpObjIcon;  // offset: 0x50
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIIconStorage : public uGUIBase::cReferenceUIBase
    {
    public:
        enum TYPE
        {
            TYPE_STORAGE = 0,
            TYPE_PL = 1,
            TYPE_EX_STORAGE = 2,
            TYPE_BAGGAGE_FREE = 3,
            TYPE_BAGGAGE_RENTAL = 3,
            TYPE_EQUIP = 10,
            TYPE_PAWN_EQUIP = 11,
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
        cReferenceUIIconStorage();
        // Address: 0x01adf760 - 0x01adf761 (1 bytes)
        virtual ~cReferenceUIIconStorage() {}
        void setup(uGUIBase* pUnit, cGUIInstance* pInst);
        void setImage(TYPE type);
        void setImage(u32 bag_type);
        void setImage(u32 bag_type, cItemParam* pParam);
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIIconShake : public uGUIBase::cReferenceUIBase
    {
    public:
        enum MODE
        {
            MODE_INVISIBLE = 0,
            MODE_SHAKE00 = 1,
            MODE_SHAKE01 = 2,
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
        cReferenceUIIconShake();
        // Address: 0x01adf710 - 0x01adf711 (1 bytes)
        virtual ~cReferenceUIIconShake() {}
        void setup(uGUIBase* pUnit, cGUIInstance* pInstShake00, cGUIInstance* pInstShake01);
        void setMode(MODE mode);
        void updateTimer(f32 delta_time);
    private:
        MODE mMode;  // offset: 0x4c
        MODE mModeRequest;  // offset: 0x50
        f32 mFrame;  // offset: 0x54
        cGUIInstAnimation* mpInstShake00;  // offset: 0x58
        cGUIInstAnimation* mpInstShake01;  // offset: 0x60
    public:
        static MyDTI DTI;
    private:
        static const s32 disp_frame = 90;
    };
public:
    class cReferenceUIIconSCM : public uGUIBase::cReferenceUIBase
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
        cReferenceUIIconSCM();
        // Address: 0x01ade5c0 - 0x01ade5c1 (1 bytes)
        virtual ~cReferenceUIIconSCM() {}
        void setup(uGUIBase* pBase, cGUIInstance* pInst);
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIIconGameMenu : public uGUIBase::cReferenceUIBase
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
        cReferenceUIIconGameMenu();
        // Address: 0x01ade610 - 0x01ade611 (1 bytes)
        virtual ~cReferenceUIIconGameMenu() {}
        void setup(uGUIBase* pBase, cGUIInstance* pInst);
        void setCurrentFrame(u32 uFrame);
        void setScale(f32 fScale);
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIIconComm : public uGUIBase::cReferenceUIBase
    {
    public:
        enum
        {
            FIXF_NDISP = 0,
            FIXF_TMPPHRASE = 1,
            FIXF_EMOTION = 2,
            FIXF_MYPHRASE = 3,
            FIXF_PAWNORDER = 4,
            FIXF_VOICE = 5,
            FIXF_MAX = 6,
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
        cReferenceUIIconComm();
        // Address: 0x01ade660 - 0x01ade661 (1 bytes)
        virtual ~cReferenceUIIconComm() {}
        void setup(uGUIBase* pBase, cGUIInstance* pInst);
        void setCurrentFrame(u32 uFrame);
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIIconOnlineStatus : public uGUIBase::cReferenceUIBase
    {
    public:
        enum
        {
            FIXF_OFFLINE = 0,
            FIXF_ONLINE = 1,
            FIXF_LEAVING = 2,
            FIXF_BUSY = 3,
            FIXF_ENTRY_BOARD = 4,
            FIXF_QUICK_MATCH = 5,
            FIXF_EVENT = 6,
            FIXF_CONTENTS = 7,
            FIXF_PT_LEADER = 8,
            FIXF_PT_MEMBER = 9,
            FIXF_READY = 10,
            FIXF_DOWN = 11,
            FIXF_CLOSED = 12,
            FIXF_PAWN_NORMAL = 20,
            FIXF_PAWN_LEGEND = 21,
            FIXF_MAX = 22,
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
        cReferenceUIIconOnlineStatus();
        // Address: 0x01ade6b0 - 0x01ade6b1 (1 bytes)
        virtual ~cReferenceUIIconOnlineStatus() {}
        void setup(uGUIBase* pBase, cGUIInstance* pInst);
        void setCurrentFrame(s32 uFrame);
        void setOnlineStatus(u32 onlineStatus);
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIIconClanTitle : public uGUIBase::cReferenceUIBase
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
        cReferenceUIIconClanTitle();
        // Address: 0x01ade700 - 0x01ade701 (1 bytes)
        virtual ~cReferenceUIIconClanTitle() {}
        void setup(uGUIBase* pBase, cGUIInstance* pInst);
        void setCurrentFrame(s32 frame);
        void setClanRank(u32 clanRank);
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIGammaBoard : public uGUIBase::cReferenceUIBase
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
        cReferenceUIGammaBoard();
        // Address: 0x01ade750 - 0x01ade751 (1 bytes)
        virtual ~cReferenceUIGammaBoard() {}
        void setup(uGUIBase* pBase, cGUIInstance* pInstA, cGUIInstance* pInstB);
    private:
        cGUIInstAnimation* mpInstA;  // offset: 0x50
        cGUIInstAnimation* mpInstB;  // offset: 0x58
        cGUIObjTexture* mpObjTexA;  // offset: 0x60
        cGUIObjTexture* mpObjTexB;  // offset: 0x68
        cGUIObjMessage* mpObjMsgA;  // offset: 0x70
        cGUIObjMessage* mpObjMsgB;  // offset: 0x78
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUICheckbox : public uGUIBase::cReferenceUIBase
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
        cReferenceUICheckbox();
        // Address: 0x01adcaf0 - 0x01adcaf1 (1 bytes)
        virtual ~cReferenceUICheckbox() {}
        void setup(uGUIBase* pBase, u32 instID);
        void setup(uGUIBase* pBase, cGUIInstAnimation* pInst);
        void init();
        virtual void setFocus(bool b);  // vtable slot 15
        virtual bool isFocus();  // vtable slot 16
        void setCheck(bool b);
        bool isCheck() const;
        void reverseCheck();
        bool isForbid() const;
        void setForbid(bool bForbid, bool bCheck);
        virtual void update();  // vtable slot 13
    protected:
        virtual void updatePointerPos();  // vtable slot 14
    private:
        void _update();
    private:
        bool mFocus;  // offset: 0x49
        bool mCheck;  // offset: 0x4a
        bool mIsForbid;  // offset: 0x4b
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIButton2 : public uGUIBase::cReferenceUIButton
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
        cReferenceUIButton2();
        // Address: 0x01adce10 - 0x01adce11 (1 bytes)
        virtual ~cReferenceUIButton2() {}
        virtual void setup(uGUIBase* pParentGUI, cGUIInstance* pInst, MT_CTSTR pMsgInit, f32 fSize);  // vtable slot 19
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIToggleBtn : public uGUIBase::cReferenceUIBase
    {
        // inferred: uGUIGiveAndTake::evCtrlToggle names uGUIGiveAndTake::mToggleBtnBagRef.mValueForbid
        friend class uGUIGiveAndTake;
    public:
        enum
        {
            TYPE_BAG = 0,
            TYPE_MEMBER = 1,
            TYPE_GOLDBOX = 2,
            TYPE_BAGGAGE_FREE = 3,
            TYPE_BAGGAGE_RENTAL = 4,
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
        cReferenceUIToggleBtn();
        // Address: 0x01adce70 - 0x01adce71 (1 bytes)
        virtual ~cReferenceUIToggleBtn() {}
        void setup(uGUIBase* pParentGUI, cGUIInstance* pInst, u8 uValueInit, u8 uValueForbid, u8 type, MT_CTSTR str);
        virtual void update();  // vtable slot 13
        void execute();
        virtual void setFocus(bool isFocus);  // vtable slot 15
        virtual bool isFocus();  // vtable slot 16
        void setEnable(bool isEnable);
        bool isEnable();
        void setTxt(MT_CTSTR str);
        void setTxtVisible(bool isVisible);
        void setType(u8);
        void setValue(u8 uValue);
        u8 getValue();
        void setValueForbid(u8 uValue, bool bReset);
        u8 getValueForbid();
        cControl* getCtrl();
        bool isSwitch();
    protected:
        virtual void updatePointerPos();  // vtable slot 14
    private:
        void setupIconFrame();
        void setObjFrame(cGUIObject* pObj, f32 frame);
    private:
        cGUIObjNull* mpObjNullBtn;  // offset: 0x50
        cGUIObjNull* mpObjNullInfo;  // offset: 0x58
        cGUIObjNull* mpObjNullIcon;  // offset: 0x60
        cGUIObjTexture* mpObjTexLeft;  // offset: 0x68
        cGUIObjTexture* mpObjTexRight;  // offset: 0x70
        cGUIObjColorAdjust* mpObjInfoColAdjust;  // offset: 0x78
        cGUIObjTexture* mpObjInfoR;  // offset: 0x80
        cGUIObjTexture* mpObjInfoC;  // offset: 0x88
        cGUIObjTexture* mpObjInfoL;  // offset: 0x90
        cGUIObjMessage* mpObjTxt;  // offset: 0x98
        cControl* mpCtrl;  // offset: 0xa0
        u8 mType;  // offset: 0xa8
        u8 mValue;  // offset: 0xa9
        u8 mValueForbid;  // offset: 0xaa
        bool mIsEnable;  // offset: 0xab
        bool mFocus;  // offset: 0xac
        bool mSwitch;  // offset: 0xad
        bool mIsTxtVisible;  // offset: 0xae
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUISimpleBtn : public uGUIBase::cReferenceUIBase
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
        cReferenceUISimpleBtn();
        // Address: 0x01add000 - 0x01add001 (1 bytes)
        virtual ~cReferenceUISimpleBtn() {}
        void setup(uGUIBase* pBase, u32 instID, u32 ptrObjID, u32 msgObjID, MT_CTSTR pMsg);
        void setup(uGUIBase* pBase, cGUIInstAnimation* pInst, cGUIObject* pObj, u32 msgObjID, MT_CTSTR pMsg);
        void setMessageObj(u32 msgObjId);
        void setMessage(MT_CTSTR pMsg);
        MT_CTSTR getMessage();
        virtual void setFocus(bool b);  // vtable slot 15
        virtual bool isFocus();  // vtable slot 16
        void disable(bool b);
        bool isDisable() const;
        void setPointerObj(u32 ptrObjID);
        void setPointerObj(cGUIObject* pObj);
        virtual MtVector2 getPointerPos();  // vtable slot 10
        void useDisableFocus(u32);
    protected:
        virtual void updatePointerPos();  // vtable slot 14
    private:
        cGUIObjMessage* mpMsg;  // offset: 0x50
        MT_CHAR mMsg[256];  // offset: 0x58
        bool mFocus;  // offset: 0x158
        bool mDisable;  // offset: 0x159
        u32 mDisablefocusNo;  // offset: 0x15c
        bool mUseDisableFocus;  // offset: 0x160
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIEditBtn : public uGUIBase::cReferenceUIBase
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
        cReferenceUIEditBtn();
        // Address: 0x01addfe0 - 0x01addfe1 (1 bytes)
        virtual ~cReferenceUIEditBtn() {}
        void setup(uGUIBase* pBase, u32 instID);
        virtual void setFocus(bool b);  // vtable slot 15
        virtual bool isFocus();  // vtable slot 16
        void disable(bool b);
        bool isDisable() const;
    private:
        bool mFocus;  // offset: 0x49
        bool mDisable;  // offset: 0x4a
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUICheckList : public uGUIBase::cReferenceUIBase
    {
    public:
        enum
        {
            CF_CHECKLIST = 0,
            CF_BUTTON = 1,
        };
        enum
        {
            RESULT_BUSY = 0,
            RESULT_CONTINUE = 1,
            RESULT_CANCELED = 2,
            RESULT_DECIDED = 3,
        };
        enum BUTTON_ID
        {
            BUTTON_ID_DECIDE = 0,
            BUTTON_ID_CANCEL = 1,
            BUTTON_NUM = 2,
        };
        enum FLAG
        {
            FLAG_MOVE_BUTTON = 0,
            FLAG_MODE_SINGLE = 1,
            FLAG_WAIT = 2,
            FLAG_MAX = 3,
        };
    public:
        class MyDTI;
        class cList;
        struct DATA;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cList : public MtObject
        {
        public:
            cList();
            virtual ~cList();
        public:
            uGUIBase::cDupliInstNull mInst;  // offset: 0x8
            uGUIBase::cReferenceUICheckbox mCheckbox;  // offset: 0x30
            cGUIInstAnimation* mpInst_msg_check;  // offset: 0x80
            cGUIObjMessage* mpOBJ_msg_check_m_keyword;  // offset: 0x88
            cGUIObjPolygon* mpOBJ_msg_check_mouseover;  // offset: 0x90
            bool mIsLock;  // offset: 0x98
            MT_CTSTR mpMsgAnnounceLock;  // offset: 0xa0
            MtFloat2 mOffset;  // offset: 0xa8
        };
    public:
        struct DATA
        {
        public:
            cGUIInstNull* mpINST_Null;  // offset: 0x0
            cGUIInstNull* mpINST_Null_checkbox;  // offset: 0x8
            cGUIInstAnimation* mpINST_checkbox;  // offset: 0x10
            cGUIInstAnimation* mpINST_msg_check;  // offset: 0x18
            cGUIInstAnimation* mpINST_msg_title;  // offset: 0x20
            cGUIInstAnimation* mpINST_window;  // offset: 0x28
            cGUIInstAnimation* mpINST_window_frame;  // offset: 0x30
            cGUIObjMessage* mpTitleMsg;  // offset: 0x38
            cGUIObjNull* mpObjNullWndwLineTop;  // offset: 0x40
            cGUIObjNull* mpObjNullWndwLineBottom;  // offset: 0x48
            cGUIObjNull* mpObjNullWndwFrmLineTop;  // offset: 0x50
            cGUIObjTexture* mpObjTexWndwFrmLineTop;  // offset: 0x58
            cGUIObjTexture* mpOBJ_checkbox_box;  // offset: 0x60
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
        cReferenceUICheckList();
        virtual ~cReferenceUICheckList();
        void setup(uGUIBase* pBase, s32 num, s32 col, u32 topNullID, u32 nullCheckboxID, u32 checkboxID, u32 msg_checkID, u32 msg_titleID, u32 windowID, u32 window_frameID, u32 msg_btnID, u32 msg_cancel_btnID);
        void execute();
        virtual void update();  // vtable slot 13
        void updateDisp();
        void initAllCheck();
        void setButtonName(MT_CTSTR str);
        void setTitleName(MT_CTSTR str);
        void addFactor(MT_CTSTR str, s32 posX, s32 posY);
        void setMessage(MT_CTSTR str, s32 idx);
        void setMessage(MT_CTSTR str, s32 x, s32 y);
        void setCheck(s32 idx, bool b);
        bool isCheck(s32 idx);
        void setCheckBoxNum(u32 num, bool bResetCtrl);
        u32 getCheckBoxNum();
        u32 getCheckNum();
        void setMaxCheckNum(u32 n);
        u32 getMaxCheckNum();
        void setNeedCheckNum(u32 n);
        void setMoveDecide(bool b);
        void setModeSingle(bool b);
        void setWait(bool b);
        void setVisible(bool b);
        bool isVisible();
        void initCtrlPos(s32 sPos);
        bool isDecideOK();
        bool isCancelEnable();
        void setBit(u32 bit);
        u32 getBit();
        bool isLock(u32 uIdx);
        void setLock(u32 uIdx, bool bLock, MT_CTSTR pMsgAnnounceLock);
        u32 getResult();
        void setResult(u32 uResult);
        void setPosition(const MtVector4& pos);
        const MtVector4& getPosition();
        void setTblWindow(const u32* pTbl);
    protected:
        virtual MtSizeF calcWindowSize(f32 totalWidth, f32 rowHeight, s32 rowNum, MtFloat2& outWindowFrameOffset, MtFloat2& outTitleOffset, MtFloat2& outCheckboxOffset, MtFloat2& outButtonOffset);  // vtable slot 19
        virtual void setWindowSize(uGUIBase::cAdjustableWindow& window, const MtSize& windowSize);  // vtable slot 20
    private:
        void updateWindowSize();
    public:
        void updateWindow();
    public:
        cControl* mpCtrl;  // offset: 0x50
        uGUIBase::cMatrix* mpMtxCtrl;  // offset: 0x58
        uGUIBase::cHorizontalList* mpHCtrl;  // offset: 0x60
        u32 mCtrlFocus;  // offset: 0x68
        u32 mCtrlFocusOld;  // offset: 0x6c
        MtTypedArray<cList> mListArray;  // offset: 0x70
        nDDOUtility::cBitSet<3> mFlag;  // offset: 0x90
        uGUIBase::cAdjustableWindow mWindow;  // offset: 0x98
    protected:
        DATA mData;  // offset: 0x138
        MtSize mListSize;  // offset: 0x1a0
        uGUIBase::cReferenceUIButton mButton;  // offset: 0x1a8
        uGUIBase::cReferenceUIButton mCancelButton;  // offset: 0x338
        u32 mCheckboxID;  // offset: 0x4c8
        u32 mMsgCheckID;  // offset: 0x4cc
        u32 mCheckBoxNum;  // offset: 0x4d0
        u32 mMaxCheckNum;  // offset: 0x4d4
        u32 mNeedCheckNum;  // offset: 0x4d8
        u32 mResult;  // offset: 0x4dc
        u32 mTblWindow[11];  // offset: 0x4e0
        MtFloat2 mWindowDefaultPos;  // offset: 0x50c
        MtFloat2 mWindowFrameDefaultPos;  // offset: 0x514
        MtFloat2 mTitleDefaultPos;  // offset: 0x51c
        MtFloat2 mButtonDefaultPos;  // offset: 0x524
        MtFloat2 mCancelButtonDefaultPos;  // offset: 0x52c
        bool mIsVisible;  // offset: 0x534
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUICheckListForClan : public uGUIBase::cReferenceUICheckList
    {
    public:
        enum FORM
        {
            FORM_NONE = 0,
            FORM_MOTTO = 1,
            FORM_TIME = 2,
            FORM_FEATURE = 3,
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
        cReferenceUICheckListForClan();
        virtual ~cReferenceUICheckListForClan();
        void init(s32 enableNum, s32 max);
        void setForm(FORM form, u32& param, u32 page, bool isForSearch);
        void setForm(FORM form, CClanParam* pClanParam, u32 page, bool isForSearch);
        FORM getForm();
        u32 getPage();
        s32 getSMenuCursorValue();
        MT_CTSTR getStr(u32 idx);
        void setGUIMsgPtr(FORM form, u32 idx, cGUIObjMessage* pMsg);
        void applyMessage();
        void applyMessageEx(FORM form, u32 bit, u32 page);
    private:
        FORM mForm;  // offset: 0x538
        u32 mPage;  // offset: 0x53c
        nDDOUtility::cArray<cGUIObjMessage*, 2> mMottoMsgs;  // offset: 0x540
        nDDOUtility::cArray<cGUIObjMessage*, 2> mDayHourMsgs;  // offset: 0x550
        nDDOUtility::cArray<cGUIObjMessage*, 4> mFeatureMsgs;  // offset: 0x560
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIClanEmblem : public uGUIBase::cReferenceUIBase
    {
    public:
        enum INST_TYPE
        {
            INST_TYPE_EMBLEM = 0,
            INST_TYPE_PATTERN = 1,
            INST_TYPE_BASE = 2,
            INST_TYPE_FRAME = 3,
            TYPE_NUM = 4,
        };
        enum COLOR_TYPE
        {
            COLOR_TYPE_MAIN = 0,
            COLOR_TYPE_SUB = 1,
            COLOR_TYPE_NUM = 2,
        };
    public:
        class MyDTI;
        struct guiInst;
        struct guiDataObj;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        struct guiInst
        {
        public:
            cGUIInstAnimation* mpEmblembase;  // offset: 0x0
            cGUIInstAnimation* mpFix_pattern;  // offset: 0x8
            cGUIInstAnimation* mpEmblem;  // offset: 0x10
            cGUIInstAnimation* mpEmblemframe;  // offset: 0x18
        };
    public:
        struct guiDataObj
        {
        public:
            guiDataObj();
        public:
            cGUIObjPolygon* emblembase_back;  // offset: 0x0
            cGUIObjTexture* fix_pattern_f_pattern;  // offset: 0x8
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
        cReferenceUIClanEmblem();
        virtual ~cReferenceUIClanEmblem();
        void setup(uGUIBase* pBase, cGUIInstance* pEmblembase, cGUIInstance* pFix_pattern, cGUIInstance* pEmblem, cGUIInstance* pEmblemframe);
        void updateArcLoader(f32 deltaTime);
        virtual void setFocus(bool b);  // vtable slot 15
        virtual bool isFocus();  // vtable slot 16
        void setEmblemBase(s32 emblemBaseId);
        s32 getEmblemBaseId() const;
        void setEmblemMark(s32 emblemMarkId);
        s32 getEmblemMarkId() const;
        cGUIInstAnimation* getObj(INST_TYPE instType) const;
        void setVisible(INST_TYPE instType, bool b);
        bool isVisible(INST_TYPE instType) const;
        void setColor(COLOR_TYPE colorType, s32 colorId);
        s32 getColorId(COLOR_TYPE colorType) const;
        void applyParam(const nNet::stClanEmblem& emblem);
        void applyParam(const CClanParam& param);
    private:
        void setColor(COLOR_TYPE colorType, const MtColor& color);
    private:
        guiInst mInst;  // offset: 0x50
        guiDataObj mDataObj;  // offset: 0x70
        s32 mMarkId;  // offset: 0x80
        s32 mBaseId;  // offset: 0x84
        nDDOUtility::cArray<int, 2> mColorIds;  // offset: 0x88
        uGUIBase::cTexRefArcLoader mTexRefArcLoader;  // offset: 0x90
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUINumBox : public uGUIBase::cReferenceUIBase
    {
        // inferred: uGUIPopNumber01::evCtrlNumDecide names uGUIPopNumber01::mRefNumBox.mMode
        friend class uGUIPopNumber01;
    public:
        enum MODE
        {
            MODE_DEFAULT = 0,
            MODE_EDIT = 1,
        };
        enum
        {
            GRAYOUT_NONE = 0,
            GRAYOUT_L = 1,
            GRAYOUT_R = 2,
            GRAYOUT_LR = 3,
        };
        enum
        {
            MOUSE_OVER_LEFT = 0,
            MOUSE_OVER_RIGHT = 1,
            MOUSE_OVER_CENTER = 2,
            MOUSE_OVER_NUM = 3,
        };
        enum
        {
            NUMBER = 10,
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
        cReferenceUINumBox();
        virtual ~cReferenceUINumBox();
        void setup(uGUIBase* pUnit, cGUIInstAnimation* pInst, s32 Min, s32 Max, s32 Num);
        void setEnable(bool isEnable);
        void moveInput();
        void moveEvent();
        virtual void update();  // vtable slot 13
        virtual void setFocus(bool IsFocus);  // vtable slot 15
        virtual bool isFocus();  // vtable slot 16
        void setMode(MODE mode);
        MODE getMode() const;
        MODE getModeOld() const;
        void pushLArrow(s32 AddNum);
        void pushRArrow(s32 AddNum);
        void setLGrayOut();
        void setRGrayOut();
        void dispRefresh();
        void setNum(s32 Num);
        s32 getNum() const;
        bool isMin() const;
        bool isMax() const;
        void setMin(s32 n);
        s32 getMin() const;
        void setMax(s32 n);
        s32 getMax() const;
        void useComma();
        void changeWidth(f32 Width);
        void resetInputRange(s32 Min, s32 Max);
        MtVector2 getLeftArrowPos(uGUIBase*);
        MtVector2 getRightArrowPos(uGUIBase*);
        void addMouseTouchList(cControl* pOwner, u32 id);
        bool isEnableDispGuide() const;
    protected:
        virtual void updatePointerPos();  // vtable slot 14
    private:
        void setNumCore(s32 Num);
        void moveAnimation();
        void moveEdit();
        void changeMinMax();
        void setStatusLArrow(bool IsEnable, bool IsPush);
        void setStatusRArrow(bool IsEnable, bool IsPush);
        void setStatusArrow(bool IsLPush, bool IsRPush);
        void setWidth(f32 Size);
        void setSequence(u32 SeqId);
        void setMaxNum(s32 Num);
        void setMinNum(s32 Num);
        void setCurrentNum(s32 Num);
        void setOldNum(s32 Num);
        void setEditNum(s32 Num);
        s32 getMaxNum() const;
        s32 getMinNum() const;
        s32 getCurrentNum() const;
        s32 getOldNum() const;
        s32 getEditNum() const;
    public:
        u32 setInputEvent(u32 InputEvent);
        u32 getInputEvent();
    private:
        cGUIInstAnimation* mpInstance;  // offset: 0x50
        cGUIObjMessage* mpText;  // offset: 0x58
        cGUIObjTexture* mpRArrow;  // offset: 0x60
        cGUIObjTexture* mpLArrow;  // offset: 0x68
        cGUIObjTexture* mpRPushArrow;  // offset: 0x70
        cGUIObjTexture* mpLPushArrow;  // offset: 0x78
        cGUIObjTexture* mpBGCenter;  // offset: 0x80
        cGUIObjTexture* mpBGLeft;  // offset: 0x88
        cGUIObjTexture* mpBGRight;  // offset: 0x90
        cGUIObjTexture* mpSelCenter;  // offset: 0x98
        cGUIObjTexture* mpSelLeft;  // offset: 0xa0
        cGUIObjTexture* mpSelRight;  // offset: 0xa8
        cGUIObjPolygon* mpDirectPoly;  // offset: 0xb0
        cGUIObjPolygon* mpCMouseOver;  // offset: 0xb8
        cGUIObjPolygon* mpRMouseOver;  // offset: 0xc0
        cGUIObjPolygon* mpLMouseOver;  // offset: 0xc8
        s32 mMinNum;  // offset: 0xd0
        s32 mMaxNum;  // offset: 0xd4
        s32 mCurrentNum;  // offset: 0xd8
        s32 mOldNum;  // offset: 0xdc
        s32 mEditNum;  // offset: 0xe0
        u32 mGrayOutType;  // offset: 0xe4
        MODE mMode;  // offset: 0xe8
        MODE mModeOld;  // offset: 0xec
        bool mIsEnable;  // offset: 0xf0
        bool mIsFocus;  // offset: 0xf1
        bool mIsUseComma;  // offset: 0xf2
        bool mIsChangeNum;  // offset: 0xf3
        uGUIBase::cVerticalList* mpCtrl;  // offset: 0xf8
        s32 mNumPlace;  // offset: 0x100
        f32 mCWidth;  // offset: 0x104
        f32 mPOfsWidth;  // offset: 0x108
        f32 mLRSize;  // offset: 0x10c
        bool mIsSetInputEvent;  // offset: 0x110
        bool mIsPushAllowL;  // offset: 0x111
        bool mIsPushAllowR;  // offset: 0x112
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIPageDot : public uGUIBase::cReferenceUIBase
    {
        // inferred: uGUIGiveAndTake::setupCtrl names uGUIPopDetail01::mRefPageDot.mDispPageNum
        friend class uGUIGiveAndTake;
    public:
        class MyDTI;
        class cPageDotWork;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cPageDotWork : public MtObject
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
            cPageDotWork();
            // Address: 0x01adee50 - 0x01adee51 (1 bytes)
            virtual ~cPageDotWork() {}
        public:
            cGUIInstAnimation* mpInst;  // offset: 0x8
            cGUIObjTexture* mpObj;  // offset: 0x10
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
        cReferenceUIPageDot();
        virtual ~cReferenceUIPageDot();
        virtual void setup(uGUIBase* pParentGUI, cGUIInstance* pInstPoint, cGUIInstance* pInstPager, u32 uPageMax, u32 uDispPageNum);  // vtable slot 19
        void updateDisp();
        void setCurrentPos(u32 uPos);
        void addCurrentPos(u32 add);
        u32 getCurrentPos();
        void setDispPageNum(u32 uNum);
        u32 getDispPageNum();
        virtual void setVisible(bool visible);  // vtable slot 20
        virtual void setFocus(bool b);  // vtable slot 15
        virtual bool isFocus();  // vtable slot 16
        void setEnable(bool b);
        virtual MtVector2 getPointerPos();  // vtable slot 10
    protected:
        MtTypedArray<cPageDotWork> mWork;  // offset: 0x50
        u32 mCurrentPos;  // offset: 0x70
        u32 mDispPageNum;  // offset: 0x74
        cGUIInstAnimation* mpInstPager;  // offset: 0x78
        bool mEnable;  // offset: 0x80
        bool mFocus;  // offset: 0x81
    public:
        static MyDTI DTI;
        static const u32 INVALID_PAGE = 4294967295;
        static const u32 DIST_PAGEDOT = 20;
    };
public:
    class cReferenceUIRadioButton : public uGUIBase::cReferenceUIBase
    {
    public:
        enum MODE
        {
            MODE_NONE = 0,
            MODE_SINGLE = 1,
            MODE_MULTI = 2,
        };
        enum FLAG
        {
            FLAG_DISABLE_BUTTON = 0,
            FLAG_MAX = 1,
        };
    public:
        class MyDTI;
        class cObject;
    public:
        class MyDTI : public MtDTI
        {
        public:
            MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
            virtual MtObject* newInstance() const;  // vtable slot 2
        };
    public:
        class cObject : public uGUIBase::cSupportBase
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
            cObject();
            // Address: 0x01adc030 - 0x01adc031 (1 bytes)
            virtual ~cObject() {}
            void setSelect(bool b);
            bool isSelect();
            void setFocus(bool b);
            bool isFocus();
        private:
            void setSeq();
        private:
            uGUIBase::cDupliInstAnim mInst;  // offset: 0x18
            cGUIObjMessage* mpObjMsgTitle;  // offset: 0x40
            cGUIObjNull* mpObjNullPointer;  // offset: 0x48
            cGUIObjPolygon* mpObjMouseOver;  // offset: 0x50
            bool mIsSelect;  // offset: 0x58
            bool mIsFocus;  // offset: 0x59
        public:
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
        cReferenceUIRadioButton();
        virtual ~cReferenceUIRadioButton();
        void setup(uGUIBase* pBase, cGUIInstance* pInst, s32 num, s32 select, const MtVector2& nextMove);
        virtual void execute();  // vtable slot 19
        virtual void setFocus(bool b);  // vtable slot 15
        virtual bool isFocus();  // vtable slot 16
        void setMessage(u32 idx, MT_CTSTR msg);
        void resetItemAll();
        virtual s32 getVItemNum();  // vtable slot 17
        void deleteInstance();
        uGUIBase::cVerticalList* getCtrl();
        s32 size();
        const MtVector2& getNextOffset();
        void setSelect(s32 idx, bool select);
        s32 getSelectIndex();
        s32 getCurrentPos();
        void setDisableButton(bool);
        void addMouseTouchList(cControl* pCtrl, s32 startPos, s32 vol, bool autoErase);
    protected:
        virtual bool setupPointerPos();  // vtable slot 8
        virtual void updatePointerPos();  // vtable slot 14
    protected:
        MODE mMode;  // offset: 0x4c
        bool mFocus;  // offset: 0x50
        MtTypedArray<cObject> mArray;  // offset: 0x58
        cObject mSingleObject;  // offset: 0x78
        uGUIBase::cVerticalList* mpCtrl;  // offset: 0xd8
        MtVector2 mNextOffset;  // offset: 0xe0
        s32 mSelectIdx;  // offset: 0xe8
        nDDOUtility::cBitSet<1> mFlag;  // offset: 0xec
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUINumPager : public uGUIBase::cReferenceUIBase
    {
        // inferred: uGUICaplinkFriendList::eventAdjustPage names uGUICaplinkFriendList::mMain.mPage.mNum
        friend class uGUICaplinkFriendList;
        // inferred: uGUICaplinkTalk::moveEvent names uGUICaplinkTalk::mMain.mPage.mNum
        friend class uGUICaplinkTalk;
    public:
        enum
        {
            MOUSE_OVER_LEFT = 0,
            MOUSE_OVER_RIGHT = 1,
            MOUSE_OVER_WHEEL = 2,
            MOUSE_OVER_NUM = 3,
        };
        enum
        {
            COLOR_DEFAULT = 0,
            COLOR_BLACK = 1,
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
        cReferenceUINumPager();
        void setup(uGUIBase* pBase, cGUIInstance* pInst, s32 num, s32 max, u8 uColorType);
        void execute();
        virtual void update();  // vtable slot 13
        void setNum(s32 n);
        s32 getNum() const;
        void setMax(s32 n);
        s32 getMax();
        void setCtrl(cControl* pCtrl);
        void setOwnerCtrl(cControl* pOwnerCtrl);
        cControl* getOwnerCtrl();
        void addNum(s32 n);
        void changeString();
        void setColorType(u8 uColorType);
        void setLimitCtrl(bool flg);
        void addMouseTouchList(cControl* pOwner);
        cGUIObjPolygon* getMouseOverObjectL();
        cGUIObjPolygon* getMouseOverObjectR();
        void addMouseWheelTouchList(cGUIInstance* instWheel);
        void addMouseWheelTouchListInstAnimation(u32 instAnimationId);
        void addMouseWheelTouchListInstScissorMask(u32 instScissorMaskId);
        void addMouseWheelTouchList(cGUIObject* objWheel);
        void setupRankView(s32 total, s32 viewMax);
    private:
        cGUIObjMessage* mpOBJ_message;  // offset: 0x50
        cGUIObjTextureSet* mpOBJ_left;  // offset: 0x58
        cGUIObjTextureSet* mpOBJ_right;  // offset: 0x60
        cGUIObjPolygon* mpOBJ_mouseover_left;  // offset: 0x68
        cGUIObjPolygon* mpOBJ_mouseover_right;  // offset: 0x70
        s32 mNum;  // offset: 0x78
        s32 mMax;  // offset: 0x7c
        u8 mColorType;  // offset: 0x80
        bool mbLimitCtrl;  // offset: 0x81
        bool mIsLoop;  // offset: 0x82
        cControl* mpPagerCtrl;  // offset: 0x88
        cControl* mpOwnerCtrl;  // offset: 0x90
        bool mIsRankView;  // offset: 0x98
        s32 mTotal;  // offset: 0x9c
        s32 mDispNumOnPage;  // offset: 0xa0
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIIconButton : public uGUIBase::cReferenceUIBase
    {
    public:
        enum SHAPE
        {
            SHAPE_QUAD = 0,
            SHAPE_CIRCLE = 1,
        };
        enum TYPE
        {
            TYPE_MAN = 120,
            TYPE_WOMAN = 121,
            TYPE_LIST = 122,
            TYPE_UPDATE = 123,
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
        cReferenceUIIconButton();
        virtual ~cReferenceUIIconButton();
        void setup(uGUIBase* pUnit, cGUIInstAnimation* inst, SHAPE shape);
        void setPositionX(f32 x);
        f32 getPositionX() const;
        virtual void setFocus(bool isFocus);  // vtable slot 15
        virtual bool isFocus();  // vtable slot 16
        void setSelected(bool isSelected);
        bool isSelected() const;
        void setState(bool isFocus, bool isSelected);
        void setIconFrame(s32 iconFrame);
        void setColorFrame(s32 colorFrame);
        void setJobId(u32 jobId);
        void setType(TYPE type);
        s32 getJobId() const;
        void setEnable(bool isEnable);
        virtual void update();  // vtable slot 13
    protected:
        virtual void updatePointerPos();  // vtable slot 14
    private:
        cGUIObjTexture* mOBJ_fix_job_f_job;  // offset: 0x50
        cGUIObjTexture* mOBJ_fix_job_waku01;  // offset: 0x58
        s32 mIconFrame;  // offset: 0x60
        s32 mColorFrame;  // offset: 0x64
        SHAPE mShape;  // offset: 0x68
        bool mIsFocus;  // offset: 0x6c
        bool mIsSelected;  // offset: 0x6d
        bool mIsEnable;  // offset: 0x6e
        u32 mJobId;  // offset: 0x70
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIEditSlider : public uGUIBase::cReferenceUIBase
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
        cReferenceUIEditSlider();
        virtual ~cReferenceUIEditSlider();
        void setup(uGUIBase* pBase, cGUIInstance* pInst, s32 sizeX, s32 div, s32 pos, MT_CTSTR leftName, MT_CTSTR topName);
        void setupSize();
        void setSliderPos(s32 n, bool bInit);
        s32 getSliderPos();
        f32 getDiv() const;
        void setSliderOffset(s32 n);
        bool executeMouse();
        bool execute(bool isSkipMouse);
        virtual void setFocus(bool b);  // vtable slot 15
        virtual bool isFocus();  // vtable slot 16
        virtual MtVector2 getPointerPos();  // vtable slot 10
        bool isVisibleNum();
        void setVisibleNum(bool);
        void setDefaultPos(s32 sPos);
        void setDecidePos(s32 sPos);
        void setVisibleTexPoint(bool visible, u32 index);
        void setVisibleTexPointAll(bool visible);
        void setVisibleDefaultObj(bool visible);
        void setVisibleTexDecideObj(bool visible);
        void setVisibleNullSlider(bool visible);
        void setIsLock(bool isLock);
        bool isSliderLock() const;
        uGUIBase::cHorizontalList* getControl() const;
        void setSpdUpChk(u32 uValue);
        void setSpdUpAddAdd(s32 sValue);
        void setSpdUpAddMax(s32 sValue);
    protected:
        virtual void setMsgNumStr(s32 n, bool bInit);  // vtable slot 19
        virtual void updatePointerPos();  // vtable slot 14
    protected:
        cGUIObjMessage* mpMsgNum;  // offset: 0x50
        bool mIsSliderLock;  // offset: 0x58
    private:
        cGUIObjTexture* mpTexSlider;  // offset: 0x60
        cGUIObjTexture* mpTexCenter;  // offset: 0x68
        cGUIObjTexture* mpTexRight;  // offset: 0x70
        cGUIObjTexture* mpTexLeft;  // offset: 0x78
        cGUIObjTexture* mpTexPointDecide;  // offset: 0x80
        cGUIObjTexture* mpTexPoint[5];  // offset: 0x88
        cGUIObjMessage* mpMsgHead;  // offset: 0xb0
        cGUIObjMessage* mpMsgLeft;  // offset: 0xb8
        cGUIObjNull* mpObjNullSlider;  // offset: 0xc0
        cGUIObjPolygon* mpObjDefault;  // offset: 0xc8
        cGUIObjPolygon* mpObjMouseOverSlider;  // offset: 0xd0
        f32 mSizeX;  // offset: 0xd8
        f32 mDiv;  // offset: 0xdc
        s32 mPos;  // offset: 0xe0
        s32 mPosDefault;  // offset: 0xe4
        s32 mPosDecide;  // offset: 0xe8
        s32 mSliderOffset;  // offset: 0xec
        uGUIBase::cHorizontalList* mpCtrl;  // offset: 0xf0
        uGUIBase::cCalcMovePos mMovePos;  // offset: 0xf8
        bool mVisibleNum;  // offset: 0x118
        bool mFocus;  // offset: 0x119
        u32 mDefSpdUpChk;  // offset: 0x11c
        f32 mDefSpdAddAddRate;  // offset: 0x120
        f32 mDefSpdAddAddMaxRate;  // offset: 0x124
        u32 mSliderDragFlow;  // offset: 0x128
        static const u32 POINTDIV_MAX = 5;
    public:
        static MyDTI DTI;
    };
public:
    class cReferenceUIIconFriend : public uGUIBase::cReferenceUIBase
    {
    public:
        enum
        {
            INVISIBLE = 0,
            GOOD = 1,
            BLOCK = 2,
            NORMAL = 3,
            OWNER = 4,
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
        cReferenceUIIconFriend();
        // Address: 0x01ade870 - 0x01ade871 (1 bytes)
        virtual ~cReferenceUIIconFriend() {}
        void setup(uGUIBase* pUnit, cGUIInstance* pInst);
        void setStatus(u32 status);
    public:
        static MyDTI DTI;
    };
public:
    class cScrollCtrl
    {
        // inferred: uGUIQuestList::clearInfo names uGUIQuestList::mInfo.mScrollCtrl.::uGUIBase::cScrollCtrl::mBar.::uGUIBase::cSupportInstAnim::mpInstance
        friend class uGUIQuestList;
    public:
        cScrollCtrl();
        // Address: 0x01add6e0 - 0x01add6e1 (1 bytes)
        virtual ~cScrollCtrl() {}
        void setup(uGUIBase* pUnit, cGUIInstance* pInstScrollBar, cGUIInstance* pInstNullScroll, cGUIObject* pObjWheelArea);
        void setupNullDefaultPos();
        void setNullDefaultPos(f32 pos);
        f32 getNullDefaultPos();
        void setBarSize(f32 bar_length, f32 list_range, f32 disp_range);
        void setSliderPos(f32 scroll_pos, bool isImmediate);
        f32 getSliderPos();
        void setScrollDist(s32 dist);
        void moveScroll(s32 scroll_num);
        bool isScrollTop();
        bool isScrollBottom();
        void setScrollTop();
        void setScrollBottom();
        void resetPos();
        virtual bool update(f32 delta_time);  // vtable slot 2
        virtual bool updateMouseOperation(f32 delta_time);  // vtable slot 3
        void setAutoUpdateMouseOperation(bool isAuto);
        uGUIBase::cReferenceUIScrollBar& getBar();
        const uGUIBase::cCalcMovePos& getPosCtrl();
        cGUIInstNull* getInstNullScroll();
    protected:
        bool updateScroll(f32 delta_time);
    protected:
        cGUIInstNull* mpInstNullScroll;  // offset: 0x8
        uGUIBase::cReferenceUIScrollBar mBar;  // offset: 0x10
        uGUIBase::cCalcMovePos mPosCtrl;  // offset: 0xb8
        f32 mNullDefaultPos;  // offset: 0xd8
        s32 mScrollDist;  // offset: 0xdc
        bool mIsAutoUpdateMouseOperation;  // offset: 0xe0
    };
public:
    class cScrollList : public uGUIBase::cScrollCtrl
    {
        // inferred: uGUIBoxGachaInfo::evAdjustTab names uGUIBoxGachaInfo::mList.mListCtrl.mpOwner
        friend class uGUIBoxGachaInfo;
        // inferred: uGUIInfo::evCtrlMouse names uGUIInfo::mList.mListCtrl.mInfoArray.::MtArray::mLength
        friend class uGUIInfo;
        // inferred: uGUIKeyConfig::getCategoryListIndex names uGUIKeyConfig::mCategoryList.::uGUIKeyConfig::cList::mScrollList.mpVCtrl
        friend class uGUIKeyConfig;
        // inferred: uGUIMenuTutorial::updateWaitCaption names uGUIMenuTutorial::mScrollListCaption.mIsDecide
        friend class uGUIMenuTutorial;
        // inferred: uGUIMyRoom::getItemIndex names uGUIMyRoom::mList.mScrollList.mpVCtrl
        friend class uGUIMyRoom;
        // inferred: uGUINewspaper::initRankingActiveControl names uGUINewspaper::mRankingScrollbar.mpOwner
        friend class uGUINewspaper;
        // inferred: uGUISystemMsg::setPointerPriority names uGUISystemMsg::mScrollList.mIsAutoDispPointer
        friend class uGUISystemMsg;
    public:
        using SetupFunc = void(uGUIBase::*)(uGUIBase::cScrollListItemBase*, uGUIBase::cScrollListInfoBase*, u32);
        using HideFunc = void(uGUIBase::*)(uGUIBase::cScrollListItemBase*);
        using MsgEventFunc = bool(uGUIBase::*)(cControl::Message*);
    public:
        cScrollList();
        virtual ~cScrollList();
        void addItem(uGUIBase::cScrollListItemBase* pItem);
        void clearInfo();
        void addInfo(uGUIBase::cScrollListInfoBase* pInfo);
        void addVisualItem(uGUIBase::cScrollListItemBase* pItem);
        void addVisualInfo(uGUIBase::cScrollListInfoBase* pInfo);
        void setupList(f32 bar_length, f32 disp_range, f32 visible_top, f32 visible_bottom, s32 currentPos, f32 sliderPos, bool useLR);
        void setupList(cGUIInstNull* pInstMask, u32 topObjId, u32 centerObjId, u32 bottomObjId, s32 currentPos, f32 sliderPos, bool useLR);
        void clear();
        void setListPos(bool isImmediate);
        void setListPos(u32 pos, bool isImmediate);
        void setListPos(s32 pos, bool isImmediate);
        u32 getListPos() const;
        bool isVisiblePos(u32 pos);
        bool isVisiblePos();
        virtual bool update(f32 delta_time);  // vtable slot 2
        virtual bool updateMouseOperation(f32 delta_time);  // vtable slot 3
        void setSliderPosEx(f32 scroll_pos, bool isImmediate);
        void setupAllItem();
        void setAutoDispPointer(bool isAutoDisp);
        void setAutoDispPointer(bool isAutoDisp, u32 prio);
        void setAutoDispCursorPointer(bool isAutoDisp);
        void setAutoDispCursorPointer(bool isAutoDisp, u32 prio);
        bool isAutoDispPointer();
        u32 getPrioGrp();
        void setDirectPosSet(bool isDirectPosSet);
        bool isDirectPosSet() const;
        void resetPointerPos();
        const MtVector2& getPointerPos() const;
        u32 length() const;
        uGUIBase::cScrollListItemBase* getItem(u32 index);
        uGUIBase::cScrollListInfoBase* getInfo(u32 index);
        uGUIBase::cScrollListItemBase* getVisualItem(u32);
        uGUIBase::cScrollListInfoBase* getVisualInfo(u32 index);
        u32 getInfoNum() const;
        u32 getVisualInfoNum() const;
        MtTypedArray<uGUIBase::cScrollListInfoBase>& getListInfo();
        MtTypedArray<uGUIBase::cScrollListInfoBase>& getListVisualInfo();
        void setAutoDeleteInfo(bool isAutoDelete);
        uGUIBase::cVerticalList* getCtrl();
        void executeCtrl();
        void setIsInputEvent(bool flag);
        bool isInputEvent() const;
        s32 getCurrentPos() const;
        void setCurrentPos(s32 pos);
        s32 getOldPos() const;
        s32 getDetailPos() const;
        void setFocus(bool flag);
        void setEnableKey(bool flag);
        bool isEnableKey();
        void setTrgLoop(bool flag);
        bool moveEvent();
        u32 getInputEvent();
        void setDecideEventSMenu();
        bool isDecideEventSMenu() const;
        uGUIBase::cReferenceUIVlCursor* getCursor();
        uGUIBase::cReferenceUIVlCursor& refCursor();
        void setVisibleCursor(bool bVisible);
        void setFocusCursor(bool bFocus);
        u32 getDispIndex(uGUIBase::cScrollListItemBase* pItem);
        uGUIBase::cScrollListItemBase* getCurrentItem();
        void setDecide(bool flag);
        bool isDecide() const;
        void setNoScrollNoCursor();
        void setScreenCenterMargin(f32 margin);
        void eraseMouseTouchList(s32 sPos, s32 sClickVol);
        void offLRKeyPageSkip();
        void setIsPullDown(bool flag);
        bool isPullDown() const;
        void setSeqChangeCallSetupFunc(bool flag);
        void setIsAdjustDecide(bool);
        bool isAdjustDecide() const;
        void setIsAdjustTopbtn(bool);
        bool isAdjustTopbtn() const;
        void setIsAdjustChkout(bool flag);
        bool isAdjustChkout() const;
    private:
        bool updateScroll(f32 delta_time);
        void updateCursor();
    protected:
        void updateListItem();
        uGUIBase::cScrollListItemBase* getBlankListItem(u8 type);
        uGUIBase::cScrollListItemBase* getBlankVisualListItem(u8 type);
        bool isInScreen(uGUIBase::cScrollListInfoBase* pInfo);
        bool isInMouseReactionRange(uGUIBase::cScrollListInfoBase* pInfo);
        void setListFocus(bool isClear);
        void setupPointerPos(uGUIBase::cScrollListItemBase* pItem);
    public:
        void setup(uGUIBase* pUnit, cGUIInstance* pInstScrollBar, cGUIInstance* pInstNullScroll, cGUIObject* pObjWheelArea);
        void setupList(f32 bar_length, f32 disp_range, bool isResetPos);
        void setupCtrl(bool useLR);
        bool callMsgEventFunc(cControl::Message* msg);
        void setupCursor(cGUIInstance* pInst, const MtFloat2& size, f32 fDistY);
        void clearCursorFocus();
        void resetListItem();
        void setAutoSetVisibleSize(bool isAutoSet);
        s32 getClickVol() const;
        void setClickVol(s32 Vol);
    protected:
        uGUIBase* mpOwner;  // offset: 0xe8
        MtTypedArray<uGUIBase::cScrollListItemBase> mItemArray;  // offset: 0xf0
        MtTypedArray<uGUIBase::cScrollListInfoBase> mInfoArray;  // offset: 0x110
        MtTypedArray<uGUIBase::cScrollListItemBase> mVisualItemArray;  // offset: 0x130
        MtTypedArray<uGUIBase::cScrollListInfoBase> mVisualInfoArray;  // offset: 0x150
        SetupFunc mpSetupFunc;  // offset: 0x170
        HideFunc mpHideFunc;  // offset: 0x180
        MsgEventFunc mpMsgEventFunc;  // offset: 0x190
        uGUIBase::cVerticalList* mpVCtrl;  // offset: 0x1a0
        uGUIBase::cReferenceUIVlCursor mCursor;  // offset: 0x1b0
        f32 mVisibleTopPos;  // offset: 0x260
        f32 mVisibleBottomPos;  // offset: 0x264
        f32 mScreenCenterMargin;  // offset: 0x268
        u32 mListPos;  // offset: 0x26c
        u32 mDispNum;  // offset: 0x270
        MtVector2 mPointObjPos;  // offset: 0x278
        MtVector2 mPointerPos;  // offset: 0x280
        u32 mPointerPrio;  // offset: 0x288
        bool mIsAutoDispPointer;  // offset: 0x28c
        bool mIsDecide;  // offset: 0x28d
        bool mIsCursorClear;  // offset: 0x28e
        bool mIsNoScrollNoCursor;  // offset: 0x28f
        bool mIsInputEvent;  // offset: 0x290
        bool mIsDirectPosSet;  // offset: 0x291
        bool mDecideEventSmenu;  // offset: 0x292
        bool mIsExecuteCtrl;  // offset: 0x293
        bool mIsPullDown;  // offset: 0x294
        bool mClearFirst;  // offset: 0x295
        bool mSeqChangeCallSetupFunc;  // offset: 0x296
        bool mIsAdjustDecide;  // offset: 0x297
        bool mIsAdjustTopbtn;  // offset: 0x298
        bool mIsAdjustChkout;  // offset: 0x299
        bool mIsAutoSetVisibleSize;  // offset: 0x29a
        s32 mClickVol;  // offset: 0x29c
        bool mIsFocusCursor;  // offset: 0x2a0
    };
public:
    class cReferenceUIPullDown : public uGUIBase::cReferenceUIBase
    {
    public:
        enum STATE
        {
            STATE_NONE = 0,
            STATE_OPEN_INIT = 1,
            STATE_OPEN_LOOP = 2,
            STATE_IDLE = 3,
            STATE_CLOSE_INIT = 4,
            STATE_CLOSE_LOOP = 5,
            STATE_MAX = 6,
        };
        enum SE
        {
            SE_OPEN = 0,
            SE_CLOSE = 1,
            SE_SELECT = 2,
        };
    public:
        class MyDTI;
        struct DATA;
        class cData;
        class cScrollListItemBasePD;
        class cMsg;
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
            cGUIInstAnimation* mpINST_msg_pulldown;  // offset: 0x0
            cGUIInstAnimation* mpINST_mask_pulldown;  // offset: 0x8
            cGUIInstAnimation* mpINST_window;  // offset: 0x10
            cGUIInstAnimation* mpINST_mask_pulldownlist;  // offset: 0x18
            cGUIInstAnimation* mpINST_msg_list;  // offset: 0x20
            cGUIInstAnimation* mpINST_Scrbar;  // offset: 0x28
            cGUIInstNull* mpINST_Null_Scroll01Id;  // offset: 0x30
            cGUIInstNull* mpINST_Null_pull_scroll;  // offset: 0x38
            cGUIObjTexture* mpOBJ_msg_pulldown_left;  // offset: 0x40
            cGUIObjTexture* mpOBJ_msg_pulldown_center;  // offset: 0x48
            cGUIObjTexture* mpOBJ_msg_pulldown_right;  // offset: 0x50
            cGUIObjPolygon* mpOBJ_mask_pulldownlist_top;  // offset: 0x58
            cGUIObjPolygon* mpOBJ_mask_pulldownlist_center;  // offset: 0x60
            cGUIObjPolygon* mpOBJ_mask_pulldownlist_bottom;  // offset: 0x68
            cGUIObjTexture* mpOBJ_msg_pulldown_left_focus;  // offset: 0x70
            cGUIObjTexture* mpOBJ_msg_pulldown_right_focus;  // offset: 0x78
            cGUIObjTexture* mpOBJ_msg_pulldown_center_focus;  // offset: 0x80
            cGUIObjPolygon* mpOBJ_mask_pulldown_center;  // offset: 0x88
            cGUIObjPolygon* mpOBJ_msg_pulldown_mouseover;  // offset: 0x90
            cGUIObjPolygon* mpOBJ_msg_list_mouseover;  // offset: 0x98
            cGUIObjMessage* mpOBJ_msg_list_m_list;  // offset: 0xa0
        };
    public:
        class cScrollListItemBasePD : public uGUIBase::cScrollListItemBase
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
            cScrollListItemBasePD();
        public:
            uGUIBase::cReferenceUIPullDown* mpOwner;  // offset: 0x58
            static MyDTI DTI;
        };
    public:
        class cMsg : public MtObject
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
            cMsg();
            virtual ~cMsg();
        public:
            MtString mStr;  // offset: 0x8
            MtColor mColor;  // offset: 0x10
            bool mIsAnalyze;  // offset: 0x14
            static MyDTI DTI;
        };
    public:
        class cData : public MtObject
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
            cData();
            // Address: 0x01add790 - 0x01add791 (1 bytes)
            virtual ~cData() {}
            virtual void setup(uGUIBase::cReferenceUIPullDown* pPar, cGUIInstance* pInstance);  // vtable slot 6
        public:
            uGUIBase::cDupliInstAnim mInst;  // offset: 0x8
            cGUIObjMessage* mpMsg;  // offset: 0x30
            cGUIObjPolygon* mpMouseover;  // offset: 0x38
            uGUIBase::cReferenceUIPullDown::cScrollListItemBasePD mScrDispData;  // offset: 0x40
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
        cReferenceUIPullDown();
        virtual ~cReferenceUIPullDown();
        void setup(uGUIBase* pBase, u32 msg_pulldownID, u32 mask_pulldownID, u32 windowID, u32 cursorID, u32 mask_pulldownlistID, u32 msg_listID, u32 null_pull_scrollID, u32 null_scroll01ID, u32 scrbarID, f32 uiWidth, s32 visibleSize);
        void setup(uGUIBase* pBase, cGUIInstance* pMsgPulldown, cGUIInstance* pMaskPulldown, cGUIInstance* pWindow, cGUIInstance* pCursor, cGUIInstance* pMaskPulldownList, cGUIInstance* pMsgList, cGUIInstance* pNullPullScrollId, cGUIInstance* pNullScroll01Id, cGUIInstance* pScrbar, f32 uiWidth, s32 visibleSize);
        void setSkillMode(bool);
        void addMessage(MT_CTSTR str, bool isAnalyze);
        void setMessage(u32 idx, MT_CTSTR str, bool isAnalyze);
        void setTitle(MT_CTSTR str);
        void setMessageColor(u32 idx, MtColor color);
        MT_CTSTR getMessage(u32);
        MT_CTSTR getNowMessage();
        u32 getMessageNum();
        virtual void update();  // vtable slot 13
        void execute();
        bool moveEvent();
        void deleteMsgList();
        void setIdx(s32 idx);
        s32 getIdx() const;
        bool wakeup();
        void close(bool isAnim);
        bool isAnimationEnd();
        bool isWakeup() const;
        STATE getState() const;
        void setState(STATE state);
        virtual void setFocus(bool b);  // vtable slot 15
        virtual bool isFocus();  // vtable slot 16
        s32 getVisibleSize();
        void setVisibleSize(s32 n);
        void setDecide(bool bDecide);
        bool isDecide();
        void setCancel(bool bCancel);
        bool isCancel();
        void setUseKey(bool b);
        bool isUseKey();
        void setUseAnimation(bool);
        f32 getListSizeH();
        virtual void reqSE(SE type);  // vtable slot 19
        virtual void changeTitleText(u32 idx);  // vtable slot 20
        u32 addMouseTouchList(cControl* pOwner, s32 pos, s32 vol, bool autoErase);
        void setIsInputEvent(bool flag);
        bool isInputEvent();
        bool isForbid() const;
        void setForbid(bool bForbid, s32 sIdx);
        virtual void updateString(cData* pData, u32 curIdx);  // vtable slot 21
        uGUIBase::cScrollList& getScrollList();
        MtTypedArray<cData>& getDataArray();
        MtTypedArray<cMsg>& getMsgArray();
    protected:
        virtual void updatePointerPos();  // vtable slot 14
        void createDuplicate(u32 num);
        void initScrollList(u32 startIdx);
        void updateScrollList(u32 listNum);
        void udjustCursor(bool isImmediate);
        void resetFormSize();
        void resetWindowSize();
        void evMove();
        void evCancel();
        void evDecide();
        void setSequenceIdEx(cGUIInstAnimation* pInst, u32 id);
        virtual f32 setupObject(f32 width);  // vtable slot 22
        virtual cData* newData();  // vtable slot 23
        virtual cMsg* newMsg();  // vtable slot 24
        void setTitleText(const cMsg* msg);
    protected:
        DATA mData;  // offset: 0x50
        uGUIBase::cReferenceUIVlCursor mCursor;  // offset: 0x100
        uGUIBase::cScrollList mScrList;  // offset: 0x1b0
        uGUIBase::cExGUIMessageObj64 mTitleText;  // offset: 0x460
        uGUIBase::cCalcMovePos mMovePos;  // offset: 0x4c8
        uGUIBase::cAdjustableWindow mWindow;  // offset: 0x4e8
        cControl* mpCtrl;  // offset: 0x588
        u32 mPosFirst;  // offset: 0x590
        s32 mVisibleSize;  // offset: 0x594
        s32 mCursorIdx;  // offset: 0x598
        bool mIsUseKey;  // offset: 0x59c
        bool mIsUseAnim;  // offset: 0x59d
        STATE mState;  // offset: 0x5a0
        f32 mEndPos;  // offset: 0x5a4
        MtTypedArray<cData> mDataArray;  // offset: 0x5a8
        MtTypedArray<cMsg> mMsgArray;  // offset: 0x5c8
        bool mFocus;  // offset: 0x5e8
        bool mDecide;  // offset: 0x5e9
        bool mCancel;  // offset: 0x5ea
        bool mSkillMode;  // offset: 0x5eb
        bool mIsInputEvent;  // offset: 0x5ec
        bool mIsForbid;  // offset: 0x5ed
        f32 mListSizeH;  // offset: 0x5f0
        f32 mDefaultMouseOverWidth;  // offset: 0x5f4
        f32 mDefaultMessageWidth;  // offset: 0x5f8
        f32 mDefaultCenterWidth;  // offset: 0x5fc
        f32 mDeltaWidth;  // offset: 0x600
    public:
        static MyDTI DTI;
        static const u32 VISIBLESIZE_MAX = 7;
        static const u32 LIST_HEIGHT = 24;
    };
public:
    class cReferenceUIPullDownSkill : public uGUIBase::cReferenceUIPullDown
    {
    public:
        class MyDTI;
        struct DATA;
        class cMsgEx;
        class cDataEx;
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
            cGUIObjMessage* mpOBJ_list;  // offset: 0x0
            cGUIObjMessage* mpOBJ_num;  // offset: 0x8
            cGUIObjMessage* mpOBJ_jp;  // offset: 0x10
        };
    public:
        class cMsgEx : public uGUIBase::cReferenceUIPullDown::cMsg
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
            cMsgEx();
            virtual ~cMsgEx();
        public:
            MtString mNum;  // offset: 0x18
            static MyDTI DTI;
        };
    public:
        class cDataEx : public uGUIBase::cReferenceUIPullDown::cData
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
            cDataEx();
            // Address: 0x01addaa0 - 0x01addaa1 (1 bytes)
            virtual ~cDataEx() {}
            virtual void setup(uGUIBase::cReferenceUIPullDown* pPar, cGUIInstance* pInstance);  // vtable slot 6
        public:
            cGUIObjMessage* mpMsgNum;  // offset: 0xa0
            cGUIObjMessage* mpMsgJp;  // offset: 0xa8
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
        cReferenceUIPullDownSkill();
        virtual ~cReferenceUIPullDownSkill();
        void addMessage(MT_CTSTR str, MT_CTSTR num);
        void setMessage(u32 idx, MT_CTSTR str, MT_CTSTR num);
        void changeTitleText(MT_CTSTR title, MT_CTSTR num);
        void setup(uGUIBase* pBase, cGUIInstance* pPulldown, cGUIInstance* pMaskPulldown, cGUIInstance* pWindow, cGUIInstance* pCursor, cGUIInstance* pMaskPulldownList, cGUIInstance* pMsgList, cGUIInstance* pNullPullScrollId, cGUIInstance* pNullScroll01Id, cGUIInstance* pScrbar, f32 uiWidth, s32 visibleSize);
        virtual void updateString(uGUIBase::cReferenceUIPullDown::cData* pData, u32 curIdx);  // vtable slot 21
    protected:
        virtual uGUIBase::cReferenceUIPullDown::cData* newData();  // vtable slot 23
        virtual cMsgEx* newMsg();  // vtable slot 24
        virtual void changeTitleText(u32 idx);  // vtable slot 20
    protected:
        uGUIBase::cExGUIMessageObj64 mNumText;  // offset: 0x608
        cGUIObjMessage* mpMsgJp;  // offset: 0x670
        DATA mData;  // offset: 0x678
    public:
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
    virtual bool isSMENUdecide();  // vtable slot 62
    virtual bool isSMENUcancel();  // vtable slot 63
    virtual bool isSMENUchkout();  // vtable slot 64
    virtual bool isSMENUtopbtn();  // vtable slot 65
    bool isChatSubMenu();
    u32 evCtrlDummy(cControl::Message* msg);
    u32 evCtrlControlMgrCancel(cControl::Message* pMsg);
    u32 evCtrlControlMgrStart(cControl::Message* pMsg);
    u32 evCtrlControlMgrDecide(cControl::Message* pMsg);
    u32 evCtrlControlMgrTabMove(cControl::Message* pMsg);
    u32 evCtrlControlMgrVListMove(cControl::Message* pMsg);
    u32 evCtrlControlMgrHListMove(cControl::Message* pMsg);
    u32 evCtrlPageListMoveParent(cControl::Message* msg);
    u32 evCtrlPageListMoveCursor(cControl::Message* msg);
    u32 evCtrlPageListMovePage(cControl::Message* msg);
    u32 evCtrlPageListMouseSelect(cControl::Message* msg);
    u32 evCtrlPageListMouseDecide(cControl::Message* msg);
    void deleteControl(cControl* obj);
    void addControl(cControl* pCtrl);
    void setupEquipEnableJobIcon(cReferenceUIIconJob(&icons)[10], u32 item_id);
protected:
    u32 evCtrlBtnGuideMouseLClick(cControl::Message* msg);
public:
    bool isBtnGuideInput(u32 idx);
    void addBtnGuideCtrl(cControl* pCtrl);
    u32 evCtrlTextBoxDecide(cControl::Message* msg);
    u32 evCtrlTextBoxCancel(cControl::Message* msg);
protected:
    u32 evCtrlcReferenceUIToggleBtnSwitch(cControl::Message* msg);
private:
    u32 evCtrlcReferenceUICheckListCancel(cControl::Message* msg);
    u32 evCtrlcReferenceUICheckListMove(cControl::Message* msg);
    u32 evCtrlcReferenceUICheckListMtxDecide(cControl::Message* msg);
    u32 evCtrlcReferenceUICheckListHListDecide(cControl::Message* msg);
    u32 evCtrlcReferenceUICheckListMtxClick(cControl::Message* msg);
    u32 evCtrlcReferenceUICheckListHListClick(cControl::Message* msg);
public:
    u32 cReferenceUINumBoxEvCtrl(cControl::Message* pMsg, u32 InputEvent);
    u32 cReferenceUINumBoxEvCtrlCursorRMove(cControl::Message* pMsg);
    u32 cReferenceUINumBoxEvCtrlCursorLMove(cControl::Message* pMsg);
    u32 cReferenceUINumBoxEvCtrlCursorUMove(cControl::Message* pMsg);
    u32 cReferenceUINumBoxEvCtrlCursorDMove(cControl::Message* pMsg);
    u32 cReferenceUINumBoxEvCtrlCursorDecide(cControl::Message* pMsg);
    u32 cReferenceUINumBoxEvCtrlCursorCancel(cControl::Message* pMsg);
    u32 cReferenceUINumBoxEvCtrlLClickOOMT(cControl::Message* pMsg);
    u32 cReferenceUINumBoxEvCtrlMouseWheel(cControl::Message* pMsg);
    u32 evCtrlNumPagerMouseClick(cControl::Message* msg);
    u32 evCtrlNumPagerMouseWheel(cControl::Message* msg);
private:
    u32 evCtrlScrollListUp(cControl::Message* msg);
    u32 evCtrlScrollListDown(cControl::Message* msg);
    u32 evCtrlScrollListLeft(cControl::Message* msg);
    u32 evCtrlScrollListRight(cControl::Message* msg);
    u32 evCtrlScrollListMouseSelect(cControl::Message* msg);
    u32 evCtrlScrollListMouseDecide(cControl::Message* msg);
    u32 evCtrlScrollListMouseLClickOOMT(cControl::Message* msg);
    u32 evCtrlScrollListDecide(cControl::Message* msg);
    u32 evCtrlScrollListTopbtn(cControl::Message* msg);
    u32 evCtrlScrollListChkout(cControl::Message* msg);
public:
    u32 cReferenceUIPullDown_evCtrlCancel(cControl::Message* msg);
    u32 cReferenceUIPullDown_evCtrlDecide(cControl::Message* msg);
    void updateScrollListDisp_PullDown(cScrollListItemBase* pDispItem, cScrollListInfoBase* pListItem, u32 Index);
    void updateScrollListHide_PullDown(cScrollListItemBase* pDispItem);
    bool isEndLoadResource();
    uGUIBase(u32 initFlags, bool isChatSubMenu);
    virtual ~uGUIBase();
    virtual void move();  // vtable slot 9
    virtual void moveAfter();  // vtable slot 10
    virtual bool errorResourceCheck(rGUI* pResource);  // vtable slot 32
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void draw(cDraw* pDraw);  // vtable slot 12
    static void convertToUTF8(MT_STR dst, MT_CTSTR src, s32 sEncodingType, s32 sLength);
    GUI_RESULT getResult() const;
    void setResult(GUI_RESULT result);
    bool isSuspend() const;
    bool isFlowEnd() const;
    bool isAttachedResource() const;
    void setEndType(u32 uEndType);
    u32 getEndType() const;
    void setEndReason(END_REASON uEndReason);
    END_REASON getEndReason() const;
    void setBaseF(u32);
    void orBaseF(u32 uFlag);
    void xorBaseF(u32);
    void clrBaseF(u32 uFlag);
    bool isBaseF(u32 uFlag) const;
    void setCancelButtonEnd();
    void setStartButtonEnd();
    f32 getDeltaTimeRate() const;
    void setDeltaTimeRate(f32);
    void takeOverEndFlag(uGUIBase* pBaseGUI);
    void setWindowSizeIdx(u8);
    u8 getWindowSizeIdx() const;
    bool isStartEnd() const;
    void setGUIMove(bool IsMove);
    bool isGUIMove() const;
    bool isStopAllControl() const;
    virtual void setStopAllContol(bool b);  // vtable slot 66
    bool isEnableControlExecution() const;
    void executedMsgEventNtc(s32 reason);
    u32 getPrioGrp();
    void setUseIGUIExtNetFunc(u32 ReqID);
    void setUseIItemMangerNetFunc(sItemManager::stRequest* pRequest);
    virtual bool isForceSamplerLinear(cGUIObject* pObj) const;  // vtable slot 46
    uGUIPopCmd01* createPopCmd01(bool isChatSubMenu);
    virtual void deleteDuplicateAll();  // vtable slot 67
    virtual void deleteDuplicateInstance(cGUIInstance* pInst);  // vtable slot 68
    virtual void deleteDuplicateInstanceAll();  // vtable slot 69
    virtual s32 getSMenuCursorX();  // vtable slot 70
    virtual s32 getSMenuCursorXOrder(s32 orderId);  // vtable slot 71
    virtual s32 getSMenuCursorY();  // vtable slot 72
    virtual s32 getSMenuCursorYOrder(s32 orderId);  // vtable slot 73
    virtual s32 getSMenuTab();  // vtable slot 74
    // Address: 0x01ad7950 - 0x01ad7951 (1 bytes)
    virtual void setArgs(MT_CTSTR arg1, MT_CTSTR arg2, MT_CTSTR arg3) {}  // vtable slot 75
    MT_CTSTR getUnitName();
    static u32 getItemIconNo(u32 itemID);
    u32 getVariableParamU32FromId(u32 varId);
    s32 getVariableParamS32FromId(u32 varId);
    f32 getVariableParamF32FromId(u32 varId);
    u32 getVariableParamU32FromName(MT_CTSTR varName);
    s32 getVariableParamS32FromName(MT_CTSTR varName);
    f32 getVariableParamF32FromName(MT_CTSTR varName);
    u32 getVariableInitParamU32FromId(u32 varId);
    s32 getVariableInitParamS32FromId(u32 varId);
    f32 getVariableInitParamF32FromId(u32 varId);
    void setPositionInstNull(const MtVector4& vPos);
protected:
    void forceUpdateMatrix();
    virtual bool loadResource();  // vtable slot 76
    virtual bool loadArchive();  // vtable slot 77
    virtual void update();  // vtable slot 78
    virtual void end();  // vtable slot 79
private:
    bool loadResourceBase();
public:
    rEmblemColorTable* getEmblemColorTableRes() const;
    rGUIMessage* getMsgOnlineStatus() const;
    rGUIMessage* getMsgPawnPersonality() const;
    rGUIMessage* getMsgPawnFeedbackComment() const;
    rGUIMessage* getMsgPawnShareRange() const;
    rGUIMessage* getMsgPawnStatus() const;
    rGUIMessage* getMsgPlayStyleItem() const;
    rGUIMessage* getMsgClanProfileItem() const;
protected:
    void setPriority(u32 uIssueIdx, bool bSetScreenLayer);
    virtual void replacePriority(u32 uPrioGrp);  // vtable slot 80
    virtual bool fixCameraRelatedScreenPos();  // vtable slot 81
public:
    void exitGUI();
    void requestExit();
    bool forceExitFunc();
private:
    bool isExitGUI();
public:
    void setWindowActive(bool IsActive);
    bool isWindowActive() const;
    nGUIExt::stWindowActive& getWindowActive();
    void clearReactiveWindowFunc();
protected:
    void setActiveBar(cGUIInstAnimation* pInst);
    void setActiveBar(u32 InstId);
    void setForceDispOffActiveBar(bool IsOn);
    cGUIInstAnimation* getActiveBar();
    virtual void setFocusForActiveBar(bool IsActive);  // vtable slot 82
private:
    bool isInputActive() const;
    void setInputActive(bool IsActive);
    void setInputActiveForce(bool IsActive);
    bool isInputActiveReq() const;
    void setInputActiveReq();
    void resetInputActiveReq();
    void initWindowActive();
    void managerWindowActive();
    void setWindowActiveStatus(bool IsActive);
public:
    void setBasePointerPriority(u32 prio, u32 range);
    u32 getBasePointerPriority();
    u32 getNextBasePointerPriority();
    void setPointerPosReq(const MtVector2& pos);
    void setPointerPosReq(const MtVector2& pos, u32 uPrio);
    void updatePointerGuide();
    void updatePointerGuide(u32 uPrio);
    void hidePointer();
protected:
    virtual cGUIInstance* getInstance(const u32 id, bool isAssert) const;  // vtable slot 83
    void setSequenceId(cGUIInstAnimation* pInstAnim, u32 uSeqId, bool bReset);
    void setSequenceId(cGUIObjChildAnimationRoot* pInst, u32 uSeqId, bool bReset);
    u32 getSequenceId(u32 instId);
    u32 getSequenceId(cGUIInstAnimation* pInst);
    void setInstNull(cGUIInstNull* pInstNull, bool bOptionData);
    cGUIInstNull* getInstNull();
    void setInstNullDesign(cGUIInstNull* pInstNull);
    cGUIInstNull* getInstNullDesign();
    void setInstWindow(cGUIInstAnimation* pInst);
    cGUIInstAnimation* getInstWindow();
    void setInstanceVisible(cGUIInstance* pInst, bool bVisible);
    void setInstanceVisible(u32 instId, bool bVisible);
    void setInstanceVisibleTree(cGUIInstance* pInst, bool bVisible);
    void setInstanceExecute(cGUIInstance* pInst, bool bExecute);
    void setInstanceExecuteTree(cGUIInstance* pInst, bool bExecute);
    void copyInstanceExecuteTree(cGUIInstance* pTreeOrg, cGUIInstance* pTreeDup);
    void setInstFixFrameTree(cGUIInstance* pInst, bool bFix);
    void setInstancePosition(u32 inst_id, const MtVector4& pos);
    MtVector4 getInstancePosition(u32 inst_id);
    MtVector4 getInstancePosition(cGUIInstNull* pInst);
    MtVector4 getInstancePositionRoot(cGUIInstance* pInst, MtVector3* pScaleRoot);
    MtVector3 getInstanceMtxPos(u32 uInstId);
    MtVector3 getInstanceMtxPos(cGUIInstNull* pInstNull);
    void setInstanceScale(cGUIInstNull* pInstNull, f32 fScale);
    virtual void adjustScale();  // vtable slot 84
    virtual void updateScaleForWindow(f32& fScaleRate);  // vtable slot 85
    virtual f32 getScaleForDefaultResolution(f32 fScaleRate);  // vtable slot 86
    void adjustOfs(cGUIInstNull* pInstNull);
    void setPolygonColor(cGUIObjPolygon* p, const MtColor& col, u32 num);
    bool isHitInstanceChild(cGUIInstance* pInstance, const MtVector3& pt, f32 ratio) const;
    f32 getTabWidth(u32 InstId, u32 ObjCenterCenterId);
    static f32 getTabWidth(f32 ObjectWidth);
    cGUIInstance* ManageDuplicate(cGUIInstance* pOrgInst, cGUIInstance* pParentInst);
    cGUIInstance* ManageDuplicateAuto(cGUIInstance* pInst);
    u32 getManagedDupliInstNum() const;
    cGUIInstance* getManagedDupliInst(u32);
    bool setManagedDupliPosTreeFromParent(cGUIInstance* pInstDupli, cGUIInstance* pInstOrg, bool bChildOnly);
    cGUIObject* getObjectFromId(cGUIInstance* pInst, u32 uId);
    cGUIObject* getObjectFromId(u32 uInstId, u32 uId);
    MtVector2 getObjectScreenPos(cGUIObject* pObj, const MtVector3& offset);
    static MtVector2 getInstanceScreenPos(cGUIInstance* pInst, const MtVector3& offset);
    void getInstancePosFromRoot(MtVector4* pPos, cGUIInstance* pInst);
    void getObjectPosFromRoot(MtVector4* pPos, cGUIInstance* pInst, cGUIObject* pObj);
    void getInstancePosFromParent(MtVector4* pPos, cGUIInstance* pInst, cGUIInstance* pInstParent);
    void setObjFixFrameTree(cGUIObject* pObj, bool bFix);
public:
    void setMsgAnalyzerWork(u32 uIdx, MT_CTSTR pAnalyzeMsg);
    void setMsgAnalyzerWork(u32 uIdx, s32 sAnalyzeNum);
    void clearMsgAnalyzerWork();
    void clearMsgAnalyzerCount();
    u32 getMsgAnalyzerCount();
    void setMsgAnalyzerAutoClear(bool flag);
    const nGUIExt::stMsgAnalyzerWork* getMsgAnalyzerWork(u32 uIdx);
    void incMsgAnalyzerCount();
    void setMsgAnalyzerScheduleId(u32 ScheduleId);
    u32 getMsgAnalyzerScheduleId() const;
    void setMsgAnalyzerAutoColor(bool IsAutoColor);
    bool getMsgAnalyzerAutoColor() const;
    void setMsgAnalyzerDispMySelf(bool IsMySelf);
    bool getMsgAnalyzerDispMySelf() const;
protected:
    void clearMessageAll();
    void clearMessageInstanceTree(cGUIInstance* pInst);
    void clearMessageObjectTree(cGUIObject* pObj);
    void setMessageColor(cGUIObject* pObj, const MtColor& color);
    void setObjectMessage(cGUIObject* pObj, MT_CTSTR msg, u32 uGenderType, bool bAutoWrap);
    void setObjectMessageFromId(u32 instId, u32 objId, MT_CTSTR msg, u32 uGenderType, bool bAutoWrap);
    void setObjectMessageFromId(cGUIInstance* pInst, u32 objId, MT_CTSTR msg, u32 uGenderType, bool bAutoWrap);
    void setObjectMessage(cGUIObject* pObj, rGUIMessage* pRes, u32 uMsgId, u32 uGenderType, bool bAutoWrap);
    void setObjectMessageFromId(u32 instId, u32 objId, rGUIMessage* pRes, u32 uMsgId, u32 uGenderType, bool bAutoWrap);
    void setObjectMessageFromId(cGUIInstance* pInst, u32 objId, rGUIMessage* pRes, u32 uMsgId, u32 uGenderType, bool bAutoWrap);
    void setObjectMessageColor(cGUIObject* pObj, MT_CTSTR msg, const MtColor& color, u32 uGenderType, bool bAutoWrap);
    void setObjectMessageAdjustSize(cGUIObject* pObj, MT_CTSTR msg, u32 uGenderType, bool bAutoWrap);
    void setObjectMessageFit(cGUIObjMessage* pObjMsg, MT_CTSTR msg, size_t size);
    void setInstNumberFormatting(cGUIInstance* pInst, s32 num);
    void setWindowTitle(u32 InstId, u32 EngObjId, u32 JpObjId, MT_CTSTR pEngName, MT_CTSTR pJpName);
    void setWindowTitle(cGUIObjMessage* pEngObj, cGUIObjMessage* pJpObj, MT_CTSTR pEngName, MT_CTSTR pJpName);
    void setVariableParamFromId(u32 varId, s32 prm, bool reset);
    void setVariableParamFromId(u32 varId, u32 prm, bool reset);
    void setVariableParamFromId(u32 varId, f32 prm, bool reset);
    void subVariableRegister(cDuplicateData* pDuplicate, cGUIInstance* pInst);
    virtual void evChangeFlow(const nGUI::FLOW* pNewFlow, const nGUI::FLOW* pNowFlow);  // vtable slot 47
    void setFlowAndInit(const u32 flowId, bool isEndWait);
    void setChangeFlowVariable(const u32 varId, bool bChange);
    void changeFlow(u32 uVarIdSW, u32 uFlowSwitch, u32 uVarIdCF);
    bool updateAnimWaitInstSlot();
    rSoundRequest* getPauseSe();
    void loadPauseSe();
    void requestPauseSe(u32 seNo);
    void setVariableSizeWindowObject(cGUIObjPolygon* pLeftTop, cGUIObjPolygon* pLeftCenter, cGUIObjPolygon* pLeftUnder, cGUIObjPolygon* pCenterTop, cGUIObjPolygon* pCenterCenter, cGUIObjPolygon* pCenterUnder, cGUIObjPolygon* pRightTop, cGUIObjPolygon* pRightCenter, cGUIObjPolygon* pRightUnder, MtFloat2 Size, MtFloat2 Ofs, u8 uOptionF, u8 uAlign);
    void setVariableSizeWindowObject(cGUIObjPolygon* * p9SliceTbl, MtFloat2 Size, MtFloat2 Ofs, u8 uOptionF, u8 uAlign);
    void getObjVariableSizeWindow(cGUIObjPolygon* * pObjTbl, cGUIInstance* pInst);
    void setScrollBar(cGUIInstance* pInstScrBar, cGUIObject* pObjSlider, cGUIObject* pObjCenter, cVerticalList* pCtrl, MtVector4& v4Pos, f32 fWindowH);
    void setSliderBar(cGUIInstance* pInstScrBar, cGUIObject* pObjSlider, cGUIObject* pObjTop, cGUIObject* pObjTopArrow, cGUIObject* pObjCenter, cGUIObject* pObjBottom, cGUIObject* pObjBottomArrow, cVerticalList* pCtrl, MtVector4& v4Pos, f32 fWindowH);
    void setLRTab(cGUIInstAnimation* pInstL, cGUIInstAnimation* pInstR, cHorizontalList* pCtrl, bool bSelectL, bool bSelectR);
    void setStatusGauge(cGUIObject* pObjGauge, cGUIObject* pObjMsgValue, f32 value, f32 max_value, bool isInverce);
    void setHeartGauge(cGUIObject* pObjTexGauge, u32 value);
    void setExpGauge(cGUIObject* pObjTexGauge, cGUIObject* pObjMsgValue, const nJobParam::cJobInfo* pJobInfo, bool isInverce);
    void setMessageHorizontalInterval(cGUIObj2D* pObjLeft, cGUIObj2D* pObjRight, f32 interval, bool isLeftBase);
    static s32 convertJobID2ResJobFrame(nHuman::JOB_ENUM val);
    static s32 convertJobID2ResRoleFrame(nHuman::ROLE_ENUM val);
    void setArcTag(u32 tagId, u32 index, bool isKeep);
    u32 getArcTag(u32 index);
    cResource* uiCreateResource(u32 arcTag, u32 searchId, u32 mode, t64 update_time);
    bool loadGMD(MT_CTSTR str, u32 aryIdx);
    bool loadGMDarc(u32 arcTag, MT_CTSTR resTag, u32 aryIdx);
    void releaseGMD();
public:
    bool setGMD(rGUIMessage* pRes, u32 aryIdx, bool isAddRef);
protected:
    MT_CTSTR getGMDMsg(u32 gmdIdx, u32 aryIdx) const;
    MT_CTSTR getGMDMsgValNum(u32 gmdIdx, u32 aryIdx, s32 val1, s32 val2, s32 val3);
    rGUIMessage* getGMD(u32 aryIdx) const;
    u32 getGMDNumMax() const;
public:
    MtCriticalSection* getCS();
    void setOpenSE(u32 SeNo);
protected:
    void setPS4ShareNG(bool IsNG);
    bool isInstanceSectionEndFromIndex(u32 instIdx);
    void setupItemIconTex(cGUIObjTexture* tex_obj, u32 tex_id, bool isReplace);
    void setupItemIconTex(cGUIObjTexture* tex_obj, u32 tex_id, rTexture* tex_res, bool isReplace);
    void setupIconTex(cGUIObjTexture* tex_obj, u32 tex_id, rTexture* tex_res, f32 tex_width, f32 tex_height, bool isReplace);
    MtVector3 getScreenPos(const MtVector3& world_pos, sCamera::VIEWPORT_NO vp_no);
    static void changePathIntoCurrentLangage(MT_STR out_buff, MT_CTSTR org_path);
    void purgeAllControlMessage();
    void disableAllControls();
    void executeAllControls();
    // Address: 0x01ad77a0 - 0x01ad77a1 (1 bytes)
    virtual void applyWorldOffset(const MtVector3& offset, const MtVector3& absolute_offset) {}  // vtable slot 15
    MtVector2 getDistanceBetweenInstances(cGUIInstance* pInstFrom, cGUIInstance* pInstTo);
    void updateMockUpDisp(uUIMockUp* pMockUp, cGUIInstAnimation* pIndicator, cGUIObjTexture* pTex);
private:
    bool autoWrapMessage(MT_STR pDst, MT_CTSTR pSrc, u32 srcLength, MtSize size, MtFloat2 region, s32 letterSpace, const rGUIFont* pFont);
    void setSuspendFlag(bool);
    void setSuspendCtrl();
protected:
    bool isNoRegistSystemCallBack();
private:
    void releaseRegistSystemCallBack();
    void manageIGUIExtNetReq();
    bool isExistIGUIExtNetReq();
    void manageIItemManagerNetReq();
    bool isExistItemMangerNetReq();
    void deleteItemManagerNetReq();
    void manageCommunicateServer();
    void setNextRequestStartServer();
protected:
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void waitArcLoadFunc();
    virtual void setServerErrorEnd(u32 ErrorCode);  // vtable slot 89
    void stopRequestServerMove();
    bool isRequestServerMove();
    void setInputEvent(u32 EventId);
    void resetInputEvent();
    bool isExistInputEvent();
    bool isMouseOver() const;
public:
    u32 getInputEvent();
private:
    void moveAutoAlpharingMenu();
    void moveHUD();
    void moveWindow();
    void moveTextBox();
    void initInputTextKey();
    void moveInputTextKey();
public:
    const nInputTextKeyboardHook::Keycode& getInputTextKey() const;
    void addInputTextKey(const nInputTextKeyboardHook::Keycode& keycode);
    cInputTextKeyboardHook* getInputTextKeyboardHook();
protected:
    virtual bool onKeyEvent(const nInputTextKeyboardHook::Keycode& keycode);  // vtable slot 90
protected:
    u32 mBtnGuideTouchInputBit;  // offset: 0x438
    MtTypedArray<cControl> mBtnGuideCtrl;  // offset: 0x440
    GUI_RESULT mResult;  // offset: 0x460
    bool mIsCurrentFuncExecute;  // offset: 0x464
    bool mSMENUdecide;  // offset: 0x465
    bool mSMENUcancel;  // offset: 0x466
    bool mSMENUchkout;  // offset: 0x467
    bool mSMENUtopbtn;  // offset: 0x468
    bool mIsChatSubMenu;  // offset: 0x469
    u32 mRoutine;  // offset: 0x46c
    u32 mPrioIssueIdx;  // offset: 0x470
    cGUIInstAnimControl* mpWaitAnimInstSlot[16];  // offset: 0x478
    u32 mWaitAnimInstNum;  // offset: 0x4f8
    void(uGUIBase::*mpAnimEndCallBack)();  // offset: 0x500
    bool mIsFlowEnd;  // offset: 0x510
    bool mIsFlowWaitMode;  // offset: 0x511
    bool mIsEndLoadResource;  // offset: 0x512
    bool mIsAttachedResource;  // offset: 0x513
private:
    u32 mArcTag[5];  // offset: 0x514
    bool mArcKeep[5];  // offset: 0x528
protected:
    u32 mEndType;  // offset: 0x530
    END_REASON mEndReason;  // offset: 0x534
    u32 mBaseF;  // offset: 0x538
    u32 mInitFlags;  // offset: 0x53c
    MtTypedArray<cReferenceUIBase> mRefrenceUIArray;  // offset: 0x540
private:
    cReferenceUITextBox* mpActiveTextBox;  // offset: 0x560
protected:
    cGUIInstNull* mpInstNullBase;  // offset: 0x568
    cGUIInstNull* mpInstNullDesign;  // offset: 0x570
    cGUIInstAnimation* mpInstWindow;  // offset: 0x578
    cReferenceUIWndwDrag mDragBar;  // offset: 0x580
    u32 mOpenSeNo;  // offset: 0x600
    TICKET mArcTicket;  // offset: 0x608
    TICKET mArcTicketKeep;  // offset: 0x610
private:
    bool mSuspendFlag;  // offset: 0x618
    bool mIsStopAllControl;  // offset: 0x619
    cDuplicateDataArray mDuplicates;  // offset: 0x620
    rSoundRequest* mpPauseSe;  // offset: 0x640
    f32 mDeltaTimeRate;  // offset: 0x648
    MtTypedArray<cControl> mControls;  // offset: 0x650
    bool mIsInputActive;  // offset: 0x670
    bool mIsReqInputActive;  // offset: 0x671
    u8 mWindowSizeIdx;  // offset: 0x672
    nGUIExt::stWindowActive mWindowActive;  // offset: 0x673
    bool mIsWindowActive;  // offset: 0x675
    nDDOUtility::cBitSet<2> mInitWindowActiveMode;  // offset: 0x678
    cGUIInstAnimation* mpActiveBar;  // offset: 0x680
    void(uGUIBase::*mpReactiveWindowFunc)();  // offset: 0x688
    bool mIsActiveBarForceDispOff;  // offset: 0x698
    u32 mBasePointerPrio;  // offset: 0x69c
    u32 mPointerPrioRange;  // offset: 0x6a0
    bool(uGUIBase::*mpCheckExitGUIFunc)();  // offset: 0x6a8
    sItemManager::stRequest* mpItemMgrRequest;  // offset: 0x6b8
    u32 mGUIExtNetMgrUseId;  // offset: 0x6c0
    rEmblemColorTable* mpEmblemColorTable;  // offset: 0x6c8
    rGUIMessage* mpMsgOnlineStatus;  // offset: 0x6d0
    rGUIMessage* mpMsgPawnPersonality;  // offset: 0x6d8
    rGUIMessage* mpMsgPawnFeedbackComment;  // offset: 0x6e0
    rGUIMessage* mpMsgPawnShareRange;  // offset: 0x6e8
    rGUIMessage* mpMsgPawnStatus;  // offset: 0x6f0
    rGUIMessage* mpMsgPlayStyleItem;  // offset: 0x6f8
    rGUIMessage* mpMsgClanProfileItem;  // offset: 0x700
protected:
    MtTypedArray<cKeepInScreen> mAryKeepInScreen;  // offset: 0x708
    cKeepInScreen mKeepInScreenDefault;  // offset: 0x728
private:
    nGUIExt::stMsgAnalyzerWork mMsgAnalyzerWork[10];  // offset: 0x750
    u32 mMsgAnalyzeCnt;  // offset: 0x7f0
    u32 mMsgAnalyzeScheduleId;  // offset: 0x7f4
    bool mMsgAnalyzeAutoClear;  // offset: 0x7f8
    bool mMsgAnalyzeAutoColor;  // offset: 0x7f9
    bool mMsgAnalyzeDispMySelf;  // offset: 0x7fa
protected:
    void(uGUIBase::*mpCurrentFunc)();  // offset: 0x800
private:
    nDDOUtility::cArray<rGUIMessage*, 4> mpGUIMsgs;  // offset: 0x810
public:
    MtCriticalSection mCS;  // offset: 0x830
protected:
    u32 mInputEventId;  // offset: 0x838
private:
    u32 mServerRno;  // offset: 0x83c
    u32 mServerResult;  // offset: 0x840
    u32 mServerCommandStatus;  // offset: 0x844
    u32 mServerCommandStatusRsv;  // offset: 0x848
    ServerRequestFunc mpServerRequestFunc;  // offset: 0x850
    ServerRequestFunc mpServerRequestFuncRsv;  // offset: 0x860
    ServerSuccessCallBack mpServerSuccessFunc;  // offset: 0x870
    ServerSuccessCallBack mpServerSuccessFuncRsv;  // offset: 0x880
    ServerFailedCallBack mpServerFailedFunc;  // offset: 0x890
    ServerFailedCallBack mpServerFailedFuncRsv;  // offset: 0x8a0
    nInputTextKeyboardHook::Keycode mInputTextKey;  // offset: 0x8b0
    nInputTextKeyboardHook::Keycode mInputTextKeyReq;  // offset: 0x8b4
    InputTextKeyboardHook mInputTextKeyboardHook;  // offset: 0x8b8
public:
    static MyDTI DTI;
    static const u32 MSGANALYZERWORK_MAX = 10;
protected:
    static const u32 WAIT_ANIM_MAX = 16;
    static const u32 STRBUF_S_MAX = 256;
    static const u32 STRBUF_M_MAX = 512;
    static const u32 STRBUF_L_MAX = 2048;
public:
    static const u32 InitFlag_None = 0;
    static const u32 InitFlag_Window = 1;
    static const u32 InitFlag_WindowActive_NoRegist = 2;
    static const u32 InitFlag_WindowActive_InitNoActive = 4;
    static const u32 InitFlag_WindowActive_InitForceOn = 8;
    static const u32 InitFlag_WindowActive_PrioErrorDialog = 16;
    static const s32 DISABLE_IDX;
};

// Inline, no code of its own: checked where it is inlined.
inline bool uGUIBase::isAttachedResource() const {
    return this->mIsAttachedResource;
}

// Inline, no code of its own: checked where it is inlined.
inline rEmblemColorTable* uGUIBase::getEmblemColorTableRes() const {
    return this->mpEmblemColorTable;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 uGUIBase::getBasePointerPriority() {
    return this->mBasePointerPrio;
}

// Inline, no code of its own: checked where it is inlined.
inline u32 uGUIBase::getInputEvent() {
    return this->mInputEventId;
}

// Inline, no code of its own: checked where it is inlined.
inline cGUIInstAnimation* uGUIBase::cSupportInstAnim::getInstance() {
    return this->mpInstance;
}

// Inline, no code of its own: checked where it is inlined.
inline uGUIBase::cSupportBase::cSupportBase() {
    this->mpUnit = static_cast<uGUIBase*>(nullptr);
    this->mAutoClear = false;
}

// Inline, no code of its own: checked where it is inlined.
inline uGUIBase::cVerticalList* uGUIBase::cScrollList::getCtrl() {
    return this->mpVCtrl;
}

// Inline, no code of its own: checked where it is inlined.
inline bool uGUIBase::cTexRefJpegDownloader::isReplaceTex() const {
    return this->mIsReplaceTex;
}

// Inline, no code of its own: checked where it is inlined.
inline bool uGUIBase::cImageDownloader::isFail() {
    return this->mIsFail;
}

// Inline, no code of its own: checked where it is inlined.
inline uGUIBase::cReferenceUINumBox::MODE uGUIBase::cReferenceUINumBox::getMode() const {
    return this->mMode;
}

// Inline, no code of its own: checked where it is inlined.
inline s32 uGUIBase::cReferenceUINumBox::getCurrentNum() const {
    return this->mCurrentNum;
}

// Inline, no code of its own: checked where it is inlined.
inline uGUIBase::cReferenceUIPageDot::cPageDotWork::cPageDotWork() {
    this->mpObj = static_cast<cGUIObjTexture*>(nullptr);
    this->mpInst = static_cast<cGUIInstAnimation*>(nullptr);
}
