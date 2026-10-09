#pragma once

#include <cstdint>
#include <cstddef>

// Dependencies
#include "MtDTI.h"
#include "cSystem.h"
#include "ime_dialog.h"
#include "ime_types.h"

// Forward declarations
class MtAllocator;
class MtDTI;
class MtObject;
class MtPropertyList;
struct SceImeDialogParam;
struct SceImeKeycode;
struct SceImeParamExtended;
class cInputTextKeyboardHook;
class cMenuEditClanMessage;

// Declarations
class sKeyboardInterface;

// Type aliases from DWARF
using MT_CHAR = char;
using MT_CTSTR = const MT_CHAR*;
using MT_WCHAR = wchar_t;
using _Sizet = long unsigned int;
using __uint16_t = unsigned short;
using __uint32_t = unsigned int;
using s32 = int;
using size_t = _Sizet;
using u32 = unsigned int;
using uint16_t = __uint16_t;
using uint32_t = __uint32_t;

class sKeyboardInterface : public cSystem
{
    // inferred: cMenuEditClanMessage::moveEditClanMessage names sKeyboardInterface::mOutputText_utf8[0]
    friend class cMenuEditClanMessage;
public:
    enum MODE
    {
        MODE_IDLE = 0,
        MODE_RUNNING = 1,
        MODE_CLOSE = 2,
        MODE_CANCELED = 3,
    };
    enum REQUEST
    {
        REQ_NONE = 0,
        REQ_OPEN_TO_KEYBOARD = 1,
        REQ_OPEN_TO_PAD = 2,
        REQ_FORCE_CLOSE = 3,
        REQ_FORCE_CANCEL = 4,
    };
    enum KEYBOARD_TYPE
    {
        KEYBOARD_TYPE_NUMERAL = 0,
        KEYBOARD_TYPE_ASCII = 1,
        KEYBOARD_TYPE_JAPANESE = 2,
    };
    enum RESULT
    {
        RESULT_NONE = 0,
        RESULT_OK = 1,
        RESULT_CANCEL = 2,
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
    sKeyboardInterface();
    virtual ~sKeyboardInterface();
    virtual void createProperty(MtPropertyList& s);  // vtable slot 4
    virtual void init();  // vtable slot 10
    virtual void move();  // vtable slot 7
    virtual void reset();  // vtable slot 6
    static sKeyboardInterface* getInstance();
    MODE getMode() const;
    void setInputField(MT_CTSTR titleText, MT_CTSTR defaultText, u32 maxCharacterCount);
    bool requestOpen(u32 option, cInputTextKeyboardHook* keyboardHook);
    bool requestOpenPad(u32 option, cInputTextKeyboardHook* keyboardHook);
    bool requestClose(bool isCancel);
    void resetRequest();
    MT_CTSTR getResultText();
    void setKeyboardSetting(KEYBOARD_TYPE keyboardType, MT_CTSTR titleText, MT_CTSTR defaultText, s32 maxCharacterCount);
    bool isBusy() const;
    bool isRunning() const;
    bool isClosing() const;
    bool isOpenByPad() const;
    bool isSoftwareKeyboard() const;
    RESULT getResult() const;
private:
    bool open();
    void close(bool isCancel);
    bool checkOpenRequest();
    bool checkCloseRequest(bool* isCancel);
    static int KeyboardFilter(const SceImeKeycode* srcKeycode, uint16_t* outKeycode, uint32_t* outStatus, void* reserved);
private:
    MODE mMode;  // offset: 0x14
    REQUEST mRequest;  // offset: 0x18
    bool mIsOpenByPad;  // offset: 0x1c
    KEYBOARD_TYPE mKeyboardType;  // offset: 0x20
    MT_WCHAR mDefaultText[2048];  // offset: 0x24
    MT_WCHAR mTitleText[2048];  // offset: 0x1024
    MT_WCHAR mResultText[2048];  // offset: 0x2024
    u32 mMaxCharacterCount;  // offset: 0x3024
    MT_CHAR mOutputText_utf8[6144];  // offset: 0x3028
    u32 mOutputTextLength;  // offset: 0x4828
    SceImeDialogParam mDialogParam;  // offset: 0x4830
    SceImeParamExtended mParamExtended;  // offset: 0x4890
    u32 mKeyStateClearNum;  // offset: 0x4918
    RESULT mResult;  // offset: 0x491c
    u32 mOption;  // offset: 0x4920
    u32 mOptionReq;  // offset: 0x4924
    cInputTextKeyboardHook* mKeyboardHook;  // offset: 0x4928
    cInputTextKeyboardHook* mKeyboardHookReq;  // offset: 0x4930
public:
    static const u32 OPTION_PASSWORD = 1;
    static MyDTI DTI;
private:
    static sKeyboardInterface* mpInstance;
};

// Inline, no code of its own: checked where it is inlined.
inline sKeyboardInterface* sKeyboardInterface::getInstance() {
    return ::sKeyboardInterface::mpInstance;
}
