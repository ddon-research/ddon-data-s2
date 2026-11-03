#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../../MT/MtDTI.h"
#include "cControl.h"
#include "nCharacterEdit.h"
#include "sSavedataExt.h"
#include "uGUIBase.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
class cControl;
class cGUIInstNull;
class cGUIObjMessage;
class rGUI;
class rGUIMessage;
class uGUISystemMsg;

// Declarations
class uGUISaveListComment;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using _Sizet = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;

class uGUISaveListComment : public uGUIBase
{
public:
    enum UPDATE_FLOW
    {
        UPDATE_NONE = 0,
        UPDATE_INIT = 1,
        UPDATE_WAIT = 2,
        UPDATE_CANCEL_DIALOG = 3,
        UPDATE_INPUT_COMMENT = 4,
        UPDATE_EXIT = 5,
        UPDATE_ERROR = 6,
    };
    enum EXIT_TYPE
    {
        EXIT_TYPE_NONE = 0,
        EXIT_TYPE_CANCEL = 1,
        EXIT_TYPE_SUCCESS = 2,
    };
    enum CHOICE_POS
    {
        CHOICE_POS_NONE = -1,
        CHOICE_POS_YES = 0,
        CHOICE_POS_NO = 1,
    };
    enum SELECT_POS
    {
        SELECT_POS_COMMENT = 0,
        SELECT_POS_DECIDE = 1,
        SELECT_POS_NUM = 2,
    };
    enum
    {
        INPUTEVENT_CANCEL = 66,
        INPUTEVENT_SELECT_COMMENT = 67,
        INPUTEVENT_SELECT_DECIDE = 68,
        INPUTEVENT_SELECT_MOVE_V = 69,
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
    uGUISaveListComment();
    virtual ~uGUISaveListComment();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual bool loadResource();  // vtable slot 76
    virtual void setup();  // vtable slot 6
    virtual void move();  // vtable slot 9
    virtual void kill();  // vtable slot 16
    virtual void updatePtr();  // vtable slot 17
    MT_CTSTR getSaveListMsg(u32 msgID) const;
    MT_CTSTR getCommonMsg(u32 msgID) const;
    void setSaveLoadMode(nCharacterEdit::SAVE_LOAD_MODE mode);
    void setUseHeader(const cStorageDataBase::UserHeader& header);
    EXIT_TYPE getExitType() const;
    const cStorageDataBase::UserHeader& getUserHeader() const;
    bool isEnd() const;
private:
    void setComment(MT_CTSTR comment);
    void setExitType(EXIT_TYPE type);
    void updateInit();
    void updateWait();
    void updateCnacelDialog();
    void updateInputComment();
    void updateExit();
    void changeUpdateFlow(UPDATE_FLOW flowNo);
    bool manageEnv();
    virtual void moveInput();  // vtable slot 87
    virtual void moveEvent();  // vtable slot 88
    u32 evCtrlCancel(cControl::Message* msg);
    u32 evCtrlDecide(cControl::Message* msg);
    u32 evCtrlMoveV(cControl::Message* msg);
    u32 evCtrlMouseClickText(cControl::Message* msg);
    u32 evCtrlMouseClickDecide(cControl::Message* msg);
    void inputEventMoveV();
    void setUpInstObj();
    void setUpCtrl();
    s32 getSelectPos() const;
    bool reqestDialogEasy(u32 msgID);
    bool checkDialogEndEasy();
    bool reqestDialog(u32 msgID, CHOICE_POS defPos, u32 msgDecideID, u32 msgCancelID);
    s32 checkDialogEnd();
    void changeFocus(s32 vPos);
    void changeCurrentPos(s32 vPos);
private:
    cGUIInstNull* mpInstNull;  // offset: 0x8c8
    cGUIInstNull* mpInstMsgTxt;  // offset: 0x8d0
    cGUIObjMessage* mpMsgTxtMsgJpn;  // offset: 0x8d8
    cGUIObjMessage* mpMsgTxtMsgTxt000;  // offset: 0x8e0
    cGUIObjMessage* mpMsgTxtMsgTxt01;  // offset: 0x8e8
    cGUIObjMessage* mpMsgTxtMsgTxt02;  // offset: 0x8f0
    cGUIObjMessage* mpMsgTxtMsgTxt03;  // offset: 0x8f8
    cGUIObjMessage* mpMsgTxtMsgTxt04;  // offset: 0x900
    cGUIObjMessage* mpMsgTxtMsgTxt07;  // offset: 0x908
    uGUIBase::cReferenceUICloseBtn mRefCloseBtn;  // offset: 0x910
    uGUIBase::cReferenceUITextBox mRefTextBox;  // offset: 0x968
    uGUIBase::cReferenceUIButton2 mRefButton;  // offset: 0xad0
    UPDATE_FLOW mUpdateFlowNo;  // offset: 0xc60
    rGUI* mpGUIRes;  // offset: 0xc68
    rGUIMessage* mpGMDRes;  // offset: 0xc70
    uGUISystemMsg* mpGUISystemMsg;  // offset: 0xc78
    nCharacterEdit::SAVE_LOAD_MODE mSaveLoadMode;  // offset: 0xc80
    cStorageDataBase::UserHeader mSaveDataHeader;  // offset: 0xc88
    uGUIBase::cVerticalList* mpCtrlV;  // offset: 0xd58
    cControl* mpCtrlRefButton;  // offset: 0xd60
    EXIT_TYPE mExitType;  // offset: 0xd68
    bool mIsEnd;  // offset: 0xd6c
    SAVEDATA_TYPE mSaveDataType;  // offset: 0xd70
public:
    static MyDTI DTI;
private:
    static const u32 SAVE_COMMENT_LENGTH = 22;
};

inline void* uGUISaveListComment::operator new(size_t sz, void* p_addr) {
    return p_addr;
}
