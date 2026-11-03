#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "Protocol/PacketData/Character.h"
#include "../../MT/MtCollection.h"
#include "../../MT/MtDTI.h"
#include "../../MT/MtObject.h"
#include "../../MT/MtString.h"
#include "cControl.h"
#include "cEditChargeInfoUpdator.h"
#include "nCharacterEdit.h"
#include "nDDOUtility.h"
#include "nGUIExt.h"
#include "../../generated/shared/nKeyCustom.h"
#include "sPadExt.h"
#include "uGUIBase.h"
#include "uGUICharaEditPartsWrap.h"
#include "uGUIsMenuBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class MtString;
class cArcLoaderBase;
class cControl;
class cEditChargeInfoUpdator;
class cGUIInstAnimation;
class cGUIInstNull;
class cGUIObjMessage;
class cGUIObjNull;
class cGUIObjPolygon;
class cUndoData;
class cpCharacterEdit;
class rCharacterEditColorDef;
class rCharacterEditVoicePalette;
class rGUI;
class rSndPitchLimit;
class rSoundRequest;
class uCharacterEdit;
class uEditSaveLoadFlow;
class uGUICharaEditPartsWrap;
class uGUIGPShop;
class uGUISystemMsg;
class uMockUpModel;

// Declarations
class uGUICharacterEdit;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using TICKET = cArcLoaderBase*;
using _Sizet = long unsigned int;
using f32 = float;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUICharacterEdit : public uGUIsMenuBase
{
    friend class uCharacterEdit;
    friend class uGUICharaEditPartsWrap;
public:
    enum HELPER_UI_TYPE
    {
        HELPER_TYPE_NONE = 0,
        HELPER_HISTORY_L = 1,
        HELPER_HISTORY_R = 2,
        HELPER_DEFAULT = 3,
        HELPER_MODEL_ROTA = 4,
        HELPER_CAMERA_ROTA = 5,
        HELPER_SAVE_LOAD = 6,
        HELPER_PAUSE = 7,
        HELPER_TRIAL_VOICE = 8,
        HELPER_TRIAL_FACE = 9,
        HELPER_TYPE_NUM = 10,
    };
    enum PR
    {
        PR_MAIN = 0,
        PR_SUB = 1,
        PR_WARNING_DECIDE = 2,
        PR_WARNING_EXIT = 3,
        PR_WARNING_INIT = 4,
        PR_WARNING_CARD = 5,
        PR_SELECT_STAGE = 6,
        PR_SELECT_EQUIP = 7,
        PR_SELECT_SAVE_LOAD = 8,
        PR_GP_SHOP = 9,
        PR_END = 10,
        PR_MAX = 11,
    };
    enum BUILD_MODE
    {
        BUILD_MODE_CREATE = 0,
        BUILD_MODE_REGIST = 1,
    };
    enum EDIT_SAVE_LOAD_ROUTINE
    {
        EDIT_SAVE_LOAD_ROUTINE_INIT = 0,
        EDIT_SAVE_LOAD_ROUTINE_WAIT = 1,
        EDIT_SAVE_LOAD_ROUTINE_END = 2,
    };
    enum EDIT_DIALOG_ROUTINE
    {
        EDIT_DIALOG_INIT = 0,
        EDIT_DIALOG_WAIT_NAME = 1,
        EDIT_DIALOG_WAIT_EDIT = 2,
        EDIT_DIALOG_END = 3,
    };
    enum GP_SHOP_ROUTINE
    {
        GP_SHOP_ROUTINE_INIT = 0,
        GP_SHOP_ROUTINE_WAIT = 1,
        GP_SHOP_CHAGE_INFO_INIT = 2,
        GP_SHOP_CHAGE_INFO_MOVE = 3,
        GP_SHOP_CHAGE_INFO_FINAL = 4,
        GP_SHOP_ROUTINE_END = 5,
        GP_SHOP_ROUTINE_ERROR = 6,
    };
    enum EDIT_UPDATE_TYPE
    {
        EDIT_UPDATE_NONE = 0,
        EDIT_UPDATE_FREE = 1,
        EDIT_UPDATE_CHARGE = 2,
    };
    enum EDIT_GMD_TYPE
    {
        EDIT_GMD_TYPE_EDIT = 0,
        EDIT_GMD_TYPE_HELP = 1,
        EDIT_GMD_TYPE_DIALOG = 2,
        EDIT_GMD_TYPE_CAST_NAME = 3,
        EDIT_GMD_TYPE_NUM = 4,
    };
    enum CAMERA_INPUT_MASK
    {
        CAMERA_INPUT_MASK_MAIN = 0,
        CAMERA_INPUT_MASK_MAIN_A = 1,
        CAMERA_INPUT_MASK_SUB = 2,
        CAMERA_INPUT_MASK_HELPER = 3,
        CAMERA_INPUT_MASK_NUM = 4,
    };
    enum
    {
        MOUSE_TYPE_LEFT = 0,
        MOUSE_TYPE_RIGHT = 1,
        MOUSE_TYPE_CENTER = 2,
    };
    enum
    {
        INPUTEVENT_END = 66,
        INPUTEVENT_OPEN_SUB_GUI = 67,
        INPUTEVENT_DECEIDE_MAIN_RANDOM_FACE = 68,
        INPUTEVENT_DECEIDE_MAIN_DECEIDE = 69,
        INPUTEVENT_DECEIDE_DISP_INIT_WARNING = 70,
        INPUTEVENT_DECEIDE_DISP_EXT_WARNING = 71,
        INPUTEVENT_CLOSE_SUB_GUI = 72,
        INPUTEVENT_START_SAVELOAD = 73,
        INPUTEVENT_EDIT_DEFAULT = 74,
        INPUTEVENT_OPEN_STAGELIST = 75,
        INPUTEVENT_CHANGE_STAGE = 76,
        INPUTEVENT_CLOSE_STAGELIST = 77,
        INPUTEVENT_CANCEL_STAGELIST = 78,
        INPUTEVENT_LEFT_STAGE = 79,
        INPUTEVENT_RIGHT_STAGE = 80,
        INPUTEVENT_OPEN_EQUIPLIST = 81,
        INPUTEVENT_CHANGE_EQUIP = 82,
        INPUTEVENT_CLOSE_EQUIPLIST = 83,
        INPUTEVENT_CANCEL_EQUIPLIST = 84,
        INPUTEVENT_LEFT_EQUIP = 85,
        INPUTEVENT_RIGHT_EQUIP = 86,
        INPUTEVENT_MOVE_V = 87,
        INPUTEVENT_MOVE_H = 88,
        INPUTEVENT_PARTS_OPEN = 89,
        INPUTEVENT_PARTS_DECIDE = 90,
        INPUTEVENT_PARTS_CLOSE = 91,
        INPUTEVENT_PARTS_MOVE_H = 92,
        INPUTEVENT_PARTS_MOVE_V = 93,
        INPUTEVENT_PARTS_MOUSE_OVER = 94,
        INPUTEVENT_PARTS_MOUSE_WUP = 95,
        INPUTEVENT_PARTS_MOUSE_WDOWN = 96,
        INPUTEVENT_PARTS_MOUSE_DRAG_BAR = 97,
        INPUTEVENT_MOVE_V_SUB = 98,
        INPUTEVENT_TOP_SUB_CHILD = 99,
        INPUTEVENT_CHANGE_MOTION = 100,
        INPUTEVENT_UNDO = 101,
        INPUTEVENT_REDO = 102,
        INPUTEVENT_CHANGE_FACE_ANIME = 103,
        INPUTEVENT_PARTS_OPEN_PULLDOWN = 104,
        INPUTEVENT_PARTS_CLOSE_PULLDOWN = 105,
        INPUTEVENT_PARTS_EXIT_PULLDOWN = 106,
        INPUTEVENT_PARTS_CANCEL_INPUT_NAME = 107,
        INPUTEVENT_PARTS_OPEN_CHAGE_SHOP = 108,
    };
    enum SW
    {
        SW_MAIN = 0,
        SW_SUB = 1,
        SW_END = 2,
        SW_SALON_MAIN = 3,
        SW_SALON_SUB = 4,
        SW_SALON_END = 5,
    };
public:
    class MyDTI;
    class cListStage;
    class cListEquip;
    class cIndex;
    class cGUIUnderHelpMsg;
    struct stGuiInst;
    struct stGuiObj;
    class cList;
    class cVerticalListEx;
    class cListHelper;
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class cListStage : public MtObject
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
        cListStage();
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x8
        cGUIInstAnimation* mpInstAnim;  // offset: 0x30
        cGUIObjNull* mpObjNullCursor;  // offset: 0x38
        cGUIObjPolygon* mpObjMouseOverL;  // offset: 0x40
        cGUIObjPolygon* mpObjMouseOverR;  // offset: 0x48
        cGUIObjPolygon* mpObjMouseOverC;  // offset: 0x50
        uGUIBase::cCalcMovePos mMovePos;  // offset: 0x58
        bool mIsLeft;  // offset: 0x78
        bool mIsNonRight;  // offset: 0x79
        static MyDTI DTI;
    };
