#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "../MT/MtDTI.h"
#include "cSystem.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtProperty;
class MtPropertyList;
class MtUI;
struct SceImeEvent;

// Declarations
class sCommonDialog;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_STR = MT_CHAR*;
using _Sizet = long unsigned int;
using __uint64_t = long unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using u64 = __uint64_t;

class sCommonDialog : public cSystem
{
public:
    enum STATE
    {
        STATE_NONE = 0,
        STATE_MESSAGE_DIALOG = 1,
        STATE_IME_DIALOG = 2,
        STATE_LIBIME = 3,
    };
    enum LANGUAGE
    {
        LANGUAGE_ALL = 0,
        LANGUAGE_DANISH = 1,
        LANGUAGE_GERMAN = 2,
        LANGUAGE_ENGLISH = 4,
        LANGUAGE_SPANISH = 8,
        LANGUAGE_FRENCH = 16,
        LANGUAGE_ITALIAN = 32,
        LANGUAGE_DUTCH = 64,
        LANGUAGE_NORWEGIAN = 128,
        LANGUAGE_POLISH = 256,
        LANGUAGE_PORTUGUESE = 512,
        LANGUAGE_RUSSIAN = 1024,
        LANGUAGE_FINNISH = 2048,
        LANGUAGE_SWEDISH = 4096,
        LANGUAGE_JAPANESE = 8192,
        LANGUAGE_KOREAN = 16384,
        LANGUAGE_CHINESE_S = 32768,
        LANGUAGE_CHINESE_T = 65536,
        LANGUAGE_APP = 268435456,
        LANGUAGE_UNDEFINED = 536870912,
    };
    enum BUTTON_TYPE
    {
        BUTTON_TYPE_OK = 0,
        BUTTON_TYPE_YESNO = 1,
        BUTTON_TYPE_NONE = 2,
        BUTTON_TYPE_WAIT = 3,
        BUTTON_TYPE_WAIT_CANCEL = 4,
    };
    enum SYSMSG_TYPE
    {
        SYSMSG_TYPE_EMPTY_STORE = 0,
        SYSMSG_TYPE_PSN_CHAT_RESTRICTION = 1,
        SYSMSG_TYPE_PSN_UGC_RESTRICTION = 2,
        SYSMSG_TYPE_WARING_SWITCH_TO_SIMULVIEW = 3,
    };
    enum TEXTBOX_MODE
    {
        TEXTBOX_MODE_DEFAULT = 0,
        TEXTBOX_MODE_PASSWORD = 1,
    };
    enum IME_TYPE
    {
        IME_TYPE_DEFAULT = 0,
        IME_TYPE_BASIC_LATIN = 1,
        IME_TYPE_NUMBER = 2,
    };
    enum DIALOG_TYPE
    {
        DIALOG_TYPE_UNKNOWN = 0,
        DIALOG_TYPE_USERMSG = 1,
        DIALOG_TYPE_SYSMSG = 2,
        DIALOG_TYPE_PROGRESSBAR = 3,
        DIALOG_TYPE_ERRORINFO = 4,
        DIALOG_TYPE_IME = 5,
    };
    enum MSG_DIALOG_RESULT
    {
        MSG_DIALOG_RESULT_BUTTON_INVALID = 0,
        MSG_DIALOG_RESULT_BUTTON_OK = 1,
        MSG_DIALOG_RESULT_BUTTON_YES = 1,
        MSG_DIALOG_RESULT_BUTTON_NO = 2,
        MSG_DIALOG_RESULT_USER_CANCELED = 3,
        MSG_DIALOG_RESULT_ABORTED = 4,
        MSG_DIALOG_RESULT_ERROR = 5,
    };
    enum IME_CALLBACK_TYPE
    {
        IME_CALLBACK_TYPE_RESULT_OK = 0,
        IME_CALLBACK_TYPE_RESULT_USER_CANCELED = 1,
        IME_CALLBACK_TYPE_RESULT_ABORTED = 2,
        IME_CALLBACK_TYPE_PRESS_ENTER = 3,
        IME_CALLBACK_TYPE_UPDATE_TEXT = 4,
        IME_CALLBACK_TYPE_ERROR = 5,
    };
public:
    class MyDTI;
    class CommonDialogData;
    struct ImeDialogParamData;
    class UserMessageDialogData;
    class ErrorMessageDialogData;
public:
    using MSG_DIALOG_CALLBACK = void(MtObject::*)(s32);
    using IME_CALLBACK = void(MtObject::*)(s32, MT_CTSTR);
public:
    class MyDTI : public MtDTI
    {
    public:
        MyDTI(MT_CTSTR class_name, MtDTI* ps, size_t size, u32 id, u32 attr);
        virtual MtObject* newInstance() const;  // vtable slot 2
    };
public:
    class CommonDialogData
    {
    public:
        CommonDialogData();
        static void* operator new(size_t sz, u32 align);
        static void* operator new[](size_t sz, u32 align);
        static void operator delete(void* p_addr);
        static void operator delete[](void* p_addr);
        static void operator delete(void* p_addr, u32 align);
        static void operator delete[](void* p_addr, u32 align);
    public:
        s32 mode;  // offset: 0x0
        u32 prio;  // offset: 0x4
        MtObject* owner;  // offset: 0x8
        sCommonDialog::MSG_DIALOG_CALLBACK callback;  // offset: 0x10
        sCommonDialog::CommonDialogData* next;  // offset: 0x20
    };
public:
    struct ImeDialogParamData
    {
    public:
        u64 language;  // offset: 0x0
        MT_CHAR title[128];  // offset: 0x8
        sCommonDialog::IME_TYPE type;  // offset: 0x88
        sCommonDialog::TEXTBOX_MODE mode;  // offset: 0x8c
        u32 max_length;  // offset: 0x90
        MT_CHAR text[512];  // offset: 0x94
        bool language_forced;  // offset: 0x294
    };
public:
    class UserMessageDialogData : public sCommonDialog::CommonDialogData
    {
    public:
        UserMessageDialogData();
        ~UserMessageDialogData();
    public:
        MT_STR message;  // offset: 0x28
        s32 type;  // offset: 0x30
    };
public:
    class ErrorMessageDialogData : public sCommonDialog::CommonDialogData
    {
    public:
        ErrorMessageDialogData();
    public:
        s32 errorcode;  // offset: 0x28
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
    sCommonDialog();
    virtual ~sCommonDialog();
    virtual void move();  // vtable slot 7
    static sCommonDialog* getInstance();
    virtual MtUI* createUI(MtProperty& prop);  // vtable slot 2
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    bool setCommonDialogLanguage(LANGUAGE lang);
    LANGUAGE getLanguage() const;
    LANGUAGE convertAppLanguage2CommonDialogLanguage(s32 sys_lang);
    s32 convertCommonDialogLanguage2AppLanguage(s32 lang);
    STATE getState() const;
    s32 getMsgDialogResult() const;
    bool createUserMsgDialog(MT_CTSTR message, BUTTON_TYPE type);
    bool createUserMsgDialog(MT_CTSTR message, BUTTON_TYPE type, MtObject* owner, MSG_DIALOG_CALLBACK callback, u32 prio);
    bool createSystemMsgDialog(SYSMSG_TYPE type, s32 value);
    bool createErrorMsgDialog(s32 errorcode);
    bool createProgressBarMsgDialog(MT_CTSTR message, s32 type);
    void setProgressBarInc(u32 value);
    void setProgressBarValue(u32 value);
    bool closeMsgDialog();
    bool abortMsgDialog();
    bool createImeDialogDefault(MT_CTSTR title, s32 length);
    bool createImeDialogLatin(MT_CTSTR title, s32 length, TEXTBOX_MODE mode);
    bool createImeDialog(const ImeDialogParamData& param);
    bool createIme(const ImeDialogParamData& param);
    void setImeCallback(MtObject* own, IME_CALLBACK func);
protected:
    bool initUserMessageDialog(MT_CTSTR message, s32 type);
    bool initSystemMessageDialog(s32 type, s32 value);
    bool initErrorMessageDialog(s32 errorcode);
    bool initProgressBarDialog(s32 type, MT_CTSTR message);
    s32 updateMessageDialog();
    s32 updateErrorDialog();
    s32 updateImeDialog();
    s32 updateLibime();
    static void onImeEvent(void* arg, const SceImeEvent* e);
    bool addMsgDialogList(CommonDialogData* data);
    bool deleteMsgDialogListTop();
    void updateMessageDialogList();
    bool createMessageDialog();
    void clearMsgDialogList();
    void startCommonDialog(STATE newstate);
    void finishCommonDialog();
protected:
    s32 mDialogType;  // offset: 0x14
    STATE mState;  // offset: 0x18
    LANGUAGE mLanguage;  // offset: 0x1c
    s32 mMsgResult;  // offset: 0x20
    s32 mListCount;  // offset: 0x24
    CommonDialogData* mpMsgDialogList;  // offset: 0x28
    MT_CHAR mImeStr[4096];  // offset: 0x30
    void* mpIMEWork;  // offset: 0x1030
    MtObject* mpMsgOwner;  // offset: 0x1038
    MSG_DIALOG_CALLBACK mMsgCallback;  // offset: 0x1040
    MtObject* mpImeOwner;  // offset: 0x1050
    IME_CALLBACK mImeCallback;  // offset: 0x1058
public:
    static MyDTI DTI;
protected:
    static sCommonDialog* mpInstance;
    static const s32 MAX_LIST_NUM = 8;
};

inline void* sCommonDialog::operator new(size_t sz, void* p_addr) {
    return p_addr;
}

inline sCommonDialog::ErrorMessageDialogData::ErrorMessageDialogData() {
}

// Included after the classes: the generic bodies below need these complete.
#include "../MT/MtAllocator.h"
#include "../MT/MtMemoryAllocator.h"

inline void sCommonDialog::operator delete(void* p_addr) {
    ::MtMemoryAllocator::getAllocator(::sCommonDialog::DTI)->memFree(p_addr);
}