public:
    class cListEquip : public MtObject
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
        cListEquip();
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x8
        cGUIInstAnimation* mpInstAnim;  // offset: 0x30
        cGUIObjNull* mpObjNullCursor;  // offset: 0x38
        cGUIObjPolygon* mpObjMouseOverL;  // offset: 0x40
        cGUIObjPolygon* mpObjMouseOverR;  // offset: 0x48
        cGUIObjPolygon* mpObjMouseOverC;  // offset: 0x50
        uGUIBase::cCalcMovePos mMovePos;  // offset: 0x58
        bool mIsLeft;  // offset: 0x78
        bool mIsNonLeft;  // offset: 0x79
        bool mIsOriginal;  // offset: 0x7a
        u32 mPresetTagID;  // offset: 0x7c
        u32 mIconID;  // offset: 0x80
        static MyDTI DTI;
    };
public:
    class cIndex : public MtObject
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
    public:
        nCharacterEdit::CATE mCategory;  // offset: 0x8
        static MyDTI DTI;
    };
public:
    class cGUIUnderHelpMsg : public MtObject
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
        cGUIUnderHelpMsg();
        void setActive(bool isActive);
    public:
        uGUIBase::cDupliInstAnim mInst;  // offset: 0x8
        cGUIObjMessage* mpMsgKey;  // offset: 0x30
        cGUIObjMessage* mpMsg;  // offset: 0x38
        uGUICharacterEdit::HELPER_UI_TYPE mType;  // offset: 0x40
        static MyDTI DTI;
    };
public:
    struct stGuiInst
    {
    public:
        cGUIInstAnimation* title;  // offset: 0x0
        cGUIInstNull* Null;  // offset: 0x8
        cGUIInstAnimation* pointer;  // offset: 0x10
        cGUIInstAnimation* msg_name;  // offset: 0x18
        cGUIInstAnimation* fix_msg_category;  // offset: 0x20
        cGUIInstAnimation* cursor;  // offset: 0x28
        cGUIInstAnimation* msg_ctrl;  // offset: 0x30
        cGUIInstAnimation* msg_exp;  // offset: 0x38
        cGUIInstAnimation* msg_location;  // offset: 0x40
        cGUIInstAnimation* msg_save;  // offset: 0x48
        cGUIInstAnimation* fix_location;  // offset: 0x50
        cGUIInstAnimation* base;  // offset: 0x58
        cGUIInstAnimation* msg_sup_txt00;  // offset: 0x60
        cGUIInstNull* Null_main;  // offset: 0x68
        cGUIInstAnimation* base_sub;  // offset: 0x70
        cGUIInstNull* Null_sub;  // offset: 0x78
        cGUIInstAnimation* radio_btn;  // offset: 0x80
        cGUIInstAnimation* msg_pulldown02;  // offset: 0x88
        cGUIInstAnimation* fix_hairstyle;  // offset: 0x90
        cGUIInstAnimation* haircolor;  // offset: 0x98
        cGUIInstNull* Null_hstyle;  // offset: 0xa0
        cGUIInstNull* Null_hcolor;  // offset: 0xa8
        cGUIInstNull* Null_rbtn;  // offset: 0xb0
        cGUIInstNull* Null_pulldown02;  // offset: 0xb8
        cGUIInstAnimation* fix_msg_acnt;  // offset: 0xc0
        cGUIInstAnimation* msg_textbox00;  // offset: 0xc8
        cGUIInstAnimation* msg_textbox01;  // offset: 0xd0
        cGUIInstNull* Null_acnt;  // offset: 0xd8
        cGUIInstNull* Null_support;  // offset: 0xe0
        cGUIInstNull* Null_exp;  // offset: 0xe8
        cGUIInstNull* Null_loca;  // offset: 0xf0
        cGUIInstNull* Nullctgry;  // offset: 0xf8
        cGUIInstAnimation* msg_slider;  // offset: 0x100
        cGUIInstNull* Null_slider;  // offset: 0x108
        cGUIInstAnimation* msg_num;  // offset: 0x110
        cGUIInstAnimation* mask;  // offset: 0x118
        cGUIInstNull* Null_mask;  // offset: 0x120
    };
public:
    struct stGuiObj
    {
    public:
        cGUIObjMessage* msg_name_m_txt;  // offset: 0x0
        cGUIObjMessage* fix_msg_category_m_ctgry;  // offset: 0x8
        cGUIObjMessage* fix_msg_category_m_btn;  // offset: 0x10
        cGUIObjMessage* msg_ctrl_m_ctrl02;  // offset: 0x18
        cGUIObjMessage* msg_ctrl_m_ctrl02a;  // offset: 0x20
        cGUIObjMessage* msg_exp_m_exp;  // offset: 0x28
        cGUIObjMessage* msg_location_m_lctn00;  // offset: 0x30
        cGUIObjMessage* msg_location_m_lctn01;  // offset: 0x38
        cGUIObjMessage* fix_msg_acnt_m_first;  // offset: 0x40
        cGUIObjMessage* fix_msg_acnt_m_family;  // offset: 0x48
        cGUIObjMessage* fix_msg_acnt_m_exp;  // offset: 0x50
        cGUIObjMessage* msg_num_m_num;  // offset: 0x58
        cGUIObjMessage* msg_num_m_max;  // offset: 0x60
        cGUIObjMessage* msg_stone_m_number;  // offset: 0x68
        cGUIObjMessage* msg_sup_txt_m_ctrl01;  // offset: 0x70
        cGUIObjMessage* title_sub_m_title;  // offset: 0x78
        cGUIObjPolygon* mpObjBaseSubBase;  // offset: 0x80
        cGUIObjPolygon* mpObjBaseCur00;  // offset: 0x88
        cGUIObjPolygon* mpObjBaseCur00a;  // offset: 0x90
        cGUIObjPolygon* mpObjSupportMouseline04;  // offset: 0x98
    };
public:
    class cList : public MtObject
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
        cList();
        virtual ~cList() {}
        void setPatern(u32 id);
    public:
        uGUIBase::cDupliInstNull mInst;  // offset: 0x8
        cGUIInstAnimation* mpInstFixMsgCategory;  // offset: 0x30
        cGUIInstAnimation* mpUpdate;  // offset: 0x38
        cGUIObjPolygon* mpObjCategoryPolygon;  // offset: 0x40
        cGUIObjPolygon* mpObjMouseOver;  // offset: 0x48
        cGUIObjPolygon* mpObjMouseOver01;  // offset: 0x50
        static MyDTI DTI;
    };
public:
    class cVerticalListEx : public uGUIBase::cVerticalList
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
        cVerticalListEx(s32 item_num, const u32* tags, s32 visible_size);
        virtual void reqPresetSE(cControl::Message* pMsg);  // vtable slot 12
        virtual void reqPresetSE(nGUIExt::MSG_REASON reason);  // vtable slot 13
    public:
        uGUICharacterEdit* mpUnit;  // offset: 0xc58
        static MyDTI DTI;
    };
public:
    class cListHelper
    {
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
    uGUICharacterEdit();
    virtual ~uGUICharacterEdit();
    void resetHelperActive();
    void changeHelperActive(HELPER_UI_TYPE type, bool active);
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void kill();  // vtable slot 16
    virtual void move();  // vtable slot 9
    virtual void updatePtr();  // vtable slot 17
    MT_CTSTR getGMDHelp(u32 id);
    MT_CTSTR getGMDDlg(u32);
    void reboot();
    bool setProc(PR proc, bool force, bool isInitLight);
    PR getProc();
    PR getProcOld();
    uGUIBase::cVerticalList* getVControl(s32 idx) const;
    s32 getVPos(s32 idx) const;
    s32 getOldPos(s32 idx);
    nCharacterEdit::CATE getMainCategoryFromVPos(s32 vPos) const;
    void setVPos(s32 vPos, PR idx);
    bool isFlowAnimEnd();
    void setCharacterEditUnit(uCharacterEdit* p);
    uMockUpModel* getModel() const;
    nCharacterEdit::CATE getNowCategory();
    MT_CTSTR getNameFromCategory(nCharacterEdit::CATE cate);
    MT_CTSTR getNameFromNowCategory();
    MT_CTSTR getFirstName();
    void setFirstName(MT_CTSTR name);
    MT_CTSTR getLastName();
    void setLastName(MT_CTSTR name);
    void setEdit(nGUIExt::CHARA_EDIT edit);
    nGUIExt::CHARA_EDIT getEdit() const;
    MT_CTSTR getHelpMessage();
    void changeHelpMessage();
    s32 getCategoryNum();
    bool isNameCheck();
    void setUndoNum(s32);
    s32 getUndoNum();
    void setLeftTopUserName(MT_CTSTR pFirstName, MT_CTSTR pLastName);
    void registerCategoryParamList(s32 category, s32 editType);
    void notifyInputName(nCharacterEdit::EDIT_NAME_TYPE type);
    bool isInputName(nCharacterEdit::EDIT_NAME_TYPE type) const;
    void callbackApplyUndoRedo(cUndoData& undoData, bool isUndo);
    virtual void registUndoRedo(cUndoData& undoData);  // vtable slot 96
    void callbackResetUndoRedo();
    void reqestUndoRedo(nCharacterEdit::EDIT_TYPE type);
    void resetVoiceIdx();
    s32 getEditImageOffset(nCharacterEdit::EDIT_TYPE type, u32 index) const;
    void updateGpUI();
    void changeScrFlag_On();
    void changeScrFlag_Off();
    bool isChangeScr() const;
    void saveEquipIcon();
    void saveStageIcon();
    void loadEquipIcon();
    void loadStageIcon();
    void resetNameInput();
    void notifyNameInput();
private:
    EDIT_UPDATE_TYPE checkUpdateCategory(nCharacterEdit::CATE category) const;
    EDIT_UPDATE_TYPE decideUpdateType(u32 flag) const;
    void initUnderHelp();
    void addUnderHelp(nKeyCustom::KB_CUSTOM type, MT_CTSTR msg, HELPER_UI_TYPE helperType);
    void updateUnderHelp();
    void setEquipIconActive(bool flag);
    void setStageIconActive(bool flag);
    void updateCameraForbit();
    cGUIUnderHelpMsg* findHelperMsg(HELPER_UI_TYPE helperType);
    void updateStageEquipList();
    void updateChargeIcon();
    rSoundRequest* getSoundRes();
    void releaseOpenParts();
    rCharacterEditColorDef* getColorPalette(u32 id);
    void updateParts();
    void getVisiblePartsNum(uGUICharaEditPartsWrap::cPartsBase* pBase, s32& num);
    s32 updateParts(uGUICharaEditPartsWrap::cPartsBase* pBase, s32 initY, s32 floor);
    void focusParts(uGUICharaEditPartsWrap::cPartsBase* pBase, s32& num, s32 focusNum);
    void setPartsVisibleAll(bool b, uGUICharaEditPartsWrap::cPartsBase* pBase);
    void deleteParts(uGUICharaEditPartsWrap::cPartsBase* pBase, bool first);
    s32 getVIdx(s32 idx) const;
    cGUIInstNull* getOrgInstance(uGUICharaEditPartsWrap::cPartsBase* pBase);
    s32 getPartsOffsetY(uGUICharaEditPartsWrap::cPartsBase* pBase);
    cpCharacterEdit* findCpCharacterEdit() const;
    rCharacterEditVoicePalette* findeEditVoicePallete() const;
    bool isChargedVoiceData(u32 voiceType, u32 voiceUID) const;
    void buildParts(nCharacterEdit::CATE category, BUILD_MODE buildMode);
    uGUICharaEditPartsWrap::cPartsRadioButton* createPartsRadioButtonCore(uGUICharaEditPartsWrap::cPartsBase* pParentParts, s32 editType, u32 bottunNum, s32 addOffset);
    uGUICharaEditPartsWrap::cPartsRadioButton* createPartsPresetRadioButton(uGUICharaEditPartsWrap::cPartsBase* pParentParts, s32 editType, EDIT_GMD_TYPE gmdType, u32 gmdIndex, u32 bottunNum, s32 addOffset);
    uGUICharaEditPartsWrap::cPartsSlider* createPartsSliderLeftString(uGUICharaEditPartsWrap::cPartsBase* pParentParts, s32 editType, MT_CTSTR leftName, s32 div);
    uGUICharaEditPartsWrap::cPartsRadioSlider* createPartsRadioSlider(uGUICharaEditPartsWrap::cPartsBase* pParentParts, s32 editType, nCharacterEdit::CATE editCategory, s32 idx, nCharacterEdit::CHARGE_TYPE chargeType, bool isSliderLock);
    uGUICharaEditPartsWrap::cPartsPulldown* createPartsPulldown(uGUICharaEditPartsWrap::cPartsBase* pParentParts, MT_CTSTR msg, bool isClose);
    uGUICharaEditPartsWrap::cPartsColor* createPartsColor(uGUICharaEditPartsWrap::cPartsBase* pParentParts, s32 editType, rCharacterEditColorDef* pTable);
    uGUICharaEditPartsWrap::cPartsColorEye* createPartsColorEye(uGUICharaEditPartsWrap::cPartsBase* pParentParts, s32 editType, rCharacterEditColorDef* pTable);
    uGUICharaEditPartsWrap::cPartsColorHairAll* createPartsColorHairAll(uGUICharaEditPartsWrap::cPartsBase* pParentParts, s32 editType, rCharacterEditColorDef* pTable);
    void createPartsColorCore(uGUICharaEditPartsWrap::cPartsColor* pPartsColor, uGUICharaEditPartsWrap::cPartsBase* pParentParts, s32 editType, rCharacterEditColorDef* pTable);
    uGUICharaEditPartsWrap::cPartsImage* createPartsImage(uGUICharaEditPartsWrap::cPartsBase* pParentParts, s32 editType, s32 num, nCharacterEdit::PALETTE pal);
    uGUICharaEditPartsWrap::cPartsMask* createPartsMask(uGUICharaEditPartsWrap::cPartsBase* pParentParts);
    uGUICharaEditPartsWrap::cPartsMyName* createPartsMyName(uGUICharaEditPartsWrap::cPartsBase* pParentParts);
    s32 getSliderPosFromVal(nCharacterEdit::EDIT_TYPE type, u32 div);
    void addBuildPartsNum();
    void resetBuildPartsNum();
    u32 getBuildPartsNum() const;
    void initBottunCtrl_PrSub(cControl* & pCtrlSub);
    bool isOpenParts() const;
    rSndPitchLimit* getSndPitchLimit() const;
    void setUpInstObj();
    void setUpRegistCtrl();
    void setUpEquipStageList();
    bool manageEnv();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    void moveInputPad();
    void setInputEventWrap(u32 inputEvent);
    void moveInputParts();
    void moveEventParts();
    void moveEventParts(s32 eventNo);
    virtual void updateInit();  // vtable slot 93
    void updateInit2();
    void updateInitLight();
    void updateInitCommon();
    void updateWait();
    void updateExit();
    void moveMainList();
    void moveDialog();
    void moveDialogInit();
    MT_CTSTR getDialogExitMsg();
    void moveDialogExit();
    void moveGpShop();
    void initMain();
    void initSub();
    void moveSub();
    void moveSaveLoad();
    void setSubProc(u32 proc);
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlMoveV(cControl::Message* msg);
    u32 evCtrlMoveLeft(cControl::Message* msg);
    u32 evCtrlMoveRight(cControl::Message* msg);
    u32 evCtrlMouseClickMain(cControl::Message* msg);
    u32 evCtrlMouseClickStage(cControl::Message* msg);
    u32 evCtrlMouseClickEquip(cControl::Message* msg);
    u32 evCtrlMouseOverMain(cControl::Message* msg);
    u32 evCtrlMouseOverStage(cControl::Message* msg);
    u32 evCtrlMouseOverEquip(cControl::Message* msg);
    u32 evCtrlMouseOverCamera(cControl::Message* msg);
    u32 evCtrlRedo(cControl::Message* msg);
    u32 evCtrlUndo(cControl::Message* msg);
    u32 evCtrlOpenStageList(cControl::Message* msg);
    u32 evCtrlCancelStageList(cControl::Message* msg);
    u32 evCtrlOpenEquipList(cControl::Message* msg);
    u32 evCtrlCancelEquipList(cControl::Message* msg);
    u32 evCtrlStartSaveLoad(cControl::Message* msg);
    u32 evCtrlEditDefault(cControl::Message* msg);
    u32 evCtrlPartsMatrix(cControl::Message* msg);
    u32 evCtrlTop(cControl::Message* msg);
    u32 evCtrlPartsDecide(cControl::Message* msg);
    u32 evCtrlPartsCancel(cControl::Message* msg);
    u32 evCtrlPartsMoveH(cControl::Message* msg);
    u32 evCtrlPartsMoveV(cControl::Message* msg);
    u32 evCtrlPartsMouseOver(cControl::Message* msg);
    u32 evCtrlPartsMouseClickName(cControl::Message* msg);
    u32 evCtrlPartsMouseClick(cControl::Message* msg);
    u32 evCtrlPartsMouseClickInPullDown(cControl::Message* msg);
    u32 evCtrlPartsMouseWInPullDown(cControl::Message* msg);
    u32 evCtrlPartsMouseClickRadioSlider(cControl::Message* msg);
    u32 evCtrlPartsMouseDragSlider(cControl::Message* msg);
    u32 evCtrlDecideMainCore(s32 vPos, cControl::Message* msg);
    u32 evParts(uGUICharaEditPartsWrap::cPartsBase* pBase, nCharacterEdit::PARTS_EVENT ev, bool isRegistRedoUndo);
    void changeVoice(uGUICharaEditPartsWrap::cPartsBase* pBase, nCharacterEdit::PARTS_EVENT ev);
    void changePersonal(uGUICharaEditPartsWrap::cPartsBase* pBase, nCharacterEdit::PARTS_EVENT ev);
    uGUICharaEditPartsWrap::cPartsBase* getPartsFromVPos(u32 vPos) const;
    nCharacterEdit::CATE getCurrentCategory() const;
    void evInputOpenSubChild();
    void evInputDeceideMainRamdomFace();
    void evInputDeceideMainDeceide();
    void evInputDispInitWarning();
    void evInputDispExitWarning();
    void evInputSelectSubChild();
    void evInputCloseSubChild();
    void evInputTopSubChild();
    void evInputChangeMotion();
    void evInputRedo();
    void evInputUndo();
    void evInputChangeFaceAnime();
    void evInputStartSaveLoad();
    void evInputEditDefault();
    void evInputOpenStageList();
    void evInputChangeStage();
    void evInputCloseStageList(bool isCancel);
    void evInputChangeStageLR(bool isLeft);
    void evInputOpenEquipList();
    void evInputChangeEquip();
    void evInputCloseEquipList(bool isCancel);
    void evInputChangeEquipLR(bool isLeft);
    void evInputMoveVSub();
    void evCloseSubChild();
    void evOpenGpShopFromChageVoice();
    void checkCloseSubUI();
    void unfocusMainListArray();
    void setUnderHelperUI();
    void updateMainListFocus(bool isUpdate);
    void registMouseOverMainCategory(cControl* pCtrl, bool mouseOverMini, bool isRefButton);
    void registMouseOverEquipC(cControl* pCtrl);
    void registMouseOverEquipLR(cControl* pCtrl);
    void clearMouseOverEquipLR(cControl* pCtrl);
    void registMouseOverStageC(cControl* pCtrl);
    void registMouseOverStageLR(cControl* pCtrl);
    void clearMouseOverStageLR(cControl* pCtrl);
    void changeEquipCoordinate(u32 index);
    nCharacterEdit::EDIT_WARN_TYPE getInitWarnTypeOld() const;
    nCharacterEdit::EDIT_WARN_TYPE getInitWarnType() const;
    nCharacterEdit::EDIT_WARN_TYPE convertWarnFromMainCate(nCharacterEdit::CATE category) const;
    void setInitWarnType(nCharacterEdit::EDIT_WARN_TYPE type);
    void setInitWarnTypeOld(nCharacterEdit::EDIT_WARN_TYPE);
    u32 getKbFromPadBtnType(sPadExt::PAD_BTN_TYPE button) const;
    void clearInitWarnType();
    bool isOffline();
    bool isRewardRelease(nCharacter::E_EDIT_PALETTE_PARAM_TYPE rewardType, u32 rewardID) const;
public:
    nDDOUtility::cArray<bool, 10> mIsHelperDefaultActive;  // offset: 0x958
    MtTypedArray<cListStage> mListStageArray;  // offset: 0x968
    MtTypedArray<cListEquip> mListEquipArray;  // offset: 0x988
    MtTypedArray<cIndex> mIndexArray;  // offset: 0x9a8
    MtTypedArray<cGUIUnderHelpMsg> mGUIUnderHelpMsgArray;  // offset: 0x9c8
private:
    stGuiInst mInst;  // offset: 0x9e8
    stGuiObj mObj;  // offset: 0xb10
    rGUI* mpGUIRes;  // offset: 0xbb0
    PR mProc;  // offset: 0xbb8
    PR mProcOld;  // offset: 0xbbc
    u32 mSubProc;  // offset: 0xbc0
    bool mSubInit;  // offset: 0xbc4
    u32 mSetFlow;  // offset: 0xbc8
    u32 mUndoNum;  // offset: 0xbcc
    MtString mHelpMessage;  // offset: 0xbd0
    s32 mBuildAfterFrame;  // offset: 0xbd8
    nCharacterEdit::DIR mDir;  // offset: 0xbdc
    BUILD_MODE mBuildMode;  // offset: 0xbe0
    nCharacterEdit::CATE mRegisterCategory;  // offset: 0xbe4
    uCharacterEdit* mpCharacterEdit;  // offset: 0xbe8
    MtTypedArray<cList> mMainListArray;  // offset: 0xbf0
    bool mDebugInfoDraw;  // offset: 0xc10
    nGUIExt::CHARA_EDIT mEdit;  // offset: 0xc14
    nDDOUtility::cArray<int, 32> mVoicePitches;  // offset: 0xc18
    s32 mVoiceIndex;  // offset: 0xc98
    s32 mVoiceSaveIdx;  // offset: 0xc9c
    f32 mVoiceSavePitch;  // offset: 0xca0
    s32 mPersonalitySaveIdx;  // offset: 0xca4
    TICKET mSystemMsgTicket;  // offset: 0xca8
    MtString mFirstName;  // offset: 0xcb0
    MtString mLastName;  // offset: 0xcb8
    uGUICharaEditPartsWrap::cPartsBase* mpPartsArray;  // offset: 0xcc0
    MtTypedArray<uGUICharaEditPartsWrap::cPartsBase> mPartsOrgArray;  // offset: 0xcc8
    uGUIBase::cReferenceUIVlCursor mRefCursor;  // offset: 0xcf0
    uGUIBase::cReferenceUIButton2 mRefButton;  // offset: 0xda0
    uGUICharaEditPartsWrap::cPartsSlider mOrgPartsSlider;  // offset: 0xf30
    uGUICharaEditPartsWrap::cPartsImage mOrgPartsImage;  // offset: 0x1170
    uGUICharaEditPartsWrap::cPartsColor mOrgPartsColor;  // offset: 0x1348
    uGUICharaEditPartsWrap::cPartsColorEye mOrgPartsColorEye;  // offset: 0x1518
    uGUICharaEditPartsWrap::cPartsColorHairAll mOrgPartsColorHairAll;  // offset: 0x16f8
    uGUICharaEditPartsWrap::cPartsPulldown mOrgPartsPulldown;  // offset: 0x18e0
    uGUICharaEditPartsWrap::cPartsMask mOrgPartsMask;  // offset: 0x1fe0
    uGUICharaEditPartsWrap::cPartsRadioButton mOrgPartsRadioButton;  // offset: 0x2108
    uGUICharaEditPartsWrap::cPartsRadioSlider mOrgPartsRadioSlider;  // offset: 0x22e0
    uGUICharaEditPartsWrap::cPartsMyName mOrgPartsMyName;  // offset: 0x2780
    uGUICharaEditPartsWrap::cPartsBase* mpOpenParts;  // offset: 0x2b68
    uGUICharaEditPartsWrap::cPartsBase* mpFocusParts;  // offset: 0x2b70
    uEditSaveLoadFlow* mpSaveLoadFlow;  // offset: 0x2b78
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0x2b80
    uGUIGPShop* mpGUIGoldStonShop;  // offset: 0x2b88
    nDDOUtility::cArray<cVerticalListEx*, 11> mVCtrlPtrArray;  // offset: 0x2b90
    cControl* mpBottunCtrl_PrMain;  // offset: 0x2be8
    cControl* mpBottunCtrl_PrSub;  // offset: 0x2bf0
    cControl* mpBottunCtrl_StageSub;  // offset: 0x2bf8
    cControl* mpBottunCtrl_EquipSub;  // offset: 0x2c00
    cControl* mpBottunCtrl_Camera;  // offset: 0x2c08
    u32 mBuildPartsIndex;  // offset: 0x2c10
    s32 mVarGap;  // offset: 0x2c14
    s32 mVarMargin;  // offset: 0x2c18
    s32 mLastStagePos;  // offset: 0x2c1c
    s32 mLastEquipPos;  // offset: 0x2c20
    bool mLastStageIsLeft;  // offset: 0x2c24
    bool mLastEquipIsLeft;  // offset: 0x2c25
    bool mIsChangeScr;  // offset: 0x2c26
    bool mIsNameInput_move;  // offset: 0x2c27
    nCharacterEdit::EDIT_WARN_TYPE mInitWarnType;  // offset: 0x2c28
    nCharacterEdit::EDIT_WARN_TYPE mInitWarnTypeOld;  // offset: 0x2c2c
    bool mNameInputed[2];  // offset: 0x2c30
    EDIT_SAVE_LOAD_ROUTINE mSaveLoadRno;  // offset: 0x2c34
    EDIT_DIALOG_ROUTINE mEditDialogRno;  // offset: 0x2c38
    GP_SHOP_ROUTINE mGpShopRno;  // offset: 0x2c3c
    cEditChargeInfoUpdator mEditChargeInfoUpdator;  // offset: 0x2c40
public:
    static MyDTI DTI;
    static const u32 COORDINATE_NUM = 5;
    static const u32 HELP_MSG_NUM = 7;
    static const u32 PRESET_TYPE_NUM = 15;
    static const u32 VOICE_PITCH_DIV_NUM = 2;
private:
    static const u32 EDIT_UPDATE_CHAGE_FRAME = 0;
    static const u32 EDIT_UPDATE_FREE_FRAME = 1;
    static const u32 EQUIP_STAGE_ICON_ACTIVE_FRAME = 0;
    static const u32 EQUIP_STAGE_ICON_INACTIVE_FRAME = 1;
};

inline void* uGUICharacterEdit::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline uGUICharacterEdit::PR uGUICharacterEdit::getProc() {
    return this->mProc;
}

inline void uGUICharacterEdit::setCharacterEditUnit(uCharacterEdit* p) {
    this->mpCharacterEdit = p;
}

inline void uGUICharacterEdit::setEdit(nGUIExt::CHARA_EDIT edit) {
    this->mEdit = edit;
}

inline void uGUICharacterEdit::changeScrFlag_On() {
    this->mIsChangeScr = true;
}

inline void uGUICharacterEdit::changeScrFlag_Off() {
    this->mIsChangeScr = false;
}

inline void uGUICharacterEdit::resetNameInput() {
    this->mIsNameInput_move = false;
}

inline nCharacterEdit::EDIT_WARN_TYPE uGUICharacterEdit::getInitWarnTypeOld() const {
    return this->mInitWarnTypeOld;
}

inline void uGUICharacterEdit::clearInitWarnType() {
    this->mInitWarnTypeOld = this->mInitWarnType;
    this->mInitWarnType = static_cast<nCharacterEdit::EDIT_WARN_TYPE>(0);
}

inline void* uGUICharacterEdit::cListStage::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharacterEdit::cListEquip::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharacterEdit::cIndex::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharacterEdit::cGUIUnderHelpMsg::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharacterEdit::cList::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline void* uGUICharacterEdit::cVerticalListEx::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
